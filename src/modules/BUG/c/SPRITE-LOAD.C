/* SPRITE-LOAD.C -- cutting bugs.pic into asm_bugs_sprites.
 */
#include "BUG.H"
#include "ANI_LD2.H"
#include "FACES.H"
#include "BOARD.H"

/* Cut the face sprites, then load bugs.pic and cut it into sprites: two rows
 * of sixteen 8x8 wire pieces from BUG_SPRITE_WIRE, then the twelve 16x16
 * chips from BUG_SPRITE_CHIPS.
 */
void c_load_sprites(void)
{
    INT row;
    INT col;

    drv_jump_gfx_pool_alloc();
    c_faces_cut();
    drv_jump_gfx_set_colour_map(&dat_colours_plain, &dat_colours_plain);
    c_load_picture(dat_str_bugs_pic, 2);
    for (row = 0; row < 2; row++)
        for (col = 0; col < 0x10; col++)
            asm_bugs_sprites[BUG_SPRITE_WIRE + (row << 4) + col] =
                drv_jump_gfx_grab(2, col << 3, (row << 3) + 0x10, 8, 8);
    row = 0;
    do {
        asm_bugs_sprites[BUG_SPRITE_CHIPS + row] =
            drv_jump_gfx_grab(2, row << 4, 0, 0x10, 0x10);
        row++;
    } while (row < 0xc);
    drv_jump_gfx_pool_release();
}
