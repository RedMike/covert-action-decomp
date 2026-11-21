/* CASE.C -- the case: suspects and their evidence, clues, buildings, dossiers
 * and intercepts.
 */
#include "TAC.H"
#include "SPRITES.H"
#include "CASE.H"
#include "RANDOM.H"
#include "CITY.H"
#include "MENU.H"
#include "PANEL.H"
#include "PROMPT.H"
#include "TILES.H"
#include "RADAR.H"
#include "FACES.H"
#include "BLOCK.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "CLUEFACT.H"

/* shared_include_start: ../../../../shared/c/SUSPECT-SCAN.C -- generated */
/* SUSPECT-SCAN.C -- c_suspect_scan, what watching a place turns up.
 */

/* Scan every suspect for the time `arg3` spent watching organisation `arg1` in
 * city `arg2`; answer how many clues and pieces of evidence turned up. With
 * `arg4`, a hint is given if nothing did.
 */
INT c_suspect_scan(INT arg1, INT arg2, INT arg3, LONG arg4)
{
    INT v1i;    /* suspect being stepped */
    INT v0j;
    INT v2i;    /* how many of the role's clues are known */
    INT v4h;    /* how far the suspect's organisation is from arg1 */
    INT v3i;    /* the suspect a message is sent to */
    INT v5h;
    INT v7g;    /* how many clues and pieces of evidence, and the result */
    INT v6h;    /* crime event the message belongs to */
    INT v8g;    /* the suspect's rate of progress */
    INT v10o;   /* the suspect's organisation */
    INT v9g;    /* how far the suspect's city is from arg2 */
    INT v11o;   /* the bit the message learns */
    INT v13n;   /* the suspect's city */
    INT v12o;   /* role being stepped, then a threshold rising per message */
    INT v14n;   /* scratch */
    INT v16m;   /* a suspect at no distance from arg1 and arg2, if any */
    INT v15n;   /* message being looked at */
    INT v17m;   /* the suspect's score after the step */
    INT v19l;   /* what the score rate is divided by */
    INT v18m;   /* the evidence the suspect ends the step with */
    INT v20e;   /* the suspect a message is sent to */
    INT v22d;   /* what the clue visibility gain is divided by */
    INT v21e;
    INT v23d;   /* whether the hint's place is worth the trip */

    v7g = 0;
    shm_wire_clue_source = (INT) arg4;
    if (arg3 <= 0)
        return 0;
    v0j = 0;
    v5h = 9999;
    v21e = -1;
    v16m = -1;
    for (v1i = 0; v1i < shm_suspect_count; v1i++) {
        if (shm_suspects[v1i].visuals == 0)
            continue;
        v10o = shm_suspects[v1i].org;
        v13n = shm_suspects[v1i].city;
        v4h = c_packed_distance(
            shm_orgs[arg1].where,
            shm_orgs[v10o].where);
        v9g = c_packed_distance(
            shm_cities[arg2].where,
            shm_cities[v13n].where);
        if (v4h == 0 && v9g == 0)
            v16m = v1i;
        v19l = ((LONG) ((v4h + 2) * (v9g + 2)) << 8) / (arg3 + 1);
        v22d = ((LONG) ((v4h + 3) * (v9g + 6)) << 6) / (arg3 + 1);
        v8g = 10000 / (shm_difficulty + 2) / v19l;
        shm_suspects[v1i].score +=
            (LONG) v8g * v8g
            / (shm_suspects[v1i].score / 2
               + v8g + 1);
        v17m = shm_suspects[v1i].score;
        v19l = 2500 / (v17m + 1);
        for (v12o = 0; v12o < shm_crime_role_count; v12o++)
            if (v1i == shm_crime_roles[v12o].suspect
                && shm_role_scan_states[v12o].clue_visible_since
                   <= shm_case_tick
                && shm_role_scan_states[v12o].clue_visible_since != -1) {
                shm_role_scan_states[v12o].clue_visibility +=
                    5000 / (shm_difficulty + 3) / v22d;
                v18m = shm_crime_roles[v12o].clues_known;
                v2i = shd_scan_counts[v18m & 0x1f];
                while (shm_role_scan_states[v12o].clue_visibility
                           * (shm_crime_roles[v12o].exposure + 2)
                       > ((v2i + 2) * (v2i + 2)) << 5
                       && (shm_crime_roles[v12o].clues_known & 0x1f)
                          != 0x1f) {
                    v7g += c_cell_reveal(v12o, arg1, arg2);
                    v2i = shd_scan_counts
                        [shm_crime_roles[v12o].clues_known & 0x1f];
                }
            }
        if (shm_suspects[v1i].flags == 0
            && v4h != 0 && v9g != 0)
            continue;
        v18m = shm_suspects[v1i].flags;
        v12o = 2;
        for (v15n = 0; v15n < shm_log_count; v15n++)
            if (shm_log[v15n].from == v1i) {
                v6h = shm_log[v15n].slot;
                while (shm_crime_roles[shm_crime_events[v6h].main_participant].exposure
                       * shm_suspects[v1i].score / 0x60
                       > shd_scan_counts
                             [shm_log[v15n].known & 0xf] * 2
                         + v12o
                       && (shm_log[v15n].known & 0xf)
                          != 0xf) {
                    v11o = 1 << c_random_below(4);
                    /* An `if`, not a `continue`, as shipped. */
                    if (!(v11o & shm_log[v15n].known)) {
                        c_dossier(v1i, 0, 0);
                        shm_scratch[0] = 0;
                        if (shm_crime_events[v6h].flags & CRIME_MESSAGE)
                            strcpy(shm_scratch, shd_str_coded_message);
                        if (shm_crime_events[v6h].flags & CRIME_MEETING)
                            strcpy(shm_scratch, shd_str_meeting_notes);
                        strcat(shm_scratch,
                                   shm_log[v15n].known == 0
                                   ? shd_str_new_information : shd_str_additional_information);
                        c_person_name(v1i);
                        strcat(shm_scratch, shd_str_space_after_name);
                        c_intercept_line(v15n);
                        strcat(shm_scratch, shd_str_dots);
                            /* A `goto`, not an `if` block, as shipped. */
                        if (!(v11o & 1))
                            goto undated;
                        strcat(shm_scratch, shd_str_on);
                        strcat(shm_scratch,
                                   shd_month_names[shm_campaign.cases % 0xc]);
                        strcat(shm_scratch, shd_str_space_after_month);
                        strcat(shm_scratch,
                                   itoa(shm_log[v15n].minute / 0x5a0 + 1,
                                            shm_clue_digits, 10));
undated:
                        if (shm_crime_events[v6h].flags & CRIME_IN_USE) {
                            v20e = shm_log[v15n].to;
                            if (v11o & 2) {
                                shm_suspects[v20e].flags |= SUSPECT_NAME;
                                c_person_name(v20e);
                            }
                            if (v11o & 4) {
                                strcat(shm_scratch, shd_str_of_the);
                                strcat(shm_scratch,
                                           shm_orgs[shm_suspects[v20e].org].long_name);
                            }
                            if (v11o & 8) {
                                strcat(shm_scratch, shd_str_in);
                                strcat(shm_scratch,
                                           shm_cities[shm_log[v15n].to_city].name);
                            }
                            strcat(shm_scratch, shd_str_newline);
                            c_menu_box(0x10, 0x60, 0x108, 0x30,
                                               shm_cga != 0 ? 4 : 3);
                            shd_screen->bg_pen = 3;
                            c_draw_message(0x20, 0x14, 0x64, 0xb);
                            c_wait_key();
                            shm_log[v15n].known |= v11o;
                            c_dossier(v1i, 0, 0);
                            c_wait_key();
                            shm_suspects[v1i].flags |= SUSPECT_PARTICIPANT;
                        } else {
                            shm_log[v15n].known |= 0xe;
                            c_wait_key();
                        }
                        shm_log[v15n].known |= v11o;
                        if (!(shm_suspects[v1i].role_known
                              & (1 << shm_crime_events[v6h].main_participant))
                            && ((shm_difficulty < 1 && v4h + v9g == 0
                                 && (shm_log[v15n].known & 0xf)
                                    == 0xf)
                                || !(shm_crime_events[v6h].flags & CRIME_IN_USE))) {
                            shm_suspects[v1i].role_known |=
                                1 << shm_crime_events[v6h].main_participant;
                            v18m |= SUSPECT_PARTICIPANT;
                            shm_suspects[v1i].flags &= ~SUSPECT_PARTICIPANT;
                            shm_log[v15n].known |= 0xf;
                        }
                    }
                }
                v12o++;
                if ((shm_crime_events[v6h].flags & CRIME_KIND)
                    && (shm_log[v15n].known & 0xe)) {
                    v3i = shm_log[v15n].to;
                    c_evidence_unlock(shm_suspects[v3i].org,
                                       shm_suspects[v3i].city,
                                       shm_log[v15n].known & 6,
                                                 LONG_LIT(0));
                    if (shm_log[v15n].to_city
                        == shm_suspects[v3i].city)
                        c_evidence_unlock(shm_suspects[v3i].org,
                                           shm_suspects[v3i].city,
                                           shm_log[v15n].known & 8,
                                                     LONG_LIT(0));
                }
            }
        while (v18m != 0
               && (shd_scan_counts
                       [(v18m & (SUSPECT_IDENTITY | SUSPECT_BACKGROUND)) >> 8]
                   + shd_scan_counts[v18m & SUSPECT_IDENTITY]) * 0x19
                  < shm_suspects[v1i].score
               && (v18m & (SUSPECT_IDENTITY | SUSPECT_BACKGROUND))
                  != (SUSPECT_IDENTITY | SUSPECT_BACKGROUND)) {
            if (arg1 == v10o && !(v18m & SUSPECT_ORG)) {
                v18m |= SUSPECT_ORG;
                break;
            }
            if (arg2 == v13n && !(v18m & SUSPECT_CITY)) {
                v18m |= SUSPECT_CITY;
                break;
            }
            do
                v14n = 1 << c_random_below(0xc);
            while (v14n & v18m & (SUSPECT_IDENTITY | SUSPECT_BACKGROUND)
                   || !(v14n & (SUSPECT_IDENTITY | SUSPECT_BACKGROUND)));
            v18m |= v14n;
        }
        if (shm_suspects[v1i].flags != v18m) {
            c_evidence_unlock(v10o, v13n, v18m, LONG_LIT(1));
            v5h = 0;
            v21e = -1;
            v7g++;
        }
    }
    if (v7g == 0 && (INT) arg4 != 0) {
        strcpy(shm_scratch, shd_str_empty_watch);
        v1i = shm_crime_roles[c_random_below(shm_crime_role_count)].suspect;
        shm_menu_face = -1;
        switch (c_random_below(8 - shm_difficulty)) {
        case 0:
            strcpy(shm_scratch,
                       shm_cities[shm_suspects[v1i].city].name);
            shm_activity.city[*(UNSIGNED_INT *) &shm_suspects[v1i].city]++;
            break;
        case 1:
            strcpy(shm_scratch,
                       shm_orgs[shm_suspects[v1i].org].long_name);
            shm_activity.org[*(UNSIGNED_INT *) &shm_suspects[v1i].org]++;
            shm_orgs[shm_suspects[v1i].org].known |= 1;
            break;
        case 2:
            strcpy(shm_scratch, shd_str_space_face);
            shm_menu_face =
                shm_suspects[v1i].visuals;
            break;
        case 3:
            v14n = shm_suspects[v1i].flags;
            shm_suspects[v1i].flags |= SUSPECT_NAME;
            shm_scratch[0] = 0;
            c_person_name(v1i);
            shm_suspects[v1i].flags = v14n;
            break;
        case 4:
        case 6:
            v10o = shm_case_org;
            v13n = shm_suspects[shm_crime_roles[c_random_below(shm_crime_role_count)].suspect].city;
            goto news;
        case 5:
        case 7:
            v10o = shm_suspects[shm_crime_roles[c_random_below(shm_crime_role_count)].suspect].org;
            v13n = shm_case_city;
news:
            v23d = c_worth_the_trip(shm_case_org, v10o, v13n);
            if (v23d != 0
                && !(shm_cities[v13n].known_orgs
                     & (1 << v10o))
                && c_presence(v13n, v10o) != 0) {
                shm_cities[v13n].known_orgs |= 1 << v10o;
                c_building_explore(v10o, v13n, 0xc);
                shm_orgs[v10o].known |= 1;
                strcpy(shm_scratch, shm_orgs[v10o].long_name);
                c_say_presence(v13n, v10o);
                strcat(shm_scratch, shd_str_in_2);
                strcat(shm_scratch, shm_cities[v13n].name);
                shm_menu_face = -2;
            } else {
                shm_scratch[0] = 0;
            }
            break;
        }
        if (shm_scratch[0] != 0) {
            c_hook_message();
            c_wait_key();
        }
    }
    return v7g;
}
/* shared_include_end: ../../../../shared/c/SUSPECT-SCAN.C */

