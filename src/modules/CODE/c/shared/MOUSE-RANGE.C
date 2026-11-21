/* MOUSE-RANGE.C -- the INT 33h fence around the mouse pointer.
 */
#include "CODE.H"

/* shared_include_start: ../../../../shared/c/MOUSE-FENCE.C -- generated */
/* MOUSE-FENCE.C -- c_mouse_fence, an INT 33h mouse-driver call.
 */

/* Fence the pointer in, INT 33h AX=7 for the columns and AX=8 for the rows. */
void c_mouse_fence(INT left, INT top, INT right, INT bottom)
{
    shm_mouse_regs.x.ax = 7;
    shm_mouse_regs.x.cx = left;
    shm_mouse_regs.x.dx = right;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
    shm_mouse_regs.x.ax = 8;
    shm_mouse_regs.x.cx = top;
    shm_mouse_regs.x.dx = bottom;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-FENCE.C */
