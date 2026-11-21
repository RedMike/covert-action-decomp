/* SEEN.C -- what a guard makes of the player.
 */
#include "TAC.H"
#include "ALERTED.H"

/* Whether a guard sees the player: never past a wall or anything opaque,
 * always in the open, and past cover by who is crouching and where it stands. */
INT c_guard_sees_player(INT guard)
{
    INT v0j;    /* whether the line of sight is clear */

    /* Look from the guard to the player; this also marks which half any cover is in. */
    v0j = c_line_of_sight(
              asm_people[guard].x,
              asm_people[guard].y,
              asm_player_x, asm_player_y);
    /* Something opaque between them hides the player. */
    if (v0j == 0)
        return 0;
    /* Nothing between them, and he is seen. */
    if (v0j == 2)
        return 1;
    /* Past cover, a standing guard sees a player who stands or fires. */
    if ((asm_people[guard].flags & 4) == 0
        && (asm_crouched == 0 || asm_shot_timer != 0))
        return 1;
    /* Both crouched, and the player not firing, the cover hides him. */
    if ((asm_people[guard].flags & 4) != 0
        && asm_crouched != 0 && asm_shot_timer == 0)
        return 0;
    /* A crouching player is hidden by cover in his own half of the line. */
    if (asm_crouched != 0 && asm_shot_timer == 0)
        return asm_guard_tick & 2;
    /* A crouching guard cannot see past cover in his own half. */
    return asm_guard_tick & 1;
}
