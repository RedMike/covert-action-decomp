"""How a symbol is spelled on each side of the assembly/C boundary. MSC mangles
a cdecl symbol with a leading underscore: the C's `strcpy` reaches LINK as
`_strcpy`, which is what the assembly spells."""

import re

# MASM identifiers: letters, digits, and _ $ ? @, not starting with a digit.
IDENTIFIER_OK = re.compile(r"[^A-Za-z0-9_$?@]")

# Words MASM 5.1 will not accept as a symbol.
RESERVED = frozenset("""
    assume byte comment db dd dosseg dq dt dup dw end endm endp ends
    eq equ even exitm extrn far ge group gt high if ifb ifdef ife ifidn ifnb
    ifndef include includelib irp irpc label le length local low lt macro
    mask mod name ne near offset or org page proc ptr public purge qword
    record rept seg segment shl short shr size stack struc subttl this title
    type width word xor
""".split())


def masm_identifier(name, fallback=None):
    """Make a symbol name MASM will accept: no `;` or `-`, and no reserved
    word."""
    cleaned = IDENTIFIER_OK.sub("_", str(name))
    if not cleaned or cleaned[0].isdigit():
        cleaned = "_" + cleaned
    if cleaned.lower() in RESERVED:
        cleaned += "_"
    return cleaned or fallback


# C is stricter than MASM: `$`, `?` and `@` are legal in a MASM name and not in
# a C one.
C_IDENTIFIER_OK = re.compile(r"[^A-Za-z0-9_]")


def c_identifier(name, fallback=None):
    """Make a symbol name both C and MASM will accept, for every name that
    crosses the boundary: both sides have to spell it the same way."""
    cleaned = C_IDENTIFIER_OK.sub("_", str(name))
    if not cleaned or cleaned[0].isdigit():
        cleaned = "_" + cleaned
    return cleaned or fallback


def is_linker_name(name):
    """Whether a canonical identifier is already the linker's spelling: one
    beginning with an underscore, as `_strcpy`, which is never renamed."""
    return str(name).startswith("_")


def library_spelling(canonical, meaningful):
    """The library's own name for this symbol, or None: a run-time routine's
    canonical name, or what `[names]` maps a run-time datum to."""
    if is_linker_name(canonical):
        return canonical
    if is_linker_name(meaningful):
        return meaningful
    return None


def linker_spelling(c_name):
    """How the assembly spells a crossing symbol the C spells `c_name`: CL's
    underscore, on a name sanitised to the C alphabet. Not for a linker
    name."""
    return "_" + c_identifier(c_name)


def c_spelling(linker_name):
    """How the C spells a linker name: one underscore shorter, which CL puts
    back."""
    return str(linker_name)[1:]
