/* TAC.H -- what the C side can reach on the assembly side. */
#ifndef TAC_H
#define TAC_H

/* The driver entries this module calls, declared once for every module. */
#include "DRIVERS.H"

/* The dispatch segment's own routines, declared once for every module. */
#include "DRVREAL.H"

/* The MSC 5.1 run-time this module calls, declared once for the tree. */
#include "RUNTIME.H"

/* A type this module reaches, declared once for the modules sharing it. */
#include "COMM.H"

/* The structures this module reaches, defined once for the whole tree. */
#include "STRUCTS.H"

/* data defined in assembly, exported to C */
#ifdef PORT_MODERN
/* The data group, datum by datum, which the portable build alone reads. */
#include "TAC_PORT.H"
#else
extern unsigned char dat_str_env_sve[8];
extern unsigned char dat_str_camera_pic[11];
extern unsigned char dat_str_guys3_pic[10];
extern unsigned char dat_str_guys2_pic[10];
extern unsigned char dat_str_equip1_pic[11];
extern unsigned char dat_str_equip1m_pic[12];
extern unsigned char dat_str_env_sve_2[8];
/* The ten kinds of room, Office to Storage Room, one record each, which
asm_rooms[].kind indexes: the name the panel shows and what a bug or a photo
there scores. */
extern struct ROOM_KIND dat_room_kinds[10];
/* What a floor grid cell can hold, sixty-two records from Wall to Local Agent;
a cell holds the index in its low six bits. Furnishing names record 60 after
the crime and moves the pictures of 60 and 61 across the sheet. */
extern struct FLOOR_OBJECT dat_floor_objects[62];
/* The across step for each of the eight directions, indexed 1 to 8; entry 0 is
no move. */
extern INT dat_move_dx[9];
/* The down step for each of the eight directions, indexed 1 to 8; entry 0 is
no move. */
extern INT dat_move_dy[9];
/* The one-cell across step for each of the eight directions, indexed 1 to 8;
entry 0 is no move. */
extern INT dat_step_dx[9];
/* The one-cell down step for each of the eight directions, indexed 1 to 8;
entry 0 is no move. */
extern INT dat_step_dy[9];
/* The across step to each of the four sides, indexed 0 to 3, with entry 4
repeating entry 0. */
extern INT dat_side_dx[5];
/* The down step to each of the four sides, indexed 0 to 3, with entry 4
repeating entry 0. */
extern INT dat_side_dy[5];
extern struct RASTPORT *asm_status_page;
extern struct RASTPORT *dat_cast_frames;
extern struct RASTPORT *asm_saved_page;
/* The case's 64 suspect records, 16 bytes each, saved as one section. */
extern struct SUSPECT shm_suspects[64];
/* The buildings the player knows of, 100h records of 12 bytes, one per
 * organisation and city, shm_building_count of them in use. Saved as one
 * section. */
