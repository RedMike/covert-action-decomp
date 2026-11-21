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
