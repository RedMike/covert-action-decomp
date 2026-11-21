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
