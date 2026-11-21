/* SPOT.C -- whether a guard has the player in view.
 */
#include "TAC.H"
#include "ALERTED.H"
#include "OCTANT16.H"

/* Whether a guard has the player in view: he must be in the same room, and a
 * guard who is looking somewhere else does not see a target off his heading. */
INT c_guard_sees(INT guard)
{
    INT v0j;    /* how far off his heading the player is */
    INT v1n;    /* how far away across */
    INT v2b;    /* and down */

    /* A guard sees nothing outside the player's room. */
    asm_guard_sees = 0;
    if (asm_people[guard].room
        != asm_room_last)
        return 0;
    /* Whether he would see the player, cover and crouching considered. */
    asm_guard_sees = c_guard_sees_player(guard);
    /* How many eighths of a turn the player is off the guard's heading. */
    v1n = asm_player_x
          - asm_people[guard].x;
    v2b = asm_player_y
          - asm_people[guard].y;
    v0j = asm_people[guard].facing
          - c_facing8(v1n, v2b);
    /* A player over a quarter turn off his heading goes unseen, unless an alarm has him searching this room. */
    if ((asm_guard_alert == 0
         || asm_people[guard].room
            != asm_target_room)
        && (INT) abs(v0j) > 2 && (INT) abs(v0j) < 6)
        return 0;
    return asm_guard_sees;
}
