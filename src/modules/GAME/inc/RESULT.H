/* RESULT.H -- the slots of COMM_BLOCK's `result`, for every handover. GAME
 * fills a minigame's inputs and reads its outputs, so it names them all; each
 * minigame's own RESULT.H names only its handover's, the same values as here.
 */
#ifndef RESULT_H
#define RESULT_H

/* Into CHASE, from a stakeout or a building. */

/** Into CHASE: the suspect being tailed. */
#define RES_CHASE_SUSPECT 0
/** Into CHASE: the organisation the chase starts from. */
#define RES_CHASE_ORG 1
/** Into CHASE: the suspect's visuals, whose bit 0 is their gender for CHASE's closing message. */
#define RES_CHASE_SEX 2

/* Out of CHASE. */

/** Out of CHASE: how the chase ended, 1 the suspect led home, 2 caught. */
#define RES_CHASE_OUTCOME 1
/** Out of CHASE: the suspect's suspicion as a percentage, 0 to 100 in steps
 * of 25, the alert GAME hands c_raise_alert. */
#define RES_CHASE_ALERT 2
/** Out of CHASE: the organisation whose building was reached. */
#define RES_CHASE_GOAL_ORG 6

/* Into TAC. */

/** Into TAC: the prisoner to free, or the organisation ambushing the player. */
#define RES_TAC_TARGET 4

/* Out of TAC. */

/** Out of TAC: how the mission ended; 0ffh the player caught. */
#define RES_TAC_END_LINE 0
/** Out of TAC: how far the organisation is alerted. */
#define RES_TAC_ALERT 1
/** Out of TAC: outcome bits, 1 the crime object found, 2 an arrest. */
#define RES_TAC_OUTCOME 2
/** Out of TAC: the wounds taken, each six hours to recover. */
#define RES_TAC_WOUNDS 3

/* Out of BUG. */

/** Out of BUG: the score, the phones tapped or 0 after an alarm. */
#define RES_BUG_SCORE 0
/** Out of BUG: how many alarm lines tripped. */
#define RES_BUG_ALARMS 1

/* Into CODE. */

/** Into CODE: the log entry to decode; 0ffh none picked. */
#define RES_CODE_MESSAGE 0

/* Out of CODE. */

/** Out of CODE: 1 once the puzzle is solved. */
#define RES_CODE_SOLVED 1
/** Out of CODE: the time taken, in half hours. */
#define RES_CODE_HALF_HOURS 2

/* Out of CHASE and TAC. */

/** Out of CHASE and TAC: 0 lets an arrest turn the suspect, revealing his role. */
#define RES_ROLE_HIDDEN 5

/* Out of every minigame. */

/** Out of every minigame: how long it took. */
#define RES_MINUTES 7

#endif
