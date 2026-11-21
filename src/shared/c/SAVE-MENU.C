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
