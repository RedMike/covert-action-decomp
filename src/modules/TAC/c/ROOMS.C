/* ROOMS.C -- numbering the rooms the walls cut the floor into.
 */
#include "TAC.H"
#include "DOORS.H"

/* Number the rooms the walls have cut the floor into, measuring each as it
 * goes, and answer whether every one of them came out small enough. */
INT c_number_rooms(void)
{
    INT v0j;    /* which cell, across */
    INT v1l;    /* and down */
    INT v2n;    /* which room while measuring */
    INT v3;     /* whether they all fit */
    INT v4b;    /* how far along the run is */

    /* Sweep the inside of the map a row at a time, left to right. */
    asm_room_count = 0;
    for (v1l = 1; v1l < 31; v1l++) {
        v4b = 1;
        for (v0j = 1; v0j < 39; v0j++)
            /* No wall on the left: the room carries on from the cell to the
             * left, and is as wide as the run so far. */
            if ((asm_wall_map[(v0j << 5) + v1l] & 8)
                == 0) {
                asm_room_map[(v0j << 5) + v1l] =
                    asm_room_map[(v0j << 5) + v1l - 32];
                v4b++;
                asm_rooms[asm_room_map[(v0j << 5) + v1l]].width = v4b;
            } else {
                /* A wall on the left starts a new run. */
                v4b = 1;
                /* No wall above: the room above carries on a row further. */
                if ((asm_wall_map[(v0j << 5) + v1l]
                     & 1) == 0) {
                    asm_room_map[(v0j << 5) + v1l] =
                        asm_room_map[(v0j << 5) + v1l - 1];
                    (asm_rooms[asm_room_map[(v0j << 5) + v1l]].height)++;
                /* Walled on the left and above: the top left corner of a new
                 * room. */
                } else {
                    asm_room_map[(v0j << 5) + v1l] =
                        ++asm_room_count;
                    asm_rooms[asm_room_count].left = v0j;
                    asm_rooms[asm_room_count].top = v1l;
                    asm_rooms[asm_room_count].height = 1;
                }
            }
    }
    /* The layout fails if any room is over ten cells either way. */
    v3 = 1;
    for (v2n = 1; v2n <= asm_room_count; v2n++)
        if (asm_rooms[v2n].width > 10
            || asm_rooms[v2n].height > 10)
            v3 = 0;
    return v3;
}
