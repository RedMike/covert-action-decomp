/* CMP_INIT.C -- waiting, with the campaign clock run on until interrupted.
 */
#include "GAME.H"
#include "ADVICE.H"
#include "DECODE.H"

/* Run the clock on an hour at a time until something ends the wait or a key
 * is pressed. */
INT c_wait_it_out(void)
{
    /* The clock runs on by itself while the agent waits. */
    asm_auto_waiting = 1;
    /* Until something happens that ends the campaign loop. */
    while (shm_finished == 0) {
        /* A key ends the wait. */
        if (kbhit() != 0)
            break;
        /* Another hour passes. */
        c_advance_clock(60, LONG_LIT(0));
    }
    asm_auto_waiting = 0;
}
