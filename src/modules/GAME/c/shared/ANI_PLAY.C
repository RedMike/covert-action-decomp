/* ANI_PLAY.C -- playing a full-screen animation and setting its variables.
 */
#include "GAME.H"
#include "ANI_RUN2.H"
#include "ANI_PLAY.H"

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
