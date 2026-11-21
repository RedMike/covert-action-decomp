/* SIGNOF.C -- the sign of a number.
 */
#include "TAC.H"
#include "SIGNOF.H"

/* shared_include_start: ../../../../shared/c/SIGN.C -- generated */
/* SIGN.C -- c_sign, the sign of a number.
 */

/* Which way `n` points: 1, -1, or 0 for neither. */
INT c_sign(INT n)
{
    if (n > 0)
        return 1;
    if (n < 0)
        return -1;
    return 0;
}
/* shared_include_end: ../../../../shared/c/SIGN.C */
