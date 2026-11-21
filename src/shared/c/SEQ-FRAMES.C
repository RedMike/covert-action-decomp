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
