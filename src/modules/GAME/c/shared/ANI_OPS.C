/* ANI_OPS.C -- the byte-code a PAN animation is written in, and its actors.
 */
#include "GAME.H"
#include "ANI_OPS.H"
#include "ANI_READ.H"

/* shared_include_start: ../../../../shared/c/SEQ-CODE.C -- generated */
/* SEQ-CODE.C -- c_seq_code, the animation script interpreter.
 */

INT c_seq_code(void)
{
    while (shm_seq_done == 0) {
        switch (shm_seq_wait) {
        case 0:
        shm_seq_op = *shm_seq_pc;
        if (shm_seq_op == 0) {
            if (shm_seq_data.stack[shm_seq_depth - 6] == -1)
                shm_seq_data.stack[shm_seq_depth - 6] = c_actor_take_slot();
            if (shm_seq_data.stack[shm_seq_depth - 6] > 0
                    && shm_seq_data.stack[shm_seq_depth - 6] <= 0x32)
                c_actor_set(shm_seq_data.stack[shm_seq_depth - 6],
                                shm_seq_data.stack[shm_seq_depth - 7],
                                shm_seq_data.stack[shm_seq_depth - 5],
                                shm_seq_data.stack[shm_seq_depth - 4],
                                shm_seq_data.stack[shm_seq_depth - 3],
                                shm_seq_data.stack[shm_seq_depth - 2],
                                shm_seq_data.stack[shm_seq_depth - 1]);
            shm_seq_depth -= 7;
            shm_seq_pc++;
        }
        if (shm_seq_op == 1) {
            if (shm_seq_data.stack[shm_seq_depth - 1] > 0
                    && shm_seq_data.stack[shm_seq_depth - 1] <= 0x32)
                shm_seq_data.actors[shm_seq_data.stack[shm_seq_depth - 1]
                                   - 1].in_use = 0;
            shm_seq_depth--;
            shm_seq_pc++;
        }
        if (shm_seq_op == 2) {
            shm_seq_depth--;
            shm_seq_operand = shm_seq_data.stack[shm_seq_depth];
            shm_seq_wait = 1;
            shm_seq_pc++;
        }
        if (shm_seq_op == 3) {
            shm_seq_depth--;
            shm_seq_data.queue[shm_seq_sound_queue_count++] =
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 4) {
            if (shm_seq_data.stack[shm_seq_depth - 1] > 0
                    && shm_seq_data.stack[shm_seq_depth - 1] <= 0x32)
                shm_seq_data.actors[shm_seq_data.stack[shm_seq_depth - 1]
                                   - 1].hidden = 1;
            shm_seq_depth--;
            shm_seq_pc++;
        }
        if (shm_seq_op == 5) {
            shm_seq_operand = *(INT FAR *) (shm_seq_pc + 2);
            if (shm_seq_pc[1] != 0)
                shm_seq_operand =
                    shm_seq_vars[shm_seq_operand];
            shm_seq_data.stack[shm_seq_depth++] = shm_seq_operand;
            shm_seq_pc += 4;
        }
        if (shm_seq_op == 6) {
            shm_seq_depth--;
            shm_seq_operand = *(INT FAR *) (shm_seq_pc + 1);
            if (shm_seq_operand >= 0
                    && shm_seq_operand < 0x33)
                shm_seq_vars[shm_seq_operand] =
                    shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc += 3;
        }
        if (shm_seq_op == 7) {
            shm_seq_depth++;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 2];
            shm_seq_pc++;
        }
        if (shm_seq_op == 8) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                == shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 9) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                != shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 10) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                > shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 11) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                < shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 12) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                >= shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 13) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                <= shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 14) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] +=
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 15) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] -=
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 0x10) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] *=
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 0x11) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] /=
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 0x12) {
            shm_seq_depth--;
            if (shm_seq_data.stack[shm_seq_depth] == 0)
                shm_seq_pc += 3;
            else
                SET_POINTER_WITHIN(shm_seq_pc, *(INT FAR *) (shm_seq_pc + 1));
        }
        if (shm_seq_op == 0x13)
            SET_POINTER_WITHIN(shm_seq_pc, *(INT FAR *) (shm_seq_pc + 1));
        if (shm_seq_op == 0x14)
            return 0;
        if (shm_seq_op == 0x15)
            shm_seq_done = 1;
        if (shm_seq_op == 0x17) {
            shm_seq_data.stack[shm_seq_depth++] =
                GET_POINTER_WITHIN(shm_seq_pc) + 3;
            SET_POINTER_WITHIN(shm_seq_pc, *(INT FAR *) (shm_seq_pc + 1));
        }
        if (shm_seq_op == 0x16) {
            shm_seq_depth--;
            SET_POINTER_WITHIN(shm_seq_pc, shm_seq_data.stack[shm_seq_depth]);
        }
            break;
        case 1:
            if (shm_seq_operand-- != 0)
                return 0;
            shm_seq_wait = 0;
            break;
        }
    }
    return 1;
}
/* shared_include_end: ../../../../shared/c/SEQ-CODE.C */

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

