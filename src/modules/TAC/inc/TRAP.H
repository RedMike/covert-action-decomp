/* TRAP.H -- setting a trap, drawing the cast, and hearing a noise.
 *
 * c_resolve_shot's second parameter is unchecked: it is defined as an INT but
 * called with a long.
 */
#ifndef TRAP_H
#define TRAP_H

INT c_draw_cast(void);
INT c_resolve_shot(INT who, UNCHECKED_PARAMS(INT heard));
INT c_add_grenade(INT x, INT y, INT dir, INT anim, INT flags);

#endif
