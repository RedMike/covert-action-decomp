/* HOOK-HAND-BACK.C -- telling the shared block that nothing runs next.
 */
#include "CODE.H"
#include "SETUP.H"

/* Put 0ffh back in the shared block's next-module byte when asked to, which
 * says the module has nothing to hand on. The argument is a long, as its sites
 * push it.
 */
void c_hook_hand_back(LONG hand_back)
{
    /* Quitting the game outright leaves nothing to run next. */
    if ((INT) hand_back)
        COMM()->next_module = NONE_EXIT;
}
