/* ALL-ACTORS-DRAW.C -- c_actor_draw_all, drawing every actor in use.
 */

void c_actor_draw_all(void)
{
    INT i;

    for (i = 0; i < 0x32; i++)
        if (shm_seq_data.actors[i].in_use != 0)
            c_actor_draw(i);
}
