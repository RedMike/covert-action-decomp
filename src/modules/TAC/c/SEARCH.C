/* SEARCH.C -- searching the files for a name.
 */
#include "TAC.H"
#include "CITY.H"
#include "MENU.H"
#include "PANEL.H"
#include "CASE.H"
#include "PROMPT.H"
#include "RADAR.H"
#include "PASSWORD.H"
#include "SEARCH.H"
#include "TYPE.H"
#include "SUSPFLAG.H"

/* Ask for a word and look for it everywhere the case knows a name: the
 * participants, the cities, the organisations, the plot's own steps and the
 * crime's four named items. The first hit is shown; three misses give up. The
 * two gotos are as shipped.
 */
INT c_search_names(void)
{
    INT v0j;    /* which participant */
    INT v1k;    /* which of the three tries */
    INT v2l;    /* which city, organisation, plot step or named item */
    INT v3m;    /* the plot step being described */
    INT v4o;    /* whether the organisation has a presence there */
    char v5[20];/* the word, in upper case */
    INT v6a;    /* and how long it is */

    /* Let the password's acceptance stand a moment. */
    v4o = 0;
    c_wait_retraces(60);
    v1k = 0;
    do {
        /* Ask what to search for, and match it in upper case; nothing typed ends the search. */
        c_question_panel(dat_str_search);
        shm_scratch[0] = 0;
        c_type_message(106, 100, 15);
        c_wait_for_release();
        strcpy(v5, shm_scratch);
        strupr(v5);
        v6a = strlen(v5);
        if (v6a == 0)
            return;
        /* A suspect whose real name holds the word: show their dossier. */
        for (v0j = 0; v0j < 64; v0j++) {
            if (shm_suspects[v0j].visuals == 0)
                continue;
            shm_scratch[0] = 0;
            c_person_real_name(v0j);
            if (strstr(strupr(shm_scratch), v5)
                == 0)
                continue;
            /* From the third difficulty level up, only one in this city or this organisation is found. */
            if (shm_suspects[v0j].city
                != shm_case_city
                && shm_suspects[v0j].org
                   != shm_case_org
                && asm_difficulty_was >= 2)
                continue;
            /* Evidence: they become known, and one of this organisation in this city has their roles revealed too. */
            shm_suspects[v0j].flags |= SUSPECT_IDENTITY | SUSPECT_PARTICIPANT;
            if (shm_suspects[v0j].city
                == shm_case_city
                && shm_suspects[v0j].org
                   == shm_case_org)
                shm_suspects[v0j].role_known |=
                    shm_suspects[v0j].role
                    & 0x7fff;
            c_dossier(v0j, 0, 0);
            c_wait_key();
            return;
        }
        /* A city: say whether this building's organisation is present there. */
        for (v2l = 0; v2l < 16; v2l++) {
            strcpy(shm_scratch,
                       shm_cities[v2l].name);
            if (strstr(strupr(shm_scratch), v5)
                != 0) {
                strcpy(shm_scratch, shm_orgs[(INT) shm_case_org].long_name);
                strcat(shm_scratch,
                           dat_str_has);
                /* Present: name its strength, and mark the organisation known in that city. */
                if (c_presence(v2l, shm_case_org) != 0) {
                    strcat(shm_scratch, dat_str_a);
                    c_say_presence(v2l, shm_case_org);
                    shm_cities[v2l].known_orgs |=
                        1 << shm_case_org;
                    c_building_explore(shm_case_org, v2l, 0xc);
                    v4o = 1;
                } else {
                    /* Absent: no operatives. */
                    strcat(shm_scratch,
                               dat_str_no_operatives);
                    v4o = 0;
                }
                strcat(shm_scratch,
                           dat_str_newline_in);
                strcat(shm_scratch,
                           shm_cities[v2l].name);
                strcat(shm_scratch,
                           dat_str_newline_14);
                /* A presence is shown in the pop-up panel with the readout picture; an absence as a plain message. */
                if (v4o != 0) {
jump:
                    asm_panel_x = 100;
                    asm_panel_y = 100;
                    shm_menu_face = -2;
                    c_hook_message();
                    c_wait_key();
                    return;
                }
                goto show;
            }
        }
        /* An organisation, all but the first two: say whether it is present in this city. */
        for (v2l = 2; v2l < 16; v2l++) {
            strcpy(shm_scratch, shm_orgs[v2l].long_name);
            if (strstr(strupr(shm_scratch), v5)
                != 0) {
                strcpy(shm_scratch, shm_orgs[v2l].long_name);
                /* Present: name its strength, and mark it known in this city. */
                if (c_presence(shm_case_city, v2l) != 0) {
                    c_say_presence(shm_case_city, v2l);
                    shm_cities[shm_case_city].known_orgs |= 1 << v2l;
                    c_building_explore(v2l, shm_case_city, 0xc);
                    v4o = 1;
                } else {
                    /* Absent: no operatives. */
                    strcat(shm_scratch,
                               dat_str_has_no_operatives);
                    v4o = 0;
                }
                strcat(shm_scratch,
                           dat_str_newline_in_2);
                strcat(shm_scratch,
                           shm_cities[shm_case_city].name);
                strcat(shm_scratch,
                           dat_str_newline_15);
                /* Shown the same two ways as a city's answer. */
                if (v4o != 0)
                    goto jump;
show:
                c_ask_menu((rt_addr) shm_scratch,
                                100, 80);
                return;
            }
        }
        /* A thing a step of the plot names: file a clue about that step, if it has one left to give. */
        v2l = 0;
        while (v2l < shm_crime_role_count) {
            v3m = c_clue_text(v2l, 0);
            shm_scratch[0] = 0;
            c_clue_thing(v3m);
            if (strstr(strupr(shm_scratch), v5)
                != 0
                && c_cell_reveal(v2l, shm_case_org,
                                   shm_case_city) != 0)
                return;
            v2l++;
        }
        /* One of the crime's four items, if someone holds it: say which city it is now in. */
        for (v2l = 0; v2l < 4; v2l++)
            if (shm_crime_block[v2l].u2 != -1) {
                strcpy(shm_scratch,
                           shm_crime_block[v2l].name);
                if (strstr(strupr((str_addr)
                                          shm_scratch), v5) != 0) {
                    strcpy(shm_scratch,
                               shm_crime_block[v2l].name);
                    strcat(shm_scratch,
                               dat_str_now_2);
                    strcat(shm_scratch,
                               shm_cities[shm_suspects[shm_crime_block[v2l].u2].city].name);
                    strcat(shm_scratch, dat_str_bang);
                    c_ask_menu((rt_addr) shm_scratch,
                                    100, 80);
                    return;
                }
            }
        /* Nothing matched: say so for a moment and ask again, three tries in all. */
        c_question_panel(dat_str_empty_20);
        c_draw_centred(dat_str_no_data, 160, 103, 7);
        c_wait_retraces(90);
        v1k++;
    } while (v1k < 3);
}
