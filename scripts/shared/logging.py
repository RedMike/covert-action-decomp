import datetime
import importlib.util
import logging
import os
import sys

import structlog

CONSOLE_LEVEL_DEFAULT = "WARN"
FILE_LEVEL_DEFAULT = "DEBUG"

_LEVELS = {
    "DEBUG": logging.DEBUG,
    "INFO": logging.INFO,
    "WARN": logging.WARNING,
    "ERROR": logging.ERROR,
    "CRITICAL": logging.CRITICAL,
}

_LINE_FORMAT = "[%(asctime)s.%(msecs)03d][%(levelname)s][%(name)s] %(message)s"
_RESET = structlog.dev.RESET_ALL
_LEVEL_COLOURS = {
    "DEBUG": structlog.dev.DIM,
    "INFO": structlog.dev.GREEN,
    "WARNING": structlog.dev.YELLOW,
    "ERROR": structlog.dev.RED,
    "CRITICAL": structlog.dev.RED,
}
_TIMESTAMP_FORMAT = "%Y-%m-%d %H:%M:%S"
_FILENAME_FORMAT = "log_%s_%s.log"
_FILENAME_TIMESTAMP_FORMAT = "%Y-%m-%d_%H-%M-%S"


def add_arguments(parser):
    group = parser.add_argument_group("logging")
    group.add_argument("--log-to-file", action="store_true",
                       help="write the log to a file as well as the console")
    group.add_argument("--log-console-level", type=str.upper,
                       default=CONSOLE_LEVEL_DEFAULT, choices=sorted(_LEVELS),
                       metavar="LEVEL",
                       help="lowest level the console shows "
                            "(default: %(default)s)")
    group.add_argument("--log-file-level", type=str.upper,
                       default=FILE_LEVEL_DEFAULT, choices=sorted(_LEVELS),
                       metavar="LEVEL",
                       help="lowest level the file records "
                            "(default: %(default)s)")
    group.add_argument("--log-dir", default=None, metavar="DIR",
                       help="directory the log file is written to, with "
                            "--log-to-file (default: the working directory)")
    group.add_argument("--log-long-tracebacks", action="store_true",
                       help="log tracebacks with each frame's local variables "
                            "rather than the plain traceback")
    return group


def _exception_formatter(long_tracebacks):
    if long_tracebacks and importlib.util.find_spec("rich") is not None:
        return structlog.dev.rich_traceback
    return structlog.dev.plain_traceback


def _bind_structlog():
    structlog.configure(
        processors=[structlog.stdlib.ProcessorFormatter.wrap_for_formatter],
        logger_factory=structlog.stdlib.LoggerFactory(),
        wrapper_class=structlog.stdlib.BoundLogger,
        cache_logger_on_first_use=False,
    )


class _Coloured(structlog.stdlib.ProcessorFormatter):
    """The same line with the level and the source coloured."""

    def format(self, record):
        # A copy: the same record goes on to the file handler uncoloured.
        record = logging.makeLogRecord(record.__dict__)
        level = _LEVEL_COLOURS.get(record.levelname, "")
        record.levelname = "%s%s%s" % (level, record.levelname, _RESET)
        record.name = "%s%s%s" % (structlog.dev.CYAN, record.name, _RESET)
        return super().format(record)


def _formatter(long_tracebacks, colours):
    build = _Coloured if colours else structlog.stdlib.ProcessorFormatter
    return build(
        fmt=_LINE_FORMAT,
        datefmt=_TIMESTAMP_FORMAT,
        processors=[
            structlog.stdlib.ProcessorFormatter.remove_processors_meta,
            structlog.dev.ConsoleRenderer(
                colors=colours, pad_event_to=0, sort_keys=False,
                exception_formatter=_exception_formatter(long_tracebacks)),
        ],
    )


def log_path(script, directory=None, started=None):
    started = started or datetime.datetime.now()
    directory = directory or os.getcwd()
    name = _FILENAME_FORMAT % (
        script, started.strftime(_FILENAME_TIMESTAMP_FORMAT))
    return os.path.abspath(os.path.join(directory, name))


def configure(args, script, started=None):
    started = started or datetime.datetime.now()
    _bind_structlog()

    long = getattr(args, "log_long_tracebacks", False)
    root = logging.getLogger()
    for handler in list(root.handlers):
        root.removeHandler(handler)
        handler.close()
    root.setLevel(logging.DEBUG)

    console = logging.StreamHandler(sys.stderr)
    console.setLevel(_LEVELS[getattr(args, "log_console_level",
                                     CONSOLE_LEVEL_DEFAULT)])
    console.setFormatter(_formatter(long, colours=True))
    root.addHandler(console)

    path = None
    if getattr(args, "log_to_file", False):
        path = log_path(script, getattr(args, "log_dir", None), started)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        stream = logging.FileHandler(path, encoding="utf-8")
        stream.setLevel(_LEVELS[getattr(args, "log_file_level",
                                        FILE_LEVEL_DEFAULT)])
        stream.setFormatter(_formatter(long, colours=False))
        root.addHandler(stream)

    return path


def get_logger(source):
    return structlog.get_logger(source)


def always(method, event, **kwargs):
    """Call a bound log method (`log.info`, `log.error`, ...) with every
    handler's level restriction lifted, for the one summary line a run is
    judged by regardless of --log-console-level/--log-file-level."""
    root = logging.getLogger()
    saved = [(handler, handler.level) for handler in root.handlers]
    for handler, _ in saved:
        handler.setLevel(logging.NOTSET)
    try:
        method(event, **kwargs)
    finally:
        for handler, level in saved:
            handler.setLevel(level)


# Silent until a script configures it, the way a library is.
_bind_structlog()
logging.getLogger().addHandler(logging.NullHandler())
