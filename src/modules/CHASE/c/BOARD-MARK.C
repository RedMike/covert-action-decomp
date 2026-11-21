/* BOARD-MARK.C -- marking a car's place on the board.
 */
#include "CHASE.H"
#include "BOARDMAR.H"
#include "BOARDDOT.H"

/* Mark (x, y) on the board as a two-by-two block of dots in `what`, the board
 * being drawn at a quarter of the map's scale.
 */
void c_board_mark(INT x, INT y, INT what)
{
    INT v0j;
    INT v1a;

    c_board_dot((x << 3) / 32, (y << 3) / 32, what);
    v0j = (x << 3) / 32 + 1;
    c_board_dot(v0j, (y << 3) / 32, what);
    v1a = (y << 3) / 32 + 1;
    c_board_dot((x << 3) / 32, v1a, what);
    c_board_dot(v0j, v1a, what);
}
