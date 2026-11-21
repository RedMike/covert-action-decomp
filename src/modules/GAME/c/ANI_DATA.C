/* ANI_DATA.C -- the declaration of the sequencer's far data, opening its unit.
 *
 * All the sequencer keeps in FARDATA is reached through `shm_seq_data`: the
 * unit names one far object and no more.
 */
#include "GAME.H"
#include "ANI_OPS.H"

/* The whole far segment as one structure, declared here rather than in
 * GAME.H. */
extern struct SEQ FAR shm_seq_data;
