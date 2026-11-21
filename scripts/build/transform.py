#!/usr/bin/env python3
"""Turn the source in src/ into what the toolchain is given, in build/.

Renaming: the source spells meaningful names and the build maps them back to
the canonical identifiers the manifest is keyed on, in place by source
position, through a parse that says which occurrences refer to the symbol.

Splitting: LINK concatenates objects in link order, so the assembly is cut
around each routine written in C, and a module whose routines run A B C D
still links in that order with B coming from C."""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from lib import spelling
from interop import assembly as assembly_reader
from interop import csource as csource_reader

# What the assembly carries where a routine written in C belongs, which is
# where the build splits it.
SPLIT_MARKER = ";;SPLIT "


class TransformError(Exception):
    pass


def _substitute(text, replacements):
    """Apply (start, end, new text) edits to a string, right to left so each
    edit's offsets stay valid."""
    out = text
    for start, end, replacement in sorted(replacements, reverse=True):
        out = out[:start] + replacement + out[end:]
    return out


def crossing_map(module):
    """How a renamed symbol that crosses the boundary is spelled on each side.
    MSC mangles a cdecl symbol to `_name`, so the assembly carries the
    underscore and the C does not, both sanitised to the C alphabet. A
    linker name such as `_strcpy` is never renamed. Returns {'asm': {...},
    'c': {...}}, source spelling to toolchain spelling."""
    out = {"asm": {}, "c": {}}
    crossing = tuple(module.porting.publics) + tuple(module.porting.externs)
    for name in crossing:
        meaningful = module.names.meaningful(name)
        if meaningful == name:
            continue
        library = spelling.library_spelling(name, meaningful)
        if library:
            # The library's own spelling of a datum, as `_errno`: both sides
            # map it to itself, or the plain [names] map would rename it to its
            # canonical name and the library object asking for it would find
            # nothing.
            out["asm"][library] = library
            out["c"][spelling.c_spelling(library)] = spelling.c_spelling(library)
            continue
        out["asm"][spelling.linker_spelling(meaningful)] = spelling.linker_spelling(name)
        out["c"][spelling.c_identifier(meaningful)] = spelling.c_identifier(name)
    return out


def _canonical(names, crossing, kind="asm"):
    """One lookup for both maps, the crossing spelling first: [names] alone
    would map a crossing symbol to a canonical identifier that is not always
    a legal one. A name that does not cross is sanitised to the alphabet of
    the tool given the file."""
    clean = spelling.c_identifier if kind == "c" else spelling.masm_identifier

    def lookup(text):
        if crossing and text in crossing:
            return crossing[text]
        if not names:
            return text
        canonical = names.canonical(text)
        # Only a name the map moved is sanitised: `masm_identifier` would
        # rename a reserved word such as SEGMENT.
        return clean(canonical) if canonical != text else text
    return lookup


def rename_assembly(text, names, path=None, crossing=None):
    """Meaningful names back to canonical ones, through the MASM parse.
    Comments and string bodies are not tokens, so they stay as written."""
    lookup = _canonical(names, crossing, "asm")
    parsed = assembly_reader.parse(text, path)
    edits = []
    for token in parsed.identifier_tokens():
        canonical = lookup(token.text)
        if canonical != token.text:
            edits.append((token.start, token.end, canonical))
    return _substitute(text, edits), len(edits)


def rename_c(text, names, path=None, crossing=None):
    """The same, through the C parse: only occurrences that refer to a symbol,
    never a member, a label, a struct tag or anything in a preprocessor
    directive."""
    lookup = _canonical(names, crossing, "c")
    parsed = csource_reader.parse(text, path)
    edits = []
    for occurrence in parsed.renameable_occurrences():
        canonical = lookup(occurrence.name)
        if canonical != occurrence.name:
            edits.append((occurrence.token.start, occurrence.token.end,
                          canonical))
    return _substitute(text, edits), len(edits)


