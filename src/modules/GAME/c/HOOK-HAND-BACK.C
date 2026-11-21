/* HOOK-HAND-BACK.C -- handing the game over to the next module.
 */
#include "GAME.H"
#include "HANDOVER.H"
#include "CASE.H"
#include "ANI_LD2.H"
#include "SAVELOAD.H"
#include "ORGPLAN.H"
#include "RESULT.H"

/* Fill the shared block in for whatever runs next -- the local organisation's
 * alert, the difficulty, and shm_finished as the next module -- save, and hand
 * back. 0ffh means nobody runs next, so the closing picture is shown here.
 */
void c_hook_hand_back(UNSET_PARAMS(INT unused))
{
    /* Tell the next module the local organisation's alert, the difficulty and what to run, with no time spent yet. */
    COMM()->org_alert_level = c_org_mood(shm_case_org, shm_case_city);
    COMM()->game_50 = shm_difficulty;
    COMM()->handover = COMM()->next_module = shm_finished;
    COMM()->result[RES_MINUTES] = 0;
    /* Save the campaign to env.sve across the hand-over. */
    c_save_put(dat_str_env_sve_2);
    /* Leave the display on the game palette and the front page. */
    drv_jump_gfx_set_palette(&dat_palette_game);
    drv_jump_gfx_show_page(0);
    /* With nothing to run next the game is over: show ad.pic until a key. */
    if (COMM()->next_module == NONE_EXIT) {
        c_load_picture(dat_str_ad_pic, 0);
        c_wait_key();
    }
}
