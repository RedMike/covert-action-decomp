/* CHASE_PORT.H -- the data group, as the portable build reads it.
 *
 * CHASE.H includes it under PORT_MODERN; the DOS build never stages it.
 */
#ifndef CHASE_PORT_H
#define CHASE_PORT_H

#include "PORTING.H"
#include "COMM.H"
#include "STRUCTS.H"

#ifndef PORT_MODERN
extern unsigned char run_banner_pad[8];
extern unsigned char run_banner[58];
extern UNSIGNED_INT drv_DAT_1663_0042;
extern UNSIGNED_INT drv_DAT_1663_0044;
extern unsigned char asm_block_0046[38];
extern unsigned char dat_str_env_sve[8];
#endif
extern unsigned char dat_str_chase_pic[10];
extern unsigned char dat_str_street_pic[11];
extern unsigned char dat_str_we_ve_totally_lost[76];
extern unsigned char dat_str_he[3];
extern unsigned char dat_str_she[4];
extern unsigned char dat_str_turns_corner_dashes[57];
extern unsigned char dat_str_we_ll_have_less[49];
extern unsigned char dat_str_dash_into_building[60];
extern unsigned char dat_str_he_2[3];
extern unsigned char dat_str_she_2[4];
extern unsigned char dat_str_pulls_over_walks_into[67];
extern unsigned char dat_str_pursuers_run_off_road[37];
extern unsigned char dat_str_run[9];
extern unsigned char dat_str_his[4];
extern unsigned char dat_str_her[4];
extern unsigned char dat_str_car_off_road_make[42];
extern struct RASTPORT dat_map_page_port;
extern struct RASTPORT *shd_map_page;
#ifndef PORT_MODERN
extern unsigned char asm_block_1614[32];
#endif
extern struct COLOUR_MAP shd_colours_screen;
extern struct COLOUR_MAP shd_colours_screen_2;
extern struct COLOUR_MAP dat_colours_car_pick;
/* Which of the three situations this is: 2 is being ambushed rather than
tailing, which also reverses what a lit board sprite means. */
extern UNSIGNED_INT asm_chase_kind;
extern UNSIGNED_INT asm_game_speed;
extern UNSIGNED_INT shd_pan_disk;
extern struct PALETTE dat_palette_chase;
/* The rectangle each windscreen-car sprite is grabbed from, four words an
entry: two corners. */
extern INT dat_windscreen_car_rects[16][4];
extern UNSIGNED_INT asm_page_3;
/* dat_palette_chase with the background register cleared, for
c_turning_animation and the closing menu. */
extern struct PALETTE dat_palette_default;
/* How far a step moves across, one entry per facing. */
extern INT dat_side_dx[4];
/* How far a step moves down, one entry per facing. */
extern INT dat_side_dy[4];
/* One word per gear: a car moves a step on the frames whose bit, frame count
mod 6, is set, so gear 0 never moves and gear 4 moves on four frames in six. */
extern UNSIGNED_INT dat_gear_steps[5];
/* Per facing, the x offsets within a block of the two ends of the street
on that side. */
extern struct STREET_SPAN dat_street_x[4];
/* Per facing, the y offsets within a block of the two ends of the street
on that side. */
extern struct STREET_SPAN dat_street_y[4];
/* The car the player drives: 1 or 2, swapped by Space, or 0 when ambushed. */
extern INT asm_active_car;
extern struct RASTPORT dat_tile_page_port;
extern struct RASTPORT *dat_tile_page;
extern struct RASTPORT dat_dash_page_port;
extern struct RASTPORT *dat_dash_page;
extern struct RASTPORT dat_windscreen_port;
/* The picture over the windscreen, (201, 1) to (318, 75), which the
suspect's car is drawn into so that it is clipped to the windscreen. */
extern struct RASTPORT *dat_windscreen;
extern unsigned char dat_str_cars_pic[9];
extern unsigned char dat_str_tracking[11];
extern unsigned char dat_str_empty;
extern unsigned char dat_str_mph[5];
extern unsigned char dat_str_excellent[10];
extern unsigned char dat_str_fair[5];
extern unsigned char dat_str_low[4];
extern unsigned char dat_str_moderate[9];
extern unsigned char dat_str_high[5];
extern unsigned char dat_str_extreme[8];
/* "Car #", the label written on a chosen car's strip, then the two fill
colours for each of the four car colours. */
extern unsigned char asm_car_stats[23];
extern unsigned char dat_str_sure_want_quit_no[42];
extern UNSIGNED_INT dat_car_offset[16];
extern unsigned char dat_str_empty_2[2];
/* The windscreen frame the dashboard last drew, so an unchanged one is not redrawn. */
extern UNSIGNED_INT dat_windscreen_shown;
/* Where down the windscreen the suspect's car was last drawn, -1 for none. */
extern UNSIGNED_INT dat_windscreen_car_shown;
/* The clock string, '0:00:00': one hour digit, then minutes and seconds
as two digits each. */
extern unsigned char dat_clock_text[8];
extern unsigned char dat_str_loc[4];
extern unsigned char shd_str_one_moment_please[21];
extern unsigned char shd_str_sure_want_quit_no_2[41];
#ifndef PORT_MODERN
extern unsigned char dat_str_pani[5];
extern unsigned char asm_block_1911;
#endif
/* Which city's picture is on screen, so an unchanged one is not reloaded;
-1 for none. */
extern UNSIGNED_INT shd_city_on_screen;
extern INT shd_drive;
extern UNSIGNED_INT shm_pan_width;
#ifndef PORT_MODERN
extern unsigned char asm_block_1918[2];
#endif
extern struct PALETTE shd_palette_menu;
extern struct PALETTE shd_palette_face;
extern unsigned char shd_str_ok[3];
extern unsigned char shd_str_briefing_pan[13];
extern unsigned char shd_str_bld[4];
#ifndef PORT_MODERN
extern unsigned char asm_block_1951;
#endif
extern UNSIGNED_INT shm_pan_building;
extern unsigned char shd_str_animation_pan[14];
extern UNSIGNED_INT shd_joystick_dirs[9];
extern unsigned char dat_str_final_exe[10];
extern unsigned char dat_str_game_exe[9];
extern unsigned char dat_str_tac_exe[8];
extern unsigned char dat_str_hq_pan[7];
extern unsigned char shd_str_please_insert_disk[20];
extern unsigned char shd_str_if_3_5_insert[23];
extern unsigned char shd_str_close_paren[2];
extern unsigned char shd_str_press_return_continue[41];
extern drv_addr shd_disk_names[4];
extern unsigned char shd_disk_letter[2];
extern struct RASTPORT dat_screen_port;
extern struct RASTPORT *shd_screen;
#ifndef PORT_MODERN
extern unsigned char drv_DAT_1663_1a0a;
extern unsigned char drv_DAT_1663_1a0b;
extern UNSIGNED_INT drv_DAT_1663_1a0c;
extern UNSIGNED_INT drv_DAT_1663_1a0e;
extern UNSIGNED_INT drv_DAT_1663_1a10;
extern UNSIGNED_INT drv_DAT_1663_1a12;
extern UNSIGNED_INT drv_DAT_1663_1a14;
extern UNSIGNED_INT drv_DAT_1663_1a16;
extern UNSIGNED_INT drv_DAT_1663_1a18;
extern UNSIGNED_INT drv_DAT_1663_1a1a;
extern unsigned char dat_message_pool[27];
extern unsigned char dat_str_ms_dos_lied_us[54];
extern unsigned char dat_str_filename_not_found[19];
extern unsigned char dat_str_not_enough_memory_load[31];
extern unsigned char dat_str_overlay_load_failed[36];
extern unsigned char dat_str_overlay_has_overrun[37];
extern unsigned char dat_str_unable_shrink_overlay[43];
extern unsigned char dat_str_error_releasing_overlay[31];
#endif
extern rt_addr shd_archive_buffer_end;
extern INT shd_archive_fd;
#ifndef PORT_MODERN
extern unsigned char asm_block_1b36;
extern UNSIGNED_INT drv_DAT_1663_1b37;
extern UNSIGNED_INT drv_DAT_1663_1b39;
extern UNSIGNED_INT drv_DAT_1663_1b3b;
extern UNSIGNED_INT drv_DAT_1663_1b3d;
extern UNSIGNED_INT drv_DAT_1663_1b3f;
extern unsigned char asm_block_1b41[436];
extern UNSIGNED_INT drv_DAT_1663_1cf5;
extern UNSIGNED_INT drv_DAT_1663_1cf7;
extern unsigned char asm_block_1cf9[438];
extern UNSIGNED_INT drv_DAT_1663_1eaf;
extern UNSIGNED_INT drv_DAT_1663_1eb1;
extern UNSIGNED_INT drv_DAT_1663_1eb3;
extern UNSIGNED_INT drv_DAT_1663_1eb5;
extern UNSIGNED_INT drv_DAT_1663_1eb7;
extern UNSIGNED_INT drv_DAT_1663_1eb9;
extern unsigned char asm_block_1ebb;
extern unsigned char drv_DAT_1663_1ebc;
extern UNSIGNED_INT drv_DAT_1663_1ebd;
extern UNSIGNED_INT drv_DAT_1663_1ebf;
extern UNSIGNED_INT drv_DAT_1663_1ec1;
extern UNSIGNED_INT drv_DAT_1663_1ec3;
extern UNSIGNED_INT drv_DAT_1663_1ec5;
extern UNSIGNED_INT drv_DAT_1663_1ec7;
extern unsigned char asm_block_1ec9;
extern UNSIGNED_INT drv_DAT_1663_1eca;
extern UNSIGNED_INT drv_DAT_1663_1ecc;
extern UNSIGNED_INT drv_DAT_1663_1ece;
extern UNSIGNED_INT drv_DAT_1663_1ed0;
extern UNSIGNED_INT drv_DAT_1663_1ed2;
extern UNSIGNED_INT drv_DAT_1663_1ed4;
extern UNSIGNED_INT drv_DAT_1663_1ed6;
extern UNSIGNED_INT drv_DAT_1663_1ed8;
extern UNSIGNED_INT drv_DAT_1663_1eda;
extern UNSIGNED_INT drv_DAT_1663_1edc;
extern UNSIGNED_INT drv_DAT_1663_1ede;
extern UNSIGNED_INT drv_DAT_1663_1ee0;
extern unsigned char asm_block_1eea[80];
extern UNSIGNED_INT run_crt0dat_1f49;
extern unsigned char asm_block_1f4b[8];
extern unsigned char asm_block_1f55[4];
extern unsigned char asm_block_1f5d;
extern unsigned char asm_block_1f5f;
extern unsigned char run_crt0dat_1f63;
extern unsigned char asm_block_1f64;
extern unsigned char run_crt0dat_1f65;
extern unsigned char run_crt0dat_1f66;
extern unsigned char run_crt0dat_1f67;
extern unsigned char run_crt0dat_1f68;
extern unsigned char asm_block_1f69[13];
extern unsigned char run_crt0dat_1f80;
extern unsigned char run_crt0dat_1f81;
extern unsigned char asm_block_1f82[8];
extern UNSIGNED_INT STKHQQ;
extern UNSIGNED_INT run_stdargv_1f8e;
extern unsigned char asm_block_1f90[340];
extern unsigned char dat_str_pst[4];
extern unsigned char run_timeset_20e8;
extern unsigned char asm_block_20e9[3];
extern UNSIGNED_INT run_timeset_20ee;
extern unsigned char asm_block_20f4;
extern unsigned char run_day_names[23];
extern unsigned char run_month_names[37];
extern unsigned char asm_block_2131;
extern UNSIGNED_INT run_rand_2132;
extern UNSIGNED_INT run_rand_2134;
extern unsigned char run_err_error_0[8];
extern unsigned char asm_block_213e;
extern unsigned char run_err_no_such_file_directory[29];
extern unsigned char asm_block_215c;
extern unsigned char run_err_arg_list_too_long[18];
extern unsigned char run_err_exec_format_error[18];
extern unsigned char run_err_bad_file_number[16];
extern unsigned char asm_block_2191[2];
extern unsigned char run_err_not_enough_core[16];
extern unsigned char run_err_permission_denied[21];
extern unsigned char run_err_file_exists[12];
extern unsigned char run_err_cross_device_link[20];
extern unsigned char asm_block_21d8;
extern unsigned char run_err_invalid_argument[17];
extern unsigned char asm_block_21ea;
extern unsigned char run_err_too_many_open_files[21];
extern unsigned char asm_block_2200[2];
extern unsigned char run_err_no_space_left_device[26];
extern unsigned char asm_block_221c[2];
extern unsigned char run_err_math_argument[14];
extern unsigned char run_err_result_too_large[17];
extern unsigned char asm_block_223d;
extern unsigned char run_err_resource_deadlock_would[30];
extern unsigned char run_err_unknown_error[14];
extern unsigned char dat_str_6_y_z_o[53];
extern unsigned char asm_block_229f[21];
extern UNSIGNED_INT run_syserr_22b4;
extern unsigned char asm_block_22b8[2];
extern UNSIGNED_INT run_crt0dat_22bc;
extern UNSIGNED_LONG run_crt0dat_22be;
extern UNSIGNED_LONG run_crt0dat_22c2;
extern unsigned char asm_block_22c6[2];
extern unsigned char run_nmsg_marker[8];
extern UNSIGNED_INT run_crt0msg_22d0;
extern unsigned char run_crt0msg_22d2[26];
extern unsigned char asm_block_22ec[2];
extern unsigned char run_msg_r6003[31];
extern unsigned char asm_block_230d[2];
extern unsigned char run_msg_r6009[44];
extern unsigned char asm_block_233b[7];
extern unsigned char run_msg_runtime_error[16];
extern unsigned char asm_block_2352[2];
extern unsigned char run_msg_r6002[37];
extern unsigned char asm_block_2379[2];
extern unsigned char run_msg_r6001[35];
extern unsigned char asm_block_239e[4];
extern unsigned char asm_block_23a2[16];
#endif
/* The far address the section reader copies from, when the section comes out of
the shared block. */
extern unsigned char FAR *shm_save_block;
/* How far into the shared block the next section starts, and zero when the
sections are being read from a file. */
extern UNSIGNED_INT shm_save_offset;
/* The file handle passed with each save section; the sections come out
of the shared block, so it goes unread. */
extern UNSIGNED_INT asm_arena;
/* Where the map window has scrolled to across the map, and zero until it
has been placed once. */
extern UNSIGNED_INT asm_view_set;
/* Where the map window has scrolled to down the map, which chases the
active car four pixels a frame. */
extern UNSIGNED_INT asm_view_at;
/* The cell the window's corner sits in, across. */
extern UNSIGNED_INT asm_view_col;
/* The cell the window's corner sits in, down. */
extern UNSIGNED_INT asm_view_row;
/* 3fh less the range, clamped: how near the active car is, which places
the suspect's car on the windscreen. */
extern INT asm_windscreen_near;
/* How far the active car is from car 0 along a clear line, half as far
again, and zero when it is out of sight. */
extern UNSIGNED_INT asm_windscreen_range;
/* Where across the windscreen the suspect's car is centred, moved when the
active car and car 0 face different ways. */
extern UNSIGNED_INT asm_windscreen_car_x;
/* How far down the windscreen the suspect's car is drawn, lower the nearer it
is; worked out from asm_windscreen_near. */
extern UNSIGNED_INT asm_windscreen_car_y;
/* Which way car 0 lies from the active car, across. */
extern INT asm_compass_dx;
/* Which way car 0 lies from the active car, down. */
extern INT asm_compass_dy;
/* Scratch the dashboard uses twice: first which of the sixteen windscreen-car
sprites the sighting range picks, then the width of the suspicion bar. */
extern UNSIGNED_INT asm_dash_scratch;
extern unsigned char asm_number_digits_2[16];
/* The screen's background animation, a struct SEQ_BLOCK: armed when a screen
 * is entered, started each time a menu opens and stepped while it waits. */
