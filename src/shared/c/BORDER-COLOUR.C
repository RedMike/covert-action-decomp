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
