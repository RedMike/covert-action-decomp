/* MENU.C -- menus, keys and the joystick, the pan animation, and the save.
 */
#include "TAC.H"
#include "KEYSHIFT.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "MENU.H"
#include "LOADDISK.H"
#include "PAGESHOW.H"
#include "CITY.H"
#include "PROMPT.H"
#include "NOTHING.H"
#include "FACES.H"
#include "STUBS.H"
#include "RANDOM.H"

/* shared_include_start: ../../../../shared/c/MENU-RUN.C -- generated */
/* MENU-RUN.C -- c_menu_run, running a menu until an item is chosen.
 */

#ifdef EXTRA_MENU_OPTIONS
/* Mod option: one more than the item Left and Right leave the menu on, 0 for
 * none; the arrow's key code replaces it when one does. */
INT menu_sideways;
#endif

/* Run the menu `title` at (`x`, `y`) and answer the item chosen, or -1. An
 * armed animation plays behind it; Alt-A, Alt-S and Alt-J toggle animations,
 * sound and joystick, and Alt-Q quits.
 */
INT c_menu_run(rt_addr title, INT x, INT y)
{
    INT unused;
    INT sel;
    INT last;
    INT hit;
    INT anim;
    INT pad;
    INT done;
    INT i;
    INT tall;
    INT hat;
    INT flags;
    INT held;
    INT unread;

    last = -1;
    sel = shm_menu_pick;
    if (shm_menu_no_pick != 0 || shm_menu_draw_only != 0)
        sel = -1;
    shm_menu_first_line = -1;
    shm_menu_relayout = 1;
    tall = 8;
    anim = done = unread = 0;
    if (shm_pan_playing != 0 && shm_menu_draw_only == 0
        && ((shm_options & OPT_ANIMATION) != 0 || shm_menu_face != -1)) {
        drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
        if (shd_drive == -1)
            _dos_getdrive((rt_addr) &shd_drive);
        if (shd_drive <= 2 && shm_active_pan.page_a <= 200)
            c_write_text(shd_str_one_moment_please, shm_active_pan.page_a + 2, 1, 7);
        c_seq_start(&shm_active_pan);
        anim = 1;
        shd_city_on_screen = -1;
        drv_jump_gfx_set_palette(&shd_palette_menu);
        c_want_disk(shd_pan_disk, 1);
        if (shm_menu_face != -1) {
            if (((shm_menu_face >> 2) & 3) == 3)
                drv_jump_gfx_set_palette(&shd_palette_face);
            shd_screen->page = 2;
            c_draw_face(shm_menu_face, shm_menu_face_x,
                            shm_menu_face_y);
            shd_screen->page = 0;
        }
        for (i = 0; i < 2; i++)
            c_seq_step();
    }
    shm_menu_face = -1;
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
    c_menu_draw((char *) title, x, y, sel);
    if (shm_menu_first_line != -1 && shm_menu_draw_only == 0
        && shm_menu_no_pick == 0) {
        drv_jump_gfx_fill(shd_screen, x + 3,
                          ((shm_menu_first_line + shm_menu_pick) << 3) + y
                          + 4, shm_menu_text_width + 3, tall + 1,
                          shm_menu_colour_bar, 14);
        last = shm_menu_pick;
    }
    if (shm_pan_playing != 0)
        c_pan_restore(x, y);
    c_wait_for_release();
    if (shm_menu_draw_only != 0) {
        shm_menu_draw_only = 0;
        return -1;
    }
    do {
        shm_menu_relayout = 0;
        flags = shm_options;
        hat = -1;
        while (drv_jump_keyboard_empty() != 0 && hat == -1) {
            if (shm_pan_playing != 0 && c_seq_step() != 0)
                shm_pan_playing = 0;
            hat = c_joystick_key();
        }
        if (drv_jump_keyboard_empty() == 0 || hat != -1) {
            hit = hat == -1 ? c_menu_key() : hat;
            switch (hit) {
            case KEY_DOWN:
                if (sel < shm_menu_items - 1)
                    sel++;
                break;
            case KEY_UP:
                if (sel > 0)
                    sel--;
                break;
#ifdef EXTRA_MENU_OPTIONS
            case KEY_LEFT:
            case KEY_RIGHT:
                /* A slider item leaves on the arrow, kept in menu_sideways. */
                if (menu_sideways == sel + 1) {
                    menu_sideways = hit;
                    done = 1;
                }
                break;
#endif
            /* The three toggles share one tail, as shipped. */
            case KEY_ALT_A:
                shm_options ^= OPT_ANIMATION;
                goto toggled;
            case KEY_ALT_S:
                shm_options ^= OPT_SOUND;
                goto toggled;
            case KEY_ALT_J:
                shm_options ^= OPT_JOYSTICK;
                if (shm_options & OPT_JOYSTICK)
                    drv_jump_joy_calibrate();
toggled:
                if (flags < shm_options)
                    c_sound_command(20);
                else
                    c_sound_command(19);
                break;
            case KEY_ALT_Q:
                held = shm_pan_playing;
                shm_pan_playing = shm_menu_no_pick = 0;
                drv_jump_gfx_show_page(0);
                if (c_menu_run(shd_str_sure_want_quit_no_2, x, y & 0xfe) == 1) {
                    shm_finished = -1;
                    if (held != 0)
                        c_seq_stop();
                    COMM()->next_module = (unsigned char) shm_finished;
                    c_hook_hand_back(UNSET_ARGS(0));
                    exit(UNSET_ARGS(0));
                }
                shm_pan_playing = held;
                /* fall through */
            case KEY_ESC:
                sel = -1;
                /* fall through */
            case KEY_ENTER:
            case KEY_SPACE:
            case KEY_F1:
                done = 1;
                break;
            }
        }
        if (sel < 0 || sel >= shm_menu_items
            || shm_menu_tick != 0 || shm_menu_no_pick != 0)
            sel = -1;
        if (sel != last) {
            if (last != -1)
                drv_jump_gfx_fill(shd_screen, x + 3,
                                  ((last + shm_menu_first_line) << 3) + y + 4,
                                  shm_menu_text_width + 3, tall + 1, 14,
                                  shm_menu_colour_bar);
            if (sel != -1)
                drv_jump_gfx_fill(shd_screen, x + 3,
                                  ((sel + shm_menu_first_line) << 3) + y + 4,
                                  shm_menu_text_width + 3, tall + 1,
                                  shm_menu_colour_bar, 14);
            last = sel;
            if (hat != -1)
                c_wait_retraces(15);
        }
        if (shm_pan_playing != 0)
            c_pan_restore(x, y);
    } while (done == 0);
    if (sel != -1) {
        drv_jump_gfx_fill(shd_screen, x + 3,
                          ((sel + shm_menu_first_line) << 3) + y + 4,
                          shm_menu_text_width + 3, tall + 1, 14, 15);
        if (shm_pan_playing != 0)
            c_pan_restore(x, y);
        c_wait_retraces(20);
    }
    if (shm_pan_playing != 0) {
        c_seq_stop();
        shm_pan_playing = 0;
    }
    if (anim != 0) {
        shd_screen->page = 0;
        drv_jump_gfx_show_page(0);
    }
    shm_menu_pick = 0;
    shm_menu_marked = 0;
    shm_menu_no_pick = shm_menu_tick = 0;
    return sel;
}
/* shared_include_end: ../../../../shared/c/MENU-RUN.C */

