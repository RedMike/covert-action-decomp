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
