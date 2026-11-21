/* MESSAGE.C -- printing a message on paper: the sheet, the printer, the text.
 */
#include "GAME.H"
#include "SPRITES.H"
#include "CMP_STRT.H"
#include "MISC1.H"
#include "CASE.H"
#include "LINES.H"
#include "PANEL.H"
#include "NOTICE.H"
#include "MESSAGE.H"

/* shared_include_start: ../../../../shared/c/DRAW-PAPER.C -- generated */
/* DRAW-PAPER.C -- c_draw_paper, a blank sheet of printer paper.
 */

/* Draw a blank sheet of continuous-feed paper: a white page, two tractor rails
 * with sprocket holes, and ruled bands.
 */
INT c_draw_paper(void)
{
    INT high;
    INT rule;

    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 200, 0xf);
    c_draw_line(8, 0, 8, 199, 7);
    c_draw_line(0x137, 0, 0x137, 199, 7);
    high = 4;
    do {
        drv_real_fill_rect(shd_screen, 2, high, 4, 4, 8);
        drv_real_fill_rect(shd_screen, 0x13a, high, 4, 4, 8);
        high += 0xc;
    } while (high < 199);
    for (high = 0x20; high < 199; high += 0x40) {
        c_draw_line(0x17, high + 1, 0x17, high + 0x1d, 0xb);
        c_draw_line(0x128, high + 1, 0x128, high + 0x1d, 0xb);
        for (rule = 0; rule < 0x20; rule += 2)
            c_draw_line(0x18, high + rule, 0x127, high + rule, 0xb);
    }
}
/* shared_include_end: ../../../../shared/c/DRAW-PAPER.C */

/* shared_include_start: ../../../../shared/c/PRINT-MESSAGE.C -- generated */
/* PRINT-MESSAGE.C -- c_print_message, a message coming off the printer.
 */

/* Show the message titled `title` coming off the printer a line at a time,
 * until it is all out or a key is pressed, then put the caller's screen back.
 */
INT c_print_message(rt_addr title)
{
    INT cell;    /* the print head's column */
    INT edge;    /* the y the laid-out message reached */
    INT spent;   /* how many eight-pixel rows have gone through the slot */

    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 0x140, 200, shd_map_page, 0, 0);
    drv_jump_gfx_set_colour_map(&shd_colours_paper, &shd_colours_paper);
    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 100, 5);
    c_draw_display_list((char *) shd_list_printout);
    drv_real_fill_rect(shd_screen, 0x32, 0x96, 0xdc, 0xd, 0xf);
    c_draw_centred((str_addr) title, 0xa0, 0x98, 0xc);
    c_draw_centred(shd_str_incoming_msg, 0x40, 0xba, 10);
    c_draw_line(0x31, 0x96, 0x31, 0xa2, 8);
    c_draw_line(0x10e, 0x96, 0x10e, 0xa2, 8);
    drv_jump_gfx_copy_rect(shd_screen, 0, 100, 0x140, 100, shd_picture_page, 0, 100);
    shd_screen->page = 2;
    drv_real_fill_rect(shd_screen, 0x32, 0x44, 0xdc, 0x5f, 0xf);
    shd_screen->bg_pen = 0xf;
    edge = c_draw_message(0x19, 0x3a, 0x4c, 5);
    shd_screen->page = 0;
    c_wait_for_release();
    for (spent = 0; spent < (edge - 0x4c) / 8; spent++) {
        drv_jump_gfx_copy_rect(shd_screen, 0x31, 0x96 - spent * 8, 0xde, spent * 8 + 0xd, shd_screen, 0x31, 0x8e - spent * 8);
        drv_real_fill_rect(shd_screen, 0x32, 0x9b, 0xdc, 8, 0xf);
        c_sound_command(0x1f);
        for (cell = 0x34; cell < 0xf0; cell++) {
            drv_jump_gfx_copy_rect(shd_picture_page, cell - 2, spent * 8 + 0x4a, 2, 10, shd_screen, cell - 2, 0x99);
            c_draw_line(cell - 1, 0xa3, cell - 1, 0xa6, 7);
            c_draw_sprite(SPRITE_TYPEWRITER, cell, 0x9a);
            c_wait_retraces((cell & 7) != 0 ? 1 : 3);
            if (drv_jump_keyboard_empty() == 0)
                break;
        }
        c_sound_command(0x20);
        c_wait_retraces(0xf);
        drv_jump_gfx_copy_rect(shd_picture_page, cell - 2, spent * 8 + 0x4a, 0x20, 10, shd_screen, cell - 2, 0x99);
        drv_real_fill_rect(shd_screen, cell - 1, 0xa3, 0x20, 4, 7);
        if (drv_jump_keyboard_empty() == 0)
            break;
    }
    drv_jump_gfx_copy_rect(shd_screen, 0x31, 0x96 - spent * 8, 0xde, spent * 8 + 0xd, shd_screen, 0x31, 0x8e - spent * 8);
    drv_real_fill_rect(shd_screen, 0x32, 0x9b, 0xdc, 8, 0xf);
    drv_jump_gfx_copy_rect(shd_screen, 0x31, 0x8e - spent * 8, 0xde, spent * 8 + 0x15, shd_screen, 0x31, 0x88 - spent * 8);
    drv_real_fill_rect(shd_screen, 0x32, 0x9b, 0xdc, 8, 0xf);
    c_draw_sprite(SPRITE_TYPEWRITER, 0x34, 0x9a);
    c_wait_key();
    drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 0x140, 200, shd_screen, 0, 0);
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
}
/* shared_include_end: ../../../../shared/c/PRINT-MESSAGE.C */

/* shared_include_start: ../../../../shared/c/LIST-DRAW.C -- generated */
/* LIST-DRAW.C -- c_draw_display_list, drawing a list of lines and boxes.
 */

/* Draw the display list at `list`: 12-byte records ending at kind -1. Kind 0
 * is a line, 1 a filled box, 3 an outlined one, and 2 repeats the records
 * before it, shifted each time.
 */
INT c_draw_display_list(char *list)
{
    INT again;
    INT pos;
    INT v2l;   /* the running x offset the repeat accumulates */
    INT v3m;   /* and the y one */

    pos = v2l = v3m = 0;
    do {
        switch (*(INT *) (list + pos * 0xc)) {
        case 0:
            c_draw_line(*(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            break;
        case 1:
            c_fill_box(*(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            break;
        case 2:
            if (*(INT *) (list + pos * 0xc + 0xa) == 0) {
                v2l = v3m = 0;
                again = *(INT *) (list + pos * 0xc + 6);
                *(INT *) (list + pos * 0xc + 0xa) = 1;
            }
            again--;
            if (again != 0) {
                v2l += *(INT *) (list + pos * 0xc + 2);
                v3m += *(INT *) (list + pos * 0xc + 4);
                pos -= *(INT *) (list + pos * 0xc + 8) + 1;
            } else {
                *(INT *) (list + pos * 0xc + 0xa) = 0;
                v2l = v3m = 0;
            }
            break;
        case 3:
            c_draw_line(*(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            c_draw_line(*(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            c_draw_line(*(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            c_draw_line(*(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
        break;
        case -1:
        pos = -1;
        break;
        }
        pos++;
    } while (pos != 0);
}
/* shared_include_end: ../../../../shared/c/LIST-DRAW.C */
