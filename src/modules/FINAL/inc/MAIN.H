/* MAIN.H -- the sound command, the animation player, case set-up and hooks.
 */
#ifndef MAIN_H
#define MAIN_H

/* Answers an int without a return statement: whatever the body left in AX. */
INT c_sound_command(UNSIGNED_INT what);
void c_play_animation(rt_addr name, UNSIGNED_INT x, UNSIGNED_INT y);
void c_practice_setup(INT mode);
void c_hook_hand_back(UNSET_PARAMS(INT unused));
void c_hook_repaint(void);
void c_opening_blurb(void);
void c_hook_message(void);

#endif
