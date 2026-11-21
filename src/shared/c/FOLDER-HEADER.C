/* FOLDER-HEADER.C -- c_folder_header, drawing a folder tab and its rules.
 */

/* Draw the folder tab at (x, y) in `colour`, with a rule from its foot to each
 * screen edge.
 */
void c_folder_header(INT x, INT y, UNSIGNED_INT colour)
{
    drv_real_fill_rect(shd_screen, x + 0xa, y, 0x8c, 8, colour);
    if (y != 0)
        c_draw_line(x + 0xa, y - 1, x + 0x93, y - 1, 5);
    c_draw_line(0, y + 8, x, y + 8, 8);
    c_draw_line(x + 0x9e, y + 8, 0x13f, y + 8, 8);
    c_draw_sprite(SPRITE_FOLDER_START, x, y);
    c_draw_sprite(SPRITE_FOLDER_END, x + 0x93, y);
    drv_jump_gfx_fill(shd_screen, x, y, 0xa0, 8, 0xd, colour);
}
