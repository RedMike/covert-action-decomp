/* ANI_CODE.C -- decoding a file into a surface, block by block.
 *
 * Compiled with `/Ol`.
 */
#include "CHASE.H"
#include "ARCFILE.H"
#include "SRCFILE.H"
#include "FILEIO.H"

/* shared_include_start: ../../../../shared/c/PICTURE-DECODE.C -- generated */
/* PICTURE-DECODE.C -- c_decode_picture, reading a picture from a file.
 */

/* Open `name`, decode its picture row by row onto surface `a`, and answer what
 * closing the file answers.
 */
INT c_decode_picture(UNSIGNED_INT a, rt_addr name)
{
    INT i;
    INT handle;

    handle = c_open(name, 0);
    c_decode_from_file(handle);
    drv_real_unpack_start();
    for (i = 0; i < shm_sprite_height; i++) {
        drv_real_unpack_row(shm_anim_row_2);
        drv_jump_gfx_row_put(shm_anim_row_2, a, i, 0, shm_sprite_width);
    }
    return c_close(handle);
}
/* shared_include_end: ../../../../shared/c/PICTURE-DECODE.C */
