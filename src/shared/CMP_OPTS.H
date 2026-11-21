/* CMP_OPTS.H -- the bits of the option word: COMM_BLOCK's `options`, which
 * every module copies into shm_options. Bit 0 is never used.
 */
#ifndef CMP_OPTS_H
#define CMP_OPTS_H

#define OPT_FEMALE 0x2          /* the agent is Maxine rather than Max */
#define OPT_SOUND 0x4           /* sound on; Alt-S */
#define OPT_ANIMATION 0x8       /* animations on; Alt-A */
#define OPT_JOYSTICK 0x10       /* the joystick is read; Alt-J */
#define OPT_PRACTICE 0x20       /* practising a skill, not in a campaign */
#define OPT_MISSION_ENDED 0x40  /* saved as the previous mission ended */
#define OPT_COPYRIGHT_SKIP 0x80 /* copy protection already passed */

#endif /* CMP_OPTS_H */
