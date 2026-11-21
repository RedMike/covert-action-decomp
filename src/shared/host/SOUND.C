/* SOUND.C -- the sound driver, which is the null one.
 *
 * NSOUND.CA answers every entry with a RETF, and so does this.
 */

#include "DRIVERS.H"

void FAR drv_jump_snd_open(void)
{
}

void FAR drv_jump_snd_command(INT command, ...)
{
}

UNSIGNED_INT FAR drv_jump_snd_close(void)
{
    return 0;
}
