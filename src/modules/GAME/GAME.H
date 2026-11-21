/* GAME.H -- what the C side can reach on the assembly side. */
#ifndef GAME_H
#define GAME_H

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
UNSIGNED_INT shm_hook_critical_error(void);
UNSIGNED_INT shm_unhook_critical_error(void);

/* data defined in assembly, exported to C */
#ifdef PORT_MODERN
/* The data group, datum by datum, which the portable build alone reads. */
#include "GAME_PORT.H"
#else
extern unsigned char dat_str_env_sve[8];
extern unsigned char dat_str_one_moment_please[22];
/* The case's 64 suspect records, 16 bytes each, crossing modules as one
save section. */
extern struct SUSPECT shm_suspects[64];
/* The buildings the player knows of, 100h records of 12 bytes, one per
 * organisation and city, shm_building_count of them in use. Saved as one
 * section. */
extern struct BUILDING shm_buildings[256];
/* The clues the player has turned up, 50h records of 12 bytes, filled in
 * order; the first whose role is -1 is the next free one. Saved as one
 * section. */
extern struct SHOWN_CLUE shm_clues_shown[80];
/* The arrested suspect a jailbreak is coming for, and -1 for none: set by
c_test_for_jailbreak, cleared once the jailbreak is announced or the suspect is
released. */
extern INT shm_jailbreak_suspect;
/* The page a city picture is decoded into. */
extern struct RASTPORT *shd_picture_page;
extern struct RASTPORT *shd_map_page;
extern struct COLOUR_MAP shd_colours_screen;
extern struct COLOUR_MAP shd_colours_screen_2;
extern struct COLOUR_MAP shd_colours_paper;
extern struct COLOUR_MAP shd_colours_face;
extern struct COLOUR_MAP dat_colours_statbar;
extern struct COLOUR_MAP dat_colours_hq;
extern struct COLOUR_MAP dat_colours_cia_entrance;
extern struct COLOUR_MAP dat_colours_cia_office;
extern struct COLOUR_MAP dat_colours_cia_hall;
extern struct COLOUR_MAP dat_colours_escape_2;
extern struct COLOUR_MAP dat_colours_escape;
extern struct COLOUR_MAP dat_colours_stakeout;
extern struct COLOUR_MAP dat_colours_building[5];
extern struct COLOUR_MAP dat_colours_accuse;
extern struct COLOUR_MAP dat_colours_advice;
extern struct COLOUR_MAP dat_colours_city_2;
extern struct COLOUR_MAP dat_colours_building_2;
extern struct COLOUR_MAP dat_colours_stakeout_2;
extern struct COLOUR_MAP dat_colours_accuse_2;
extern struct COLOUR_MAP dat_colours_map;
extern struct COLOUR_MAP dat_colours_report;
extern struct COLOUR_MAP dat_colours_city;
extern struct PALETTE dat_palette_game;
extern UNSIGNED_INT shd_pan_disk;
extern unsigned char dat_str_animation_pan[14];
extern unsigned char dat_str_env_sve_2[8];
extern unsigned char dat_str_ad_pic[7];
extern unsigned char shd_str_newline_wrap[2];
extern unsigned char shd_str_ellipsis_2[6];
extern unsigned char shd_str_hideout[9];
extern unsigned char shd_str_agent[7];
extern unsigned char shd_str_safehouse[11];
extern unsigned char shd_str_active_cel[12];
extern unsigned char shd_str_office[8];
extern unsigned char dat_str_agent_2[8];
extern unsigned char dat_str_space_14[3];
extern unsigned char *dat_first_names[2][64];
extern unsigned char *dat_last_names[64];
extern unsigned char dat_str_master_plan[12];
extern unsigned char dat_str_secret[11];
extern unsigned char dat_str_arrested[9];
extern unsigned char dat_str_hiding[10];
extern unsigned char dat_str_turned[8];
extern unsigned char dat_str_personnel_file[15];
extern unsigned char dat_str_action_team[13];
extern unsigned char dat_str_comma_4[3];
extern unsigned char dat_str_no_activity[14];
/* The counter the frame timer keeps, as text, '00:00:00', its digits written
 * in place. */