extern struct BUILDING shm_buildings[256];
/* The clues the player has turned up, 50h records of 12 bytes filled in
order, the first whose role is -1 being the next free one. Saved as one
section. */
extern struct SHOWN_CLUE shm_clues_shown[80];
extern UNSIGNED_INT shm_jailbreak_suspect;
extern struct RASTPORT *shd_map_page;
extern struct COLOUR_MAP shd_colours_screen;
extern struct COLOUR_MAP shd_colours_screen_2;
extern struct COLOUR_MAP shd_colours_face;
extern struct COLOUR_MAP dat_colours_badge;
extern struct COLOUR_MAP dat_colours_tactical;
extern INT asm_game_speed;
extern UNSIGNED_INT dat_room_mask;
extern UNSIGNED_INT shd_pan_disk;
extern struct PALETTE shd_palette_records[5];
extern UNSIGNED_INT asm_page_3;
extern unsigned char dat_str_empty_15;
extern unsigned char dat_str_which_door[16];
extern unsigned char dat_str_door_5[7];
extern unsigned char dat_str_newline_13[4];
extern INT asm_facing;
extern INT asm_facing_goal;
extern unsigned char dat_str_paused[8];
extern unsigned char dat_str_sure_want_quit_no[42];
/* The keypad scan code each joystick direction stands for, indexed 1 to 8;
entry 0 is no direction. */
extern INT dat_joystick_keys[9];
/* Set in a frame in which a shot goes off, so that its flash is drawn and
then cleared. */
extern UNSIGNED_INT asm_shot_fired;
/* The colour the hit-chance meter is filled with for each chance, 0 to 4. */
extern char dat_meter_colours[5];
extern unsigned char dat_str_set_trap_cancel_remote[47];
extern unsigned char dat_str_empty_16;
extern unsigned char dat_str_do_want_arrest[23];
extern unsigned char dat_str_question[12];
extern unsigned char dat_str_bug[9];
extern unsigned char dat_str_photo[11];
extern unsigned char dat_str_closed[9];
extern unsigned char dat_str_nothing_photograph[23];
extern unsigned char dat_str_already_photographed[22];
extern unsigned char dat_str_photographed[15];
extern unsigned char dat_str_open[6];
extern unsigned char dat_str_first[8];
extern unsigned char dat_str_out_film[13];
extern unsigned char dat_str_empty_17;
extern unsigned char dat_str_bugged[9];
extern unsigned char dat_str_room_already_bugged[21];
extern unsigned char dat_str_nothing_bug[16];
extern unsigned char dat_str_gas[4];
extern unsigned char dat_str_disguise[9];
extern unsigned char dat_str_overcome_by_gas_pass[39];
extern unsigned char dat_str_slump_ground_overcome[51];
extern unsigned char dat_str_prisoner_released_while[57];
extern unsigned char dat_str_have_eliminated_all[42];
extern unsigned char dat_str_quickly_slip_out[39];
extern unsigned char dat_str_cia_agent[18];
extern unsigned char dat_str_double_agent[22];
extern unsigned char dat_str_now[9];
extern unsigned char dat_str_bang_2[3];
extern unsigned char dat_str_find[10];
extern unsigned char dat_str_bang_3[3];
extern unsigned char dat_str_empty_18[1];
extern unsigned char dat_str_has_been_identified_as[52];
extern unsigned char dat_str_find_incriminating[49];
extern unsigned char dat_str_into_double_agent[23];
/* The eight kit items a tip can tell the player to find. */
extern INT dat_tip_items[8];
extern unsigned char dat_str_mode_read_text_2[3];
extern unsigned char dat_str_text_dta[9];
extern unsigned char dat_fmt_word[5];
extern unsigned char dat_fmt_word_2[5];
extern unsigned char dat_password_hint_initial[11];
extern unsigned char dat_str_enter_password[16];
extern unsigned char dat_str_empty_19[1];
extern unsigned char dat_str_access_confirmed[17];
extern unsigned char dat_str_access_denied[14];
extern unsigned char dat_str_search[12];
extern unsigned char dat_str_has[6];
extern unsigned char dat_str_a[2];
extern unsigned char dat_str_no_operatives[14];
extern unsigned char dat_str_newline_in[5];
extern unsigned char dat_str_newline_14[2];
extern unsigned char dat_str_has_no_operatives[19];
extern unsigned char dat_str_newline_in_2[5];
extern unsigned char dat_str_newline_15[2];
extern unsigned char dat_str_now_2[9];
extern unsigned char dat_str_bang[3];
extern unsigned char dat_str_empty_20[1];
extern unsigned char dat_str_no_data[9];
/* The floor object a cell shows for each combination of its four wall bits. */
extern char dat_wall_tiles[16];
extern unsigned char dat_str_street[7];
extern unsigned char dat_str_spritesf_pic[13];
extern unsigned char dat_str_sprites_pic[12];
/* The facing a guard takes for a step, indexed 3 * the sign of its across move
+ the sign of its down move + 4; entry 4, no move at all, is 0. */
extern INT dat_step_facing[9];
/* The room number that is no room, -1. */
extern UNSIGNED_INT dat_no_room;
extern unsigned char dat_str_equip2_pic[11];
/* The sixteen kit item names, Pistol to Floor Plan; three entries are empty
strings. */
extern unsigned char *addr_kit_names[16];
/* The twelve kit screen boxes' moves, one record per box, box 0 zero: the box
each of up, down, left and right takes the highlight to. */
extern struct KIT_BOX dat_kit_boxes[12];
/* Where the kit panel draws, thirteen points: 0 to 7 the carried items, 8 to
10 the three grenade rows, 11 the rounds row and 12 the clips row. */
extern struct POINT dat_kit_points[13];
/* The fifteen rectangles of equip2.pic the kit sprites are grabbed from. */
extern struct RECT dat_kit_sprite_rects[15];
/* The twelve kit slot rectangles on the equipment screen, one per slot, slot 0
empty. */
extern struct RECT dat_kit_slot_rects[12];
extern unsigned char shd_str_coded_message[23];
extern unsigned char shd_str_meeting_notes[23];
extern unsigned char shd_str_new_information[24];
extern unsigned char shd_str_additional_information[28];
extern unsigned char shd_str_space_after_name[2];
extern unsigned char shd_str_dots[6];
extern unsigned char shd_str_on[4];
extern unsigned char shd_str_space_after_month[2];
extern unsigned char shd_str_of_the[8];
extern unsigned char shd_str_in[4];
extern unsigned char shd_str_newline[2];
extern unsigned char shd_str_empty_watch[1];
extern unsigned char shd_str_space_face[2];
extern unsigned char shd_str_in_2[5];
extern unsigned char *shd_clue_phrases[40];
extern char shd_scan_counts[32];
extern unsigned char *shd_month_names[12];
extern unsigned char shd_str_empty_identified[1];
extern unsigned char shd_str_has_been_identified_as[52];
extern unsigned char shd_str_empty_positively;
extern unsigned char shd_str_has_been_positively[36];
extern unsigned char shd_str_newline_2[2];
extern unsigned char shd_str_we_have_acquired[34];
extern unsigned char shd_str_stop[3];
extern unsigned char shd_str_empty_spotted[1];
extern unsigned char shd_str_has_been_spotted[22];
extern unsigned char shd_str_newline_3[2];
extern unsigned char shd_str_empty_org[1];
extern unsigned char shd_str_has_been_identified_as_org[41];
extern unsigned char shd_str_newline_4[2];
extern unsigned char shd_str_we_have_obtained[52];
extern unsigned char shd_str_newline_5[2];
extern unsigned char shd_str_we_have_determined_rank[32];
extern unsigned char shd_str_newline_6[2];
extern unsigned char shd_str_we_found_recruiting[39];
extern unsigned char shd_str_newline_7[2];
extern unsigned char shd_str_we_found_recruiting_2[39];
extern unsigned char shd_str_newline_8[2];
extern rt_addr shd_clue_kinds[80];
extern unsigned char shd_str_clue[5];
extern unsigned char shd_str_source_2[10];
extern unsigned char shd_str_slash_source[2];
extern unsigned char shd_str_newline_9[2];
extern unsigned char shd_str_method_stop[11];
extern unsigned char shd_str_related_2[16];
extern unsigned char shd_str_newline_10[2];
extern unsigned char shd_str_none[8];
extern unsigned char *shd_clue_source[7];
extern unsigned char shd_key_clue[7];
extern unsigned char shd_str_clues_txt[11];
extern rt_addr shd_clue_keys[5];
extern unsigned char shd_str_period[2];
extern unsigned char shd_str_face[11];
extern unsigned char shd_str_valkerie[9];
extern unsigned char shd_str_thunderbolt[12];
extern unsigned char shd_str_00[3];
extern unsigned char shd_str_000[4];
extern unsigned char shd_key_clue_2[5];
extern unsigned char shd_key_clue_3[7];
extern unsigned char shd_key_clue_4[7];
extern unsigned char shd_str_clues_txt_2[10];
extern unsigned char shd_str_empty_dossier[1];
extern unsigned char shd_str_name[7];
extern unsigned char shd_str_rank[7];
extern unsigned char shd_str_org[7];
extern unsigned char shd_str_city[8];
extern unsigned char shd_str_recruited[10];
extern unsigned char shd_str_by[5];
extern unsigned char shd_str_in_3[5];
extern unsigned char shd_str_period_2[2];
extern unsigned char shd_str_role[8];
extern unsigned char shd_str_role_2[20];
extern unsigned char shd_str_role_3[15];
extern unsigned char shd_str_under_arrest[15];
extern unsigned char shd_str_hiding[12];
extern unsigned char shd_str_turned[9];
extern unsigned char shd_str_empty_dossier_line[1];
extern unsigned char shd_str_quote[2];
extern unsigned char shd_str_quote_2[2];
extern unsigned char shd_str_message_not_decoded[22];
extern unsigned char shd_str_more[8];
extern unsigned char shd_str_empty_dossier_page[1];
extern unsigned char shd_str_rcvd_msg_fm[12];
extern unsigned char shd_str_sent_msg[12];
extern unsigned char shd_str_space_9[2];
extern unsigned char shd_str_someone[9];
extern unsigned char shd_str_of_the_2[9];
extern unsigned char shd_str_in_4[5];
extern unsigned char shd_str_on_2[5];
extern unsigned char shd_str_space_10[2];
extern unsigned char shd_str_period_3[2];
extern unsigned char *shd_subst_keys[7];
extern rt_addr shd_subst_values[7];
extern unsigned char shd_str_mode_read_text[3];
extern unsigned char shd_fmt_line[7];
extern unsigned char shd_fmt_line_2[7];
extern unsigned char shd_str_space_12[2];
extern unsigned char shd_fmt_line_3[7];
extern unsigned char shd_str_information_requires[47];
extern unsigned char shd_str_empty_message;
extern unsigned char shd_str_sloc00[8];
extern unsigned char shd_str_text_dta_sloc[9];
extern unsigned char shd_str_rloc00[8];
extern unsigned char shd_str_text_dta_rloc[9];
extern unsigned char shd_str_sorg00[8];
extern unsigned char shd_str_text_dta_sorg[9];
extern unsigned char shd_str_rorg00[8];
extern unsigned char shd_str_text_dta_rorg[9];
extern unsigned char shd_str_mark_80[2];
extern unsigned char shd_str_text_dta_msg[9];
extern unsigned char shd_str_mark_8f[2];
extern unsigned char shd_str_fluf00[8];
extern unsigned char shd_str_text_dta_fluf[9];
extern unsigned char shd_str_alrt00[8];
extern unsigned char shd_str_text_dta_help[9];
extern unsigned char shd_str_aidd00[8];
extern unsigned char shd_str_text_dta_aidd[9];
extern unsigned char shd_str_text_dta_event[9];
extern unsigned char shd_str_msg0000[9];
extern unsigned char shd_str_facesf_pic[11];
extern unsigned char shd_str_faces_pic[10];
extern unsigned char shd_str_newline_wrap[2];
extern unsigned char shd_str_ellipsis_2[6];
extern unsigned char shd_str_hideout[9];
extern unsigned char shd_str_agent[7];
extern unsigned char shd_str_safehouse[11];
extern unsigned char shd_str_active_cel[12];
extern unsigned char shd_str_office[8];
extern unsigned char shd_str_agent_3[8];
extern unsigned char shd_str_space_13[3];
extern unsigned char *shd_first_names[2][64];
extern unsigned char *shd_last_names[64];
extern unsigned char shd_str_master_plan[12];
extern unsigned char shd_str_secret[11];
extern unsigned char shd_str_arrested_upper[9];
extern unsigned char shd_str_hiding_upper[10];
extern unsigned char shd_str_turned_upper[8];
extern unsigned char shd_str_personnel_file[15];
extern unsigned char shd_str_action_team[13];
extern unsigned char shd_str_comma_3[3];
extern unsigned char shd_str_no_activity[15];
/* The counter in the panel's corner, as text, '00:00:00', its digits written
 * in place. */
