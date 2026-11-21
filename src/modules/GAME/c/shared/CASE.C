/* shared/CASE.C -- the shared routines in CASE.C's unit, after CASE.C. */
#include "GAME.H"
#include "SPRITES.H"
#include "CASE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "DIALOG.H"
#include "FRAME.H"
#include "BLOCK.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "SUSPECTS.H"
#include "PANEL.H"
#include "FACES.H"
#include "HANDOVER.H"
#include "TAG.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/WAIT-KEY.C -- generated */
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
/* shared_include_end: ../../../../shared/c/WAIT-KEY.C */

