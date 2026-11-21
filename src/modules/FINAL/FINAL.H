/* FINAL.H -- what the C side can reach on the assembly side. */
#ifndef FINAL_H
#define FINAL_H

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

/* routines in assembly, exported to C */
/* Install the module's INT 24h handler, so a critical error inside a save
 * comes back as a failed call. */
UNSIGNED_INT shm_hook_critical_error(void);
/* Put the INT 24h handler back, if this is the call that took it. */
UNSIGNED_INT shm_unhook_critical_error(void);

/* data defined in assembly, exported to C */
#ifdef PORT_MODERN
/* The data group, datum by datum, which the portable build alone reads. */
#include "FINAL_PORT.H"
#else
extern unsigned char dat_str_env_sve[8];
extern unsigned char dat_str_move_joystick_upper[54];
extern unsigned char dat_str_move_joystick_lower[55];
extern unsigned char dat_str_labs_pic[9];
extern unsigned char dat_str_env_sve_2[8];
extern unsigned char dat_str_title2_pan[11];
extern unsigned char dat_str_credits_pan[12];
extern unsigned char dat_str_do_want_create_new[101];
extern unsigned char dat_str_env_sve_3[8];
extern unsigned char dat_str_env_sve_4[8];
/* The case's 64 suspect records, 16 bytes each, crossing modules as one
400h-byte save section. */
extern struct SUSPECT shm_suspects[64];
/* The buildings the player knows of, 100h records of 12 bytes, one per
 * organisation and city, shm_building_count of them in use. One 0c00h-byte
 * save section. */
extern struct BUILDING shm_buildings[256];
/* The clues the player has turned up, 50h records of 12 bytes, filled in
 * order; the first whose role is -1 is the next free one. One 3c0h-byte save
 * section. */
extern struct SHOWN_CLUE shm_clues_shown[80];
/* The arrested suspect a jailbreak is coming for, -1 for none; here only the
 * prisoner field of a save's header. */
extern UNSIGNED_INT shm_jailbreak_suspect;
extern struct RASTPORT *shd_map_page;
extern struct COLOUR_MAP dat_colours_title;
extern struct COLOUR_MAP dat_colours_title_2;
extern struct COLOUR_MAP shd_colours_screen;
extern struct COLOUR_MAP shd_colours_screen_2;
extern struct COLOUR_MAP dat_colours_report;
extern struct COLOUR_MAP dat_colours_main;
extern struct COLOUR_MAP shd_colours_face;
extern struct COLOUR_MAP dat_colours_badge;
extern struct COLOUR_MAP dat_colours_grid;
extern struct PALETTE dat_palette_title;
/* The disk number c_want_disk is called with. Ships as 1 and nothing writes it. */
extern UNSIGNED_INT shd_pan_disk;
extern unsigned char dat_str_animation_pan[14];
extern unsigned char dat_str_env_sve_5[8];
extern unsigned char dat_str_empty_15;
extern unsigned char dat_str_sloc00[8];
extern unsigned char dat_str_text_dta[9];
extern unsigned char dat_str_rloc00[8];
extern unsigned char dat_str_text_dta_2[9];
extern unsigned char dat_str_sorg00[8];
extern unsigned char dat_str_text_dta_3[9];
extern unsigned char dat_str_rorg00[8];
extern unsigned char dat_str_text_dta_4[9];
extern unsigned char dat_str_fluf00[8];
extern unsigned char dat_str_text_dta_5[9];
extern unsigned char dat_str_gender_pic[11];
extern unsigned char dat_str_select_one_maximillian[56];
extern unsigned char dat_str_which_difficulty_level[95];
/* The organisation table: 26 rows of eight words, in the order dat_org_names
names them, each row its MasterMind's face and body. */
extern INT dat_org_table[26][8];
/* The mission-set table: sixteen struct MISSION_SET of 74 bytes, of which
 * three fields are read and the name never is. */
