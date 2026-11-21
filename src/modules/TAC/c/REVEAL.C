/* REVEAL.C -- turning one more letter of the password face up.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "CITY.H"
#include "MENU.H"
#include "REVEAL.H"

/* Turn one more letter of the password face up, picking at random until a
 * covered one comes up or ninety-nine tries are spent, then redraw the line. */
INT c_reveal_letter(void)
{
    INT v0j;    /* how many tries have been made */
    INT v1a;    /* which letter came up */

    /* Try letters at random, giving up after ninety-nine. */
    v0j = 0;
    do {
        v1a = c_random_below(strlen(asm_password_text));
        /* One still showing its dot is uncovered and ends the search; the space
         * test never matters, as c_pick_password takes only lower-case words. */
        if (asm_password_text[v1a] != ' '
            && asm_password_hint[v1a] == '.') {
            asm_password_hint[v1a] =
                asm_password_text[v1a];
            v0j = 99;
        }
        v0j++;
    } while (v0j < 99);
    /* Redraw the hint in its box on the kit panel, where c_draw_kit_panel puts it. */
    drv_real_fill_rect(shd_screen, 248, 88, 64, 9, 10);
    c_outline_box(248, 88, 64, 9, 2);
    c_write_text_trimmed((rt_addr) asm_password_hint,
                    250, 89, 5);
}
