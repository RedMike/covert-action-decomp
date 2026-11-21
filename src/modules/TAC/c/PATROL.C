/* PATROL.C -- one guard's turn.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "ALERTED.H"
#include "RANDOM.H"
#include "RANGE.H"
#include "TILES.H"
#include "DOOR.H"
#include "OCTANT16.H"
#include "PATROL.H"
#include "PLACE.H"
#include "SIGNOF.H"
#include "TRAP.H"
#include "WAYOUT.H"

/* One guard's turn: notice, chase, shoot, open a door, pick the next step and
 * walk it. Guard 1's turn first clears the counts the whole floor shares. */
INT c_guard_turn(INT a)
{
    INT v1i;    /* how far the candidate step is from everything that matters */
    INT v0j;    /* the step count on the guard's own cell */
    INT v2i;    /* whether the guard is in the target room with the alarm up */
    INT v4h;    /* which try */
    INT v3i;    /* the step count on the cell a trial step would enter */
    INT v5h;    /* the best distance a trial step reached */
    INT v6h;    /* and the column it reached it at */
    INT v8g;    /* the doorway the guard is heading for */
    INT v7h;    /* the thing, the direction or the corner being stepped */
    INT v9g;    /* the row the best trial step reached */
    INT v10;    /* whether the guard has somewhere of its own to be */
    INT v12o;   /* the chosen step, in pixels across */
    INT v11;    /* the lowest step count a step reached */
    INT v13o;   /* the guard's own column */
    INT v15n;   /* and its row */
    INT v14o;   /* the chosen step, in pixels down */
    INT v16n;   /* how far across the thing being measured is */
    INT v17n;   /* and how far down */
    INT v19m;   /* the direction of it, or the distance to it */
    INT v18n;   /* the room the guard is in */
    INT v20f;   /* the map cell being looked at */

    /* A new round: last round's count of guards at the target is kept, and the
     * counts this round makes start again. */
    if (a == 1) {
        asm_guard_seen = asm_guards_at_target;
        asm_guards_at_target = asm_seen_longest =
            asm_guards_awake =
            shm_activity.city[0] = asm_guard_in_room = 0;
        /* On the first tick, note every room's distance from the guards' post,
         * then measure from the payload room. */
        if (asm_frame_tick == 0) {
            c_room_distances(asm_guard_room, 0);
            for (v7h = 0; v7h < 24; v7h++)
                asm_guard_distances[v7h] =
                    asm_rooms[v7h].distance;
            c_room_distances(asm_payload_room, 0);
        }
        /* Acting up in the payload room, with the suspect there, sets the alarm off. */
        if (asm_conspicuous != 0 && asm_suspect_here != -1
            && asm_room_last == asm_payload_room)
            c_room_distances(asm_payload_room, 240);
    }
    /* Every sixteen ticks bring an absent guard in: at the start, at random as the alarm
     * runs, or in a jailbreak or with asm_high_security set, on his turn of a rota. */
    if ((asm_people[a].flags & 0x80) == 0
        && (asm_frame_tick & 0xf) == 0
        && ((asm_mission_kind != 2
             && ((INT) c_random_below(1000 / (shm_difficulty + 1))
                 < asm_guard_alert
                 || asm_frame_tick == 0))
            || ((asm_mission_kind == 2 || asm_high_security != 0)
                && (a & 7) == (asm_frame_tick >> 5 & 7))))
        c_place_person(a);
    /* A guard still not on the floor has no turn. */
    if ((asm_people[a].flags & 0x80) == 0)
        return;
    /* Count him if he is awake, and again if he is still on his feet. */
    if (asm_people[a].stun < 999)
        asm_guards_awake++;
    if (asm_people[a].stun < 24)
        shm_activity.city[0]++;
    /* Count him at the target room, awake or, on the easier levels, not; two
     * there with the player elsewhere and the alarm stops pointing at it. */
    if (asm_people[a].room == asm_target_room
        && (asm_people[a].stun < 999
            || shm_difficulty < 2)) {
        asm_guards_at_target++;
        if ((INT) asm_guards_at_target >= 2
            && asm_target_room != asm_room_last)
            c_room_distances(-1, 0);
    }
    /* In a jailbreak, an enemy on his feet in the prisoner's room while the
     * player is away frees the prisoner, and it is over. */
    if (asm_mission_kind == 2
        && asm_people[a].room
           == asm_payload_room
        && asm_people[a].stun < 24
        && asm_room_last != asm_payload_room)
        shm_finished = 1;
    /* The cell he stands on. */
    v13o = asm_people[a].x / 16;
    v15n = asm_people[a].y / 16;
    /* A guard on his feet who sees the player, except on an escape after capture. */
    if (c_guard_sees(a) != 0
        && asm_people[a].stun < 24
        && asm_mission_kind != 1) {
        /* A disguise holds only so long in a room, less the harder the game,
         * and never while the player faces the guard; then he takes aim faster. */
        if (asm_disguised != 0) {
            v16n = asm_people[a].x
                   - asm_people[0].x;
            v17n = asm_people[a].y
                   - asm_people[0].y;
            v19m = c_facing8(v16n, v17n);
            v19m = abs(v19m - asm_people[0].facing);
            if (256 / (shm_difficulty + 1) < (INT) ++asm_guard_turn_at
                || v19m < 2 || v19m > 6) {
                asm_people[a].alert += 2;
                goto stepped;
            }
        } else {
            /* Undisguised, he takes aim, drops what he was doing, and marks
             * where the player was seen. */
            (asm_people[a].alert)++;
            *(char *) &asm_people[a].flags &= 0xfe;
            asm_player_cell = asm_player_x / 16;
            asm_player_cell_row = asm_player_y / 16;
            asm_people[a].field_14 = 1;
            goto stepped;
        }
    }
    /* Not seeing the player, or fooled by the disguise, he has no aim. */
    asm_people[a].alert = 0;
stepped:
    /* While he has the player in view, acting up in front of him on his feet
     * gives the player away and sets the alarm off here. */
    if (asm_guard_sees != 0) {
        if (asm_conspicuous != 0
            && asm_people[a].stun < 24) {
            asm_disguised = 0;
            c_room_distances(asm_room_last, 240);
        }
        /* Time the sighting, and keep the longest any awake guard has had. */
        (asm_people[a].field_18)++;
        if (asm_people[a].field_18
            > (INT) asm_seen_longest
            && asm_people[a].stun < 999)
            asm_seen_longest =
                asm_people[a].field_18;
    } else
        asm_people[a].field_18 = 0;
    /* An awake guard in the player's room makes the joystick's fire button shoot. */
    if (asm_people[a].room == asm_room_last) {
        if (asm_people[a].stun < 999)
            asm_guard_in_room = 1;
        /* He shows while he sees the player, fires, or there is no alarm here;
         * otherwise, lying in wait, he hides from view, on a fourth tick. */
        if (asm_guard_sees != 0
            || asm_people[a].shot_timer != 0
            || asm_guard_alert == 0
            || asm_target_room != asm_room_last)
            *(char *) &asm_people[a].flags &= 0xf7;
        else if ((asm_frame_tick & 3) == 0)
            asm_people[a].flags |= 8;
    }
    /* Gas in his room overcomes him, sparing guards 4 and 8. */
    if ((asm_rooms[asm_people[a].room].flags & 0x10)
        != 0 && (a & 3) != 0)
        asm_people[a].stun += 2;
    /* Being stunned wears off; while it is deep he slumps and does nothing. */
    if (asm_people[a].stun != 0) {
        (asm_people[a].stun)--;
        if (asm_people[a].stun > 32) {
            asm_people[a].alert = 0;
            asm_people[a].flags |= 4;
            return;
        }
    }
    /* With the alarm on in the player's room, he crouches every eighth tick, and
     * stands again where no cover near him hides where the player was seen. */
    if (asm_people[a].room == asm_target_room
        && asm_target_room == asm_room_last && asm_guard_alert != 0
        && (asm_frame_tick & 7) == 0) {
        asm_people[a].flags |= 4;
        if (asm_player_cell != 0
            && (INT) c_line_of_sight(
                   asm_people[a].x,
                   asm_people[a].y,
                   (asm_player_cell << 4) + 8,
                   (asm_player_cell_row << 4) + 8)
               + (INT) (asm_guard_tick & 1) >= 2)
            *(char *) &asm_people[a].flags &= 0xfb;
    }
    /* Taking aim, he turns to face the player. */
    if (asm_people[a].alert != 0) {
        v16n = asm_player_x
               - asm_people[a].x;
        v17n = asm_player_y
               - asm_people[a].y;
        v19m = c_facing8(v16n, v17n);
        if (v19m != 0)
            asm_people[a].facing = v19m;
        /* Aimed long enough, sooner the harder the game, he sets the alarm off
         * here, draws the patrols to this room, fires, and stands to do it. */
        if (asm_people[a].room
            == asm_room_last
            && (5 - shm_difficulty) * 7 - 6
               < asm_people[a].alert) {
            c_room_distances(asm_room_last, 240);
            asm_room_seen_tick[asm_room_last] = 0;
            if (asm_people[a].shot_timer == 0)
                asm_people[a].shot_timer += 4;
            asm_people[a].field_14 = 9;
            *(char *) &asm_people[a].flags &= 0xfb;
        }
    }
    /* A guard who has walked out onto the street leaves the floor, back among
     * the guards still to come. */
    v18n = asm_room_map[(v13o << 5) + v15n];
    if (v18n == 0) {
        *(char *) &asm_people[a].flags &= 0x7f;
        asm_guards_to_come++;
        return;
    }
    /* Finding signs of the player in his room, a body or something left open,
     * he raises the alarm there, or with one already up sets it to 240. */
    if ((asm_rooms[v18n].flags & 8) != 0) {
        asm_rooms[v18n].flags &= 0xf7;
        if (asm_guard_alert == 0)
            c_room_distances(v18n, 240);
        else
            asm_guard_alert = 240;
    }
    /* Whether he is hunting: in the alarm's room while it runs. */
    v2i = asm_people[a].room == asm_target_room
          && asm_guard_alert != 0;
    /* With no goal, no wait and no shot under way, he picks where to go next. */
    if (asm_people[a].field_6 == -1
        && asm_people[a].field_14 == 0
        && asm_people[a].shot_timer == 0) {
        v10 = 0;
        v4h = 0;
        /* Hunting, he tries 16 free cells, 32 if none will do, for the one nearest him
         * and where the player was seen that has cover from that spot. */
        if (v2i != 0) {
            v5h = 999;
            v6h = -1;
            do {
                v16n = asm_rooms[v18n].left
                       + c_random_below(
                             asm_rooms[v18n].width);
                v17n = asm_rooms[v18n].top
                       + c_random_below(
                             asm_rooms[v18n].height);
                v20f = asm_floor_map[(v16n << 5) + v17n];
                v1i = (INT) abs(v16n - (INT) asm_player_cell)
                      + (INT) abs(v17n - (INT) asm_player_cell_row);
                v1i += (INT) abs(v16n - v13o) + (INT) abs(v17n - v15n);
                if (v20f == -1 && v1i < v5h
                    && (INT) c_line_of_sight((v16n << 4) + 8, (v17n << 4) + 8,
                                             (asm_player_cell << 4) + 8,
                                             (asm_player_cell_row << 4) + 8)
                       + (INT) (asm_guard_tick & 1) < 2) {
                    v6h = v16n;
                    v9g = v17n;
                    v5h = v1i;
                }
                v4h++;
            } while (v4h < 16 || (v4h < 32 && v6h == -1));
        } else {
            /* Otherwise he looks round for something worth minding, longer in a room
             * that scores more, shorter as the organisation and the trouble grow. */
            do {
                v6h = asm_rooms[v18n].left
                      + c_random_below(
                            asm_rooms[v18n].width);
                v9g = asm_rooms[v18n].top
                      + c_random_below(
                            asm_rooms[v18n].height);
                v20f = asm_floor_map[(v6h << 5) + v9g];
                if (v20f != -1
                    && (dat_floor_objects[(v20f & 0x3f)].flags & (FOBJ_BUGGABLE | FOBJ_PHOTOGRAPHABLE | FOBJ_DOOR | FOBJ_TERMINAL)) != 0)
                    v10 = 1;
                if (v10 != 0)
                    break;
            } while (dat_room_kinds[asm_rooms[v18n].kind].score
                     - asm_org_alert_level / 16 - asm_seen_count * 2
                     > ++v4h);
            /* Finding nothing, with an alarm elsewhere, or with gas in the room,
             * he makes for the doorway to the next room. */
            if (v10 == 0
                || (asm_guard_alert != 0 && v18n != asm_target_room)
                || (asm_rooms[v18n].flags & 0x10) != 0) {
                v8g = c_next_room(v18n, a);
                c_doorway_cell(v18n, v8g, &v6h, &v9g);
                asm_people[a].flags |= 1;
            }
            /* But a kind 2 guard at his post with all quiet stays, and wanders
             * to a random cell of the room instead. */
            if (v10 == 0 && c_guard_alertness(a) == 2
                && asm_people[a].room
                   == asm_guard_room
                && asm_guard_alert == 0) {
                v6h = asm_rooms[v18n].left
                      + c_random_below(
                            asm_rooms[v18n].width);
                v9g = asm_rooms[v18n].top
                      + c_random_below(
                            asm_rooms[v18n].height);
                *(char *) &asm_people[a].flags &= 0xfe;
            }
        }
        /* Nowhere found, he stays where he is. */
        if (v6h == -1) {
            v6h = v13o;
            v9g = v15n;
        }
        /* Lay the route; a guard who cannot reach his goal, out of the player's
         * room, leaves the floor, back among the guards still to come. */
        c_flood_path(a, v18n, v13o, v15n, v6h, v9g);
        if (asm_step_map[a][(v13o << 5) + v15n] == 0
            && asm_people[a].room
               != asm_room_last) {
            *(char *) &asm_people[a].flags &= 0x7f;
            asm_guards_to_come++;
            return;
        }
        asm_people[a].field_6 = v6h;
        asm_people[a].field_8 = v9g;
        asm_people[a].room = v18n;
    }
    /* An awake guard who comes near a booby trap in his room sets it off. */
    if (asm_people[a].stun == 0)
        for (v7h = 0; v7h < 16; v7h++)
            if (asm_grenades[v7h].flags != -1
                && asm_grenades[v7h].timer
                   == -9998
                && (INT) abs(
                       asm_grenades[v7h].x
                       - asm_people[a].x)
                   + (INT) abs(
                         asm_grenades[v7h].y
                         - asm_people[a].y)
                   < 24
                && asm_room_map[((asm_grenades[v7h].x / 16) << 5)
                    + asm_grenades[v7h].y / 16]
                   == asm_people[a].room) {
                asm_grenades[v7h].timer = -63;
                break;
            }
    /* With no wait and no shot under way, he walks. */
    if (asm_people[a].field_14 == 0
        && asm_people[a].shot_timer == 0) {
        /* The next cell is the neighbour one step nearer the goal, or the
         * lowest count off the route; a straight step beats a diagonal. */
        v0j = asm_step_map[a][(v13o << 5) + v15n];
        v11 = 999;
        v19m = 0;
        for (v7h = 0; v7h <= 8; v7h++) {
            v3i = asm_step_map[a][((dat_step_dx[v7h] + v13o) << 5)
                            + dat_step_dy[v7h] + v15n];
            if (v3i != 0
                && (v0j - 1 == v3i || (v0j == 0 && v3i < v11))
                && (v19m == 0 || (v7h & 1) != 0)) {
                v19m = v7h;
                v11 = v3i;
            }
        }
        /* Head for the centre of that cell. */
        v12o = ((dat_step_dx[v19m] + v13o)
                << 4) + 8;
        v14o = ((dat_step_dy[v19m] + v15n)
                << 4) + 8;
        v16n = (v12o - asm_people[a].x) / 2;
        v17n = (v14o - asm_people[a].y) / 2;
        v19m = *(INT *) ((char *) dat_step_facing + 8
                                  + c_sign(v16n) * 6 + c_sign(v17n) * 2);
        /* Facing that way he steps, a pixel at a time crouched; otherwise he
         * turns an eighth the shorter way, standing up while he turns. */
        if (v19m != 0) {
            if (asm_people[a].facing == v19m) {
                if ((asm_people[a].flags & 4) != 0) {
                    asm_people[a].x +=
                        dat_step_dx[v19m];
                    asm_people[a].y +=
                        dat_step_dy[v19m];
                } else {
                    asm_people[a].x +=
                        dat_move_dx[v19m];
                    asm_people[a].y +=
                        dat_move_dy[v19m];
                }
            } else {
                if (((v19m - asm_people[a].facing)
                     & 7) < 4)
                    (asm_people[a].facing)++;
                else
                    (asm_people[a].facing)--;
                asm_people[a].facing =
                    ((asm_people[a].facing - 1) & 7)
                    + 1;
                if (asm_people[a].facing != v19m)
                    *(char *) &asm_people[a].flags &= 0xfb;
            }
        }
        /* The walking pose moves on. */
        asm_people[a].kind =
            ++asm_people[a].kind & 3;
        /* No step left to take: he has arrived. */
        if ((INT) abs(v16n) < 2 && (INT) abs(v17n) < 2) {
            /* He faces his goal, or standing on it, the way what is there faces. */
            v16n = asm_people[a].field_6
                   - v13o;
            v17n = asm_people[a].field_8
                   - v15n;
            v19m = *(INT *) ((char *) dat_step_facing + 8
                                  + c_sign(v16n) * 6 + c_sign(v17n) * 2);
            if (v19m != 0)
                asm_people[a].facing = v19m;
            else
                asm_people[a].facing =
                    (asm_floor_map[(v13o << 5) + v15n]
                     & 3) * 2 + 1;
            /* Hunting, he picks a new spot next turn, and with no grenade thrown lately he lobs
             * a fragmentation one where the player was seen, if in line and middling range. */
            if (v2i != 0) {
                asm_people[a].field_6 = -1;
                v16n = (asm_player_cell << 4)
                       - asm_people[a].x;
                v17n = (asm_player_cell_row << 4)
                       - asm_people[a].y;
                v19m = 0;
                if ((INT) abs(v16n) < 12 || (INT) abs(v17n) < 12
                    || (INT) abs((INT) abs(v16n)
                                     - (INT) abs(v17n)) < 12) {
                    v19m = c_facing8(v16n, v17n);
                    v1i = c_cheap_distance(v16n, v17n);
                    if (v1i > 32 && v1i < 112
                        && asm_frame_tick
                           - asm_last_grenade_tick > (5 - shm_difficulty) * 8) {
                        c_add_grenade(
                            asm_people[a].x,
                            asm_people[a].y,
                            v19m, (v1i + 16) / 32, 0x80);
                        asm_last_grenade_tick = asm_frame_tick;
                    }
                }
                /* Then he waits a moment, less the harder the game. */
                asm_people[a].field_14 =
                    c_random_below(8) + (4 - shm_difficulty) * 4;
            } else {
                /* Otherwise he stands and waits a while, less the harder the game. */
                asm_people[a].field_14 =
                    c_random_below(8) + (4 - shm_difficulty) * 6;
                asm_people[a].kind = 0;
                /* What opens at his goal he opens, counting it in the player's
                 * room if it is not a door, and lingers over it unless passing through. */
                v20f = asm_floor_map[(asm_people[a].field_6 << 5)
                    + asm_people[a].field_8];
                if (v20f != -1
                    && asm_people[a].field_6
                       != -1) {
                    v20f &= 0x3f;
                    if ((dat_floor_objects[v20f].flags
                         & FOBJ_OPENABLE) != 0) {
                        if (asm_people[a].room
                            == asm_room_last
                            && (dat_floor_objects[v20f].flags & FOBJ_DOOR) == 0)
                            asm_room_seen++;
                        asm_floor_map[(asm_people[a].field_6 << 5)
                            + asm_people[a].field_8] |= 0x80;
                        c_draw_cell(
                            asm_people[a].field_6,
                            asm_people[a].field_8);
                        if ((asm_people[a].flags & 1)
                            == 0)
                            asm_people[a].field_14 += 18;
                    }
                }
            }
            /* At a doorway into the alarm's room, empty last round, on the harder levels
             * he lobs a stun grenade through; either way he turns about while he waits. */
            if ((asm_people[a].flags & 1) != 0) {
                if (asm_difficulty_was > 1 && asm_guard_alert != 0
                    && asm_guard_seen == 0
                    && asm_room_map[((dat_step_dx[asm_people[a].facing]
                        + v13o) << 5) + dat_step_dy[asm_people[a].facing] + v15n] == asm_target_room) {
                    asm_people[a].field_14 =
                        c_random_below(3) * 5 + 9;
                    c_add_grenade(
                        asm_people[a].x,
                        asm_people[a].y,
                        asm_people[a].facing,
                        asm_people[a].field_14
                        / 5, 0x82);
                }
                asm_people[a].facing =
                    ((asm_people[a].facing + 3) & 7)
                    + 1;
            }
        }
    }
    /* When his wait runs out, he shuts whatever opens at his goal and drops the goal. */
    if (asm_people[a].field_14 != 0
        && --asm_people[a].field_14 == 0) {
    v20f = asm_floor_map[(asm_people[a].field_6 << 5) + asm_people[a].field_8];
    if (v20f != -1
        && asm_people[a].field_6 != -1) {
        v20f &= 0x3f;
        if ((dat_floor_objects[v20f].flags & FOBJ_OPENABLE) != 0) {
            if (asm_people[a].room
                == asm_room_last
                && (dat_floor_objects[v20f].flags & FOBJ_DOOR)
                   == 0)
                asm_room_seen--;
            asm_floor_map[(asm_people[a].field_6 << 5)
                + asm_people[a].field_8] &= 0x7f;
            c_draw_cell(
                asm_people[a].field_6,
                asm_people[a].field_8);
        }
    }
    asm_people[a].field_6 = -1;
    /* Passing through, he steps into the next room, facing into it, and comes
     * through with a head start on taking aim. */
    if ((asm_people[a].flags & 1) != 0) {
    for (v7h = 0; v7h < 4; v7h++) {
        v16n = dat_side_dx[v7h] + v13o;
        v17n = dat_side_dy[v7h] + v15n;
        if (asm_people[a].room
            != asm_room_map[(v16n << 5) + v17n]) {
            asm_people[a].x =
                (v16n << 4) + 8;
            asm_people[a].y =
                (v17n << 4) + 8;
            asm_people[a].room =
                asm_room_map[(v16n << 5) + v17n];
            asm_people[a].facing = v7h * 2 + 1;
            asm_people[a].alert = 10;
            break;
        }
    }
    *(char *) &asm_people[a].flags &= 0xfe;
    }
    }
}
