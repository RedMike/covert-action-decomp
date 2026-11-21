/* BOARD-LAYOUT.C -- reading the board picture and laying the puzzle out on it.
 */
#include "BUG.H"
#include "PRIMS.H"
#include "BOARD.H"

#ifndef PORT_MODERN
/* A second link name for shm_difficulty, which only the DOS build needs. */
extern UNSIGNED_INT shm_difficulty_word;
#endif

/* Turn the board picture on screen into the wire grid, then deal the puzzle
 * onto it to suit the difficulty and draw what was dealt.
 */
void c_deal_board(void)
{
    INT num;    /* how many chip pairs have been joined */
    INT way;    /* which of the eight neighbours is being sampled */
    INT bits;   /* the eight samples, packed */
    INT cole;   /* column of the cell being worked on */
    INT rowl;   /* row of it */
    INT idx;    /* outer loop index */
    INT tally;  /* running total of the last column of asm_deal_lines */
    INT odd;    /* whether the previous chip opened a pair */
    INT round;  /* the value just dealt, and the count of forced cells */
    INT i;      /* inner loop index */
    INT pins;   /* cells with both halves of a pair set */

    /* A load and store back, read through the second name so CL keeps the
     * store. */
#ifdef PORT_MODERN
    shm_difficulty = shm_difficulty;
#else
    shm_difficulty = shm_difficulty_word;
#endif
    asm_DAT_1a63_8274 =
        c_clamp((shm_difficulty << 1) + 6, 0, CHIP_MAX);

    /* Read the drawn board into the wire grid, one 8-pixel cell at a time. */
    for (idx = 0; idx < WIRE_GRID_COLS; idx++) {
        for (i = 0; i < WIRE_GRID_ROWS; i++) {
            cole = (idx << 3) + 4;
            rowl = (i << 3) + 4;
            bits = 0;
            /* A neighbour drawn in the wire colour means a wire runs that way. */
            for (way = 0; way < 8; way++) {
                if ((shm_cga != 0 ? 3 : 10)
                        == drv_jump_gfx_get_pixel(0,
                               dat_neighbour_col[way] * 2 + cole,
                               dat_neighbour_row[way] * 2 + rowl))
                    bits += 1 << way;
            }
            asm_wire_grid[idx][i] = bits;
        }
    }

    /* Wire the slots until the number of joined pairs suits the difficulty. */
    do {
        num = 0;
        for (idx = 0; idx < CHIP_COLS - 1; idx++) {
            odd = 0;
            for (i = 0; i < CHIP_ROWS; i++) {
                cole = (idx << 2) + 7;
                rowl = (i << 2) + 1;
                /* Two times in three the slot passes its lines straight through. */
                switch (c_random_below(3)) {
                case 0:
                case 1:
                    asm_wire_grid[cole][rowl] = WIRE_E | WIRE_W;
                    asm_wire_grid[cole + 1][rowl] = WIRE_E | WIRE_W;
                    asm_wire_grid[cole][rowl + 1] = WIRE_E | WIRE_W;
                    asm_wire_grid[cole + 1][rowl + 1] = WIRE_E | WIRE_W;
                    asm_deal_pins[idx][i * 2] = i * 2;
                    asm_deal_pins[idx][i * 2 + 1] = i * 2 + 1;
                    /* Following another such slot, the two join as a pair and
                     * trade their adjoining lines. */
                    if (odd) {
                        num++;
                        asm_wire_grid[cole][rowl] = WIRE_N | WIRE_W;
                        asm_wire_grid[cole + 1][rowl] = WIRE_N | WIRE_E;
                        asm_wire_grid[cole][rowl - 1] = WIRE_NE | WIRE_S;
                        asm_wire_grid[cole + 1][rowl - 1] = WIRE_S | WIRE_NW;
                        asm_wire_grid[cole][rowl - 2] = WIRE_N | WIRE_SE;
                        asm_wire_grid[cole + 1][rowl - 2] = WIRE_N | WIRE_SW;
                        asm_wire_grid[cole][rowl - 3] = WIRE_S | WIRE_W;
                        asm_wire_grid[cole + 1][rowl - 3] = WIRE_E | WIRE_S;
                        asm_deal_pins[idx][i * 2] = i * 2 - 1;
                        asm_deal_pins[idx][i * 2 - 1] = i * 2;
                    }
                    odd = 1;
                    break;
                /* Otherwise the slot crosses its own two lines over. */
                case 2:
                    asm_wire_grid[cole][rowl] = WIRE_SE | WIRE_W;
                    asm_wire_grid[cole + 1][rowl] = WIRE_E | WIRE_SW;
                    asm_wire_grid[cole][rowl + 1] = WIRE_NE | WIRE_W;
                    asm_wire_grid[cole + 1][rowl + 1] = WIRE_E | WIRE_NW;
                    asm_deal_pins[idx][i * 2] = i * 2 + 1;
                    asm_deal_pins[idx][i * 2 + 1] = i * 2;
                    odd = 0;
                    break;
                }
            }
        }
    } while (num < (shm_difficulty << 2)
             || num > (shm_difficulty << 2) + 4);

    /* Clear every line, and feed the fixed 1, 0, 0, 1 pattern in at the left. */
    for (idx = 0; idx < LINE_ROWS; idx++) {
        i = 0;
        do {
            asm_deal_lines[i][idx] = -1;
            i++;
        } while (i < LINE_COLS);
        asm_deal_lines[0][idx] =
            (idx & 3) == 0 || (idx & 3) == 3;
    }

    /* Branch the last line of every gap but the first downward as well. */
    for (idx = 1; idx < CHIP_COLS - 1; idx++) {
        cole = (idx << 2) + 7;
        rowl = 17;
        asm_wire_grid[cole][rowl + 1] |= WIRE_S;
        asm_wire_grid[cole + 1][rowl + 1] |= WIRE_S;
    }

    /* Deal chips until the settled outputs come out as the difficulty asks. */
    do {
        /* Values rise with the difficulty; the last column's are at least 4. */
        for (idx = 0; idx < CHIP_COLS; idx++) {
            for (i = 0; i < CHIP_ROWS; i++) {
                do {
                    round = asm_deal_chip[idx][i] =
                        c_clamp(
                            c_random_below(shm_difficulty + 6)
                                + shm_difficulty, 0, CHIP_MAX);
                } while (idx == CHIP_COLS - 1 && round < 4);
            }
        }
        /* Settle the board, then total its outputs and count the lit pairs. */
        c_board_step(LONG_LIT(0));
        tally = 0;
        pins = 0;
        idx = 0;
        do {
            tally += asm_deal_lines[LINE_COLS - 1][idx];
            asm_column_done[idx] =
                asm_deal_lines[LINE_COLS - 1][idx] == 0;
            if (asm_deal_lines[LINE_COLS - 1][idx & 0xe] != 0
                && asm_deal_lines[LINE_COLS - 1][(idx & 0xe) + 1] != 0)
                pins++;
            idx++;
        } while (idx < LINE_ROWS);
    } while (-(shm_difficulty / 2 - 6) != tally
             || (pins != 0
                 && pins / 2 > 4 - shm_difficulty));

    /* Reveal chips at random, fewer the harder the game, and all the last column. */
    for (idx = 0; idx < CHIP_COLS; idx++) {
        for (i = 0; i < CHIP_ROWS; i++) {
            if (c_random_below(3) + 1 >= shm_difficulty
                || idx == CHIP_COLS - 1)
                asm_deal_chip[idx][i] |= CHIP_SHOWN;
        }
    }

    /* Lock twice the difficulty in high chips, face up and off the sixth
     * column. */
    round = 0;
    while (round < (shm_difficulty << 1)) {
        cole = c_random_below(CHIP_COLS - 1);
        rowl = c_random_below(CHIP_ROWS);
        if (asm_deal_chip[cole][rowl] > 3
            && (asm_deal_chip[cole][rowl] & CHIP_LOCKED) == 0
            && (cole != CHIP_COLS - 2 || shm_difficulty == 4)) {
            asm_deal_chip[cole][rowl] |= CHIP_LOCKED;
            if (shm_difficulty != 4)
                asm_deal_chip[cole][rowl] |= CHIP_SHOWN;
            round++;
        }
    }

    /* Draw the locked slots' covering and every revealed chip. */
    for (idx = 0; idx < CHIP_COLS; idx++) {
        for (i = 0; i < CHIP_ROWS; i++) {
            if (asm_deal_chip[idx][i] & CHIP_LOCKED) {
                drv_jump_gfx_fill(shd_screen, (idx << 5) + 39,
                                  (i << 5) + 5, 18, 23, 2, 8);
                drv_jump_gfx_fill(shd_screen, (idx << 5) + 39,
                                  (i << 5) + 5, 18, 23, 3, 8);
                c_draw_line((idx << 5) + 40, (i << 5) + 5,
                                   (idx << 5) + 40, (i << 5) + 24, 8);
                c_draw_line((idx << 5) + 55, (i << 5) + 5,
                                   (idx << 5) + 55, (i << 5) + 24, 8);
            }
            if (asm_deal_chip[idx][i] & CHIP_SHOWN)
                c_draw_chip_box(asm_deal_chip[idx][i],
                                   (idx << 5) + 40, (i << 5) + 8,
                                   LONG_LIT(0));
        }
    }

    /* Hand the player a first chip from the same range as the dealt ones. */
    asm_held_chip =
        c_clamp(c_random_below(shm_difficulty + 6)
                               + shm_difficulty, 0, CHIP_MAX);
    /* Clear the lines again and settle the board, drawing it this time. */
    for (idx = 0; idx < LINE_ROWS; idx++) {
        i = 0;
        do {
            asm_deal_lines[i][idx] = -1;
            i++;
        } while (i < LINE_COLS);
        asm_deal_lines[0][idx] =
            (idx & 3) == 0 || (idx & 3) == 3;
    }
    c_board_step(LONG_LIT(1));
    /* Start the cursor on the middle slot, showing its chip if revealed. */
    asm_cursor_col = 3;
    asm_cursor_row = 2;
    if (asm_deal_chip[3][2] & CHIP_SHOWN)
        c_draw_chip_box(asm_deal_chip[3][2],
                           136, 72, LONG_LIT(1));
    else
        c_draw_chip_box(-1, (asm_cursor_col << 5) + 40,
                           (asm_cursor_row << 5) + 8, LONG_LIT(1));
}
