/* CAMPAIGN-MISSION-END-2.C -- more of the module's own routines in CAMPAIGN-MISSION-END.C's unit, after shared/CAMPAIGN-MISSION-END.C. */
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

/* Write `minutes` since the case opened into the "00:00 AM Jun 00" template
 * and answer it. The month is the case number's: a campaign walks through the
 * year a case at a time.
 */
rt_addr c_timestamp(INT minutes)
{
    INT hour;

    /* The minutes past the hour, as two digits. */
    asm_case_minute = minutes % 60;
    dat_date_template[3] = (INT) asm_case_minute / 10 + '0';
    dat_date_template[4] = (INT) asm_case_minute % 10 + '0';
    /* The hour on a twelve-hour clock, and AM or PM by the day's hour. */
    minutes /= 60;
    asm_case_hour = minutes % 24;
    hour = ((INT) asm_case_hour - 1) % 12 + 1;
    dat_date_template[0] = hour / 10 + '0';
    dat_date_template[1] = hour % 10 + '0';
    dat_date_template[6] = (INT) asm_case_hour > 11 ? 'P' : 'A';
    /* The month is the career's: one case a month, from the case count. */
    strcpy(dat_date_template + 9,
               (char *) shd_month_names[shm_campaign.cases
                                                  % 12]);
    /* Then the day of the case, counting from 1, as two digits. */
    strcat(dat_date_template, dat_str_day_number);
    asm_case_day = minutes / 24 + 1;
    dat_date_template[13] = (INT) asm_case_day / 10 + '0';
    dat_date_template[14] = (INT) asm_case_day % 10 + '0';
    return (rt_addr) dat_date_template;
}

/* Mark the whole case known so the chronology can show all of it: every
 * suspect with a face, every role and the suspect holding it, every log entry
 * and every crime event.
 */
void c_reveal_case(void)
{
    INT i;

    /* Every fact about every suspect in play; a free record has no face. */
    for (i = 0; i < shm_suspect_count; i++)
        if (shm_suspects[i].visuals != 0)
            shm_suspects[i].flags = -1;
    /* Every role shown, and each one's holder known to fill it. */
    for (i = 0; i < shm_crime_role_count; i++) {
        *((char *) &shm_crime_roles[i].flags + 1) |= ROLE_REVEALED >> 8;
        shm_suspects[shm_crime_roles[i].suspect].role_known |= 1 << i;
    }
    /* All of every log entry. */
    for (i = 0; i < shm_log_count; i++)
        shm_log[i].known |= 0xf;
    /* And every crime event, by the top bit of its flag word. */
    for (i = 0; i < shm_crime_event_count; i++)
        *((char *) &shm_crime_events[i].flags + 1) |= CRIME_REVEALED >> 8;
}

/* The Efficiency Report: a panel per participant, object moved, crime done or
 * prevented and undetected double agent, a key after each; answers the rating
 * `25 * earned / (possible / 40)`, at least 0. Sets asm_case_flags as it
 * scores. `unused` and `scrap` are never read.
 */
