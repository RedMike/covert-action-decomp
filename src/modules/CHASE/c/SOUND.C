/* SOUND.C -- playing a sound effect.
 */
#include "CHASE.H"
#include "SETUP.H"

/* Play `effect` through the driver, if bit 2 of the option word says sound is
 * on at all.
 */
void c_sound_command(INT effect)
{
    if (shm_options & OPT_SOUND)
        drv_jump_snd_command(effect, asm_engine_note);
}
