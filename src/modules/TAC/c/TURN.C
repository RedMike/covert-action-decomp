/* TURN.C -- one tick of the break-in.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "PAGESHOW.H"
#include "RANGE.H"
#include "PLAN.H"
#include "NOTHING.H"
#include "INPUT.H"
#include "PATROL.H"
#include "ROOM.H"
#include "STATUS.H"
#include "TRAP.H"
#include "TURN.H"

/* Run one tick: pick up the room the player has walked into, hand the turn to
 * the occupants, run the clock on and refresh the two status lamps. */
INT c_tick(void)
{
    INT v0j;    /* the index being walked, then the guard the clock picked */
    INT v1l;    /* declared, and nothing reads it */

    /* Has the player walked into another room? */
    asm_player_col = asm_player_x / 16;
    asm_player_row = asm_player_y / 16;
    if (asm_room_map[(asm_player_col << 5)
        + asm_player_row] != asm_room_last) {
        /* The room left behind stays disturbed only for what the player leaves in it. */
        if (asm_room_last != -1) {
            asm_rooms[asm_room_last].flags &= 0xf7;
            /* Guards down for good leave play, and the room left is marked for them. */
            for (v0j = 1; v0j < 8; v0j++)
                if (asm_people[v0j].flags != 0
                    && asm_people[v0j].stun
                       > 999) {
                    asm_people[v0j].flags = 0;
                    asm_rooms[asm_room_last].flags |= 8;
                }
            /* So it is for anything left open, or a body lying there. */
            if ((INT) asm_room_seen > 0 || asm_signs_here != 0)
                asm_rooms[asm_room_last].flags |= 8;
        }
        /* Into the new room, standing just short of the middle of the cell entered. */
        asm_room_seen = 0;
        asm_room_last = asm_room_map[(asm_player_col << 5)
            + asm_player_row];
        asm_guard_turn_at = 0;
        asm_player_x = (asm_player_col << 4)
            - dat_move_dx[asm_facing] + 8;
        asm_player_y = (asm_player_row << 4)
            - dat_move_dy[asm_facing] + 8;
        /* Out in the street the break-in is over. */
        if (asm_room_last == 0) {
            shm_finished = 1;
            drv_jump_gfx_copy_rect(shd_map_page, asm_cast_x[0], asm_cast_y[0], 15, 15, shd_screen, asm_cast_x[0], asm_cast_y[0]);
            return;
        }
        /* Show the room and put it on the plan as explored. */
        c_draw_room(asm_room_last);
        asm_rooms[asm_room_last].flags |= 2;
        c_draw_plan(180, 100, 3);
        /* Walking undisguised into the payload room with a suspect there raises the alarm. */
        if (asm_room_last == asm_payload_room
            && asm_suspect_here != -1 && asm_disguised == 0)
            c_room_distances(asm_room_last, 240);
        /* Whether the room was found disturbed. */
        asm_signs_here = *(INT *) &asm_rooms[asm_room_last].flags & 8;
    }
    /* The player moves, then the guards, and everyone is drawn. */
    c_player_move();
    if (shm_finished != 0)
        return;
    for (v0j = 1; v0j <= 8; v0j++)
        c_guard_turn(v0j);
    c_draw_cast();
    /* The tick's sound, one of five by the alarm, the disguise and whether a guard was
     * in the target room; every 256 ticks one of three variants is picked afresh. */
    asm_sound_arg_1 = 1;
    if ((asm_frame_tick & 0xff) == 0)
        asm_sound_arg_2 = c_random_below(3) + 1;
    if (asm_guard_alert <= 0) {
        if (asm_guard_seen != 0) {
            if (asm_disguised != 0)
                asm_sound_arg_1 = 3;
            else
                asm_sound_arg_1 = 2;
        }
    } else if (asm_guard_seen != 0)
        asm_sound_arg_1 = 5;
    else
        asm_sound_arg_1 = 4;
    c_sound_command(44);
    /* The clock runs on, held under 7500 by steps of 256 so its low bits keep cycling. */
    asm_frame_tick++;
    if (asm_frame_tick > 7500)
        asm_frame_tick -= 256;
    c_draw_status();
    /* A flash lasts one tick: put the normal palette back. */
    if (asm_palette_flash != 0) {
        c_set_palette_record(0);
        asm_palette_flash = 0;
    }
    /* With the agent under arrest there is no passing as a guard. */
    if ((asm_outcome & 2) != 0)
        asm_disguised = 0;
    /* The alarm strips the disguise and runs down; when it ends, the guards are
     * measured from the payload room again. */
    if (asm_guard_alert != 0) {
        asm_disguised = 0;
        if (--asm_guard_alert == 0)
            c_room_distances(asm_payload_room, 0);
        /* Every sixteen ticks it flashes the screen, and sounds while it is still high. */
        if ((asm_frame_tick & 0xf) == 0 && asm_mission_kind != 3) {
            c_set_palette_record(2);
            asm_palette_flash = 1;
            if (asm_guard_alert > 200) {
                c_sound_command(18);
                asm_alarm_sounded = 1;
            }
        }
    }
    /* Every 32 ticks Num Lock is put back on, and the gas clears from one room at random. */
    if ((asm_frame_tick & 0x1f) == 0) {
        NUM_LOCK_ON();
        v0j = c_random_below(24);
        if ((asm_rooms[v0j].flags & 0x10) != 0) {
            asm_rooms[v0j].flags &= 0xef;
            c_draw_plan(180, 100, 3);
        }
    }
    /* Recolour the portrait strip when the disguise comes or goes, except on CGA. */
    if (asm_disguise_label_shown != asm_disguised && shm_cga == 0) {
        asm_disguise_label_shown = asm_disguised;
        if (asm_disguise_label_shown != 0)
            drv_jump_gfx_fill(dat_cast_frames, 0, 160, 320, 40, 13,
                              asm_belt_text);
        else
            drv_jump_gfx_fill(dat_cast_frames, 0, 160, 320, 40,
                              asm_belt_text, 13);
    }
    /* And when the player's room fills with gas or clears of it. */
    if (((unsigned char) *(INT *) &asm_rooms[asm_room_last].flags & 0x10)
        != asm_gas_label_shown) {
        asm_gas_label_shown = *(INT *) &asm_rooms[asm_room_last].flags & 0x10;
        if (asm_gas_label_shown != 0)
            drv_jump_gfx_fill(dat_cast_frames, 0, 160, 320, 40, 9, 12);
        else
            drv_jump_gfx_fill(dat_cast_frames, 0, 160, 320, 40, 12, 9);
    }
}
