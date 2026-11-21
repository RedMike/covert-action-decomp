/* DRAW-CENTRED.C -- c_draw_centred, drawing text centred on a point.
 */

/* Draw `text` centred on `x`, with draw_mode cleared for the call so no
 * background is painted.
 */
void c_draw_centred(str_addr text, INT x, INT y, UNSIGNED_INT colour)
{
    x -= c_text_width((rt_addr) text) / 2;
    shd_screen->draw_mode = 0;
    c_write_text((drv_addr) text, x, y, colour);
    shd_screen->draw_mode = 1;
}
