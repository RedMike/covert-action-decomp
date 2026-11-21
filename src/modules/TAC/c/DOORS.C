/* DOORS.C -- cutting doorways between the rooms.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "DOORS.H"

/* Cut doorways between the rooms until every one of them is reachable, or
 * until the tries or the doorway table run out. The empty `if` is as shipped:
 * its test is evaluated and neither arm goes anywhere. */
INT c_cut_doorways(void)
{
    INT v0j;    /* how many tries have been made */
    INT v1j;    /* the room the doorway leaves */
    INT v2k;    /* where it goes, across */
    INT v3k;    /* the room it reaches */
    INT v4l;    /* and down */
    INT v5m;    /* how far either side is looked at */
    INT v6m;    /* whether the spot will do */
    INT v7n;    /* whether a room is still walled off */
    INT v8n;    /* which way the doorway faces */
    INT v9o;    /* how many rooms have been reached */

    /* Start with every room walled off from every other. */
    for (v5m = 0; v5m < 24; v5m++) {
        asm_room_doorways[v5m] = 0;
        *(LONG *) &asm_rooms[v5m].neighbours = LONG_LIT(0);
    }
    /* The walk starts in a random room, which counts as reached; v7n is never
     * set anywhere but to 0, so the tests on it decide nothing. */
    v7n = v0j = asm_doorway_count = 0;
    v1j = c_random_below(asm_room_count) + 1;
    v9o = 1;
    do {
        do {
            /* Try the middle of one of the room's four walls, at random. */
            switch (c_random_below(4)) {
        /* The top wall. */
        case 0:
            v2k = asm_rooms[v1j].width / 2
                + asm_rooms[v1j].left;
            v4l = asm_rooms[v1j].top;
            v8n = 0;
            break;
        /* The bottom wall. */
        case 1:
            v2k = asm_rooms[v1j].width / 2
                + asm_rooms[v1j].left;
            v4l = asm_rooms[v1j].top
                + asm_rooms[v1j].height - 1;
            v8n = 2;
            break;
        /* The left wall. */
        case 2:
            v4l = asm_rooms[v1j].height / 2
                + asm_rooms[v1j].top;
            v2k = asm_rooms[v1j].left;
            v8n = 3;
            break;
        /* The right wall. */
        case 3:
            v4l = asm_rooms[v1j].height / 2
                + asm_rooms[v1j].top;
            v2k = asm_rooms[v1j].left
                + asm_rooms[v1j].width - 1;
            v8n = 1;
            break;
        }
        /* The room across that wall; one already joined is simply walked into. */
        v6m = 1;
        v3k = asm_room_map[((dat_side_dx[v8n] + v2k) << 5) + dat_side_dy[v8n]
            + v4l];
        if ((*(LONG *) &asm_rooms[v1j].neighbours
             & (LONG) (1 << v3k)) == 0) {
            /* A new doorway needs the cell and those either side of it, on both
             * sides of the wall, clear of any wall running across this one. */
            for (v5m = -1; v5m <= 1; v5m++) {
                if (((v8n & 1) != 0 ? 5 : 0xa)
                    & asm_wall_map[((dat_side_dx[v8n + 1] * v5m + v2k) << 5)
                        + dat_side_dy[v8n + 1] * v5m + v4l])
                    v6m = 0;
                if (((v8n & 1) != 0 ? 5 : 0xa)
                    & asm_wall_map[((dat_side_dx[v8n + 1] * v5m
                        + dat_side_dx[v8n] + v2k) << 5) + dat_side_dy[v8n + 1] * v5m + dat_side_dy[v8n] + v4l])
                    v6m = 0;
            }
            if ((*(LONG *) &asm_rooms[v1j].neighbours
                 & (LONG) (1 << v3k)) == 0) {
            }
        }
        /* No doorway is cut to the street. */
        if (v3k == 0)
            v6m = 0;
        } while (++v0j < 999 && v6m == 0);
        /* A spot found into a room not yet joined: cut the doorway. */
        if ((*(LONG *) &asm_rooms[v1j].neighbours
             & (LONG) (1 << v3k)) == 0
            && v0j < 999) {
            /* Take the wall out from both sides. */
            asm_wall_map[(v2k << 5) + v4l] &=
                0xf - (1 << v8n);
            asm_wall_map[((dat_side_dx[v8n] + v2k) << 5) + dat_side_dy[v8n]
                + v4l] &=
                0xf - (1 << ((v8n + 2) & 3));
            /* Each room has one more doorway, and the tries start over. */
            asm_room_doorways[v1j]++;
            asm_room_doorways[v3k]++;
            v0j = 0;
            /* A room joined to nothing until now has just been reached. */
            if (*(LONG *) &asm_rooms[v3k].neighbours
                == 0)
                v9o++;
            *(LONG *) &asm_rooms[v1j].neighbours |=
                (LONG) (1 << v3k);
            *(LONG *) &asm_rooms[v3k].neighbours |=
                (LONG) (1 << v1j);
            /* A door on each side, each the Door record facing its own way out. */
            asm_floor_map[(v2k << 5) + v4l] = v8n + 8;
            asm_floor_map[((dat_side_dx[v8n] + v2k) << 5) + dat_side_dy[v8n]
                + v4l] =
                ((v8n + 2) & 3) + 8;
            /* Keep the doorway, for the guards' routes and the room distances. */
            asm_doorways[asm_doorway_count].from = v1j;
            asm_doorways[asm_doorway_count].to =
                v3k;
            asm_doorways[asm_doorway_count].col =
                v2k;
            asm_doorways[asm_doorway_count].row =
                v4l;
            asm_doorways[asm_doorway_count].facing =
                v8n;
            asm_doorway_count++;
            if (v7n != 0
                && (asm_rooms[v3k].flags & 2) != 0)
                v7n = 0;
        }
        /* Walk on into the room across, and go on until every room is reached. */
        v1j = v3k;
    } while ((v9o < asm_room_count || v7n != 0)
             && v0j < 999 && asm_doorway_count < 96);
    /* The layout holds only if the walk ended that way. */
    return v7n == 0 && v0j < 999 && asm_doorway_count < 96;
}
