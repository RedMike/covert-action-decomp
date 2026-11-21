/* CASEFLAG.H -- the bits of asm_case_flags, which the career record keeps as
 * each case's second byte: c_efficiency_report sets them as it scores the
 * case, and c_career_screen reads them back.
 */
#ifndef CASEFLAG_H
#define CASEFLAG_H

#define CASE_ARRESTS        0xf     /* how many participants were arrested or turned, counted up */
#define CASE_CRIME_DONE     0x40    /* the case's crime was committed: it could not be stopped */
#define CASE_MASTERMIND     0x80    /* the MasterMind was taken; the record adds his organisation */

#endif /* CASEFLAG_H */
