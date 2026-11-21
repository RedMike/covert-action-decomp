/* BUG_PORT.H -- the data group, as the portable build reads it.
 *
 * BUG.H includes it under PORT_MODERN; the DOS build never stages it.
 */
#ifndef BUG_PORT_H
#define BUG_PORT_H

#include "PORTING.H"
#include "COMM.H"
#include "STRUCTS.H"
#include "STRUCTS.H"

#ifndef PORT_MODERN
extern unsigned char run_banner_pad[8];
extern unsigned char run_banner[58];
extern UNSIGNED_INT drv_DAT_1a63_0042;
extern UNSIGNED_INT drv_DAT_1a63_0044;
extern unsigned char asm_block_0046[38];
#endif
extern unsigned char dat_str_env_sve[8];
extern unsigned char dat_str_camera_pic[11];
extern unsigned char dat_str_board_pic[10];
extern unsigned char dat_str_env_sve_2[8];
#ifndef PORT_MODERN
extern unsigned char asm_block_0091;
#endif
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
extern struct RASTPORT dat_picture_page_port;
extern struct RASTPORT *shd_picture_page;
extern struct RASTPORT dat_map_page_port;
extern struct RASTPORT *shd_map_page;
#ifndef PORT_MODERN
extern unsigned char asm_block_155c[32];
#endif
extern struct COLOUR_MAP shd_colours_screen;
extern struct COLOUR_MAP shd_colours_screen_2;
/* The colour map set for both halves of the call where nothing is being
remapped. */
extern struct COLOUR_MAP dat_colours_plain;
extern struct COLOUR_MAP shd_colours_paper;
extern struct COLOUR_MAP shd_colours_face;
extern UNSIGNED_INT shd_pan_disk;
extern struct RASTPORT dat_chip_page_port;
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
#ifndef PORT_MODERN
extern unsigned char asm_block_1769;
#endif
extern unsigned char dat_str_tied[10];
extern unsigned char dat_str_registered[16];
extern unsigned char dat_str_acquired_by[14];
extern unsigned char dat_str_delivered[15];
extern unsigned char dat_str_requested[16];
extern unsigned char dat_str_tied_2[10];
extern unsigned char dat_str_registered_2[16];
extern unsigned char dat_str_traced[12];
extern unsigned char dat_str_smuggled_into[16];
extern unsigned char dat_str_requested_2[16];
extern unsigned char dat_str_tied_3[10];
extern unsigned char dat_str_rented_by[12];
extern unsigned char dat_str_frequented_by[16];
extern unsigned char dat_str_is_in[8];
extern unsigned char dat_str_linked[12];
extern unsigned char dat_str_purchased_by[15];
extern unsigned char dat_str_purchased_by_2[15];
extern unsigned char dat_str_traced_2[12];
extern unsigned char dat_str_purchased[15];
extern unsigned char dat_str_linked_2[12];
extern unsigned char dat_str_received_by[14];
extern unsigned char dat_str_signed_by[16];
extern unsigned char dat_str_traced_3[12];
extern unsigned char dat_str_sent[10];
extern unsigned char dat_str_refers[12];
extern unsigned char dat_str_withdrawn_by[15];
extern unsigned char dat_str_withdrawn_by_2[15];
extern unsigned char dat_str_paid_by[10];
extern unsigned char dat_str_transaction[17];
extern unsigned char dat_str_requested_3[16];
extern unsigned char dat_str_withdrawn_by_3[15];
extern unsigned char dat_str_withdrawn_by_4[15];
extern unsigned char dat_str_paid_by_2[10];
extern unsigned char dat_str_transaction_2[17];
extern unsigned char dat_str_requested_4[16];
extern unsigned char dat_str_assigned[14];
extern unsigned char dat_str_assigned_2[14];
extern unsigned char dat_str_assigned_3[14];
extern unsigned char dat_str_used[10];
extern unsigned char dat_str_assigned_4[14];
extern unsigned char dat_str_jan[4];
extern unsigned char dat_str_feb[4];
extern unsigned char dat_str_mar[4];
extern unsigned char dat_str_apr[4];
extern unsigned char dat_str_may[4];
extern unsigned char dat_str_jun[4];
extern unsigned char dat_str_jul[4];
extern unsigned char dat_str_aug[4];
extern unsigned char dat_str_sep[4];
extern unsigned char dat_str_oct[4];
extern unsigned char dat_str_nov[4];
extern unsigned char dat_str_dec[4];
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
#ifndef PORT_MODERN
extern unsigned char asm_block_1a90[16];
#endif
extern char shd_scan_counts[32];
extern unsigned char *shd_month_names[12];
#ifndef PORT_MODERN
extern unsigned char asm_block_1ad8[2];
#endif
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
extern unsigned char dat_str_recruit[8];
extern unsigned char dat_str_operative[10];
extern unsigned char dat_str_technician[11];
extern unsigned char dat_str_agent[6];
extern unsigned char dat_str_organizer[10];
extern unsigned char dat_str_special_agent[14];
extern unsigned char dat_str_group_leader[13];
extern unsigned char dat_str_mastermind[11];
extern unsigned char dat_str_car[4];
extern unsigned char dat_str_wpn[4];
extern unsigned char dat_str_adr[4];
extern unsigned char dat_str_tkt[4];
extern unsigned char dat_str_msg[4];
extern unsigned char dat_str_dollar_1[2];
extern unsigned char dat_str_dollar_2[2];
extern unsigned char dat_str_fce[4];
extern unsigned char dat_str_ford_escort[14];
extern unsigned char dat_str_chevy_nova[13];
extern unsigned char dat_str_toyota_tercel[16];
extern unsigned char dat_str_vw_golf[10];
extern unsigned char dat_str_mazda_rx7[12];
extern unsigned char dat_str_honda_civic[14];
extern unsigned char dat_str_peugot[9];
extern unsigned char dat_str_chrysler[11];
extern unsigned char dat_str_walther_ppk[14];
extern unsigned char dat_str_smith_wesson_9mm[19];
extern unsigned char dat_str_berreta_m92s[15];
extern unsigned char dat_str_browning_9mm[15];
extern unsigned char dat_str_hechler_koch_vp[18];
extern unsigned char dat_str_luger_9mm[12];
extern unsigned char dat_str_colt_45[10];
extern unsigned char dat_str_357_magnum[13];
extern unsigned char dat_str_rue_laverne[13];
extern unsigned char dat_str_hochstrasse[13];
extern unsigned char dat_str_main_st[10];
extern unsigned char dat_str_webley_ct[12];
extern unsigned char dat_str_holmley_park[14];
extern unsigned char dat_str_obensgrabbe[13];
extern unsigned char dat_str_la_paz_blvd[14];
extern unsigned char dat_str_north_ave[12];
extern unsigned char dat_str_panam[8];
extern unsigned char dat_str_united[9];
extern unsigned char dat_str_sabena[9];
extern unsigned char dat_str_lufthansa[12];
extern unsigned char dat_str_el_al[8];
extern unsigned char dat_str_klm[6];
extern unsigned char dat_str_swissair[11];
extern unsigned char dat_str_boac[7];
extern unsigned char dat_str_w_union[10];
extern unsigned char dat_str_rca[6];
extern unsigned char dat_str_telex[8];
extern unsigned char dat_str_amtel[8];
extern unsigned char dat_str_intertel[11];
extern unsigned char dat_str_satcomm[10];
extern unsigned char dat_str_teltron[10];
extern unsigned char dat_str_comlink[10];
extern unsigned char dat_str_dollar_3[2];
extern unsigned char dat_str_dollar_4[2];
extern unsigned char dat_str_dollar_5[2];
extern unsigned char dat_str_dollar_6[2];
extern unsigned char dat_str_dollar_7[2];
extern unsigned char dat_str_dollar_8[2];
extern unsigned char dat_str_dollar_9[2];
extern unsigned char dat_str_dollar_10[2];
extern unsigned char dat_str_dollar_11[2];
extern unsigned char dat_str_dollar_12[2];
extern unsigned char dat_str_dollar_13[2];
extern unsigned char dat_str_dollar_14[2];
extern unsigned char dat_str_dollar_15[2];
extern unsigned char dat_str_dollar_16[2];
extern unsigned char dat_str_dollar_17[2];
extern unsigned char dat_str_dollar_18[2];
extern unsigned char dat_str_swiss_passport[17];
extern unsigned char dat_str_interpol_id[13];
extern unsigned char dat_str_bahamian_passport[20];
extern unsigned char dat_str_gold_card[12];
extern unsigned char dat_str_swedish_passport[19];
extern unsigned char dat_str_green_card[13];
extern unsigned char dat_str_vista_card[13];
extern unsigned char dat_str_liberian_passport[21];
extern rt_addr shd_clue_kinds[80];
extern unsigned char dat_str_clandestine_photo[18];
extern unsigned char dat_str_electronic_wiretap[19];
extern unsigned char dat_str_covert_surveillance[20];
extern unsigned char dat_str_file_record_search[19];
extern unsigned char dat_str_local_informant[16];
extern unsigned char dat_str_interpol_data_base[19];
extern unsigned char dat_str_local_authorities[18];
extern unsigned char shd_str_clue[5];
extern unsigned char shd_str_source_2[10];
extern unsigned char shd_str_slash_source[2];
extern unsigned char shd_str_newline_9[2];
extern unsigned char shd_str_method_stop[11];
extern unsigned char shd_str_related_2[16];
extern unsigned char shd_str_newline_10[2];
extern unsigned char shd_str_none[8];
#ifndef PORT_MODERN
extern unsigned char asm_block_207d;
#endif
extern unsigned char *shd_clue_source[7];
extern unsigned char dat_msg_key[5];
extern unsigned char dat_msg_name[6];
extern unsigned char dat_msg_org[5];
extern unsigned char dat_msg_city[6];
extern unsigned char dat_msg_role[6];
extern unsigned char shd_key_clue[7];
extern unsigned char shd_str_clues_txt[10];
#ifndef PORT_MODERN
extern unsigned char asm_block_20b9;
#endif
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
#ifndef PORT_MODERN
extern unsigned char asm_block_21eb;
#endif
extern unsigned char dat_str_victim[8];
extern unsigned char dat_msg_sndorg[8];
extern unsigned char dat_msg_rcvorg[8];
extern unsigned char dat_msg_sndloc[8];
extern unsigned char dat_msg_rcvloc[8];
extern unsigned char dat_msg_hlporg[8];
extern unsigned char dat_str_object[8];
/* The first of nine 26-byte value buffers in a row, one per $-key the message
substitution fills in; shd_subst_values[1] to [6] point at buffers 2 to 7,
and [0] at this one. */
extern unsigned char asm_subst_buffer_0[26];
#ifndef PORT_MODERN
extern unsigned char asm_subst_buffer_1[26];
#endif
extern unsigned char asm_subst_buffer_2[26];
extern unsigned char asm_subst_buffer_3[26];
extern unsigned char asm_subst_buffer_4[26];
extern unsigned char asm_subst_buffer_5[26];
extern unsigned char asm_subst_buffer_6[26];
extern unsigned char asm_subst_buffer_7[26];
#ifndef PORT_MODERN
extern unsigned char asm_subst_buffer_8[26];
#endif
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
extern unsigned char dat_str_georgina[9];
extern unsigned char dat_str_arkada[7];
extern unsigned char dat_str_yuria[6];
extern unsigned char dat_str_anatola[8];
extern unsigned char dat_str_andra[6];
extern unsigned char dat_str_nikola[7];
extern unsigned char dat_str_viktora[8];
extern unsigned char dat_str_ivana[6];
extern unsigned char dat_str_natasha[8];
extern unsigned char dat_str_svetlana[9];
extern unsigned char dat_str_anna[5];
extern unsigned char dat_str_ludmilla[9];
extern unsigned char dat_str_lexandra[9];
extern unsigned char dat_str_katerina[9];
extern unsigned char dat_str_olga[5];
extern unsigned char dat_str_nadia[6];
extern unsigned char dat_str_leona[6];
extern unsigned char dat_str_pat[4];
extern unsigned char dat_str_carla[6];
extern unsigned char dat_str_bobbie[7];
extern unsigned char dat_str_jenny[6];
extern unsigned char dat_str_frieda[7];
extern unsigned char dat_str_alice[6];
extern unsigned char dat_str_rose[5];
extern unsigned char dat_str_deirdre[8];
extern unsigned char dat_str_martha[7];
extern unsigned char dat_str_lisa[5];
extern unsigned char dat_str_erica[6];
extern unsigned char dat_str_liz[4];
extern unsigned char dat_str_emma[5];
extern unsigned char dat_str_isadora[8];
extern unsigned char dat_str_jane[5];
extern unsigned char dat_str_omara[6];
extern unsigned char dat_str_alicia[7];
extern unsigned char dat_str_hasana[7];
extern unsigned char dat_str_leila[6];
extern unsigned char dat_str_yasria[7];
extern unsigned char dat_str_ailha[6];
extern unsigned char dat_str_yousfa[7];
extern unsigned char dat_str_aziza[6];
extern unsigned char dat_str_fatima[7];
extern unsigned char dat_str_benazir[8];
extern unsigned char dat_str_ouida[6];
extern unsigned char dat_str_selima[7];
extern unsigned char dat_str_ismaila[8];
extern unsigned char dat_str_persis[7];
extern unsigned char dat_str_haurouna[9];
extern unsigned char dat_str_zara[5];
extern unsigned char dat_str_carlotta[9];
extern unsigned char dat_str_josita[7];
extern unsigned char dat_str_miguela[8];
extern unsigned char dat_str_ramona[7];
extern unsigned char dat_str_luisa[6];
extern unsigned char dat_str_julia[6];
extern unsigned char dat_str_juanita[8];
extern unsigned char dat_str_raquel[7];
extern unsigned char dat_str_isabel[7];
extern unsigned char dat_str_maria[6];
extern unsigned char dat_str_elena[6];
extern unsigned char dat_str_linda[6];
extern unsigned char dat_str_carmen[7];
extern unsigned char dat_str_agnes[6];
extern unsigned char dat_str_celeste[8];
extern unsigned char dat_str_phyllis[8];
extern unsigned char dat_str_georgi[7];
extern unsigned char dat_str_arkady[7];
extern unsigned char dat_str_yuri[5];
extern unsigned char dat_str_anatol[7];
extern unsigned char dat_str_andrei[7];
extern unsigned char dat_str_nikita[7];
extern unsigned char dat_str_viktor[7];
extern unsigned char dat_str_ivan[5];
extern unsigned char dat_str_boris[6];
extern unsigned char dat_str_nikolai[8];
extern unsigned char dat_str_grigori[8];
extern unsigned char dat_str_pavel[6];
extern unsigned char dat_str_mischa[7];
extern unsigned char dat_str_petrov[7];
extern unsigned char dat_str_vladimir[9];
extern unsigned char dat_str_mikhail[8];
extern unsigned char dat_str_leon[5];
extern unsigned char dat_str_ian[4];
extern unsigned char dat_str_carl[5];
extern unsigned char dat_str_bob[4];
extern unsigned char dat_str_jim[4];
extern unsigned char dat_str_fred[5];
extern unsigned char dat_str_alan[5];
extern unsigned char dat_str_ralph[6];
extern unsigned char dat_str_antoine[8];
extern unsigned char dat_str_heinrich[9];
extern unsigned char dat_str_eric[5];
extern unsigned char dat_str_gordon[7];
extern unsigned char dat_str_david[6];
extern unsigned char dat_str_pierre[7];
extern unsigned char dat_str_claude[7];
extern unsigned char dat_str_gerard[7];
extern unsigned char dat_str_omar[5];
extern unsigned char dat_str_ali[4];
extern unsigned char dat_str_hasan[6];
extern unsigned char dat_str_abdul[6];
extern unsigned char dat_str_yasr[5];
extern unsigned char dat_str_abu[4];
extern unsigned char dat_str_yousf[6];
extern unsigned char dat_str_saadi[6];
extern unsigned char dat_str_achmet[7];
extern unsigned char dat_str_ibrahim[8];
extern unsigned char dat_str_selim[6];
extern unsigned char dat_str_ismail[7];
extern unsigned char dat_str_mahmoud[8];
extern unsigned char dat_str_haround[8];
extern unsigned char dat_str_suleiman[9];
extern unsigned char dat_str_yezid[6];
extern unsigned char dat_str_carlos[7];
extern unsigned char dat_str_jose[5];
extern unsigned char dat_str_miguel[7];
extern unsigned char dat_str_ramon[6];
extern unsigned char dat_str_luis[5];
extern unsigned char dat_str_julio[6];
extern unsigned char dat_str_juan[5];
extern unsigned char dat_str_pedro[6];
extern unsigned char dat_str_enrique[8];
extern unsigned char dat_str_eduardo[8];
extern unsigned char dat_str_arturo[7];
extern unsigned char dat_str_jorge[6];
extern unsigned char dat_str_manuel[7];
extern unsigned char dat_str_hector[7];
extern unsigned char dat_str_franco[7];
extern unsigned char dat_str_jaime[6];
extern unsigned char dat_str_katkov[7];
extern unsigned char dat_str_gorny[6];
extern unsigned char dat_str_gromyko[8];
extern unsigned char dat_str_kormarov[9];
extern unsigned char dat_str_molotov[8];
extern unsigned char dat_str_charyk[7];
extern unsigned char dat_str_markov[7];
extern unsigned char dat_str_filatov[8];
extern unsigned char dat_str_badenov[8];
extern unsigned char dat_str_chekhov[8];
extern unsigned char dat_str_gogol[6];
extern unsigned char dat_str_zhukov[7];
extern unsigned char dat_str_nevsky[7];
extern unsigned char dat_str_kemidov[8];
extern unsigned char dat_str_dubrovnik[10];
extern unsigned char dat_str_kerensky[9];
extern unsigned char dat_str_lorenz[7];
extern unsigned char dat_str_koch[5];
extern unsigned char dat_str_baader[7];
extern unsigned char dat_str_brown[6];
extern unsigned char dat_str_jones[6];
extern unsigned char dat_str_bloom[6];
extern unsigned char dat_str_cahill[7];
extern unsigned char dat_str_grivas[7];
extern unsigned char dat_str_cook[5];
extern unsigned char dat_str_muller[7];
extern unsigned char dat_str_hansen[7];
extern unsigned char dat_str_olsen[6];
extern unsigned char dat_str_merrick[8];
extern unsigned char dat_str_ballard[8];
extern unsigned char dat_str_verne[6];
extern unsigned char dat_str_konrad[7];
extern unsigned char dat_str_abbas[6];
extern unsigned char dat_str_said[5];
extern unsigned char dat_str_daoud[6];
extern unsigned char dat_str_moussa[7];
extern unsigned char dat_str_nidal[6];
extern unsigned char dat_str_khaled[7];
extern unsigned char dat_str_hammid[7];
extern unsigned char dat_str_afafat[7];
extern unsigned char dat_str_agha[5];
extern unsigned char dat_str_murad[6];
extern unsigned char dat_str_akbar[6];
extern unsigned char dat_str_hosayn[7];
extern unsigned char dat_str_raisuli[8];
extern unsigned char dat_str_musafir[8];
extern unsigned char dat_str_nasr[5];
extern unsigned char dat_str_rashid[7];
extern unsigned char dat_str_munoz[6];
extern unsigned char dat_str_diaz[5];
extern unsigned char dat_str_munoz_2[6];
extern unsigned char dat_str_perez[6];
extern unsigned char dat_str_ramirez[8];
extern unsigned char dat_str_alvarez[8];
extern unsigned char dat_str_garcia[7];
extern unsigned char dat_str_lopez[6];
extern unsigned char dat_str_santos[7];
extern unsigned char dat_str_diego[6];
extern unsigned char dat_str_cordoba[8];
extern unsigned char dat_str_valdez[7];
extern unsigned char dat_str_santiago[9];
extern unsigned char dat_str_enriquez[9];
extern unsigned char dat_str_sanchez[8];
extern unsigned char dat_str_delarosa[9];
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
#ifndef PORT_MODERN
extern unsigned char asm_block_2b49;
#endif
/* The clock string in the screen header's corner, '00:00:00', its digits
 * written in place. */
