/* FACES-CUT.C -- c_faces_cut, cutting the face sprites out of their pictures.
 */

/* Cut the face sprites out of facesf.pic and faces.pic: forty face parts and
 * four bodies from each, then faces.pic's clue sources, paperclip, folder ends
 * and typewriter.
 */
void c_faces_cut(void)
{
    INT i;
    INT spare;

    c_decode_picture(2, shd_str_facesf_pic);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_FACES_0 + i] =
            drv_jump_gfx_grab(2, i % 8 * 32 + 1, i / 8 * 0x23 + 1, 0x1e, 0x21);
        i++;
    } while (i < 40);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_BODIES_0 + i] =
            drv_jump_gfx_grab(2, 0x101, i * 20, 0x2c, 0x12);
        i++;
    } while (i < 4);
    c_decode_picture(2, shd_str_faces_pic);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_FACES_1 + i] =
            drv_jump_gfx_grab(2, i % 8 * 32 + 1, i / 8 * 0x23 + 1, 0x1e, 0x21);
        i++;
    } while (i < 40);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_CLUE_SOURCE + i] =
            drv_jump_gfx_grab(2, i * 32 + 0x60, 0xae, 0x20, 0x1a);
        i++;
    } while (i < 7);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_BODIES_1 + i] =
            drv_jump_gfx_grab(2, 0x101, i * 20, 0x2c, 0x12);
        i++;
    } while (i < 4);
    shm_faces_sprites[SPRITE_PAPERCLIP] =
        drv_jump_gfx_grab(2, 0x49, 0xaf, 0x15, 0x16);
    shm_faces_sprites[SPRITE_FOLDER_START] =
        drv_jump_gfx_grab(2, 0x133, 0, 0xb, 8);
    shm_faces_sprites[SPRITE_FOLDER_END] =
        drv_jump_gfx_grab(2, 0x133, 9, 0xc, 8);
    shm_faces_sprites[SPRITE_TYPEWRITER] =
        drv_jump_gfx_grab(2, 0x101, 0xa0, 0x1a, 0xe);
}
