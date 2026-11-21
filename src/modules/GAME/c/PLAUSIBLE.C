/* PLAUSIBLE.C -- how strongly an organisation is present in a city.
 */
#include "GAME.H"
#include "LINES.H"
#include "PLAUSIBL.H"

/* How strongly organisation `city` is present in city `who` (the names are
 * swapped), from 0 to 5: the city's rank plus four, times the organisation's
 * strength, over their distance apart and against the organisation's scale.
 * `at` is unread.
 */
INT c_presence(INT who, INT city)
{
    INT at;
    INT legs;
    INT rank;

    /* A bigger city and a stronger organisation make for more presence, distance for less. */
    legs = c_packed_distance(shm_cities[who].where,
                           shm_orgs[city].where);
    rank = (shm_cities[who].rank + 4)
           * shm_orgs[city].strength / (legs + 1);
    /* Any presence at all comes out as 1 to 5 against the organisation's scale. */
    if (rank > 0) {
        at = 60 * rank
             / shm_orgs[city].scale + 10;
        rank = 6 * rank
               / shm_orgs[city].scale + 1;
        if (rank > 5)
            rank = 5;
    }
    /* The mastermind's own city and organisation is only ever a hideout. */
    if (who == shm_campaign.mastermind_city && city == shm_campaign.mastermind_org)
        rank = 1;
    /* On the easiest level, the first role's organisation has at least a hideout in city 1. */
    if (rank <= 0 && shm_difficulty == 0 && who == 1
        && shm_suspects[shm_crime_roles[0].suspect].org == city)
        rank = 1;
    return rank;
}
