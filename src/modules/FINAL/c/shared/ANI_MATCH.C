/* ANI_MATCH.C -- finding the palette entry a colour triple already has.
 *
 * The triple after the buffer's first 257 is looked for among them, and its
 * index, 101h when absent, is set as the border colour.
 */
#include "FINAL.H"
#include "BIOSMODE.H"

/* shared_include_start: ../../../../shared/c/MATCH-COLOUR.C -- generated */
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
/* shared_include_end: ../../../../shared/c/MATCH-COLOUR.C */
