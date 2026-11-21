/* shared/TAG.C -- the shared routines in TAG.C's unit, after TAG.C. */
#include "GAME.H"
#include "BLOCK.H"
#include "TAG.H"

/* shared_include_start: ../../../../shared/c/MESSAGE-TAG.C -- generated */
/* MESSAGE-TAG.C -- c_message_tag, building a message's text tag.
 */

/* Build the tag "*MSGaabb" in shm_message_key from `a` and `b`; a negative `b`
 * makes `a` 99 and `b` half its magnitude.
 */
INT c_message_tag(INT a, INT b)
{
    strcpy(shm_message_key, shd_str_msg0000);
    if (b < 0) {
        a = 99;
        b = -b / 2;
    }
    shm_message_key[4] += a / 10;
    shm_message_key[5] += a % 10;
    shm_message_key[6] += b / 10;
    shm_message_key[7] += b % 10;
}
/* shared_include_end: ../../../../shared/c/MESSAGE-TAG.C */
