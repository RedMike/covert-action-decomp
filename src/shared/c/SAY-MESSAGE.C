/* SAY-MESSAGE.C -- c_say_message, what an informant says about a message.
 */

/* Append what an informant says about intercepted message `nth`: its two ends
 * fill the substitutions, then seven topics follow in random order.
 */
void c_say_message(INT nth)
{
    INT reversed;
    INT slot;
    INT told;
    INT from;
    INT target;
    INT pick;
    INT hold;
    INT org;

    slot = shm_log[nth].slot;
    strcpy(shm_scratch, (char *) &shd_str_empty_message);
    from = shm_log[nth].from;
    target = shm_log[nth].to;
    if (slot >= 0) {
        reversed = 0;
        if ((shm_crime_events[slot].flags & CRIME_KIND) == (CRIME_MESSAGE | CRIME_RECEIVED)) {
            hold = from;
            from = target;
            target = hold;
            reversed = 1;
        }
    }
    strcpy(shd_subst_values[0], shm_campaign.text[0]);
    strcpy(shd_subst_values[6], shm_campaign.text[1]);
    strcpy(shd_subst_values[1],
               shm_orgs[shm_suspects[from].org].long_name);
    strcpy(shd_subst_values[2],
               shm_orgs[shm_suspects[target].org].long_name);
    if (reversed == 0) {
        strcpy(shd_subst_values[3],
                   shm_cities[shm_log[nth].from_city].name);
        strcpy(shd_subst_values[4],
                   shm_cities[shm_log[nth].to_city].name);
    } else {
        strcpy(shd_subst_values[4],
                   shm_cities[shm_log[nth].from_city].name);
        strcpy(shd_subst_values[3],
                   shm_cities[shm_log[nth].to_city].name);
    }
    told = 0;
    do {
        pick = c_random_below(7);
        if ((told & 1 << pick) == 0) {
            told |= 1 << pick;
            switch (pick) {
            case 0:
                if (shm_suspects[from].flags & SUSPECT_CITY)
                    c_say_one_of(shd_str_text_dta_sloc, (char *) shd_str_sloc00, 8);
                break;
            case 1:
                if (shm_suspects[target].flags & SUSPECT_CITY)
                    c_say_one_of(shd_str_text_dta_rloc, (char *) shd_str_rloc00, 8);
                break;
            case 2:
                if (shm_suspects[from].flags & SUSPECT_ORG)
                    c_say_one_of(shd_str_text_dta_sorg, (char *) shd_str_sorg00, 8);
                break;
            case 3:
                if (shm_suspects[target].flags & SUSPECT_ORG)
                    c_say_one_of(shd_str_text_dta_rorg, (char *) shd_str_rorg00, 8);
                break;
            case 4:
                c_message_tag(shm_mission,
                                   slot >= 0
                                   ? shm_crime_events[slot].message_id : slot);
                strcat(shm_scratch, shd_str_mark_80);
                c_say_block(shd_str_text_dta_msg, shm_message_key);
                strcat(shm_scratch, shd_str_mark_8f);
                break;
            case 5:
                c_say_one_of(shd_str_text_dta_fluf, (char *) shd_str_fluf00, 0xc);
                break;
            case 6:
                strcpy(shm_message_key, shd_str_alrt00);
                shm_message_key[6] += c_clamp(
                    shm_log[nth].status / 20,
                    0, 4);
                if (shm_log[nth].status > 15) {
                    c_say_block(shd_str_text_dta_help, shm_message_key);
                } else {
                    org = shm_suspects[shm_crime_roles[(INT) c_random_below(shm_crime_role_count - shm_difficulty * 4)].suspect].org;
                    if (shm_suspects[from].org
                            != org
                        && shm_suspects[target].org != org) {
                        strcpy(shd_subst_values[5], shm_orgs[org].long_name);
                        c_say_one_of(shd_str_text_dta_aidd, (char *) shd_str_aidd00, 2);
                    }
                }
                break;
            }
        }
    } while (told != 0x7f);
}
