/* shared/MAIN.C -- the shared routines in MAIN.C's unit, after stubs/HOOK-HAND-BACK.C. */
#include "BUG.H"
#include "LOADDISK.H"
#include "ANIMSTUB.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "MENU.H"
#include "BOARD.H"
#include "MAIN.H"
#include "RESULT.H"

/* shared_include_start: ../../../../shared/c/SOUND-COMMAND.C -- generated */
/* SOUND-COMMAND.C -- c_sound_command, a command for the sound driver. */

/* Send the command `what` alone to the sound driver when sound is on (bit 2 of
 * the options).
 */
INT c_sound_command(UNSIGNED_INT what)
{
    if (shm_options & OPT_SOUND)
        drv_jump_snd_command(what);
}
/* shared_include_end: ../../../../shared/c/SOUND-COMMAND.C */

/* shared_include_start: ../../../../shared/c/DISPLAY-PAGE.C -- generated */
/* DISPLAY-PAGE.C -- c_set_display_page, choosing the page the screen shows.
 */

/* Make `page` the BIOS's active display page: INT 10h function 5, through the
 * shared register block.
 */
void c_set_display_page(char page)
{
    shm_regs.h.ah = 5;
    shm_regs.h.al = page;
    INTERRUPT(0x10, &shm_regs, &shm_regs);
}
/* shared_include_end: ../../../../shared/c/DISPLAY-PAGE.C */
