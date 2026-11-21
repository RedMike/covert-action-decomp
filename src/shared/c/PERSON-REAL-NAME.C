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
