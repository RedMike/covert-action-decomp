/* CLUE-SHIFT.C -- closing the gap a spent clue leaves.
 */
#include "BUG.H"

/* shared_include_start: ../../../../shared/c/CLUE-CLOSE-GAP.C -- generated */
/* CLUE-CLOSE-GAP.C -- c_clue_close_gap, taking one clue out of the list.
 */

/* Slide the clue list down over the record at `from`, as far as the first free
 * record, whose role is -1.
 */
void c_clue_close_gap(INT from)
{
    INT slot;   /* the record being moved into */

    for (slot = from; slot < 0x4f; slot++) {
        memcpy((char *) &shm_clues_shown[slot],
                   (char *) &shm_clues_shown[slot + 1], 0xc);
        if (shm_clues_shown[slot].role == -1) {
            shm_clues_shown[slot].org = -1;
            shm_clues_shown[slot].city = -1;
            break;
        }
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-CLOSE-GAP.C */
