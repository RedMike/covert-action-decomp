/* CASE-4.C -- more of the module's own routines in CASE.C's unit, after shared/CASE-3.C. */
#include "GAME.H"
#include "SPRITES.H"
#include "CASE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "DIALOG.H"
#include "FRAME.H"
#include "BLOCK.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "SUSPECTS.H"
#include "PANEL.H"
#include "FACES.H"
#include "HANDOVER.H"
#include "TAG.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "CLUEFACT.H"

/* Append the thing clue record `nth` was about, given the word `about`: the
 * kind in the high byte, the thing in the low one. */
void c_clue_subject(INT nth, INT about)
{
    INT who;

    /* Which one is named, then what kind of fact the clue gives. */
    who = (unsigned char) about;
    switch (about >> 8) {
    /* A city, by name. */
    case CLUE_CITY:
        strcat(shm_scratch, shm_cities[who].name);
        break;
    /* An organisation, which the player has now heard of. */
    case CLUE_ORG:
        strcat(shm_scratch, shm_orgs[who].long_name);
        shm_orgs[who].known |= 1;
        break;
    /* A suspect's real name. */
    case CLUE_NAME:
        c_person_real_name(who);
        break;
    /* "this face.", with the suspect's face drawn beside it. */
    case CLUE_FACE:
        strcat(shm_scratch, dat_str_face);
        shm_menu_face = shm_suspects[who].visuals;
        break;
    /* The role: Valkerie if real, Thunderbolt if a red herring. No caller reaches it. */
    case CLUE_ROLE:
        if (shm_clues_shown[nth].role
            < shm_crime_role_count - shm_difficulty * 4)
            strcat(shm_scratch, dat_str_valkerie);
        else
            strcat(shm_scratch, dat_str_thunderbolt);
        break;
    }
}
