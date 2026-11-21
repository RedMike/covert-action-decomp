/* ANI_STUBS.C -- the empty sequence start and step hooks.
 */
#include "CHASE.H"
#include "PORTING.H"
#include "SEQSTUBS.H"

/* Start and step the menu's background animation: empty, as this module has
 * none. UNSET_PARAMS keeps c_seq_start's parameter out of the definition.
 */
void c_seq_start(UNSET_PARAMS(struct SEQ_BLOCK *save))
{
}

INT c_seq_step(void)
{
}
