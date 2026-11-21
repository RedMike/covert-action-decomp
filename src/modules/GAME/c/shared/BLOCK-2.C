/* shared/BLOCK-2.C -- the shared routines in BLOCK.C's unit, after BLOCK.C. */
#include "GAME.H"
#include "BLOCK.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "FRAME.H"
#include "CASE.H"
#include "LINES.H"
#include "TAG.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/SAY-ONE-OF.C -- generated */
/* SAY-ONE-OF.C -- c_say_one_of, appending one of several phrasings.
 */

/* Append one of `n` phrasings of the tag `key` from the file `name`: a random
 * number below `n` replaces the tag's last two digits.
 */
INT c_say_one_of(rt_addr name, char *key, INT n)
{
    n = c_random_below(n);
    key[6] = n % 10 + '0';
    key[5] = n / 10 + '0';
    return c_say_block(name, (rt_addr) key);
}
/* shared_include_end: ../../../../shared/c/SAY-ONE-OF.C */