/* shared_include_start: ../../../../shared/c/EVIDENCE-UNLOCK.C -- generated */
/* EVIDENCE-UNLOCK.C -- c_evidence_unlock, adding evidence about a suspect.
 */

/* Add evidence `bits` about the suspect of `org` in `city`, making a record if
 * there is none, and answer it or -1; with `show` the new fields are reported.
 */
INT c_evidence_unlock(INT org, INT city, INT bits, LONG show)
{
    INT slot;
    INT keep;
    INT step;
    INT held;

    for (slot = 0; slot < shm_suspect_count; slot++)
        if (shm_suspects[slot].org == org
            && shm_suspects[slot].city == city) {
            held = shm_suspects[slot].flags;
            if ((shm_suspects[slot].flags |= bits)
                != 0) {
tell:
                if ((INT) show != 0)
                    c_report_new_fields(slot, held);
                return slot;
            }
            return -1;
        }
    do
        slot = c_random_below(0x3f) + 1;
    while (shm_suspects[slot].visuals != 0);
    if (org == shm_campaign.mastermind_org && city == shm_campaign.mastermind_city) {
        slot = 0;
        bits |= shm_campaign.mastermind_flags;
    }
    if (bits == 0)
        return -1;
    held = shm_suspects[slot].flags;
    shm_suspects[slot].org = org;
    shm_suspects[slot].city = city;
    shm_suspects[slot].flags = bits;
    shm_suspects[slot].role = 0;
    shm_suspects[slot].role_known = 0;
    do {
        keep = 1;
        shm_suspects[slot].visuals =
            c_random_below(0x7fff);
        for (step = 0; step < shm_suspect_count; step++)
            /* `==` binds before `&`: only a face of 3fh counts, as shipped. */
            if ((shm_suspects[slot].visuals
                 & (0x3f == shm_suspects[step].visuals)
                 & 0x3f)
                && slot != step)
                keep = 0;
    } while (keep == 0);
    goto tell;
}
/* shared_include_end: ../../../../shared/c/EVIDENCE-UNLOCK.C */

