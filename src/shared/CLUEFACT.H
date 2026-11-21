/* CLUEFACT.H -- names for the five facts a crime role's clues give: the bits
 * of CRIME_ROLE's `clues_known`, and the high byte of SHOWN_CLUE's `subject`.
 */
#ifndef CLUEFACT_H
#define CLUEFACT_H

#define CLUE_FACE   0x1     /* the suspect's face */
#define CLUE_NAME   0x2     /* the suspect's real name */
#define CLUE_ORG    0x4     /* the suspect's organisation */
#define CLUE_CITY   0x8     /* the suspect's city */
#define CLUE_ROLE   0x10    /* the role in the plot itself */

#endif /* CLUEFACT_H */
