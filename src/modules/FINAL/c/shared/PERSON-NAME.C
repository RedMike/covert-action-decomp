/* PERSON-NAME.C -- what to call a suspect.
 *
 * The real name once the player has learnt it, and until then "Agent A" to
 * "Agent Z", the letter being the suspect's number modulo 26.
 */
#include "FINAL.H"
#include "SCREEN.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/PERSON-NAME.C -- generated */
/* PERSON-NAME.C -- c_person_name, the name a suspect goes by.
 */

/* Append suspect `nth`'s name to the scratch buffer: the real name once
 * revealed, otherwise a codename lettered from `nth`.
 */
void c_person_name(INT nth)
{
    if (shm_suspects[nth].flags & SUSPECT_NAME) {
        c_person_real_name(nth);
    } else {
        strcat(shm_scratch, shd_str_agent_3);
        ((char *) shm_scratch)[strlen(shm_scratch) - 1] =
            nth % 26 + 'A';
    }
}
/* shared_include_end: ../../../../shared/c/PERSON-NAME.C */

/* shared_include_start: ../../../../shared/c/PERSON-REAL-NAME.C -- generated */
/* PERSON-REAL-NAME.C -- c_person_real_name, a suspect's real name.
 */

/* Append suspect `nth`'s real name to the scratch buffer: the organisation's
 * nationality picks a run of names and the suspect's visuals pick from it.
 * `spare` is unused.
 */
void c_person_real_name(INT nth)
{
    INT spare;

    strcat(shm_scratch,
               shd_first_names
                   [shm_suspects[nth].visuals & 1]
                   [shm_orgs[shm_suspects[nth].org].nationality * 2
                    + (shm_suspects[nth].visuals >> 1
                       & 0xf)]);
    strcat(shm_scratch, shd_str_space_13);
    strcat(shm_scratch,
               shd_last_names
                   [shm_orgs[shm_suspects[nth].org].nationality * 2
                    + (shm_suspects[nth].visuals >> 5
                       & 0xf)]);
}
/* shared_include_end: ../../../../shared/c/PERSON-REAL-NAME.C */