extern struct MISSION_SET dat_mission_sets[16];
extern unsigned char dat_key_plot_start[8];
extern unsigned char dat_str_briefing_pan[13];
extern unsigned char dat_str_plot_txt[9];
extern unsigned char dat_str_max_remington_s[26];
extern unsigned char dat_str_mattress_full_cash[24];
extern unsigned char dat_str_pl000a[8];
extern unsigned char dat_str_pl000a_2[8];
extern unsigned char dat_str_briefing_pan_2[13];
extern unsigned char dat_str_plot_txt_2[9];
extern unsigned char dat_str_max_s_code_name[20];
extern unsigned char dat_str_which_difficulty_level_2[95];
extern unsigned char dat_str_training_pic[13];
extern unsigned char dat_str_blank[2];
extern unsigned char dat_str_practice[12];
extern unsigned char dat_str_training[12];
/* The five skill names as pointers: Combat, Driving, Cryptography, Electronics,
Stamina. The training screen reads the first four. */
extern unsigned char *dat_skill_names[5];
extern unsigned char dat_str_average[8];
extern unsigned char dat_str_good[5];
extern unsigned char dat_str_excellent[10];
extern unsigned char dat_str_awesome[9];
/* The colour of each of the four skill rows' bars; CGA zeroes the last. */
extern INT dat_skill_colours[4];
extern struct PALETTE dat_palette_badge;
extern unsigned char dat_str_max_i_m_sure[45];
extern unsigned char dat_str_among_these_faces[22];
extern unsigned char dat_str_briefing_pan_3[13];
extern unsigned char dat_str_looks_like_about_wraps[44];
extern unsigned char dat_str_we_ve_been_able[84];
extern unsigned char dat_str_icons_pic[10];
extern unsigned char dat_key_plot_zero[8];
extern unsigned char dat_note_01[13];
extern unsigned char dat_note_02[9];
extern unsigned char dat_note_03[85];
extern unsigned char dat_note_04[50];
extern unsigned char dat_note_05[53];
extern unsigned char dat_note_06[46];
extern unsigned char dat_note_07[58];
extern unsigned char dat_note_08[12];
extern unsigned char dat_note_09[49];
extern unsigned char dat_note_10[13];
extern unsigned char dat_note_11[51];
extern unsigned char dat_note_12[52];
extern unsigned char dat_note_13[52];
extern unsigned char dat_note_14[55];
extern unsigned char dat_note_15[26];
extern unsigned char dat_note_16[95];
extern unsigned char dat_note_17[44];
extern unsigned char dat_note_18[14];
extern struct RASTPORT *asm_replay_page;
/* '*PL0000', the plot.txt tag, whose four digits are written over
with the set, the mission and the paragraph. */
extern unsigned char asm_plot_key[8];
extern unsigned char dat_str_empty_2[1];
extern unsigned char dat_str_paren_open[3];
extern unsigned char dat_str_paren_close[3];
extern unsigned char dat_str_space[2];
extern unsigned char dat_str_slash[2];
extern unsigned char dat_str_sent_message[18];
extern unsigned char dat_str_caret[2];
extern unsigned char dat_str_caret_2[2];
extern unsigned char dat_str_empty_3[1];
extern unsigned char dat_str_sent_message_2[16];
extern unsigned char dat_str_sent_package[16];
extern unsigned char dat_str_empty_4[1];
extern unsigned char dat_str_paren_open_2[3];
extern unsigned char dat_str_paren_close_2[3];
extern unsigned char dat_str_slash_2[2];
extern unsigned char dat_str_caret_3[2];
extern unsigned char dat_str_caret_4[2];
extern unsigned char dat_str_paren_open_3[3];
extern unsigned char dat_str_paren_close_3[3];
extern unsigned char dat_str_now_has[13];
extern unsigned char dat_str_empty_5[1];
extern unsigned char dat_str_left[7];
extern unsigned char dat_str_traveled[17];
extern unsigned char dat_str_broke[17];
extern unsigned char dat_str_slash_3[2];
extern unsigned char dat_str_arrested[14];
extern unsigned char dat_str_confiscated[17];
extern unsigned char dat_str_went_into_hiding[19];
extern unsigned char dat_str_mission_completed[19];
extern unsigned char dat_str_unable[10];
extern unsigned char dat_str_complete_mission[18];
extern unsigned char dat_str_came_out_hiding[21];
extern unsigned char dat_str_escaped_from_jail[20];
extern unsigned char dat_str_released_by_exchange[23];
extern unsigned char dat_str_turned[12];
extern unsigned char dat_str_space_2[2];
extern unsigned char dat_str_day_number[4];
/* The time stamp, '00:00 AM Jun 00', which the time, the month and the
day are written into before the report stamps a line. */
extern unsigned char dat_date_template[16];
extern unsigned char dat_str_efficiency_report[18];
extern unsigned char dat_str_org_sep[3];
extern unsigned char dat_str_org_slash[2];
extern unsigned char dat_str_at_large[9];
extern unsigned char dat_str_arrested_2[9];
extern unsigned char dat_str_turned_2[7];
extern unsigned char dat_str_ep_0[4];
extern unsigned char dat_str_ep_of[3];
extern unsigned char dat_str_ep_50[5];
extern unsigned char dat_str_confiscated_2[12];
extern unsigned char dat_str_ep_50_2[6];
extern unsigned char dat_str_not_found[10];
extern unsigned char dat_str_of_50[5];
extern unsigned char dat_str_of_org[2];
extern unsigned char dat_str_ep_blank[7];
extern unsigned char dat_str_prevented_crime[16];
extern unsigned char dat_str_ep_100[12];
extern unsigned char dat_str_empty_agents[1];
extern unsigned char dat_str_double_agent_s[17];
extern unsigned char dat_str_remained_undetected[20];
extern unsigned char dat_str_within_cia[16];
extern unsigned char dat_str_ep_slash[6];
extern unsigned char dat_str_efficiency_rating[18];
extern unsigned char dat_str_dashes[5];
extern unsigned char dat_str_dashes_end[5];
extern unsigned char dat_str_ep_total[4];
extern unsigned char dat_str_ep_total_of[3];
extern unsigned char dat_str_career[7];
extern unsigned char dat_str_career_2[14];
extern unsigned char dat_str_max[6];
extern unsigned char dat_str_remington[12];
extern unsigned char dat_str_case[7];
extern unsigned char dat_str_comma[3];
extern unsigned char dat_str_space_3[2];
extern unsigned char dat_str_arrests[13];
extern unsigned char dat_str_ep_colon[6];
extern unsigned char dat_str_couldn_t_stop[19];
extern unsigned char dat_str_prevented[15];
extern unsigned char dat_str_slash_4[2];
extern unsigned char dat_str_arrested_3[14];
extern unsigned char dat_str_mastermind[13];
extern unsigned char dat_str_career_3[7];
extern unsigned char dat_str_arrested_masterminds[24];
extern unsigned char dat_str_agents[11];
extern unsigned char dat_str_career_4[7];
extern unsigned char dat_str_masterminds_arrested[21];
/* The thirteen mission-type names, Kidnapping to Manufacture, indexed by a
mission's type; dat_org_names follows it directly. */
extern unsigned char *addr_crime_names[13];
/* The 26 organisation names as pointers, in dat_org_table's row order,
 * directly after the thirteen mission-type names. */
