/* MAIN.C -- the module's entry point: start or resume the career and run it.
 */
#include "GAME.H"
#include "LOADDISK.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "SAVELOAD.H"
#include "FACES.H"
#include "HANDOVER.H"
#include "TRAVEL.H"
#include "CITY.H"
#include "CAMPSTAT.H"
#include "RESULT.H"

/* Link the drivers COVERT.EXE loaded, start a fresh campaign or resume one,
 * and run it city by city until shm_finished says it is over; then ask for
 * the disk that ending needs and hand back.
 *
 * A resumed campaign reads its difficulty and place back out of the block.
 */
INT c_main(void)
{
    INT spare;

    /* Make the three drivers COVERT.EXE loaded callable. */
    drv_real_link_slots(COMM()->driver_segment[0]);
    drv_real_link_slots(COMM()->driver_segment[1]);
    drv_real_link_slots(COMM()->driver_segment[2]);
    /* The screen's font and colours, and the portraits. */
    shd_screen->font = 1;
    shd_screen->bg_pen = 15;
    c_faces_load();
    drv_jump_gfx_set_palette(&dat_palette_game);
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
    /* Take up the campaign where the shared block left it, on a blank screen. */
    c_save_get(dat_str_env_sve);
    c_seed_random();
    c_clear_for_menu();
    /* The next menu clears the screen first, and the city's contact counts as met. */
    asm_last_screen = 0xffff;
    asm_contact_met = 1;
    if (COMM()->mission_started == 0) {
        /* A new mission: no jailbreak pending, the CIA to deal with, sound and animation on. */
        shm_jailbreak_suspect = 0xffff;
        c_campaign_start();
        COMM()->mission_started = 1;
        asm_campaign_state = NONE_CAMPAIGN_START;
        shm_case_org = 1;
        shm_options |= (OPT_SOUND | OPT_ANIMATION);
    } else {
        /* Back from another module: its handover is still to be dealt with. */
        shm_difficulty = COMM()->game_50;
        asm_campaign_state = (char) COMM()->handover;
        c_hook_repaint();
        /* The time it took passes, rounded up to the half hour, unless a chase or break-in made an arrest. */
        if (!(asm_campaign_state == CHASE_SUSPECT
              && COMM()->result[RES_CHASE_OUTCOME] == 2)
            && !(asm_campaign_state == TAC_BREAK_IN
                 && (COMM()->result[RES_TAC_OUTCOME] & 2) != 0))
            c_campaign_tick((unsigned) ((char) COMM()->result[RES_MINUTES]
                                        + 29) / 30 * 30);
        /* A case under way is ready to break. */
        asm_case_ready = 1;
    }
    /* Nothing is to run next until the hand-back names a module. */
    COMM()->next_module = NONE_EXIT;
    c_wait_for_release();
    /* City by city until something ends the campaign's run here. */
    do {
        c_city_loop(shm_case_city);
        if (shm_finished == 0)
            c_travel_menu(shm_case_city);
    } while (shm_finished == 0);
    /* TAC's handovers need disk 3 in the drive, FINAL's disk 1. */
    switch (shm_finished) {
    case 1:
    case 7:
    case 8:
    case 10:
    case 13:
        c_want_disk(3, (LONG) 1);
        break;
    case 9:
    case 11:
        c_want_disk(1, (LONG) 1);
        break;
    }
    /* "One moment please..." while the next module loads. */
    shm_menu_draw_only = 1;
    c_ask_menu(dat_str_one_moment_please, 100, 2);
    c_hook_hand_back(UNSET_ARGS(0));
}
