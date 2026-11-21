/* MAIN-3.C -- more of the module's own routines in MAIN.C's unit, after stubs/MAIN.C. */
#include "BUG.H"
#include "LOADDISK.H"
#include "ANIMSTUB.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "MENU.H"
#include "BOARD.H"
#include "MAIN.H"
#include "RESULT.H"

/* Run the menu `a` with its position left at zero.
 */
void c_show_menu(rt_addr a)
{
    c_menu_run(a, 0, 0);
}

