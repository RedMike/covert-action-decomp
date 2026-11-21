/* TIP.C -- giving the player a tip, which photographing a Floor Safe turns up.
 */
#include "TAC.H"
#include "RANDOM.H"
#include "PANEL.H"
#include "CASE.H"
#include "PROMPT.H"
#include "REVEAL.H"

/* Hand the player one of the five kinds of tip a search can turn up, retrying
 * until one of them has something to say or nine tries are spent. */
INT c_give_tip(void)
{
    INT v0j;    /* how many tries have been made */
    INT v1n;    /* which room, or which crime role */
    INT v2b;    /* what the tip is about */

    v0j = 0;
    do {
        /* Roll which kind of tip to try. */
        switch (c_random_below(5)) {
        /* Name a city whose CIA agent is a double agent: this one if it is so, else a city at random. */
        case 4:
            v2b = shm_case_city;
            if ((shm_double_agent_cities & 1 << shm_case_city) == 0)
                v2b = c_random_below(16);
            if ((shm_double_agent_cities & 1 << v2b) == 0)
                break;
            strcpy(shm_scratch,
                       dat_str_cia_agent);
            strcat(shm_scratch,
                       shm_cities[v2b].name);
            strcat(shm_scratch,
                       dat_str_double_agent);
            c_ask_menu((rt_addr) shm_scratch, 20, 100);
            v0j = 999;
            break;
        /* The Master Plan (now and then, where this building's suspect has a role) or the organisation's file, if not yet seen. */
        case 0:
            if (asm_suspect_here != -1
                && (shm_suspects[asm_suspect_here].role & 0x7fff) != 0
                && c_random_below(3) == 0)
                v2b = 0;
            else
                v2b = shm_case_org;
            if ((shm_orgs_known & 1 << v2b) == 0) {
                c_personnel_file(v2b, LONG_LIT(1));
                v0j = 999;
                break;
            }
            /* That file already seen, say which city one of the crime's four items is in, if someone holds it. */
            v2b = c_random_below(4);
            if (shm_crime_block[v2b].u2 != -1) {
                strcpy(shm_scratch,
                           shm_crime_block[v2b].name);
                strcat(shm_scratch, dat_str_now);
                strcat(shm_scratch,
                           shm_cities[shm_suspects[shm_crime_block[v2b].u2].city].name);
                strcat(shm_scratch, dat_str_bang_2);
                c_ask_menu((rt_addr) shm_scratch, 20,
                                100);
                v0j = 999;
            }
            break;
        /* A piece of kit the player is not carrying, found and taken. */
        case 1:
            v2b = dat_tip_items[c_random_below(8)];
            if (((INT) asm_kit & 1 << v2b) == 0) {
                strcpy(shm_scratch, dat_str_find);
                strcat(shm_scratch,
                           (char *) addr_kit_names[v2b]);
                strcat(shm_scratch, dat_str_bang_3);
                c_ask_menu((rt_addr) shm_scratch, 20, 80);
                asm_kit |= 1 << v2b;
                /* The floor plan shows every room as visited. */
                if (v2b == 15) {
                    v1n = 0;
                    while (v1n <= asm_room_count) {
                        asm_rooms[v1n].flags |= 2;
                        v1n++;
                    }
                }
                /* Grenades come two to a find, up to eight of a kind. */
                if (v2b == 8)
                    asm_ammunition[0] =
                        c_clamp(asm_ammunition[0] + 2, 0, 8);
                if (v2b == 9)
                    asm_ammunition[1] =
                        c_clamp(asm_ammunition[1] + 2, 0, 8);
                if (v2b == 10)
                    asm_ammunition[2] =
                        c_clamp(asm_ammunition[2] + 2, 0, 8);
                v0j = 999;
            }
            break;
        /* Something about one crime role, four fewer to pick from for each difficulty level. */
        case 2:
        case 3:
            v1n = c_random_below(shm_crime_role_count
                                  - (asm_difficulty_was << 2));
            v2b = 1 << v1n;
            /* Only if this building's suspect fills it, and not once he is turned and the role is known. */
            if (asm_suspect_here == -1
                || (shm_suspects[asm_suspect_here].role & v2b) == 0
                || ((asm_outcome & 4) != 0
                    && (shm_suspects[asm_suspect_here].role_known & v2b)
                       != 0))
                break;
            shm_scratch[0] = 0;
            /* An unknown role: he is identified as a participant. */
            if ((v2b & shm_suspects[asm_suspect_here].role_known) == 0) {
                shm_suspects[asm_suspect_here].role_known |= v2b;
                c_dossier(asm_suspect_here, 0, 0);
                strcpy(shm_scratch,
                           dat_str_empty_18);
                c_person_name(asm_suspect_here);
                strcat(shm_scratch,
                           dat_str_has_been_identified_as);
            /* A known one: evidence to turn him into a double agent, once, and never suspect 0. */
            } else if ((asm_outcome & 4) == 0
                       && asm_suspect_here != 0) {
                c_dossier(asm_suspect_here, 0, 0);
                strcpy(shm_scratch,
                           dat_str_find_incriminating);
                c_person_name(asm_suspect_here);
                strcat(shm_scratch,
                           dat_str_into_double_agent);
                asm_outcome |= 4;
            }
            if (shm_scratch[0] != 0) {
                c_ask_menu((rt_addr) shm_scratch, 20,
                                100);
                v0j = 999;
            }
            break;
        }
        /* A tip given ends it; otherwise try again, nine times in all. */
        v0j++;
    } while (v0j < 9);
}
