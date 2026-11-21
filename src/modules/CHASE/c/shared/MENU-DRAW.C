/* MENU-DRAW.C -- laying the menu box out and drawing its lines.
 */
#include "CHASE.H"
#include "SETUP.H"
#include "RANDOM.H"
#include "TEXTOUT.H"
#include "PANEL.H"
#include "BOXES.H"
#include "MENU1.H"

/* shared_include_start: ../../../../shared/c/MENU-DRAW.C -- generated */
/* MENU-DRAW.C -- c_menu_draw, drawing a menu's box and lines.
 */

/* Draw the menu `title` at (`x`, `y`) with item `sel` highlighted, answering
 * `sel`. A relayout draws the box, styled by bit 0 of `y`; otherwise only the
 * lines around `sel` are redrawn.
 */
INT c_menu_draw(char *title, INT x, INT y, INT sel)
{
    INT junk[40];
    INT i;
    INT wide;
    INT item;

    shm_menu_line_start[0] = 0;
    if (shm_menu_relayout == 1) {
        for (i = 0; i < 0x20; i++)
            shm_menu_shortcut[i] = 0;
        i = shm_menu_text_width = wide = shm_menu_lines = item = 0;
        for (i = 0; i < (INT) strlen(title); i++) {
            if (title[i] == '\n') {
                if (wide > shm_menu_text_width)
                    shm_menu_text_width = wide;
                wide = 0;
                shm_menu_lines++;
                shm_menu_line_start[shm_menu_lines] = i + 1;
            } else {
                if (wide == 0 && title[i] == ' ') {
                    shm_menu_shortcut[item] = (title + i)[1];
                    if (shm_menu_first_line == -1)
                        shm_menu_first_line = shm_menu_lines;
                    item++;
                }
                wide += drv_jump_gfx_char_width(shd_screen->font,
                                          title[i]);
            }
        }
        shm_menu_lines = c_clamp(shm_menu_lines, 0,
                                            (0xc0 - y) / 8);
        shm_menu_right = x + shm_menu_text_width + 8;
        shm_menu_bottom = y + (shm_menu_lines << 3) + 6;
        if (title[strlen(title) - 1] != '\n')
            item--;
        shm_menu_items = item;
        shm_menu_colour_plain = 0xf;
        shm_menu_colour_item = 7;
        shm_menu_colour_pick = 7;
        shm_menu_colour_bar = 5;
        if (y & 1) {
            if (shm_pan_playing != 0) {
                shm_pan_width = c_clamp(shm_active_pan.page_a,
                                                    shm_menu_right + 5,
                                                    0x3e7);
                shd_screen->bg_pen = 5;
                if (y < 0x90) {
                    drv_real_fill_rect(shd_screen, 0, 0,
                                      shm_pan_width, 0xc8, 5);
                    c_hook_repaint();
                } else {
                    drv_real_fill_rect(shd_screen, 4, y, 0x138,
                                      0xc6 - y, 5);
                }
            } else {
                drv_real_fill_rect(shd_screen, x + 1, y + 1,
                                  shm_menu_right - x,
                                  shm_menu_bottom - y,
                                  shd_screen->bg_pen);
                if (shd_screen->bg_pen == 0xf) {
                    shm_menu_colour_plain = 0;
                    shm_menu_colour_pick = 8;
                    shm_menu_colour_item = 7;
                    shm_menu_colour_bar = 0xf;
                }
            }
        } else {
            shd_screen->bg_pen = 5;
            c_menu_box(x, y, shm_menu_right - x,
                            shm_menu_bottom - y, 5);
            shm_menu_colour_bar = 5;
        }
        if (shm_menu_tick != 0) {
            c_write_text(shd_str_ok, shm_menu_right - 0x11,
                            shm_menu_bottom - 8, 0xb);
            c_outline_box(shm_menu_right - 0x14,
                            shm_menu_bottom - 0xa, 0x14, 0xa, 0xb);
        }
    }
    item = *title == ' ' ? 0 : -1;
    shd_screen->fg_pen = shm_menu_colour_plain;
    for (i = 0; i < shm_menu_lines; i++) {
        if (shm_menu_relayout != 0 || (INT) abs(sel - item) < 2) {
            title[shm_menu_line_start[i + 1] - 1] = 0;
            if (item >= 0 && (shm_menu_marked & 1 << item)) {
                title[shm_menu_line_start[i]] = '^';
                c_write_text_trimmed((drv_addr) (title
                                       + shm_menu_line_start[i]),
                                x + 5, (i << 3) + y + 5,
                                item < 0 ? shm_menu_colour_plain
                                : item == sel ? shm_menu_colour_pick
                                : shm_menu_colour_item);
                title[shm_menu_line_start[i]] = ' ';
            } else {
                c_write_text_trimmed((drv_addr) (title
                                       + shm_menu_line_start[i]),
                                x + 5, (i << 3) + y + 5,
                                item < 0 ? shm_menu_colour_plain
                                : item == sel ? shm_menu_colour_pick
                                : shm_menu_colour_item);
            }
            title[shm_menu_line_start[i + 1] - 1] = '\n';
        }
        if (title[shm_menu_line_start[i + 1]] == ' ')
            item++;
    }
    return sel;
}
/* shared_include_end: ../../../../shared/c/MENU-DRAW.C */
