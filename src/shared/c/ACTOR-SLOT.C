/* ACTOR-SLOT.C -- c_actor_take_slot, finding the first free actor slot.
 */

INT c_actor_take_slot(void)
{
    INT i;

    for (i = 1; i <= 0x32; i++)
        if (shm_seq_data.actors[i - 1].in_use == 0)
            return i;
    return i - 1;
}
