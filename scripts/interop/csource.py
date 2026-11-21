#!/usr/bin/env python3
"""Parse the module C into a syntax tree with source positions: `parse(text,
name)` gives its functions, call sites and the occurrences a rename may
touch, and modifies nothing.

It works on C constructs, so `p->count`, a label `count:` and a `count` in a
comment or a string are not mentions of the global `count`. Preprocessor
directives are kept whole and opaque, and a global shadowed by a local is
not accommodated."""

import re

IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
NUMBER = re.compile(r"(?:\.[0-9]|[0-9])[0-9A-Za-z_.]*(?:[eEpP][-+][0-9]*)?")

# Words that can appear where a declarator name would, and are not names.
KEYWORDS = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "far", "float", "for", "goto", "huge",
    "if", "int", "interrupt", "long", "near", "pascal", "register", "return",
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while", "cdecl", "fortran",
    "_cdecl", "_far", "_near", "_huge", "_pascal", "_interrupt", "__cdecl",
}

# Type-ish words: a declaration can start with any of these.
TYPE_WORDS = {
    "auto", "char", "const", "double", "enum", "extern", "far", "float",
    "huge", "int", "interrupt", "long", "near", "pascal", "register", "short",
    "signed", "static", "struct", "typedef", "union", "unsigned", "void",
    "volatile", "cdecl", "fortran", "_cdecl", "_far", "_near", "_huge",
    "_pascal", "_interrupt", "__cdecl",
}


class CSourceError(Exception):
    pass


class Token:
    """One lexical item, with where it sits in the file."""

    __slots__ = ("kind", "text", "line", "column", "start", "end")

    def __init__(self, kind, text, line, column, start, end):
        self.kind = kind      # ident | number | string | char | punct | directive
        self.text = text
        self.line = line      # 1-based
        self.column = column  # 1-based
        self.start = start    # absolute offset into the source text
        self.end = end

    def __repr__(self):
        return "<%s %r @%d:%d>" % (self.kind, self.text, self.line, self.column)


class Occurrence:
    """One mention of an identifier, classified by what it refers to."""

    __slots__ = ("name", "token", "role", "container")

    def __init__(self, name, token, role, container=None):
        self.name = name
        self.token = token
        # symbol     -- refers to an ordinary identifier we could rename
        # member     -- after `.` or `->`, or a struct field declaration
        # label      -- a goto target, its own namespace
        # tag        -- a struct/union/enum tag, its own namespace
        # declaration-- the defining occurrence of a symbol
        self.role = role
        self.container = container   # enclosing function, or None at file scope

    @property
    def line(self):
        return self.token.line

    @property
    def column(self):
        return self.token.column

    @property
    def renameable(self):
        return self.role in ("symbol", "declaration")

    def __repr__(self):
        return "<%s %s at %d:%d%s>" % (
            self.role, self.name, self.line, self.column,
            " in %s" % self.container if self.container else "")


class Call:
    """One call site: what is named, where it sits, and the tokens of each
    argument. A macro invocation is a call here too."""

    __slots__ = ("name", "token", "arguments", "container")

    def __init__(self, name, token, arguments, container=None):
        self.name = name
        self.token = token
        self.arguments = arguments   # tuple of tuples of Token
        self.container = container   # the function it sits in, or None

    @property
    def line(self):
        return self.token.line

    @property
    def column(self):
        return self.token.column

    @property
    def count(self):
        """How many arguments are written, counting each as one."""
        return len(self.arguments)

    def __repr__(self):
        return "<call %s(%d) at %d:%d%s>" % (
            self.name, self.count, self.line, self.column,
            " in %s" % self.container if self.container else "")


