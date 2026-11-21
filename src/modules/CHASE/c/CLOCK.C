/* CLOCK.C -- the clock text, with a one-digit hour.
 */
#include "CHASE.H"
#include "CLOCK.H"

/* Format the clock as "H:MM:SS" and answer the string: `ticks` seconds after
 * shm_clock_minutes, wrapped to a day, the hour as its units digit.
 */
char *c_clock_text(INT ticks)
{
    INT mm;
    INT sec;
    INT hrs;
    INT day;

    day = (ticks / 60 + (INT) shm_clock_minutes) % 1440;
    hrs = day / 60;
    mm = day % 60;
    sec = ticks % 60;
    dat_clock_text[0] = hrs % 10 + '0';
    dat_clock_text[2] = mm / 10 + '0';
    dat_clock_text[3] = mm % 10 + '0';
    dat_clock_text[5] = sec / 10 + '0';
    dat_clock_text[6] = sec % 10 + '0';
    return dat_clock_text;
}
