/* CAMPAIGN-MISSION-END.C -- the end of a case: replay, report and career.
 */
#include "FINAL.H"
#include "SPRITES.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "ARCHIVE.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "MENUS.H"
#include "SEQUENCE.H"
#include "LOADDISK.H"
#include "SCREEN.H"
#include "MAIN.H"
#include "CSTART.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "ORIENT.H"
#include "SAVELOAD.H"
#include "CASERUN.H"
#include "CMISEND.H"
#include "CRIMEVNT.H"
#include "CASEFLAG.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* End a case: the debrief, the replay and report, the plot's last paragraphs,
 * the career totals and record, then the Continue/Save/End menu. Leaving the
 * game sets the next module to 0ffh and exits. `reserved`, `junk` and `dead`
 * are never read.
 */
void c_case_end(void)
{
    INT reserved;
    INT eff;
    INT gap;
    INT junk[20];
    INT i;
    INT rank;
    INT reply;
    INT found;
    INT dead;

    /* A debugging dump of the crime events, in the portable build only. */
    CRIME_EVENT_DUMP("c_case_end", shm_crime_events, shm_crime_event_count,
                     shm_crime_role_count);
    /* The debrief: the briefing pan, variant 4, behind "Looks like that about wraps it up". */
    c_sound_command(2);
    c_seq_set_var(0, 4);
    drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
    c_pan_arm(dat_str_briefing_pan_3, 0, 0);
    strcpy(shm_scratch, dat_str_looks_like_about_wraps);
    strcat(shm_scratch, dat_str_we_ve_been_able);
    c_wrap_message(40);
    c_ask_menu((rt_addr) shm_scratch, 8, 149);
    c_clear_message_panel();
    /* The object icons go to page 2, where the replay copies them from; clear the screen. */
    c_load_picture(dat_str_icons_pic, 2);
    drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 1);
    /* The grid shows the real roles only, not the red herrings the difficulty added. */
    asm_grid_in_play = shm_crime_role_count - shm_difficulty * 4;
    /* Park what the player learnt of each suspect in its score, for the efficiency report. */
    for (i = 0; i < shm_suspect_count; i++)
        shm_suspects[i].score = shm_suspects[i].flags;
    /* Reveal everything for the replay, but keep what the player really knew of the MasterMind. */
    shm_campaign.mastermind_flags = shm_suspects[0].flags;
    c_reveal_case();
    shm_suspects[0].flags = shm_campaign.mastermind_flags;
    /* Start the case's tallies from nothing, then replay the case and score it. */
    asm_case_flags = asm_case_points = asm_report_topics
        = asm_report_total = asm_report_slots = 0;
    c_chronology();
    eff = c_efficiency_report();
    c_sound_command(1);
    /* The plot.txt key for this set and mission; a crime not stopped starts at '5', the scoldings. */
    strcpy(asm_plot_key, dat_key_plot_zero);
    asm_plot_key[3] = shm_campaign.mission_set / 10 + '0';
    asm_plot_key[4] = shm_campaign.mission_set % 10 + '0';
    asm_plot_key[5] = shm_campaign.mission_step + '0';
    if (asm_case_flags & CASE_CRIME_DONE)
        asm_plot_key[6] = '5';
    /* The briefing pan again, variant 4 for a crime not stopped and 3 otherwise. */
    c_seq_set_var(0, asm_case_flags & CASE_CRIME_DONE ? 4 : 3);
    drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
    c_pan_arm(dat_note_01, 0, 0);
    /* Show the mission's closing paragraphs one at a time, until the next key is missing. */
    do {
        shm_scratch[0] = 0;
        found = c_say_block(dat_note_02, asm_plot_key);
        if (found) {
            c_wrap_message(40);
            c_ask_menu((rt_addr) shm_scratch, 8, 149);
            c_clear_message_panel();
        }
        asm_plot_key[6]++;
    } while (found);
    /* A crime not stopped moves the set on: this mission counts as done. */
    if (asm_case_flags & CASE_CRIME_DONE) {
        shm_campaign.missions_done |= 1 << shm_campaign.mission_step;
    } else {
        /* A crime prevented: find a fact about the MasterMind still unknown, the name first. */
        gap = -1;
        if (!(shm_campaign.mastermind_flags & SUSPECT_CITY))
            gap = SUSPECT_CITY;
        if (!(shm_campaign.mastermind_flags & SUSPECT_ORG))
            gap = SUSPECT_ORG;
        if (!(shm_campaign.mastermind_flags & SUSPECT_PHOTO))
            gap = SUSPECT_PHOTO;
        if (!(shm_campaign.mastermind_flags & SUSPECT_NAME))
            gap = SUSPECT_NAME;
        /* Outside the first set, the interrogations give that fact away for the next case. */
        if (gap != -1 && shm_campaign.mission_set != 0) {
            strcpy(shm_scratch, dat_note_03);
            c_wrap_message(40);
            c_ask_menu((rt_addr) shm_scratch, 8, 149);
            c_evidence_unlock(shm_campaign.mastermind_org, shm_campaign.mastermind_city, gap, LONG_LIT(1));
            shm_campaign.mastermind_flags |= gap;
        }
    }
    /* The MasterMind in jail: "You have captured the MasterMind controlling the ..." */
    if (shm_suspects[0].alert_level == ALERT_ARRESTED) {
        strcpy(shm_scratch, dat_note_04);
        strcat(shm_scratch,
                   shm_orgs[shm_campaign.mastermind_org].long_name);
        strcat(shm_scratch, dat_note_05);
        strcat(shm_scratch, dat_note_06);
        c_clear_message_panel();
        c_wrap_message(38);
        c_ask_menu((rt_addr) shm_scratch, 8, 149);
    }
    /* The between-case vignette, its scene set by efficiency; scene 0 only in a first case. */
    c_interlude(
        c_clamp(eff * (shm_difficulty + 1) / 150,
                           shm_campaign.cases != 0, 20), LONG_LIT(1));
    c_wait_for_release();
    c_wait_key();
    c_sound_command(1);
    /* Put the case on the hall of fame, which lives on disk 1. */
    c_want_disk(1, LONG_LIT(1));
    c_fame_load();
    c_fame_add(eff);
    c_fame_save();
    /* One more case in the career; find the end of the career record to append it at. */
    shm_campaign.cases++;
    asm_career_cursor = -1;
    for (i = 0; i < 508; i++)
        if (shm_campaign.record[i] == 0xff) {
            asm_career_cursor = i;
            break;
        }
    /* Append set and mission, flags, efficiency high then low, and the MasterMind if taken. */
    if (asm_career_cursor != -1) {
        shm_campaign.record[asm_career_cursor++] =
            (shm_campaign.mission_set << 4)
            + shm_campaign.mission_step;
        shm_campaign.record[asm_career_cursor++] = asm_case_flags;
        shm_campaign.record[asm_career_cursor++] = eff / 256;
        shm_campaign.record[asm_career_cursor++] = eff;
        if (asm_case_flags & CASE_MASTERMIND)
            shm_campaign.record[asm_career_cursor++] = shm_campaign.mastermind_org_known;
        shm_campaign.record[asm_career_cursor] = 0xff;
    }
    /* Tick off this organisation's MasterMind as arrested for the career. */
    if (asm_case_flags & CASE_MASTERMIND)
        shm_campaign.masterminds_arrested |=
            LONG_LIT(1) << *(unsigned char *) &shm_campaign.mastermind_org_known;
    c_career_screen();
    /* Add the case to the career score and work out the rank it earns, 1 the best. */
    shm_campaign.score += eff * (shm_difficulty + 1) / 16;
    rank = c_clamp(
        (shm_campaign.cases * 100 + 10000)
            / (shm_campaign.score + 100),
        1, 99);
    /* A better rank than ever before is a promotion, with the President's commendation. */
    if (rank < shm_campaign.best_rank) {
        strcpy(shm_scratch, dat_note_07);
        strcat(shm_scratch,
                   itoa(shm_campaign.best_rank, asm_number_digits, 10));
        strcat(shm_scratch, dat_note_08);
        strcat(shm_scratch,
                   itoa(rank, asm_number_digits, 10));
        strcat(shm_scratch, dat_note_09);
        shm_campaign.best_rank = rank;
        c_seq_set_var(0, 1);
        drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
        c_pan_arm(dat_note_10, 0, 0);
        c_wrap_message(36);
        c_ask_menu((rt_addr) shm_scratch, 8, 149);
        c_clear_message_panel();
    }
    shm_pan_playing = 0;
    /* The career ends with all 26 MasterMinds arrested or ten years (120 cases) served. */
    if (asm_masterminds_arrested == 26)
        strcpy(shm_scratch, dat_note_11);
    if (shm_campaign.cases == 120)
        strcpy(shm_scratch, dat_note_12);
    /* Retirement: the portrait screen, then out of the game. */
    if (asm_masterminds_arrested == 26 || shm_campaign.cases == 120) {
        strcat(shm_scratch, dat_note_13);
        c_portrait_screen();
        c_hook_hand_back(UNSET_ARGS(0));
        COMM()->next_module = NONE_EXIT;
        exit(UNSET_ARGS(0));
    }
    /* Continue, Save or End; a MasterMind taken below Global Crisis also offers a new level. */
    for (;;) {
        strcpy(shm_scratch, dat_note_14);
        if (shm_difficulty < 3
            && asm_case_flags & CASE_MASTERMIND)
            strcat(shm_scratch,
                       dat_note_15);
        reply = c_ask_menu((rt_addr) shm_scratch,
                                   80, 80);
        if (reply != 3)
            break;
        /* Change Difficulty Level: the bump is lost to the level chosen; then the menu again. */
        shm_difficulty++;
        strcpy(shm_scratch, dat_note_16);
        shm_difficulty = c_clamp(
            c_ask_menu((rt_addr) shm_scratch, 80, 80),
            0, 3);
    }
    /* End Game: leave the program. */
    if (reply == 2) {
        c_hook_hand_back(UNSET_ARGS(0));
        COMM()->next_module = NONE_EXIT;
        exit(UNSET_ARGS(0));
    }
    /* Save Game: marked as between missions, clock 0, case city 1; then continue or end. */
    if (reply == 1) {
        shm_options |= OPT_MISSION_ENDED;
        shm_clock_minutes = 0;
        shm_case_city = 1;
        c_save_menu();
        strcpy(shm_scratch, dat_note_17);
        if (c_ask_menu((rt_addr) shm_scratch, 80, 80)
            == 1) {
            c_hook_hand_back(UNSET_ARGS(0));
            COMM()->next_module = NONE_EXIT;
            exit(UNSET_ARGS(0));
        }
    }
    /* Continuing: arm the briefing pan again, variant 4, for what comes next. */
    c_seq_set_var(0, 4);
    drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
    c_pan_arm(dat_note_18, 0, 0);
}

