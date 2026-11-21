/* ORIENT.H -- the agent's orientation, only under FLEXIBLE_ORIENTATION.
 *
 * FINAL asks for it after the agent's sex and, each mission, settles what
 * stands in for that sex in GAME's briefing. Both live in unused bytes of the
 * shared block, so they cross modules and saves; zero is the shipped game's.
 */
#ifndef ORIENT_H
#define ORIENT_H

#ifdef FLEXIBLE_ORIENTATION

#define ORIENTATION_STRAIGHT 0
#define ORIENTATION_GAY 1
#define ORIENTATION_BISEXUAL 2

/* Where the two bytes sit in spare_66: the orientation, then the mission's
 * pairing plus one, 0 for none yet. */
#define COMM_ORIENTATION (0x1fe - 0x66)
#define COMM_MISSION_ORIENTATION (0x1ff - 0x66)

/* What the agent chose, ORIENTATION_*. */
extern INT orientation;
/* What stands in for the agent's sex, 0 male and 1 female as in bit 1 of
 * shm_options: a straight agent's own sex, a gay agent's the other, a
 * bisexual agent's rolled each mission. */
extern INT mission_orientation;

void c_orientation_load(void);
void c_orientation_menu(void);
void c_orientation_roll(void);
INT c_orientation_partner(void);
INT c_orientation_babe(INT kind, INT n);

#endif

#endif /* ORIENT_H */
