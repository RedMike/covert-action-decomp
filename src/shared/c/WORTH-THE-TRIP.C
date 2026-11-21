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
