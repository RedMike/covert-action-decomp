/* DIALOG.C -- the menu dialogues and the boxes they are drawn in.
 */
#include "GAME.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "LOADDISK.H"
#include "HANDOVER.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DIALOG.H"
#include "ANI_RUN.H"
#include "ANI_RUN2.H"
#include "NOTICE.H"
#include "FACES.H"

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
