/* ANI_FRAME.C -- decoding one frame of an animation into a sprite.
 */
#include "FINAL.H"
#include "ANIMREAD.H"
#include "ANIMFRM.H"

/* shared_include_start: ../../../../shared/c/ANIM-FRAME.C -- generated */
/* ANIM-FRAME.C -- c_anim_frame, reading one animation frame into a sprite.
 */

/* Read one frame into a sprite through the driver; answer the sprite, or 0 if
 * a row was refused. shm_anim_packed picks packed rows or plain ones.
 */
INT c_anim_frame(void)
{
    INT row;

    if ((shd_archive_buffer_end - shm_source_at) % 2 != 0)
        c_anim_byte();
    if (shm_anim_packed != 0)
        drv_real_unpack_start();
    else
        c_anim_frame_header();
    drv_jump_gfx_sprite_begin(shm_sprite_width, shm_sprite_height);
    for (row = 0; row < shm_sprite_height; row++) {
        if (shm_anim_packed != 0)
            drv_real_unpack_row((rt_addr) shm_anim_row);
        else
            c_anim_read(shm_anim_row, 1, shm_sprite_width);
        if (drv_jump_gfx_sprite_row((rt_addr) shm_anim_row) == 0)
            return 0;
    }
    return drv_jump_gfx_sprite_end();
}
/* shared_include_end: ../../../../shared/c/ANIM-FRAME.C */


/* shared_include_start: ../../../../shared/c/ANIM-HEADER.C -- generated */
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
/* shared_include_end: ../../../../shared/c/ANIM-HEADER.C */
