/* VIDEO-MODE.C -- setting the graphics and text video modes.
 */
#include "CHASE.H"

/* shared_include_start: ../../../../shared/c/GRAPHICS-MODE.C -- generated */
/* GRAPHICS-MODE.C -- c_set_graphics_mode, switching to 16-colour graphics.
 */

/* Set BIOS video mode 0dh, 320x200 in sixteen colours, through shm_regs. */
INT c_set_graphics_mode(void)
{
    shm_regs.h.ah = 0;
    shm_regs.h.al = 0xd;
    INTERRUPT(0x10, &shm_regs, &shm_regs);
}
/* shared_include_end: ../../../../shared/c/GRAPHICS-MODE.C */

/* shared_include_start: ../../../../shared/c/TEXT-MODE.C -- generated */
/* TEXT-MODE.C -- c_set_text_mode, back to the 80-column text mode.
 */

/* Set mode 3, the 80-column text mode the game leaves behind on exit. */
INT c_set_text_mode(void)
{
    shm_regs.h.ah = 0;
    shm_regs.h.al = 3;
    INTERRUPT(0x10, &shm_regs, &shm_regs);
}
/* shared_include_end: ../../../../shared/c/TEXT-MODE.C */
