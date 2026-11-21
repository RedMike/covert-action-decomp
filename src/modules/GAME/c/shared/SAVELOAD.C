/* SAVELOAD.C -- the save and load menus, and the save file itself.
 */
#include "GAME.H"
#include "KEYCODES.H"
#include "SAVELOAD.H"
#include "LOADDISK.H"
#include "CMP_STRT.H"
#include "MISC1.H"

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

/* shared_include_start: ../../../../shared/c/SAVE-PUT.C -- generated */
/* SAVE-PUT.C -- c_save_put, saving the game.
 */

/* Save the game: the header and twelve sections into the shared block or, for
 * any name but "env.sve", into a new file. `unused` is not read.
 */
void c_save_put(char *name)
{
    INT unused;
    char block[1024];
    char FAR *far_at;

    shm_campaign.saved_minutes = shm_clock_minutes;
    COMM()->case_city = shm_case_city;
    COMM()->case_org = shm_case_org;
    COMM()->options = shm_options;
    COMM()->mission = shm_mission;
    COMM()->case_org_1 = shm_case_org_1;
    COMM()->case_org_2 = shm_case_org_2;
    COMM()->case_city_1 = shm_case_city_1;
    COMM()->case_city_2 = shm_case_city_2;
    COMM()->clock_minutes = shm_clock_minutes;
    COMM()->suspect_count = shm_suspect_count;
    COMM()->building_count = shm_building_count;
    COMM()->case_tick = shm_case_tick;
    COMM()->carried_38 = shm_case_spare_2;
    COMM()->difficulty = shm_difficulty;
    COMM()->case_seed = shm_case_seed;
    COMM()->crime_role_count = shm_crime_role_count;
    COMM()->crime_event_count = shm_crime_event_count;
    COMM()->prisoner = shm_jailbreak_suspect;
    COMM()->graphics_letter = (char) shm_graphics_letter;
    COMM()->log_count = shm_log_count;
    COMM()->double_agent_cities = shm_double_agent_cities;
    COMM()->orgs_known = shm_orgs_known;
    COMM()->skills = shm_skills;
    COMM()->carried_52 = shm_global_alert_level;
    if (strcmp(name, shd_str_env_sve_put) != 0) {
        far_at = block;
        shm_save_fd = open((rt_addr) name,
                                               0x8301, 0x80);
        shm_save_block = COMM_BYTES + 0x10;
        COPY_FAR(shm_save_block, far_at, 0x3f0);
        write(shm_save_fd, block, 0x3f0);
        strcpy(shm_campaign.city_name, shm_cities[shm_case_city].name);
        shm_save_offset = 0;
    } else {
        shm_save_offset = 0x400;
    }
    c_put_section(shm_save_fd, (char *) &shm_campaign, 0x28e);
    c_put_section(shm_save_fd, (char *) shm_crime_roles,
                    shm_crime_role_count * 0x30);
    c_put_section(shm_save_fd, (char *) shm_role_scan_states,
                    shm_crime_role_count * 6);
    c_put_section(shm_save_fd, (char *) shm_crime_events,
                    shm_crime_event_count * 0x2c);
    c_put_section(shm_save_fd, (char *) shm_cities, 0x220);
    c_put_section(shm_save_fd, (char *) shm_orgs, 0x240);
    c_put_section(shm_save_fd, (char *) shm_suspects, 0x400);
    c_put_section(shm_save_fd, (char *) shm_buildings, 0xc00);
    c_put_section(shm_save_fd, (char *) shm_clues_shown, 0x3c0);
    c_put_section(shm_save_fd, (char *) shm_log, 0x700);
    c_put_section(shm_save_fd, (char *) shm_crime_block, 0x48);
    c_put_section(shm_save_fd, (char *) &shm_activity, 0x40);
    if (shm_save_offset == 0)
        close(shm_save_fd);
}
/* shared_include_end: ../../../../shared/c/SAVE-PUT.C */

/* shared_include_start: ../../../../shared/c/PUT-SECTION.C -- generated */
/* PUT-SECTION.C -- c_put_section, writing one section of a save.
 */

/* Write `many` bytes from `at` to `fd` or, when shm_save_offset is set, into
 * the shared block at that offset.
 */
void c_put_section(INT fd, char *at, INT many)
{
    char FAR *far_at;

    if (shm_save_offset != 0) {
        far_at = at;
        shm_save_block = COMM_BYTES + shm_save_offset;
        COPY_FAR(far_at, shm_save_block, many);
        shm_save_offset += many;
    } else {
        write(fd, at, many);
    }
}
/* shared_include_end: ../../../../shared/c/PUT-SECTION.C */

