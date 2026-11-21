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