/* MOUSE-INIT.C -- c_mouse_reset, an INT 33h mouse-driver call.
 */

/* INT 33h AX=0 -- reset the driver and ask whether one is installed. */
void c_mouse_reset(void)
{
    shm_mouse_regs.x.ax = 0;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
