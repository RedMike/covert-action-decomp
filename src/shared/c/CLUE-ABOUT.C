/* CLUE-ABOUT.C -- c_clue_about, packing what a clue says into one word.
 */

/* Pack fact `what` of clue record `slot` into a word: the fact in the high
 * byte and what it names in the low one. Naming an organisation or city counts
 * it in shm_activity.
 */
INT c_clue_about(INT slot, INT what)
{
    INT suspect;   /* the suspect filling the clue's role */

    suspect = shm_crime_roles[shm_clues_shown[slot].role].suspect;
    switch (what) {
    case CLUE_CITY:
        shm_activity.city[shm_suspects[suspect].city]++;
        return what * 0x100
               + shm_suspects[suspect].city;

    case CLUE_ORG:
        shm_activity.org[shm_suspects[suspect].org]++;
        shm_orgs[shm_suspects[suspect].org].known |= 1;
        strcat(shm_scratch,
                   shm_orgs[shm_suspects[suspect].org].long_name);
        return what * 0x100
               + shm_suspects[suspect].org;

    case CLUE_FACE:
        return what * 0x100 + suspect;

    case CLUE_NAME:
        return what * 0x100 + suspect;

    case CLUE_ROLE:
        return what * 0x100
               + shm_clues_shown[slot].role;

    }
}
