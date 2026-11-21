/* CIABLDG.C -- the CIA building's floors and the menus on each. */
#include "GAME.H"
#include "BLOCK.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DECODE.H"
#include "DIALOG.H"
#include "CASE.H"
#include "CAMPSTAT.H"
#include "RESULT.H"

/* The floor menu's entries, in the order dat_note_06 lists them. */
enum cia_floor_entry {
    CIA_FLOOR_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    CIA_FLOOR_DATA_SECTION = 0,
    CIA_FLOOR_INTELLIGENCE_SECTION = 1,
    CIA_FLOOR_CRYPTO_BRANCH = 2,
    CIA_FLOOR_LEAVE_BUILDING = 3
};

/* The intelligence section's entries, in the order dat_note_08 lists them. */
enum cia_intelligence_entry {
    CIA_INTELLIGENCE_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    CIA_INTELLIGENCE_LOCAL_SCAN = 0,
    CIA_INTELLIGENCE_INTERNATIONAL_SCAN = 1,
    CIA_INTELLIGENCE_ACTIVE_WIRE_TAPS = 2,
    CIA_INTELLIGENCE_ACCUSE_DOUBLE_AGENT = 3,
    CIA_INTELLIGENCE_CHECK_WITH_SAM = 4
};

/* The data section's entries, in the order dat_note_15 and dat_note_16 list them. */
enum cia_data_entry {
    CIA_DATA_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    CIA_DATA_REVIEW_CLUES = 0,
    CIA_DATA_REVIEW_SUSPECTS = 1,
    CIA_DATA_INSIDE_INFORMATION = 2,
    CIA_DATA_NEWS_BULLETINS = 3,
    CIA_DATA_ORGANIZATION_SUMMARY = 4,
    CIA_DATA_CITY_SUMMARY = 5,
    CIA_DATA_ACTIVITY_REPORTS = 6
};

/* The crypto branch's entries, in the order dat_note_18 lists them. */
enum cia_crypto_entry {
    CIA_CRYPTO_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    CIA_CRYPTO_CODED_MESSAGES = 0,
    CIA_CRYPTO_CRIME_CHRONOLOGY = 1
};

/* Run the CIA building: pick a floor, then that section's own menu, until the
 * player leaves the building or a case takes over. The crypto branch sits
 * after the floor menu's loop, reached by goto. */
