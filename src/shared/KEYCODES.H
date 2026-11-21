/* KEYCODES.H -- names for the driver's key word: scan code high, ASCII low.
 *
 * KEY_KEYPAD_* are keypad digits with Num Lock on; KEY_ALT_* are named for the
 * key pressed; the letters are the lower-case word. KEY_UNKNOWN_<hex> are
 * alternate words for the keys above.
 *
 * JOY_* are c_joystick_read's directions, and JOY_B1_* TAC's word for one with
 * button 1 held: that direction's keypad scan code plus 80h.
 */
#ifndef KEYCODES_H
#define KEYCODES_H

enum {
    KEY_UP = 0x4800,
    KEY_DOWN = 0x5000,
    KEY_LEFT = 0x4b00,
    KEY_RIGHT = 0x4d00,
    KEY_HOME = 0x4700,
    KEY_END = 0x4f00,
    KEY_PGUP = 0x4900,
    KEY_PGDN = 0x5100,
    KEY_INS = 0x5200,
    KEY_DEL = 0x5300,

    KEY_KEYPAD_1 = 0x4f31,
    KEY_KEYPAD_2 = 0x5032,
    KEY_KEYPAD_3 = 0x5133,
    KEY_KEYPAD_4 = 0x4b34,
    KEY_KEYPAD_6 = 0x4d36,
    KEY_KEYPAD_7 = 0x4737,
    KEY_KEYPAD_8 = 0x4838,
    KEY_KEYPAD_9 = 0x4939,

    KEY_CTRL_BREAK = 0, /* the word the BIOS buffers for Ctrl-Break */
    KEY_ESC = 0x1b,
    KEY_ENTER = 0xd,
    KEY_BACKSPACE = 8,
    KEY_SPACE = 0x20,
    KEY_MINUS = 0x2d,
    KEY_1 = 0x31,
    KEY_2 = 0x32,
    KEY_3 = 0x33,
    KEY_4 = 0x34,
    KEY_5 = 0x35,
    KEY_6 = 0x36,
    KEY_7 = 0x37,
    KEY_8 = 0x38,
    KEY_9 = 0x39,
    KEY_EQUALS = 0x3d,
    KEY_A = 0x61,
    KEY_D = 0x64,
    KEY_E = 0x65,
    KEY_F = 0x66,
    KEY_S = 0x73,
    KEY_F1 = 0x3b00,
    KEY_F2 = 0x3c00,
    KEY_F3 = 0x3d00,
    KEY_F4 = 0x3e00,
    KEY_F5 = 0x3f00,
    KEY_F6 = 0x4000,
    KEY_F7 = 0x4100,
    KEY_F8 = 0x4200,
    KEY_F9 = 0x4300,
    KEY_F10 = 0x4400,

    KEY_ALT_P = 0x1900,
    KEY_ALT_Q = 0x1000,
    KEY_ALT_A = 0x1e00,
    KEY_ALT_S = 0x1f00,
    KEY_ALT_J = 0x2400,

    KEY_UNKNOWN_487E = 0x487e,
    KEY_UNKNOWN_5060 = 0x5060,
    KEY_UNKNOWN_4B7C = 0x4b7c,
    KEY_UNKNOWN_475C = 0x475c,
    KEY_UNKNOWN_4B43 = 0x4b43,
    KEY_UNKNOWN_4D46 = 0x4d46,
    KEY_UNKNOWN_F400 = -3072, /* f400h, which MSC 5.1 refuses in an enum */

    JOY_UP = 1,
    JOY_UP_RIGHT = 2,
    JOY_RIGHT = 3,
    JOY_DOWN_RIGHT = 4,
    JOY_DOWN = 5,
    JOY_DOWN_LEFT = 6,
    JOY_LEFT = 7,
    JOY_UP_LEFT = 8,

    JOY_B1_UP = 0xc8,
    JOY_B1_UP_RIGHT = 0xc9,
    JOY_B1_RIGHT = 0xcd,
    JOY_B1_DOWN_RIGHT = 0xd1,
    JOY_B1_DOWN = 0xd0,
    JOY_B1_DOWN_LEFT = 0xcf,
    JOY_B1_LEFT = 0xcb,
    JOY_B1_UP_LEFT = 0xc7
};

#endif
