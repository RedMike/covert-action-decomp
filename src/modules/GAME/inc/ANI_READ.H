/* ANI_READ.H -- opening an animation and reading it by block and by frame.
 */
#ifndef ANI_READ_H
#define ANI_READ_H

void c_anim_start_chunks(void);
INT c_anim_byte(void);
void c_anim_chunk(void);
INT c_anim_extra_blocks(void);
INT c_anim_frame(void);
INT c_anim_frame_header(void);
void c_anim_frame_rows(INT arg);
INT c_anim_open(rt_addr name);
INT c_anim_paragraphs(void);
INT c_anim_read(char *dest, INT size, INT count);
INT c_anim_signature(rt_addr name);
INT c_anim_sprites(void);
INT c_set_border_colour(INT page);

#endif