extern unsigned char shd_clock_text[9];
extern unsigned char shd_str_incoming_msg[13];
extern unsigned char shd_list_printout[588];
extern unsigned char dat_str_warning_pan[12];
extern unsigned char dat_str_jailbreak[14];
extern unsigned char dat_str_bang_nl[3];
extern unsigned char dat_str_agents_trying_free[28];
extern unsigned char dat_str_bang_nl_2[3];
extern unsigned char dat_str_bustout_pan[12];
extern unsigned char dat_str_escapes[11];
extern unsigned char dat_str_escape_attempt_foiled[24];
extern unsigned char dat_str_car_tracer_leads_new[46];
extern unsigned char dat_str_carcap[8];
extern unsigned char dat_str_wounded_pan[12];
extern unsigned char dat_str_take_time_recover_from[43];
extern unsigned char dat_str_surprisel[11];
extern unsigned char dat_str_surprisew[11];
extern unsigned char dat_str_you_are_in[12];
extern unsigned char dat_str_do_go[19];
extern unsigned char dat_str_airport[15];
extern unsigned char dat_str_hotel[15];
extern unsigned char dat_str_unknown_building[17];
extern unsigned char dat_str_nl_space[3];
extern unsigned char dat_str_nl_space_2[3];
extern unsigned char dat_str_check_data[12];
extern unsigned char dat_str_surprise[10];
extern unsigned char dat_str_at[16];
extern unsigned char dat_str_unknown_building_2[17];
extern unsigned char dat_str_few_guards_peering[47];
extern unsigned char dat_str_appears_extra_guards[43];
extern unsigned char dat_str_building_swarming[39];
extern unsigned char dat_str_do_place_wiretap[28];
extern unsigned char dat_str_break_into_building[22];
extern unsigned char dat_str_watch_building_check[40];
extern unsigned char dat_str_blding01_pan[13];
extern unsigned char dat_str_sneakin_pic[12];
extern unsigned char dat_str_wiretap_pic[12];
extern unsigned char dat_str_guards[16];
extern unsigned char dat_str_will_have[17];
extern unsigned char dat_str_minutes[11];
extern unsigned char dat_str_followed_pan[13];
extern unsigned char dat_str_followed[10];
extern unsigned char dat_str_hq_pan[7];
extern unsigned char dat_str_arrive_at_cia_building[61];
extern unsigned char dat_str_binos3_pan[11];
extern unsigned char dat_str_notice_someone[19];
extern unsigned char dat_str_leaving_building[24];
extern unsigned char dat_str_do_wait_follow_car[55];
extern unsigned char dat_str_he_looks[10];
extern unsigned char dat_str_she_looks[11];
extern unsigned char dat_str_nl_dot[3];
extern unsigned char dat_str_bugcar_pan[11];
extern unsigned char dat_str_briefing_pan[13];
extern unsigned char dat_str_good_job_max_found[29];
extern unsigned char dat_str_should_really_slow_down[50];
extern unsigned char dat_str_intrgate_pan[13];
extern unsigned char dat_str_accuse[12];
extern unsigned char dat_str_taking_part_plot_we[59];
extern unsigned char dat_str_dot_quote_nl[4];
extern unsigned char dat_str_have_no_evidence[30];
extern unsigned char dat_str_dot_nl_he[5];
extern unsigned char dat_str_dot_nl_she[6];
extern unsigned char dat_str_will_have_released[28];
extern unsigned char dat_str_inter1[8];
extern unsigned char dat_str_doublea[9];
extern unsigned char dat_str_inter2[8];
extern unsigned char dat_str_ask[13];
extern unsigned char dat_str_oh_yeah_i_guess[50];
extern unsigned char dat_str_hmmm_i_don_t[61];
extern unsigned char dat_str_mastermind_breaks_down[67];
extern unsigned char dat_str_injail_pan[11];
extern unsigned char dat_str_taken_local_jail[30];
extern unsigned char dat_str_briefing_pan_2[13];
extern unsigned char dat_str_nice0[7];
extern unsigned char dat_str_prose_dta[10];
extern unsigned char dat_msg_rplc[6];
extern unsigned char dat_str_max_remington[14];
extern unsigned char dat_msg_name[6];
extern unsigned char dat_msg_city[6];
extern unsigned char dat_msg_org[5];
extern unsigned char dat_key_us[4];
extern unsigned char dat_str_surndr01_pan[13];
extern unsigned char dat_str_grilled[9];
extern unsigned char dat_str_warning_pan_2[12];
extern unsigned char dat_str_jailbreak_2[14];
extern unsigned char dat_str_bang_nl_3[3];
extern unsigned char dat_str_agents_free[14];
extern unsigned char dat_str_bang_nl_4[3];
extern unsigned char dat_str_escape_pan[11];
extern unsigned char dat_str_escape[8];
extern unsigned char dat_str_no_thanks_squinty_agree[42];
extern unsigned char dat_str_exchanged[23];
extern unsigned char dat_str_dot_nl[3];
extern unsigned char dat_str_two_double_agents[20];
extern unsigned char dat_str_europe_pic[11];
extern unsigned char dat_str_africa_pic[11];
extern unsigned char dat_str_central_pic[12];
extern unsigned char dat_str_re[11];
extern unsigned char dat_str_do_travel[23];
extern unsigned char dat_str_stay_here[12];
extern unsigned char dat_str_space[2];
extern unsigned char dat_str_nl[2];
extern unsigned char dat_str_check_data_2[14];
/* How far a leg of the flight moves the plane, across. */
extern unsigned char asm_leg_x[8];
/* How far a leg of the flight moves the plane, down. */
extern unsigned char asm_leg_y[8];
/* Which of the eight legs points at the destination: one byte per pair of
 * signs, indexed by sign(across) * 3 + sign(down) from its fifth byte, each a
 * subscript into asm_leg_x and asm_leg_y. */
