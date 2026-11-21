/* SETUP.C -- taking the settings and save sections out of the shared block.
 */
#include "CHASE.H"
#include "SETUP1.H"
#include "SECTIONR.H"

/* Copy the chase's settings out of the shared block into the module's own
 * globals, then read the six save sections that follow them into their arrays.
 */
void c_setup(INT unused)
{
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
    asm_graphics_word = COMM()->graphics_letter;
    shm_log_count = COMM()->log_count;
    shm_double_agent_cities = COMM()->double_agent_cities;
    shm_orgs_known = COMM()->orgs_known;
    shm_skills = COMM()->skills;
    shm_save_offset = 0x400;
    c_get_section(asm_arena, (char *) &shm_campaign, 0x28e);
    c_get_section(asm_arena, (char *) shm_crime_roles,
                    0x30 * shm_crime_role_count);
    c_get_section(asm_arena, (char *) shm_role_scan_states,
                    6 * shm_crime_role_count);
    c_get_section(asm_arena, (char *) shm_crime_events,
                    0x2c * shm_crime_event_count);
    c_get_section(asm_arena, (char *) shm_cities, 0x220);
    c_get_section(asm_arena, shm_orgs, 0x240);
}
