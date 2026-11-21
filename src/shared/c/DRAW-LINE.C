/* DRAW-LINE.C -- c_draw_line, drawing a line on the screen.
 */

/* Draw a line from (x1, y1) to (x2, y2) in `colour`. */
INT c_draw_line(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour)
{
    return drv_real_draw_line(shd_screen, x1, y1, x2, y2, colour);
}