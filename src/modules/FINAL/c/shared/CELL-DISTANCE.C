/* CELL-DISTANCE.C -- map distances, and an organisation's presence in a city.
 *
 * Both distances are octagonal, the larger axis doubled plus the smaller: one
 * over coordinates packed a nibble each, one over a city's finer map position.
 */
#include "FINAL.H"
#include "SCREEN.H"

/* shared_include_start: ../../../../shared/c/WORTH-THE-TRIP.C -- generated */
/* WORTH-THE-TRIP.C -- c_worth_the_trip, whether a lead is worth the distance.
 */

/* Whether `other`'s presence in `city` beats the cost of getting there from
 * `org`.
 */
INT c_worth_the_trip(INT org, INT other, INT city)
{
    INT sum;

    sum = c_packed_distance(
              shm_orgs[org].where,
              shm_cities[city].where)
        + c_packed_distance(
              shm_orgs[org].where,
              shm_orgs[other].where) * 3 / 2;
    return c_presence(city, other) * 4 + 0x10 > sum;
}
/* shared_include_end: ../../../../shared/c/WORTH-THE-TRIP.C */

/* shared_include_start: ../../../../shared/c/PACKED-DISTANCE.C -- generated */
/* PACKED-DISTANCE.C -- c_packed_distance, the distance between two positions.
 */

/* The distance between two packed coordinates, a pair of nibbles each: the
 * larger difference doubled plus the smaller.
 */
INT c_packed_distance(INT a, INT b)
{
    INT dx;
    INT dy;

    dx = abs((a & 0xf) - (b & 0xf));
    dy = abs(((unsigned char) a & 0xf0) / 16
                 - ((unsigned char) b & 0xf0) / 16);
    if (dx > dy)
        return dx * 2 + dy;
    return dy * 2 + dx;
}
/* shared_include_end: ../../../../shared/c/PACKED-DISTANCE.C */

/* shared_include_start: ../../../../shared/c/CITY-DISTANCE.C -- generated */
/* CITY-DISTANCE.C -- c_city_distance, how far apart two cities are on the map.
 */

/* Answer how far apart cities `a` and `b` are on the map: twice the larger of
 * the two axis distances plus the smaller.
 */
INT c_city_distance(INT a, INT b)
{
    INT dx;
    INT dy;

    dx = abs(shm_cities[a].map_x
                 - shm_cities[b].map_x);
    dy = abs(shm_cities[a].map_y
                 - shm_cities[b].map_y);
    if (dx > dy)
        return dx * 2 + dy;
    return dy * 2 + dx;
}
/* shared_include_end: ../../../../shared/c/CITY-DISTANCE.C */

/* shared_include_start: ../../../../shared/c/SAY-PRESENCE.C -- generated */
/* SAY-PRESENCE.C -- c_say_presence, naming an organisation's presence.
 */

/* Append the word for `org`'s presence in `city` to shm_scratch and answer the
 * number behind it, 0 to 5. "active cel" is spelt that way in the data.
 */
INT c_say_presence(INT city, INT org)
{
    INT rank;

    rank = c_presence(city, org);
    if (rank == 1)
        strcat(shm_scratch, shd_str_hideout);
    if (rank == 2)
        strcat(shm_scratch, shd_str_agent);
    if (rank == 3)
        strcat(shm_scratch, shd_str_safehouse);
    if (rank == 4)
        strcat(shm_scratch, shd_str_active_cel);
    if (rank == 5)
        strcat(shm_scratch, shd_str_office);
    return rank;
}
/* shared_include_end: ../../../../shared/c/SAY-PRESENCE.C */

/* shared_include_start: ../../../../shared/c/PRESENCE.C -- generated */
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
/* shared_include_end: ../../../../shared/c/PRESENCE.C */
