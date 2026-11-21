/* PROMPT.C -- putting a question up.
 */
#include "TAC.H"
#include "PORTING.H"
#include "MENU.H"
#include "PROMPT.H"

/* Put a question up, answer the choice, and leave the screen ready to draw
 * over again. */
INT c_ask_menu(drv_addr text, INT arg2, INT arg3)
{
    INT v0j;    /* what was chosen */

    /* Ask, then put back the background pen the break-in's drawing expects. */
    v0j = c_menu_run(text, arg2, arg3);
    shd_screen->bg_pen = 1;
    return (v0j);
}
