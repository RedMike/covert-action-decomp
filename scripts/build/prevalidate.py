#!/usr/bin/env python3
"""Gate a module's input before build.py transforms it: every crossing symbol
is prefixed and spellable, no .C or .H spells one by its canonical name, the
manifest's files are there, and each routine is declared once and called one
way. A finding stops the build."""

import argparse
import os
import re
import sys

if __package__ in (None, ""):
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    __package__ = "build"

from lib import layout
from lib import manifest as manifest_lib
from lib import spelling
from interop import csource as csource_reader
from shared import logging as shared_logging
from shared.metrics import Metrics

from . import shared_sync

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SRC_ROOT = layout.src_root(REPO_ROOT)

# DOS truncates a stem past 8 rather than refusing.
DOS_STEM = 8


def source_kind_of(path):
    return "c" if path.lower().endswith((".c", ".h")) else "asm"

# Tried in order: a crossing symbol's prefix says what kind of thing it is.
PREFIX_NAMES = (
    "drv_", "run_", "shd_", "shm_", "c_", "todo_", "asm_", "dat_", "addr_",
)

# A legal C identifier; s_'$.$6$C$O$Average_20d8_247e is not one.
C_IDENTIFIER = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")

# Identifiers inside a preprocessor directive, which the C parse keeps opaque.
IDENTIFIER = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")

# src/shared/PORTING.H's macros; the suffix says how many each stands for.
UNSET = re.compile(r"^UNSET_(ARGS|PARAMS)([2-8])?$")
UNCHECKED = re.compile(r"^UNCHECKED_PARAMS([2-8])?$")


class Finding:
    """One thing that is wrong: a code, a place and a severity. An error stops
    the build; a warning is printed and nothing more."""

    __slots__ = ("code", "message", "path", "line", "severity")

    def __init__(self, code, message, path=None, line=None, severity="error"):
        self.code = code
        self.message = message
        self.path = path
        self.line = line
        self.severity = severity

    @property
    def is_warning(self):
        return self.severity == "warning"

    @property
    def where(self):
        if self.path and self.line:
            return "%s:%d" % (_relative(self.path), self.line)
        if self.path:
            return _relative(self.path)
        return ""

    def __str__(self):
        place = self.where
        return "%s%s%s: %s" % (self.code,
                               " warning" if self.is_warning else "",
                               " at %s" % place if place else "",
                               self.message)


def _relative(path):
    try:
        return os.path.relpath(path, REPO_ROOT).replace(os.sep, "/")
    except ValueError:
        return path


class Report:
    def __init__(self, module):
        self.module = module
        self.findings = []

    def add(self, *args, **kwargs):
        self.findings.append(Finding(*args, **kwargs))

    @property
    def errors(self):
        return [f for f in self.findings if not f.is_warning]

    @property
    def warnings(self):
        return [f for f in self.findings if f.is_warning]

    @property
    def ok(self):
        return not self.errors


def crossing(module):
    """The canonical names that cross: `publics` then `externs`, in manifest
    order, deduplicated -- exactly what the module's `.H` declares."""
    out = []
    for name in tuple(module.porting.publics) + tuple(module.porting.externs):
        if name not in out:
            out.append(name)
    return out


# ---------------------------------------------------------------------------
# P: the prefixes.
# ---------------------------------------------------------------------------


def prefix_of(name):
    """Which prefix a name carries, or None."""
    for prefix in PREFIX_NAMES:
        if name.startswith(prefix) and len(name) > len(prefix):
            return prefix
    return None


def check_prefixes(module, report):
    """Every crossing symbol is renamed to something prefixed and spellable."""
    path = module.path
    names = crossing(module)
    if not names:
        return

    for name in names:
        # A library name like `_strcpy` crosses as it is and is never renamed.
        meaningful = module.names.meaningful(name)
        if spelling.library_spelling(name, meaningful):
            continue

        if prefix_of(meaningful) is None:
            report.add(
                "P001",
                "%s crosses as %r, which carries no prefix (one of %s)"
                % (name, meaningful, " ".join(PREFIX_NAMES)), path)

        if not C_IDENTIFIER.match(meaningful):
            report.add(
                "P004",
                "%s is renamed to %r, which is not a legal C identifier"
                % (name, meaningful), path)


def check_rename_map(module, report):
    """No meaningful name is already another symbol's canonical name, the
    direction `Names` cannot see. Every entry, not only the crossing ones."""
    named = module.names.named()
    if not named:
        return
    canonical = set(named) | set(crossing(module))

    for name, meaningful in sorted(named.items()):
        if meaningful != name and meaningful in canonical:
            report.add(
                "P010",
                "%s is renamed to %r, which is another symbol's canonical "
                "name; the map is read both ways" % (name, meaningful),
                module.path)


