/* SCREEN-TEXT.C -- measuring and centring a string, and a page's text panel.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "SCREEN.H"

/* shared_include_start: ../../../../shared/c/TEXT-WIDTH.C -- generated */
/* TEXT-WIDTH.C -- c_text_width, how wide a string is in pixels.
 */

/* How many pixels `text` takes in the screen's font. */
INT c_text_width(rt_addr text)
{
    INT typeface;
    unsigned char *at;
    INT wide;

    at = (unsigned char *) text;
    typeface = shd_screen->font;
    wide = 0;
    while (*at != 0)
        wide += drv_jump_gfx_char_width(typeface, *at++);
    return wide;
}
/* shared_include_end: ../../../../shared/c/TEXT-WIDTH.C */

/* shared_include_start: ../../../../shared/c/TEXT-PANEL.C -- generated */
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
/* shared_include_end: ../../../../shared/c/TEXT-PANEL.C */

/* shared_include_start: ../../../../shared/c/DRAW-CENTRED.C -- generated */
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
/* shared_include_end: ../../../../shared/c/DRAW-CENTRED.C */