class Node:
    """One construct in the tree, with the span it covers."""

    __slots__ = ("kind", "name", "tokens", "children", "name_token",
                 "storage", "type_text")

    def __init__(self, kind, name, tokens, name_token=None, storage=(),
                 type_text=""):
        self.kind = kind          # function | prototype | variable | typedef
                                  # | tag | directive | unknown
        self.name = name
        self.tokens = tokens      # every token of the construct
        self.name_token = name_token
        self.children = []
        self.storage = tuple(storage)
        self.type_text = type_text

    @property
    def line(self):
        return self.tokens[0].line if self.tokens else 0

    @property
    def end_line(self):
        return self.tokens[-1].line if self.tokens else 0

    @property
    def parameters(self):
        """The declarator's parameter list, one tuple of tokens each; empty for
        `f()` and for anything that is not a function."""
        if self.kind not in ("function", "prototype") or not self.name_token:
            return ()
        for position, token in enumerate(self.tokens):
            if token is self.name_token:
                arguments, _ = _bracketed(self.tokens, position + 1)
                return arguments or ()
        return ()

    @property
    def is_variadic(self):
        """Whether the parameter list ends in an ellipsis."""
        for parameter in self.parameters:
            for token in parameter:
                if token.kind == "punct" and token.text == "...":
                    return True
        return False

    def __repr__(self):
        return "<%s %s @%d..%d>" % (self.kind, self.name or "?",
                                    self.line, self.end_line)


def tokenize(text):
    """Every token, with comments dropped and directive lines kept whole.
    String and character bodies are single tokens, never identifiers."""
    tokens = []
    line = 1
    line_start = 0
    index = 0
    length = len(text)
    at_line_start = True

    while index < length:
        char = text[index]

        if char == "\n":
            line += 1
            index += 1
            line_start = index
            at_line_start = True
            continue

        if char in " \t\r":
            index += 1
            continue

        if char == "/" and index + 1 < length:
            if text[index + 1] == "/":
                while index < length and text[index] != "\n":
                    index += 1
                continue
            if text[index + 1] == "*":
                end = text.find("*/", index + 2)
                end = length if end < 0 else end + 2
                line += text.count("\n", index, end)
                last = text.rfind("\n", index, end)
                if last >= 0:
                    line_start = last + 1
                index = end
                at_line_start = False
                continue

        if char == "#" and at_line_start:
            # A whole preprocessor directive, continuations included, as one
            # opaque token.
            start = index
            while index < length:
                if text[index] == "\n" and not text[index - 1:index] == "\\":
                    break
                index += 1
            body = text[start:index]
            tokens.append(Token("directive", body, line,
                                start - line_start + 1, start, index))
            line += body.count("\n")
            continue

        at_line_start = False

        if char in "'\"":
            quote = char
            start = index
            index += 1
            while index < length and text[index] != quote:
                if text[index] == "\\":
                    index += 1
                index += 1
            index = min(index + 1, length)
            body = text[start:index]
            tokens.append(Token("string" if quote == '"' else "char", body,
                                line, start - line_start + 1, start, index))
            line += body.count("\n")
            continue

        if char.isdigit() or (char == "." and index + 1 < length
                              and text[index + 1].isdigit()):
            match = NUMBER.match(text, index)
            body = match.group(0) if match else char
            tokens.append(Token("number", body, line, index - line_start + 1,
                                index, index + len(body)))
            index += len(body)
            continue

        match = IDENT.match(text, index)
        if match:
            body = match.group(0)
            tokens.append(Token("ident", body, line, index - line_start + 1,
                                index, match.end()))
            index = match.end()
            continue

        # Multi-character punctuators that matter for resolution, the ellipsis
        # among them.
        if text[index:index + 3] == "...":
            tokens.append(Token("punct", "...", line, index - line_start + 1,
                                index, index + 3))
            index += 3
            continue

        two = text[index:index + 2]
        if two in ("->", "++", "--", "<<", ">>", "<=", ">=", "==", "!=", "&&",
                   "||", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "::"):
            tokens.append(Token("punct", two, line, index - line_start + 1,
                                index, index + 2))
            index += 2
            continue

        tokens.append(Token("punct", char, line, index - line_start + 1,
                            index, index + 1))
        index += 1

    return tokens