/* shared_include_start: ../../../../shared/c/MENU-DRAW.C -- generated */
/* MENU-DRAW.C -- c_menu_draw, drawing a menu's box and lines.
 */

/* Draw the menu `title` at (`x`, `y`) with item `sel` highlighted, answering
 * `sel`. A relayout draws the box, styled by bit 0 of `y`; otherwise only the
 * lines around `sel` are redrawn.
 */
INT c_menu_draw(char *title, INT x, INT y, INT sel)
{
    INT junk[40];
    INT i;
    INT wide;
    INT item;

    shm_menu_line_start[0] = 0;
    if (shm_menu_relayout == 1) {
        for (i = 0; i < 0x20; i++)
            shm_menu_shortcut[i] = 0;
        i = shm_menu_text_width = wide = shm_menu_lines = item = 0;
        for (i = 0; i < (INT) strlen(title); i++) {
            if (title[i] == '\n') {
                if (wide > shm_menu_text_width)
                    shm_menu_text_width = wide;
                wide = 0;
                shm_menu_lines++;
                shm_menu_line_start[shm_menu_lines] = i + 1;
            } else {
                if (wide == 0 && title[i] == ' ') {
                    shm_menu_shortcut[item] = (title + i)[1];
                    if (shm_menu_first_line == -1)
                        shm_menu_first_line = shm_menu_lines;
                    item++;
                }
                wide += drv_jump_gfx_char_width(shd_screen->font,
                                          title[i]);
            }
        }
        shm_menu_lines = c_clamp(shm_menu_lines, 0,
                                            (0xc0 - y) / 8);
        shm_menu_right = x + shm_menu_text_width + 8;
        shm_menu_bottom = y + (shm_menu_lines << 3) + 6;
        if (title[strlen(title) - 1] != '\n')
            item--;
        shm_menu_items = item;
        shm_menu_colour_plain = 0xf;
        shm_menu_colour_item = 7;
        shm_menu_colour_pick = 7;
        shm_menu_colour_bar = 5;
        if (y & 1) {
            if (shm_pan_playing != 0) {
                shm_pan_width = c_clamp(shm_active_pan.page_a,
                                                    shm_menu_right + 5,
                                                    0x3e7);
                shd_screen->bg_pen = 5;
                if (y < 0x90) {
                    drv_real_fill_rect(shd_screen, 0, 0,
                                      shm_pan_width, 0xc8, 5);
                    c_hook_repaint();
                } else {
                    drv_real_fill_rect(shd_screen, 4, y, 0x138,
                                      0xc6 - y, 5);
                }
            } else {
                drv_real_fill_rect(shd_screen, x + 1, y + 1,
                                  shm_menu_right - x,
                                  shm_menu_bottom - y,
                                  shd_screen->bg_pen);
                if (shd_screen->bg_pen == 0xf) {
                    shm_menu_colour_plain = 0;
                    shm_menu_colour_pick = 8;
                    shm_menu_colour_item = 7;
                    shm_menu_colour_bar = 0xf;
                }
            }
        } else {
            shd_screen->bg_pen = 5;
            c_menu_box(x, y, shm_menu_right - x,
                            shm_menu_bottom - y, 5);
            shm_menu_colour_bar = 5;
        }
        if (shm_menu_tick != 0) {
            c_write_text(shd_str_ok, shm_menu_right - 0x11,
                            shm_menu_bottom - 8, 0xb);
            c_outline_box(shm_menu_right - 0x14,
                            shm_menu_bottom - 0xa, 0x14, 0xa, 0xb);
        }
    }
    item = *title == ' ' ? 0 : -1;
    shd_screen->fg_pen = shm_menu_colour_plain;
    for (i = 0; i < shm_menu_lines; i++) {
        if (shm_menu_relayout != 0 || (INT) abs(sel - item) < 2) {
            title[shm_menu_line_start[i + 1] - 1] = 0;
            if (item >= 0 && (shm_menu_marked & 1 << item)) {
                title[shm_menu_line_start[i]] = '^';
                c_write_text_trimmed((drv_addr) (title
                                       + shm_menu_line_start[i]),
                                x + 5, (i << 3) + y + 5,
                                item < 0 ? shm_menu_colour_plain
                                : item == sel ? shm_menu_colour_pick
                                : shm_menu_colour_item);
                title[shm_menu_line_start[i]] = ' ';
            } else {
                c_write_text_trimmed((drv_addr) (title
                                       + shm_menu_line_start[i]),
                                x + 5, (i << 3) + y + 5,
                                item < 0 ? shm_menu_colour_plain
                                : item == sel ? shm_menu_colour_pick
                                : shm_menu_colour_item);
            }
            title[shm_menu_line_start[i + 1] - 1] = '\n';
        }
        if (title[shm_menu_line_start[i + 1]] == ' ')
            item++;
    }
    return sel;
}
/* shared_include_end: ../../../../shared/c/MENU-DRAW.C */

