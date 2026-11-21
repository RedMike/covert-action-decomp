/* EFFECT.C -- stepping the traps and their blasts.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "BLIP.H"
#include "ALERTED.H"
#include "PAGESHOW.H"
#include "MAPDRAW.H"
#include "RANGE.H"
#include "PLAN.H"
#include "NOTHING.H"
#include "TILES.H"
#include "RANDOM.H"

/* Step every live effect on the board: draw it where it can be seen, let a
 * blast reach the people near it, and move a thrown one on a step. */
INT c_step_effects(LONG draw)
{
    INT v0j;        /* the kind this slot holds */
    INT v1j;        /* where it steps to, across, in pixels */
    INT v2j;        /* where it steps to, down, in pixels */
    INT v3j;        /* how far the blast has to carry */
    INT v4j;        /* the room it is in */
    INT v5j;        /* the person being reached */
    INT v6j;        /* set when the cell it steps to is an open door */
    INT v7j;        /* where on the screen it is drawn, across */
    INT v8j;        /* where on the screen it is drawn, down */
    INT v9j;        /* the slot being walked */
    INT v10c;       /* the cell it steps to, across */
    INT v11c;       /* the cell it steps to, down */
    INT v12c;       /* what the blast has to get through */
    INT v13c;       /* set when the player can see it */
    INT v14c;       /* the drawn position, one tile up */

    for (v9j = 0; v9j < 16; v9j++) {
        if (asm_grenades[v9j].flags != -1) {
            /* Where the grenade falls in the room view, and which room it is in. */
            v7j = asm_grenades[v9j].x
                - (asm_rooms[asm_room_last].left << 4) + asm_view_left;
            v8j = asm_grenades[v9j].y
                - (asm_rooms[asm_room_last].top << 4) + asm_view_top;
            v0j = asm_grenades[v9j].flags & 0x7f;
            v4j = asm_room_map[((asm_grenades[v9j].x / 16) << 5)
                + asm_grenades[v9j].y / 16];
            /* It shows in the view when it is in the player's room and not a set trap still waiting. */
            v13c = v4j == asm_room_last
                   && asm_grenades[v9j].timer
                      >= -63;
            /* The player's own grenade stays hidden while the throw is being drawn. */
            if (asm_throw_frames != 0
                && (asm_grenades[v9j].flags & 0x80)
                   == 0)
                v13c = 0;
            /* A grenade going off runs its blast a frame a call, the player's stun grenade
             * all its frames at once; a set trap still waiting is left be. */
            if (asm_grenades[v9j].timer < 0
                && asm_grenades[v9j].timer > -9998
                && (INT) draw != 0)
                do {
                    /* Draw this frame; a stun grenade flashes the screen, and so does any grenade going off. */
                    if (v13c != 0) {
                        c_draw_tile_2(
                            (asm_grenades[v9j].timer & 7) + 168,
                            v7j - 8, v14c = v8j - 8);
                        if (v0j == 0)
                            c_draw_tile_2(
                                (*(UNSIGNED_INT *) &asm_grenades[v9j].timer & 3) + 160,
                                v7j - 8, v14c);
                        if (v0j == 2
                            || asm_grenades[v9j].timer == -63) {
                            c_set_palette_record(2);
                            c_set_palette_record(1);
                            asm_palette_flash = 1;
                        }
                    }
                    /* The moment it goes off: its blast lands now. */
                    if (asm_grenades[v9j].timer
                        == -63) {
                        /* Gas lingers sixteen frames, the others eight; the plan loses the trap's cross. */
                        asm_grenades[v9j].timer =
                            asm_grenades[v9j].flags == 1 ? -16 : -8;
                        c_draw_plan(180, 100, 3);
                        /* Anything but gas is heard, one sound in the player's room and another elsewhere. */
                        if (v0j != 1)
                            c_sound_command(v4j == asm_room_last ? 7 : 8);
                        /* The player's own bang raises the alarm on that room and counts against the player. */
                        if (v0j != 1
                            && (asm_grenades[v9j].flags & 0x80) == 0) {
                            c_room_distances(v4j, 240);
                            asm_seen_count++;
                        }
                        /* A blast out of sight still flashes the screen. */
                        if (v4j != asm_room_last) {
                            c_set_palette_record(4);
                            c_set_palette_record(1);
                            asm_palette_flash = 1;
                        }
                        /* Reach everyone in play in that room, the player included. */
                        for (v5j = 0; v5j <= 8; v5j++)
                            if (asm_people[v5j].room == v4j
                                && (asm_people[v5j].flags & 0x80) != 0) {
                            v3j = c_cheap_distance(
                                asm_people[v5j].x
                                - asm_grenades[v9j].x,
                                asm_people[v5j].y
                                - asm_grenades[v9j].y);
                            /* Harder difficulties put guards further from a blast and the player nearer. */
                            if (v5j != 0)
                                v3j = v3j * (shm_difficulty + 2) / 4;
                            else
                                v3j = v3j * 4 / (shm_difficulty + 2);
                            /* Being down low, and a doorway or wall between, each cut what reaches. */
                            v12c = (asm_people[v5j].flags & 4) != 0 ? 2 : 1;
                            v12c += 2 - c_line_of_sight(
                                asm_grenades[v9j].x,
                                asm_grenades[v9j].y,
                                asm_people[v5j].x,
                                asm_people[v5j].y);
                            /* Fragmentation close enough fells a guard for good or wounds the player. */
                            if (v0j == 0 && 40 / v12c > v3j) {
                                if (v5j != 0)
                                    c_guard_knocked_down(v5j);
                                else {
                                    asm_wounds++;
                                    c_draw_kit_panel();
                                }
                            }
                            /* A stun grenade stuns, more the nearer and the more exposed, up to 999. */
                            if (v0j == 2)
                                asm_people[v5j].stun =
                                    c_clamp(
                                        asm_people[v5j].stun,
                                        (160 - v3j) / v12c, 999);
                        }
                    }
                    /* The blast is over: wipe it off the view and free the slot. */
                    if (++asm_grenades[v9j].timer
                        == 0) {
                        if (v13c != 0)
                            drv_jump_gfx_copy_rect(shd_map_page, v7j - 8, v8j - 8, 15, 15, shd_screen, v7j - 8, v8j - 8);
                        /* Gas leaves its room gassed, and the plan shows it. */
                        if (v0j == 1) {
                            asm_rooms[v4j].flags |= 0x10;
                            c_draw_plan(180, 100, 3);
                        }
                        asm_grenades[v9j].flags =
                            -1;
                    }
                } while (asm_grenades[v9j].flags
                         == 2
                         && asm_grenades[v9j].timer
                            > -63);
            /* A grenade in flight: rub out its dot in the view and on the plan. */
            if (asm_grenades[v9j].timer > 0) {
                if (v13c != 0)
                    drv_jump_gfx_copy_rect(shd_map_page, v7j, v8j, 1, 1, shd_screen, v7j, v8j);
                v7j = asm_grenades[v9j].x * 3
                      / 16 + 180;
                v8j = asm_grenades[v9j].y * 3
                      / 16 + 100;
                drv_jump_gfx_copy_rect(shd_map_page, v7j, v8j, 1, 1, shd_screen, v7j, v8j);
                /* Step it on, and see whether the step leaves the room other than by an open door. */
                v1j = dat_move_dx[asm_grenades[v9j].dir]
                    + asm_grenades[v9j].x;
                v2j = dat_move_dy[asm_grenades[v9j].dir]
                    + asm_grenades[v9j].y;
                v10c = v1j / 16;
                v11c = v2j / 16;
                v6j = (asm_floor_map[(v10c << 5) + v11c] & 0x80)
                          != 0
                      && (dat_floor_objects[(asm_floor_map[(v10c << 5) + v11c]
                               & 0x3f)].flags & FOBJ_DOOR) != 0;
                /* A wall stops it: it falls back two steps and goes off at once. */
                if (asm_room_map[(v10c << 5) + v11c] != v4j
                    && v6j == 0) {
                    asm_grenades[v9j].timer = 1;
                    asm_grenades[v9j].x -=
                        dat_move_dx[asm_grenades[v9j].dir] * 2;
                    asm_grenades[v9j].y -=
                        dat_move_dy[asm_grenades[v9j].dir] * 2;
                } else {
                    asm_grenades[v9j].x = v1j;
                    asm_grenades[v9j].y = v2j;
                }
                /* Put its dot down again where it now is, in the view and on the plan. */
                if (v13c != 0) {
                    v7j = asm_grenades[v9j].x
                        - (asm_rooms[asm_room_last].left << 4)
                        + asm_view_left;
                    v8j = asm_grenades[v9j].y
                        - (asm_rooms[asm_room_last].top << 4)
                        + asm_view_top;
                    c_board_dot(v7j, v8j, 10);
                }
                v7j = asm_grenades[v9j].x * 3
                      / 16 + 180;
                v8j = asm_grenades[v9j].y * 3
                      / 16 + 100;
                c_board_dot(v7j, v8j, 10);
                /* At the end of its flight it goes off. */
                if (--asm_grenades[v9j].timer == 0)
                    asm_grenades[v9j].timer = -63;
            }
        }
    }
}
