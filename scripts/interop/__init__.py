"""Raw access to what the build scripts drive and read: DOSBox, the DOS build
tools, the EXEPACK model, and one reader each for the assembly and the C.
Ordering and policy belong to the callers, and the readers never modify what
they read."""

__all__ = ["assembly", "buildtools", "csource", "dosbox", "exepack"]
