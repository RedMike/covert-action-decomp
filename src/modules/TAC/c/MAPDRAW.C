/* MAPDRAW.C -- drawing the equipment panel.
 */
#include "TAC.H"
#include "CITY.H"
#include "MENU.H"
#include "MAPDRAW.H"
#include "CLOCK.H"
#include "CAMERA.H"

/* Redraw the whole equipment panel: the backdrop, the item the belt has turned
 * to, the eight carried things, the counts along the bottom rows and, where
 * one is set, the password that has been read. The goto is as shipped. */
INT c_draw_kit_panel(void)
{
    INT v0j;    /* the item, the count or the character being drawn */
    INT v1a;    /* which of the three counted rows */

    /* Start from the clean panel kept on the map page. */
    drv_jump_gfx_copy_rect(shd_map_page, 176, 0, 144, 100, shd_screen, 176, 0);
    /* Move the selected kind of trap on past any that has run out. */
    v1a = 0;
    while (asm_ammunition[asm_effect] <= 0) {
        v1a++;
        if (v1a >= 4)
            goto done;
        asm_effect++;
        if (asm_effect == 3)
            asm_effect = 0;
    }
done:
    /* Unless all three are out, highlight the selected kind's row. */
    if (v1a < 4)
        drv_real_fill_rect(shd_screen,
                          dat_kit_points[asm_effect + 8].x - 1,
                          dat_kit_points[asm_effect + 8].y - 1,
                          asm_ammunition[asm_effect] * 6 + 8,
                          15, 9);
    /* The carried items, bar the bugs, which are drawn as a count below. */
    for (v0j = 7; v0j >= 0; v0j--)
        if (((asm_kit & 1 << v0j) != 0
#ifdef TAC_PHOTOS_BY_DEFAULT
             /* the camera too when photos come without it */
             || (v0j == 2 && CAMERA_CARRIED(asm_kit, asm_mission_kind))
#endif
             ) && v0j != 3)
            drv_jump_gfx_sprite_put(shd_screen,
                              dat_kit_points[v0j].x,
                              dat_kit_points[v0j].y,
                              asm_kit_sprites[v0j]);
    /* With a camera, how many photos are left. */
    if (CAMERA_CARRIED(asm_kit, asm_mission_kind))
        c_clock_draw();
    /* A round for each left in the gun. */
    for (v0j = 0; v0j < (INT) asm_rounds_left; v0j++)
        drv_jump_gfx_sprite_put(shd_screen, v0j * 5 + dat_kit_points[11].x,
                          dat_kit_points[11].y, asm_kit_sprites[11]);
    /* A clip for each spare. */
    for (v0j = 0; v0j < (INT) asm_clips_left; v0j++)
        drv_jump_gfx_sprite_put(shd_screen, v0j * 13 + dat_kit_points[12].x,
                          dat_kit_points[12].y, asm_kit_sprites[12]);
    /* The bugs left, two to a row. */
    for (v0j = 0; v0j < (INT) asm_bugs_left; v0j++)
        drv_jump_gfx_sprite_put(shd_screen,
                          (v0j & 1) * 9 + dat_kit_points[3].x,
                          v0j / 2 * 7 + dat_kit_points[3].y,
                          asm_kit_sprites[3]);
    /* A mark for each wound, staggered up and down. */
    for (v0j = 0; v0j < asm_wounds; v0j++)
        drv_jump_gfx_sprite_put(shd_screen, v0j * 6 + 260,
                          (v0j & 1) * 10 + v0j + 63, asm_kit_sprites[13]);
    /* What is left of each of the three kinds of trap. */
    for (v1a = 0; v1a < 3; v1a++)
        for (v0j = 0;
             asm_ammunition[v1a] > v0j;
             v0j++)
            drv_jump_gfx_sprite_put(shd_screen,
                              v0j * 6
                              + dat_kit_points[v1a + 8].x,
                              dat_kit_points[v1a + 8].y,
                              asm_kit_sprites[v1a + 8]);
    /* Once any letter of the password has been given away, show the hint. */
    for (v0j = 0; (INT) strlen(asm_password_text) > v0j; v0j++)
        if (asm_password_hint[v0j] != '.') {
            drv_real_fill_rect(shd_screen, 248, 88, 64, 9, 10);
            c_outline_box(248, 88, 64, 9, 2);
            c_write_text_trimmed((drv_addr) asm_password_hint,
                            250, 89, 5);
            break;
        }
}
