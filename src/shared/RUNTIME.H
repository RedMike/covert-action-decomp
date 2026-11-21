/* RUNTIME.H -- the MSC 5.1 run-time the game calls, one signature each. A name
 * with no prefix is the library's own.
 */
#ifndef RUNTIME_H
#define RUNTIME_H

/* The game was compiled with no prototypes in scope, so a signature here is
 * the library's, corrected to what the sites pass.
 */
/* A parameter's type follows the sites: a word type where they hold a word, a
 * pointer where they hold a pointer.
 */

/* The word types. */
#include "ADDRESS.H"

/* FAR and NEAR, and the widths the two builds disagree on. */
#include "PORTING.H"

/* What the host's library has, a portable build takes from its
 * headers; those functions keep their prototypes for DOS alone. */
#ifdef PORT_MODERN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#endif

/* A Windows host takes the MSVCRT extras from its headers too; any
 * other host keeps the prototype and defines the function itself. */
#ifdef _WIN32
#include <process.h>
#include <stdlib.h>
#include <string.h>
#endif

/* Long division, a compiler helper: CL emits the call itself with the
 * operands in registers, so there is no parameter list to write.
 */
UNSIGNED_LONG _aNldiv();

/* Long multiplication, on the same terms as _aNldiv. */
UNSIGNED_LONG _aNlmul();

/* Long shift left, on the same terms as _aNldiv. */
UNSIGNED_LONG _aNlshl();

/* Long shift right, on the same terms as _aNldiv. */
UNSIGNED_LONG _aNlshr();

/* INT 13h, the BIOS disk service. */
UNSIGNED_INT _bios_disk(UNSIGNED_INT service, rt_addr info);

/* INT 1Ah, the BIOS tick count. */
UNSIGNED_INT _bios_timeofday(UNSIGNED_INT service, rt_addr ticks);

/* INT 21h AH=48h. Returns 0, or the DOS error. */
UNSIGNED_INT _dos_allocmem(UNSIGNED_INT paragraphs, rt_addr segment);

/* INT 21h AH=3Eh. */
UNSIGNED_INT _dos_close(INT handle);

/* INT 21h AH=3Ch. */
UNSIGNED_INT _dos_creat(str_addr path, UNSIGNED_INT attributes,
        rt_addr handle);

/* INT 21h AH=49h. */
UNSIGNED_INT _dos_freemem(UNSIGNED_INT segment);

/* INT 21h AH=19h, the current drive. */
void _dos_getdrive(rt_addr drive);

/* INT 21h AH=3Dh. */
UNSIGNED_INT _dos_open(str_addr path, UNSIGNED_INT mode, rt_addr handle);

/* INT 21h AH=3Fh. The buffer is far, so it is two words, which rt_far_addr is
 * on the 8086.
 */
UNSIGNED_INT _dos_read(INT handle, rt_far_addr buffer, UNSIGNED_INT count,
        rt_addr read);

/* INT 21h AH=40h. No list: the sites pass the far buffer as one long or as
 * two words, so no one list fits them all.
 */
UNSIGNED_INT _dos_write();

/* Absolute value. */
#ifndef PORT_MODERN
INT abs(INT value);
#endif

/* Whether a path exists and allows a mode. The host's own, because a name the
 * game spells in lower case has to be found in a directory that may not.
 */
#ifdef PORT_MODERN
#define access port_access
INT port_access(str_addr path, INT mode);
#else
INT access(str_addr path, INT mode);
#endif

/* Close a handle from open. The host's own, so that what a module leaves open
 * can be closed when it ends.
 */
#ifdef PORT_MODERN
#define close port_close
INT port_close(INT handle);
#else
INT close(INT handle);
#endif

/* Stop the program with a status. No list, as some sites push none. The host's
 * own on a portable build, where a module's exit returns to the launcher.
 */
#ifdef PORT_MODERN
#define exit port_exit
void port_exit();
#else
void exit();
#endif

/* Close a stream from fopen. The host's own, on close's terms. */
#ifdef PORT_MODERN
#define fclose port_fclose
INT port_fclose(rt_stream stream);
#else
INT fclose(rt_stream stream);
#endif

/* Open a stream. The result is a FILE *, kept in a word. The host's own, for
 * the reason access is.
 */
#ifdef PORT_MODERN
#define fopen port_fopen
rt_stream port_fopen(str_addr path, str_addr mode);
#else
rt_stream fopen(str_addr path, str_addr mode);
#endif

/* Read one field from a stream by format. Not variadic, unlike the library's
 * own: the game only ever reads one field into one buffer.
 */
#ifndef PORT_MODERN
INT fscanf(rt_stream stream, str_addr format, str_addr buffer);
#endif

/* Move a stream's position. */
#ifndef PORT_MODERN
INT fseek(rt_stream stream, LONG offset, INT origin);
#endif

/* Read a key without echoing it. */
INT getch(void);

/* Read a byte from a port. */
INT inp(UNSIGNED_INT port);