INT c_efficiency_report(void)
{
    INT ring;
    INT unused;
    INT subj;
    INT total;
    INT pts;
    INT x_indent;
    INT scrap;
    INT yat;
    INT earned;
    INT item;
#ifdef CRIME_ULTIMATE_PLOT_FIX
    INT whole;  /* the case's crime-event scores summed, capped at 10 */
#endif

    /* A fresh page, the panels starting near its top left. */
    c_page_frame(dat_str_efficiency_report, 14);
    yat = 11;
    x_indent = 8;
    drv_jump_gfx_set_colour_map(&dat_colours_grid, &dat_colours_grid);
    /* A panel per participant in the case's crime grid, headed by the role's name. */
    for (item = 0; item < asm_grid_in_play; item++) {
        c_text_panel(x_indent, yat);
        strcpy(shm_scratch,
                   shm_crime_roles[item].name);
        c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 100,
                           yat + 2, 0);
        ring = shm_crime_roles[item].suspect;
        /* Who held the role, unless it is the MasterMind still free and so never unmasked. */
        if (!((*(INT *) &shm_crime_roles[item].flags
               & ROLE_MASTERMIND)
              && shm_suspects[ring].alert_level != ALERT_ARRESTED
              && shm_suspects[ring].alert_level != ALERT_TURNED)) {
            /* Their face, then name and rank... */
            c_draw_face_panel(shm_suspects[ring].visuals,
                               x_indent + 102, yat + 16);
            shm_scratch[0] = 0;
            c_person_name(ring);
            strcat(shm_scratch, dat_str_org_sep);
            strcat(shm_scratch,
                       (char *) shd_clue_kinds
                       [shm_crime_roles[item].rank]);
            c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 100,
                               yat + 72, 0);
            /* ...and their organisation and city. */
            shm_scratch[0] = 0;
            strcat(shm_scratch,
                       shm_orgs[shm_suspects[ring].org].long_name);
            strcat(shm_scratch, dat_str_org_slash);
            strcat(shm_scratch,
                       (char *) (shm_cities[shm_suspects[ring].city].name));
            c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 100,
                               yat + 80, 0);
        }
        /* The outcome: an arrest earns 5 and a turn 10, each counted in the case flags. */
        drv_jump_gfx_set_colour_map(&dat_colours_grid, &dat_colours_grid);
        strcpy(shm_scratch, dat_str_at_large);
        earned = 0;
        if (shm_suspects[ring].alert_level == ALERT_ARRESTED) {
            earned = 5;
            strcpy(shm_scratch, dat_str_arrested_2);
            asm_case_flags++;
        } else if (shm_suspects[ring].alert_level == ALERT_TURNED) {
            earned = 10;
            strcpy(shm_scratch, dat_str_turned_2);
            asm_case_flags++;
        } else {
            /* At large: a point for name, org and city known before the reveal, one for a photo. */
            if ((shm_suspects[ring].score & 0xe) == 0xe)
                earned++;
            if (shm_suspects[ring].score & 1)
                earned++;
        }
        /* Suspect 0, the MasterMind, taken: flagged for the career record. */
        if (ring == 0 && earned >= 5)
            asm_case_flags |= CASE_MASTERMIND;
        c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 24,
                           yat + 2, 12);
        /* Times rank plus 3, out of 15 plus 5 a rank; both four times over for the MasterMind. */
        earned = (shm_crime_roles[item].rank
                  + 3) * earned;
        pts = shm_crime_roles[item].rank
              * 5 + 15;
        if (ring == 0) {
            earned <<= 2;
            pts <<= 2;
        }
        /* "EP: earned of possible", added to the case's running totals. */
        strcpy(shm_scratch, dat_str_ep_0);
        strcat(shm_scratch,
                   (char *) itoa(earned, asm_number_digits_2, 10));
        strcat(shm_scratch, dat_str_ep_of);
        strcat(shm_scratch,
                   (char *) itoa(pts, asm_number_digits_2, 10));
        c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 244,
                           yat + 2, 1);
        asm_case_points += earned;
        asm_report_total += pts;
        /* After a key, the next panel goes a step further down, at a random indent. */
        x_indent = c_random_below(14) + 2;
        yat += 10;
        c_wait_key();
    }
    /* A panel per crime object in play, worth 50 if it was confiscated. */
    for (item = 0; item < 4; item++)
        if (asm_report_slots & 1 << item) {
            c_text_panel(x_indent, yat);
            asm_report_total += 50;
            strcpy(shm_scratch, (char *) shm_crime_block[item].name);
            c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 100,
                               yat + 2, 0);
            strcpy(shm_scratch, dat_str_ep_50);
            if (asm_report_topics & 1 << item) {
                c_write_text_trimmed(dat_str_confiscated_2, x_indent + 8, yat + 2, 12);
                strcpy(shm_scratch, dat_str_ep_50_2);
                asm_case_points += 50;
            } else {
                c_write_text_trimmed(dat_str_not_found, x_indent + 24, yat + 2, 12);
            }
            strcat(shm_scratch, dat_str_of_50);
            c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 240,
                               yat + 2, 1);
            x_indent = c_random_below(14) + 2;
            yat += 10;
            c_wait_key();
        }
#ifdef CRIME_ULTIMATE_PLOT_FIX
    /* What the whole crime is worth, capped at 10, to judge a major step against. */
    whole = 0;
    for (item = 0; item < shm_crime_event_count; item++)
        whole += shm_crime_events[item].score;
    if (whole > 10)
        whole = 10;
