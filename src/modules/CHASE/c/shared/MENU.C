/* MENU.C -- running a menu and the keys that drive it.
 */
#include "CHASE.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "SEQSTUBS.H"
#include "HELPCLR.H"
#include "JOYWAIT.H"
#include "SETUP.H"
#include "MENU1.H"
#include "RETRACE.H"
#include "TEXTOUT.H"
#include "KEYREAD.H"
#include "ANI_STOP.H"
#include "LOADDISK.H"

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