/* shared_include_start: ../../../../shared/c/SUSPECT-RELEASE.C -- generated */
/* SUSPECT-RELEASE.C -- c_suspect_release, freeing a suspect record nothing holds.
 */

/* Free suspect record `slot` unless a crime role still holds it: a face of
 * zero marks it free.
 */
void c_suspect_release(INT slot)
{
    if (shm_suspects[slot].role & 0x7fff)
        goto held;
    shm_suspects[slot].visuals = 0;
    shm_suspects[slot].org = -1;
    shm_suspects[slot].city = -1;
    shm_suspects[slot].flags = 0;
held:
    ;
}
/* shared_include_end: ../../../../shared/c/SUSPECT-RELEASE.C */

/* shared_include_start: ../../../../shared/c/REPORT-FIELDS.C -- generated */
/* REPORT-FIELDS.C -- c_report_new_fields, announcing new evidence.
 */

/* Announce the evidence just added on suspect `who`: one message per newly set
 * bit. `flags` is the word before the evidence.
 */
UNSIGNED_INT c_report_new_fields(INT who, UNSIGNED_INT flags)
{
    INT picked;   /* the bits still to be reported */
    INT gained;   /* every bit the suspect ends up with */

    gained = shm_suspects[who].flags;
    shm_suspects[who].flags = flags;
    if (gained == flags)
        return flags;
    do {
        c_dossier(who, 0, 0);
        shm_menu_draw_only = 0;
        gained |= shm_suspects[who].flags;
        picked = gained
                 ^ shm_suspects[who].flags;
        if (picked & SUSPECT_PARTICIPANT) {
            shm_suspects[who].flags |= SUSPECT_PARTICIPANT;
            strcpy(shm_scratch, shd_str_empty_identified);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_identified_as);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_NAME) {
            strcpy(shm_scratch, (char *) &shd_str_empty_positively);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_positively);
            shm_suspects[who].flags |= SUSPECT_NAME;
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_2);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_PHOTO) {
            shm_suspects[who].flags |= SUSPECT_PHOTO;
            strcpy(shm_scratch, shd_str_we_have_acquired);
            c_person_name(who);
            strcat(shm_scratch, shd_str_stop);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_CITY) {
            shm_suspects[who].flags |= SUSPECT_CITY;
            strcpy(shm_scratch, shd_str_empty_spotted);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_spotted);
            strcat(shm_scratch,
                       shm_cities[shm_suspects[who].city].name);
            strcat(shm_scratch, shd_str_newline_3);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
            shm_activity.city[shm_suspects[who].city]++;
        } else if (picked & SUSPECT_ORG) {
            shm_suspects[who].flags |= SUSPECT_ORG;
            strcpy(shm_scratch, shd_str_empty_org);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_identified_as_org);
            strcat(shm_scratch,
                       shm_orgs[shm_suspects[who].org].long_name);
            strcat(shm_scratch, shd_str_newline_4);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
            shm_orgs[shm_suspects[who].org].known |= 1;
            shm_activity.org[shm_suspects[who].org]++;
        } else if (picked & SUSPECT_MORE_INFO) {
            shm_suspects[who].flags |= SUSPECT_MORE_INFO;
            strcpy(shm_scratch, shd_str_we_have_obtained);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_5);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RANK) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RANK >> 8;
            strcpy(shm_scratch, shd_str_we_have_determined_rank);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_6);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RECRUITED_IN) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RECRUITED_IN >> 8;
            strcpy(shm_scratch, shd_str_we_found_recruiting);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_7);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RECRUITED_BY) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RECRUITED_BY >> 8;
            strcpy(shm_scratch, shd_str_we_found_recruiting_2);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_8);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        continue;
    }
    } while (shm_suspects[who].flags != gained);
    c_dossier(who, 0, 0);
    return c_wait_key();
}
/* shared_include_end: ../../../../shared/c/REPORT-FIELDS.C */

/* shared_include_start: ../../../../shared/c/WAIT-KEY.C -- generated */
/* WAIT-KEY.C -- c_wait_key, waiting for a key or a joystick button.
 */

/* Wait for a key, or either joystick button when the stick is on, then for
 * everything to be let go; answer the key's menu code, or 1 for a button.
 */
INT c_wait_key(void)
{
    INT input;   /* the key, or 1 for a button, and -1 until one arrives */

    input = -1;
    while (drv_jump_keyboard_empty() != 0 && input == -1) {
        if (shm_options & OPT_JOYSTICK) {
            if (c_joystick_button(0) != 0 || c_joystick_button(1) != 0)
                input = 1;
        }
    }
    if (input == -1)
        input = c_menu_key();
    c_wait_for_release();
    return input;
}
/* shared_include_end: ../../../../shared/c/WAIT-KEY.C */