extern unsigned char asm_leg_next[9];
extern unsigned char dat_str_quiet[6];
extern unsigned char dat_str_unsuspecting[13];
extern unsigned char dat_str_cautious[9];
extern unsigned char dat_str_suspicious[11];
extern unsigned char dat_str_nervous[8];
extern unsigned char dat_str_very_nervous[13];
extern unsigned char dat_str_briefing_pan_3[13];
extern unsigned char dat_str_rest_up[24];
extern unsigned char dat_str_i_ve_assigned_one[81];
extern unsigned char dat_str_president_s_counting[56];
extern unsigned char dat_str_pic[5];
extern unsigned char dat_str_comma_space[3];
extern unsigned char dat_str_cities_cat[12];
extern unsigned char dat_str_coded_message[23];
extern unsigned char dat_str_meeting_notes[23];
extern unsigned char dat_str_new_information[24];
extern unsigned char dat_str_additional_information[28];
extern unsigned char dat_str_space_2[2];
extern unsigned char dat_str_dots[6];
extern unsigned char dat_str_on[4];
extern unsigned char dat_str_space_2_2[2];
extern unsigned char dat_str_of_the[8];
extern unsigned char dat_str_in[4];
extern unsigned char dat_str_newline[2];
extern unsigned char dat_str_empty_4[1];
extern unsigned char dat_str_space_3[2];
extern unsigned char dat_str_in_2[5];
extern unsigned char *shd_clue_phrases[40];
extern char shd_scan_counts[32];
extern unsigned char *shd_month_names[12];
extern unsigned char dat_str_empty_5[1];
extern unsigned char dat_str_has_been_identified_as[52];
extern unsigned char dat_str_empty_6;
extern unsigned char dat_str_has_been_positively[36];
extern unsigned char dat_str_newline_2[2];
extern unsigned char dat_str_we_have_acquired[34];
extern unsigned char dat_str_stop[3];
extern unsigned char dat_str_empty_7[1];
extern unsigned char dat_str_has_been_spotted[22];
extern unsigned char dat_str_newline_3[2];
extern unsigned char dat_str_empty_8[1];
extern unsigned char dat_str_has_been_identified_as_2[41];
extern unsigned char dat_str_newline_4[2];
extern unsigned char dat_str_we_have_obtained[52];
extern unsigned char dat_str_newline_5[2];
extern unsigned char dat_str_we_have_determined_rank[32];
extern unsigned char dat_str_newline_6[2];
extern unsigned char dat_str_we_found_recruiting[39];
extern unsigned char dat_str_newline_7[2];
extern unsigned char dat_str_we_found_recruiting_2[39];
extern unsigned char dat_str_newline_8[2];
extern rt_addr shd_clue_kinds[80];
extern unsigned char dat_str_clue[5];
extern unsigned char dat_str_source_2_2[10];
extern unsigned char dat_str_slash[2];
extern unsigned char dat_str_newline_9[2];
extern unsigned char dat_str_method_stop[11];
extern unsigned char dat_str_related_2[16];
extern unsigned char dat_str_newline_10[2];
extern unsigned char dat_str_none[8];
extern unsigned char *dat_clue_source[7];
extern unsigned char dat_key_clue[7];
extern unsigned char dat_str_clues_txt[11];
extern rt_addr shd_clue_keys[5];
extern unsigned char shd_str_period[2];
extern unsigned char dat_str_face[11];
extern unsigned char dat_str_valkerie[9];
extern unsigned char dat_str_thunderbolt[12];
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
extern unsigned char dat_note_01[10];
extern unsigned char dat_note_02[115];
extern unsigned char dat_note_03[8];
extern unsigned char dat_note_04[68];
extern unsigned char dat_note_05[59];
extern unsigned char dat_note_06[120];
extern unsigned char dat_note_07[9];
extern unsigned char dat_note_08[112];
extern unsigned char dat_note_09[20];
extern unsigned char dat_note_10[20];
extern unsigned char dat_note_11[44];
extern unsigned char dat_note_12[52];
extern unsigned char dat_note_13[93];
extern unsigned char dat_note_14[13];
extern unsigned char dat_note_15[84];
extern unsigned char dat_note_16[55];
extern unsigned char dat_note_17[11];
extern unsigned char dat_note_18[52];
extern unsigned char dat_note_19[24];
extern unsigned char dat_note_20[9];
extern unsigned char dat_str_empty_9[1];
extern unsigned char dat_str_slash_2[2];
extern unsigned char dat_str_dots_2[6];
extern unsigned char dat_str_percent[3];
extern unsigned char dat_str_none_2[7];
extern unsigned char dat_str_which_organization[24];
extern unsigned char dat_str_allies[11];
extern unsigned char dat_str_nl_space_3[3];
extern unsigned char dat_str_none_3[5];
extern unsigned char dat_str_known_locations[19];
extern unsigned char dat_str_in_5[5];
extern unsigned char dat_str_nl_dash[3];
extern unsigned char dat_str_associates[15];
extern unsigned char dat_str_nl_space_4[3];
extern unsigned char dat_str_none_4[5];
extern unsigned char dat_str_space_4[2];
extern unsigned char dat_str_newline_11[2];
extern unsigned char dat_str_which_city[16];
extern unsigned char dat_str_known_locations_2[19];
extern unsigned char dat_str_unknown_building_3[18];
extern unsigned char dat_str_nl_dash_2[3];
extern unsigned char dat_str_none_5[6];
extern unsigned char dat_str_suspects[12];
extern unsigned char dat_str_slash_3[2];
extern unsigned char dat_str_ellipsis[7];
extern unsigned char dat_str_nl_dash_space[4];
extern unsigned char dat_str_none_6[6];
extern unsigned char dat_str_clues[8];
extern unsigned char dat_str_dash[2];
extern unsigned char dat_str_newline_12[2];
extern unsigned char dat_str_none_7[6];
extern unsigned char dat_str_space_5[2];
extern unsigned char dat_str_newline_13[2];
extern unsigned char dat_str_documents[10];
extern unsigned char dat_str_select_document[19];
extern unsigned char dat_str_master_plan_2[14];
extern unsigned char dat_str_personel_file[17];
extern unsigned char dat_str_none_8[7];
extern unsigned char dat_str_suspect_files[14];
extern unsigned char dat_str_space_6[2];
extern unsigned char dat_str_of_the_3[9];
extern unsigned char dat_str_in_6[5];
extern unsigned char dat_str_dot_nl_2[4];
extern unsigned char dat_str_bullet[3];
extern unsigned char dat_str_space_7[2];
extern unsigned char dat_str_arrested_2[11];
extern unsigned char dat_str_hiding_3[9];
extern unsigned char dat_str_turned_3[9];
extern unsigned char dat_str_custody[13];
extern unsigned char dat_str_nl_2[3];
extern unsigned char dat_str_none_9[7];
extern unsigned char dat_str_coded_messages[15];
extern unsigned char dat_str_space_8[2];
extern unsigned char dat_str_space_11[2];
extern unsigned char dat_str_nl_3[6];
extern unsigned char dat_str_nl_4[3];
extern unsigned char dat_str_none_10[7];
extern unsigned char dat_str_message_decode[15];
extern unsigned char dat_str_from[6];
extern unsigned char dat_str_to_heading[4];
extern unsigned char dat_str_message[9];
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
extern unsigned char *shd_subst_keys[7];
extern rt_addr shd_subst_values[7];
extern unsigned char shd_str_mode_read_text[3];
extern unsigned char shd_fmt_line[7];
extern unsigned char shd_fmt_line_2[7];
extern unsigned char shd_str_space_12[2];
extern unsigned char shd_fmt_line_3[7];
extern unsigned char shd_str_information_requires[47];
extern unsigned char dat_str_empty_9_2;
extern unsigned char dat_str_sloc00[8];
extern unsigned char dat_str_text_dta[9];
extern unsigned char dat_str_rloc00[8];
extern unsigned char dat_str_text_dta_2[9];
extern unsigned char dat_str_sorg00[8];
extern unsigned char dat_str_text_dta_3[9];
extern unsigned char dat_str_rorg00[8];
extern unsigned char dat_str_text_dta_4[9];
extern unsigned char dat_str_mark_80[2];
extern unsigned char dat_str_text_dta_5[9];
extern unsigned char dat_str_mark_8f[2];
extern unsigned char dat_str_fluf00[8];
extern unsigned char dat_str_text_dta_6[9];
extern unsigned char dat_str_alrt00[8];
extern unsigned char dat_str_text_dta_7[9];
extern unsigned char dat_str_aidd00[8];
extern unsigned char dat_str_text_dta_8[9];
extern unsigned char dat_str_text_dta_9[9];
extern unsigned char shd_str_msg0000[9];
extern unsigned char shd_str_facesf_pic[11];
extern unsigned char shd_str_faces_pic[10];
extern unsigned char dat_str_bulletin[11];
extern unsigned char dat_str_has_gone_into_hiding[24];
extern unsigned char dat_str_surveillance_team[18];
extern unsigned char dat_str_env_sve_3[8];
extern unsigned char dat_str_interpol_bulletin[20];
extern unsigned char dat_str_spotted[13];
extern unsigned char dat_str_bang_nl_5[3];
extern unsigned char dat_str_interpol[9];
extern unsigned char dat_str_empty_10;
extern unsigned char dat_str_message_traffic[31];
extern unsigned char dat_str_from_2[7];
extern unsigned char dat_str_to[5];
extern unsigned char dat_str_dots_3[6];
extern unsigned char dat_str_satellite_intercept[20];
extern unsigned char dat_str_double_agent[15];
extern unsigned char dat_str_wiretap_at[12];
extern unsigned char dat_str_slash_4[2];
extern unsigned char dat_str_reveals[10];
extern unsigned char dat_str_he[4];
extern unsigned char dat_str_she_2[5];
extern unsigned char dat_str_space_13[2];
extern unsigned char dat_str_nl_5[2];
extern unsigned char dat_str_empty_12[1];
extern unsigned char dat_str_from_3[7];
extern unsigned char dat_str_slash_5[2];
extern unsigned char dat_str_nl_6[2];
extern unsigned char dat_str_has_just_returned_from[35];
extern unsigned char dat_str_dot_nl_3[3];
extern unsigned char dat_str_airport_surveillance[21];
extern unsigned char dat_str_empty_13;
extern unsigned char dat_str_seems_have_departed[30];
extern unsigned char dat_str_dot_nl_4[3];
extern unsigned char dat_str_airport_surveillance_2[21];
extern unsigned char dat_str_bulletin_2[11];
extern unsigned char dat_str_has_come_out_hiding[26];
extern unsigned char dat_str_surveillance_team_2[18];
extern unsigned char dat_str_bulletin_3[11];
extern unsigned char dat_str_has_come_out_hiding_2[26];
extern unsigned char dat_str_surveillance_team_3[18];
extern unsigned char dat_str_day_slot[4];
extern unsigned char asm_TIMESTAMP[16];
extern unsigned char dat_str_comma_space_2[4];
/* The screen y the status bar's top edge is drawn at: 174 at the
foot in a city, 4 at the top in a building, and put back to 174 after each
draw. */
extern INT asm_status_bar_y;
extern unsigned char dat_str_arrested_3[9];
extern unsigned char dat_str_turned_4[7];
extern unsigned char dat_str_clues_2[6];
/* The colour each clue-menu row is filled with, by the row's count mod 4, so
that the rows alternate. */
extern INT dat_clue_colours[4];
/* The clue menu's highlighted entry, stepped by Up and Down through the
places listed; its parity picks the column the entry sits in. */
extern INT asm_clue_selected;
extern unsigned char dat_str_clue_2[5];
extern unsigned char dat_str_source_3[10];
extern unsigned char dat_str_slash_6[2];
extern unsigned char dat_str_nl_7[2];
extern unsigned char dat_str_nl_8[2];
extern unsigned char dat_str_arrested_4[9];
extern unsigned char dat_str_hiding_4[10];
extern unsigned char dat_str_turned_5[8];
extern unsigned char dat_str_officem_pan[12];
extern unsigned char dat_str_officef_pan[12];
extern unsigned char dat_str_max_i_ve_been[57];
extern unsigned char dat_str_i_d_look_into[36];
extern unsigned char dat_str_space_15[2];
extern unsigned char dat_str_newline_17[2];
extern unsigned char dat_str_mark_8f_2[49];
extern unsigned char dat_str_newline_space[3];
extern unsigned char dat_str_there_s_not_much[39];
extern unsigned char dat_str_the[5];
extern unsigned char dat_str_has[7];
extern unsigned char dat_str_right_here[16];
extern unsigned char dat_str_i_d_suggest_go[60];
extern unsigned char dat_str_message_should_give_us[46];
extern unsigned char dat_str_space_16[2];
extern unsigned char dat_str_check_crypto_branch[32];
extern unsigned char dat_str_max_we_ve_got[54];
extern unsigned char dat_str_max_i_suggest_check[43];
extern unsigned char dat_str_he_2[3];
extern unsigned char dat_str_she_3[4];
extern unsigned char dat_str_s_right_here[18];
extern unsigned char dat_str_stop_space[3];
extern unsigned char dat_str_advicea[9];
extern unsigned char dat_str_advice1[9];
extern unsigned char dat_str_advice2[9];
extern unsigned char dat_str_advice3[9];
extern unsigned char dat_str_advice4[9];
extern unsigned char dat_str_advice5[9];
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
extern struct RASTPORT dat_anim_page_2_port;
extern struct RASTPORT *shd_anim_page;
extern struct RASTPORT *shd_anim_page_2;
extern drv_addr drv_page_hidden;
extern drv_addr drv_page_shown;
extern drv_addr drv_page_anim;
/* The picture the PAN animation is on. */
extern UNSIGNED_INT shm_seq_picture;
extern INT shm_frame_toggle;
extern unsigned char shd_str_pani[5];
extern unsigned char shd_str_one_moment_please[21];
extern unsigned char shd_str_sure_want_quit_no_2[41];
/* Which city's picture is on screen, so an unchanged one is not reloaded; cleared to -1 when a sequence starts. */
extern UNSIGNED_INT shd_city_on_screen;
extern INT shd_drive;
/* How wide a notice is: the whole screen over a picture, and the right-hand
strip over the map. */
extern UNSIGNED_INT shm_pan_width;
extern struct PALETTE shd_palette_menu;
extern struct PALETTE shd_palette_face;
extern unsigned char shd_str_ok[3];
extern unsigned char shd_str_briefing_pan[13];
extern unsigned char shd_str_bld[4];
extern UNSIGNED_INT shm_pan_building;
extern unsigned char shd_str_animation_pan[14];
extern UNSIGNED_INT shd_joystick_dirs[9];
extern struct RASTPORT dat_screen_port;
extern struct RASTPORT *shd_screen;
extern unsigned char asm_DAT_2206_4370;
extern unsigned char asm_DAT_2206_4371;
extern UNSIGNED_INT asm_DAT_2206_4372;
extern UNSIGNED_INT asm_DAT_2206_4374;
extern UNSIGNED_INT asm_DAT_2206_4376;
extern UNSIGNED_INT asm_DAT_2206_4378;
extern UNSIGNED_INT asm_DAT_2206_437a;
extern UNSIGNED_INT asm_DAT_2206_437c;
extern UNSIGNED_INT asm_DAT_2206_437e;
extern rt_addr shd_archive_buffer_end;
extern INT shd_archive_fd;
extern UNSIGNED_INT asm_DAT_2206_449d;
extern UNSIGNED_INT asm_DAT_2206_449f;
extern UNSIGNED_INT asm_DAT_2206_44a1;
extern UNSIGNED_INT asm_DAT_2206_44a3;
extern UNSIGNED_INT asm_DAT_2206_44a5;
extern UNSIGNED_INT asm_DAT_2206_4815;
extern UNSIGNED_INT asm_DAT_2206_4817;
extern UNSIGNED_INT asm_DAT_2206_4819;
extern UNSIGNED_INT asm_DAT_2206_481b;
extern UNSIGNED_INT asm_DAT_2206_481d;
extern UNSIGNED_INT asm_DAT_2206_481f;
extern unsigned char asm_DAT_2206_4822;
extern UNSIGNED_INT asm_DAT_2206_4823;
extern UNSIGNED_INT asm_DAT_2206_4825;
extern UNSIGNED_INT asm_DAT_2206_4827;
extern UNSIGNED_INT asm_DAT_2206_4829;
extern UNSIGNED_INT asm_DAT_2206_482b;
extern UNSIGNED_INT asm_DAT_2206_482d;
extern UNSIGNED_INT asm_DAT_2206_4830;
extern UNSIGNED_INT asm_DAT_2206_4832;
extern UNSIGNED_INT asm_DAT_2206_4834;
extern UNSIGNED_INT asm_DAT_2206_4836;
/* The four row-edge table addresses the page routines index by page: the left
 * edge tables of pages 0 and 1, then the right ones, 200 words each. */
