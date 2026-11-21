/* CAMPAIGN-MISSION-START-2.C -- more of the module's own routines in CAMPAIGN-MISSION-START.C's unit, after shared/CAMPAIGN-MISSION-START.C. */
#include "FINAL.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "SCREEN.H"
#include "CSTART.H"
#include "CMISEND.H"
#include "CASERUN.H"
#include "CMISSTRT.H"
#include "ROLEFLAG.H"

/* Place one participant: its organisation, its city and its suspect record,
 * rolling whatever the role's flags leave open. Answers 0 once 999 tries run
 * out. Flag bits 0, 7 and 6 fix the organisation, 5, 4 and 1 the city, and 8
 * both to the mastermind's.
 */
INT c_place_participant(INT slot)
{
    INT site;
    INT retry;
    INT gap;
    INT role_org;
    INT role_city;

    retry = 0;
    for (;;) {
        /* A fresh clue object, nothing yet known of the role, and scans not yet building on it. */
        shm_crime_roles[slot].clue_id
            = c_random_below(0x7fff);
        shm_crime_roles[slot].clues_known = 0;
        shm_role_scan_states[slot].clue_visible_since = -1;
        shm_role_scan_states[slot].clue_visibility = 0;
        for (;;) {
            /* The organisation the role's flags fix, if any. */
            role_org = -1;
            if (shm_crime_roles[slot].flags & ROLE_MASTERMIND_ORG)
                role_org = asm_case_mastermind;
            if (shm_crime_roles[slot].flags & ROLE_CASE_ORG_1)
                role_org = shm_case_org_1;
            if (shm_crime_roles[slot].flags & ROLE_CASE_ORG_2)
                role_org = shm_case_org_2;
            /* Else any past the CIA within 12 of the case's first, in a grid column over 4. */
            if (role_org == -1) {
                do {
                    role_org = c_random_below(15) + 1;
                    gap = c_packed_distance(
                        shm_orgs[role_org].where,
                        shm_orgs[shm_case_org_1].where);
                    if (gap > 12)
                        continue;
                    if ((shm_orgs[role_org].where & 0xf) <= 4)
                        continue;
                    if (role_org != 1)
                        break;
                } while (++retry < 999);
            }
            /* The city the role's flags fix, if any. */
            role_city = -1;
            if (shm_crime_roles[slot].flags & ROLE_CASE_CITY_1)
                role_city = shm_case_city_1;
            if (shm_crime_roles[slot].flags & ROLE_CASE_CITY_2)
                role_city = shm_case_city_2;
            if (shm_crime_roles[slot].flags & ROLE_CASE_CITY_3)
                role_city = asm_case_city_3;
            /* Else a city the organisation works in, at least 8 from the case's first city. */
            if (role_city == -1) {
                do {
                    role_city = c_random_below(16);
                    gap = c_packed_distance(
                        shm_cities[role_city].where,
                        shm_cities[shm_case_city_1].where);
                    if (gap >= 8 && c_presence(role_city, role_org))
                        break;
                    retry++;
                } while (retry < 999);
            }
            /* An organisation with no presence in the city means another roll. */
            if (!c_presence(role_city, role_org)) {
                retry++;
                if (retry < 999)
                    continue;
            }
            /* The mastermind sits where the campaign's mastermind is; nobody else may sit there. */
            if (shm_crime_roles[slot].flags & ROLE_MASTERMIND) {
                role_org = shm_campaign.mastermind_org;
                role_city = shm_campaign.mastermind_city;
            } else if (role_org == shm_campaign.mastermind_org
                       && role_city == shm_campaign.mastermind_city) {
                retry++;
                if (retry < 999)
                    continue;
            }
            /* On the easiest level the first participant is in Washington, city 1. */
            if (shm_difficulty == 0 && slot == 0)
                role_city = 1;
            /* One role to a person: a suspect there who already plays one means another roll. */
            site = c_suspect_reserve(role_org, role_city, 0);
            if (site != -1
                && shm_suspects[site].role != 0) {
                retry++;
                if (retry < 999)
                    continue;
            }
            break;
        }
        if (retry < 999) {
            /* Give the suspect the role. */
            site = c_suspect_reserve(role_org, role_city, 1 << slot);
            /* A mastermind the player already has facts on is known to be the mastermind. */
            if ((shm_crime_roles[slot].flags
                 & ROLE_MASTERMIND)
                && shm_suspects[site].flags != 0)
                *(UNSIGNED_INT *) &shm_suspects[site].role_known
                    |= 1 << slot;
            /* A suspect out of play does not take the role, */
            if (shm_suspects[site].alert_level < 0)
                *(UNSIGNED_INT *) &shm_suspects[site].role
                    &= ~(1 << slot);
        }
        /* and then the whole placement is rolled again, from a new clue object. */
        if (shm_suspects[site].alert_level < 0) {
            retry++;
            if (retry < 999)
                continue;
        }
        break;
    }
    /* Tie the role to its suspect; a widow's suspect is made a woman. */
    shm_crime_roles[slot].suspect = site;
    if (shm_crime_roles[slot].flags & ROLE_WIDOW)
        *(unsigned char *) &shm_suspects[site].visuals
            &= 0xfe;
    /* Whether the role was placed before the tries ran out. */
    return retry < 999 ? 1 : 0;
}

