"""Where a module's files sit under `src/`.

    src/
      <group>/                base, modules
        <MODULE>/
          <MODULE>.ASM        the module's assembly
          <MODULE>.H          the header declaring what the assembly defines
          <MODULE>_PORT.H     the data group the portable build alone reads
          data/
            module.toml       the manifest
          c/                  every `.C` holding a routine of the module's own
            shared/           every `.C` made only of shared chunks
            stubs/            every `.C` made only of empty routines
          inc/                every other `.H`
          host/               the host side that is this module's alone
      shared/                 what is not one module's

A module's directory is found by name, whichever group it sits in; a name
under two groups is an error.
"""

import os

REPO_ROOT = os.path.abspath(os.path.join(
    os.path.dirname(__file__), "..", ".."))

# The groups a module can sit in; `shared/` is beside them and holds no module.
# A group name must differ from every module name by more than case.
GROUPS = ("base", "modules")
SHARED = "shared"

# The subdirectories inside a module, named once.
DATA_DIR = "data"
CODE_DIR = "c"
SHARED_CODE_DIR = "shared"
STUBS_CODE_DIR = "stubs"
CODE_PARTS = (SHARED_CODE_DIR, STUBS_CODE_DIR)
INCLUDE_DIR = "inc"
HOST_DIR = "host"

MANIFEST_NAME = "module.toml"


class LayoutError(Exception):
    pass


def src_root(root=None):
    return os.path.join(root or REPO_ROOT, "src")


def shared_dir(root=None):
    """`src/shared/`, which every C module includes from."""
    return os.path.join(src_root(root), SHARED)


def driver_header(root=None):
    """`src/shared/DRIVERS.H`, the driver entries every module's C calls."""
    return os.path.join(shared_dir(root), "DRIVERS.H")


def shared_host_dir(root=None):
    """`src/shared/host/`, the host side every portable build links: what the
    drivers, the run-time and the PC supplied, written for the host."""
    return os.path.join(shared_dir(root), HOST_DIR)


def host_dir(directory):
    """`host/` under a module: the host side that is this module's alone."""
    return os.path.join(directory, HOST_DIR)


def host_files(folder):
    """Every `.C` in a host directory, sorted; none where there is no such
    directory, which is most modules."""
    return _c_in(folder)


def _c_in(folder):
    """Every `.C` directly in a folder, sorted; none where it does not exist."""
    if not os.path.isdir(folder):
        return []
    return sorted(os.path.join(folder, entry) for entry in os.listdir(folder)
                  if entry.upper().endswith(".C")
                  and os.path.isfile(os.path.join(folder, entry)))


def code_dir(directory):
    return os.path.join(directory, CODE_DIR)


def shared_code_part(directory):
    """`c/shared/`: a module's `.C` files made only of shared chunks."""
    return os.path.join(directory, CODE_DIR, SHARED_CODE_DIR)


def stub_code_part(directory):
    """`c/stubs/`: a game module's `.C` files made only of empty routines."""
    return os.path.join(directory, CODE_DIR, STUBS_CODE_DIR)


def code_part(path):
    """`shared` or `stubs` for a module `.C` under that part of `c/`, else None."""
    parent = os.path.dirname(os.path.abspath(path))
    part = os.path.basename(parent)
    if part in CODE_PARTS and os.path.basename(os.path.dirname(parent)) == CODE_DIR:
        return part
    return None


def c_name(path):
    """A module `.C` as a manifest `sources` entry spells it."""
    name, part = os.path.basename(path), code_part(path)
    return "%s/%s" % (part, name) if part else name


def include_dir(directory):
    return os.path.join(directory, INCLUDE_DIR)


def manifest_path(directory):
    """The module's manifest, whose name is fixed and not the module's."""
    return os.path.join(directory, DATA_DIR, MANIFEST_NAME)