extern unsigned char shd_clock_text[9];
#ifndef PORT_MODERN
extern unsigned char asm_block_2b53;
#endif
extern unsigned char shd_str_incoming_msg[13];
#ifndef PORT_MODERN
extern unsigned char asm_block_2b61;
#endif
extern unsigned char shd_list_printout[588];
extern unsigned char shd_str_one_moment_please[21];
extern unsigned char shd_str_sure_want_quit_no_2[41];
#ifndef PORT_MODERN
extern unsigned char dat_str_pani[5];
extern unsigned char asm_block_2df1;
#endif
/* Which city's picture is on screen, so an unchanged one is not reloaded; -1
once an animation has been started over it. */
extern UNSIGNED_INT shd_city_on_screen;
extern INT shd_drive;
extern UNSIGNED_INT shm_pan_width;
#ifndef PORT_MODERN
extern unsigned char asm_block_2df8[2];
#endif
extern struct PALETTE shd_palette_menu;
extern struct PALETTE shd_palette_face;
extern unsigned char shd_str_ok[3];
extern unsigned char shd_str_briefing_pan[13];
extern unsigned char shd_str_bld[4];
#ifndef PORT_MODERN
extern unsigned char asm_block_2e31;
#endif
extern UNSIGNED_INT shm_pan_building;
extern unsigned char shd_str_animation_pan[14];
extern UNSIGNED_INT shd_joystick_dirs[9];
extern unsigned char shd_str_env_sve_put[8];
extern unsigned char shd_str_env_sve[8];
extern unsigned char shd_str_file_error[13];
extern unsigned char shd_str_newline_12[3];
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
extern unsigned char drv_DAT_1a63_2f0a;
extern unsigned char drv_DAT_1a63_2f0b;
extern UNSIGNED_INT drv_DAT_1a63_2f0c;
extern UNSIGNED_INT drv_DAT_1a63_2f0e;
extern UNSIGNED_INT drv_DAT_1a63_2f10;
extern UNSIGNED_INT drv_DAT_1a63_2f12;
extern UNSIGNED_INT drv_DAT_1a63_2f14;
extern UNSIGNED_INT drv_DAT_1a63_2f16;
extern UNSIGNED_INT drv_DAT_1a63_2f18;
extern UNSIGNED_INT drv_DAT_1a63_2f1a;
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
extern unsigned char asm_block_3036;
extern UNSIGNED_INT drv_DAT_1a63_3037;
extern UNSIGNED_INT drv_DAT_1a63_3039;
extern UNSIGNED_INT drv_DAT_1a63_303b;
extern UNSIGNED_INT drv_DAT_1a63_303d;
extern UNSIGNED_INT drv_DAT_1a63_303f;
extern unsigned char asm_block_3041[436];
extern UNSIGNED_INT drv_DAT_1a63_31f5;
extern UNSIGNED_INT drv_DAT_1a63_31f7;
extern unsigned char asm_block_31f9[438];
extern UNSIGNED_INT drv_DAT_1a63_33af;
extern UNSIGNED_INT drv_DAT_1a63_33b1;
extern UNSIGNED_INT drv_DAT_1a63_33b3;
extern UNSIGNED_INT drv_DAT_1a63_33b5;
extern UNSIGNED_INT drv_DAT_1a63_33b7;
extern UNSIGNED_INT drv_DAT_1a63_33b9;
extern unsigned char asm_block_33bb;
extern unsigned char drv_DAT_1a63_33bc;
extern UNSIGNED_INT drv_DAT_1a63_33bd;
extern UNSIGNED_INT drv_DAT_1a63_33bf;
extern UNSIGNED_INT drv_DAT_1a63_33c1;
extern UNSIGNED_INT drv_DAT_1a63_33c3;
extern UNSIGNED_INT drv_DAT_1a63_33c5;
extern UNSIGNED_INT drv_DAT_1a63_33c7;
extern unsigned char asm_block_33c9;
extern UNSIGNED_INT drv_DAT_1a63_33ca;
extern UNSIGNED_INT drv_DAT_1a63_33cc;
extern UNSIGNED_INT drv_DAT_1a63_33ce;
extern UNSIGNED_INT drv_DAT_1a63_33d0;
extern UNSIGNED_INT drv_DAT_1a63_33d2;
extern UNSIGNED_INT drv_DAT_1a63_33d4;
extern UNSIGNED_INT drv_DAT_1a63_33d6;
extern UNSIGNED_INT drv_DAT_1a63_33d8;
extern UNSIGNED_INT drv_DAT_1a63_33da;
extern UNSIGNED_INT drv_DAT_1a63_33dc;
extern UNSIGNED_INT drv_DAT_1a63_33de;
extern UNSIGNED_INT drv_DAT_1a63_33e0;
extern UNSIGNED_INT run_crt0_33ea;
extern UNSIGNED_INT run_crt0_33ec;
extern UNSIGNED_INT run_crt0_33ee;
extern unsigned char asm_block_33f0[73];
extern unsigned char dat_str_3_c_file_info[14];
extern unsigned char asm_block_344b[8];
extern unsigned char asm_block_3457[2];
extern unsigned char asm_block_345d;
extern unsigned char asm_block_345f;
extern unsigned char run_crt0dat_3463;
extern unsigned char asm_block_3464;
extern unsigned char run_crt0dat_3465;
extern unsigned char run_crt0dat_3466;
extern unsigned char run_crt0dat_3467;
extern unsigned char run_crt0dat_3468;
extern unsigned char asm_block_3469[13];
extern unsigned char run_crt0dat_3480;
extern unsigned char run_crt0dat_3481;
extern unsigned char asm_block_3482[8];
extern UNSIGNED_INT STKHQQ;
extern UNSIGNED_INT run_stdargv_348e;
extern unsigned char asm_block_3490[24];
extern unsigned char asm_block_34aa[6];
extern unsigned char run__file_34b0;
extern unsigned char asm_block_34b1;
extern UNSIGNED_INT run__file_34b2;
extern UNSIGNED_INT run__file_34b4;
extern UNSIGNED_INT run__file_34b6;
extern unsigned char run__file_34b8;
extern unsigned char run__file_34b9;
extern unsigned char asm_block_34ba[264];
extern UNSIGNED_INT run_input_35c4;
extern unsigned char asm_block_35c6;
extern unsigned char run_txtmode_35c7;
extern UNSIGNED_INT run_nmalloc_35ca;
extern unsigned char asm_block_35cc[2];
extern UNSIGNED_INT run_nmalloc_35ce;
extern unsigned char asm_block_35d0[18];
extern UNSIGNED_INT run_cmiscdat_35e2;
extern unsigned char asm_block_35e4[330];
extern unsigned char dat_str_pst[4];
extern unsigned char run_timeset_3732;
extern unsigned char asm_block_3733[3];
extern UNSIGNED_INT run_timeset_3738;
extern unsigned char run_month_names[38];
extern UNSIGNED_INT run_rand_377c;
extern UNSIGNED_INT run_rand_377e;
extern unsigned char run_err_error_0[8];
extern unsigned char asm_block_3788;
extern unsigned char run_err_no_such_file_directory[27];
extern unsigned char asm_block_37a4[3];
extern unsigned char run_err_arg_list_too_long[18];
extern unsigned char run_err_exec_format_error[18];
extern unsigned char run_err_bad_file_number[17];
extern unsigned char asm_block_37dc;
extern unsigned char run_err_not_enough_core[16];
extern unsigned char run_err_permission_denied[19];
extern unsigned char asm_block_3800[2];
extern unsigned char run_err_file_exists[12];
extern unsigned char run_err_cross_device_link[18];
extern unsigned char asm_block_3820[3];
extern unsigned char run_err_invalid_argument[17];
extern unsigned char asm_block_3834;
extern unsigned char run_err_too_many_open_files[23];
extern unsigned char run_err_no_space_left_device[24];
extern unsigned char asm_block_3864[4];
extern unsigned char run_err_math_argument[14];
extern unsigned char run_err_result_too_large[18];
extern unsigned char run_err_resource_deadlock_would[30];
extern unsigned char run_err_unknown_error[14];
extern unsigned char asm_block_38b4[37];
extern unsigned char dat_str_8_8_8_8[37];
extern UNSIGNED_INT run_syserr_38fe;
extern unsigned char asm_block_3902[2];
extern UNSIGNED_INT run_crt0dat_3906;
extern UNSIGNED_LONG run_crt0dat_3908;
extern UNSIGNED_LONG run_crt0dat_390c;
extern unsigned char asm_seg_xp[2];
extern unsigned char asm_const_pair[2];
extern unsigned char run_nmsg_marker[8];
extern UNSIGNED_INT run_crt0msg_391c;
extern unsigned char run_crt0msg_391e[26];
extern unsigned char asm_block_3938[2];
extern unsigned char run_msg_r6003[31];
extern unsigned char asm_block_3959[2];
extern unsigned char run_msg_r6009[44];
extern unsigned char asm_block_3987[7];
extern unsigned char run_msg_runtime_error[16];
extern unsigned char asm_block_399e[2];
extern unsigned char run_msg_r6002[37];
extern unsigned char asm_block_39c5[2];
extern unsigned char run_msg_r6001[35];
extern unsigned char asm_block_39ea[4];
extern unsigned char asm_block_39ee;
extern unsigned char asm_block_39ef;
extern unsigned char asm_block_39f0[14];
#endif
extern unsigned char asm_number_digits[16];
extern unsigned char shm_clue_digits[32];
/* The text.dta tag for one message, nine bytes: a copy of a template such as
 * '*MSG0000', to whose four digits the numbers are added. */