/* shared_include_start: ../../../../shared/c/MENU-BOX.C -- generated */
/* MENU-BOX.C -- c_menu_box, a filled box with a contrasting outline.
 */

/* Fill a box and outline it in `colour ^ 8`, or 7 for black and 0dh. The
 * background pen is left at the box's colour.
 */
INT c_menu_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour)
{
    c_fill_box(x, y, x + w, y + h, colour);
    shd_screen->bg_pen = colour;
    colour ^= 8;
    if (colour == 0)
        colour = 7;
    if (colour == 0xd)
        colour = 7;
    return c_outline_box(x, y, w, h, colour);
}
/* shared_include_end: ../../../../shared/c/MENU-BOX.C */

/* shared_include_start: ../../../../shared/c/OUTLINE-BOX.C -- generated */
/* OUTLINE-BOX.C -- c_outline_box, outlining a box.
 */

/* Outline the `w` by `h` box at (`x`, `y`) in `colour`. */
INT c_outline_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour)
{
    c_draw_line(x, y, x + w, y, colour);
    c_draw_line(x, y + h, x + w, y + h, colour);
    c_draw_line(x + w, y, x + w, y + h, colour);
    return c_draw_line(x, y, x, y + h, colour);
}
/* shared_include_end: ../../../../shared/c/OUTLINE-BOX.C */

