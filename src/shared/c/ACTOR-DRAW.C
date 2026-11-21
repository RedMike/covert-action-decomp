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
