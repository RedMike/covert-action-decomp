/* CLUE-TEXT.C -- c_clue_text, the word saying what a role's clue reads as.
 */

/* The word a clue about crime role `cell` reads as: a clue type in the high
 * byte and the role's clue_id in the low one, halved unless `full`.
 */
INT c_clue_text(INT cell, INT full)
{
    INT num;
    INT shade;
    char key[8];

    shade = *(unsigned char *) &shm_crime_roles[cell].clue_id;
    if (full != 0)
        shade &= 0x7f;
    else
        shade >>= 1;
    if (shm_crime_role_count - shm_difficulty * 4 > cell)
        return shm_crime_roles[cell].clue_type * 256
               + shade;
    num = shm_suspects[shm_crime_roles[cell].suspect].visuals;
    strcpy(key, shd_key_clue);
    key[5] += num % 6;
    key[3] += (num >> 3) % 4;
    num = strlen(shm_scratch);
    c_say_block_with(shd_str_clues_txt, key, shd_clue_keys,
                       shd_subst_values, 5);
    (shm_scratch)[num] = 0;
    return (*((char *) &shm_scratch[1] + num) & 0xf) * 256 + shade;
}
