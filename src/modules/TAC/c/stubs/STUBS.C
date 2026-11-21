/* STUBS.C -- the empty animation-sequence hooks.
 */
#include "TAC.H"
#include "PORTING.H"
#include "STUBS.H"

/* Three RETs in a row: the animation-sequence hooks, which do nothing here.
 * UNSET_PARAMS keeps the first's parameter out of the definition.
 */
INT c_seq_start(UNSET_PARAMS(struct SEQ_BLOCK *block))
{
}

INT c_seq_step(void)
{
}

INT c_seq_stop(void)
{
}
