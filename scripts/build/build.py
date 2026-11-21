#!/usr/bin/env python3
"""Build a module from its source: transform its .ASM, .C and .H into
build/<MODULE>/, assemble and compile each object in link order, link, and
stage the result into rebuilt/. One module is one DOSBox and four run at
once."""

import argparse
import collections
import concurrent.futures
import contextlib
import os
import re
import shutil
import sys

if __package__ in (None, ""):
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    __package__ = "build"

from lib import layout
from lib import manifest as manifest_lib
from interop import dosbox as dosbox_interop
from interop import exepack
from shared import logging as shared_logging
from shared.metrics import Metrics, step

from . import copyright_patch
from . import prevalidate as prevalidate_lib
from . import sourcehash
from . import transform as transform_lib

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SRC_ROOT = layout.src_root(REPO_ROOT)

# Four at once: one DOSBox saturates a core.
DEFAULT_JOBS = min(4, os.cpu_count() or 1)
BUILD_ROOT = os.path.join(REPO_ROOT, "build")
REBUILT_ROOT = os.path.join(REPO_ROOT, "rebuilt")
LOCK_PATH = os.path.join(BUILD_ROOT, "build.lock")


class BuildError(Exception):
    pass


class BuildLocked(BuildError):
    pass


def process_alive(pid):
    if not pid or pid <= 0:
        return False
    if sys.platform == "win32":
        import ctypes
        # OpenProcess, never os.kill: on Windows that terminates the process.
        handle = ctypes.windll.kernel32.OpenProcess(0x1000, False, pid)
        if not handle:
            return False
        ctypes.windll.kernel32.CloseHandle(handle)
        return True
    try:
        os.kill(pid, 0)
    except ProcessLookupError:
        return False
    except PermissionError:
        return True
    return True


def lock_holder(path):
    try:
        with open(path, "r", encoding="utf-8") as handle:
            return int(handle.read().strip())
    except (OSError, ValueError):
        return None


