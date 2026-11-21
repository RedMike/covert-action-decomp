/* shared/CAMPAIGN-MISSION-START.C -- the shared routines in CAMPAIGN-MISSION-START.C's unit, after CAMPAIGN-MISSION-START.C. */
#include "FINAL.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "SCREEN.H"
#include "CSTART.H"
#include "CMISEND.H"
#include "CASERUN.H"
#include "CMISSTRT.H"
#include "ROLEFLAG.H"

/* shared_include_start: ../../../../shared/c/CLEAR-HAPPEN-TICKS.C -- generated */
/* CLEAR-HAPPEN-TICKS.C -- c_clear_happen_ticks, resetting every crime event.
 */

/* Mark every crime event as still to happen, a happen_tick of 999. `spare` is
 * unused, kept for the frame's size.
 */
void c_clear_happen_ticks(void)
{
    INT i;
    INT spare;

    for (i = 0; i < shm_crime_event_count; i++)
        shm_crime_events[i].happen_tick = 999;
}
/* shared_include_end: ../../../../shared/c/CLEAR-HAPPEN-TICKS.C */

