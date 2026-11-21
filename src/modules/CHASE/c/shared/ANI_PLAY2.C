/* ANI_PLAY2.C -- decoding a file into a surface, with the arguments swapped.
 *
 * Compiled with `/Ol`, which the decode loop's code needs.
 */
#include "CHASE.H"
#include "ARCFILE.H"
#include "SRCFILE.H"

/* shared_include_start: ../../../../shared/c/LOAD-ANIM.C -- generated */
/* LOAD-ANIM.C -- c_load_anim, decoding a picture file onto a surface.
 */

/* Open `name` and decode it into surface `a`, answering nothing. The file is
 * left open.
 */
INT c_load_anim(rt_addr name, UNSIGNED_INT a)
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
}
/* shared_include_end: ../../../../shared/c/LOAD-ANIM.C */
