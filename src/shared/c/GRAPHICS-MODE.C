/* GRAPHICS-MODE.C -- c_set_graphics_mode, switching to 16-colour graphics.
 */

/* Set BIOS video mode 0dh, 320x200 in sixteen colours, through shm_regs. */
INT c_set_graphics_mode(void)
{
    shm_regs.h.ah = 0;
    shm_regs.h.al = 0xd;
    INTERRUPT(0x10, &shm_regs, &shm_regs);
}