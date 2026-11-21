#!/usr/bin/env python3
"""Lay out the DOS toolchain tree from the extracted MSC 5.1 / MASM 5.1 disks.

Produces the tree scripts/build/ expects:

    dos/msc51/bin      compiler passes, LINK 3.65, LIB 3.11, SETUP
    dos/msc51/include  C headers
    dos/msc51/lib      component libraries, for SETUP /L to combine
    dos/msc51/src      C runtime startup source
    dos/masm51/bin     MASM 5.10, CREF
    dos/masm51/include MASM headers

Several tools are on the disks in both DOS real-mode and OS/2 bound forms, so
the lists below name the disk each file comes from.

This copies only: the combined libraries (LLIBCE.LIB and the rest) are on no
disk, and SETUP /L builds them afterwards.

Usage:
    python layout_toolchain.py --disks DIR --dest DIR [--dry-run]
"""

import argparse
import os
import shutil
import sys

# (source disk, source path within disk, destination path within chain)
#
# LINK: the real-mode Overlay Linker 3.65 is on Utilities 3. Utilities 1
# carries the OS/2 linker, 5.01.21, and MASM's own disks 3.64 and 5.01.20.
MSC = [
    ("Setup (01521)", "CL.EXE", "bin/CL.EXE"),
    ("Setup (01521)", "CL.ERR", "bin/CL.ERR"),
    ("Setup (01521)", "CL.HLP", "bin/CL.HLP"),
    ("Setup (01521)", "C1.EXE", "bin/C1.EXE"),
    ("Setup (01521)", "C23.ERR", "bin/C23.ERR"),
    ("Setup (01521)", "SETUP.EXE", "bin/SETUP.EXE"),
    ("Compiler 1 (01522)", "C1L.EXE", "bin/C1L.EXE"),
    ("Compiler 1 (01522)", "C3.EXE", "bin/C3.EXE"),
    ("Compiler 1 (01522)", "C1.ERR", "bin/C1.ERR"),
    ("Compiler 2 (01523)", "C2.EXE", "bin/C2.EXE"),
    ("Utilities 3 (02113)", "LINK.EXE", "bin/LINK.EXE"),  # 3.65 -- see above
    ("Utilities 1 (01524)", "LIB.EXE", "bin/LIB.EXE"),
    ("Utilities 1 (01524)", "EXEHDR.EXE", "bin/EXEHDR.EXE"),
    ("Utilities 1 (01524)", "EXEMOD.EXE", "bin/EXEMOD.EXE"),
    ("Utilities 1 (01524)", "ERROUT.EXE", "bin/ERROUT.EXE"),
    ("Utilities 1 (01524)", "MAKE.EXE", "bin/MAKE.EXE"),
    # Not on the build path, where scripts/interop/exepack.py stands in for it.
    ("Utilities 1 (01524)", "EXEPACK.EXE", "bin/EXEPACK.EXE"),
    # Component libraries, which SETUP /L merges into the combined libraries CL
    # names on the link line. All models and both float packages.
    ("Libraries (Small and Medium Models) (01527)", "SLIBCR.LIB", "lib/SLIBCR.LIB"),
    ("Libraries (Small and Medium Models) (01527)", "SLIBFA.LIB", "lib/SLIBFA.LIB"),
    ("Libraries (Small and Medium Models) (01527)", "SVARSTCK.OBJ", "lib/SVARSTCK.OBJ"),
    ("Libraries (Small and Medium Models) (01527)", "MLIBCR.LIB", "lib/MLIBCR.LIB"),
    ("Libraries (Small and Medium Models) (01527)", "MLIBFA.LIB", "lib/MLIBFA.LIB"),
    ("Libraries (Small and Medium Models) (01527)", "MVARSTCK.OBJ", "lib/MVARSTCK.OBJ"),
    ("Libraries (Large and Compact Models) (01528)", "CLIBCR.LIB", "lib/CLIBCR.LIB"),
    ("Libraries (Large and Compact Models) (01528)", "CVARSTCK.OBJ", "lib/CVARSTCK.OBJ"),
    ("Libraries (Large and Compact Models) (01528)", "LLIBCR.LIB", "lib/LLIBCR.LIB"),
    ("Libraries (Large and Compact Models) (01528)", "LLIBFA.LIB", "lib/LLIBFA.LIB"),
    ("Libraries (Large and Compact Models) (01528)", "LVARSTCK.OBJ", "lib/LVARSTCK.OBJ"),
    ("Floating-Point Libraries (01529)", "SLIBFP.LIB", "lib/SLIBFP.LIB"),
    ("Floating-Point Libraries (01529)", "MLIBFP.LIB", "lib/MLIBFP.LIB"),
    ("Floating-Point Libraries (01529)", "CLIBFP.LIB", "lib/CLIBFP.LIB"),
    ("Floating-Point Libraries (01529)", "CLIBFA.LIB", "lib/CLIBFA.LIB"),
    ("Floating-Point Libraries (01529)", "LLIBFP.LIB", "lib/LLIBFP.LIB"),
    ("Floating-Point Libraries (01529)", "EM.LIB", "lib/EM.LIB"),
    ("Floating-Point Libraries (01529)", "87.LIB", "lib/87.LIB"),
    ("Floating-Point Libraries (01529)", "LIBH.LIB", "lib/LIBH.LIB"),
    ("Floating-Point Libraries (01529)", "GRAPHICS.LIB", "lib/GRAPHICS.LIB"),
    ("Floating-Point Libraries (01529)", "BINMODE.OBJ", "lib/BINMODE.OBJ"),
    ("Floating-Point Libraries (01529)", "SETARGV.OBJ", "lib/SETARGV.OBJ"),
]

