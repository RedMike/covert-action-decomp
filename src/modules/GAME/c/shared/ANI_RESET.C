/* ANI_RESET.C -- starting an animation's byte-code over from its first byte.
 */
#include "GAME.H"
#include "ANI_OPS.H"

/* shared_include_start: ../../../../shared/c/SEQ-RESET.C -- generated */
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
/* shared_include_end: ../../../../shared/c/SEQ-RESET.C */
