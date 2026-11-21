/* CLAMP.C -- c_clamp, bringing a value inside a range.
 *
 * Compiled on its own, so it includes PORTING.H alone.
 */
#include "PORTING.H"

/* Answer `v` brought inside `low`..`high`, both inclusive. */
INT c_clamp(INT v, INT low, INT high)
{
    if (v < low)
        v = low;
    if (v > high)
        v = high;
    return v;
}
