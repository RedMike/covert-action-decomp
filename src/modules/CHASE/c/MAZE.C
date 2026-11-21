/* MAZE.C -- laying out the board.
 */
#include "CHASE.H"
#include "RANDOM.H"
#include "MAZE.H"
#include "TEXTOUT.H"
#include "BOARDMAR.H"
#include "LINE.H"
#include "STREET.H"
#include "BOXFILL.H"
#include "RESULT.H"

/* Lay out the board: a 24-by-24 grid of blocks, 192 passes closing streets to
 * merge them, then sixteen destinations kept apart. With asm_fresh_board set,
 * the generator is first seeded from the city.
 *
 * The locals' names fix their frame slots.
 */
INT c_make_maze(void)
{
    INT v0j;                            /* how far it is from an earlier one */
    INT v1j;                            /* the destination's x */
    INT v2j;                            /* the cell's row, or a line's x */
    INT v3k;                            /* the destination's y */
    INT v4k;                            /* the pass, then the destination */
    INT v5l;                            /* the cell's column, or a line's y */
    INT v6l;                            /* set while the spot is far enough */
    INT v7m;                            /* an earlier destination */
    INT v8m;                            /* never read */
    INT v9n;                            /* the colour the blocks are drawn in */
    INT v10g;                           /* the side whose street is closed */

    /* A city's streets come out the same every time a chase is held there. */
    if (asm_fresh_board != 0)
        srand((unsigned) shm_case_city * 123 + (asm_DAT_1663_5c00 & 0x3fff));
    /* The blocks are drawn darker at night and on CGA. */
    v9n = asm_night != 0 || shm_cga != 0 ? 8 : 7;
    /* Frame the map, and put up the backdrop of the view from the car beside it. */
    c_fill_box(0, 0, 199, 199, 1);
    c_fill_box(1, 1, 198, 198, v9n);
    c_fill_box(200, 0, 319, 99, 1);
    drv_jump_gfx_copy_rect(dat_tile_page, 200, 101, 120, 100, shd_screen, 200, 0);
    c_draw_line(200, 0, 319, 0, 15);
    /* Every block starts with a street on all four sides and a random tile. */
    for (v2j = 0; v2j < 24; v2j++)
        for (v5l = 0; v5l < 24; v5l++)
            asm_cell_map[v2j * 24 + v5l] =
                c_random_below(16) * 0x10 + 0xf;
    /* Draw the streets between the blocks, down... */
    v2j = 8;
    do {
        c_draw_line(v2j, 1, v2j, 198, 5);
        c_draw_line(v2j + 1, 1, v2j + 1, 198, 5);
        v2j += 8;
    } while (v2j < 200);
    /* ...and across. */
    v5l = 8;
    do {
        c_draw_line(1, v5l, 198, v5l, 5);
        c_draw_line(1, v5l + 1, 198, v5l + 1, 5);
        v5l += 8;
    } while (v5l < 200);
    /* Merge blocks at random, closing the street between them, away from the edge. */
    for (v4k = 0; v4k < 192; v4k++) {
        v2j = c_random_below(21) + 2;
        v5l = c_random_below(21) + 2;
        v10g = v4k & 3;
        /* Every other pair of passes merges only two blocks that are both still whole. */
        if ((v4k & 2) != 0) {
            if ((asm_cell_map[v2j * 24 + v5l]
                 & 0xf) != 0xf)
                continue;
            if ((asm_cell_map[(v2j + dat_side_dx[v10g]) * 24
                              + v5l + dat_side_dy[v10g]] & 0xf) != 0xf)
                continue;
        }
        /* Close the street on this block's side, and give it a merged block's tile... */
        asm_cell_map[v2j * 24 + v5l] &= 0xff - (1 << v10g);
        asm_cell_map[v2j * 24 + v5l] =
            (((char) v2j + (char) v5l) & 1) * 0x10
            + (asm_cell_map[v2j * 24 + v5l] & 0xf) + 0x80;
        /* ...and on its neighbour's, which faces it. */
        asm_cell_map[(v2j + dat_side_dx[v10g]) * 24 + v5l + dat_side_dy[v10g]]
            &= 0xff - (1 << ((v4k + 2) & 3));
        /* Paint the street over in the blocks' colour, both lines of it. */
        c_draw_line(dat_street_x[v10g].from + v2j * 8,
                    dat_street_y[v10g].from + v5l * 8,
                    dat_street_x[v10g].to + v2j * 8,
                    dat_street_y[v10g].to + v5l * 8,
                    v9n);
        c_draw_line(dat_street_x[v10g].from + (v10g & 1)
                        + v2j * 8,
                    dat_street_y[v10g].from + v5l * 8
                        - (v10g & 1) + 1,
                    dat_street_x[v10g].to + (v10g & 1)
                        + v2j * 8,
                    dat_street_y[v10g].to + v5l * 8
                        - (v10g & 1) + 1, v9n);
    }
    /* Place the sixteen destinations, one for each organisation. */
    for (v4k = 0; v4k < 16; v4k++) {
        do {
            /* On a street; on the easier levels, only in the middle of the city. */
            do {
                if (shm_difficulty < 2) {
                    v1j = c_random_below(12) * 32 + 192;
                    v3k = c_random_below(12) * 32 + 208;
                } else {
                    v1j = c_random_below(18) * 32 + 96;
                    v3k = c_random_below(18) * 32 + 112;
                }
            } while (c_is_open(v1j / 32, v3k / 32, 2) == 0);
            /* Keep them apart, the further the harder the chase. */
            v6l = 1;
            for (v7m = 1; v7m < v4k; v7m++) {
                v0j = abs(v1j - asm_spot_x[v7m])
                      + abs(v3k - asm_spot_y[v7m]);
                if (v0j < shm_difficulty * 32 + 64) {
                    v6l = 0;
                    break;
                }
            }
        } while (v6l == 0);
        asm_spot_x[v4k] = v1j;
        asm_spot_y[v4k] = v3k;
        /* Show the player the ones they know of, named where the city is real. */
        if (v4k != 0
            && (asm_fresh_board == 0
                || shm_cities[shm_case_city].known_orgs & 1 << v4k)) {
            c_board_mark(((v4k & 1) != 0 ? 8 : -8) + v1j, v3k, 15);
            if (asm_fresh_board == 0) {
                strcpy(shm_scratch, dat_str_loc);
                strcat(shm_scratch, itoa(v4k, asm_number_digits_2, 10));
            } else
                strcpy(shm_scratch, shm_orgs[v4k].short_name);
            shd_screen->draw_mode = 0;
            c_write_text(shm_scratch, (v1j << 3) / 32 + 4,
                            (v3k << 3) / 32 - 3,
                            shm_cga != 0 ? 15
                            : asm_night != 0 ? 7 : 9);
            shd_screen->draw_mode = 1;
        }
    }
    /* The suspect drives from one destination to another... */
    asm_start_spot = c_random_below(15) + 1;
    do {
        asm_goal_spot = c_random_below(15) + 1;
    } while (asm_start_spot == asm_goal_spot);
    /* ...which in a real city is from their organisation to the one the case is after. */
    if (asm_fresh_board != 0) {
        asm_start_spot = (char) COMM()->result[RES_CHASE_ORG];
        /* A practice chase starts anywhere else. */
        if (shm_options & OPT_PRACTICE)
            do {
                asm_start_spot = c_random_below(16);
            } while (asm_start_spot == shm_case_org);
        asm_goal_spot = shm_case_org;
    }
}
