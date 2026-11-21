#!/usr/bin/env python3
"""Validate the rebuilt binaries against the shipped ones: the load image
byte for byte, the MZ header field by field, the relocation set and the
packed declaration, rebuilt/ against decompressed/ and only for a module
staged from the source as it stands.
"""

import argparse
import os
import struct
import sys

if __package__ in (None, ""):
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    __package__ = "build"

from lib import layout
from lib import manifest as manifest_lib
from interop import exepack
from shared import logging as shared_logging
from shared.metrics import Metrics, step

from . import sourcehash

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SRC_ROOT = layout.src_root(REPO_ROOT)
REBUILT_ROOT = os.path.join(REPO_ROOT, "rebuilt")
DECOMPRESSED_ROOT = os.path.join(REPO_ROOT, "decompressed")

ERROR = "ERROR"

# MZ header fields with their offsets, in the order the header has them.
HEADER_FIELDS = [
    ("lastsize", 0x02), ("nblocks", 0x04), ("nreloc", 0x06),
    ("hdrsize", 0x08), ("minalloc", 0x0A), ("maxalloc", 0x0C),
    ("ss", 0x0E), ("sp", 0x10), ("cksum", 0x12), ("ip", 0x14),
    ("cs", 0x16), ("relocoff", 0x18), ("noverlay", 0x1A),
]

# Outside the check, not tolerated; all else fails.
IGNORED_FIELDS = {"minalloc", "cksum"}


class ValidationError(Exception):
    pass


class Finding:
    """One thing that is wrong or different, with a code and a place."""

    __slots__ = ("code", "severity", "message", "path", "offset")

    def __init__(self, code, severity, message, path=None, offset=None):
        self.code = code
        self.severity = severity
        self.message = message
        self.path = path
        self.offset = offset

    @property
    def where(self):
        parts = []
        if self.path:
            parts.append(_relative(self.path))
        if self.offset is not None:
            parts.append("0x%04x" % self.offset)
        return " ".join(parts)

    def __str__(self):
        place = self.where
        return "%s %s%s: %s" % (self.code, self.severity,
                                " at %s" % place if place else "",
                                self.message)


def _relative(path):
    try:
        return os.path.relpath(path, REPO_ROOT).replace(os.sep, "/")
    except ValueError:
        return path


class Report:
    def __init__(self, module):
        self.module = module
        self.findings = []
        self.notes = []

    def add(self, *args, **kwargs):
        self.findings.append(Finding(*args, **kwargs))

    def note(self, text):
        self.notes.append(text)

    @property
    def errors(self):
        return [f for f in self.findings if f.severity == ERROR]

    @property
    def ok(self):
        return not self.errors


# ---------------------------------------------------------------------------
# Reading an MZ file.
# ---------------------------------------------------------------------------


class Executable:
    """An MZ file, split into the parts that get compared separately."""

    def __init__(self, data, path):
        self.path = path
        self.data = data
        if len(data) < 0x1C or data[:2] not in (b"MZ", b"ZM"):
            raise ValidationError("not an MZ executable: %s" % _relative(path))
        self.header = dict(zip([n for n, _ in HEADER_FIELDS],
                               struct.unpack_from("<13H", data, 2)))
        self.header_bytes = self.header["hdrsize"] * 16
        last = self.header["lastsize"]
        self.image_end = ((self.header["nblocks"] - 1) * 512
                          + (last if last else 512))
        if self.image_end > len(data):
            raise ValidationError(
                "%s: the header claims %d bytes and the file holds %d"
                % (_relative(path), self.image_end, len(data)))

    @property
    def image(self):
        """The load module: what DOS copies into memory, before fixups."""
        return self.data[self.header_bytes:self.image_end]

    @property
    def relocations(self):
        """Fixup sites as linear offsets into the image, normalised: LINK may
        name the same byte by a different frame paragraph than the original."""
        table = self.header["relocoff"]
        sites = []
        for index in range(self.header["nreloc"]):
            start = table + 4 * index
            if start + 4 > len(self.data):
                break
            offset, segment = struct.unpack_from("<HH", self.data, start)
            sites.append(segment * 16 + offset)
        return sites


def read(path):
    with open(path, "rb") as handle:
        return Executable(handle.read(), path)


# ---------------------------------------------------------------------------
# The checks.
# ---------------------------------------------------------------------------


