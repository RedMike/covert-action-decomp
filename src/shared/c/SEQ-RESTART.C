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
