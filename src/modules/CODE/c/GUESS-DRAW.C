/* GUESS-DRAW.C -- redrawing the guesses and the text under the cipher.
 */
#include "CODE.H"
#include "TEXTOUT.H"
#include "RETRACE.H"
#include "PLAY.H"

/* Redraw the guess column and the plaintext row under the cipher. `padd` is
 * never read.
 */
void c_draw_guesses(void)
{
    INT cell;
    INT which;
    INT spot;
    INT padd;
    INT read;

    /* Beside each cipher letter in the column, the player's guess for it. */
    shd_screen->bg_pen = 0;
    for (spot = 0; spot < asm_alphabet_size; spot++) {
        dat_one_char[0] = dat_guess[spot];
        c_write_text(dat_one_char, 4, spot * 7 + 9, 11);
    }
    /* Then the whole text again: each cipher character, and the guess for it beneath. */
    cell = which = 0;
    shd_screen->bg_pen = 0;
    spot = 0;
    for (; (INT) strlen(shm_scratch) > spot; spot++) {
        read = (char) shm_scratch[spot];
        if (read >= 'A' && read <= '\\')
            read = (char) dat_cipher[read - 'A'];
        dat_one_char[0] = read;
        shd_screen->font = 3;
        drv_real_fill_rect(shd_screen, cell * 6 + 44,
                          which * 16 + 16, 6, 7, 0);
        c_wait_retraces(0);
        c_write_text_trimmed(dat_one_char, cell * 6 + 44,
                           which * 16 + 16, 10);
        shd_screen->font = 2;
        if ((char) shm_scratch[spot] >= 'A'
            && (char) shm_scratch[spot] <= '\\') {
            read = (char) dat_guess[read - 'A'];
            dat_one_char[0] = read;
        }
        c_write_text(dat_one_char, cell * 6 + 44,
                           which * 16 + 23, 11);
        cell++;
        if (cell >= 42) {
            cell = 0;
            which++;
        }
    }
}