/* shared_include_start: ../../../../shared/c/PAN-ARM.C -- generated */
/* PAN-ARM.C -- c_pan_arm, arming an animation to play behind a menu.
 */

/* Arm the animation `name` at origin (`y`, `z`); answer whether it was armed.
 * It is refused when animations are off or its disk is not in. A name starting
 * "bld" marks a building animation.
 */
INT c_pan_arm(char *name, INT y, INT z)
{
    char saved;

    if ((shm_options & OPT_ANIMATION) == 0
        || (strcmp(name, shd_str_briefing_pan) != 0
            && c_want_disk(4, 0) == 0)) {
        drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xc8, 5);
        shm_active_pan.page_a = y;
        shd_screen->bg_pen = 5;
        return 0;
    }
    strcpy(shd_str_animation_pan, name);
    saved = name[3];
    name[3] = 0;
    if (strcmp(name, shd_str_bld) == 0)
        shm_pan_building = 1;
    name[3] = saved;
    shm_pan_playing = 1;
    shm_active_pan.name = shd_str_animation_pan;
    shm_active_pan.duration = -1;
    shm_active_pan.page_a = y;
    shm_active_pan.page_b = z;
    shm_active_pan.rate = -1;
    return 1;
}
/* shared_include_end: ../../../../shared/c/PAN-ARM.C */

/* shared_include_start: ../../../../shared/c/PAN-RESTORE.C -- generated */
/* PAN-RESTORE.C -- c_pan_restore, copying the animation area between pages.
 */

/* Copy the screen's animation area onto the map page, and a building
 * animation's corner once more. Neither parameter is read.
 */
