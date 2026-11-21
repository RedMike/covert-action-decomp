/* SUSPFLAG.H -- names for the bits of SUSPECT's `flags`.
 *
 * Most bits are evidence, a fact the player has learnt about the suspect; the
 * others record what has happened to the suspect. Bits 11 to 15 are never set.
 * A write to the high byte as a byte shifts its name down by 8.
 */
#ifndef SUSPFLAG_H
#define SUSPFLAG_H

#define SUSPECT_PHOTO               0x1     /* a photograph: the dossier shows the face */
#define SUSPECT_NAME                0x2     /* the real name rather than a codename */
#define SUSPECT_ORG                 0x4     /* the organisation */
#define SUSPECT_CITY                0x8     /* the city they work from */
#define SUSPECT_PARTICIPANT         0x10    /* identified as a participant in the plot */
#define SUSPECT_MORE_INFO           0x20    /* "additional information", reported and never read */
#define SUSPECT_JAILBREAK_ATTEMPTED 0x40    /* a jailbreak has been tried for them: no second one */
#define SUSPECT_PHOTO_LOST          0x80    /* the photograph was taken away again */
#define SUSPECT_RANK                0x100   /* the rank */
#define SUSPECT_RECRUITED_IN        0x200   /* the Recruited line's city */
#define SUSPECT_RECRUITED_BY        0x400   /* the Recruited line's recruiter */

/* Groups of the bits above, as the tests mask them. */
#define SUSPECT_IDENTITY    0xf     /* photo, name, organisation and city */
#define SUSPECT_BACKGROUND  0x700   /* the rank and both halves of the Recruited line */

#endif /* SUSPFLAG_H */
