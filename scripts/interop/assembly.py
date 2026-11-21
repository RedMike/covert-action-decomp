#!/usr/bin/env python3
"""Read the assembly side of a module: `parse(text, name)` gives its segments,
procedures, symbols and positioned identifier tokens, and modifies nothing.

Not a full parser: structure comes from PROC/ENDP, labels, SEGMENT/ENDS,
EXTRN, COMM, PUBLIC, GROUP, EQU, LABEL and named data definitions. It
tokenises, so a name inside a comment or a string is not a mention."""

import re

# MASM identifiers. A leading dot starts a directive, so it is tokenised as
# punctuation and the directive's name comes out as the identifier after it.
IDENT_START = "A-Za-z_$?@"
IDENT_BODY = "A-Za-z0-9_$?@"
IDENT = re.compile("[%s][%s]*" % (IDENT_START, IDENT_BODY))

# A number, so `0FFh` and `1010b` are never taken for identifiers.
NUMBER = re.compile(r"[0-9][0-9A-Fa-f]*[hHbBoOdD]?")

# Data definition directives, and the size each reserves.
DATA_DIRECTIVES = {"DB": 1, "DW": 2, "DD": 4, "DF": 6, "DQ": 8, "DT": 10}

# Directives that define the symbol in front of them: `name PROC`.
DEFINING = {"PROC", "SEGMENT", "EQU", "=", "LABEL", "STRUC", "RECORD",
            "MACRO"} | set(DATA_DIRECTIVES)

# Prefixes that stand in front of a mnemonic rather than being one.
PREFIXES = {"REP", "REPE", "REPZ", "REPNE", "REPNZ", "LOCK"}

# Directives whose operand is text rather than a symbol: `TITLE INTRO` names
# no symbol.
TEXT_DIRECTIVES = {"TITLE", "SUBTTL", "NAME", "PAGE", "COMMENT", "INCLUDE",
                   "IFDEF", "IFNDEF"}

# MASM's own symbols: `$` is the location counter and `?` an uninitialised
# value.
SPECIAL = {"$", "?"}

# Keywords that are never symbols, so a mention of one is not an edge. Not
# exhaustive: an unknown word is taken for a symbol. Mnemonics are found by
# position instead.
RESERVED = {
    # registers
    "AX", "BX", "CX", "DX", "AL", "BL", "CL", "DL", "AH", "BH", "CH", "DH",
    "SI", "DI", "BP", "SP", "CS", "DS", "ES", "SS", "FS", "GS", "IP", "FLAGS",
    # size and pointer keywords
    "BYTE", "WORD", "DWORD", "FWORD", "QWORD", "TBYTE", "PTR", "SHORT",
    "NEAR", "FAR", "OFFSET", "SEG", "TYPE", "LENGTH", "SIZE", "WIDTH", "MASK",
    "THIS", "HIGH", "LOW", "ST",
    # combine/align/class keywords used on SEGMENT lines
    "PUBLIC", "COMMON", "STACK", "MEMORY", "AT", "PRIVATE", "PARA", "BYTE",
    "PAGE", "INPAGE", "USE16", "USE32",
    # `ASSUME es:NOTHING`: a keyword, not a symbol named NOTHING.
    "NOTHING",
    # operators
    "AND", "OR", "XOR", "NOT", "SHL", "SHR", "MOD", "EQ", "NE", "LT", "LE",
    "GT", "GE", "DUP",
    # structural directives
    "SEGMENT", "ENDS", "PROC", "ENDP", "END", "ASSUME", "GROUP", "EXTRN",
    "EXTERN", "PUBLIC", "INCLUDE", "IF", "IFE", "ELSE", "ENDIF", "TITLE",
    "SUBTTL", "PAGE", "NAME", "ORG", "EVEN", "ALIGN", "EQU", "LABEL", "MACRO",
    "ENDM", "STRUC", "RECORD", "COMMENT", "COMM",
}


class Token:
    """One lexical item, with where it sits in the file."""

    __slots__ = ("kind", "text", "line", "column", "start", "end")

    def __init__(self, kind, text, line, column, start, end):
        self.kind = kind          # ident | number | string | punct
        self.text = text
        self.line = line          # 1-based
        self.column = column      # 1-based
        self.start = start        # absolute offset into the source text
        self.end = end

    @property
    def upper(self):
        return self.text.upper()

    def __repr__(self):
        return "<%s %r @%d:%d>" % (self.kind, self.text, self.line, self.column)


class Occurrence:
    """One mention of a symbol, and what contained it."""

    __slots__ = ("name", "token", "container", "defining")

    def __init__(self, name, token, container, defining=False):
        self.name = name
        self.token = token
        self.container = container   # procedure or segment name, or None
        self.defining = defining     # True where this is the definition site

    @property
    def line(self):
        return self.token.line

    @property
    def column(self):
        return self.token.column

    def __repr__(self):
        return "<%s %s at %d:%d%s>" % (
            "def" if self.defining else "use", self.name,
            self.line, self.column, " in %s" % self.container
            if self.container else "")