extern unsigned char *dat_org_names[26];
extern unsigned char dat_str_gender_pic_2[11];
extern unsigned char dat_str_max_2[4];
extern unsigned char dat_str_remington_2[10];
extern unsigned char dat_str_arrested_4[9];
extern unsigned char dat_str_arrested_5[9];
extern unsigned char dat_str_after_difficult_few[65];
extern unsigned char dat_str_word_latest_case_seems[69];
extern unsigned char dat_str_after_successful_case[61];
extern unsigned char dat_str_re_feeling_invincible[64];
extern unsigned char dat_str_final4_cat[11];
extern unsigned char dat_str_final3_cat[11];
extern unsigned char dat_str_back_pic[9];
extern unsigned char dat_str_hand[5];
extern unsigned char dat_str_f_pic[6];
extern unsigned char dat_str_m_pic[6];
extern unsigned char dat_str_laudude1_pic[13];
extern unsigned char dat_str_dude[5];
extern unsigned char dat_str_babe[5];
extern unsigned char dat_str_pic[5];
/* The four place prefixes the interlude builds file names from: lau, off, bch,
cas, indexed by the first word of a dat_interlude_table row. */
extern unsigned char *dat_ending_names[4];
/* The interlude table: 21 rows of five words -- the place, 0 to 3, then sprite
numbers ending at -1. */
extern struct INTERLUDE dat_interlude_table[21];
extern unsigned char dat_str_red_herring[12];
extern unsigned char dat_str_we_have_indications[26];
extern unsigned char dat_str_operation_preparation[45];
extern unsigned char dat_str_europe[8];
extern unsigned char dat_str_africa_middle_east[20];
extern unsigned char dat_str_central_america[17];
extern unsigned char dat_str_the[6];
extern unsigned char dat_str_known_involved[26];
extern unsigned char dat_str_mission_prevent[59];
extern unsigned char dat_str_capture_as_many[56];
extern unsigned char dat_str_caution_one_more_double[78];
extern unsigned char dat_str_i_m_afraid_re[50];
extern unsigned char dat_str_perhaps_should_practice[67];
extern unsigned char dat_str_ok_re_cleared[21];
extern unsigned char dat_str_here_some_info_we[59];
extern unsigned char dat_str_we_think_s_linked[43];
extern unsigned char dat_str_briefing_pan_4[13];
extern unsigned char dat_str_10_dta[7];
/* "crime0.dta ", with a trailing space a two-digit case number takes over: the
digit is patched at [5], and above 9 "10.dta" goes over [5] and [6]. */
extern unsigned char dat_CRIME_DTA_NAME[12];
/* 'world0.dta', whose digit is patched in place before
the file is opened. */
extern unsigned char dat_str_world[11];
extern unsigned char dat_str_fame_dta[9];
extern unsigned char dat_str_fame_dta_2[9];
extern unsigned char dat_str_fame_dta_3[9];
extern unsigned char dat_str_fame_dta_4[9];
extern unsigned char dat_str_hall_fame[13];
extern unsigned char dat_str_covert_action[14];
extern unsigned char dat_str_hall_fame_2[13];
extern unsigned char dat_str_dashes_2[5];
extern unsigned char dat_str_stop[3];
extern unsigned char dat_str_max_3[6];
extern unsigned char dat_str_remington_case[21];
extern unsigned char dat_str_space_4[2];
extern unsigned char dat_str_space_5[2];
extern unsigned char dat_str_slash_5[2];
extern unsigned char dat_str_ep_colon_2[5];
extern unsigned char dat_str_score_stop[17];
extern unsigned char dat_str_dashes_3[5];
extern unsigned char dat_str_clear[7];
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
/* Bits set in 0 to 31: 32 bytes, each the population count of its index. */
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
extern unsigned char *shd_clue_keys[5];
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
/* The first names, 128 pointers in halves of 64 chosen by bit 0 of a suspect's
 * face word, indexed by the organisation's nationality byte doubled plus bits
 * 1 to 4 of the face word; bits 5 to 8 pick among the 64 surnames. */
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
/* The template a time is written into, '00:00:00'; c_clock_text writes the six
 * digits in place. */
