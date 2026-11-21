/* CMP_DAY.C -- advancing the clock, and what the world does meanwhile.
 */
#include "GAME.H"
#include "CASE.H"
#include "ADVICE.H"
#include "PORTING.H"
#include "LOADDISK.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "BLOCK.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "SAVELOAD.H"
#include "MESSAGE.H"
#include "HANDOVER.H"
#include "TAG.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* Advance the campaign clock and, past noon or midnight, let the world act:
 * alert decays, plot events come due, a suspect may go into hiding, and
 * message traffic and wiretaps are reported. The closing loop is dead code. */
INT c_advance_clock(INT minutes, LONG forced)
{
    INT v1i;    /* the city a departing suspect leaves for */
    INT v0j;    /* how many suspects have been tried */
    INT v2i;    /* the suspect being acted on */
    INT v3i;    /* the roster entry that suspect came from */
    INT v4i;    /* whoever already stands where he would go */
    INT v5i;    /* the day the clock started on */
    INT v7h;    /* the hour the clock started on */
    INT v6i;    /* the crime event picked to come due */
    INT v8h;    /* set once a departure has been reported */
    INT v9h;    /* declared and never used */
    INT v10a;   /* the entry being walked */
    INT v11a;   /* the event answering it, or how many came due */
    INT v13;    /* set once a bulletin has gone out */
    INT v12a;   /* the message, or the tap, being walked */
    INT v14;    /* set while no due event claims this suspect */
    INT v15;    /* declared and never used */
    INT v16;    /* how many destinations have been tried */
    INT v17;    /* declared and never used */
    INT v18;    /* the tap that covers the meeting */

    /* Move the clock on and show it. */
    v7h = asm_hour;
    v5i = asm_day;
    shm_clock_minutes += minutes;
    c_hook_repaint();
    c_wait_retraces(2);
    /* The world only acts when the clock passes noon or midnight, or a new day is forced. */
    if ((v7h >= 12 || asm_hour < 12)
        && v5i == asm_day && (INT) forced == 0)
        return;
    /* A new half-day of the case, and the cities' visit marks start over. */
    shm_case_tick++;
    for (v10a = 0; v10a < 16; v10a++)
        shm_cities[v10a].visited_cia = 0;
    /* Alert fades by a share that is smaller the harder the game, for each suspect at large and overall. */
    for (v2i = 0; v2i < shm_suspect_count; v2i++)
        if (shm_suspects[v2i].visuals != 0
            && shm_suspects[v2i].alert_level >= 0)
            shm_suspects[v2i].alert_level -=
                shm_suspects[v2i].alert_level
                / (shm_difficulty + 3);
    shm_global_alert_level -= shm_global_alert_level / (shm_difficulty + 3);
    /* Count the plot events ready to happen; in this first scan a jailbreak is only a chance. */
    v11a = 0;
    asm_jailbreak_target_suspect = -2;
    for (v10a = 0; v10a < shm_crime_event_count - 1; v10a++)
        if (c_case_due(v10a) != -1)
            v11a++;
    /* Once the case is under way, a half-day often passes quietly, less often the harder the game. */
    if (c_random_below(10) >= shm_difficulty + 4
        && shm_log_count > 5 && v11a != 0 && (INT) forced == 0)
        return;
    /* With few events ready, scan again, where a due jailbreak is certain, and note whether any is ready. */
    if (v11a <= shm_difficulty) {
        asm_jailbreak_target_suspect = -1;
        for (v10a = 0; v10a < shm_crime_event_count - 1; v10a++)
            if (c_case_due(v10a) != -1) {
                v11a = 1;
                break;
            }
    }
    /* Suspects may go into hiding: one, and then more only while the player knows nothing of who they are. */
    v13 = 0;
    for (;;) {
        /* Pick a suspect in a real role who is still at large and no jailbreak's target. */
        v0j = 0;
        do {
            v3i = c_random_below(shm_crime_role_count
                                  - (shm_difficulty << 2));
            v2i = shm_crime_roles[v3i].suspect;
            if (shm_suspects[v2i].alert_level >= 0
                && v2i != asm_jailbreak_target_suspect)
                break;
        } while (++v0j < 999);
        /* Not early in the case, and not from under the player's nose unless the player is waiting the time out. */
        if (v0j != 999 && shm_log_count > 8
            && (shm_suspects[v2i].city
                   != shm_case_city
                || shm_suspects[v2i].org
                   != shm_case_org
                || asm_auto_waiting != 0)) {
            /* A suspect with a plot event still to happen stays at work... */
            v14 = 1;
            for (v10a = 0; v10a < shm_crime_event_count; v10a++)
                if (shm_crime_roles[shm_crime_events[v10a].main_participant].suspect == v2i
                    && shm_crime_events[v10a].happen_tick == 999) {
                    v14 = 0;
                    break;
                }
            /* ...unless nothing is ready and no jailbreak is coming; else hide, told if the suspect is on file. */
            if ((v14 != 0 || (v11a == 0 && asm_jailbreak_target_suspect < 0))
                && (v13 == 0
                    || (shm_suspects[v2i].flags & SUSPECT_IDENTITY)
                       == 0)) {
                shm_suspects[v2i].alert_level = ALERT_HIDING;
                if (shm_suspects[v2i].flags != 0) {
                    strcpy(shm_scratch, dat_str_bulletin);
                    c_person_name(v2i);
                    strcat(shm_scratch, dat_str_has_gone_into_hiding);
                    c_print_message(dat_str_surveillance_team);
                }
                c_log_add(LOG_HIDING, v2i);
                v13 = 1;
                continue;
            }
        }
        break;
    }
    /* The case is over when no suspect is left at large and nothing can happen, or after 40000 minutes. */
    if ((v0j == 999 && v11a == 0) || shm_clock_minutes > 0x9c40) {
        /* Keep what is known of the mastermind for the next case, save, and go to FINAL. */
        shm_campaign.mastermind_flags = shm_suspects[0].flags;
        c_save_put(dat_str_env_sve_3);
        c_want_disk(1, (LONG) 1);
        c_hook_hand_back(UNSET_ARGS(0));
        COMM()->next_module = FINAL_CAMPAIGN_OVER;
        exit(UNSET_ARGS(0));
    }
    /* A forced new day only lets the world settle; no plot event happens. */
    if ((INT) forced != 0)
        return;
    /* Make one ready plot event happen, picked at random. */
    if (v11a != 0) {
        do {
            v6i = c_random_below(shm_crime_event_count - 1);
            v11a = c_case_due(v6i);
        } while (v11a == -1);
        /* Someone acting alone: it happens now, and the role starts to show up in scans. */
        if ((shm_crime_events[v6i].flags & CRIME_IN_USE) == 0) {
            shm_crime_events[v6i].happen_tick = shm_case_tick;
            if (shm_role_scan_states[shm_crime_events[v6i].main_participant].clue_visible_since == -1)
                shm_role_scan_states[shm_crime_events[v6i].main_participant].clue_visible_since
                    = shm_case_tick;
        /* With the other party out of play, an event so marked is passed as done at tick 0, not reported. */
        } else if ((shm_crime_events[v6i].flags & CRIME_UNKNOWN_10) != 0
                   && shm_suspects[shm_crime_roles[shm_crime_events[v11a].main_participant].suspect].alert_level < 0) {
            shm_crime_events[v6i].happen_tick = 0;
        /* The other half has already happened: this one is dated with it. */
        } else if (shm_crime_events[v11a].happen_tick != 999) {
            shm_crime_events[v6i].happen_tick = shm_crime_events[v11a].happen_tick;
            goto walk;
        /* Otherwise both halves happen now, and both roles start to show up in scans. */
        } else {
            shm_crime_events[v6i].happen_tick = shm_case_tick;
            if (shm_role_scan_states[shm_crime_events[v6i].main_participant].clue_visible_since == -1)
                shm_role_scan_states[shm_crime_events[v6i].main_participant].clue_visible_since
                    = shm_case_tick;
            shm_crime_events[v11a].happen_tick = shm_case_tick;
            if (shm_role_scan_states[shm_crime_events[v11a].main_participant].clue_visible_since == -1)
                shm_role_scan_states[shm_crime_events[v11a].main_participant].clue_visible_since
                    = shm_case_tick;
            /* Other events carrying the same message will never happen now. */
            for (v10a = 0; v10a < shm_crime_event_count; v10a++)
                if (shm_crime_events[v6i].message_id
                    == shm_crime_events[v10a].message_id
                    && v10a != v6i && v10a != v11a)
                    shm_crime_events[v10a].happen_tick = -1;
            /* One suspect cannot exchange with themself, so such a pair is cancelled. */
            if (shm_crime_roles[shm_crime_events[v6i].main_participant].suspect
                == shm_crime_roles[shm_crime_events[v11a].main_participant].suspect) {
                shm_crime_events[v6i].happen_tick = -1;
                shm_crime_events[v11a].happen_tick = -1;
            }
            goto walk;
        }
    }
walk:
    /* Every event that happened this half-day goes in the case log and may be reported. */
    for (v10a = 0; v10a < shm_crime_event_count; v10a++)
        if (shm_crime_events[v10a].happen_tick == shm_case_tick) {
            c_log_add(LOG_MESSAGE, v10a);
            v2i = shm_crime_roles[shm_crime_events[v10a].main_participant].suspect;
            for (v12a = 0; v12a < 4; v12a++) {
                /* An object handed over is now this suspect's... */
                if ((shm_crime_events[v10a].objects & CRIME_OBJECT_ADDED(v12a)) != 0) {
                    shm_crime_block[v12a].u2
                        = (char) v2i;
                    /* ...and on the two easiest levels INTERPOL may report it spotted in the suspect's city. */
                    if (c_random_below(2) >= shm_difficulty
                        && (shm_crime_events[v10a].flags & CRIME_BULLETIN) == 0
                        && shm_log_count > 5) {
                        strcpy(shm_scratch, dat_str_interpol_bulletin);
                        strcat(shm_scratch, shm_crime_block[v12a].name);
                        strcat(shm_scratch, dat_str_spotted);
                        strcat(shm_scratch,
                                   shm_cities[shm_suspects[v2i].city].name);
                        strcat(shm_scratch, dat_str_bang_nl_5);
                        c_print_message(dat_str_interpol);
                        c_log_add(LOG_BULLETIN,
                                        (v12a << 8)
                                        + shm_suspects[v2i].city);
                    }
                }
                /* An object destroyed is nobody's. */
                if ((shm_crime_events[v10a].objects & CRIME_OBJECT_DESTROYED(v12a)) != 0)
                    shm_crime_block[v12a].u2 = -1;
            }
            /* A news event is printed as its own text, and that is all it does. */
            if ((shm_crime_events[v10a].flags & CRIME_BULLETIN) != 0) {
                shm_scratch[0] = 0;
                c_say_event_text(v10a);
                c_print_message(&dat_str_empty_10);
                continue;
            }
            /* Satellites pick up a message sent, naming one end's city as activity there. */
            if ((shm_crime_events[v10a].flags & CRIME_KIND) == CRIME_MESSAGE
                && shm_log_count > 5) {
                strcpy(shm_scratch, dat_str_message_traffic);
                if (c_random_below(2) != 0) {
                    strcat(shm_scratch, dat_str_from_2);
                    strcat(shm_scratch,
                               shm_cities[shm_suspects[v2i].city].name);
                    shm_activity.city[shm_suspects[v2i].city]++;
                } else {
                    strcat(shm_scratch, dat_str_to);
                    strcat(shm_scratch,
                               shm_cities[shm_suspects[shm_crime_roles[CRIME_FAR_CELL(shm_crime_events[v10a])].suspect].city].name);
                    shm_activity.city[shm_suspects[shm_crime_roles[CRIME_FAR_CELL(shm_crime_events[v10a])].suspect].city]++;
                }
                strcat(shm_scratch, dat_str_dots_3);
                c_print_message(dat_str_satellite_intercept);
            }
            /* A double agent always tells; a tap on the suspect's building overhears in proportion to its level. */
            v18 = c_building_explore(shm_suspects[v2i].org,
                                  shm_suspects[v2i].city, 0);
            if (shm_suspects[v2i].alert_level == ALERT_TURNED
                || (v18 != -1
                    && shm_buildings[v18].wiretap_level
                       > c_random_below(50)))
                for (v12a = 0; v12a < shm_log_count; v12a++) {
                    if (shm_log[v12a].kind == LOG_MESSAGE
                        && shm_log[v12a].slot
                           == v10a
                        && shm_log[v12a].minute
                           == shm_clock_minutes) {
                        /* The intercept is known in full, and needs no decoding. */
                        shm_log[v12a].known |= 0xf;
                        *((char *) &shm_log[v12a].known + 1)
                            |= 0x80;
                        /* The double agent also gives away the other party's organisation, city and role. */
                        if (shm_suspects[v2i].alert_level
                            == ALERT_TURNED) {
                            strcpy(shm_scratch, dat_str_double_agent);
                            shm_suspects[shm_log[v12a].to].flags |= SUSPECT_ORG | SUSPECT_CITY;
                            shm_suspects[shm_log[v12a].to].role_known
                                |= 1 << CRIME_FAR_CELL_CHAR(shm_crime_events[v10a]);
                        } else
                            strcpy(shm_scratch, dat_str_wiretap_at);
                        /* Report where it was heard, who spoke, and the intercept. */
                        strcat(shm_scratch,
                                   shm_orgs[shm_suspects[v2i].org].long_name);
                        strcat(shm_scratch, dat_str_slash_4);
                        strcat(shm_scratch,
                                   shm_cities[shm_suspects[v2i].city].name);
                        strcat(shm_scratch, dat_str_reveals);
                        if (shm_suspects[v2i].alert_level == ALERT_TURNED)
                            strcat(shm_scratch,
                                       (shm_suspects[v2i].visuals
                                        & 1) != 0 ? dat_str_he : dat_str_she_2);
                        else {
                            c_person_name(v2i);
                            strcat(shm_scratch, dat_str_space_13);
                        }
                        c_intercept_line(v12a);
                        strcat(shm_scratch, dat_str_nl_5);
                        /* Meeting notes give away the other party's role; a double agent quotes any event. */
                        if ((shm_crime_events[v10a].flags & CRIME_KIND) == CRIME_MEETING) {
                            c_say_event_text(v10a);
                            shm_suspects[shm_log[v12a].to].role_known
                                |= shm_suspects[shm_log[v12a].to].role;
                        } else if (shm_suspects[v2i].alert_level
                                   == ALERT_TURNED)
                            c_say_event_text(v10a);
                        c_print_message(dat_str_empty_12);
                    }
                }
            /* A suspect on file by photo, coming home from a meeting elsewhere, is seen at the airport. */
            if ((shm_crime_events[v10a].flags & CRIME_KIND) == (CRIME_MEETING | CRIME_RECEIVED)
                && (shm_suspects[v2i].flags & SUSPECT_PHOTO) != 0)
                for (v12a = 0; v12a < shm_log_count; v12a++) {
                    if (shm_log[v12a].kind == LOG_MESSAGE
                        && shm_log[v12a].slot
                           == v10a
                        && shm_log[v12a].from_city
                           != shm_log[v12a].to_city) {
                        strcpy(shm_scratch, dat_str_from_3);
                        strcat(shm_scratch, shm_orgs[1].long_name);
                        strcat(shm_scratch, dat_str_slash_5);
                        strcat(shm_scratch,
                                   shm_cities[shm_log[v12a].from_city].name);
                        strcat(shm_scratch, dat_str_nl_6);
                        c_person_name(v2i);
                        strcat(shm_scratch, dat_str_has_just_returned_from);
                        strcat(shm_scratch,
                                   shm_cities[shm_log[v12a].to_city].name);
                        strcat(shm_scratch, dat_str_dot_nl_3);
                        c_print_message(dat_str_airport_surveillance);
                        /* The city of the meeting goes on the intercept's record. */
                        shm_log[v12a].known |= 9;
                    }
                }
        }
    /* Dead code: this loop never moves a suspect, as the tests below show. */
    /* Meant to move one wary suspect of a role marked 08, whose city the player knows, elsewhere. */
    v8h = 0;
    for (v10a = 0; v10a < shm_crime_role_count; v10a++)
        if (v8h == 0
            && (shm_crime_roles[v10a].flags & ROLE_UNKNOWN_08) != 0) {
        v2i = shm_crime_roles[v10a].suspect;
        if ((shm_suspects[v2i].flags & SUSPECT_CITY) != 0
            && shm_suspects[v2i].alert_level
               > c_random_below(128 / (shm_difficulty + 1))
            && shm_suspects[v2i].city
               != shm_case_city)
        /* Four tries at a city where the organisation is present. */
        for (v16 = 0; v16 < 4; v16++) {
            v1i = c_random_below(16);
            if (c_presence(v1i,
                                shm_suspects[v2i].org) != 0) {
            /* No bits: answers -1, or a record whose evidence is nonzero. */
            v4i = c_evidence_unlock(shm_suspects[v2i].org, v1i, 0,
                                            LONG_LIT(0));
            /* Only -1 could pass; its role is "as" in "One moment please". */
            if (shm_suspects[v4i].role == 0
                && shm_suspects[v4i].flags == 0) {
            ASSERT_SUSPECT_INDEX(v4i);
            /* Airport surveillance would report the departure, and the case log record it. */
            strcpy(shm_scratch, &dat_str_empty_13);
            c_person_name(v2i);
            strcat(shm_scratch, dat_str_seems_have_departed);
            strcat(shm_scratch,
                       shm_cities[shm_suspects[v2i].city].name);
            strcat(shm_scratch, dat_str_dot_nl_4);
            c_print_message(dat_str_airport_surveillance_2);
            c_log_add(LOG_DEPARTED, (v2i << 8)
                               + shm_suspects[v2i].city);
            /* Then the move: the player loses the city, and the suspect calms by half. */
            c_suspect_release(v4i);
            shm_suspects[v2i].city = v1i;
            c_forget(v2i, SUSPECT_CITY);
            shm_suspects[v2i].alert_level /= 2;
            v8h = 1;
            break;
            }
            }
        }
        }
}
