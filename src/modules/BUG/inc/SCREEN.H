/* SCREEN.H -- the headings and the boxes they sit in.
 */
#ifndef SCREEN_H
#define SCREEN_H

void c_page_frame(rt_addr text, INT colour);
void c_folder_header(INT x, INT y, UNSIGNED_INT colour);
INT c_text_width(rt_addr text);
void c_text_panel(INT x, INT y);
void c_draw_centred(str_addr text, INT x, INT y, UNSIGNED_INT colour);

#endif
