/* DAC-BLOCK.C -- handing the BIOS a block of colour registers. */
#include "FINAL.H"

/* shared_include_start: ../../../../shared/c/DAC-BLOCK.C -- generated */
/* DAC-BLOCK.C -- c_set_dac_block, loading all 256 DAC colour registers.
 */

/* Load the 100h DAC colour registers from `table`, three bytes each: INT 10h
 * function 1012h.
 */
INT c_set_dac_block(char *table)
{
    INT regs[7];
    INT sregs[4];
    rt_far_addr addr[1];

    *(char FAR **) addr = (char FAR *) table;
    *((char *) regs + 1) = 0x10;
    *(char *) regs = 0x12;
    regs[1] = 0;
    regs[2] = 0x100;
    regs[3] = (UNSIGNED_INT) table;
    sregs[0] = ((UNSIGNED_INT *) addr)[1];
    int86x(0x10, (rt_addr) regs, (rt_addr) regs, (rt_addr) sregs);
}
/* shared_include_end: ../../../../shared/c/DAC-BLOCK.C */
