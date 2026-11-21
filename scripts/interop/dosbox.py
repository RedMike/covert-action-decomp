#!/usr/bin/env python3
"""Raw access to headless DOSBox, and through it the 16-bit DOS toolchain: a
session running DOS command lines with one directory mounted in and another
out, many to an emulator since SDL, XMS, the mounts and COMMAND.COM cost more
than the tools. Runs on Linux, which on Windows means under WSL.
"""

import os
import shutil
import subprocess
import sys
import tempfile
import uuid

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
DEFAULT_CONF = os.path.join(REPO_ROOT, "scripts", "interop", "toolchain.conf")

# No C: here: DOSBox auto-mounts the batch's directory, so C: is the toolchain.
DRIVE_IN = "d"
DRIVE_OUT = "e"
DRIVE_TMP = "f"

# Echoed by the batch itself to cut the shared log per command; no tool emits it.
BATCH_MARK = "#dostool#"


class DosBoxError(Exception):
    pass


def env_value(name):
    """Read one variable out of .env rather than sourcing it."""
    path = os.path.join(REPO_ROOT, ".env")
    if not os.path.isfile(path):
        return None
    value = None
    with open(path, encoding="utf-8") as handle:
        for line in handle:
            line = line.strip()
            if line.startswith(f"{name}="):
                value = line[len(name) + 1 :].strip().strip('"')
    return value or None


def toolchain_dir():
    value = os.environ.get("DOS_TOOLCHAIN_DIR") or env_value("DOS_TOOLCHAIN_DIR")
    if not value:
        raise DosBoxError("DOS_TOOLCHAIN_DIR is not set (check .env)")
    if not os.path.isdir(value):
        raise DosBoxError(f"DOS_TOOLCHAIN_DIR does not exist: {value}")
    return value


def dos_path(path):
    return path.replace("/", "\\")


def fix_case(path):
    """Rename a DOS-uppercased file to the lowercase name we asked for: on a
    case-sensitive filesystem the two are different files."""
    if os.path.isfile(path):
        return True
    directory = os.path.dirname(path) or "."
    wanted = os.path.basename(path).lower()
    if not os.path.isdir(directory):
        return False
    for name in os.listdir(directory):
        if name.lower() == wanted:
            os.rename(os.path.join(directory, name), path)
            return True
    return False


def refresh_name(path):
    """Round-trip a rename, to shake off the stale uppercase name a Windows
    drive mounted into WSL can keep."""
    if os.path.isfile(path):
        tmp = path + ".tmp"
        os.rename(path, tmp)
        os.rename(tmp, path)


class Result:
    def __init__(self, ok, output, log, artifacts):
        self.ok = ok
        self.output = output  # the tool's own stdout, captured in DOS
        self.log = log  # the emulator's stderr/stdout
        self.artifacts = artifacts  # produced files that were found

    def __bool__(self):
        return self.ok


class Command:
    """One DOS command line and the files it needs, built without a session;
    `run_batch` runs it. `expect` is under `out_dir`."""

    __slots__ = ("tool", "chain", "cmdline", "in_dir", "out_dir", "expect",
                 "label", "cleanup", "inputs")

    def __init__(self, tool, chain, cmdline, in_dir, out_dir, expect=(),
                 label=None, cleanup=(), inputs=()):
        self.tool = tool
        self.chain = chain
        self.cmdline = cmdline
        self.in_dir = os.path.abspath(in_dir)
        self.out_dir = os.path.abspath(out_dir)
        self.expect = tuple(expect)
        self.label = label or cmdline
        self.cleanup = tuple(cleanup)
        self.inputs = tuple(os.path.abspath(p) for p in inputs)

    def __repr__(self):
        return "<command %s %s>" % (self.tool, self.label)


