/* CLUE-FULL.C -- c_clue_line_full, a clue record as its own line.
 */

/* Append clue record `nth` as its own line from clues.txt rather than as an
 * assembled phrase.
 */
void c_clue_line_full(INT nth)
{
    c_clue_from_file(shm_clues_shown[nth].subject,
                    shm_clues_shown[nth].text, nth);
}
