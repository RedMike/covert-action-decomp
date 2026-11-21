/* SCRAMBLE.C -- the flourish played before a letter is given away.
 */
#include "CODE.H"
#include "SETUP.H"
#include "RANDOM.H"
#include "TEXTOUT.H"
#include "RETRACE.H"
#include "PUZZLE.H"

/* The flourish before a letter is given away: 200 random positions in the
 * text, each blanked and redrawn where it sits, 42 characters to a row.
 */
void c_hint_animate(void)
{
    INT cell;
    INT which;
    INT spot;
    INT key;
    INT step;

    /* Flicker the text at random, as if the workstation were working on it. */
    c_sound_command(46);
    shd_screen->font = 3;
    for (step = 0; step < 200; step++) {
        spot = c_random_below(strlen(shm_scratch));
        key = (char) shm_scratch[spot];
        if (key >= 'A' && key <= 'Z')
            key = (char) dat_cipher[key - 'A'];
        dat_one_char[0] = key;
        cell = spot % 42;
        which = spot / 42;
        drv_real_fill_rect(shd_screen, cell * 6 + 44, which * 16 + 16,
                          6, 6, 0);
        c_wait_retraces(2);
        c_write_text_trimmed(dat_one_char, cell * 6 + 44,
                           which * 16 + 16, 10);
    }
    shd_screen->font = 2;
}
