#!/usr/bin/env python3
"""Build decompressed/: a copy of original/ with every EXEPACK'd .EXE replaced
by its unpacked form. original/ is never touched, plain MZ executables are
copied as they are, and the bundled DOSBox tree is copied without being
scanned.

Usage:
    python scripts/setup/build_decompressed.py [--original DIR] [--dest DIR]
                                               [--keep] [--dry-run]

    --original   source tree (default: <repo>/original)
    --dest       destination tree (default: <repo>/decompressed)
    --keep       don't wipe the destination first; overwrite in place
    --dry-run    report what would happen, change nothing
"""

import argparse
import os
import shutil
import sys

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(REPO_ROOT, "scripts"))

from interop import exepack  # noqa: E402  (needs the sys.path tweak above)

# Copied verbatim, never inspected: modern Win32 binaries, not game code.
SKIP_DIRS = {"dosbox_windows"}


def iter_exe_files(root):
    """Yield every .EXE under root, skipping the non-game subtrees."""
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d.lower() not in SKIP_DIRS]
        for name in sorted(filenames):
            if name.lower().endswith(".exe"):
                yield os.path.join(dirpath, name)


def main(argv=None):
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    ap.add_argument("--original", default=os.path.join(REPO_ROOT, "original"))
    ap.add_argument("--dest", default=os.path.join(REPO_ROOT, "decompressed"))
    ap.add_argument("--keep", action="store_true",
                    help="don't wipe the destination first")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args(argv)

    original = os.path.abspath(args.original)
    dest = os.path.abspath(args.dest)

    if not os.path.isdir(original):
        sys.exit(f"error: source tree not found: {original}\n"
                 "Install the retail release into original/ first.")
    if os.path.commonpath([original, dest]) in (original, dest):
        sys.exit(f"error: {dest} and {original} must not contain each other.")

    if args.dry_run:
        print(f"[dry-run] would rebuild {dest} from {original}")
    else:
        if os.path.exists(dest) and not args.keep:
            print(f"clearing {dest}")
            shutil.rmtree(dest)
        print(f"copying {original} -> {dest}")
        shutil.copytree(original, dest, dirs_exist_ok=True)

    unpacked = skipped = 0
    failures = []
    scan_root = dest if not args.dry_run else original

    for path in iter_exe_files(scan_root):
        rel = os.path.relpath(path, scan_root)
        try:
            data = open(path, "rb").read()
            if not exepack.is_exepack(data):
                skipped += 1
                continue
            out = exepack.unpack(data)
        except (exepack.ExepackError, OSError) as e:
            failures.append((rel, str(e)))
            print(f"  FAIL    {rel}: {e}")
            continue

        unpacked += 1
        if args.dry_run:
            print(f"  [dry-run] would unpack {rel} ({len(data)} -> {len(out)} bytes)")
        else:
            open(path, "wb").write(out)
            print(f"  unpacked {rel} ({len(data)} -> {len(out)} bytes)")

    print(f"\n{unpacked} unpacked, {skipped} left as-is, {len(failures)} failed")
    if failures:
        return 1
    if not args.dry_run:
        print(f"decompressed copy ready at {dest}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
