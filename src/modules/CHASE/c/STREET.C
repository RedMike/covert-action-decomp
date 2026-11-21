/* STREET.C -- the street test for a board block.
 */
#include "CHASE.H"
#include "STREET.H"

/* Whether the block at (row, col) has a street on `side`, numbered as the
 * facings are: bit 0 or 3 of its byte, or of the neighbour that holds that
 * side. A side out of range answers with the side.
 */
UNSIGNED_INT c_is_open(INT row, INT col, INT side)
{
    if (row == 0 && side != 1)
        return 0;
    if (col == 0 && side != 2)
        return 0;
    if (row == 0x17 && side != 3)
        return 0;
    if (col == 0x17 && side != 0)
        return 0;
    switch (side) {
    case 0:
        return asm_cell_map[row * 24 + col - 1] & 8;
    case 1:
        return asm_cell_map[row * 24 + col] & 1;
    case 2:
        return asm_cell_map[row * 24 + col] & 8;
    case 3:
        return asm_cell_map[row * 24 + col - 24] & 1;
    default:
        return (side);
    }
}
