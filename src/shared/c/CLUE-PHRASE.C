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
