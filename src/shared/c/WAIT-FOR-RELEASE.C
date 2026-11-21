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