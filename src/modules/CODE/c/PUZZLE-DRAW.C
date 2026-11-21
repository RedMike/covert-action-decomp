/* PUZZLE-DRAW.C -- drawing the puzzle screen and the letter counts.
 */
#include "CODE.H"
#include "TEXTOUT.H"
#include "RETRACE.H"
#include "BOXFILL.H"
#include "LINE.H"
#include "SETUP.H"
#include "PUZZLE.H"
#include "PLAY.H"

/* Draw the puzzle screen: the panel, the header with the case's three digits,
 * and the cipher in rows of 42 with the letter counts beside it; below
 * difficulty 1 some letters are given away. `used` is written and never read.
 */
void c_puzzle_draw(void)
{
    char heading[40];
    INT used;
    INT most;
    INT field;
    INT spot;
    INT row;
    INT i;
    INT k;
    INT second;
    INT n;

    /* Clear the screen, put up the header bar, and frame the letter column. */
    c_fill_box(0, 0, 320, 200, 0);
    c_fill_box(34, 0, 320, 8, 10);
    c_draw_line(1, 0, 31, 0, 2);
    c_draw_line(1, 199, 31, 199, 2);
    c_draw_line(0, 1, 0, 198, 2);
    c_draw_line(32, 1, 32, 198, 2);
    drv_real_fill_rect(shd_screen, 2, 2, 29, 4, 2);
    drv_real_fill_rect(shd_screen, 2, 194, 29, 4, 2);
    /* The header numbers the message with three digits taken from its text. */
    shd_screen->font = 2;
    strcpy(heading, dat_str_crypto_workstation_msg);
    heading[26] = (shm_scratch[13] & 7) + '0';
    heading[27] = (shm_scratch[21] & 7) + '1';
    heading[28] = (shm_scratch[7] & 7) + '2';
    c_write_text_trimmed(heading, 64, 1, 0);
    /* Count how often each cipher letter appears. */
    field = row = 0;
    shd_screen->font = 3;
    for (i = 0; (INT) strlen(shm_scratch) > i; i++) {
        n = (char) shm_scratch[i];
        if (n >= 'A' && n <= 'Z') {
            n = (char) dat_cipher[n - 'A'];
            asm_letter_count[n - 'A']++;
        }
    }
    /* Harder puzzles disguise the commonest letter: each cipher letter the text
     * leaves unused stands in for it at every other place it falls. */
    used = 0;
    if (asm_difficulty == 2 || asm_difficulty > 3) {
        used = 1;
        for (i = 0; i < asm_alphabet_size; i++)
            if (asm_letter_count[i] == 0) {
                most = 0;
                for (second = 0; second < asm_alphabet_size; second++)
                    if (most < asm_letter_count[second]) {
                        spot = second;
                        most = asm_letter_count[second];
                    }
                for (second = 0; second < asm_alphabet_size; second++)
                    if ((char) dat_cipher[second] == spot + 'A') {
                        n = (char) dat_plain[second];
                        break;
                    }
                for (second = 0; second < asm_alphabet_size; second++)
                    if ((char) dat_cipher[second] == i + 'A') {
                        k = second;
                        break;
                    }
                for (second = 0;
                     (INT) strlen(shm_scratch) > second; second++)
                    if ((char) shm_scratch[second] == n && (second & 1)) {
                        shm_scratch[second] = k + 'A';
                        asm_letter_count[i]++;
                        asm_letter_count[spot]--;
                        dat_plain[k] = n;
                        used = 0;
                    }
            }
    }
    /* The counts are written through the text's own buffer, so keep its start. */
    for (i = 0; i < 10; i++)
        heading[i] = shm_scratch[i];
    /* The alphabet down the left, every count at zero; note the commonest letter. */
    most = 0;
    for (i = 0; i < asm_alphabet_size; i++) {
        shd_screen->font = 3;
        dat_one_char[0] = i + 'A';
        c_write_text_trimmed(dat_one_char, 12, i * 7 + 9, 10);
        shd_screen->font = 2;
        c_write_text_trimmed(dat_str_zero, 20, i * 7 + 9, 10);
        if (most < asm_letter_count[i]) {
            most = asm_letter_count[i];
            spot = i;
        }
        asm_letter_count[i] = 0;
    }
    /* The screen holds eleven rows of forty-two. */
    if ((INT) strlen(shm_scratch) > 462)
        shm_scratch[462] = 0;
    /* Type the cipher out a character at a time, counting each letter as it comes. */
    for (i = 0; (INT) strlen(shm_scratch) > i; i++) {
        n = (char) shm_scratch[i];
        if (n >= 'A' && n <= '\\') {
            n = (char) dat_cipher[n - 'A'];
            shd_screen->font = 2;
            drv_real_fill_rect(shd_screen, 20, n * 7 - 446, 12, 7, 0);
            strcpy(shm_scratch, dat_str_blank);
            strcat(shm_scratch,
                       itoa(++asm_letter_count[n - 'A'], asm_count_digits, 10));
            c_write_text_trimmed(shm_scratch, 20, n * 7 - 446, 10);
            for (second = 0; second < 10; second++)
                shm_scratch[second] = heading[second];
        }
        dat_one_char[0] = n;
        shd_screen->font = 3;
        c_write_text_trimmed(dat_one_char, field * 6 + 44,
                           row * 16 + 16, 10);
        /* At a row's end, hyphenate a word that runs on and start the next row. */
        field++;
        if (field >= 42) {
            if ((char) shm_scratch[i] >= 'A'
                && (char) shm_scratch[i] <= 'Z'
                && (char) shm_scratch[i + 1] >= 'A'
                && (char) shm_scratch[i + 1] <= 'Z')
                c_write_text_trimmed(dat_str_dash, field * 6 + 44,
                                   row * 16 + 16, 10);
            field = 0;
            row++;
        }
        c_wait_retraces(2);
    }
    for (i = 0; i < 10; i++)
        shm_scratch[i] = heading[i];
    /* Easy puzzles start with the commonest letter given, and one more per level below 1. */
    if (asm_difficulty <= 0) {
        for (i = 0; i < asm_alphabet_size; i++)
            if ((char) dat_cipher[i] == spot + 'A') {
                dat_guess[spot] = i + 'A';
                asm_letter_known[spot] = 1;
            }
        for (second = asm_difficulty; second < 0; second++)
            c_give_letter();
        c_draw_guesses();
    }
}
