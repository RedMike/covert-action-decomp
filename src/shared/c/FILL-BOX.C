/* FILL-BOX.C -- c_fill_box, filling a rectangle given by its corners.
 */

/* Fill the box from (x1, y1) to (x2, y2), corners included, in `colour`. */
INT c_fill_box(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour)
{
    return drv_real_fill_rect(shd_screen, x1, y1, x2 - x1 + 1,
                             y2 - y1 + 1, colour);
}