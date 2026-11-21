/* CHASECUE.C -- deciding whether an arrested suspect's jailbreak is attempted.
 */
#include "GAME.H"
#include "RANDOM.H"
#include "ADVICE.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* Decide whether suspect `who`, under arrest, is to be broken out: when the
 * odds allow, the difficulty is above 1, no jailbreak has been attempted for
 * `who` and the mastermind is free, make `who` the jailbreak's suspect and
 * answer 1. */
INT c_test_for_jailbreak(INT who, INT nth)
{
    INT v1l;            /* never used */
    INT v0j;            /* the crime role being looked over */

    /* Find the mastermind's suspect among the real roles. */
    for (v0j = 0; v0j < shm_crime_role_count - shm_difficulty * 4; v0j++)
        if ((shm_crime_roles[v0j].flags & ROLE_MASTERMIND) != 0)
            asm_jailbreak_source_suspect = shm_crime_roles[v0j].suspect;
    /* Surely or by the odds: a held prisoner, from difficulty 2 up, never twice, while the mastermind is free. */
    if ((asm_jailbreak_target_suspect == -1
         || c_random_below(8) < shm_difficulty)
        && shm_suspects[who].alert_level == ALERT_ARRESTED
        && shm_difficulty > 1
        && (shm_suspects[who].flags & SUSPECT_JAILBREAK_ATTEMPTED) == 0
        && shm_suspects[asm_jailbreak_source_suspect].alert_level
           != ALERT_ARRESTED) {
        /* The jailbreak is coming for them. */
        asm_jailbreak_target_suspect = who;
        shm_jailbreak_suspect = who;
        return 1;
    }
    /* No jailbreak this time. */
    return 0;
}
