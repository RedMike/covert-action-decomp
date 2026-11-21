/* FACES.H -- loading and cutting the faces, and the two ways one is drawn.
 */
#ifndef FACES_H
#define FACES_H

void c_draw_face(INT flags, INT x, INT y);
void c_draw_face_panel(INT flags, INT x, INT y);
void c_faces_cut(void);
void c_faces_load(void);

#endif
