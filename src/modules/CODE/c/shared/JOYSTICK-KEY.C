/* JOYSTICK-KEY.C -- the joystick read as a menu key.
 */
#include "CODE.H"
#include "KEYCODES.H"
#include "JOYREAD.H"
#include "JOYBTN.H"
#include "JOYWAIT.H"

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
