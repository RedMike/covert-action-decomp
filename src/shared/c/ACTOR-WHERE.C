/* ACTOR-WHERE.C -- c_actor_where, an actor's position, its parent's included.
 */

void c_actor_where(INT slot, INT *x, INT *y)
{
    struct ACTOR FAR *p;

    p = &shm_seq_data.actors[slot];
    if (p->parent + 1 == -1) {
        *x = p->x;
        *y = p->y;
    } else if (p->parent + 1 > 0 || p->parent + 1 > 0x32) {
        if (shm_seq_data.actors[p->parent].in_use == 0)
            return;
        *x = shm_seq_data.actors[p->parent].x + p->home_x + p->x;
        *y = shm_seq_data.actors[p->parent].y + p->home_y + p->y;
    }
}