/* shared_include_start: ../../../../shared/c/ACTOR-HIDDEN.C -- generated */
/* ACTOR-HIDDEN.C -- c_actor_draw_hidden, drawing hidden actors on page two.
 */

void c_actor_draw_hidden(void)
{
    struct ACTOR FAR *p;
    INT x;
    INT y;
    INT n;

    for (n = 0; n < 0x32; n++)
        if (shm_seq_data.actors[n].in_use != 0 && shm_seq_data.actors[n].hidden != 0) {
            p = &shm_seq_data.actors[n];
            c_actor_where(n, &x, &y);
            drv_real_sprite_put_2(shd_anim_page_2, x, y,
                              shm_anim_sprites[p->frame]);
        }
}
/* shared_include_end: ../../../../shared/c/ACTOR-HIDDEN.C */

/* shared_include_start: ../../../../shared/c/ALL-ACTORS-DRAW.C -- generated */
/* ALL-ACTORS-DRAW.C -- c_actor_draw_all, drawing every actor in use.
 */

void c_actor_draw_all(void)
{
    INT i;

    for (i = 0; i < 0x32; i++)
        if (shm_seq_data.actors[i].in_use != 0)
            c_actor_draw(i);
}
/* shared_include_end: ../../../../shared/c/ALL-ACTORS-DRAW.C */

/* shared_include_start: ../../../../shared/c/ACTOR-DRAW.C -- generated */
/* ACTOR-DRAW.C -- c_actor_draw, drawing one visible actor's current frame.
 */

void c_actor_draw(INT slot)
{
    struct ACTOR FAR *p;
    INT x;
    INT y;

    p = &shm_seq_data.actors[slot];
    if (p->frame != 0xff && p->hidden == 0) {
        c_actor_where(slot, &x, &y);
        if (p->overlay != 0)
            drv_jump_gfx_sprite_put_clipped(shd_anim_page, x, y,
                              shm_anim_sprites[p->frame]);
        else
            drv_real_sprite_put(shd_anim_page, x, y,
                              shm_anim_sprites[p->frame]);
    }
}
/* shared_include_end: ../../../../shared/c/ACTOR-DRAW.C */

/* shared_include_start: ../../../../shared/c/ACTOR-CLEAR-HIDDEN.C -- generated */
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
/* shared_include_end: ../../../../shared/c/ACTOR-CLEAR-HIDDEN.C */

/* shared_include_start: ../../../../shared/c/ACTOR-WHERE.C -- generated */
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
/* shared_include_end: ../../../../shared/c/ACTOR-WHERE.C */

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

/* shared_include_start: ../../../../shared/c/MATCH-COLOUR.C -- generated */
/* MATCH-COLOUR.C -- c_palette_match, finding the palette entry for a colour.
 */

INT c_palette_match(char *buf)
{
    INT i;

    for (i = 0; i < 0x101; i++)
        if (memcmp(buf + 0x303, buf + i * 3, 3) == 0)
            break;
    return c_set_border_colour(i);
}
/* shared_include_end: ../../../../shared/c/MATCH-COLOUR.C */
