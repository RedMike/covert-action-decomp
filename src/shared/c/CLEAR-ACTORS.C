/* CLEAR-ACTORS.C -- c_actor_clear_all, freeing every actor slot.
 */

void c_actor_clear_all(void)
{
    INT i;

    for (i = 0; i < 0x32; i++)
        shm_seq_data.actors[i].in_use = 0;
}
