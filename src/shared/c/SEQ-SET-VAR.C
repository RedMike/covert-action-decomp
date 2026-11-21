/* SEQ-SET-VAR.C -- c_seq_set_var, setting a sequence variable.
 */

/* Set sequence variable `line` to `value`, with no bounds check. */
void c_seq_set_var(INT line, INT value)
{
    shm_seq_vars[line] = value;
}