extern unsigned char shd_clock_text[9];
extern unsigned char shd_str_one_moment_please[21];
extern unsigned char shd_str_sure_want_quit_no_2[41];
/* Which city's picture is on screen, so an unchanged one is not reloaded; -1
once an animation has been started over it. */
extern UNSIGNED_INT shd_city_on_screen;
extern INT shd_drive;
extern UNSIGNED_INT shm_pan_width;
extern struct PALETTE shd_palette_menu;
extern struct PALETTE shd_palette_face;
extern unsigned char shd_str_ok[3];
extern unsigned char shd_str_briefing_pan[13];
extern unsigned char shd_str_bld[4];
extern UNSIGNED_INT shm_pan_building;
extern unsigned char shd_str_animation_pan[14];
extern UNSIGNED_INT shd_joystick_dirs[9];
extern unsigned char shd_str_env_sve_put[8];
extern unsigned char shd_str_env_sve[8];
extern unsigned char shd_str_file_error[13];
extern unsigned char shd_str_newline_12[3];
extern unsigned char shd_str_please_insert_disk[20];
extern unsigned char shd_str_if_3_5_insert[23];
extern unsigned char shd_str_close_paren[2];
extern unsigned char shd_str_press_return_continue[41];
extern drv_addr shd_disk_names[4];
extern unsigned char shd_disk_letter[2];
/* The screen's page descriptor, the first argument of every drawing call. */
extern struct RASTPORT *shd_screen;
extern rt_addr shd_archive_buffer_end;
extern INT shd_archive_fd;
/* The register block the keyboard-rate and display-page BIOS calls read and
write. */
extern union REGS asm_regs;
extern unsigned char asm_number_digits_3[10];
/* Where each person's dot was last put on the radar, across, one per
person. */
extern INT asm_blip_x[9];
/* Where each person's dot was last put on the radar, down. */
extern INT asm_blip_y[9];
/* Where each person was last drawn on the map, across, one per person; -1 is
nowhere. */
extern INT asm_cast_x[9];
/* Where each person was last drawn on the map, down. */
extern INT asm_cast_y[9];
/* Signs of the player in the current room that would raise the alarm, a
body or something left open; set from the room's flag 8 on entering it. */
extern UNSIGNED_INT asm_signs_here;
/* The disguise the portrait strip is recoloured for, magenta to asm_belt_text,
brought level with asm_disguised at the end of each turn; never on CGA. */
extern UNSIGNED_INT asm_disguise_label_shown;
/* The gas the portrait strip is recoloured for, 9 to 0ch, brought level with
the current room's flag 10h at the end of each turn; never on CGA. */
extern UNSIGNED_INT asm_gas_label_shown;
extern UNSIGNED_INT asm_move_cost;
extern UNSIGNED_INT asm_direction_keycode;
/* Who fired the shot going off this frame, 0 the player. */
extern UNSIGNED_INT asm_shooter;
/* Where the shot's muzzle flash is drawn, across. */
extern UNSIGNED_INT asm_flash_x;
/* Where the shot's muzzle flash is drawn, down. */
extern UNSIGNED_INT asm_flash_y;
extern INT shm_field_cursor;
extern UNSIGNED_INT shm_field_char_width;
extern UNSIGNED_INT shm_field_cursor_x;
/* How many doorways each room has. */
extern INT asm_room_doorways[24];
/* The step map a path search floods, one plane a person: how many steps each
cell is from the goal. */
extern char asm_step_map[9][1280];
/* The frame tick a guard last threw a grenade on. */
extern INT asm_last_grenade_tick;
/* The columns of the cells the path search has still to expand. */
extern unsigned char asm_path_queue_col[256];
/* Their rows, one to each column. */
extern unsigned char asm_path_queue_row[256];
extern unsigned char asm_number_digits[26];
extern unsigned char shm_clue_digits[32];
/* The text.dta tag for one message, nine bytes: a copy of a template such as
 * '*MSG0000', to whose four digits the numbers are added. */
