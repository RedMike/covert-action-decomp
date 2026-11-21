#!/usr/bin/env python3
"""Sync each module's copy of a shared body from src/shared/c/, never back:
a chunk is the text between a shared_include_start and shared_include_end
marker. The default reports every chunk that differs from its file; --replace
rewrites every chunk from it."""

import argparse
import os
import re
import sys

if __package__ in (None, ""):
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    __package__ = "build"

from lib import layout

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SRC_ROOT = layout.src_root(REPO_ROOT)

START = re.compile(r"^/\* shared_include_start: (\S+)(?: .*)? \*/[ \t]*$")
END = re.compile(r"^/\* shared_include_end: (\S+) \*/[ \t]*$")


class ChunkError(Exception):

    def __init__(self, message, line):
        super().__init__(message)
        self.line = line


class Chunk:
    """One marker pair: the path as written, the file it resolves to, the
    start marker's line, and the body's offsets in the host text."""

    __slots__ = ("marker", "target", "line", "body_start", "body_end")

    def __init__(self, marker, target, line, body_start, body_end):
        self.marker = marker
        self.target = target
        self.line = line
        self.body_start = body_start
        self.body_end = body_end


def normalise(text):
    return text.replace("\r\n", "\n")


def parse(text, path):
    """The chunks of a source in order; ChunkError on an unpaired marker."""
    directory = os.path.dirname(os.path.abspath(path))
    chunks = []
    opened = None
    offset = 0
    for number, line in enumerate(text.splitlines(True), 1):
        bare = line.rstrip("\r\n")
        start, end = START.match(bare), END.match(bare)
        if start:
            if opened:
                raise ChunkError("shared_include_start for %s inside the chunk "
                                 "for %s" % (start.group(1), opened[0]), number)
            opened = (start.group(1), number, offset + len(line))
        elif end:
            if not opened or opened[0] != end.group(1):
                raise ChunkError("shared_include_end for %s has no matching "
                                 "start" % end.group(1), number)
            target = os.path.normpath(os.path.join(directory, opened[0]))
            chunks.append(Chunk(opened[0], target, opened[1], opened[2], offset))
            opened = None
        offset += len(line)
    if opened:
        raise ChunkError("shared_include_start for %s has no shared_include_end"
                         % opened[0], opened[1])
    return chunks


def expected(chunk):
    """The shared file's text as a chunk holds it, line endings aside."""
    with open(chunk.target, "r", encoding="utf-8", newline="") as handle:
        text = normalise(handle.read())
    return text if not text or text.endswith("\n") else text + "\n"


def findings(path):
    """(kind, line, message) for each broken chunk in a source: kind is
    `unpaired`, `unresolved` or `diverged`."""
    with open(path, "r", encoding="utf-8", newline="") as handle:
        text = handle.read()
    try:
        chunks = parse(text, path)
    except ChunkError as error:
        return [("unpaired", error.line, str(error))]
    out = []
    for chunk in chunks:
        if not os.path.isfile(chunk.target):
            out.append(("unresolved", chunk.line,
                        "shared_include_start names %s, which is not on disk"
                        % chunk.marker))
        elif normalise(text[chunk.body_start:chunk.body_end]) != expected(chunk):
            out.append(("diverged", chunk.line,
                        "the chunk differs from %s; run "
                        "scripts/build/shared_sync.py --replace" % chunk.marker))
    return out


def replaced(text, path):
    """The source with every chunk rewritten from its file, all of it in LF.
    Raises ChunkError where a chunk cannot be rewritten."""
    text = normalise(text)
    for chunk in reversed(parse(text, path)):
        if not os.path.isfile(chunk.target):
            raise ChunkError("%s is not on disk" % chunk.marker, chunk.line)
        text = text[:chunk.body_start] + expected(chunk) + text[chunk.body_end:]
    return text


def sources(src_root, wanted=()):
    """(module, path) for every .C a module keeps under c/ and its parts."""
    for name, directory in sorted(layout.modules(src_root).items()):
        if wanted and name not in wanted:
            continue
        for path in layout.c_files(directory):
            yield name, path


def run(src_root, wanted=(), replace=False, out=sys.stdout):
    """Report or rewrite every chunk; the count of problems left."""
    problems = 0
    for module, path in sources(src_root, wanted):
        where = "%s %s" % (module, os.path.relpath(path, src_root).replace(os.sep, "/"))
        found = findings(path)
        diverged = [f for f in found if f[0] == "diverged"]
        broken = [f for f in found if f[0] != "diverged"]
        for _, line, message in broken + ([] if replace else diverged):
            print("%s:%d: %s" % (where, line, message), file=out)
            problems += 1
        if not replace or not diverged or broken:
            continue
        with open(path, "r", encoding="utf-8", newline="") as handle:
            text = handle.read()
        with open(path, "w", encoding="utf-8", newline="\n") as handle:
            handle.write(replaced(text, path))
        print("%s: rewrote %d chunk(s)" % (where, len(diverged)), file=out)
    return problems


def main(argv=None):
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("module", nargs="*",
                        help="module name (default: every module)")
    parser.add_argument("--replace", action="store_true",
                        help="rewrite every chunk from its shared file")
    args = parser.parse_args(argv)
    return 1 if run(SRC_ROOT, args.module, args.replace) else 0


if __name__ == "__main__":
    sys.exit(main())
