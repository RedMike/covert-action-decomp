/* CITY.C -- the city loop: settling the last errand, then the places in town.
 */
#include "GAME.H"
#include "CASE.H"
#include "PROSE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DECODE.H"
#include "DIALOG.H"
#include "BLOCK.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "ANI_PLAY.H"
#include "ORGPLAN.H"
#include "PRISONER.H"
#include "BUILDING.H"
#include "CITY.H"
#include "LOGKINDS.H"
#include "CAMPSTAT.H"
#include "RESULT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"

/* The city loop: settle whatever the last module came back with, then list the
 * places here and hand the chosen one on, over and over until something takes
 * the player out of town. */
INT c_city_loop(INT city)
{
    INT v0j;    /* whoever the last errand was about */
    INT v1k;    /* the plot a clue belongs to */
    INT v2l;    /* the place being listed */
    INT v3m;
    INT v4n;    /* the hour being slept through */
    INT v5o;    /* that place's record */
    INT v6;     /* what the player chose */
    INT v7a;    /* the organisation the ambush was at */

    do {
        /* In town the status bar sits at the foot of the screen. */
        asm_status_bar_y = 174;
        /* A jailbreak due and nothing else pending: warn of it and hand over to TAC to stop it, at the CIA. */
        if (asm_campaign_state == NONE_NOTHING_PENDING && shm_jailbreak_suspect != -1) {
            drv_jump_gfx_set_colour_map(&dat_colours_map, &dat_colours_map);
            c_pan_arm(dat_str_warning_pan, 168, 0);
            strcpy(shm_scratch, dat_str_jailbreak);
            strcat(shm_scratch, shm_cities[shm_suspects[shm_jailbreak_suspect].city].name);
            strcat(shm_scratch, dat_str_bang_nl);
            strcat(shm_scratch, shm_orgs[shm_suspects[shm_jailbreak_suspect].org].long_name);
            strcat(shm_scratch, dat_str_agents_trying_free);
            c_person_name(shm_jailbreak_suspect);
            strcat(shm_scratch, dat_str_bang_nl_2);
            c_ask_menu(shm_scratch, 16, 21);
            /* One attempt per prisoner. */
            shm_suspects[shm_jailbreak_suspect].flags
                |= SUSPECT_JAILBREAK_ATTEMPTED;
            COMM()->result[RES_TAC_TARGET] = shm_jailbreak_suspect;
            shm_jailbreak_suspect = -1;
            shm_finished = TAC_JAILBREAK;
            shm_case_org = 1;
            return;
        }
        /* Back from the jailbreak: if the player was caught the prisoner escapes, otherwise it was foiled. */
        if (asm_campaign_state == TAC_JAILBREAK) {
            v0j = (char) COMM()->result[RES_TAC_TARGET];
            if (COMM()->result[RES_TAC_END_LINE] == 0xff) {
                drv_jump_gfx_set_colour_map(&dat_colours_city, &dat_colours_city);
                c_pan_arm(dat_str_bustout_pan, 168, 0);
                /* The animation's variable 0 is set by the prisoner's gender, visuals bit 0. */
                c_seq_set_var(0, (shm_suspects[v0j].visuals & 1) != 0 ? -1 : 1);
                c_person_name(v0j);
                strcat(shm_scratch, dat_str_escapes);
                /* The escapee is back in play, his building forgotten, and the escape logged. */
                shm_suspects[v0j].alert_level
                    = ALERT_FREED;
                shm_suspects[v0j].flags |= SUSPECT_JAILBREAK_ATTEMPTED;
                c_building_forget(shm_suspects[v0j].org,
                                shm_suspects[v0j].city);
                c_log_add(LOG_ESCAPED, v0j);
            } else {
                c_pan_blank();
                strcat(shm_scratch, dat_str_escape_attempt_foiled);
            }
            c_ask_menu(shm_scratch, 20, 21);
            asm_campaign_state = NONE_NOTHING_PENDING;
        }
        /* Back from planting a car tracer: alarms raise the alert, 25 apiece. */
        if (asm_campaign_state == BUG_CAR_TRACER) {
            c_raise_alert(shm_case_org, shm_case_city,
                            (char) COMM()->result[RES_BUG_ALARMS] * 25);
            /* A score of 25 or more tracks the car to the building, where the state takes the player next. */
            if ((char) COMM()->result[RES_BUG_SCORE] >= 25) {
                c_building_explore(shm_case_org, city, 8);
                strcpy(shm_scratch, dat_str_car_tracer_leads_new);
                c_ask_menu(shm_scratch, 16, 120);
            } else
                asm_campaign_state = NONE_NOTHING_PENDING;
        }
        /* Back from tailing a suspect: led home finds the building, which the state takes the player to. */
        if (asm_campaign_state == CHASE_SUSPECT) {
            if ((char) COMM()->result[RES_CHASE_OUTCOME] == 1)
                c_building_explore(shm_case_org, city, 8);
            else
                asm_campaign_state = NONE_NOTHING_PENDING;
            /* Caught, he is interrogated; either way his suspicion alerts the organisation. */
            if ((char) COMM()->result[RES_CHASE_OUTCOME] == 2)
                c_arrest((char) COMM()->result[RES_CHASE_SUSPECT]);
            c_raise_alert(shm_case_org, city,
                          (char) COMM()->result[RES_CHASE_ALERT]);
        }
        /* Back from being followed out of a building. */
        if (asm_campaign_state == CHASE_AMBUSHED) {
            /* Caught in the chase: say so, and hand over to TAC for the fight with that organisation. */
            if ((char) COMM()->result[RES_CHASE_OUTCOME] != 0) {
                c_clear_for_menu();
                shm_scratch[0] = 0;
#ifdef PORT_MODERN
                c_show_prose(dat_str_carcap, 32, (char *) 0, 0);
#else
                c_show_prose(dat_str_carcap, 32);
#endif
                c_ask_menu(shm_scratch, 20, 32);
                COMM()->result[RES_TAC_TARGET] = shm_case_org;
                shm_finished = TAC_FIGHT_AMBUSHED;
                return;
            }
            /* Got away: go on to the building the chase reached, as after a tail, with the alert cleared. */
            shm_case_org = (char) COMM()->result[RES_CHASE_GOAL_ORG];
            shm_global_alert_level = 0;
            asm_campaign_state = CHASE_SUSPECT;
        }
        /* Back from escaping after capture: caught again means captivity again. */
        if (asm_campaign_state == TAC_CAPTURE_ESCAPE) {
            if (COMM()->result[RES_TAC_END_LINE] == 0xff)
                c_player_captured_menu();
            if (shm_finished != 0)
                return;
            asm_campaign_state = NONE_NOTHING_PENDING;
        }
        /* Wounds from a break-in without an arrest, an escape, or a fight survived cost six hours each to heal. */
        if ((((COMM()->result[RES_TAC_OUTCOME] & 2) == 0
              && COMM()->result[RES_TAC_END_LINE] != 0xff
              && asm_campaign_state == TAC_BREAK_IN)
             || asm_campaign_state == TAC_CAPTURE_ESCAPE
             || (asm_campaign_state == TAC_FIGHT_AMBUSHED
                 && COMM()->result[RES_TAC_END_LINE] != 0xff))
            && (char) COMM()->result[RES_TAC_WOUNDS] != 0) {
            drv_jump_gfx_set_colour_map(&dat_colours_city_2, &dat_colours_city_2);
            c_pan_arm(dat_str_wounded_pan, 224, 0);
            strcpy(shm_scratch, dat_str_take_time_recover_from);
            c_ask_menu(shm_scratch, 20, 21);
            for (v2l = 0; v2l < (char) COMM()->result[RES_TAC_WOUNDS]; v2l++)
                for (v4n = 0; v4n < 6; v4n++)
                    c_campaign_tick(60);
            /* A fight still has its own outcome to settle below. */
            if (asm_campaign_state != TAC_FIGHT_AMBUSHED)
                asm_campaign_state = NONE_NOTHING_PENDING;
        }
        /* Back from being set upon in the city. */
        if (asm_campaign_state == TAC_FIGHT_AMBUSHED) {
            /* The attack spends the alert: global, and that of the attackers' suspect here. */
            v7a = (char) COMM()->result[RES_TAC_TARGET];
            shm_global_alert_level = 0;
            v0j = c_evidence_unlock(v7a, city, 0, LONG_LIT(0));
            if (v0j != -1
                && shm_suspects[v0j].alert_level
                   > 0)
                shm_suspects[v0j].alert_level = 0;
            /* Caught: on the easiest level only told of the defeat, otherwise taken captive. */
            if (COMM()->result[RES_TAC_END_LINE] == 0xff) {
                if (shm_difficulty == 0) {
                    shm_scratch[0] = 0;
#ifdef PORT_MODERN
                    c_show_prose(dat_str_surprisel, 32,
                                    shm_orgs[v7a].long_name, 0);
#else
                    c_show_prose(dat_str_surprisel, 32,
                                    shm_orgs[v7a].long_name);
#endif
                    c_ask_menu(shm_scratch, 20, 32);
                } else {
                    shm_case_org = v7a;
                    c_player_captured_menu();
                    if (shm_finished != 0)
                        return;
                }
            /* Won: the attackers are named, and their building here found and identified. */
            } else {
                shm_scratch[0] = 0;
#ifdef PORT_MODERN
                c_show_prose(dat_str_surprisew, 32,
                                shm_orgs[v7a].long_name, 0);
#else
                c_show_prose(dat_str_surprisew, 32,
                                shm_orgs[v7a].long_name);
#endif
                c_ask_menu(shm_scratch, 20, 32);
                c_building_explore(v7a, shm_case_city, 0xc);
            }
            asm_campaign_state = NONE_NOTHING_PENDING;
        }
        for (;;) {
            /* The city screen: its picture, unless passing straight through to a building. */
            c_clear_for_menu();
            asm_last_screen = -1;
            if (asm_campaign_state == NONE_NOTHING_PENDING)
                c_city_picture(shm_case_city, 240, 140);
            shd_screen->bg_pen = 5;
            c_campaign_tick(0);
            /* The menu always offers the airport and the hotel first. */
            strcpy(shm_scratch, dat_str_you_are_in);
            strcat(shm_scratch, shm_cities[shm_case_city].name);
            strcat(shm_scratch, dat_str_do_go);
            strcat(shm_scratch, dat_str_airport);
            strcat(shm_scratch, dat_str_hotel);
            asm_menu_choice_count = 2;
            /* Then every building known here, named if identified, each entry standing for its organisation. */
            for (v2l = 1; v2l < 16; v2l++) {
                v5o = c_building_explore(v2l, city, 0);
                if (v5o == -1)
                    continue;
                asm_menu_choices[asm_menu_choice_count++] = v2l;
                if ((shm_buildings[v5o].identity_flags & 4) != 0) {
                    strcat(shm_scratch,
                               shm_orgs[v2l].long_name);
                    c_say_presence(city, v2l);
                } else
                    strcat(shm_scratch, dat_str_unknown_building);
                strcat(shm_scratch, dat_str_nl_space);
            }
            /* Then every address a clue has given for a suspect based in this city. */
            v2l = 0;
            do {
                if (shm_clues_shown[v2l].role != -1) {
                    v1k = shm_clues_shown[v2l].role;
                    if (shm_clues_shown[v2l].text >> 8 == 2
                        && shm_clues_shown[v2l].subject >> 8
                           == 8
                        && shm_suspects[shm_crime_roles[v1k].suspect].city
                           == shm_case_city) {
                        c_clue_thing(shm_clues_shown[v2l].text);
                        strcat(shm_scratch, dat_str_nl_space_2);
                        asm_menu_choices[asm_menu_choice_count++] =
                            shm_suspects[shm_crime_roles[v1k].suspect].org;
                    }
                }
                v2l++;
            } while (v2l < 80);
            /* Check Data closes the menu. */
            strcat(shm_scratch, dat_str_check_data);
            asm_menu_choices[asm_menu_choice_count] = -1;
            /* With nothing pending, ask where to go. */
            if (asm_campaign_state == NONE_NOTHING_PENDING) {
                v6 = c_ask_menu(shm_scratch, 16, 9);
                /* Past the easiest level, going anywhere but the first place listed risks an ambush. */
                v0j = shm_suspects[shm_crime_roles[c_random_below(shm_crime_role_count)].suspect].org;
                /* It strikes when its alert here tops 50, or 20 where the CIA office has a double agent. */
                if (shm_difficulty != 0 && v6 > 2
                    && v6 < asm_menu_choice_count
                    && ((shm_double_agent_cities & 1 << shm_case_city) != 0
                        ? 20 : 50)
                       < c_org_mood(v0j, shm_case_city)) {
                    /* Then say so and hand over to TAC for the fight, the alert spent. */
                    COMM()->result[RES_TAC_TARGET] = v0j;
                    shm_finished = TAC_FIGHT_AMBUSHED;
                    shm_global_alert_level = 0;
                    c_clear_for_menu();
                    shm_scratch[0] = 0;
#ifdef PORT_MODERN
                    c_show_prose(dat_str_surprise, 16, (char *) 0, 0);
#else
                    c_show_prose(dat_str_surprise, 16);
#endif
                    c_ask_menu(shm_scratch, 24, 31);
                    return;
                }
            } else
                /* Something pending: go straight to the building it concerns, or to the CIA after a decode. */
                switch ((INT) asm_campaign_state) {
                case TAC_BREAK_IN:
                case CHASE_SUSPECT:
                case BUG_WIRETAP:
                case BUG_CAR_TRACER:
                case NONE_CAMPAIGN_START:
                    v6 = 2;
                    asm_menu_choices[2] = shm_case_org;
                    break;

                case CODE_MESSAGE_DECODE:
                    v6 = 2;
                    asm_menu_choices[2] = 1;
                    break;
                }
            /* Check Data comes back to this same screen. */
            if (v6 == asm_menu_choice_count)
                c_data_menu();
            else
                break;
        }
        /* The hotel, or two hours to get anywhere else, waived when a break-in has just made an arrest. */
        if (v6 == 1)
            c_hotel_menu();
        else if (asm_campaign_state != TAC_BREAK_IN
                 || (COMM()->result[RES_TAC_OUTCOME] & 2) == 0)
            c_campaign_tick(120);
        /* A place: go to its organisation's building; the airport or Escape leaves town. */
        if (v6 > 1) {
            shm_case_org = asm_menu_choices[v6];
            if (shm_case_org != 0)
                c_building_menu();
        }
    } while (v6 > 0 && shm_finished == 0);
}
