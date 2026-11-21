/* FRAME-SHOW.C -- putting a finished frame on screen: its palette here, and the
 * blit in shared/FRAME-SHOW.C after it.
 */
#include "FINAL.H"
#include "SEQFRAME.H"

void c_seq_apply_palette(void)
{
    /* Only an animation whose header carried a palette block changes the palette. */
    if (shm_anim_more != 0) {
        /* Keep palette register 0, the background, at black, then load the rest. */
        shm_anim_palette[0] = 0;
        drv_real_FUN_1000_00ca((struct PALETTE *) shm_anim_palette);
    }
}