/* The chronology: the case log replayed over the participant grid, one screen
 * an entry until the log ends or Esc. `shown` is 0 while nothing is drawn, -1
 * once a line is on screen and 1 when the entry is skipped. `code` is written
 * and never read.
 */
void c_chronology(void)
{
    INT org;
    INT code;
    INT mask;
    INT reserve;
    INT slotno;
    INT old;
    INT item;
    INT empty;
    INT untouched;
    INT shown;
    INT topic;

    /* The participant grid across the top 104 rows: every real role's cell. */
    drv_jump_gfx_set_colour_map(&shd_colours_face, &shd_colours_face);
    drv_real_fill_rect(shd_screen, 0, 0, 320, 104, 7);
    shd_screen->bg_pen = 1;
    for (item = 0; item < asm_grid_in_play; item++)
        c_grid_cell(item);
    /* Flash the MasterMind's cells, then off CGA lay the 9-and-7 pattern over the grid. */
    c_grid_connections(0);
    if (shm_cga == 0)
        drv_jump_gfx_fill(shd_screen, 0, 0, 320, 104, 9, 7);
    /* The text panel below the grid. */
    drv_real_fill_rect(shd_screen, 0, 104, 320, 96, 1);
    shd_screen->bg_pen = 9;
    /* At the start of the case nobody holds any of the four crime objects. */
    for (slotno = 0; slotno < 4; slotno++)
        shm_crime_block[slotno].u2 = 0xff;
    /* Replay the case log in order, skipping an entry whose kind is -1. */
    for (item = 0; item < shm_log_count; item++) {
        if (shm_log[item].kind != -1) {
            /* A fresh panel and grid pattern for each entry, headed by when it happened. */
            topic = shm_log[item].slot;
            shown = 0;
            drv_real_fill_rect(shd_screen, 8, 112, 304, 80,
                              shm_cga ? 0 : 9);
            if (shm_cga == 0)
                drv_jump_gfx_fill(shd_screen, 0, 0, 320, 104, 9, 1);
            c_draw_centred((str_addr) (
                c_timestamp(
                    shm_log[item].minute) + 9),
                160, 114, 7);
            switch (shm_log[item].kind) {
            /* LOG_MESSAGE: an intercepted message, never seen by the player, is passed over. */
            case 0:
                if (shm_log[item].known == 0) {
                    shown = 1;
                    break;
                }
                /* The receiving side of a crime event is told by its sender's entry instead. */
                if (!((shm_crime_events[topic].flags & CRIME_RECEIVED)
                      && topic >= 0)) {
                    /* The sender: name, crime role, and organisation/city. */
                    strcpy(shm_scratch, dat_str_empty_2);
                    org = shm_log[item].from;
                    c_person_name(org);
                    code = shm_crime_events[topic].main_participant;
                    if (topic >= 0) {
                        strcat(shm_scratch, dat_str_paren_open);
                        strcat(shm_scratch,
                                   shm_crime_roles[shm_crime_events[topic].main_participant].name);
                        strcat(shm_scratch, dat_str_paren_close);
                        c_grid_highlight_cell(shm_crime_events[topic].main_participant);
                    } else {
                        /* No crime event behind it: no role, so light all the sender's cells. */
                        c_grid_highlight_org(org);
                        strcat(shm_scratch, dat_str_space);
                    }
                    if (org != 0) {
                        strcat(shm_scratch,
                                   shm_orgs[shm_suspects[org].org].long_name);
                        strcat(shm_scratch, dat_str_slash);
                        strcat(shm_scratch,
                                   (char *) (shm_cities[shm_suspects[org].city].name));
                    }
                    c_trim_to_width(300);
                    c_draw_centred(shm_scratch,
                                       160, 124, 15);
                    /* No crime event: "sent message to" the recipient, then the message itself. */
                    if (topic < 0) {
                        strcpy(shm_scratch, dat_str_sent_message);
                        c_person_name(shm_log[item].to);
                        c_draw_centred(shm_scratch,
                                           160, 132, 15);
                        c_draw_line(20, 150, 299, 150, 7);
                        strcpy(shm_scratch, dat_str_caret);
                        c_say_event_text(topic);
                        strcat(shm_scratch, dat_str_caret_2);
                        c_draw_message(35, 20, 152, 14);
                        c_grid_highlight_org(shm_log[item].to);
                    } else {
                        /* A crime event: its description, or "sent message/package to". */
                        strcpy(shm_scratch, dat_str_empty_3);
                        strcat(shm_scratch,
                                   shm_crime_events[topic].description);
                        mask = shm_crime_events[topic].flags;
                        if (mask & 0x200)
                            strcpy(shm_scratch, dat_str_sent_message_2);
                        if (mask & 0x400)
                            strcpy(shm_scratch, dat_str_sent_package);
                        c_draw_centred(shm_scratch,
                                           160, 132, 15);
                        /* An event with a far end: the recipient's name, role and whereabouts. */
                        if (shm_crime_events[topic].flags & CRIME_KIND) {
                            strcpy(shm_scratch, dat_str_empty_4);
                            org = shm_log[item].to;
                            c_person_name(org);
                            strcat(shm_scratch, dat_str_paren_open_2);
                            strcat(shm_scratch,
                                       shm_crime_roles[CRIME_FAR_CELL(shm_crime_events[topic])].name);
                            strcat(shm_scratch, dat_str_paren_close_2);
                            if (org != 0) {
                                strcat(shm_scratch,
                                           shm_orgs[shm_suspects[org].org].long_name);
                                strcat(shm_scratch, dat_str_slash_2);
                                strcat(shm_scratch,
                                           shm_cities[shm_suspects[org].city].name);
                            }
                            c_trim_to_width(300);
                            c_draw_centred(shm_scratch,
                                               160, 140, 15);
                            c_grid_highlight_cell(
                                *(unsigned char *) &shm_crime_events[topic].flags);
                            /* Under a rule, what the message said; a package has no text. */
                            c_draw_line(20, 150, 299, 150, 7);
                            if (!(mask & 0x400)) {
                                strcpy(shm_scratch, dat_str_caret_3);
                                c_say_event_text(topic);
                                strcat(shm_scratch, dat_str_caret_4);
                                c_draw_message(35, 12, 152, 14);
                            }
                        }
                    }
                    shown = -1;
                } else
                    shown = 1;
                /* Objects the event hands over pass to its main participant's suspect. */
                org = shm_crime_roles[shm_crime_events[topic].main_participant].suspect;
                for (slotno = 0; slotno < 4; slotno++) {
                    if (shm_crime_events[topic].objects
                        & 1 << slotno) {
                        /* Let the player read what is up before clearing the panel. */
                        if (shown <= 0)
                            c_wait_key();
                        drv_real_fill_rect(shd_screen, 8, 112, 304, 80,
                                          shm_cga ? 0 : 9);
                        /* Move the object's icon from its old holder's cells to the new one's. */
                        old = shm_crime_block[slotno].u2;
                        shm_crime_block[slotno].u2 = org;
                        c_grid_restack(old);
                        c_grid_restack(org);
                        /* "Name (role) now has the object". */
                        shm_scratch[0] = 0;
                        c_person_name(org);
                        code = shm_crime_events[topic].main_participant;
                        strcat(shm_scratch, dat_str_paren_open_3);
                        strcat(shm_scratch,
                                   shm_crime_roles[shm_crime_events[topic].main_participant].name);
                        strcat(shm_scratch, dat_str_paren_close_3);
                        c_draw_centred(shm_scratch,
                                           160, 140, 15);
                        strcpy(shm_scratch, dat_str_now_has);
                        strcat(shm_scratch,
                                   (char *) shm_crime_block[slotno].name);
                        c_draw_centred(shm_scratch,
                                           160, 148, 15);
                        shown = -1;
                        /* Note for the report that this object changed hands. */
                        asm_report_slots |= 1 << slotno;
                    }
                    /* An object the event destroys leaves its holder. */
                    if (shm_crime_events[topic].objects
                        & 0x100 << slotno) {
                        old = shm_crime_block[slotno].u2;
                        shm_crime_block[slotno].u2 = 0xff;
                        c_grid_restack(old);
                    }
                }
                break;
            /* LOG_DEPARTED: "<suspect> left <city>". */
            case 1:
                strcpy(shm_scratch, dat_str_empty_5);
                c_person_name(topic >> 8);
                strcat(shm_scratch, dat_str_left);
                strcat(shm_scratch,
                           shm_cities[(INT) (unsigned char) topic].name);
                break;
            /* LOG_TRAVEL: "You traveled to <city>". */
            case 4:
                strcpy(shm_scratch, dat_str_traveled);
                strcat(shm_scratch, shm_cities[topic].name);
                break;
            /* LOG_BREAK_IN: "You broke in to <organisation>/<city>". */
            case 5:
                strcpy(shm_scratch, dat_str_broke);
                strcat(shm_scratch,
                           shm_orgs[topic >> 8].long_name);
                strcat(shm_scratch, dat_str_slash_3);
                strcat(shm_scratch,
                           shm_cities[(INT) (unsigned char) topic].name);
                break;
            /* LOG_ARRESTED: "You arrested <suspect>", and bars over the suspect's cells. */
            case 6:
                strcpy(shm_scratch, dat_str_arrested);
                c_person_name(topic);
                c_draw_centred(shm_scratch,
                                   160, 144, 15);
                c_grid_bar_cell(topic);
                shown = -1;
                break;
            /* LOG_OBJECT_REMOVED: "You confiscated <object>", taken from whoever held it. */
            case 7:
                strcpy(shm_scratch, dat_str_confiscated);
                strcat(shm_scratch, (char *) shm_crime_block[topic].name);
                old = shm_crime_block[topic].u2;
                shm_crime_block[topic].u2 = 0xff;
                c_grid_restack(old);
                asm_report_topics |= 1 << topic;
                break;
            /* LOG_HIDING: "<suspect> went into hiding". */
            case 8:
                shm_scratch[0] = 0;
                c_person_name(topic);
                strcat(shm_scratch, dat_str_went_into_hiding);
                c_draw_centred(shm_scratch,
                                   160, 140, 15);
                /* Look for an event of the suspect's still pending, happen_tick 999. */
                old = -1;
                for (slotno = 0; slotno < shm_crime_event_count; slotno++)
                    if (shm_crime_events[slotno].happen_tick == 999
                        && shm_crime_roles[shm_crime_events[slotno].main_participant].suspect
                            == topic) {
                            old = slotno;
                            break;
                        }
                /* None left is "Mission completed."; one left is "Unable to complete mission." */
                if (old == -1) {
                    strcpy(shm_scratch, dat_str_mission_completed);
                } else {
                    strcpy(shm_scratch, dat_str_unable);
                    c_draw_centred(shm_scratch,
                                       160, 148, 15);
                    strcpy(shm_scratch, dat_str_complete_mission);
                }
                c_draw_centred(shm_scratch,
                                   160, 156, 15);
                c_grid_connections(topic);
                shown = -1;
                break;
            /* LOG_AT_LARGE, LOG_ESCAPED, LOG_EXCHANGED: the suspect back in play, face restored. */
            case 9:
            case 10:
            case 13:
                shm_scratch[0] = 0;
                c_person_name(topic);
                switch (shm_log[item].kind) {
                case 9:
                    strcat(shm_scratch, dat_str_came_out_hiding);
                    break;
                case 10:
                    strcat(shm_scratch, dat_str_escaped_from_jail);
                    break;
                case 13:
                    strcat(shm_scratch, dat_str_released_by_exchange);
                    break;
                }
                c_draw_centred(shm_scratch,
                                   160, 144, 15);
                c_grid_redraw_org(topic);
                shown = -1;
                break;
            /* LOG_BULLETIN: left out of the replay. */
            case 11:
                shown = 1;
                break;
            /* LOG_TURNED: "You turned <suspect>", their cells lit, then the 9-and-2 pattern. */
            case 12:
                strcpy(shm_scratch, dat_str_turned);
                c_person_name(topic);
                c_grid_highlight_org(topic);
                if (shm_cga == 0)
                    drv_jump_gfx_fill(shd_screen, 0, 0, 320, 104, 9, 2);
                break;
            }
            /* The one-line kinds are drawn here, trimmed to the panel. */
            if (shown == 0) {
                c_trim_to_width(300);
                c_draw_centred(shm_scratch,
                                   160, 144, 15);
            }
            /* Wait on anything shown; Esc ends the replay. */
            if (shown <= 0 && c_wait_key() == KEY_ESC)
                break;
        }
    }
}

