/* ANI_LOAD.C -- reading a file through the decoder without keeping it.
 *
 * Compiled with `/Ol`, which the decode loop's code needs.
 */
#include "CHASE.H"
#include "ARCFILE.H"
#include "SRCFILE.H"

/* shared_include_start: ../../../../shared/c/DECODE-SCAN.C -- generated */
/* DECODE-SCAN.C -- c_decode_scan, decoding a picture file into a sprite.
 */

/* Decode picture file `name` into a new sprite, a row at a time through the
 * driver, and answer the sprite the driver builds.
 */
INT c_decode_scan(rt_addr name)
{
    INT i;
    INT handle;

    handle = c_open(name, 0);
    c_decode_from_file(handle);
    drv_real_unpack_start();
    drv_jump_gfx_sprite_begin(shm_sprite_width, shm_sprite_height);
    for (i = 0; i < shm_sprite_height; i++) {
        drv_real_unpack_row(shm_anim_row_2);
        drv_jump_gfx_sprite_row(shm_anim_row_2);
    }
    c_close(handle);
    return drv_jump_gfx_sprite_end();
}
/* shared_include_end: ../../../../shared/c/DECODE-SCAN.C */
