/* WAYOUT.C -- picking the next room a guard makes for.
 */
#include "TAC.H"
#include "ALERTED.H"
#include "RANGE.H"
#include "WAYOUT.H"

/* Pick the room through a doorway of `room` that stands closest to where the
 * guard is heading, note the turn it was picked on, and answer which it
 * was. */
INT c_next_room(INT room, INT guard)
{
    INT v0j;    /* what the guard is making for */
    INT v1m;    /* the best distance so far */
    INT v2;     /* which doorway is being looked at */
    INT v3c;    /* and the room it leads to */

    /* Any room beats none, and how near each is depends on the guard's kind. */
    v1m = 9999;
    v0j = c_guard_alertness(guard);
    /* Try the room through every doorway of this one, either way round, but never
     * the street; the best is measured again, so its random edge is rolled anew. */
    for (v2 = 0; v2 < asm_doorway_count; v2++) {
        if (asm_doorways[v2].from == room
            && c_room_cost(asm_doorways[v2].to,
                               v0j) < v1m
            && asm_doorways[v2].to != 0) {
            v3c = asm_doorways[v2].to;
            v1m = c_room_cost(v3c, v0j);
        }
        if (asm_doorways[v2].to == room
            && c_room_cost(asm_doorways[v2].from,
                               v0j) < v1m
            && asm_doorways[v2].from != 0) {
            v3c = asm_doorways[v2].from;
            v1m = c_room_cost(v3c, v0j);
        }
    }
    /* Stamp the pick, so a guard making the rounds goes elsewhere next. */
    room = v3c;
    asm_room_seen_tick[room] =
        asm_frame_tick + 1;
    return room;
}
