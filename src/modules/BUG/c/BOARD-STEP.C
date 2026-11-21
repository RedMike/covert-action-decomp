/* BOARD-STEP.C -- one step of the board: outputs, lamps, and the round's end.
 */
#include "BUG.H"
#include "MENU.H"
#include "MAIN.H"
#include "BOARD.H"

/* Work out every chip's two outputs and pass them to the next column, light
 * the ten lamps, and end the round on an alarm, on enough taps or when time
 * runs out. `redraw` off is the deal's settling pass; on, the pass the player
 * sees.
 */
void c_board_step(LONG redraw)
{
    INT unit;   /* never read */
    INT leftf;  /* x of the lamp being drawn */
    INT lcolx;  /* column of asm_deal_lines this chip reads */
    INT lrow;   /* row of it */
    INT top;    /* y of the lamp */
    INT idx;    /* outer loop index */
    INT oldw;   /* the line's value before this step, to see whether it changed */
    INT part;   /* inner loop index */

    /* Redraw the chip in hand, and before the clock starts send the signal up
     * from its source. */
    drv_real_fill_rect(shd_screen, 154, 177, 12, 16, 8);
    c_draw_bug_sprite((asm_held_chip & CHIP_KIND) + BUG_SPRITE_CHIPS, 152, 177);
    if ((INT)redraw != 0 && asm_frame_count == 0)
        c_trace_wire(7, 20, WAY_N, 1);

    /* Pass the signal through the chips a column at a time, left to right. */
    for (idx = 0; idx < CHIP_COLS; idx++) {
        for (part = 0; part < CHIP_ROWS; part++) {
            lcolx = idx << 1;
            lrow = part << 1;
            /* The chip's first output, from its kind and its two inputs; on
             * screen a change runs along its wire, and it feeds the next column. */
            oldw = asm_deal_lines[lcolx + 1][lrow];
            asm_deal_lines[lcolx + 1][lrow] =
                dat_chip_outputs[asm_deal_chip[idx][part] & CHIP_KIND]
                    [asm_deal_lines[lcolx][lrow + 1] * 2
                     + asm_deal_lines[lcolx][lrow]][0];
            if ((INT)redraw != 0
                && asm_deal_lines[lcolx + 1][lrow] != oldw)
                c_trace_wire((idx << 2) + 7, (part << 2) + 1, WAY_E,
                                asm_deal_lines[lcolx + 1][lrow]);
            if (idx < CHIP_COLS - 1)
                asm_deal_lines[lcolx + 2][asm_deal_pins[idx][lrow]] =
                    asm_deal_lines[lcolx + 1][lrow];

            /* And the same for its second. */
            oldw = asm_deal_lines[lcolx + 1][lrow + 1];
            asm_deal_lines[lcolx + 1][lrow + 1] =
                dat_chip_outputs[asm_deal_chip[idx][part] & CHIP_KIND]
                    [asm_deal_lines[lcolx][lrow + 1] * 2
                     + asm_deal_lines[lcolx][lrow]][1];
            if ((INT)redraw != 0
                && asm_deal_lines[lcolx + 1][lrow + 1] != oldw)
                c_trace_wire((idx << 2) + 7, (part << 2) + 2, WAY_E,
                                asm_deal_lines[lcolx + 1][lrow + 1]);
            if (idx < CHIP_COLS - 1)
                asm_deal_lines[lcolx + 2][asm_deal_pins[idx][lrow + 1]] =
                    asm_deal_lines[lcolx + 1][lrow + 1];
        }
    }

    /* On screen, light a lamp for each output line and count the goals. */
    if ((INT)redraw != 0) {
        asm_wires_live = 0;
        for (idx = 0; idx < LINE_ROWS; idx++) {
            leftf = ((idx & 1) != 0 ? 24 : 0) + 264;
            top = idx << 4;
            oldw = asm_deal_lines[LINE_COLS - 1][idx];
            /* An alarm line trips once it leaves 0. */
            if (asm_column_done[idx] != 0) {
                drv_jump_gfx_copy_rect(dat_chip_page, oldw != 0 ? 18 : 2, 32, 12, 16, shd_screen, leftf + 2, top);
                if (oldw != 0)
                    asm_alarms++;
            } else {
                /* Any other line is a goal once it reaches 0; a new best
                 * sounds, and on a phone tap reports what the tap turned up. */
                if (asm_wires_live == asm_max_goals_reached && oldw == 0)
                    c_sound_command(29);
                if (asm_board_stage == BOARD_STAGE_PHONES) {
                    drv_jump_gfx_copy_rect(dat_chip_page, oldw != 0 ? 34 : 50, 32, 12, 16, shd_screen, leftf + 2, top);
                    if (oldw == 0) {
                        asm_wires_live++;
                        if (asm_wires_live
                                > asm_max_goals_reached) {
                        asm_max_goals_reached = asm_wires_live;
                        if ((shm_options & OPT_PRACTICE) == 0)
                            c_scan_for_tap(8);
                        }
                    }
                }
                /* On a car tracer a new best builds its progress line, which
                 * nothing then shows. */
                if (asm_board_stage == BOARD_STAGE_TRACER) {
                    drv_jump_gfx_copy_rect(dat_chip_page, oldw != 0 ? 66 : 82, 32, 12, 16, shd_screen, leftf + 2, top);
                    if (oldw == 0) {
                        asm_wires_live++;
                        if (asm_wires_live
                                > asm_max_goals_reached) {
                        asm_max_goals_reached = asm_wires_live;
                        drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
                        strcpy(shm_scratch, dat_str_car_tracer);
                        strcat(shm_scratch,
                                   itoa(asm_wires_live * 20,
                                            asm_number_digits, 10));
                        strcat(shm_scratch, dat_str_complete);
                        drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen, 0, 0);
                        }
                    }
                }
            }
        }
    }

    /* A tripped alarm ends the round with nothing scored. */
    shd_screen->bg_pen = 1;
    if (asm_alarms != 0) {
        c_set_palette_record(0);
        c_sound_command(30);
        strcpy(shm_scratch, dat_str_alarm);
        c_menu_run(shm_scratch, 100, 81);
        asm_score = 0;
        shm_finished = 1;
    }
    /* Enough goals, fewer the harder a tap and five for a tracer, or the clock
     * running out, ends it with the goals reached as the score. */
    if ((asm_board_stage == BOARD_STAGE_PHONES
             ? -(shm_difficulty / 2 - 6) : 5)
                <= asm_wires_live
        || asm_seconds_left == 0) {
        /* Finished in time: a completed tap reports what it found. */
        if (asm_seconds_left != 0) {
            if (asm_board_stage == BOARD_STAGE_PHONES) {
                if ((shm_options & OPT_PRACTICE) == 0)
                    c_scan_for_tap(asm_case_difficulty << 4);
                strcpy(shm_scratch, dat_str_phone_taps_completed);
            } else {
                strcpy(shm_scratch, dat_str_car_tracer_installed);
            }
            c_sound_command(46);
        } else {
            strcpy(shm_scratch, dat_str_time_expired);
            if (asm_board_stage == BOARD_STAGE_PHONES) {
                strcat(shm_scratch,
                           itoa(asm_wires_live, asm_number_digits, 10));
                strcat(shm_scratch, dat_str_phones_tapped);
            }
        }
        /* Either way, say how many alarms went off. */
        if (asm_alarms != 0)
            strcat(shm_scratch, itoa(asm_alarms, asm_number_digits, 10));
        else
            strcat(shm_scratch, dat_str_no);
        strcat(shm_scratch, dat_str_alarms);
        shd_screen->bg_pen = 15;
        c_menu_run(shm_scratch, 100, 81);
        asm_score = asm_wires_live;
        shm_finished = 1;
    }
}