#endif
    /* Every scoring crime event a logged message carried was done: 40 possible per score point. */
    total = 0;
    for (item = 0; item < shm_log_count; item++)
        if (shm_log[item].kind == 0) {
            subj = shm_log[item].slot;
            if (shm_crime_events[subj].score != 0) {
                c_text_panel(x_indent, yat);
                total += shm_crime_events[subj].score;
                /* A big enough step means the crime was committed: the set moves on. */
#ifdef CRIME_ULTIMATE_PLOT_FIX
                if (shm_crime_events[subj].score * 2 >= whole)
#else
                if (shm_crime_events[subj].score >= 5)
#endif
                    asm_case_flags |= CASE_CRIME_DONE;
                earned = shm_crime_events[subj].score * 40;
                /* The event's sentence, naming its participant's role unless it is a bulletin. */
                strcpy(shm_scratch,
                           shm_crime_events[subj].description);
                if (!(shm_crime_events[subj].flags
                      & 0x2000)) {
                    strcat(shm_scratch, dat_str_of_org);
                    strcat(shm_scratch,
                               shm_crime_roles[shm_crime_events[subj].main_participant].name);
                }
                c_draw_centred(shm_scratch, x_indent + 151,
                                   yat + 2, 0);
                /* What it cost, counted only towards the possible. */
                strcpy(shm_scratch, dat_str_ep_blank);
                strcat(shm_scratch,
                           (char *) itoa(earned, asm_number_digits_2, 10));
                c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 240,
                                   yat + 2, 4);
                asm_report_total += earned;
                /* Then what the case knows of it, wrapped below. */
                shm_scratch[0] = 0;
                c_say_event_text(subj);
                c_draw_message(32, x_indent + 8, yat + 16, 12);
                x_indent = c_random_below(14) + 2;
                yat += 10;
                c_wait_key();
            }
        }
    /* No major step done: the crime was prevented, worth 100. */
    if (!(asm_case_flags & CASE_CRIME_DONE)) {
        c_text_panel(x_indent, yat);
        c_draw_centred(dat_str_prevented_crime, x_indent + 151, yat + 2, 0);
        c_write_text_trimmed(dat_str_ep_100, x_indent + 240, yat + 2, 1);
        asm_case_points += 100;
        asm_report_total += 100;
        x_indent = c_random_below(14) + 2;
        yat += 10;
        c_wait_key();
    }
    /* Count the double agents left undetected in the CIA. */
    earned = 0;
    for (item = 0; item < 16; item++)
        if (shm_double_agent_cities & 1 << item)
            earned++;
    /* Each costs 50 possible points the player did not earn. */
    if (earned != 0) {
        c_text_panel(x_indent, yat);
        strcpy(shm_scratch, dat_str_empty_agents);
        strcat(shm_scratch,
                   (char *) itoa(earned, asm_number_digits_2, 10));
        strcat(shm_scratch, dat_str_double_agent_s);
        c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 100,
                           yat + 2, 0);
        strcpy(shm_scratch, dat_str_remained_undetected);
        c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 100,
                           yat + 10, 0);
        strcpy(shm_scratch, dat_str_within_cia);
        c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 100,
                           yat + 18, 0);
        strcpy(shm_scratch, dat_str_ep_slash);
        strcat(shm_scratch,
                   (char *) itoa(earned * 50, asm_number_digits_2, 10));
        c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 240,
                           yat + 2, 4);
        asm_report_total += earned * 50;
        x_indent = c_random_below(14) + 2;
        yat += 10;
        c_wait_key();
    }
    /* The rating: points earned per thousand possible, near enough, never negative. */
    c_text_panel(x_indent, yat);
    total = 25 * asm_case_points / (asm_report_total / 40);
    if (total < 0)
        total = 0;
    c_write_text_trimmed(dat_str_efficiency_rating, x_indent + 100, yat + 2, 0);
    strcpy(shm_scratch, dat_str_dashes);
    strcat(shm_scratch, (char *) itoa(total, asm_number_digits_2, 10));
    strcat(shm_scratch, dat_str_dashes_end);
    c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 100,
                       yat + 24, 0);
    /* And the points in total, earned of possible. */
    strcpy(shm_scratch, dat_str_ep_total);
    strcat(shm_scratch,
               (char *) itoa(asm_case_points, asm_number_digits_2, 10));
    strcat(shm_scratch, dat_str_ep_total_of);
    strcat(shm_scratch,
               (char *) itoa(asm_report_total, asm_number_digits_2, 10));
    c_write_text_trimmed((rt_addr) shm_scratch, x_indent + 240,
                       yat + 2, 1);
    c_wait_key();
    return total;
}

/* The career screen: every case closed, then the face of every MasterMind
 * arrested. A case's record is set and slot, arrests and flags, the EP
 * big-endian, and the organisation where a MasterMind was taken.
 */
