/* PRISONER.C -- exchanging the captured player for a prisoner.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "BLOCK.H"
#include "CASE.H"
#include "SUSPECT.H"
#include "PRISONER.H"
#include "LOGKINDS.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"

/* Offer the prisoner exchange: pick the arrested suspect cheapest to give up
 * and, if the offer is taken, release them -- or, with nobody held, settle
 * for two double agents instead. */
INT c_prisoner_exchange(void)
{
    INT v0j;    /* the agent worth exchanging */
    INT v1k;    /* what he costs */
    INT v2m;    /* the crime event being weighed against him */
    INT v3o;    /* the crime role being weighed */
    INT v4;     /* what this one costs */
    INT v5b;    /* the agent it is about */

    /* Among the real plotters, not the red herrings, find the arrested one costing least, ties to the later role. */
    v0j = -1;
    v1k = 99;
    for (v3o = 0;
         v3o < shm_crime_role_count - shm_difficulty * 4; v3o++) {
        v5b = shm_crime_roles[v3o].suspect;
        /* The cost starts at the role's exposure, less 2 for each of its events still to come. */
        v4 = shm_crime_roles[v3o].exposure;
        for (v2m = 0; v2m < shm_crime_event_count - 1; v2m++)
            if ((char) shm_crime_events[v2m].main_participant == v3o
                && shm_crime_events[v2m].happen_tick == 999)
                v4 -= 2;
        if (shm_suspects[v5b].alert_level == ALERT_ARRESTED
            && v4 <= v1k) {
            v0j = v5b;
            v1k = v4;
        }
    }
    /* Offer the deal; the second answer agrees to it. */
    strcat(shm_scratch, dat_str_no_thanks_squinty_agree);
    if (c_ask_menu(shm_scratch, 16, 21) == 1) {
        strcpy(shm_scratch, dat_str_exchanged);
        /* The prisoner goes free, back in play with his building forgotten, and the exchange is logged. */
        if (v0j != -1) {
            c_person_name(v0j);
            strcat(shm_scratch, dat_str_dot_nl);
            shm_suspects[v0j].alert_level = ALERT_FREED;
            shm_suspects[v0j].flags |= SUSPECT_JAILBREAK_ATTEMPTED;
            c_building_forget(shm_suspects[v0j].org,
                            shm_suspects[v0j].city);
            c_log_add(LOG_EXCHANGED, v0j);
        /* With nobody to give, the CIA offices of two random cities, maybe the same one, get double agents. */
        } else {
            strcat(shm_scratch, dat_str_two_double_agents);
            shm_double_agent_cities |= 1 << c_random_below(16);
            shm_double_agent_cities |= 1 << c_random_below(16);
        }
        c_ask_menu(shm_scratch, 16, 121);
        return 1;
    }
    return 0;
}
