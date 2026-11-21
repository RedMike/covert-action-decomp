/* HELP-CLEAR.C -- putting the animation area back on screen.
 */
#include "CHASE.H"
#include "HELPCLR.H"

/* shared_include_start: ../../../../shared/c/PAN-RESTORE.C -- generated */
/* PAN-RESTORE.C -- c_pan_restore, copying the animation area between pages.
 */

/* Copy the screen's animation area onto the map page, and a building
 * animation's corner once more. Neither parameter is read.
 */
INT c_pan_restore(INT x, INT y)
{
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, shm_pan_width, 0xc8, shd_map_page, 0, 0);
    if (shm_pan_building != 0) {
        drv_jump_gfx_copy_rect(shd_screen, 0, 0, 0xa0, 0x1e, shd_map_page, 0, 0);
        shm_pan_building = 0;
    }
}
/* shared_include_end: ../../../../shared/c/PAN-RESTORE.C */