# ---------------------------------------------------------------------------
# P002/P003: what the C side actually spells.
# ---------------------------------------------------------------------------


def check_spelling(module, report):
    """No `.C` or `.H` names a crossing symbol by its canonical name:
    transform.py passes an unmapped identifier through, so it compiles as if
    renamed."""
    renamed = {}
    for name in crossing(module):
        meaningful = module.names.meaningful(name)
        if meaningful != name:
            renamed[name] = meaningful
    if not renamed:
        return

    # Every C the manifest compiles, plus the shared header staged beside it.
    checked = ([module.source_path(".H"), layout.driver_header(REPO_ROOT)]
               + list(module.c_sources()))
    for path in checked:
        if not os.path.isfile(path):
            continue
        try:
            unit = load_source(path)
        except csource_reader.CSourceError as error:
            report.add("P020", "cannot be parsed: %s" % error, path)
            continue

        for occurrence in unit.renameable_occurrences():
            if occurrence.name in renamed:
                report.add(
                    "P002",
                    "spells %s, the canonical name, which reaches the compiler "
                    "unmapped; the prefixed name is %r"
                    % (occurrence.name, renamed[occurrence.name]),
                    path, occurrence.line)

        for token in unit.tokens:
            if token.kind != "directive":
                continue
            for found in IDENTIFIER.findall(token.text):
                if found in renamed:
                    report.add(
                        "P003",
                        "names %s inside a preprocessor directive, which the "
                        "parse cannot rename" % found,
                        path, token.line)
                elif found in renamed.values():
                    report.add(
                        "P003",
                        "names %s inside a preprocessor directive, so it "
                        "reaches CL unmapped" % found,
                        path, token.line)


# ---------------------------------------------------------------------------
# S: the files the build is about to read.
# ---------------------------------------------------------------------------


def check_sources(module, report):
    """The manifest names files, and the files are there and make a set."""
    path = module.path

    if not module.objects:
        report.add(
            "S001", "lists no objects", path)
        return

    compiled = []
    targets = []
    for spec in module.object_sources():
        target, sources, tool, link = (spec.target, spec.sources,
                                       spec.tool, spec.link)
        targets.append(target)
        for source in sources:
            if not os.path.isfile(source):
                report.add(
                    "S002",
                    "%s is listed in [[objects]] and is not on disk"
                    % _relative(source), path)
            if tool == "cl":
                compiled.append((source, link))
        if source_kind_of(target) != "asm":
            odd = [s for s in sources if source_kind_of(s) == "asm"]
            if odd:
                report.add(
                    "S005",
                    "%s joins %s, which is assembly; a target is one language"
                    % (target, ", ".join(map(_relative, odd))), path)

    # Stem *and* extension: build.py separates TESTMOD.ASM from TESTMOD.C.
    keys = [(os.path.splitext(t)[0].upper()[:DOS_STEM],
             os.path.splitext(t)[1].upper()) for t in targets]
    clashing = sorted({"%s%s" % k for k in keys if keys.count(k) > 1})
    if clashing:
        report.add(
            "S006",
            "two [[objects]] targets share the 8.3 name %s, so one object "
            "overwrites the other" % ", ".join(clashing), path)

    header = module.source_path(".H")
    # On disk, not in [[objects]]: a module may carry C it does not compile yet.
    csources = sorted(set(layout.c_files(module.directory))
                      | {s for s in module.c_sources() if os.path.isfile(s)})
    has_header = os.path.isfile(header)
    has_c = bool(csources)

    if has_c and not has_header:
        report.add(
            "S003",
            "there is C under src/ and no %s.H for it to reach the assembly "
            "through" % module.name, csources[0])
    if compiled and not has_header:
        report.add(
            "S004",
            "[[objects]] compiles %s and there is no %s.H to include"
            % (_relative(compiled[0][0]), module.name), path)

    check_ported(module, compiled, report)
    check_shared_chunks(module, report)


CHUNK_CODES = {"unpaired": "S020", "unresolved": "S021", "diverged": "S022"}

# The group whose modules are real C and so keep their empty routines apart.
GAME_GROUP = "modules"


def check_shared_chunks(module, report):
    """Every shared chunk is paired, names a file, and holds that file's text."""
    for path in layout.c_files(module.directory):
        for kind, line, message in shared_sync.findings(path):
            report.add(CHUNK_CODES[kind], message, path, line)
        check_placement(module, path, report)


