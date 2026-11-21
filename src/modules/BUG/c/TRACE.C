/* TRACE.C -- following a signal through the board's wiring and drawing it.
 */
#include "BUG.H"
#include "PRIMS.H"
#include "BOARD.H"

/* Walk the wire leaving one cell, marking each cell it reaches as carrying the
 * signal or not by `mark` and drawing it. `from` is the way the signal came
 * in; while the clock runs, each step takes a tick.
 */
void c_trace_wire(INT col, INT row, INT from, INT mark)
{
    INT lane;
    INT way;
    INT bits;

    while ((bits = asm_wire_grid[col][row]) != 0 && from != -1) {
        asm_wire_grid[col][row] =
            (INT) (unsigned char) bits + (mark != 0 ? WIRE_LIVE : 0);
        c_draw_wires(col, row, from);
        lane = -1;
        for (way = 0; way < 8; way++) {
            if (((unsigned char) (from + 4) & 7) != way && (bits & 1 << way)) {
                if (lane == -1)
                    lane = way;
                else
                    c_trace_wire(*(INT *) &dat_neighbour_col[way] + col,
                                    *(INT *) &dat_neighbour_row[way] + row,
                                    way, mark);
            }
        }
        from = lane;
        col += dat_neighbour_col[from];
        row += dat_neighbour_row[from];
        if (asm_frame_count != 0 && asm_seconds_left > 1) {
            c_tick(1);
            c_wait_retraces(1);
        }
    }
}

/* Draw one cell's wires, an 8x8 sprite per neighbour bit: BUG_SPRITE_WIRE, or
 * where the cell carries the signal, BUG_SPRITE_WIRE_IN for the way it came in
 * and BUG_SPRITE_WIRE_OUT for the rest.
 */
void c_draw_wires(INT col, INT row, INT from)
{
    INT lane;
    INT shape;

    shape = asm_wire_grid[col][row];
    for (lane = 0; lane < 8; lane++) {
        if (shape & 1 << lane) {
            if (shape & WIRE_LIVE)
                c_draw_bug_sprite((((unsigned char) (from + 4) & 7) == lane
                                   ? BUG_SPRITE_WIRE_IN
                                   : BUG_SPRITE_WIRE_OUT) + lane,
                                  col << 3, row << 3);
            else
                c_draw_bug_sprite(BUG_SPRITE_WIRE + lane, col << 3,
                                  row << 3);
        }
    }
}
