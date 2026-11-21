/* FACES.H -- faces: loading and cutting the sprites, and drawing a face.
 */
#ifndef FACES_H
#define FACES_H

void c_faces_load(void);
void c_draw_face(INT flags, INT x, INT y);
void c_draw_face_panel(INT flags, INT x, INT y);
void c_faces_cut(void);

#endif