extern unsigned char shm_message_key[9];
#ifndef PORT_MODERN
extern unsigned char asm_block_3a37[49];
#endif
/* The screen's background animation, armed when a screen is entered, started
 * each time a menu opens and stepped while it waits. */
extern struct SEQ_BLOCK shm_active_pan;
#ifndef PORT_MODERN
extern unsigned char asm_block_3a76[16];
#endif
extern INT shm_menu_line_start[32];
extern UNSIGNED_INT shm_menu_colour_plain;
extern UNSIGNED_INT shm_menu_colour_item;
extern INT shm_menu_lines;
extern UNSIGNED_INT shm_menu_colour_pick;
extern unsigned char FAR *shm_save_block;
#ifndef PORT_MODERN
extern unsigned char asm_block_3ad2[16];
#endif
extern UNSIGNED_INT shm_save_offset;
extern INT shm_save_fd;
#ifndef PORT_MODERN
extern unsigned char asm_block_3ae6[16];
#endif
extern UNSIGNED_INT shm_source_fd;
extern UNSIGNED_INT shm_source_dst;
extern UNSIGNED_INT shm_source_src;
#ifndef PORT_MODERN
extern UNSIGNED_INT drv_DAT_1a63_3afc;
extern unsigned char drv_DAT_1a63_3afe;
extern UNSIGNED_INT drv_DAT_1a63_3aff;
extern unsigned char drv_DAT_1a63_3b01;
extern unsigned char asm_block_3b02[6138];
#endif
extern UNSIGNED_INT shm_sprite_width;
extern INT shm_sprite_height;
extern UNSIGNED_INT shm_palette_count;
#ifndef PORT_MODERN
extern UNSIGNED_INT drv_DAT_1a63_5302;
extern UNSIGNED_INT drv_DAT_1a63_5304;
extern unsigned char drv_DAT_1a63_5306;
extern unsigned char drv_DAT_1a63_5307;
extern unsigned char drv_DAT_1a63_5308;
extern unsigned char drv_DAT_1a63_5309;
extern UNSIGNED_INT drv_DAT_1a63_530a;
extern UNSIGNED_INT drv_DAT_1a63_530c;
extern UNSIGNED_INT drv_DAT_1a63_530e;
extern unsigned char drv_DAT_1a63_5310;
extern unsigned char drv_DAT_1a63_5311;
extern UNSIGNED_INT drv_DAT_1a63_5312;
extern unsigned char drv_DAT_1a63_5314;
extern unsigned char asm_block_5315[513];
extern UNSIGNED_INT run_input_5516;
extern UNSIGNED_INT run_input_5518;
extern UNSIGNED_INT run_input_551a;
extern UNSIGNED_INT run_input_551c;
extern UNSIGNED_INT run_input_551e;
extern UNSIGNED_INT run_input_5520;
extern UNSIGNED_INT run_input_5522;
extern UNSIGNED_INT run_input_5524;
extern UNSIGNED_INT run_input_5526;
extern UNSIGNED_INT run_input_5528;
extern UNSIGNED_INT run_input_552a;
extern UNSIGNED_INT run_input_552c;
extern UNSIGNED_INT run_input_552e;
extern UNSIGNED_INT run_input_5530;
extern UNSIGNED_INT run_input_5532;
extern UNSIGNED_INT run_input_5534;
extern UNSIGNED_INT run_tzset_5536;
extern unsigned char asm_block_5538[8];
#endif
extern struct JOYSTICK shm_joystick;
/* The scratch text buffer every screen builds its lines in, 200h bytes. */
extern unsigned char shm_scratch[512];
/* Where the title screen's box starts, across. */
extern UNSIGNED_INT asm_title_x;
#ifndef PORT_MODERN
extern unsigned char asm_block_5946[2];
#endif
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
#ifndef PORT_MODERN
extern unsigned char asm_block_5c32[512];
#endif
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
#ifndef PORT_MODERN
extern unsigned char asm_block_7264[4];
#endif
extern INT shm_building_count;
/* The case's clock in half-days; an event that comes due is stamped with it in
 * CRIME_EVENT.happen_tick. It crosses modules as COMM()->case_tick. */
