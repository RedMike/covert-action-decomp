/* SETUP.H -- the hand-back, the sound command, and two do-nothing routines.
 *
 * c_hook_hand_back takes a long, as its sites push it, and tests one word.
 * UNSET_PARAMS3 keeps c_draw_face's parameters out of the definition.
 */
#ifndef SETUP_H
#define SETUP_H

void c_hook_hand_back(LONG hand_back);
INT c_sound_command(UNSIGNED_INT what);
void c_hook_repaint(void);
void c_draw_face(UNSIGNED_INT a, UNSIGNED_INT b, UNSIGNED_INT c);

#endif
