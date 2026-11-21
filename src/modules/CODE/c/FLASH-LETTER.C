/* FLASH-LETTER.C -- flashing a letter of the alphabet column.
 */
#include "CODE.H"
#include "TEXTOUT.H"
#include "RETRACE.H"
#include "CLOCK.H"
#include "SOLVED.H"

/* Flash one letter of the alphabet column until a key is hit. */
void c_flash_letter(INT letter)
{
    /* Blink the letter chosen until the guess for it comes, the clock still running. */
    dat_one_char[0] = letter + 'A';
    do {
        asm_clock_seconds++;
        c_clock_draw(asm_clock_seconds);
        shd_screen->font = 3;
        shd_screen->bg_pen = 14;
        drv_real_fill_rect(shd_screen, 12, letter * 7 + 9, 6, 6, 0);
        c_wait_retraces(5);
        c_write_text_trimmed(dat_one_char, 12, letter * 7 + 9, 10);
        shd_screen->font = 2;
        c_wait_retraces(5);
    } while (kbhit() == 0);
}
