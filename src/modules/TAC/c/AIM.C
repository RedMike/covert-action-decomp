/* AIM.C -- aiming the cursor at the cell ahead of the player.
 */
#include "TAC.H"
#include "BUGROOM.H"

/* Put the cursor on the cell three walking steps ahead of the player, nine
 * pixels straight on or six each way on a diagonal, or back on the player where
 * that cell holds nothing, holds a wall, or lies outside this room. */
INT c_aim_cursor(void)
{
    INT v0j;    /* the cell ahead, across */
    INT v1n;    /* and down */
    INT v2b;    /* what stands on it */

    /* The point a short reach ahead of the player, and the cell it falls in. */
    v0j = (dat_move_dx[asm_facing] * 3
           + asm_player_x) / 16;
    v1n = (dat_move_dy[asm_facing] * 3
           + asm_player_y) / 16;
    v2b = asm_floor_map[(v0j << 5) + v1n];
    /* Only a thing other than a wall, inside the player's room, can be aimed at. */
    if (v2b != -1 && ((unsigned char) v2b & 0x3f) > 7
        && v0j >= asm_rooms[asm_room_last].left
        && asm_rooms[asm_room_last].width
           + asm_rooms[asm_room_last].left > v0j
        && v1n >= asm_rooms[asm_room_last].top
        && asm_rooms[asm_room_last].height
           + asm_rooms[asm_room_last].top > v1n) {
        asm_cursor_col = v0j;
        asm_cursor_row = v1n;
    } else {
        /* Otherwise the act lands on the player's own cell. */
        asm_cursor_col = asm_player_col;
        asm_cursor_row = asm_player_row;
    }
}
