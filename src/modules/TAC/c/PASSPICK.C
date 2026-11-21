/* PASSPICK.C -- picking the password.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "REVEAL.H"

/* Pick the password out of TEXT.DTA: seek somewhere at random, then read words
 * until one is five to nine letters and all lower case, and cover it in dots. */
INT c_pick_password(void)
{
    INT v0j[128];   /* never read */
    INT v1l;        /* which letter is being checked */
    INT v2n;        /* whether the word will do */
    INT v3;         /* likewise reserved */
    rt_stream v4b;  /* the open file */

    /* Start somewhere in the file's first 20000 bytes and drop the word it lands in. */
    v4b = fopen(dat_str_text_dta, dat_str_mode_read_text_2);
    fseek(v4b, (LONG) c_random_below(20000), 0);
    fscanf(v4b, dat_fmt_word, asm_password_text);
    /* Take the next word that is five to nine lower-case letters. */
    v2n = 0;
    do {
        fscanf(v4b, dat_fmt_word_2, asm_password_text);
        if ((INT) strlen(asm_password_text) >= 5
            && (INT) strlen(asm_password_text) <= 9) {
            v2n = 1;
            for (v1l = 0; (INT) strlen(asm_password_text) > v1l; v1l++)
                if (((char *) asm_password_text)[v1l] < 'a'
                    || ((char *) asm_password_text)[v1l] > 'z') {
                    v2n = 0;
                    break;
                }
        }
    } while (v2n == 0);
    /* The hint starts as dots, one per letter of the password. */
    strcpy(asm_password_hint,
               dat_password_hint_initial);
    asm_password_hint[strlen(asm_password_text)] = 0;
    fclose(v4b);
}