def rename(text, names, kind, path=None, crossing=None):
    """Dispatch on what the file is. `kind` is 'asm' or 'c'."""
    if not names and not crossing:
        return text, 0
    if kind == "asm":
        return rename_assembly(text, names, path, crossing)
    if kind == "c":
        return rename_c(text, names, path, crossing)
    raise TransformError("no renamer for %r" % kind)


# ---------------------------------------------------------------------------
# Splitting.
# ---------------------------------------------------------------------------


class Fragment:
    """One assembly file the split produced, and where it sits in link order."""

    __slots__ = ("index", "text", "after", "routines")

    def __init__(self, index, text, after=(), routines=()):
        self.index = index
        self.text = text
        # The ported routines whose positions this fragment follows, in source
        # order; empty for the first. Several where consecutive ported routines
        # left nothing between them. A bare string is wrapped, since tuple()
        # would split it.
        self.after = (after,) if isinstance(after, str) else tuple(after)
        self.routines = tuple(routines)

    def __repr__(self):
        return "<fragment %d, %d routine(s)%s>" % (
            self.index, len(self.routines),
            " after %s" % ", ".join(self.after) if self.after else "")


def split_points(text):
    """The ported routines the assembly marks, in source order."""
    found = []
    for number, line in enumerate(text.splitlines(), start=1):
        stripped = line.strip()
        if stripped.startswith(SPLIT_MARKER):
            found.append((number, stripped[len(SPLIT_MARKER):].strip()))
    return found


# The type a data definition's directive gives its symbol, for the EXTRN
# another fragment needs.
DATA_TYPE = {"DB": "BYTE", "DW": "WORD", "DD": "DWORD", "DQ": "QWORD",
             "DT": "TBYTE"}

# Symbol kinds another object can be pointed at; a segment or group name is not
# one.
DEFINING_KINDS = ("proc", "label", "data", "equ")


def _host_segment(parsed, marks, where):
    """The segment every split marker sits in. It has to be one: a split cuts
    one segment's contribution in two."""
    hosts = {}
    for number, name in marks:
        for segment in parsed.segments.values():
            if (segment.end_line is not None
                    and segment.start_line < number < segment.end_line):
                hosts.setdefault(segment.name, []).append(name)
                break
        else:
            raise TransformError(
                "cannot split %s: the marker for %s on line %d is not inside "
                "any segment" % (where, name, number))
    if len(hosts) > 1:
        raise TransformError(
            "cannot split %s: the ported routines are spread over %s, and a "
            "split cuts one segment"
            % (where, " and ".join("%s (%s)" % (segment, ", ".join(names))
                                   for segment, names in sorted(hosts.items()))))
    return parsed.segments[next(iter(hosts))]


def _extern_type(parsed, name, where):
    """What `EXTRN name:...` has to say, read off the definition."""
    symbol = parsed.symbols[name]
    if symbol.kind == "proc":
        procedure = parsed.procedures.get(name)
        return (procedure.distance or "NEAR").upper() if procedure else "NEAR"
    if symbol.kind == "equ":
        return "ABS"
    if symbol.kind == "label":
        return "NEAR"
    line = parsed.lines[symbol.definition.token.line - 1]
    words = line.split()
    if len(words) >= 2 and words[1].upper() in DATA_TYPE:
        return DATA_TYPE[words[1].upper()]
    raise TransformError(
        "cannot split %s: %s is defined on line %d by something of unknown "
        "width: %r"
        % (where, name, symbol.definition.token.line, line.strip()))