extern unsigned char shm_message_key[9];
/* The screen's background animation, armed when a screen is entered, started
 * each time a menu opens and stepped while it waits. */
extern struct SEQ_BLOCK shm_active_pan;
extern INT shm_menu_line_start[32];
extern UNSIGNED_INT shm_menu_colour_plain;
extern UNSIGNED_INT shm_menu_colour_item;
extern INT shm_menu_lines;
extern UNSIGNED_INT shm_menu_colour_pick;
extern unsigned char FAR *shm_save_block;
extern UNSIGNED_INT shm_save_offset;
extern INT shm_save_fd;
extern UNSIGNED_INT shm_source_fd;
extern UNSIGNED_INT shm_source_dst;
extern UNSIGNED_INT shm_source_src;
extern INT shm_sprite_width;
extern INT shm_sprite_height;
extern UNSIGNED_INT shm_palette_count;
/* How alert the organisation is, out of the shared block's
org_alert_level; read only when breaking in. */
extern INT asm_org_alert_level;
extern UNSIGNED_INT asm_photo_score;
extern struct JOYSTICK shm_joystick;
extern UNSIGNED_INT asm_clips_left;
/* Set when a blast or the alarm has flashed the palette, so that the next
tick puts palette record 0 back. */
extern INT asm_palette_flash;
/* The scratch text buffer every screen builds its lines in, 200h bytes. */
extern unsigned char shm_scratch[512];
extern UNSIGNED_INT asm_guard_seen;
/* Whether the player wears a disguise: set by taking one from a guard, and
cleared by an alarm, by a guard's sighting or as time goes by. The status
line shows "Disguise" while it is set. */
extern UNSIGNED_INT asm_disguised;
extern UNSIGNED_INT asm_night;
/* The mission's difficulty. */
extern INT shm_difficulty;
/* Where the pop-up panel goes, across: at the cursor for a photo, 64h for a
message. */
extern UNSIGNED_INT asm_panel_x;
/* Where the pop-up panel goes, down. */
extern UNSIGNED_INT asm_panel_y;
extern INT shm_clock_minutes;
extern INT asm_guard_alert;
/* The ticks a jump has left, the last six spent landing. */
extern UNSIGNED_INT asm_jump_ticks;
/* What stands on each map cell, an index into dat_floor_objects and -1 for
nothing, indexed 20h * column + row over forty columns and thirty-two rows. */
extern char asm_floor_map[1280];
/* The best-scoring outside room with two doorways or more, kept beside
asm_payload_room: people are placed in either, and a guard with no alert on
stays in it. */
extern INT asm_guard_room;
/* How many times this round a guard has stood in the target room; the first
guard's move copies it to asm_guard_seen and starts it again. */
extern UNSIGNED_INT asm_guards_at_target;
extern INT asm_crouch_walk_ticks;
/* The player's shot countdown: Space adds 4, it is copied into the player's
PERSON.shot_timer, and c_draw_cast fires the shot when it reaches 1. */
extern UNSIGNED_INT asm_shot_timer;
extern UNSIGNED_INT asm_rounds_left;
/* The doorway records, 96 of five bytes each, the first asm_doorway_count of
them in use. */
extern struct DOORWAY asm_doorways[96];
extern struct CAMPAIGN shm_campaign;
extern UNSIGNED_INT shm_seed;
/* The option mask out of the shared block. */
extern INT shm_options;
/* The room's right edge. */
extern UNSIGNED_INT asm_room_right;
/* Set when the graphics letter is 'C', so the CGA paths are taken. */
extern INT shm_cga;
extern UNSIGNED_INT asm_radar_sprite;
extern UNSIGNED_INT asm_readout_sprite;
/* One bit per thing the player chose to carry. */
extern UNSIGNED_INT asm_kit;
/* The room's bottom edge. */
extern UNSIGNED_INT asm_room_bottom;
/* Which kind of trap the player has picked, 0 to 2: F10 steps it round and
the kit panel shows it. It indexes asm_ammunition. */
extern INT asm_effect;
/* The sixteen grenade slots, 10 bytes each. */
extern struct GRENADE asm_grenades[16];
/* The sixteen city records, 34 bytes each. */
extern struct CITY shm_cities[16];
/* How many photos the player has taken, of the film carried: the camera's
thirty-six. */
extern UNSIGNED_INT asm_photos_taken;
extern UNSIGNED_INT asm_player_cell;
/* The kit panel's fifteen sprites, one per dat_kit_sprite_rects entry: 0 to 7
the carried items, 8 to 10 the three kinds of grenade, 11 a round in the gun,
12 a spare clip, 13 a wound, and 14 the icon beside the hit-chance meter. */
extern UNSIGNED_INT asm_kit_sprites[15];
/* The row of the cell the player stands on, asm_player_y / 16, set beside
asm_player_cell's column. */
extern UNSIGNED_INT asm_player_cell_row;
/* The room records, 24 of 0eh bytes, record i for room i and record 0 the
street. */
extern struct ROOM asm_rooms[24];
extern INT asm_room_seen_tick[24];
extern UNSIGNED_INT asm_room_seen;
extern UNSIGNED_INT shm_menu_tick;
extern INT shm_suspect_count;
extern INT asm_mission_kind;
/* The case log, 80h records of 14 bytes, saved as one section. */
extern struct LOG_ENTRY shm_log[128];
extern INT shm_menu_face;
/* The grenade-throw animation's frames left: F5 to F7 set it to 3. */
extern UNSIGNED_INT asm_throw_frames;
extern UNSIGNED_INT asm_bugs_planted;
extern INT asm_frame_tick;
/* Which of shd_clue_source the watch is about, 1 an electronic wiretap and 0 a
clandestine photo. */
extern INT shm_wire_clue_source;
/* The crime event list, 64 records of 2ch bytes from CRIMEn.DTA, each one step
 * of the crime; shm_crime_event_count says how many the case fills. */
