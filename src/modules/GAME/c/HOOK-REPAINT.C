/* HOOK-REPAINT.C -- the status bar: where the player is, and the time.
 */
#include "GAME.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "PANEL.H"

/* Draw the status bar: the frame, the panel behind it, where the player is,
 * and the clock, then put the bar's own row back to 0aeh. */
INT c_hook_repaint(void)
{
    char v0j[32];   /* the place name and its country */

    /* The bar has colours of its own. */
    drv_jump_gfx_set_colour_map(&dat_colours_statbar, &dat_colours_statbar);
    /* The bar, 160 wide at the left, with a bevelled edge. */
    drv_real_fill_rect(shd_screen, 0, asm_status_bar_y, 160, 26, 8);
    c_draw_line(1, asm_status_bar_y + 1, 1, asm_status_bar_y + 24, 5);
    c_draw_line(2, asm_status_bar_y + 2, 2, asm_status_bar_y + 24, 7);
    c_draw_line(2, asm_status_bar_y + 1, 158, asm_status_bar_y + 1, 7);
    c_draw_line(158, asm_status_bar_y + 2, 158,
                    asm_status_bar_y + 24, 5);
    c_draw_line(2, asm_status_bar_y + 24, 158,
                    asm_status_bar_y + 24, 5);
    /* A box on its upper line for where the player is. */
    drv_real_fill_rect(shd_screen, 5, asm_status_bar_y + 3, 150, 9, 5);
    c_draw_line(3, asm_status_bar_y + 3, 5, asm_status_bar_y + 3, 5);
    c_draw_line(6, asm_status_bar_y + 4, 6, asm_status_bar_y + 11, 7);
    c_draw_line(156, asm_status_bar_y + 3, 156,
                    asm_status_bar_y + 11, 5);
    /* The city and its country, centred in it. */
    strcpy(v0j, shm_cities[shm_case_city].name);
    strcat(v0j, dat_str_comma_space_2);
    strcat(v0j, shm_cities[shm_case_city].country);
    c_draw_centred((str_addr) v0j, 80, asm_status_bar_y + 4, 10);
    /* A narrower box below it for the clock. */
    drv_real_fill_rect(shd_screen, 15, asm_status_bar_y + 14, 130, 9, 5);
    c_draw_line(13, asm_status_bar_y + 14, 15,
                    asm_status_bar_y + 14, 5);
    c_draw_line(16, asm_status_bar_y + 15, 16,
                    asm_status_bar_y + 22, 7);
    c_draw_line(146, asm_status_bar_y + 14, 146,
                    asm_status_bar_y + 22, 5);
    /* The campaign's time and date, centred in it. */
    c_draw_centred((str_addr) c_timestamp(shm_clock_minutes), 80,
                    asm_status_bar_y + 15, 10);
    /* Back to the screen's colours, and the bar back to the foot of the screen, where it sits in town. */
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
    asm_status_bar_y = 174;
}