def check_inputs(commands):
    """Every command's input is on disk, or written by one ahead of it in the
    batch."""
    promised = set()
    for command in commands:
        for path in command.inputs:
            if os.path.isfile(path) or path in promised:
                continue
            raise DosBoxError(
                "%s reads %s, which does not exist and is not written by any "
                "command before it in this batch" % (command.label, path))
        promised.update(os.path.join(command.out_dir, name)
                        for name in command.expect)


def split_log(text, count):
    """A batch's shared log, cut into one command's output per entry.
    Noise before the first marker is dropped; a quiet tool's entry stays empty."""
    outputs = [""] * count
    current = None
    buffer = []
    for line in (text or "").splitlines(keepends=True):
        stripped = line.strip()
        if stripped.startswith(BATCH_MARK):
            if current is not None:
                outputs[current] = "".join(buffer)
            buffer = []
            try:
                index = int(stripped[len(BATCH_MARK):].strip())
            except ValueError:
                current = None
                continue
            current = index if 0 <= index < count else None
            continue
        buffer.append(line)
    if current is not None:
        outputs[current] = "".join(buffer)
    return outputs


class DosBox:
    """A headless DOSBox session: each `run` is its own emulator invocation,
    since DOSBox cannot be kept alive and fed commands."""

    def __init__(self, conf=None, verbose=False, debug=False):
        self.root = toolchain_dir()
        self.conf = conf or DEFAULT_CONF
        self.verbose = verbose
        self.debug = debug

        if not os.path.isfile(self.conf):
            raise DosBoxError(f"missing DOSBox config: {self.conf}")
        if not shutil.which("dosbox"):
            if sys.platform == "win32":
                raise DosBoxError(
                    "the DOS build runs on Linux. On Windows, run it under "
                    "WSL:\n"
                    "  wsl python3 scripts/build/build.py ..."
                )
            raise DosBoxError("dosbox is not installed, or not on PATH")

    @property
    def tools(self):
        """The build tools, bound to this session."""
        from . import buildtools

        return buildtools.BuildTools(self)

    def _log(self, message):
        if self.debug:
            print(f"dosbox: {message}", file=sys.stderr)

    def have_chain(self, chain):
        return os.path.isdir(os.path.join(self.root, chain))

    def run_batch(self, commands, pre_lines=()):
        """Run many DOS command lines in one emulator, one Result each, in order.
        One batch is one pair of mounts; a failure does not stop what follows."""
        commands = list(commands)
        if not commands:
            raise DosBoxError("no commands to run")
        for command in commands:
            if not self.have_chain(command.chain):
                raise DosBoxError(
                    f"no toolchain '{command.chain}' under {self.root}")

        in_dirs = {c.in_dir for c in commands}
        out_dirs = {c.out_dir for c in commands}
        if len(in_dirs) != 1 or len(out_dirs) != 1:
            raise DosBoxError(
                "one batch is one pair of mounts, so every command in it has "
                "to share an input and an output directory; got inputs %s and "
                "outputs %s" % (", ".join(sorted(in_dirs)),
                                ", ".join(sorted(out_dirs))))
        in_dir, out_dir = in_dirs.pop(), out_dirs.pop()
        for path, label in ((in_dir, "input"), (out_dir, "output")):
            if not os.path.isdir(path):
                raise DosBoxError(f"{label} directory does not exist: {path}")

        check_inputs(commands)

        same = os.path.samefile(in_dir, out_dir)
        out_drive = DRIVE_IN if same else DRIVE_OUT

        log_name = "dostool.log"
        log_path = os.path.join(out_dir, log_name)
        for stale in (log_path, log_path.upper()):
            if os.path.isfile(stale):
                os.remove(stale)
        # Delete what is expected first: its presence afterwards is the proof.
        for command in commands:
            for name in command.expect:
                target = os.path.join(out_dir, name)
                if os.path.isfile(target):
                    os.remove(target)

        tmp_dir = tempfile.mkdtemp(prefix="dostool-")
        # Per batch, not per process (parallel builds share one); eight chars for 8.3.
        bat_path = os.path.join(self.root, "dt%s.bat" % uuid.uuid4().hex[:6])

        lines = ["@echo off", f"mount {DRIVE_IN} {in_dir}"]
        if not same:
            lines.append(f"mount {DRIVE_OUT} {out_dir}")
        lines += [
            f"mount {DRIVE_TMP} {tmp_dir}",
            f"set TMP={DRIVE_TMP.upper()}:\\",
            *pre_lines,
            f"{DRIVE_IN}:",
        ]
        chain = None
        for index, command in enumerate(commands):
            if command.chain != chain:
                chain = command.chain
                # Re-set, never both at once: MASM 5.1 ships its own LINK.EXE.
                lines += [
                    f"set PATH=Z:\\;C:\\{chain}\\bin",
                    f"set INCLUDE=C:\\{chain}\\include",
                    f"set LIB=C:\\{chain}\\lib",
                ]
            lines.append(
                f"echo {BATCH_MARK}{index} >> {out_drive}:\\{log_name}")
            lines.append(f"{command.cmdline} >> {out_drive}:\\{log_name}")
        batch = "\r\n".join(lines) + "\r\n"
        self._log(f"batch:\n{batch}")

        try:
            with open(bat_path, "w", newline="") as handle:
                handle.write(batch)

            env = dict(os.environ)
            env.setdefault("SDL_VIDEODRIVER", "dummy")
            proc = subprocess.run(
                ["dosbox", "-conf", self.conf, bat_path, "-exit"],
                capture_output=True,
                text=True,
                env=env,
            )
            emu_log = proc.stdout + proc.stderr
        finally:
            if os.path.isfile(bat_path):
                os.remove(bat_path)
            shutil.rmtree(tmp_dir, ignore_errors=True)
            for command in commands:
                for stale in command.cleanup:
                    for name in (stale, stale.upper()):
                        if os.path.isfile(name):
                            os.remove(name)

        fix_case(log_path)
        text = ""
        if os.path.isfile(log_path):
            with open(log_path, encoding="cp437", errors="replace") as handle:
                text = handle.read()
            os.remove(log_path)
        outputs = split_log(text, len(commands))

        results = []
        for index, command in enumerate(commands):
            artifacts = []
            for name in command.expect:
                target = os.path.join(out_dir, name)
                if fix_case(target):
                    refresh_name(target)
                    artifacts.append(target)
            results.append(Result(len(artifacts) == len(command.expect),
                                  outputs[index], emu_log, artifacts))
        return results


