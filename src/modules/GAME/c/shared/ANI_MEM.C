/* ANI_MEM.C -- decoding a picture that is already in memory.
 */
#include "GAME.H"
#include "REFILL.H"

/* The decoder's refill routine: a far call back into this module. */
typedef INT (FAR *READER)();

/* shared_include_start: ../../../../shared/c/ANIM-FROM-MEMORY.C -- generated */
/* ANIM-FROM-MEMORY.C -- c_animation_from_memory, unpacking a held picture.
 */

/* Decode the packed picture at the start of segment `src` onto surface `a`. */
INT c_animation_from_memory(UNSIGNED_INT src, UNSIGNED_INT a)
{
    INT i;

    shm_source_dst = 0;
    shm_source_src = src;
    shm_source_at = shd_archive_buffer_end;
    *(INT (FAR **) ()) &shm_refill = c_refill_from_memory;
    drv_real_unpack_start();
    for (i = 0; i < shm_sprite_height; i++) {
        drv_real_unpack_row(shm_anim_row_2);
        drv_jump_gfx_row_put(shm_anim_row_2, a, i, 0, shm_sprite_width);
    }
}
/* shared_include_end: ../../../../shared/c/ANIM-FROM-MEMORY.C */
