/* SAVE-DRIVE.C -- asking which drive holds the save files, and checking it.
 *
 * A to D pick the drive and Escape cancels, the current drive being offered
 * first; the answer becomes the drive letter of the save file's name.
 */
#include "FINAL.H"
#include "KEYCODES.H"
#include "MENUS.H"
#include "CMISEND.H"
#include "SAVELOAD.H"

/* shared_include_start: ../../../../shared/c/ASK-DRIVE.C -- generated */
/* ASK-DRIVE.C -- c_ask_drive, asking which drive holds the saved games.
 */

/* Ask which drive holds the saves and check it has a disk; answer the drive, 0
 * for A, or -1. `spare` and `spare2` are unused.
 */
INT c_ask_drive(void)
{
    INT key;
    INT drive;
    INT spare;
    INT spare2;

    _dos_getdrive((rt_addr) &drive);
    drive--;
    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xc8, 0);
    do {
        strcpy(shm_scratch,
                   shm_save_loading ? shd_str_which_drive_contains
                                     : shd_str_which_drive_contains_2);
        ((char *) shm_scratch)[strlen(shm_scratch) - 1] =
            drive + 'A';
        strcat(shm_scratch, shd_str_press_drive_letter);
        strcat(shm_scratch, shd_str_press_escape_cancel);
        shm_menu_draw_only = 1;
        c_ask_menu((rt_addr) shm_scratch, 0x50, 0x50);
        key = c_menu_key();
        if (key == 'A' || key == 'a')
            drive = 0;
        if (key == 'B' || key == 'b')
            drive = 1;
        if (key == 'C' || key == 'c')
            drive = 2;
        if (key == 'D' || key == 'd')
            drive = 3;
        if (key == KEY_ESC)
            drive = -1;
    } while (key != KEY_ENTER && key != KEY_ESC);
    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xc8, 0);
    if (drive != -1 && c_drive_ready(drive) == 0) {
        strcpy(shm_scratch, shd_str_no_disk_drive);
        ((char *) shm_scratch)[strlen(shm_scratch) - 3] =
            drive + 'A';
        c_ask_menu((rt_addr) shm_scratch, 100, 0x50);
        return -1;
    }
    shd_save_name[0] = drive + 'a';
    return drive;
}
/* shared_include_end: ../../../../shared/c/ASK-DRIVE.C */

/* shared_include_start: ../../../../shared/c/DRIVE-READY.C -- generated */
/* DRIVE-READY.C -- c_drive_ready, whether a drive has a disk in it.
 */

/* Whether drive `drive` holds a readable disk, by a BIOS verify tried three
 * times; any drive past B is taken as ready.
 */
INT c_drive_ready(INT drive)
{
    INT tries;
    INT err;
    INT disk[7];

    if (drive > 1)
        return 1;
    disk[0] = drive;
    disk[1] = 0;
    disk[2] = 0;
    disk[3] = 2;
    disk[4] = 1;
    for (tries = 0; tries < 3; tries++) {
        err = _bios_disk(4, (rt_addr) disk);
        if ((err & 0xff00) == 0)
            return 1;
        _bios_disk(0, 0);
    }
    return 0;
}
/* shared_include_end: ../../../../shared/c/DRIVE-READY.C */
