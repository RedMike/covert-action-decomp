/* LOGKINDS.H -- names for LOG_ENTRY's `kind`: what a case-log record is about.
 * 2 and 3 are never written.
 *
 * `kind` stays an INT and the names an anonymous enum, an enum type being two
 * bytes under MSC 5.1 and four on a modern compiler.
 */
#ifndef LOGKINDS_H
#define LOGKINDS_H

enum {
    LOG_MESSAGE = 0x0,      /* a message intercepted between two people */
    LOG_DEPARTED = 0x1,     /* a suspect left a city; only dead code logs it */
    LOG_TRAVEL = 0x4,       /* the player flew somewhere */
    LOG_BREAK_IN = 0x5,     /* the player broke into a building */
    LOG_ARRESTED = 0x6,     /* a suspect arrested and interrogated */
    LOG_OBJECT_REMOVED = 0x7, /* a found crime object taken out of play */
    LOG_HIDING = 0x8,       /* a suspect has gone into hiding */
    LOG_AT_LARGE = 0x9,     /* a suspect is back in circulation */
    LOG_ESCAPED = 0xa,      /* a prisoner is out of custody */
    LOG_BULLETIN = 0xb,     /* an INTERPOL bulletin: a suspect spotted */
    LOG_TURNED = 0xc,       /* a suspect arrested and turned double agent */
    LOG_EXCHANGED = 0xd     /* a prisoner exchanged */
};

/* The name of a kind, for a debugging line to print beside the number. Only
 * the portable build has a console, so LOG_KIND_NAME is empty on DOS.
 */
#ifdef PORT_MODERN
static const char *port_log_kind_name(INT kind) __attribute__((unused));

static const char *port_log_kind_name(INT kind)
{
    if (kind == LOG_MESSAGE)
        return "LOG_MESSAGE";
    if (kind == LOG_DEPARTED)
        return "LOG_DEPARTED";
    if (kind == LOG_TRAVEL)
        return "LOG_TRAVEL";
    if (kind == LOG_BREAK_IN)
        return "LOG_BREAK_IN";
    if (kind == LOG_ARRESTED)
        return "LOG_ARRESTED";
    if (kind == LOG_OBJECT_REMOVED)
        return "LOG_OBJECT_REMOVED";
    if (kind == LOG_HIDING)
        return "LOG_HIDING";
    if (kind == LOG_AT_LARGE)
        return "LOG_AT_LARGE";
    if (kind == LOG_ESCAPED)
        return "LOG_ESCAPED";
    if (kind == LOG_BULLETIN)
        return "LOG_BULLETIN";
    if (kind == LOG_TURNED)
        return "LOG_TURNED";
    if (kind == LOG_EXCHANGED)
        return "LOG_EXCHANGED";
    return "?";
}

#define LOG_KIND_NAME(kind) port_log_kind_name((kind))
#else
#define LOG_KIND_NAME(kind) ""
#endif

#endif /* LOGKINDS_H */