/* One participant cell of the grid, four to a row: the frame, the face and
 * body of the role's suspect from its visuals word, and the caption.
 */
void c_grid_cell(INT cell)
{
    INT x;
    INT y;
    INT n;

    /* Cells are 80 by 52, four to a row. */
    x = cell % 4 * 80;
    y = cell / 4 * 52;
    /* The cell's background inside a one-pixel margin. */
    drv_real_fill_rect(shd_screen, x + 1, y + 1, 78, 50,
                      shm_cga ? 3 : 1);
    /* The suspect in the role, face and body, from their visuals word. */
    n = shm_suspects[shm_crime_roles[cell].suspect].visuals;
    c_draw_face(n, x + 45, y + 8);
    c_draw_sprite((n & 1 ? SPRITE_BODIES_1 : SPRITE_BODIES_0) + (n & 3), x + 35, y + 33);
    /* The role's name across the top. */
    c_grid_caption(x, y, cell);
}

/* A participant cell's caption: the role's name, split at its first space onto
 * two lines. shm_cga picks the text primitive.
 */
void c_grid_caption(INT x, INT y, INT cell)
{
    str_addr at;

    /* Find the first space in the role's name, where a second line starts. */
    strcpy(shm_scratch,
               shm_crime_roles[cell].name);
    at = strstr(shm_scratch, dat_str_space_2);
    /* On CGA, plain text: one line, or the name split over two. */
    if (shm_cga != 0) {
        if (at == 0) {
            c_write_text((rt_addr) shm_scratch,
                               x + 2, y + 2, 5);
        } else {
            *at = 0;
            c_write_text((rt_addr) shm_scratch,
                               x + 2, y + 2, 5);
            c_write_text((drv_addr) (at + 1), x + 2, y + 10, 5);
        }
    } else {
        /* Otherwise the same through the trimmed writer. */
        if (at == 0) {
            c_write_text_trimmed((rt_addr) shm_scratch,
                               x + 2, y + 2, 5);
        } else {
            *at = 0;
            c_write_text_trimmed((rt_addr) shm_scratch,
                               x + 2, y + 2, 5);
            c_write_text_trimmed((drv_addr) (at + 1), x + 2, y + 10, 5);
        }
    }
}

