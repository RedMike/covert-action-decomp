/* PUZZLE-SET.C -- shuffling the cipher and laying out the puzzle text.
 */
#include "CODE.H"
#include "RANDOM.H"
#include "PUZZLE.H"

/* Shuffle the cipher alphabet and lay out the puzzle text from the shared
 * block's message, without its spaces at difficulty 3 and up and its full
 * stops at 1 and 2.
 */
void c_puzzle_set(void)
{
    INT letter;
    INT from;
    INT index;
    char trail[1024];

    /* Every puzzle gets a fresh cipher, and no letter starts out given. */
    asm_alphabet_size = 26;
    for (from = 0; from < asm_alphabet_size; from++) {
        index = c_random_below(asm_alphabet_size);
        letter = (char) dat_cipher[from];
        dat_cipher[from] = dat_cipher[index];
        dat_cipher[index] = letter;
        asm_letter_known[from] = 0;
    }
    /* Take the message the game assembled. */
    strcpy(shm_scratch, dat_str_empty);
    for (from = 0; from < 512; from++)
        shm_scratch[from] = COMM()->message[from];
    /* Harder puzzles lose the spaces; middling ones the full stops. */
    for (from = 0; (INT) strlen(shm_scratch) > from; from++) {
        if (shm_scratch[from] == ' ' && asm_difficulty > 2) {
            strcpy(trail, &shm_scratch[from + 1]);
            strcpy(&shm_scratch[from], trail);
        }
        if (shm_scratch[from] == '.'
            && (asm_difficulty == 1 || asm_difficulty == 2)) {
            strcpy(trail, &shm_scratch[from + 1]);
            strcpy(&shm_scratch[from], trail);
        }
    }
    /* Drop the message's last character, and set it in capitals. */
    shm_scratch[strlen(shm_scratch) - 1] = 0;
    strupr(shm_scratch);
}
