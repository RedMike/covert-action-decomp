/* FATAL.C -- fatal errors, and setting a video mode keeping errno.
 */
#include "TAC.H"
#include "FATAL.H"

/* shared_include_start: ../../../../shared/c/FATAL-ERROR.C -- generated */
/* FATAL-ERROR.C -- c_fatal, reporting an error and ending the program.
 */

/* Report `what` through perror from text mode and exit with code 63h. */
INT c_fatal(rt_addr what)
{
    c_set_mode_keeping_errno(3);
    perror(what);
    exit(0x63);
}
/* shared_include_end: ../../../../shared/c/FATAL-ERROR.C */

/* shared_include_start: ../../../../shared/c/KEEP-ERRNO.C -- generated */
/* KEEP-ERRNO.C -- c_set_mode_keeping_errno, a mode switch that spares errno.
 */

/* Set BIOS video mode `mode`, leaving `errno` as it was so a pending error is
 * not lost.
 */
INT c_set_mode_keeping_errno(INT mode)
{
    INT regs[7];
    INT saved;

    saved = errno;
    *((char *) regs + 1) = 0;
    *(char *) regs = (char) mode;
    INTERRUPT(0x10, regs, regs);
    errno = saved;
}
/* shared_include_end: ../../../../shared/c/KEEP-ERRNO.C */
