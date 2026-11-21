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
