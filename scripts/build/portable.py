#!/usr/bin/env python3
"""Build the game from its C alone with a modern compiler: the same .C and .H
with PORT_MODERN defined, never the .ASM. COVERT is the launcher and carries
the host; every other module is a library it loads."""

import argparse
import os
import platform
import posixpath
import re
import shutil
import subprocess
import sys
import tomllib
from concurrent.futures import ThreadPoolExecutor

if __package__ in (None, ""):
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    __package__ = "build"

from lib import layout
from shared import logging as shared_logging
from shared.metrics import Metrics, step

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SRC = layout.src_root(ROOT)
# Names the directory gcc reads the tree from, where the default is not
# wanted.
STAGE_ENV = "PORTABLE_STAGE"


def on_windows_drive(root):
    """Whether the repository is on a Windows drive mounted into WSL."""
    return ("microsoft" in platform.release().lower()
            and root.startswith("/mnt/"))


def stage_root(root=ROOT, environ=os.environ):
    """The tree gcc reads: $PORTABLE_STAGE if set (empty builds in place), else
    the repository itself, or a copy on the Linux disk where the repository
    is on a Windows drive mounted into WSL."""
    if STAGE_ENV in environ:
        return environ[STAGE_ENV] or root
    if on_windows_drive(root):
        return os.path.join(os.path.expanduser("~"), ".cache",
                            "covert-action-decomp", "portable")
    return root


BUILD_ROOT = stage_root()
OUT = os.path.join(BUILD_ROOT, "build", "portable")
PORTABLE_ROOT = os.path.join(ROOT, "portable")
# Headless apart, so building it never replaces the windowed program.
PORTABLE_HEADLESS_ROOT = os.path.join(ROOT, "portable_headless")

FLAGS = ["-x", "c", "-std=c89", "-Wall", "-Wextra",
         "-Werror=implicit-function-declaration", "-DPORT_MODERN",
         "-Wno-unused-variable", "-Wno-unused-but-set-variable",
         "-Wno-unused-parameter", "-Wno-pointer-sign", "-Wno-main",
         "-Wno-address-of-packed-member", "-Wno-return-type",
         "-Wno-stringop-overflow", "-Wno-stringop-overread", "-Wno-address",
         "-Wno-sequence-point", "-Wno-type-limits",
         "-fno-strict-aliasing", "-g", "-O0"]

# One program per platform under portable/<platform>/: the launcher with
# `suffix`, a module library with `library`. `compiler` is the default, `env`
# the variable that overrides it, `package` the name the toolchain usually goes
# by, `pic` what a library's code is compiled with.
PLATFORMS = {
    "linux": {"compiler": "cc", "env": "CC", "suffix": "", "library": ".so",
              "pic": ["-fPIC"], "package": "gcc"},
    "windows": {"compiler": "x86_64-w64-mingw32-gcc", "env": "CC_WINDOWS",
                "suffix": ".exe", "library": ".dll", "pic": [],
                "package": "gcc-mingw-w64-x86-64"},
}

# The launcher, which is the program, and the entry a module library exports.
LAUNCHER = "COVERT"
ENTRY = "port_main"

# The window the host draws in: SDL2 where the platform has it, none where it
# has not or --no-window asks.
WINDOW_DEFINE = "-DPORT_SDL"
MINGW_ROOT_ENV = "MINGW_ROOT"
MINGW_ROOT = "/usr/x86_64-w64-mingw32"


def screen(platform, wanted=True):
    """The window backend a platform links: (defines, libraries, files to
    put beside the launcher), all empty where there is no window."""
    if not wanted:
        return [], [], []
    if platform == "linux":
        if not shutil.which("sdl2-config"):
            return [], [], []
        ask = lambda flag: subprocess.run(  # noqa: E731
            ["sdl2-config", flag], capture_output=True, text=True).stdout.split()
        return [WINDOW_DEFINE] + ask("--cflags"), ask("--libs"), []
    if platform == "windows":
        root = os.environ.get(MINGW_ROOT_ENV) or MINGW_ROOT
        include = os.path.join(root, "include", "SDL2")
        dll = os.path.join(root, "bin", "SDL2.dll")
        if not os.path.isfile(os.path.join(include, "SDL.h")):
            return [], [], []
        return ([WINDOW_DEFINE, "-I" + include],
                ["-L" + os.path.join(root, "lib"), "-lSDL2"],
                [dll] if os.path.isfile(dll) else [])
    return [], [], []