/* shared_include_start: ../../../../shared/c/GET-SECTION.C -- generated */
/* GET-SECTION.C -- c_get_section, reading one section of a saved game.
 */

/* Read `many` bytes of a saved game into `at`: from the shared block when
 * shm_save_offset is set, else from `fd`.
 */
void c_get_section(INT fd, char *at, INT many)
{
    char FAR *far_at;

    if (shm_save_offset != 0) {
        far_at = at;
        shm_save_block = COMM_BYTES + shm_save_offset;
        COPY_FAR(shm_save_block, far_at, many);
        shm_save_offset += many;
    } else {
        read(fd, at, many);
    }
}
/* shared_include_end: ../../../../shared/c/GET-SECTION.C */

/* shared_include_start: ../../../../shared/c/SAVE-GET.C -- generated */
/* SAVE-GET.C -- c_save_get, loading a saved game.
 */

/* Load a save from the file `name`, or for "env.sve" from the shared block
 * alone: the header, then twelve sections. Answers 0 if the file cannot be
 * opened.
 */
INT c_save_get(char *name)
{
    INT i;
    char block[1024];
    INT copy[3];
    char FAR *far_at;

    if (strcmp(name, shd_str_env_sve) != 0) {
        far_at = block;
        shm_save_fd = open((rt_addr) name, 0x8000);
        if (shm_save_fd == -1) {
            strcpy(shm_scratch, shd_str_file_error);
            strcat(shm_scratch, name);
            strcat(shm_scratch, shd_str_newline_12);
            c_ask_menu((rt_addr) shm_scratch, 100, 0x50);
            return 0;
        }
        for (i = 0; i < 3; i++)
            copy[i] = COMM()->driver_segment[i];
        shm_save_block = COMM_BYTES + 0x10;
        read(shm_save_fd, block, 0x3f0);
        COPY_FAR(far_at, shm_save_block, 0x3f0);
        for (i = 0; i < 3; i++)
            COMM()->driver_segment[i] = copy[i];
        shm_save_offset = 0;
    } else {
        shm_save_offset = 0x400;
    }
    shm_case_city = COMM()->case_city;
    shm_case_org = COMM()->case_org;
    shm_options = COMM()->options;
    shm_mission = COMM()->mission;
    shm_case_org_1 = COMM()->case_org_1;
    shm_case_org_2 = COMM()->case_org_2;
    shm_case_city_1 = COMM()->case_city_1;
    shm_case_city_2 = COMM()->case_city_2;
    shm_clock_minutes = COMM()->clock_minutes;
    shm_suspect_count = COMM()->suspect_count;
    shm_building_count = COMM()->building_count;
    shm_case_tick = COMM()->case_tick;
    shm_case_spare_2 = COMM()->carried_38;
    shm_difficulty = COMM()->difficulty;
    shm_case_seed = COMM()->case_seed;
    shm_crime_role_count = COMM()->crime_role_count;
    shm_crime_event_count = COMM()->crime_event_count;
    shm_jailbreak_suspect = COMM()->prisoner;
    if (shm_save_offset != 0)
        shm_graphics_letter = COMM_LETTER_BYTE;
    shm_cga = shm_graphics_letter == 'C';
    shm_log_count = COMM()->log_count;
    shm_double_agent_cities = COMM()->double_agent_cities;
    shm_orgs_known = COMM()->orgs_known;
    shm_skills = COMM()->skills;
    shm_global_alert_level = COMM()->carried_52;
    c_get_section(shm_save_fd, (char *) &shm_campaign, 0x28e);
    c_get_section(shm_save_fd, (char *) shm_crime_roles,
                    shm_crime_role_count * 0x30);
    c_get_section(shm_save_fd, (char *) shm_role_scan_states,
                    shm_crime_role_count * 6);
    c_get_section(shm_save_fd, (char *) shm_crime_events,
                    shm_crime_event_count * 0x2c);
    c_get_section(shm_save_fd, (char *) shm_cities, 0x220);
    c_get_section(shm_save_fd, (char *) shm_orgs, 0x240);
    c_get_section(shm_save_fd, (char *) shm_suspects, 0x400);
    c_get_section(shm_save_fd, (char *) shm_buildings, 0xc00);
    c_get_section(shm_save_fd, (char *) shm_clues_shown, 0x3c0);
    c_get_section(shm_save_fd, (char *) shm_log, 0x700);
    c_get_section(shm_save_fd, (char *) shm_crime_block, 0x48);
    c_get_section(shm_save_fd, (char *) &shm_activity, 0x40);
    if (shm_save_offset == 0)
        close(shm_save_fd);
}
/* shared_include_end: ../../../../shared/c/SAVE-GET.C */