def generated_path(directory, name, extension):
    """`<MODULE>.ASM` or `<MODULE>.H`, which sit where the directory opens."""
    return os.path.join(directory, "%s%s" % (name, extension))


PORT_HEADER_SUFFIX = "_PORT.H"


def port_header_path(directory, name):
    """`<MODULE>_PORT.H`, the data group the portable build alone reads,
    beside the two files both builds read."""
    return generated_path(directory, name, PORT_HEADER_SUFFIX)


def source_path(directory, name, filename):
    """Resolve a bare filename, a manifest `sources` entry, to a path: a `.C`
    under `c/` (`shared/X.C` and `stubs/X.C` under those parts of it), a
    `.H` under `inc/`, and `<MODULE>.ASM`, `<MODULE>.H` or anything else at
    the top."""
    stem, extension = os.path.splitext(filename)
    lowered = extension.lower()
    if stem.upper() == name.upper() and lowered in (".asm", ".h"):
        return os.path.join(directory, filename)
    if lowered == ".c":
        return os.path.join(directory, CODE_DIR, *filename.split("/"))
    if lowered == ".h":
        return os.path.join(directory, INCLUDE_DIR, filename)
    return os.path.join(directory, filename)


def c_files(directory):
    """Every `.C` the module keeps, sorted, compiled or not: those under `c/`
    first, then `c/shared/` and `c/stubs/`."""
    return (_c_in(code_dir(directory)) + _c_in(shared_code_part(directory))
            + _c_in(stub_code_part(directory)))


def header_files(directory, name):
    """Every `.H` the module keeps: its own, then those under inc/."""
    out = []
    for generated in (generated_path(directory, name, ".H"),
                      port_header_path(directory, name)):
        if os.path.isfile(generated):
            out.append(generated)
    folder = include_dir(directory)
    if os.path.isdir(folder):
        out.extend(sorted(os.path.join(folder, entry)
                          for entry in os.listdir(folder)
                          if entry.upper().endswith(".H")
                          and os.path.isfile(os.path.join(folder, entry))))
    return out


def build_inputs(directory):
    """Every file a build of this module reads, sorted by basename.

    The `.ASM`, `.C` and `.H` wherever they sit, plus the manifest.
    """
    found = []
    for folder in (directory, code_dir(directory), shared_code_part(directory),
                   stub_code_part(directory), include_dir(directory)):
        if not os.path.isdir(folder):
            continue
        for entry in os.listdir(folder):
            path = os.path.join(folder, entry)
            if (os.path.isfile(path)
                    and entry.lower().endswith((".asm", ".c", ".h"))):
                found.append(path)
    manifest = manifest_path(directory)
    if os.path.isfile(manifest):
        found.append(manifest)
    return sorted(found, key=lambda p: (os.path.basename(p).upper(),
                                        code_part(p) or ""))


def modules(src=None):
    """{MODULE: directory} for every module under `src/`: any directory holding
    `data/module.toml`."""
    src = src or src_root()
    out = {}
    for group in GROUPS:
        folder = os.path.join(src, group)
        if not os.path.isdir(folder):
            continue
        for name in sorted(os.listdir(folder)):
            directory = os.path.join(folder, name)
            if not os.path.isfile(manifest_path(directory)):
                continue
            if name in out:
                raise LayoutError(
                    "%s appears under two groups, %s and %s. A module is named "
                    "once and sits in one place, because everything keyed by "
                    "the name -- the manifest, rebuilt/build.hash -- carries "
                    "no group to tell them apart."
                    % (name, os.path.basename(os.path.dirname(out[name])),
                       group))
            out[name] = directory
    return out


def names(src=None):
    """Every module name under `src/`, sorted, ignoring the group."""
    return sorted(modules(src))


def group_of(directory):
    """The group a module directory sits in."""
    return os.path.basename(os.path.dirname(os.path.abspath(directory)))


def directory_for(name, src=None):
    """The directory a module name resolves to, or None if there is none."""
    return modules(src).get(name)
