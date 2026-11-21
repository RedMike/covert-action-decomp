/* CHIP-PICK.C -- choosing which fact a chip gives up.
 */
#include "BUG.H"
#include "PRIMS.H"
#include "REPORT.H"

/* shared_include_start: ../../../../shared/c/CELL-REVEAL.C -- generated */
/* CELL-REVEAL.C -- c_cell_reveal, turning up a new fact about a crime role.
 */

/* File a random fact crime role `chip` has not yet given as a clue from
 * organisation `a` in city `b`; answer 0 if all five are known.
 */
INT c_cell_reveal(INT chip, INT a, INT b)
{
    UNSIGNED_INT chosen;   /* the bit for the fact rolled */

    if ((shm_crime_roles[chip].clues_known & 0x1f) != 0x1f) {
        do {
            chosen = 1 << c_random_below(5);
            if (shm_difficulty == 0
                && (shm_crime_roles[chip].clues_known & 0x10) == 0)
                chosen = 0x10;
            if (shm_crime_roles[chip].clue_type == 2
                && shm_difficulty < 2
                && (shm_crime_roles[chip].clues_known & 8) == 0)
                chosen = 8;
        } while ((shm_crime_roles[chip].clues_known
                  & chosen) != 0);
        c_clue_record(a, b, chip, chosen);
        return 1;
    }
    return 0;
}
/* shared_include_end: ../../../../shared/c/CELL-REVEAL.C */
