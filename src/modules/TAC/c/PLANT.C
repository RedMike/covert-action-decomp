/* PLANT.C -- laying the building out.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "DOORS.H"
#include "PLANT.H"
#include "WALLCELL.H"
#include "WALLS.H"

/* Lay the building out: keep rebuilding the rooms and doorways until enough
 * rooms survive, furnish them, and clear the floor map's edges of all but
 * the doorways. */
INT c_lay_out_building(void)
{
    INT v0j;    /* never read */
    INT v1n;    /* likewise reserved */
    INT v2b;    /* which room, cell or column */

    do {
        /* Forget the last attempt's rooms. */
        for (v2b = 0; v2b < 24; v2b++)
            *(INT *) &asm_rooms[v2b].flags = 0;
        asm_room_count = 0;
        /* An ambush is the one walled room, which serves for both the target and the guards. */
        if (asm_mission_kind == 3) {
            c_clear_floor();
            c_number_rooms();
            asm_payload_room = asm_guard_room = 1;
            break;
        }
        /* Run walls across the floor until the rooms come out small enough and doorways reach them all. */
        do {
            c_clear_floor();
            if (asm_mission_kind != 3)
                c_run_walls();
        } while (c_number_rooms() == 0 || c_cut_doorways() == 0);
    /* Start over unless at least twelve rooms are left once the unreached ones go. */
    } while (asm_room_count - (INT) c_pick_rooms() < 12);
    /* Give every room a use and its furniture. */
    v2b = 1;
    while (v2b <= asm_room_count) {
        c_furnish_room(v2b);
        v2b++;
    }
    /* Clear the top and bottom edge rows of everything but doors. */
    v2b = 0;
    do {
        if (((unsigned char) asm_floor_map[(v2b << 5)] & 0xfc) != 8)
            asm_floor_map[(v2b << 5)] = -1;
        if (((unsigned char) asm_floor_map[(v2b << 5) + 31] & 0xfc) != 8)
            asm_floor_map[(v2b << 5) + 31] = -1;
        v2b++;
    } while (v2b < 39);
    /* And the left and right edge columns. */
    v2b = 0;
    do {
        if (((unsigned char) asm_floor_map[v2b] & 0xfc)
            != 8)
            asm_floor_map[v2b] = -1;
        if (((unsigned char) asm_floor_map[(39 << 5) + v2b] & 0xfc)
            != 8)
            asm_floor_map[(39 << 5) + v2b] = -1;
        v2b++;
    } while (v2b < 31);
    /* The layout came from the building's own seed; play reseeds from the clock. */
    c_seed_random();
}