def check_placement(module, path, report):
    """Chunks under c/shared/, a game module's empty routines under c/stubs/,
    the rest under c/."""
    with open(path, "r", encoding="utf-8", newline="") as handle:
        text = handle.read()
    try:
        chunks = shared_sync.parse(text, path)
        functions = csource_reader.parse(text, path).functions()
    except (shared_sync.ChunkError, csource_reader.CSourceError):
        return
    game = layout.group_of(module.directory) == GAME_GROUP
    part = layout.code_part(path)
    spans = [(c.line, text.count("\n", 0, c.body_end) + 1) for c in chunks]
    if part == layout.STUBS_CODE_DIR:
        if chunks:
            report.add("S026", "a shared chunk under c/stubs/, which holds only "
                       "the module's own empty routines", path, chunks[0].line)
    elif chunks and part != layout.SHARED_CODE_DIR:
        report.add(
            "S023",
            "a shared chunk under c/, where only the module's own routines "
            "go; the chunk goes in a file under c/shared/", path,
            chunks[0].line)
    for function in functions:
        chunked = any(a <= function.line <= b for a, b in spans)
        empty = is_empty(function)
        if part == layout.STUBS_CODE_DIR and not empty:
            report.add("S026", "%s has a body; c/stubs/ holds only empty "
                       "routines" % function.name, path, function.line)
        elif game and empty and part != layout.STUBS_CODE_DIR:
            report.add("S025", "%s is empty, and a game module's empty routines "
                       "go in a file under c/stubs/" % function.name, path,
                       function.line)
        elif part == layout.SHARED_CODE_DIR and not chunked:
            report.add(
                "S024",
                "%s is the module's own, outside every shared chunk; c/shared/ "
                "holds only shared routines, so it goes in a file under c/"
                % function.name, path, function.line)


def is_empty(function):
    """Whether a routine's body holds nothing: a lone RET once compiled."""
    tokens = [token.text for token in function.tokens]
    return tokens[tokens.index("{") + 1:-1] == []


def check_ported(module, compiled, report):
    """Naming a routine in `externs` removes its body from the assembly and
    leaves an EXTRN, so a linked C source has to define it."""
    if not module.porting.externs:
        return

    defined = {}
    for source, link in compiled:
        if not os.path.isfile(source):
            continue
        try:
            unit = load_source(source)
        except csource_reader.CSourceError:
            continue  # reported as P020 where the file is parsed for spelling
        for function in unit.functions():
            if function.name:
                defined.setdefault(function.name, (source, link))

    for name in module.porting.externs:
        meaningful = module.names.meaningful(name)
        if meaningful not in defined:
            report.add(
                "S010",
                "%s is ported in `externs` and no compiled source defines %r"
                % (name, meaningful), module.path)
            continue
        source, link = defined[meaningful]
        if not link:
            report.add(
                "S011",
                "%s is ported and %s defines it, but that source is "
                "`link = false`" % (name, _relative(source)), module.path)


# ---------------------------------------------------------------------------
# D: the declarations.
# ---------------------------------------------------------------------------


def load_source(path):
    """A C source, shared chunks and all, as the compiler sees it."""
    if not os.path.isfile(path):
        raise csource_reader.CSourceError("no C source at %s" % path)
    with open(path, "r", encoding="utf-8", newline="") as handle:
        text = handle.read()
    return csource_reader.parse(text, path)


def c_sources_on_disk(module):
    """Every C source of the module, deduplicated, in manifest order -- on disk
    rather than in `[[objects]]`, since what is written is still written."""
    out = []
    for path in [module.source_path(".C")] + list(module.c_sources()):
        if path not in out and os.path.isfile(path):
            out.append(path)
    return out


def headers_of(module):
    """Every `.H` the module's C can include, its own then shared -- the same
    set `build.py` stages, and so the same set the compiler sees."""
    out = list(module.headers())
    shared = layout.shared_dir(REPO_ROOT)
    if os.path.isdir(shared):
        for entry in sorted(os.listdir(shared)):
            path = os.path.join(shared, entry)
            if entry.upper().endswith(".H") and os.path.isfile(path):
                out.append(path)
    return out


def check_forward_declarations(module, report):
    """No `.C` declares a routine a `.H` should declare. Routines only."""
    read = c_sources_on_disk(module)
    declarations = 0

    for path in read:
        try:
            unit = load_source(path)
        except csource_reader.CSourceError:
            continue  # reported as P020 where the file is parsed for spelling

        for node in unit.prototypes():
            declarations += 1
            report.add(
                "D001",
                "declares %s here rather than in a .H" % node.name,
                path, node.line)


def variadic_in(unit):
    """The routines this file declares or defines with an ellipsis, written as
    one or as `UNCHECKED_PARAMS`."""
    return set(node.name for node in unit.declarations
               if node.name and node.kind in ("function", "prototype")
               and (node.is_variadic or _unchecked(node)))


def _unchecked(node):
    """Whether a parameter is spelled through `UNCHECKED_PARAMS`."""
    return any(token.kind == "ident" and UNCHECKED.match(token.text)
               for parameter in node.parameters for token in parameter)


