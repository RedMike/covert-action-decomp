/* PALENTRY.C -- setting one palette register.
 */
#include "TAC.H"

/* INT 10h function 1010h -- set one palette register.
 *
 * The register block is a local, seven words, of which only AX, BX and the
 * three colour bytes are set. */
INT c_set_palette_entry(INT slot, INT red, INT green, INT blue)
{
    INT regs[7];

    /* AX = 1010h, the colour register in BX, and red, green and blue in DH, CH and CL. */
    *((char *) regs + 1) = 0x10;
    *(char *) regs = 0x10;
    regs[1] = slot;
    *((char *) regs + 7) = (char) red;
    *((char *) regs + 5) = (char) green;
    *((char *) regs + 4) = (char) blue;
    INTERRUPT(0x10, regs, regs);
}
