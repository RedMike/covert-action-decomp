/* ALERT.C -- resolving a shot, and the meter of the chance to hit.
 */
#include "TAC.H"
#include "ALERTED.H"
#include "RANDOM.H"
#include "PAGESHOW.H"
#include "CITY.H"
#include "MAPDRAW.H"
#include "RANGE.H"
#include "NOTHING.H"
#include "TILES.H"
#include "OCTANT.H"
#include "TRAP.H"

/* Resolve a shot: guard `who` firing at the player, or with `who` 0 the player
 * spending a round on the nearest guard ahead who can see him. With `heard`
 * the hit is rolled and the shot played; without, only the meter of the
 * chance to hit is drawn. */
INT c_resolve_shot(INT who, INT heard)
{
    INT v0j;    /* the closest anyone has been so far */
    INT v1j;    /* how far away this one is */
    INT v2k;    /* who the shot is at: 0 the player, -1 nobody */
    INT v3l;    /* the chance to hit, out of four */
    INT v4m;    /* which way the guard is from the player */
    INT v5m;    /* the person being tried */
    INT v6n;    /* how far across */
    INT v7o;    /* how far down */
    INT v8;     /* the meter's icon */

    /* A guard can only aim at a player he can see. */
    if (who != 0) {
        v2k = 0;
        if (c_guard_sees_player(who) == 0)
            v2k = -1;
    } else {
        /* The player cannot fire with no rounds left. */
        if (asm_rounds_left == 0)
            return;
        /* A real shot spends a round, and the panel and map show it. */
        if (heard != 0) {
            asm_rounds_left--;
            c_draw_kit_panel();
            asm_conspicuous = 1;
        }
        /* The player's target is the nearest guard ahead who can see him. */
        v2k = -1;
        v0j = 9999;
        for (v5m = 1; v5m <= 8; v5m++) {
            /* Only a guard in play, in the player's room and not out cold. */
            if ((asm_people[v5m].flags & 0x80)
                == 0
                || asm_people[v5m].room
                   != asm_room_last
                || asm_people[v5m].stun
                   > 999)
                continue;
            v6n = asm_people[v5m].x
                  - asm_player_x;
            v7o = asm_people[v5m].y
                  - asm_player_y;
            /* Only within the quarter turn centred on the player's facing. */
            v4m = c_octant(v6n, v7o);
            if (v4m != asm_facing
                && ((asm_facing - 2) & 7) + 1 != v4m)
                continue;
            if (c_guard_sees_player(v5m) == 0)
                continue;
            /* Keep the nearest so far. */
            v1j = c_cheap_distance(v6n, v7o);
            if (v1j < v0j) {
                v2k = v5m;
                v0j = v1j;
            }
        }
    }
    v3l = 0;
    if (v2k != -1) {
        /* Range from the shooter to the target. */
        v1j = c_cheap_distance(
            asm_people[who].x
            - asm_people[v2k].x,
            asm_people[who].y
            - asm_people[v2k].y);
        if (v2k == 0) {
            /* A guard firing at the player: he has been seen, and the alarm
             * goes up on his room. */
            asm_seen_count++;
            c_room_distances(asm_room_last, 240);
            /* The guard's aim builds with his alertness, faster the harder the
             * game, and a player not walking is easier to hit. */
            v3l = asm_people[who].alert
                  / (5 - shm_difficulty);
            if (asm_last_move_type != 1)
                v3l++;
            /* The easiest level gives guards a flat chance. */
            if (shm_difficulty == 0)
                v3l = 1;
        } else {
            /* The player firing at a guard: half the guard's field_18 count,
             * one better with the Uzi, and a real shot spends that count. */
            v3l = asm_people[v2k].field_18 / 2;
            if ((asm_kit & 2) != 0)
                v3l++;
            if (heard != 0)
                asm_people[v2k].field_18 = 0;
        }
        /* The chance falls by one for every 48 pixels, three cells, of range. */
        v3l += 1 - v1j / 48;
        if (heard != 0) {
            /* A guard who has fired must work his aim up again. */
            if (v2k == 0)
                asm_people[who].alert = 0;
            /* A hit marks the target and plays the hit for the gun fired. */
            if ((INT) c_random_below(4) < v3l) {
                asm_people[v2k].flags |= 2;
                c_sound_command(v2k == 0 ? 3
                                   : ((asm_kit & 2) != 0 ? 6 : 4));
            } else {
                /* A miss plays the miss, and the noise brings the alarm to
                 * the player's room and gives away the cell he stands on. */
                c_sound_command(v2k == 0 ? 33
                                   : ((asm_kit & 2) != 0
                                      ? 6 : 34));
                c_room_distances(asm_room_last, 240);
                asm_player_cell = asm_player_x / 16;
                asm_player_cell_row = asm_player_y / 16;
            }
        }
    /* A shot at nobody still makes its noise. */
    } else if (heard != 0)
        c_sound_command(34);
    /* A real shot flashes the screen for one retrace. */
    if (heard != 0) {
        c_set_palette_record(3);
        c_wait_retraces(1);
        c_set_palette_record(0);
    /* Otherwise colour the meter's icon by the chance to hit. */
    } else if (v3l != 0) {
        v8 = dat_meter_colours[c_clamp(v3l, 0, 4)];
        drv_jump_gfx_sprite_put(shd_screen, 4, 1, asm_kit_sprites[14]);
        drv_jump_gfx_fill(shd_screen, 4, 1, 16, 16, 1, v8);
    }
}
