#!/usr/bin/env python3
"""Put the shipped copyright patch back over a linked module. In the retail
FINAL.EXE one routine's `JNE` is two `NOP`s, which C cannot produce, so the
C carries the real branch: `copyright_patch = false` yields what was
compiled, true what shipped."""

import os

# 1100:1728..1736, FUN_1100_1394's answer test and both arms, matched by bytes.
FIND = bytes.fromhex("8b469e3946a27505b80100eb022bc0")  # 75 05, the real JNE
PATCHED = bytes.fromhex("8b469e3946a29090b80100eb022bc0")  # 90 90, as shipped

assert len(FIND) == len(PATCHED)


class CopyrightPatchError(Exception):
    """The site was not in the linked file exactly once."""


def occurrences(image, pattern):
    """Every offset `pattern` starts at, overlaps included."""
    out, at = [], image.find(pattern)
    while at != -1:
        out.append(at)
        at = image.find(pattern, at + 1)
    return out


def apply(path):
    """Rewrite the file at `path` with the patch in it, and say where. Raises
    `CopyrightPatchError` without writing unless the site is there exactly once."""
    with open(path, "rb") as handle:
        image = handle.read()
    found = occurrences(image, FIND)
    if len(found) != 1:
        raise CopyrightPatchError(complaint(path, image, found))
    at = found[0]
    with open(path, "wb") as handle:
        handle.write(image[:at] + PATCHED + image[at + len(FIND):])
    return at


def complaint(path, image, found):
    """Why the patch could not be placed, in terms of what to do about it."""
    where = os.path.basename(path)
    if len(found) > 1:
        return ("%s: the site appears %d times, at %s, and has to appear once"
                % (where, len(found),
                   ", ".join("0x%x" % offset for offset in found)))
    already = occurrences(image, PATCHED)
    if already:
        return ("%s: the site is already patched, at %s; set "
                "`copyright_patch = false` while the routine is still assembly"
                % (where, ", ".join("0x%x" % offset for offset in already)))
    return "%s: the site is not in this build" % where
