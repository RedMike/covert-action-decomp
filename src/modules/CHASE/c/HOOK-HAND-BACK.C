/* HOOK-HAND-BACK.C -- marking that the module hands nothing on.
 */
#include "CHASE.H"
#include "SETUP.H"

/* If `hand_back` is non-zero, put 0ffh in the first byte of the shared block,
 * which says the module has nothing to hand on. The argument is a long, as its
 * sites push it.
 */
void c_hook_hand_back(LONG hand_back)
{
    if ((INT) hand_back)
        COMM()->next_module = NONE_EXIT;
}