extern struct CRIME_EVENT shm_crime_events[64];
extern INT shm_log_count;
extern INT shm_menu_first_line;
/* The longest any awake guard has had the player in sight this round, which
puts the player in the alert pose. */
extern UNSIGNED_INT asm_seen_longest;
/* Whether the guard being moved sees the player, as c_guard_sees_player
answers. */
extern UNSIGNED_INT asm_guard_sees;
/* How many rooms the walls cut the floor into. */
extern INT asm_room_count;
/* Where the player stands, across. */
extern INT asm_player_col;
extern INT shm_building_count;
/* Set while a guard who is not out cold is in the player's room, which makes
the joystick's fire button shoot rather than use. */
extern UNSIGNED_INT asm_guard_in_room;
/* The case's clock in half-days; an event that comes due is stamped with it in
 * CRIME_EVENT.happen_tick. It crosses modules as COMM()->case_tick. */
extern INT shm_case_tick;
/* Where the cursor is, across. */
extern INT asm_cursor_col;
/* Where the player stands, down. */
extern INT asm_player_row;
/* The map of which room each cell belongs to, one byte a cell over a 32-column
grid, the symbol sitting one byte into the map itself. */
extern char asm_room_map[1280];
/* Where the cursor is, down. */
extern INT asm_cursor_row;
/* How the player last moved: 0 standing, 1 walking, 2 using, 4 jumping; 3,
 * walking crouched, is never set. */
