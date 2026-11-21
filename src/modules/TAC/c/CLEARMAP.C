/* CLEARMAP.C -- emptying the floor and walling it round.
 */
#include "TAC.H"
#include "WALLCELL.H"
#include "WALLS.H"

/* Empty the floor and draw the outside wall around it, at the size this kind
 * of building uses. */
INT c_clear_floor(void)
{
    INT v0j;    /* how wide the floor is */
    INT v1l;    /* and how deep */
    INT v2n;    /* which column while clearing */
    INT v3;     /* and which row */
    INT v4b;    /* which cell of the wall */

    /* An ambush is fought in one small room; every other mission gets the whole 40 by 32 board. */
    if (asm_mission_kind == 3) {
        v0j = 12;
        v1l = 13;
    } else {
        v0j = 40;
        v1l = 32;
    }
    /* Start from a bare board: no walls, no rooms, nothing standing. */
    for (v2n = 0; v2n < 40; v2n++)
        for (v3 = 0; v3 < 32; v3++) {
            asm_wall_map[(v2n << 5) + v3] =
                asm_room_map[(v2n << 5) + v3] = 0;
            asm_floor_map[(v2n << 5) + v3] = -1;
        }
    /* Wall the top and bottom one cell in, leaving the board's own edge rows bare. */
    v4b = 1;
    while (v0j - 1 > v4b) {
        c_set_wall(v4b, 1, 0);
        c_set_wall(v4b, v1l - 2, 2);
        asm_wall_map[(v4b << 5)] =
            asm_wall_map[(v4b << 5) + 31] = 0;
        v4b++;
    }
    /* And the left and right sides the same way. */
    v4b = 1;
    while (v1l - 1 > v4b) {
        c_set_wall(1, v4b, 3);
        c_set_wall(v0j - 2, v4b, 1);
        asm_wall_map[v4b] =
            asm_wall_map[v4b + 1248] = 0;
        v4b++;
    }
}
