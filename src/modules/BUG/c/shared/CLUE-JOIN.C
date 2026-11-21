/* CLUE-JOIN.C -- a clue record written out as one phrase.
 */
#include "BUG.H"
#include "REPORT.H"

/* shared_include_start: ../../../../shared/c/CLUE-LINE.C -- generated */
/* CLUE-LINE.C -- c_clue_line, a clue record as an assembled phrase.
 */

/* Append clue record `nth` to shm_scratch as a phrase: the clue's thing, the
 * joining words and the subject, a half left out where its word is -1.
 */
void c_clue_line(INT nth)
{
    if (shm_clues_shown[nth].text != -1) {
        c_clue_thing(shm_clues_shown[nth].text);
        strcat(shm_scratch,
                   (char *) shd_clue_phrases[
                       c_clue_phrase(
                           shm_clues_shown[nth].subject,
                           shm_clues_shown[nth].text)]);
    }
    if (shm_clues_shown[nth].subject != -1) {
        c_clue_subject(nth,
                        shm_clues_shown[nth].subject);
        strcat(shm_scratch, shd_str_period);
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-LINE.C */

/* shared_include_start: ../../../../shared/c/CLUE-PHRASE.C -- generated */
/* CLUE-PHRASE.C -- c_clue_phrase, choosing the words that join up a clue.
 */

/* Which of the forty phrases in shd_clue_phrases joins a clue to its subject:
 * the run of five by the clue type in `kind`, the place in it by the fact bit
 * in `about`.
 */
INT c_clue_phrase(INT about, INT kind)
{
    INT pick;
    INT step;

    pick = ((kind >> 8) & 7) * 5;
    for (step = about >> 8; step > 1; step >>= 1)
        pick++;
    return pick;
}
/* shared_include_end: ../../../../shared/c/CLUE-PHRASE.C */
