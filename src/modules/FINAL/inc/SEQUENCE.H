/* SEQUENCE.H -- playing a scripted sequence, a frame at a time.
 */
#ifndef SEQUENCE_H
#define SEQUENCE_H

void c_seq_play(str_addr a, INT b, INT c, INT d);
void c_seq_set_var(INT line, INT value);
void c_seq_sound(INT what);
INT c_seq_interrupted(void);
INT c_seq_run(struct SEQ_BLOCK *block);
INT c_seq_start(struct SEQ_BLOCK *block);
INT c_seq_set_picture(INT entry);
INT c_seq_stop(void);
INT c_seq_step(void);
void c_seq_restart(void);
INT c_seq_frames(INT frames);

#endif
