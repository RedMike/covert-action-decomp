/* DATA.C -- the sequencer's far data, defined for the portable build.
 *
 * It is the one datum the assembly defines outside the data group, which the
 * portable build takes whole from elsewhere.
 */
#include "GAME.H"
#include "ANI_OPS.H"

/* FARDATA, whole, as one structure. */
struct SEQ shm_seq_data;
