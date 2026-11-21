/* BUG.H -- what the C side can reach on the assembly side. */
#ifndef BUG_H
#define BUG_H

/* The driver entries this module calls, declared once for every module. */
#include "DRIVERS.H"

/* The dispatch segment's own routines, declared once for every module. */
#include "DRVREAL.H"

/* The MSC 5.1 run-time this module calls, declared once for the tree. */
#include "RUNTIME.H"

/* A type this module reaches, declared once for the modules sharing it. */
#include "COMM.H"

/* A type this module reaches, declared once for the modules sharing it. */
#include "STRUCTS.H"

/* The structures this module reaches, defined once for the whole tree. */
#include "STRUCTS.H"

/* data defined in assembly, exported to C */
#ifdef PORT_MODERN
/* The data group, datum by datum, which the portable build alone reads. */
#include "BUG_PORT.H"
#else
extern unsigned char dat_str_env_sve[8];
extern unsigned char dat_str_camera_pic[11];
extern unsigned char dat_str_board_pic[10];
extern unsigned char dat_str_env_sve_2[8];
/* How far each of the eight neighbours is, across. */
extern UNSIGNED_INT dat_neighbour_col[8];
/* How far each of the eight neighbours is, down. */
extern UNSIGNED_INT dat_neighbour_row[8];
/* What a chip's two outputs are, indexed by its kind and by the pair of inputs
it already has. */
extern INT dat_chip_outputs[12][4][2];
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
extern struct RASTPORT *shd_picture_page;
extern struct RASTPORT *shd_map_page;
extern struct COLOUR_MAP shd_colours_screen;
extern struct COLOUR_MAP shd_colours_screen_2;
/* The colour map set for both halves of the call where nothing is being
remapped. */
extern struct COLOUR_MAP dat_colours_plain;
extern struct COLOUR_MAP shd_colours_paper;
extern struct COLOUR_MAP shd_colours_face;
extern UNSIGNED_INT shd_pan_disk;
extern struct RASTPORT *dat_chip_page;
extern INT shm_difficulty;
extern struct PALETTE shd_palette_records[5];
extern unsigned char dat_str_bugs_pic[9];
extern unsigned char dat_str_car_tracer[12];
extern unsigned char dat_str_complete[12];
extern unsigned char dat_str_alarm[10];
extern unsigned char dat_str_phone_taps_completed[23];
extern unsigned char dat_str_car_tracer_installed[23];
extern unsigned char dat_str_time_expired[15];
extern unsigned char dat_str_phones_tapped[17];
extern unsigned char dat_str_no[3];
extern unsigned char dat_str_alarms[9];
extern unsigned char dat_str_sure_want_quit_no[41];
extern unsigned char dat_str_paused[9];
/* The board's own clock, '00:00:00', its digits written in place. */
extern unsigned char dat_clock_text[9];
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
extern unsigned char shd_str_empty_positively[1];
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
extern unsigned char shd_str_clues_txt[10];
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
extern unsigned char asm_block_21eb;
extern unsigned char *shd_subst_keys[7];
extern rt_addr shd_subst_values[7];
extern unsigned char shd_str_mode_read_text[3];
extern unsigned char shd_fmt_line[7];
extern unsigned char shd_fmt_line_2[7];
extern unsigned char shd_str_space_12[2];
extern unsigned char shd_fmt_line_3[7];
extern unsigned char shd_str_information_requires[47];
extern unsigned char shd_str_empty_message[1];
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
extern unsigned char shd_str_faces_pic[11];
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
extern unsigned char shd_str_no_activity[14];
/* The clock string in the screen header's corner, '00:00:00', its digits
 * written in place. */
