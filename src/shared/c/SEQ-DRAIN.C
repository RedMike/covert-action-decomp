/* SEQ-DRAIN.C -- c_seq_drain_queue, passing a sequence's queued sounds on.
 */

INT c_seq_drain_queue(void)
{
    if (shm_seq_sound_queue_count != 0)
        while (shm_seq_sound_queue_count != 0) {
            shm_seq_sound_queue_count--;
            c_seq_sound(shm_seq_data.queue[shm_seq_sound_queue_count]);
        }
}
