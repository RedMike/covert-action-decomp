#!/usr/bin/env python3
"""What a build was made from, so validate.py only measures a file built from
src/ as it stands. Digests content, never mtimes; one digest per module plus
a roll-up."""

import hashlib
import json
import os
import sys
import threading

if __package__ in (None, ""):
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    __package__ = "build"

from lib import layout

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SRC_ROOT = layout.src_root(REPO_ROOT)
REBUILT_ROOT = os.path.join(REPO_ROOT, "rebuilt")

# The record sits inside the tree it is about: no rebuilt/, no claim.
HASH_NAME = "build.hash"

FORMAT = 1


class SourceHashError(Exception):
    pass


def hash_path(rebuilt_root=None):
    return os.path.join(rebuilt_root or REBUILT_ROOT, HASH_NAME)


def module_sources(directory):
    """The files a build of this module reads, ordered by upper-cased basename
    so the digest depends on neither the platform nor the subdirectory."""
    if not os.path.isdir(directory):
        return []
    return layout.build_inputs(directory)


def normalise(data):
    """Line endings out: a file may reach disk in either, and the toolchain
    emits the same binary either way."""
    return data.replace(b"\r\n", b"\n").replace(b"\r", b"\n")


def module_digest(directory):
    """One digest over a module's sources -- name, length and bytes of each, so
    a rename is a change and no two files collide with their concatenation."""
    digest = hashlib.sha256()
    for path in module_sources(directory):
        with open(path, "rb") as handle:
            data = normalise(handle.read())
        name = (layout.c_name(path) if path.upper().endswith(".C")
                else os.path.basename(path))
        digest.update(name.upper().encode("utf-8"))
        digest.update(b"\0")
        digest.update(str(len(data)).encode("ascii"))
        digest.update(b"\0")
        digest.update(data)
    return digest.hexdigest()


def modules(src_root=None):
    root = src_root or SRC_ROOT
    if not os.path.isdir(root):
        return []
    return layout.names(root)


def _module_directory(name, src_root=None):
    """Where a module sits, or a path that does not exist: a missing module
    digests as nothing."""
    root = src_root or SRC_ROOT
    return layout.directory_for(name, root) or os.path.join(root, name)


def rollup(digests):
    """One digest over the per-module map, for "is the whole tree current"."""
    combined = hashlib.sha256()
    for name in sorted(digests):
        combined.update(name.encode("utf-8"))
        combined.update(b"\0")
        combined.update(digests[name].encode("ascii"))
        combined.update(b"\0")
    return combined.hexdigest()


def read(path=None):
    """The recorded map, or None where there is no record: None means no build
    has completed into this tree, an empty map one that staged nothing."""
    path = path or hash_path()
    if not os.path.isfile(path):
        return None
    try:
        with open(path, "r", encoding="utf-8") as handle:
            document = json.load(handle)
    except (OSError, ValueError) as error:
        raise SourceHashError("%s is unreadable: %s" % (path, error))
    if not isinstance(document, dict) or "modules" not in document:
        raise SourceHashError("%s is not a build record" % path)
    if document.get("format") != FORMAT:
        raise SourceHashError(
            "%s was written in format %r and this is format %d -- rebuild"
            % (path, document.get("format"), FORMAT))
    return document["modules"]


def write(digests, path=None):
    path = path or hash_path()
    document = {"format": FORMAT, "tree": rollup(digests),
                "modules": dict(sorted(digests.items()))}
    directory = os.path.dirname(path)
    if not os.path.isdir(directory):
        raise SourceHashError(
            "no %s to record a build in -- a build with no module named "
            "makes it" % directory)
    with open(path, "w", encoding="utf-8", newline="\n") as handle:
        json.dump(document, handle, indent=2, sort_keys=True)
        handle.write("\n")
    return path


# Parallel builds read-modify-write one map, so the pair must not interleave.
_RECORD_LOCK = threading.Lock()


def record(name, src_root=None, path=None):
    """Note this module staged from its current source: one entry replaced
    under the lock, so a build of one claims nothing about the others."""
    digest = module_digest(_module_directory(name, src_root))
    with _RECORD_LOCK:
        try:
            digests = read(path) or {}
        except SourceHashError:
            digests = {}      # unreadable or stale format: start it again
        digests[name] = digest
        return write(digests, path)


def forget_module(name, path=None):
    """Drop one module's entry: what is staged for it is not a build of its
    source, as a build with a define is not, so validate.py must not measure
    it."""
    with _RECORD_LOCK:
        try:
            digests = read(path)
        except SourceHashError:
            return
        if not digests or name not in digests:
            return
        del digests[name]
        write(digests, path)


def status(name, src_root=None, path=None):
    """Whether `rebuilt/` holds a build of this module's current source, as
    (state, detail): 'current', 'stale', 'unbuilt' or 'no-record'."""
    try:
        recorded = read(path)
    except SourceHashError as error:
        return "no-record", str(error)
    if recorded is None:
        return "no-record", "no %s" % (path or hash_path())
    if name not in recorded:
        return "unbuilt", "no entry for %s" % name
    if recorded[name] != module_digest(_module_directory(name, src_root)):
        return "stale", "the source has changed since it was staged"
    return "current", recorded[name]
