/* shared/CAMPAIGN-MISSION-END-2.C -- the shared routines in CAMPAIGN-MISSION-END.C's unit, after CAMPAIGN-MISSION-END-2.C. */
#include "FINAL.H"
#include "SPRITES.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "ARCHIVE.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "MENUS.H"
#include "SEQUENCE.H"
#include "LOADDISK.H"
#include "SCREEN.H"
#include "MAIN.H"
#include "CSTART.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "ORIENT.H"
#include "SAVELOAD.H"
#include "CASERUN.H"
#include "CMISEND.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* shared_include_start: ../../../../shared/c/TRIM-TO-WIDTH.C -- generated */
/* TRIM-TO-WIDTH.C -- c_trim_to_width, cutting text down to a width.
 */

/* Drop characters from the end of the scratch string until it fits `width`
 * pixels, measuring again after each.
 */
void c_trim_to_width(INT width)
{
    while ((INT) c_text_width((rt_addr) shm_scratch) > width)
        *((unsigned char *) shm_scratch
          + strlen(shm_scratch) - 1) = 0;
}
/* shared_include_end: ../../../../shared/c/TRIM-TO-WIDTH.C */

