/* TEXT-OUT.C -- writing text, with and without the glyphs' extra rows.
 */
#include "CODE.H"

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
