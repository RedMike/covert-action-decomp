/* TRAVMENU.C -- the travel map: choosing a city and flying there.
 */
#include "GAME.H"
#include "KEYCODES.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DECODE.H"
#include "BLOCK.H"
#include "LINES.H"
#include "ANI_LD2.H"
#include "TRAVEL.H"
#include "LOGKINDS.H"

/* Run the travel map: pick a city off it, fly there, and charge the time. */
INT c_travel_menu(INT city)
{
    INT v0j;    /* whether a frame has been drawn since the last key */
    INT v1k;    /* set once a city has been chosen */
    INT v2l;    /* the city being listed */
    INT v3m;
    INT v4o;    /* the key just read */
    INT v5;     /* how long the flight took */
    INT v6a;    /* the city the cursor is on */

    for (;;) {
        /* The map is picked by the first city's third letter, not WORLDn.DTA,
         * so a change to that city list can leave no map loaded at all. */
        switch (shm_cities[0].name[2]) {
        case 's':
            c_load_picture(dat_str_europe_pic, 1);
            break;
        case 'm':
            c_load_picture(dat_str_africa_pic, 1);
            break;
        case 'g':
            c_load_picture(dat_str_central_pic, 1);
            break;
        }
        drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen, 0, 0);
        /* Down the right of the map: Stay Here, the sixteen cities, then Check Data. */
        strcpy(shm_scratch, dat_str_re);
        strcat(shm_scratch, shm_cities[shm_case_city].name);
        strcat(shm_scratch, dat_str_do_travel);
        strcat(shm_scratch, dat_str_stay_here);
        for (v2l = 0; v2l < 16; v2l++) {
            strcat(shm_scratch, dat_str_space);
            strcat(shm_scratch, shm_cities[v2l].name);
            strcat(shm_scratch, dat_str_nl);
        }
        strcat(shm_scratch, dat_str_check_data_2);
        shd_screen->bg_pen = 0;
        c_draw_message(40, 194, 9, 7);
        drv_jump_gfx_fill(shd_screen, 192, 9, 128, 16, 7, 15);
        /* Keep the whole screen as drawn, so the map can be put back under a moving name. */
        drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
        /* The bar starts on Stay Here, line -1. */
        v6a = -1;
        v1k = v0j = 0;
        do {
            /* Name the city the player is in, and the one under the bar, and light the bar's line. */
            c_city_name(shm_case_city,
                            shm_cga != 0 ? 15 : 7);
            if (v6a >= 0 && v6a < 16)
                c_city_name(v6a, 15);
            drv_jump_gfx_fill(shd_screen, 192, (v6a << 3) + 33, 128, 8,
                              7, 11);
            /* Pace the bar when it was moved by the joystick, which repeats while held. */
            if (v0j != 0)
                c_wait_retraces(10);
            city = v6a;
            /* Wait for the joystick or a key; a key wins. */
            do {
                v4o = c_joystick_key();
            } while (v4o == -1 && drv_jump_keyboard_empty() != 0);
            v0j = drv_jump_keyboard_empty();
            if (v0j == 0)
                v4o = c_menu_key();
            /* Up and down move the bar, Escape stays here, Return or Space takes the line under the bar. */
            switch (v4o) {
            case KEY_DOWN:
                v6a++;
                break;
            case KEY_UP:
                v6a--;
                break;
            case KEY_ESC:
                v6a = -1;
                v1k = 1;
                break;
            case KEY_ENTER:
            case KEY_SPACE:
                v1k = 1;
                break;
            }
            /* The bar runs from Stay Here, -1, to Check Data, 16, without wrapping. */
            v6a = c_clamp(v6a, -1, 16);
            /* Still choosing: put the bare map back and unlight the line the bar has left. */
            if (v1k == 0) {
                drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 192, 200, shd_screen, 0, 0);
                drv_jump_gfx_fill(shd_screen, 192, (city << 3) + 33, 128,
                                  8, 11, 7);
            }
        } while (v1k == 0);
        c_wait_for_release();
        shd_screen->bg_pen = 7;
        /* Picking the city the player is in is staying here; count the lines from 1, so 0 is staying. */
        if (v6a == shm_case_city)
            v6a = -1;
        city = v6a + 1;
        /* A city: fly there, taking an hour plus half an hour for every eight steps of the flight. */
        if (city != 0 && city < 17) {
            v5 = (INT) c_fly_distance(shm_case_city, city - 1) / 8 * 30
                 + 60;
            shm_case_city = city - 1;
            c_log_add(LOG_TRAVEL, city - 1);
            c_campaign_tick(v5);
            /* Leaving town cools the organisations' alert to a third. */
            shm_global_alert_level /= 3;
            return;
        }
        /* Staying, or Escape, ends here; Check Data comes back to the map after. */
        if (city != 17)
            return;
        c_data_menu();
    }
}
