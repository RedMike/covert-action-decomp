/* LEAD.C -- the building record for one organisation in one city.
 */
#include "BUG.H"
#include "REPORT.H"

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
