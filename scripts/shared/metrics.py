"""How long each stage of a piece of work took: nanoseconds inside,
milliseconds out, the total the sum of the stages."""

import contextlib
import time


class Metrics:
    __slots__ = ("stages",)

    def __init__(self):
        self.stages = {}

    @contextlib.contextmanager
    def stage(self, name):
        started = time.perf_counter_ns()
        try:
            yield
        finally:
            self.stages[name] = (self.stages.get(name, 0)
                                 + time.perf_counter_ns() - started)

    @property
    def total_ms(self):
        return sum(self.stages.values()) // 1000000

    def stage_ms(self, name):
        return self.stages.get(name, 0) // 1000000


@contextlib.contextmanager
def step(log, metrics, name, at=None):
    """One stage, logged before and after and timed, at DEBUG unless `at` says
    otherwise."""
    at = at or log.debug
    at("Doing %s.." % name)
    with metrics.stage(name):
        yield
    at("Done %s" % name, duration_ms=metrics.stage_ms(name))
