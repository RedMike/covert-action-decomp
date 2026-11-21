/* STEP.C -- one tick of the chase.
 */
#include "CHASE.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "SETUP.H"
#include "RANDOM.H"
#include "JOYWAIT.H"
#include "MENU1.H"
#include "SIGHT.H"
#include "KEYREAD.H"
#include "NEARCAR.H"
#include "BOARDMAR.H"
#include "STREET.H"
#include "DOOR1.H"
#include "NOTHING.H"
#include "BOARDDRA.H"
#include "DASHBOAR.H"
#include "CARSPEC.H"

/* One tick of the chase: read a key, then move and draw the three cars. At a
 * crossing a car picks its way from the keys, towards its destination or
 * towards where car 0 was last seen, and it steps when its gear allows.
 *
 * The locals' names fix their frame slots.
 */
INT c_chase_step(void)
{
    INT v0j;                            /* tries at picking a direction */
    INT v1j;                            /* how far car 0 is in sight */
    INT v2j;                            /* the gap across the car's facing */
    INT v3j;                            /* the direction it will take */
    INT v4j;                            /* the car */
    INT v5j;                            /* never read */
    INT v6j;                            /* the follower being tested */
    INT v7j;                            /* whether the car moved this tick */
    INT v8j;                            /* its cell, across */
    INT v9j;                            /* the key */
    INT v10c;                           /* the gap to the mark, across */
    INT v11c;                           /* its cell, down */
    INT v12c;                           /* the gap along the car's facing */
    INT v13c;                           /* the gap to the mark, down */
    INT v14c;                           /* whether it shows at its mark */

    /* Tailing, the player's cars set off in second once the board has been up a moment. */
    if (asm_chase_kind != 2 && asm_frame_tick == 32) {
        asm_cars[1].gear = asm_cars[2].gear = 2;
        c_sound_command(22);
        asm_engine_note = asm_cars[asm_active_car].gear;
        c_sound_command(27);
        c_sound_command(26);
        c_wait_for_release();
    }
    /* After that, the keys drive. */
    if (drv_jump_keyboard_empty() == 0 && asm_frame_tick > 32) {
        v9j = c_menu_key();
        switch (v9j) {
        /* How fast the game runs: fast, medium or slow. */
        case KEY_F:
            asm_game_speed = 2;
            break;
        case KEY_D:
            asm_game_speed = 1;
            break;
        case KEY_S:
            asm_game_speed = 0;
            break;
        /* Let the car drive itself after the suspect. */
        case KEY_F10:
            asm_cars[asm_active_car].locked_on = 1;
            break;
        /* Turn that way at the next junction, taking the wheel back from the car. */
        case KEY_UP:
            asm_cars[asm_active_car].goal = 0;
            asm_cars[asm_active_car].locked_on = 0;
            break;
        case KEY_RIGHT:
            asm_cars[asm_active_car].goal = 1;
            asm_cars[asm_active_car].locked_on = 0;
            break;
        case KEY_DOWN:
            asm_cars[asm_active_car].goal = 2;
            asm_cars[asm_active_car].locked_on = 0;
            break;
        case KEY_LEFT:
            asm_cars[asm_active_car].goal = 3;
            asm_cars[asm_active_car].locked_on = 0;
            break;
        /* Shift up, no higher than the car's top gear. */
        case KEY_EQUALS:
            if (asm_cars[asm_active_car].gear == 0)
                c_sound_command(22);
            else if ((UNSIGNED_INT) asm_cars[asm_active_car].gear
                     < ((unsigned char) (asm_cars[asm_active_car].spec + 2) & CAR_SPEED))
                c_sound_command(24);
            asm_cars[asm_active_car].gear = c_clamp(asm_cars[asm_active_car].gear + 1, 0,
                                                    (asm_cars[asm_active_car].spec & CAR_SPEED) + 2);
            /* An ambushed player's car can do no better than second. */
            if (asm_chase_kind == 2 && asm_cars[asm_active_car].gear > 2)
                asm_cars[asm_active_car].gear = 2;
            asm_engine_note = asm_cars[asm_active_car].gear;
            c_sound_command(asm_active_car == 1 ? 26 : 27);
            break;
        /* Shift down. */
        case KEY_MINUS:
            if (asm_cars[asm_active_car].gear != 0)
                c_sound_command(25);
            asm_cars[asm_active_car].gear = c_clamp(asm_cars[asm_active_car].gear - 1, 0, 3);
            asm_engine_note = asm_cars[asm_active_car].gear;
            c_sound_command(asm_active_car == 1 ? 26 : 27);
            break;
        /* Tailing, take over the other car, whose view of the road is its own. */
        case KEY_SPACE:
            if (asm_chase_kind != 2) {
                asm_active_car++;
                if (asm_active_car >= 3)
                    asm_active_car = 1;
                asm_windscreen_frame = (asm_windscreen_frame + 4) & 7;
            }
            asm_engine_note = asm_cars[asm_active_car].gear;
            c_sound_command(asm_active_car == 1 ? 26 : 27);
            break;
        /* Run the car met head-on off the road, or, ambushed, escape into a building. */
        case KEY_A:
        case KEY_F1:
            if (asm_head_on != 0) {
                asm_outcome = 2;
                shm_finished = 1;
                return;
            }
            if (c_near_destination(asm_cars[0].x, asm_cars[0].y) != 0) {
                shm_finished = 1;
                asm_outcome = 0;
            }
            break;
        /* Ambushed, escape into a building at hand. */
        case KEY_E:
        case KEY_F2:
            if (c_near_destination(asm_cars[0].x, asm_cars[0].y) != 0) {
                shm_finished = 1;
                asm_outcome = 0;
            }
            break;
        /* Quit the game, once the player says they are sure. */
        case KEY_ALT_Q:
            if (c_menu_run(dat_str_sure_want_quit_no, 202, 4) == 1) {
                c_hook_hand_back((LONG) 1);
                exit(UNSET_ARGS(0));
            }
            break;
        /* Sound on or off. */
        case KEY_ALT_S:
            if (shm_options & OPT_SOUND)
                c_sound_command(0);
            shm_options ^= OPT_SOUND;
            break;
        /* Pause until a key is pressed. */
        case KEY_ALT_P:
            c_sound_command(37);
            c_menu_key();
            c_sound_command(38);
            break;
        /* Tailing, the player can give up. */
        case KEY_ESC:
            if (asm_chase_kind != 2) {
                shm_finished = 1;
                return;
            }
            break;
        }
        /* Asked to go back the way it came, only a car that handles well turns on the spot. */
        if (((asm_cars[asm_active_car].facing + 2) & 3) == asm_cars[asm_active_car].goal) {
            if (asm_cars[asm_active_car].spec & CAR_HANDLING) {
                c_sound_command(23);
                asm_cars[asm_active_car].facing = asm_cars[asm_active_car].goal;
            }
            asm_cars[asm_active_car].goal = -1;
        }
    }
    asm_head_on = 0;
    for (v4j = 0; v4j < 3; v4j++) {
        /* The player sees their own cars where they are, the others where last seen. */
        v14c = asm_chase_kind != 2 ? v4j == 0 : v4j != 0;
        /* Take the car off the map before it moves. */
        if (v14c == 0)
            c_board_mark(asm_cars[v4j].x,
                            asm_cars[v4j].y,
                            5);
        else
            c_board_mark(asm_cars[v4j].from_x,
                            asm_cars[v4j].from_y,
                            5);
        /* It moves a step on the frames its gear allows. */
        v7j = 0;
        if ((dat_gear_steps[asm_cars[v4j].gear]
             & 1 << asm_frame_tick % 6) != 0) {
            asm_cars[v4j].x +=
                dat_side_dx[asm_cars[v4j].facing];
            asm_cars[v4j].y +=
                dat_side_dy[asm_cars[v4j].facing];
            v7j = 1;
            /* A car that reaches the point it was steering at no longer needs it. */
            if (v14c == 0
                && asm_cars[v4j].x
                   == asm_cars[v4j].from_x
                && asm_cars[v4j].y
                   == asm_cars[v4j].from_y)
                asm_cars[v4j].from_x = -1;
            /* The road goes by through the windscreen of the car being driven. */
            if (v4j == asm_active_car) {
                asm_windscreen_frame++;
                /* The cast keeps the code as shipped. */
                asm_windscreen_frame = (INT) asm_windscreen_frame & 7;
            }
        }
        /* The player's own cars go back on the map, the one being driven blinking. */
        if (v14c == 0) {
            if (v4j != asm_active_car
                || (asm_frame_tick & 2) != 0)
                c_board_mark(asm_cars[v4j].x,
                                asm_cars[v4j].y, 10);
        } else {
            asm_suspect_alert = asm_cars[v4j].suspicion
                                / asm_suspicion_scale;
            /* A car in contact is marked where it now is; otherwise where it was last seen. */
            if (asm_cars[v4j].locked_on != 0
                || asm_DAT_1663_626a != 0) {
                asm_cars[v4j].from_x =
                    asm_cars[v4j].x;
                asm_cars[v4j].from_y =
                    asm_cars[v4j].y;
                asm_cars[v4j].goal =
                    asm_cars[v4j].facing;
            }
            /* An ambush's pursuers only show while in contact. */
            if (asm_chase_kind != 2
                || asm_cars[v4j].locked_on != 0)
                c_board_mark(asm_cars[v4j].from_x,
                                asm_cars[v4j].from_y,
                                asm_cars[v4j].locked_on != 0 ? 13 : 7);
            asm_cars[v4j].locked_on = 0;
            /* Once the suspect has arrived, the chase ends when the wait runs out. */
            if (asm_countdown != 0 && --asm_countdown == 0)
                shm_finished = 1;
            /* The suspect stops at their destination, and waits less the harder the chase. */
            if (asm_chase_kind != 2
                && asm_cars[v4j].x
                   == asm_goal_x
                && asm_cars[v4j].y
                   == asm_goal_y
                && asm_countdown == 0) {
                asm_cars[v4j].gear = 0;
                asm_countdown = -((shm_difficulty << 6) - 256);
            }
        }
        /* Whether this car can see car 0. */
        v1j = c_sight(v4j);
        if (v4j != 0 && v1j != 0) {
            if (asm_chase_kind != 2) {
                /* A tail on the move gets noticed: more when close, fast or conspicuous. */
                if (asm_cars[v4j].gear != 0) {
                    (asm_cars[v4j].suspicion)++;
                    if (v1j <= 32)
                        (asm_cars[v4j].suspicion)++;
                    if (asm_cars[v4j].gear > 2)
                        (asm_cars[v4j].suspicion)++;
                    asm_cars[v4j].suspicion +=
                        ((asm_cars[v4j].spec
                          & CAR_VISIBILITY) >> CAR_VISIBILITY_SHIFT) - 1;
                }
                asm_cars[0].locked_on = 1;
                /* A suspect who has noticed a tail grows wary, and speeds up to lose it. */
                if (asm_cars[v4j].suspicion
                    > asm_suspicion_scale * 2) {
                    asm_cars[0].suspicion++;
                    if (asm_suspicion_scale / 2 < asm_cars[0].suspicion
                        && asm_countdown == 0)
                        asm_cars[0].gear = 3;
                    if (asm_cars[0].suspicion > asm_suspicion_scale
                        && asm_countdown == 0)
                        asm_cars[0].gear = 4;
                }
                /* Seen waiting at their destination, the suspect has been followed there. */
                if (asm_countdown != 0 && asm_chase_kind != 2) {
                    asm_outcome = 1;
                    asm_stuck_count++;
                    if ((INT) asm_stuck_count > 16)
                        shm_finished = 1;
                }
            }
            /* The suspect never lets a car in sight drive faster than they do. */
            if (asm_chase_kind != 2 && asm_countdown == 0
                && asm_cars[0].gear
                   < asm_cars[v4j].gear)
                asm_cars[0].gear =
                    asm_cars[v4j].gear;
            /* Head-on and close: an ambush is over, and a tail can ram the suspect. */
            if ((((unsigned char) asm_cars[0].facing + 2) & 3)
                    == asm_cars[v4j].facing
                && (INT) abs(asm_cars[v4j].x
                                 - asm_cars[0].x)
                   + (INT) abs(asm_cars[v4j].y
                                   - asm_cars[0].y) <= 8) {
                asm_head_on = 1;
                if (asm_chase_kind == 2)
                    asm_outcome = shm_finished = 1;
            }
            /* A pursuer with the player in sight closes in, easing off when near. */
            if (asm_chase_kind == 2) {
                asm_cars[v4j].from_x =
                    asm_cars[v4j].x;
                asm_cars[v4j].from_y =
                    asm_cars[v4j].y;
                asm_cars[v4j].locked_on = 1;
                asm_cars[v4j].gear =
                    c_clamp((asm_frame_tick >> 3) - v4j, 0,
                                    v1j < 32 ? 2 : 3);
            }
        } else {
            /* Out of sight, the suspect forgets a tail a little at a time. */
            if (v4j != 0
                && asm_cars[v4j].suspicion > 0)
                (asm_cars[v4j].suspicion)--;
            /* A pursuer out of sight cruises at a pace set by the difficulty. */
            if (v4j != 0 && asm_chase_kind == 2) {
                asm_cars[v4j].gear = 3;
                if (shm_difficulty == 0)
                    asm_cars[v4j].gear =
                        (asm_frame_tick & 0x10 << v4j) != 0 ? 2 : 3;
                if (shm_difficulty == 3)
                    asm_cars[v4j].gear =
                        (asm_frame_tick & 0x10 << v4j) != 0 ? 3 : 4;
                /* Near enough, it knows where the player is without seeing them. */
                v1j = (INT) abs(asm_cars[0].x
                                    - asm_cars[v4j].x)
                      + (INT) abs(asm_cars[0].y
                                      - asm_cars[v4j].y);
                if (((5 - shm_difficulty) << 5) / 2 >= v1j) {
                    asm_cars[v4j].from_x =
                        asm_cars[v4j].x;
                    asm_cars[v4j].from_y =
                        asm_cars[v4j].y;
                    asm_cars[v4j].locked_on = 1;
                }
            }
        }
        /* At a junction, each car decides which way to go on. */
        if (v7j != 0
            && asm_cars[v4j].x % 32 == 0
            && asm_cars[v4j].y % 32 == 0) {
            c_hook_step();
            v8j = asm_cars[v4j].x / 32;
            v11c = asm_cars[v4j].y / 32;
            if (v4j == 0) {
                if (asm_chase_kind == 2) {
                    /* Ambushed, the player's car turns where the keys asked, if it can. */
                    if (asm_cars[v4j].goal != -1
                        && c_is_open(v8j, v11c,
                                           asm_cars[v4j].goal) != 0) {
                        if (v4j == asm_active_car
                            && asm_cars[v4j].facing
                               != asm_cars[v4j].goal)
                            c_turning_animation(asm_cars[v4j].facing,
                                            asm_cars[v4j].goal);
                        asm_cars[v4j].facing =
                            asm_cars[v4j].goal;
                        asm_cars[v4j].goal = -1;
                    }
                    /* A dead end turns it at random, and back only if nothing else is open. */
                    if (c_is_open(v8j, v11c,
                                        asm_cars[v4j].facing) == 0) {
                        v0j = 0;
                        do {
                            v3j = c_random_below(4);
                        } while (c_is_open(v8j, v11c, v3j) == 0
                                 || (((asm_cars[v4j].facing + 2) & 3) == v3j
                                     && ++v0j < 9));
                        if (v4j == asm_active_car)
                            c_turning_animation(asm_cars[v4j].facing, v3j);
                        asm_cars[v4j].facing = v3j;
                    }
                } else {
                    /* The suspect drives to their destination at an easy pace... */
                    if (asm_countdown == 0)
                        asm_cars[0].gear = 2;
                    /* ...taking either way that closes on it, chosen at random. */
                    v10c = asm_goal_x
                           - asm_cars[v4j].x;
                    v13c = asm_goal_y
                           - asm_cars[v4j].y;
                    if ((c_random_below(2) != 0 || v13c == 0) && v10c != 0) {
                        v3j = v10c > 0 ? 1 : 3;
                        if (c_is_open(v8j, v11c, v3j) == 0)
                            v3j = v13c > 0 ? 2 : 0;
                    } else {
                        v3j = v13c > 0 ? 2 : 0;
                        if (c_is_open(v8j, v11c, v3j) == 0)
                            v3j = v10c > 0 ? 1 : 3;
                    }
                    /* A wary suspect turns at random to shake off a tail. */
                    if (asm_cars[v4j].suspicion
                        > (INT) c_random_below(asm_suspicion_scale * 4))
                        v3j = c_random_below(4);
                    /* Never into a closed street, and back only when there is no other way. */
                    v0j = 0;
                    while (c_is_open(v8j, v11c, v3j) == 0
                           || (((asm_cars[v4j].facing
                                 + 2) & 3) == v3j
                               && ++v0j < 9))
                        v3j = c_random_below(4);
                    asm_cars[v4j].facing = v3j;
                    /* A tail with the suspect in sight fixes where the player's cars steer for. */
                    for (v6j = 1; v6j < 3; v6j++)
                        if (c_sight(v6j) != 0) {
                            asm_cars[1].from_x =
                                dat_side_dx[asm_cars[0].facing] * 2
                                + asm_cars[0].x;
                            asm_cars[1].from_y =
                                dat_side_dy[asm_cars[0].facing] * 2
                                + asm_cars[0].y;
                        }
                }
            } else {
                /* A pursuer steers to cut the player off, judging by the player's heading. */
                if (asm_chase_kind == 2) {
                    v10c = asm_cars[0].x
                           - asm_cars[v4j].x;
                    v13c = asm_cars[0].y
                           - asm_cars[v4j].y;
                    switch (asm_cars[0].facing) {
                    case 0:
                        v12c = -v13c;
                        v2j = v10c;
                        break;
                    case 2:
                        v12c = v13c;
                        v2j = -v10c;
                        break;
                    case 1:
                        v12c = v10c;
                        v2j = v13c;
                        break;
                    case 3:
                        v12c = -v10c;
                        v2j = -v13c;
                        break;
                    }
                    /* On the player's line, it turns off to either side in turn... */
                    if (v2j == 0) {
                        v3j = ((asm_tick++ & 1) * 2
                               + asm_cars[0].facing - 1) & 3;
                        if (((asm_cars[v4j].facing
                              + 2) & 3) == v3j
                            || c_is_open(v8j, v11c, v3j) == 0)
                            v3j = asm_cars[0].facing;
                        if (c_is_open(dat_side_dx[v3j] + v8j,
                                            dat_side_dy[v3j] + v11c,
                                            asm_cars[0].facing) == 0)
                            v3j = asm_cars[0].facing;
                        /* ...but turns to meet a player coming its way, and follows one well ahead. */
                        if (v12c < 0)
                            v3j = (asm_cars[0].facing + 2) & 3;
                        if (v12c > 32)
                            v3j = asm_cars[0].facing;
                    /* Off it, it follows the player's heading or turns towards the line. */
                    } else if (-(INT) abs(c_random_below(v2j)) < v12c) {
                        v3j = asm_cars[0].facing;
                        if (((asm_cars[v4j].facing
                              + 2) & 3) == v3j
                            || c_is_open(v8j, v11c, v3j) == 0)
                            v3j = (v2j > 0 ? asm_cars[0].facing + 1
                                           : asm_cars[0].facing - 1) & 3;
                    } else {
                        v3j = (v2j > 0 ? asm_cars[0].facing + 1
                                       : asm_cars[0].facing - 1) & 3;
                        if (((asm_cars[v4j].facing
                              + 2) & 3) == v3j
                            || c_is_open(v8j, v11c, v3j) == 0)
                            v3j = asm_cars[0].facing;
                    }
                } else {
                    /* A player's car tailing turns where the keys asked, if it can... */
                    v3j = asm_cars[v4j].facing;
                    if (asm_cars[v4j].goal != -1) {
                        if (c_is_open(v8j, v11c,
                                            asm_cars[v4j].goal) != 0) {
                            v3j = asm_cars[v4j].goal;
                            asm_cars[v4j].goal = -1;
                        }
                    /* ...or, driving itself, steers for where the suspect was last seen. */
                    } else if (asm_cars[v4j].locked_on
                               == 1) {
                        v10c = asm_cars[1].from_x
                               - asm_cars[v4j].x;
                        v13c = asm_cars[1].from_y
                               - asm_cars[v4j].y;
                        /* With tracking, it makes for the suspect when that point would lead it away. */
                        if ((asm_cars[v4j].spec & CAR_TRACKING) != 0
                            && (c_sign(v10c)
                                    != c_sign(asm_cars[0].x
                                                       - asm_cars[v4j].x)
                                || c_sign(v13c)
                                    != c_sign(asm_cars[0].y
                                                       - asm_cars[v4j].y))) {
                            v10c = c_sign(asm_cars[0].x
                                                   - asm_cars[v4j].x) * 4;
                            v13c = c_sign(asm_cars[0].y
                                                   - asm_cars[v4j].y) * 4
                                   - c_random_below(2) * 2 + 1;
                        }
                        if (v10c != 0 || v13c != 0) {
                            if ((INT) abs(v10c) > (INT) abs(v13c))
                                v3j = v10c > 0 ? 1 : 3;
                            else
                                v3j = v13c > 0 ? 2 : 0;
                            if ((((unsigned char)
                                  asm_cars[v4j].facing
                                  + 2) & 3) == v3j
                                || c_is_open(v8j, v11c, v3j) == 0) {
                                if ((INT) abs(v10c) <= (INT) abs(v13c))
                                    v3j = v10c > 0 ? 1 : 3;
                                else
                                    v3j = v13c > 0 ? 2 : 0;
                            }
                            if ((((unsigned char)
                                  asm_cars[v4j].facing
                                  + 2) & 3) == v3j)
                                v3j = asm_cars[v4j].facing;
                        }
                    }
                    /* Seeing the suspect moves the point both cars steer for. */
                    if (c_sight(v4j) != 0) {
                        asm_cars[1].from_x =
                            dat_side_dx[asm_cars[0].facing] * 2
                            + asm_cars[0].x;
                        asm_cars[1].from_y =
                            dat_side_dy[asm_cars[0].facing] * 2
                            + asm_cars[0].y;
                    }
                }
                /* Take the way chosen if it is open and not back; otherwise turn at random. */
                if (c_is_open(v8j, v11c, v3j) != 0
                    && ((unsigned char)
                        (asm_cars[v4j].facing
                         + 2) & 3) != v3j) {
                    if (v4j == asm_active_car)
                        c_turning_animation(asm_cars[v4j].facing, v3j);
                } else {
                    v0j = 0;
                    do
                        v3j = c_random_below(4);
                    while (c_is_open(v8j, v11c, v3j) == 0
                           || (((unsigned char)
                                (asm_cars[v4j].facing + 2) & 3) == v3j
                               && ++v0j < 9));
                }
                asm_cars[v4j].facing = v3j;
            }
        }
    }
    /* A suspect who knows they are tailed gets away the moment no one can see them. */
    if (asm_chase_kind != 2 && (LONG) asm_cars[0].locked_on == 0
        && asm_suspicion_scale * 2 < asm_cars[0].suspicion
        && asm_countdown == 0)
        shm_finished = 2;
    /* Redraw the map window and the dashboard for the car being driven. */
    c_board_draw(asm_active_car, 200, 100);
    return c_dashboard();
}