class _Plan:
    """Which fragment defines each symbol, and which mention it, from one parse
    of the whole file. A symbol mentioned where it is not defined crosses:
    PUBLIC where defined, EXTRN where used. Symbols of the shared header are
    in every fragment and never cross."""

    def __init__(self, parsed, ranges, head_end):
        self.parsed = parsed
        self.ranges = ranges            # [(first, last), ...] per fragment
        self.head_end = head_end
        self.defined = {}               # symbol -> fragment that defines it
        self.used = {}                  # symbol -> {fragments mentioning it}
        self.mentions = {}              # every symbol, defining kind or not
        for name, symbol in parsed.symbols.items():
            for occurrence in symbol.occurrences:
                index = self.fragment_of(occurrence.token.line)
                if index is None:
                    continue
                if not occurrence.defining:
                    self.mentions.setdefault(name, set()).add(index)
                if symbol.kind not in DEFINING_KINDS:
                    continue
                if occurrence.defining:
                    self.defined[name] = index
                else:
                    self.used.setdefault(name, set()).add(index)

    def fragment_of(self, line):
        for index, spans in enumerate(self.ranges):
            for first, last in spans:
                if first <= line <= last:
                    return index
        return None

    def in_head(self, name):
        definition = self.parsed.symbols[name].definition
        return definition is not None and definition.token.line <= self.head_end

    def crossing(self):
        """(symbol, defining fragment, using fragment), in definition order."""
        out = []
        ordered = sorted(
            self.defined,
            key=lambda name: self.parsed.symbols[name].definition.token.line)
        for name in ordered:
            if self.in_head(name):
                continue
            owner = self.defined[name]
            for user in sorted(self.used.get(name, ())):
                if user != owner:
                    out.append((name, owner, user))
        return out


def _first_content_segment(lines):
    """The line where the first segment with something in it opens; everything
    above is the header every fragment gets. It is the first `X SEGMENT` not
    closed by the very next line."""
    def code(index):
        """The next line that is neither blank nor a comment, from `index`."""
        while index < len(lines):
            stripped = lines[index].strip()
            if stripped and not stripped.startswith(";"):
                return lines[index].split()
            index += 1
        return []

    for number, line in enumerate(lines, start=1):
        stripped = line.strip()
        # A comment, and one that begins "; Segment order" sits directly
        # above the declarations. Its second word is SEGMENT.
        if not stripped or stripped.startswith(";"):
            continue
        words = line.split()
        if len(words) < 2 or words[1].upper() != "SEGMENT":
            continue
        following = code(number)
        if (len(following) >= 2 and following[0] == words[0]
                and following[1].upper() == "ENDS"):
            continue
        return number
    raise TransformError("no segment in the assembly is ever opened")


def _segment_of_symbol(parsed, name):
    """The segment a symbol is defined in, or None for one outside them all."""
    line = parsed.symbols[name].definition.token.line
    for segment in parsed.segments.values():
        if (segment.end_line is not None
                and segment.start_line <= line <= segment.end_line):
            return segment
    return None


def _needed_segments(index, parsed, plan, host):
    """The segments a fragment declares, or None for the one that keeps them
    all. As few as possible: LINK applies an empty segment's alignment too,
    padding what came before it."""
    if not index:
        return None
    keep = {host.name}
    # The DGROUP members, which the ASSUME naming the group needs.
    for members in parsed.groups.values():
        keep.update(members)
    # And any segment this fragment names outright, as `MOV DX,FARDATA` does.
    keep.update(name for name, symbol in parsed.symbols.items()
                if symbol.kind == "segment"
                and index in plan.mentions.get(name, ()))
    return keep


def _extern_home(kind, segment, keep):
    """Which segment's declaration an EXTRN goes inside, or None for file
    scope. Inside where the fragment declares that segment anyway, so the
    offset is measured from the symbol's own segment and group; a FAR or
    absolute fixup carries its own frame and goes at file scope."""
    if kind in ("FAR", "ABS") or segment is None:
        return None
    if keep is not None and segment.name not in keep:
        return None
    return segment.name


def _carries_code(slice_):
    """Whether a fragment's slice of the host segment holds anything but
    comments, as the slice between two consecutive ported routines does not."""
    for line in slice_:
        stripped = line.strip()
        if stripped and not stripped.startswith(";"):
            return True
    return False


