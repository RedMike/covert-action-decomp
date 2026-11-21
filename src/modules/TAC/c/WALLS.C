/* WALLS.C -- running walls across the floor.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "WALLCELL.H"
#include "WALLS.H"

/* Run twenty walls in from the outside: pick a start on an existing wall that
 * has room around it, then lay cells along one heading until the way is
 * blocked or the floor runs out. */
INT c_run_walls(void)
{
    INT v0j;    /* how many starts have been tried */
    INT v1k;    /* how much of the way is already walled */
    INT v2l;    /* which wall */
    INT v3m;    /* where it is, across */
    INT v4n;    /* and down */
    INT v5o;    /* how far along the neighbours are looked at */
    INT v6;     /* whether the start will do */
    INT v7a;    /* which way the wall runs */

    for (v2l = 0; v2l < 20; v2l++) {
        v0j = 0;
        do {
            /* A random cell off the floor's edge; one walled on a single side starts a
             * wall running straight away from that side. */
            v3m = c_random_below(38) + 1;
            v4n = c_random_below(30) + 1;
            v7a = -1;
            if (asm_wall_map[(v3m << 5) + v4n] == 1)
                v7a = 2;
            if (asm_wall_map[(v3m << 5) + v4n] == 2)
                v7a = 3;
            if (asm_wall_map[(v3m << 5) + v4n] == 4)
                v7a = 0;
            if (asm_wall_map[(v3m << 5) + v4n] == 8)
                v7a = 1;
            /* Refuse it if a wall along the same line lies within four cells to either side. */
            v6 = 1;
            for (v5o = -4; v5o <= 4; v5o++) {
                if ((((v7a & 1) != 0 ? 5 : 0xa)
                     & asm_wall_map[((dat_side_dx[v7a + 1] * v5o + v3m) << 5)
                         + dat_side_dy[v7a + 1] * v5o + v4n]) != 0)
                    v6 = 0;
            }
        } while ((v7a == -1 || v6 == 0) && ++v0j < 999);
        /* No room for another wall: stop laying them. */
        if (v0j >= 999)
            return;
        /* Lay the wall cell by cell until it meets another wall or leaves the floor. */
        v1k = -1;
        do {
            if (asm_wall_map[(v3m << 5) + v4n] != 0)
                v1k++;
            c_set_wall(v3m, v4n, (v7a + 1) & 3);
            v3m += dat_side_dx[v7a];
            v4n += dat_side_dy[v7a];
        } while (v1k == 0 && v3m >= 0 && v4n >= 0 && v3m < 40
                 && v4n < 40);
    }
}