class Symbol:
    """A name the file defines or declares, and everywhere it is mentioned."""

    __slots__ = ("name", "kind", "definition", "occurrences")

    def __init__(self, name, kind, definition=None):
        self.name = name
        # proc | label | data | segment | equ | extrn | comm | group
        self.kind = kind
        self.definition = definition
        self.occurrences = []

    @property
    def defined(self):
        """Whether the storage is here: `extrn` and `comm` only declare."""
        return self.kind not in ("extrn", "comm")

    def __repr__(self):
        return "<%s %s (%d mention(s))>" % (self.kind, self.name,
                                            len(self.occurrences))


class Procedure:
    """A PROC..ENDP span."""

    __slots__ = ("name", "distance", "start_line", "end_line", "lines")

    def __init__(self, name, distance, start_line):
        self.name = name
        self.distance = distance      # NEAR | FAR | None
        self.start_line = start_line  # 1-based, the PROC line
        self.end_line = None          # the ENDP line
        self.lines = []               # source lines between them, verbatim

    @property
    def body(self):
        return self.lines

    def __repr__(self):
        return "<proc %s %s..%s>" % (self.name, self.start_line, self.end_line)


class Segment:
    """A SEGMENT..ENDS span."""

    __slots__ = ("name", "align", "combine", "klass", "start_line", "end_line",
                 "procedures")

    def __init__(self, name, align, combine, klass, start_line):
        self.name = name
        self.align = align
        self.combine = combine
        self.klass = klass
        self.start_line = start_line
        self.end_line = None
        self.procedures = []

    def __repr__(self):
        return "<segment %s %s..%s>" % (self.name, self.start_line,
                                        self.end_line)


def tokenize(text):
    """Every code token in the source, comments and string bodies dropped."""
    tokens = []
    line_number = 1
    line_start = 0
    index = 0
    length = len(text)

    while index < length:
        char = text[index]

        if char == "\n":
            line_number += 1
            index += 1
            line_start = index
            continue

        if char in " \t\r":
            index += 1
            continue

        if char == ";":
            while index < length and text[index] != "\n":
                index += 1
            continue

        if char in "'\"":
            quote = char
            index += 1
            while index < length and text[index] != quote:
                if text[index] == "\n":
                    break
                index += 1
            index += 1  # past the closing quote
            continue

        if char.isdigit():
            match = NUMBER.match(text, index)
            token_text = match.group(0) if match else char
            tokens.append(Token("number", token_text, line_number,
                                index - line_start + 1, index,
                                index + len(token_text)))
            index += len(token_text)
            continue

        match = IDENT.match(text, index)
        if match:
            token_text = match.group(0)
            tokens.append(Token("ident", token_text, line_number,
                                index - line_start + 1, index, match.end()))
            index = match.end()
            continue

        tokens.append(Token("punct", char, line_number,
                            index - line_start + 1, index, index + 1))
        index += 1

    return tokens


def _by_line(tokens):
    """Group tokens into lines, dropping lines with none."""
    grouped = {}
    for token in tokens:
        grouped.setdefault(token.line, []).append(token)
    return grouped