/* shared_include_start: ../../../../shared/c/SUSPECT-RESERVE.C -- generated */
/* SUSPECT-RESERVE.C -- c_suspect_reserve, finding or making a suspect record.
 */

/* Find the suspect record for `org` in `city` and OR `bits` into its roles, or
 * with nonzero `bits` make one; answer the record, or -1. The mastermind takes
 * slot 0.
 */
INT c_suspect_reserve(INT org, INT city, INT bits)
{
    INT cell;   /* the record being looked at, then the one chosen */

    for (cell = 0; cell < shm_suspect_count; cell++) {
        if (shm_suspects[cell].org == org
            && shm_suspects[cell].city
                   == city) {
            shm_suspects[cell].role |= bits;
            return cell;
        }
    }
    do {
        cell = c_random_below(0x40);
    } while (shm_suspects[cell].visuals != 0
             || cell == 0);
    if (org == shm_campaign.mastermind_org && city == shm_campaign.mastermind_city)
        cell = 0;
    if (bits != 0) {
        shm_suspects[cell].org = org;
        shm_suspects[cell].city = city;
        shm_suspects[cell].flags =
            cell != 0 ? 0 : shm_campaign.mastermind_flags;
        shm_suspects[cell].role = bits;
        shm_suspects[cell].role_known = 0;
        shm_suspects[cell].score = 0;
        if (cell != 0) {
            shm_suspects[cell].visuals =
                c_random_below(0x7ffe) + 1;
            if (c_random_below(3) == 0)
                shm_suspects[cell].visuals |= 1;
        } else {
            shm_suspects[cell].visuals =
                shm_campaign.mastermind_visuals;
        }
        shm_suspects[cell].alert_level = 0;
        return cell;
    }
    return -1;
}
/* shared_include_end: ../../../../shared/c/SUSPECT-RESERVE.C */

/* shared_include_start: ../../../../shared/c/BUILDING-EXPLORE.C -- generated */
/* BUILDING-EXPLORE.C -- c_building_explore, learning about a building.
 */

/* Find or make the building record for `org` in `city`, fold in
 * `identity_flags` and answer the record, or -1 if it is left with no flags.
 */
INT c_building_explore(INT org, INT city, UNSIGNED_INT identity_flags)
{
    INT cell;   /* the record being looked at */

    if (identity_flags != 0)
        shm_cities[city].known_orgs |= 1 << org;
    for (cell = 0; cell < shm_building_count; cell++) {
        if (shm_buildings[cell].org == org
            && shm_buildings[cell].city
                   == city) {
            if ((shm_buildings[cell].identity_flags
                    |= identity_flags) != 0)
                return cell;
            return -1;
        }
    }
    if (identity_flags == 0)
        return -1;
    shm_buildings[shm_building_count].org = org;
    shm_buildings[shm_building_count].city = city;
    shm_buildings[shm_building_count].identity_flags = identity_flags;
    shm_buildings[shm_building_count].wiretap_level = 0;
    shm_buildings[shm_building_count].tac_rooms_explored = 0;
    shm_building_count++;
    return shm_building_count - 1;
}
/* shared_include_end: ../../../../shared/c/BUILDING-EXPLORE.C */

/* shared_include_start: ../../../../shared/c/BUILDING-FORGET.C -- generated */
/* BUILDING-FORGET.C -- c_building_forget, forgetting a known building.
 */

/* Forget the building record for `org` in `city` and the city's known_orgs
 * bit; the record keeps its organisation and city.
 */
void c_building_forget(INT org, INT city)
{
    INT cell;   /* the record being looked at */

    for (cell = 0; cell < shm_building_count; cell++) {
        if (shm_buildings[cell].org == org
            && shm_buildings[cell].city
                   == city) {
            shm_buildings[cell].identity_flags = 0;
            shm_buildings[cell].tac_rooms_explored = 0;
            shm_buildings[cell].wiretap_level = 0;
            shm_cities[city].known_orgs &=
                ~(1 << org);
            break;
        }
    }
}
/* shared_include_end: ../../../../shared/c/BUILDING-FORGET.C */

/* shared_include_start: ../../../../shared/c/CELL-REVEAL.C -- generated */
/* CELL-REVEAL.C -- c_cell_reveal, turning up a new fact about a crime role.
 */

/* File a random fact crime role `chip` has not yet given as a clue from
 * organisation `a` in city `b`; answer 0 if all five are known.
 */
INT c_cell_reveal(INT chip, INT a, INT b)
{
    UNSIGNED_INT chosen;   /* the bit for the fact rolled */

    if ((shm_crime_roles[chip].clues_known & 0x1f) != 0x1f) {
        do {
            chosen = 1 << c_random_below(5);
            if (shm_difficulty == 0
                && (shm_crime_roles[chip].clues_known & 0x10) == 0)
                chosen = 0x10;
            if (shm_crime_roles[chip].clue_type == 2
                && shm_difficulty < 2
                && (shm_crime_roles[chip].clues_known & 8) == 0)
                chosen = 8;
        } while ((shm_crime_roles[chip].clues_known
                  & chosen) != 0);
        c_clue_record(a, b, chip, chosen);
        return 1;
    }
    return 0;
}
/* shared_include_end: ../../../../shared/c/CELL-REVEAL.C */

/* shared_include_start: ../../../../shared/c/CLUE-CLOSE-GAP.C -- generated */
/* CLUE-CLOSE-GAP.C -- c_clue_close_gap, taking one clue out of the list.
 */

/* Slide the clue list down over the record at `from`, as far as the first free
 * record, whose role is -1.
 */