/* The briefing: where the operation is (`region` names the continent), who is
 * behind it and what the agent must do; below difficulty 2 it names one
 * organisation. The copyright screen comes next, unless passed and not the
 * first case.
 */
void c_briefing(INT region)
{
    INT org;

    /* First page: an operation is being prepared, and in which part of the world. */
    strcpy(shm_scratch, dat_str_we_have_indications);
    strcat(shm_scratch, dat_str_operation_preparation);
    switch (region) {
    case 0:
        strcat(shm_scratch, dat_str_europe);
        break;
    case 1:
        strcat(shm_scratch, dat_str_africa_middle_east);
        break;
    case 2:
        strcat(shm_scratch, dat_str_central_america);
        break;
    }
    /* On the two easiest levels, name the organisation of one participant, and mark it known. */
    if (shm_difficulty < 2) {
        org = shm_suspects[shm_crime_roles[(INT) c_random_below(shm_crime_role_count)].suspect].org;
        strcat(shm_scratch, dat_str_the);
        strcat(shm_scratch, shm_orgs[org].long_name);
        strcat(shm_scratch, dat_str_known_involved);
        shm_orgs[org].known |= 1;
    }
    c_wrap_message(40);
    c_ask_menu((rt_addr) shm_scratch, 8, 149);
    /* Second page: the orders, with a warning of double agents past the easiest level. */
    strcpy(shm_scratch, dat_str_mission_prevent);
    strcat(shm_scratch, dat_str_capture_as_many);
    if (shm_difficulty)
        strcat(shm_scratch, dat_str_caution_one_more_double);
    c_clear_message_panel();
    c_wrap_message(40);
    c_ask_menu((rt_addr) shm_scratch, 8, 149);
    /* The copyright screen, unless passed and not the first case; failed, it is off to practice, */
    if (!((shm_campaign.cases != 0
           && (shm_options & OPT_COPYRIGHT_SKIP))
          || c_copy_protection())) {
        c_seq_set_var(0, 4);
        strcpy(shm_scratch, dat_str_i_m_afraid_re);
        strcat(shm_scratch, dat_str_perhaps_should_practice);
    } else {
        /* passed, on to the case with its first leads, the screen skipped from the next case on. */
        c_seq_set_var(0, 1);
        shm_scratch[0] = 0;
        if (shm_campaign.cases == 0)
            strcat(shm_scratch, dat_str_ok_re_cleared);
        strcat(shm_scratch, dat_str_here_some_info_we);
        strcat(shm_scratch, dat_str_we_think_s_linked);
        shm_options |= OPT_COPYRIGHT_SKIP;
    }
    /* The verdict on its own page, over the briefing animation. */
    drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
    c_pan_arm(dat_str_briefing_pan_4, 0, 0);
    c_wrap_message(40);
    c_ask_menu((rt_addr) shm_scratch, 8, 149);
}

/* Read CRIMEn.DTA: the participant roles, the crime events and the crime
 * block. The file name is patched in place.
 */
void c_read_crime(INT n)
{
    INT fd;

    /* The mission type's file: crime0.dta to crime9.dta, or crime10.dta and up. */
    dat_CRIME_DTA_NAME[5] = n + '0';
    if (n > 9) {
        strcpy(dat_CRIME_DTA_NAME + 5, dat_str_10_dta);
        dat_CRIME_DTA_NAME[6] = n % 10 + '0';
    }
    /* The two counts first, then as many roles and events as they say, then the block. */
    fd = open((rt_addr) dat_CRIME_DTA_NAME, 0x8000);
    ASSERT_FD_SUCCESS(fd, dat_CRIME_DTA_NAME);
    read(fd, (rt_addr) &shm_crime_role_count, 2);
    read(fd, (rt_addr) &shm_crime_event_count, 2);
    read(fd, (rt_addr) shm_crime_roles, shm_crime_role_count * 48);
    read(fd, (rt_addr) shm_crime_events, shm_crime_event_count * 44);
    read(fd, (rt_addr) shm_crime_block, 72);
    close(fd);
    LOG_MESSAGE3("crime file %s: %d grid cell(s), %d crime event(s)",
                 (const char *) dat_CRIME_DTA_NAME, (int) shm_crime_role_count,
                 (int) shm_crime_event_count);
}

/* Read WORLDn.DTA: the cities and the organisations that work out of them. */
void c_read_world(INT n)
{
    INT towns;
    INT org_cnt;
    INT handle;

    /* The region's file, world0.dta to world2.dta. */
    dat_str_world[5] = n + '0';
    towns = 16;
    org_cnt = 16;
    /* Its two counts, then that many city records and organisation records. */
    handle = open(dat_str_world, 0x8000);
    ASSERT_FD_SUCCESS(handle, dat_str_world);
    read(handle, &towns, 2);
    read(handle, &org_cnt, 2);
    read(handle, (rt_addr) shm_cities, towns * 34);
    read(handle, (rt_addr) shm_orgs, org_cnt * 36);
    close(handle);
}