extern unsigned char *addr_page_row_tables[4];
extern UNSIGNED_INT asm_DAT_2206_4e80;
extern UNSIGNED_INT asm_DAT_2206_4e82;
extern UNSIGNED_INT __argc;
extern UNSIGNED_INT _cflush;
extern UNSIGNED_INT asm_DAT_2206_4f68;
extern UNSIGNED_INT asm_DAT_2206_4f6a;
extern UNSIGNED_INT asm_DAT_2206_4f6c;
extern UNSIGNED_INT asm_DAT_2206_5234;
extern UNSIGNED_INT shm_anim_magic;
/* Sixteen bytes of scratch: the CIA building's animation
name, 'BLDING01.PAN' with the floor written over its last digit, and the
digits of a count. */
extern unsigned char asm_building_pan[16];
/* Set while a building is being watched. */
extern UNSIGNED_INT asm_watched;
/* How likely the watch is to turn something up. */
extern UNSIGNED_INT asm_watch_odds;
/* How wide the picture on screen is. */
extern UNSIGNED_INT asm_picture_width;
/* How tall the picture on screen is. */
extern UNSIGNED_INT asm_picture_height;
extern unsigned char shm_clue_digits[16];
/* The digits itoa writes a wiretap's level into for its line
of the tap list. */
extern unsigned char asm_tap_digits[16];
/* The key a message's block is looked up by, nine bytes: a copy of a template
 * such as '*MSG0000', to whose four digits the numbers are added. */
