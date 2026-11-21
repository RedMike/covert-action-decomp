/* SPRITE-DRAW.C -- putting one of the module's own sprites on the screen.
 */
#include "BUG.H"
#include "BOARD.H"

/* The same for the wire pieces and chips in asm_bugs_sprites, by a
 * BUG_SPRITE_* index. */
void c_draw_bug_sprite(INT sprite, UNSIGNED_INT x, UNSIGNED_INT y)
{
    drv_jump_gfx_sprite_put(shd_screen, x, y, asm_bugs_sprites[sprite]);
}
