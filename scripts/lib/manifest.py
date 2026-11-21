"""A module's manifest, `data/module.toml`, as the build reads it.

    name = "INTRO"
    output = "INTRO.EXE"
    target = "MPS/COVERT/INTRO.EXE"
    packed = false

    # Optional, default false: scripts/build/copyright_patch.py patches the
    # linked file.
    copyright_patch = false

    # Optional, default "small": the model a build with a define uses.
    mod_model = "medium"

    [link]
    flags = []
    libs = []
    load_libs = []

    # In link order, which fixes segment and routine layout.
    [[objects]]
    target = "INTRO.ASM"
    sources = ["INTRO.ASM"]
    tool = "masm"

    [porting]
    # Routines written in C, which the assembly declares EXTRN.
    externs = ["init_palette"]
    # Assembly symbols the C reaches, declared in the module's header.
    publics = ["frame_counter"]

    # Canonical identifier to the meaningful name the sources spell.
    [names]
    FUN_1000_044a = "draw_frame"
"""

import collections
import os
import tomllib

from . import layout

# One `[[objects]]` entry, resolved.
ObjectSpec = collections.namedtuple(
    "ObjectSpec", "target sources tool flags link")


class ManifestError(Exception):
    pass


class Names:
    """The rename map, read both ways: canonical identifier to the meaningful
    name the sources spell."""

    def __init__(self, mapping=None, module=None):
        self.module = module
        self._forward = dict(mapping or {})
        self._reverse = {}
        problems = []
        for canonical, meaningful in self._forward.items():
            if not isinstance(meaningful, str) or not meaningful:
                problems.append("%s maps to something that is not a name"
                                % canonical)
                continue
            # A name beginning with an underscore is the linker's own spelling,
            # as `_strcpy`, and is never renamed.
            if canonical.startswith("_"):
                problems.append(
                    "%s is a linker name -- the library's own spelling -- and "
                    "is not renamed: the assembly spells it as it is, and "
                    "the C spells it %r" % (canonical, canonical[1:]))
                continue
            if meaningful in self._reverse:
                problems.append(
                    "two canonical names both map to %r: %s and %s -- the map "
                    "has to be readable in both directions"
                    % (meaningful, self._reverse[meaningful], canonical))
                continue
            self._reverse[meaningful] = canonical
        if problems:
            where = " in %s" % module if module else ""
            raise ManifestError("bad [names] map%s:\n  %s"
                                % (where, "\n  ".join(problems)))

    def __len__(self):
        return len(self._forward)

    def __bool__(self):
        return bool(self._forward)

    def __contains__(self, canonical):
        return canonical in self._forward

    def meaningful(self, canonical):
        """The name the sources spell, or the canonical one if none was given."""
        return self._forward.get(canonical, canonical)

    def canonical(self, meaningful):
        """Back to the identifier the toolchain is given."""
        return self._reverse.get(meaningful, meaningful)

    def named(self):
        return dict(self._forward)


class Porting:
    """The two lists of `[porting]` a build reads: what crosses between the
    assembly and the C, and in which direction."""

    def __init__(self, config, module=None):
        self.module = module
        self.externs = tuple(config.get("externs", ()))
        self.publics = tuple(config.get("publics", ()))
        self._validate()

    def _validate(self):
        problems = []

        for attribute in ("externs", "publics"):
            seen = set()
            for name in getattr(self, attribute):
                if name in seen:
                    problems.append("duplicate %s entry: %s" % (attribute, name))
                seen.add(name)

        both = sorted(set(self.externs) & set(self.publics))
        for name in both:
            problems.append(
                "%s is in both externs and publics -- it is either defined in "
                "the assembly and exported, or defined in C and imported"
                % name)

        if problems:
            where = " in %s" % self.module if self.module else ""
            raise ManifestError(
                "bad [porting] config%s:\n  %s" % (where, "\n  ".join(problems)))


