/* ANIM-SPRITES.C -- c_anim_sprites, reading every sprite of an animation.
 */

INT c_anim_sprites(void)
{
    INT ok;
    INT spare;
    INT n;

    ok = 1;
    c_anim_read((char *) shm_anim_sprites, 2, 0xfa);
    if (drv_jump_gfx_pool_alloc() == 0)
        return 0;
    for (n = 0; n < 0xfa; n++)
        if (shm_anim_sprites[n] != 0) {
            shm_anim_sprites[n] = c_anim_frame();
            if (shm_anim_sprites[n] == 0) {
                shm_anim_error = 0;
                ok = 0;
                break;
            }
        }
    drv_jump_gfx_pool_release();
    return ok;
}
