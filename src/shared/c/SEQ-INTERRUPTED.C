/* SEQ-INTERRUPTED.C -- c_seq_interrupted, whether the player has interrupted.
 */

/* Answer 1 to stop the sequence on a key or joystick button after three
 * frames; where a stop was asked for, note it in sequence variable 6 and
 * answer 0. The c_menu_key call is unreachable, as shipped.
 */
INT c_seq_interrupted(void)
{
    if ((drv_jump_keyboard_empty() != 0
         && ((shm_options & OPT_JOYSTICK) == 0 || c_joystick_button(0) == 0))
        || shm_seq_frames_done < 3)
        return 0;
    if (drv_jump_keyboard_empty == 0)
        c_menu_key();
    if (shm_seq_stop_asked != 0) {
        shm_seq_stop_asked = 0;
        shm_seq_vars[6] = -1;
        return 0;
    }
    return 1;
}
