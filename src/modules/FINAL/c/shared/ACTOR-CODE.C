/* ACTOR-CODE.C -- one actor's byte-code, one step of it.
 *
 * `speed` is added to `credit` every call and each 255 buys a step, which runs
 * opcodes until one sets the picture (00h), halts (09h) or retires it (0Ah).
 * `pc` keeps the cursor's segment, as a jump writes back only the offset.
 */
#include "FINAL.H"
#include "ACTORS.H"

/* shared_include_start: ../../../../shared/c/ACTOR-STEP.C -- generated */
/* ACTOR-STEP.C -- c_actor_step, running an actor's script to its next frame.
 */

void c_actor_step(INT slot)
{
    struct ACTOR FAR *p;
    char FAR *pc;
    char FAR *prev;
    INT op;

    p = &shm_seq_data.actors[slot];
    if (p->in_use == 0)
        return;
    p->credit += p->speed;
    if (p->credit <= 0xff)
        return;
    p->credit -= 0xff;
    pc = p->pc;
    for (;;) {
        op = *p->pc;
        if (op == 0) {
            p->frame = p->pc[1];
            p->pc += 2;
            return;
        }
        if (op == 1) {
            p->x = *(INT FAR *) (p->pc + 1);
            p->y = *(INT FAR *) (p->pc + 3);
            p->pc += 5;
        }
        if (op == 2) {
            p->x += *(INT FAR *) (p->pc + 1);
            p->y += *(INT FAR *) (p->pc + 3);
            p->pc += 5;
        }
        if (op == 3) {
            p->speed = *(INT FAR *) (p->pc + 1);
            p->pc += 3;
        }
        if (op == 4) {
            p->speed += *(INT FAR *) (p->pc + 1);
            p->pc += 3;
        }
        if (op == 5) {
            p->loops[p->depth++] = *(INT FAR *) (p->pc + 1);
            p->pc += 3;
        }
        if (op == 6) {
            if (--p->loops[p->depth - 1] != 0) {
                SET_POINTER_WITHIN(pc, *(INT FAR *) (p->pc + 1));
                p->pc = pc;
            } else {
                p->depth--;
                p->pc += 3;
            }
        }
        if (op == 7) {
            if (p->parent + 1 == -1) {
                p->x = p->home_x;
                p->y = p->home_y;
            } else {
                p->x = 0;
                p->y = 0;
            }
            p->speed = p->rate;
            p->credit = 0xff;
        }
        if (op == 8 || op == 7) {
            p->depth = 0;
            SET_POINTER_WITHIN(pc, p->script);
            p->pc = pc;
        }
        if (op == 9)
            return;
        if (op == 10) {
            p->in_use = 0;
            return;
        }
    }
}
/* shared_include_end: ../../../../shared/c/ACTOR-STEP.C */
