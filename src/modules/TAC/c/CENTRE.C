/* CENTRE.C -- writing a line centred in the top strip.
 */
#include "TAC.H"
#include "CITY.H"
#include "CENTRE.H"

/* Clear the strip along the top and write one line centred in it. */
INT c_write_centred(rt_addr text)
{
    /* Wipe the strip so no earlier line shows through. */
    c_fill_box(27, 10, 168, 17, 1);
    /* Centre on x 100, at six pixels a character. */
    c_write_text_trimmed(text, 100 - (INT) strlen(text) * 3, 10, 15);
}
