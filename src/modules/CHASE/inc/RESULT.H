/* RESULT.H -- the slots of COMM_BLOCK's `result` CHASE reads and writes.
 * GAME's RESULT.H names every handover's, with the same values.
 */
#ifndef RESULT_H
#define RESULT_H

/* In. */

/** Into CHASE: the suspect being tailed. */
#define RES_CHASE_SUSPECT 0
/** Into CHASE: the organisation the chase starts from. */
#define RES_CHASE_ORG 1
/** Into CHASE: the suspect's visuals, whose bit 0 is their gender for CHASE's closing message. */
#define RES_CHASE_SEX 2

/* Out. */

/** Out of CHASE: how the chase ended, 1 the suspect led home, 2 caught. */
#define RES_CHASE_OUTCOME 1
/** Out of CHASE: the suspect's suspicion as a percentage, 0 to 100 in steps
 * of 25, the alert GAME hands c_raise_alert. */
#define RES_CHASE_ALERT 2
/** Out of CHASE and TAC: 0 lets an arrest turn the suspect, revealing his role. */
#define RES_ROLE_HIDDEN 5
/** Out of CHASE: the organisation whose building was reached. */
#define RES_CHASE_GOAL_ORG 6
/** Out of every minigame: how long it took. */
#define RES_MINUTES 7

#endif
