/* RUNTIME.C -- the MSC 5.1 run-time the host's library lacks.
 *
 * DOS file calls on host descriptors, with names found in any case; the BIOS
 * clock, the ports, the console and segment memory; and string helpers glibc
 * lacks.
 */

/* Ask for the POSIX calls below before any header: -std=c89 hides them. */
#if !defined(_WIN32) && !defined(_DEFAULT_SOURCE)
#define _DEFAULT_SOURCE 1
#define _POSIX_C_SOURCE 200809L
#endif

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#else
#include <dirent.h>
#include <unistd.h>
#endif

#include "HOST.H"
#include "RUNTIME.H"

/* Undo RUNTIME.H's renames, so the host library's own can be called. */
#undef open
#undef fopen
#undef access
#undef close
#undef fclose

#ifndef O_BINARY
#define O_BINARY 0
#endif

/* MSC 5.1's open flags, which the game passes as numbers. */
#define MSC_WRONLY 0x0001
#define MSC_RDWR 0x0002
#define MSC_APPEND 0x0008
#define MSC_CREAT 0x0100
#define MSC_TRUNC 0x0200
#define MSC_EXCL 0x0400

/* ---- names ---------------------------------------------------------- */

static int exists(const char *path)
{
#ifdef _WIN32
    return _access(path, 0) == 0;
#else
    return access(path, F_OK) == 0;
#endif
}

/* A name as spelled where that exists, else the directory's entry matching it
 * in any case. A DOS drive in front names the game's own directory, and a
 * trailing space is dropped, as DOS dropped it. */
static const char *find_name(const char *name, char *buffer, size_t size)
{
    size_t len;
    if (!name)
        name = "";
    if (isalpha((unsigned char) name[0]) && name[1] == ':')
        name += 2;
    len = strlen(name);
    while (len > 0 && name[len - 1] == ' ')
        len--;
    if (len >= size)
        len = 0;
    memcpy(buffer, name, len);
    buffer[len] = 0;
#ifndef _WIN32
    if (!exists(buffer) && buffer[0]) {
        const char *slash = strrchr(buffer, '/');
        const char *base = slash ? slash + 1 : buffer;
        char directory[512];
        DIR *dir;
        struct dirent *entry;
        size_t head = (size_t) (base - buffer);
        if (head >= sizeof directory)
            return buffer;
        memcpy(directory, buffer, head);
        directory[head] = 0;
        dir = opendir(head ? directory : ".");
        if (!dir)
            return buffer;
        while ((entry = readdir(dir)) != 0) {
            if (strcasecmp(entry->d_name, base) == 0) {
                if (head + strlen(entry->d_name) < size)
                    strcpy(buffer + head, entry->d_name);
                break;
            }
        }
        closedir(dir);
    }
#endif
    return buffer;
}

#ifdef _WIN32
#define enter_directory(path) (_chdir(path) == 0)
#else
#define enter_directory(path) (chdir(path) == 0)
#endif

/* The game's directory is the one holding fonts.cv: the current one, the one
 * COVERT_GAME names, the executable's own, the one above that, or the
 * repository's rebuilt tree, tried in that order and entered once. */
static int directory_settled;

static int game_is_here(void)
{
    char path[512];
    return exists(find_name("fonts.cv", path, sizeof path));
}

void host_settle_directory(void)
{
    char here[512];
    char candidate[512];
    const char *named = getenv("COVERT_GAME");
    if (directory_settled)
        return;
    directory_settled = 1;
    if (game_is_here())
        return;
    here[0] = 0;
#ifdef _WIN32
    _getcwd(here, sizeof here);
#else
    if (!getcwd(here, sizeof here))
        here[0] = 0;
#endif
    if (named && *named && enter_directory(named) && game_is_here())
        return;
    host_executable_directory(candidate, sizeof candidate);
    if (candidate[0] && enter_directory(candidate) && game_is_here())
        return;
    if (candidate[0] && strlen(candidate) + 24 < sizeof candidate) {
        char *tail = candidate + strlen(candidate);
        strcpy(tail, "..");
        if (enter_directory(candidate) && game_is_here())
            return;
        strcpy(tail, "../../rebuilt/MPS/COVERT");
        if (enter_directory(candidate) && game_is_here())
            return;
    }
    if (here[0] && !enter_directory(here))
        here[0] = 0;
    fprintf(stderr, "covert: fonts.cv is not here: run from the game's "
                    "directory, or set COVERT_GAME to it\n");
}

