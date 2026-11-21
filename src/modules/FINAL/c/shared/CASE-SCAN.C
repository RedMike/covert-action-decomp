/* CASE-SCAN.C -- the scan for clues, evidence and messages.
 *
 * Four tables meet in it: the suspects, the intercepted messages of the case
 * log, the crime events, and the crime roles with their scan states. Suspect
 * records are added to and given back here too.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "MENUS.H"
#include "SCREEN.H"
#include "MAIN.H"
#include "CASERUN.H"
#include "CRIMEVNT.H"
#include "SUSPFLAG.H"

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
