/* SUSPMENU.C -- the menu of every suspect seen, with what is known of each.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "DECODE.H"
#include "SUSPECT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"

/* List every suspect that has been seen, with what is known about each, and
 * answer the one picked. */
INT c_suspect_menu(void)
{
    INT v0j;    /* never used */
    INT v1k;    /* never used */
    INT v2m;    /* never used */
    INT v3o;    /* the suspect being listed */
    INT v4;     /* whether this one has a second line */
    INT v5b;    /* the crime role being checked against the suspect */

    /* Every line starts with a space, the first one included. */
    strcpy(shm_scratch, dat_str_space_6);
    for (v3o = 0; v3o < shm_suspect_count; v3o++) {
        /* Everyone the player knows anything about. */
        if (shm_suspects[v3o].flags != 0) {
            /* "<name> of the <org> in <city>.", as far as those are known. */
            c_person_name(v3o);
            if ((shm_suspects[v3o].flags & SUSPECT_ORG) != 0) {
                strcat(shm_scratch, dat_str_of_the_3);
                strcat(shm_scratch,
                           shm_orgs[shm_suspects[v3o].org].short_name);
            }
            if ((shm_suspects[v3o].flags & SUSPECT_CITY) != 0) {
                strcat(shm_scratch, dat_str_in_6);
                strcat(shm_scratch,
                           shm_cities[shm_suspects[v3o].city].name);
            }
            strcat(shm_scratch, dat_str_dot_nl_2);
            /* A second line for the parts they are known to play, one bullet each. */
            v4 = 0;
            for (v5b = 0; v5b < 15; v5b++)
                if ((shm_suspects[v3o].role_known & 1 << v5b) != 0) {
                    strcat(shm_scratch, dat_str_bullet);
                    strcat(shm_scratch, shm_crime_roles[v5b].name);
                    strcat(shm_scratch, dat_str_space_7);
                    v4 = 1;
                }
            /* And for what has become of them. */
            if (shm_suspects[v3o].alert_level == ALERT_ARRESTED) {
                strcat(shm_scratch, dat_str_arrested_2);
                v4 = 1;
            }
            if (shm_suspects[v3o].alert_level == ALERT_HIDING) {
                strcat(shm_scratch, dat_str_hiding_3);
                v4 = 1;
            }
            if (shm_suspects[v3o].alert_level == ALERT_TURNED) {
                strcat(shm_scratch, dat_str_turned_3);
                v4 = 1;
            }
            if (shm_suspects[v3o].alert_level == ALERT_IN_CUSTODY) {
                strcat(shm_scratch, dat_str_custody);
                v4 = 1;
            }
            /* Either of the suspect's lines picks the suspect. */
            asm_menu_choices[asm_menu_choice_count++] = v3o;
            if (v4 != 0) {
                strcat(shm_scratch, dat_str_nl_2);
                asm_menu_choices[asm_menu_choice_count++] = v3o;
            }
        }
    }
    /* Nobody yet: a "none" line that picks nobody. */
    if (asm_menu_choice_count == 1) {
        strcat(shm_scratch, dat_str_none_9);
        asm_menu_choices[asm_menu_choice_count] = -1;
    }
    /* The suspect on the line picked; Escape lands on the caller's -1 in entry 0. */
    return asm_menu_choices[c_ask_menu(shm_scratch, 10, 17) + 1];
}
