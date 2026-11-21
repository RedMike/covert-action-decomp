/* MOUSE-PRESS.C -- reading a mouse button's press counter.
 */
#include "CHASE.H"

/* shared_include_start: ../../../../shared/c/MOUSE-PRESSES.C -- generated */
/* MOUSE-PRESSES.C -- c_mouse_presses, an INT 33h mouse-driver call.
 */

/* Read the press counter for one button through INT 33h AX=5, and copy the
 * four register words out into the mouse variables.
 */
void c_mouse_presses(INT button)
{
    shm_mouse_regs.x.ax = 5;
    shm_mouse_regs.x.bx = button;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
    shm_mouse_buttons = shm_mouse_regs.x.ax;
    shm_mouse_count = shm_mouse_regs.x.bx;
    shm_mouse_x = shm_mouse_regs.x.cx;
    shm_mouse_y = shm_mouse_regs.x.dx;
}
/* shared_include_end: ../../../../shared/c/MOUSE-PRESSES.C */
