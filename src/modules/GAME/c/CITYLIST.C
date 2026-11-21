/* CITYLIST.C -- listing the cities as menu entries.
 */
#include "GAME.H"
#include "DECODE.H"

/* List the sixteen cities into the message buffer, one to a line, and record
 * which menu entry each of them is. */
INT c_city_list(void)
{
    INT v0j;    /* the city being listed */

    /* One indented line per city, the menu entry standing for that city. */
    for (v0j = 0; v0j < 16; v0j++) {
        strcat(shm_scratch, dat_str_space_5);
        strcat(shm_scratch, shm_cities[v0j].name);
        strcat(shm_scratch, dat_str_newline_13);
        asm_menu_choices[asm_menu_choice_count++] = v0j;
    }
}
