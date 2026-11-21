/* FACE-PANEL.C -- c_draw_face_panel, a framed portrait with its shoulders.
 */

/* Draw the framed portrait of face `flags` at (x, y): frame, face and
 * shoulders. The casts on `x + 3` and `y + 3` keep the code as shipped.
 */
void c_draw_face_panel(INT flags, INT x, INT y)
{
    INT spare;

    drv_jump_gfx_set_colour_map(&shd_colours_face, &shd_colours_face);
    drv_real_fill_rect(shd_screen, x - 2, y - 2, 0x36, 0x38, 7);
    drv_real_fill_rect(shd_screen, x - 1, y - 1, 0x34, 0x36, 0xf);
    drv_real_fill_rect(shd_screen, x + 2, y + 2, 0x2e, 0x2d, 0);
    drv_real_fill_rect(shd_screen, (UNSIGNED_INT) x + 3,
                      (UNSIGNED_INT) y + 3, 0x2c, 0x2b,
                      (flags >> 2 & 3) == 3 && shm_graphics_letter != 'C'
                      ? 7 : 3);
    c_draw_face(flags, x + 0xd, y + 3);
    if (shm_graphics_letter != 'C') {
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 8, 5);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 0xc, 7);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 0xe, 0xf);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 6, 8);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 4, 8);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 1, 8);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 10, 7);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 9, 7);
    }
    c_draw_sprite((flags & 1 ? SPRITE_BODIES_1 : SPRITE_BODIES_0) + (flags & 3), x + 3, y + 0x1c);
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
}
