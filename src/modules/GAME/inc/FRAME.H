/* FRAME.H -- the page frame, the badge bar across it, and text width.
 */
#ifndef FRAME_H
#define FRAME_H

void c_folder_header(INT x, INT y, UNSIGNED_INT colour);
void c_page_frame(rt_addr text, INT colour);
INT c_text_width(rt_addr text);

#endif
