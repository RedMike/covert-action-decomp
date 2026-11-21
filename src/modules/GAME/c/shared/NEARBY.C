/* NEARBY.C -- distances on the map, and whether a detour is worth making.
 */
#include "GAME.H"
#include "LINES.H"
#include "PLAUSIBL.H"

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
