/* ANI_PLAY.C -- setting a scripted sequence going and running it out.
 *
 * A sequence is a seven-word block saying what to play, run by a loop that
 * starts it, steps it a frame at a time until it is done, and takes it down.
 */
#include "FINAL.H"
#include "MAIN.H"
#include "SAVELOAD.H"
#include "MENUS.H"
#include "SEQUENCE.H"

/* shared_include_start: ../../../../shared/c/SEQ-PLAY.C -- generated */
/* SEQ-PLAY.C -- c_seq_play, playing a full-screen sequence.
 */

/* Play the full-screen sequence named `a` for duration `b` at origin (`c`,
 * `d`). `spare` is unused.
 */
void c_seq_play(str_addr a, INT b, INT c, INT d)
{
    INT spare;

    shm_fullscreen_pan.name = a;
    shm_fullscreen_pan.duration = b;
    shm_fullscreen_pan.page_a = c;
    shm_fullscreen_pan.page_b = d;
    shm_fullscreen_pan.rate = 0xffff;
    c_seq_run(&shm_fullscreen_pan);
}
/* shared_include_end: ../../../../shared/c/SEQ-PLAY.C */

/* shared_include_start: ../../../../shared/c/SEQ-SET-VAR.C -- generated */
/* SEQ-SET-VAR.C -- c_seq_set_var, setting a sequence variable.
 */

/* Set sequence variable `line` to `value`, with no bounds check. */
void c_seq_set_var(INT line, INT value)
{
    shm_seq_vars[line] = value;
}
/* shared_include_end: ../../../../shared/c/SEQ-SET-VAR.C */

/* shared_include_start: ../../../../shared/c/SEQ-SOUND.C -- generated */
/* SEQ-SOUND.C -- c_seq_sound, an animation's sound hook.
 */

/* The sound hook a PAN animation calls: hand it on to the sound player. */
void c_seq_sound(INT what)
{
    c_sound_command(what);
}
/* shared_include_end: ../../../../shared/c/SEQ-SOUND.C */

/* shared_include_start: ../../../../shared/c/SEQ-INTERRUPTED.C -- generated */
/* SEQ-INTERRUPTED.C -- c_seq_interrupted, whether the player has interrupted.
 */

/* Answer 1 to stop the sequence on a key or joystick button after three
 * frames; where a stop was asked for, note it in sequence variable 6 and
 * answer 0. The c_menu_key call is unreachable, as shipped.
 */
INT c_seq_interrupted(void)
{
    if ((drv_jump_keyboard_empty() != 0
         && ((shm_options & OPT_JOYSTICK) == 0 || c_joystick_button(0) == 0))
        || shm_seq_frames_done < 3)
        return 0;
    if (drv_jump_keyboard_empty == 0)
        c_menu_key();
    if (shm_seq_stop_asked != 0) {
        shm_seq_stop_asked = 0;
        shm_seq_vars[6] = -1;
        return 0;
    }
    return 1;
}
/* shared_include_end: ../../../../shared/c/SEQ-INTERRUPTED.C */

/* shared_include_start: ../../../../shared/c/SEQ-RUN.C -- generated */
/* SEQ-RUN.C -- c_seq_run, running a sequence to its end.
 */

/* Start the sequence `block` describes, step it until it ends, and take it
 * down.
 */
INT c_seq_run(struct SEQ_BLOCK *block)
{
    c_seq_start(block);
    do {
    } while (c_seq_step() == 0);
    c_seq_stop();
}
/* shared_include_end: ../../../../shared/c/SEQ-RUN.C */
