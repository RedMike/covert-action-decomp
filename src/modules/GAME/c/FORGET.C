/* FORGET.C -- taking one fact about a suspect away again, as evidence and as a clue.
 */
#include "GAME.H"
#include "ADVICE.H"
#include "SUSPFLAG.H"

/* Take one fact away from a suspect: clear the bit from its evidence and from
 * its roles' clues, halve what each was worth, and drop the clues that told it. */
INT c_forget(INT who, INT bit)
{
    INT v0j;    /* the crime event or clue being scanned */
    char v1l;   /* the crime role that event is about */

    /* The evidence loses the fact, and the suspect is worth half as much. */
    shm_suspects[who].flags &= ~bit;
    shm_suspects[who].score /= 2;
    /* A photograph taken away is remembered as lost. */
    if (bit == SUSPECT_PHOTO)
        shm_suspects[who].flags |= SUSPECT_PHOTO_LOST;
    /* Every role the suspect acts in may yield the fact again as a clue, its visibility halved. */
    for (v0j = 0; v0j < shm_crime_event_count; v0j++) {
        v1l = shm_crime_events[v0j].main_participant;
        if (shm_crime_roles[v1l].suspect == who) {
            shm_crime_roles[v1l].clues_known &= ~bit;
            shm_role_scan_states[v1l].clue_visibility /= 2;
        }
    }
    /* Clues about the suspect that told this fact leave the clue list. */
    for (v0j = 0; v0j < 80; v0j++)
        if (shm_crime_roles[shm_clues_shown[v0j].role].suspect == who
            && shm_clues_shown[v0j].subject >> 8 == bit)
            shm_clues_shown[v0j].role = -1;
}