INT c_pan_restore(INT x, INT y)
{
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, shm_pan_width, 0xc8, shd_map_page, 0, 0);
    if (shm_pan_building != 0) {
        drv_jump_gfx_copy_rect(shd_screen, 0, 0, 0xa0, 0x1e, shd_map_page, 0, 0);
        shm_pan_building = 0;
    }
}
/* shared_include_end: ../../../../shared/c/PAN-RESTORE.C */

/* shared_include_start: ../../../../shared/c/MENU-KEY.C -- generated */
/* MENU-KEY.C -- c_menu_key, reading a key for a menu.
 */

/* Read a key: an arrow, Home or keypad code, else its ASCII, or the whole word
 * when the ASCII is zero. The switch is on `(INT) key`, as shipped.
 */
INT c_menu_key(void)
{
    UNSIGNED_INT key;

    key = drv_jump_read_key();
    TRACE_MESSAGE1("c_menu_key: %x", key);
    switch ((INT) key) {
    case KEY_UP:
    case KEY_UNKNOWN_487E:
        key = KEY_UP;
        break;
    case KEY_PGUP:
        key = KEY_PGUP;
        break;
    case KEY_UNKNOWN_F400:
    case KEY_RIGHT:
        key = KEY_RIGHT;
        break;
    case KEY_PGDN:
        key = KEY_PGDN;
        break;
    case KEY_DOWN:
    case KEY_UNKNOWN_5060:
        key = KEY_DOWN;
        break;
    case KEY_END:
        key = KEY_END;
        break;
    case KEY_LEFT:
    case KEY_UNKNOWN_4B7C:
        key = KEY_LEFT;
        break;
    case KEY_HOME:
    case KEY_UNKNOWN_475C:
        key = KEY_HOME;
        break;
    case KEY_KEYPAD_8:
        key = KEY_KEYPAD_8;
        break;
    case KEY_KEYPAD_9:
        key = KEY_KEYPAD_9;
        break;
    case KEY_KEYPAD_6:
    case KEY_UNKNOWN_4D46:
        key = KEY_KEYPAD_6;
        break;
    case KEY_KEYPAD_3:
        key = KEY_KEYPAD_3;
        break;
    case KEY_KEYPAD_2:
        key = KEY_KEYPAD_2;
        break;
    case KEY_KEYPAD_1:
        key = KEY_KEYPAD_1;
        break;
    case KEY_KEYPAD_4:
    case KEY_UNKNOWN_4B43:
        key = KEY_KEYPAD_4;
        break;
    case KEY_KEYPAD_7:
        key = KEY_KEYPAD_7;
        break;
    default:
        if (*(char *) &key != 0)
            ((char *) &key)[1] = 0;
    }
    return key;
}
/* shared_include_end: ../../../../shared/c/MENU-KEY.C */

/* shared_include_start: ../../../../shared/c/PAN-BLANK.C -- generated */
/* PAN-BLANK.C -- c_pan_blank, blanking the animation area.
 */

/* Blank the animation area to colour 5 and let the repaint hook redraw what
 * sits over it.
 */
INT c_pan_blank(void)
{
    drv_real_fill_rect(shd_screen, 0, 0, shm_pan_width, 0xc8, 5);
    c_hook_repaint();
    shd_screen->bg_pen = 5;
}
/* shared_include_end: ../../../../shared/c/PAN-BLANK.C */

/* shared_include_start: ../../../../shared/c/WAIT-FOR-RELEASE.C -- generated */
/* WAIT-FOR-RELEASE.C -- c_wait_for_release, waiting until nothing is pressed.
 */

/* Drain the keyboard, then wait for the joystick's buttons to be let go when
 * it is on.
 */
void c_wait_for_release(void)
{
    while (drv_jump_keyboard_empty() == 0)
        c_menu_key();
    while (shm_options & OPT_JOYSTICK) {
        if (c_joystick_button(0) != 0)
            continue;
        if (c_joystick_button(1) == 0)
            break;
    }
}
/* shared_include_end: ../../../../shared/c/WAIT-FOR-RELEASE.C */

