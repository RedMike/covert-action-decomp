/* PATH.C -- flooding the step map towards a goal.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "PLACE.H"

/* Flood the floor's step map outwards from one cell until the goal is reached
 * or the queue runs dry, and answer whether it was reached. */
INT c_flood_path(INT floor, INT who, INT gc, INT gr, INT col, INT row)
{
    INT v0j;        /* where the queue is written */
    INT v1j;        /* and where it is read */
    INT v2j;        /* the step count on the cell being expanded */
    INT v3j;        /* set once the goal is reached */
    INT v4j;        /* that cell's column */
    INT v5j[10];    /* which ways out are open, wrapped at both ends */
    INT v6j;        /* and its row */
    INT v7k;        /* which way out */
    INT v8k;        /* never read */
    INT v9k;        /* the column that way leads to */
    INT v10d;       /* likewise reserved */
    INT v11d;       /* and the row */
    INT v12d;       /* what stands on a cell */
    char v13d;      /* the step count carried back to the goal */

    /* Start from nothing, with the one cell queued. */
    memset(asm_step_map[floor], 0, 1280);
    v0j = 0;
    v1j = 0;
    asm_path_queue_col[v0j] = col;
    asm_path_queue_row[v0j++] = row;
    /* The start counts one step, or none when it stands on something solid. */
    v12d = asm_floor_map[(col << 5) + row] & 0x3f;
    if (v12d != 0x3f
        && (((char *) &dat_floor_objects[0].flags)[v12d * 20] & FOBJ_SOLID) != 0)
        ((char *) asm_step_map)[floor * 1280 + (col << 5) + row] = 0;
    else
        asm_step_map[floor][(col << 5) + row] = 1;
    v3j = 0;
    do {
        /* Take the next cell off the queue, which wraps at 256. */
        v4j = asm_path_queue_col[v1j];
        v6j = asm_path_queue_row[v1j];
        v2j = asm_step_map[floor][(v4j << 5) + v6j];
        v1j++;
        v1j = (unsigned char) v1j;
        /* Which of the eight ways lead to a free cell of the same room; none diagonal
         * from a cell that counted no step. */
        for (v7k = 1; v7k <= 8; v7k++) {
            v9k = dat_step_dx[v7k] + v4j;
            v11d = dat_step_dy[v7k] + v6j;
            v5j[v7k] = 1;
            if (asm_room_map[(v9k << 5) + v11d] != who)
                v5j[v7k] = 0;
            v12d = asm_floor_map[(v9k << 5) + v11d] & 0x3f;
            if (v12d != 0x3f
                && (((char *) &dat_floor_objects[0].flags)[v12d * 20] & FOBJ_SOLID) != 0)
                v5j[v7k] = 0;
            if (v2j == 0 && (v7k & 1) == 0)
                v5j[v7k] = 0;
        }
        /* Count and queue every open way not yet counted, a diagonal only with both sides by it open. */
        v5j[0] = v5j[8];
        v5j[9] = v5j[1];
        for (v7k = 1; v7k <= 8; v7k++) {
            v9k = dat_step_dx[v7k] + v4j;
            v11d = dat_step_dy[v7k] + v6j;
            if (v5j[v7k] == 0)
                continue;
            if ((v7k & 1) == 0) {
                if (v5j[v7k - 1] == 0)
                    continue;
                if (v5j[v7k + 1] == 0)
                    continue;
            }
            if (asm_step_map[floor][(v9k << 5) + v11d] == 0) {
                asm_step_map[floor][(v9k << 5) + v11d] = v2j + 1;
                asm_path_queue_col[v0j] = v9k;
                asm_path_queue_row[v0j] = v11d;
                v0j++;
                v0j = (unsigned char) v0j;
                if (v9k == gc && v11d == gr)
                    v3j = 1;
            }
        }
    } while (v3j == 0 && v1j != v0j);
    /* A goal the flood left uncounted, such as one on something solid, takes a side neighbour's count. */
    if (asm_step_map[floor][(gc << 5) + gr] == 0)
        for (v7k = 0; v7k < 4; v7k++) {
            v9k = dat_side_dx[v7k] + gc;
            v11d = dat_side_dy[v7k] + gr;
            v13d = asm_step_map[floor][(v9k << 5) + v11d];
            if (v13d != 0)
                asm_step_map[floor][(gc << 5) + gr] = v13d;
        }
    return v3j;
}
