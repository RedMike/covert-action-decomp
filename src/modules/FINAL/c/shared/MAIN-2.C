/* shared/MAIN-2.C -- the shared routines in MAIN.C's unit, after MAIN-3.C. */
#include "FINAL.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "LOADDISK.H"
#include "CSTART.H"
#include "CMISEND.H"
#include "CMISSTRT.H"
#include "CASERUN.H"
#include "SAVELOAD.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "MAIN.H"
#include "ORIENT.H"
#include "MODOPTS.H"
#include "SETUPTXT.H"
#include "RESULT.H"
#include "ALERTLVL.H"

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