/* Highlight every grid cell whose suspect is `org`; one can hold several. */
void c_grid_highlight_org(INT org)
{
    INT i;

    /* Every role the suspect fills has a cell of its own. */
    for (i = 0; i < asm_grid_in_play; i++)
        if (shm_crime_roles[i].suspect == org)
            c_grid_highlight_cell(i);
}

/* Highlight one grid cell with a dithered fill of 1 and 9, except on CGA. */
void c_grid_highlight_cell(INT cell)
{
    INT x;
    INT y;

    /* The cell's corner, then the pattern over its inside; CGA goes without. */
    x = cell % 4 * 80;
    y = cell / 4 * 52;
    if (shm_cga == 0)
        drv_jump_gfx_fill(shd_screen, x + 1, y + 1, 78, 50, 1, 9);
}

/* Redraw the objects suspect `org` holds on each of its cells: the strip is
 * repainted in the cell's own colour, then each object is drawn a row above
 * the last. An `org` of -1 draws nothing.
 */
void c_grid_restack(INT org)
{
    INT cell;
    INT x;
    INT y;
    INT j;
    INT tint;

    /* -1 is nobody: an object that had no holder. */
    if (org == -1)
        return;
    for (cell = 0; cell < asm_grid_in_play; cell++) {
        if (shm_crime_roles[cell].suspect != org)
            continue;
        x = cell % 4 * 80;
        y = cell / 4 * 52;
        /* Wipe the 16-wide strip on the cell's left in the colour just above it. */
        tint = drv_jump_gfx_get_pixel(0, x + 1, y + 18);
        drv_real_fill_rect(shd_screen, x + 1, y + 19,
                          16, 32, tint);
        /* Stack the icon of each object the suspect holds, bottom up, from page 2. */
        for (j = 0; j < 4; j++)
            if (shm_crime_block[j].u2 == org) {
                drv_jump_gfx_copy_rect(asm_replay_page, shm_crime_block[j].u1 << 4,
                                    0, 16, 16, shd_screen, x + 1, y + 35);
                y -= 16;
            }
    }
}

