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