extern struct SEQ_BLOCK shm_active_pan;
#ifndef PORT_MODERN
extern unsigned char asm_block_23ee[16];
#endif
extern INT shm_menu_line_start[32];
extern UNSIGNED_INT shm_menu_colour_plain;
extern UNSIGNED_INT shm_menu_colour_item;
extern INT shm_menu_lines;
extern UNSIGNED_INT shm_menu_colour_pick;
#ifndef PORT_MODERN
extern unsigned char asm_block_2446[16];
#endif
extern UNSIGNED_INT shm_source_fd;
extern UNSIGNED_INT shm_source_dst;
extern UNSIGNED_INT shm_source_src;
#ifndef PORT_MODERN
extern UNSIGNED_INT drv_DAT_1663_245c;
extern unsigned char drv_DAT_1663_245e;
extern UNSIGNED_INT drv_DAT_1663_245f;
extern unsigned char drv_DAT_1663_2461;
extern unsigned char asm_block_2462[6138];
#endif
extern UNSIGNED_INT shm_sprite_width;
extern INT shm_sprite_height;
extern UNSIGNED_INT shm_palette_count;
#ifndef PORT_MODERN
extern UNSIGNED_INT drv_DAT_1663_3c62;
extern UNSIGNED_INT drv_DAT_1663_3c64;
extern unsigned char drv_DAT_1663_3c66;
extern unsigned char drv_DAT_1663_3c67;
extern unsigned char drv_DAT_1663_3c68;
extern unsigned char drv_DAT_1663_3c69;
extern UNSIGNED_INT drv_DAT_1663_3c6a;
extern UNSIGNED_INT drv_DAT_1663_3c6c;
extern UNSIGNED_INT drv_DAT_1663_3c6e;
extern unsigned char drv_DAT_1663_3c70;
extern unsigned char drv_DAT_1663_3c71;
extern UNSIGNED_INT drv_DAT_1663_3c72;
extern unsigned char drv_DAT_1663_3c74;
extern unsigned char asm_block_3c75[513];
extern UNSIGNED_INT run_tzset_3e76;
extern unsigned char asm_block_3e78[8];
#endif
/* How alert the organisation is, out of the shared block's
org_alert_level. */
extern UNSIGNED_INT asm_org_alert_level;
extern struct JOYSTICK shm_joystick;
/* Non-zero after a sighting unless the two cars share a spot; the windscreen
shows a car only while it is set. */
extern UNSIGNED_INT asm_sight_dir;
/* The scratch text buffer every screen builds its lines in, 200h bytes. */
extern unsigned char shm_scratch[512];
/* Set when the chase starts between eight in the evening and eight in the
morning, which changes the board's colours. */
extern UNSIGNED_INT asm_night;
/* The chase's difficulty, 0 to 3. */
extern INT shm_difficulty;
#ifndef PORT_MODERN
extern unsigned char asm_block_428a[2];
#endif
/* Which of the sixteen destinations the chase is heading for. */
extern UNSIGNED_INT asm_goal_spot;
/* What time of day the chase began, in minutes. */
extern UNSIGNED_INT shm_clock_minutes;
/* The three car records, 20 bytes each: car 0 leads and cars 1 and 2 follow
it. The keys drive car 0 when ambushed and cars 1 and 2 when tailing. */
extern struct CAR asm_cars[3];
/* A counter bumped at each use, whose low bit alternates the way a pursuer
turns off car 0's line. */
extern UNSIGNED_INT asm_tick;
extern struct CAMPAIGN shm_campaign;
extern UNSIGNED_INT shm_seed;
extern INT shm_options;
/* Set when the graphics letter is 'C', so the CGA paths are taken. */
extern INT shm_cga;
/* The sixteen city records, 34 bytes each; the chase's city's
known-organisation bitmap says which destinations are on the board. */
extern struct CITY shm_cities[16];
extern UNSIGNED_INT shm_menu_tick;
/* How many times a follower has seen car 0 waiting at its destination;
past sixteen the chase ends. */
extern UNSIGNED_INT asm_stuck_count;
/* How many suspect records the case has, copied from the shared block. */
extern INT shm_suspect_count;
/* The board, one byte a block over a 24-by-24 grid: the low nibble which
of its four sides have a street, and the high nibble its tile. */
extern unsigned char asm_cell_map[2368];
/* Which of the eight pictures of the road ahead is on screen, laid out in dat_dash_page
as two columns of four. */
extern INT asm_windscreen_frame;
extern INT shm_menu_face;
/* Set for a tick in which another car meets car 0 head-on and close, which
ends an ambush and, when tailing, lets the keys run car 0 off the road. */
extern UNSIGNED_INT asm_head_on;
/* The register block the INT 33h calls read and write. */
extern union REGS shm_mouse_regs;
/* How the chase ended, which the closing message is assembled from. */
extern UNSIGNED_INT asm_outcome;
/* The frame counter, read as the chase's seconds by the clock; its low
bits make things blink. */
extern INT asm_frame_tick;
/* The crime event list, 64 records of 2ch bytes from CRIMEn.DTA, each one step
 * of the crime; shm_crime_event_count says how many the case fills. */
