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
