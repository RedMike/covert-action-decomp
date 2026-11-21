/* PANEL.C -- a filled box with a contrasting outline.
 */
#include "CODE.H"
#include "BOXFILL.H"
#include "BOXES.H"
#include "PANEL.H"

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
