/* DOORWAY.C -- the cell a doorway between two rooms stands on.
 */
#include "TAC.H"
#include "PLACE.H"

/* Find the doorway joining two rooms and report the cell it stands on as seen
 * from `from`, stepping across the threshold when the record names the two
 * rooms the other way round.
 */
INT c_doorway_cell(INT from, INT to, INT *col, INT *row)
{
    INT v0j;    /* which doorway is being looked at */

    for (v0j = 0; v0j < asm_doorway_count; v0j++) {
        /* Cut from `from`'s side: the record's cell is already that side's. */
        if (asm_doorways[v0j].from == from
            && asm_doorways[v0j].to == to) {
            *col = asm_doorways[v0j].col;
            *row = asm_doorways[v0j].row;
            return 1;
        }
        /* Cut from `to`'s side: step through it to the cell on `from`'s. */
        if (asm_doorways[v0j].from == to
            && asm_doorways[v0j].to == from) {
            *col = asm_doorways[v0j].col
                + dat_side_dx[asm_doorways[v0j].facing];
            *row = asm_doorways[v0j].row
                + dat_side_dy[asm_doorways[v0j].facing];
            return 1;
        }
    }
    /* No doorway joins the two rooms. */
    return 0;
}
