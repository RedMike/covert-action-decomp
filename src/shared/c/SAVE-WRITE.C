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