/* The path a name the game spells is found at, in the game's directory. */
const char *host_path(const char *name, char *buffer, size_t size)
{
    host_settle_directory();
    return find_name(name, buffer, size);
}

int host_file_exists(const char *name)
{
    char path[512];
    return exists(host_path(name, path, sizeof path));
}

/* ---- what a module has open ----------------------------------------- */

/* Every descriptor and stream opened while a module runs, so what it leaves
 * open can be closed after it, as DOS closed a child's handles. */
#define TRACKED 64
static int open_fds[TRACKED];
static FILE *open_streams[TRACKED];
static int fds_open, streams_open;
static int streams_live;    /* every stream open now, tracked or not */
static int tracking;

static void note_fd(int fd)
{
    if (tracking && fd >= 0 && fds_open < TRACKED)
        open_fds[fds_open++] = fd;
}

static void forget_fd(int fd)
{
    int i;
    for (i = 0; i < fds_open; i++)
        if (open_fds[i] == fd) {
            open_fds[i] = open_fds[--fds_open];
            return;
        }
}

static void note_stream(FILE *stream)
{
    if (tracking && stream && streams_open < TRACKED)
        open_streams[streams_open++] = stream;
}

static void forget_stream(FILE *stream)
{
    int i;
    for (i = 0; i < streams_open; i++)
        if (open_streams[i] == stream) {
            open_streams[i] = open_streams[--streams_open];
            return;
        }
}

/* ---- the library's own, under the host's names ---------------------- */

INT port_open(str_addr path, UNSIGNED_INT oflag, ...)
{
    char resolved[512];
    int flags, mode = 0666, fd;
    if (oflag & MSC_RDWR)
        flags = O_RDWR;
    else if (oflag & MSC_WRONLY)
        flags = O_WRONLY;
    else
        flags = O_RDONLY;
    if (oflag & MSC_APPEND)
        flags |= O_APPEND;
    if (oflag & MSC_CREAT) {
        va_list ap;
        va_start(ap, oflag);
        (void) va_arg(ap, int);
        va_end(ap);
        flags |= O_CREAT;
    }
    if (oflag & MSC_TRUNC)
        flags |= O_TRUNC;
    if (oflag & MSC_EXCL)
        flags |= O_EXCL;
    fd = open(host_path((const char *) path, resolved, sizeof resolved),
              flags | O_BINARY, mode);
    note_fd(fd);
    return (INT) fd;
}

INT port_close(INT handle)
{
    forget_fd(handle);
    return (INT) close(handle);
}

/* A -1 descriptor is a missing file: fatal, naming the file opened. */
void port_assert_fd_success(INT fd, str_addr name)
{
    char text[300];
    if (fd != -1)
        return;
    sprintf(text, "%.256s: file missing", (const char *) name);
    host_fatal(text);
}

/* A 0 from fscanf is a read that consumed nothing: fatal, naming file and tag. */
void port_assert_scan_progress(INT scanned, str_addr name, str_addr key)
{
    char text[600];
    if (scanned != 0)
        return;
    sprintf(text, "%.256s: read stuck looking for %.256s", (const char *) name,
            (const char *) key);
    host_fatal(text);
}

/* A negative suspect index read as a record: fatal, naming the index. */
void port_assert_suspect_index(INT index)
{
    char text[64];
    if (index >= 0)
        return;
    sprintf(text, "suspect index %d read as a record", (int) index);
    host_fatal(text);
}