# What a diagnostic line looks like, for counting rather than parsing.
KINDS = ("error:", "warning:")

# A path with `..` in it, which an include across directories leaves behind.
WINDING = re.compile(r"[\w./+-]*/\.\./[\w./+-]*")

# A tool naming itself by its full path, as `/usr/bin/ld: `.
TOOL = re.compile(r"^/\S+/([\w.+-]+): ")


def shorten(line):
    """A diagnostic with the paths cut to what the reader needs: repo-relative,
    with the `..` of an include collapsed and the tool named by itself."""
    line = TOOL.sub(r"\1: ", line)
    line = WINDING.sub(lambda found: posixpath.normpath(found.group()), line)
    for root in {BUILD_ROOT, ROOT}:
        line = line.replace(root + "/", "").replace(root, "")
    return line


# The seven modules built: INTRO only asks for the drivers this build links in,
# and MISC is assembly alone.
PROGRAMS = ("BUG", "CHASE", "CODE", "COVERT", "FINAL", "GAME", "TAC")


def modules():
    return [name for name in layout.names(SRC) if name in PROGRAMS]


def is_launcher(module):
    return module == LAUNCHER


def compiler(platform):
    """The compiler a platform builds with: its environment override, else
    its default."""
    spec = PLATFORMS[platform]
    return os.environ.get(spec["env"]) or spec["compiler"]


def compiler_found(platform):
    return shutil.which(compiler(platform)) is not None


def platform_dir(platform, window=True):
    """Where a platform's program lands: portable/<platform>/, or
    portable_headless/<platform>/ when built without a window."""
    root = PORTABLE_ROOT if window else PORTABLE_HEADLESS_ROOT
    return os.path.join(root, platform)


def image_path(platform, module, window=True):
    """What a module becomes for a platform: the launcher its executable,
    any other module a library, each with the suffix it takes there."""
    spec = PLATFORMS[platform]
    suffix = spec["suffix"] if is_launcher(module) else spec["library"]
    return os.path.join(platform_dir(platform, window),
                        module.lower() + suffix)


def staged(path):
    """The same repository path in the tree gcc reads."""
    if BUILD_ROOT == ROOT:
        return path
    return os.path.join(BUILD_ROOT, os.path.relpath(path, ROOT))


def sync_sources(log):
    """Bring the staged src/ up to date, copying only what changed; nothing
    to do when building in place."""
    if BUILD_ROOT == ROOT:
        return True
    if not shutil.which("rsync"):
        log.error("rsync not found, so the sources cannot be staged",
                  stage=BUILD_ROOT, override=STAGE_ENV)
        return False
    target = staged(SRC)
    os.makedirs(target, exist_ok=True)
    done = subprocess.run(["rsync", "-a", "--delete", SRC + "/", target + "/"],
                          capture_output=True, text=True)
    for line in done.stderr.splitlines():
        if line.strip():
            log.error(line, source="rsync")
    return done.returncode == 0


def object_dir(platform, module):
    """Where a platform's objects and joined units go, apart from any other's."""
    return os.path.join(OUT, platform, module)


def import_library(platform):
    """The launcher's import library, which a Windows module links against
    to import the host from the executable; none on a platform whose
    executable exports its symbols itself."""
    if platform != "windows":
        return None
    return os.path.join(object_dir(platform, LAUNCHER), "libcovert.a")


def units(module):
    """Every translation unit the module builds, as (target, [source paths]):
    a target's `.C` sources joined as build.py joins them, in manifest order,
    then any `.C` on disk the manifest never names, one unit each."""
    directory = layout.directory_for(module, SRC)
    with open(layout.manifest_path(directory), "rb") as handle:
        manifest = tomllib.load(handle)
    out, seen = [], set()
    for entry in manifest.get("objects", []):
        paths = [layout.source_path(directory, module, name)
                 for name in entry.get("sources", [])
                 if name.upper().endswith(".C")]
        paths = [path for path in paths if os.path.isfile(path)]
        if paths:
            out.append((entry["target"], paths))
            seen.update(os.path.normcase(os.path.abspath(p)) for p in paths)
    for path in layout.c_files(directory):
        if os.path.normcase(os.path.abspath(path)) not in seen:
            out.append((os.path.basename(path), [path]))
    return out


