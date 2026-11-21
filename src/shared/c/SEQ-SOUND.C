/* SEQ-SOUND.C -- c_seq_sound, an animation's sound hook.
 */

/* The sound hook a PAN animation calls: hand it on to the sound player. */
void c_seq_sound(INT what)
{
    c_sound_command(what);
}
