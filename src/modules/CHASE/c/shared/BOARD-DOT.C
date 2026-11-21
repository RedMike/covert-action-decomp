/* BOARD-DOT.C -- one dot on the board.
 */
#include "CHASE.H"
#include "BOARDDOT.H"
#include "LINE.H"

/* shared_include_start: ../../../../shared/c/BOARD-DOT.C -- generated */
/* BOARD-DOT.C -- c_board_dot, plotting a single pixel.
 */

/* Put one pixel of `colour` at (x, y), as a line of one point. */
void c_board_dot(INT x, INT y, INT colour)
{
    c_draw_line(x, y, x, y, colour);
}
/* shared_include_end: ../../../../shared/c/BOARD-DOT.C */