extern unsigned char shd_clock_text[9];
extern unsigned char shd_str_nsyn_overflow[15];
extern unsigned char shd_str_chronology[11];
extern unsigned char shd_str_news[5];
extern unsigned char shd_str_sent_msg_2[14];
extern unsigned char shd_str_met[11];
extern unsigned char shd_str_quote_3[2];
extern unsigned char shd_str_quote_4[2];
extern unsigned char shd_str_meeting_noted[14];
extern unsigned char shd_str_more_2[8];
extern unsigned char shd_str_chronology_2[11];
extern unsigned char shd_str_news_2[5];
extern unsigned char shd_str_none_log[5];
extern unsigned char shd_str_one_moment_please[21];
extern unsigned char shd_str_sure_want_quit_no_2[41];
/* Which city's picture is on screen, so an unchanged one is not reloaded; -1 once a menu's animation has drawn over it. */
extern UNSIGNED_INT shd_city_on_screen;
/* The drive the game started from, or -1, as it ships, for "not asked yet". A
drive of 2 or below gets "One moment please...". */
extern INT shd_drive;
/* The width of the animation area, blanked and copied back over: the screen's
140h once a page frame is drawn, and widened past a menu drawn beside the pan. */
extern UNSIGNED_INT shm_pan_width;
extern struct PALETTE shd_palette_menu;
extern struct PALETTE shd_palette_face;
extern unsigned char shd_str_ok[3];
extern unsigned char shd_str_briefing_pan[13];
extern unsigned char shd_str_bld[4];
extern UNSIGNED_INT shm_pan_building;
extern unsigned char shd_str_animation_pan[14];
extern UNSIGNED_INT shd_joystick_dirs[9];
extern unsigned char shd_str_select_load_file[22];
/* The save slot's file name, 'a:cv0.sve', whose drive letter and slot digit,
 * '0' to '3', are written in place. */