void c_career_screen(void)
{
    INT type;
    INT arrests;
    INT ep;
    INT heads;
    INT x;
    INT index;
    INT y;
    INT off;
    INT value;
    INT sets;
    INT cases;

    /* The page, headed with the agent's full name. */
    c_page_frame(dat_str_career, 1);
    c_draw_centred(dat_str_career_2, 160, 16, 0);
    strcpy(shm_scratch, dat_str_max);
    strcat(shm_scratch, shm_campaign.player_name);
    strcat(shm_scratch, dat_str_remington);
    c_draw_centred(shm_scratch, 160, 24, 0);
    /* Walk the career record a case at a time, to its 0ffh end or 256 bytes. */
    off = cases = ep = arrests = heads = 0;
    y = 36;
    while (shm_campaign.record[off] != 0xff
           && off < 256) {
        sets = shm_campaign.record[off] >> 4;
        index = shm_campaign.record[off] & 0xf;
        /* "Case n, Month Year": one case a month from January 1990. */
        strcpy(shm_scratch, dat_str_case);
        strcat(shm_scratch,
                   (char *) itoa(cases + 1, asm_number_digits_3, 10));
        strcat(shm_scratch, dat_str_comma);
        strcat(shm_scratch,
                   (char *) shd_month_names[cases % 12]);
        strcat(shm_scratch, dat_str_space_3);
        strcat(shm_scratch,
                   (char *) itoa(cases / 12 + 1990, asm_number_digits_3, 10));
        /* Then its arrests, out of the flags' low nibble, kept for the career total. */
        strcat(shm_scratch, dat_str_arrests);
        value = shm_campaign.record[off + 1] & CASE_ARRESTS;
        strcat(shm_scratch,
                   (char *) itoa(value, asm_number_digits_3, 10));
        arrests += value;
        /* And its efficiency, stored high byte first. */
        strcat(shm_scratch, dat_str_ep_colon);
        value = shm_campaign.record[off + 2] * 0x100
                + shm_campaign.record[off + 3];
        strcat(shm_scratch,
                   (char *) itoa(value, asm_number_digits_3, 10));
        ep += value;
        c_write_text((rt_addr) shm_scratch, 16, y, 0);
        y += 8;
        /* Whether the crime was stopped, its type, and the first of its slot's nouns. */
        strcpy(shm_scratch,
                   (char *) (shm_campaign.record[off + 1]
                             & CASE_CRIME_DONE ? dat_str_couldn_t_stop : dat_str_prevented));
        type = dat_mission_sets[sets].mission[index];
        strcat(shm_scratch,
                   (char *) addr_crime_names[type]);
        strcat(shm_scratch, dat_str_slash_4);
        strcat(shm_scratch,
                   (char *) dat_mission_sets[sets].text[index][0]);
        c_trim_to_width(300);
        c_write_text((rt_addr) shm_scratch, 12, y, 7);
        y += 8;
        /* A MasterMind taken adds a line, its organisation in the record's fifth byte. */
        if (shm_campaign.record[off + 1] & CASE_MASTERMIND) {
            strcpy(shm_scratch, dat_str_arrested_3);
            strcat(shm_scratch,
                       (char *) dat_org_names[
                           shm_campaign.record[off + 4]]);
            strcat(shm_scratch, dat_str_mastermind);
            off++;
            c_write_text((rt_addr) shm_scratch, 12, y, 12);
            y += 8;
            heads++;
        }
        /* On to the next case, with a fresh page once this one is full. */
        y += 2;
        off += 4;
        cases++;
        if (y > 180) {
            c_wait_key();
            c_page_frame(dat_str_career_3, 1);
            y = 16;
        }
    }
    /* A rule, then the career's MasterMinds and agents arrested. */
    c_draw_line(12, y + 1, 303, y + 1, 0);
    strcpy(shm_scratch, dat_str_arrested_masterminds);
    strcat(shm_scratch, (char *) itoa(heads, asm_number_digits_3, 10));
    strcat(shm_scratch, dat_str_agents);
    strcat(shm_scratch, (char *) itoa(arrests, asm_number_digits_3, 10));
    c_write_text((rt_addr) shm_scratch, 12, y + 4, 0);
    c_wait_key();
    /* Where any MasterMind has been arrested, a gallery of their faces. */
    if ((LONG) shm_campaign.masterminds_arrested != LONG_LIT(0)) {
        /* Start past both edges, so the first face opens a page. */
        x = y = 999;
        for (off = 0; off < 26; off++) {
            if ((LONG_LIT(1) << off) & (LONG) shm_campaign.masterminds_arrested) {
                asm_masterminds_arrested++;
                /* Past the right edge, a new row. */
                if (x > 256) {
                    x = 28;
                    y += 80;
                }
                /* Past the bottom, a new page, after a key unless it is the first. */
                if (y > 140) {
                    if (y < 999)
                        c_wait_key();
                    c_page_frame(dat_str_career_4, 1);
                    y = 16;
                    c_draw_centred(dat_str_masterminds_arrested, 160, 16, 0);
                    y = 32;
                }
                /* The face with its organisation beneath, staggered up and down along the row. */
                c_draw_mastermind_face_panel(off, x, y, 0, 0);
                c_draw_centred(dat_org_names[off], x + 25, y + 56,
                                   shm_cga ? 0 : 12);
                x += 72;
                y ^= 8;
            }
        }
        c_wait_key();
    }
}
