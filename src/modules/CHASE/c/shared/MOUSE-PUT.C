/* MOUSE-PUT.C -- moving the mouse pointer.
 */
#include "CHASE.H"

/* shared_include_start: ../../../../shared/c/MOUSE-MOVE.C -- generated */
/* MOUSE-MOVE.C -- c_mouse_move, an INT 33h mouse-driver call.
 */

/* Put the mouse pointer at (`across`, `down`) through INT 33h AX=4. */
void c_mouse_move(INT across, INT down)
{
    shm_mouse_regs.x.ax = 4;
    shm_mouse_regs.x.cx = across;
    shm_mouse_regs.x.dx = down;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-MOVE.C */
