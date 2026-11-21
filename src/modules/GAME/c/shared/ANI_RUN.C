/* ANI_RUN.C -- stepping a PAN animation a frame at a time.
 *
 * Nothing here is a menu: a menu draws over the still frame one leaves behind.
 */
#include "GAME.H"
#include "ANI_RUN.H"
#include "MISC1.H"
#include "ANI_OPS.H"
#include "ANI_RUN2.H"
#include "PACE.H"

/* shared_include_start: ../../../../shared/c/SEQ-STEP.C -- generated */
/* SEQ-STEP.C -- c_seq_step, advancing a sequence by one frame.
 */

/* Advance the sequence by one frame and say what next: 0 carry on, 1 finished,
 * its script ended or its frame count run out, and -1 interrupted.
 */
INT c_seq_step(void)
{
    INT r;

    if (c_seq_interrupted() != 0)
        return -1;
    shm_seq_frames_done++;
    c_hold_frame();
    r = c_seq_frames(1);
    c_hold_frame();
    if (--shm_seq_frames_left == 0)
        r = 1;
    return r;
}
/* shared_include_end: ../../../../shared/c/SEQ-STEP.C */

/* shared_include_start: ../../../../shared/c/SEQ-RESTART.C -- generated */
/* SEQ-RESTART.C -- c_seq_restart, putting a sequence back to its start.
 */

/* Put the sequence back to where a fresh one starts: script, actors, counters,
 * and page 1 as the page drawn on.
 */
void c_seq_restart(void)
{
    c_seq_reset();
    c_actor_clear_all();
    drv_real_anim_reset();
    shm_frames_owed = 2;
    shm_seq_done = 0;
    shm_seq_ticks = shm_seq_wait = 0;
    shd_anim_page->page = 1;
}
/* shared_include_end: ../../../../shared/c/SEQ-RESTART.C */

/* shared_include_start: ../../../../shared/c/SEQ-FRAMES.C -- generated */
/* SEQ-FRAMES.C -- c_seq_frames, running and showing a sequence's frames.
 */

/* Run the script and actors for `frames` frames, then show what was drawn;
 * answer 1 if the script ended on the way.
 */
INT c_seq_frames(INT frames)
{
    while (frames-- != 0) {
        c_actor_clear_hidden();
        if (c_seq_code() != 0)
            return 1;
        c_actor_step_all();
        c_actor_draw_hidden();
        shm_seq_ticks++;
    }
    c_seq_prepare_pages();
    c_actor_draw_all();
    c_seq_drain_queue();
    drv_jump_gfx_show_page(shd_anim_page->page);
    c_wait_retraces(1);
    if (drv_jump_gfx_capability(0) != 0)
        *(char *) shd_anim_page ^= 1;
    return 0;
}
/* shared_include_end: ../../../../shared/c/SEQ-FRAMES.C */