def check_declaration(module, declared, report):
    """Does the manifest's `packed` hold of the file that shipped? The subject
    is the retail file in `original/`, never our build output."""
    shipped = os.path.join(REPO_ROOT, "original", module.target)
    if not os.path.isfile(shipped):
        report.note("packing: cannot check the declaration -- no %s"
                    % _relative(shipped))
        return
    with open(shipped, "rb") as handle:
        actual = exepack.is_exepack(handle.read())
    if declared and not actual:
        report.add("V100", ERROR,
                   "the manifest says `packed = true` and the shipped file is "
                   "not EXEPACK'd.", shipped)
    elif not declared and actual:
        report.add("V101", ERROR,
                   "the manifest says `packed = false` and the shipped file "
                   "is EXEPACK'd. decompressed/ would then hold the unpacked "
                   "form of something we think was never packed.", shipped)
    else:
        report.note("packing: the shipped file is %s, as declared"
                    % ("EXEPACK'd" if actual else "not packed"))


def check_currency(module, report):
    """Does `rebuilt/` hold a build of this module's source as it stands? A
    missing record means no build completed into this tree, which is a finding."""
    state, detail = sourcehash.status(module.name)
    if state == "current":
        report.note("currency: staged from the source as it stands")
        return True
    if state == "no-record":
        report.add("V004", ERROR,
                   "there is no record of a build in rebuilt/ (%s), so "
                   "nothing says the file being measured came from src/. Run "
                   "scripts/build/build.py %s." % (detail, module.name))
    elif state == "unbuilt":
        report.add("V004", ERROR,
                   "rebuilt/ has no record of %s being staged, so the file "
                   "there is the shipped one this is supposed to be compared "
                   "against, or a build with a define. Run "
                   "scripts/build/build.py %s."
                   % (module.name, module.name))
    else:
        report.add("V004", ERROR,
                   "%s has changed since rebuilt/ was staged from it, so the "
                   "file being measured is a build of source that no longer "
                   "exists. Re-run scripts/build/build.py %s."
                   % (_relative(module.directory), module.name))
    return False


def check_artefact(built, report):
    """The staged file is never packed, and this says so if it is: rebuilt/
    holds link output, so a packed file there came from somewhere else."""
    if exepack.is_exepack(built.data):
        report.add("V111", ERROR,
                   "the staged file is EXEPACK'd. rebuilt/ holds link output, "
                   "which never is -- packing is a separate final step and is "
                   "not what this compares.", built.path)
        return True
    return False


def check_image(ours, theirs, report, limit=16):
    """The load image, byte for byte."""
    a, b = ours.image, theirs.image

    if len(a) != len(b):
        report.add("V200", ERROR,
                   "the load image is %d bytes and the original is %d "
                   "(%+d)" % (len(a), len(b), len(a) - len(b)),
                   ours.path)

    differing = [i for i in range(min(len(a), len(b))) if a[i] != b[i]]
    for offset in differing[:limit]:
        report.add("V201", ERROR,
                   "load image differs: original %02x, ours %02x"
                   % (b[offset], a[offset]),
                   ours.path, offset)
    if len(differing) > limit:
        report.add("V201", ERROR,
                   "... and %d more differing byte(s) in the load image"
                   % (len(differing) - limit), ours.path)

    if not differing and len(a) == len(b):
        report.note("load image: BYTE-IDENTICAL (%d bytes)" % len(a))
    return not differing and len(a) == len(b)


def check_header(ours, theirs, report):
    """Every MZ header field, named, with both values."""
    offsets = dict(HEADER_FIELDS)
    checked = [name for name, _ in HEADER_FIELDS if name not in IGNORED_FIELDS]
    differing = []
    for name in checked:
        mine, theirs_value = ours.header[name], theirs.header[name]
        if mine == theirs_value:
            continue
        differing.append(name)
        report.add("V300", ERROR,
                   "header field %s: original %04x, ours %04x"
                   % (name, theirs_value, mine),
                   ours.path, offsets[name])
    if not differing:
        report.note("header: %d field(s) match (%s not compared)"
                    % (len(checked), ", ".join(sorted(IGNORED_FIELDS))))
    return differing


