/* TAG.C -- the text of a crime event's message, found by its tag.
 */
#include "GAME.H"
#include "BLOCK.H"
#include "TAG.H"

/* Append the text of crime event `nth`'s message: fill four substitution
 * buffers, two from the mission and two from the event, build its tag, read
 * the tagged block, and mark the sending organisation as heard of. */
void c_say_event_text(INT nth)
{
    /* $VICTIM and $OBJECT come from the mission, $SNDORG and $SNDLOC from the event's main participant. */
    strcpy(shd_subst_values[0], shm_campaign.text[0]);
    strcpy(shd_subst_values[6], shm_campaign.text[1]);
    strcpy(shd_subst_values[1],
               shm_orgs[shm_suspects[shm_crime_roles[shm_crime_events[nth].main_participant].suspect].org].long_name);
    strcpy(shd_subst_values[3],
               shm_cities[shm_suspects[shm_crime_roles[shm_crime_events[nth].main_participant].suspect].city].name);
    /* The message's text in text.dta, keyed by the case's mission and the event's message. */
    c_message_tag(shm_mission,
                    nth >= 0
                    ? shm_crime_events[nth].message_id : nth);
    c_say_block(dat_str_text_dta_9, shm_message_key);
    /* The sender's organisation is now heard of. */
    shm_orgs[shm_suspects[shm_crime_roles[shm_crime_events[nth].main_participant].suspect].org].known |= 1;
}
