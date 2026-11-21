/* GUESS-ROW.C -- rebuilding the guess row from the letters known.
 */
#include "CODE.H"
#include "PUZZLE.H"

/* Rebuild the guess row from the letters marked known, blanking the rest. */
void c_fill_guess_row(void)
{
    INT letter;
    INT index;

    /* Keep the letters the player was given; forget their own guesses. */
    for (letter = 0; letter < asm_alphabet_size; letter++) {
        if (asm_letter_known[letter] != 0) {
            for (index = 0; index < asm_alphabet_size; index++)
                if ((char) dat_cipher[index] == letter + 'A')
                    dat_guess[letter] = dat_plain[index];
        } else
            dat_guess[letter] = ' ';
    }
}
