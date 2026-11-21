/* REDACT.C -- cutting a message down to the words the player has overheard.
 */
#include "GAME.H"
#include "LINES.H"

/* shared_include_start: ../../../../shared/c/FILTER-MESSAGE.C -- generated */
/* FILTER-MESSAGE.C -- c_filter_message, keeping only some words of a message.
 */

/* Keep only the words of shm_scratch whose bit in `mask`, counted modulo
 * `mod`, is set, with an ellipsis where words were dropped.
 */
void c_filter_message(INT mask, INT mod)
{
    INT from;
    char kept[512];
    INT keep;
    INT at;
    INT word;

    from = word = keep = 0;
    kept[0] = 0;
    for (at = 0; (INT) strlen(shm_scratch) > at; at++) {
        if ((shm_scratch)[at] == ' '
            || (shm_scratch)[at] == '\n') {
            if (mask & 1 << word % mod) {
                if (keep == 0)
                    from = at + 1;
                keep = 1;
            } else {
                if (keep != 0) {
                    (shm_scratch)[at] = 0;
                    strcat(kept,
                               shm_scratch + from);
                    (shm_scratch)[at] = ' ';
                    strcat(kept, shd_str_ellipsis_2);
                }
                keep = 0;
            }
            word++;
        }
    }
    if (keep != 0)
        strcat(kept, shm_scratch + from);
    strcpy(shm_scratch, kept);
}
/* shared_include_end: ../../../../shared/c/FILTER-MESSAGE.C */
