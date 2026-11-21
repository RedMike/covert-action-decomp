/* CHIP-DRAW.C -- drawing one cell of the puzzle grid.
 */
#include "BUG.H"
#include "BOARD.H"

/* Draw the box a chip sits in, highlighted when `flag` is set, and then the
 * chip itself; a `chip` of -1 leaves the box empty, which rubs the cursor out.
 */
void c_draw_chip_box(INT chip, INT x, INT y, LONG flag)
{
    drv_jump_gfx_copy_rect(dat_chip_page, (INT) flag != 0 ? 0x11 : 1, 0x37, 0xe, 0x13, shd_screen, x + 1, y - 1);
    if (chip != -1)
        c_draw_bug_sprite((chip & CHIP_KIND) + BUG_SPRITE_CHIPS, x, y);
}
