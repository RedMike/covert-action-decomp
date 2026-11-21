/* ANI_BLKS.C -- loading what an animation is drawn from.
 *
 * The sprite table is read as a list of "a sprite is here" and each such entry
 * replaced with the handle of the frame decoded for it; the byte-code block is
 * allocated and read in whole. Either answers 0 on a failure.
 */
#include "FINAL.H"
#include "ANIMREAD.H"
#include "ANIMFRM.H"
#include "ANI_CHNK.H"

/* shared_include_start: ../../../../shared/c/ANIM-SPRITES.C -- generated */
/* ANIM-SPRITES.C -- c_anim_sprites, reading every sprite of an animation.
 */

INT c_anim_sprites(void)
{
    INT ok;
    INT spare;
    INT n;

    ok = 1;
    c_anim_read((char *) shm_anim_sprites, 2, 0xfa);
    if (drv_jump_gfx_pool_alloc() == 0)
        return 0;
    for (n = 0; n < 0xfa; n++)
        if (shm_anim_sprites[n] != 0) {
            shm_anim_sprites[n] = c_anim_frame();
            if (shm_anim_sprites[n] == 0) {
                shm_anim_error = 0;
                ok = 0;
                break;
            }
        }
    drv_jump_gfx_pool_release();
    return ok;
}
/* shared_include_end: ../../../../shared/c/ANIM-SPRITES.C */

/* shared_include_start: ../../../../shared/c/ANIM-PARAGRAPHS.C -- generated */
/* ANIM-PARAGRAPHS.C -- c_anim_paragraphs, loading an animation's script block.
 */

INT c_anim_paragraphs(void)
{
    char FAR *p;
    UNSIGNED_INT total;
    UNSIGNED_INT paras;
    UNSIGNED_INT i;
    UNSIGNED_INT avail;

    c_anim_read((char *) &paras, 2, 1);
    avail = drv_jump_mem_avail();
    if (avail < paras) {
        shm_anim_error = 0;
        return 0;
    }
    _dos_allocmem(paras, (rt_addr) &shm_anim_segment);
    SET_POINTER_START(p, shm_anim_segment);
    total = paras << 4;
    for (i = 0; i < total; i++)
        *p++ = c_anim_byte();
    /* The byte count, which is nonzero for success. */
    return (total);
}
/* shared_include_end: ../../../../shared/c/ANIM-PARAGRAPHS.C */
