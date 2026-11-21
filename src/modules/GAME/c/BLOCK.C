/* BLOCK.C -- the case log, and the tagged text blocks messages are read from.
 */
#include "GAME.H"
#include "BLOCK.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "FRAME.H"
#include "CASE.H"
#include "LINES.H"
#include "TAG.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"
#include "SUSPFLAG.H"

/* Everything an informant will say about intercepted message `nth`, in a
 * random order, written into shm_scratch. */
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

    /* Start an empty report on the message's two ends. */
    slot = shm_log[nth].slot;
    strcpy(shm_scratch, &dat_str_empty_9_2);
    from = shm_log[nth].from;
    target = shm_log[nth].to;
    /* A message logged from the receiving side is told with its ends the other way round. */
    if (slot >= 0) {
        reversed = 0;
        if ((shm_crime_events[slot].flags & CRIME_KIND) == (CRIME_MESSAGE | CRIME_RECEIVED)) {
            hold = from;
            from = target;
            target = hold;
            reversed = 1;
        }
    }
    /* The text's $-keys: the mission's $VICTIM and $OBJECT, then each end's organisation and city. */
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
    /* Seven topics, each told once, in a random order so no two reports read alike. */
    told = 0;
    do {
        pick = c_random_below(7);
        if ((told & 1 << pick) == 0) {
            told |= 1 << pick;
            switch (pick) {
            /* Where the sender is based, once the player knows that city. */
            case 0:
                if (shm_suspects[from].flags & SUSPECT_CITY)
                    c_say_one_of(dat_str_text_dta, dat_str_sloc00, 8);
                break;
            /* Where the receiver is based, likewise. */
            case 1:
                if (shm_suspects[target].flags & SUSPECT_CITY)
                    c_say_one_of(dat_str_text_dta_2, dat_str_rloc00, 8);
                break;
            /* The sender's organisation, once known. */
            case 2:
                if (shm_suspects[from].flags & SUSPECT_ORG)
                    c_say_one_of(dat_str_text_dta_3, dat_str_sorg00, 8);
                break;
            /* The receiver's organisation, likewise. */
            case 3:
                if (shm_suspects[target].flags & SUSPECT_ORG)
                    c_say_one_of(dat_str_text_dta_4, dat_str_rorg00, 8);
                break;
            /* The message's own text, between the two marks that set it apart. */
            case 4:
                c_message_tag(shm_mission,
                                   slot >= 0
                                   ? shm_crime_events[slot].message_id : slot);
                strcat(shm_scratch, dat_str_mark_80);
                c_say_block(dat_str_text_dta_5, shm_message_key);
                strcat(shm_scratch, dat_str_mark_8f);
                break;
            /* One of twelve bits of filler. */
            case 5:
                c_say_one_of(dat_str_text_dta_6, dat_str_fluf00, 12);
                break;
            /* How alert the sender was, in one of five steps of 20. */
            case 6:
                strcpy(shm_message_key, dat_str_alrt00);
                shm_message_key[6] += c_clamp(
                    shm_log[nth].status / 20,
                    0, 4);
                if (shm_log[nth].status > 15) {
                    c_say_block(dat_str_text_dta_7, shm_message_key);
                } else {
                    /* Not alert: instead, maybe name a third organisation from the plot as giving aid. */
                    org = shm_suspects[shm_crime_roles[(INT) c_random_below(shm_crime_role_count - shm_difficulty * 4)].suspect].org;
                    if (shm_suspects[from].org
                            != org
                        && shm_suspects[target].org != org) {
                        strcpy(shd_subst_values[5], shm_orgs[org].long_name);
                        c_say_one_of(dat_str_text_dta_8, dat_str_aidd00, 2);
                    }
                }
                break;
            }
        }
    } while (told != 0x7f);
}
