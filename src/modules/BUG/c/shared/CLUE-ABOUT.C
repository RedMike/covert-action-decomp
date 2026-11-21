/* CLUE-ABOUT.C -- the thing a clue was about.
 */
#include "BUG.H"
#include "TEXTLAY.H"
#include "REPORT.H"
#include "CLUEFACT.H"

/* shared_include_start: ../../../../shared/c/CLUE-SUBJECT.C -- generated */
/* CLUE-SUBJECT.C -- c_clue_subject, naming what a clue is about.
 */

/* Append what clue record `nth` is about, from `about`: the fact in the high
 * byte and what it names in the low one.
 */
void c_clue_subject(INT nth, INT about)
{
    INT who;

    who = (unsigned char) about;
    switch (about >> 8) {
    case CLUE_CITY:
        strcat(shm_scratch, shm_cities[who].name);
        break;
    case CLUE_ORG:
        strcat(shm_scratch, shm_orgs[who].long_name);
        shm_orgs[who].known |= 1;
        break;
    case CLUE_NAME:
        c_person_real_name(who);
        break;
    case CLUE_FACE:
        strcat(shm_scratch, shd_str_face);
        shm_menu_face = shm_suspects[who].visuals;
        break;
    case CLUE_ROLE:
        if (shm_clues_shown[nth].role
            < shm_crime_role_count - shm_difficulty * 4)
            strcat(shm_scratch, shd_str_valkerie);
        else
            strcat(shm_scratch, shd_str_thunderbolt);
        break;
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-SUBJECT.C */
