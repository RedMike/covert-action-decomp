/* shared/MAIN-3.C -- the shared routines in MAIN.C's unit, after MAIN.C. */
#include "FINAL.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "LOADDISK.H"
#include "CSTART.H"
#include "CMISEND.H"
#include "CMISSTRT.H"
#include "CASERUN.H"
#include "SAVELOAD.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "MAIN.H"
#include "ORIENT.H"
#include "MODOPTS.H"
#include "SETUPTXT.H"
#include "RESULT.H"
#include "ALERTLVL.H"

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
