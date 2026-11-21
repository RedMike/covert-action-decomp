/* SOLVED.C -- whether the puzzle counts as solved.
 */
#include "CODE.H"
#include "SOLVED.H"

/* Whether the puzzle counts as solved: more than nineteen points and nothing
 * guessed wrong, where a letter the text never uses is worth half a point.
 * `padh` is never read.
 */
INT c_is_solved(void)
{
    INT zero;
    INT correct;
    INT idx;
    INT index;
    INT error;
    INT padh;

    /* Tally right guesses, wrong ones, and letters the text never uses. */
    idx = correct = error = zero = 0;
    for (; idx < asm_alphabet_size; idx++) {
        index = (char) dat_cipher[idx] - 'A';
        if (dat_guess[index] != ' '
            && asm_letter_count[index] > 0) {
            if (dat_guess[index] == dat_plain[idx])
                correct++;
            else
                error++;
        }
        if (asm_letter_count[index] == 0)
            zero++;
    }
    /* Enough right and none wrong; an unused letter counts for half. */
    return zero / 2 + correct > 19 && error == 0;
}
