/* PAGE-FRAME.C -- c_page_frame, a full-screen page with a title.
 */

/* Frame the whole screen: a background in `colour` (always 2 on CGA), a
 * border, a white page, and `text` as a centred title.
 */
void c_page_frame(rt_addr text, INT colour)
{
    INT wide;

    shm_pan_width = 0x140;
    if (shm_cga != 0)
        colour = 2;
    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xa, 6);
    drv_real_fill_rect(shd_screen, 0, 0xa, 0x140, 0xbe, colour);
    shd_screen->bg_pen = colour;
    c_folder_header(0xa0, 2, colour);
    c_draw_line(0, 0, 0, 0xc7, 6);
    c_draw_line(0x13f, 0, 0x13f, 0xc7, 6);
    drv_real_fill_rect(shd_screen, 8, 0xe, 0x130, 0xba, 0xf);
    c_draw_line(0xa, 0xd, 0x138, 0xd, 7);
    c_draw_line(0x138, 0xd, 0x138, 0xc7, 8);
    wide = c_text_width(text);
    drv_real_fill_rect(shd_screen, 0xef - wide / 2, 3, wide + 2, 9, 7);
    c_write_text_trimmed(text, 0xf0 - wide / 2, 4, 0);
    shd_screen->bg_pen = 0xf;
}
