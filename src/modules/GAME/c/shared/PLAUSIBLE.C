/* shared/PLAUSIBLE.C -- the shared routines in PLAUSIBLE.C's unit, before PLAUSIBLE.C. */

#include "GAME.H"
#include "LINES.H"
#include "PLAUSIBL.H"

/* shared_include_start: ../../../../shared/c/SAY-PRESENCE.C -- generated */
/* SAY-PRESENCE.C -- c_say_presence, naming an organisation's presence.
 */

/* Append the word for `org`'s presence in `city` to shm_scratch and answer the
 * number behind it, 0 to 5. "active cel" is spelt that way in the data.
 */
INT c_say_presence(INT city, INT org)
{
    INT rank;

    rank = c_presence(city, org);
    if (rank == 1)
        strcat(shm_scratch, shd_str_hideout);
    if (rank == 2)
        strcat(shm_scratch, shd_str_agent);
    if (rank == 3)
        strcat(shm_scratch, shd_str_safehouse);
    if (rank == 4)
        strcat(shm_scratch, shd_str_active_cel);
    if (rank == 5)
        strcat(shm_scratch, shd_str_office);
    return rank;
}
/* shared_include_end: ../../../../shared/c/SAY-PRESENCE.C */

