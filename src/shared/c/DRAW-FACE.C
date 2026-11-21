/* DRAW-FACE.C -- c_draw_face, drawing a face from its packed description.
 */

/* Draw the face packed into `flags` at (x, y): five sprites, one from each
 * group of eight in the bank bit 0 picks, then the overlay bits 2 and 3 pick.
 * Leaves shm_menu_face at -1.
 */
void c_draw_face(INT flags, INT x, INT y)
{
    if (flags & 1) {
        c_draw_sprite((flags & 2) * 2 + 0x48, x + 1, y + 1);
        c_draw_sprite((flags >> 4 & 7) + 0x40, x + 1, y + 1);
        c_draw_sprite((flags >> 7 & 7) + 0x38, x + 1, y + 1);
        c_draw_sprite((flags >> 10 & 7) + 0x30, x + 1, y + 1);
        c_draw_sprite((flags >> 13 & 7) + 0x28, x + 1, y + 1);
    } else {
        c_draw_sprite((flags & 2) * 2 + 0x20, x + 1, y + 1);
        c_draw_sprite((flags >> 4 & 7) + 0x18, x + 1, y + 1);
        c_draw_sprite((flags >> 7 & 7) + 0x10, x + 1, y + 1);
        c_draw_sprite((flags >> 10 & 7) + 8, x + 1, y + 1);
        c_draw_sprite(flags >> 13 & 7, x + 1, y + 1);
    }
    if (shm_graphics_letter != 'C') {
        switch (flags >> 2 & 3) {
        case 0:
            drv_jump_gfx_fill(shd_screen, x, y, 0x20, 0x23, 0xb, 0xe);
            break;
        case 1:
            drv_jump_gfx_fill(shd_screen, x, y, 0x20, 0x23, 0xb, 6);
            break;
        case 3:
            drv_jump_gfx_fill(shd_screen, x, y, 0x20, 0x23, 0xc, 6);
            /* fall through */
        case 2:
            drv_jump_gfx_fill(shd_screen, x, y, 0x20, 0x23, 0xb, 5);
            break;
        }
    }
    shm_menu_face = 0xffff;
}