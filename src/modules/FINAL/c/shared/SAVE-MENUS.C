/* SAVE-MENUS.C -- the Load Game and Save Game menus, and their four slots.
 *
 * A slot is a file called `a:cv<n>.sve`, one name written over in place for
 * each. Both menus ask which drive, then describe all four slots and let the
 * player pick one.
 */
#include "FINAL.H"
#include "LOADDISK.H"
#include "CMISEND.H"
#include "SAVELOAD.H"

/* shared_include_start: ../../../../shared/c/LOAD-MENU.C -- generated */
/* LOAD-MENU.C -- c_load_menu, the Load Game menu.
 */

/* Ask for the drive and one of the four slots and load it; answer the slot, or
 * -1 if nothing was loaded. `spare` is unused.
 */
INT c_load_menu(void)
{
    UNSIGNED_INT slot;
    INT drive;
    INT spare;

    shm_save_loading = 1;
    drive = c_ask_drive();
    if (drive != -1) {
        strcpy(shm_scratch, shd_str_select_load_file);
        shm_slots_filled = 0;
        for (slot = 0; slot < 4; slot++) {
            shd_save_name[4] = slot + '0';
            if (c_save_slot(shd_save_name, LONG_LIT(1)) != 0)
                shm_slots_filled |= 1 << slot;
        }
        shm_slot_pick = c_ask_menu((rt_addr) shm_scratch,
                                            4, 0x10);
        if (shm_slot_pick >= 0)
            shm_slot_pick /= 3;
        if ((shm_slots_filled & 1 << shm_slot_pick) == 0)
            shm_slot_pick = -1;
        if (shm_slot_pick != -1) {
            shd_save_name[4] = shm_slot_pick + '0';
            if (c_save_slot(shd_save_name, LONG_LIT(0)) == 0)
                shm_slot_pick = -1;
        }
        c_want_disk(1, LONG_LIT(1));
        return shm_slot_pick;
    }
    return -1;
}
/* shared_include_end: ../../../../shared/c/LOAD-MENU.C */

/* shared_include_start: ../../../../shared/c/SAVE-SLOT.C -- generated */
/* SAVE-SLOT.C -- c_save_slot, describing or loading a save slot.
 */

/* With `probe`, append slot `name`'s description to the scratch buffer as
 * three menu lines and answer 0 for an empty slot; without, load the slot and
 * answer 1.
 */
INT c_save_slot(char *name, LONG probe)
{
    strcpy(name + 6, shd_str_sve);
    if ((INT) probe != 0) {
        shm_slot_fd = open((rt_addr) name, 0x8000);
        if (shm_slot_fd != -1) {
            lseek(shm_slot_fd, LONG_LIT(0x3f0), 0);
            read(shm_slot_fd, (char *) &shm_probed_campaign, 0x28e);
            lseek(shm_slot_fd, LONG_LIT(0x2a), 0);
            read(shm_slot_fd, &shm_slot_word, 2);
            strcat(shm_scratch, shd_str_max);
            strcat(shm_scratch, shm_probed_campaign.player_name);
            strcat(shm_scratch, shd_str_remington_00);
            strcat(shm_scratch,
                       itoa(shm_probed_campaign.best_rank, shm_slot_digits, 10));
            strcat(shm_scratch, shd_str_rank_2);
            strcat(shm_scratch, shm_probed_campaign.city_name);
            strcat(shm_scratch, shd_str_colon);
            strcat(shm_scratch,
                       (char *) shd_month_names
                                        [shm_probed_campaign.cases % 12]);
            strcat(shm_scratch, shd_str_space_slot);
            strcat(shm_scratch,
                       itoa(shm_probed_campaign.saved_minutes / 0x5a0 + 1,
                                shm_slot_digits, 10));
            strcat(shm_scratch, shd_str_comma_2);
            strcat(shm_scratch,
                       itoa(shm_probed_campaign.cases / 12 + 0x7c6,
                                shm_slot_digits, 10));
            switch (shm_slot_word) {
            case 0:
                strcat(shm_scratch, shd_str_local);
                break;
            case 1:
                strcat(shm_scratch, shd_str_national);
                break;
            case 2:
                strcat(shm_scratch, shd_str_regional);
                break;
            case 3:
                strcat(shm_scratch, shd_str_global);
                break;
            }
            strcat(shm_scratch, shd_str_stop_blank);
        } else {
            strcat(shm_scratch, shd_str_empty_slot);
        }
        close(shm_slot_fd);
        if (shm_slot_fd != -1)
            return 1;
        return 0;
    }
    c_save_get(name);
    shm_options &= ~OPT_COPYRIGHT_SKIP;
    return 1;
}
/* shared_include_end: ../../../../shared/c/SAVE-SLOT.C */

