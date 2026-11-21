/* FRAME-TIMER.C -- holding a frame on screen for as long as it is owed.
 *
 * One routine does both halves of a wait, alternating: one call sets the tick
 * the frame may end at, the next spins to it, giving up at midnight's wrap.
 */
#include "FINAL.H"
#include "SEQFRAME.H"

/* shared_include_start: ../../../../shared/c/HOLD-FRAME.C -- generated */
/* HOLD-FRAME.C -- c_hold_frame, pacing frames by the BIOS clock.
 */

/* Hold the frame rate steady: calls alternate between noting when the frame
 * should end, shm_frame_ticks ticks on, and waiting for it.
 */
void c_hold_frame(void)
{
    LONG now;

    if (shm_frame_toggle != 0) {
        _bios_timeofday(0, (rt_addr) &shm_frame_deadline);
        *(LONG *) &shm_frame_deadline += shm_frame_ticks;
    } else
        do {
            if (_bios_timeofday(0, (rt_addr) &now) != 0)
                break;
        } while (now < *(LONG *) &shm_frame_deadline);
    shm_frame_toggle ^= 1;
}
/* shared_include_end: ../../../../shared/c/HOLD-FRAME.C */