class Assembly:
    """One .ASM file, read once at construction."""

    def __init__(self, text, path=None):
        self.text = text
        self.path = path
        self.lines = text.splitlines()
        self.tokens = tokenize(text)
        self.symbols = {}
        self.procedures = {}
        self.segments = {}
        self.groups = {}
        self.externs = {}
        self.communals = {}
        self.publics = []
        self.occurrences = []
        self._parse()

    # ------------------------------------------------------------- parsing

    def _symbol(self, name, kind=None, definition=None):
        symbol = self.symbols.get(name)
        if symbol is None:
            symbol = Symbol(name, kind or "unknown", definition)
            self.symbols[name] = symbol
        elif kind and symbol.kind == "unknown":
            symbol.kind = kind
            symbol.definition = definition
        return symbol

    def _record(self, name, token, container, defining=False, kind=None):
        symbol = self._symbol(name, kind)
        occurrence = Occurrence(name, token, container, defining)
        symbol.occurrences.append(occurrence)
        self.occurrences.append(occurrence)
        if defining and symbol.definition is None:
            symbol.definition = occurrence
        return occurrence

    def _parse(self):
        grouped = _by_line(self.tokens)
        procedure = None
        segment = None

        for number in sorted(grouped):
            row = grouped[number]
            container = procedure.name if procedure else (
                segment.name if segment else None)

            if procedure is not None:
                procedure.lines.append(self.lines[number - 1])

            words = [t.upper for t in row]

            # `name DIRECTIVE ...` -- a definition whose name precedes it.
            if len(row) >= 2 and row[0].kind == "ident" and words[1] in DEFINING:
                name, directive = row[0].text, words[1]

                if directive == "PROC":
                    distance = words[2] if len(row) > 2 else None
                    procedure = Procedure(name, distance, number)
                    procedure.lines.append(self.lines[number - 1])
                    self.procedures[name] = procedure
                    if segment is not None:
                        segment.procedures.append(name)
                    self._record(name, row[0], segment.name if segment else None,
                                 defining=True, kind="proc")
                    continue

                if directive == "SEGMENT":
                    align = combine = klass = None
                    for token in row[2:]:
                        if token.kind == "string":
                            klass = token.text
                        elif token.upper in ("PARA", "BYTE", "WORD", "DWORD",
                                             "PAGE"):
                            align = token.upper
                        elif token.upper in ("PUBLIC", "COMMON", "STACK",
                                             "MEMORY", "PRIVATE", "AT"):
                            combine = token.upper
                    # The class is a quoted string, which the tokeniser drops;
                    # read it off the raw line.
                    quoted = re.search(r"'([^']*)'", self.lines[number - 1])
                    if quoted:
                        klass = quoted.group(1)
                    segment = Segment(name, align, combine, klass, number)
                    self.segments[name] = segment
                    self._record(name, row[0], None, defining=True,
                                 kind="segment")
                    continue

                kind = {"EQU": "equ", "=": "equ", "LABEL": "label"}.get(
                    directive, "data")
                self._record(name, row[0], container, defining=True, kind=kind)
                self._mentions(row[2:], container)
                continue

            # `name ENDP` / `name ENDS`
            if len(row) >= 2 and row[0].kind == "ident":
                if words[1] == "ENDP":
                    if procedure is not None:
                        procedure.end_line = number
                        procedure = None
                    continue
                if words[1] == "ENDS":
                    if segment is not None:
                        segment.end_line = number
                        segment = None
                    continue
                if words[1] == "GROUP":
                    members = [t.text for t in row[2:] if t.kind == "ident"]
                    self.groups[row[0].text] = members
                    self._record(row[0].text, row[0], None, defining=True,
                                 kind="group")
                    self._mentions(row[2:], container)
                    continue

            # `label:` -- a plain code label.
            if (len(row) >= 2 and row[0].kind == "ident"
                    and row[1].kind == "punct" and row[1].text == ":"
                    and row[0].upper not in RESERVED):
                self._record(row[0].text, row[0], container, defining=True,
                             kind="label")
                self._mentions(row[2:], container)
                continue

            # `EXTRN name:type, ...`
            if words[0] in ("EXTRN", "EXTERN"):
                for index, token in enumerate(row[1:], start=1):
                    if token.kind != "ident":
                        continue
                    following = row[index + 1] if index + 1 < len(row) else None
                    if following and following.text == ":":
                        self.externs[token.text] = (
                            row[index + 2].text
                            if index + 2 < len(row) else None)
                        self._record(token.text, token, None, defining=True,
                                     kind="extrn")
                continue

            # `COMM [NEAR|FAR] name:type[:count], ...`: a communal variable,
            # declared and not defined, as EXTRN's is.
            if words[0] == "COMM":
                for index, token in enumerate(row[1:], start=1):
                    if token.kind != "ident" or token.upper in RESERVED:
                        continue
                    following = row[index + 1] if index + 1 < len(row) else None
                    if not following or following.text != ":":
                        continue
                    self.communals[token.text] = (
                        row[index + 2].text if index + 2 < len(row) else None)
                    self._record(token.text, token, None, defining=True,
                                 kind="comm")
                continue

            # `PUBLIC name, ...`
            if words[0] == "PUBLIC":
                for token in row[1:]:
                    if token.kind == "ident":
                        self.publics.append(token.text)
                        self._record(token.text, token, None)
                continue

            # Anything left is an instruction or a directive line: its first
            # identifier is the mnemonic or the directive, after any repeat or
            # lock prefix.
            if words and words[0] in TEXT_DIRECTIVES:
                continue
            start = 0
            while (start < len(row) and row[start].kind == "ident"
                   and row[start].upper in PREFIXES):
                start += 1
            if start < len(row) and row[start].kind == "ident":
                start += 1          # the mnemonic itself
            self._mentions(row[start:], container)

    def _mentions(self, tokens, container):
        for token in tokens:
            if token.kind != "ident" or token.upper in RESERVED:
                continue
            if token.text in SPECIAL:
                continue
            self._record(token.text, token, container)

    # ------------------------------------------------------------ querying

    def identifier_tokens(self):
        """Every identifier token with its absolute position in the text, which
        is what a rename is applied through."""
        return [t for t in self.tokens if t.kind == "ident"]


def parse(text, path=None):
    return Assembly(text, path)
