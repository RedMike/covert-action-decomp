/* BLIP.C -- a guard knocked down for good.
 */
#include "TAC.H"
#include "BLIP.H"

/* Knock guard `nth` down for good, shot or caught in a blast: wipe his blip
 * off the map panel, count him, mark his room, and set his timer to 9999,
 * which never wears off. Gas knocks a guard down without coming here. */
INT c_guard_knocked_down(INT nth)
{
    INT v0j;    /* where the blip goes across */
    INT v1l;    /* and down */

    /* Take his dot off the floor plan, three pixels to the 16-pixel cell. */
    v0j = 3 * asm_people[nth].x / 16 + 180;
    v1l = 3 * asm_people[nth].y / 16 + 100;
    drv_jump_gfx_copy_rect(shd_map_page, v0j, v1l, 2, 2, shd_screen, v0j, v1l);
    /* A body lies in the room now, for a guard who comes in to find. */
    asm_signs_here++;
    asm_rooms[asm_people[nth].room].flags |= 8;
    /* It counts against the player in the alert the break-in reports. */
    asm_seen_count++;
    /* And he never gets up. */
    asm_people[nth].stun = 9999;
}