extern unsigned char shd_save_name[10];
extern unsigned char shd_str_sve[4];
extern unsigned char shd_str_max[7];
extern unsigned char shd_str_remington_00[16];
extern unsigned char shd_str_rank_2[12];
extern unsigned char shd_str_colon[3];
extern unsigned char shd_str_space_slot[2];
extern unsigned char shd_str_comma_2[3];
extern unsigned char shd_str_local[9];
extern unsigned char shd_str_national[12];
extern unsigned char shd_str_regional[12];
extern unsigned char shd_str_global[10];
extern unsigned char shd_str_stop_blank[5];
extern unsigned char shd_str_empty_slot[14];
extern unsigned char shd_str_select_save_file[21];
extern unsigned char shd_str_game_has_been_saved[22];
extern unsigned char shd_str_game_not_saved[17];
extern unsigned char shd_str_write_access_denied[22];
extern unsigned char shd_str_disk_full[12];
extern unsigned char shd_str_press_key_continue[24];
extern unsigned char shd_str_sve_2[4];
extern unsigned char shd_str_file_error_write[13];
extern unsigned char shd_str_newline_save[2];
extern unsigned char shd_str_save_progress[25];
extern unsigned char shd_str_which_drive_contains[59];
extern unsigned char shd_str_which_drive_contains_2[57];
extern unsigned char shd_str_press_drive_letter[61];
extern unsigned char shd_str_press_escape_cancel[29];
extern unsigned char shd_str_no_disk_drive[21];
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
extern struct RASTPORT *shd_anim_page;
extern struct RASTPORT *shd_anim_page_2;
extern drv_addr drv_page_hidden;
extern drv_addr drv_page_shown;
extern drv_addr drv_page_anim;
extern UNSIGNED_INT shm_seq_picture;
extern UNSIGNED_INT shm_frame_toggle;
extern unsigned char shd_str_pani[5];
extern struct RASTPORT *shd_screen;
extern rt_addr shd_archive_buffer_end;
extern INT shd_archive_fd;
extern UNSIGNED_INT shm_anim_magic;
extern INT shm_field_cursor;
extern UNSIGNED_INT shm_field_char_width;
extern UNSIGNED_INT shm_field_cursor_x;
extern unsigned char asm_number_digits[16];
extern unsigned char asm_number_digits_2[16];
extern unsigned char asm_number_digits_3[16];
extern unsigned char asm_number_digits_4[32];
extern unsigned char asm_number_digits_5[16];
extern unsigned char shm_clue_digits[32];
/* The tag one message's text is read under, nine bytes: a copy of a template
 * such as '*MSG0000', to whose four digits the numbers are added. */
extern unsigned char shm_message_key[9];
/* The screen's background animation, a struct SEQ_BLOCK: armed when a screen
 * is entered, started each time a menu opens and stepped while it waits. */