extern unsigned char shm_message_key[9];
/* The suspect c_test_for_jailbreak last picked in the day's scan of due
events: -2 through the first scan and -1 through the second, where a jailbreak
is certain rather than a chance. */
extern INT asm_jailbreak_target_suspect;
/* The mastermind's suspect, found afresh by every c_test_for_jailbreak: no
jailbreak while they are under arrest. */
extern UNSIGNED_INT asm_jailbreak_source_suspect;
extern unsigned char shm_slot_digits[16];
extern UNSIGNED_INT shm_save_loading;
extern INT shm_save_errno;
extern INT shm_slot_fd;
extern INT shm_slot_word;
extern unsigned char FAR *shm_save_block;
extern UNSIGNED_INT shm_save_offset;
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
arguments it is played with and run to its end; here it plays before the car
tracer, after watching a location. */
extern struct SEQ_BLOCK shm_fullscreen_pan;
extern UNSIGNED_LONG shm_frame_deadline;
extern UNSIGNED_INT shm_seq_op;
extern INT shm_seq_operand;
extern UNSIGNED_INT shm_anim_fd;
extern UNSIGNED_INT shm_anim_magic_read;
extern UNSIGNED_INT shm_anim_packed;
extern char shm_anim_signature[5];
/* The row buffer an animation is read into one scanline at a time, and which
the driver takes a sprite row or a screen row from. */
extern unsigned char shm_anim_row[320];
/* The screen's background animation, a struct SEQ_BLOCK: armed when a screen
 * is entered, started each time a menu opens and stepped while it waits. */
