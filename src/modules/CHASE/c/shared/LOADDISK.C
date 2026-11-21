/* LOADDISK.C -- asking for the right floppy to be put in the drive.
 */
#include "CHASE.H"
#include "MENU1.H"
#include "LOADDISK.H"

/* shared_include_start: ../../../../shared/c/WANT-DISK.C -- generated */
/* WANT-DISK.C -- c_want_disk, making sure a game disk is in the drive.
 *
 * `ready` is four bytes wide but only its low word is used.
 */

/* Make sure disk `disk` is in the drive and say whether it is. With `ready` 0,
 * only look; otherwise prompt until it is in, and with -1 prompt once even if
 * it is.
 */
INT c_want_disk(INT disk, LONG ready)
{
    if ((INT) ready == 0) {
        if (drv_real_FUN_1000_0002(shd_disk_names[disk - 1], 0) != -1)
            return 1;
        c_want_disk(shd_pan_disk, LONG_LIT(1));
        return 0;
    }
    while (drv_real_FUN_1000_0002(shd_disk_names[disk - 1], 0) == -1
           || *(INT *) &ready == -1) {
        drv_jump_gfx_show_page(shd_screen->page);
        if (*(INT *) &ready == -1)
            *(INT *) &ready = 1;
        drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xc8, 0);
        shd_disk_letter[0] = disk + '@';
        strcpy(shm_scratch, shd_str_please_insert_disk);
        strcat(shm_scratch, shd_disk_letter);
        if (disk >= 3) {
            strcat(shm_scratch, shd_str_if_3_5_insert);
            shd_disk_letter[0] -= 2;
            strcat(shm_scratch, shd_disk_letter);
            strcat(shm_scratch, shd_str_close_paren);
        }
        strcat(shm_scratch, shd_str_press_return_continue);
        shm_menu_no_pick = 1;
        c_menu_run((rt_addr) shm_scratch, 100, 0x50);
        drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xc8, 0);
    }
    return (INT) ready;
}
/* shared_include_end: ../../../../shared/c/WANT-DISK.C */