extern INT shm_case_tick;
#ifndef PORT_MODERN
extern unsigned char asm_block_726c[2];
#endif
extern rt_addr shm_source_at;
extern INT shm_case_city_1;
extern UNSIGNED_INT shm_case_city_2;
#ifndef PORT_MODERN
extern unsigned char asm_block_7274[512];
#endif
extern UNSIGNED_INT shm_pan_playing;
extern UNSIGNED_INT shm_menu_no_pick;
#ifndef PORT_MODERN
extern unsigned char asm_block_7478[2];
#endif
/* How many alarm lines have tripped, handed back through the shared block. */
extern UNSIGNED_INT asm_alarms;
extern INT shm_menu_items;
/* The two pins each dealt chip takes, for the six gaps between columns of
chips, ten lines each: for each line out of a column, which line of the next it
feeds. */
extern INT asm_deal_pins[6][10];
#ifndef PORT_MODERN
extern unsigned char asm_block_74f6[20];
#endif
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
#ifndef PORT_MODERN
extern unsigned char asm_block_7648[2];
#endif
extern UNSIGNED_INT shm_case_org_2;
/* The 116 sprite handles cut out of facesf.pic and faces.pic, by SPRITE_*
 * index: two banks of face parts, then the plane and its shadow, clue sources,
 * bodies, paperclip, folder ends and typewriter head. */
