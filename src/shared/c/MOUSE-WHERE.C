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
