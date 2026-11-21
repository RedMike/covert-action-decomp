/* ASM.C -- stubs for the assembly routines FINAL's C calls.
 *
 * The critical-error hook and its release do nothing and answer 0, so the
 * module links.
 */

#include "FINAL.H"

UNSIGNED_INT shm_hook_critical_error(void)
{
    return 0;
}

UNSIGNED_INT shm_unhook_critical_error(void)
{
    return 0;
}