@contextlib.contextmanager
def build_lock(path=LOCK_PATH):
    """One build at a time: two runs would race over build/, rebuilt/ and the
    record."""
    log = shared_logging.get_logger("lock")
    os.makedirs(os.path.dirname(path), exist_ok=True)
    while True:
        try:
            descriptor = os.open(path, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
            break
        except FileExistsError:
            holder = lock_holder(path)
            if process_alive(holder):
                raise BuildLocked(
                    "another build is running (pid %s); delete %s if it is not"
                    % (holder, path))
            log.warning("Clearing a stale lock", pid=holder, path=path)
            try:
                os.unlink(path)
            except FileNotFoundError:
                pass
    with os.fdopen(descriptor, "w", encoding="utf-8", newline="\n") as handle:
        handle.write("%d\n" % os.getpid())
    log.debug("Holding the build lock", pid=os.getpid(), path=path)
    try:
        yield path
    finally:
        if lock_holder(path) == os.getpid():
            try:
                os.unlink(path)
            except FileNotFoundError:
                pass


# One thing worth reporting about a build: an error that stopped it, or a
# warning worth reading.
Finding = collections.namedtuple("Finding", ("severity", "stage", "message"))


def count_findings(findings, severity):
    return sum(1 for finding in findings if finding.severity == severity)


def source_kind(path):
    return "c" if path.lower().endswith((".c", ".h")) else "asm"


class Staged:
    """One source in build/, ready to compile, and where it sits in the link:
    `after` is the ported routines it follows, `defines` what a C source defines."""

    __slots__ = ("path", "tool", "flags", "link", "after", "defines",
                 "routines")

    def __init__(self, path, tool, flags, link, after=(), defines=(),
                 routines=()):
        self.path = path
        self.tool = tool
        self.flags = list(flags)
        self.link = link
        # Wrapped rather than refused, since tuple() would split a bare string.
        self.after = (after,) if isinstance(after, str) else tuple(after)
        self.defines = tuple(defines)
        # Only to notice two split points sharing one object with code between.
        self.routines = tuple(routines)

    @property
    def name(self):
        return os.path.basename(self.path)

    def __repr__(self):
        return "<staged %s>" % self.name


def link_order(staged, module):
    """Put each object where the routine it carries sits in the assembly: LINK
    concatenates in the order it is given."""
    by_routine = {}
    for item in staged:
        for name in item.defines:
            by_routine.setdefault(name, item)

    wanted = [name for item in staged for name in item.after]
    missing = [name for name in wanted if name not in by_routine]
    if missing:
        raise BuildError(
            "%s: the assembly was split for %s and nothing in [[objects]] "
            "defines it" % (module.name, ", ".join(sorted(set(missing)))))
    for name in wanted:
        if not by_routine[name].link:
            raise BuildError(
                "%s: %s defines %s, which the split needs, but is "
                "`link = false`"
                % (module.name, by_routine[name].name, name))

    moved = {id(by_routine[name]) for name in wanted}
    placed = set()
    out = []
    for item in staged:
        if id(item) in moved and not item.after:
            continue  # placed at its split point below
        # In order: a surviving fragment speaks for every routine in its run.
        for name in item.after:
            owner = by_routine[name]
            if id(owner) not in placed:
                out.append(owner)
                placed.add(id(owner))
            elif any(piece.routines for piece in out[out.index(owner) + 1:]):
                # One object, two split points, code between: LINK places it once.
                raise BuildError(
                    "%s: %s is asked to sit at two split points with assembly "
                    "between them; LINK places an object once"
                    % (module.name, owner.name))
        out.append(item)
    return out


# The medium model for a mod build: each C unit far, in a code segment of its own.
MEDIUM_FLAG = "/AM"


def medium_flags(flags):
    """The compiler flags with the medium model on; a manifest that already
    fixes a model is refused."""
    fixed = [flag for flag in flags if flag.upper().startswith("/A")]
    if fixed:
        raise BuildError("the manifest fixes the memory model with %s, so "
                         "--medium cannot choose one" % " ".join(fixed))
    return list(flags) + [MEDIUM_FLAG]


def medium_libs(libs):
    """The MSC run-time libraries named for the medium model, SLIBCE.LIB to
    MLIBCE.LIB; any other library is left as it is."""
    out = []
    for name in libs:
        upper = name.upper()
        if upper.startswith("SLIBC") and upper.endswith(".LIB"):
            name = "M" + name[1:]
        out.append(name)
    return out


def use_medium(module, defines, medium=None):
    """Whether a build is medium-model: as forced, else when it is a mod build
    of a module whose manifest says `mod_model = "medium"`."""
    if medium is not None:
        return medium
    return bool(defines) and module.mod_model == "medium"


# Where small-model C lands, so what medium-model C reaches far.
MEDIUM_SEGMENT = "_TEXT"


def medium_assembly(text, source):
    """The staged assembly with every `PROC NEAR` in `_TEXT` made `FAR`, as
    medium-model C calls it; a routine that reads a parameter is refused."""
    out = []
    in_text = False
    body = None
    for line in text.splitlines(True):
        tokens = line.split(";")[0].split()
        if len(tokens) >= 2 and tokens[0] == MEDIUM_SEGMENT:
            in_text = tokens[1] == "SEGMENT"
        elif body and len(tokens) >= 2 and tokens[1] == "ENDP":
            body = None
        elif body and ("[bp+" in line.split(";")[0] or tokens[:1] == ["retn"]):
            raise BuildError(
                "%s: %s reads a parameter off BP or returns near, which a far "
                "frame moves; make it far by hand before --medium"
                % (source, body))
        elif (in_text and len(tokens) == 3 and tokens[1] == "PROC"
              and tokens[2] == "NEAR"):
            body = tokens[0]
            line = line.replace("NEAR", "FAR", 1)
        out.append(line)
    return "".join(out)


def stage_sources(module, out_dir):
    """Transform src/ into build/, returning a list of Staged in link order,
    one entry per fragment for a `.ASM` that split."""
    log = shared_logging.get_logger(worker_source(module.name))
    metrics = Metrics()
    prepared = []
    names = module.names
    # How a renamed symbol is spelled each side; MSC mangles cdecl to _name.
    crossing = transform_lib.crossing_map(module)

    # The header first: included, not compiled, and it must be the transformed one.
    with step(log, metrics, "module header"):
        header_path = module.source_path(".H")
        if os.path.isfile(header_path):
            with open(header_path, "r", encoding="utf-8", newline="") as handle:
                text = handle.read()
            renamed, _ = transform_lib.rename(text, names, "c", header_path,
                                              crossing["c"])
            target = os.path.join(out_dir, os.path.basename(header_path))
            with open(target, "w", encoding="utf-8", newline="\n") as handle:
                handle.write(renamed)

    # Other headers under inc/, staged flat: uncopied is unincludable.
    with step(log, metrics, "module includes"):
        for extra in module.headers():
            entry = os.path.basename(extra)
            if os.path.abspath(extra) == os.path.abspath(header_path):
                continue
            with open(extra, "r", encoding="utf-8", newline="") as handle:
                text = handle.read()
            renamed, _ = transform_lib.rename(text, names, "c", extra,
                                              crossing["c"])
            target = os.path.join(out_dir, entry)
            with open(target, "w", encoding="utf-8", newline="\n") as handle:
                handle.write(renamed)

    # What src/shared/ keeps for the C to include, renamed through this
    # module's [names].
    with step(log, metrics, "shared headers"):
        shared_dir = layout.shared_dir(REPO_ROOT)
        if any(source_kind(spec.target) == "c" for spec in module.object_sources()):
            for entry in sorted(os.listdir(shared_dir) if os.path.isdir(shared_dir)
                                else []):
                extra = os.path.join(shared_dir, entry)
                if not entry.upper().endswith(".H") or not os.path.isfile(extra):
                    continue
                with open(extra, "r", encoding="utf-8", newline="") as handle:
                    text = handle.read()
                renamed, _ = transform_lib.rename(text, names, "c", extra,
                                                  crossing["c"])
                target = os.path.join(out_dir, entry)
                with open(target, "w", encoding="utf-8", newline="\n") as handle:
                    handle.write(renamed)

    with step(log, metrics, "objects"):
        for spec in module.object_sources():
            target, sources, tool, flags = (spec.target, spec.sources,
                                            spec.tool, spec.flags)
            link = spec.link
            parts = []
            for source in sources:
                if not os.path.isfile(source):
                    raise BuildError(
                        "%s: no source at %s" % (module.name, source))
                with open(source, "r", encoding="utf-8", newline="") as handle:
                    parts.append((source, handle.read()))

            whole = transform_lib.join_sources([text for _, text in parts])

            # The target extension decides how the joined text is read.
            kind = source_kind(target)
            pieces, _ = transform_lib.transform_group(
                parts, names, kind, crossing[kind])

            # Over the join: the object is one contribution.
            defines = (transform_lib.definitions(whole, names, target)
                       if kind == "c" else ())

            stem, extension = os.path.splitext(target)
            for index, piece in enumerate(pieces):
                name = stem if len(pieces) == 1 else "%s%d" % (stem, index)
                written = os.path.join(out_dir, name + extension)
                with open(written, "w", encoding="utf-8", newline="\n") as handle:
                    handle.write(piece.text)
                prepared.append(Staged(written, tool, flags, link,
                                       piece.after, defines, piece.routines))

    return link_order(prepared, module)


# DOS 8.3 truncates silently, so MASM writes INTRO_AS.OBJ for INTRO_ASM.obj.
DOS_STEM = 8


def object_names(prepared):
    """One object file name per source, disambiguated where stems collide,
    as INTRO.ASM and INTRO.C both want INTRO.obj."""
    stems = [os.path.splitext(item.name)[0] for item in prepared]
    duplicated = {stem for stem in stems if stems.count(stem) > 1}
    names = []
    for item, stem in zip(prepared, stems):
        if stem in duplicated:
            suffix = "_" + os.path.splitext(item.path)[1].lstrip(".").upper()[:1]
            stem = stem[:DOS_STEM - len(suffix)] + suffix
        names.append(stem[:DOS_STEM])
    if len(set(names)) != len(names):
        raise BuildError(
            "two objects share the 8.3 name %s, so one overwrites the other"
            % ", ".join(sorted(names)))
    return names


def compile_commands(tools, prepared, out_dir):
    """The assembler and compiler calls for a module in link order, built
    rather than run: every call for one module goes into a single DOSBox."""
    commands = []
    objects = []
    for item, stem in zip(prepared, object_names(prepared)):
        obj = os.path.join(out_dir, "%s.obj" % stem)

        if item.tool == "cl":
            command = tools.cl_command([item.path], obj, item.flags)
        elif item.tool == "masm":
            command = tools.masm_command(item.path, obj, item.flags)
        else:
            raise BuildError("unknown tool %r for %s" % (item.tool, item.path))
        commands.append(command)
        objects.append(obj)
    return commands, objects


def report_calls(log, commands, results):
    """One line per tool call, once the instance that ran them all has exited,
    at DEBUG unless any of them failed, which puts the lot at ERROR."""
    broken = [result for result in results if not result.ok]
    at = log.error if broken else log.info
    each = log.error if broken else log.debug
    at("Ran %d call(s) in one DOSBox instance" % len(results),
       failed=len(broken))
    for command, result in zip(commands, results):
        each("%s %s" % (command.tool, command.label), ok=result.ok)


# Matches a 16-bit tool error line, as in: foo.c(12) : error C2065:
TOOL_ERROR = re.compile(r"\berror\b|\bSevere\s+Error", re.IGNORECASE)


def tool_errors(output, limit=12):
    """The error lines of a tool's output, without the warnings."""
    lines = [line.rstrip() for line in (output or "").splitlines()
             if TOOL_ERROR.search(line) and "0 Severe" not in line]
    if len(lines) > limit:
        return lines[:limit] + ["... and %d more" % (len(lines) - limit)]
    return lines


def clear_output(out_dir, module):
    """Delete what a run before this one left, so a failed build leaves no
    stale binary."""
    for name in (module.output, os.path.splitext(module.output)[0] + ".map",
                 module.output + ".packed", module.output + ".unpacked"):
        path = os.path.join(out_dir, name)
        if os.path.isfile(path):
            os.remove(path)


def stage_rebuilt(module, path):
    """Drop the built module into rebuilt/ over its shipped counterpart, only
    where the tree exists. Returns (staged, message)."""
    if not module.target:
        return False, None
    destination = os.path.join(REBUILT_ROOT, module.target)
    if not os.path.isdir(os.path.dirname(destination)):
        return False, ("not staged: %s does not exist yet -- a build with "
                       "no module named makes it"
                       % os.path.dirname(destination))
    shutil.copy2(path, destination)
    return True, "staged %s" % destination


def reset_rebuilt():
    """Put rebuilt/ back to a copy of decompressed/, which drops the old
    build.hash with it."""
    log = shared_logging.get_logger("reset_rebuilt")
    source = os.path.join(REPO_ROOT, "decompressed")
    log.debug("Copying the base tree", source=source, target=REBUILT_ROOT)
    if not os.path.isdir(source):
        raise BuildError(
            "no decompressed/ to reset rebuilt/ from; run "
            "scripts/setup/build_decompressed.py")
    if os.path.isdir(REBUILT_ROOT):
        shutil.rmtree(REBUILT_ROOT)
    shutil.copytree(source, REBUILT_ROOT)


def build_module(module_name, stage=True, defines=(), medium=None, **kwargs):
    """Build one module; returns (success, findings, metrics, error)."""
    findings = []
    metrics = Metrics()
    log = shared_logging.get_logger(worker_source(module_name))
    try:
        module = manifest_lib.open_module(module_name)
        medium = use_medium(module, defines, medium)
        if defines:
            log.info("Build with defines: not byte-identical by design",
                     defines=",".join(defines))
        if medium:
            log.info("Medium-model build: every C unit far and in its own "
                     "code segment, not byte-identical by design")

        # The input check, before anything is written; the output is validate.py's.
        with step(log, metrics, "prevalidate", at=log.info):
            report = prevalidate_lib.prevalidate(module.name)
        for found in report.findings:
            findings.append(Finding(
                "warning" if found.is_warning else "error",
                "prevalidate", str(found)))
        if not report.ok:
            return False, findings, metrics, None

        out_dir = os.path.join(BUILD_ROOT, module.name)
        os.makedirs(out_dir, exist_ok=True)

        with step(log, metrics, "transform", at=log.info):
            prepared = stage_sources(module, out_dir)
            if medium:
                for item in prepared:
                    if item.tool == "cl":
                        item.flags = medium_flags(item.flags)
                    elif item.tool == "masm":
                        with open(item.path, "r", encoding="utf-8",
                                  newline="") as handle:
                            text = handle.read()
                        with open(item.path, "w", encoding="utf-8",
                                  newline="\n") as handle:
                            handle.write(medium_assembly(text, item.name))

        with step(log, metrics, "dosbox", at=log.info):
            session = dosbox_interop.DosBox(**kwargs)
            tools = session.tools

            exe = os.path.join(out_dir, module.output)
            clear_output(out_dir, module)

            commands, objects = compile_commands(tools, prepared, out_dir)
            linked = [obj for item, obj in zip(prepared, objects) if item.link]

            # The link is built up front: its objects come from the staged sources.
            libs = module.link.get("libs", [])
            commands.append(tools.link_command(
                linked, exe,
                libs=medium_libs(libs) if medium else libs,
                load_libs=module.link.get("load_libs", []),
                flags=module.link.get("flags", [])))

            # CL's own variable and not /D: a DOS command line ends at 127.
            pre_lines = (["set CL=%s" % " ".join("/D%s" % name
                                                 for name in defines)]
                         if defines else [])
            results = session.run_batch(commands, pre_lines)
            report_calls(log, commands, results)
            for item in prepared:
                if not item.link:
                    log.debug("Compiled but not linked: `link = false`",
                              source=item.name)

            broken = [(item.name, item.tool, result)
                      for item, result in zip(prepared, results[:-1])
                      if not result.ok]
            if broken:
                # LINK ran regardless, so take its output away.
                clear_output(out_dir, module)
                for name, tool, result in broken:
                    findings.append(Finding("error", "compile",
                                            "%s failed on %s" % (tool, name)))
                    for line in tool_errors(result.output):
                        findings.append(Finding("error", "compile", line))
                return False, findings, metrics, None

            result = tools.check_link(results[-1])
            if not result.ok:
                findings.append(Finding("error", "link", "link failed"))
                for line in tool_errors(result.output):
                    findings.append(Finding("error", "link", line))
                return False, findings, metrics, None
            if not os.path.isfile(exe):
                findings.append(Finding("error", "link",
                                        "link wrote no %s" % module.output))
                for line in tool_errors(result.output):
                    findings.append(Finding("error", "link", line))
                return False, findings, metrics, None

            produced = exe
            log.debug("Linked", path=exe, bytes=os.path.getsize(exe))

        # Before packing and staging, so every artefact this run produces carries it.
        if module.copyright_patch:
            try:
                with step(log, metrics, "patch", at=log.info):
                    at = copyright_patch.apply(exe)
            except copyright_patch.CopyrightPatchError as error:
                findings.append(Finding("error", "copyright", str(error)))
                return False, findings, metrics, None
            log.debug("Applied the copyright patch", at="0x%x" % at,
                      output=module.output)

        # A module that shipped packed is staged packed then unpacked, as it shipped.
        if module.packed:
            with open(exe, "rb") as handle:
                plain = handle.read()
            try:
                with step(log, metrics, "pack", at=log.info):
                    packed_data = exepack.pack(plain)
                    unpacked_data = exepack.unpack(packed_data)
            except exepack.ExepackError as error:
                findings.append(Finding("error", "exepack", str(error)))
                return False, findings, metrics, None
            packed = exe + ".packed"
            unpacked = exe + ".unpacked"
            with open(packed, "wb") as handle:
                handle.write(packed_data)
            with open(unpacked, "wb") as handle:
                handle.write(unpacked_data)
            produced = unpacked
            log.debug("Packed and unpacked again, as the module shipped",
                      linked=len(plain), packed=len(packed_data),
                      unpacked=len(unpacked_data),
                      staged=os.path.basename(unpacked))

        if stage:
            with step(log, metrics, "stage", at=log.info):
                staged, message = stage_rebuilt(module, produced)
                if staged and (defines or medium):
                    # Not what src/ builds to: a normal build puts it back.
                    sourcehash.forget_module(module.name)
                    log.info("Staged a build that is not byte-identical by "
                             "design; the record does not claim it, so "
                             "validate.py will refuse it")
                elif staged:
                    # After the file is in place, and one module only.
                    sourcehash.record(module.name)
            if message:
                log.debug(message)
            if staged:
                log.debug("Recorded in the build hash",
                          path=os.path.relpath(sourcehash.hash_path(),
                                               REPO_ROOT).replace(os.sep, "/"))
        else:
            log.debug("Not staged (--no-stage), and nothing recorded")

        return True, findings, metrics, None
    except Exception as caught:
        findings.append(Finding(
            "error", "build", "%s: %s" % (type(caught).__name__, caught)))
        return False, findings, metrics, caught


def worker_source(name):
    return "build.%s" % name


def build_collected(name, **kwargs):
    """One module, logged on a logger of its own so concurrent modules can be
    told apart."""
    log = shared_logging.get_logger(worker_source(name))
    log.info("Building module", module=name)
    success, findings, metrics, error = build_module(name, **kwargs)
    for finding in findings:
        at = log.warning if finding.severity == "warning" else log.error
        at(finding.message, stage=finding.stage)
    report = log.info if success else log.error
    report("Built module" if success else "Failed to build module",
           module=name,
           success=success,
           errors=count_findings(findings, "error"),
           warnings=count_findings(findings, "warning"),
           duration_ms=metrics.total_ms,
           exc_info=error)
    return success


def scheduling_order(names):
    """Longest first by source size, so the big modules are not left until the
    end."""
    def weight(name):
        directory = layout.directory_for(name, SRC_ROOT)
        if not directory:
            return 0        # let the build report it, not the scheduler
        try:
            return sum(os.path.getsize(path)
                       for path in layout.build_inputs(directory))
        except OSError:
            return 0
    return sorted(names, key=weight, reverse=True)


def build_modules(names, jobs, **kwargs):
    """Build the named modules, one DOSBox each and `jobs` of them at a time.
    At one job a failure stops the run; above one every module is built."""
    log = shared_logging.get_logger("build")
    # Longest first only when it can help: at one job the order is the caller's.
    order = scheduling_order(names) if jobs > 1 else list(names)
    log.info("Building modules", count=len(order), at_once=jobs)
    log.debug("Build order", order=",".join(order))

    metrics = Metrics()
    built = failed = 0
    queue = iter(order)
    pending = set()
    stop = False
    pool = concurrent.futures.ThreadPoolExecutor(max_workers=jobs)
    try:
        with metrics.stage("modules"):
            while True:
                while not stop and len(pending) < jobs:
                    name = next(queue, None)
                    if name is None:
                        break
                    pending.add(pool.submit(build_collected, name, **kwargs))
                if not pending:
                    break
                done, pending = concurrent.futures.wait(
                    pending, return_when=concurrent.futures.FIRST_COMPLETED)
                for future in done:
                    success = future.result()
                    built += 1 if success else 0
                    failed += 0 if success else 1
                    if not success and jobs == 1:
                        stop = True
    finally:
        pool.shutdown(wait=True, cancel_futures=True)
    if stop:
        log.warning("Stopped at the first failure")
    shared_logging.always(log.info, "Finished building modules", built=built,
                          failed=failed, duration_ms=metrics.total_ms)
    return 1 if failed else 0


def main(argv=None):
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("module", nargs="*",
                        help="module name, directory or manifest path "
                             "(default: every module, which resets rebuilt/ "
                             "first)")
    parser.add_argument("--no-stage", action="store_true",
                        help="leave rebuilt/ alone")
    parser.add_argument("--clean", action="store_true",
                        help="wipe the build directory first")
    parser.add_argument("--dry-run", action="store_true",
                        help="report what the run would do and stop before "
                             "anything is built, wiped or staged")
    parser.add_argument("--define", action="append", default=[],
                        metavar="NAME",
                        help="define NAME for every C unit (repeatable): a "
                             "build with one of the optional changes in it "
                             "and not byte-identical, on named modules only")
    model = parser.add_mutually_exclusive_group()
    model.add_argument("--medium", action="store_true",
                       help="build in the medium model with no define: every "
                            "C unit /AM and the medium run-time, which a "
                            "build with defines gets by itself where the "
                            "manifest says mod_model = \"medium\"; not "
                            "byte-identical, on named modules only")
    model.add_argument("--small", action="store_true",
                       help="keep a build with defines in the small model, "
                            "as the byte-identical build is, where the "
                            "manifest would make it medium")
    parser.add_argument("-j", "--jobs", type=int, default=DEFAULT_JOBS,
                        metavar="N",
                        help="build N modules at once, one DOSBox each "
                             "(default: %(default)s). Past the host's "
                             "*physical* core count this buys nothing -- "
                             "DOSBox saturates a core on its own. Every "
                             "module is built even after one fails, because "
                             "parallel work cannot be un-started; -j 1 to "
                             "build them one at a time and stop at the first")
    dosbox_interop.add_common_args(parser)
    shared_logging.add_arguments(parser)
    args = parser.parse_args(argv)
    shared_logging.configure(args, "build")
    log = shared_logging.get_logger("main")
    if args.jobs < 1:
        parser.error("--jobs must be at least 1")

    if args.define and not args.module:
        parser.error("--define needs the modules named: a full run resets "
                     "rebuilt/ to what src/ builds to")
    for name in args.define:
        if not name.replace("_", "").isalnum() or name[0].isdigit():
            parser.error("--define takes a bare identifier, not %r" % name)
    if args.medium and not args.module:
        parser.error("--medium needs the modules named: a full run resets "
                     "rebuilt/ to what src/ builds to")
    if args.small and not args.define:
        parser.error("--small keeps a build with defines small, so it needs "
                     "--define")
    forced = True if args.medium else (False if args.small else None)

    wanted = args.module or sourcehash.modules()
    # A full run starts pristine, or the tree is a mixture of two runs.
    everything = not args.module and not args.no_stage
    parallel = args.jobs if args.jobs > 1 and len(wanted) > 1 else 1

    log.info("Starting DOS build:",
             wipe=everything,
             clean=args.clean,
             modules=",".join(wanted) if args.module else "everything",
             model="medium" if args.medium else "small" if args.small
             else "manifest",
             parallel=parallel)
    log.debug("Repository root", path=REPO_ROOT)
    log.debug("Source tree", path=SRC_ROOT)
    log.debug("Build scratch", path=BUILD_ROOT)
    log.debug("Staging tree", path=REBUILT_ROOT)
    log.debug("DOSBox binary", path=shutil.which("dosbox"))
    log.debug("DOSBox config", path=args.conf or dosbox_interop.DEFAULT_CONF)

    if args.dry_run:
        log.info("Dry run, stopping before any work")
        return 0

    try:
        with build_lock():
            if everything:
                log.info("Resetting rebuilt/ from decompressed/")
                reset_rebuilt()
                log.info("Finished resetting rebuilt/")
            if args.clean:
                # Before anything is built: wiping mid-stage is a race.
                log.info("Cleaning the build directory", modules=len(wanted))
                for name in wanted:
                    module = manifest_lib.open_module(name)
                    log.info("Cleaning module", module=module.name)
                    shutil.rmtree(os.path.join(BUILD_ROOT, module.name),
                                  ignore_errors=True)
                log.info("Finished cleaning the build directory")

            settings = dict(stage=not args.no_stage,
                            defines=tuple(args.define), medium=forced,
                            **dosbox_interop.common_kwargs(args))
            return build_modules(wanted, parallel, **settings)
    except BuildLocked as error:
        log.error("Not starting: %s" % error)
        return 3
    except (BuildError, manifest_lib.ManifestError,
            transform_lib.TransformError, dosbox_interop.DosBoxError,
            sourcehash.SourceHashError) as error:
        log.exception("Build failed: %s" % error)
        return 2


if __name__ == "__main__":
    sys.exit(main())
