/* SEQSTUBS.H -- the two empty sequence hooks.
 *
 * UNSET_PARAMS keeps c_seq_start's parameter out of the definition.
 */
#ifndef SEQSTUBS_H
#define SEQSTUBS_H

void c_seq_start(struct SEQ_BLOCK *save);
INT c_seq_step(void);

#endif
