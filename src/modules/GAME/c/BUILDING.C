/* BUILDING.C -- the menu outside a building: tap it, break in or watch it.
 */
#include "GAME.H"
#include "PROSE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DECODE.H"
#include "DIALOG.H"
#include "CASE.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "ANI_LD2.H"
#include "ANI_PLAY.H"
#include "ORGPLAN.H"
#include "STAKEOUT.H"
#include "RAID.H"
#include "BUILDING.H"
#include "CAMPSTAT.H"
#include "RESULT.H"

/* The building menu's entries, in the order dat_str_do_place_wiretap onwards lists them. */
enum building_menu_entry {
    BUILDING_MENU_CIA_BUILDING = -2,   /* the CIA's own building: no menu is shown */
    BUILDING_MENU_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    BUILDING_MENU_PLACE_WIRETAP = 0,
    BUILDING_MENU_BREAK_INTO_BUILDING = 1,
    BUILDING_MENU_WATCH_THE_BUILDING = 2,
    BUILDING_MENU_CHECK_DATA = 3,
    BUILDING_MENU_LEAVE = 4
};

/* Stand outside a building and offer what can be done to it: tap it, break in,
 * watch it, check the files or leave, until something takes the player away. */
INT c_building_menu(void)
{
    INT v0j;    /* what the wiretap attempt came away with */
    INT v1j;    /* what the player chose */
    INT v2j;    /* the city it is in */
    INT v3k;
    INT v4k;    /* how well it is guarded */
    INT v5k;
    INT v6l;
    INT v7l;    /* which of the building pictures it wears */
    INT v8l;    /* the building record the taps are added to */
    INT v9m;    /* how much of the message was the name */
    INT v10f;   /* the organisation it belongs to */
    INT v11f;

    asm_watched = 0;
    do {
        /* A chase, a car tracer or the campaign's start only brought the player here; nothing more is owed to them. */
        if (asm_campaign_state == CHASE_SUSPECT || asm_campaign_state == BUG_CAR_TRACER
            || asm_campaign_state == NONE_CAMPAIGN_START)
            asm_campaign_state = NONE_NOTHING_PENDING;
        v2j = shm_case_city;
        v10f = shm_case_org;
        /* A watch turns up more the nearer the organisation's base is to the CIA's. */
        asm_watch_odds = c_clamp(
            99 - c_packed_distance(shm_orgs[1].where,
                                   shm_orgs[v10f].where) * 6, 0, 99);
        /* The CIA's own building has a menu of its own, not this one. */
        if (v10f == 1)
            v1j = BUILDING_MENU_CIA_BUILDING;
        else {
            /* Head the menu with whose building it is and how strongly they are here, once that is known. */
            strcpy(shm_scratch, dat_str_at);
            v4k = c_building_explore(v10f, v2j, 0);
            if ((shm_buildings[v4k].identity_flags & 4) != 0) {
                strcat(shm_scratch,
                           shm_orgs[v10f].long_name);
                v7l = c_say_presence(v2j, v10f);
            } else
                strcat(shm_scratch, dat_str_unknown_building_2);
            /* Gauge the guard, but keep the alertness word c_org_mood appends out of the text. */
            v9m = strlen(shm_scratch);
            v4k = c_org_mood(v10f, v2j);
            (shm_scratch)[v9m] = 0;
            /* Describe the guard instead, by alertness in bands of 16. */
            switch (v4k / 16) {
            case 0:
                break;

            case 1:
                strcat(shm_scratch, dat_str_few_guards_peering);
                break;

            case 2:
                strcat(shm_scratch, dat_str_appears_extra_guards);
                break;

            default:
                strcat(shm_scratch, dat_str_building_swarming);
                break;
            }
            /* Then the choices. */
            strcat(shm_scratch, dat_str_do_place_wiretap);
            strcat(shm_scratch, dat_str_break_into_building);
            strcat(shm_scratch, dat_str_watch_building_check);
            shd_screen->bg_pen = 5;
            /* With nothing pending, show the building and ask what to do. */
            if (asm_campaign_state == NONE_NOTHING_PENDING) {
                /* The stronger the presence, the bigger the building drawn. */
                strcpy(asm_building_pan, dat_str_blding01_pan);
                v7l = c_clamp(v7l - 2, 0, 3);
                asm_building_pan[7] = v7l + '1';
                /* The status bar moves to the top of the screen, clear of the picture. */
                asm_status_bar_y = 4;
                drv_jump_gfx_set_colour_map(dat_colours_building + v7l,
                                  dat_colours_building + v7l);
                c_pan_arm(asm_building_pan, 0, 0);
                /* The animation's variable 10 gets the guard's band, 1 to 4. */
                c_seq_set_var(10, c_clamp(v4k / 16 + 1, 1, 4));
                v1j = c_ask_menu(shm_scratch, 2, 33);
            } else
                /* Back from a break-in or a wiretap, pick up where that choice left off to settle it. */
                switch ((INT) asm_campaign_state) {
                case TAC_BREAK_IN:
                    v1j = BUILDING_MENU_BREAK_INTO_BUILDING;
                    break;

                case CHASE_SUSPECT:
                case BUG_WIRETAP:
                    v1j = BUILDING_MENU_PLACE_WIRETAP;
                    break;
                }
        }
        switch (v1j) {
        /* At the CIA, go inside, and leave this menu once done there. */
        case BUILDING_MENU_CIA_BUILDING:
            c_arrive(v10f, v2j);
            asm_watched = 1;
            break;

        /* Watch the building; a stakeout that ends at the CIA leaves this menu. */
        case BUILDING_MENU_WATCH_THE_BUILDING:
            c_stakeout(v10f, v2j);
            if (shm_case_org == 1)
                asm_watched = 1;
            break;

        case BUILDING_MENU_BREAK_INTO_BUILDING:
            /* Hand over to TAC for the break-in, an hour later, with the sneaking-in picture up meanwhile. */
            if (asm_campaign_state == NONE_NOTHING_PENDING && asm_contact_met != 0) {
                asm_status_bar_y = 4;
                c_campaign_tick(60);
                shm_finished = TAC_BREAK_IN;
                c_load_picture(dat_str_sneakin_pic, 1);
                drv_jump_gfx_dissolve(1);
                /* From drive A:, or with the drive not yet read, hold the picture a moment. */
                if (shd_drive < 2)
                    c_wait_retraces(60);
            /* Back from TAC: settle what the break-in found. */
            } else {
                c_raid(v10f, v2j);
                asm_campaign_state = NONE_NOTHING_PENDING;
            }
            break;

        case BUILDING_MENU_PLACE_WIRETAP:
            /* Hand over to BUG, telling the player how many minutes, 2 to 10, the guard leaves them. */
            if (asm_campaign_state == NONE_NOTHING_PENDING && asm_contact_met != 0) {
                c_load_picture(dat_str_wiretap_pic, 0);
                strcpy(shm_scratch, dat_str_guards);
                v4k = c_org_mood(v10f, v2j);
                v4k = c_clamp(10 - v4k / 5, 2, 10);
                strcat(shm_scratch, dat_str_will_have);
                strcat(shm_scratch, itoa(v4k, asm_building_pan, 10));
                strcat(shm_scratch, dat_str_minutes);
                shm_menu_draw_only = 1;
                c_ask_menu(shm_scratch, 20, 20);
                shm_finished = BUG_WIRETAP;
            } else {
                /* Back from BUG: each alarm tripped puts the organisation on alert, 50 apiece. */
                asm_campaign_state = NONE_NOTHING_PENDING;
                if (asm_contact_met != 0) {
                    v0j = (char) COMM()->result[RES_BUG_SCORE];
                    c_raise_alert(shm_case_org, shm_case_city,
                        (char) COMM()->result[RES_BUG_ALARMS] * 50);
                }
                /* The phones tapped strengthen the building's wiretap, and it is identified. */
                if (v0j != 0) {
                    v8l = c_building_explore(v10f, v2j, 4);
                    shm_buildings[v8l].wiretap_level += v0j;
                }
                /* The job took an hour. */
                c_campaign_tick(60);
            }
            break;

        case BUILDING_MENU_CHECK_DATA:
            c_data_menu();
            break;

        /* Walking away; past the easiest level, a guard alert above 50 has the player followed. */
        case BUILDING_MENU_NO_CHOICE:
        case BUILDING_MENU_LEAVE:
            asm_watched = 1;
            if (shm_difficulty != 0
                && c_org_mood(shm_case_org, shm_case_city)
                   > 50) {
                /* Say so, then hand over to CHASE with the organisation's car on the player's tail. */
                c_pan_arm(dat_str_followed_pan, 0, 0);
                shm_scratch[0] = 0;
#ifdef PORT_MODERN
                c_show_prose(dat_str_followed, 32, (char *) 0, 0);
#else
                c_show_prose(dat_str_followed, 32);
#endif
                c_ask_menu(shm_scratch, 24, 145);
                drv_jump_gfx_set_colour_map(&dat_colours_building_2, &dat_colours_building_2);
                COMM()->result[RES_CHASE_ORG] = shm_case_org;
                shm_finished = CHASE_AMBUSHED;
            }
            break;
        }
    } while (asm_watched == 0 && shm_finished == 0);
    /* A visit to a CIA office with a double agent in it puts organisation shm_case_org_1 on alert. */
    if (shm_case_org == 1
        && (shm_double_agent_cities & 1 << shm_case_city) != 0)
        c_raise_alert(shm_case_org_1, shm_case_city, 40);
}
