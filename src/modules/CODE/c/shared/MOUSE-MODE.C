/* MOUSE-MODE.C -- the INT 33h mouse reset, show, hide and position calls.
 */
#include "CODE.H"

/* shared_include_start: ../../../../shared/c/MOUSE-INIT.C -- generated */
/* MOUSE-INIT.C -- c_mouse_reset, an INT 33h mouse-driver call.
 */

/* INT 33h AX=0 -- reset the driver and ask whether one is installed. */
void c_mouse_reset(void)
{
    shm_mouse_regs.x.ax = 0;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-INIT.C */

/* shared_include_start: ../../../../shared/c/MOUSE-SHOW.C -- generated */
/* MOUSE-SHOW.C -- c_mouse_show, an INT 33h mouse-driver call.
 */

/* INT 33h AX=1 -- show the pointer. */
void c_mouse_show(void)
{
    shm_mouse_regs.x.ax = 1;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-SHOW.C */

/* shared_include_start: ../../../../shared/c/MOUSE-HIDE.C -- generated */
/* MOUSE-HIDE.C -- c_mouse_hide, an INT 33h mouse-driver call.
 */

/* INT 33h AX=2 -- hide the pointer. */
void c_mouse_hide(void)
{
    shm_mouse_regs.x.ax = 2;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-HIDE.C */

/* shared_include_start: ../../../../shared/c/MOUSE-WHERE.C -- generated */
/* MOUSE-WHERE.C -- c_mouse_where, an INT 33h mouse-driver call.
 */

/* INT 33h AX=3 -- where the pointer is and which buttons are down. */
void c_mouse_where(void)
{
    shm_mouse_regs.x.ax = 3;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
    shm_mouse_buttons = shm_mouse_regs.x.bx;
    shm_mouse_x = shm_mouse_regs.x.cx;
    shm_mouse_y = shm_mouse_regs.x.dx;
}
/* shared_include_end: ../../../../shared/c/MOUSE-WHERE.C */
