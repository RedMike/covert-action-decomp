/* CLOCK-TEXT.C -- c_clock_text, a time of day as "hh:mm:ss".
 */

/* Write the time `seconds` after shm_clock_minutes, wrapped to a day, into the
 * template shd_clock_text and answer it.
 */
rt_addr c_clock_text(INT seconds)
{
    INT mins;
    INT rest;
    INT hour;
    INT secs;

    rest = (UNSIGNED_INT) (seconds / 60 + shm_clock_minutes) % 1440;
    hour = rest / 60;
    mins = rest % 60;
    secs = seconds % 60;
    shd_clock_text[0] = hour / 10 + '0';
    shd_clock_text[1] = hour % 10 + '0';
    shd_clock_text[3] = mins / 10 + '0';
    shd_clock_text[4] = mins % 10 + '0';
    shd_clock_text[6] = secs / 10 + '0';
    shd_clock_text[7] = secs % 10 + '0';
    return (rt_addr) shd_clock_text;
}