extern struct SEQ_BLOCK shm_active_pan;
extern INT shm_menu_line_start[32];
extern UNSIGNED_INT shm_menu_colour_plain;
extern UNSIGNED_INT shm_menu_colour_item;
extern INT shm_menu_lines;
extern UNSIGNED_INT shm_menu_colour_pick;
extern UNSIGNED_INT shm_source_fd;
extern UNSIGNED_INT shm_source_dst;
extern UNSIGNED_INT shm_source_src;
extern INT shm_sprite_width;
extern INT shm_sprite_height;
extern INT shm_palette_count;
extern struct JOYSTICK shm_joystick;
/* The scratch text buffer every screen builds its lines in, 200h bytes,
the length copied to and from the shared block's message. */
extern unsigned char shm_scratch[512];
/* The campaign's difficulty. */
extern INT shm_difficulty;
/* The campaign day. */
extern UNSIGNED_INT asm_day;
/* The campaign clock, in minutes. */
extern UNSIGNED_INT shm_clock_minutes;
extern struct CAMPAIGN shm_campaign;
extern UNSIGNED_INT shm_seed;
extern INT shm_options;
extern INT shm_cga;
/* The sixteen city records, 34 bytes each. */
extern struct CITY shm_cities[16];
extern UNSIGNED_INT shm_menu_tick;
extern INT shm_suspect_count;
/* The case log, 80h records of 14 bytes, crossing between modules as one
save section. */
extern struct LOG_ENTRY shm_log[128];
/* The face the menu draws beside itself. */
extern INT shm_menu_face;
/* Which clue source the watch is about, 1 an electronic wiretap and 0 a
 * clandestine photo, which also picks the wire over the box on the tracer's
 * title panel. */