/* shared_include_start: ../../../../shared/c/JOY-KEY.C -- generated */
/* JOY-KEY.C -- c_joystick_key, reading the joystick as a menu key.
 */

/* The stick as a menu key: KEY_UP, KEY_DOWN, or -1 otherwise or with the
 * joystick off. Button 0 is Return and button 1 Escape, and a button wins.
 */
INT c_joystick_key(void)
{
    INT x;
    INT key;
    INT y;

    key = -1;
    if (shm_options & OPT_JOYSTICK) {
        switch (key = c_joystick_read(&x, &y)) {
        case JOY_UP:
        case JOY_UP_RIGHT:
        case JOY_UP_LEFT:
            key = KEY_UP;
            break;
        case JOY_DOWN_RIGHT:
        case JOY_DOWN:
        case JOY_DOWN_LEFT:
            key = KEY_DOWN;
            break;
        default:
            key = -1;
        }
        if (c_joystick_button(0) != 0)
            key = KEY_ENTER;
        if (c_joystick_button(1) != 0)
            key = KEY_ESC;
    }
    return key;
}
/* shared_include_end: ../../../../shared/c/JOY-KEY.C */

/* shared_include_start: ../../../../shared/c/JOY-READ.C -- generated */
/* JOY-READ.C -- c_joystick_read, reading the joystick's direction.
 */

/* Read the stick into `*px` and `*py` as -1, 0 or 1 each and answer the
 * direction, 1 to 8 clockwise from up, or -1 if centred or the joystick is
 * off.
 */
INT c_joystick_read(INT *px, INT *py)
{
    if ((shm_options & OPT_JOYSTICK) == 0)
        return -1;
    *(INT *) &shm_joystick = drv_jump_joy_read();
    *px = (char) shm_joystick.x;
    *py = (char) shm_joystick.y;
    if (*px > 0x60)
        *px = 1;
    else if (*px < -0x60)
        *px = -1;
    else
        *px = 0;
    if (*py > 0x60)
        *py = 1;
    else if (*py < -0x60)
        *py = -1;
    else
        *py = 0;
    return *(INT *) ((char *) &shd_joystick_dirs[4] + (*px * 3 + *py) * 2);
}
/* shared_include_end: ../../../../shared/c/JOY-READ.C */

/* shared_include_start: ../../../../shared/c/JOY-BUTTON.C -- generated */
/* JOY-BUTTON.C -- c_joystick_button, whether a joystick button is down.
 */

/* Answer whether joystick button `button` is down. The game port at 201h
 * carries the four buttons in its high nibble, active low.
 */
INT c_joystick_button(INT button)
{
    return ((INT) inp(0x201) >> (button + 4) & 1) == 0;
}
/* shared_include_end: ../../../../shared/c/JOY-BUTTON.C */

/* shared_include_start: ../../../../shared/c/SAVE-PUT.C -- generated */
/* SAVE-PUT.C -- c_save_put, saving the game.
 */

/* Save the game: the header and twelve sections into the shared block or, for
 * any name but "env.sve", into a new file. `unused` is not read.
 */
