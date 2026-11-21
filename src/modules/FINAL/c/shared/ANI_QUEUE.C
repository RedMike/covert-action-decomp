/* ANI_QUEUE.C -- playing the sound commands a sequence queued.
 *
 * All of the sequencer's far data is reached through `shm_seq_data`, one
 * structure: the module names one far object and no more.
 */
#include "FINAL.H"
#include "SEQUENCE.H"
#include "ACTORS.H"

/* Declared far here rather than in FINAL.H. */
extern struct SEQ FAR shm_seq_data;

/* shared_include_start: ../../../../shared/c/SEQ-DRAIN.C -- generated */
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
/* shared_include_end: ../../../../shared/c/SEQ-DRAIN.C */
