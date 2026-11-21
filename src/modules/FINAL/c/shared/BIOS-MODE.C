/* BIOS-MODE.C -- setting the border colour and the video mode via the BIOS.
 */
#include "FINAL.H"
#include "BIOSMODE.H"

/* shared_include_start: ../../../../shared/c/BORDER-COLOUR.C -- generated */
/* BORDER-COLOUR.C -- c_set_border_colour, which sets the border colour.
 */

/* Set the border (overscan) colour: INT 10h function 10h, subfunction 1. */
INT c_set_border_colour(INT colour)
{
    union REGS regs;

    regs.h.ah = 0x10;
    regs.h.al = 1;
    regs.h.bh = (char) colour;
    INTERRUPT(0x10, &regs, &regs);
}
/* shared_include_end: ../../../../shared/c/BORDER-COLOUR.C */

/* shared_include_start: ../../../../shared/c/VIDEO-MODE.C -- generated */
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
/* shared_include_end: ../../../../shared/c/VIDEO-MODE.C */