/* `message` to the standard error, formatted against the arguments given. */
void port_log_message(const char *message, ...)
{
    va_list args;

    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);
    fputc('\n', stderr);
}

/* A debug message to the standard error; compiled in only under PORT_DEBUG. */
#if PORT_DEBUG
void port_debug_message(const char *message, ...)
{
    va_list args;

    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);
    fputc('\n', stderr);
}
#endif

/* A trace message to the standard error; compiled in only under PORT_TRACE. */
#if PORT_TRACE
void port_trace_message(const char *message, ...)
{
    va_list args;

    va_start(args, message);
    vfprintf(stderr, message, args);
    va_end(args);
    fputc('\n', stderr);
}
#endif

/* A text-mode read where the host has no text mode: the file's bytes with
 * every CR dropped and a Ctrl-Z ending them, served from memory. */
#ifndef _WIN32
static struct { FILE *stream; unsigned char *bytes; } text_streams[TRACKED];

static FILE *text_stream(const char *path)
{
    FILE *raw = fopen(path, "rb");
    unsigned char *bytes;
    long size;
    size_t got, n, kept = 0;
    int i;
    if (!raw)
        return 0;
    if (fseek(raw, 0, SEEK_END) != 0 || (size = ftell(raw)) < 0
            || fseek(raw, 0, SEEK_SET) != 0) {
        fclose(raw);
        return 0;
    }
    bytes = malloc((size_t) size + 1);
    if (!bytes) {
        fclose(raw);
        return 0;
    }
    got = fread(bytes, 1, (size_t) size, raw);
    fclose(raw);
    for (n = 0; n < got && bytes[n] != 0x1a; n++)
        if (bytes[n] != '\r')
            bytes[kept++] = bytes[n];
    raw = fmemopen(bytes, kept, "r");
    if (!raw) {
        free(bytes);
        return fopen(path, "r");
    }
    for (i = 0; i < TRACKED; i++)
        if (!text_streams[i].stream) {
            text_streams[i].stream = raw;
            text_streams[i].bytes = bytes;
            return raw;
        }
    fclose(raw);
    free(bytes);
    return 0;
}

static void text_release(FILE *stream)
{
    int i;
    for (i = 0; i < TRACKED; i++)
        if (text_streams[i].stream == stream) {
            free(text_streams[i].bytes);
            text_streams[i].stream = 0;
            text_streams[i].bytes = 0;
        }
}
#else
#define text_release(stream) ((void) 0)
#endif

rt_stream port_fopen(str_addr path, str_addr mode)
{
    char resolved[512];
    const char *where = host_path((const char *) path, resolved, sizeof resolved);
    const char *how = (const char *) mode;
    FILE *stream;
#ifndef _WIN32
    if (how[0] == 'r' && !strchr(how, 'b') && !strchr(how, '+'))
        stream = text_stream(where);
    else
#endif
        stream = fopen(where, how);
    if (!stream) {
        /* Fatal, as port_assert_fd_success is: no caller checks for a null. */
        char text[700];
        sprintf(text, "%.256s: open failed (%.256s, %s): %s; %d live, %d tracked",
                (const char *) path, where, how, strerror(errno),
                streams_live, streams_open);
        host_fatal(text);
    }
    streams_live++;
    note_stream(stream);
    return stream;
}

INT port_fclose(rt_stream stream)
{
    int status;
    streams_live--;
    forget_stream(stream);
    status = fclose(stream);
    text_release(stream);
    return (INT) status;
}

INT port_access(str_addr path, INT mode)
{
    char resolved[512];
    return (INT) access(host_path((const char *) path, resolved, sizeof resolved),
                        mode & 6);
}

/* MSC 5.1's generator, which answers a 15-bit word; the same seed gives the
 * same sequence as under DOS. */
static unsigned long random_seed = 1;

