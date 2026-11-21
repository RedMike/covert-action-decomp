/* MAIN.C -- the module's entry point.
 */
#include "BUG.H"
#include "LOADDISK.H"
#include "ANIMSTUB.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "MENU.H"
#include "BOARD.H"
#include "MAIN.H"
#include "RESULT.H"

/* The bugging module's entry point: set the scene up from what COMM says, run
 * the board until the round is over, then tell the next module what happened.
 * A next_module of BUG_CAR_TRACER on entry makes the round a car tracer on
 * half the time.
 */
void c_main(void)
{
    asm_DAT_1a63_7636 = 1;
    c_save_get(dat_str_env_sve);
    asm_case_difficulty = shm_difficulty;
    shm_difficulty =
        c_clamp(shm_difficulty - ((INT) COMM()->skills >> 6 & 3) + 1,
                           0, 3);
    asm_seconds_left =
        (INT) c_clamp(-((INT) COMM()->org_alert_level / 5 - 10), 2, 10) * 0x3c;
    if (COMM()->next_module == BUG_CAR_TRACER) {
        asm_board_stage = BOARD_STAGE_TRACER;
        asm_seconds_left /= 2;
    }
    COMM()->next_module = NONE_EXIT;
    drv_real_link_slots(COMM()->driver_segment[0]);
    drv_real_link_slots(COMM()->driver_segment[1]);
    drv_real_link_slots(COMM()->driver_segment[2]);
    shd_screen->font = 1;
    shd_screen->bg_pen = 0xf;
    drv_jump_gfx_set_colour_map(&dat_colours_plain, &dat_colours_plain);
    drv_jump_gfx_pool_alloc();
    c_load_picture(dat_str_camera_pic, 2);
    asm_agent_sprite = drv_jump_gfx_grab(2, 0, 0, 0x92, 0x66);
    asm_wire_sprite = drv_jump_gfx_grab(2, 0xc8, 0, 0x48, 0x3d);
    drv_jump_gfx_pool_release();
    c_load_sprites();
    drv_jump_gfx_set_colour_map(&dat_colours_plain, &dat_colours_plain);
    c_load_picture(dat_str_board_pic, 0);
    c_seed_random();
    c_deal_board();
    c_wait_for_release();
    do {
        c_read_keys();
    } while (shm_finished == 0);
    COMM()->result[RES_BUG_SCORE] = (INT) asm_score * 5;
    COMM()->result[RES_BUG_ALARMS] = asm_alarms;
    COMM()->next_module = (shm_options & OPT_PRACTICE)
        ? FINAL_PRACTICE_OVER : GAME_CAMPAIGN;
    c_save_put(dat_str_env_sve_2);
    c_sound_command(0);
    c_hook_hand_back(UNSET_ARGS(0));
    c_set_palette_record(4);
    c_want_disk((shm_options & OPT_PRACTICE) ? 1 : 2,
                       LONG_LIT(1));
}
