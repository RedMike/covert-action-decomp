/* RANGE.C -- how far a room is from where a guard wants to be, and every
 * room's distance from one room.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "RANGE.H"

/* How far room `who` is from where a guard of `kind`, c_guard_alertness's
 * answer, wants to be: c_next_room takes the lowest it is offered. */
INT c_room_cost(INT who, INT kind)
{
    switch (kind) {
    /* Kind 0 makes the rounds: the room picked longest ago is nearest. */
    case 0:
        return asm_room_seen_tick[who];
    /* Kind 1 heads for the room last measured from, where the alarm points or in
     * a jailbreak the prisoner's, with a random edge; with no target, the rounds. */
    case 1:
        if (asm_target_room <= 0)
            return asm_room_seen_tick[who];
        return asm_rooms[who].distance * 4
               + c_random_below(7);
    /* Kind 2, and -1, join the hunt while an alarm is on and otherwise keep
     * near asm_guard_room, with the same random edge. */
    case -1:
    case 2:
        if (asm_guard_alert != 0)
            return asm_rooms[who].distance * 4
                   + c_random_below(7);
        return asm_guard_distances[who] * 4
               + c_random_below(7);
    }
}

/* Re-walk the room graph and put every room's distance from `here` back in
 * asm_rooms, relaxing both ways along each doorway until nothing moves.
 * `here` becomes the target room and the alarm rises to at least `elapsed`. */
INT c_room_distances(INT here, INT elapsed)
{
    INT v0j;                            /* the doorway's near room */
    INT v1m;                            /* and its far one */
    INT v2;                             /* whether the pass settled */
    INT v3c;                            /* the doorway, then the room */

    /* Raising the alarm strips the player's disguise. */
    if (elapsed != 0)
        asm_disguised = 0;
    /* The harder the game, the longer an alarm runs. */
    elapsed = elapsed / 4 * (shm_difficulty + 4);
    /* The guards converge on `here`; in a jailbreak they are measured from the
     * prisoner's room whatever the target, and an alarm with no room points there. */
    asm_target_room = here;
    if (asm_mission_kind == 2) {
        if (here == -1)
            asm_target_room = asm_payload_room;
        here = asm_payload_room;
    }
    /* The alarm runs at least that long, and never past 9999 ticks. */
    asm_guard_alert = c_clamp(asm_guard_alert, elapsed, 9999);
    /* With no room to measure from, the distances stay as they were. */
    if (here == dat_no_room)
        return;
    /* Every room starts out of reach but `here` itself. */
    for (v3c = 0; v3c <= asm_room_count; v3c++)
        asm_rooms[v3c].distance = -1;
    asm_rooms[here].distance = 0;
    /* Pass over the doorways until no distance shortens. */
    do {
        v2 = 1;
        for (v3c = 0; v3c < asm_doorway_count; v3c++) {
            v0j = (char) asm_doorways[v3c].from;
            v1m = (char) asm_doorways[v3c].to;
            /* A doorway of a scrapped room joins nothing. */
            if (v0j == 0 && v1m == 0)
                continue;
            /* Either side reached gives the other side one more, if that is shorter. */
            if (asm_rooms[v1m].distance != -1
                && (asm_rooms[v0j].distance == -1
                    || asm_rooms[v1m].distance + 1
                       < asm_rooms[v0j].distance)) {
                asm_rooms[v0j].distance =
                    asm_rooms[v1m].distance + 1;
                v2 = 0;
            }
            if (asm_rooms[v0j].distance != -1
                && (asm_rooms[v1m].distance == -1
                    || asm_rooms[v0j].distance + 1
                       < asm_rooms[v1m].distance)) {
                asm_rooms[v1m].distance =
                    asm_rooms[v0j].distance + 1;
                v2 = 0;
            }
        }
    } while (v2 == 0);
    /* The street is never somewhere to make for. */
    asm_rooms[0].distance = 999;
}
