/* DOOR.C -- the turning animation.
 */
#include "CHASE.H"
#include "SETUP.H"
#include "RETRACE.H"
#include "DOOR1.H"

/* Animate the active car turning a quarter turn, left or right as `side` lies
 * from `dir`; any other turn animates nothing. Each frame blits the windscreen
 * picture in two pieces either side of a moving split.
 */
void c_turning_animation(INT dir, INT side)
{
    INT at;

    drv_jump_gfx_set_palette(&dat_palette_default);
    if ((((unsigned char) dir - 1) & 3) == side) {
        c_sound_command(0x17);
        at = 8;
        do {
            drv_jump_gfx_copy_rect(dat_dash_page, asm_windscreen_frame / 4 * 0x7d, asm_windscreen_frame % 4 * 0x2f, 0x74 - at, 0x2c, shd_screen, at + 0xc9, 1);
            drv_jump_gfx_copy_rect(dat_dash_page, asm_windscreen_frame / 4 * 0x7d - at + 0x74, asm_windscreen_frame % 4 * 0x2f, at, 0x2c, shd_screen, 0xc9, 1);
            c_wait_retraces(2);
            at += 32 / ((INT) asm_game_speed + 2);
        } while (at < 0x74);
    }
    if ((((unsigned char) dir + 1) & 3) == side) {
        c_sound_command(0x17);
        at = 0x6c;
        do {
            drv_jump_gfx_copy_rect(dat_dash_page, asm_windscreen_frame / 4 * 0x7d, asm_windscreen_frame % 4 * 0x2f, 0x74 - at, 0x2c, shd_screen, at + 0xc9, 1);
            drv_jump_gfx_copy_rect(dat_dash_page, asm_windscreen_frame / 4 * 0x7d - at + 0x74, asm_windscreen_frame % 4 * 0x2f, at, 0x2c, shd_screen, 0xc9, 1);
            c_wait_retraces(2);
            at -= 32 / ((INT) asm_game_speed + 2);
        } while (at > 8);
    }
    drv_jump_gfx_set_palette(&dat_palette_chase);
}
