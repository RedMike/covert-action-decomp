/* SEQ-RESET.C -- c_seq_reset, rewinding a sequence's script.
 */

/* Point the script reader at the start of the animation's code and empty its
 * stack and queue. `unused` is not read.
 */
void c_seq_reset(void)
{
    INT unused;

    SET_POINTER_START(shm_seq_pc, shm_anim_segment);
    shm_seq_depth = shm_seq_sound_queue_count = 0;
}
