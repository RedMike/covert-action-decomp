/* ANI_SND.C -- the sound hook a PAN animation calls.
 */
#include "GAME.H"
#include "NOTICE.H"
#include "ANI_SND.H"

/* shared_include_start: ../../../../shared/c/SEQ-SOUND.C -- generated */
/* SEQ-SOUND.C -- c_seq_sound, an animation's sound hook.
 */

/* The sound hook a PAN animation calls: hand it on to the sound player. */
void c_seq_sound(INT what)
{
    c_sound_command(what);
}
/* shared_include_end: ../../../../shared/c/SEQ-SOUND.C */
