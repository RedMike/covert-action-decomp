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
