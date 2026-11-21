/* ASK-MENU.C -- the one-line wrapper that puts a message up.
 */
#include "BUG.H"
#include "MENU.H"
#include "BOARD.H"

/* shared_include_start: ../../../../shared/c/ASK-MENU.C -- generated */
/* ASK-MENU.C -- c_ask_menu, putting up a menu and answering the choice.
 */

/* Run the menu `text` at (x, y) and answer the choice, straight through to
 * c_menu_run.
 */
INT c_ask_menu(rt_addr text, INT x, INT y)
{
    return c_menu_run(text, x, y);
}
/* shared_include_end: ../../../../shared/c/ASK-MENU.C */
