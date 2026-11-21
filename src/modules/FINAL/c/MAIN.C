/* MAIN.C -- the module's entry point. */
#include "FINAL.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "LOADDISK.H"
#include "CSTART.H"
#include "CMISEND.H"
#include "CMISSTRT.H"
#include "CASERUN.H"
#include "SAVELOAD.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "MAIN.H"
#include "ORIENT.H"
#include "MODOPTS.H"
#include "SETUPTXT.H"
#include "RESULT.H"
#include "ALERTLVL.H"

/* The module's entry point: the title, the main menu -- a new character, a
 * saved game, practising a skill, the Hall of Fame -- and the way into a case.
 * A case coming back from the other modules is settled and the next briefed.
 * Practising and a game loaded mid-mission skip the briefing through `goto
 * ending`.
 */
void c_main(void)
{
    INT saved;
    INT choice;

#ifdef COVERT_MENU_OPTIONS
    c_mod_options_load();
#endif
    /* Make the three drivers COVERT loaded callable, and open the screen in the title's colours. */
    drv_real_link_slots(COMM()->driver_segment[0]);
    drv_real_link_slots(COMM()->driver_segment[1]);
    drv_real_link_slots(COMM()->driver_segment[2]);
    drv_jump_gfx_open(0);
    shd_screen->font = 1;
    shd_screen->bg_pen = 8;
    drv_jump_gfx_set_palette(&dat_palette_title);
    drv_jump_gfx_set_colour_map(&dat_colours_title, &dat_colours_title_2);
    /* Seed the random numbers, and the case's own seed, from the clock. */
    shm_case_seed = (UNSIGNED_INT) time(0L) & 0x7fff;
    srand(shm_case_seed);
    /* Two words set here and read nowhere. */
    asm_DAT_20d8_9bee = -1;
    asm_DAT_20d8_9e86 = 1;
    /* A session just starting: note the graphics driver, and whether it is CGA. */
    if (COMM()->next_module == FINAL_TITLE) {
        asm_fresh_start = 1;
        shm_graphics_letter = COMM()->graphics_driver;
        shm_cga = shm_graphics_letter == 'C';
    }
    /* Back from practice: take back the state the shared block kept across it. */
    if (COMM()->next_module == FINAL_PRACTICE_OVER) {
        asm_fresh_start = -1;
        c_save_get(dat_str_env_sve);
    }
    /* Nothing runs next unless a choice below says so, and any practice is over. */
    COMM()->next_module = NONE_EXIT;
    shm_options &= ~OPT_PRACTICE;
    if (asm_fresh_start == 1) {
        /* A new session has sound and animations on, sound off with the null driver. */
        shm_options |= (OPT_SOUND | OPT_ANIMATION);
        if (COMM()->sound_driver == 'N')
            shm_options &= ~OPT_SOUND;
        /* With a joystick chosen, calibrate it: one corner, a pause, then the other. */
        if (COMM()->joystick_enabled) {
            drv_jump_joy_calibrate();
            shm_options |= OPT_JOYSTICK;
            strcpy(shm_scratch, dat_str_move_joystick_upper);
            c_menu_run((rt_addr) shm_scratch, 80, 91);
            c_wait_for_release();
            c_wait_retraces(60);
            strcpy(shm_scratch, dat_str_move_joystick_lower);
            c_menu_run((rt_addr) shm_scratch, 80, 91);
            c_wait_for_release();
        }
    }
    /* The labs picture behind the title, for a new session only; the faces always. */
    if (asm_fresh_start == 1)
        c_load_picture(dat_str_labs_pic, 0);
    c_faces_load();
    if (asm_fresh_start == 0) {
        /* Back from a case: take its state back, then score it and debrief. */
        c_save_get(dat_str_env_sve_2);
        shm_options |= OPT_ANIMATION;
        c_case_end();
        /* The MasterMind arrested, or the tutorial set done, ends the set: start another. */
        if (shm_suspects[0].alert_level == ALERT_ARRESTED
            || shm_campaign.mission_set == 0)
            c_set_start();
    } else {
        /* A new session opens on the title and, unless a key cut it short, the credits. */
        if (asm_fresh_start == 1) {
            c_sound_command(2);
            drv_jump_gfx_set_colour_map(&dat_colours_main, &dat_colours_main);
            c_play_animation(dat_str_title2_pan, 0, 0);
            if (drv_jump_keyboard_empty())
                c_play_animation(dat_str_credits_pan, 0, 0);
        }
        /* The main menu, asked again after anything that does not lead into a case. */
        for (;;) {
            /* The shipped four items, then whichever the mod builds add under
             * them. */
            shd_screen->bg_pen = 5;
            strcpy(shm_scratch, dat_str_do_want_create_new);
#ifdef SETUP_OPTIONS
            strcat((str_addr) shm_scratch, (str_addr) " Options\n");
#endif
#ifdef COVERT_MENU_OPTIONS
            /* A further item, made one by the line's leading space. */
            strcat((str_addr) shm_scratch, (str_addr) " Mod Options\n");
#endif
#ifdef DIAGNOSTICS
            strcat((str_addr) shm_scratch, (str_addr) " Diagnostics\n");
#endif
            /* Ask; sound command 1 follows whatever the answer, Escape included. */
            choice = c_ask_menu((rt_addr) shm_scratch, 80, 80);
            shd_screen->bg_pen = 5;
            c_sound_command(1);
            switch (choice) {
            /* The mod builds' own menus, coming back to the main menu on their own item. */
#ifdef SETUP_OPTIONS
            case OPTIONS_ITEM:
                c_setup_menu();
                shm_menu_pick = OPTIONS_ITEM;
                continue;
#endif
#ifdef COVERT_MENU_OPTIONS
            case MOD_OPTIONS_ITEM:
                c_mod_options_menu();
                shm_menu_pick = MOD_OPTIONS_ITEM;
                continue;
#endif
#ifdef DIAGNOSTICS
            case DIAGNOSTICS_ITEM:
                c_diagnostics_menu();
                shm_menu_pick = DIAGNOSTICS_ITEM;
                continue;
#endif
            /* Escape too starts a new character: a campaign, and its first mission set. */
            case MAIN_MENU_NO_CHOICE:
            case MAIN_MENU_CREATE_A_NEW_CHARACTER:
                c_campaign_start();
                c_set_start();
                break;
            /* The Hall of Fame as fame.dta has it, then back to the menu. */
            case MAIN_MENU_REVIEW_HALL_OF_FAME:
                c_fame_load();
                c_fame_screen(-1);
                continue;
            /* A difficulty and a skill, and off to practise it with no briefing. */
            case MAIN_MENU_PRACTICE_A_SKILL:
                choice = c_difficulty_menu();
                if (choice == -1)
                    continue;
                c_practice_setup(choice);
                goto ending;
            /* A saved game, keeping this session's joystick setting over the save's. */
            case MAIN_MENU_LOAD_A_SAVED_GAME:
                saved = shm_options;
                if ((INT) c_load_menu() == -1)
                    continue;
                shm_options = (saved & OPT_JOYSTICK) | (shm_options & ~OPT_JOYSTICK);
                /* Saved between missions: go on as from a case's end, to the next mission. */
                if (shm_options & OPT_MISSION_ENDED) {
                    if (shm_suspects[0].alert_level == ALERT_ARRESTED
                        || shm_campaign.mission_set == 0)
                        c_set_start();
                    break;
                }
                /* Saved mid-mission: straight back to GAME with that mission under way. */
                COMM()->next_module = GAME_CAMPAIGN;
                COMM()->mission_started = 1;
                COMM()->handover = 0;
                COMM()->result[RES_MINUTES] = 0;
                c_save_put(dat_str_env_sve_3);
                goto ending;
            }
            break;
        }
    }

    /* The set's next mission, for GAME to start afresh. */
    c_mission_pick();
    COMM()->next_module = GAME_CAMPAIGN;
    COMM()->mission_started = 0;
    asm_dossier_seen = -1;

ending:
    /* A new mission is generated and briefed, the copyright screen with it. */
    if (COMM()->mission_started == 0) {
        c_case_generate();
        /* Failing the copyright screen sends the player to practise at the lowest difficulty. */
        if (shm_seq_vars[0] != 1) {
            shm_difficulty = 0;
            choice = c_training_screen(LONG_LIT(1));
            c_practice_setup(choice == -1 ? 0 : choice);
        } else {
            c_save_put(dat_str_env_sve_4);
        }
    }
    /* Make sure the disk with the next module is in: 3 for combat practice, else 2. */
    drv_jump_gfx_set_palette(&dat_palette_title);
    if (COMM()->next_module == TAC_PRACTICE)
        c_want_disk(3, LONG_LIT(1));
    else
        c_want_disk(2, LONG_LIT(1));
    c_hook_hand_back(UNSET_ARGS(0));
}