def split_assembly(text, path=None):
    """Cut the assembly at each ported routine into fragments, each a complete
    assembly file that LINK concatenates in order, so a routine ported out
    of the middle keeps its address. Only one fragment carries a given
    definition, and a symbol defined in one and mentioned in another is
    PUBLIC there and EXTRN here. Returns a list of Fragment; with no split
    markers, one holding the text unchanged."""
    marks = split_points(text)
    if not marks:
        return [Fragment(0, text, (), ())]

    where = path or "the assembly"
    parsed = assembly_reader.parse(text, path)
    lines = text.splitlines()

    if not parsed.segments:
        raise TransformError("cannot split %s: it declares no segments" % where)
    host = _host_segment(parsed, marks, where)
    if host.end_line is None:
        raise TransformError(
            "cannot split %s: segment %s is never closed with ENDS"
            % (where, host.name))

    first_open = _first_content_segment(lines)
    head = lines[:first_open - 1]
    before = lines[first_open - 1:host.start_line - 1]
    open_line = lines[host.start_line - 1]
    body = lines[host.start_line:host.end_line - 1]
    close_line = lines[host.end_line - 1]
    after = lines[host.end_line:]
    body_offset = host.start_line + 1        # 1-based line number of body[0]

    # An ASSUME immediately inside the segment applies to everything after it,
    # so every fragment needs its own copy.
    assume = [line for line in body[:4]
              if line.strip().upper().startswith("ASSUME")]

    cuts = []
    for number, name in marks:
        position = number - body_offset
        if 0 <= position < len(body):
            cuts.append((position, name))
    if not cuts:
        return [Fragment(0, text, (), ())]

    # Which lines of the original each fragment carries: the first the header,
    # everything before the host segment, its slice of the host and everything
    # after; the rest their slice alone.
    boundaries = [position for position, _ in cuts] + [len(body)]
    ranges = []
    start = 0
    for index, stop in enumerate(boundaries):
        span = [(body_offset + start, body_offset + stop - 1)]
        if index == 0:
            span = [(1, host.start_line)] + span + [(host.end_line, len(lines))]
        ranges.append(span)
        start = stop
    plan = _Plan(parsed, ranges, first_open - 1)

    keep = [_needed_segments(index, parsed, plan, host)
            for index in range(len(ranges))]

    already_public = set(parsed.publics)
    publics = [[] for _ in ranges]
    claimed = [set() for _ in ranges]
    externs = [{} for _ in ranges]     # fragment -> segment name or None -> lines
    for name, owner, user in plan.crossing():
        if name not in claimed[owner] and name not in already_public:
            claimed[owner].add(name)
            publics[owner].append(name)
        kind = _extern_type(parsed, name, where)
        segment = _segment_of_symbol(parsed, name)
        externs[user].setdefault(_extern_home(kind, segment, keep[user]),
                                 []).append("\tEXTRN\t%s:%s" % (name, kind))

    fragments = []
    pending = ()      # names from fragments that were dropped, still to place
    start = 0
    for index, stop in enumerate(boundaries):
        slice_ = [line for line in body[start:stop]
                  if not line.strip().startswith(SPLIT_MARKER)]
        follows = pending + ((cuts[index - 1][1],) if index else ())
        start = stop

        # A fragment between two consecutive ported routines holds no code, so
        # its names are handed to the next and nothing is emitted, unless a
        # PUBLIC or an EXTRN rides on it. The first fragment carries the header
        # and the last has no next, so both are kept.
        if (index and index < len(boundaries) - 1
                and not _carries_code(slice_)
                and not publics[index]
                and not any(externs[index].values())):
            pending = follows
            continue
        pending = ()

        piece = _fragment_text(index, plan, head, before, after, open_line,
                               close_line, assume, slice_, keep[index],
                               publics[index], externs[index])
        routines = sorted(name for name, symbol in parsed.symbols.items()
                          if symbol.kind == "proc"
                          and plan.defined.get(name) == index)
        fragments.append(Fragment(index, piece, follows, routines))

    return fragments


