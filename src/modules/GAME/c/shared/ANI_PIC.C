/* ANI_PIC.C -- setting the animation sequencer's current picture.
 *
 * It is `int`: its unit calls it ahead of its definition.
 */
#include "GAME.H"
#include "ANI_RUN2.H"

/* shared_include_start: ../../../../shared/c/SEQ-PICTURE.C -- generated */
/* SEQ-PICTURE.C -- c_seq_set_picture, choosing a sequence's picture.
 */

/* Set the sequence's current picture to `entry`. */
INT c_seq_set_picture(INT entry)
{
    shm_seq_picture = entry;
}
/* shared_include_end: ../../../../shared/c/SEQ-PICTURE.C */
