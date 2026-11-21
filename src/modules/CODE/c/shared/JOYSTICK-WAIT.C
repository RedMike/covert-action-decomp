/* JOYSTICK-WAIT.C -- waiting for the keys and buttons to be let go.
 */
#include "CODE.H"
#include "JOYBTN.H"
#include "JOYWAIT.H"
#include "KEYREAD.H"

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