/* INT n with the general registers set from a block. */
INT int86(INT number, rt_addr in, rt_addr out);

/* int86 with the segment registers set as well. */
INT int86x(INT number, rt_addr in, rt_addr out, rt_addr segments);

/* INT 21h with the general registers set. */
INT intdos(rt_addr in, rt_addr out);

/* Format an integer into a buffer; returns the buffer, which is the same
 * string it was handed.
 */
#ifndef _WIN32
str_addr itoa(INT value, str_addr text, INT radix);
#endif

/* Whether a key is waiting. */
INT kbhit(void);

/* Move a handle's position; the result is a long. */
#ifndef PORT_MODERN
LONG lseek(INT handle, LONG offset, INT origin);
#endif

/* Compare two blocks. */
#ifndef PORT_MODERN
INT memcmp(char *left, char *right, UNSIGNED_INT count);
#endif

/* Copy a block; returns the destination. */
#ifndef PORT_MODERN
rt_addr memcpy(char *dest, char *source, UNSIGNED_INT count);
#endif

/* Fill a block; returns the destination. */
#ifndef PORT_MODERN
rt_addr memset(char *dest, INT fill, UNSIGNED_INT count);
#endif

/* Copy between two far addresses, each given as a segment and an offset. */
void movedata(UNSIGNED_INT source_segment, UNSIGNED_INT source_offset,
        UNSIGNED_INT dest_segment, UNSIGNED_INT dest_offset,
        UNSIGNED_INT count);

/* Open a file. The third argument is the creation mode, which only a site that
 * creates passes. The host's own, for the reason access is and because the
 * flags are MSC's spellings.
 */
#ifdef PORT_MODERN
#define open port_open
INT port_open(str_addr path, UNSIGNED_INT oflag, ...);
#else
INT open(str_addr path, UNSIGNED_INT oflag, ...);
#endif

/* Report errno on the standard error. */
#ifndef PORT_MODERN
void perror(str_addr text);
#endif

/* The next pseudo-random number, 0 to 7fffh. The host's own goes to 2^31, and
 * the game scales it as a 15-bit word, so the host keeps MSC's generator.
 */
#ifdef PORT_MODERN
#define rand port_rand
INT port_rand(void);
#else
INT rand(void);
#endif

/* Read from a handle. */
#ifndef PORT_MODERN
INT read(INT handle, str_addr buffer, UNSIGNED_INT count);
#endif

/* Run another program and wait for it. Not variadic, unlike the library's own:
 * fixed to the path, one argument and the two nulls that close the list.
 */
#ifndef _WIN32
INT spawnl(INT mode, str_addr path, str_addr arg0, str_addr arg1,
        str_addr end);
#endif

/* spawnl, searching PATH, and fixed likewise: the file, three arguments and
 * the two nulls that close the list.
 */
#ifndef _WIN32
INT spawnlp(INT mode, str_addr file, str_addr arg0, str_addr arg1,
        str_addr arg2, str_addr arg3, str_addr end);
#endif

/* Seed the generator, MSC's on the host as with rand. */
#ifdef PORT_MODERN
#define srand port_srand
void port_srand(UNSIGNED_INT seed);
#else
void srand(UNSIGNED_INT seed);
#endif

/* Append; returns the destination. */
#ifndef PORT_MODERN
str_addr strcat(str_addr dest, str_addr source);
#endif

/* Compare two strings. */
#ifndef PORT_MODERN
INT strcmp(str_addr left, str_addr right);
#endif

/* Compare two strings, ignoring case. */
#ifndef _WIN32
INT strcmpi(str_addr left, str_addr right);
#endif

/* Copy; returns the destination. */
#ifndef PORT_MODERN
str_addr strcpy(str_addr dest, str_addr source);
#endif

/* How long a string is. */
#ifndef PORT_MODERN
UNSIGNED_INT strlen(str_addr text);
#endif

/* Compare two strings to a length, ignoring case. */
#ifndef _WIN32
INT strnicmp(str_addr left, str_addr right, UNSIGNED_INT count);
#endif

/* Find a string in a string, or 0. */
#ifndef PORT_MODERN
str_addr strstr(str_addr text, str_addr pattern);
#endif

/* Upper-case in place; returns the string. */
#ifndef _WIN32
str_addr strupr(str_addr text);
#endif

/* Seconds since the epoch, as a long. No list: the sites push the 0 they pass
 * as a word or as a long.
 */
#ifndef PORT_MODERN
LONG time();
#endif

/* Write to a handle. */
#ifndef PORT_MODERN
INT write(INT handle, str_addr buffer, UNSIGNED_INT count);
#endif

/* The run-time's own data the modules reach. */

/* The error the last library call left, saved and put back around a video-mode
 * call. An `unsigned int` on DOS; a portable build takes the host's own from
 * <errno.h>.
 */
#ifdef PORT_MODERN
#include <errno.h>
#else
extern UNSIGNED_INT errno;
#endif

#endif /* RUNTIME_H */
