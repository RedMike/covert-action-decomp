/* TILES-2.C -- more of the module's own routines in TILES.C's unit, after shared/TILES.C. */
#include "TAC.H"
#include "FACES.H"
#include "ANI_LD2.H"
#include "TILES.H"
#include "MODOPTS.H"

#ifdef TAC_PLAYER_DISGUISE_SPRITE
/* The player's cells of the eight rows, columns 0 to 7 and 16 to 19, grabbed
 * again with black (5) turned to the belt colour, as the disguise does to the
 * portrait's magenta; twelve a row. None on CGA or with the option off. */
static UNSIGNED_INT player_disguise_sprites[8 * 12];
static INT player_disguise_ready;

static void c_player_disguise_grab(void)
{
    INT row;
    INT col;

    if (shm_cga != 0 || !MOD_ON(player_disguise_sprite))
        return;
    /* Recolour the player's columns of the sheet as the disguise has it. */
    drv_jump_gfx_fill(asm_status_page, 0, 0, 128, 128, 5, asm_belt_text);
    drv_jump_gfx_fill(asm_status_page, 256, 0, 64, 128, 5,
                      asm_belt_text);
    /* And cut them out again, skipping the guards' eight columns between. */
    for (row = 0; row < 8; row++)
        for (col = 0; col < 12; col++)
            player_disguise_sprites[row * 12 + col] =
                drv_jump_gfx_grab(2, ((col < 8 ? col : col + 8) << 4) + 1,
                                  (row << 4) + 1, 15, 15);
    player_disguise_ready = 1;
}
#endif

/* One board tile, blitted from the sprites cut out of the tile page. */
void c_draw_tile_2(INT tile, INT x, INT y)
{
#ifdef TAC_PLAYER_DISGUISE_SPRITE
    INT col;

    /* the disguise the portrait shows, rather than asm_disguised, which an
     * alarm clears only after the cast is drawn */
    if (asm_disguise_label_shown != 0 && player_disguise_ready
        && tile < 160) {
        /* A player's cell of the sheet is drawn from the disguised copy instead. */
        col = tile % 20;
        if (col < 8 || col >= 16) {
            drv_jump_gfx_sprite_put(shd_screen, x, y,
                player_disguise_sprites[tile / 20 * 12
                                        + (col < 8 ? col : col - 8)]);
            return;
        }
    }
#endif
    /* Put the tile's sprite on the screen. */
    drv_jump_gfx_sprite_put(shd_screen, x, y, asm_tile_sprites[tile]);
}

/* Load the tile page and cut it up: every 16x16 cell of the 8x20 sheet, then
 * the two strips below it, each kept as a driver handle. */
void c_load_tiles(void)
{
    INT v0j;                            /* the row */
    INT v1j;                            /* the column */

    /* Take the driver's pool for the sprites, and cut the dossier faces while asm_film_left is set. */
    drv_jump_gfx_pool_alloc();
    if (asm_film_left != 0)
        c_faces_cut();
    /* Load the sprite sheet for Maxine or for Max. */
    if ((shm_options & OPT_FEMALE) != 0)
        c_load_picture(dat_str_spritesf_pic, 2);
    else
        c_load_picture(dat_str_sprites_pic, 2);
    /* The guards wear one of three colours by their organisation. */
    switch (shm_case_org % 3) {
    case 0:
        asm_belt_text = 14;
        break;
    case 1:
        asm_belt_text = 11;
        break;
    case 2:
        asm_belt_text = 15;
        break;
    }
    /* So recolour the sheet's colour 14 to it, except on CGA, which keeps 14. */
    if (shm_cga != 0)
        asm_belt_text = 14;
    else
        drv_jump_gfx_fill(asm_status_page, 0, 0, 320, 200, 14,
                          asm_belt_text);
    /* The people: eight rows, one a facing, of twenty cells. */
    for (v0j = 0; v0j < 8; v0j++)
        for (v1j = 0; v1j < 20; v1j++)
            asm_tile_sprites[v0j * 20 + v1j] =
                drv_jump_gfx_grab(2, (v1j << 4) + 1, (v0j << 4) + 1, 15, 15);
    /* The hit frames and the two slumps, in the strip below them. */
    for (v0j = 0; v0j < 6; v0j++)
        (asm_tile_sprites + 160)[v0j] =
            drv_jump_gfx_grab(2, (v0j << 4) + 1, 129, 15, 15);
    /* The eight frames of a blast, in the strip under that. */
    for (v0j = 0; v0j < 8; v0j++)
        (asm_tile_sprites + 168)[v0j] =
            drv_jump_gfx_grab(2, (v0j << 4) + 1, 145, 15, 15);
    /* And the fallen player, the seventh cell of the first strip. */
    asm_tile_sprites[166] = drv_jump_gfx_grab(2, 97, 129, 15, 15);
#ifdef TAC_PLAYER_DISGUISE_SPRITE
    c_player_disguise_grab();
#endif
    /* Give the driver's pool back, as the load began by taking it. */
    drv_jump_gfx_pool_release();
}
