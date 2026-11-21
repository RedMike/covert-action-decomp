/* PORTING.H -- macros for what differs between the DOS build and a host.
 *
 * Where a macro has two arms, the DOS one compiles to the shipped game's bytes
 * and the PORT_MODERN one says the same for a modern compiler and host.
 */
#ifndef PORTING_H
#define PORTING_H

/* The distance of a pointer or a call, which a portable build drops. */
#ifdef PORT_MODERN
#define FAR
#define NEAR
#else
#define FAR far
#define NEAR near
#endif

/* A structure laid out byte for byte as the shipped game lays it out: MSC 5.1
 * packs a structure as it comes, where a modern compiler would pad it.
 */
#ifdef PORT_MODERN
#define PORT_PACKED __attribute__((packed))
#else
#define PORT_PACKED
#endif

/* A word and a double word, at the widths MSC 5.1 gives `int` and `long`: the
 * keyword on DOS and the host type of that width under PORT_MODERN. They fix
 * storage, not arithmetic, which the host still does in 32 bits.
 */
#ifdef PORT_MODERN
#define INT short
#define UNSIGNED_INT unsigned short
#define LONG int
#define UNSIGNED_LONG unsigned int
#else
#define INT int
#define UNSIGNED_INT unsigned int
#define LONG long
#define UNSIGNED_LONG unsigned long
#endif

/* A literal of LONG's width: the `L` suffix on DOS alone, where a host's would
 * be wider than LONG.
 */
#ifdef PORT_MODERN
#define LONG_LIT(n) (n)
#else
#define LONG_LIT(n) (n##L)
#endif

/* An address kept in an integer variable: an `int` on DOS and the host's
 * pointer-width integer otherwise, signed as the code compares it.
 */
#ifdef PORT_MODERN
#include <stdint.h>
#define POINTER intptr_t
#else
#define POINTER int
#endif

/* The address of a table element as a POINTER, the base added last as the
 * shipped code adds it.
 */
#define INT_INDEX_INTO(table, index, type) \
    ((index) * sizeof(type) + (POINTER) (table))

/* rt_addr and str_addr. */
#include "ADDRESS.H"
/* A char used as a subscript, signed as MSC 5.1's `char` is. */
#ifdef PORT_MODERN
#define CHAR_INDEX signed char
#else
#define CHAR_INDEX char
#endif
/* Num Lock, on and off. On DOS that is bit 5 of the BIOS keyboard-flag byte;
 * a host with no BIOS data area supplies the operation itself.
 */
#ifdef PORT_MODERN
/* Supplied by the host. */
void port_num_lock(INT on);
#define NUM_LOCK_ON() port_num_lock(1)
#define NUM_LOCK_OFF() port_num_lock(0)
#else
/* The BIOS keyboard-flag byte, whose bit 5 is Num Lock. */
#define BIOS_KEYBOARD_FLAGS \
    (*(char FAR *) (((unsigned long) 0x0040 << 16) | 0x0017))
#define NUM_LOCK_ON() (BIOS_KEYBOARD_FLAGS |= 0x20)
#define NUM_LOCK_OFF() (BIOS_KEYBOARD_FLAGS &= 0xdf)
#endif
/* Setting and reading a far pointer's parts: START is the segment, WITHIN the
 * offset and AT the whole address. Of the two full setters, SET_POINTER_START
 * writes the segment first and SET_POINTER_AT the offset.
 */
#ifdef PORT_MODERN
/* Supplied by the host. */
void *port_set_pointer(UNSIGNED_INT segment, UNSIGNED_INT offset);
void *port_set_pointer_within(void *fp, UNSIGNED_INT offset);
UNSIGNED_INT port_get_pointer_start(void *fp);
UNSIGNED_INT port_get_pointer_within(void *fp);
#define SET_POINTER_START(fp, segment) \
    ((fp) = port_set_pointer((segment), 0))
#define SET_POINTER_AT(fp, segment, offset) \
    ((fp) = port_set_pointer((segment), (offset)))
#define SET_POINTER_WITHIN(fp, offset) \
    ((fp) = port_set_pointer_within((fp), (offset)))
#define GET_POINTER_START(fp) port_get_pointer_start(fp)
#define GET_POINTER_AT(fp) (fp)
#define GET_POINTER_WITHIN(fp) port_get_pointer_within(fp)
#else
/* A far pointer is its offset in the low word and its segment in the high. */
#define SET_POINTER_START(fp, segment) \
    (*((unsigned int *) &(fp) + 1) = (segment), \
     *((unsigned int *) &(fp)) = 0)
#define SET_POINTER_AT(fp, segment, offset) \
    (*((unsigned int *) &(fp)) = (offset), \
     *((unsigned int *) &(fp) + 1) = (segment))
