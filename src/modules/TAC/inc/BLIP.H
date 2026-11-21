/* BLIP.H -- a dot on the board, a man's blip on the map, stepping the effects.
 *
 * c_step_effects takes a long, as its sites push it.
 */
#ifndef BLIP_H
#define BLIP_H

void c_board_dot(INT x, INT y, INT colour);
INT c_guard_knocked_down(INT nth);
INT c_step_effects(LONG draw);

#endif
