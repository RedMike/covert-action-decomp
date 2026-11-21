/* RESULT.H -- the slots of COMM_BLOCK's `result` TAC reads and writes.
 * GAME's RESULT.H names every handover's, with the same values.
 */
#ifndef RESULT_H
#define RESULT_H

/* In. */

/** Into TAC: the prisoner to free, or the organisation ambushing the player. */
#define RES_TAC_TARGET 4

/* Out. */

/** Out of TAC: how the mission ended; 0ffh the player caught. */
#define RES_TAC_END_LINE 0
/** Out of TAC: how far the organisation is alerted. */
#define RES_TAC_ALERT 1
/** Out of TAC: outcome bits, 1 the crime object found, 2 an arrest. */
#define RES_TAC_OUTCOME 2
/** Out of TAC: the wounds taken, each six hours to recover. */
#define RES_TAC_WOUNDS 3
/** Out of CHASE and TAC: 0 lets an arrest turn the suspect, revealing his role. */
#define RES_ROLE_HIDDEN 5
/** Out of every minigame: how long it took. */
#define RES_MINUTES 7

#endif
