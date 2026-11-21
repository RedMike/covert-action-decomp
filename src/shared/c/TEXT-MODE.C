/* TEXT-MODE.C -- c_set_text_mode, back to the 80-column text mode.
 */

/* Set mode 3, the 80-column text mode the game leaves behind on exit. */
INT c_set_text_mode(void)
{
    shm_regs.h.ah = 0;
    shm_regs.h.al = 3;
    INTERRUPT(0x10, &shm_regs, &shm_regs);
}