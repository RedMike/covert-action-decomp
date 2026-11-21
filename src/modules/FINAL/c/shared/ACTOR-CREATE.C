/* ACTOR-CREATE.C -- taking an actor slot, clearing them all, filling one in.
 *
 * Slot numbers here are one-based, so a subscript takes one off: nought means
 * "no actor", and a caller can hold a slot in the word it holds "none" in.
 */
#include "FINAL.H"
#include "ACTORS.H"

/* shared_include_start: ../../../../shared/c/ACTOR-SLOT.C -- generated */
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
/* shared_include_end: ../../../../shared/c/ACTOR-SLOT.C */

/* shared_include_start: ../../../../shared/c/CLEAR-ACTORS.C -- generated */
/* CLEAR-ACTORS.C -- c_actor_clear_all, freeing every actor slot.
 */

void c_actor_clear_all(void)
{
    INT i;

    for (i = 0; i < 0x32; i++)
        shm_seq_data.actors[i].in_use = 0;
}
/* shared_include_end: ../../../../shared/c/CLEAR-ACTORS.C */

/* shared_include_start: ../../../../shared/c/ACTOR-SET.C -- generated */
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
/* shared_include_end: ../../../../shared/c/ACTOR-SET.C */
