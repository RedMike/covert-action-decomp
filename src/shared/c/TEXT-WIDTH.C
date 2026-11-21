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
