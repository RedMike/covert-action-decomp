/* OCTANT16.C -- turning a step into a facing, the finer way.
 */
#include "TAC.H"
#include "OCTANT16.H"

/* The finer facing: a step counts as straight only while one axis is more than
 * twice the other, and the eight answers fall out of the two tests. */
INT c_facing8(INT dx, INT dy)
{
    INT v0j;    /* set while the step is mostly across */
    INT v1k;    /* set while it is mostly down */

    /* Whether the step is near enough level or near enough upright to count as straight. */
    v0j = (INT) abs(dy) * 2 < (INT) abs(dx);
    v1k = (INT) abs(dx) * 2 < (INT) abs(dy);
    /* Down and right: right, down, or the diagonal between. */
    if (dx > 0) {
        if (dy > 0) {
            if (v0j != 0)
                return 3;
            if (v1k != 0)
                return 5;
            return 4;
        }
        /* Up and right: right, up, or the diagonal between. */
        if (v0j != 0)
            return 3;
        if (v1k != 0)
            return 1;
        return 2;
    }
    /* Down and left: left, down, or the diagonal between. */
    if (dy > 0) {
        if (v0j != 0)
            return 7;
        if (v1k != 0)
            return 5;
        return 6;
    }
    /* Up and left: left, up, or the diagonal between. */
    if (v0j != 0)
        return 7;
    if (v1k != 0)
        return 1;
    return 8;
}
