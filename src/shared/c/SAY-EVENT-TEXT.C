/* SAY-EVENT-TEXT.C -- c_say_event_text, the text of a crime event's message.
 */

/* Append what the case says about crime event `nth`: the block its "*MSGaabb"
 * tag names, with the victim, object and sender filled in.
 */
INT c_say_event_text(INT nth)
{
    strcpy(shd_subst_values[0], shm_campaign.text[0]);
    strcpy(shd_subst_values[6], shm_campaign.text[1]);
    strcpy(shd_subst_values[1],
               shm_orgs[shm_suspects[shm_crime_roles[shm_crime_events[nth].main_participant].suspect].org].long_name);
    strcpy(shd_subst_values[3],
               shm_cities[shm_suspects[shm_crime_roles[shm_crime_events[nth].main_participant].suspect].city].name);
    c_message_tag(shm_mission,
                    nth >= 0
                    ? shm_crime_events[nth].message_id : nth);
    return c_say_block(shd_str_text_dta_event, shm_message_key);
}
