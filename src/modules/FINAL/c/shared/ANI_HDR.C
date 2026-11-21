/* ANI_HDR.C -- reading an animation file's optional header blocks.
 */
#include "FINAL.H"
#include "ANIMREAD.H"
#include "ANIMHDR.H"

/* shared_include_start: ../../../../shared/c/ANIM-BLOCKS.C -- generated */
/* ANIM-BLOCKS.C -- c_anim_extra_blocks, reading an animation's palette block.
 */

/* Read the palette the header's flag bytes announce: 11h bytes for kind 0,
 * 306h for kind 2, else none.
 */
INT c_anim_extra_blocks(void)
{
    c_anim_read((char *) &shm_anim_more, 1, 1);
    if (shm_anim_more == 0)
        return;
    c_anim_read((char *) &shm_anim_block_kind, 1, 1);
    switch (shm_anim_block_kind) {
    case 0:
        c_anim_read((char *) shm_anim_palette, 0x11, 1);
        break;
    case 1:
        break;
    case 2:
        c_anim_read((char *) shm_anim_palette, 0x306, 1);
        break;
    }
}
/* shared_include_end: ../../../../shared/c/ANIM-BLOCKS.C */
