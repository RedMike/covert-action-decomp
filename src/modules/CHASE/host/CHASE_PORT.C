#ifdef PORT_MODERN
#include "CHASE_PORT.H"

unsigned char dat_str_chase_pic[10] = "chase.pic";
unsigned char dat_str_street_pic[11] = "street.pic";
unsigned char dat_str_we_ve_totally_lost[76] =
    "'We've totally lost\ntrack of this guy.\nLet's go back to\nwhere we start"
    "ed.'\n";
unsigned char dat_str_he[3] = "He";
unsigned char dat_str_she[4] = "She";
unsigned char dat_str_turns_corner_dashes[57] =
    " turns the corner\nand dashes into a\ncrowded restaurant.\n";
unsigned char dat_str_we_ll_have_less[49] =
    "'We'll have to\nbe less obvious\nnext time, Max.'\n";
unsigned char dat_str_dash_into_building[60] =
    "You dash into the\nbuilding seconds ahead\nof your pursuers!\n";
unsigned char dat_str_he_2[3] = "He";
unsigned char dat_str_she_2[4] = "She";
unsigned char dat_str_pulls_over_walks_into[67] =
    " pulls over\nand walks into\na building as you\nquietly park nearby.\n";
unsigned char dat_str_pursuers_run_off_road[37] =
    "Your pursuers run\nyou off the road!\n";
unsigned char dat_str_run[9] = "You run ";
unsigned char dat_str_his[4] = "his";
unsigned char dat_str_her[4] = "her";
unsigned char dat_str_car_off_road_make[42] =
    " car\noff the road and\nmake the arrest!\n";
