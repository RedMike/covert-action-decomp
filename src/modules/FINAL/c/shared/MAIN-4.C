/* shared/MAIN-4.C -- the shared routines in MAIN.C's unit, after MAIN-5.C. */
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

/* shared_include_start: ../../../../shared/c/DISPLAY-PAGE.C -- generated */
/* DISPLAY-PAGE.C -- c_set_display_page, choosing the page the screen shows.
 */

/* Make `page` the BIOS's active display page: INT 10h function 5, through the
 * shared register block.
 */
void c_set_display_page(char page)
{
    shm_regs.h.ah = 5;
    shm_regs.h.al = page;
    INTERRUPT(0x10, &shm_regs, &shm_regs);
}
/* shared_include_end: ../../../../shared/c/DISPLAY-PAGE.C */