extern struct SEQ_BLOCK shm_active_pan;
extern INT shm_menu_line_start[32];
extern UNSIGNED_INT shm_menu_colour_plain;
extern UNSIGNED_INT shm_menu_colour_item;
extern INT shm_menu_lines;
extern UNSIGNED_INT shm_menu_colour_pick;
extern unsigned char shm_slot_digits[16];
/* Which drive prompt is put up: 0 the Save Game one, non-zero the saved-game-files
one. */
extern UNSIGNED_INT shm_save_loading;
/* The errno a save left, and the only report of a critical error inside one. 0dh
and 1ch get a sentence of their own -- write-protected and full. */
extern INT shm_save_errno;
/* The handle for describing and creating a slot, as against shm_save_fd,
which the save itself is written through. */
extern INT shm_slot_fd;
/* The case scope read out of a slot's file, 0 to 3: Local, National,
Regional, Global. */
extern INT shm_slot_word;
/* Where the far end of a section copy is built, inside the shared block. */
extern unsigned char FAR *shm_save_block;
/* Where a save is going: zero for a file, otherwise the offset into the shared
block, from 400h up by each section's length. */
extern UNSIGNED_INT shm_save_offset;
/* The file handle a save is written or read back through. */
extern INT shm_save_fd;
extern UNSIGNED_INT shm_seq_frames_left;
extern UNSIGNED_INT shm_frames_owed;
extern UNSIGNED_INT shm_seq_wait;
extern struct SEQ_BLOCK *shm_seq_block;
extern char FAR *shm_seq_pc;
extern UNSIGNED_INT shm_seq_depth;
extern UNSIGNED_INT shm_seq_frames_done;
extern UNSIGNED_INT shm_seq_sound_queue_count;
/* The full-screen animation, a struct SEQ_BLOCK, filled from the four
arguments of a play and run to its end; in FINAL, the intro animations. */
extern struct SEQ_BLOCK shm_fullscreen_pan;
extern UNSIGNED_LONG shm_frame_deadline;
extern UNSIGNED_INT shm_seq_op;
extern INT shm_seq_operand;
extern UNSIGNED_INT shm_anim_fd;
extern UNSIGNED_INT shm_anim_magic_read;
extern UNSIGNED_INT shm_anim_packed;
extern char shm_anim_signature[5];
/* The row buffer c_anim_read fills one scanline at a time, and which the
driver takes a sprite row or a screen row from. */
extern unsigned char shm_anim_row[320];
extern UNSIGNED_INT shm_source_fd;
extern UNSIGNED_INT shm_source_dst;
extern UNSIGNED_INT shm_source_src;
extern UNSIGNED_INT shm_sprite_width;
extern INT shm_sprite_height;
extern UNSIGNED_INT shm_palette_count;
extern struct JOYSTICK shm_joystick;
/* The scratch text buffer every screen builds its lines in, 200h bytes,
the size of the shared block's message it is copied to and from. */
extern unsigned char shm_scratch[512];
extern INT asm_report_slots;
extern INT shm_difficulty;
extern UNSIGNED_INT asm_case_day;
extern INT asm_career_cursor;
extern INT asm_report_topics;
extern UNSIGNED_INT shm_clock_minutes;
/* The campaign record, 28eh bytes, the first section of a save. */
extern struct CAMPAIGN shm_campaign;
extern UNSIGNED_INT shm_seed;
extern UNSIGNED_INT asm_screen_sprite_a;
extern UNSIGNED_INT asm_scene_sprites[5];
extern UNSIGNED_INT asm_screen_sprite_c;
extern INT shm_options;
extern INT shm_cga;
extern UNSIGNED_INT asm_DAT_20d8_828e;
/* The sixteen city records, 34 bytes each. */
extern struct CITY shm_cities[16];
extern UNSIGNED_INT shm_menu_tick;
extern INT shm_suspect_count;
/* The case log, 80h records of 14 bytes, crossing modules as one 700h-byte
save section. */
extern struct LOG_ENTRY shm_log[128];
/* What the clue screen should show next: -1 nothing, -2 a fresh sighting,
otherwise the packed face to draw. */
extern INT shm_menu_face;
/* The four-word register block the INT 33h calls read and write. */
extern union REGS shm_mouse_regs;
/* Which of shd_clue_source the watch is about: 1 an electronic wiretap, 0 a
 * clandestine photo. */
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
extern INT shm_frame_ticks;
extern UNSIGNED_INT asm_shown_count;
extern rt_addr shm_source_at;
extern INT shm_case_city_1;
extern UNSIGNED_INT shm_case_city_2;
extern UNSIGNED_INT shm_anim_more;
extern UNSIGNED_INT shm_pan_playing;
extern unsigned char shm_anim_palette[774];
extern INT asm_report_total;
extern UNSIGNED_INT asm_case_minute;
extern UNSIGNED_INT shm_menu_no_pick;
/* Set to -1 on start-up and never read. */
extern UNSIGNED_INT asm_DAT_20d8_9bee;
/* The campaign record of a save slot being described, read out of its
file so the slot is described without being loaded. */
extern struct CAMPAIGN shm_probed_campaign;
extern INT shm_menu_items;
extern UNSIGNED_INT shm_anim_segment;
extern UNSIGNED_INT asm_case_hour;
extern UNSIGNED_INT shm_seq_ticks;
/* Set to 1 on start-up and never read. */
extern UNSIGNED_INT asm_DAT_20d8_9e86;
/* How many of the crime event list's 64 records the case fills. */
extern INT shm_crime_event_count;
extern UNSIGNED_INT shm_case_seed;
extern UNSIGNED_INT shm_clue_method;
extern UNSIGNED_INT shm_menu_relayout;
extern INT shm_mission;
extern UNSIGNED_INT shm_menu_colour_bar;
extern INT shm_case_org_1;
extern INT shm_menu_text_width;
extern UNSIGNED_INT shm_case_org_2;
/* The 116 sprites cut out of facesf.pic and faces.pic: two banks of forty face
 * parts, then the plane and its shadow, clue sources, bodies, paperclip,
 * folder edge and typewriter head. */
