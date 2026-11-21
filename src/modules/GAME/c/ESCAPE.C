/* ESCAPE.C -- the player captured: exchanged for a prisoner, or escaping.
 */
#include "GAME.H"
#include "PROSE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "ADVICE.H"
#include "DIALOG.H"
#include "BLOCK.H"
#include "CASE.H"
#include "SUSPECT.H"
#include "PRISONER.H"
#include "LOGKINDS.H"
#include "CAMPSTAT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"

/* The player captured: grilled, then exchanged for a prisoner, or held for
 * spells of six hours -- in which the enemy may break our own prisoner out --
 * until the escape panel. */
INT c_player_captured_menu(void)
{
    INT v0j;    /* the six-hour spell being served */

    /* The surrender scene, and the player grilled by the captors. */
    drv_jump_gfx_set_colour_map(&dat_colours_escape, &dat_colours_escape);
    c_pan_arm(dat_str_surndr01_pan, 224, 0);
    shm_scratch[0] = 0;
#ifdef PORT_MODERN
    c_show_prose(dat_str_grilled, 24, (char *) 0, 0);
#else
    c_show_prose(dat_str_grilled, 24);
#endif
    /* No exchange made: the player sits in a cell while the clock runs. */
    if (c_prisoner_exchange() == 0) {
        for (v0j = 0; v0j < c_random_below(3) + 2; v0j++) {
            c_campaign_tick(360);
            /* Unless that time brought a jailbreak due, there is nothing to report. */
            if (shm_jailbreak_suspect == -1)
                continue;
            /* With the player locked up, the jailbreak goes unopposed: announce it. */
            c_clear_for_menu();
            drv_jump_gfx_set_colour_map(&dat_colours_map, &dat_colours_map);
            c_pan_arm(dat_str_warning_pan_2, 160, 0);
            strcpy(shm_scratch, dat_str_jailbreak_2);
            strcat(shm_scratch, shm_cities[shm_suspects[shm_jailbreak_suspect].city].name);
            strcat(shm_scratch, dat_str_bang_nl_3);
            strcat(shm_scratch, shm_orgs[shm_suspects[shm_jailbreak_suspect].org].long_name);
            strcat(shm_scratch, dat_str_agents_free);
            c_person_name(shm_jailbreak_suspect);
            strcat(shm_scratch, dat_str_bang_nl_4);
            c_ask_menu(shm_scratch, 16, 21);
            /* The prisoner is free, and their organisation's building there is forgotten. */
            shm_suspects[shm_jailbreak_suspect].flags
                |= SUSPECT_JAILBREAK_ATTEMPTED;
            shm_suspects[shm_jailbreak_suspect].alert_level = ALERT_FREED;
            c_building_forget(shm_suspects[shm_jailbreak_suspect].org,
                            shm_suspects[shm_jailbreak_suspect].city);
            /* Into the case log, and the jailbreak is spent. */
            c_log_add(LOG_ESCAPED, shm_jailbreak_suspect);
            shm_jailbreak_suspect = -1;
        }
        /* Then the chance to break out, played in TAC. */
        drv_jump_gfx_set_colour_map(&dat_colours_escape_2, &dat_colours_escape_2);
        c_pan_arm(dat_str_escape_pan, 224, 0);
        shm_scratch[0] = 0;
#ifdef PORT_MODERN
        c_show_prose(dat_str_escape, 24, (char *) 0, 0);
#else
        c_show_prose(dat_str_escape, 24);
#endif
        c_ask_menu(shm_scratch, 16, 21);
        shm_finished = TAC_CAPTURE_ESCAPE;
    } else {
        /* Exchanged: past the easiest level the building is forgotten, and the player is out of it. */
        if (shm_difficulty != 0)
            c_building_forget(shm_case_org, shm_case_city);
        asm_watched = 1;
    }
}