def sources(module):
    """The `.C` files `units` compiles, as the manifest spells them, in the
    order they are joined."""
    return [layout.c_name(path)
            for _, paths in units(module) for path in paths]


def host_units(module):
    """The host side a program links, one unit each: the launcher every file
    under src/shared/host/, a library none; then what its own host/ holds."""
    directory = layout.directory_for(module, SRC)
    shared = (layout.host_files(layout.shared_host_dir(ROOT))
              if is_launcher(module) else [])
    paths = shared + layout.host_files(layout.host_dir(directory))
    return [(os.path.basename(path), [path]) for path in paths]


def entry_define(module):
    """`-D<name>=main` or `-D<name>=port_main` for the routine the manifest's
    [names] spells `main` as: the C run-time calls the launcher's, and the
    launcher calls a module's by the name every library exports."""
    directory = layout.directory_for(module, SRC)
    with open(layout.manifest_path(directory), "rb") as handle:
        names = tomllib.load(handle).get("names", {})
    spelled = names.get("main") or "main"
    entry = "main" if is_launcher(module) else ENTRY
    return ["-D%s=%s" % (spelled, entry)] if spelled != entry else []


def link_command(platform, module, objects, image, libraries):
    """How a program is linked: the launcher exporting the host, a library
    importing it and binding its own names to itself."""
    command = [compiler(platform)]
    if is_launcher(module):
        command += objects + ["-o", image]
        if platform == "windows":
            command += ["-Wl,--export-all-symbols",
                        "-Wl,--out-implib," + import_library(platform)]
        else:
            command += ["-rdynamic"]
        command += libraries
        if platform == "linux":
            command += ["-ldl"]
        return command
    command += ["-shared"] + objects + ["-o", image]
    if platform == "windows":
        command += [import_library(platform)]
    else:
        command += ["-Wl,-Bsymbolic"]
    return command


def missing_symbols(needed, offered):
    """The names a library needs that the launcher does not export: nm's
    `U` lines of the one against the defined names of the other, a
    versioned name (`@`) being a shared library's and never missing."""
    have = {line.split()[-1] for line in offered if line.split()}
    out = set()
    for line in needed:
        parts = line.split()
        if len(parts) < 2 or parts[-2] != "U" or "@" in parts[-1]:
            continue
        if parts[-1] not in have:
            out.add(parts[-1])
    return sorted(out)


def unresolved(platform, module, window=True):
    """What a linked library would fail to load for, on the platform whose
    linker cannot say so: the names it needs that the launcher does not
    export. Empty where the check cannot run."""
    if platform != "linux" or not shutil.which("nm"):
        return []

    def names(flag, path):
        done = subprocess.run(["nm", "-D", flag, path],
                              capture_output=True, text=True)
        return done.stdout.splitlines() if done.returncode == 0 else None

    needed = names("--undefined-only", image_path(platform, module, window))
    offered = names("--defined-only", image_path(platform, LAUNCHER, window))
    if needed is None or offered is None:
        return []
    return missing_symbols(needed, offered)


def joined_unit(platform, module, target, paths):
    """Write the file that stands for a target joined from several sources: one
    `#include` per source, so a diagnostic names the file it came from."""
    path = os.path.join(object_dir(platform, module), target)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="\n") as handle:
        print("/* %s -- the %s target of %s, joined as build.py joins it. */"
              % (target, target, module), file=handle)
        for source in paths:
            print('#include "%s"' % staged(source), file=handle)
    return path


