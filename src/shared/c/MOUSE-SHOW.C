/* MOUSE-SHOW.C -- c_mouse_show, an INT 33h mouse-driver call.
 */

/* INT 33h AX=1 -- show the pointer. */
void c_mouse_show(void)
{
    shm_mouse_regs.x.ax = 1;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