/* Bar over every cell of the arrested suspect `org`: the cell is framed as a
 * panel and crossed by vertical bars, a light line with a dark one beside.
 */
void c_grid_bar_cell(INT org)
{
    INT x;
    INT y;
    INT box;
    INT off;

    for (box = 0; box < asm_grid_in_play; box++) {
        if (shm_crime_roles[box].suspect != org)
            continue;
        x = box % 4 * 80;
        y = box / 4 * 52;
        /* A frame of colour 7 around a window over the face: top, left, right and bottom. */
        drv_real_fill_rect(shd_screen, x, y, 80, 11, 7);
        drv_real_fill_rect(shd_screen, x, y + 10, 24, 42, 7);
        drv_real_fill_rect(shd_screen, x + 72, y + 10, 8, 42, 7);
        drv_real_fill_rect(shd_screen, x, y + 40, 80, 12, 7);
        /* The window's sill, then a bar every six pixels across it. */
        c_draw_line(x + 24, y + 39, x + 71, y + 39, 8);
        for (off = 24; off < 72; off += 6) {
            c_draw_line(x + off, y + 11, x + off, y + 39, 7);
            c_draw_line(x + off + 1, y + 11, x + off + 1,
                               y + 39, 0);
        }
        /* The frame covered the caption, so write it again. */
        c_grid_caption(x, y, box);
    }
}

/* Flash every cell whose suspect is `org`: its picture area is filled in turn
 * with each colour from 2 to 0Fh, dithered with 0.
 */
void c_grid_connections(INT org)
{
    INT bar;
    INT x;
    INT y;
    INT box;

    for (box = 0; box < asm_grid_in_play; box++) {
        if (shm_crime_roles[box].suspect != org)
            continue;
        x = box % 4 * 80;
        y = box / 4 * 52;
        /* Cycle the area below the caption through colours 2 to 15. */
        for (bar = 1; bar < 16; bar++)
            if (bar != 1)
                drv_jump_gfx_fill(shd_screen, x + 1, y + 9,
                                  78, 42, bar, 0);
    }
}

/* Redraw every cell whose suspect is `org`, putting its face back. `junk`,
 * `bare` and `dead` are never read.
 */
void c_grid_redraw_org(INT org)
{
    INT junk;
    INT bare;
    INT dead;
    INT n;

    /* Drawing the cell afresh takes off the bars or the highlight. */
    for (n = 0; n < asm_grid_in_play; n++)
        if (shm_crime_roles[n].suspect == org)
            c_grid_cell(n);
}
