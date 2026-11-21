/* CHASE-START.C -- putting the cars on the road.
 */
#include "CHASE.H"
#include "CHASESTA.H"

/* Put the cars on the road: asm_suspicion_scale, car 0 at the start facing
 * towards the destination, and cars 1 and 2 strung out behind it.
 *
 * `lead` and `spare` are never read.
 */
void c_chase_start(void)
{
    INT lead;
    INT i;
    INT spare;

    asm_suspicion_scale = 1000 / (shm_difficulty + 3);
    asm_suspicion_scale = 10 * asm_suspicion_scale
                        / ((INT) asm_org_alert_level + 100) * 10;
    asm_outcome = 0;
    asm_cars[0].x = asm_spot_x[asm_start_spot];
    asm_cars[0].y = asm_spot_y[asm_start_spot];
    asm_cars[0].facing = (INT) asm_spot_y[asm_goal_spot]
                        < asm_cars[0].y ? 0 : 2;
    asm_cars[0].from_x = asm_cars[0].x;
    asm_cars[0].from_y = asm_cars[0].y;
    asm_cars[0].goal = -1;
    asm_cars[0].suspicion = 0;
    asm_cars[0].spec = 0;
    asm_cars[0].gear = 2;

    i = 1;
    do {
        asm_cars[i].x = asm_cars[0].x
            - (INT) (dat_side_dx[asm_cars[0].facing] << 5) / 4 * i;
        asm_cars[i].y = asm_cars[0].y
            - (INT) (dat_side_dy[asm_cars[0].facing] << 5) / 4 * i;
        asm_cars[i].facing = asm_cars[0].facing;
        asm_cars[i].locked_on = 1;
        asm_cars[i].from_x = -1;
        asm_cars[i].goal = -1;
        asm_cars[i].suspicion = 0;
        asm_cars[i].gear = 0;
        i++;
    } while (i < 3);

    asm_goal_x = asm_spot_x[asm_goal_spot];
    asm_goal_y = asm_spot_y[asm_goal_spot];
    if (asm_chase_kind == 2)
        asm_active_car = 0;
}
