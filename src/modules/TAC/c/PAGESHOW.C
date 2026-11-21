/* PAGESHOW.C -- selecting the display page.
 */
#include "TAC.H"
#include "PAGESHOW.H"

/* Select the active display page through INT 10h AH=5. */
INT c_set_display_page(char page)
{
    /* Ask the video BIOS to show `page`. */
    asm_regs.h.ah = 5;
    asm_regs.h.al = page;
    INTERRUPT(0x10, &asm_regs, &asm_regs);
}