def split_io(paths, must_exist=True):
    """All inputs must share one directory; return (directory, [basenames]).
    `must_exist` is False for LINK's objects: earlier commands write them."""
    if not paths:
        raise DosBoxError("no input files")
    dirs = {os.path.dirname(os.path.abspath(p)) for p in paths}
    if len(dirs) != 1:
        raise DosBoxError(
            "all input files must be in one directory (DOSBox gets one input "
            f"drive); got: {', '.join(sorted(dirs))}"
        )
    if must_exist:
        for path in paths:
            if not os.path.isfile(path):
                raise DosBoxError(f"input file does not exist: {path}")
    return dirs.pop(), [os.path.basename(p) for p in paths]


def write_response(path, text, debug=False):
    with open(path, "w", newline="") as handle:
        handle.write(text)
    if debug:
        print(f"--- {path}\n{text}---", file=sys.stderr)


def add_common_args(parser):
    """Flags shared by every front-end that drives DOSBox."""
    parser.add_argument("-v", "--verbose", action="store_true",
                        help="print LINK's output even where it reports no "
                             "error")
    parser.add_argument("-d", "--debug", action="store_true",
                        help="print the generated batch and response files")
    parser.add_argument("--conf", help=f"DOSBox config (default: {DEFAULT_CONF})")


def common_kwargs(args):
    return {"verbose": args.verbose, "debug": args.debug, "conf": args.conf}
