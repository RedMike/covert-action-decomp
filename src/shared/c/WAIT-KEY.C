/* WAIT-KEY.C -- c_wait_key, waiting for a key or a joystick button.
 */

/* Wait for a key, or either joystick button when the stick is on, then for
 * everything to be let go; answer the key's menu code, or 1 for a button.
 */
INT c_wait_key(void)
{
    INT input;   /* the key, or 1 for a button, and -1 until one arrives */

    input = -1;
    while (drv_jump_keyboard_empty() != 0 && input == -1) {
        if (shm_options & OPT_JOYSTICK) {
            if (c_joystick_button(0) != 0 || c_joystick_button(1) != 0)
                input = 1;
        }
    }
    if (input == -1)
        input = c_menu_key();
    c_wait_for_release();
    return input;
}
