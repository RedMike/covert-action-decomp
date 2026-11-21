/* TEXT-OUT.C -- c_write_text, writing text on the screen.
 */

/* Write `text` at (`across`, `down`) in `colour` and answer the width written.
 */
INT c_write_text(drv_addr text, INT across, INT down, UNSIGNED_INT colour)
{
    shd_screen->fg_pen = colour;
    return drv_jump_gfx_text(shd_screen, across, down, text);
}