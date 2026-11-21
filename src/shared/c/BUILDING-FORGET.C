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
