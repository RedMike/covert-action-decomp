/* LINES.C -- drawing the message buffer as wrapped lines of text.
 */
#include "GAME.H"
#include "MISC1.H"
#include "LINES.H"

/* shared_include_start: ../../../../shared/c/DRAW-MESSAGE.C -- generated */
/* DRAW-MESSAGE.C -- c_draw_message, drawing shm_scratch word-wrapped.
 */

/* Draw shm_scratch from (x, y), wrapped into lines of at most `width` * 8
 * pixels; answer the y the next line would start at. Text past y = 0c0h is
 * left out.
 */
INT c_draw_message(INT width, UNSIGNED_INT x, INT y, UNSIGNED_INT colour)
{
    INT saved;
    INT wide;
    INT space;
    INT start;
    INT n;

    for (n = wide = start = space = 0; (INT) strlen(shm_scratch) > n;
         n++) {
        wide += drv_jump_gfx_char_width(shd_screen->font,
                                  ((char *) shm_scratch)[n]);
        if ((shm_scratch)[n] == ' ' || (shm_scratch)[n] == '\n')
            space = n;
        if ((shm_scratch)[n] == '\n' || width * 8 < wide) {
            saved = ((char *) shm_scratch)[space];
            (shm_scratch)[space] = 0;
            c_write_text_trimmed((rt_addr) shm_scratch + start, x, y,
                               colour);
            (shm_scratch)[space] = saved;
            y += 8;
            wide = 0;
            start = space + 1;
            n = space;
            if (y >= 0xc0)
                break;
        }
    }
    if (wide > 0 && y < 0xc0) {
        c_write_text_trimmed((rt_addr) shm_scratch + start, x, y,
                           colour);
        y += 8;
    }
    return y;
}
/* shared_include_end: ../../../../shared/c/DRAW-MESSAGE.C */
