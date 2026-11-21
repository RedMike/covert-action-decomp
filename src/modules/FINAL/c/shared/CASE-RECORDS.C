/* CASE-RECORDS.C -- handing out, changing and taking back case records.
 *
 * Finding or making a suspect or building record is the same routine but for
 * how a fresh one is come by: a suspect is drawn at random, rejecting any in
 * use, and a building is handed out in order and never reused.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "CASERUN.H"

/* shared_include_start: ../../../../shared/c/SUSPECT-RESERVE.C -- generated */
/* SUSPECT-RESERVE.C -- c_suspect_reserve, finding or making a suspect record.
 */

/* Find the suspect record for `org` in `city` and OR `bits` into its roles, or
 * with nonzero `bits` make one; answer the record, or -1. The mastermind takes
 * slot 0.
 */
INT c_suspect_reserve(INT org, INT city, INT bits)
{
    INT cell;   /* the record being looked at, then the one chosen */

    for (cell = 0; cell < shm_suspect_count; cell++) {
        if (shm_suspects[cell].org == org
            && shm_suspects[cell].city
                   == city) {
            shm_suspects[cell].role |= bits;
            return cell;
        }
    }
    do {
        cell = c_random_below(0x40);
    } while (shm_suspects[cell].visuals != 0
             || cell == 0);
    if (org == shm_campaign.mastermind_org && city == shm_campaign.mastermind_city)
        cell = 0;
    if (bits != 0) {
        shm_suspects[cell].org = org;
        shm_suspects[cell].city = city;
        shm_suspects[cell].flags =
            cell != 0 ? 0 : shm_campaign.mastermind_flags;
        shm_suspects[cell].role = bits;
        shm_suspects[cell].role_known = 0;
        shm_suspects[cell].score = 0;
        if (cell != 0) {
            shm_suspects[cell].visuals =
                c_random_below(0x7ffe) + 1;
            if (c_random_below(3) == 0)
                shm_suspects[cell].visuals |= 1;
        } else {
            shm_suspects[cell].visuals =
                shm_campaign.mastermind_visuals;
        }
        shm_suspects[cell].alert_level = 0;
        return cell;
    }
    return -1;
}
/* shared_include_end: ../../../../shared/c/SUSPECT-RESERVE.C */
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
