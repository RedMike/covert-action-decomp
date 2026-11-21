/* NEAR-CAR.C -- finding a destination near a point.
 */
#include "CHASE.H"
#include "NEARCAR.H"
#include "RESULT.H"

/* Whether (x, y) is within six of a destination the city's bitmap marks, and
 * if so which; the answer goes in the shared block. `dist` is left over from
 * the previous turn where a destination is not marked, as shipped.
 */
INT c_near_destination(INT x, INT y)
{
    INT dist;
    INT hit;
    INT i;

    hit = 0;
    /* Only a building the player has been told about can be the one reached. */
    for (i = 1; i < 16; i++) {
        if (shm_cities[shm_case_city].known_orgs & 1 << i)
            dist = abs(x - asm_spot_x[i])
                 + abs(y - asm_spot_y[i]);
        if (dist > 6)
            continue;
        /* In a real city, the game goes on from the organisation reached. */
        if (asm_fresh_board != 0) {
            shm_case_org = (char) (COMM()->result[RES_CHASE_GOAL_ORG] = i);
        }
        hit = 1;
        break;
    }
    return hit;
}
