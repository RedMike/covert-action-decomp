/* TICK.C -- the board's clock.
 */
#include "BUG.H"
#include "PORTING.H"
#include "BOARD.H"

/* Run the board forward by `ticks` frames, each with its sound: every eighth
 * takes a second off the clock and redraws it, and the one that reaches zero
 * ends the round.
 */
void c_tick(INT ticks)
{
    INT num;

    for (num = 0; num < ticks; num++) {
        asm_frame_count++;
        if ((asm_frame_count & 7) == 0) {
            asm_seconds_left--;
            c_clock_draw();
            if (asm_seconds_left == 0)
                /* The clock running out is a pass the player sees. */
                c_board_step(UNSET_ARGS(LONG_LIT(1)));
        }
        c_set_palette_record(asm_frame_count & 3);
    }
}
