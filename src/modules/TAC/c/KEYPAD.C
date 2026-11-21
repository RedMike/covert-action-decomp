/* KEYPAD.C -- asking for the password at a terminal.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "BUGROOM.H"
#include "STATUS.H"
#include "PASSWORD.H"

/* Aim at the cell ahead of the player, and ask for the password where that
 * cell holds a terminal. */
INT c_secondary_interact(void)
{
    INT v0j;    /* what stands on that cell */

    /* Look at what stands on the cell ahead of the player. */
    c_aim_cursor();
    v0j = asm_floor_map[(asm_cursor_col << 5) + asm_cursor_row];
    /* Only a terminal takes a password. */
    if (v0j != -1
        && (dat_floor_objects[(v0j & 0x3f)].flags & FOBJ_TERMINAL) != 0)
        c_ask_password();
}
