/* DISPLAY-PAGE.C -- c_set_display_page, choosing the page the screen shows.
 */

/* Make `page` the BIOS's active display page: INT 10h function 5, through the
 * shared register block.
 */
void c_set_display_page(char page)
{
    shm_regs.h.ah = 5;
    shm_regs.h.al = page;
    INTERRUPT(0x10, &shm_regs, &shm_regs);
}