extern INT shm_wire_clue_source;
/* The crime event list, 64 records of 2ch bytes from CRIMEn.DTA, each one step
 * of the crime; shm_crime_event_count says how many the case fills. */
extern struct CRIME_EVENT shm_crime_events[64];
/* Where the next log record goes, and so how many there are. */
extern INT shm_log_count;
extern INT shm_menu_first_line;
/* How many of the building records in shm_buildings have been handed out. */
extern INT shm_building_count;
/* The case's clock in half-days, -1 just before a case is ticked in; an event
 * that comes due is stamped with it in CRIME_EVENT.happen_tick. It crosses
 * modules as COMM()->case_tick. */
extern INT shm_case_tick;
extern INT shm_frame_ticks;
/* How wide the picture just loaded is. */
extern UNSIGNED_INT asm_loaded_width;
extern rt_addr shm_source_at;
/* How tall the picture just loaded is. */
extern UNSIGNED_INT asm_loaded_height;
extern INT shm_case_city_1;
extern UNSIGNED_INT shm_case_city_2;
extern UNSIGNED_INT shm_anim_more;
extern UNSIGNED_INT shm_pan_playing;
extern unsigned char shm_anim_palette[774];
/* The minute the day stamp shows. */
extern UNSIGNED_INT asm_stamp_minute;
extern UNSIGNED_INT shm_menu_no_pick;
/* What was last on screen, so a menu knows whether to clear it first. */
extern INT asm_last_screen;
extern struct CAMPAIGN shm_probed_campaign;
extern INT shm_menu_items;
extern UNSIGNED_INT shm_anim_segment;
/* The campaign hour. */
extern INT asm_hour;
extern UNSIGNED_INT shm_seq_ticks;
/* Set once the contact in this city has introduced himself. */
extern UNSIGNED_INT asm_contact_met;
/* How many of the crime event list's 64 records the case fills. */
extern INT shm_crime_event_count;
extern UNSIGNED_INT shm_case_seed;
/* The method nibble of the clue being shown. */
extern UNSIGNED_INT shm_clue_method;
extern UNSIGNED_INT shm_menu_relayout;
/* The case's mission, which keys its clues.txt and text.dta blocks. */
extern INT shm_mission;
extern UNSIGNED_INT shm_menu_colour_bar;
/* An organisation chosen at case start, at least 8 from the CIA and within 8
 * of the MasterMind on the grid, whose alert rises when the player visits a
 * CIA office holding a double agent. */
