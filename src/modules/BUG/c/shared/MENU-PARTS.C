/* MENU-PARTS.C -- the menu's box, its background animation and its input.
 */
#include "BUG.H"
#include "KEYCODES.H"
#include "LOADDISK.H"
#include "ANIMSTUB.H"
#include "PRIMS.H"
#include "MAIN.H"
#include "MENU.H"

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
