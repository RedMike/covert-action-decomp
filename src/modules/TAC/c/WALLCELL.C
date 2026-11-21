/* WALLCELL.C -- putting a wall on one side of a cell.
 */
#include "TAC.H"
#include "WALLCELL.H"

/* Put a wall on one side of a cell, mark the matching side of the cell across
 * from it, and redraw both from the wall-shape table. */
INT c_set_wall(INT col, INT row, INT side)
{
    /* The wall is shared: the cell across that side gets it on its facing side, within the floor. */
    asm_wall_map[(col << 5) + row] |= 1 << side;
    if (side == 0 && row > 0)
        asm_wall_map[(col << 5) + row - 1] |= 4;
    if (side == 1 && col < 39)
        asm_wall_map[(col << 5) + row + 32] |= 8;
    if (side == 2 && row < 31)
        asm_wall_map[(col << 5) + row + 1] |= 1;
    if (side == 3 && col > 0)
        asm_wall_map[(col << 5) + row - 32] |= 2;
    /* Both cells show the wall piece their walls now call for. */
    asm_floor_map[(col << 5) + row] =
        dat_wall_tiles[asm_wall_map[(col << 5) + row]];
    asm_floor_map[((dat_side_dx[side] + col) << 5) + dat_side_dy[side] + row] =
        dat_wall_tiles[asm_wall_map[((dat_side_dx[side] + col) << 5)
            + dat_side_dy[side] + row]];
}
