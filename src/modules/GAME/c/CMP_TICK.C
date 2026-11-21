/* CMP_TICK.C -- running the campaign clock on, an hour at a time.
 */
#include "GAME.H"
#include "ADVICE.H"
#include "MISC1.H"

/* Run the clock on by `minutes`, an hour at a time, so that everything due in
 * between gets its turn. */
INT c_campaign_tick(INT minutes)
{
    /* No time to pass only redraws the status bar. */
    if (minutes == 0)
        c_hook_repaint();
    /* Whole hours, with a pause after each once the log has more than five entries. */
    while (minutes >= 60) {
        c_advance_clock(60, LONG_LIT(0));
        minutes -= 60;
        if (shm_log_count > 5)
            c_wait_retraces(30);
    }
    /* Whatever is left of an hour passes as half an hour. */
    if (minutes != 0)
        c_advance_clock(30, LONG_LIT(0));
}
