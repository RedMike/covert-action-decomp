/* WRAP.C -- breaking the message buffer into lines.
 */
#include "GAME.H"
#include "WRAP.H"

/* shared_include_start: ../../../../shared/c/WRAP-MESSAGE.C -- generated */
/* WRAP-MESSAGE.C -- c_wrap_message, wrapping text into lines.
 */

/* Wrap shm_scratch at the first space past `width` characters on each line. A
 * '^' forces a break.
 */
void c_wrap_message(INT width)
{
    INT run;
    INT i;

    run = 0;
    for (i = 0; (INT) strlen(shm_scratch) > i; i++) {
        if ((shm_scratch)[i] == '^') {
            (shm_scratch)[i] = ' ';
            (shm_scratch)[i + 1] = '\n';
            run = -1;
        }
        if ((shm_scratch)[i] == '\n')
            run = -1;
        run++;
        if (run > width && (shm_scratch)[i] == ' '
            && (shm_scratch)[i + 1] != ' ') {
            (shm_scratch)[i] = '\n';
            run = 0;
        }
    }
    if (run > 0)
        strcat(shm_scratch, shd_str_newline_wrap);
}
/* shared_include_end: ../../../../shared/c/WRAP-MESSAGE.C */
