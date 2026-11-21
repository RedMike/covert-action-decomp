/* ANIM-ROWS.C -- c_anim_frame_rows, reading one frame straight onto a page.
 */

void c_anim_frame_rows(INT arg)
{
    INT i;

    if ((shd_archive_buffer_end - shm_source_at) % 2 != 0)
        c_anim_byte();
    if (shm_anim_packed != 0)
        drv_real_unpack_start();
    else
        c_anim_frame_header();
    for (i = 0; i < shm_sprite_height; i++) {
        if (shm_anim_packed != 0)
            drv_real_unpack_row((rt_addr) shm_anim_row);
        else
            c_anim_read(shm_anim_row, 1, shm_sprite_width);
        drv_jump_gfx_row_put((rt_addr) shm_anim_row, arg, i, 0, shm_sprite_width);
    }
}