extern INT shm_case_org_1;
extern INT shm_menu_text_width;
extern UNSIGNED_INT shm_case_org_2;
/* How many entries of asm_menu_choices the menu being built
has filled. */
extern INT asm_menu_choice_count;
/* The 116 sprite handles cut out of facesf.pic and faces.pic: two banks of
 * forty face parts, then the plane by heading and its shadow, clue sources,
 * bodies, paperclip, folder edge and typewriter head. */
extern UNSIGNED_INT shm_faces_sprites[116];
/* How alert the organisations are to the player, raised by
c_raise_alert, decaying each day, cut by flying out and cleared when one strikes
back. */
extern INT shm_global_alert_level;
extern UNSIGNED_INT shm_slots_filled;
/* AL of the four-word register block the INT 10h calls read and write. */
extern union REGS shm_regs;
extern UNSIGNED_INT shm_anim_error;
/* One bit per city whose CIA office holds a double agent: the prisoner
exchange sets bits, accusing a double agent clears them, and case start keeps
Washington's clear. An organisation's alert in such a city is 16 higher. */
extern UNSIGNED_INT shm_double_agent_cities;
/* How many crime roles the case has: the crime file's participant
count plus four red herrings a difficulty level. */
extern INT shm_crime_role_count;
extern UNSIGNED_INT shm_menu_marked;
/* The case's crime roles, 32 records of 30h bytes: the participant records of
 * CRIME*.DTA, then the red herrings the difficulty appends. One save
 * section. */
extern struct CRIME_ROLE shm_crime_roles[32];
extern UNSIGNED_INT shm_seq_done;
extern rt_addr shm_refill;
extern UNSIGNED_INT asm_DAT_2206_9daa;
extern unsigned char shm_archive_buffer[512];
/* Where a notice is drawn, across. */
extern UNSIGNED_INT shm_menu_face_x;
extern UNSIGNED_INT shm_menu_draw_only;
extern UNSIGNED_INT shm_skills;
/* Where a notice is drawn, down. */
extern UNSIGNED_INT shm_menu_face_y;
/* The sixteen organisation records, 36 bytes each. */
extern struct ORG_STATE shm_orgs[16];
extern UNSIGNED_INT shm_anim_sprites[250];
/* Set once a case is ready to break. */
extern UNSIGNED_INT asm_case_ready;
extern rt_addr shm_anim_name;
/* What runs next, handed on when the campaign loop ends: 0 while the campaign
goes on, and -1 for nobody, so the closing sequence plays. */
extern INT shm_finished;
extern unsigned char shm_menu_shortcut[32];
extern UNSIGNED_INT shm_menu_pick;
/* The 72 bytes CRIMEn.DTA ends with, read after the crime events: four
CRIME_ENTRY records, saved and restored with the case. */
extern struct CRIME_ENTRY shm_crime_block[4];
extern UNSIGNED_INT shm_menu_right;
extern unsigned char shm_substitute_tail[256];
/* The case's role scan states, one per crime role: when clue visibility may
 * start building against it, and how much has built. One save section, six
 * bytes a role. */
extern struct ROLE_SCAN_STATE shm_role_scan_states[32];
extern unsigned char shm_graphics_letter;
extern UNSIGNED_INT shm_menu_bottom;
extern UNSIGNED_INT shm_seq_stop_asked;
/* The handover GAME last made and has come back from, whose results are still
to be dealt with, or NONE_NOTHING_PENDING; CAMPSTAT.H names the values. */
extern UNSIGNED_INT asm_campaign_state;
/* Which city the player is in. */
extern INT shm_case_city;
/* One counter per city and one per organisation, of the names the player has been
told there, shown as bars in the activity report. Saved as one section. */
extern struct ACTIVITY shm_activity;
extern UNSIGNED_INT shm_orgs_known;
/* Set while the clock runs on by itself: the wait after the opening briefing,
and the hotel's wait. */
extern UNSIGNED_INT asm_auto_waiting;
extern INT shm_slot_pick;
extern UNSIGNED_INT shm_case_spare_2;
extern unsigned char shm_anim_row_2[320];
/* What each line of the menu on screen stands for, -1 closing it: a place in
the city, an organisation, a clue or a suspect, by which menu filled it. */
extern UNSIGNED_INT asm_menu_choices[32];
extern UNSIGNED_INT shm_anim_block_kind;
extern INT shm_seq_vars[51];
/* Which organisation the player is dealing with. */
extern UNSIGNED_INT shm_case_org;
#endif

#endif /* GAME_H */
