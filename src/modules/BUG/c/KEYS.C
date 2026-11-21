/* KEYS.C -- one pass of the board's input loop.
 */
#include "BUG.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "PRIMS.H"
#include "MENU.H"
#include "MAIN.H"
#include "BOARD.H"

/* Read one key or joystick move and act on it: the eight directions move the
 * cursor, Enter or space swaps the held chip with the one under it, Escape
 * ends the round, and Alt-Q, S and P quit, toggle the sound and pause.
 *
 * The eight directions share `move` by goto, as shipped.
 */
void c_read_keys(void)
{
    INT live;   /* whether the joystick moved this frame */
    INT colc;   /* the cursor's column while the swap is done */
    INT slot;   /* and its row */
    UNSIGNED_INT taken;  /* the chip that was in hand before the swap */
    INT last;   /* the key or scan code being acted on */
    INT dcolc;  /* how far the cursor moves across the board */
    INT drowj;  /* and down it */

    c_tick(1);
    last = -1;
    live = 0;
    if (shm_options & OPT_JOYSTICK) {
        last = c_joystick_read(&colc, &slot);
        if (c_joystick_button(0) != 0) {
            last = 0xd;
            c_wait_for_release();
        }
        if (last != -1)
            live = 1;
    }
    if (drv_jump_keyboard_empty() == 0 || last != -1) {
        if (last == -1)
            last = c_menu_key();
        switch (last) {
        case KEY_ESC:
            asm_score = asm_wires_live;
            shm_finished = 1;
            break;

        case KEY_ENTER:
        case KEY_SPACE:
            colc = asm_cursor_col;
            slot = asm_cursor_row;
            if (asm_deal_chip[asm_cursor_col][asm_cursor_row] & CHIP_LOCKED)
                break;
            if ((asm_deal_chip[colc][slot] & CHIP_SHOWN) == 0) {
                c_draw_chip_box(asm_deal_chip[colc][slot],
                                   (colc << 5) + 0x28, (slot << 5) + 8,
                                   LONG_LIT(1));
                c_tick(0xa);
            }
            taken = asm_held_chip;
            asm_held_chip = asm_deal_chip[colc][slot] & CHIP_KIND;
            asm_deal_chip[colc][slot] = taken + CHIP_SHOWN;
            c_draw_chip_box((INT) taken + CHIP_SHOWN, (colc << 5) + 0x28,
                               (slot << 5) + 8, LONG_LIT(1));
            c_sound_command(0x1c);
            c_board_step(LONG_LIT(1));
            break;

        case 1:
        case KEY_UP:
            dcolc = 0;
            drowj = -1;
            goto move;

        case 2:
        case KEY_PGUP:
            dcolc = 1;
            drowj = -1;
            goto move;

        case 3:
        case KEY_RIGHT:
            dcolc = 1;
            drowj = 0;
            goto move;

        case 4:
        case KEY_PGDN:
            dcolc = 1;
            drowj = 1;
            goto move;

        case 5:
        case KEY_DOWN:
            dcolc = 0;
            drowj = 1;
            goto move;

        case 6:
        case KEY_END:
            dcolc = -1;
            drowj = 1;
            goto move;

        case 7:
        case KEY_LEFT:
            dcolc = -1;
            drowj = 0;
            goto move;

        case 8:
        case KEY_HOME:
            dcolc = -1;
            drowj = -1;
            goto move;

        case KEY_ALT_Q:
            drv_jump_gfx_copy_rect(shd_screen, 0, 0, 0x140, 0xc8, shd_map_page, 0, 0);
            shd_screen->bg_pen = 0xf;
            if (c_menu_run(dat_str_sure_want_quit_no, 0x50, 0x51) == 1) {
                c_hook_hand_back(UNSET_ARGS(0));
                COMM()->next_module = NONE_EXIT;
                exit(UNSET_ARGS(0));
            }
            drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 0x140, 0xc8, shd_screen, 0, 0);
            break;

        case KEY_ALT_S:
            if (shm_options & OPT_SOUND)
                c_sound_command(0);
            shm_options ^= OPT_SOUND;
            break;

        case KEY_ALT_P:
            drv_jump_gfx_copy_rect(shd_screen, 0, 0, 0x140, 0xc8, shd_map_page, 0, 0);
            drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xc8, 0);
            shm_menu_draw_only = 1;
            c_menu_run(dat_str_paused, 0x80, 0x51);
            c_menu_key();
            drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 0x140, 0xc8, shd_screen, 0, 0);
            break;

        move:
            if (asm_deal_chip[asm_cursor_col][asm_cursor_row] & CHIP_SHOWN)
                c_draw_chip_box(asm_deal_chip[asm_cursor_col][asm_cursor_row],
                                   (asm_cursor_col << 5) + 0x28,
                                   (asm_cursor_row << 5) + 8, LONG_LIT(0));
            else
                c_draw_chip_box(-1, (asm_cursor_col << 5) + 0x28,
                                   (asm_cursor_row << 5) + 8, LONG_LIT(0));
            asm_cursor_col =
                c_clamp(dcolc + asm_cursor_col, 0, 5);
            asm_cursor_row =
                c_clamp(drowj + asm_cursor_row, 0, 4);
            if (asm_deal_chip[asm_cursor_col][asm_cursor_row] & CHIP_SHOWN)
                c_draw_chip_box(asm_deal_chip[asm_cursor_col][asm_cursor_row],
                                   (asm_cursor_col << 5) + 0x28,
                                   (asm_cursor_row << 5) + 8, LONG_LIT(1));
            else
                c_draw_chip_box(-1, (asm_cursor_col << 5) + 0x28,
                                   (asm_cursor_row << 5) + 8, LONG_LIT(1));
            break;

        }
    }
    c_wait_retraces(live != 0 ? 0x14 : 5);
}
