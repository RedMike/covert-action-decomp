/* PAGE-SWAP.C -- the screen save and restore pair.
 */
#include "CODE.H"

/* shared_include_start: ../../../../shared/c/SCREEN-SAVE.C -- generated */
/* SCREEN-SAVE.C -- c_screen_save, a whole-screen copy that copies nothing.
 */

/* Meant to copy the whole screen from page 0 to page 2, but the height of 0
 * copies nothing.
 */
void c_screen_save(void)
{
    drv_jump_gfx_copy_rect((struct RASTPORT *) 0, 0, 0, 2, 0, (struct RASTPORT *) 0, 0x13f, 0xc7);
}
/* shared_include_end: ../../../../shared/c/SCREEN-SAVE.C */

/* shared_include_start: ../../../../shared/c/SCREEN-RESTORE.C -- generated */
/* SCREEN-RESTORE.C -- c_screen_restore, a screen copy that copies nothing.
 */

void c_screen_restore(void)
{
    drv_jump_gfx_copy_rect((struct RASTPORT *) 2, 0, 0, 0, 0, (struct RASTPORT *) 0, 0x13f, 0xc7);
}
/* shared_include_end: ../../../../shared/c/SCREEN-RESTORE.C */
