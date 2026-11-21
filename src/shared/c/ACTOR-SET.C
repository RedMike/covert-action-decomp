/* ACTOR-SET.C -- c_actor_set, starting an actor on its script in a slot.
 */

void c_actor_set(INT slot, INT script, INT parent, INT home_x, INT home_y,
                     INT rate, INT overlay)
{
    struct ACTOR FAR *p;
    char FAR *pc;

    p = &shm_seq_data.actors[slot] - 1;
    p->in_use = 1;
    p->hidden = 0;
    p->parent = parent - 1;
    p->home_x = home_x;
    p->home_y = home_y;
    if (p->parent + 1 == -1) {
        p->x = p->home_x;
        p->y = p->home_y;
    } else {
        p->x = 0;
        p->y = 0;
    }
    p->rate = rate;
    p->speed = rate;
    p->credit = 0xff;
    p->depth = 0;
    p->script = script;
    p->overlay = overlay;
    SET_POINTER_AT(pc, shm_anim_segment, p->script);
    p->pc = pc;
}
