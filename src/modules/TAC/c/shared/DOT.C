/* DOT.C -- putting one pixel on the board.
 */
#include "TAC.H"
#include "BLIP.H"
#include "CITY.H"

/* shared_include_start: ../../../../shared/c/BOARD-DOT.C -- generated */
/* BOARD-DOT.C -- c_board_dot, plotting a single pixel.
 */

/* Put one pixel of `colour` at (x, y), as a line of one point. */
void c_board_dot(INT x, INT y, INT colour)
{
    c_draw_line(x, y, x, y, colour);
}
/* shared_include_end: ../../../../shared/c/BOARD-DOT.C */