void c_save_put(char *name)
{
    INT unused;
    char block[1024];
    char FAR *far_at;

    shm_campaign.saved_minutes = shm_clock_minutes;
    COMM()->case_city = shm_case_city;
    COMM()->case_org = shm_case_org;
    COMM()->options = shm_options;
    COMM()->mission = shm_mission;
    COMM()->case_org_1 = shm_case_org_1;
    COMM()->case_org_2 = shm_case_org_2;
    COMM()->case_city_1 = shm_case_city_1;
    COMM()->case_city_2 = shm_case_city_2;
    COMM()->clock_minutes = shm_clock_minutes;
    COMM()->suspect_count = shm_suspect_count;
    COMM()->building_count = shm_building_count;
    COMM()->case_tick = shm_case_tick;
    COMM()->carried_38 = shm_case_spare_2;
    COMM()->difficulty = shm_difficulty;
    COMM()->case_seed = shm_case_seed;
    COMM()->crime_role_count = shm_crime_role_count;
    COMM()->crime_event_count = shm_crime_event_count;
    COMM()->prisoner = shm_jailbreak_suspect;
    COMM()->graphics_letter = (char) shm_graphics_letter;
    COMM()->log_count = shm_log_count;
    COMM()->double_agent_cities = shm_double_agent_cities;
    COMM()->orgs_known = shm_orgs_known;
    COMM()->skills = shm_skills;
    COMM()->carried_52 = shm_global_alert_level;
    if (strcmp(name, shd_str_env_sve_put) != 0) {
        far_at = block;
        shm_save_fd = open((rt_addr) name,
                                               0x8301, 0x80);
        shm_save_block = COMM_BYTES + 0x10;
        COPY_FAR(shm_save_block, far_at, 0x3f0);
        write(shm_save_fd, block, 0x3f0);
        strcpy(shm_campaign.city_name, shm_cities[shm_case_city].name);
        shm_save_offset = 0;
    } else {
        shm_save_offset = 0x400;
    }
    c_put_section(shm_save_fd, (char *) &shm_campaign, 0x28e);
    c_put_section(shm_save_fd, (char *) shm_crime_roles,
                    shm_crime_role_count * 0x30);
    c_put_section(shm_save_fd, (char *) shm_role_scan_states,
                    shm_crime_role_count * 6);
    c_put_section(shm_save_fd, (char *) shm_crime_events,
                    shm_crime_event_count * 0x2c);
    c_put_section(shm_save_fd, (char *) shm_cities, 0x220);
    c_put_section(shm_save_fd, (char *) shm_orgs, 0x240);
    c_put_section(shm_save_fd, (char *) shm_suspects, 0x400);
    c_put_section(shm_save_fd, (char *) shm_buildings, 0xc00);
    c_put_section(shm_save_fd, (char *) shm_clues_shown, 0x3c0);
    c_put_section(shm_save_fd, (char *) shm_log, 0x700);
    c_put_section(shm_save_fd, (char *) shm_crime_block, 0x48);
    c_put_section(shm_save_fd, (char *) &shm_activity, 0x40);
    if (shm_save_offset == 0)
        close(shm_save_fd);
}
/* shared_include_end: ../../../../shared/c/SAVE-PUT.C */

/* shared_include_start: ../../../../shared/c/PUT-SECTION.C -- generated */
/* PUT-SECTION.C -- c_put_section, writing one section of a save.
 */

/* Write `many` bytes from `at` to `fd` or, when shm_save_offset is set, into
 * the shared block at that offset.
 */
void c_put_section(INT fd, char *at, INT many)
{
    char FAR *far_at;

    if (shm_save_offset != 0) {
        far_at = at;
        shm_save_block = COMM_BYTES + shm_save_offset;
        COPY_FAR(far_at, shm_save_block, many);
        shm_save_offset += many;
    } else {
        write(fd, at, many);
    }
}
/* shared_include_end: ../../../../shared/c/PUT-SECTION.C */

/* shared_include_start: ../../../../shared/c/GET-SECTION.C -- generated */
/* GET-SECTION.C -- c_get_section, reading one section of a saved game.
 */

/* Read `many` bytes of a saved game into `at`: from the shared block when
 * shm_save_offset is set, else from `fd`.
 */
void c_get_section(INT fd, char *at, INT many)
{
    char FAR *far_at;

    if (shm_save_offset != 0) {
        far_at = at;
        shm_save_block = COMM_BYTES + shm_save_offset;
        COPY_FAR(shm_save_block, far_at, many);
        shm_save_offset += many;
    } else {
        read(fd, at, many);
    }
}
/* shared_include_end: ../../../../shared/c/GET-SECTION.C */

