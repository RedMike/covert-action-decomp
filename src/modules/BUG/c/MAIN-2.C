/* MAIN-2.C -- more of the module's own routines in MAIN.C's unit, after shared/MAIN.C. */
#include "BUG.H"
#include "LOADDISK.H"
#include "ANIMSTUB.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "MENU.H"
#include "BOARD.H"
#include "MAIN.H"
#include "RESULT.H"

/* Load one DAC colour register through the BIOS, INT 10h function 1010h.
 * Indices above 7 are moved up by eight, into the EGA's bright half.
 */
void c_set_dac(INT colour, char red, char green, char blue)
{
    union REGS regs;

    if (colour > 7)
        colour += 8;
    regs.h.ah = 0x10;
    regs.h.al = 0x10;
    regs.x.bx = colour;
    regs.h.dh = red;
    regs.h.ch = green;
    regs.h.cl = blue;
    INTERRUPT(0x10, &regs, &regs);
}
