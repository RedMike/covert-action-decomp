/* shared/ADVICE.C -- the shared routines in ADVICE.C's unit, before ADVICE.C. */

#include "GAME.H"
#include "PROSE.H"
#include "CMP_STRT.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DIALOG.H"
#include "CASE.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "ANI_PLAY.H"
#include "WRAP.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"
#include "ORIENT.H"
#include "SUSPFLAG.H"

#ifdef FLEXIBLE_ORIENTATION
/* shared_include_start: ../../../../shared/c/ORIENTATION.C -- generated */
/* ORIENTATION.C -- the orientation settings and their load.
 */

INT orientation;
INT mission_orientation;

/* Read both from the shared block, where the mission's is stored plus one and
 * 0 stands in the agent's own sex. */
void c_orientation_load(void)
{
    INT paired;

    orientation = COMM()->spare_66[COMM_ORIENTATION];
    paired = COMM()->spare_66[COMM_MISSION_ORIENTATION];
    mission_orientation = paired != 0 ? paired - 1 : (shm_options & OPT_FEMALE) != 0;
}
/* shared_include_end: ../../../../shared/c/ORIENTATION.C */
#endif