class TranslationUnit:
    """One .C or .H file, parsed."""

    def __init__(self, text, path=None):
        self.text = text
        self.path = path
        self.lines = text.splitlines()
        self.tokens = tokenize(text)
        self.declarations = []
        self.occurrences = []
        self.call_sites = []
        self._by_name = {}
        self._parse()

    # ------------------------------------------------------------- parsing

    def _parse(self):
        tokens = self.tokens
        index = 0
        while index < len(tokens):
            token = tokens[index]
            if token.kind == "directive":
                self.declarations.append(
                    Node("directive", None, [token]))
                index += 1
                continue
            if token.kind == "punct" and token.text == ";":
                index += 1
                continue
            index = self._declaration(index)

    def _declaration(self, index):
        """One file-scope construct, from `index` to just past its end."""
        tokens = self.tokens
        start = index
        depth = 0
        body_start = None

        while index < len(tokens):
            token = tokens[index]
            if token.kind == "punct":
                if token.text in "([{":
                    if token.text == "{" and depth == 0:
                        body_start = index
                    depth += 1
                elif token.text in ")]}":
                    depth -= 1
                    if depth == 0 and body_start is not None:
                        index += 1
                        break
                elif token.text == ";" and depth == 0:
                    index += 1
                    break
            index += 1

        span = tokens[start:index]
        if not span:
            return index + 1

        node = self._classify(span, body_start is not None)
        self.declarations.append(node)
        if node.name:
            self._by_name.setdefault(node.name, node)
        self._collect(span, node)
        return index

    def _classify(self, span, has_body):
        """What a run of tokens declares, and under what name: the identifier a
        `(` follows for a function, or the last one before `;`, `=`, `[` or
        `,` for a variable. Not a full declarator grammar."""
        storage = [t.text for t in span
                   if t.kind == "ident" and t.text in
                   ("extern", "static", "typedef", "register", "auto")]

        # A struct/union/enum definition with no declarator is a tag.
        words = [t.text for t in span if t.kind == "ident"]
        if words and words[0] in ("struct", "union", "enum"):
            named = [t for t in span if t.kind == "ident"
                     and t.text not in KEYWORDS]
            tail = [t for t in span[::-1]
                    if t.kind == "ident" and t.text not in KEYWORDS]
            if "typedef" in storage and tail:
                return Node("typedef", tail[0].text, span, tail[0], storage)
            if named and not has_body:
                # `struct foo x;` -- x is the declarator, foo the tag.
                pass
            elif named:
                return Node("tag", named[0].text, span, named[0], storage)

        name_token = None
        kind = "variable"

        for position, token in enumerate(span):
            if token.kind != "ident" or token.text in KEYWORDS:
                continue
            following = span[position + 1] if position + 1 < len(span) else None
            if following and following.kind == "punct" and following.text == "(":
                name_token = token
                kind = "function" if has_body else "prototype"
                break

        if name_token is None:
            candidates = [t for t in span
                          if t.kind == "ident" and t.text not in KEYWORDS]
            if candidates:
                name_token = candidates[-1]
                for position, token in enumerate(span):
                    if token is name_token:
                        following = (span[position + 1]
                                     if position + 1 < len(span) else None)
                        if following and following.text in (";", "=", "[", ","):
                            break
                        # Trailing identifier is the type, not a name:
                        # `struct thing;`
                        if position == len(span) - 1 and len(span) > 1:
                            pass

        if "typedef" in storage and name_token is not None:
            kind = "typedef"

        type_text = ""
        if name_token is not None:
            type_text = " ".join(t.text for t in span
                                 if t.kind == "ident" and t is not name_token
                                 and t.text in TYPE_WORDS)

        return Node(kind, name_token.text if name_token else None, span,
                    name_token, storage, type_text)

    def _collect(self, span, node):
        """Classify every identifier in a construct by role and record it."""
        container = node.name if node.kind == "function" else None
        struct_depth = 0
        brace_depth = 0

        for position, token in enumerate(span):
            if token.kind == "punct":
                if token.text == "{":
                    brace_depth += 1
                elif token.text == "}":
                    brace_depth -= 1
                    if struct_depth and brace_depth < struct_depth:
                        struct_depth = 0
                continue
            if token.kind != "ident":
                continue

            previous = span[position - 1] if position else None
            following = span[position + 1] if position + 1 < len(span) else None

            if token.text in KEYWORDS:
                # Only a struct that opens a body puts us inside one; `struct
                # frame *f` as a parameter type does not.
                if token.text in ("struct", "union", "enum") \
                        and _opens_a_body(span, position):
                    struct_depth = brace_depth + 1
                continue

            # `p->field` and `s.field`: a member, not our symbol.
            if previous is not None and previous.kind == "punct" \
                    and previous.text in (".", "->"):
                self._add(token, "member", container)
                continue

            # The tag in `struct thing`.
            if previous is not None and previous.kind == "ident" \
                    and previous.text in ("struct", "union", "enum"):
                self._add(token, "tag", container)
                continue

            # A goto target, and the label it names: a namespace of their own.
            if previous is not None and previous.kind == "ident" \
                    and previous.text == "goto":
                self._add(token, "label", container)
                continue
            if following is not None and following.kind == "punct" \
                    and following.text == ":" and self._at_statement(span, position):
                self._add(token, "label", container)
                continue

            # A field declared inside a struct body.
            if struct_depth and brace_depth >= struct_depth:
                self._add(token, "member", container)
                continue

            if token is node.name_token:
                self._add(token, "declaration", container)
                continue

            # A symbol a `(` follows is being called, a routine calling itself
            # included.
            if following is not None and following.kind == "punct" \
                    and following.text == "(":
                arguments, _ = _bracketed(span, position + 1)
                if arguments is not None:
                    self.call_sites.append(
                        Call(token.text, token, arguments, container))

            self._add(token, "symbol", container)

    @staticmethod
    def _at_statement(span, position):
        """Whether the identifier at `position` starts a statement, which
        separates a label from the `x` in `a ? x : y` and the value in `case
        FOO:`."""
        if position == 0:
            return True
        previous = span[position - 1]
        if previous.kind == "punct" and previous.text in (";", "{", "}", ":"):
            return True
        if previous.kind == "ident" and previous.text in ("case", "default"):
            return False
        return False

    def _add(self, token, role, container):
        occurrence = Occurrence(token.text, token, role, container)
        self.occurrences.append(occurrence)

    # ------------------------------------------------------------ querying

    def functions(self):
        return [d for d in self.declarations if d.kind == "function"]

    def prototypes(self):
        return [d for d in self.declarations if d.kind == "prototype"]

    def calls(self, name=None):
        """Every call site in the file, in file order, nested calls each their
        own; `name` narrows it to one callee."""
        if name is None:
            return list(self.call_sites)
        return [call for call in self.call_sites if call.name == name]

    def renameable_occurrences(self):
        """Every occurrence a rename may touch, in file order."""
        return [o for o in self.occurrences if o.renameable]