extern UNSIGNED_INT asm_last_move_type;
/* The room's left edge. */
extern UNSIGNED_INT asm_room_left;
/* The biggest inside room, where the crime's item and the agent are placed. */
extern INT asm_payload_room;
extern rt_addr shm_source_at;
/* The room's top edge. */
extern UNSIGNED_INT asm_room_top;
extern INT shm_case_city_1;
/* Each room's distance from asm_guard_room, copied out of asm_rooms
at frame 0 and used for sight while no alert is on. */
extern INT asm_guard_distances[24];
extern UNSIGNED_INT shm_case_city_2;
/* The three ammunition counts, one per kind of trap, indexed by asm_effect. */
extern INT asm_ammunition[3];
extern UNSIGNED_INT shm_pan_playing;
/* Set in a tick in which the player walked, which picks the walking frame. */
extern UNSIGNED_INT asm_walked;
extern UNSIGNED_INT asm_bug_score;
extern UNSIGNED_INT shm_menu_no_pick;
extern INT shm_menu_items;
extern INT asm_crouched;
extern INT asm_hour;
extern UNSIGNED_INT asm_walk_frame;
extern UNSIGNED_INT asm_film_left;
/* How many of the crime event list's 64 records the case fills. */
extern INT shm_crime_event_count;
/* Set when the building matters more: in practice, with suspect 0 here, in a
 * city whose CIA office holds a double agent, or with the crime's item placed
 * here. It fields more guards and keeps them alert at night. */
