/* OUTLINE-BOX.C -- c_outline_box, outlining a box.
 */

/* Outline the `w` by `h` box at (`x`, `y`) in `colour`. */
INT c_outline_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour)
{
    c_draw_line(x, y, x + w, y, colour);
    c_draw_line(x, y + h, x + w, y + h, colour);
    c_draw_line(x + w, y, x + w, y + h, colour);
    return c_draw_line(x, y, x, y + h, colour);
}