def compile_unit(platform, module, target, paths, extra=(), subdir="",
                 flags=FLAGS):
    """Compile one unit. Returns (ok, [diagnostic lines], object path); the
    caller logs, so a parallel run still reports in unit order."""
    where = staged(layout.directory_for(module, SRC))
    obj = os.path.join(object_dir(platform, module), subdir,
                       os.path.splitext(target)[0] + ".o")
    os.makedirs(os.path.dirname(obj), exist_ok=True)
    source = (staged(paths[0]) if len(paths) == 1
              else joined_unit(platform, module, target, paths))
    # Flags first, -x c binds after.
    command = ([compiler(platform), "-c"] + list(flags) + list(extra)
               + ["-I", where,
                  "-I", layout.include_dir(where),
                  "-I", layout.shared_dir(BUILD_ROOT)])
    command += [source, "-o", obj]
    done = subprocess.run(command, capture_output=True, text=True)
    lines = [line for line in done.stderr.splitlines() if line.strip()]
    return done.returncode == 0, lines, obj


def count(lines):
    tally = {kind: 0 for kind in KINDS}
    for line in lines:
        for kind in KINDS:
            if kind in line:
                tally[kind] += 1
    return tally


def module_source(platform, name):
    return "portable.%s.%s" % (platform, name)


def build(platform, module, window=True, launcher_built=True, jobs=1,
         flags=FLAGS):
    """Compile and link one program; a library only links when the
    launcher it imports from was built this run."""
    metrics = Metrics()
    log = shared_logging.get_logger(module_source(platform, module))
    launcher = is_launcher(module)
    kind = "launcher" if launcher else "library"
    log.info("Building module", module=module, platform=platform, kind=kind)
    parts = units(module)
    if not parts:
        log.warning("No C to build", module=module)
        return None
    host = host_units(module)
    pic = [] if launcher else PLATFORMS[platform]["pic"]
    entry = entry_define(module) + pic
    defines, libraries, beside = (screen(platform, window) if launcher
                                  else ([], [], []))

    work = ([(target, paths, entry, "") for target, paths in parts]
            + [(target, paths, defines + pic, "host") for target, paths in host])
    objects, said, failed = [], [], []
    with step(log, metrics, "compile"):
        with ThreadPoolExecutor(max_workers=max(1, jobs)) as pool:
            results = list(pool.map(
                lambda job: compile_unit(platform, module, job[0], job[1],
                                         extra=job[2], subdir=job[3],
                                         flags=flags),
                work))
        for (target, _, _, _), (ok, lines, obj) in zip(work, results):
            for line in lines:
                at = log.error if KINDS[0] in line else log.debug
                at(shorten(line), source=target)
            said.extend(lines)
            if ok:
                objects.append(obj)
            else:
                failed.append(target)
    linked = None
    image = image_path(platform, module, window)
    against = (import_library(platform)
               or image_path(platform, LAUNCHER, window))
    if not failed and not launcher and not (launcher_built
                                            and os.path.isfile(against)):
        log.error("The launcher did not build, so nothing to link against",
                  wanted=against)
        linked = False
    elif not failed:
        with step(log, metrics, "link"):
            os.makedirs(os.path.dirname(image), exist_ok=True)
            done = subprocess.run(
                link_command(platform, module, objects, image, libraries),
                capture_output=True, text=True)
            linked = done.returncode == 0
            at = log.debug if linked else log.error
            for line in done.stderr.splitlines():
                if line.strip():
                    at(shorten(line), source="link")
            said.extend(done.stderr.splitlines())
            for path in beside if linked else ():
                shutil.copy2(path, os.path.dirname(image))
        if linked and not launcher:
            for name in unresolved(platform, module, window):
                log.error("The launcher does not export a name the library "
                          "needs", symbol=name, source="link")
                said.append("error: undefined reference to " + name)
                linked = False

    tally = count(said)
    success = linked is True
    at = log.info if success else log.error
    at("Built module" if success else "Failed to build module",
       module=module, platform=platform, kind=kind, success=success,
       units=len(parts), host=len(host),
       compiled=len(parts) + len(host) - len(failed),
       errors=tally["error:"], warnings=tally["warning:"],
       link="ok" if linked else ("failed" if linked is False else "not tried"),
       duration_ms=metrics.total_ms)
    return {"module": module, "platform": platform, "kind": kind,
            "units": len(parts), "host": len(host),
            "compiled": len(parts) + len(host) - len(failed),
            "linked": linked, "errors": tally["error:"],
            "warnings": tally["warning:"]}


def build_order(wanted):
    """The launcher first, and always: a library links against what it
    exports, and is checked against it."""
    return [LAUNCHER] + [name for name in wanted if name != LAUNCHER]


