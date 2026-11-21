/* TAPLIST.C -- the list of wiretapped buildings.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "DECODE.H"
#include "FRAME.H"

/* Show the wiretaps: one line per building tapped above 1%, with its level. */
INT c_tap_list(void)
{
    INT v0j;    /* the building being listed */
    INT v1a;    /* whether anything was listed */

    /* A page of its own, one line per tapped building: whose, where, and the tap's strength as a percentage. */
    c_page_frame(dat_note_20, 7);
    strcpy(shm_scratch, dat_str_empty_9);
    v1a = 0;
    for (v0j = 0; v0j < shm_building_count; v0j++)
        if (shm_buildings[v0j].wiretap_level > 1) {
            strcat(shm_scratch,
                       shm_orgs[shm_buildings[v0j].org].long_name);
            strcat(shm_scratch, dat_str_slash_2);
            strcat(shm_scratch,
                       shm_cities[shm_buildings[v0j].city].name);
            strcat(shm_scratch, dat_str_dots_2);
            strcat(shm_scratch,
                       itoa(shm_buildings[v0j].wiretap_level,
                                asm_tap_digits, 10));
            strcat(shm_scratch, dat_str_percent);
            v1a = 1;
        }
    /* None, when there is nothing to list; the page stays up until dismissed. */
    if (v1a == 0)
        strcat(shm_scratch, dat_str_none_2);
    return c_ask_menu(shm_scratch, 50, 21);
}
