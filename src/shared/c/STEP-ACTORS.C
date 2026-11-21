/* STEP-ACTORS.C -- c_actor_step_all, stepping every actor.
 */

void c_actor_step_all(void)
{
    INT i;

    for (i = 0; i < 0x32; i++)
        c_actor_step(i);
}
