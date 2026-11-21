/* CAST.C -- drawing everyone in the room.
 */
#include "TAC.H"
#include "BLIP.H"
#include "PAGESHOW.H"
#include "CITY.H"
#include "MAPDRAW.H"
#include "TILES.H"
#include "TRAP.H"
#include "RANDOM.H"

/* Redraw everyone in the room: rub each sprite out where it was, work out
 * which frame it wants now, put it back, and run the blasts over the top. */
INT c_draw_cast(void)
{
    INT v0j;    /* the pass, nine down to zero */
    INT v1k;    /* how far the person is from the player */
    INT v2m;    /* the frame of the sprite to draw */
    INT v3o;    /* the person being drawn */
    INT v4;     /* how much of the health bar is left */
    INT v5b;    /* the blast frame being drawn */

    /* Rub out every sprite drawn last time, and last time's muzzle flash, from the clean map page. */
    for (v3o = 0; v3o <= 8; v3o++)
        if (asm_cast_x[v3o] != -1)
            drv_jump_gfx_copy_rect(shd_map_page, asm_cast_x[v3o], asm_cast_y[v3o], 15, 15, shd_screen, asm_cast_x[v3o], asm_cast_y[v3o]);
    if (asm_shot_fired != 0)
        drv_jump_gfx_copy_rect(shd_map_page, asm_flash_x, asm_flash_y, 15, 15, shd_screen, asm_flash_x, asm_flash_y);
    asm_shot_fired = 0;
    /* Draw from the last guard down to the player, and the player first as well, in pass nine. */
    for (v0j = 9; v0j >= 0; v0j--) {
        v3o = v0j;
        if (v0j == 9)
            v3o = 0;
        /* Only someone in play in the player's room is drawn; the rest are marked as nowhere. */
        if (asm_people[v3o].room
            == asm_room_last
            && (asm_people[v3o].flags & 0x80)
               != 0) {
            /* Where they stand on the screen, the sprite centred on them. */
            asm_cast_x[v3o] =
                asm_people[v3o].x
                - (asm_rooms[asm_room_last].left << 4)
                + asm_view_left - 8;
            asm_cast_y[v3o] =
                asm_people[v3o].y
                - (asm_rooms[asm_room_last].top << 4)
                + asm_view_top - 8;
            /* Pass nine draws the player beneath the guards, unless he is firing, down or throwing. */
            if (v0j == 9) {
                if (asm_people[v3o].shot_timer == 0
                    && ((asm_kit & 0x40) != 0 ? 3 : 1)
                       >= asm_wounds
                    && asm_throw_frames == 0) {
                    v2m = asm_people[v3o].kind;
                    if (asm_people[v3o].alert
                        != 0)
                        v2m = 4;
                    if ((asm_people[v3o].flags
                         & 4) != 0)
                        v2m = 7;
                    c_draw_tile_2(
                        ((asm_crouched
                          & asm_crouch_walk_ticks & 1) != 0 ? 9 : 0)
                        + asm_people[v3o].facing
                          * 20 + v2m - 20,
                        asm_cast_x[v3o],
                        asm_cast_y[v3o]);
                }
                continue;
            }
            /* Not firing: the walking frame, the alert pose, or the crouch. */
            if (asm_people[v3o].shot_timer == 0) {
                v2m = asm_people[v3o].kind;
                if (asm_people[v3o].alert
                    != 0)
                    v2m = 4;
                if ((asm_people[v3o].flags
                     & 4) != 0)
                    v2m = 7;
            } else {
                /* Firing: count the shot down between the two firing poses, dropping the creeping step. */
                if (v3o == 0)
                    asm_crouch_walk_ticks = 0;
                v2m = ((asm_people[v3o].shot_timer)-- & 2) == 2 ? 4 : 5;
                /* At the count of one the shot goes off: one shooter a frame, and not one just hit or deeply stunned. */
                if ((asm_people[v3o].shot_timer & 3)
                    == 1) {
                    if (asm_shot_fired == 0
                        && (asm_people[v3o].flags & 2) == 0
                        && asm_people[v3o].stun < 99) {
                        /* Note the shooter, and put the muzzle flash six pixels ahead of him. */
                        asm_shooter = v3o;
                        asm_shot_fired = 1;
                        asm_flash_x =
                            dat_step_dx[asm_people[v3o].facing] * 6
                            + asm_cast_x[v3o];
                        asm_flash_y =
                            dat_step_dy[asm_people[v3o].facing] * 6
                            + asm_cast_y[v3o];
                        /* A guard always fires; the player only with a round left, and an empty gun clicks. */
                        if (asm_shooter != 0
                            || asm_rounds_left != 0)
                            c_draw_tile_2(
                                asm_people[v3o].facing * 20 - 6,
                                asm_flash_x, asm_flash_y);
                        if (asm_shooter == 0
                            && asm_rounds_left == 0)
                            c_sound_command(5);
                    } else
                        /* Anyone else holds the shot back to a later frame. */
                        (asm_people[v3o].shot_timer)++;
                }
            }
            if (v3o == 0) {
                /* The portrait top left mirrors the player's pose, with a frame of its own for standing still. */
                if (asm_throw_frames == 0)
                    drv_jump_gfx_copy_rect(dat_cast_frames, (((asm_walked != 0 || v2m != 0) ? v2m : 9)
                         + (asm_crouched & asm_crouch_walk_ticks & 1))
                        * 24, 160, 25, 40, shd_screen, 0, 0);
                else {
                    /* A throw plays its three frames, on the portrait and on the map alike. */
                    drv_jump_gfx_copy_rect(dat_cast_frames, (13 - (INT) asm_throw_frames) * 24, 160, 25, 40, shd_screen, 0, 0);
                    v2m = 19 - --asm_throw_frames;
                    asm_crouch_walk_ticks = 0;
                }
                /* Show the player's chance to hit, without firing. */
                c_resolve_shot(0, LONG_LIT(0));
                /* Shade the portrait up from the bottom as the player is overcome, or while a jump lands. */
                if (asm_people[0].stun >= 66
                    || (asm_jump_ticks != 0
                        && (INT) asm_jump_ticks < 6)) {
                    v4 = c_clamp(
                        (asm_people[0].stun - 64) / 2,
                        asm_jump_ticks, 38);
                    drv_real_fill_rect(shd_screen, 1, 39 - v4,
                                      23, v4, 7);
                }
                /* The player's own shot flashes on the portrait too. */
                if (asm_shot_fired != 0 && asm_shooter == 0
                    && asm_rounds_left != 0)
                    c_draw_tile_2(54, 10, 1);
            }
            /* A player past the wounds he can take lies fallen. */
            if (v3o == 0
                && ((asm_kit & 0x40) != 0 ? 3 : 1)
                   < asm_wounds)
                c_draw_tile_2(
                    166,
                    asm_cast_x[v3o],
                    asm_cast_y[v3o]);
            /* A stunned guard slumps, one way facing up and another otherwise. */
            else if (v3o != 0
                     && asm_people[v3o].stun > 32)
                c_draw_tile_2(
                    (dat_step_dy[asm_people[v3o].facing] == -1
                     ? 4 : 5) + 160,
                    asm_cast_x[v3o],
                    asm_cast_y[v3o]);
            /* Anyone not hidden is drawn in his pose: a guard eight columns along, a creeping player nine. */
            else if ((asm_people[v3o].flags
                      & 8) == 0)
                c_draw_tile_2(
                    (v3o != 0 ? 8
                     : ((asm_crouched & asm_crouch_walk_ticks & 1) != 0
                        ? 9 : 0))
                    + asm_people[v3o].facing
                      * 20 + v2m - 20,
                    asm_cast_x[v3o],
                    asm_cast_y[v3o]);
        } else
            asm_cast_x[v3o] = -1;
    }
    /* Move the dot of everyone in play and not out cold to where they now are on the floor plan. */
    for (v3o = 8; v3o >= 0; v3o--)
        if ((asm_people[v3o].flags & 0x80) != 0
            && asm_people[v3o].stun < 999) {
            drv_jump_gfx_copy_rect(shd_map_page, asm_blip_x[v3o], asm_blip_y[v3o], 2, 2, shd_screen, asm_blip_x[v3o], asm_blip_y[v3o]);
            asm_blip_x[v3o] =
                asm_people[v3o].x * 3
                / 16 + 180;
            asm_blip_y[v3o] =
                asm_people[v3o].y * 3
                / 16 + 100;
            /* A guard shows when near, further with the motion detector, or when his room is bugged or in a jailbreak. */
            if (v3o != 0) {
                v1k = c_cheap_distance(
                    asm_people[v3o].x
                    - asm_player_x,
                    asm_people[v3o].y
                    - asm_player_y);
                if (((asm_kit & 0x80) != 0 ? 256 : 96) > v1k
                    || (asm_rooms[asm_people[v3o].room].flags & 4) != 0
                    || asm_mission_kind == 2)
                    /* A hidden guard shows only at the easiest level; in his organisation's colour, blinking on CGA. */
                    if ((asm_people[v3o].flags
                         & 8) == 0 || shm_difficulty == 0)
                        c_fill_box(
                            asm_blip_x[v3o],
                            asm_blip_y[v3o],
                            asm_blip_x[v3o] + 1,
                            asm_blip_y[v3o] + 1,
                            (shm_cga & asm_frame_tick & 1) != 0
                            ? 0 : asm_belt_text);
            /* The player's own dot blinks. */
            } else if ((asm_frame_tick & 1) != 0 || v3o != 0)
                c_fill_box(
                    asm_blip_x[v3o],
                    asm_blip_y[v3o],
                    asm_blip_x[v3o]
                    + 1,
                    asm_blip_y[v3o]
                    + 1, 0);
        }
    /* Play out every shot that hit someone in the player's room. */
    for (v3o = 8; v3o >= 0; v3o--)
        if (asm_people[v3o].room
            == asm_room_last
            && (asm_people[v3o].flags & 0x80)
               != 0
            && (asm_people[v3o].flags & 2)
               != 0) {
            *(char *) &asm_people[v3o].flags &= 0xfd;
            /* The pose they were hit in. */
            if (asm_people[v3o].shot_timer == 0) {
                v2m = asm_people[v3o].kind;
                if ((asm_people[v3o].flags & 4)
                    != 0)
                    asm_people[v3o].kind = 7;
            } else
                v2m = ((asm_people[v3o].shot_timer + 1) & 2)
                      == 2 ? 4 : 5;
            /* Four frames of the hit over the figure, a moment apart. */
            for (v5b = 0; v5b < 4; v5b++) {
                drv_jump_gfx_copy_rect(shd_map_page, asm_cast_x[v3o], asm_cast_y[v3o], 15, 15, shd_screen, asm_cast_x[v3o], asm_cast_y[v3o]);
                c_draw_tile_2(
                    v5b + 160,
                    asm_cast_x[v3o],
                    asm_cast_y[v3o]);
                c_draw_tile_2(
                    (v3o != 0 ? 8 : 0)
                    + asm_people[v3o].facing
                      * 20 + v2m - 20,
                    asm_cast_x[v3o],
                    asm_cast_y[v3o]);
                c_wait_retraces(2);
            }
            /* A guard hit is down for good; the player takes a wound. */
            if (v3o != 0) {
                c_guard_knocked_down(v3o);
                asm_cast_x[v3o] =
                    asm_cast_y[v3o] = 0;
            } else {
                asm_wounds++;
                c_draw_kit_panel();
            }
        }
    /* The grenades and blasts go over everyone, then this frame's shot is fired. */
    c_step_effects(LONG_LIT(1));
    if (asm_shot_fired != 0)
        c_resolve_shot(asm_shooter, LONG_LIT(1));
}
