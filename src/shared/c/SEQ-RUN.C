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
