/* TILES.C -- the cheap distance, the first piece of the tiles unit.
 */
#include "TAC.H"
#include "FACES.H"
#include "ANI_LD2.H"
#include "TILES.H"
#include "MODOPTS.H"

/* The cheap distance between two offsets: the longer leg plus half the
 * shorter, which is close enough to a hypotenuse for a guard's reach. */
INT c_cheap_distance(INT dx, INT dy)
{
    /* Only the lengths of the legs matter. */
    dx = abs(dx);
    dy = abs(dy);
    /* The longer leg in full, the shorter at half. */
    if (dx > dy)
        return dy / 2 + dx;
    return dx / 2 + dy;
}
