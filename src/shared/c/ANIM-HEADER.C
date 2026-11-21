/* ANIM-HEADER.C -- c_anim_frame_header, reading a plain frame's size.
 */

/* Read a plain frame's header, three words: one skipped, then the width and
 * the row count.
 */
INT c_anim_frame_header(void)
{
    INT ignored;

    c_anim_read((char *) &ignored, 1, 2);
    c_anim_read((char *) &shm_sprite_width, 1, 2);
    c_anim_read((char *) &shm_sprite_height, 1, 2);
}
