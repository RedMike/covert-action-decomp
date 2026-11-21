/* CLUE-KIND.C -- the line a clue's own word stands for.
 */
#include "BUG.H"
#include "REPORT.H"

/* shared_include_start: ../../../../shared/c/CLUE-THING.C -- generated */
/* CLUE-THING.C -- c_clue_thing, naming the object a clue is about.
 */

/* Append the thing the clue word `about` names, unless it is -1: its name from
 * shd_clue_kinds and its number. Types 5 and 6 are money, in hundreds and
 * thousands.
 */
void c_clue_thing(INT about)
{
    if (about != -1) {
        strcat(shm_scratch,
                   (char *) ((rt_addr (*)[8]) &shd_clue_kinds[16])
                   [(about >> 8) & 0xf][(about >> 4) & 7]);
        strcat(shm_scratch,
                   (char *) itoa((about & 0x3f) + 1, shm_clue_digits, 10));
        if (((about >> 8) & 0xf) == 5)
            strcat(shm_scratch, shd_str_00);
        if (((about >> 8) & 0xf) == 6)
            strcat(shm_scratch, shd_str_000);
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-THING.C */