extern UNSIGNED_INT asm_high_security;
/* Set when the alarm sounds, while it is above 200; nothing reads it. */
extern UNSIGNED_INT asm_alarm_sounded;
extern UNSIGNED_INT asm_bugs_left;
extern UNSIGNED_INT asm_guard_tick;
/* Where the player stands in pixels, across. */
extern INT asm_player_x;
extern UNSIGNED_INT shm_case_seed;
extern UNSIGNED_INT shm_clue_method;
extern UNSIGNED_INT shm_menu_relayout;
extern unsigned char asm_outcome;
/* Where the player stands in pixels, down. */
extern INT asm_player_y;
extern INT shm_mission;
extern UNSIGNED_INT shm_menu_colour_bar;
extern UNSIGNED_INT asm_guard_turn_at;
extern INT shm_case_org_1;
extern INT shm_menu_text_width;
extern UNSIGNED_INT shm_case_org_2;
/* The 116 sprite handles cut out of facesf.pic and faces.pic, by SPRITE_*
 * index: two banks of face parts, then the plane and its shadow, clue sources,
 * bodies, paperclip, folder ends and typewriter head. */
extern UNSIGNED_INT shm_faces_sprites[116];
/* Every map tile there is to draw: 0 to 159 the eight rows of twenty grabbed
from the picture, 160 to 167 the row at y 81h and 168 to 175 the row at 91h. */
extern UNSIGNED_INT asm_tile_sprites[176];
/* The suspect the break-in is about: the one whose organisation and city
match the case, in a jailbreak the prisoner to free, or -1 for none. Not a
room. */
extern INT asm_suspect_here;
extern INT asm_room_last;
extern INT shm_global_alert_level;
/* The register block the two video-mode calls read and write. */
extern union REGS shm_regs;
extern UNSIGNED_INT shm_double_agent_cities;
/* How many crime roles the case has: the crime file's participant
count plus four red herrings a difficulty level. */
extern INT shm_crime_role_count;
extern UNSIGNED_INT shm_menu_marked;
/* The case's crime roles, 32 records of 30h bytes: the participant records of
CRIME*.DTA, read whole, then the red herrings the difficulty appends. Saved
as one section. */
extern struct CRIME_ROLE shm_crime_roles[32];
extern rt_addr shm_refill;
extern UNSIGNED_INT asm_DAT_20e3_c3f8;
extern unsigned char shm_archive_buffer[512];
/* Where the view starts, across. */
extern UNSIGNED_INT asm_view_left;
extern UNSIGNED_INT shm_menu_face_x;
extern UNSIGNED_INT shm_menu_draw_only;
/* The packed skill word out of the shared block. */
extern INT shm_skills;
/* Where the view starts, down. */
extern UNSIGNED_INT asm_view_top;
/* The sixteen organisation records, 36 bytes each. */
extern struct ORG_STATE shm_orgs[16];
/* Where the face beside the menu is drawn, down. */
extern UNSIGNED_INT shm_menu_face_y;
/* The password read out of the file with %32s, so 33 bytes, which the map
draws along the top a character at a time. */
extern unsigned char asm_password_text[33];
extern INT shm_finished;
extern INT asm_target_room;
/* The people on the floor, nine records of 1ch bytes, the player first. */
extern struct PERSON asm_people[9];
extern unsigned char shm_menu_shortcut[32];
extern unsigned char asm_password_hint[11];
extern UNSIGNED_INT asm_belt_text;
/* Which item the menu starts on, cleared to 0 as it leaves. Setting it before
a menu opens selects that option, and a value past the last selects none
until the player moves. */
extern UNSIGNED_INT shm_menu_pick;
/* The 72 bytes CRIMEn.DTA ends with, read after the crime events; this
module only saves and restores them. */
extern struct CRIME_ENTRY shm_crime_block[4];
extern UNSIGNED_INT asm_end_line;
extern UNSIGNED_INT shm_menu_right;
/* Where a substitution parks the rest of a line while the key is cut out and
the value appended. */
extern unsigned char shm_substitute_tail[256];
/* The case's role scan states, one per crime role: when clue visibility may
 * start building against it, and how much has built. Saved as one section. */
