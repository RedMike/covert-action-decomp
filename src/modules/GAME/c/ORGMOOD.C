/* ORGMOOD.C -- how alert an organisation is in a city, in words and number.
 */
#include "GAME.H"
#include "CASE.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "ORGPLAN.H"

/* Append how alert organisation `who` is in city `where`, and answer the
 * number behind the word. */
INT c_org_mood(INT who, INT where)
{
    INT v0j;    /* the organisation's suspect in that city, or -1 */
    INT v1a;    /* how alert it is */

    /* An organisation with no presence in the city is quiet. */
    if (c_presence(where, who) == 0) {
        strcat(shm_scratch, dat_str_quiet);
        return 0;
    }
    /* Its suspect here, if on file; the general alert counts more the further it stands from the CIA. */
    v0j = c_evidence_unlock(who, where, 0, LONG_LIT(0));
    v1a = c_packed_distance(shm_orgs[1].where,
                          shm_orgs[who].where)
          * shm_global_alert_level / 24;
    /* Averaged with its local suspect's own alert, where there is one on file. */
    if (v0j != -1)
        v1a = (shm_suspects[v0j].alert_level + v1a) / 2;
    /* A double agent in the city's CIA office has tipped them off. */
    if ((shm_double_agent_cities & 1 << where) != 0)
        v1a += 16;
    /* A reading below zero, as a suspect out of play can give, counts as very nervous. */
    if (v1a < 0)
        v1a = 99;
    /* One word for every twelve points, and the answer is the number. */
    switch (v1a / 12) {
    case 0:
        strcat(shm_scratch, dat_str_unsuspecting);
        break;
    case 1:
        strcat(shm_scratch, dat_str_cautious);
        break;
    case 2:
        strcat(shm_scratch, dat_str_suspicious);
        break;
    case 3:
        strcat(shm_scratch, dat_str_nervous);
        break;
    default:
        strcat(shm_scratch, dat_str_very_nervous);
        break;
    }
    return v1a;
}
