/* Reading one key, with the numeric keypad folded onto the arrow keys. */

#include "CHASE.H"
#include "KEYCODES.H"
#include "KEYREAD.H"

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
