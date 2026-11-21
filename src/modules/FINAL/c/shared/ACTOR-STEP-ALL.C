/* ACTOR-STEP-ALL.C -- one step of every actor's byte-code.
 *
 * The loop is zero-based: it indexes the array rather than naming a slot.
 */
#include "FINAL.H"
#include "ACTORS.H"

/* shared_include_start: ../../../../shared/c/STEP-ACTORS.C -- generated */
/* STEP-ACTORS.C -- c_actor_step_all, stepping every actor.
 */

void c_actor_step_all(void)
{
    INT i;

    for (i = 0; i < 0x32; i++)
        c_actor_step(i);
}
/* shared_include_end: ../../../../shared/c/STEP-ACTORS.C */
