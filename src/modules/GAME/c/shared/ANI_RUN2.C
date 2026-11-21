/* ANI_RUN2.C -- starting a PAN animation, running it out, and stopping it.
 */
#include "GAME.H"
#include "MISC1.H"
#include "ANI_READ.H"
#include "ANI_RUN.H"
#include "ANI_RUN2.H"
#include "PACE.H"

/* shared_include_start: ../../../../shared/c/SEQ-INTERRUPTED.C -- generated */
/* SEQ-INTERRUPTED.C -- c_seq_interrupted, whether the player has interrupted.
 */

/* Answer 1 to stop the sequence on a key or joystick button after three
 * frames; where a stop was asked for, note it in sequence variable 6 and
 * answer 0. The c_menu_key call is unreachable, as shipped.
 */
INT c_seq_interrupted(void)
{
    if ((drv_jump_keyboard_empty() != 0
         && ((shm_options & OPT_JOYSTICK) == 0 || c_joystick_button(0) == 0))
        || shm_seq_frames_done < 3)
        return 0;
    if (drv_jump_keyboard_empty == 0)
        c_menu_key();
    if (shm_seq_stop_asked != 0) {
        shm_seq_stop_asked = 0;
        shm_seq_vars[6] = -1;
        return 0;
    }
    return 1;
}
/* shared_include_end: ../../../../shared/c/SEQ-INTERRUPTED.C */

/* shared_include_start: ../../../../shared/c/SEQ-RUN.C -- generated */
/* SEQ-RUN.C -- c_seq_run, running a sequence to its end.
 */

/* Start the sequence `block` describes, step it until it ends, and take it
 * down.
 */
INT c_seq_run(struct SEQ_BLOCK *block)
{
    c_seq_start(block);
    do {
    } while (c_seq_step() == 0);
    c_seq_stop();
}
/* shared_include_end: ../../../../shared/c/SEQ-RUN.C */

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