extern struct CRIME_EVENT shm_crime_events[64];
extern UNSIGNED_INT shm_log_count;
extern INT shm_menu_first_line;
extern UNSIGNED_INT shm_case_seed;
extern INT shm_building_count;
/* The case's clock in half-days, one tick each time the clock passes noon or
midnight. A crime event that comes due is stamped with it in
CRIME_EVENT.happen_tick. */
extern INT shm_case_tick;
/* The graphics driver's letter again, copied from the shared block as a
word. */
extern UNSIGNED_INT asm_graphics_word;
extern rt_addr shm_source_at;
extern INT shm_case_city_1;
extern UNSIGNED_INT shm_case_city_2;
extern UNSIGNED_INT shm_pan_playing;
extern UNSIGNED_INT shm_menu_no_pick;
#ifndef PORT_MODERN
extern unsigned char asm_block_5bf6[2];
#endif
extern INT shm_menu_items;
/* The gear the sound driver is given with every effect. */
extern UNSIGNED_INT asm_engine_note;
/* When set, the board is seeded from the city and its destinations are the
organisations known there; when clear, it is random and they are numbered. */
extern UNSIGNED_INT asm_fresh_board;
/* How many of the crime event list's 64 records the case fills. */
extern INT shm_crime_event_count;
/* Part of the seed the board is laid out from; what it holds is unknown. */
extern UNSIGNED_INT asm_DAT_1663_5c00;
/* Which destination car 0 starts at. */
extern UNSIGNED_INT asm_start_spot;
extern UNSIGNED_INT shm_menu_relayout;
extern INT shm_mission;
extern UNSIGNED_INT shm_menu_colour_bar;
extern INT shm_case_org_1;
extern INT shm_menu_text_width;
extern UNSIGNED_INT shm_case_org_2;
#ifndef PORT_MODERN
extern unsigned char asm_block_5c10[2];
#endif
/* The suspect's car seen from behind through the windscreen, sixteen
sizes from nearest to farthest, grabbed once at startup. */
extern UNSIGNED_INT asm_windscreen_car_sprites[16];
#ifndef PORT_MODERN
extern unsigned char asm_block_5c32[34];
#endif
/* The register block the INT 10h calls read and write. */
extern union REGS shm_regs;
/* Frames left before the chase ends once car 0 has reached its
destination, and zero until then. */
extern UNSIGNED_INT asm_countdown;
extern UNSIGNED_INT shm_double_agent_cities;
/* How many crime roles the case has: the crime file's participant
count plus four red herrings a difficulty level. */
extern INT shm_crime_role_count;
extern UNSIGNED_INT shm_menu_marked;
/* The case's crime roles, 32 records of 30h bytes: the participant records
of CRIME*.DTA, read in whole, then the red herrings the difficulty appends.
One save section. */
extern struct CRIME_ROLE shm_crime_roles[32];
/* What it holds is unknown; while it is non-zero, a car's mark follows its
place every tick as though it were in sight. */
extern UNSIGNED_INT asm_DAT_1663_626a;
/* The buffer itoa writes a number's digits into. */
extern unsigned char asm_number_digits[10];
extern rt_addr shm_refill;
extern unsigned char shm_archive_buffer[512];
extern UNSIGNED_INT shm_menu_face_x;
extern UNSIGNED_INT shm_menu_draw_only;
/* The packed skill word out of the shared block. */
extern UNSIGNED_INT shm_skills;
extern UNSIGNED_INT shm_mouse_buttons;
extern UNSIGNED_INT shm_mouse_x;
extern UNSIGNED_INT shm_mouse_y;
extern UNSIGNED_INT shm_mouse_count;
extern UNSIGNED_INT shm_menu_face_y;
extern struct ORG_STATE shm_orgs[16];
#ifndef PORT_MODERN
extern unsigned char asm_block_66ca[4];
#endif
/* Non-zero once the chase is over. */
extern INT shm_finished;
extern unsigned char shm_menu_shortcut[32];
extern UNSIGNED_INT shm_menu_pick;
#ifndef PORT_MODERN
extern unsigned char asm_block_66f2[74];
#endif
extern UNSIGNED_INT shm_menu_right;
/* The case's role scan states, one per crime role: when clue visibility may
 * start building against it, and how much has built. One save section, six
 * bytes a role. */
