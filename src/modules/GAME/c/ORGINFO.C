/* ORGINFO.C -- the page of what is known about one organisation.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "MISC1.H"
#include "DECODE.H"
#include "FRAME.H"
#include "CASE.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "PANEL.H"

/* Show what is known about one organisation -- its allies, the cities it is
 * known to work in, and its associates -- and come back for another. */
INT c_org_info(void)
{
    INT v0j;    /* declared and never used */
    INT v1l;    /* how far apart the two organisations are */
    INT v2n;    /* the organisation, or the city, being listed */
    INT v3;     /* set and never cleared, so "none" always follows the list */
    INT v4b;    /* the organisation the page is about */

    for (;;) {
        /* Ask which of the organisations the player has heard of to look up; none ends it. */
        strcpy(shm_scratch, dat_str_which_organization);
        asm_menu_choice_count = 0;
        c_org_list();
        c_pan_blank();
        v4b = c_ask_menu(shm_scratch, 16, 21);
        if (v4b == -1)
            break;
        /* A page headed with the organisation picked from the menu. */
        v4b = asm_menu_choices[v4b];
        c_page_frame(shm_orgs[v4b].long_name, 12);
        c_draw_centred((str_addr) shm_orgs[v4b].long_name,
                        160, 16, 5);
        /* Its allies are the organisations placed close to it, organisation 0 left out. */
        v3 = 1;
        strcpy(shm_scratch, dat_str_allies);
        for (v2n = 1; v2n < 16; v2n++)
            if (c_packed_distance(shm_orgs[v4b].where,
                                shm_orgs[v2n].where) < 8
                && v2n != v4b) {
                strcat(shm_scratch, shm_orgs[v2n].long_name);
                strcat(shm_scratch, dat_str_nl_space_3);
            }
        if (v3 == 1)
            strcat(shm_scratch, dat_str_none_3);
        /* Drawn down the left, with no pick taken. */
        shm_menu_draw_only = 1;
        c_ask_menu(shm_scratch, 20, 23);
        /* Its known locations: each city where it has a building the player knows and has identified. */
        strcpy(shm_scratch, dat_str_known_locations);
        for (v2n = 0; v2n < 16; v2n++)
            if (c_presence(v2n, v4b)
                && (shm_cities[v2n].known_orgs
                    & 1 << v4b)
                && (shm_buildings[c_building_explore(v4b, v2n, 0)].identity_flags & 4)) {
                c_say_presence(v2n, v4b);
                strcat(shm_scratch, dat_str_in_5);
                strcat(shm_scratch,
                           shm_cities[v2n].name);
                strcat(shm_scratch, dat_str_nl_dash);
            }
        /* Drawn down the right, then a rule under the page's heading. */
        shm_menu_draw_only = 1;
        c_ask_menu(shm_scratch, 144, 23);
        c_draw_line(24, 25, 295, 25, 4);
        /* Its associates are the organisations a little further off than its allies. */
        v3 = 1;
        strcpy(shm_scratch, dat_str_associates);
        for (v2n = 1; v2n < 16; v2n++)
            if ((v1l = c_packed_distance(shm_orgs[v4b].where,
                                       shm_orgs[v2n].where)) >= 8
                && v1l < 12 && v2n != v4b) {
                strcat(shm_scratch, shm_orgs[v2n].long_name);
                strcat(shm_scratch, dat_str_nl_space_4);
            }
        if (v3 == 1)
            strcat(shm_scratch, dat_str_none_4);
        /* Shown lower down until a key, which ends the page. */
        shm_menu_no_pick = 1;
        c_ask_menu(shm_scratch, 20, 103);
    }
}