# Whole directories: (source disk, source subdir, destination subdir)
MSC_TREES = [
    ("Include Files and Startup Source Code (01526)", "INCLUDE", "include"),
    ("Include Files and Startup Source Code (01526)", "STARTUP", "src/STARTUP"),
]

# MASM.EXE is 110,703 bytes on disk01 (real-mode DOS) and 124,712 on disk05
# (bound OS/2); the first is the one wanted.
MASM = [
    ("disk01", "MASM.EXE", "bin/MASM.EXE"),
    ("disk01", "CREF.EXE", "bin/CREF.EXE"),
    ("disk03", "DOS.INC", "include/DOS.INC"),
    ("disk03", "BIOS.INC", "include/BIOS.INC"),
]

# CMACROS.INC ships with MSC's startup source, but it is a MASM include.
MASM_FROM_MSC = [
    ("Include Files and Startup Source Code (01526)", "STARTUP/CMACROS.INC", "include/CMACROS.INC"),
    ("Include Files and Startup Source Code (01526)", "STARTUP/MSDOS.INC", "include/MSDOS.INC"),
]


def copy_file(src, dst, dry_run):
    if not os.path.isfile(src):
        raise FileNotFoundError(src)
    print(f"  {dst}")
    if dry_run:
        return
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    shutil.copy2(src, dst)


def copy_tree(src, dst, dry_run):
    if not os.path.isdir(src):
        raise FileNotFoundError(src)
    count = 0
    for dirpath, _, filenames in os.walk(src):
        for name in sorted(filenames):
            rel = os.path.relpath(os.path.join(dirpath, name), src)
            if not dry_run:
                target = os.path.join(dst, rel)
                os.makedirs(os.path.dirname(target), exist_ok=True)
                shutil.copy2(os.path.join(dirpath, name), target)
            count += 1
    print(f"  {dst}/ ({count} files)")
    return count


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--disks", required=True, help="extracted disks root")
    parser.add_argument("--dest", required=True, help="dos/ directory to build")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args(argv)

    msc_disks = os.path.join(args.disks, "msc51")
    masm_disks = os.path.join(args.disks, "masm51")
    msc_dest = os.path.join(args.dest, "msc51")
    masm_dest = os.path.join(args.dest, "masm51")

    missing = []

    def place(disk_root, entries, dest_root):
        for disk, src_rel, dst_rel in entries:
            src = os.path.join(disk_root, disk, src_rel)
            try:
                copy_file(src, os.path.join(dest_root, dst_rel), args.dry_run)
            except FileNotFoundError:
                print(f"  MISSING {disk}/{src_rel}", file=sys.stderr)
                missing.append(f"{disk}/{src_rel}")

    print("msc51:")
    place(msc_disks, MSC, msc_dest)
    for disk, src_rel, dst_rel in MSC_TREES:
        copy_tree(
            os.path.join(msc_disks, disk, src_rel),
            os.path.join(msc_dest, dst_rel),
            args.dry_run,
        )

    print("masm51:")
    place(masm_disks, MASM, masm_dest)
    place(msc_disks, MASM_FROM_MSC, masm_dest)

    if missing:
        print(f"\n{len(missing)} file(s) missing -- layout incomplete", file=sys.stderr)
        return 1

    print("\nLayout complete. Combined libraries still need SETUP /L.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