def build_platform(platform, wanted, log, window=True, jobs=1, flags=FLAGS):
    """Build every wanted module for one platform. Returns (rows, ok), ok
    false when the platform's compiler is not there to build with."""
    if not compiler_found(platform):
        spec = PLATFORMS[platform]
        log.error("Compiler not found, platform not built", platform=platform,
                  compiler=compiler(platform), override=spec["env"],
                  package=spec["package"])
        return [], False
    metrics = Metrics()
    order = build_order(wanted)
    log.info("Building platform", platform=platform, count=len(order),
             compiler=compiler(platform), into=platform_dir(platform, window),
             window="SDL2" if screen(platform, window)[0] else "none")
    rows = []
    with metrics.stage(platform):
        launcher_built = False
        for name in order:
            row = build(platform, name, window, launcher_built, jobs, flags)
            if row:
                rows.append(row)
            if is_launcher(name):
                launcher_built = bool(row and row["linked"])
    failed = sum(1 for row in rows if not row["linked"])
    at = log.error if failed else log.info
    at("Finished building platform", platform=platform, count=len(rows),
       linked=len(rows) - failed, failed=failed,
       errors=sum(row["errors"] for row in rows),
       warnings=sum(row["warnings"] for row in rows),
       duration_ms=metrics.total_ms)
    return rows, not failed


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("module", nargs="*",
                        help="module name, e.g. GAME; the launcher is "
                             "always built first")
    parser.add_argument("--all", action="store_true", help="every module")
    parser.add_argument("--platform", action="append", choices=PLATFORMS,
                        help="build this platform only (repeatable); "
                             "default every platform")
    parser.add_argument("--no-window", action="store_true",
                        help="link no window backend: the host draws to "
                             "nothing and reads scripted keys")
    parser.add_argument("--with-debug", action="store_true",
                        help="compile in DEBUG_MESSAGE* (off by default)")
    parser.add_argument("--with-trace", action="store_true",
                        help="compile in TRACE_MESSAGE* (off by default)")
    parser.add_argument("--define", action="append", default=[],
                        metavar="NAME",
                        help="define NAME for every unit (repeatable): one "
                             "of the optional changes")
    parser.add_argument("-j", "--jobs", type=int, default=os.cpu_count() or 1,
                        help="units compiled at once (default: every CPU)")
    shared_logging.add_arguments(parser)
    args = parser.parse_args(argv)
    shared_logging.configure(args, "portable")
    log = shared_logging.get_logger("main")

    wanted = modules() if args.all or not args.module else args.module
    for name in [name for name in wanted if name not in PROGRAMS]:
        log.warning("Not a compiled program, skipping", module=name)
    wanted = [name for name in wanted if name in PROGRAMS]
    platforms = [name for name in PLATFORMS
                 if not args.platform or name in args.platform]
    flags = list(FLAGS)
    if args.with_debug:
        flags.append("-DPORT_DEBUG=1")
    if args.with_trace:
        flags.append("-DPORT_TRACE=1")
    for name in args.define:
        if not name.replace("_", "").isalnum() or name[0].isdigit():
            parser.error("--define takes a bare identifier, not %r" % name)
        flags.append("-D%s" % name)
    metrics = Metrics()
    log.info("Building modules", count=len(wanted), platforms=platforms,
             tree=BUILD_ROOT, jobs=args.jobs, with_debug=args.with_debug,
             with_trace=args.with_trace)
    with metrics.stage("stage"):
        if not sync_sources(log):
            return 1
    rows, failed = [], []
    with metrics.stage("platforms"):
        for platform in platforms:
            built, ok = build_platform(platform, wanted, log,
                                       window=not args.no_window,
                                       jobs=args.jobs, flags=flags)
            rows.extend(built)
            if not ok:
                failed.append(platform)

    at = log.error if failed else log.info
    at("Finished building modules", count=len(rows),
       linked=sum(1 for row in rows if row["linked"]),
       failed=sum(1 for row in rows if not row["linked"]),
       platforms_failed=failed,
       errors=sum(row["errors"] for row in rows),
       warnings=sum(row["warnings"] for row in rows),
       duration_ms=metrics.total_ms)
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
