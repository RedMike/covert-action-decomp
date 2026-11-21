/* MISC1.C -- menu keys, the joystick, drawing primitives and the video mode.
 */
#include "GAME.H"
#include "KEYCODES.H"
#include "MISC1.H"
#include "ADVICE.H"

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

/* shared_include_start: ../../../../shared/c/DRAW-LINE.C -- generated */
/* DRAW-LINE.C -- c_draw_line, drawing a line on the screen.
 */

/* Draw a line from (x1, y1) to (x2, y2) in `colour`. */
INT c_draw_line(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour)
{
    return drv_real_draw_line(shd_screen, x1, y1, x2, y2, colour);
}
/* shared_include_end: ../../../../shared/c/DRAW-LINE.C */

/* shared_include_start: ../../../../shared/c/TEXT-OUT.C -- generated */
/* TEXT-OUT.C -- c_write_text, writing text on the screen.
 */

/* Write `text` at (`across`, `down`) in `colour` and answer the width written.
 */
INT c_write_text(drv_addr text, INT across, INT down, UNSIGNED_INT colour)
{
    shd_screen->fg_pen = colour;
    return drv_jump_gfx_text(shd_screen, across, down, text);
}
/* shared_include_end: ../../../../shared/c/TEXT-OUT.C */

/* shared_include_start: ../../../../shared/c/WRITE-TEXT-TRIMMED.C -- generated */
/* WRITE-TEXT-TRIMMED.C -- c_write_text_trimmed, text without the extra rows.
 */

/* Write `text` with the screen's draw mode 0, so glyphs lose the font's extra
 * rows.
 */
INT c_write_text_trimmed(drv_addr text, INT across, INT down, UNSIGNED_INT colour)
{
    shd_screen->draw_mode = 0;
    c_write_text(text, across, down, colour);
    shd_screen->draw_mode = 1;
}
/* shared_include_end: ../../../../shared/c/WRITE-TEXT-TRIMMED.C */

/* shared_include_start: ../../../../shared/c/WAIT-RETRACES.C -- generated */
/* WAIT-RETRACES.C -- c_wait_retraces, waiting for vertical retraces.
 */

/* Wait `n` vertical retraces, by bit 3 of status port 3dah. `unused` is not
 * read.
 */
INT c_wait_retraces(INT n)
{
    INT unused;

    if (n != 0)
        while (n-- != 0) {
            while ((inp(0x3da) & 8) == 0)
                ;
            while ((inp(0x3da) & 8) != 0)
                ;
        }
}
/* shared_include_end: ../../../../shared/c/WAIT-RETRACES.C */

/* shared_include_start: ../../../../shared/c/SCREEN-SAVE.C -- generated */
/* SCREEN-SAVE.C -- c_screen_save, a whole-screen copy that copies nothing.
 */

/* Meant to copy the whole screen from page 0 to page 2, but the height of 0
 * copies nothing.
 */
void c_screen_save(void)
{
    drv_jump_gfx_copy_rect((struct RASTPORT *) 0, 0, 0, 2, 0, (struct RASTPORT *) 0, 0x13f, 0xc7);
}
/* shared_include_end: ../../../../shared/c/SCREEN-SAVE.C */

/* shared_include_start: ../../../../shared/c/SCREEN-RESTORE.C -- generated */
/* SCREEN-RESTORE.C -- c_screen_restore, a screen copy that copies nothing.
 */

void c_screen_restore(void)
{
    drv_jump_gfx_copy_rect((struct RASTPORT *) 2, 0, 0, 0, 0, (struct RASTPORT *) 0, 0x13f, 0xc7);
}
/* shared_include_end: ../../../../shared/c/SCREEN-RESTORE.C */

/* shared_include_start: ../../../../shared/c/FILL-BOX.C -- generated */
/* FILL-BOX.C -- c_fill_box, filling a rectangle given by its corners.
 */

/* Fill the box from (x1, y1) to (x2, y2), corners included, in `colour`. */
INT c_fill_box(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour)
{
    return drv_real_fill_rect(shd_screen, x1, y1, x2 - x1 + 1,
                             y2 - y1 + 1, colour);
}
/* shared_include_end: ../../../../shared/c/FILL-BOX.C */

/* shared_include_start: ../../../../shared/c/GRAPHICS-MODE.C -- generated */
/* GRAPHICS-MODE.C -- c_set_graphics_mode, switching to 16-colour graphics.
 */

/* Set BIOS video mode 0dh, 320x200 in sixteen colours, through shm_regs. */
INT c_set_graphics_mode(void)
{
    shm_regs.h.ah = 0;
    shm_regs.h.al = 0xd;
    INTERRUPT(0x10, &shm_regs, &shm_regs);
}
/* shared_include_end: ../../../../shared/c/GRAPHICS-MODE.C */
