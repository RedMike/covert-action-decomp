/* FRAME.C -- the page frame and its badge bar, the clock text and text widths.
 */
#include "GAME.H"
#include "SPRITES.H"
#include "FRAME.H"
#include "CMP_STRT.H"
#include "MISC1.H"

/* shared_include_start: ../../../../shared/c/PAGE-FRAME.C -- generated */
/* PAGE-FRAME.C -- c_page_frame, a full-screen page with a title.
 */

/* Frame the whole screen: a background in `colour` (always 2 on CGA), a
 * border, a white page, and `text` as a centred title.
 */
void c_page_frame(rt_addr text, INT colour)
{
    INT wide;

    shm_pan_width = 0x140;
    if (shm_cga != 0)
        colour = 2;
    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xa, 6);
    drv_real_fill_rect(shd_screen, 0, 0xa, 0x140, 0xbe, colour);
    shd_screen->bg_pen = colour;
    c_folder_header(0xa0, 2, colour);
    c_draw_line(0, 0, 0, 0xc7, 6);
    c_draw_line(0x13f, 0, 0x13f, 0xc7, 6);
    drv_real_fill_rect(shd_screen, 8, 0xe, 0x130, 0xba, 0xf);
    c_draw_line(0xa, 0xd, 0x138, 0xd, 7);
    c_draw_line(0x138, 0xd, 0x138, 0xc7, 8);
    wide = c_text_width(text);
    drv_real_fill_rect(shd_screen, 0xef - wide / 2, 3, wide + 2, 9, 7);
    c_write_text_trimmed(text, 0xf0 - wide / 2, 4, 0);
    shd_screen->bg_pen = 0xf;
}
/* shared_include_end: ../../../../shared/c/PAGE-FRAME.C */

/* shared_include_start: ../../../../shared/c/FOLDER-HEADER.C -- generated */
/* FOLDER-HEADER.C -- c_folder_header, drawing a folder tab and its rules.
 */

/* Draw the folder tab at (x, y) in `colour`, with a rule from its foot to each
 * screen edge.
 */
void c_folder_header(INT x, INT y, UNSIGNED_INT colour)
{
    drv_real_fill_rect(shd_screen, x + 0xa, y, 0x8c, 8, colour);
    if (y != 0)
        c_draw_line(x + 0xa, y - 1, x + 0x93, y - 1, 5);
    c_draw_line(0, y + 8, x, y + 8, 8);
    c_draw_line(x + 0x9e, y + 8, 0x13f, y + 8, 8);
    c_draw_sprite(SPRITE_FOLDER_START, x, y);
    c_draw_sprite(SPRITE_FOLDER_END, x + 0x93, y);
    drv_jump_gfx_fill(shd_screen, x, y, 0xa0, 8, 0xd, colour);
}
/* shared_include_end: ../../../../shared/c/FOLDER-HEADER.C */

/* shared_include_start: ../../../../shared/c/CLOCK-TEXT.C -- generated */
/* CLOCK-TEXT.C -- c_clock_text, a time of day as "hh:mm:ss".
 */

/* Write the time `seconds` after shm_clock_minutes, wrapped to a day, into the
 * template shd_clock_text and answer it.
 */
rt_addr c_clock_text(INT seconds)
{
    INT mins;
    INT rest;
    INT hour;
    INT secs;

    rest = (UNSIGNED_INT) (seconds / 60 + shm_clock_minutes) % 1440;
    hour = rest / 60;
    mins = rest % 60;
    secs = seconds % 60;
    shd_clock_text[0] = hour / 10 + '0';
    shd_clock_text[1] = hour % 10 + '0';
    shd_clock_text[3] = mins / 10 + '0';
    shd_clock_text[4] = mins % 10 + '0';
    shd_clock_text[6] = secs / 10 + '0';
    shd_clock_text[7] = secs % 10 + '0';
    return (rt_addr) shd_clock_text;
}
/* shared_include_end: ../../../../shared/c/CLOCK-TEXT.C */

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