/* shared_include_start: ../../../../shared/c/SAVE-GET.C -- generated */
/* SAVE-GET.C -- c_save_get, loading a saved game.
 */

/* Load a save from the file `name`, or for "env.sve" from the shared block
 * alone: the header, then twelve sections. Answers 0 if the file cannot be
 * opened.
 */
INT c_save_get(char *name)
{
    INT i;
    char block[1024];
    INT copy[3];
    char FAR *far_at;

    if (strcmp(name, shd_str_env_sve) != 0) {
        far_at = block;
        shm_save_fd = open((rt_addr) name, 0x8000);
        if (shm_save_fd == -1) {
            strcpy(shm_scratch, shd_str_file_error);
            strcat(shm_scratch, name);
            strcat(shm_scratch, shd_str_newline_12);
            c_ask_menu((rt_addr) shm_scratch, 100, 0x50);
            return 0;
        }
        for (i = 0; i < 3; i++)
            copy[i] = COMM()->driver_segment[i];
        shm_save_block = COMM_BYTES + 0x10;
        read(shm_save_fd, block, 0x3f0);
        COPY_FAR(far_at, shm_save_block, 0x3f0);
        for (i = 0; i < 3; i++)
            COMM()->driver_segment[i] = copy[i];
        shm_save_offset = 0;
    } else {
        shm_save_offset = 0x400;
    }
    shm_case_city = COMM()->case_city;
    shm_case_org = COMM()->case_org;
    shm_options = COMM()->options;
    shm_mission = COMM()->mission;
    shm_case_org_1 = COMM()->case_org_1;
    shm_case_org_2 = COMM()->case_org_2;
    shm_case_city_1 = COMM()->case_city_1;
    shm_case_city_2 = COMM()->case_city_2;
    shm_clock_minutes = COMM()->clock_minutes;
    shm_suspect_count = COMM()->suspect_count;
    shm_building_count = COMM()->building_count;
    shm_case_tick = COMM()->case_tick;
    shm_case_spare_2 = COMM()->carried_38;
    shm_difficulty = COMM()->difficulty;
    shm_case_seed = COMM()->case_seed;
    shm_crime_role_count = COMM()->crime_role_count;
    shm_crime_event_count = COMM()->crime_event_count;
    shm_jailbreak_suspect = COMM()->prisoner;
    if (shm_save_offset != 0)
        shm_graphics_letter = COMM_LETTER_BYTE;
    shm_cga = shm_graphics_letter == 'C';
    shm_log_count = COMM()->log_count;
    shm_double_agent_cities = COMM()->double_agent_cities;
    shm_orgs_known = COMM()->orgs_known;
    shm_skills = COMM()->skills;
    shm_global_alert_level = COMM()->carried_52;
    c_get_section(shm_save_fd, (char *) &shm_campaign, 0x28e);
    c_get_section(shm_save_fd, (char *) shm_crime_roles,
                    shm_crime_role_count * 0x30);
    c_get_section(shm_save_fd, (char *) shm_role_scan_states,
                    shm_crime_role_count * 6);
    c_get_section(shm_save_fd, (char *) shm_crime_events,
                    shm_crime_event_count * 0x2c);
    c_get_section(shm_save_fd, (char *) shm_cities, 0x220);
    c_get_section(shm_save_fd, (char *) shm_orgs, 0x240);
    c_get_section(shm_save_fd, (char *) shm_suspects, 0x400);
    c_get_section(shm_save_fd, (char *) shm_buildings, 0xc00);
    c_get_section(shm_save_fd, (char *) shm_clues_shown, 0x3c0);
    c_get_section(shm_save_fd, (char *) shm_log, 0x700);
    c_get_section(shm_save_fd, (char *) shm_crime_block, 0x48);
    c_get_section(shm_save_fd, (char *) &shm_activity, 0x40);
    if (shm_save_offset == 0)
        close(shm_save_fd);
}
/* shared_include_end: ../../../../shared/c/SAVE-GET.C */