extern UNSIGNED_INT shm_faces_sprites[116];
#ifndef PORT_MODERN
extern unsigned char asm_block_7734[8];
#endif
/* The 44 sprite handles cut out of bugs.pic, by BUG_SPRITE_* index: two rows
 * of sixteen 8-pixel wire pieces and the twelve 16-pixel chips. */
extern UNSIGNED_INT asm_bugs_sprites[44];
#ifndef PORT_MODERN
extern unsigned char asm_block_7794[8];
#endif
extern INT shm_global_alert_level;
/* The register block the INT 10h calls read and write. */
extern union REGS shm_regs;
extern UNSIGNED_INT shm_double_agent_cities;
#ifndef PORT_MODERN
extern unsigned char asm_block_77ae[2];
#endif
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
#ifndef PORT_MODERN
extern UNSIGNED_INT asm_DAT_1a63_7db8;
#endif
extern unsigned char shm_archive_buffer[512];
extern UNSIGNED_INT shm_menu_face_x;
extern UNSIGNED_INT shm_menu_draw_only;
extern UNSIGNED_INT shm_skills;
/* The sixteen organisation records, 36 bytes each. */
extern struct ORG_STATE shm_orgs[16];
extern UNSIGNED_INT shm_menu_face_y;
#ifndef PORT_MODERN
extern unsigned char asm_block_8202[4];
#endif
/* Non-zero once the round is over. */
extern INT shm_finished;
extern unsigned char shm_menu_shortcut[32];
extern UNSIGNED_INT shm_menu_pick;
#ifndef PORT_MODERN
extern unsigned char asm_block_822a[2];
#endif
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
#ifndef PORT_MODERN
extern unsigned char asm_block_8439;
#endif
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
#ifndef PORT_MODERN
extern unsigned char asm_block_8c52[514];
#endif
extern UNSIGNED_INT shm_case_spare_2;
extern unsigned char shm_anim_row_2[320];
/* The whole case's difficulty, kept apart from this board's so a tap's
findings are worked out at the case's. */
extern UNSIGNED_INT asm_case_difficulty;
#ifndef PORT_MODERN
extern unsigned char asm_block_8f98[64];
#endif
/* The organisation the module was entered for. */
extern UNSIGNED_INT shm_case_org;
#ifndef PORT_MODERN
extern unsigned char asm_block_8fda[2070];
#endif

#endif /* BUG_PORT_H */
