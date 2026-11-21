/* REPORT-FIELDS.C -- c_report_new_fields, announcing new evidence.
 */

/* Announce the evidence just added on suspect `who`: one message per newly set
 * bit. `flags` is the word before the evidence.
 */
UNSIGNED_INT c_report_new_fields(INT who, UNSIGNED_INT flags)
{
    INT picked;   /* the bits still to be reported */
    INT gained;   /* every bit the suspect ends up with */

    gained = shm_suspects[who].flags;
    shm_suspects[who].flags = flags;
    if (gained == flags)
        return flags;
    do {
        c_dossier(who, 0, 0);
        shm_menu_draw_only = 0;
        gained |= shm_suspects[who].flags;
        picked = gained
                 ^ shm_suspects[who].flags;
        if (picked & SUSPECT_PARTICIPANT) {
            shm_suspects[who].flags |= SUSPECT_PARTICIPANT;
            strcpy(shm_scratch, shd_str_empty_identified);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_identified_as);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_NAME) {
            strcpy(shm_scratch, (char *) &shd_str_empty_positively);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_positively);
            shm_suspects[who].flags |= SUSPECT_NAME;
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_2);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_PHOTO) {
            shm_suspects[who].flags |= SUSPECT_PHOTO;
            strcpy(shm_scratch, shd_str_we_have_acquired);
            c_person_name(who);
            strcat(shm_scratch, shd_str_stop);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_CITY) {
            shm_suspects[who].flags |= SUSPECT_CITY;
            strcpy(shm_scratch, shd_str_empty_spotted);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_spotted);
            strcat(shm_scratch,
                       shm_cities[shm_suspects[who].city].name);
            strcat(shm_scratch, shd_str_newline_3);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
            shm_activity.city[shm_suspects[who].city]++;
        } else if (picked & SUSPECT_ORG) {
            shm_suspects[who].flags |= SUSPECT_ORG;
            strcpy(shm_scratch, shd_str_empty_org);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_identified_as_org);
            strcat(shm_scratch,
                       shm_orgs[shm_suspects[who].org].long_name);
            strcat(shm_scratch, shd_str_newline_4);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
            shm_orgs[shm_suspects[who].org].known |= 1;
            shm_activity.org[shm_suspects[who].org]++;
        } else if (picked & SUSPECT_MORE_INFO) {
            shm_suspects[who].flags |= SUSPECT_MORE_INFO;
            strcpy(shm_scratch, shd_str_we_have_obtained);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_5);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RANK) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RANK >> 8;
            strcpy(shm_scratch, shd_str_we_have_determined_rank);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_6);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RECRUITED_IN) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RECRUITED_IN >> 8;
            strcpy(shm_scratch, shd_str_we_found_recruiting);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_7);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RECRUITED_BY) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RECRUITED_BY >> 8;
            strcpy(shm_scratch, shd_str_we_found_recruiting_2);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_8);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        continue;
    }
    } while (shm_suspects[who].flags != gained);
    c_dossier(who, 0, 0);
    return c_wait_key();
}
