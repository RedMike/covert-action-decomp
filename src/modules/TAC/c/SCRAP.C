/* SCRAP.C -- throwing a room away.
 */
#include "TAC.H"
#include "WALLCELL.H"

/* Throw a room away: clear every cell it covers, hand the player's start to it
 * if it has doorways, and blank its end of every doorway record. */
INT c_scrap_room(INT room)
{
    INT v0j;    /* which cell, across */
    INT v1a;    /* and down */

    /* Mark it scrapped, so it is not furnished. */
    asm_rooms[room].flags |= 1;
    /* Take its walls and its number off the map, and everything on its floor
     * but the doors. */
    for (v0j = asm_rooms[room].left;
         asm_rooms[room].left
         + asm_rooms[room].width > v0j;
         v0j++)
        for (v1a = asm_rooms[room].top;
             asm_rooms[room].top
             + asm_rooms[room].height > v1a;
             v1a++) {
            asm_wall_map[(v0j << 5) + v1a] =
                asm_room_map[(v0j << 5) + v1a] = 0;
            if (((unsigned char) asm_floor_map[(v0j << 5) + v1a] & 0xfc) != 8)
                asm_floor_map[(v0j << 5) + v1a] = -1;
        }
    /* One with doorways is handed the player's start. */
    if (asm_room_doorways[room] != 0)
        asm_room_last = room;
    /* Its doorways now lead from outside. */
    v0j = 0;
    while (v0j < asm_doorway_count) {
        if (asm_doorways[v0j].from == room)
            asm_doorways[v0j].from = 0;
        if (asm_doorways[v0j].to == room)
            asm_doorways[v0j].to = 0;
        v0j++;
    }
}
