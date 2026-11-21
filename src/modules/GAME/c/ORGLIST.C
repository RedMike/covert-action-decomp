/* ORGLIST.C -- listing the organisations the player knows as menu entries.
 */
#include "GAME.H"
#include "DECODE.H"

/* List every organisation the player has heard of into the message buffer,
 * and record which menu entry each of them is. */
INT c_org_list(void)
{
    INT v0j;    /* the organisation being listed */

    /* Every organisation heard of, past the local contact, is a line and a menu entry. */
    for (v0j = 1; v0j < 16; v0j++)
        if ((shm_orgs[v0j].known & 1) != 0) {
            strcat(shm_scratch, dat_str_space_4);
            strcat(shm_scratch, shm_orgs[v0j].long_name);
            strcat(shm_scratch, dat_str_newline_11);
            asm_menu_choices[asm_menu_choice_count++] = v0j;
        }
}
