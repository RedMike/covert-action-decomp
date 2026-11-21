/* TEXT-LAYOUT.C -- laying the scratch text buffer out as lines.
 *
 * Wrapping it, drawing it, and cutting it down to the words a mask keeps.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "SCREEN.H"

/* shared_include_start: ../../../../shared/c/WRAP-MESSAGE.C -- generated */
/* WRAP-MESSAGE.C -- c_wrap_message, wrapping text into lines.
 */

/* Wrap shm_scratch at the first space past `width` characters on each line. A
 * '^' forces a break.
 */
void c_wrap_message(INT width)
{
    INT run;
    INT i;

    run = 0;
    for (i = 0; (INT) strlen(shm_scratch) > i; i++) {
        if ((shm_scratch)[i] == '^') {
            (shm_scratch)[i] = ' ';
            (shm_scratch)[i + 1] = '\n';
            run = -1;
        }
        if ((shm_scratch)[i] == '\n')
            run = -1;
        run++;
        if (run > width && (shm_scratch)[i] == ' '
            && (shm_scratch)[i + 1] != ' ') {
            (shm_scratch)[i] = '\n';
            run = 0;
        }
    }
    if (run > 0)
        strcat(shm_scratch, shd_str_newline_wrap);
}
/* shared_include_end: ../../../../shared/c/WRAP-MESSAGE.C */

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

/* shared_include_start: ../../../../shared/c/FILTER-MESSAGE.C -- generated */
/* FILTER-MESSAGE.C -- c_filter_message, keeping only some words of a message.
 */

/* Keep only the words of shm_scratch whose bit in `mask`, counted modulo
 * `mod`, is set, with an ellipsis where words were dropped.
 */
void c_filter_message(INT mask, INT mod)
{
    INT from;
    char kept[512];
    INT keep;
    INT at;
    INT word;

    from = word = keep = 0;
    kept[0] = 0;
    for (at = 0; (INT) strlen(shm_scratch) > at; at++) {
        if ((shm_scratch)[at] == ' '
            || (shm_scratch)[at] == '\n') {
            if (mask & 1 << word % mod) {
                if (keep == 0)
                    from = at + 1;
                keep = 1;
            } else {
                if (keep != 0) {
                    (shm_scratch)[at] = 0;
                    strcat(kept,
                               shm_scratch + from);
                    (shm_scratch)[at] = ' ';
                    strcat(kept, shd_str_ellipsis_2);
                }
                keep = 0;
            }
            word++;
        }
    }
    if (keep != 0)
        strcat(kept, shm_scratch + from);
    strcpy(shm_scratch, kept);
}
/* shared_include_end: ../../../../shared/c/FILTER-MESSAGE.C */