#define SET_POINTER_WITHIN(fp, offset) (*((unsigned int *) &(fp)) = (offset))
#define GET_POINTER_START(fp) (*((unsigned int *) &(fp) + 1))
#define GET_POINTER_AT(fp) (fp)
#define GET_POINTER_WITHIN(fp) (*((unsigned int *) &(fp)))
#endif

/* Copy `count` bytes from one far pointer to another: movedata on DOS, memmove
 * on a host.
 */
#ifdef PORT_MODERN
#define COPY_FAR(src, dst, count) \
    ((void) memmove((dst), (src), (count)))
#else
#define COPY_FAR(src, dst, count) \
    movedata(*((unsigned int *) &(src) + 1), *((unsigned int *) &(src)), \
             *((unsigned int *) &(dst) + 1), *((unsigned int *) &(dst)), \
             (count))
#endif

/* Copy `count` bytes to a far pointer from a segment and an offset held apart,
 * as a picture decoder reading from memory keeps them.
 */
#ifdef PORT_MODERN
#define COPY_FROM_SEGMENT(segment, offset, dst, count) \
    ((void) memmove((dst), \
                    (unsigned char *) port_set_pointer((segment), (offset)), \
                    (count)))
#else
#define COPY_FROM_SEGMENT(segment, offset, dst, count) \
    movedata((segment), (offset), \
             *((unsigned int *) &(dst) + 1), *((unsigned int *) &(dst)), \
             (count))
#endif

/* Arguments a call site leaves off: the shipped code pushes nothing for them,
 * and a modern compiler is given them. The suffix is how many, one to eight;
 * unsuffixed is one.
 */
#ifdef PORT_MODERN
#define UNSET_ARGS(a) a
#define UNSET_ARGS2(a, b) a, b
#define UNSET_ARGS3(a, b, c) a, b, c
#define UNSET_ARGS4(a, b, c, d) a, b, c, d
#define UNSET_ARGS5(a, b, c, d, e) a, b, c, d, e
#define UNSET_ARGS6(a, b, c, d, e, f) a, b, c, d, e, f
#define UNSET_ARGS7(a, b, c, d, e, f, g) a, b, c, d, e, f, g
#define UNSET_ARGS8(a, b, c, d, e, f, g, h) a, b, c, d, e, f, g, h
#else
#define UNSET_ARGS(a)
#define UNSET_ARGS2(a, b)
#define UNSET_ARGS3(a, b, c)
#define UNSET_ARGS4(a, b, c, d)
#define UNSET_ARGS5(a, b, c, d, e)
#define UNSET_ARGS6(a, b, c, d, e, f)
#define UNSET_ARGS7(a, b, c, d, e, f, g)
#define UNSET_ARGS8(a, b, c, d, e, f, g, h)
#endif

/* Parameters a definition leaves off, for a routine that never reads them and
 * has no BP frame: `void` on DOS and the list on a modern host. The suffix
 * counts as for UNSET_ARGS.
 */
#ifdef PORT_MODERN
#define UNSET_PARAMS(a) a
#define UNSET_PARAMS2(a, b) a, b
#define UNSET_PARAMS3(a, b, c) a, b, c
#define UNSET_PARAMS4(a, b, c, d) a, b, c, d
#define UNSET_PARAMS5(a, b, c, d, e) a, b, c, d, e
#define UNSET_PARAMS6(a, b, c, d, e, f) a, b, c, d, e, f
#define UNSET_PARAMS7(a, b, c, d, e, f, g) a, b, c, d, e, f, g
#define UNSET_PARAMS8(a, b, c, d, e, f, g, h) a, b, c, d, e, f, g, h
#else
#define UNSET_PARAMS(a) void
#define UNSET_PARAMS2(a, b) void
#define UNSET_PARAMS3(a, b, c) void
#define UNSET_PARAMS4(a, b, c, d) void
#define UNSET_PARAMS5(a, b, c, d, e) void
#define UNSET_PARAMS6(a, b, c, d, e, f) void
#define UNSET_PARAMS7(a, b, c, d, e, f, g) void
#define UNSET_PARAMS8(a, b, c, d, e, f, g, h) void
#endif

/* Parameters a declaration leaves unchecked, for a routine passed different
 * widths at different sites: an ellipsis on DOS and the list on a modern host.
 * The suffix counts as for UNSET_ARGS.
 */
