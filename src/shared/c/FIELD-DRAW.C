/* FIELD-DRAW.C -- c_text_field_draw, redrawing a text entry field.
 */

/* Redraw the `n`-cell text field at (x, y) from shm_scratch, keeping the x and
 * width of the character at the cursor.
 */
void c_text_field_draw(INT x, UNSIGNED_INT y, INT n)
{
    INT i;
    INT ch;

    x += 2;
    y += 2;
    for (i = 0; i < n; i++) {
        drv_real_fill_rect(shd_screen, x, y, 8, 8, 5);
        if ((INT) strlen(shm_scratch) > i) {
            ch = ((char *) shm_scratch)[i + 1];
            ((char *) shm_scratch)[i + 1] = 0;
            c_write_text((drv_addr) (shm_scratch + i),
                               x, y, 0xa);
            ((char *) shm_scratch)[i + 1] = ch;
            if (i == shm_field_cursor) {
                shm_field_cursor_x = x;
                shm_field_char_width = drv_jump_gfx_char_width(
                    1, ((char *) shm_scratch)[i]);
            }
            x += drv_jump_gfx_char_width(1, ((char *) shm_scratch)[i]);
        }
    }
}
