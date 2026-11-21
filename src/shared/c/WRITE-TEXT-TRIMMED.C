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