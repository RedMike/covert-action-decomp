/* PACE.C -- pacing an animation's frames, and installing its palette.
 */
#include "GAME.H"
#include "PACE.H"

/* Install the palette the animation file carried, if it carried one. */
void c_seq_apply_palette(void)
{
    if (shm_anim_more != 0) {
        /* Palette register 0 always stays colour 0. */
        shm_anim_palette[0] = 0;
        drv_jump_gfx_set_palette((struct PALETTE *) shm_anim_palette);
    }
}