def check_relocations(ours, theirs, report):
    """The fixup sites as a set, which is a real defect when it differs, and as
    a sequence, which is LINK's bookkeeping and changes nothing at run time."""
    mine, original = ours.relocations, theirs.relocations

    if len(mine) != len(original):
        report.add("V310", ERROR,
                   "%d relocation(s) against the original's %d"
                   % (len(mine), len(original)), ours.path)

    missing = sorted(set(original) - set(mine))
    extra = sorted(set(mine) - set(original))
    for site in missing[:8]:
        report.add("V311", ERROR,
                   "the original fixes up image 0x%04x and we do not -- the "
                   "loader will leave a segment word at its pre-relocation "
                   "value" % site, ours.path, site)
    for site in extra[:8]:
        report.add("V311", ERROR,
                   "we fix up image 0x%04x and the original does not -- the "
                   "loader will corrupt a word that is not a segment"
                   % site, ours.path, site)

    if not missing and not extra:
        report.note("relocations: %d, same sites (order not compared)"
                    % len(mine))


# ---------------------------------------------------------------------------
# Driver.
# ---------------------------------------------------------------------------


def module_source(name):
    return "validate.%s" % name


def validate(module_name, packed=None, limit=16):
    metrics = Metrics()
    module = manifest_lib.open_module(module_name)
    log = shared_logging.get_logger(module_source(module.name))
    log.info("Validating module", module=module.name)
    report = Report(module.name)
    try:
        return _validated(module, report, log, metrics, packed, limit)
    finally:
        for line in report.notes:
            log.debug(line)
        for finding in report.findings:
            log.error(str(finding))
        at = log.info if report.ok else log.error
        at("Validated module", module=module.name, success=report.ok,
           errors=len(report.errors), duration_ms=metrics.total_ms)


def _validated(module, report, log, metrics, packed, limit):
    if not module.target:
        report.add("V002", ERROR,
                   "the manifest names no `target`, so there is nothing to "
                   "compare against.", module.path)
        return report

    reference_path = os.path.join(DECOMPRESSED_ROOT, module.target)
    if not os.path.isfile(reference_path):
        report.add("V002", ERROR,
                   "no reference at %s -- run "
                   "scripts/setup/build_decompressed.py"
                   % _relative(reference_path))
        return report

    built_path = os.path.join(REBUILT_ROOT, module.target)
    if not os.path.isfile(built_path):
        report.add("V001", ERROR,
                   "nothing at %s -- rebuilt/ is made and staged into by "
                   "scripts/build/build.py %s"
                   % (_relative(built_path), module.name))
        return report

    # Everything after this is a claim about a build of the current source.
    with step(log, metrics, "currency"):
        current = check_currency(module, report)
    if not current:
        return report

    with step(log, metrics, "read"):
        try:
            built = read(built_path)
            reference = read(reference_path)
        except ValidationError as error:
            report.add("V003", ERROR, str(error))
            return report

    # Two questions: whether the shipped file is packed, and whether ours is.
    declared = module.packed if packed is None else packed
    with step(log, metrics, "declaration"):
        check_declaration(module, declared, report)
        packed_here = check_artefact(built, report)
    if packed_here:
        return report

    with step(log, metrics, "image"):
        check_image(built, reference, report, limit)
    with step(log, metrics, "header"):
        check_header(built, reference, report)
    with step(log, metrics, "relocations"):
        check_relocations(built, reference, report)
    return report


def modules():
    return layout.names(SRC_ROOT)


def main(argv=None):
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("module", nargs="*",
                        help="module names (default: every module)")
    group = parser.add_mutually_exclusive_group()
    group.add_argument("--packed", dest="packed", action="store_true",
                       default=None,
                       help="assert the built file is EXEPACK'd, overriding "
                            "the manifest")
    group.add_argument("--unpacked", dest="packed", action="store_false",
                       help="assert it is not")
    parser.add_argument("--limit", type=int, default=16,
                        help="how many differing bytes to itemise")
    shared_logging.add_arguments(parser)
    args = parser.parse_args(argv)
    shared_logging.configure(args, "validate")
    log = shared_logging.get_logger("main")

    wanted = args.module or modules()
    metrics = Metrics()
    failed = 0
    log.info("Validating modules", count=len(wanted))

    with metrics.stage("modules"):
        for name in wanted:
            try:
                report = validate(name, packed=args.packed, limit=args.limit)
            except manifest_lib.ManifestError as error:
                log.error("Cannot open the manifest", module=name,
                          exc_info=error)
                failed += 1
                continue

            if not report.ok:
                failed += 1

    at = log.error if failed else log.info
    shared_logging.always(at, "Finished validating modules",
                          validated=len(wanted) - failed, failed=failed,
                          duration_ms=metrics.total_ms)
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
