/* ENTRY.C -- placing the player at the start of a break-in.
 */
#include "TAC.H"
#include "CITY.H"
#include "MAPDRAW.H"
#include "PROMPT.H"
#include "RANGE.H"
#include "PLAN.H"
#include "EQUIP.H"
#include "PLACE.H"
#include "TURN.H"

/* Place the player for the break-in: pick the way in, mark the cell it starts
 * from, clear the per-turn tables and put the view on it. */
INT c_place_player(void)
{
    INT v0j;        /* how many ways in the menu offered */
    INT v1l;        /* the starting column */
    INT v2n;        /* the starting row */
    INT v3;         /* the index being walked */
    INT v4b[8];     /* which way in each menu line stands for */

    /* A break-in lets the player choose the kit; escape, jailbreak and ambush hand one out. */
    if (asm_mission_kind != 1 && asm_mission_kind != 2
        && asm_mission_kind != 3)
        c_kit_screen(LONG_LIT(1));
    else {
        /* Pistol, Kevlar and motion detector; the jailbreak swaps the Uzi in, and the
         * ambush drops the detector, both with four fragmentation grenades. */
        asm_kit = 0xc1;
        if (asm_mission_kind == 2 || asm_mission_kind == 3) {
            asm_ammunition[0] = 4;
            if (asm_mission_kind == 2)
                asm_kit = 0xc2;
            else
                asm_kit &= 0xff7f;
        }
        c_kit_screen(LONG_LIT(0));
        c_draw_kit_panel();
    }
    /* Into the building's colours, with the street on the plan from the start. */
    drv_jump_gfx_set_colour_map(&dat_colours_tactical, &dat_colours_tactical);
    asm_rooms[0].flags |= 2;
    c_draw_plan(180, 100, 3);
    shd_screen->bg_pen = 1;
    /* The middle of the floor stands for the player until the start cell is known. */
    asm_player_x = 328;
    asm_player_y = 264;
    if (asm_mission_kind == 1 || asm_mission_kind == 2
        || asm_mission_kind == 3) {
        /* Escape, jailbreak and ambush start in the middle of the payload room, the
         * ambush on its bottom row with the guards' attention on it. */
        asm_room_last = asm_payload_room;
        v1l = asm_rooms[asm_payload_room].left
            + asm_rooms[asm_payload_room].width / 2;
        v2n = asm_rooms[asm_payload_room].top
            + asm_rooms[asm_payload_room].height / 2;
        if (asm_mission_kind == 3) {
            v2n = asm_rooms[asm_payload_room].height
                + asm_rooms[asm_payload_room].top
                - 1;
            asm_target_room = asm_payload_room;
        }
        /* Escaping, no room counts as the payload room. */
        if (asm_mission_kind == 1)
            asm_payload_room = -1;
        /* Facing up, with a chair on the start cell, or the cell above it in the ambush. */
        asm_facing = 1;
        *((char *) asm_floor_map + (v1l << 5)
      + (v2n - (asm_mission_kind == 3 ? 1 : 0))) = 14;
        /* In a jailbreak the rooms next to the payload room are already explored. */
        if (asm_mission_kind == 2)
            for (v3 = 0; v3 < asm_doorway_count; v3++) {
                if (asm_doorways[v3].from
                    == asm_payload_room)
                    asm_rooms[asm_doorways[v3].to].flags |= 2;
                if (asm_doorways[v3].to
                    == asm_payload_room)
                    asm_rooms[asm_doorways[v3].from].flags |= 2;
            }
    } else {
        /* A break-in: number every door to the street on the plan. */
        asm_room_last = -1;
        v0j = 0;
        for (v3 = 0; v3 < asm_doorway_count; v3++)
            if ((asm_doorways[v3].from == 0
                 && asm_doorways[v3].to != 0)
                || (asm_doorways[v3].to == 0
                    && asm_doorways[v3].from != 0)) {
                v4b[v0j++] = v3;
                strcpy(shm_scratch, &dat_str_empty_15);
                strcat(shm_scratch, itoa(v0j, asm_number_digits_3, 10));
                c_write_text_trimmed(shm_scratch,
                                asm_doorways[v3].col * 3
                                + 180,
                                asm_doorways[v3].row * 3
                                + 98,
                                shm_cga != 0 ? 4 : 15);
            }
        /* With more than one, ask which; Escape takes the first. */
        if (v0j > 1) {
            strcpy(shm_scratch, dat_str_which_door);
            for (v3 = 0; v3 < v0j; v3++) {
                strcat(shm_scratch, dat_str_door_5);
                strcat(shm_scratch, itoa(v3 + 1, asm_number_digits_3, 10));
                strcat(shm_scratch, dat_str_newline_13);
            }
            v3 = c_ask_menu(shm_scratch, 180, 64);
            if (v3 != -1)
                v3 = v4b[v3];
            else
                v3 = v4b[0];
        } else
            v3 = v4b[0];
        /* Start on the inside of that door, facing into the building. */
        if (asm_doorways[v3].from == 0
            && asm_doorways[v3].to != 0) {
            asm_room_last = asm_doorways[v3].to;
            v1l = asm_doorways[v3].col
                + dat_side_dx[asm_doorways[v3].facing];
            v2n = asm_doorways[v3].row
                + dat_side_dy[asm_doorways[v3].facing];
            asm_facing =
                asm_doorways[v3].facing * 2 + 1;
        }
        if (asm_doorways[v3].to == 0
            && asm_doorways[v3].from != 0) {
            asm_room_last = asm_doorways[v3].from;
            v1l = asm_doorways[v3].col;
            v2n = asm_doorways[v3].row;
            asm_facing =
                ((asm_doorways[v3].facing + 2) & 3) * 2 + 1;
        }
        /* The door the player comes in by stands open. */
        asm_floor_map[(v1l << 5) + v2n] |= 0x80;
        /* With a suspect inside, measure the rooms from the payload room, raising no alarm. */
        if (asm_suspect_here != -1)
            c_room_distances(asm_payload_room, 0);
    }
    /* A jailbreak starts with the alarm already up. */
    if (asm_mission_kind == 2)
        c_room_distances(asm_payload_room, 999);
    asm_facing_goal = asm_facing;
    /* No grenades, and nobody drawn or on the radar yet. */
    for (v3 = 0; v3 < 16; v3++)
        asm_grenades[v3].flags = -1;
    for (v3 = 0; v3 <= 8; v3++) {
        asm_cast_x[v3] =
            asm_cast_y[v3] =
            asm_blip_x[v3] =
            asm_blip_y[v3] = 0;
        asm_people[v3].flags = 0;
    }
    /* The player, then the guards, more the harder it is; none yet in a jailbreak. */
    c_place_person(0);
    asm_people[0].flags |= 0x80;
    for (v3 = 1; v3 <= shm_difficulty + 1; v3++)
        if (asm_mission_kind != 2)
            c_place_person(v3);
    for (v3 = 0; v3 < 24; v3++)
        asm_room_seen_tick[v3] = 0;
    /* Stand the player in the middle of the start cell; the first tick enters its room. */
    asm_player_x = (v1l << 4) + 8;
    asm_player_y = (v2n << 4) + 8;
    asm_signs_here = 0;
    asm_room_last = -1;
    if (asm_mission_kind == 2 || asm_mission_kind == 3) {
        asm_player_cell = asm_player_x / 16;
        asm_player_cell_row = asm_player_y / 16;
        /* The ambush starts with the alarm up and floor object 2, a wall, on the player's cell. */
        if (asm_mission_kind == 3) {
            c_room_distances(1, 240);
            asm_floor_map[((INT) asm_player_cell << 5)
                + asm_player_cell_row] = 2;
        }
    }
}
