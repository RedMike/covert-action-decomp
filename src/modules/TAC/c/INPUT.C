/* INPUT.C -- the player's move each tick, from the keyboard or the stick.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "KEYSHIFT.H"
#include "RANDOM.H"
#include "PAGESHOW.H"
#include "MENU.H"
#include "CASE.H"
#include "MAPDRAW.H"
#include "PROMPT.H"
#include "RANGE.H"
#include "RESTORE.H"
#include "RADAR.H"
#include "BUGROOM.H"
#include "INPUT.H"
#include "STATUS.H"
#include "TRAP.H"
#include "MODOPTS.H"
#include "CAMERA.H"

/* Take one key or stick reading and turn it into the player's next move:
 * decide the heading, walk the cells it would cross, and hand the result to
 * the guard the clock has picked. */
INT c_player_move(void)
{
    INT v0j;        /* a cell being looked at, across */
    INT v1j;        /* set when the player's cell is an open doorway */
    INT v2j;        /* a cell being looked at, down */
    INT v3k;        /* the stick's reading, across */
    INT v4k;        /* the stick's reading, down */
    INT v5k;        /* the step being walked, then the guard picked */
    INT v6l;        /* the cell the step lands in, across */
    INT v7l;        /* the cell the step lands in, down */
    INT v8l;        /* the code the move came in as */
    INT v9m;        /* the key read, or -1 for none */
    INT v10f;       /* declared, and nothing reads it */
    INT v11f;       /* what stands on the cell */
#ifdef FIX_TAC_MOVE
    INT v12p;       /* the keyboard's last byte, against last tick's key */
#endif

    /* Too many wounds end the break-in, and the Kevlar vest allows more. */
    if (((asm_kit & 0x40) != 0 ? 3 : 1) < asm_wounds)
        shm_finished = 1;
    /* Gas in the room, without the gas mask, overcomes the player a little more each tick. */
    if ((asm_rooms[asm_room_last].flags & 0x10)
        != 0 && (asm_kit & 0x20) == 0)
        asm_people[0].stun += 2;
    /* The gas wears off a tick at a time. */
    if (asm_people[0].stun != 0) {
        asm_people[0].stun--;
        /* Well under, the player slumps where he is and can do nothing. */
        if (asm_people[0].stun > 64) {
            asm_people[0].alert = 0;
            asm_people[0].flags |= 4;
            asm_crouched = 1;
            /* Keys pressed meanwhile are thrown away. */
            while (drv_jump_keyboard_empty() == 0)
                c_menu_key();
            /* Further under still, he passes out and the break-in ends. */
            if (asm_people[0].stun > 256)
                shm_finished = 1;
            return;
        }
    }
    /* Nothing conspicuous has been done yet this tick. */
    asm_conspicuous = 0;
    /* An empty gun is reloaded from a spare clip while there is one. */
    if (asm_rounds_left == 0 && asm_clips_left != 0) {
        asm_rounds_left = 6;
        asm_clips_left--;
        c_draw_kit_panel();
    }
    /* With the joystick on and no key waiting, the stick and its buttons stand in for keys. */
    v9m = -1;
    if ((shm_options & OPT_JOYSTICK) != 0 && drv_jump_keyboard_empty() != 0) {
        v9m = c_joystick_read(&v3k, &v4k);
        /* Button 0 fires with a guard not out cold in the room, and otherwise uses what is ahead. */
        if (c_joystick_button(0) != 0) {
            if (asm_guard_in_room != 0)
                v9m = KEY_SPACE;
            else {
                v9m = KEY_F1;
                c_wait_for_release();
            }
        }
        /* Button 1 alone crouches; with the stick pushed it jumps that way. */
        if (c_joystick_button(1) != 0) {
            if (v9m == -1)
                v9m = KEY_5;
            else
                v9m = dat_joystick_keys[v9m] + 0x80;
            c_wait_for_release();
        }
    }
    /* A move is taken only while no jump or throw is playing out. */
    if ((drv_jump_keyboard_empty() == 0 || v9m != -1) && asm_jump_ticks == 0
        && asm_throw_frames == 0) {
        /* From the keyboard, the oldest key waiting. */
        if (v9m == -1) {
#ifdef FIX_TAC_MOVE
            if (MOD_ON(fast_tac_move)) {
                /* The newest key is the one held now; the older are repeats. */
                do
                    v8l = c_menu_key();
                while (drv_jump_keyboard_empty() == 0);
                /* A fresh key walks until its first repeat: 4, 5 or 6 ticks. */
                if (v8l != asm_direction_keycode)
                    asm_move_cost = asm_game_speed + 4;
                else
                    asm_move_cost = 0;
            } else
#endif
            {
                /* A key unlike last tick's buys four ticks of walking, to reach its
                 * first repeat; the same key again buys this tick only. */
                v8l = c_menu_key();
                if (v8l != asm_direction_keycode)
                    asm_move_cost = 4;
                else
                    asm_move_cost = 0;
            }
        } else
            v8l = v9m;
        /* Remembered, to tell next tick's repeat from a fresh press. */
        asm_direction_keycode = v8l;
        switch (v8l) {
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
        /* Fire. In the target's room, with its agent not yet arrested, that is conspicuous. */
        case KEY_SPACE:
            if (asm_room_last == asm_payload_room
                && asm_suspect_here != -1
                && (asm_outcome & 2) == 0)
                asm_conspicuous = 1;
            /* Hold the firing pose four ticks more; the stick only starts it from rest. */
            if ((INT) asm_shot_timer < 4
                && (v9m == -1 || asm_shot_timer == 0))
                asm_shot_timer += 4;
            /* Firing stops a walk where it is. */
            if (asm_last_move_type != 3)
                asm_last_move_type = 0;
            break;
        /* Crouch or stand up, and draw the player to match. */
        case KEY_5:
            asm_last_move_type = 0;
            asm_crouched ^= 1;
            *(unsigned char *) &asm_people[0].flags &= 0xfb;
            asm_people[0].flags |= asm_crouched << 2;
            break;
        /* Use what is ahead, standing up to do it; there is nothing to use in an ambush. */
        case KEY_ENTER:
        case KEY_F1:
            if (asm_mission_kind != 3) {
                c_primary_interact();
                asm_last_move_type = 2;
                asm_crouched = 0;
            }
            break;
        /* Photograph what is ahead, when a camera is carried; a conspicuous act. */
        case KEY_F2:
            asm_conspicuous = 1;
            if (CAMERA_CARRIED(asm_kit, asm_mission_kind))
                c_take_photo();
            break;
        /* Plant a bug on what is ahead; a conspicuous act. */
        case KEY_F3:
            asm_conspicuous = 1;
            c_plant_bug();
            break;
        /* Try the password at the terminal ahead; a conspicuous act. */
        case KEY_F4:
            asm_conspicuous = 1;
            c_secondary_interact();
            break;
        /* Throw the chosen grenade a short way, playing the throw, while one is left. */
        case KEY_F5:
            asm_conspicuous = 1;
            if (asm_ammunition[asm_effect]-- > 0) {
                c_add_grenade(asm_player_x, asm_player_y,
                                   asm_facing, 1, asm_effect);
                asm_throw_frames = 3;
            }
            break;
        /* Throw it further. */
        case KEY_F6:
            asm_conspicuous = 1;
            if (asm_ammunition[asm_effect]-- > 0) {
                c_add_grenade(asm_player_x, asm_player_y,
                                   asm_facing, 2, asm_effect);
                asm_throw_frames = 3;
            }
            break;
        /* Throw it furthest. */
        case KEY_F7:
            asm_conspicuous = 1;
            if (asm_ammunition[asm_effect]-- > 0) {
                c_add_grenade(asm_player_x, asm_player_y,
                                   asm_facing, 3, asm_effect);
                asm_throw_frames = 3;
            }
            break;
        /* Set off every remote-control trap at once. */
        case KEY_F8:
            for (v5k = 0; v5k < 16; v5k++)
                if (asm_grenades[v5k].timer
                    == -9999)
                    asm_grenades[v5k].timer =
                        -63;
            break;
        /* Set the chosen grenade as a trap where the player stands; the trap menu spends it. */
        case KEY_F9:
            asm_conspicuous = 1;
            if (asm_ammunition[asm_effect] > 0)
                c_add_grenade(asm_player_x, asm_player_y,
                                   asm_facing, -1, asm_effect);
            break;
        /* Turn to the next kind of grenade. */
        case KEY_F10:
            asm_effect++;
            if (asm_effect > 2)
                asm_effect = 0;
            c_draw_kit_panel();
            break;
        /* Sound off or on, silencing what plays as it goes off. */
        case KEY_ALT_S:
            if ((shm_options & OPT_SOUND) != 0)
                c_sound_command(0);
            shm_options ^= OPT_SOUND;
            break;
        /* Pause over a saved screen until a key, with a sound command either side. */
        case KEY_ALT_P:
            c_view_save();
            c_sound_command(37);
            shm_menu_draw_only = 1;
            c_ask_menu(dat_str_paused, 80, 96);
            c_wait_key();
            c_sound_command(38);
            c_view_restore();
            break;
        /* Quit the game once the player is sure, handing the keyboard's shift state back. */
        case KEY_ALT_Q:
            c_view_save();
            if (c_ask_menu(dat_str_sure_want_quit_no, 80, 80) == 1) {
                c_hook_hand_back(LONG_LIT(1));
                exit(UNSET_ARGS(0));
            }
            c_view_restore();
            break;
        /* Joystick on or off, calibrating it as it comes on. */
        case KEY_ALT_J:
            shm_options ^= OPT_JOYSTICK;
            if ((shm_options & OPT_JOYSTICK) != 0)
                drv_jump_joy_calibrate();
            break;
        /* Stop dead, giving up any turn under way. */
        case KEY_CTRL_BREAK:
            asm_last_move_type = 0;
            asm_facing_goal = asm_facing;
            break;
        /* Walk: the keypad digits, or the stick, pick the way to face and walk. */
        case JOY_UP_LEFT:
        case KEY_7:
        case KEY_KEYPAD_7:
            asm_facing_goal = 8;
            asm_last_move_type = 1;
            break;
        case JOY_UP:
        case KEY_8:
        case KEY_KEYPAD_8:
            asm_last_move_type = 1;
            asm_facing_goal = 1;
            break;
        case JOY_UP_RIGHT:
        case KEY_9:
        case KEY_KEYPAD_9:
            asm_facing_goal = 2;
            asm_last_move_type = 1;
            break;
        case JOY_LEFT:
        case KEY_4:
        case KEY_KEYPAD_4:
            asm_facing_goal = 7;
            asm_last_move_type = 1;
            break;
        case JOY_RIGHT:
        case KEY_6:
        case KEY_KEYPAD_6:
            asm_facing_goal = 3;
            asm_last_move_type = 1;
            break;
        case JOY_DOWN_LEFT:
        case KEY_1:
        case KEY_KEYPAD_1:
            asm_facing_goal = 6;
            asm_last_move_type = 1;
            break;
        case JOY_DOWN:
        case KEY_2:
        case KEY_KEYPAD_2:
            asm_facing_goal = 5;
            asm_last_move_type = 1;
            break;
        case JOY_DOWN_RIGHT:
        case KEY_3:
        case KEY_KEYPAD_3:
            asm_facing_goal = 4;
            asm_last_move_type = 1;
            break;
        /* Jump: the cursor keys, or the stick with button 1, pick the way to jump. */
        case JOY_B1_UP_LEFT:
        case KEY_HOME:
            asm_facing_goal = 8;
            asm_last_move_type = 4;
            break;
        case JOY_B1_UP:
        case KEY_UP:
            asm_last_move_type = 4;
            asm_facing_goal = 1;
            break;
        case JOY_B1_UP_RIGHT:
        case KEY_PGUP:
            asm_facing_goal = 2;
            asm_last_move_type = 4;
            break;
        case JOY_B1_LEFT:
        case KEY_LEFT:
            asm_facing_goal = 7;
            asm_last_move_type = 4;
            break;
        case JOY_B1_RIGHT:
        case KEY_RIGHT:
            asm_facing_goal = 3;
            asm_last_move_type = 4;
            break;
        case JOY_B1_DOWN_LEFT:
        case KEY_END:
            asm_facing_goal = 6;
            asm_last_move_type = 4;
            break;
        case JOY_B1_DOWN:
        case KEY_DOWN:
            asm_facing_goal = 5;
            asm_last_move_type = 4;
            break;
        case JOY_B1_DOWN_RIGHT:
        case KEY_PGDN:
            asm_facing_goal = 4;
            asm_last_move_type = 4;
            break;
        }
        /* Escaping, the first step or jump raises the alarm on the player's room,
         * and from then on it is an ordinary break-in. */
        if (asm_mission_kind == 1
            && (asm_last_move_type == 1 || asm_last_move_type == 4)) {
            c_room_distances(asm_room_last, 240);
            asm_mission_kind = 0;
        }
        /* A jump looks ahead along the way chosen to see how far it can go. */
        if (asm_last_move_type == 4) {
            asm_conspicuous = 1;
            asm_jump_ticks = 0;
            for (v5k = 3; v5k <= 9; v5k++) {
                v0j = (dat_move_dx[asm_facing_goal] * v5k
                       + asm_player_x) / 16;
                v2j = (dat_move_dy[asm_facing_goal] * v5k
                       + asm_player_y) / 16;
                /* The room's edge ends the jump short of it. */
                if (asm_room_map[(v0j << 5) + v2j]
                    != asm_room_last) {
                    asm_jump_ticks = v5k / 2 + 4;
                    break;
                }
                v11f = asm_floor_map[(v0j << 5) + v2j];
                if (v11f != -1) {
                    /* Something that blocks sight stops it; low furniture is jumped over. */
                    v11f &= 0x3f;
                    if ((dat_floor_objects[v11f].flags
                         & FOBJ_OPAQUE) != 0)
                        break;
                    /* Something that does not block is somewhere to land. */
                    if ((dat_floor_objects[v11f].flags
                         & FOBJ_SOLID) == 0) {
                        asm_jump_ticks = v5k / 2 + 6;
                        asm_facing = asm_facing_goal;
                    }
                } else {
                    /* Bare floor is somewhere to land. */
                    asm_jump_ticks = v5k / 2 + 6;
                    asm_facing = asm_facing_goal;
                }
            }
            /* With nowhere to land there is no jump; otherwise it ends in a crouch. */
            if (asm_jump_ticks == 0)
                asm_last_move_type = 0;
            else
                asm_crouched = 1;
        }
    } else
#ifdef FIX_TAC_MOVE
    if (MOD_ON(fast_tac_move)) {
        /* The keyboard's last byte matching last tick's key keeps the walk
         * going; that key's release code, bit 7 set, ends the walk. */
        v12p = inp(0x60) ^ (asm_direction_keycode >> 8);
        if (v12p == 0)
            asm_move_cost++;
        else {
            if (v12p == 0x80)
                asm_move_cost = 0;
            asm_direction_keycode = -1;
        }
    } else
#endif
        /* No key this tick, so the next one is a fresh press. */
        asm_direction_keycode = -1;
    /* Each tick spends one of the walk's paid-for ticks. */
    asm_move_cost--;
    /* Throw away the repeats queued behind the key, unless button 0 is held to keep firing. */
    if ((shm_options & OPT_JOYSTICK) == 0 || c_joystick_button(0) == 0)
        c_wait_for_release();
#ifdef FIX_TAC_MOVE
    /* A walk under way faces the way asked at once, as a jump does; asm_walked
     * is still set by a last tick that walked, so a standing start turns. */
    if (MOD_ON(fast_tac_move) && asm_walked != 0)
        asm_facing = asm_facing_goal;
#endif
    /* Turn an eighth a tick towards the way asked, the shorter way round. */
    if (asm_facing_goal != asm_facing) {
        if (((asm_facing_goal
              - asm_facing) & 7) < 4)
            asm_facing++;
        else
            asm_facing--;
        asm_facing = ((asm_facing - 1) & 7) + 1;
    }
    /* A walk looks two steps ahead before it takes one. */
    if (asm_last_move_type == 1) {
        v6l = (dat_move_dx[asm_facing] * 2
               + asm_player_x) / 16;
        v7l = (dat_move_dy[asm_facing] * 2
               + asm_player_y) / 16;
        /* Standing in an open doorway, the player may cross the room's edge. */
        v1j = (asm_floor_map[(asm_player_col << 5) + asm_player_row]
               & 0x80) != 0
              && (dat_floor_objects[(asm_floor_map[(asm_player_col << 5) + asm_player_row] & 0x3f)].flags
                  & FOBJ_DOOR) != 0;
        /* Elsewhere he stops half a cell short of the left or right edge he heads for. */
        if (v1j == 0) {
            if (((INT) asm_room_left + 8 > asm_player_x
                 && dat_move_dx[asm_facing] < 0)
                || ((INT) asm_room_right - 8 < asm_player_x
                    && dat_move_dx[asm_facing] > 0))
                asm_last_move_type = 0;
        }
        /* Something solid in the next column along his row stops him. */
        if (v6l != asm_player_col) {
            v11f = asm_floor_map[(v6l << 5) + asm_player_row] & 0x3f;
            if (v11f != 0x3f
                && (dat_floor_objects[v11f].flags & FOBJ_SOLID)
                   != 0)
                asm_last_move_type = 0;
        }
        /* The same for the top and bottom edges. */
        if (v1j == 0) {
            if (((INT) asm_room_top + 8 > asm_player_y
                 && dat_move_dy[asm_facing] < 0)
                || ((INT) asm_room_bottom - 8 < asm_player_y
                    && dat_move_dy[asm_facing] > 0))
                asm_last_move_type = 0;
        }
        /* And something solid in the next row along his column. */
        if (v7l != asm_player_row) {
            v11f = asm_floor_map[v7l + (asm_player_col << 5)] & 0x3f;
            if (v11f != 0x3f
                && (dat_floor_objects[v11f].flags & FOBJ_SOLID)
                   != 0)
                asm_last_move_type = 0;
        }
        /* On a diagonal, something solid in the corner cell stops him too. */
        if (v6l != asm_player_col && v7l != asm_player_row) {
            v11f = asm_floor_map[(v6l << 5) + v7l]
                   & 0x3f;
            if (v11f != 0x3f
                && (dat_floor_objects[v11f].flags & FOBJ_SOLID)
                   != 0)
                asm_last_move_type = 0;
        }
    }
    /* Whether the player walked this tick, which the portrait's frame follows. */
    asm_walked = 0;
    switch (asm_last_move_type) {
    /* A jump covers two steps a tick, its last six ticks spent landing. */
    case 4:
        if ((INT) asm_jump_ticks > 6) {
            asm_player_x += dat_move_dx[asm_facing] * 2;
            asm_player_y += dat_move_dy[asm_facing] * 2;
        }
        if (--asm_jump_ticks == 0)
            asm_last_move_type = 0;
        break;
    /* A walk steps only once the turn is done, and crouched it takes short steps. */
    case 1:
        asm_walked = 1;
        if (asm_facing_goal == asm_facing) {
            if (asm_crouched == 0 || asm_jump_ticks != 0) {
                asm_player_x +=
                    dat_move_dx[asm_facing];
                asm_player_y +=
                    dat_move_dy[asm_facing];
            } else {
                asm_player_x +=
                    dat_step_dx[asm_facing];
                asm_player_y +=
                    dat_step_dy[asm_facing];
                asm_crouch_walk_ticks++;
            }
            /* The walk stops once the ticks the key paid for are spent. */
            if ((INT) asm_move_cost <= 0 && asm_jump_ticks == 0)
                asm_last_move_type = 0;
        }
        /* Step through the four walking frames. */
        asm_walk_frame = ++asm_walk_frame & 3;
        break;
    /* Using something, and walking crouched, have a frame each. */
    case 2:
        asm_walk_frame = 6;
        break;
    case 3:
        asm_walk_frame = 7;
        break;
    /* Standing, in the alert pose while a guard has him in sight, unless escaping or disguised. */
    default:
        asm_walk_frame = 0;
        if (asm_seen_longest != 0 && asm_mission_kind != 1
            && asm_disguised == 0)
            asm_walk_frame = 4;
        break;
    }
    /* Crouched, the player is drawn crouching whatever he does. */
    if (asm_crouched != 0)
        asm_walk_frame = 7;
    /* Copy the player into his person record, which the drawing and the guards read. */
    asm_people[0].x = asm_player_x;
    asm_people[0].y = asm_player_y;
    asm_people[0].facing = asm_facing;
    asm_people[0].shot_timer = asm_shot_timer;
    asm_people[0].last_move_type = asm_last_move_type;
    asm_people[0].kind = asm_walk_frame;
    asm_people[0].room = asm_room_last;
    *(unsigned char *) &asm_people[0].flags &= 0xfb;
    asm_people[0].flags += asm_crouched << 2;
    /* The firing pose wears off a tick at a time. */
    if (asm_shot_timer != 0)
        asm_shot_timer--;
    /* One guard a tick, in turn, is checked for the player walking into him:
     * a slumped one, or any one while the player is undisguised. */
    v5k = asm_frame_tick % 8 + 1;
    if (v5k != 0
        && (asm_people[v5k].flags & 0x80) != 0
        && (INT) abs(asm_player_x
                         - asm_people[v5k].x)
           + (INT) abs(asm_player_y
                           - asm_people[v5k].y) < 10
        && (asm_people[v5k].stun > 24
            || asm_disguised == 0)) {
        /* An undisguised player walking into a wide-awake guard takes a wound. */
        if (asm_disguised == 0
            && asm_people[v5k].stun == 0)
            asm_wounds++;
        /* Taking away a guard out cold leaves one less sign in the room that
         * would raise the alarm; with none left the room's mark is cleared. */
        if (asm_people[v5k].stun > 999
            && --asm_signs_here == 0)
            asm_rooms[asm_room_last].flags &= 0xf7;
        /* The guard is gone, and the player has his clothes and two of his grenades. */
        asm_people[v5k].flags =
            asm_people[v5k].stun = 0;
        asm_disguised = 1;
        v5k = c_random_below(3);
        asm_ammunition[v5k] =
            c_clamp(asm_ammunition[v5k] + 2, 2, 8);
        c_draw_kit_panel();
    }
    /* In a jailbreak or an ambush, with no guard left on his feet or after an hour
     * on the clock, the player is out as though he had walked out. */
    if (asm_frame_tick > 64
        && (asm_mission_kind == 3 || asm_mission_kind == 2)
        && (shm_activity.city[0] == 0 || asm_frame_tick > 3600)) {
        asm_room_last = 0;
        shm_finished = 1;
    }
}
