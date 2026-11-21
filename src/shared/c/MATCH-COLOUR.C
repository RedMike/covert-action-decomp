/* MATCH-COLOUR.C -- c_palette_match, finding the palette entry for a colour.
 */

INT c_palette_match(char *buf)
{
    INT i;

    for (i = 0; i < 0x101; i++)
        if (memcmp(buf + 0x303, buf + i * 3, 3) == 0)
            break;
    return c_set_border_colour(i);
}