INT port_rand(void)
{
    random_seed = (random_seed * 214013UL + 2531011UL) & 0xffffffffUL;
    return (INT) ((random_seed >> 16) & 0x7fff);
}

void port_srand(UNSIGNED_INT seed)
{
    random_seed = seed;
}

/* ---- the DOS file calls --------------------------------------------- */

UNSIGNED_INT _dos_open(str_addr path, UNSIGNED_INT mode, rt_addr handle)
{
    char resolved[512];
    int fd = open(host_path((const char *) path, resolved, sizeof resolved),
                  O_RDONLY | O_BINARY);
    if (fd < 0)
        return 2;
    note_fd(fd);
    *(INT *) handle = (INT) fd;
    return 0;
}

UNSIGNED_INT _dos_creat(str_addr path, UNSIGNED_INT attributes,
        rt_addr handle)
{
    char resolved[512];
    int fd = open(host_path((const char *) path, resolved, sizeof resolved),
                  O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0666);
    if (fd < 0)
        return 3;
    note_fd(fd);
    *(INT *) handle = (INT) fd;
    return 0;
}

UNSIGNED_INT _dos_read(INT handle, rt_far_addr buffer, UNSIGNED_INT count,
        rt_addr read_back)
{
    long got = (long) read(handle, buffer, count);
    if (got < 0)
        return 5;
    *(INT *) read_back = (INT) got;
    return 0;
}

/* Declared with no parameter list, since the game passes five words: the
 * handle, the buffer, the count, an unused word, and where to put the
 * count written. */
UNSIGNED_INT _dos_write(handle, buffer, count, unused, wrote)
    int handle;
    unsigned char *buffer;
    int count;
    int unused;
    unsigned char *wrote;
{
    long put = (long) write(handle, buffer, (size_t) count);
    if (put < 0)
        return 5;
    *(INT *) wrote = (INT) put;
    return 0;
}

UNSIGNED_INT _dos_close(INT handle)
{
    forget_fd(handle);
    return close(handle) == 0 ? 0 : 6;
}

/* INT 21h with a register block: only AH=42h, seek, is answered. */
INT intdos(rt_addr in, rt_addr out)
{
    union REGS *r = (union REGS *) in;
    union REGS *back = (union REGS *) out;
    if (r->h.ah == 0x42) {
        long offset = ((long) r->x.cx << 16) | r->x.dx;
        long at = (long) lseek(r->x.bx, offset, r->h.al);
        *back = *r;
        if (at < 0) {
            back->x.ax = (UNSIGNED_INT) errno;
            back->x.cflag = 1;
        } else {
            back->x.ax = (UNSIGNED_INT) (at & 0xffff);
            back->x.dx = (UNSIGNED_INT) ((at >> 16) & 0xffff);
            back->x.cflag = 0;
        }
        return (INT) back->x.ax;
    }
    *back = *r;
    back->x.cflag = 0;
    return (INT) back->x.ax;
}

/* int86 with the segment registers set as well, which are ignored. */
INT int86x(INT number, rt_addr in, rt_addr out, rt_addr segments)
{
    return port_int86(number, in, out);
}

/* ---- memory by segment ---------------------------------------------- */

UNSIGNED_INT _dos_allocmem(UNSIGNED_INT paragraphs, rt_addr segment)
{
    *(UNSIGNED_INT *) segment = host_block_new((size_t) paragraphs * 16);
    return 0;
}

UNSIGNED_INT _dos_freemem(UNSIGNED_INT segment)
{
    host_block_free(segment);
    return 0;
}

void movedata(UNSIGNED_INT source_segment, UNSIGNED_INT source_offset,
        UNSIGNED_INT dest_segment, UNSIGNED_INT dest_offset,
        UNSIGNED_INT count)
{
    unsigned char *from = host_block_base(source_segment);
    unsigned char *to = host_block_base(dest_segment);
    if (from && to)
        memmove(to + dest_offset, from + source_offset, count);
}

/* ---- the machine ---------------------------------------------------- */

