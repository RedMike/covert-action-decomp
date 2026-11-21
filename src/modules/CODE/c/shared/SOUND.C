/* SOUND.C -- telling the sound driver what the module is doing.
 */
#include "CODE.H"
#include "SETUP.H"

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
