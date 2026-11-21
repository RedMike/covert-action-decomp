/* OCTANT.C -- turning a step into one of the eight facings.
 */
#include "TAC.H"
#include "OCTANT.H"

/* Turn a step into one of the eight facings: which axis dominates settles the
 * diagonal, and the signs settle the quadrant. */
INT c_octant(INT dx, INT dy)
{
    INT v0j;    /* set while the step is longer across than down */

    /* Which half of its quadrant the step lies in; each 45-degree sector
     * answers the facing at its anticlockwise edge, not the nearest one. */
    v0j = (INT) abs(dx) > (INT) abs(dy);
    /* Down and right, then up and right. */
    if (dx > 0) {
        if (dy > 0)
            return v0j != 0 ? 3 : 4;
        return v0j != 0 ? 2 : 1;
    }
    /* Down and left. */
    if (dy > 0)
        return v0j != 0 ? 6 : 5;
    /* Up and left. */
    return v0j != 0 ? 7 : 8;
}
