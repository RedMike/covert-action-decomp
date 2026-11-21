/* SOUNDCMD.C -- sending a sound command to the driver.
 */
#include "TAC.H"
#include "PAGESHOW.H"

/* Play `which` through the driver, if bit 2 of the option word says sound is
 * on at all, with the two sound arguments after it.
 */
INT c_sound_command(INT which)
{
    /* Stay silent when the player has turned sound off. */
    if ((shm_options & OPT_SOUND) != 0)
        drv_jump_snd_command(which, asm_sound_arg_1, asm_sound_arg_2);
}