ALIGNMENTS = ("BYTE", "WORD", "DWORD", "PARA", "PAGE")


def _byte_aligned(line):
    """The same SEGMENT line, aligned to a byte, for every declaration but a
    segment's first: LINK applies each contribution's alignment, so a later
    one must not pad. That covers an empty declaration and the host segment
    in a continuation fragment, which has to abut what precedes it."""
    words = line.split()
    if len(words) < 2 or words[1].upper() != "SEGMENT":
        return line
    if len(words) > 2 and words[2].upper() in ALIGNMENTS:
        words[2] = "BYTE"
    else:
        words.insert(2, "BYTE")
    return "%s\tSEGMENT\t%s" % (words[0], " ".join(words[2:]))


def _fragment_text(index, plan, head, before, after, open_line, close_line,
                   assume, slice_, keep, publics, externs):
    """One fragment's source, out of the shared parts and its own."""
    out = _reduced_head(index, plan, head, keep, externs)
    if publics or externs.get(None):
        out.append("")
    for name in publics:
        out.append("\tPUBLIC\t%s" % name)
    for line in externs.get(None, ()):
        out.append(line)

    if index == 0:
        out += before + [open_line] + slice_ + [close_line] + after
    else:
        out += [""] + [_byte_aligned(open_line)] + assume + slice_ \
               + [close_line, "", "\tEND"]
    return "\n".join(out) + "\n"


def _reduced_head(index, plan, head, keep, externs):
    """The header, without what this fragment must not repeat: a PUBLIC belongs
    where the symbol is defined, an EXTRN where it is mentioned, a segment
    declaration where the fragment uses the segment. The crossing data and
    near-code externs are injected into the declarations, and every
    declaration a continuation fragment keeps is byte-aligned. `keep` is
    None for the first fragment."""
    parsed_head = assembly_reader.parse("\n".join(head))
    skip = set()
    inject = {}
    unalign = set()
    for name, segment in parsed_head.segments.items():
        if segment.end_line is None:
            continue
        if keep is not None and name not in keep:
            skip.update(range(segment.start_line, segment.end_line + 1))
            continue
        if keep is not None:
            unalign.add(segment.start_line)
        if externs.get(name):
            inject[segment.end_line] = externs[name]

    out = []
    for number, line in enumerate(head, start=1):
        if number in skip:
            continue
        if number in unalign:
            out.append(_byte_aligned(line))
            continue
        words = line.split()
        upper = words[0].upper() if words else ""
        if upper == "PUBLIC" and len(words) > 1:
            if plan.defined.get(words[1]) != index:
                continue
        if upper in ("EXTRN", "EXTERN") and len(words) > 1:
            name = words[1].split(":")[0]
            if index not in plan.mentions.get(name, set()):
                continue
        if number in inject:
            out.extend(inject[number])
        out.append(line)
    return out


def join_sources(texts):
    """Join the parts of one object into the text the tool is handed, raw,
    adding only a newline where a part does not end in one."""
    out = []
    for text in texts:
        if text and not text.endswith("\n"):
            text += "\n"
        out.append(text)
    return "".join(out)


def transform_group(parts, names, kind, crossing=None):
    """Rename each part, join them, and for assembly split the result. `parts`
    is (path, text) in join order. Renaming is per part so a diagnostic
    names its file; splitting is over the join."""
    renamed = []
    total = 0
    for path, text in parts:
        piece, count = rename(text, names, kind, path, crossing)
        renamed.append(piece)
        total += count
    joined = join_sources(renamed)
    if kind != "asm":
        return [Fragment(0, joined, (), ())], total
    return split_assembly(joined, parts[0][0] if parts else None), total


def definitions(text, names, path=None):
    """The canonical names of the routines a C file defines, which is what a
    split marker carries and `externs` is keyed on."""
    parsed = csource_reader.parse(text, path)
    return tuple(names.canonical(f.name) if names else f.name
                 for f in parsed.functions())
