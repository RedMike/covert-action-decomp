/* ACTOR-DRAW.C -- putting the actors on the screen, and where each one is.
 *
 * Hidden actors go to the second page and shown ones to the first; the hidden
 * flag lasts until cleared. A child stands at its parent's position plus its
 * offset and its own `x`, `y`; a parent not in use leaves it unplaced.
 */
#include "FINAL.H"
#include "ACTORS.H"

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
