/* ASM.C -- portable stubs for the assembly routines the C calls.
 *
 * The critical-error hook and its release each do nothing and answer 0, so
 * the module links.
 */

#include "GAME.H"

UNSIGNED_INT shm_hook_critical_error(void)
{
    return 0;
}

UNSIGNED_INT shm_unhook_critical_error(void)
{
    return 0;
}