#ifdef PORT_MODERN
#define UNCHECKED_PARAMS(a) a
#define UNCHECKED_PARAMS2(a, b) a, b
#define UNCHECKED_PARAMS3(a, b, c) a, b, c
#define UNCHECKED_PARAMS4(a, b, c, d) a, b, c, d
#define UNCHECKED_PARAMS5(a, b, c, d, e) a, b, c, d, e
#define UNCHECKED_PARAMS6(a, b, c, d, e, f) a, b, c, d, e, f
#define UNCHECKED_PARAMS7(a, b, c, d, e, f, g) a, b, c, d, e, f, g
#define UNCHECKED_PARAMS8(a, b, c, d, e, f, g, h) a, b, c, d, e, f, g, h
#else
#define UNCHECKED_PARAMS(a) ...
#define UNCHECKED_PARAMS2(a, b) ...
#define UNCHECKED_PARAMS3(a, b, c) ...
#define UNCHECKED_PARAMS4(a, b, c, d) ...
#define UNCHECKED_PARAMS5(a, b, c, d, e) ...
#define UNCHECKED_PARAMS6(a, b, c, d, e, f) ...
#define UNCHECKED_PARAMS7(a, b, c, d, e, f, g) ...
#define UNCHECKED_PARAMS8(a, b, c, d, e, f, g, h) ...
#endif

/* The copyright check's answer, as the shipped game gives it: "correct" for
 * any face, the branch on the compare being NOPed out. The DOS build patches
 * that in after the link; the portable arm evaluates the compare and says 1.
 */
#ifdef PORT_MODERN
#define COPYRIGHT_ANSWER(compare) ((void) (compare), 1)
#else
#define COPYRIGHT_ANSWER(compare) (compare)
#endif

/* A software interrupt, with a register block in and one out: int86 on DOS,
 * and supplied by the host otherwise.
 */
#ifdef PORT_MODERN
/* Supplied by the host. */
INT port_int86(INT number, rt_addr in, rt_addr out);
#define INTERRUPT(number, in, out) \
    port_int86((number), (rt_addr) (in), (rt_addr) (out))
#else
#define INTERRUPT(number, in, out) \
    int86((number), (rt_addr) (in), (rt_addr) (out))
#endif

/* Spawning the next module, by path and by searching PATH, which a host
 * supplies itself. Not variadic, unlike the library's: each takes a fixed
 * argument count and adds the terminating nulls.
 */
#ifdef PORT_MODERN
/* Supplied by the host. */
INT port_spawnl(INT mode, str_addr path, str_addr arg0);
INT port_spawnlp(INT mode, str_addr file, str_addr arg0,
                 str_addr arg1, str_addr arg2);
#define SPAWN_PROCESS(mode, path, arg0) \
    port_spawnl((mode), (str_addr) (path), (str_addr) (arg0))
#define SPAWN_PROCESS_ON_PATH(mode, file, arg0, arg1, arg2) \
    port_spawnlp((mode), (str_addr) (file), (str_addr) (arg0), \
                 (str_addr) (arg1), (str_addr) (arg2))
#else
#define SPAWN_PROCESS(mode, path, arg0) \
    spawnl((mode), (str_addr) (path), (str_addr) (arg0), 0, 0)
#define SPAWN_PROCESS_ON_PATH(mode, file, arg0, arg1, arg2) \
    spawnlp((mode), (str_addr) (file), (str_addr) (arg0), (str_addr) (arg1), \
            (str_addr) (arg2), 0, 0)
#endif

/* Asking the setup questions: graphics driver, sound driver, joystick. On DOS
 * that is spawning INTRO, which writes the answers into the shared block; a
 * host fills them in itself.
 */
#ifdef PORT_MODERN
/* Supplied by the host. */
void port_setup(void);
#define SETUP_QUESTIONS(mode, path, arg0) port_setup()
#else
#define SETUP_QUESTIONS(mode, path, arg0) SPAWN_PROCESS((mode), (path), (arg0))
#endif

/* A file the caller assumes is there: the shipped game never checks the open,
 * and the portable arm stops loudly.
 */
#ifdef PORT_MODERN
void port_assert_fd_success(INT fd, str_addr name);
#define ASSERT_FD_SUCCESS(fd, name) port_assert_fd_success((fd), (str_addr) (name))
#else
#define ASSERT_FD_SUCCESS(fd, name) ((void) 0)
#endif

/* A text read that matched nothing and so did not move: the caller loops until
 * EOF or a tag, so the portable arm stops loudly rather than spin for good.
 */
#ifdef PORT_MODERN
void port_assert_scan_progress(INT scanned, str_addr name, str_addr key);
#define ASSERT_SCAN_PROGRESS(scanned, name, key) \
    port_assert_scan_progress((scanned), (str_addr) (name), (str_addr) (key))
#else
#define ASSERT_SCAN_PROGRESS(scanned, name, key) ((void) 0)
#endif

/* A suspect index of -1 that got past a test on its record, which on DOS is
 * the bytes before the table and never passes: the portable arm stops loudly.
 */
#ifdef PORT_MODERN
void port_assert_suspect_index(INT index);
#define ASSERT_SUSPECT_INDEX(index) port_assert_suspect_index(index)
#else
#define ASSERT_SUSPECT_INDEX(index) ((void) 0)
#endif