void _dos_getdrive(rt_addr drive)
{
    *(INT *) drive = 3;
}

UNSIGNED_INT _bios_disk(UNSIGNED_INT service, rt_addr info)
{
    return 0;
}

/* The BIOS clock: ticks at 18.2 a second since the host's clock began. Polled
 * in loops, so the pump runs. */
UNSIGNED_INT _bios_timeofday(UNSIGNED_INT service, rt_addr ticks)
{
    unsigned long long ms = host_ticks_ms();
    host_pump();
    if (service == 0)
        *(LONG *) ticks = (LONG) (ms * 182065ull / 10000000ull);
    return 0;
}

/* Port reads: the CGA status port's vertical-retrace bit, the keyboard's last
 * byte, and the game port's buttons. The retrace is reported once per
 * sixty-hertz frame; a read after that sleeps to the next. */
INT inp(UNSIGNED_INT port)
{
    static unsigned int reported_frame = 0xffffffffu;
    if (port == 0x3da) {
        unsigned int now = host_ticks_ms();
        unsigned int frame = now / 17;
        host_pump();
        if (frame != reported_frame) {
            reported_frame = frame;
            return 8;
        }
        host_sleep_ms(17 - now % 17);
        return 0;
    }
    if (port == 0x60) {
        host_pump();
        return (INT) host_key_port();
    }
    if (port == 0x201) {
        /* The four buttons in the high nibble, active low; with no controller
         * nothing is pressed. */
        unsigned int buttons = host_joystick_present()
                               ? host_joystick_buttons() : 0;
        return (INT) (0xff & ~((buttons & 0x0f) << 4));
    }
    return 0;
}

/* ---- the console ---------------------------------------------------- */

static int pending_scan = -1;

INT getch(void)
{
    unsigned int code;
    if (pending_scan >= 0) {
        int scan = pending_scan;
        pending_scan = -1;
        return (INT) scan;
    }
    code = host_key_take();
    if ((code & 0xff) == 0) {
        pending_scan = (int) (code >> 8);
        return 0;
    }
    return (INT) (code & 0xff);
}

INT kbhit(void)
{
    return host_key_waiting() ? 1 : 0;
}

/* ---- what glibc never had ------------------------------------------- */

#ifndef _WIN32
str_addr itoa(INT value, str_addr text, INT radix)
{
    char *out = (char *) text;
    char digits[34];
    int n = 0, negative = value < 0 && radix == 10;
    unsigned int rest = negative ? (unsigned int) -(int) value
                                 : (unsigned int) (unsigned short) value;
    if (radix < 2 || radix > 36)
        radix = 10;
    do {
        digits[n++] = "0123456789abcdefghijklmnopqrstuvwxyz"[rest % radix];
        rest /= radix;
    } while (rest);
    if (negative)
        *out++ = '-';
    while (n)
        *out++ = digits[--n];
    *out = 0;
    return text;
}

INT strcmpi(str_addr left, str_addr right)
{
    return (INT) strcasecmp((const char *) left, (const char *) right);
}

INT strnicmp(str_addr left, str_addr right, UNSIGNED_INT count)
{
    return (INT) strncasecmp((const char *) left, (const char *) right, count);
}

str_addr strupr(str_addr text)
{
    unsigned char *at;
    for (at = text; *at; at++)
        *at = (unsigned char) toupper(*at);
    return text;
}
#endif

/* ---- a module's run ------------------------------------------------- */

/* What a DOS child's run-time started with and gave back: a generator
 * seeded at 1, and no file open. */
void host_runtime_module_begin(void)
{
    random_seed = 1;
    fds_open = streams_open = 0;
    tracking = 1;
}

void host_runtime_module_end(void)
{
    tracking = 0;
    while (fds_open)
        close(open_fds[--fds_open]);
    while (streams_open) {
        streams_live--;
        fclose(open_streams[--streams_open]);
        text_release(open_streams[streams_open]);
    }
}
