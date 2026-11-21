/* CLOCK.C -- the elapsed-time clock on the puzzle screen.
 */
#include "CODE.H"
#include "TEXTOUT.H"
#include "CLOCK.H"

/* Carry the tick counter into the elapsed time and redraw it. `pad` and
 * `ticks` are never read.
 */
void c_clock_draw(UNSIGNED_INT ticks)
{
    INT num;
    INT pad;
    INT cur;

    /* Carry whole minutes out of the seconds. */
    shm_clock_minutes += asm_clock_seconds / 60;
    asm_clock_seconds = asm_clock_seconds % 60;
    /* Show it in the header as hours, minutes and seconds. */
    shd_screen->font = 2;
    cur = (INT) shm_clock_minutes / 60;
    shd_clock_text[0] = cur / 10 + '0';
    shd_clock_text[1] = cur % 10 + '0';
    num = (INT) shm_clock_minutes % 60;
    shd_clock_text[3] = num / 10 + '0';
    shd_clock_text[4] = num % 10 + '0';
    shd_clock_text[6] = asm_clock_seconds / 10 + '0';
    shd_clock_text[7] = asm_clock_seconds % 10 + '0';
    shd_screen->bg_pen = 10;
    c_write_text(shd_clock_text, 256, 1, 2);
}
