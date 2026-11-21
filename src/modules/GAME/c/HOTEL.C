/* HOTEL.C -- the hotel menu: waiting, local contacts, saving and loading.
 */
#include "GAME.H"
#include "PROSE.H"
#include "CMP_STRT.H"
#include "ADVICE.H"
#include "DECODE.H"
#include "CASE.H"
#include "ANI_LD2.H"
#include "SAVELOAD.H"
#include "ORGPLAN.H"
#include "ROLEFLAG.H"

/* The hotel menu's entries, in the order dat_note_02 lists them. */
enum hotel_menu_entry {
    HOTEL_MENU_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    HOTEL_MENU_LEAVE_HOTEL = 0,
    HOTEL_MENU_VISIT_THE_LOUNGE = 1,
    HOTEL_MENU_SLEEP_THROUGH_CASE = 2,
    HOTEL_MENU_SAVE_GAME = 3,
    HOTEL_MENU_LOAD_GAME = 4,
    HOTEL_MENU_BLANK = 5,   /* the empty line above Quit */
    HOTEL_MENU_QUIT = 6
};

/* Run the hotel menu until something takes the player out of it. */
INT c_hotel_menu(void)
{
    INT v0j;    /* the suspect filling the participant's role */
    INT v1m;    /* the participant being looked at */
    INT v2;     /* what the flags were before the map */
    INT v3c;    /* the entry picked */

    do {
        /* The hotel picture and its menu. */
        c_load_picture(dat_note_01, 0);
        strcpy(shm_scratch, dat_note_02);
        v3c = c_ask_menu(shm_scratch, 16, 40);
        switch (v3c) {
        /* Escape or Leave Hotel goes back out into the city. */
        case HOTEL_MENU_NO_CHOICE:
        case HOTEL_MENU_LEAVE_HOTEL:
            return;
        /* Let the clock run on until something happens or a key is pressed. */
        case HOTEL_MENU_SLEEP_THROUGH_CASE:
            c_wait_it_out();
            break;
        case HOTEL_MENU_VISIT_THE_LOUNGE:
            /* The lounge's talk, from prose.dta. */
            shm_scratch[0] = 0;
#ifdef PORT_MODERN
            c_show_prose(dat_note_03, 32, (char *) 0, 0);
#else
            c_show_prose(dat_note_03, 32);
#endif
            c_ask_menu(shm_scratch, 20, 80);
            /* Each participant working from this city, bar the mastermind, gives a fact away as a clue. */
            for (v1m = 0; v1m < shm_crime_role_count; v1m++) {
                v0j = shm_crime_roles[v1m].suspect;
                if (shm_suspects[v0j].city
                        == shm_case_city
                    && (*(INT *) &shm_crime_roles[v1m].flags
                        & ROLE_MASTERMIND) == 0)
                    c_cell_reveal(v1m, 0, shm_case_city);
            }
            /* Asking around raises the alert in this city. */
            c_raise_alert(0, shm_case_city, 20);
            break;
        /* Save, marked as saved mid-mission, with the difficulty carried in the shared block. */
        case HOTEL_MENU_SAVE_GAME:
            shm_options &= ~OPT_MISSION_ENDED;
            COMM()->game_50 = shm_difficulty;
            c_save_menu();
            break;
        /* Load, keeping this session's joystick setting, then redraw the status bar. */
        case HOTEL_MENU_LOAD_GAME:
            v2 = shm_options;
            c_load_menu();
            shm_options = (v2 & OPT_JOYSTICK) | (shm_options & ~OPT_JOYSTICK);
            c_campaign_tick(0);
            break;
        /* Quit: nothing runs next, so the closing sequence plays. */
        case HOTEL_MENU_QUIT:
            shm_finished = -1;
            break;
        }
    } while (shm_finished == 0);
}
