/* SIGHT.C -- the line of sight between two points.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "ALERTED.H"

/* Walk the line between two points cell by cell and say what stops it: 2 for
 * nothing, 1 for cover on the way, 0 for something that blocks sight outright.
 * Only what stands on a cell is looked at, never the walls, and a door blocks
 * nothing. */
INT c_line_of_sight(INT x1, INT y1, INT x2, INT y2)
{
    INT v0j;    /* where the next horizontal crossing is, down */
    INT v1j;    /* the whole span, for the halfway test */
    INT v2j;    /* the cell's column */
    INT v3j;
    INT v4j;    /* the cell's row */
    INT v5j;    /* where the walk has got to, across */
    INT v6j;    /* and down */
    INT v7j;    /* -1 while the walk was folded across */
    INT v8j;    /* and down */
    INT v9j;    /* how far it goes across */
    INT v10c;   /* and down */
    INT v11c;   /* what to report */
    INT v12c;   /* where the next vertical crossing is, across */
    INT v13c;   /* what is on the cell */
    INT v14c;   /* where the next horizontal crossing is, across */
    INT v15c;   /* where the next vertical crossing is, down */

    /* How far the line runs each way; it is clear, in both halves, until something turns up. */
    v9j = x2 - x1;
    v10c = y2 - y1;
    v7j = v8j = 1;
    v11c = 2;
    asm_guard_tick = 3;
    /* A line running left is mirrored across the 640-pixel board so it runs right. */
    if (v9j < 0) {
        v9j = -v9j;
        x1 = 639 - x1;
        x2 = 639 - x2;
        v7j = -1;
    }
    /* And one running up is mirrored down the 512-pixel board. */
    if (v10c < 0) {
        v10c = -v10c;
        y1 = 511 - y1;
        y2 = 511 - y2;
        v8j = -1;
    }
    /* Start at the first point; the line's whole length tells which half cover lies in. */
    v5j = x1;
    v6j = y1;
    v1j = x2 - x1 + y2 - y1;
    /* Shrink the slope's two terms, keeping their ratio, so the products below fit in a word. */
    while (v9j > 100 || v10c > 100) {
        v9j /= 2;
        v10c /= 2;
    }
    for (;;) {
        /* Where the line next crosses into a new column; never, if it runs straight down. */
        v12c = (v5j & 0xfff0) + 16;
        if (v9j != 0)
            v15c = (v12c - x1) * v10c / v9j + y1;
        else {
            v12c = 999;
            v15c = 999;
        }
        /* Where it next crosses into a new row; never, if it runs straight across. */
        v0j = (v6j & 0xfff0) + 16;
        if (v10c != 0)
            v14c = (v0j - y1) * v9j / v10c + x1;
        else {
            v14c = 999;
            v0j = 999;
        }
        /* Step to whichever crossing comes first. */
        if (v12c + v15c < v0j + v14c) {
            v5j = v12c;
            v6j = v15c;
        } else {
            v5j = v14c;
            v6j = v0j;
        }
        /* Past the far point, the line is through: report what it met. */
        if (v5j > x2 || v6j > y2)
            return v11c;
        /* The cell reached, unmirrored back onto the real board. */
        v2j = v5j >> 4;
        v4j = v6j >> 4;
        if (v7j < 0)
            v2j = 39 - v2j;
        if (v8j < 0)
            v4j = 31 - v4j;
        /* What stands there, if anything. */
        v13c = (char) asm_floor_map[(v2j << 5) + v4j]
               & 0x3f;
        if (v13c != 0x3f) {
            /* Something that blocks sight ends it. */
            if ((dat_floor_objects[v13c].flags & FOBJ_OPAQUE)
                != 0)
                return 0;
            /* Cover is noted: near the first point it clears bit 0, near the second bit 1. */
            if ((dat_floor_objects[v13c].flags & FOBJ_SOLID)
                != 0) {
                v11c = 1;
                if (v5j - x1 + v6j - y1 < v1j / 2 + 4)
                    *(char *) &asm_guard_tick &= 0xfe;
                if (v5j - x1 + v6j - y1 > v1j / 2 - 4)
                    *(char *) &asm_guard_tick &= 0xfd;
            }
        }
    }
}
