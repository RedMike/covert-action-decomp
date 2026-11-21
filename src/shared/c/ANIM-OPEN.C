/* ANIM-OPEN.C -- c_anim_open, loading an animation file.
 */

/* Load the animation file `name`; answer 1, or 0 if the signature is wrong or
 * the sprites or the memory fail.
 */
INT c_anim_open(rt_addr name)
{
    INT unused;
    INT spare;

    shm_anim_fd = c_open(name, 0x8000);
    c_decode_from_file(shm_anim_fd);
    if (c_anim_signature(name) == 0) {
        c_close(shm_anim_fd);
        return 0;
    }
    c_anim_extra_blocks();
    c_anim_start_chunks();
    c_anim_chunk();
    if (c_anim_sprites() == 0 || c_anim_paragraphs() == 0) {
        c_close(shm_anim_fd);
        return 0;
    }
    c_close(shm_anim_fd);
    return 1;
}
