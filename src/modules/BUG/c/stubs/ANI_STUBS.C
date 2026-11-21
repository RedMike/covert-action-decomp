/* ANI_STUBS.C -- the three animation entry points this module does nothing in.
 */
#include "BUG.H"
#include "PORTING.H"
#include "ANIMSTUB.H"

/* The module has no pan animation to start, step or stop, so each is an empty
 * function. UNSET_PARAMS keeps c_seq_start's parameter out of the definition.
 */
void c_seq_start(UNSET_PARAMS(struct SEQ_BLOCK *block))
{
}

INT c_seq_step(void)
{
}

void c_seq_stop(void)
{
}