extern UNSIGNED_INT shm_faces_sprites[116];
extern INT shm_global_alert_level;
/* A bit per save slot that has a file. Choosing an empty slot answers the same as
backing out. */
extern UNSIGNED_INT shm_slots_filled;
/* The four-word register block the INT 10h calls read and write. */
extern union REGS shm_regs;
extern UNSIGNED_INT shm_anim_error;
extern UNSIGNED_INT shm_double_agent_cities;
/* How many crime roles the case has: the crime file's participant
count plus four red herrings a difficulty level. */
extern INT shm_crime_role_count;
extern UNSIGNED_INT shm_menu_marked;
/* The case's crime roles, 32 records of 30h bytes: the participant records of
 * CRIME*.DTA, then the red herrings the difficulty appends. One save
 * section. */
extern struct CRIME_ROLE shm_crime_roles[32];
extern UNSIGNED_INT asm_fresh_start;
extern UNSIGNED_INT shm_seq_done;
extern rt_addr shm_refill;
extern UNSIGNED_INT asm_DAT_20d8_a5ac;
extern unsigned char shm_archive_buffer[512];
/* Where a menu draws the face it is to show, across; shm_menu_face_y is down. */
extern UNSIGNED_INT shm_menu_face_x;
extern UNSIGNED_INT shm_menu_draw_only;
extern UNSIGNED_INT shm_skills;
extern UNSIGNED_INT shm_mouse_buttons;
extern UNSIGNED_INT shm_mouse_x;
extern UNSIGNED_INT shm_mouse_y;
extern UNSIGNED_INT shm_mouse_count;
/* Where a menu draws the face it is to show, down. */
extern UNSIGNED_INT shm_menu_face_y;
/* The sixteen organisation records, 36 bytes each. */
extern struct ORG_STATE shm_orgs[16];
extern UNSIGNED_INT shm_anim_sprites[250];
extern rt_addr shm_anim_name;
extern UNSIGNED_INT asm_case_mastermind;
/* The byte left in the shared block on the way out of the program -- the last
thing the module says to whatever loaded it. */
extern INT shm_finished;
extern UNSIGNED_INT asm_case_flags;
/* Thirty-two bytes, one shortcut letter per menu item: the character after its
leading space. */
extern unsigned char shm_menu_shortcut[32];
extern UNSIGNED_INT shm_menu_pick;
extern UNSIGNED_INT asm_case_city_3;
/* The 72 bytes CRIMEn.DTA ends with, read after the crime events and
saved with the case. */
extern struct CRIME_ENTRY shm_crime_block[4];
extern UNSIGNED_INT asm_masterminds_arrested;
extern UNSIGNED_INT shm_menu_right;
/* Where c_substitute parks the rest of a line while the key is cut out and
the value appended. */
extern unsigned char shm_substitute_tail[256];
/* The case's role scan states, one per crime role: when clue visibility may
 * start building against it, and how much has built. One save section, six
 * bytes a role. */
extern struct ROLE_SCAN_STATE shm_role_scan_states[32];
extern unsigned char shm_graphics_letter;
extern UNSIGNED_INT shm_menu_bottom;
extern UNSIGNED_INT shm_seq_stop_asked;
extern UNSIGNED_INT asm_set_first;
extern INT shm_case_city;
extern struct ACTIVITY shm_activity;
extern UNSIGNED_INT shm_orgs_known;
extern UNSIGNED_INT asm_dossier_seen;
/* The save slot last chosen; the previous value goes to shm_menu_pick. */
extern INT shm_slot_pick;
extern UNSIGNED_INT shm_case_spare_2;
extern unsigned char shm_anim_row_2[320];
/* The hall of fame, six records of 2ch bytes, best score first, read and
written as all 108h bytes at once. */
extern struct FAME_ENTRY asm_fame[6];
extern INT asm_case_points;
extern UNSIGNED_INT shm_anim_block_kind;
extern INT asm_grid_in_play;
/* The sequence language's fifty-one variables. Entry 6 is set to -1 when a
sequence is interrupted. Entry 0 carries choices into a sequence and out: the
copyright check's verdict, 1 for a pass and 4 for a fail. */
extern INT shm_seq_vars[51];
extern UNSIGNED_INT shm_case_org;
#endif

#endif /* FINAL_H */
