/* CLOCK.C -- the countdown in the corner of the board.
 */
#include "BUG.H"
#include "PRIMS.H"
#include "BOARD.H"

/* Redraw the clock from the seconds left, its digits written into the template
 * in place.
 */
void c_clock_draw(void)
{
    INT min;
    INT sec;
    INT hrs;
    INT rest;

    rest = asm_seconds_left;
    hrs = rest / 0xe10;
    rest -= 0xe10 * hrs;
    min = rest / 0x3c;
    rest -= 0x3c * min;
    sec = rest;
    dat_clock_text[0] = hrs / 10 + '0';
    dat_clock_text[1] = hrs % 10 + '0';
    dat_clock_text[3] = min / 10 + '0';
    dat_clock_text[4] = min % 10 + '0';
    dat_clock_text[6] = sec / 10 + '0';
    dat_clock_text[7] = sec % 10 + '0';
    drv_real_fill_rect(shd_screen, 0x100, 0xb8, 0x30, 9, 0);
    shd_screen->bg_pen = 0;
    c_write_text((rt_addr) dat_clock_text, 0x104, 0xb9, 7);
}
