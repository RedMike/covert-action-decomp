/* MENU-BOX.C -- the filled box and the plain box a menu is drawn in.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "MENUS.H"

/* shared_include_start: ../../../../shared/c/MENU-BOX.C -- generated */
/* MENU-BOX.C -- c_menu_box, a filled box with a contrasting outline.
 */

/* Fill a box and outline it in `colour ^ 8`, or 7 for black and 0dh. The
 * background pen is left at the box's colour.
 */
INT c_menu_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour)
{
    c_fill_box(x, y, x + w, y + h, colour);
    shd_screen->bg_pen = colour;
    colour ^= 8;
    if (colour == 0)
        colour = 7;
    if (colour == 0xd)
        colour = 7;
    return c_outline_box(x, y, w, h, colour);
}
/* shared_include_end: ../../../../shared/c/MENU-BOX.C */

/* shared_include_start: ../../../../shared/c/OUTLINE-BOX.C -- generated */
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
/* shared_include_end: ../../../../shared/c/OUTLINE-BOX.C */