/* strcpy of a string shifted left over its own front, which MSC 5.1's strcpy
 * survives and a host's need not: the portable arm uses memmove.
 */
#ifdef PORT_MODERN
#define OVERLAPPING_STRCPY(dest, source) \
    ((void) memmove((dest), (source), strlen((const char *) (source)) + 1))
#else
#define OVERLAPPING_STRCPY(dest, source) ((void) strcpy((dest), (source)))
#endif

/* A line to the console for a debugging session, never fatal and empty on DOS:
 * `message` is a printf format and the suffix is how many arguments, zero to
 * four. DEBUG_* and TRACE_* are the same, under PORT_DEBUG and PORT_TRACE.
 */
#ifdef PORT_MODERN
void port_log_message(const char *message, ...);
#define LOG_MESSAGE(message) port_log_message((message))
#define LOG_MESSAGE1(message, arg1) port_log_message((message), (arg1))
#define LOG_MESSAGE2(message, arg1, arg2) \
    port_log_message((message), (arg1), (arg2))
#define LOG_MESSAGE3(message, arg1, arg2, arg3) \
    port_log_message((message), (arg1), (arg2), (arg3))
#define LOG_MESSAGE4(message, arg1, arg2, arg3, arg4) \
    port_log_message((message), (arg1), (arg2), (arg3), (arg4))

#if PORT_DEBUG
void port_debug_message(const char *message, ...);
#define DEBUG_MESSAGE(message) port_debug_message((message))
#define DEBUG_MESSAGE1(message, arg1) port_debug_message((message), (arg1))
#define DEBUG_MESSAGE2(message, arg1, arg2) \
    port_debug_message((message), (arg1), (arg2))
#define DEBUG_MESSAGE3(message, arg1, arg2, arg3) \
    port_debug_message((message), (arg1), (arg2), (arg3))
#define DEBUG_MESSAGE4(message, arg1, arg2, arg3, arg4) \
    port_debug_message((message), (arg1), (arg2), (arg3), (arg4))
#else
#define DEBUG_MESSAGE(message) ((void) 0)
#define DEBUG_MESSAGE1(message, arg1) ((void) 0)
#define DEBUG_MESSAGE2(message, arg1, arg2) ((void) 0)
#define DEBUG_MESSAGE3(message, arg1, arg2, arg3) ((void) 0)
#define DEBUG_MESSAGE4(message, arg1, arg2, arg3, arg4) ((void) 0)
#endif

#if PORT_TRACE
void port_trace_message(const char *message, ...);
#define TRACE_MESSAGE(message) port_trace_message((message))
#define TRACE_MESSAGE1(message, arg1) port_trace_message((message), (arg1))
#define TRACE_MESSAGE2(message, arg1, arg2) \
    port_trace_message((message), (arg1), (arg2))
#define TRACE_MESSAGE3(message, arg1, arg2, arg3) \
    port_trace_message((message), (arg1), (arg2), (arg3))
#define TRACE_MESSAGE4(message, arg1, arg2, arg3, arg4) \
    port_trace_message((message), (arg1), (arg2), (arg3), (arg4))
#else
#define TRACE_MESSAGE(message) ((void) 0)
#define TRACE_MESSAGE1(message, arg1) ((void) 0)
#define TRACE_MESSAGE2(message, arg1, arg2) ((void) 0)
#define TRACE_MESSAGE3(message, arg1, arg2, arg3) ((void) 0)
#define TRACE_MESSAGE4(message, arg1, arg2, arg3, arg4) ((void) 0)
#endif

#else
#define LOG_MESSAGE(message) ((void) 0)
#define LOG_MESSAGE1(message, arg1) ((void) 0)
#define LOG_MESSAGE2(message, arg1, arg2) ((void) 0)
#define LOG_MESSAGE3(message, arg1, arg2, arg3) ((void) 0)
#define LOG_MESSAGE4(message, arg1, arg2, arg3, arg4) ((void) 0)
#define DEBUG_MESSAGE(message) ((void) 0)
#define DEBUG_MESSAGE1(message, arg1) ((void) 0)
#define DEBUG_MESSAGE2(message, arg1, arg2) ((void) 0)
#define DEBUG_MESSAGE3(message, arg1, arg2, arg3) ((void) 0)
#define DEBUG_MESSAGE4(message, arg1, arg2, arg3, arg4) ((void) 0)
#define TRACE_MESSAGE(message) ((void) 0)
#define TRACE_MESSAGE1(message, arg1) ((void) 0)
#define TRACE_MESSAGE2(message, arg1, arg2) ((void) 0)
#define TRACE_MESSAGE3(message, arg1, arg2, arg3) ((void) 0)
#define TRACE_MESSAGE4(message, arg1, arg2, arg3, arg4) ((void) 0)
#endif

#endif