extern struct ROLE_SCAN_STATE shm_role_scan_states[32];
/* The graphics driver's letter, read from the shared block as a byte. */
extern unsigned char shm_graphics_letter;
#ifndef PORT_MODERN
extern unsigned char asm_block_67ff;
#endif
extern UNSIGNED_INT shm_menu_bottom;
/* The sixteen destinations' positions across the board. */
extern UNSIGNED_INT asm_spot_x[16];
/* The sixteen destinations' positions down the board. */
extern UNSIGNED_INT asm_spot_y[16];
/* The suspect's suspicion in whole units of asm_suspicion_scale, handed
back as a percentage, the alert GAME hands c_raise_alert. */
extern UNSIGNED_INT asm_suspect_alert;
/* The city the chase is in: it picks the city record in shm_cities
and seeds the board generator. */
extern INT shm_case_city;
/* The unit CAR.suspicion is measured in: 1000 over the difficulty plus
three, cut further the more alert the organisation is. */
extern INT asm_suspicion_scale;
extern UNSIGNED_INT shm_orgs_known;
extern UNSIGNED_INT shm_jailbreak_suspect;
extern UNSIGNED_INT shm_case_spare_2;
extern unsigned char shm_anim_row_2[384];
/* Where that destination is, across. */
extern UNSIGNED_INT asm_goal_x;
/* Where that destination is, down. */
extern UNSIGNED_INT asm_goal_y;
/* The destination: the organisation the module was entered for, then the
one reached. The start is drawn against it so the two differ. */
extern UNSIGNED_INT shm_case_org;
#ifndef PORT_MODERN
extern unsigned char asm_block_69d4[2076];
#endif

#endif /* CHASE_PORT_H */
