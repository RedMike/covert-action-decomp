/* CLUE-FROM-FILE.C -- c_clue_from_file, a clue's own line from clues.txt.
 */

/* Append clue record `nth`'s line from clues.txt, keyed by the clue type in
 * `kind` and the fact in `about`, with its fields filled in; a face only sets
 * shm_menu_face.
 */
void c_clue_from_file(INT about, INT kind, INT nth)
{
    INT num;
    INT here;
    char seek[8];
    INT cut;

    /* The clue's line in clues.txt is keyed by the clue's type and by which fact it tells. */
    num = (unsigned char) about;
    strcpy(seek, shd_key_clue_2);
    seek[2] += (kind >> 8) & 0xf;
    for (here = about >> 8; here > 1; here >>= 1)
        seek[3]++;
    /* The object the clue turns on becomes $KEY, built at the buffer's end and cut off again. */
    here = strlen(shm_scratch);
    c_clue_thing(kind);
    strcpy((char *) shd_subst_values[0],
               (char *) shm_scratch + here);
    (shm_scratch)[here] = 0;
    /* Most lines are led by one character, the method, which is cut off the text. */
    cut = 1;
    switch (about >> 8) {
    /* A face is shown beside the text rather than written into it. */
    case 1:
        shm_menu_face = shm_suspects[num].visuals;
        break;
    /* The suspect's real name becomes $NAME. */
    case 2:
        c_person_real_name(num);
        strcpy((char *) shd_subst_values[1],
                   (char *) shm_scratch + here);
        (shm_scratch)[here] = 0;
        break;
    /* The organisation becomes $ORG. */
    case 4:
        strcpy((char *) shd_subst_values[2],
                   shm_orgs[num].long_name);
        break;
    /* The city becomes $CITY. */
    case 8:
        strcpy((char *) shd_subst_values[3],
                   shm_cities[num].name);
        break;
    /* The role itself has a line of its own, led by two characters to cut. */
    case 0x10:
        cut = 2;
        /* A real role's line is keyed by the case's mission and the role. */
        if (shm_clues_shown[nth].role
            < shm_crime_role_count - shm_difficulty * 4) {
            strcpy(seek, shd_key_clue_3);
            seek[5] += num;
            seek[3] += shm_mission % 10;
            seek[2] += shm_mission / 10;
        /* A red herring's line is picked by bits of its suspect's face instead. */
        } else {
            here = shm_suspects[shm_crime_roles[shm_clues_shown[nth].role].suspect].visuals;
            strcpy(seek, shd_key_clue_4);
            seek[5] += here % 6;
            seek[3] += (here >> 3) % 4;
        }
        break;
    }
    /* Append the line with the fields filled in. */
    here = strlen(shm_scratch);
    c_say_block_with(shd_str_clues_txt_2, seek, shd_clue_keys,
                       shd_subst_values, 5);
    /* Keep the lead character as the clue's method, and cut the lead off the text. */
    shm_clue_method = *((char *) shm_scratch + here) & 0xf;
    OVERLAPPING_STRCPY((char *) shm_scratch + here,
               (char *) shm_scratch + here + cut);
}
