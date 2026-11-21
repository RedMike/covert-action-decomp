/* ROLEFLAG.H -- names for the bits of CRIME_ROLE's `flags`.
 *
 * The crime file supplies the word, and a red herring's is zero. The low byte
 * says where the role's suspect is placed. The high byte is the participant
 * type, and the game marks two more bits in it as the case runs. A write to
 * the high byte as a byte shifts its name down by 8.
 */
#ifndef ROLEFLAG_H
#define ROLEFLAG_H

/* Low byte: where the role's suspect is placed. 04 is unused. */
#define ROLE_MASTERMIND_ORG 0x1     /* in the mastermind's organisation */
#define ROLE_CASE_CITY_3    0x2     /* in the case's third city */
#define ROLE_UNKNOWN_08     0x8     /* purpose unknown */
#define ROLE_CASE_CITY_2    0x10    /* in the case's second city */
#define ROLE_CASE_CITY_1    0x20    /* in the case's first city */
#define ROLE_CASE_ORG_2     0x40    /* in the case's second organisation */
#define ROLE_CASE_ORG_1     0x80    /* in the case's first organisation */

/* High byte: the participant type, then the game's own marks. */
#define ROLE_MASTERMIND     0x100   /* the mastermind */
#define ROLE_WIDOW          0x200   /* a widow: the suspect is made female */
#define ROLE_LISTED         0x4000  /* already listed in the clue menu being drawn */
#define ROLE_REVEALED       0x8000  /* set on every role by c_reveal_case at the end of the case */

#endif /* ROLEFLAG_H */
