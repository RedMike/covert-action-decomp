#!/usr/bin/env python3
"""Raw access to the MSC 5.1 / MASM 5.1 build tools over a DOSBox session: one
method per tool, each building the command that runs it from the flags it is
given. Reached as `DosBox(...).tools`."""

import os
import re

from .dosbox import (DRIVE_IN, DRIVE_OUT, Command, dos_path, split_io,
                     write_response)

# LINK batches object files 8 per line with '+' continuation, to stay under the
# DOS command-line length limit.
LINK_OBJS_PER_LINE = 8

# Which toolchain tree each tool lives in.
CHAINS = {
    "cl": "msc51",
    "link": "msc51",
    "masm": "masm51",
}


class BuildTools:
    """The three DOS build tools, bound to one DOSBox session."""

    def __init__(self, session):
        self.dosbox = session

    # ----------------------------------------------------------------- cl

    def cl_command(self, sources, out_obj, flags=()):
        """The `cl /c` command, built but not run."""
        in_dir, names = split_io(sources)
        out_dir = os.path.dirname(os.path.abspath(out_obj))
        out_name = os.path.basename(out_obj)
        drive = DRIVE_IN if os.path.samefile(in_dir, out_dir) else DRIVE_OUT

        cmdline = "cl"
        if flags:
            cmdline += " " + " ".join(flags)
        cmdline += f" /c /Fo{drive}:\\{dos_path(out_name)} " + " ".join(names)
        return Command("cl", CHAINS["cl"], cmdline, in_dir, out_dir,
                       expect=[out_name], label=" ".join(names),
                       inputs=sources)

    # --------------------------------------------------------------- masm

    def masm_command(self, source, out_obj, flags=()):
        """The `masm` command, built but not run."""
        in_dir, names = split_io([source])
        out_dir = os.path.dirname(os.path.abspath(out_obj))
        out_name = os.path.basename(out_obj)
        drive = DRIVE_IN if os.path.samefile(in_dir, out_dir) else DRIVE_OUT

        cmdline = "masm"
        if flags:
            cmdline += " " + " ".join(flags)
        # MASM's positional form: source,object,listing,cross-reference; with
        # both trailing fields NUL, since an empty one makes MASM write a .LST
        # and a .CRF by default.
        cmdline += f" {names[0]},{drive}:\\{dos_path(out_name)},NUL,NUL;"
        return Command("masm", CHAINS["masm"], cmdline, in_dir, out_dir,
                       expect=[out_name], label=names[0], inputs=[source])

    # --------------------------------------------------------------- link

    def link_command(self, objs, out_exe, libs=(), load_libs=(), flags=(),
                     map_file=True):
        """The `link` command, built but not run. A library named with the
        objects is a load library, linked whole; one in its own section
        contributes only what references pull in. /M is on by default. The
        objects need not exist yet: a compile ahead of this in the batch
        writes them."""
        in_dir, names = split_io(objs, must_exist=False)
        out_dir = os.path.dirname(os.path.abspath(out_exe))
        out_name = os.path.basename(out_exe)
        same = os.path.samefile(in_dir, out_dir)
        drive = DRIVE_IN if same else DRIVE_OUT

        stem = os.path.splitext(out_name)[0]
        map_name = f"{stem}.map" if map_file else None

        entries = list(names) + list(load_libs)
        lines = []
        for index in range(0, len(entries), LINK_OBJS_PER_LINE):
            chunk = entries[index : index + LINK_OBJS_PER_LINE]
            suffix = "+" if index + LINK_OBJS_PER_LINE < len(entries) else ""
            lines.append(" ".join(chunk) + suffix)
        lines.append(f"{drive}:\\{dos_path(out_name)}")
        lines.append(f"{drive}:\\{dos_path(map_name)}" if map_name else "NUL")
        lines.append(" ".join(libs) if libs else ";")

        rsp_name = f"{stem}.rsp"
        rsp_path = os.path.join(in_dir, rsp_name)
        write_response(rsp_path, "\r\n".join(lines) + "\r\n", self.dosbox.debug)

        flags = list(flags)
        if map_file and not any(f.upper().startswith("/M") for f in flags):
            flags.append("/M")

        cmdline = "link"
        if flags:
            cmdline += " " + " ".join(flags)
        cmdline += f" @{rsp_name}"

        expect = [out_name] + ([map_name] if map_name else [])
        return Command("link", CHAINS["link"], cmdline, in_dir, out_dir,
                       expect=expect, label=out_name, cleanup=[rsp_path],
                       inputs=objs)

    def check_link(self, result):
        """LINK's verdict, from its log: LINK writes an executable even when it
        errors. The output is printed too."""
        if re.search(r"error L[0-9]+", result.output):
            if result.ok and not self.dosbox.verbose:
                print(result.output.rstrip())
            result.ok = False
        return result
