/* ANI_RUN.C -- one sequence's setup, its frames, and its teardown.
 */
#include "FINAL.H"
#include "ACTORS.H"
#include "SEQFRAME.H"
#include "ANIMLOAD.H"
#include "PRIMS.H"
#include "SEQUENCE.H"

/* shared_include_start: ../../../../shared/c/SEQ-START.C -- generated */
/* SEQ-START.C -- c_seq_start, starting an animation sequence.
 */

/* Start the sequence `block` describes and say whether its file opened. The
 * rate, origin and duration apply only when not -1.
 */
INT c_seq_start(struct SEQ_BLOCK *block)
{
    shm_seq_block = block;
    shm_seq_frames_done = 0;
    if (c_anim_open(block->name) == 0)
        return 0;
    c_seq_set_picture(shm_seq_block->picture);
    shm_seq_picture = shm_seq_block->picture;
    if (shm_seq_block->rate != 0xffff)
        shm_frame_ticks = shm_seq_block->rate;
    if (shm_seq_block->page_a != 0xffff) {
        shd_anim_page_2->origin_x = shm_seq_block->page_a;
        shd_anim_page->origin_x = shm_seq_block->page_a;
    }
    if (shm_seq_block->page_b != 0xffff) {
        shd_anim_page_2->origin_y = shm_seq_block->page_b;
        shd_anim_page->origin_y = shm_seq_block->page_b;
    }
    if (shm_seq_block->duration != 0xffff)
        shm_seq_frames_left = shm_seq_block->duration
                            * (shm_frame_ticks + 0x13) / shm_frame_ticks;
    else
        shm_seq_frames_left = 0xffff;
    c_seq_apply_palette();
    c_seq_restart();
    return 1;
}
/* shared_include_end: ../../../../shared/c/SEQ-START.C */

/* shared_include_start: ../../../../shared/c/SEQ-PICTURE.C -- generated */
/* SEQ-PICTURE.C -- c_seq_set_picture, choosing a sequence's picture.
 */

/* Set the sequence's current picture to `entry`. */
INT c_seq_set_picture(INT entry)
{
    shm_seq_picture = entry;
}
/* shared_include_end: ../../../../shared/c/SEQ-PICTURE.C */

/* shared_include_start: ../../../../shared/c/SEQ-STOP.C -- generated */
/* SEQ-STOP.C -- c_seq_stop, taking a sequence down.
 */

/* Take the sequence down: copy the shown page over the hidden one where two
 * are in use, then give the memory up. Only the first non-zero sprite handle
 * is freed, as shipped.
 */
INT c_seq_stop(void)
{
    INT i;

    shm_seq_picture = 0;
    if (drv_jump_gfx_capability(0) != 0 && shd_anim_page->page == 0) {
        drv_jump_gfx_copy_rect((struct RASTPORT *) drv_page_shown, 0, 0, 0x140, 0xc8, (struct RASTPORT *) drv_page_hidden, 0, 0);
        drv_jump_gfx_show_page(shd_anim_page->page);
        *(char *) shd_anim_page ^= 1;
    }
    _dos_freemem(shm_anim_segment);
    for (i = 0; i < 0xfa; i++)
        if (shm_anim_sprites[i] != 0) {
            _dos_freemem(shm_anim_sprites[i]);
            break;
        }
}
/* shared_include_end: ../../../../shared/c/SEQ-STOP.C */

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
