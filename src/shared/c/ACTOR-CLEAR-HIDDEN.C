/* ACTOR-CLEAR-HIDDEN.C -- c_actor_clear_hidden, unhiding every actor in use.
 */

void c_actor_clear_hidden(void)
{
    struct ACTOR FAR *p;
    INT act;

    for (act = 0; act < 0x32; act++) {
        p = &shm_seq_data.actors[act];
        if (p->in_use != 0 && p->hidden != 0)
            p->hidden = 0;
    }
}
