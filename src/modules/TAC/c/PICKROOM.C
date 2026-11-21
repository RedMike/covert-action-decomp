/* PICKROOM.C -- choosing which rooms stay, the way in and the target.
 */
#include "TAC.H"
#include "WALLCELL.H"

/* Throw away every room the doorways never reached, pick the best outside room
 * for the guards and the biggest inside one for the target, and answer how
 * many rooms went. */
INT c_pick_rooms(void)
{
    INT v0j;    /* whether a room with doorways had to go */
    INT v1k;    /* the biggest room so far */
    INT v2l;    /* how many rooms went */
    INT v3m;    /* the best outside room's score */
    INT v4n;    /* which room */
    INT v5o;    /* this room's score */
    INT v6;     /* how big it is */
    INT v7a;    /* how many of its sides are the outside wall */

    v0j = v2l = v1k = 0;
    v3m = -999;
    for (v4n = 1; v4n <= asm_room_count; v4n++) {
        /* A room no doorway reaches cannot be walked into, so it goes. */
        if (asm_room_doorways[v4n] == 0) {
            c_scrap_room(v4n);
            v2l++;
        } else {
            /* Count the sides that lie along the building's outer wall. */
            v7a = 0;
            if (asm_rooms[v4n].left == 1)
                v7a++;
            if (asm_rooms[v4n].top == 1)
                v7a++;
            if (asm_rooms[v4n].left
                + asm_rooms[v4n].width == 39)
                v7a++;
            if (asm_rooms[v4n].top
                + asm_rooms[v4n].height == 31)
                v7a++;
            v6 = asm_rooms[v4n].width
                * asm_rooms[v4n].height;
            if (v7a != 0) {
                /* An outside room with one doorway becomes street, its doorway a way in. */
                if (asm_room_doorways[v4n] < 2) {
                    c_scrap_room(v4n);
                    v2l++;
                    v0j = 1;
                } else {
                    /* Otherwise favour more outer wall, fewer doorways, and size. */
                    v5o = (v7a - asm_room_doorways[v4n]) * 50 + v6;
                    if (v5o > v3m) {
                        v3m = v5o;
                        asm_guard_room = v4n;
                    }
                }
            } else if (v6 > v1k) {
                /* The biggest room clear of the outer wall holds the target. */
                v1k = v6;
                asm_payload_room = v4n;
            }
        }
    }
    /* With no way in made yet, scrap rooms from the first up to the first ordinary
     * one with doorways; already-scrapped rooms on the way are counted again. */
    if (v0j == 0) {
        v4n = 0;
        do {
            v4n++;
            if (v4n != asm_guard_room && v4n != asm_payload_room) {
                c_scrap_room(v4n);
                v2l++;
            }
        } while (asm_room_doorways[v4n] == 0
                 || v4n == asm_guard_room || v4n == asm_payload_room);
    }
    return v2l;
}
