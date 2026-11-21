/* VIDEO-MODE.C -- c_set_video_mode, setting a BIOS video mode.
 */

/* INT 10h function 0 -- set video mode `mode`. */
INT c_set_video_mode(INT mode)
{
    INT regs[7];

    *((char *) regs + 1) = 0;
    *(char *) regs = (char) mode;
    INTERRUPT(0x10, regs, regs);
}
