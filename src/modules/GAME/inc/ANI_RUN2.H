/* ANI_RUN2.H -- running a sequence, and the picture it is set against.
 */
#ifndef ANI_RUN2_H
#define ANI_RUN2_H

INT c_seq_interrupted(void);
INT c_seq_run(struct SEQ_BLOCK *block);
INT c_seq_set_picture(INT entry);
INT c_seq_start(struct SEQ_BLOCK *block);
INT c_seq_stop(void);

#endif
