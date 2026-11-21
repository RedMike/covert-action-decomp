/* SOLVE-ONE.C -- giving one letter away.
 */
#include "CODE.H"
#include "RANDOM.H"
#include "PUZZLE.H"

/* Give one unguessed letter away: draw at random, 999 times at most, until a
 * letter turns up that the text uses and the player has not filled in, then
 * write its plain form into the guess row and mark it known.
 */
void c_give_letter(void)
{
    INT again;
    INT idx;
    INT cur;

    /* A letter the text uses that the player has not filled in, if there is one. */
    again = 0;
    do {
        cur = c_random_below(asm_alphabet_size);
    } while (asm_letter_count[cur] == 0
             || (dat_guess[cur] != ' ' && ++again < 999));
    /* Fill in what it really stands for, and remember it was given. */
    for (idx = 0; idx < asm_alphabet_size; idx++)
        if ((char) dat_cipher[idx] == cur + 'A') {
            dat_guess[cur] = dat_plain[idx];
            asm_letter_known[cur] = 1;
        }
}
