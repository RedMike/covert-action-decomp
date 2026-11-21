/* CLOCK.C -- writing the campaign clock out as a timestamp.
 *
 * The day's digits are stamped over the " 10" placeholder the strcat appends.
 */
#include "GAME.H"
#include "ADVICE.H"

/* Write the clock as "HH:MM AM Mon DD" into the timestamp buffer, set the
 * current minute, hour and day from it, and hand the buffer back. */
rt_addr c_timestamp(UNSIGNED_INT minutes)
{
    INT v0j;    /* the hour on a twelve-hour clock */

    /* The minutes past the hour, as two digits. */
    asm_stamp_minute = minutes % 60;
    asm_TIMESTAMP[3] = (INT) asm_stamp_minute / 10 + '0';
    asm_TIMESTAMP[4] = (INT) asm_stamp_minute % 10 + '0';
    /* The hour of the day, shown on a twelve-hour clock from 1 to 12. */
    minutes /= 60;
    asm_hour = minutes % 24;
    v0j = (asm_hour + 11) % 12 + 1;
    asm_TIMESTAMP[0] = v0j / 10 + '0';
    asm_TIMESTAMP[1] = v0j % 10 + '0';
    /* AM or PM. */
    asm_TIMESTAMP[6] = asm_hour > 11 ? 'P' : 'A';
    /* The month is the case's: one case a month from January 1990. */
    strcpy(&asm_TIMESTAMP[9],
               shd_month_names[shm_campaign.cases % 12]);
    strcat(asm_TIMESTAMP, dat_str_day_slot);
    /* The day, counted from 1, as two digits. */
    asm_day = minutes / 24 + 1;
    asm_TIMESTAMP[13] = (INT) asm_day / 10 + '0';
    asm_TIMESTAMP[14] = (INT) asm_day % 10 + '0';
    return (rt_addr) asm_TIMESTAMP;
}