void c_clue_close_gap(INT from)
{
    INT slot;   /* the record being moved into */

    for (slot = from; slot < 0x4f; slot++) {
        memcpy((char *) &shm_clues_shown[slot],
                   (char *) &shm_clues_shown[slot + 1], 0xc);
        if (shm_clues_shown[slot].role == -1) {
            shm_clues_shown[slot].org = -1;
            shm_clues_shown[slot].city = -1;
            break;
        }
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-CLOSE-GAP.C */

/* shared_include_start: ../../../../shared/c/CLUE-RECORD.C -- generated */
/* CLUE-RECORD.C -- c_clue_record, filing a new clue and showing it.
 */

/* File fact `bit` about crime role `cell`, from organisation `org` in `city`,
 * in the first free clue record unless already given, then show it with the
 * records sharing its text.
 */
UNSIGNED_INT c_clue_record(INT org, INT city, INT cell, INT bit)
{
    INT phase;
    INT inert;
    INT stray;
    INT pad;
    INT spot;
    INT pad2;
    INT line;
    INT scrap;
    INT into;
    INT match;
    INT shown;

    if ((shm_crime_roles[cell].clues_known & bit) == 0) {
        for (into = 0; into < 0x50; into++)
            if (shm_clues_shown[into].role == -1) {
            shm_clues_shown[into].org = org;
            shm_clues_shown[into].city = city;
            shm_clues_shown[into].role = cell;
            if (bit > 0x1f)
                bit >>= 5;
            shm_clues_shown[into].subject =
                c_clue_about(into, bit);
            shm_clues_shown[into].text =
                c_clue_text(cell, 0);
            shm_crime_roles[cell].clues_known |= bit;
            c_page_frame(shd_str_clue, 9);
            shd_screen->bg_pen = 0xf;
            strcpy(shm_scratch, &shd_str_source_2);
            strcat(shm_scratch, shm_orgs[shm_clues_shown[into].org].long_name);
            strcat(shm_scratch, shd_str_slash_source);
            strcat(shm_scratch, shm_cities[shm_clues_shown[into].city].name);
            strcat(shm_scratch, shd_str_newline_9);
            c_clue_line_full(into);
            if (shm_clues_shown[into].org > 1)
                shm_clue_method = shm_wire_clue_source == 1 ? 1 : 0;
            strcat(shm_scratch, shd_str_method_stop);
            strcat(shm_scratch, (char *) shd_clue_source[shm_clue_method]);
            c_draw_message(0x1f, 0x10, 0x11, 5);
            if (bit == 1) {
                c_draw_face_panel(shm_menu_face, 0x108, 0x12);
                c_draw_sprite(SPRITE_PAPERCLIP, 0x12b, 0x2e);
            } else
                c_draw_sprite(shm_clue_method + SPRITE_CLUE_SOURCE, 0x110,
                              0x10);
            c_write_text_trimmed(&shd_str_related_2, 0x10, 0x42, 5);
            line = 0x4c;
            shown = 0;
            spot = 0x49;
            for (phase = 0; phase < 2; phase++)
                for (match = 0; match < 0x50; match++) {
                    if (shm_clues_shown[match].role
                        == -1)
                        continue;
                    if (into == match)
                        continue;
                    if (line > 0xb4)
                        break;
                    if (!((phase != 0
                           && shm_clues_shown[into].subject
                              == shm_clues_shown[match].subject)
                          || (phase == 0
                              && shm_clues_shown[into].text
                                 == shm_clues_shown[match].text)))
                        continue;
                    shm_scratch[0] = 0;
                    pad = c_random_below(0xc) + 4;
                    c_text_panel(pad, line - 2);
                    if (shm_clues_shown[match].subject
                        >> 8 == 0x10)
                        c_clue_line_full(match);
                    else
                        c_clue_line(match);
                    strcat(shm_scratch, shd_str_newline_10);
                    shown = 1;
                    line = c_draw_message(0x20, pad + 8, line, 0);
                    line += 4;
                    if (shm_clues_shown[match].subject
                        >> 8 == 1) {
                        c_draw_face_panel(
                            shm_suspects[shm_crime_roles[shm_clues_shown[match].role].suspect].visuals,
                            0x108, c_clamp(spot, 0, 0x96));
                        c_draw_sprite(SPRITE_PAPERCLIP, 0x12b,
                                        c_clamp(spot + 0x18, 0,
                                                           0xb0));
                        spot += 0x28;
                    }
                }
            if (shown == 0)
                c_write_text_trimmed(shd_str_none, 0x10, 0x48, 5);
            c_wait_key();
            shm_menu_face = -1;
            into = 999;
        }
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-RECORD.C */

/* shared_include_start: ../../../../shared/c/CLUE-ABOUT.C -- generated */
/* CLUE-ABOUT.C -- c_clue_about, packing what a clue says into one word.
 */

/* Pack fact `what` of clue record `slot` into a word: the fact in the high
 * byte and what it names in the low one. Naming an organisation or city counts
 * it in shm_activity.
 */
INT c_clue_about(INT slot, INT what)
{
    INT suspect;   /* the suspect filling the clue's role */

    suspect = shm_crime_roles[shm_clues_shown[slot].role].suspect;
    switch (what) {
    case CLUE_CITY:
        shm_activity.city[shm_suspects[suspect].city]++;
        return what * 0x100
               + shm_suspects[suspect].city;

    case CLUE_ORG:
        shm_activity.org[shm_suspects[suspect].org]++;
        shm_orgs[shm_suspects[suspect].org].known |= 1;
        strcat(shm_scratch,
                   shm_orgs[shm_suspects[suspect].org].long_name);
        return what * 0x100
               + shm_suspects[suspect].org;

    case CLUE_FACE:
        return what * 0x100 + suspect;

    case CLUE_NAME:
        return what * 0x100 + suspect;

    case CLUE_ROLE:
        return what * 0x100
               + shm_clues_shown[slot].role;

    }
}
/* shared_include_end: ../../../../shared/c/CLUE-ABOUT.C */

/* shared_include_start: ../../../../shared/c/CLUE-TEXT.C -- generated */
/* CLUE-TEXT.C -- c_clue_text, the word saying what a role's clue reads as.
 */

/* The word a clue about crime role `cell` reads as: a clue type in the high
 * byte and the role's clue_id in the low one, halved unless `full`.
 */
INT c_clue_text(INT cell, INT full)
{
    INT num;
    INT shade;
    char key[8];

    shade = *(unsigned char *) &shm_crime_roles[cell].clue_id;
    if (full != 0)
        shade &= 0x7f;
    else
        shade >>= 1;
    if (shm_crime_role_count - shm_difficulty * 4 > cell)
        return shm_crime_roles[cell].clue_type * 256
               + shade;
    num = shm_suspects[shm_crime_roles[cell].suspect].visuals;
    strcpy(key, shd_key_clue);
    key[5] += num % 6;
    key[3] += (num >> 3) % 4;
    num = strlen(shm_scratch);
    c_say_block_with(shd_str_clues_txt, key, shd_clue_keys,
                       shd_subst_values, 5);
    (shm_scratch)[num] = 0;
    return (*((char *) &shm_scratch[1] + num) & 0xf) * 256 + shade;
}
/* shared_include_end: ../../../../shared/c/CLUE-TEXT.C */

/* shared_include_start: ../../../../shared/c/CLUE-LINE.C -- generated */
/* CLUE-LINE.C -- c_clue_line, a clue record as an assembled phrase.
 */

/* Append clue record `nth` to shm_scratch as a phrase: the clue's thing, the
 * joining words and the subject, a half left out where its word is -1.
 */
void c_clue_line(INT nth)
{
    if (shm_clues_shown[nth].text != -1) {
        c_clue_thing(shm_clues_shown[nth].text);
        strcat(shm_scratch,
                   (char *) shd_clue_phrases[
                       c_clue_phrase(
                           shm_clues_shown[nth].subject,
                           shm_clues_shown[nth].text)]);
    }
    if (shm_clues_shown[nth].subject != -1) {
        c_clue_subject(nth,
                        shm_clues_shown[nth].subject);
        strcat(shm_scratch, shd_str_period);
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-LINE.C */

/* shared_include_start: ../../../../shared/c/CLUE-PHRASE.C -- generated */
/* CLUE-PHRASE.C -- c_clue_phrase, choosing the words that join up a clue.
 */

/* Which of the forty phrases in shd_clue_phrases joins a clue to its subject:
 * the run of five by the clue type in `kind`, the place in it by the fact bit
 * in `about`.
 */
INT c_clue_phrase(INT about, INT kind)
{
    INT pick;
    INT step;

    pick = ((kind >> 8) & 7) * 5;
    for (step = about >> 8; step > 1; step >>= 1)
        pick++;
    return pick;
}
/* shared_include_end: ../../../../shared/c/CLUE-PHRASE.C */

/* shared_include_start: ../../../../shared/c/CLUE-SUBJECT.C -- generated */
/* CLUE-SUBJECT.C -- c_clue_subject, naming what a clue is about.
 */

/* Append what clue record `nth` is about, from `about`: the fact in the high
 * byte and what it names in the low one.
 */
void c_clue_subject(INT nth, INT about)
{
    INT who;

    who = (unsigned char) about;
    switch (about >> 8) {
    case CLUE_CITY:
        strcat(shm_scratch, shm_cities[who].name);
        break;
    case CLUE_ORG:
        strcat(shm_scratch, shm_orgs[who].long_name);
        shm_orgs[who].known |= 1;
        break;
    case CLUE_NAME:
        c_person_real_name(who);
        break;
    case CLUE_FACE:
        strcat(shm_scratch, shd_str_face);
        shm_menu_face = shm_suspects[who].visuals;
        break;
    case CLUE_ROLE:
        if (shm_clues_shown[nth].role
            < shm_crime_role_count - shm_difficulty * 4)
            strcat(shm_scratch, shd_str_valkerie);
        else
            strcat(shm_scratch, shd_str_thunderbolt);
        break;
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-SUBJECT.C */

/* shared_include_start: ../../../../shared/c/CLUE-THING.C -- generated */
/* CLUE-THING.C -- c_clue_thing, naming the object a clue is about.
 */

/* Append the thing the clue word `about` names, unless it is -1: its name from
 * shd_clue_kinds and its number. Types 5 and 6 are money, in hundreds and
 * thousands.
 */
void c_clue_thing(INT about)
{
    if (about != -1) {
        strcat(shm_scratch,
                   (char *) ((rt_addr (*)[8]) &shd_clue_kinds[16])
                   [(about >> 8) & 0xf][(about >> 4) & 7]);
        strcat(shm_scratch,
                   (char *) itoa((about & 0x3f) + 1, shm_clue_digits, 10));
        if (((about >> 8) & 0xf) == 5)
            strcat(shm_scratch, shd_str_00);
        if (((about >> 8) & 0xf) == 6)
            strcat(shm_scratch, shd_str_000);
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-THING.C */

/* shared_include_start: ../../../../shared/c/CLUE-FULL.C -- generated */
/* CLUE-FULL.C -- c_clue_line_full, a clue record as its own line.
 */

/* Append clue record `nth` as its own line from clues.txt rather than as an
 * assembled phrase.
 */
void c_clue_line_full(INT nth)
{
    c_clue_from_file(shm_clues_shown[nth].subject,
                    shm_clues_shown[nth].text, nth);
}
/* shared_include_end: ../../../../shared/c/CLUE-FULL.C */

/* shared_include_start: ../../../../shared/c/CLUE-FROM-FILE.C -- generated */
/* CLUE-FROM-FILE.C -- c_clue_from_file, a clue's own line from clues.txt.
 */

/* Append clue record `nth`'s line from clues.txt, keyed by the clue type in
 * `kind` and the fact in `about`, with its fields filled in; a face only sets
 * shm_menu_face.
 */
void c_clue_from_file(INT about, INT kind, INT nth)
{
    INT num;
    INT here;
    char seek[8];
    INT cut;

    /* The clue's line in clues.txt is keyed by the clue's type and by which fact it tells. */
    num = (unsigned char) about;
    strcpy(seek, shd_key_clue_2);
    seek[2] += (kind >> 8) & 0xf;
    for (here = about >> 8; here > 1; here >>= 1)
        seek[3]++;
    /* The object the clue turns on becomes $KEY, built at the buffer's end and cut off again. */
    here = strlen(shm_scratch);
    c_clue_thing(kind);
    strcpy((char *) shd_subst_values[0],
               (char *) shm_scratch + here);
    (shm_scratch)[here] = 0;
    /* Most lines are led by one character, the method, which is cut off the text. */
    cut = 1;
    switch (about >> 8) {
    /* A face is shown beside the text rather than written into it. */
    case 1:
        shm_menu_face = shm_suspects[num].visuals;
        break;
    /* The suspect's real name becomes $NAME. */
    case 2:
        c_person_real_name(num);
        strcpy((char *) shd_subst_values[1],
                   (char *) shm_scratch + here);
        (shm_scratch)[here] = 0;
        break;
    /* The organisation becomes $ORG. */
    case 4:
        strcpy((char *) shd_subst_values[2],
                   shm_orgs[num].long_name);
        break;
    /* The city becomes $CITY. */
    case 8:
        strcpy((char *) shd_subst_values[3],
                   shm_cities[num].name);
        break;
    /* The role itself has a line of its own, led by two characters to cut. */
    case 0x10:
        cut = 2;
        /* A real role's line is keyed by the case's mission and the role. */
        if (shm_clues_shown[nth].role
            < shm_crime_role_count - shm_difficulty * 4) {
            strcpy(seek, shd_key_clue_3);
            seek[5] += num;
            seek[3] += shm_mission % 10;
            seek[2] += shm_mission / 10;
        /* A red herring's line is picked by bits of its suspect's face instead. */
        } else {
            here = shm_suspects[shm_crime_roles[shm_clues_shown[nth].role].suspect].visuals;
            strcpy(seek, shd_key_clue_4);
            seek[5] += here % 6;
            seek[3] += (here >> 3) % 4;
        }
        break;
    }
    /* Append the line with the fields filled in. */
    here = strlen(shm_scratch);
    c_say_block_with(shd_str_clues_txt_2, seek, shd_clue_keys,
                       shd_subst_values, 5);
    /* Keep the lead character as the clue's method, and cut the lead off the text. */
    shm_clue_method = *((char *) shm_scratch + here) & 0xf;
    OVERLAPPING_STRCPY((char *) shm_scratch + here,
               (char *) shm_scratch + here + cut);
}
/* shared_include_end: ../../../../shared/c/CLUE-FROM-FILE.C */

/* shared_include_start: ../../../../shared/c/DOSSIER.C -- generated */
/* DOSSIER.C -- c_dossier, drawing a suspect's dossier and intercepts.
 */

/* Draw suspect `nth`'s dossier at (`x`, `y`), then their intercepted messages.
 * A `y` of zero is a whole screen; any other is a panel, without the
 * recruitment line, face and messages.
 */
void c_dossier(INT nth, INT x, INT y)
{
    INT filled;
    INT disused;
    INT slot;
    INT low;
    INT unwanted;
    INT row;
    INT scrap;
    INT tick;
    INT rank;
    INT dead;

    /* Remember where the dossier starts: 0 means it has the screen to itself. */
    row = y;
    unwanted = nth;
    /* A panel is indented; a page of its own is framed with the suspect's name as its title. */
    if (y != 0)
        x += 4;
    else {
        strcpy(shm_scratch, shd_str_empty_dossier);
        c_person_name(nth);
        c_page_frame((rt_addr) shm_scratch, 3);
        y = 18;
        x += 10;
    }
    /* The name they go by, real or a codename. */
    y += 2;
    strcpy(shm_scratch, shd_str_name);
    c_person_name(nth);
    c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    /* The rank, once learnt: that of a role the suspect fills, or else one read off their face. */
    if (shm_suspects[nth].flags & SUSPECT_RANK) {
        rank = (shm_suspects[nth].visuals >> 2) & 7;
        for (tick = 0; tick < shm_crime_role_count; tick++)
            if (shm_crime_roles[tick].suspect == nth)
                rank = shm_crime_roles[tick].rank;
        strcpy(shm_scratch, shd_str_rank);
        strcat(shm_scratch, (char *) shd_clue_kinds[rank]);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* The organisation, once learnt, which also marks the organisation as heard of. */
    if (shm_suspects[nth].flags & SUSPECT_ORG) {
        shm_orgs[shm_suspects[nth].org].known |= 1;
        strcpy(shm_scratch, shd_str_org);
        strcat(shm_scratch, shm_orgs[shm_suspects[nth].org].long_name);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* The city they work from, once learnt. */
    if (shm_suspects[nth].flags & SUSPECT_CITY) {
        strcpy(shm_scratch, shd_str_city);
        strcat(shm_scratch, shm_cities[shm_suspects[nth].city].name);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* Recruited by whoever fills the first role in the same organisation, unless that is the suspect. */
    strcpy(shm_scratch, shd_str_recruited);
    if (shm_suspects[nth].flags & SUSPECT_RECRUITED_BY)
        for (tick = 0; tick < shm_crime_role_count; tick++)
            if (shm_suspects[nth].org
                == shm_suspects[shm_crime_roles[tick].suspect].org) {
                if (nth != shm_crime_roles[tick].suspect) {
                    strcat(shm_scratch, shd_str_by);
                    c_person_real_name(shm_crime_roles[tick].suspect);
                }
                break;
            }
    /* ...and in the city nearest the one they work from. */
    if (shm_suspects[nth].flags & SUSPECT_RECRUITED_IN) {
        rank = -1;
        low = 999;
        for (tick = 0; tick < 16; tick++)
            if (tick != shm_suspects[nth].city
                && (INT) c_city_distance(tick,
                                            shm_suspects[nth].city) < low) {
                rank = tick;
                low = c_city_distance(rank,
                                         shm_suspects[nth].city);
            }
        if (rank != -1) {
            strcat(shm_scratch, shd_str_in_3);
            strcat(shm_scratch, shm_cities[rank].name);
        }
    }
    /* Only a page of its own shows the Recruited line, and only once something follows the word. */
    if ((INT) strlen(shm_scratch) > 12 && row == 0) {
        strcat(shm_scratch, shd_str_period_2);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* A page of its own shows the photograph, once taken, clipped to the top right. */
    if (shm_suspects[nth].flags & SUSPECT_PHOTO && row == 0) {
        c_draw_face_panel(shm_suspects[nth].visuals, 264, 8);
        c_draw_sprite(SPRITE_PAPERCLIP, 299, 40);
    }
    /* Below a rule, a Role: line for each role the suspect is known to fill. */
    filled = 0;
    y += 10;
    c_draw_line(x, y - 2, x + 128, y - 2, 12);
    for (tick = 0; tick < shm_crime_role_count; tick++)
        if (shm_suspects[nth].role_known
            & 1 << tick) {
            strcpy(shm_scratch, shd_str_role);
            strcat(shm_scratch, shm_crime_roles[tick].name);
            c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
            filled = 1;
        }
    /* No role known: NOT INVOLVED if fully identified and flagged yet holding no real role, else unknown. */
    if (filled == 0) {
        if ((shm_suspects[nth].flags & (SUSPECT_IDENTITY | SUSPECT_PARTICIPANT))
                == (SUSPECT_IDENTITY | SUSPECT_PARTICIPANT)
            && (shm_suspects[nth].role & 0x7fff)
               == 0)
            strcpy(shm_scratch, shd_str_role_2);
        else
            strcpy(shm_scratch, shd_str_role_3);
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* What has become of the suspect: arrested, in hiding or turned. */
    if (shm_suspects[nth].alert_level == ALERT_ARRESTED) {
        strcpy(shm_scratch, shd_str_under_arrest);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 5);
    }
    if (shm_suspects[nth].alert_level == ALERT_HIDING) {
        strcpy(shm_scratch, shd_str_hiding);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 5);
    }
    if (shm_suspects[nth].alert_level == ALERT_TURNED) {
        strcpy(shm_scratch, shd_str_turned);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 5);
    }
    /* Close the card with a rule, and start the messages clear of the photograph if there is one. */
    c_draw_line(x, y + 8, x + 128, y + 8, 12);
    y += 2;
    y = c_clamp(y + 8,
                           shm_suspects[nth].flags & SUSPECT_PHOTO ? row + 54 : 0, 99);
    /* On a page of its own, every logged message from the suspect that the player knows of. */
    for (tick = 0; tick < shm_log_count; tick++)
        if (shm_log[tick].from == nth
            && shm_log[tick].known != 0
            && row == 0) {
            for (;;) {
                /* Its headline: what it was, with whom, where and when. */
                strcpy(shm_scratch, shd_str_empty_dossier_line);
                c_intercept_line(tick);
                y = c_draw_message(37, x, y, 5);
                if (row == 0) {
                    slot = shm_log[tick].slot;
                    /* A decoded message is quoted in full. */
                    if (shm_log[tick].known & 0x8000) {
                        strcpy(shm_scratch, shd_str_quote);
                        c_say_event_text(slot);
                        strcat(shm_scratch, shd_str_quote_2);
                        y = c_draw_message(36, x + 4, y, 12);
                    } else {
                        /* A coded message not yet decoded says so. */
                        if ((shm_crime_events[slot].flags & CRIME_KIND) == CRIME_MESSAGE
                            || (shm_crime_events[slot].flags & CRIME_KIND)
                               == (CRIME_MESSAGE | CRIME_RECEIVED)) {
                            c_write_text(shd_str_message_not_decoded, x + 4, y, 4);
                            y += 8;
                        }
                        /* Meeting notes show only the words the record's known bits let through. */
                        if ((shm_crime_events[slot].flags & CRIME_KIND) == CRIME_MEETING
                            || (shm_crime_events[slot].flags & CRIME_KIND)
                               == (CRIME_MEETING | CRIME_RECEIVED)) {
                            shm_scratch[0] = 0;
                            c_say_event_text(slot);
                            c_filter_message(shm_log[tick].known, 5);
                            y = c_draw_message(36, x + 4, y, 12);
                        }
                    }
                }
                /* At the foot of the page, wait for a key and redraw this message atop a fresh page. */
                if (y >= 192) {
                    c_write_text(shd_str_more, 256, 192, 12);
                    c_wait_key();
                    strcpy(shm_scratch, shd_str_empty_dossier_page);
                    c_person_name(nth);
                    c_page_frame((rt_addr) shm_scratch, 3);
                    y = 16;
                } else
                    break;
            }
        }
}
/* shared_include_end: ../../../../shared/c/DOSSIER.C */

/* shared_include_start: ../../../../shared/c/INTERCEPT-LINE.C -- generated */
/* INTERCEPT-LINE.C -- c_intercept_line, one case-log record as a sentence.
 */

/* Append log record `nth` to shm_scratch as a sentence: what happened, then as
 * far as is known who with, their organisation, the city and the date.
 */
void c_intercept_line(INT nth)
{
    INT party;
    INT last;
    INT origin;
    INT peer;

    /* What happened: the event's own description, or for a bare message which way it went. */
    origin = shm_log[nth].slot;
    if (origin >= 0)
        strcat(shm_scratch, shm_crime_events[origin].description);
    else if (origin & 1)
        strcat(shm_scratch, shd_str_rcvd_msg_fm);
    else
        strcat(shm_scratch, shd_str_sent_msg);
    /* An event with anyone at the far end goes on to name them, as far as the player knows. */
    if (shm_crime_events[origin].flags & CRIME_IN_USE || origin < 0) {
        /* The exchange's other half is the record logged the same minute, on either side. */
        peer = shm_log[nth].from;
        party = shm_log[nth].to;
        last = -1;
        if (shm_log[nth + 1].minute
            == shm_log[nth].minute)
            last = nth + 1;
        if (shm_log[nth - 1].minute
            == shm_log[nth].minute)
            last = nth - 1;
        /* Who it was with, or "someone". */
        if (shm_log[nth].known & 2) {
            strcat(shm_scratch, shd_str_space_9);
            c_person_name(party);
        } else
            strcat(shm_scratch, shd_str_someone);
        /* Their organisation. */
        if (shm_log[nth].known & 4) {
            strcat(shm_scratch, shd_str_of_the_2);
            strcat(shm_scratch, shm_orgs[shm_suspects[party].org].short_name);
        }
        /* The city at their end. */
        if (shm_log[nth].known & 8) {
            strcat(shm_scratch, shd_str_in_4);
            strcat(shm_scratch, shm_cities[shm_log[nth].to_city].name);
        }
        /* Once the far end is placed, share what is known of them between both halves and their file. */
        if ((shm_log[nth].known & 2
             && shm_suspects[party].flags & SUSPECT_NAME)
            || (shm_log[nth].known & 4
                && shm_log[nth].known & 8
                && shm_suspects[party].flags & SUSPECT_ORG
                && shm_suspects[party].flags & SUSPECT_CITY)) {
            shm_log[nth].known |=
                shm_suspects[party].flags & (SUSPECT_NAME | SUSPECT_ORG);
            shm_log[last].known |=
                shm_suspects[peer].flags & (SUSPECT_NAME | SUSPECT_ORG);
            shm_suspects[party].flags |=
                shm_log[nth].known & 6;
            if (shm_log[nth].to_city
                == shm_suspects[party].city) {
                shm_log[nth].known |=
                    shm_suspects[party].flags & SUSPECT_CITY;
                shm_suspects[party].flags |=
                    shm_log[nth].known & 8;
            }
        }
        /* The same from the other half, for the suspect at this end. */
        if ((shm_log[last].known & 2
             && shm_suspects[peer].flags & SUSPECT_NAME)
            || (shm_log[last].known & 4
                && shm_log[last].known & 8
                && shm_suspects[peer].flags & SUSPECT_ORG
                && shm_suspects[peer].flags & SUSPECT_CITY)) {
            shm_log[last].known |=
                shm_suspects[peer].flags & (SUSPECT_NAME | SUSPECT_ORG);
            shm_log[nth].known |=
                shm_suspects[party].flags & (SUSPECT_NAME | SUSPECT_ORG);
            shm_suspects[peer].flags |=
                shm_log[last].known & 6;
            if (shm_log[last].to_city
                == shm_suspects[peer].city) {
                shm_log[last].known |=
                    shm_suspects[peer].flags & SUSPECT_CITY;
                shm_suspects[peer].flags |=
                    shm_log[last].known & 8;
            }
        }
    }
    /* The date, if known: the case's month and the campaign day it happened on. */
    if (shm_log[nth].known & 1) {
        strcat(shm_scratch, shd_str_on_2);
        strcat(shm_scratch,
                   (char *) shd_month_names
                   [shm_campaign.cases % 12]);
        strcat(shm_scratch, shd_str_space_10);
        strcat(shm_scratch,
                   (char *) itoa(shm_log[nth].minute / 1440 + 1,
                                     shm_clue_digits, 10));
    }
    /* Close the sentence. */
    strcat(shm_scratch, shd_str_period_3);
}
/* shared_include_end: ../../../../shared/c/INTERCEPT-LINE.C */