extern struct ROLE_SCAN_STATE shm_role_scan_states[32];
/* How many guards this round have been awake, stun under 3e7h. */
extern UNSIGNED_INT asm_guards_awake;
extern INT asm_wounds;
/* The graphics driver's letter, out of the shared block. */
extern unsigned char shm_graphics_letter;
extern UNSIGNED_INT shm_menu_bottom;
extern UNSIGNED_INT asm_sound_arg_1;
extern UNSIGNED_INT asm_sound_arg_2;
extern INT asm_seen_count;
extern INT shm_case_city;
/* One counter per city and one per organisation, of the names the player has
 * been told there. Saved as one section. TAC reuses city[0] to count the
 * guards still on their feet. */
extern struct ACTIVITY shm_activity;
extern UNSIGNED_INT shm_orgs_known;
extern UNSIGNED_INT shm_case_spare_2;
/* The row buffer the picture decoder fills one scanline at a time, and the
driver takes a sprite row or a screen row from. */
extern unsigned char shm_anim_row_2[320];
extern INT asm_difficulty_was;
/* Set in a tick in which the player did something a guard watching would
notice, such as firing, throwing or using; a guard who sees it drops the
disguise and raises the alarm. */
extern UNSIGNED_INT asm_conspicuous;
/* How many doorways have been cut. */
extern INT asm_doorway_count;
/* The guards still to be brought onto the floor: main seeds it with the
building's count, c_place_person takes one off for each it places, and a guard
who leaves the floor is put back. */
extern INT asm_guards_to_come;
/* The walls of each map cell, one bit a side, indexed 20h * column + row over
forty columns and thirty-two rows. */
extern char asm_wall_map[1280];
extern INT shm_case_org;
#endif

#endif /* TAC_H */