/* shared_include_start: ../../../../shared/c/SAVE-MENU.C -- generated */
/* SAVE-MENU.C -- c_save_menu, the Save Game menu.
 */

/* Pick a drive and one of the four slots and save into it, with critical
 * errors failing the call; then say whether it saved.
 */
void c_save_menu(void)
{
    INT slot;
    INT drive;
    INT choice;

    shm_save_loading = shm_save_errno = 0;
    drive = c_ask_drive();
    if (drive != -1) {
        strcpy(shm_scratch, shd_str_select_save_file);
        for (slot = 0; slot < 4; slot++) {
            shd_save_name[4] = slot + '0';
            c_save_slot(shd_save_name, LONG_LIT(1));
        }
        shm_menu_pick = shm_slot_pick;
        choice = c_ask_menu((rt_addr) shm_scratch, 4, 0x10);
        if (choice >= 0)
            choice = choice / 3;
        if (choice != -1) {
            shm_hook_critical_error();
            shm_slot_pick = choice;
            shd_save_name[4] = choice + '0';
            if (c_save_write(shd_save_name) != 0) {
                strcpy(shm_scratch,
                           (LONG) shm_save_errno == 0
                               ? shd_str_game_has_been_saved
                               : shd_str_game_not_saved);
                if (shm_save_errno == 0xd)
                    strcat(shm_scratch, shd_str_write_access_denied);
                if (shm_save_errno == 0x1c)
                    strcat(shm_scratch, shd_str_disk_full);
                strcat(shm_scratch, shd_str_press_key_continue);
                c_ask_menu((rt_addr) shm_scratch, 4, 0x80);
            }
            shm_unhook_critical_error();
        }
    }
    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xc8, 5);
    c_want_disk(shd_pan_disk, LONG_LIT(1));
}
/* shared_include_end: ../../../../shared/c/SAVE-MENU.C */

/* shared_include_start: ../../../../shared/c/SAVE-WRITE.C -- generated */
/* SAVE-WRITE.C -- c_save_write, saving into a slot file.
 */

/* Create the slot file `name`, show a progress note and save into it. Answers
 * 0 if the file cannot be created; later failures show in shm_save_errno.
 */
INT c_save_write(char *name)
{
    INT unused;
    INT unused2;
    INT unused3;
    INT unused4;

    strcpy(name + 6, shd_str_sve_2);
    shm_slot_fd = open((rt_addr) name, 0x8301, 0x80);
    if (shm_slot_fd == -1) {
        strcpy(shm_scratch, shd_str_file_error_write);
        strcat(shm_scratch, name);
        strcat(shm_scratch, shd_str_newline_save);
        c_ask_menu((rt_addr) shm_scratch, 100, 0x50);
        return 0;
    }
    close(shm_slot_fd);
    shm_menu_draw_only = 1;
    strcpy(shm_scratch, name);
    strcat(shm_scratch, shd_str_save_progress);
    c_ask_menu((rt_addr) shm_scratch, 4, 100);
    c_save_put(name);
    return 1;
}
/* shared_include_end: ../../../../shared/c/SAVE-WRITE.C */

/* shared_include_start: ../../../../shared/c/WRITE-CHECKED.C -- generated */
/* WRITE-CHECKED.C -- c_write_checked, a write that keeps its error.
 */

/* Write `many` bytes from `at` to `fd`, keeping errno in shm_save_errno if the
 * write fails.
 */
void c_write_checked(INT fd, char *at, INT many)
{
    if ((INT) write(fd, at, many) == -1)
        shm_save_errno = errno;
}
/* shared_include_end: ../../../../shared/c/WRITE-CHECKED.C */
