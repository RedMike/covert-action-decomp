/* PAN-ANIMATION.C -- arming the animation behind a panel, and restoring it.
 */
#include "FINAL.H"
#include "MENUS.H"
#include "LOADDISK.H"

/* shared_include_start: ../../../../shared/c/PAN-ARM.C -- generated */
/* PAN-ARM.C -- c_pan_arm, arming an animation to play behind a menu.
 */

/* Arm the animation `name` at origin (`y`, `z`); answer whether it was armed.
 * It is refused when animations are off or its disk is not in. A name starting
 * "bld" marks a building animation.
 */
INT c_pan_arm(char *name, INT y, INT z)
{
    char saved;

    if ((shm_options & OPT_ANIMATION) == 0
        || (strcmp(name, shd_str_briefing_pan) != 0
            && c_want_disk(4, 0) == 0)) {
        drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xc8, 5);
        shm_active_pan.page_a = y;
        shd_screen->bg_pen = 5;
        return 0;
    }
    strcpy(shd_str_animation_pan, name);
    saved = name[3];
    name[3] = 0;
    if (strcmp(name, shd_str_bld) == 0)
        shm_pan_building = 1;
    name[3] = saved;
    shm_pan_playing = 1;
    shm_active_pan.name = shd_str_animation_pan;
    shm_active_pan.duration = -1;
    shm_active_pan.page_a = y;
    shm_active_pan.page_b = z;
    shm_active_pan.rate = -1;
    return 1;
}
/* shared_include_end: ../../../../shared/c/PAN-ARM.C */

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
