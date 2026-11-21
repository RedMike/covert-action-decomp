/* CURSOR.C -- placing the text cursor.
 */
#include "INTRO.H"
#include "CURSOR.H"

/* Put the cursor at (`row`, `col`) on page 0 through INT 10h AH=2. */
void c_cursor_at(char row, char col)
{
    asm_regs.h.ah = 2;
    asm_regs.h.bh = 0;
    asm_regs.h.dh = row;
    asm_regs.h.dl = col;
    asm_int86(0x10, &asm_regs, &asm_regs);
}
