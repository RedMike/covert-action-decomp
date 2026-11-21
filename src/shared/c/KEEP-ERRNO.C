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