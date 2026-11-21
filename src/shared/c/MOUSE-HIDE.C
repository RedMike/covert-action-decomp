/* MOUSE-HIDE.C -- c_mouse_hide, an INT 33h mouse-driver call.
 */

/* INT 33h AX=2 -- hide the pointer. */
void c_mouse_hide(void)
{
    shm_mouse_regs.x.ax = 2;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