struct RASTPORT dat_map_page_port = { 1, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *shd_map_page = (struct RASTPORT *) &dat_map_page_port;
struct COLOUR_MAP shd_colours_screen = {
    0x00,
    0x00,
    0x01,
    0x00,
    0x02,
    0x00,
    0x00,
    0x02,
    0x00,
    0x01,
    0x02,
    0x03,
    0x02,
    0x01,
    0x01,
    0x03,
};
struct COLOUR_MAP shd_colours_screen_2 = {
    0x00,
    0x00,
    0x11,
    0x11,
    0x22,
    0x00,
    0x00,
    0x22,
    0x00,
    0x22,
    0x33,
    0x33,
    0x22,
    0x11,
    0x22,
    0x33,
};
struct COLOUR_MAP dat_colours_car_pick = {
    0x00,
    0x00,
    0x11,
    0x11,
    0x22,
    0x00,
    0x00,
    0x33,
    0x22,
    0x22,
    0x11,
    0x33,
    0x22,
    0x33,
    0x22,
    0x33,
};
UNSIGNED_INT asm_chase_kind;
UNSIGNED_INT asm_game_speed = 0x0001;
UNSIGNED_INT shd_pan_disk = 0x0002;
struct PALETTE dat_palette_chase = {
    0x0e,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
INT dat_windscreen_car_rects[16][4] = {
    { 0x0005, 0x0054, 0x0035, 0x0074 },
    { 0x0008, 0x0075, 0x0032, 0x0091 },
    { 0x000a, 0x0092, 0x0030, 0x00ab },
    { 0x000c, 0x00ac, 0x002e, 0x00c2 },
    { 0x0047, 0x0054, 0x0066, 0x0068 },
    { 0x004a, 0x006a, 0x0064, 0x007b },
    { 0x004b, 0x007e, 0x0063, 0x008e },
    { 0x004d, 0x008f, 0x0061, 0x009c },
    { 0x004e, 0x009d, 0x0060, 0x00a8 },
    { 0x0050, 0x00a9, 0x005e, 0x00b2 },
    { 0x0051, 0x00b3, 0x005e, 0x00bb },
    { 0x0051, 0x00bc, 0x005c, 0x00c3 },
    { 0x003c, 0x00a9, 0x0044, 0x00af },
    { 0x003d, 0x00b0, 0x0044, 0x00b4 },
    { 0x003e, 0x00b5, 0x0043, 0x00b8 },
    { 0x003f, 0x00b9, 0x0042, 0x00bb },
};
UNSIGNED_INT asm_page_3;
struct PALETTE dat_palette_default = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
INT dat_side_dx[4] = {
    0x0000, 0x0001, 0x0000, -1,
};
INT dat_side_dy[4] = {
    -1, 0x0000, 0x0001, 0x0000,
};
UNSIGNED_INT dat_gear_steps[5] = {
    0x0000, 0x0001, 0x0009, 0x0015, 0x001b,
};
struct STREET_SPAN dat_street_x[4] = {
    { 2, 7 },
    { 8, 8 },
    { 2, 7 },
    { 0, 0 },
};
struct STREET_SPAN dat_street_y[4] = {
    { 0, 0 },
    { 2, 7 },
    { 8, 8 },
    { 2, 7 },
};
INT asm_active_car = 0x0001;
struct RASTPORT dat_tile_page_port = { 3, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *dat_tile_page = (struct RASTPORT *) &dat_tile_page_port;
struct RASTPORT dat_dash_page_port = { 2, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *dat_dash_page = (struct RASTPORT *) &dat_dash_page_port;
struct RASTPORT dat_windscreen_port = { 0, 201, 1, 318, 75, 0, 15, 4, 0 };
struct RASTPORT *dat_windscreen = (struct RASTPORT *) &dat_windscreen_port;
unsigned char dat_str_cars_pic[9] = "cars.pic";
unsigned char dat_str_tracking[11] = "(Tracking)";
unsigned char dat_str_empty;
unsigned char dat_str_mph[5] = " mph";
unsigned char dat_str_excellent[10] = "Excellent";
unsigned char dat_str_fair[5] = "Fair";
unsigned char dat_str_low[4] = "Low";
unsigned char dat_str_moderate[9] = "Moderate";
unsigned char dat_str_high[5] = "High";
unsigned char dat_str_extreme[8] = "Extreme";
unsigned char asm_car_stats[23] = {
    0x43, 0x61, 0x72, 0x20, 0x23, 0x00, 0x00, 0x07, 0x00, 0x08, 0x00, 0x0a,
    0x00, 0x02, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x0c, 0x00, 0x04, 0x00,
};
unsigned char dat_str_sure_want_quit_no[42] =
    "Are you sure\nyou want to Quit?\n No\n Yes\n";
UNSIGNED_INT dat_car_offset[16] = {
    0x0002, 0x001c, 0x001e, 0x0002, 0x0002, 0x001c,
    0x0000, 0x0002, 0x0000, 0x0002, 0x0002, 0x001c,
    0x001e, 0x0002, 0x0002, 0x001c,
};
unsigned char dat_str_empty_2[2];
UNSIGNED_INT dat_windscreen_shown = 0xffff;
UNSIGNED_INT dat_windscreen_car_shown = 0xffff;
unsigned char dat_clock_text[8] = "0:00:00";
unsigned char dat_str_loc[4] = "Loc";
unsigned char shd_str_one_moment_please[21] = "One moment please...";
unsigned char shd_str_sure_want_quit_no_2[41] =
    "Are you sure\nyou want to Quit?\n No\n Yes\n";
UNSIGNED_INT shd_city_on_screen = 0xffff;
INT shd_drive = -1;
UNSIGNED_INT shm_pan_width = 0x0140;
struct PALETTE shd_palette_menu = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
struct PALETTE shd_palette_face = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x06,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
unsigned char shd_str_ok[3] = "OK";
unsigned char shd_str_briefing_pan[13] = "briefing.pan";
unsigned char shd_str_bld[4] = "bld";
UNSIGNED_INT shm_pan_building;
unsigned char shd_str_animation_pan[14] = "animation.pan";
UNSIGNED_INT shd_joystick_dirs[9] = {
    0x0008, 0x0007, 0x0006, 0x0001, 0xffff, 0x0005,
    0x0002, 0x0003, 0x0004,
};
unsigned char dat_str_final_exe[10] = "final.exe";
unsigned char dat_str_game_exe[9] = "game.exe";
unsigned char dat_str_tac_exe[8] = "tac.exe";
unsigned char dat_str_hq_pan[7] = "hq.pan";
unsigned char shd_str_please_insert_disk[20] = "Please insert Disk ";
unsigned char shd_str_if_3_5_insert[23] = "\n(if 3.5\" insert Disk ";
unsigned char shd_str_close_paren[2] = ")";
unsigned char shd_str_press_return_continue[41] =
    ".\n \n     Press Return\n     to continue.\n";
drv_addr shd_disk_names[4] = {
    (drv_addr) dat_str_final_exe, (drv_addr) dat_str_game_exe,
    (drv_addr) dat_str_tac_exe, (drv_addr) dat_str_hq_pan,
};
unsigned char shd_disk_letter[2] = "A";
struct RASTPORT dat_screen_port = { 0, 0, 0, 319, 199, 1, 15, 4, 0 };
struct RASTPORT *shd_screen = (struct RASTPORT *) &dat_screen_port;
rt_addr shd_archive_buffer_end = (rt_addr) &shm_menu_face_x;
INT shd_archive_fd = -1;
unsigned char FAR *shm_save_block;
UNSIGNED_INT shm_save_offset;
UNSIGNED_INT asm_arena;
UNSIGNED_INT asm_view_set;
UNSIGNED_INT asm_view_at;
UNSIGNED_INT asm_view_col;
UNSIGNED_INT asm_view_row;
INT asm_windscreen_near;
UNSIGNED_INT asm_windscreen_range;
UNSIGNED_INT asm_windscreen_car_x;
UNSIGNED_INT asm_windscreen_car_y;
INT asm_compass_dx;
INT asm_compass_dy;
UNSIGNED_INT asm_dash_scratch;
unsigned char asm_number_digits_2[16];
struct SEQ_BLOCK shm_active_pan;
INT shm_menu_line_start[32];
UNSIGNED_INT shm_menu_colour_plain;
UNSIGNED_INT shm_menu_colour_item;
INT shm_menu_lines;
UNSIGNED_INT shm_menu_colour_pick;
UNSIGNED_INT shm_source_fd;
UNSIGNED_INT shm_source_dst;
UNSIGNED_INT shm_source_src;
UNSIGNED_INT shm_sprite_width;
INT shm_sprite_height;
UNSIGNED_INT shm_palette_count;
UNSIGNED_INT asm_org_alert_level;
struct JOYSTICK shm_joystick;
UNSIGNED_INT asm_sight_dir;
unsigned char shm_scratch[512];
UNSIGNED_INT asm_night;
INT shm_difficulty;
UNSIGNED_INT asm_goal_spot;
UNSIGNED_INT shm_clock_minutes;
struct CAR asm_cars[3];
UNSIGNED_INT asm_tick;
struct CAMPAIGN shm_campaign;
UNSIGNED_INT shm_seed;
INT shm_options;
INT shm_cga;
struct CITY shm_cities[16];
UNSIGNED_INT shm_menu_tick;
UNSIGNED_INT asm_stuck_count;
INT shm_suspect_count;
unsigned char asm_cell_map[2368];
INT asm_windscreen_frame;
INT shm_menu_face;
UNSIGNED_INT asm_head_on;
union REGS shm_mouse_regs;
UNSIGNED_INT asm_outcome;
INT asm_frame_tick;
struct CRIME_EVENT shm_crime_events[64];
UNSIGNED_INT shm_log_count;
INT shm_menu_first_line;
UNSIGNED_INT shm_case_seed;
INT shm_building_count;
INT shm_case_tick;
UNSIGNED_INT asm_graphics_word;
rt_addr shm_source_at;
INT shm_case_city_1;
UNSIGNED_INT shm_case_city_2;
UNSIGNED_INT shm_pan_playing;
UNSIGNED_INT shm_menu_no_pick;
INT shm_menu_items;
UNSIGNED_INT asm_engine_note;
UNSIGNED_INT asm_fresh_board;
INT shm_crime_event_count;
UNSIGNED_INT asm_DAT_1663_5c00;
UNSIGNED_INT asm_start_spot;
UNSIGNED_INT shm_menu_relayout;
INT shm_mission;
UNSIGNED_INT shm_menu_colour_bar;
INT shm_case_org_1;
INT shm_menu_text_width;
UNSIGNED_INT shm_case_org_2;
UNSIGNED_INT asm_windscreen_car_sprites[16];
union REGS shm_regs;
UNSIGNED_INT asm_countdown;
UNSIGNED_INT shm_double_agent_cities;
INT shm_crime_role_count;
UNSIGNED_INT shm_menu_marked;
struct CRIME_ROLE shm_crime_roles[32];
UNSIGNED_INT asm_DAT_1663_626a;
unsigned char asm_number_digits[10];
rt_addr shm_refill;
unsigned char shm_archive_buffer[512];
UNSIGNED_INT shm_menu_face_x;
UNSIGNED_INT shm_menu_draw_only;
UNSIGNED_INT shm_skills;
UNSIGNED_INT shm_mouse_buttons;
UNSIGNED_INT shm_mouse_x;
UNSIGNED_INT shm_mouse_y;
UNSIGNED_INT shm_mouse_count;
UNSIGNED_INT shm_menu_face_y;
struct ORG_STATE shm_orgs[16];
INT shm_finished;
unsigned char shm_menu_shortcut[32];
UNSIGNED_INT shm_menu_pick;
UNSIGNED_INT shm_menu_right;
struct ROLE_SCAN_STATE shm_role_scan_states[32];
unsigned char shm_graphics_letter;
UNSIGNED_INT shm_menu_bottom;
UNSIGNED_INT asm_spot_x[16];
UNSIGNED_INT asm_spot_y[16];
UNSIGNED_INT asm_suspect_alert;
INT shm_case_city;
INT asm_suspicion_scale;
UNSIGNED_INT shm_orgs_known;
UNSIGNED_INT shm_jailbreak_suspect;
UNSIGNED_INT shm_case_spare_2;
unsigned char shm_anim_row_2[384];
UNSIGNED_INT asm_goal_x;
UNSIGNED_INT asm_goal_y;
UNSIGNED_INT shm_case_org;
#endif