extern unsigned char shd_clock_text[9];
extern unsigned char shd_str_incoming_msg[13];
extern unsigned char shd_list_printout[588];
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
extern struct RASTPORT *shd_screen;
extern rt_addr shd_archive_buffer_end;
extern INT shd_archive_fd;
extern unsigned char asm_number_digits[16];
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
extern UNSIGNED_INT shm_sprite_width;
extern INT shm_sprite_height;
extern UNSIGNED_INT shm_palette_count;
extern struct JOYSTICK shm_joystick;
/* The scratch text buffer every screen builds its lines in, 200h bytes. */
extern unsigned char shm_scratch[512];
/* Where the title screen's box starts, across. */
extern UNSIGNED_INT asm_title_x;
/* Where the title screen's box starts, down. */
extern UNSIGNED_INT asm_title_y;
extern UNSIGNED_INT shm_clock_minutes;
/* The chips dealt onto the board, column first: seven columns, which the
signal crosses left to right, of five chips each. */
extern INT asm_deal_chip[7][5];
/* The campaign record, 28eh bytes, the first section of a save. */
extern struct CAMPAIGN shm_campaign;
extern UNSIGNED_INT shm_seed;
/* The most goals reached at once this round: the highest asm_wires_live has
reached. */
extern INT asm_max_goals_reached;
/* Which column the cursor is on. */
extern INT asm_cursor_col;
extern INT shm_options;
/* The agent picture the title screen draws. */
extern UNSIGNED_INT asm_agent_sprite;
/* The wire picture the title screen draws under him. */
extern UNSIGNED_INT asm_wire_sprite;
extern INT shm_cga;
/* Which row the cursor is on. */
extern INT asm_cursor_row;
/* The chip the player is holding, which the board draws beside the cursor. */
extern UNSIGNED_INT asm_held_chip;
/* The sixteen city records, 34 bytes each. */
extern struct CITY shm_cities[16];
extern UNSIGNED_INT shm_menu_tick;
extern INT shm_suspect_count;
/* 0 while tapping phones, 1 while installing a car tracer. */
extern UNSIGNED_INT asm_board_stage;
/* The case log, 80h records of 14 bytes, saved as one section. */
extern struct LOG_ENTRY shm_log[128];
extern INT shm_menu_face;
/* The round's score, the phones tapped or 0 after an alarm, which the module
hands back through the shared block. */
extern UNSIGNED_INT asm_score;
/* The board's tick count, eight to a second, whose low two bits pick the
palette record. */
extern UNSIGNED_INT asm_frame_count;
/* Which of shd_clue_source the watch is about, 1 an electronic wiretap and 0 a
clandestine photo, which also picks the wire over the box on the title
panel. */
extern INT shm_wire_clue_source;
/* The crime event list, 64 records of 2ch bytes from CRIMEn.DTA, each one step
 * of the crime; shm_crime_event_count says how many the case fills. */
extern struct CRIME_EVENT shm_crime_events[64];
extern INT shm_log_count;
extern INT shm_menu_first_line;
extern INT shm_building_count;
/* The case's clock in half-days; an event that comes due is stamped with it in
 * CRIME_EVENT.happen_tick. It crosses modules as COMM()->case_tick. */
