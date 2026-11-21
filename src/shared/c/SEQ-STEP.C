/* SEQ-STEP.C -- c_seq_step, advancing a sequence by one frame.
 */

/* Advance the sequence by one frame and say what next: 0 carry on, 1 finished,
 * its script ended or its frame count run out, and -1 interrupted.
 */
INT c_seq_step(void)
{
    INT r;

    if (c_seq_interrupted() != 0)
        return -1;
    shm_seq_frames_done++;
    c_hold_frame();
    r = c_seq_frames(1);
    c_hold_frame();
    if (--shm_seq_frames_left == 0)
        r = 1;
    return r;
}