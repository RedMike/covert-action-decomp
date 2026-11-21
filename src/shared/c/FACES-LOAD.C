/* FACES-LOAD.C -- c_faces_load, loading every sprite the face system uses.
 */

/* Load the face system's sprites: the faces, the sixteen 8-by-8 sprites under
 * them in faces.pic, the plane at eight headings and its shadow.
 */
void c_faces_load(void)
{
    INT i;

    drv_jump_gfx_pool_alloc();
    c_faces_cut();
    i = 0;
    do {
        shm_faces_sprites[SPRITE_PLANE + i] =
            drv_jump_gfx_grab(2, i % 8 * 9, i / 8 * 9 + 0xaf, 8, 8);
        i++;
    } while (i < 16);
    drv_jump_gfx_pool_release();
    shm_menu_face = 0xffff;
}
