/* CASE.C -- clues and evidence: the scan, suspects, clues, dossiers and intercepts.
 */
#include "GAME.H"
#include "SPRITES.H"
#include "CASE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "DIALOG.H"
#include "FRAME.H"
#include "BLOCK.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "SUSPECTS.H"
#include "PANEL.H"
#include "FACES.H"
#include "HANDOVER.H"
#include "TAG.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"

/* Scanning every suspect for the time the player spent watching organisation
 * `arg1` in city `arg2`, and reporting how many clues and pieces of evidence
 * turned up. */
INT c_suspect_scan(INT arg1, INT arg2, INT arg3, LONG arg4)
{
    INT v1i;    /* suspect being stepped */
    INT v0j;
    INT v2i;    /* how many of the role's facts are already known */
    INT v4h;    /* how far the suspect's organisation is from arg1 */
    INT v3i;    /* the suspect a message went to */
    INT v5h;
    INT v7g;    /* how many clues and pieces of evidence, and the result */
    INT v6h;    /* the crime event the log entry records */
    INT v8g;    /* what the suspect's score gains */
    INT v10o;   /* the suspect's organisation */
    INT v9g;    /* how far its city is from arg2 */
    INT v11o;   /* the bit the event learns */
    INT v13n;   /* the suspect's city */
    INT v12o;   /* role being stepped, then a threshold rising per message */
    INT v14n;   /* scratch */
    INT v16m;   /* the suspect of arg1's organisation in arg2's city, if any */
    INT v15n;   /* log entry being looked at */
    INT v17m;   /* the suspect's score after the step */
    INT v19l;   /* what the score gain is divided by */
    INT v18m;   /* the evidence bits the suspect ends the step with */
    INT v20e;   /* the suspect a message went to */
    INT v22d;   /* what the clue visibility gain is divided by */
    INT v21e;
    INT v23d;   /* whether the news found is worth the trip */

    /* Nothing found yet; any clue that comes out cites the source the caller names. */
    v7g = 0;
    shm_wire_clue_source = (INT) arg4;
    /* No time spent watching turns up nothing. */
    if (arg3 <= 0)
        return 0;
    /* Bookkeeping that is set up here and never used. */
    v0j = 0;
    v5h = 9999;
    v21e = -1;
    v16m = -1;
    for (v1i = 0; v1i < shm_suspect_count; v1i++) {
        /* A free record is nobody. */
        if (shm_suspects[v1i].visuals == 0)
            continue;
        /* How far the suspect's organisation and city are from the ones watched. */
        v10o = shm_suspects[v1i].org;
        v13n = shm_suspects[v1i].city;
        v4h = c_packed_distance(
            shm_orgs[arg1].where,
            shm_orgs[v10o].where);
        v9g = c_packed_distance(
            shm_cities[arg2].where,
            shm_cities[v13n].where);
        /* The suspect right at the place watched, noted and never read. */
        if (v4h == 0 && v9g == 0)
            v16m = v1i;
        /* Progress comes slower the further off the suspect is, and faster the longer the watch. */
        v19l = ((LONG) ((v4h + 2) * (v9g + 2)) << 8) / (arg3 + 1);
        v22d = ((LONG) ((v4h + 3) * (v9g + 6)) << 6) / (arg3 + 1);
        /* The suspect's score grows, less at higher difficulty and less the higher it already is. */
        v8g = 10000 / (shm_difficulty + 2) / v19l;
        shm_suspects[v1i].score +=
            (LONG) v8g * v8g
            / (shm_suspects[v1i].score / 2
               + v8g + 1);
        /* A figure worked out from the new score that nothing reads. */
        v17m = shm_suspects[v1i].score;
        v19l = 2500 / (v17m + 1);
        /* Every role the suspect fills whose clues have begun to show: */
        for (v12o = 0; v12o < shm_crime_role_count; v12o++)
            if (v1i == shm_crime_roles[v12o].suspect
                && shm_role_scan_states[v12o].clue_visible_since
                   <= shm_case_tick
                && shm_role_scan_states[v12o].clue_visible_since != -1) {
                /* it grows more visible, less so at higher difficulty and further off, */
                shm_role_scan_states[v12o].clue_visibility +=
                    5000 / (shm_difficulty + 3) / v22d;
                /* its next clue costs more the more of its five facts are already out, */
                v18m = shm_crime_roles[v12o].clues_known;
                v2i = shd_scan_counts[v18m & 0x1f];
                /* and clues come out while the visibility beats that cost and facts remain. */
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
        /* A suspect with no evidence yet gives none unless at the watched organisation or city. */
        if (shm_suspects[v1i].flags == 0
            && v4h != 0 && v9g != 0)
            continue;
        /* Start from what is known; each message the suspect sent asks a little more than the last. */
        v18m = shm_suspects[v1i].flags;
        v12o = 2;
        /* Every message logged as sent by this suspect: */
        for (v15n = 0; v15n < shm_log_count; v15n++)
            if (shm_log[v15n].from == v1i) {
                v6h = shm_log[v15n].slot;
                /* while the score, weighed by the role's exposure, beats the cost of a further fact, */
                while (shm_crime_roles[shm_crime_events[v6h].main_participant].exposure
                       * shm_suspects[v1i].score / 96
                       > shd_scan_counts
                             [shm_log[v15n].known & 0xf] * 2
                         + v12o
                       && (shm_log[v15n].known & 0xf)
                          != 0xf) {
                    /* one of the four at random: the date, the recipient's name, organisation or city. */
                    v11o = 1 << c_random_below(4);
                    /* A fact not yet known is announced over the sender's dossier. */
                    if (!(v11o & shm_log[v15n].known)) {
                        c_dossier(v1i, 0, 0);
                        /* Coded message or meeting notes, new or more information, the sender and the event. */
                        shm_scratch[0] = 0;
                        if (shm_crime_events[v6h].flags & CRIME_MESSAGE)
                            strcpy(shm_scratch, dat_str_coded_message);
                        if (shm_crime_events[v6h].flags & CRIME_MEETING)
                            strcpy(shm_scratch, dat_str_meeting_notes);
                        strcat(shm_scratch,
                                   shm_log[v15n].known == 0
                                   ? dat_str_new_information : dat_str_additional_information);
                        c_person_name(v1i);
                        strcat(shm_scratch, dat_str_space_2);
                        c_intercept_line(v15n);
                        strcat(shm_scratch, dat_str_dots);
                        /* A goto rather than an if block, as shipped. */
                        /* The date: "on" the month and the day of the month. */
                        if (!(v11o & 1))
                            goto undated;
                        strcat(shm_scratch, dat_str_on);
                        strcat(shm_scratch,
                                   shd_month_names[shm_campaign.cases % 12]);
                        strcat(shm_scratch, dat_str_space_2_2);
                        strcat(shm_scratch,
                                   itoa(shm_log[v15n].minute / 1440 + 1,
                                            shm_clue_digits, 10));
undated:
                        /* An event with another end names what is learnt of it: recipient, organisation, city. */
                        if (shm_crime_events[v6h].flags & CRIME_IN_USE) {
                            v20e = shm_log[v15n].to;
                            if (v11o & 2) {
                                shm_suspects[v20e].flags |= SUSPECT_NAME;
                                c_person_name(v20e);
                            }
                            if (v11o & 4) {
                                strcat(shm_scratch, dat_str_of_the);
                                strcat(shm_scratch,
                                           shm_orgs[shm_suspects[v20e].org].long_name);
                            }
                            if (v11o & 8) {
                                strcat(shm_scratch, dat_str_in);
                                strcat(shm_scratch,
                                           shm_cities[shm_log[v15n].to_city].name);
                            }
                            /* Show it in a box, then the sender's dossier again: the sender is now a known plotter. */
                            strcat(shm_scratch, dat_str_newline);
                            c_menu_box(16, 96, 264, 48,
                                               shm_cga != 0 ? 4 : 3);
                            shd_screen->bg_pen = 3;
                            c_draw_message(32, 20, 100, 11);
                            c_wait_key();
                            shm_log[v15n].known |= v11o;
                            c_dossier(v1i, 0, 0);
                            c_wait_key();
                            shm_suspects[v1i].flags |= SUSPECT_PARTICIPANT;
                        } else {
                            /* A lone event has no other end to learn of; the line built is not drawn. */
                            shm_log[v15n].known |= 0xe;
                            c_wait_key();
                        }
                        /* The fact is now known. */
                        shm_log[v15n].known |= v11o;
                        /* The sender's part becomes known, on the easiest level or for a lone event. */
                        if (!(shm_suspects[v1i].role_known
                              & (1 << shm_crime_events[v6h].main_participant))
                            && ((shm_difficulty < 1 && v4h + v9g == 0
                                 && (shm_log[v15n].known & 0xf)
                                    == 0xf)
                                || !(shm_crime_events[v6h].flags & CRIME_IN_USE))) {
                            /* Clearing the participant bit makes the report below announce it. */
                            shm_suspects[v1i].role_known |=
                                1 << shm_crime_events[v6h].main_participant;
                            v18m |= SUSPECT_PARTICIPANT;
                            shm_suspects[v1i].flags &= ~SUSPECT_PARTICIPANT;
                            shm_log[v15n].known |= 0xf;
                        }
                    }
                }
                /* The suspect's next message costs a little more. */
                v12o++;
                /* What a message gave away of its recipient goes quietly on their record, the city only if theirs. */
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
        /* While the score outruns 25 a piece of evidence and some remains, the suspect gives up more: */
        while (v18m != 0
               && (shd_scan_counts
                       [(v18m & (SUSPECT_IDENTITY | SUSPECT_BACKGROUND)) >> 8]
                   + shd_scan_counts[v18m & SUSPECT_IDENTITY]) * 25
                  < shm_suspects[v1i].score
               && (v18m & (SUSPECT_IDENTITY | SUSPECT_BACKGROUND))
                  != (SUSPECT_IDENTITY | SUSPECT_BACKGROUND)) {
            /* the organisation or city being watched, if it is theirs, and no more this scan; */
            if (arg1 == v10o && !(v18m & SUSPECT_ORG)) {
                v18m |= SUSPECT_ORG;
                break;
            }
            if (arg2 == v13n && !(v18m & SUSPECT_CITY)) {
                v18m |= SUSPECT_CITY;
                break;
            }
            /* otherwise an identity or background fact at random not yet known. */
            do
                v14n = 1 << c_random_below(12);
            while (v14n & v18m & (SUSPECT_IDENTITY | SUSPECT_BACKGROUND)
                   || !(v14n & (SUSPECT_IDENTITY | SUSPECT_BACKGROUND)));
            v18m |= v14n;
        }
        /* Any new evidence is filed on the suspect, reported, and counted as found. */
        if (shm_suspects[v1i].flags != v18m) {
            c_evidence_unlock(v10o, v13n, v18m, LONG_LIT(1));
            v5h = 0;
            v21e = -1;
            v7g++;
        }
    }
    /* Nothing turned up and the caller asked for one: a hint about a random role's suspect. */
    if (v7g == 0 && (INT) arg4 != 0) {
        strcpy(shm_scratch, dat_str_empty_4);
        v1i = shm_crime_roles[c_random_below(shm_crime_role_count)].suspect;
        shm_menu_face = -1;
        /* The higher the difficulty, the fewer kinds of hint there are. */
        switch (c_random_below(8 - shm_difficulty)) {
        /* Their city, tallied for the activity report. */
        case 0:
            strcpy(shm_scratch,
                       shm_cities[shm_suspects[v1i].city].name);
            shm_activity.city[*(UNSIGNED_INT *) &shm_suspects[v1i].city]++;
            break;
        /* Their organisation, tallied and now heard of. */
        case 1:
            strcpy(shm_scratch,
                       shm_orgs[shm_suspects[v1i].org].long_name);
            shm_activity.org[*(UNSIGNED_INT *) &shm_suspects[v1i].org]++;
            shm_orgs[shm_suspects[v1i].org].known |= 1;
            break;
        /* Their face. */
        case 2:
            strcpy(shm_scratch, dat_str_space_3);
            shm_menu_face =
                shm_suspects[v1i].visuals;
            break;
        /* Their real name, shown this once without being learnt. */
        case 3:
            v14n = shm_suspects[v1i].flags;
            shm_suspects[v1i].flags |= SUSPECT_NAME;
            shm_scratch[0] = 0;
            c_person_name(v1i);
            shm_suspects[v1i].flags = v14n;
            break;
        /* The case's organisation in a plotter's city, */
        case 4:
        case 6:
            v10o = shm_case_org;
            v13n = shm_suspects[shm_crime_roles[c_random_below(shm_crime_role_count)].suspect].city;
            goto news;
        /* or a plotter's organisation in the case's city: */
        case 5:
        case 7:
            v10o = shm_suspects[shm_crime_roles[c_random_below(shm_crime_role_count)].suspect].org;
            v13n = shm_case_city;
news:
            /* told, with its building, only if worth the trip, not yet known and really there. */
            v23d = c_worth_the_trip(shm_case_org, v10o, v13n);
            if (v23d != 0
                && !(shm_cities[v13n].known_orgs
                     & (1 << v10o))
                && c_presence(v13n, v10o) != 0) {
                /* The player now knows of the building: "<organisation> <presence> in <city>". */
                shm_cities[v13n].known_orgs |= 1 << v10o;
                c_building_explore(v10o, v13n, 0xc);
                shm_orgs[v10o].known |= 1;
                strcpy(shm_scratch, shm_orgs[v10o].long_name);
                c_say_presence(v13n, v10o);
                strcat(shm_scratch, dat_str_in_2);
                strcat(shm_scratch, shm_cities[v13n].name);
                shm_menu_face = -2;
            } else {
                /* Otherwise there is no hint after all. */
                shm_scratch[0] = 0;
            }
            break;
        }
        /* Show the hint, if any, and wait; in GAME the hook draws nothing. */
        if (shm_scratch[0] != 0) {
            c_hook_campaign();
            c_wait_key();
        }
    }
    /* How many clues and pieces of evidence the watch turned up. */
    return v7g;
}

/* Adding evidence on the suspect of one organisation in one city, making that
 * suspect if there is none; answer it, or -1. */
INT c_evidence_unlock(INT org, INT city, UNSIGNED_INT bits, LONG show)
{
    INT slot;
    INT keep;
    INT step;
    INT held;

    /* A suspect already on file for that organisation and city takes the new facts. */
    for (slot = 0; slot < shm_suspect_count; slot++)
        if (shm_suspects[slot].org == org
            && shm_suspects[slot].city == city) {
            held = shm_suspects[slot].flags;
            if ((shm_suspects[slot].flags |= bits)
                != 0) {
tell:
                /* Tell the player what is new, if asked to, and answer the record. */
                if ((INT) show != 0)
                    c_report_new_fields(slot, held);
                return slot;
            }
            /* One the player still knows nothing of does not count. */
            return -1;
        }
    /* Otherwise a free record from 1 up becomes the suspect, */
    do
        slot = c_random_below(63) + 1;
    while (shm_suspects[slot].visuals != 0);
    /* except that the mastermind is always record 0 and keeps what was known of them. */
    if (org == shm_campaign.mastermind_org && city == shm_campaign.mastermind_city) {
        slot = 0;
        bits |= shm_campaign.mastermind_flags;
    }
    /* Nobody is put on file with nothing known. */
    if (bits == 0)
        return -1;
    /* A fresh suspect: the place and the facts, and no part in the plot yet. */
    held = shm_suspects[slot].flags;
    shm_suspects[slot].org = org;
    shm_suspects[slot].city = city;
    shm_suspects[slot].flags = bits;
    shm_suspects[slot].role = 0;
    shm_suspects[slot].role_known = 0;
    /* A random face and identity, meant to differ from every other suspect's. */
    do {
        keep = 1;
        shm_suspects[slot].visuals =
            c_random_below(0x7fff);
        for (step = 0; step < shm_suspect_count; step++)
            /* `==` binds before `&` here, as shipped. */
            if ((shm_suspects[slot].visuals
                 & (0x3f == shm_suspects[step].visuals)
                 & 0x3f)
                && slot != step)
                keep = 0;
    } while (keep == 0);
    /* Then it is reported like one already on file. */
    goto tell;
}

/* Give a record back, unless anything is still holding it. */
void c_suspect_release(INT slot)
{
    /* A suspect who fills a real role stays; a red herring's reservation does not hold it. */
    if (shm_suspects[slot].role & 0x7fff)
        goto held;
    /* Otherwise the record is free again and knows nothing. */
    shm_suspects[slot].visuals = 0;
    shm_suspects[slot].org = -1;
    shm_suspects[slot].city = -1;
    shm_suspects[slot].flags = 0;
held:
    ;
}

/* Announcing each piece of evidence just added on one suspect. */
UNSIGNED_INT c_report_new_fields(INT who, UNSIGNED_INT flags)
{
    INT picked;   /* the bits still to be reported */
    INT gained;   /* every bit the suspect ends up with */

    /* Put the record back as it was, so each fact can be added as it is told. */
    gained = shm_suspects[who].flags;
    shm_suspects[who].flags = flags;
    /* Nothing new, nothing to tell. */
    if (gained == flags)
        return flags;
    do {
        /* The dossier as it now stands, under the next announcement. */
        c_dossier(who, 0, 0);
        shm_menu_draw_only = 0;
        /* What is still to be told, taken one fact a pass in a fixed order. */
        gained |= shm_suspects[who].flags;
        picked = gained
                 ^ shm_suspects[who].flags;
        if (picked & SUSPECT_PARTICIPANT) {
            /* "... has been identified as a participant in the plot." */
            shm_suspects[who].flags |= SUSPECT_PARTICIPANT;
            strcpy(shm_scratch, dat_str_empty_5);
            c_person_name(who);
            strcat(shm_scratch, dat_str_has_been_identified_as);
            c_ask_menu(shm_scratch, 20, 60);
        } else if (picked & SUSPECT_NAME) {
            /* The name the suspect went by, then the real one it turns out to be. */
            strcpy(shm_scratch, &dat_str_empty_6);
            c_person_name(who);
            strcat(shm_scratch, dat_str_has_been_positively);
            shm_suspects[who].flags |= SUSPECT_NAME;
            c_person_name(who);
            strcat(shm_scratch, dat_str_newline_2);
            c_ask_menu(shm_scratch, 20, 60);
        } else if (picked & SUSPECT_PHOTO) {
            /* A photograph has been acquired. */
            shm_suspects[who].flags |= SUSPECT_PHOTO;
            strcpy(shm_scratch, dat_str_we_have_acquired);
            c_person_name(who);
            strcat(shm_scratch, dat_str_stop);
            c_ask_menu(shm_scratch, 20, 60);
        } else if (picked & SUSPECT_CITY) {
            /* Spotted in their city, which the activity report tallies. */
            shm_suspects[who].flags |= SUSPECT_CITY;
            strcpy(shm_scratch, dat_str_empty_7);
            c_person_name(who);
            strcat(shm_scratch, dat_str_has_been_spotted);
            strcat(shm_scratch,
                       shm_cities[shm_suspects[who].city].name);
            strcat(shm_scratch, dat_str_newline_3);
            c_ask_menu(shm_scratch, 20, 60);
            shm_activity.city[shm_suspects[who].city]++;
        } else if (picked & SUSPECT_ORG) {
            /* Identified with their organisation, now heard of and tallied. */
            shm_suspects[who].flags |= SUSPECT_ORG;
            strcpy(shm_scratch, dat_str_empty_8);
            c_person_name(who);
            strcat(shm_scratch, dat_str_has_been_identified_as_2);
            strcat(shm_scratch,
                       shm_orgs[shm_suspects[who].org].long_name);
            strcat(shm_scratch, dat_str_newline_4);
            c_ask_menu(shm_scratch, 20, 60);
            shm_orgs[shm_suspects[who].org].known |= 1;
            shm_activity.org[shm_suspects[who].org]++;
        } else if (picked & SUSPECT_MORE_INFO) {
            /* More information obtained, an announcement with nothing behind it. */
            shm_suspects[who].flags |= SUSPECT_MORE_INFO;
            strcpy(shm_scratch, dat_str_we_have_obtained);
            c_person_name(who);
            strcat(shm_scratch, dat_str_newline_5);
            c_ask_menu(shm_scratch, 20, 60);
        } else if (picked & SUSPECT_RANK) {
            /* Their rank determined. */
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RANK >> 8;
            strcpy(shm_scratch, dat_str_we_have_determined_rank);
            c_person_name(who);
            strcat(shm_scratch, dat_str_newline_6);
            c_ask_menu(shm_scratch, 20, 60);
        } else if (picked & SUSPECT_RECRUITED_IN) {
            /* Recruiting information: the city half of the dossier's Recruited line. */
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RECRUITED_IN >> 8;
            strcpy(shm_scratch, dat_str_we_found_recruiting);
            c_person_name(who);
            strcat(shm_scratch, dat_str_newline_7);
            c_ask_menu(shm_scratch, 20, 60);
        } else if (picked & SUSPECT_RECRUITED_BY) {
            /* Recruiting information again: the recruiter half of that line. */
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RECRUITED_BY >> 8;
            strcpy(shm_scratch, dat_str_we_found_recruiting_2);
            c_person_name(who);
            strcat(shm_scratch, dat_str_newline_8);
            c_ask_menu(shm_scratch, 20, 60);
        continue;
    }
    } while (shm_suspects[who].flags != gained);
    /* The finished dossier, until the player has read it. */
    c_dossier(who, 0, 0);
    return c_wait_key();
}