INT c_cia_building(void)
{
    INT v0j;    /* the section entry picked */
    INT v1l;    /* how many tries a search has had */
    INT v2n;    /* how much those tries turned up */
    INT v3;     /* the floor picked */

    /* Back from CODE: a broken message is shown decoded, and the half hours spent on it pass. */
    if (asm_campaign_state == CODE_MESSAGE_DECODE) {
        if (COMM()->result[RES_CODE_SOLVED] != 0) {
            c_message_menu();
            c_decode_message((char) COMM()->result[RES_CODE_MESSAGE]);
        }
        c_campaign_tick(30 * (char) COMM()->result[RES_CODE_HALF_HOURS]);
        asm_campaign_state = NONE_NOTHING_PENDING;
    }
    for (;;) {
        /* Which floor? */
        c_clear_for_menu();
        strcpy(shm_scratch, dat_note_06);
        v3 = c_ask_menu(shm_scratch, 8, 21);
        switch (v3) {
        /* The Intelligence Section, over comm.pan, until its menu is left. */
        case CIA_FLOOR_INTELLIGENCE_SECTION:
            do {
                drv_jump_gfx_set_colour_map(&dat_colours_cia_entrance, &dat_colours_cia_entrance);
                c_pan_arm(dat_note_07, 168, 0);
                strcpy(shm_scratch, dat_note_08);
                v0j = c_ask_menu(shm_scratch, 20, 21);
                switch (v0j) {
                /* Scan this city's suspects from the CIA, saying so if nothing turns up; it takes four hours. */
                case CIA_INTELLIGENCE_LOCAL_SCAN:
                    if (c_suspect_scan(1, shm_case_city, 100, LONG_LIT(0)) == 0) {
                        c_pan_blank();
                        c_ask_menu(dat_note_09, 20, 41);
                    }
                    c_campaign_tick(240);
                    break;
                /* Scan four random cities, an hour each at half a local scan's depth, saying so if nothing turns up. */
                case CIA_INTELLIGENCE_INTERNATIONAL_SCAN:
                    v2n = 0;
                    for (v1l = 0; v1l < 4; v1l++) {
                        c_campaign_tick(60);
                        v2n += c_suspect_scan(1, c_random_below(16),
                                               50, LONG_LIT(0));
                    }
                    if (v2n == 0) {
                        c_pan_blank();
                        c_ask_menu(dat_note_10, 20, 41);
                    }
                    break;
                /* The buildings tapped, and how well. */
                case CIA_INTELLIGENCE_ACTIVE_WIRE_TAPS:
                    c_tap_list();
                    break;
                case CIA_INTELLIGENCE_ACCUSE_DOUBLE_AGENT:
                    /* A double agent here confesses and is replaced, and his files get up to three scans. */
                    if ((shm_double_agent_cities & 1 << shm_case_city) != 0) {
                        strcpy(shm_scratch, dat_note_11);
                        strcat(shm_scratch, dat_note_12);
                        c_ask_menu(shm_scratch, 20, 20);
                        shm_double_agent_cities -= 1 << shm_case_city;
                        for (v1l = 0; v1l < 3; v1l++)
                            if (c_suspect_scan(1, shm_case_city,
                                                100, LONG_LIT(0)) != 0)
                                break;
                        break;
                    }
                    /* Accusing an innocent agent bars the player from this city's CIA office. */
                    strcpy(shm_scratch, dat_note_13);
                    c_ask_menu(shm_scratch, 20, 20);
                    c_building_forget(1, shm_case_city);
                    return;
                /* Sam's advice. */
                case CIA_INTELLIGENCE_CHECK_WITH_SAM:
                    c_chief_briefing();
                    break;
                }
            } while (v0j != CIA_INTELLIGENCE_NO_CHOICE);
            break;
        /* The Data Section, over research.pan, until its menu is left: each entry is a screen of the case's files. */
        case CIA_FLOOR_DATA_SECTION:
            do {
                drv_jump_gfx_set_colour_map(&dat_colours_cia_hall, &dat_colours_cia_hall);
                c_pan_arm(dat_note_14, 168, 0);
                strcpy(shm_scratch, dat_note_15);
                strcat(shm_scratch, dat_note_16);
                v0j = c_ask_menu(shm_scratch, 20, 21);
                switch (v0j) {
                case CIA_DATA_REVIEW_CLUES:
                    c_clue_menu(-1);
                    break;
                case CIA_DATA_REVIEW_SUSPECTS:
                    c_dossiers();
                    break;
                case CIA_DATA_INSIDE_INFORMATION:
                    c_document_menu();
                    break;
                case CIA_DATA_NEWS_BULLETINS:
                    c_log_draw(LONG_LIT(0));
                    break;
                case CIA_DATA_ORGANIZATION_SUMMARY:
                    c_org_info();
                    break;
                case CIA_DATA_CITY_SUMMARY:
                    c_city_info();
                    break;
                case CIA_DATA_ACTIVITY_REPORTS:
                    c_activity_report();
                    break;
                }
            } while (v0j != CIA_DATA_NO_CHOICE);
            break;
        /* The Crypto Branch is laid out after the floor menu's repeat. */
        case CIA_FLOOR_CRYPTO_BRANCH:
            goto crypto;
        /* Escape or Leave Building walks out. */
        case CIA_FLOOR_NO_CHOICE:
        case CIA_FLOOR_LEAVE_BUILDING:
            return;
        }
again:
        /* Back to the floor menu, unless something has been set to run next. */
        if (shm_finished == 0)
            continue;
        return;
    }
crypto:
    /* The Crypto Branch, over crypto.pan, until its menu is left or a message goes to CODE. */
    do {
        drv_jump_gfx_set_colour_map(&dat_colours_cia_office, &dat_colours_cia_office);
        c_pan_arm(dat_note_17, 168, 0);
        strcpy(shm_scratch, dat_note_18);
        v0j = c_ask_menu(shm_scratch, 20, 21);
        switch (v0j) {
        /* Pick an intercepted message and hand it to CODE to break, unless a result is still pending. */
        case CIA_CRYPTO_CODED_MESSAGES:
            if (asm_campaign_state == NONE_NOTHING_PENDING) {
                COMM()->result[RES_CODE_MESSAGE] = 0xff;
                c_message_menu();
                if (COMM()->result[RES_CODE_MESSAGE] != 0xff)
                    shm_finished = CODE_MESSAGE_DECODE;
            }
            break;
        /* The whole case log, not just the news. */
        case CIA_CRYPTO_CRIME_CHRONOLOGY:
            c_log_draw(LONG_LIT(1));
            break;
        }
    } while (v0j != CIA_CRYPTO_NO_CHOICE && shm_finished == 0);
    /* Then back to the floor menu. */
    goto again;
}
