/* CASE-2.C -- more of the module's own routines in CASE.C's unit, after shared/CASE.C. */
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

/* Finding the suspect an organisation and a city name, or making one. */
INT c_suspect_reserve(INT org, INT city, UNSIGNED_INT bits)
{
    INT cell;   /* the record being looked at, then the one chosen */

    /* The organisation already has its suspect in that city: give it the roles too. */
    for (cell = 0; cell < shm_suspect_count; cell++) {
        if (shm_suspects[cell].org == org
            && shm_suspects[cell].city
                   == city) {
            shm_suspects[cell].role |= bits;
            return cell;
        }
    }
    /* A free record picked at random, never record 0, which is the mastermind's. */
    do {
        cell = c_random_below(64);
    } while (shm_suspects[cell].visuals != 0
             || cell == 0);
    /* Except that the mastermind's own organisation and city is the mastermind. */
    if (org == shm_campaign.mastermind_org && city == shm_campaign.mastermind_city)
        cell = 0;
    /* With roles to fill, make the person: nothing known yet, save what the mastermind carries over. */
    if (bits != 0) {
        shm_suspects[cell].org = org;
        shm_suspects[cell].city = city;
        shm_suspects[cell].flags =
            cell != 0 ? 0 : shm_campaign.mastermind_flags;
        shm_suspects[cell].role = bits;
        shm_suspects[cell].role_known = 0;
        shm_suspects[cell].score = 0;
        /* A fresh face that marks the record taken, and two in three of them men. */
        if (cell != 0) {
            shm_suspects[cell].visuals =
                c_random_below(32766) + 1;
            if (c_random_below(3) == 0)
                shm_suspects[cell].visuals |= 1;
        /* The mastermind keeps the face of the campaign so far. */
        } else {
            shm_suspects[cell].visuals =
                shm_campaign.mastermind_visuals;
        }
        shm_suspects[cell].alert_level = 0;
        return cell;
    }
    /* Only looking, and nobody there. */
    return -1;
}
