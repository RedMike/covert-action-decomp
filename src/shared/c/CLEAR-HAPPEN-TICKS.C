/* CLEAR-HAPPEN-TICKS.C -- c_clear_happen_ticks, resetting every crime event.
 */

/* Mark every crime event as still to happen, a happen_tick of 999. `spare` is
 * unused, kept for the frame's size.
 */
void c_clear_happen_ticks(void)
{
    INT i;
    INT spare;

    for (i = 0; i < shm_crime_event_count; i++)
        shm_crime_events[i].happen_tick = 999;
}
