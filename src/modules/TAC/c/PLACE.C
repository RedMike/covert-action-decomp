/* PLACE.C -- bringing a person into the building.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "PLACE.H"

/* Bring one more person into the building and stand them somewhere: at a
 * doorway when this is a jailbreak, otherwise on a random cell that passes the
 * checks, and either way giving up after 999 tries. The bare blocks around the
 * placement runs are as shipped. */
void c_place_person(INT who)
{
    INT v0j;    /* how many placements have been tried */
    INT v1l;    /* how far the cell is from the player */
    INT v2n;    /* which doorway was picked */
    INT v3;     /* how much distance is still allowed */
    INT v4b;    /* never read */

    /* No more people on the floor at once than the mission and level allow. */
    if ((asm_high_security != 0 ? 5 : 3) + shm_difficulty * 2 < who)
        return;
    /* Nobody is left to bring in. */
    if (asm_guards_to_come == 0)
        return;
    /* How far from the player a newcomer must appear, less the harder the game. */
    v3 = (4 - shm_difficulty) * 75;
    v0j = 0;
    if (asm_mission_kind == 2) {
        /* A jailbreak: they come in from outside, through a doorway with the
         * street or a scrapped room on one side and not the prisoner's room on
         * the other, standing just inside; the facing in set here is lost to
         * the facing up set below. */
        asm_people[who].x = -1;
        do {
            v2n = c_random_below(asm_doorway_count);
            /* Outside on the doorway's from side: step through to the to side. */
            if (asm_doorways[v2n].from == 0
                && asm_doorways[v2n].to != 0
                && asm_payload_room
                   != asm_doorways[v2n].to) {
                v4b = who * 0x1c;
                asm_people[who].room =
                    asm_doorways[v2n].to;
                asm_people[who].x =
                    asm_doorways[v2n].col
                    + dat_side_dx[asm_doorways[v2n].facing];
                asm_people[who].y =
                    asm_doorways[v2n].row
                    + dat_side_dy[asm_doorways[v2n].facing];
                asm_people[who].facing =
                    asm_doorways[v2n].facing * 2 + 1;
            }
            /* Outside on the to side: stand on the from side, facing back. */
            if (asm_doorways[v2n].to == 0
                && asm_doorways[v2n].from != 0
                && asm_payload_room
                   != asm_doorways[v2n].from) {
                v4b = who * 0x1c;
                asm_people[who].room =
                    asm_doorways[v2n].from;
                asm_people[who].x =
                    asm_doorways[v2n].col;
                asm_people[who].y =
                    asm_doorways[v2n].row;
                asm_people[who].facing =
                    ((asm_doorways[v2n].facing + 2) & 3)
                    * 2 + 1;
            }
        } while (asm_people[who].x == -1
                 && ++v0j < 999);
        /* From the cell to the pixel at its middle. */
        asm_people[who].x =
            (asm_people[who].x << 4) + 8;
        asm_people[who].y =
            (asm_people[who].y << 4) + 8;
    } else if (asm_high_security == 0 || asm_mission_kind != 0) {
        /* Anywhere on the map that suits, tried at random. */
        do {
            {
                asm_people[who].x =
                    (c_random_below(40) << 4) + 8;
                asm_people[who].y =
                    (c_random_below(32) << 4) + 8;
                asm_people[who].room =
                    asm_room_map[(asm_people[who].x / 16 << 5)
                        + asm_people[who].y / 16];
                v1l = (INT) abs(asm_people[who].x
                                    - asm_player_x)
                    + (INT) abs(asm_people[who].y
                                    - asm_player_y);
            }
            /* In a room, and not the player's except in an ambush. */
            if (asm_people[who].room != 0
                && (asm_room_last
                    != asm_people[who].room
                    || asm_mission_kind == 3)) {
                /* On a free cell. */
                if (asm_floor_map[(asm_people[who].x / 16 << 5)
                    + asm_people[who].y / 16] == -1) {
                    /* After the start, only in the payload or guard room,
                     * unless there is no payload room. */
                    if (asm_people[who].room
                        == asm_payload_room
                        || asm_people[who].room
                           == asm_guard_room
                        || asm_frame_tick == 0
                        || asm_payload_room <= 0) {
                        /* Far enough off, the distance asked easing each try. */
                        if (v1l >= v3--)
                            break;
                    }
                }
            }
        } while (++v0j < 999);
    } else {
        /* Otherwise only in the payload room, and nobody turns up there once
         * the player has got in after the start. */
        if (asm_frame_tick > 16
            && asm_room_last == asm_payload_room)
            return;
        do {
            {
                asm_people[who].x =
                    (c_random_below(40) << 4) + 8;
                asm_people[who].y =
                    (c_random_below(32) << 4) + 8;
                asm_people[who].room =
                    asm_room_map[(asm_people[who].x / 16 << 5)
                        + asm_people[who].y / 16];
            }
            /* A free cell in the payload room. */
            if (asm_people[who].room
                == asm_payload_room
                && asm_floor_map[(asm_people[who].x / 16 << 5)
                    + asm_people[who].y / 16] == -1)
                break;
        } while (++v0j < 999);
    }
    /* Nowhere was found: the person stays in reserve. */
    if (v0j >= 999)
        return;
    /* Take them from the reserve and start them fresh: in play, facing up,
     * unalerted and on their feet. */
    asm_guards_to_come--;
    asm_people[who].flags = 0x80;
    asm_people[who].field_6 = -1;
    asm_people[who].kind = 0;
    asm_people[who].facing = 1;
    asm_people[who].shot_timer = 0;
    asm_people[who].field_14 = 0;
    asm_people[who].last_move_type = 0;
    asm_people[who].alert =
        asm_people[who].field_18 =
        asm_people[who].stun = 0;
}
