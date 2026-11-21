/* SEEK.C -- seeking a DOS file handle to an absolute position.
 */
#include "GAME.H"
#include "SEEK.H"

/* shared_include_start: ../../../../shared/c/FILE-SEEK.C -- generated */
/* FILE-SEEK.C -- c_seek, seeking a file to an absolute position.
 */

/* Seek `handle` to the absolute position `hi`:`lo` through DOS function 42h;
 * answer 0, or DOS's error code.
 */
INT c_seek(INT handle, UNSIGNED_INT lo, UNSIGNED_INT hi)
{
    INT regs[7];

    regs[0] = 0x4200;
    regs[1] = handle;
    regs[2] = hi;
    regs[3] = lo;
    intdos((rt_addr) regs, (rt_addr) regs);
    if (regs[6] == 0)
        return 0;
    return regs[0];
}
/* shared_include_end: ../../../../shared/c/FILE-SEEK.C */