def arguments_at(call):
    """How many arguments a site really passes: `UNSET_ARGS` is written as one
    argument, expands to nothing, and counts as what it stands for."""
    total = 0
    for argument in call.arguments:
        stands_for = 1
        if argument and argument[0].kind == "ident":
            found = UNSET.match(argument[0].text)
            if found and found.group(1) == "ARGS" and _is_whole_call(argument):
                stands_for = int(found.group(2) or 1)
        total += stands_for
    return total


def _is_whole_call(argument):
    """Whether these tokens are one macro invocation and nothing else:
    `UNSET_ARGS(a) + 1` is an expression that merely starts with one."""
    if len(argument) < 3 or argument[1].text != "(":
        return False
    depth = 0
    for position, token in enumerate(argument[1:], 1):
        if token.kind != "punct":
            continue
        if token.text in "([{":
            depth += 1
        elif token.text in ")]}":
            depth -= 1
            if depth == 0:
                return position == len(argument) - 1
    return False


def check_argument_counts(module, report):
    """Every call site of a routine passes the same count; a variadic routine
    is left alone."""
    sources = c_sources_on_disk(module)
    if not sources:
        return

    sites = {}
    variadic = set()

    # A header declares and does not call; a source does both.
    for path in headers_of(module) + sources:
        try:
            unit = load_source(path)
        except csource_reader.CSourceError:
            continue  # reported as P020 where the file is parsed for spelling
        variadic |= variadic_in(unit)
        if path not in sources:
            continue
        for call in unit.calls():
            if UNSET.match(call.name):
                continue
            sites.setdefault(call.name, []).append(
                (path, call.line, arguments_at(call)))

    disagreeing = 0

    for name in sorted(sites):
        found = sites[name]
        counts = sorted({count for _, _, count in found})
        if len(counts) < 2 or name in variadic:
            continue
        disagreeing += 1

        detail = "; ".join(
            "%d at %s" % (count, ", ".join(
                "%s:%d" % (_relative(where), at)
                for where, at, taken in found if taken == count))
            for count in counts)
        source, line, _ = found[0]
        report.add(
            "D002",
            "%s is called with %s arguments (%s), which all link"
            % (name, _listed(["%d" % count for count in counts]), detail),
            source, line)


def _listed(items):
    """`2`, `2 and 3`, `2, 3 and 4` -- a list as a reader would say it."""
    if len(items) < 3:
        return " and ".join(items)
    return "%s and %s" % (", ".join(items[:-1]), items[-1])


# ---------------------------------------------------------------------------
# Driver.
# ---------------------------------------------------------------------------


CHECKS = (
    ("sources", check_sources),
    ("prefixes", check_prefixes),
    ("rename_map", check_rename_map),
    ("spelling", check_spelling),
    ("forward_declarations", check_forward_declarations),
    ("argument_counts", check_argument_counts),
)


def module_source(name):
    return "prevalidate.%s" % name


def prevalidate(module_name):
    metrics = Metrics()
    module = manifest_lib.open_module(module_name)
    log = shared_logging.get_logger(module_source(module.name))
    log.info("Checking module", module=module.name)
    report = Report(module.name)
    for name, check in CHECKS:
        with metrics.stage(name):
            check(module, report)
        log.debug("Check finished", module=module.name, check=name,
                  duration_ms=metrics.stage_ms(name))
    if not report.ok:
        report_at = log.error
    elif report.warnings:
        report_at = log.warning
    else:
        report_at = log.info
    report_at("Checked module", module=module.name, success=report.ok,
              errors=len(report.errors), warnings=len(report.warnings),
              duration_ms=metrics.total_ms)
    return report


def modules():
    return layout.names(SRC_ROOT)


def report_lines(report):
    """One module's result, as the lines to print."""
    counted = "%d finding(s)" % len(report.errors)
    if report.warnings:
        counted += ", %d warning(s)" % len(report.warnings)
    out = ["prevalidate: %s -- %s (%s)"
           % (report.module, "OK" if report.ok else "FAILED", counted)]
    for finding in report.findings:
        out.append("  %s" % finding)
    return out


def main(argv=None):
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("module", nargs="*",
                        help="module name (default: every module)")
    shared_logging.add_arguments(parser)
    args = parser.parse_args(argv)
    shared_logging.configure(args, "prevalidate")

    wanted = args.module or modules()
    failed = 0

    for name in wanted:
        try:
            report = prevalidate(name)
        except manifest_lib.ManifestError as error:
            print("prevalidate: %s: %s" % (name, error), file=sys.stderr)
            failed += 1
            continue
        for line in report_lines(report):
            print(line)
        if not report.ok:
            failed += 1

    if failed:
        print("prevalidate: %d of %d module(s) failed"
              % (failed, len(wanted)), file=sys.stderr)
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
