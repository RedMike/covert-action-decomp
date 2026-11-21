/* SAVE-FILE.C -- writing and reading a save, one section at a time.
 */
#include "BUG.H"
#include "BOARD.H"
#include "MENU.H"

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
