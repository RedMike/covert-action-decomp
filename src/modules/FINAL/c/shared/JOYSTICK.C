/* JOYSTICK.C -- reading the stick, and waiting for it to be let go.
 */
#include "FINAL.H"
#include "KEYCODES.H"
#include "MENUS.H"
#include "SAVELOAD.H"

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
