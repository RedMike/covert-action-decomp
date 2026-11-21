/* MOUSE-RELEASE.C -- the INT 33h mouse button release count.
 */
#include "CODE.H"

/* shared_include_start: ../../../../shared/c/MOUSE-RELEASES.C -- generated */
/* MOUSE-RELEASES.C -- c_mouse_releases, an INT 33h mouse-driver call.
 */

/* Read the release counter for one button through INT 33h AX=6, and copy the
 * four register words out into the mouse variables.
 */
void c_mouse_releases(INT button)
{
    shm_mouse_regs.x.ax = 6;
    shm_mouse_regs.x.bx = button;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
    shm_mouse_buttons = shm_mouse_regs.x.ax;
    shm_mouse_count = shm_mouse_regs.x.bx;
    shm_mouse_x = shm_mouse_regs.x.cx;
    shm_mouse_y = shm_mouse_regs.x.dx;
}
/* shared_include_end: ../../../../shared/c/MOUSE-RELEASES.C */
