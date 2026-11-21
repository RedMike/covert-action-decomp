/* shared/CASE-2.C -- the shared routines in CASE.C's unit, after CASE-2.C. */
#include "GAME.H"
#include "SPRITES.H"
#include "CASE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "DIALOG.H"
#include "FRAME.H"
#include "BLOCK.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "SUSPECTS.H"
#include "PANEL.H"
#include "FACES.H"
#include "HANDOVER.H"
#include "TAG.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/BUILDING-EXPLORE.C -- generated */
/* BUILDING-EXPLORE.C -- c_building_explore, learning about a building.
 */

/* Find or make the building record for `org` in `city`, fold in
 * `identity_flags` and answer the record, or -1 if it is left with no flags.
 */
INT c_building_explore(INT org, INT city, UNSIGNED_INT identity_flags)
{
    INT cell;   /* the record being looked at */

    if (identity_flags != 0)
        shm_cities[city].known_orgs |= 1 << org;
    for (cell = 0; cell < shm_building_count; cell++) {
        if (shm_buildings[cell].org == org
            && shm_buildings[cell].city
                   == city) {
            if ((shm_buildings[cell].identity_flags
                    |= identity_flags) != 0)
                return cell;
            return -1;
        }
    }
    if (identity_flags == 0)
        return -1;
    shm_buildings[shm_building_count].org = org;
    shm_buildings[shm_building_count].city = city;
    shm_buildings[shm_building_count].identity_flags = identity_flags;
    shm_buildings[shm_building_count].wiretap_level = 0;
    shm_buildings[shm_building_count].tac_rooms_explored = 0;
    shm_building_count++;
    return shm_building_count - 1;
}
/* shared_include_end: ../../../../shared/c/BUILDING-EXPLORE.C */

/* shared_include_start: ../../../../shared/c/BUILDING-FORGET.C -- generated */
/* BUILDING-FORGET.C -- c_building_forget, forgetting a known building.
 */

/* Forget the building record for `org` in `city` and the city's known_orgs
 * bit; the record keeps its organisation and city.
 */
void c_building_forget(INT org, INT city)
{
    INT cell;   /* the record being looked at */

    for (cell = 0; cell < shm_building_count; cell++) {
        if (shm_buildings[cell].org == org
            && shm_buildings[cell].city
                   == city) {
            shm_buildings[cell].identity_flags = 0;
            shm_buildings[cell].tac_rooms_explored = 0;
            shm_buildings[cell].wiretap_level = 0;
            shm_cities[city].known_orgs &=
                ~(1 << org);
            break;
        }
    }
}
/* shared_include_end: ../../../../shared/c/BUILDING-FORGET.C */

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

