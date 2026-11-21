/* ADVICE.C -- the chief's briefing on where the clues and evidence point.
 */
#include "GAME.H"
#include "PROSE.H"
#include "CMP_STRT.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DIALOG.H"
#include "CASE.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "ANI_PLAY.H"
#include "WRAP.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"
#include "ORIENT.H"
#include "SUSPFLAG.H"

/* The chief's briefing: which organisations and cities the clues and evidence
 * point at, then the one lead worth following next. */
INT c_chief_briefing(void)
{
    INT v0j;    /* the suspect the message names */
    INT v1j;    /* the first crime role's suspect, or -1 if not pointed at */
    INT v2j;    /* how much this suspect is worth */
    INT v3k;    /* the crime event the log entry records */
    INT v4k;    /* the highest count seen */
    INT v5k;    /* the entry being walked */
    INT v6l;    /* how long the text was before the list */
    INT v7l;    /* the log entry being walked */
    INT v8l;    /* where the tap would go */
    INT v9m;    /* set when the list got an entry */
    INT v10f;   /* the best score so far */
    INT v11f;   /* what the advice turned out to be */

    /* The chief's office, its animation picked by the agent's sex. */
    drv_jump_gfx_set_colour_map(&dat_colours_advice, &dat_colours_advice);
#ifdef FLEXIBLE_ORIENTATION
    /* The office by this mission's pairing rather than the agent's sex. */
    c_orientation_load();
    c_pan_arm(mission_orientation ? dat_str_officem_pan : dat_str_officef_pan,
                    168, 0);
    c_seq_set_var(0, mission_orientation ? -1 : 1);
#else
    c_pan_arm((shm_options & OPT_FEMALE) != 0 ? dat_str_officem_pan : dat_str_officef_pan,
                    168, 0);
    c_seq_set_var(0, (shm_options & OPT_FEMALE) != 0 ? -1 : 1);
#endif
    /* "Max, I've been going over the info we've got..." */
    strcpy(shm_scratch, dat_str_max_i_ve_been);
    c_ask_menu(shm_scratch, 16, 17);
    /* On the easiest level, in city 1, the first role's suspect is pointed at outright. */
    v1j = shm_crime_roles[0].suspect;
    if (shm_difficulty != 0
        || shm_suspects[v1j].alert_level < 0
        || shm_case_city != 1)
        v1j = -1;
    /* How many names the busiest organisation has been told, 3 at least. */
    v4k = 3;
    for (v5k = 0; v5k < 16; v5k++)
        if (v4k < shm_activity.org[v5k])
            v4k = shm_activity.org[v5k];
    /* Name each organisation within a quarter of the busiest, and the pointed-at suspect's. */
    v9m = 0;
    strcpy(shm_scratch, dat_str_i_d_look_into);
    for (v5k = 0; v5k < 16; v5k++)
        if (v4k - v4k / 4
            <= shm_activity.org[v5k]
            || (v1j != -1
                && shm_suspects[v1j].org == v5k)) {
            strcat(shm_scratch, dat_str_space_15);
            strcat(shm_scratch, shm_orgs[v5k].long_name);
            strcat(shm_scratch, dat_str_newline_17);
            v9m = 1;
        }
    /* No organisation stands out: drop the heading too. */
    if (v9m == 0)
        shm_scratch[0] = 0;
    /* The same for the cities: how busy the busiest is, 3 at least. */
    v4k = 3;
    for (v5k = 0; v5k < 16; v5k++)
        if (v4k < shm_activity.city[v5k])
            v4k = shm_activity.city[v5k];
    /* Name each city within a quarter of the busiest, and city 1 for the pointed-at suspect. */
    v9m = 0;
    v6l = strlen(shm_scratch);
    strcat(shm_scratch, &dat_str_mark_8f_2);
    for (v5k = 0; v5k < 16; v5k++)
        if (v4k - v4k / 4
            <= shm_activity.city[v5k]
            || (v1j != -1 && v5k == 1)) {
            strcat(shm_scratch, shm_cities[v5k].name);
            strcat(shm_scratch, dat_str_newline_space);
            v9m = 1;
        }
    /* No city stands out: drop its heading, and with neither list say there's not much to go on. */
    if (v9m == 0) {
        *((char *) shm_scratch + v6l) = 0;
        if (v6l == 0)
            strcpy(shm_scratch, dat_str_there_s_not_much);
    }
    /* Make the pointed-at suspect's building in city 1 known; until it is tapped, advise tapping it. */
    if (v1j != -1) {
        v8l = c_building_explore(shm_suspects[v1j].org, 1, 0xc);
        if (v8l == -1
            || shm_buildings[v8l].wiretap_level == 0) {
            /* Show the lists, then what the organisation has right here in this city, and the tip. */
            shm_menu_no_pick = 1;
            c_ask_menu(shm_scratch, 16, 81);
            c_pan_blank();
            strcpy(shm_scratch, dat_str_the);
            strcat(shm_scratch,
                       shm_orgs[shm_suspects[v1j].org].long_name);
            strcat(shm_scratch, dat_str_has);
            c_say_presence(1, shm_suspects[v1j].org);
            strcat(shm_scratch, dat_str_right_here);
            strcat(shm_scratch,
                       shm_cities[shm_case_city].name);
            strcat(shm_scratch, dat_str_i_d_suggest_go);
            c_wrap_message(16);
            c_ask_menu(shm_scratch, 16, 17);
            return;
        }
    }
    /* Otherwise find the one lead worth most: nothing yet. */
    v11f = -1;
    v10f = 0;
    /* A known, unspent intercepted message whose sender's role is still unknown: send it to Crypto. */
    for (v7l = 0; v7l < shm_log_count; v7l++) {
        v3k = shm_log[v7l].slot;
        if (shm_log[v7l].kind == LOG_MESSAGE
            && shm_log[v7l].known != 0
            && ((shm_crime_events[v3k].flags & CRIME_KIND) == CRIME_MESSAGE
                || (shm_crime_events[v3k].flags & CRIME_KIND)
                   == (CRIME_MESSAGE | CRIME_RECEIVED)
                || v3k < 0)
            && (shm_log[v7l].known & 0x8000)
               == 0) {
            v0j = shm_log[v7l].from;
            if ((shm_suspects[v0j].role_known & 0x7fff)
                == 0) {
                /* "This message should give us some vital info: ... Check with the Crypto branch.", worth 6. */
                strcpy(shm_scratch, dat_str_message_should_give_us);
                c_person_name(v0j);
                strcat(shm_scratch, dat_str_space_16);
                c_intercept_line(v7l);
                strcat(shm_scratch, dat_str_check_crypto_branch);
                v10f = 6;
                v11f = -2;
            }
        }
    }
    /* Score each plotter in play whose city is known: photo and organisation 1 each, here 2, a known role 5. */
    for (v5k = 0; v5k < shm_suspect_count; v5k++)
        if ((shm_suspects[v5k].flags & SUSPECT_CITY) != 0
            && (shm_suspects[v5k].role & 0x7fff)
               != 0) {
            v2j = 0;
            if (shm_suspects[v5k].alert_level < 0)
                continue;
            if ((shm_suspects[v5k].flags & SUSPECT_PHOTO) != 0)
                v2j++;
            if ((shm_suspects[v5k].flags & SUSPECT_ORG) != 0)
                v2j++;
            if ((shm_suspects[v5k].flags & SUSPECT_CITY) != 0
                && shm_suspects[v5k].city
                   == shm_case_city)
                v2j += 2;
            if ((shm_suspects[v5k].role_known & 0x7fff)
                != 0)
                v2j += 5;
            /* Keep the best; a Crypto lead already stands at 6. */
            if (v2j > v10f) {
                v11f = v5k;
                v10f = v2j;
            }
        }
    /* The advice is shown, not chosen from. */
    shm_menu_no_pick = 1;
    /* A suspect is the lead: show the dossier and say where to go after them. */
    if (v11f > -1) {
        c_dossier(v11f, 0, 0);
        strcpy(shm_scratch,
                   (shm_suspects[(unsigned) v11f].role_known
                    & 0x7fff) != 0 ? dat_str_max_we_ve_got : dat_str_max_i_suggest_check);
        /* In this very city: "He's (or she's) right here in <city>." */
        if (shm_suspects[v11f].city
            == shm_case_city) {
            strcat(shm_scratch,
                       (shm_suspects[v11f].visuals & 1) != 0
                       ? dat_str_he_2 : dat_str_she_3);
            strcat(shm_scratch, dat_str_s_right_here);
            strcat(shm_scratch,
                       shm_cities[shm_case_city].name);
            strcat(shm_scratch, dat_str_stop_space);
            /* The organisation known: advice by whether its building here is known, and the role. */
            if ((shm_suspects[v11f].flags & SUSPECT_ORG) != 0) {
                if (c_building_explore(shm_suspects[v11f].org,
                                    shm_case_city, 0) != -1)
#ifdef PORT_MODERN
                    c_show_prose(
                        shm_suspects[v11f].role_known
                        != 0 ? dat_str_advicea : dat_str_advice1, 32,
                        shm_orgs[shm_suspects[v11f].org].long_name, 0);
#else
                    c_show_prose(
                        shm_suspects[v11f].role_known
                        != 0 ? dat_str_advicea : dat_str_advice1, 32,
                        shm_orgs[shm_suspects[v11f].org].long_name);
#endif
                else
#ifdef PORT_MODERN
                    c_show_prose(dat_str_advice2, 32,
                                       shm_orgs[shm_suspects[v11f].org].long_name, 0);
#else
                    c_show_prose(dat_str_advice2, 32,
                                       shm_orgs[shm_suspects[v11f].org].long_name);
#endif
            /* Only a face or a name to go on. */
            } else if ((shm_suspects[v11f].flags & (SUSPECT_PHOTO | SUSPECT_NAME)) != 0)
#ifdef PORT_MODERN
                c_show_prose(dat_str_advice3, 32, (char *) 0, 0);
#else
                c_show_prose(dat_str_advice3, 32);
#endif
            /* Not even that. */
            else
#ifdef PORT_MODERN
                c_show_prose(dat_str_advice4, 32, (char *) 0, 0);
#else
                c_show_prose(dat_str_advice4, 32);
#endif
        /* Elsewhere: the advice names the suspect's city. */
        } else
#ifdef PORT_MODERN
            c_show_prose(dat_str_advice5, 32,
                               (rt_addr) shm_cities[shm_suspects[v11f].city].name, 0);
#else
            c_show_prose(dat_str_advice5, 32,
                               (rt_addr) shm_cities[shm_suspects[v11f].city].name);
#endif
        c_ask_menu(shm_scratch, 24, 104);
    }
    /* A message is the lead: the Crypto tip. */
    if (v11f == -2) {
        c_wrap_message(16);
        c_ask_menu(shm_scratch, 16, 81);
    }
    /* No lead at all: only the organisations and cities. */
    if (v11f == -1)
        c_ask_menu(shm_scratch, 16, 81);
}