extern INT shm_case_tick;
extern rt_addr shm_source_at;
extern INT shm_case_city_1;
extern UNSIGNED_INT shm_case_city_2;
extern UNSIGNED_INT shm_pan_playing;
extern UNSIGNED_INT shm_menu_no_pick;
/* How many alarm lines have tripped, handed back through the shared block. */
extern UNSIGNED_INT asm_alarms;
extern INT shm_menu_items;
/* The two pins each dealt chip takes, for the six gaps between columns of
chips, ten lines each: for each line out of a column, which line of the next it
feeds. */
extern INT asm_deal_pins[6][10];
/* The value on each of the ten lines going into and out of each of the seven
columns of chips, -1 until set; the last column's outputs are what the lamps
show. */
extern INT asm_deal_lines[14][10];
/* Set for each line the settled deal leaves at 0: an alarm line, which trips
if its value changes. */
extern UNSIGNED_INT asm_column_done[10];
/* Set to 1 on entry and never read. */
extern UNSIGNED_INT asm_DAT_1a63_7636;
/* How many of the crime event list's 64 records the case fills. */
extern INT shm_crime_event_count;
extern UNSIGNED_INT shm_case_seed;
/* The method nibble of the clue being shown, which picks its line. */
extern UNSIGNED_INT shm_clue_method;
extern UNSIGNED_INT shm_menu_relayout;
/* The case's mission, which keys its clues.txt and text.dta blocks. */
extern INT shm_mission;
extern UNSIGNED_INT shm_menu_colour_bar;
extern INT shm_case_org_1;
extern INT shm_menu_text_width;
extern UNSIGNED_INT shm_case_org_2;
/* The 116 sprite handles cut out of facesf.pic and faces.pic, by SPRITE_*
 * index: two banks of face parts, then the plane and its shadow, clue sources,
 * bodies, paperclip, folder ends and typewriter head. */
extern UNSIGNED_INT shm_faces_sprites[116];
/* The 44 sprite handles cut out of bugs.pic, by BUG_SPRITE_* index: two rows
 * of sixteen 8-pixel wire pieces and the twelve 16-pixel chips. */
extern UNSIGNED_INT asm_bugs_sprites[44];
extern INT shm_global_alert_level;
/* The register block the INT 10h calls read and write. */
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
/* Seconds left on the clock, taken down one every eighth tick. */
extern INT asm_seconds_left;
extern rt_addr shm_refill;
extern UNSIGNED_INT asm_DAT_1a63_7db8;
extern unsigned char shm_archive_buffer[512];
extern UNSIGNED_INT shm_menu_face_x;
extern UNSIGNED_INT shm_menu_draw_only;
extern UNSIGNED_INT shm_skills;
/* The sixteen organisation records, 36 bytes each. */
extern struct ORG_STATE shm_orgs[16];
extern UNSIGNED_INT shm_menu_face_y;
/* Non-zero once the round is over. */
extern INT shm_finished;
extern unsigned char shm_menu_shortcut[32];
extern UNSIGNED_INT shm_menu_pick;
/* The 72 bytes CRIMEn.DTA ends with, read after the crime events; this
module only saves and restores them. */
extern struct CRIME_ENTRY shm_crime_block[4];
/* Written once, as the difficulty doubled plus six and clamped to 0..0bh, and
 * never read. */
extern UNSIGNED_INT asm_DAT_1a63_8274;
extern UNSIGNED_INT shm_menu_right;
/* Where a substitution parks the rest of a line while the key is cut out and
the value appended. */
extern unsigned char shm_substitute_tail[256];
/* The case's role scan states, one per crime role: when clue visibility may
 * start building against it, and how much has built. Saved as one section. */
extern struct ROLE_SCAN_STATE shm_role_scan_states[32];
extern unsigned char shm_graphics_letter;
extern UNSIGNED_INT shm_menu_bottom;
/* The board, forty columns of 25 words, one per 8-pixel cell: one byte of
neighbour bits per cell, and 100h in the ninth bit for "carrying a signal". */
extern INT asm_wire_grid[40][25];
/* How many wires are carrying a signal. */
extern INT asm_wires_live;
/* The city the module was entered for. */
extern INT shm_case_city;
/* One counter per city and one per organisation, of the names the player has
been told there, which the activity report scales into bars. Saved as one
section. */
extern struct ACTIVITY shm_activity;
extern UNSIGNED_INT shm_orgs_known;
extern UNSIGNED_INT shm_case_spare_2;
extern unsigned char shm_anim_row_2[320];
/* The whole case's difficulty, kept apart from this board's so a tap's
findings are worked out at the case's. */
extern UNSIGNED_INT asm_case_difficulty;
/* The organisation the module was entered for. */
extern UNSIGNED_INT shm_case_org;
#endif

#endif /* BUG_H */
