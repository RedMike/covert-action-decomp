/* CITYINFO.C -- the page of what is known about one city. */
#include "GAME.H"
#include "CMP_STRT.H"
#include "MISC1.H"
#include "DECODE.H"
#include "FRAME.H"
#include "CASE.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "PANEL.H"
#include "WRAP.H"
#include "SUSPFLAG.H"

/* Show what is known about one city -- the organisations with a building
 * there, the suspects seen in it, and the clues that point at it. */
INT c_city_info(void)
{
    INT v0j;    /* never used */
    INT v1l;    /* whether the section being built has listed anything */
    INT v2n;    /* the organisation, suspect or clue being listed */
    INT v3;     /* the crime role being checked against the suspect */
    INT v4b;    /* the city the page is about */

    for (;;) {
        /* Ask which city, until Escape. */
        c_pan_blank();
        strcpy(shm_scratch, dat_str_which_city);
        asm_menu_choice_count = 0;
        c_city_list();
        v4b = c_ask_menu(shm_scratch, 20, 21);
        if (v4b == -1)
            break;
        v4b = asm_menu_choices[v4b];
        /* A page headed with the city's name. */
        c_page_frame((rt_addr) shm_cities[v4b].name, 2);
        c_draw_centred((str_addr) shm_cities[v4b].name, 160, 15, 5);
        /* Known Locations: each organisation present with a building the player knows of, named if identified. */
        v1l = 0;
        strcpy(shm_scratch, dat_str_known_locations_2);
        for (v2n = 1; v2n < 16; v2n++)
            if (c_presence(v4b, v2n) != 0
                && c_building_explore(v2n, v4b, 0) != -1) {
                if ((shm_buildings[c_building_explore(v2n, v4b, 0)].identity_flags
                     & 4) != 0) {
                    strcat(shm_scratch, shm_orgs[v2n].long_name);
                    c_say_presence(v4b, v2n);
                } else
                    strcat(shm_scratch, dat_str_unknown_building_3);
                strcat(shm_scratch, dat_str_nl_dash_2);
                v1l = 1;
            }
        /* Drawn in the right-hand column without waiting. */
        if (v1l == 0)
            strcat(shm_scratch, dat_str_none_5);
        shm_menu_draw_only = 1;
        c_ask_menu(shm_scratch, 160, 25);
        /* Suspects: everyone known to work from this city, with their organisation where known. */
        v1l = 0;
        strcpy(shm_scratch, dat_str_suspects);
        for (v2n = 0; v2n < 64; v2n++)
            if ((shm_suspects[v2n].flags & SUSPECT_CITY) != 0
                && shm_suspects[v2n].city == v4b) {
                c_person_name(v2n);
                if ((shm_suspects[v2n].flags & SUSPECT_ORG) != 0) {
                    strcat(shm_scratch, dat_str_slash_3);
                    strcat(shm_scratch,
                           shm_orgs[shm_suspects[v2n].org].short_name);
                }
                /* And every crime role the player knows the suspect plays. */
                for (v3 = 0; v3 < shm_crime_role_count; v3++)
                    if ((shm_suspects[v2n].role_known & 1 << v3) != 0) {
                        strcat(shm_scratch, dat_str_ellipsis);
                        strcat(shm_scratch, shm_crime_roles[v3].name);
                    }
                strcat(shm_scratch, dat_str_nl_dash_space);
                v1l = 1;
            }
        /* Drawn in the left-hand column without waiting, ruled off below the heading. */
        if (v1l == 0)
            strcat(shm_scratch, dat_str_none_6);
        shm_menu_draw_only = 1;
        c_ask_menu(shm_scratch, 20, 25);
        c_draw_line(24, 25, 295, 25, 10);
        /* Clues: every clue found that names this city, clue fact 8. */
        v1l = 0;
        strcpy(shm_scratch, dat_str_clues);
        for (v2n = 0; v2n < 80; v2n++)
            if (shm_clues_shown[v2n].subject >> 8 == 8
                && (shm_clues_shown[v2n].subject & 0xff) == v4b) {
                strcat(shm_scratch, dat_str_dash);
                c_clue_line(v2n);
                strcat(shm_scratch, dat_str_newline_12);
                v1l = 1;
            }
        /* Wrapped along the bottom, and the page held until a key. */
        if (v1l == 0)
            strcat(shm_scratch, dat_str_none_7);
        c_wrap_message(16);
        c_ask_menu(shm_scratch, 20, 113);
        c_pan_blank();
    }
}
