/* PRESENCE.C -- c_presence, how strongly an organisation is present in a city.
 */

/* How big `org`'s presence in `city` is, 0 to 5, from the city's rank, the
 * organisation's strength and scale, and their distance. The mastermind's city
 * and org answer 1.
 */
INT c_presence(INT city, INT org)
{
    INT span;
    INT gap;
    INT rank;

    gap = c_packed_distance(
              shm_cities[city].where,
              shm_orgs[org].where);
    rank = (shm_cities[city].rank + 4)
           * shm_orgs[org].strength / (gap + 1);
    if (rank > 0) {
        span = rank * 0x3c
               / shm_orgs[org].scale + 10;
        rank = rank * 6
               / shm_orgs[org].scale + 1;
        if (rank > 5)
            rank = 5;
    }
    if (city == shm_campaign.mastermind_city && org == shm_campaign.mastermind_org)
        rank = 1;
    if (rank <= 0 && shm_difficulty == 0 && city == 1
        && shm_suspects[shm_crime_roles[0].suspect].org
           == org)
        rank = 1;
    return rank;
}
