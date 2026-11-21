/* SUSPECT.C -- naming a suspect, by real name or by code letter.
 */
#include "GAME.H"
#include "SUSPECT.H"
#include "SUSPECTS.H"
#include "SUSPFLAG.H"

/* Append suspect `who`'s name to the message buffer: the real name once bit 1
 * of their evidence says they are identified, and otherwise a code letter,
 * the suspect's number modulo the alphabet.
 */
void c_person_name(INT who)
{
    /* Once the name is known, the real one. */
    if ((shm_suspects[who].flags & SUSPECT_NAME) != 0)
        c_person_real_name(who);
    /* Until then a codename: "Agent" and a letter taken from their number. */
    else {
        strcat(shm_scratch, dat_str_agent_2);
        shm_scratch[strlen(shm_scratch) - 1] = who % 26 + 'A';
    }
}
