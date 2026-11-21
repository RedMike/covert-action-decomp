/* TEXT-PANEL.C -- c_text_panel, the panel a page of text goes on.
 */

/* Draw the white panel a page of text goes on, 130h wide from (`x`, `y`) to
 * the bottom of the screen, with a bevel.
 */
void c_text_panel(INT x, INT y)
{
    drv_real_fill_rect(shd_screen, x, y, 0x130, 0xc8 - y, 0xf);
    c_draw_line(x + 1, y, x + 0x130, y, 7);
    c_draw_line(x + 0x130, y, x + 0x130, 0xc7, 8);
    c_draw_line(x, y + 1, x, 0xc7, 7);
}
