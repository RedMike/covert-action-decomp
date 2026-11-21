/* DRAW-PRIMS.C -- the drawing calls the rest of the module goes through.
 *
 * Each is a wrapper over a driver entry point: it fixes the surface to the
 * screen and puts the arguments in the order the game thinks in.
 */
#include "FINAL.H"
#include "PRIMS.H"

/* shared_include_start: ../../../../shared/c/DRAW-LINE.C -- generated */
/* DRAW-LINE.C -- c_draw_line, drawing a line on the screen.
 */

/* Draw a line from (x1, y1) to (x2, y2) in `colour`. */
INT c_draw_line(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour)
{
    return drv_real_draw_line(shd_screen, x1, y1, x2, y2, colour);
}
/* shared_include_end: ../../../../shared/c/DRAW-LINE.C */

/* shared_include_start: ../../../../shared/c/TEXT-OUT.C -- generated */
/* TEXT-OUT.C -- c_write_text, writing text on the screen.
 */

/* Write `text` at (`across`, `down`) in `colour` and answer the width written.
 */
INT c_write_text(drv_addr text, INT across, INT down, UNSIGNED_INT colour)
{
    shd_screen->fg_pen = colour;
    return drv_jump_gfx_text(shd_screen, across, down, text);
}
/* shared_include_end: ../../../../shared/c/TEXT-OUT.C */

/* shared_include_start: ../../../../shared/c/WRITE-TEXT-TRIMMED.C -- generated */
/* WRITE-TEXT-TRIMMED.C -- c_write_text_trimmed, text without the extra rows.
 */

/* Write `text` with the screen's draw mode 0, so glyphs lose the font's extra
 * rows.
 */
INT c_write_text_trimmed(drv_addr text, INT across, INT down, UNSIGNED_INT colour)
{
    shd_screen->draw_mode = 0;
    c_write_text(text, across, down, colour);
    shd_screen->draw_mode = 1;
}
/* shared_include_end: ../../../../shared/c/WRITE-TEXT-TRIMMED.C */

/* shared_include_start: ../../../../shared/c/WAIT-RETRACES.C -- generated */
/* WAIT-RETRACES.C -- c_wait_retraces, waiting for vertical retraces.
 */

/* Wait `n` vertical retraces, by bit 3 of status port 3dah. `unused` is not
 * read.
 */
INT c_wait_retraces(INT n)
{
    INT unused;

    if (n != 0)
        while (n-- != 0) {
            while ((inp(0x3da) & 8) == 0)
                ;
            while ((inp(0x3da) & 8) != 0)
                ;
        }
}
/* shared_include_end: ../../../../shared/c/WAIT-RETRACES.C */

/* shared_include_start: ../../../../shared/c/SCREEN-SAVE.C -- generated */
/* SCREEN-SAVE.C -- c_screen_save, a whole-screen copy that copies nothing.
 */

/* Meant to copy the whole screen from page 0 to page 2, but the height of 0
 * copies nothing.
 */
void c_screen_save(void)
{
    drv_jump_gfx_copy_rect((struct RASTPORT *) 0, 0, 0, 2, 0, (struct RASTPORT *) 0, 0x13f, 0xc7);
}
/* shared_include_end: ../../../../shared/c/SCREEN-SAVE.C */

/* shared_include_start: ../../../../shared/c/SCREEN-RESTORE.C -- generated */
/* SCREEN-RESTORE.C -- c_screen_restore, a screen copy that copies nothing.
 */

void c_screen_restore(void)
{
    drv_jump_gfx_copy_rect((struct RASTPORT *) 2, 0, 0, 0, 0, (struct RASTPORT *) 0, 0x13f, 0xc7);
}
/* shared_include_end: ../../../../shared/c/SCREEN-RESTORE.C */

/* shared_include_start: ../../../../shared/c/FILL-BOX.C -- generated */
/* FILL-BOX.C -- c_fill_box, filling a rectangle given by its corners.
 */

/* Fill the box from (x1, y1) to (x2, y2), corners included, in `colour`. */
INT c_fill_box(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour)
{
    return drv_real_fill_rect(shd_screen, x1, y1, x2 - x1 + 1,
                             y2 - y1 + 1, colour);
}
/* shared_include_end: ../../../../shared/c/FILL-BOX.C */
