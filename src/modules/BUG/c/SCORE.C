/* SCORE.C -- what a tapped phone turns up about the case.
 */
#include "BUG.H"
#include "CASERUN.H"
#include "BOARD.H"

/* Run the case scan for `what` worth of watching the organisation and city the
 * module was entered for, at the whole case's difficulty.
 */
void c_scan_for_tap(UNSIGNED_INT what)
{
    INT unit;

    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 0x140, 0xc8, shd_map_page, 0, 0);
    c_set_palette_record(4);
    asm_title_x = 0xa0;
    asm_title_y = 0x64;
    unit = shm_difficulty;
    shm_difficulty = asm_case_difficulty;
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
    c_suspect_scan(shm_case_org, shm_case_city, what, LONG_LIT(1));
    drv_jump_gfx_set_colour_map(&dat_colours_plain, &dat_colours_plain);
    shm_difficulty = unit;
    c_set_palette_record(asm_frame_count & 3);
    drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 0x140, 0xc8, shd_screen, 0, 0);
}