class Module:
    """A whole module.toml, resolved."""

    def __init__(self, path, document):
        self.path = os.path.abspath(path)
        # The manifest sits in `data/`, so the module is that directory's
        # parent.
        self.directory = os.path.dirname(os.path.dirname(self.path))
        self.name = document.get("name") or os.path.basename(self.directory)
        self.output = document.get("output", "%s.EXE" % self.name)
        self.target = document.get("target")
        self.packed = bool(document.get("packed", False))
        self.copyright_patch = bool(document.get("copyright_patch", False))
        self.mod_model = str(document.get("mod_model", "small"))
        if self.mod_model not in ("small", "medium"):
            raise ManifestError(
                "%s: mod_model is %r; it is \"small\" or \"medium\""
                % (self.name, self.mod_model))
        self.link = dict(document.get("link", {}))
        self.objects = list(document.get("objects", ()))
        self.names = Names(document.get("names"), module=self.name)
        self.porting = Porting(document.get("porting", {}), module=self.name)

    def source_path(self, extension):
        """The module's own `.ASM` or `.H`, at the directory's top."""
        return layout.generated_path(self.directory, self.name, extension)

    def resolve(self, filename):
        """A bare filename from the manifest, as a path under the module."""
        return layout.source_path(self.directory, self.name, filename)

    def headers(self):
        """Every `.H` the module keeps: its own first, then those in inc/."""
        return layout.header_files(self.directory, self.name)

    def object_sources(self):
        """One ObjectSpec per `[[objects]]` entry, in link order: a `target`,
        the file the tool compiles, and the `sources` joined to make it,
        which is how several files add back up to one translation unit.
        `link = false` compiles an object and leaves it out of the link."""
        out = []
        for entry in self.objects:
            target = entry.get("target")
            if not target:
                raise ManifestError(
                    "%s: an [[objects]] entry has no `target`. The target is "
                    "the file the build writes and hands to the tool, and it "
                    "is named rather than derived because it fixes the 8.3 "
                    "object name." % self.name)
            sources = entry.get("sources")
            if not sources:
                raise ManifestError(
                    "%s: [[objects]] entry for %s has no `sources`. Link "
                    "order is explicit data in the manifest and never a "
                    "wildcard, so an object with no parts is nothing to build."
                    % (self.name, target))
            if isinstance(sources, str):
                raise ManifestError(
                    "%s: `sources` for %s is a string. It is always a list, "
                    "so that one part and several read the same."
                    % (self.name, target))
            tool = entry.get("tool") or (
                "cl" if target.lower().endswith(".c") else "masm")
            out.append(ObjectSpec(
                target,
                [self.resolve(s) for s in sources],
                tool, list(entry.get("flags", ())),
                bool(entry.get("link", True))))
        return out

    def c_sources(self):
        """Every C file under `src/` the manifest compiles, in link order."""
        out = []
        for spec in self.object_sources():
            if spec.tool != "cl":
                continue
            out.extend(spec.sources)
        return out

    def __repr__(self):
        return "<module %s>" % self.name


def find(module, src_root=None):
    """Accept a module name, a module directory, or a manifest path."""
    for candidate in (module,
                      os.path.join(module, layout.DATA_DIR,
                                   layout.MANIFEST_NAME)):
        if os.path.isfile(candidate):
            return os.path.abspath(candidate)
    directory = layout.directory_for(module, src_root)
    if directory:
        return os.path.abspath(layout.manifest_path(directory))
    raise ManifestError("no module.toml found for %r" % module)


def read(path):
    if not os.path.isfile(path):
        raise ManifestError("no manifest at %s" % path)
    with open(path, "rb") as handle:
        try:
            return tomllib.load(handle)
        except tomllib.TOMLDecodeError as error:
            raise ManifestError("%s is not valid TOML: %s" % (path, error))


def open_module(module, src_root=None):
    """The usual entry point: name or path in, resolved Module out."""
    path = find(module, src_root)
    return Module(path, read(path))