def _bracketed(span, position):
    """The comma-separated groups inside the `(` at `position`, as (groups,
    index of the closing paren), or (None, position) where it is not a `(`
    or never closes. Only a comma directly inside these parentheses
    separates, and an empty pair is no groups."""
    if position >= len(span) or span[position].kind != "punct" \
            or span[position].text != "(":
        return None, position

    groups = []
    current = []
    depth = 0
    index = position
    while index < len(span):
        token = span[index]
        if token.kind == "punct":
            if token.text in "([{":
                depth += 1
                if depth == 1:
                    index += 1
                    continue
            elif token.text in ")]}":
                depth -= 1
                if depth == 0:
                    if current or groups:
                        groups.append(tuple(current))
                    return tuple(groups), index
            elif token.text == "," and depth == 1:
                groups.append(tuple(current))
                current = []
                index += 1
                continue
        current.append(token)
        index += 1
    return None, index


def _opens_a_body(span, position):
    """Whether the struct/union/enum keyword at `position` opens a body, as
    `struct frame { ... }` does and `struct frame *f` does not."""
    for offset in (1, 2):
        index = position + offset
        if index >= len(span):
            return False
        token = span[index]
        if token.kind == "punct":
            return token.text == "{"
        if token.kind != "ident":
            return False
    return False


def parse(text, path=None):
    return TranslationUnit(text, path)
