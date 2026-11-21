	PAGE	60,132
	TITLE	GAME
;
; GAME.ASM -- the assembly side of GAME.EXE.
;
; A SPLIT marker stands where a routine is in C; the build cuts the
; assembly there.
;

	EXTRN	_c_notice:PROC
	EXTRN	_c_sound_command:PROC
	EXTRN	_c_hook_hand_back:PROC
	EXTRN	_c_hook_campaign:PROC
	EXTRN	_c_wrap_message:PROC
	EXTRN	_c_draw_message:PROC
	EXTRN	_c_filter_message:PROC
	EXTRN	_c_worth_the_trip:PROC
	EXTRN	_c_packed_distance:PROC
	EXTRN	_c_city_distance:PROC
	EXTRN	_c_say_presence:PROC
	EXTRN	_c_presence:PROC
	EXTRN	_c_person_name:PROC
	EXTRN	_c_person_real_name:PROC
	EXTRN	_c_personnel_file:PROC
	EXTRN	_c_page_frame:PROC
	EXTRN	_c_folder_header:PROC
	EXTRN	_c_clock_text:PROC
	EXTRN	_c_text_width:PROC
	EXTRN	_c_text_panel:PROC
	EXTRN	_c_draw_centred:PROC
	EXTRN	_c_draw_paper:PROC
	EXTRN	_c_print_message:PROC
	EXTRN	_c_draw_display_list:PROC
	EXTRN	_c_city_loop:PROC
	EXTRN	_c_building_menu:PROC
	EXTRN	_c_arrive:PROC
	EXTRN	_c_stakeout:PROC
	EXTRN	_c_raid:PROC
	EXTRN	_c_arrest:PROC
	EXTRN	_c_show_prose:PROC
	EXTRN	_c_replace:PROC
	EXTRN	_c_remove_crime_object:PROC
	EXTRN	_c_player_captured_menu:PROC
	EXTRN	_c_prisoner_exchange:PROC
	EXTRN	_c_travel_menu:PROC
	EXTRN	_c_city_name:PROC
	EXTRN	_c_fly_distance:PROC
	EXTRN	_c_sign:PROC
	EXTRN	_c_raise_alert:PROC
	EXTRN	_c_org_mood:PROC
	EXTRN	_c_campaign_start:PROC
	EXTRN	_c_clear_happen_ticks:PROC
	EXTRN	_c_ask_menu:PROC
	EXTRN	_c_clear_for_menu:PROC
	EXTRN	_c_draw_sprite:PROC
	EXTRN	_c_city_picture:PROC
	EXTRN	_c_load_city_picture:PROC
	EXTRN	_c_squeeze:PROC
	EXTRN	_c_suspect_scan:PROC
	EXTRN	_c_evidence_unlock:PROC
	EXTRN	_c_suspect_release:PROC
	EXTRN	_c_report_new_fields:PROC
	EXTRN	_c_wait_key:PROC
	EXTRN	_c_suspect_reserve:PROC
	EXTRN	_c_building_explore:PROC
	EXTRN	_c_building_forget:PROC
	EXTRN	_c_cell_reveal:PROC
	EXTRN	_c_clue_close_gap:PROC
	EXTRN	_c_clue_record:PROC
	EXTRN	_c_clue_about:PROC
	EXTRN	_c_clue_text:PROC
	EXTRN	_c_clue_line:PROC
	EXTRN	_c_clue_phrase:PROC
	EXTRN	_c_clue_subject:PROC
	EXTRN	_c_clue_thing:PROC
	EXTRN	_c_clue_line_full:PROC
	EXTRN	_c_clue_from_file:PROC
	EXTRN	_c_dossier:PROC
	EXTRN	_c_intercept_line:PROC
	EXTRN	_c_wait_it_out:PROC
	EXTRN	_c_hotel_menu:PROC
	EXTRN	_c_data_menu:PROC
	EXTRN	_c_cia_building:PROC
	EXTRN	_c_activity_report:PROC
	EXTRN	_c_tap_list:PROC
	EXTRN	_c_org_info:PROC
	EXTRN	_c_org_list:PROC
	EXTRN	_c_city_info:PROC
	EXTRN	_c_city_list:PROC
	EXTRN	_c_document_menu:PROC
	EXTRN	_c_dossiers:PROC
	EXTRN	_c_suspect_menu:PROC
	EXTRN	_c_message_menu:PROC
	EXTRN	_c_decode_message:PROC
	EXTRN	_c_trim_to_width:PROC
	EXTRN	_c_log_add:PROC
	EXTRN	_c_log_draw:PROC
	EXTRN	_c_say_block:PROC
	EXTRN	_c_say_block_with:PROC
	EXTRN	_c_substitute:PROC
	EXTRN	_c_say_message:PROC
	EXTRN	_c_say_one_of:PROC
	EXTRN	_c_say_event_text:PROC
	EXTRN	_c_message_tag:PROC
	EXTRN	_c_faces_load:PROC
	EXTRN	_c_draw_face:PROC
	EXTRN	_c_draw_face_panel:PROC
	EXTRN	_c_faces_cut:PROC
	EXTRN	_c_campaign_tick:PROC
	EXTRN	_c_advance_clock:PROC
	EXTRN	_c_forget:PROC
	EXTRN	_c_case_due:PROC
	EXTRN	_c_test_for_jailbreak:PROC
	EXTRN	_c_timestamp:PROC
	EXTRN	_c_hook_repaint:PROC
	EXTRN	_c_clue_menu:PROC
	EXTRN	_c_clue_list:PROC
	EXTRN	_c_chief_briefing:PROC
	EXTRN	_c_load_menu:PROC
	EXTRN	_c_save_slot:PROC
	EXTRN	_c_save_menu:PROC
	EXTRN	_c_save_write:PROC
	EXTRN	_c_write_checked:PROC
	EXTRN	_c_ask_drive:PROC
	EXTRN	_c_drive_ready:PROC
	EXTRN	_c_save_put:PROC
	EXTRN	_c_put_section:PROC
	EXTRN	_c_get_section:PROC
	EXTRN	_c_save_get:PROC
	EXTRN	_c_want_disk:PROC
	EXTRN	_c_seq_play:PROC
	EXTRN	_c_seq_set_var:PROC
	EXTRN	_c_seq_sound:PROC
	EXTRN	_c_seq_interrupted:PROC
	EXTRN	_c_seq_run:PROC
	EXTRN	_c_seq_start:PROC
	EXTRN	_c_seq_set_picture:PROC
	EXTRN	_c_seq_stop:PROC
	EXTRN	_c_seq_step:PROC
	EXTRN	_c_seq_restart:PROC
	EXTRN	_c_seq_frames:PROC
	EXTRN	_c_hold_frame:PROC
	EXTRN	_c_seq_apply_palette:PROC
	EXTRN	_c_nothing:PROC
	EXTRN	_c_seq_prepare_pages:PROC
	EXTRN	_c_seq_drain_queue:PROC
	EXTRN	_c_seq_reset:PROC
	EXTRN	_c_seq_code:PROC
	EXTRN	_c_actor_take_slot:PROC
	EXTRN	_c_actor_clear_all:PROC
	EXTRN	_c_actor_set:PROC
	EXTRN	_c_actor_step_all:PROC
	EXTRN	_c_actor_draw_hidden:PROC
	EXTRN	_c_actor_draw_all:PROC
	EXTRN	_c_actor_draw:PROC
	EXTRN	_c_actor_clear_hidden:PROC
	EXTRN	_c_actor_where:PROC
	EXTRN	_c_actor_step:PROC
	EXTRN	_c_palette_match:PROC
	EXTRN	_c_set_dac_block:PROC
	EXTRN	_c_set_border_colour:PROC
	EXTRN	_c_set_video_mode:PROC
	EXTRN	_c_anim_open:PROC
	EXTRN	_c_anim_signature:PROC
	EXTRN	_c_anim_extra_blocks:PROC
	EXTRN	_c_anim_start_chunks:PROC
	EXTRN	_c_anim_chunk:PROC
	EXTRN	_c_anim_sprites:PROC
	EXTRN	_c_anim_paragraphs:PROC
	EXTRN	_c_anim_frame_rows:PROC
	EXTRN	_c_anim_frame:PROC
	EXTRN	_c_anim_frame_header:PROC
	EXTRN	_c_anim_read:PROC
	EXTRN	_c_anim_byte:PROC
	EXTRN	_c_menu_run:PROC
	EXTRN	_c_menu_draw:PROC
	EXTRN	_c_menu_box:PROC
	EXTRN	_c_outline_box:PROC
	EXTRN	_c_pan_arm:PROC
	EXTRN	_c_pan_restore:PROC
	EXTRN	_c_menu_key:PROC
	EXTRN	_c_pan_blank:PROC
	EXTRN	_c_wait_for_release:PROC
	EXTRN	_c_joystick_key:PROC
	EXTRN	_c_joystick_read:PROC
	EXTRN	_c_joystick_button:PROC
	EXTRN	_c_draw_line:PROC
	EXTRN	_c_write_text:PROC
	EXTRN	_c_write_text_trimmed:PROC
	EXTRN	_c_wait_retraces:PROC
	EXTRN	_c_screen_save:PROC
	EXTRN	_c_screen_restore:PROC
	EXTRN	_c_fill_box:PROC
	EXTRN	_c_set_graphics_mode:PROC
	EXTRN	_c_set_text_mode:PROC
	EXTRN	_c_seed_random:PROC
	EXTRN	_c_random_below:PROC
	EXTRN	_c_clamp:PROC
	EXTRN	_c_open:PROC
	EXTRN	_c_create:PROC
	EXTRN	_c_close:PROC
	EXTRN	_c_read_all:PROC
	EXTRN	_c_read_all_far:PROC
	EXTRN	_c_write_file:PROC
	EXTRN	_c_decode_picture:PROC
	EXTRN	_c_decode_palette:PROC
	EXTRN	_c_decode_scan:PROC
	EXTRN	_c_load_picture:PROC
	EXTRN	_c_load_anim:PROC
	EXTRN	_c_animation_from_memory:PROC
	EXTRN	_c_decode_from_file:PROC
	EXTRN	_c_refill_from_memory:PROC
	EXTRN	_c_prime_file:PROC
	EXTRN	_c_refill_from_file:PROC
	EXTRN	_c_fatal:PROC
	EXTRN	_c_set_mode_keeping_errno:PROC
	EXTRN	_c_archive_open:PROC
	EXTRN	_c_archive_close:PROC
	EXTRN	_c_archive_find:PROC
	EXTRN	_c_seek:PROC
	EXTRN	_c_main:PROC
	PUBLIC	_shm_suspects
	PUBLIC	_shm_buildings
	PUBLIC	_shm_clues_shown
	PUBLIC	_shm_jailbreak_suspect
	PUBLIC	_shd_picture_page
	PUBLIC	_shd_map_page
	PUBLIC	_shd_pan_disk
	PUBLIC	_dat_first_names
	PUBLIC	_dat_last_names
	PUBLIC	_shd_clock_text
	PUBLIC	_asm_leg_x
	PUBLIC	_asm_leg_y
	PUBLIC	_asm_leg_next
	PUBLIC	_shd_clue_phrases
	PUBLIC	_shd_scan_counts
	PUBLIC	_shd_month_names
	PUBLIC	_shd_clue_kinds
	PUBLIC	_dat_clue_source
	PUBLIC	_shd_subst_values
	PUBLIC	_asm_status_bar_y
	PUBLIC	_dat_clue_colours
	PUBLIC	_asm_clue_selected
	PUBLIC	_shd_save_name
	PUBLIC	_shd_disk_names
	PUBLIC	_shd_disk_letter
	PUBLIC	_dat_anim_page_2_port
	PUBLIC	_shd_anim_page
	PUBLIC	_shd_anim_page_2
	PUBLIC	_drv_page_hidden
	PUBLIC	_drv_page_shown
	PUBLIC	_drv_page_anim
	PUBLIC	_shm_seq_picture
	PUBLIC	_shm_frame_toggle
	PUBLIC	_shd_city_on_screen
	PUBLIC	_shd_drive
	PUBLIC	_shm_pan_width
	PUBLIC	_shm_pan_building
	PUBLIC	_shd_joystick_dirs
	PUBLIC	_dat_screen_port
	PUBLIC	_shd_screen
	PUBLIC	_asm_DAT_2206_4370
	PUBLIC	_asm_DAT_2206_4371
	PUBLIC	_asm_DAT_2206_4372
	PUBLIC	_asm_DAT_2206_4374
	PUBLIC	_asm_DAT_2206_4376
	PUBLIC	_asm_DAT_2206_4378
	PUBLIC	_asm_DAT_2206_437a
	PUBLIC	_asm_DAT_2206_437c
	PUBLIC	_asm_DAT_2206_437e
	PUBLIC	_shd_archive_buffer_end
	PUBLIC	_shd_archive_fd
	PUBLIC	_asm_DAT_2206_449d
	PUBLIC	_asm_DAT_2206_449f
	PUBLIC	_asm_DAT_2206_44a1
	PUBLIC	_asm_DAT_2206_44a3
	PUBLIC	_asm_DAT_2206_44a5
	PUBLIC	_asm_DAT_2206_4815
	PUBLIC	_asm_DAT_2206_4817
	PUBLIC	_asm_DAT_2206_4819
	PUBLIC	_asm_DAT_2206_481b
	PUBLIC	_asm_DAT_2206_481d
	PUBLIC	_asm_DAT_2206_481f
	PUBLIC	_asm_DAT_2206_4822
	PUBLIC	_asm_DAT_2206_4823
	PUBLIC	_asm_DAT_2206_4825
	PUBLIC	_asm_DAT_2206_4827
	PUBLIC	_asm_DAT_2206_4829
	PUBLIC	_asm_DAT_2206_482b
	PUBLIC	_asm_DAT_2206_482d
	PUBLIC	_asm_DAT_2206_4830
	PUBLIC	_asm_DAT_2206_4832
	PUBLIC	_asm_DAT_2206_4834
	PUBLIC	_asm_DAT_2206_4836
	PUBLIC	_addr_page_row_tables
	PUBLIC	_asm_DAT_2206_4e80
	PUBLIC	_asm_DAT_2206_4e82
	PUBLIC	_shm_anim_magic
	PUBLIC	_asm_watched
	PUBLIC	_asm_watch_odds
	PUBLIC	_asm_picture_width
	PUBLIC	_asm_picture_height
	PUBLIC	_asm_tap_digits
	PUBLIC	_asm_jailbreak_target_suspect
	PUBLIC	_asm_jailbreak_source_suspect
	PUBLIC	_shm_save_loading
	PUBLIC	_shm_save_errno
	PUBLIC	_shm_slot_fd
	PUBLIC	_shm_slot_word
	PUBLIC	_shm_save_block
	PUBLIC	_shm_save_offset
	PUBLIC	_shm_save_fd
	PUBLIC	_shm_seq_frames_left
	PUBLIC	_shm_frames_owed
	PUBLIC	_shm_seq_wait
	PUBLIC	_shm_seq_block
	PUBLIC	_shm_seq_pc
	PUBLIC	_shm_seq_depth
	PUBLIC	_shm_seq_frames_done
	PUBLIC	_shm_seq_sound_queue_count
	PUBLIC	_shm_fullscreen_pan
	PUBLIC	_shm_frame_deadline
	PUBLIC	_shm_seq_op
	PUBLIC	_shm_seq_operand
	PUBLIC	_shm_anim_fd
	PUBLIC	_shm_anim_magic_read
	PUBLIC	_shm_anim_packed
	PUBLIC	_shm_anim_signature
	PUBLIC	_shm_active_pan
	PUBLIC	_shm_menu_line_start
	PUBLIC	_shm_menu_colour_plain
	PUBLIC	_shm_menu_colour_item
	PUBLIC	_shm_menu_lines
	PUBLIC	_shm_menu_colour_pick
	PUBLIC	_shm_source_fd
	PUBLIC	_shm_source_dst
	PUBLIC	_shm_source_src
	PUBLIC	_shm_sprite_width
	PUBLIC	_shm_sprite_height
	PUBLIC	_shm_palette_count
	PUBLIC	_shm_joystick
	PUBLIC	_shm_scratch
	PUBLIC	_shm_difficulty
	PUBLIC	_asm_day
	PUBLIC	_shm_clock_minutes
	PUBLIC	_shm_campaign
	PUBLIC	_shm_seed
	PUBLIC	_shm_options
	PUBLIC	_shm_cga
	PUBLIC	_shm_cities
	PUBLIC	_shm_menu_tick
	PUBLIC	_shm_suspect_count
	PUBLIC	_shm_log
	PUBLIC	_shm_menu_face
	PUBLIC	_shm_wire_clue_source
	PUBLIC	_shm_crime_events
	PUBLIC	_shm_log_count
	PUBLIC	_shm_menu_first_line
	PUBLIC	_shm_building_count
	PUBLIC	_shm_case_tick
	PUBLIC	_shm_frame_ticks
	PUBLIC	_asm_loaded_width
	PUBLIC	_shm_source_at
	PUBLIC	_asm_loaded_height
	PUBLIC	_shm_case_city_1
	PUBLIC	_shm_case_city_2
	PUBLIC	_shm_anim_more
	PUBLIC	_shm_pan_playing
	PUBLIC	_shm_anim_palette
	PUBLIC	_asm_stamp_minute
	PUBLIC	_shm_menu_no_pick
	PUBLIC	_asm_last_screen
	PUBLIC	_shm_menu_items
	PUBLIC	_shm_anim_segment
	PUBLIC	_asm_hour
	PUBLIC	_shm_seq_ticks
	PUBLIC	_asm_contact_met
	PUBLIC	_shm_crime_event_count
	PUBLIC	_shm_case_seed
	PUBLIC	_shm_clue_method
	PUBLIC	_shm_menu_relayout
	PUBLIC	_shm_mission
	PUBLIC	_shm_menu_colour_bar
	PUBLIC	_shm_case_org_1
	PUBLIC	_shm_menu_text_width
	PUBLIC	_shm_case_org_2
	PUBLIC	_asm_menu_choice_count
	PUBLIC	_shm_faces_sprites
	PUBLIC	_shm_global_alert_level
	PUBLIC	_shm_slots_filled
	PUBLIC	_shm_regs
	PUBLIC	_shm_anim_error
	PUBLIC	_shm_double_agent_cities
	PUBLIC	_shm_crime_role_count
	PUBLIC	_shm_menu_marked
	PUBLIC	_shm_crime_roles
	PUBLIC	_shm_seq_done
	PUBLIC	_shm_refill
	PUBLIC	_asm_DAT_2206_9daa
	PUBLIC	_shm_archive_buffer
	PUBLIC	_shm_menu_face_x
	PUBLIC	_shm_menu_draw_only
	PUBLIC	_shm_skills
	PUBLIC	_shm_menu_face_y
	PUBLIC	_shm_anim_sprites
	PUBLIC	_asm_case_ready
	PUBLIC	_shm_anim_name
	PUBLIC	_shm_finished
	PUBLIC	_shm_menu_shortcut
	PUBLIC	_shm_menu_pick
	PUBLIC	_shm_menu_right
	PUBLIC	_shm_role_scan_states
	PUBLIC	_shm_graphics_letter
	PUBLIC	_shm_menu_bottom
	PUBLIC	_shm_seq_stop_asked
	PUBLIC	_asm_campaign_state
	PUBLIC	_shm_case_city
	PUBLIC	_shm_activity
	PUBLIC	_shm_orgs_known
	PUBLIC	_asm_auto_waiting
	PUBLIC	_shm_slot_pick
	PUBLIC	_shm_case_spare_2
	PUBLIC	_asm_menu_choices
	PUBLIC	_shm_anim_block_kind
	PUBLIC	_shm_seq_vars
	PUBLIC	_shm_case_org
	PUBLIC	_asm_FARBUF
	PUBLIC	_drv_real_FUN_1000_0002
	PUBLIC	_drv_jump_mem_avail
	PUBLIC	_drv_jump_gfx_grab
	PUBLIC	_drv_jump_gfx_fill
	PUBLIC	_drv_jump_gfx_char_width
	PUBLIC	_drv_jump_gfx_page_fill
	PUBLIC	_drv_jump_gfx_sprite_put_clipped
	PUBLIC	_drv_jump_gfx_pool_release
	PUBLIC	_drv_jump_gfx_dissolve
	PUBLIC	_drv_jump_gfx_get_pixel
	PUBLIC	_drv_jump_gfx_capability
	PUBLIC	_drv_jump_gfx_pool_alloc
	PUBLIC	_drv_jump_gfx_row_put
	PUBLIC	_drv_jump_gfx_copy_rect
	PUBLIC	_drv_jump_gfx_text
	PUBLIC	_drv_jump_gfx_set_palette
	PUBLIC	_drv_jump_gfx_set_colour_map
	PUBLIC	_drv_jump_gfx_show_page
	PUBLIC	_drv_jump_gfx_sprite_put
	PUBLIC	_drv_jump_gfx_sprite_end
	PUBLIC	_drv_jump_gfx_sprite_row
	PUBLIC	_drv_jump_gfx_sprite_begin
	PUBLIC	_drv_jump_keyboard_empty
	PUBLIC	_drv_jump_read_key
	PUBLIC	_drv_jump_joy_calibrate
	PUBLIC	_drv_jump_joy_read
	PUBLIC	_drv_jump_snd_command
	PUBLIC	_drv_real_link_slots
	PUBLIC	_drv_real_fill_rect
	PUBLIC	_drv_real_draw_line
	PUBLIC	_drv_real_unpack_start
	PUBLIC	_drv_real_palette_read
	PUBLIC	_drv_real_palette_put
	PUBLIC	_drv_real_unpack_row
	PUBLIC	_drv_real_sprite_put
	PUBLIC	_drv_real_sprite_put_2
	PUBLIC	_drv_real_page_copy
	PUBLIC	_drv_real_anim_reset
	PUBLIC	_shm_hook_critical_error
	PUBLIC	_shm_unhook_critical_error
	PUBLIC	_shm_seq_data
	PUBLIC	_asm_TIMESTAMP
	PUBLIC	_shd_list_printout
	PUBLIC	_dat_key_clue
	PUBLIC	_shd_str_period
	PUBLIC	_dat_str_face
	PUBLIC	_dat_str_valkerie
	PUBLIC	_dat_str_thunderbolt
	PUBLIC	_shd_str_00
	PUBLIC	_shd_str_000
	PUBLIC	_shd_key_clue_2
	PUBLIC	_shd_key_clue_3
	PUBLIC	_shd_key_clue_4
	PUBLIC	_shd_str_empty_dossier
	PUBLIC	_shd_str_name
	PUBLIC	_shd_str_rank
	PUBLIC	_shd_str_org
	PUBLIC	_shd_str_city
	PUBLIC	_shd_str_recruited
	PUBLIC	_shd_str_by
	PUBLIC	_shd_str_in_3
	PUBLIC	_shd_str_period_2
	PUBLIC	_shd_str_role
	PUBLIC	_shd_str_role_2
	PUBLIC	_shd_str_role_3
	PUBLIC	_shd_str_under_arrest
	PUBLIC	_shd_str_hiding
	PUBLIC	_shd_str_turned
	PUBLIC	_shd_str_empty_dossier_line
	PUBLIC	_shd_str_quote
	PUBLIC	_shd_str_quote_2
	PUBLIC	_shd_str_empty_dossier_page
	PUBLIC	_shd_str_rcvd_msg_fm
	PUBLIC	_shd_str_sent_msg
	PUBLIC	_shd_str_space_9
	PUBLIC	_shd_str_someone
	PUBLIC	_shd_str_of_the_2
	PUBLIC	_shd_str_in_4
	PUBLIC	_shd_str_on_2
	PUBLIC	_shd_str_space_10
	PUBLIC	_shd_str_period_3
	PUBLIC	_shd_subst_keys
	PUBLIC	_dat_str_sloc00
	PUBLIC	_dat_str_rloc00
	PUBLIC	_dat_str_sorg00
	PUBLIC	_dat_str_rorg00
	PUBLIC	_dat_str_fluf00
	PUBLIC	_dat_str_aidd00
	PUBLIC	_shm_anim_row
	PUBLIC	_shm_orgs
	PUBLIC	_shm_crime_block
	PUBLIC	_dat_str_intrgate_pan
	PUBLIC	_dat_str_accuse
	PUBLIC	_dat_str_taking_part_plot_we
	PUBLIC	_dat_str_have_no_evidence
	PUBLIC	_dat_str_will_have_released
	PUBLIC	_dat_str_inter1
	PUBLIC	_dat_str_doublea
	PUBLIC	_dat_str_inter2
	PUBLIC	_dat_str_ask
	PUBLIC	_dat_str_oh_yeah_i_guess
	PUBLIC	_dat_str_hmmm_i_don_t
	PUBLIC	_dat_str_mastermind_breaks_down
	PUBLIC	_dat_str_injail_pan
	PUBLIC	_dat_str_taken_local_jail
	PUBLIC	_dat_str_briefing_pan_2
	PUBLIC	_dat_str_nice0
	PUBLIC	_dat_note_19
	PUBLIC	_dat_str_officem_pan
	PUBLIC	_dat_str_officef_pan
	PUBLIC	_dat_str_max_i_ve_been
	PUBLIC	_dat_str_i_d_look_into
	PUBLIC	_dat_str_there_s_not_much
	PUBLIC	_dat_str_the
	PUBLIC	_dat_str_has
	PUBLIC	_dat_str_right_here
	PUBLIC	_dat_str_i_d_suggest_go
	PUBLIC	_dat_str_message_should_give_us
	PUBLIC	_dat_str_check_crypto_branch
	PUBLIC	_dat_str_max_we_ve_got
	PUBLIC	_dat_str_max_i_suggest_check
	PUBLIC	_dat_str_she_3
	PUBLIC	_dat_str_s_right_here
	PUBLIC	_dat_str_advicea
	PUBLIC	_dat_str_advice1
	PUBLIC	_dat_str_advice2
	PUBLIC	_dat_str_advice3
	PUBLIC	_dat_str_advice4
	PUBLIC	_dat_str_advice5
	PUBLIC	_shd_str_nsyn_overflow
	PUBLIC	_shd_str_chronology
	PUBLIC	_shd_str_news
	PUBLIC	_shd_str_more_2
	PUBLIC	_shd_str_sent_msg_2
	PUBLIC	_shd_str_met
	PUBLIC	_shd_str_meeting_noted
	PUBLIC	_shd_str_chronology_2
	PUBLIC	_shd_str_news_2
	PUBLIC	_shd_str_none_log
	PUBLIC	_shd_str_information_requires
	PUBLIC	_dat_str_text_dta
	PUBLIC	_dat_str_text_dta_2
	PUBLIC	_dat_str_text_dta_3
	PUBLIC	_dat_str_text_dta_4
	PUBLIC	_dat_str_text_dta_5
	PUBLIC	_dat_str_text_dta_6
	PUBLIC	_dat_str_alrt00
	PUBLIC	_dat_str_text_dta_7
	PUBLIC	_dat_str_text_dta_8
	PUBLIC	_dat_str_briefing_pan_3
	PUBLIC	_dat_str_rest_up
	PUBLIC	_dat_str_i_ve_assigned_one
	PUBLIC	_dat_str_president_s_counting
	PUBLIC	_dat_str_at
	PUBLIC	_dat_str_unknown_building_2
	PUBLIC	_dat_str_few_guards_peering
	PUBLIC	_dat_str_appears_extra_guards
	PUBLIC	_dat_str_building_swarming
	PUBLIC	_dat_str_do_place_wiretap
	PUBLIC	_dat_str_break_into_building
	PUBLIC	_dat_str_watch_building_check
	PUBLIC	_dat_str_blding01_pan
	PUBLIC	_dat_str_sneakin_pic
	PUBLIC	_dat_str_wiretap_pic
	PUBLIC	_dat_str_guards
	PUBLIC	_dat_str_will_have
	PUBLIC	_dat_str_minutes
	PUBLIC	_dat_str_followed_pan
	PUBLIC	_dat_str_followed
	PUBLIC	_dat_str_coded_message
	PUBLIC	_dat_str_meeting_notes
	PUBLIC	_dat_str_new_information
	PUBLIC	_dat_str_additional_information
	PUBLIC	_dat_str_of_the
	PUBLIC	_dat_str_has_been_identified_as
	PUBLIC	_dat_str_has_been_positively
	PUBLIC	_dat_str_we_have_acquired
	PUBLIC	_dat_str_has_been_spotted
	PUBLIC	_dat_str_has_been_identified_as_2
	PUBLIC	_dat_str_we_have_obtained
	PUBLIC	_dat_str_we_have_determined_rank
	PUBLIC	_dat_str_we_found_recruiting
	PUBLIC	_dat_str_we_found_recruiting_2
	PUBLIC	_dat_str_clue
	PUBLIC	_dat_str_none
	PUBLIC	_dat_str_clues_txt
	PUBLIC	_shd_str_clues_txt_2
	PUBLIC	_shd_str_message_not_decoded
	PUBLIC	_shd_str_more
	PUBLIC	_dat_str_bulletin_2
	PUBLIC	_dat_str_has_come_out_hiding
	PUBLIC	_dat_str_surveillance_team_2
	PUBLIC	_dat_str_bulletin_3
	PUBLIC	_dat_str_has_come_out_hiding_2
	PUBLIC	_dat_str_surveillance_team_3
	PUBLIC	_shd_str_pani
	PUBLIC	_dat_note_06
	PUBLIC	_dat_note_07
	PUBLIC	_dat_note_08
	PUBLIC	_dat_note_09
	PUBLIC	_dat_note_10
	PUBLIC	_dat_note_11
	PUBLIC	_dat_note_12
	PUBLIC	_dat_note_13
	PUBLIC	_dat_note_14
	PUBLIC	_dat_note_15
	PUBLIC	_dat_note_16
	PUBLIC	_dat_note_17
	PUBLIC	_dat_note_18
	PUBLIC	_dat_str_warning_pan
	PUBLIC	_dat_str_jailbreak
	PUBLIC	_dat_str_agents_trying_free
	PUBLIC	_dat_str_bustout_pan
	PUBLIC	_dat_str_escapes
	PUBLIC	_dat_str_escape_attempt_foiled
	PUBLIC	_dat_str_car_tracer_leads_new
	PUBLIC	_dat_str_carcap
	PUBLIC	_dat_str_wounded_pan
	PUBLIC	_dat_str_take_time_recover_from
	PUBLIC	_dat_str_surprisel
	PUBLIC	_dat_str_surprisew
	PUBLIC	_dat_str_you_are_in
	PUBLIC	_dat_str_do_go
	PUBLIC	_dat_str_airport
	PUBLIC	_dat_str_hotel
	PUBLIC	_dat_str_unknown_building
	PUBLIC	_dat_str_check_data
	PUBLIC	_dat_str_surprise
	PUBLIC	_dat_str_which_city
	PUBLIC	_dat_str_known_locations_2
	PUBLIC	_dat_str_unknown_building_3
	PUBLIC	_dat_str_none_5
	PUBLIC	_dat_str_suspects
	PUBLIC	_dat_str_none_6
	PUBLIC	_dat_str_clues
	PUBLIC	_dat_str_none_7
	PUBLIC	_dat_str_pic
	PUBLIC	_shd_str_facesf_pic
	PUBLIC	_shd_str_faces_pic
	PUBLIC	_dat_str_clue_2
	PUBLIC	_dat_str_arrested_4
	PUBLIC	_dat_str_hiding_4
	PUBLIC	_dat_str_turned_5
	PUBLIC	_dat_str_arrested_3
	PUBLIC	_dat_str_turned_4
	PUBLIC	_dat_str_clues_2
	PUBLIC	_dat_note_04
	PUBLIC	_dat_note_05
	PUBLIC	_dat_str_message_decode
	PUBLIC	_dat_str_from
	PUBLIC	_dat_str_message
	PUBLIC	_shd_str_one_moment_please
	PUBLIC	_shd_str_sure_want_quit_no_2
	PUBLIC	_shd_str_briefing_pan
	PUBLIC	_shd_str_animation_pan
	PUBLIC	_shd_str_bld
	PUBLIC	_dat_str_documents
	PUBLIC	_dat_str_select_document
	PUBLIC	_dat_str_master_plan_2
	PUBLIC	_dat_str_personel_file
	PUBLIC	_dat_str_none_8
	PUBLIC	_dat_str_suspect_files
	PUBLIC	_dat_str_surndr01_pan
	PUBLIC	_dat_str_grilled
	PUBLIC	_dat_str_warning_pan_2
	PUBLIC	_dat_str_jailbreak_2
	PUBLIC	_dat_str_agents_free
	PUBLIC	_dat_str_escape_pan
	PUBLIC	_dat_str_escape
	PUBLIC	_dat_str_no_thanks_squinty_agree
	PUBLIC	_dat_str_exchanged
	PUBLIC	_dat_str_two_double_agents
	PUBLIC	_shd_str_select_load_file
	PUBLIC	_shd_str_sve
	PUBLIC	_shd_str_max
	PUBLIC	_shd_str_remington_00
	PUBLIC	_shd_str_rank_2
	PUBLIC	_shd_str_local
	PUBLIC	_shd_str_national
	PUBLIC	_shd_str_regional
	PUBLIC	_shd_str_global
	PUBLIC	_shd_str_empty_slot
	PUBLIC	_shd_str_select_save_file
	PUBLIC	_shd_str_game_has_been_saved
	PUBLIC	_shd_str_game_not_saved
	PUBLIC	_shd_str_write_access_denied
	PUBLIC	_shd_str_disk_full
	PUBLIC	_shd_str_press_key_continue
	PUBLIC	_shd_str_sve_2
	PUBLIC	_shd_str_file_error_write
	PUBLIC	_shd_str_save_progress
	PUBLIC	_shd_str_which_drive_contains
	PUBLIC	_shd_str_which_drive_contains_2
	PUBLIC	_shd_str_press_drive_letter
	PUBLIC	_shd_str_press_escape_cancel
	PUBLIC	_shd_str_no_disk_drive
	PUBLIC	_shd_str_env_sve_put
	PUBLIC	_shd_str_env_sve
	PUBLIC	_shd_str_file_error
	PUBLIC	_dat_str_env_sve_2
	PUBLIC	_dat_str_ad_pic
	PUBLIC	_dat_note_01
	PUBLIC	_dat_note_02
	PUBLIC	_dat_note_03
	PUBLIC	_dat_str_hq_pan
	PUBLIC	_dat_str_arrive_at_cia_building
	PUBLIC	_dat_str_cities_cat
	PUBLIC	_shd_str_incoming_msg
	PUBLIC	_dat_str_coded_messages
	PUBLIC	_dat_str_none_10
	PUBLIC	_dat_str_bulletin
	PUBLIC	_dat_str_has_gone_into_hiding
	PUBLIC	_dat_str_surveillance_team
	PUBLIC	_dat_str_env_sve_3
	PUBLIC	_dat_str_interpol_bulletin
	PUBLIC	_dat_str_spotted
	PUBLIC	_dat_str_interpol
	PUBLIC	_dat_str_message_traffic
	PUBLIC	_dat_str_from_2
	PUBLIC	_dat_str_satellite_intercept
	PUBLIC	_dat_str_double_agent
	PUBLIC	_dat_str_wiretap_at
	PUBLIC	_dat_str_reveals
	PUBLIC	_dat_str_she_2
	PUBLIC	_dat_str_from_3
	PUBLIC	_dat_str_has_just_returned_from
	PUBLIC	_dat_str_airport_surveillance
	PUBLIC	_dat_str_seems_have_departed
	PUBLIC	_dat_str_airport_surveillance_2
	PUBLIC	_dat_str_animation_pan
	PUBLIC	_dat_str_allies
	PUBLIC	_dat_str_none_3
	PUBLIC	_dat_str_known_locations
	PUBLIC	_dat_str_associates
	PUBLIC	_dat_str_none_4
	PUBLIC	_dat_str_which_organization
	PUBLIC	_dat_str_unsuspecting
	PUBLIC	_dat_str_cautious
	PUBLIC	_dat_str_suspicious
	PUBLIC	_dat_str_nervous
	PUBLIC	_dat_str_very_nervous
	PUBLIC	_shd_str_hideout
	PUBLIC	_shd_str_agent
	PUBLIC	_shd_str_safehouse
	PUBLIC	_shd_str_active_cel
	PUBLIC	_shd_str_office
	PUBLIC	_dat_str_prose_dta
	PUBLIC	_dat_msg_rplc
	PUBLIC	_dat_msg_name
	PUBLIC	_dat_str_max_remington
	PUBLIC	_dat_msg_city
	PUBLIC	_dat_msg_org
	PUBLIC	_dat_str_briefing_pan
	PUBLIC	_dat_str_good_job_max_found
	PUBLIC	_dat_str_should_really_slow_down
	PUBLIC	_shd_str_please_insert_disk
	PUBLIC	_shd_str_if_3_5_insert
	PUBLIC	_shd_str_press_return_continue
	PUBLIC	_dat_str_binos3_pan
	PUBLIC	_dat_str_notice_someone
	PUBLIC	_dat_str_leaving_building
	PUBLIC	_dat_str_do_wait_follow_car
	PUBLIC	_dat_str_he_looks
	PUBLIC	_dat_str_she_looks
	PUBLIC	_dat_str_bugcar_pan
	PUBLIC	_dat_str_agent_2
	PUBLIC	_dat_str_master_plan
	PUBLIC	_dat_str_secret
	PUBLIC	_dat_str_arrested
	PUBLIC	_dat_str_hiding
	PUBLIC	_dat_str_turned
	PUBLIC	_dat_str_personnel_file
	PUBLIC	_dat_str_action_team
	PUBLIC	_dat_str_no_activity
	PUBLIC	_dat_str_of_the_3
	PUBLIC	_dat_str_arrested_2
	PUBLIC	_dat_str_hiding_3
	PUBLIC	_dat_str_turned_3
	PUBLIC	_dat_str_custody
	PUBLIC	_dat_str_none_9
	PUBLIC	_dat_str_text_dta_9
	PUBLIC	_shd_str_msg0000
	PUBLIC	_dat_note_20
	PUBLIC	_dat_str_none_2
	PUBLIC	_dat_str_europe_pic
	PUBLIC	_dat_str_africa_pic
	PUBLIC	_dat_str_central_pic
	PUBLIC	_dat_str_re
	PUBLIC	_dat_str_do_travel
	PUBLIC	_dat_str_stay_here
	PUBLIC	_dat_str_check_data_2
	PUBLIC	_dat_colours_accuse
	PUBLIC	_dat_str_dot_quote_nl
	PUBLIC	_dat_str_dot_nl_he
	PUBLIC	_dat_str_dot_nl_she
	PUBLIC	_dat_colours_accuse_2
	PUBLIC	_dat_colours_report
	PUBLIC	_dat_colours_advice
	PUBLIC	_dat_str_space_15
	PUBLIC	_dat_str_newline_17
	PUBLIC	_dat_str_mark_8f_2
	PUBLIC	_dat_str_newline_space
	PUBLIC	_dat_str_space_16
	PUBLIC	_dat_str_he_2
	PUBLIC	_dat_str_stop_space
	PUBLIC	_shd_str_quote_3
	PUBLIC	_shd_str_quote_4
	PUBLIC	_shd_str_mode_read_text
	PUBLIC	_shd_fmt_line
	PUBLIC	_shd_fmt_line_2
	PUBLIC	_shd_str_space_12
	PUBLIC	_shd_fmt_line_3
	PUBLIC	_shm_substitute_tail
	PUBLIC	_dat_str_empty_9_2
	PUBLIC	_dat_str_mark_80
	PUBLIC	_shm_message_key
	PUBLIC	_dat_str_mark_8f
	PUBLIC	_asm_building_pan
	PUBLIC	_dat_colours_building_2
	PUBLIC	_dat_str_space_2
	PUBLIC	_dat_str_dots
	PUBLIC	_dat_str_on
	PUBLIC	_dat_str_space_2_2
	PUBLIC	_shm_clue_digits
	PUBLIC	_dat_str_in
	PUBLIC	_dat_str_newline
	PUBLIC	_dat_str_empty_4
	PUBLIC	_dat_str_space_3
	PUBLIC	_dat_str_in_2
	PUBLIC	_dat_str_empty_5
	PUBLIC	_dat_str_empty_6
	PUBLIC	_dat_str_newline_2
	PUBLIC	_dat_str_stop
	PUBLIC	_dat_str_empty_7
	PUBLIC	_dat_str_newline_3
	PUBLIC	_dat_str_empty_8
	PUBLIC	_dat_str_newline_4
	PUBLIC	_dat_str_newline_5
	PUBLIC	_dat_str_newline_6
	PUBLIC	_dat_str_newline_7
	PUBLIC	_dat_str_newline_8
	PUBLIC	_dat_str_source_2_2
	PUBLIC	_dat_str_slash
	PUBLIC	_dat_str_newline_9
	PUBLIC	_dat_str_method_stop
	PUBLIC	_dat_str_related_2
	PUBLIC	_dat_str_newline_10
	PUBLIC	_shd_clue_keys
	PUBLIC	_dat_colours_cia_entrance
	PUBLIC	_dat_colours_cia_hall
	PUBLIC	_dat_colours_cia_office
	PUBLIC	_dat_colours_map
	PUBLIC	_dat_str_bang_nl
	PUBLIC	_dat_str_bang_nl_2
	PUBLIC	_dat_colours_city
	PUBLIC	_dat_colours_city_2
	PUBLIC	_dat_str_nl_space
	PUBLIC	_dat_str_nl_space_2
	PUBLIC	_dat_str_nl_dash_2
	PUBLIC	_dat_str_ellipsis
	PUBLIC	_dat_str_nl_dash_space
	PUBLIC	_dat_str_slash_3
	PUBLIC	_dat_str_dash
	PUBLIC	_dat_str_newline_12
	PUBLIC	_dat_str_space_5
	PUBLIC	_dat_str_newline_13
	PUBLIC	_dat_str_comma_space
	PUBLIC	_shd_colours_face
	PUBLIC	_shd_colours_screen
	PUBLIC	_shd_colours_screen_2
	PUBLIC	_dat_str_source_3
	PUBLIC	_dat_str_slash_6
	PUBLIC	_dat_str_nl_7
	PUBLIC	_dat_str_nl_8
	PUBLIC	_dat_str_to_heading
	PUBLIC	_shd_palette_menu
	PUBLIC	_shd_palette_face
	PUBLIC	_shd_str_ok
	PUBLIC	_dat_colours_escape
	PUBLIC	_dat_str_bang_nl_3
	PUBLIC	_dat_str_bang_nl_4
	PUBLIC	_dat_colours_escape_2
	PUBLIC	_dat_str_dot_nl
	PUBLIC	_shm_probed_campaign
	PUBLIC	_shm_slot_digits
	PUBLIC	_shd_str_colon
	PUBLIC	_shd_str_space_slot
	PUBLIC	_shd_str_comma_2
	PUBLIC	_shd_str_stop_blank
	PUBLIC	_shd_str_newline_save
	PUBLIC	_shd_str_newline_12
	PUBLIC	_dat_palette_game
	PUBLIC	_dat_colours_hq
	PUBLIC	_shd_colours_paper
	PUBLIC	_shm_anim_row_2
	PUBLIC	_dat_str_space_8
	PUBLIC	_dat_str_nl_3
	PUBLIC	_dat_str_nl_4
	PUBLIC	_dat_str_space_11
	PUBLIC	_dat_str_bang_nl_5
	PUBLIC	_dat_str_empty_10
	PUBLIC	_dat_str_to
	PUBLIC	_dat_str_dots_3
	PUBLIC	_dat_str_slash_4
	PUBLIC	_dat_str_he
	PUBLIC	_dat_str_space_13
	PUBLIC	_dat_str_nl_5
	PUBLIC	_dat_str_empty_12
	PUBLIC	_dat_str_slash_5
	PUBLIC	_dat_str_nl_6
	PUBLIC	_dat_str_dot_nl_3
	PUBLIC	_dat_str_empty_13
	PUBLIC	_dat_str_dot_nl_4
	PUBLIC	_dat_str_nl_space_3
	PUBLIC	_dat_str_in_5
	PUBLIC	_dat_str_nl_dash
	PUBLIC	_dat_str_nl_space_4
	PUBLIC	_dat_str_space_4
	PUBLIC	_dat_str_newline_11
	PUBLIC	_dat_str_quiet
	PUBLIC	_dat_key_us
	PUBLIC	_shd_str_close_paren
	PUBLIC	_shd_str_ellipsis_2
	PUBLIC	_dat_colours_stakeout
	PUBLIC	_dat_str_nl_dot
	PUBLIC	_dat_colours_stakeout_2
	PUBLIC	_dat_str_day_slot
	PUBLIC	_dat_colours_statbar
	PUBLIC	_dat_str_comma_space_2
	PUBLIC	_dat_str_space_14
	PUBLIC	_dat_str_comma_4
	PUBLIC	_dat_str_space_6
	PUBLIC	_dat_str_in_6
	PUBLIC	_dat_str_dot_nl_2
	PUBLIC	_dat_str_bullet
	PUBLIC	_dat_str_space_7
	PUBLIC	_dat_str_nl_2
	PUBLIC	_dat_str_empty_9
	PUBLIC	_dat_str_slash_2
	PUBLIC	_dat_str_dots_2
	PUBLIC	_dat_str_percent
	PUBLIC	_dat_str_space
	PUBLIC	_dat_str_nl
	PUBLIC	_shd_str_newline_wrap
	PUBLIC	_dat_colours_building
	PUBLIC	_dat_str_env_sve
	PUBLIC	_dat_str_one_moment_please

; Every segment declared once, empty, so LINK sees them in this order.
CODE_0	SEGMENT	PARA PUBLIC 'CODE'
CODE_0	ENDS
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
_TEXT	ENDS
FARDATA	SEGMENT	PARA PUBLIC 'FAR_DATA'
FARDATA	ENDS
_DATA	SEGMENT	WORD PUBLIC 'DATA'
_DATA	ENDS
CONST0	SEGMENT	WORD PUBLIC 'CONST'
CONST0	ENDS
CONST	SEGMENT	WORD PUBLIC 'CONST'
CONST	ENDS
CONST2	SEGMENT	WORD PUBLIC 'CONST'
CONST2	ENDS
_BSS	SEGMENT	WORD PUBLIC 'BSS'
_BSS	ENDS
XOB	SEGMENT	WORD PUBLIC 'BSS'
XOB	ENDS
XO	SEGMENT	WORD PUBLIC 'BSS'
XO	ENDS
XOE	SEGMENT	WORD PUBLIC 'BSS'
XOE	ENDS
c_common	SEGMENT	PARA PUBLIC 'BSS'
c_common	ENDS

DGROUP	GROUP	_DATA,CONST0,CONST,CONST2,_BSS,c_common
dat_FARBUF_SEG	EQU	53CCh

;==============================================================================
CODE_0	SEGMENT	PARA PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:CODE_0, ds:DGROUP, ss:DGROUP
DAT_1000_0000	DB	0,0

_drv_real_FUN_1000_0002	PROC	FAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	push	es
	mov	ah,35h
	mov	al,24h
	int	21h		; DOS AH=35h: get interrupt vector (AL = vector)
	mov	word ptr ds:[DAT_2206_0042],es
	mov	word ptr ds:[DAT_2206_0044],bx
	mov	ah,25h
	mov	al,24h
	mov	dx,OFFSET drv_real_FUN_1000_00b0
	push	ds
	push	cs
	pop	ds
	int	21h		; DOS AH=25h: set interrupt vector (AL = vector, DS:DX = handler)
	pop	ds
	mov	ax,DGROUP
	mov	es,ax
	mov	si,word ptr [bp+6]
	mov	di,47h
	mov	ax,2900h
	int	21h		; DOS AH=29h: parse a file name into an FCB
	mov	word ptr cs:[DAT_1000_0000],0
	mov	ah,11h
	mov	dx,47h
	int	21h		; DOS AH=11h: find first file, by FCB
	or	al,al
	jz	L10098
	mov	ah,0Eh
	mov	dx,word ptr [bp+8]
	int	21h		; DOS AH=0Eh: select default drive
	mov	word ptr cs:[DAT_1000_0000],0
	mov	ah,11h
	mov	dx,47h
	int	21h		; DOS AH=11h: find first file, by FCB
	or	al,al
	jnz	L10066
	cmp	word ptr cs:[DAT_1000_0000],0
	jz	L10098
L10066:
	int	11h		; BIOS: get equipment list
	rol	al,1
	rol	al,1
	and	al,3
	jnz	L10076
L10070:
	mov	ax,0FFFFh
	jmp	L10098
L10076:
	mov	word ptr cs:[DAT_1000_0000],0
	mov	ah,19h
	int	21h		; DOS AH=19h: get current default drive
	xor	al,1
	mov	dl,al
	mov	ah,0Eh
	int	21h		; DOS AH=0Eh: select default drive
	mov	ah,11h
	mov	dx,47h
	int	21h		; DOS AH=11h: find first file, by FCB
	cmp	word ptr cs:[DAT_1000_0000],0
	jnz	L10070
L10098:
	cbw
	push	ax
	mov	ah,25h
	mov	al,24h
	push	ds
	mov	ds,word ptr ds:[DAT_2206_0042]
	mov	dx,word ptr ds:[DAT_2206_0044]
	int	21h		; DOS AH=25h: set interrupt vector (AL = vector, DS:DX = handler)
	pop	ds
	pop	ax
	pop	es
	pop	di
	pop	si
	pop	bp
	retf
_drv_real_FUN_1000_0002	ENDP

drv_real_FUN_1000_00b0	PROC	FAR
	sti
	push	si
	push	di
	push	es
	push	ds
	push	bx
	push	cx
	push	dx
	mov	word ptr cs:[DAT_1000_0000],1
	mov	al,0
	pop	dx
	pop	cx
	pop	bx
	pop	ds
	pop	es
	pop	di
	pop	si
	iret
drv_real_FUN_1000_00b0	ENDP
D100c9	DB	0

;------------------------------------------------------------------------------
; Jump into a driver through the slot whose address the caller pushed. With
; the cursor showing it far-calls instead, so the cursor can be redrawn after.
;------------------------------------------------------------------------------
drv_real_dispatch	PROC	NEAR
	cmp	byte ptr ds:[_asm_DAT_2206_4371],0
	jnz	L100dd
	pop	word ptr cs:[L100d8+3]
	jmp	short L100d8
L100d8:
	; The target is patched in by the POP above.
	jmp	dword ptr cs:[0]
L100dd:
	mov	byte ptr ds:[_asm_DAT_2206_4370],1
	pop	word ptr cs:[L100f1+3]
	pop	word ptr ds:[_asm_DAT_2206_4372]
	pop	word ptr ds:[_asm_DAT_2206_4374]
	jmp	short L100f1
L100f1:
	; The target is patched in by the POP above.
	call	dword ptr cs:[0]
	dec	byte ptr ds:[_asm_DAT_2206_4370]
	jz	L10106
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[_asm_DAT_2206_4370],0
L10106:
	jmp	dword ptr ds:[_asm_DAT_2206_4372]
drv_real_dispatch	ENDP
D1010a	DB	0,0,0EAh,0,0,0,0,0
	DB	0

_drv_jump_mem_avail	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_mem_avail	ENDP
D10118	DB	0,0

_drv_jump_gfx_grab	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_grab	ENDP
D1011f	DB	0,0

_drv_jump_gfx_fill	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_fill	ENDP
D10126	DB	0,0

_drv_jump_gfx_char_width	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_char_width	ENDP
D1012d	DB	0,0

_drv_jump_gfx_page_fill	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_page_fill	ENDP

_drv_jump_gfx_sprite_put_clipped	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
_drv_jump_gfx_sprite_put_clipped	ENDP

_drv_jump_gfx_pool_release	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_pool_release	ENDP
D10142	DB	0,0,0EAh,0,0,0,0,0
	DB	0

_drv_jump_gfx_dissolve	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_dissolve	ENDP
D10150	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0

_drv_jump_gfx_get_pixel	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_get_pixel	ENDP
D10165	DB	0,0,0EAh,0,0,0,0

drv_jump_gfx_overlay_remove	PROC	NEAR
	call	drv_real_dispatch
L1016f:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_overlay_remove	ENDP
D1017a	DB	0,0

_drv_jump_gfx_capability	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_capability	ENDP
D10181	DB	0,0

_drv_jump_gfx_pool_alloc	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_pool_alloc	ENDP
D10188	DB	0,0

_drv_jump_gfx_row_put	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_row_put	ENDP
D1018f	DB	0,0

_drv_jump_gfx_copy_rect	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_copy_rect	ENDP
D10196	DB	0,0

_drv_jump_gfx_text	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_text	ENDP

drv_jump_FUN_1000_019d	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_FUN_1000_019d	ENDP
D101ab	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

_drv_jump_gfx_set_palette	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_set_palette	ENDP
D101c7	DB	0,0

_drv_jump_gfx_set_colour_map	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_set_colour_map	ENDP
D101ce	DB	0,0,0EAh,0,0,0,0

drv_jump_gfx_overlay_put	PROC	NEAR
	call	drv_real_dispatch
L101d8:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
drv_jump_gfx_overlay_put	ENDP

_drv_jump_gfx_show_page	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
_drv_jump_gfx_show_page	ENDP

_drv_jump_gfx_sprite_put	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
_drv_jump_gfx_sprite_put	ENDP

_drv_jump_gfx_sprite_end	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_sprite_end	ENDP
D101f1	DB	0,0

_drv_jump_gfx_sprite_row	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_sprite_row	ENDP
D101f8	DB	0,0

_drv_jump_gfx_sprite_begin	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_sprite_begin	ENDP
D101ff	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0

drv_jump_gfx_plot	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_plot	ENDP
D10214	DB	0,0

drv_jump_gfx_edge_fill	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_edge_fill	ENDP
D1021b	DB	0,0

drv_jump_gfx_write_reset	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_write_reset	ENDP
D10222	DB	0,0

drv_jump_gfx_set_colour	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_set_colour	ENDP
D10229	DB	0,0

drv_jump_gfx_line	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_line	ENDP
D10230	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0

drv_jump_gfx_select_page	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_select_page	ENDP
D1025a	DB	0,0

drv_jump_gfx_select_pic	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_select_pic	ENDP
D10261	DB	0,0

drv_jump_gfx_edge_copy	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_edge_copy	ENDP
D10268	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0

_drv_jump_keyboard_empty	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_keyboard_empty	ENDP
D10387	DB	0,0

_drv_jump_read_key	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_read_key	ENDP
D1038e	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0

_drv_jump_joy_calibrate	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_joy_calibrate	ENDP
D103b1	DB	0,0

_drv_jump_joy_read	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_joy_read	ENDP
D103b8	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

_drv_jump_snd_command	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_snd_command	ENDP
D103d4	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0,0,0,0EAh,0,0,0
	DB	0,0,0,0EAh,0,0,0,0
	DB	0,0,0EAh,0,0,0,0,0

drv_real_load	PROC	FAR
	mov	bx,sp
	mov	dx,word ptr [bx+4]
	mov	bx,word ptr [bx+6]
	push	si
	push	di
	push	ds
	push	es
	mov	word ptr ds:[_asm_DAT_2206_4376],dx
	mov	word ptr ds:[_asm_DAT_2206_4378],bx
	mov	ah,48h
	mov	bx,0FFFFh
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jc	L10437
	mov	dx,OFFSET DGROUP:dat_message_pool
	jmp	drv_real_FUN_1000_04d0
L10437:
	mov	ah,48h
	sub	bx,100h
	mov	word ptr ds:[_asm_DAT_2206_437c],bx
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jnc	L1044b
	mov	dx,OFFSET DGROUP:dat_str_ms_dos_lied_us
	jmp	drv_real_FUN_1000_04d0
L1044b:
	mov	bx,OFFSET DGROUP:_asm_DAT_2206_437e
	mov	word ptr [bx],ax
	mov	word ptr [bx+2],ax
	mov	ax,4B03h
	mov	dx,word ptr ds:[_asm_DAT_2206_4376]
	push	ds
	pop	es
	mov	word ptr ds:[_asm_DAT_2206_437a],sp
	int	21h		; DOS AH=4Bh AL=03h: load overlay
	mov	dx,DGROUP
	mov	ds,dx
	mov	es,dx
	mov	ss,dx
	mov	sp,word ptr ds:[_asm_DAT_2206_437a]
	jnc	L1048d
	cmp	ax,2
	jnz	L1047c
	mov	dx,OFFSET DGROUP:dat_str_filename_not_found
	jmp	drv_real_FUN_1000_04d0
L1047c:
	cmp	ax,8
	jnz	L10487
	mov	dx,OFFSET DGROUP:dat_str_not_enough_memory_load
	jmp	drv_real_FUN_1000_04d0
L10487:
	mov	dx,OFFSET DGROUP:dat_str_overlay_load_failed
	jmp	drv_real_FUN_1000_04d0
L1048d:
	mov	es,word ptr ds:[_asm_DAT_2206_437e]
	mov	bx,word ptr es:[2Ah]
	mov	ax,es:[2Ch]
	add	ax,0Fh
	rcr	ax,1
	shr	ax,1
	shr	ax,1
	shr	ax,1
	add	bx,ax
	call	drv_real_load_data
	mov	ax,es
	sub	bx,ax
	add	bx,8
	cmp	bx,word ptr ds:[_asm_DAT_2206_437c]
	jbe	L104bd
	mov	dx,OFFSET DGROUP:dat_str_overlay_has_overrun
	jmp	drv_real_FUN_1000_04d0
L104bd:
	mov	ah,4Ah
	int	21h		; DOS AH=4Ah: resize memory block (ES = segment, BX = paragraphs)
	jnc	L104c9
	mov	dx,OFFSET DGROUP:dat_str_unable_shrink_overlay
	jmp	drv_real_FUN_1000_04d0
L104c9:
	mov	ax,es
	pop	es
	pop	ds
	pop	di
	pop	si
	retf
drv_real_load	ENDP

drv_real_FUN_1000_04d0	PROC	NEAR
	mov	ah,9
	int	21h		; DOS AH=09h: write $-terminated string to stdout
	mov	ax,4C00h
	int	21h		; DOS AH=4Ch: terminate (AL = code)
drv_real_FUN_1000_04d0	ENDP

drv_real_load_data	PROC	NEAR
	push	ds
	mov	dx,word ptr ds:[_asm_DAT_2206_4378]
	or	dx,dx
	jz	L1052b
	mov	ax,3D00h
	int	21h		; DOS AH=3Dh: open existing file (AL = access mode)
	jnc	L104ee
	mov	dx,OFFSET DGROUP:dat_str_filename_not_found
	jmp	drv_real_FUN_1000_04d0
L104ee:
	mov	ds,bx
	mov	bx,ax
	mov	ax,3F00h
	mov	cx,8000h
	xor	dx,dx
	int	21h		; DOS AH=3Fh: read from file or device (BX = handle, CX = count)
	jnc	L10503
	mov	dx,OFFSET DGROUP:dat_str_filename_not_found
	jmp	drv_real_FUN_1000_04d0
L10503:
	cmp	ax,cx
	jc	L1050e
	mov	ax,ds
	add	ax,800h
	mov	ds,ax
L1050e:
	add	ax,0Fh
	shr	ax,1
	shr	ax,1
	shr	ax,1
	shr	ax,1
	mov	dx,ds
	add	dx,ax
	mov	ax,3E00h
	int	21h		; DOS AH=3Eh: close file (BX = handle)
	jnc	L10529
	mov	dx,OFFSET DGROUP:dat_str_filename_not_found
	jmp	drv_real_FUN_1000_04d0
L10529:
	mov	bx,dx
L1052b:
	pop	ds
	ret
drv_real_load_data	ENDP

;------------------------------------------------------------------------------
; Walk the loaded driver's entry table and write each entry into the far-jump
; slot that stands for it, which is what makes a driver callable.
;------------------------------------------------------------------------------
_drv_real_link_slots	PROC	FAR
	mov	bx,sp
	mov	dx,word ptr [bx+4]
	push	si
	push	di
	push	ds
	push	es
	mov	ds,dx
	mov	si,32h
	mov	ax,ds:[2Eh]
	mov	dl,7
	mul	dl
	lea	di,[D1010a]
	add	di,ax
	mov	ax,CODE_0
	mov	es,ax
	mov	cx,word ptr ds:[30h]
	mov	ax,ds:[28h]
L10554:
	add	di,3
	movsw
	stosw
	loop	L10554
	pop	es
	pop	ds
	pop	di
	pop	si
	retf
_drv_real_link_slots	ENDP

;------------------------------------------------------------------------------
; Give a driver's memory block back to DOS.
;------------------------------------------------------------------------------
drv_real_free	PROC	FAR
	mov	bx,sp
	mov	ax,word ptr [bx+4]
	push	es
	mov	es,ax
	mov	ah,49h
	int	21h		; DOS AH=49h: free memory block (ES = segment)
	jnc	L10574
	mov	dx,OFFSET DGROUP:dat_str_error_releasing_overlay
	jmp	drv_real_FUN_1000_04d0
L10574:
	pop	es
	retf
drv_real_free	ENDP

_drv_real_fill_rect	PROC	FAR
	push	bp
	mov	bp,sp
	push	di
	push	si
	call	drv_real_FUN_1000_05fe
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	call	far ptr drv_jump_gfx_select_page
	mov	si,word ptr [bp+0Ah]
	add	si,word ptr [bx+4]
	mov	word ptr ds:[_asm_DAT_2206_4819],si
	mov	cx,word ptr [bp+0Eh]
	shl	si,1
	lea	di,[_asm_DAT_2206_44a5]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	mov	dx,cx
	rep stosw
	mov	cx,dx
	lea	di,[asm_block_44a7+438]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	add	ax,word ptr [bp+0Ch]
	dec	ax
	rep stosw
	mov	ax,word ptr [bp+10h]
	call	far ptr drv_jump_gfx_set_colour
	mov	ax,ds:[_asm_DAT_2206_4819]
	mov	cx,ax
	add	cx,word ptr [bp+0Eh]
	dec	cx
	mov	word ptr ds:[_asm_DAT_2206_481b],cx
	mov	bx,OFFSET DGROUP:_asm_DAT_2206_44a5
	call	far ptr drv_jump_gfx_edge_fill
	call	far ptr drv_jump_gfx_write_reset
	pop	si
	pop	di
	pop	bp
	retf
_drv_real_fill_rect	ENDP
D105e1	DB	0

drv_real_FUN_1000_05e2	PROC	FAR
	push	di
	push	si
	push	bp
	mov	ax,ds:[_asm_DAT_2206_4819]
	mov	cx,word ptr ds:[_asm_DAT_2206_481b]
	mov	bx,OFFSET DGROUP:_asm_DAT_2206_44a5
	call	far ptr drv_jump_gfx_edge_fill
	pop	bp
	pop	si
	pop	di
	retf
drv_real_FUN_1000_05e2	ENDP

drv_real_FUN_1000_05f8	PROC	FAR
	push	di
	call	drv_real_FUN_1000_05fe
	pop	di
	retf
drv_real_FUN_1000_05f8	ENDP

drv_real_FUN_1000_05fe	PROC	NEAR
	mov	ax,DGROUP
	mov	es,ax
	mov	di,word ptr ds:[_asm_DAT_2206_4819]
	or	di,di
	js	L10633
	mov	cx,word ptr ds:[_asm_DAT_2206_481b]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,OFFSET DGROUP:_asm_DAT_2206_44a5
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[_asm_DAT_2206_4819],ax
	mov	cx,bx
	mov	di,dx
	add	di,OFFSET DGROUP:asm_block_44a7+438
	sub	ax,ax
	rep stosw
	mov	ds:[_asm_DAT_2206_481b],ax
L10633:
	ret
drv_real_FUN_1000_05fe	ENDP

drv_real_FUN_1000_0634	PROC	NEAR
	mov	ax,DGROUP
	mov	es,ax
	mov	cx,di
	or	si,si
	lea	di,[_asm_DAT_2206_44a5]
	jz	L1064d
	cmp	si,word ptr ds:[_asm_DAT_2206_482b]
	jnz	L1068e
	lea	di,[asm_block_44a7+438]
L1064d:
	cmp	cx,dx
	jge	L10653
	xchg	cx,dx
L10653:
	or	dx,dx
	jns	L10659
	sub	dx,dx
L10659:
	cmp	cx,word ptr ds:[_asm_DAT_2206_482d]
	jle	L10663
	mov	cx,word ptr ds:[_asm_DAT_2206_482d]
L10663:
	add	si,word ptr ds:[_asm_DAT_2206_481d]
	add	cx,word ptr ds:[_asm_DAT_2206_481f]
	add	dx,word ptr ds:[_asm_DAT_2206_481f]
	cmp	cx,word ptr ds:[_asm_DAT_2206_481b]
	jbe	L10679
	mov	word ptr ds:[_asm_DAT_2206_481b],cx
L10679:
	cmp	dx,word ptr ds:[_asm_DAT_2206_4819]
	jnc	L10683
	mov	word ptr ds:[_asm_DAT_2206_4819],dx
L10683:
	add	di,dx
	add	di,dx
	sub	cx,dx
	inc	cx
	mov	ax,si
	rep stosw
L1068e:
	ret
drv_real_FUN_1000_0634	ENDP
	sub	si,si
	or	bx,bx
	js	drv_real_FUN_1000_0634
	mov	si,word ptr ds:[_asm_DAT_2206_482b]
	cmp	bx,si
	jg	drv_real_FUN_1000_0634
	ret

drv_real_FUN_1000_069e	PROC	NEAR
	mov	ax,ds:[_asm_DAT_2206_481d]
	add	word ptr ds:[_asm_DAT_2206_449d],ax
	add	word ptr ds:[_asm_DAT_2206_449f],ax
	mov	ax,ds:[_asm_DAT_2206_481f]
	add	word ptr ds:[_asm_DAT_2206_44a1],ax
	add	word ptr ds:[_asm_DAT_2206_44a3],ax
	mov	ax,ds:[_asm_DAT_2206_449f]
	cmp	ax,word ptr ds:[_asm_DAT_2206_449d]
	jnc	L106d6
	mov	bx,word ptr ds:[_asm_DAT_2206_449d]
	mov	word ptr ds:[_asm_DAT_2206_449f],bx
	mov	ds:[_asm_DAT_2206_449d],ax
	mov	ax,ds:[_asm_DAT_2206_44a3]
	mov	bx,word ptr ds:[_asm_DAT_2206_44a1]
	mov	word ptr ds:[_asm_DAT_2206_44a3],bx
	mov	ds:[_asm_DAT_2206_44a1],ax
L106d6:
	mov	bx,word ptr ds:[_asm_DAT_2206_449f]
	sub	bx,word ptr ds:[_asm_DAT_2206_449d]
	mov	word ptr ds:[_asm_DAT_2206_4815],bx
	mov	ax,ds:[_asm_DAT_2206_44a3]
	mov	dx,ax
	mov	cx,word ptr ds:[_asm_DAT_2206_44a1]
	sub	ax,cx
	mov	bp,2
	jns	L106f8
	xchg	cx,dx
	neg	bp
	neg	ax
L106f8:
	mov	ds:[_asm_DAT_2206_4817],ax
	cmp	dx,word ptr ds:[_asm_DAT_2206_481b]
	jbe	L10705
	mov	word ptr ds:[_asm_DAT_2206_481b],dx
L10705:
	cmp	cx,word ptr ds:[_asm_DAT_2206_4819]
	jnc	L1070f
	mov	word ptr ds:[_asm_DAT_2206_4819],cx
L1070f:
	cmp	ax,bx
	jnc	drv_real_FUN_1000_075e
	mov	di,word ptr ds:[_asm_DAT_2206_44a1]
	shl	di,1
	mov	ax,ds:[_asm_DAT_2206_449d]
	mov	dx,word ptr ds:[_asm_DAT_2206_4815]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[_asm_DAT_2206_4817]
	jmp	L1073f
L10730:
	cmp	ax,word ptr [di+asm_block_44a7+438]
	jbe	L1073a
	mov	word ptr [di+asm_block_44a7+438],ax
L1073a:
	inc	ax
	sub	bx,dx
	add	di,bp
L1073f:
	cmp	ax,word ptr [di+_asm_DAT_2206_44a5]
	jnc	L10749
	mov	word ptr [di+_asm_DAT_2206_44a5],ax
L10749:
	dec	cx
	js	L10753
	add	bx,si
	jns	L10730
	inc	ax
	jmp	L10749
L10753:
	cmp	ax,word ptr [di+asm_block_44a7+438]
	jbe	L1075d
	mov	word ptr [di+asm_block_44a7+438],ax
L1075d:
	ret
drv_real_FUN_1000_069e	ENDP

drv_real_FUN_1000_075e	PROC	NEAR
	mov	di,word ptr ds:[_asm_DAT_2206_44a1]
	shl	di,1
	mov	ax,ds:[_asm_DAT_2206_449d]
	mov	dx,word ptr ds:[_asm_DAT_2206_4817]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[_asm_DAT_2206_4815]
L10778:
	cmp	ax,word ptr [di+_asm_DAT_2206_44a5]
	jnc	L10782
	mov	word ptr [di+_asm_DAT_2206_44a5],ax
L10782:
	cmp	ax,word ptr [di+asm_block_44a7+438]
	jbe	L1078c
	mov	word ptr [di+asm_block_44a7+438],ax
L1078c:
	dec	cx
	js	L1079a
	add	di,bp
	add	bx,si
	js	L10778
	sub	bx,dx
	inc	ax
	jmp	L10778
L1079a:
	ret
drv_real_FUN_1000_075e	ENDP
D1079b	DB	0

drv_real_FUN_1000_079c	PROC	FAR
	call	drv_real_FUN_1000_07ac
	retf
drv_real_FUN_1000_079c	ENDP

drv_real_FUN_1000_07a0	PROC	FAR
	push	bp
	push	si
	push	di
	push	es
	call	drv_real_FUN_1000_07ac
	pop	es
	pop	di
	pop	si
	pop	bp
	retf
drv_real_FUN_1000_07a0	ENDP

drv_real_FUN_1000_07ac	PROC	NEAR
	sub	ax,ax
	mov	es,ax
	; The INT 0 vector, in segment zero.
	push	word ptr es:[0]
	push	word ptr es:[2]
	lea	ax,[drv_real_FUN_1000_0959]
	mov	es:[0],ax
	mov	word ptr es:[2],CODE_0
	push	ds
	pop	es
	jmp	L10834
L107ce:
	sub	ax,ax
	mov	es,ax
	pop	word ptr es:[2]
	pop	word ptr es:[0]
	push	ds
	pop	es
	mov	ax,ds:[_asm_DAT_2206_449d]
	mov	bx,word ptr ds:[_asm_DAT_2206_44a1]
	mov	cx,word ptr ds:[_asm_DAT_2206_449f]
	mov	dx,word ptr ds:[_asm_DAT_2206_44a3]
	call	far ptr drv_jump_gfx_line
	clc
	ret
L107f4:
	sub	ax,ax
	mov	es,ax
	pop	word ptr es:[2]
	pop	word ptr es:[0]
	push	ds
	pop	es
	stc
	ret
L10806:
	cmc
	rcr	dx,1
	mov	word ptr ds:[_asm_DAT_2206_4823],dx
	sar	dx,1
	mov	word ptr ds:[_asm_DAT_2206_4827],dx
	mov	dx,di
	sub	dx,bp
	jno	L1081f
	cmc
	rcr	dx,1
	jmp	L1088f
L1081f:
	sar	dx,1
	jmp	L1088f
L10824:
	cmc
	rcr	dx,1
	sar	word ptr ds:[_asm_DAT_2206_4823],1
	sar	word ptr ds:[_asm_DAT_2206_4827],1
	jmp	L1088f
L10832:
	jmp	L107f4
L10834:
	mov	cx,word ptr ds:[_asm_DAT_2206_449d]
	mov	dx,word ptr ds:[_asm_DAT_2206_44a1]
	mov	si,word ptr ds:[_asm_DAT_2206_449f]
	mov	di,word ptr ds:[_asm_DAT_2206_44a3]
	mov	bx,cx
	mov	bp,dx
	call	drv_real_FUN_1000_0938
	mov	ds:[_asm_DAT_2206_4822],al
	mov	bx,si
	mov	bp,di
	call	drv_real_FUN_1000_0938
	jnz	L10871
	cmp	byte ptr ds:[_asm_DAT_2206_4822],0
	jnz	L10861
	jmp	L107ce
L10861:
	xchg	cx,si
	xchg	dx,di
	xchg	byte ptr ds:[_asm_DAT_2206_4822],al
	mov	word ptr ds:[_asm_DAT_2206_449d],cx
	mov	word ptr ds:[_asm_DAT_2206_44a1],dx
L10871:
	test	byte ptr ds:[_asm_DAT_2206_4822],al
	jnz	L10832
	mov	bp,dx
	mov	dx,si
	sub	dx,cx
	jo	L10806
	mov	word ptr ds:[_asm_DAT_2206_4823],dx
	sar	dx,1
	mov	word ptr ds:[_asm_DAT_2206_4827],dx
	mov	dx,di
	sub	dx,bp
	jo	L10824
L1088f:
	mov	word ptr ds:[_asm_DAT_2206_4825],dx
	sar	dx,1
	mov	word ptr ds:[_asm_DAT_2206_4829],dx
L10899:
	test	al,9
	jz	L108d5
	sub	bx,bx
	or	si,si
	js	L108a7
	mov	bx,word ptr ds:[_asm_DAT_2206_482b]
L108a7:
	mov	ax,bx
	sub	ax,cx
	imul	word ptr ds:[_asm_DAT_2206_4825]
	push	bx
	mov	bx,dx
	idiv	word ptr ds:[_asm_DAT_2206_4823]
	mov	bl,bh
	xor	bl,byte ptr ds:[_asm_DAT_2206_4823+1]
	jns	L108c1
	neg	dx
	dec	ax
L108c1:
	sub	dx,word ptr ds:[_asm_DAT_2206_4827]
	xor	dh,bh
	js	L108ca
	inc	ax
L108ca:
	pop	bx
	add	ax,bp
	js	L108dd
	cmp	ax,word ptr ds:[_asm_DAT_2206_482d]
	jle	L1090e
L108d5:
	mov	bx,word ptr ds:[_asm_DAT_2206_482d]
	cmp	di,bx
	jg	L108df
L108dd:
	sub	bx,bx
L108df:
	mov	ax,bx
	sub	ax,bp
	imul	word ptr ds:[_asm_DAT_2206_4823]
	push	bx
	mov	bx,dx
L108ea:
	idiv	word ptr ds:[_asm_DAT_2206_4825]
	mov	bl,bh
	xor	bl,byte ptr ds:[_asm_DAT_2206_4825+1]
	jns	L108f9
	neg	dx
	dec	ax
L108f9:
	sub	dx,word ptr ds:[_asm_DAT_2206_4829]
	xor	dh,bh
	js	L10902
	inc	ax
L10902:
	pop	bx
	add	ax,cx
	js	L1091f
	cmp	ax,word ptr ds:[_asm_DAT_2206_482b]
	jg	L1091f
	xchg	bx,ax
L1090e:
	cmp	byte ptr ds:[_asm_DAT_2206_4822],0
	jnz	L10922
	mov	ds:[_asm_DAT_2206_44a3],ax
	mov	word ptr ds:[_asm_DAT_2206_449f],bx
	jmp	L107ce
L1091f:
	jmp	L107f4
L10922:
	mov	ds:[_asm_DAT_2206_44a1],ax
	mov	word ptr ds:[_asm_DAT_2206_449d],bx
	xchg	cx,si
	xchg	bp,di
	mov	al,ds:[_asm_DAT_2206_4822]
	mov	byte ptr ds:[_asm_DAT_2206_4822],0
	jmp	L10899
drv_real_FUN_1000_07ac	ENDP

drv_real_FUN_1000_0938	PROC	NEAR
	mov	al,0Fh
	or	bx,bx
	js	L10940
	and	al,0F7h
L10940:
	cmp	bx,word ptr ds:[_asm_DAT_2206_482b]
	jg	L10948
	and	al,0FEh
L10948:
	or	bp,bp
	js	L1094e
	and	al,0FBh
L1094e:
	cmp	bp,word ptr ds:[_asm_DAT_2206_482d]
	jg	L10956
	and	al,0FDh
L10956:
	or	al,al
	ret
drv_real_FUN_1000_0938	ENDP

drv_real_FUN_1000_0959	PROC	FAR
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+2],OFFSET L108ea
	mov	ax,ds:[_asm_DAT_2206_4825]
	jz	L10969
	mov	ax,ds:[_asm_DAT_2206_4823]
L10969:
	xor	dx,ax
	mov	ax,7F00h
	jns	L10972
	neg	ax
L10972:
	add	word ptr [bp+2],4
	sub	dx,dx
	pop	bp
	iret
drv_real_FUN_1000_0959	ENDP

_drv_real_draw_line	PROC	FAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx+6]
	mov	ds:[_asm_DAT_2206_482b],ax
	mov	ax,word ptr [bx+8]
	mov	ds:[_asm_DAT_2206_482d],ax
	call	far ptr drv_jump_gfx_select_pic
	mov	ax,word ptr [bp+8]
	mov	ds:[_asm_DAT_2206_449d],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[_asm_DAT_2206_44a1],ax
	mov	ax,word ptr [bp+0Ch]
	mov	ds:[_asm_DAT_2206_449f],ax
	mov	ax,word ptr [bp+0Eh]
	mov	ds:[_asm_DAT_2206_44a3],ax
	mov	ax,word ptr [bp+10h]
	call	far ptr drv_jump_gfx_set_colour
	call	drv_real_FUN_1000_07ac
	call	far ptr drv_jump_gfx_write_reset
	pop	di
	pop	si
	pop	bp
	retf
_drv_real_draw_line	ENDP

drv_real_FUN_1000_09bf	PROC	FAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	bx,word ptr [bp+6]
	mov	cx,word ptr [bp+8]
	or	cx,cx
	js	L109fa
	cmp	cx,word ptr [bx+6]
	jg	L109fa
	mov	dx,word ptr [bp+0Ah]
	or	dx,dx
	js	L109fa
	cmp	dx,word ptr [bx+8]
	jg	L109fa
	call	far ptr drv_jump_gfx_select_pic
	mov	ax,word ptr [bp+0Ch]
	call	far ptr drv_jump_gfx_set_colour
	mov	ax,cx
	mov	bx,dx
	call	far ptr drv_jump_gfx_plot
	call	far ptr drv_jump_gfx_write_reset
L109fa:
	pop	di
	pop	si
	pop	bp
	retf
drv_real_FUN_1000_09bf	ENDP

_drv_real_unpack_start	PROC	FAR
	push	si
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10a17
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10a17:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	mov	dx,ax
	and	al,1
	mov	ds:[DAT_2206_6fcb],al
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10a3b
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10a3b:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	mov	ds:[_shm_sprite_width],ax
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10a5b
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10a5b:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	mov	ds:[_shm_sprite_height],ax
	test	dx,8
	jz	L10a71
	add	word ptr ds:[_shm_source_at],10h
	jmp	L10a7d
L10a71:
	test	dx,10h
	jz	L10a89
	add	word ptr ds:[_shm_source_at],80h
L10a7d:
	xor	ax,ax
	push	si
	push	ax
	call	far ptr _drv_jump_gfx_set_colour_map
	add	sp,4
L10a89:
	call	drv_real_FUN_1000_0b0f
	pop	si
	retf
_drv_real_unpack_start	ENDP

_drv_real_palette_read	PROC	FAR
	push	si
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10aa7
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10aa7:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	and	al,1
	mov	ds:[DAT_2206_6fcb],al
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10ac9
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10ac9:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	mov	ds:[_shm_palette_count],ax
	call	drv_real_FUN_1000_0b0f
	pop	si
	retf
_drv_real_palette_read	ENDP

_drv_real_palette_put	PROC	FAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	si,word ptr ds:[_shm_source_at]
	les	di,[bp+6]
	mov	cx,word ptr [bp+0Ah]
	call	drv_real_FUN_1000_0b83
	mov	word ptr ds:[_shm_source_at],si
	pop	di
	pop	si
	pop	bp
	retf
_drv_real_palette_put	ENDP

_drv_real_unpack_row	PROC	FAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	ax,ds
	mov	es,ax
	mov	si,word ptr ds:[_shm_source_at]
	mov	di,word ptr [bp+6]
	mov	cx,word ptr ds:[_shm_sprite_width]
	call	drv_real_FUN_1000_0b83
	mov	word ptr ds:[_shm_source_at],si
	pop	di
	pop	si
	pop	bp
	retf
_drv_real_unpack_row	ENDP

drv_real_FUN_1000_0b0f	PROC	NEAR
	mov	byte ptr ds:[DAT_2206_6fc0],0
	mov	byte ptr ds:[DAT_2206_6fc1],0
	mov	ax,OFFSET DGROUP:asm_block_6fcf+512
	mov	ds:[DAT_2206_6fbc],ax
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10b37
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10b37:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	cmp	al,0Bh
	jbe	L10b42
	mov	al,0Bh
L10b42:
	mov	ds:[DAT_2206_6fc3],al
	mov	ds:[DAT_2206_6fc8],ax
	mov	byte ptr ds:[DAT_2206_6fca],8
drv_real_FUN_1000_0b0f	ENDP

drv_real_FUN_1000_0b4d	PROC	NEAR
	mov	byte ptr ds:[DAT_2206_6fc2],9
	mov	word ptr ds:[DAT_2206_6fc4],1FFh
	mov	dx,100h
	mov	word ptr ds:[DAT_2206_6fc6],dx
	mov	ax,0FFFFh
	xor	bx,bx
	mov	cx,800h
L10b67:
	mov	word ptr [bx+DAT_2206_57b6],ax
	add	bx,3
	loop	L10b67
	mov	al,0
	xor	bx,bx
	mov	cx,100h
L10b77:
	mov	byte ptr [bx+DAT_2206_57b8],al
	inc	al
	add	bx,3
	loop	L10b77
	ret
drv_real_FUN_1000_0b4d	ENDP

drv_real_FUN_1000_0b83	PROC	NEAR
	cmp	byte ptr ds:[DAT_2206_6fcb],0
	jz	L10b8d
	inc	cx
	shr	cx,1
L10b8d:
	mov	word ptr ds:[DAT_2206_6fbe],cx
	mov	ax,ds:[DAT_2206_6fbc]
	mov	word ptr ds:[DAT_2206_6fbc],sp
	mov	sp,ax
	mov	dx,word ptr ds:[DAT_2206_6fc6]
L10b9e:
	cmp	byte ptr ds:[DAT_2206_6fc0],0
	jnz	L10bc6
	call	drv_real_FUN_1000_0bff
	cmp	al,90h
	jz	L10bb2
	mov	ds:[DAT_2206_6fc1],al
	jmp	L10bcd
L10bb2:
	call	drv_real_FUN_1000_0bff
	or	al,al
	jnz	L10bc1
	mov	al,90h
	mov	ds:[DAT_2206_6fc1],al
	jmp	L10bcd
L10bc1:
	dec	al
	mov	ds:[DAT_2206_6fc0],al
L10bc6:
	mov	al,ds:[DAT_2206_6fc1]
	dec	byte ptr ds:[DAT_2206_6fc0]
L10bcd:
	cmp	byte ptr ds:[DAT_2206_6fcb],0
	jz	L10bea
	mov	ah,al
	and	al,0Fh
	shr	ah,1
	shr	ah,1
	shr	ah,1
	shr	ah,1
	stosw
	dec	word ptr ds:[DAT_2206_6fbe]
	jnz	L10b9e
	jmp	L10bf1
L10bea:
	stosb
	dec	word ptr ds:[DAT_2206_6fbe]
	jnz	L10b9e
L10bf1:
	mov	word ptr ds:[DAT_2206_6fc6],dx
	mov	ax,ds:[DAT_2206_6fbc]
	mov	word ptr ds:[DAT_2206_6fbc],sp
	mov	sp,ax
	ret
drv_real_FUN_1000_0b83	ENDP

drv_real_FUN_1000_0bff	PROC	NEAR
	pop	bp
	cmp	sp,OFFSET DGROUP:asm_block_6fcf+512
	jz	L10c09
L10c06:
	pop	ax
	jmp	bp
L10c09:
	mov	bx,word ptr ds:[DAT_2206_6fc8]
	mov	cl,10h
	mov	ch,byte ptr ds:[DAT_2206_6fca]
	sub	cl,ch
	shr	bx,cl
	mov	cl,ch
L10c19:
	cmp	cl,byte ptr ds:[DAT_2206_6fc2]
	jge	L10c40
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10c33
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10c33:
	lodsw
	mov	ds:[DAT_2206_6fc8],ax
	shl	ax,cl
	or	bx,ax
	add	cl,10h
	jmp	L10c19
L10c40:
	sub	cl,byte ptr ds:[DAT_2206_6fc2]
	mov	byte ptr ds:[DAT_2206_6fca],cl
	mov	ax,bx
	and	ax,word ptr ds:[DAT_2206_6fc4]
	mov	cx,ax
	cmp	ax,dx
	jl	L10c5e
	mov	cx,dx
	mov	ax,ds:[DAT_2206_6fcc]
	mov	bl,byte ptr ds:[DAT_2206_6fce]
	push	bx
L10c5e:
	mov	bx,ax
	add	bx,ax
	add	bx,ax
	mov	ax,word ptr [bx+DAT_2206_57b6]
	inc	ax
	jz	L10c73
	dec	ax
	mov	bl,byte ptr [bx+DAT_2206_57b8]
	push	bx
	jmp	L10c5e
L10c73:
	mov	al,byte ptr [bx+DAT_2206_57b8]
	mov	ds:[DAT_2206_6fce],al
	push	ax
	mov	bx,dx
	add	bx,dx
	add	bx,dx
	mov	byte ptr [bx+DAT_2206_57b8],al
	mov	ax,ds:[DAT_2206_6fcc]
	mov	word ptr [bx+DAT_2206_57b6],ax
	inc	dx
	cmp	dx,word ptr ds:[DAT_2206_6fc4]
	jle	L10c9c
	inc	byte ptr ds:[DAT_2206_6fc2]
	stc
	rcl	word ptr ds:[DAT_2206_6fc4],1
L10c9c:
	mov	al,ds:[DAT_2206_6fc2]
	cmp	al,byte ptr ds:[DAT_2206_6fc3]
	jle	L10ca8
	call	drv_real_FUN_1000_0b4d
L10ca8:
	mov	word ptr ds:[DAT_2206_6fcc],cx
	jmp	L10c06
drv_real_FUN_1000_0bff	ENDP
D10caf	DB	0,0,0,0,0

_drv_real_sprite_put	PROC	NEAR
	pop	word ptr cs:[D10caf+1]
	pop	word ptr cs:[D10caf+3]
	call	far ptr _drv_jump_gfx_sprite_put_clipped
	push	bp
	mov	bp,sp
	mov	bp,word ptr [bp+2]
	call	drv_real_FUN_1000_0cff
	pop	bp
	jmp	dword ptr cs:[D10caf+1]
_drv_real_sprite_put	ENDP

_drv_real_sprite_put_2	PROC	NEAR
	pop	word ptr cs:[D10caf+1]
	pop	word ptr cs:[D10caf+3]
	call	far ptr _drv_jump_gfx_sprite_put_clipped
	push	bp
	mov	bp,sp
	mov	bp,word ptr [bp+2]
	push	ax
	push	dx
	call	drv_real_FUN_1000_0cff
	pop	dx
	pop	ax
	xor	byte ptr [bp+0],1
	call	drv_real_FUN_1000_0cff
	xor	byte ptr [bp+0],1
	pop	bp
	jmp	dword ptr cs:[D10caf+1]
_drv_real_sprite_put_2	ENDP

drv_real_FUN_1000_0cff	PROC	NEAR
	push	es
	push	di
	push	si
	mov	si,word ptr [bp+0]
	and	si,1
	shl	si,1
	mov	bx,ax
	mov	es,dx
	mov	dx,word ptr es:[bx+4]
	dec	dx
	js	L10d62
	mov	di,word ptr es:[bx+2]
	add	di,word ptr [bp+4]
	cmp	di,word ptr [si+_asm_DAT_2206_4830]
	jnc	L10d26
	mov	word ptr [si+_asm_DAT_2206_4830],di
L10d26:
	mov	cx,word ptr es:[bx+6]
	add	cx,di
	dec	cx
	cmp	cx,word ptr [si+_asm_DAT_2206_4834]
	jbe	L10d37
	mov	word ptr [si+_asm_DAT_2206_4834],cx
L10d37:
	shl	di,1
	shl	cx,1
	mov	ax,word ptr [si+_addr_page_row_tables]
	add	di,ax
	add	cx,ax
	mov	ax,word ptr es:[bx]
	add	ax,word ptr [bp+2]
	add	dx,ax
L10d4b:
	cmp	ax,word ptr [di]
	jnc	L10d51
	mov	word ptr [di],ax
L10d51:
	cmp	dx,word ptr [di+190h]
	jbe	L10d5b
	mov	word ptr [di+190h],dx
L10d5b:
	add	di,2
	cmp	di,cx
	jbe	L10d4b
L10d62:
	pop	si
	pop	di
	pop	es
	ret
drv_real_FUN_1000_0cff	ENDP

_drv_real_page_copy	PROC	FAR
	mov	bx,sp
	push	bp
	push	si
	push	di
	mov	si,word ptr [bx+4]
	mov	di,word ptr [bx+6]
	mov	bp,di
	and	bp,1
	shl	bp,1
	mov	ax,word ptr [bp+_asm_DAT_2206_4830]
	mov	cx,word ptr [bp+_asm_DAT_2206_4834]
	mov	bx,word ptr [bp+_addr_page_row_tables]
	push	bp
	call	far ptr drv_jump_gfx_edge_copy
	pop	bp
	mov	ax,ds
	mov	es,ax
	mov	di,word ptr [bp+_asm_DAT_2206_4830]
	or	di,di
	js	L10dc1
	mov	cx,word ptr [bp+_asm_DAT_2206_4834]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,word ptr [bp+_addr_page_row_tables]
	mov	ax,0FFFFh
	rep stosw
	mov	word ptr [bp+_asm_DAT_2206_4830],ax
	mov	cx,bx
	mov	di,dx
	add	di,word ptr [bp+_addr_page_row_tables+4]
	sub	ax,ax
	rep stosw
	mov	word ptr [bp+_asm_DAT_2206_4834],ax
L10dc1:
	pop	di
	pop	si
	pop	bp
	retf
_drv_real_page_copy	ENDP

_drv_real_anim_reset	PROC	FAR
	push	si
	push	di
	mov	ax,ds
	mov	es,ax
	mov	di,word ptr ds:[_asm_DAT_2206_4830]
	or	di,di
	js	L10dfb
	mov	cx,word ptr ds:[_asm_DAT_2206_4834]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,word ptr ds:[_addr_page_row_tables]
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[_asm_DAT_2206_4830],ax
	mov	cx,bx
	mov	di,dx
	add	di,word ptr ds:[_addr_page_row_tables+4]
	sub	ax,ax
	rep stosw
	mov	ds:[_asm_DAT_2206_4834],ax
L10dfb:
	mov	di,word ptr ds:[_asm_DAT_2206_4832]
	or	di,di
	js	L10e2b
	mov	cx,word ptr ds:[_asm_DAT_2206_4836]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,word ptr ds:[_addr_page_row_tables+2]
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[_asm_DAT_2206_4832],ax
	mov	cx,bx
	mov	di,dx
	add	di,word ptr ds:[_addr_page_row_tables+6]
	sub	ax,ax
	rep stosw
	mov	ds:[_asm_DAT_2206_4836],ax
L10e2b:
	pop	di
	pop	si
	retf
_drv_real_anim_reset	ENDP

;------------------------------------------------------------------------------
; Reset the mouse through INT 33h, install drv_real_mouse_event as its
; handler, and
; take the first position. Does nothing where no driver has hooked INT 33h.
;------------------------------------------------------------------------------
drv_real_mouse_open	PROC	FAR
	xor	ax,ax
	mov	es,ax
	mov	bx,0CCh
	mov	ax,word ptr es:[bx]
	or	ax,word ptr es:[bx+2]
	jz	L10e7c
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
	or	ax,ax
	jz	L10e7c
	mov	ax,0Ch
	mov	cx,1Fh
	mov	dx,cs
	mov	es,dx
	lea	dx,[drv_real_mouse_event]
	int	33h		; mouse AX=000Ch: set user-defined event handler
	mov	ax,3
	int	33h		; mouse AX=0003h: get position and button status
	mov	word ptr ds:[DAT_2206_4e8e],0
	cmp	cx,0C8h
	jc	L10e70
	shr	cx,1
	mov	word ptr ds:[DAT_2206_4e8e],1
L10e70:
	mov	word ptr ds:[DAT_2206_4e84],bx
	mov	word ptr ds:[_asm_DAT_2206_4e80],cx
	mov	word ptr ds:[_asm_DAT_2206_4e82],dx
L10e7c:
	retf
drv_real_mouse_open	ENDP

;------------------------------------------------------------------------------
; Hide the cursor and reset the mouse driver.
;------------------------------------------------------------------------------
drv_real_mouse_close	PROC	FAR
	xor	ax,ax
	mov	es,ax
	mov	bx,0CCh
	mov	ax,word ptr es:[bx]
	or	ax,word ptr es:[bx+2]
	jz	L10e97
	call	far ptr drv_real_FUN_1000_0eb6
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
L10e97:
	retf
drv_real_mouse_close	ENDP

drv_real_FUN_1000_0e98	PROC	FAR
	xor	ax,ax
	xchg	word ptr ds:[DAT_2206_4e86],ax
	retf
drv_real_FUN_1000_0e98	ENDP

;------------------------------------------------------------------------------
; Set the cursor's hot spot and which shape to draw.
;------------------------------------------------------------------------------
drv_real_mouse_set_cursor	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	ds:[DAT_2206_4e8a],ax
	mov	ax,word ptr [bp+8]
	mov	ds:[DAT_2206_4e8c],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[DAT_2206_4e88],ax
	pop	bp
	retf
drv_real_mouse_set_cursor	ENDP

drv_real_FUN_1000_0eb6	PROC	FAR
	mov	byte ptr ds:[_asm_DAT_2206_4371],0
	call	far ptr drv_jump_gfx_overlay_remove
	retf
drv_real_FUN_1000_0eb6	ENDP

;------------------------------------------------------------------------------
; Draw the cursor at the position the last event left, and record that it is
; on.
;------------------------------------------------------------------------------
drv_real_cursor_show	PROC	FAR
	push	word ptr ds:[DAT_2206_4e88]
	mov	ax,ds:[_asm_DAT_2206_4e82]
	sub	ax,word ptr ds:[DAT_2206_4e8c]
	push	ax
	mov	ax,ds:[_asm_DAT_2206_4e80]
	sub	ax,word ptr ds:[DAT_2206_4e8a]
	push	ax
	call	far ptr drv_jump_gfx_overlay_put
	add	sp,6
	mov	byte ptr ds:[_asm_DAT_2206_4371],1
	retf
drv_real_cursor_show	ENDP

;------------------------------------------------------------------------------
; One raw INT 33h call: the arguments are AX, BX, CX and DX, and the registers
; it returns are kept for the caller.
;------------------------------------------------------------------------------
drv_real_mouse_int	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	bx,word ptr [bp+8]
	mov	cx,word ptr [bp+0Ah]
	mov	dx,word ptr [bp+0Ch]
	int	33h
	mov	ds:[DAT_2206_4e90],ax
	mov	word ptr ds:[DAT_2206_4e92],bx
	mov	word ptr ds:[DAT_2206_4e94],cx
	mov	word ptr ds:[DAT_2206_4e96],dx
	lea	ax,[DAT_2206_4e90]
	pop	bp
	retf
drv_real_mouse_int	ENDP

;------------------------------------------------------------------------------
; Put back what the cursor covered and draw it again where it now is.
;------------------------------------------------------------------------------
drv_real_cursor_redraw	PROC	FAR
	ASSUME	es:CODE_0
	push	ax
	push	dx
	push	es
	mov	ax,CODE_0
	mov	es,ax
	call	dword ptr es:[L1016f]
	push	word ptr ds:[DAT_2206_4e88]
	mov	ax,ds:[_asm_DAT_2206_4e82]
	sub	ax,word ptr ds:[DAT_2206_4e8c]
	push	ax
	mov	ax,ds:[_asm_DAT_2206_4e80]
	sub	ax,word ptr ds:[DAT_2206_4e8a]
	push	ax
	mov	ax,CODE_0
	mov	es,ax
	call	dword ptr es:[L101d8]
	add	sp,6
	pop	es
	pop	dx
	pop	ax
	retf
	ASSUME	es:NOTHING
drv_real_cursor_redraw	ENDP

;------------------------------------------------------------------------------
; The mouse driver's own callback, on its stack: record the position and the
; buttons, and redraw the cursor if it is showing.
;------------------------------------------------------------------------------
drv_real_mouse_event	PROC	FAR
	mov	di,DGROUP
	mov	ds,di
	cmp	word ptr ds:[DAT_2206_4e8e],0
	jz	L10f49
	shr	cx,1
L10f49:
	or	word ptr ds:[DAT_2206_4e86],bx
	mov	word ptr ds:[DAT_2206_4e84],bx
	mov	word ptr ds:[_asm_DAT_2206_4e80],cx
	mov	word ptr ds:[_asm_DAT_2206_4e82],dx
	test	ax,1
	jz	L10f79
	cmp	byte ptr ds:[_asm_DAT_2206_4371],0
	jz	L10f79
	mov	al,2
	xchg	byte ptr ds:[_asm_DAT_2206_4370],al
	or	al,al
	jnz	L10f79
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[_asm_DAT_2206_4370],0
L10f79:
	retf
drv_real_mouse_event	ENDP

CODE_0	ENDS

;==============================================================================
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:_TEXT, ds:DGROUP, ss:DGROUP

asm_FUN_10f7_001a	PROC	FAR
	mov	al,0
	iret
asm_FUN_10f7_001a	ENDP

_shm_hook_critical_error	PROC	NEAR
	mov	al,1
	xchg	byte ptr ds:[DAT_2206_006c],al
	or	al,al
	jnz	L10fb1
	mov	ah,35h
	mov	al,24h
	int	21h		; DOS AH=35h: get interrupt vector (AL = vector)
	mov	word ptr ds:[DAT_2206_006d],bx
	mov	word ptr ds:[DAT_2206_006d+2],es
	push	ds
	mov	ah,25h
	mov	al,24h
	lds	dx,ds:[DAT_2206_0071]
	int	21h		; DOS AH=25h: set interrupt vector (AL = vector, DS:DX = handler)
	pop	ds
L10fb1:
	ret
_shm_hook_critical_error	ENDP

_shm_unhook_critical_error	PROC	NEAR
	mov	al,0
	xchg	byte ptr ds:[DAT_2206_006c],al
	or	al,al
	jz	L10fc8
	push	ds
	mov	ah,25h
	mov	al,24h
	lds	dx,ds:[DAT_2206_006d]
	int	21h		; DOS AH=25h: set interrupt vector (AL = vector, DS:DX = handler)
	pop	ds
L10fc8:
	ret
_shm_unhook_critical_error	ENDP
D10fc9	DB	0

;;SPLIT main

;;SPLIT FUN_10f7_023e

;;SPLIT FUN_10f7_0337

;;SPLIT FUN_10f7_034e

;;SPLIT FUN_10f7_03ea

;;SPLIT FUN_10f7_03ec

;;SPLIT FUN_10f7_0470

;;SPLIT FUN_10f7_055b

;;SPLIT FUN_10f7_063f

;;SPLIT FUN_10f7_06b3

;;SPLIT FUN_10f7_070f

;;SPLIT FUN_10f7_0774

;;SPLIT FUN_10f7_07f3

;;SPLIT FUN_10f7_08a6

;;SPLIT FUN_10f7_08ee

;;SPLIT FUN_10f7_0978

;;SPLIT FUN_10f7_0c38

;;SPLIT FUN_10f7_0d7f

;;SPLIT FUN_10f7_0e3b

;;SPLIT FUN_10f7_0ec7

;;SPLIT FUN_10f7_0f0c

;;SPLIT FUN_10f7_0f7d

;;SPLIT FUN_10f7_0fb8

;;SPLIT FUN_10f7_10c7

;;SPLIT FUN_10f7_147d

;;SPLIT FUN_10f7_1608

;;SPLIT FUN_10f7_1e5a

;;SPLIT FUN_10f7_231a

;;SPLIT FUN_10f7_23c9

;;SPLIT FUN_10f7_2728

;;SPLIT FUN_10f7_28a4

;;SPLIT FUN_10f7_2eb9

;;SPLIT FUN_10f7_2f56

;;SPLIT FUN_10f7_2fb6

;;SPLIT FUN_10f7_3077

;;SPLIT FUN_10f7_323b

;;SPLIT FUN_10f7_33aa

;;SPLIT FUN_10f7_36d3

;;SPLIT FUN_10f7_3791

;;SPLIT FUN_10f7_399e

;;SPLIT FUN_10f7_39bb

;;SPLIT FUN_10f7_3a95

;;SPLIT FUN_10f7_3b76

;;SPLIT FUN_10f7_3c5d

;;SPLIT FUN_10f7_3c87

;;SPLIT FUN_10f7_3cb4

;;SPLIT FUN_10f7_3cdd

;;SPLIT FUN_10f7_3cfd

;;SPLIT FUN_10f7_3e38

;;SPLIT FUN_10f7_3f69

;;SPLIT FUN_10f7_3fa6

;;SPLIT FUN_10f7_4899

;;SPLIT FUN_10f7_49d1

;;SPLIT FUN_10f7_4a04

;;SPLIT FUN_10f7_4cf2

;;SPLIT FUN_10f7_4d4b

;;SPLIT FUN_10f7_4e4f

;;SPLIT FUN_10f7_4ef0

;;SPLIT FUN_10f7_4f52

;;SPLIT FUN_10f7_4fe9

;;SPLIT FUN_10f7_5035

;;SPLIT FUN_10f7_5393

;;SPLIT FUN_10f7_5446

;;SPLIT FUN_10f7_5513

;;SPLIT FUN_10f7_557c

;;SPLIT FUN_10f7_55b3

;;SPLIT FUN_10f7_5668

;;SPLIT FUN_10f7_56ed

;;SPLIT FUN_10f7_570d

;;SPLIT FUN_10f7_58dc

;;SPLIT FUN_10f7_5f21

;;SPLIT FUN_10f7_624a

;;SPLIT FUN_10f7_6275

;;SPLIT FUN_10f7_63ad

;;SPLIT FUN_10f7_6458

;;SPLIT FUN_10f7_6801

;;SPLIT FUN_10f7_692a

;;SPLIT FUN_10f7_6a18

;;SPLIT FUN_10f7_6c94

;;SPLIT FUN_10f7_6cfa

;;SPLIT FUN_10f7_6ff1

;;SPLIT FUN_10f7_704a

;;SPLIT FUN_10f7_7129

;;SPLIT FUN_10f7_716a

;;SPLIT FUN_10f7_736f

;;SPLIT FUN_10f7_7554

;;SPLIT FUN_10f7_780c

;;SPLIT FUN_10f7_7834

;;SPLIT FUN_10f7_790c

;;SPLIT FUN_10f7_7b7c

;;SPLIT FUN_10f7_7b99

;;SPLIT FUN_10f7_7c85

;;SPLIT FUN_10f7_7cf4

;;SPLIT FUN_10f7_7fe9

;;SPLIT FUN_10f7_801e

;;SPLIT FUN_10f7_80df

;;SPLIT FUN_10f7_8136

;;SPLIT FUN_10f7_81a6

;;SPLIT FUN_10f7_830f

;;SPLIT FUN_10f7_851f

;;SPLIT FUN_10f7_8708

;;SPLIT FUN_10f7_8755

;;SPLIT FUN_10f7_91fa

;;SPLIT FUN_10f7_92b9

;;SPLIT FUN_10f7_951c

;;SPLIT FUN_10f7_95ab

;;SPLIT FUN_10f7_9680

;;SPLIT FUN_10f7_98c8

;;SPLIT FUN_10f7_9c61

;;SPLIT FUN_10f7_9e58

;;SPLIT FUN_10f7_a43e

;;SPLIT FUN_10f7_a519

;;SPLIT FUN_10f7_a6fe

;;SPLIT FUN_10f7_a833

;;SPLIT FUN_10f7_a8ef

;;SPLIT FUN_10f7_a90c

;;SPLIT FUN_10f7_aa73

;;SPLIT FUN_10f7_aad4

;;SPLIT FUN_10f7_ae09

;;SPLIT FUN_10f7_ae62

;;SPLIT FUN_10f7_aebb

;;SPLIT FUN_10f7_b27e

;;SPLIT FUN_10f7_b3b0

;;SPLIT FUN_10f7_b3df

;;SPLIT FUN_10f7_b3f0

;;SPLIT FUN_10f7_b3fe

;;SPLIT FUN_10f7_b44a

;;SPLIT FUN_10f7_b462

;;SPLIT FUN_10f7_b515

;;SPLIT FUN_10f7_b520

;;SPLIT FUN_10f7_b5ae

;;SPLIT FUN_10f7_b5e9

;;SPLIT FUN_10f7_b611

;;SPLIT FUN_10f7_b674

;;SPLIT FUN_10f7_b6c9

;;SPLIT FUN_10f7_b6e2

;;SPLIT FUN_10f7_b6e3

;;SPLIT FUN_10f7_b7b0

;;SPLIT FUN_10f7_b7da

;;SPLIT FUN_10f7_b7f8

;;SPLIT FUN_10f7_bc66

;;SPLIT FUN_10f7_bc9d

;;SPLIT FUN_10f7_bcc8

;;SPLIT FUN_10f7_bd74

;;SPLIT FUN_10f7_bd95

;;SPLIT FUN_10f7_be08

;;SPLIT FUN_10f7_be3d

;;SPLIT FUN_10f7_bec2

;;SPLIT FUN_10f7_bf01

;;SPLIT FUN_10f7_bfa4

;;SPLIT FUN_10f7_c18d

;;SPLIT FUN_10f7_c1ca

;;SPLIT FUN_10f7_c20a

;;SPLIT FUN_10f7_c231

;;SPLIT FUN_10f7_c254

;;SPLIT FUN_10f7_c2b4

;;SPLIT FUN_10f7_c318

;;SPLIT FUN_10f7_c36e

;;SPLIT FUN_10f7_c3f5

;;SPLIT FUN_10f7_c446

;;SPLIT FUN_10f7_c4b1

;;SPLIT FUN_10f7_c527

;;SPLIT FUN_10f7_c5a2

;;SPLIT FUN_10f7_c62d

;;SPLIT FUN_10f7_c66a

;;SPLIT FUN_10f7_c68f

;;SPLIT FUN_10f7_c6ae

;;SPLIT FUN_10f7_cb7d

;;SPLIT FUN_10f7_cf2e

;;SPLIT FUN_10f7_cf86

;;SPLIT FUN_10f7_cfdf

;;SPLIT FUN_10f7_d0a0

;;SPLIT FUN_10f7_d0f2

;;SPLIT FUN_10f7_d223

;;SPLIT FUN_10f7_d24c

;;SPLIT FUN_10f7_d27f

;;SPLIT FUN_10f7_d2fc

;;SPLIT FUN_10f7_d378

;;SPLIT FUN_10f7_d39a

;;SPLIT FUN_10f7_d3ba

;;SPLIT FUN_10f7_d3db

;;SPLIT FUN_10f7_d404

;;SPLIT FUN_10f7_d43c

;;SPLIT FUN_10f7_d45a

;;SPLIT FUN_10f7_d476

;;SPLIT FUN_10f7_d4a0

;;SPLIT FUN_10f7_d4ba

;;SPLIT FUN_10f7_d4d4

;;SPLIT FUN_10f7_d4eb

;;SPLIT FUN_10f7_d504

;;SPLIT FUN_10f7_d522

;;SPLIT FUN_10f7_d582

;;SPLIT FUN_10f7_d5ac

;;SPLIT FUN_10f7_d5d0

;;SPLIT FUN_10f7_d614

;;SPLIT FUN_10f7_d65a

;;SPLIT FUN_10f7_d69c

;;SPLIT FUN_10f7_d700

;;SPLIT FUN_10f7_d740

;;SPLIT FUN_10f7_d7ac

;;SPLIT FUN_10f7_d7be

;;SPLIT FUN_10f7_d81a

;;SPLIT FUN_10f7_d87e

;;SPLIT FUN_10f7_d89c

;;SPLIT FUN_10f7_d8d0

;;SPLIT FUN_10f7_d8e0

;;SPLIT FUN_10f7_d908

;;SPLIT FUN_10f7_d92a

;;SPLIT FUN_10f7_d95a

;;SPLIT FUN_10f7_d98a

;;SPLIT FUN_10f7_d9b0

;;SPLIT FUN_10f7_da70

_TEXT	ENDS

;==============================================================================
FARDATA	SEGMENT	PARA PUBLIC 'FAR_DATA'
;==============================================================================
	ASSUME	cs:FARDATA, ds:DGROUP, ss:DGROUP
_shm_seq_data	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_FARBUF	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
DAT_20e2_080c	DB	0,0
asm_block_080e	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
DAT_20e2_0840	DB	0,0
asm_block_0842	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0

FARDATA	ENDS

;==============================================================================
_DATA	SEGMENT	WORD PUBLIC 'DATA'
;==============================================================================
DAT_2206_0042	DB	0,0
DAT_2206_0044	DB	0,0
asm_block_0046	DB	0,0,3Fh,3Fh,3Fh,3Fh,3Fh,3Fh
	DB	3Fh,3Fh,3Fh,3Fh,3Fh,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
DAT_2206_006c	DB	0
DAT_2206_006d	DB	0,0,0,0
DAT_2206_0071	DB	1Ah,0
	DW	_TEXT
asm_block_0075	DB	0
_dat_str_env_sve	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_one_moment_please	DB	4Fh,6Eh,65h,20h,6Dh,6Fh,6Dh,65h
	DB	6Eh,74h,20h,70h,6Ch,65h,61h,73h
	DB	65h,2Eh,2Eh,2Eh,0Ah,0
_shm_suspects	DB	0,0,0,0,0,0,0,0		; SUSPECT[64]
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_buildings	DB	0,0,0,0,0,0,0,0		; BUILDING[256]
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_clues_shown	DB	0,0,0,0,0,0,0,0		; SHOWN_CLUE[80]
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_jailbreak_suspect	DB	0FFh,0FFh
dat_picture_page_port	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_shd_picture_page	DW	OFFSET DGROUP:dat_picture_page_port
dat_map_page_port	DB	1,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_shd_map_page	DW	OFFSET DGROUP:dat_map_page_port
asm_block_147e	DB	0,0,1,0,2,0,0,2
	DB	0,1,3,1,2,1,0,3
	DB	0,1,11h,11h,2,0,2,3
	DB	30h,11h,13h,31h,22h,23h,33h,33h
_shd_colours_screen	DB	0,0,1,0,2,0,0,2		; COLOUR_MAP
	DB	0,1,2,3,2,1,1,3
_shd_colours_screen_2	DB	0,0,11h,11h,22h,0,0,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,22h,11h,22h,33h
D2351e	DB	0,0,11h,11h,22h,22h,22h,22h
	DB	0,22h,33h,33h,0,0,11h,33h
	DB	0,22h,0,0,0,0,0,0
	DB	0,22h,22h,0,0,0,11h,33h
	DB	0,12h,11h,10h,11h,0,12h,33h
	DB	22h,13h,33h,11h,33h,22h,33h,33h
	DB	0,12h,0,0,22h,0,0,13h
	DB	2,11h,0,0,0,0,33h,33h
_shd_colours_paper	DB	0,11h,11h,11h,22h,0,22h,12h		; COLOUR_MAP
	DB	0,11h,11h,33h,33h,22h,33h,33h
D2356e	DB	0,11h,11h,11h,22h,0,22h,12h
	DB	0,11h,11h,33h,33h,22h,33h,33h
_shd_colours_face	DB	0,11h,11h,1,22h,0,22h,22h		; COLOUR_MAP
	DB	0,11h,11h,33h,33h,33h,33h,33h
_dat_colours_statbar	DB	0,0,11h,11h,22h,0,0,11h		; COLOUR_MAP
	DB	22h,22h,33h,33h,22h,11h,22h,33h
D2359e	DB	0,0,11h,11h,22h,0,0,22h
	DB	0,22h,33h,33h,22h,11h,22h,33h
	DB	0,0,11h,11h,22h,0,0,33h
	DB	22h,22h,11h,33h,22h,33h,22h,33h
_dat_colours_hq	DB	0,11h,11h,33h,21h,0,12h,33h		; COLOUR_MAP
	DB	0,11h,11h,23h,22h,32h,33h,33h
_dat_colours_cia_entrance	DB	0,11h,11h,11h,0,0,22h,33h		; COLOUR_MAP
	DB	0,11h,11h,11h,22h,22h,33h,33h
_dat_colours_cia_office	DB	0,11h,11h,11h,0,0,22h,33h		; COLOUR_MAP
	DB	0,33h,11h,11h,22h,22h,33h,33h
_dat_colours_cia_hall	DB	0,11h,11h,11h,0,0,22h,33h		; COLOUR_MAP
	DB	0,33h,11h,11h,22h,22h,33h,33h
_dat_colours_escape_2	DB	0,11h,11h,11h,20h,0,22h,3		; COLOUR_MAP
	DB	11h,33h,11h,11h,22h,22h,33h,33h
_dat_colours_escape	DB	0,11h,11h,11h,20h,0,0,33h		; COLOUR_MAP
	DB	0,33h,11h,11h,22h,22h,33h,33h
_dat_colours_stakeout	DB	0,11h,21h,11h,20h,0,0,33h		; COLOUR_MAP
	DB	2,33h,11h,11h,22h,22h,33h,33h
_dat_colours_building	DB	0,11h,21h,11h,22h,0,22h,33h		; COLOUR_MAP[5]
	DB	22h,33h,11h,11h,22h,22h,33h,33h
	DB	0,11h,21h,11h,0,0,22h,11h
	DB	22h,11h,11h,11h,22h,22h,33h,33h
	DB	0,11h,22h,11h,0,0,22h,11h
	DB	22h,12h,11h,11h,22h,22h,33h,33h
	DB	0,0,22h,11h,0,0,22h,11h
	DB	22h,12h,11h,11h,22h,22h,33h,33h
	DB	0,0,22h,11h,22h,0,22h,11h
	DB	0,11h,11h,11h,22h,22h,33h,33h
_dat_colours_accuse	DB	0,0,22h,11h,22h,0,33h,11h		; COLOUR_MAP
	DB	22h,11h,11h,11h,22h,22h,33h,33h
_dat_colours_advice	DB	0,20h,22h,11h,0,0,22h,13h		; COLOUR_MAP
	DB	0,11h,33h,11h,22h,22h,33h,33h
_dat_colours_city_2	DB	0,22h,11h,11h,0,0,22h,11h		; COLOUR_MAP
	DB	0,11h,33h,11h,22h,22h,33h,33h
_dat_colours_building_2	DB	0,11h,11h,21h,0,0,22h,0		; COLOUR_MAP
	DB	22h,11h,33h,11h,22h,22h,33h,33h
_dat_colours_stakeout_2	DB	0,11h,11h,21h,0,0,22h,0		; COLOUR_MAP
	DB	2,33h,33h,11h,22h,22h,33h,33h
_dat_colours_accuse_2	DB	0,11h,12h,11h,22h,0,22h,33h		; COLOUR_MAP
	DB	20h,33h,11h,11h,22h,22h,33h,33h
_dat_colours_map	DB	0,12h,11h,11h,11h,0,22h,33h		; COLOUR_MAP
	DB	22h,33h,33h,11h,33h,22h,33h,33h
_dat_colours_report	DB	0,12h,11h,10h,11h,0,12h,33h		; COLOUR_MAP
	DB	22h,13h,33h,11h,33h,22h,33h,33h
_dat_colours_city	DB	0,2,11h,11h,0,0,22h,11h		; COLOUR_MAP
	DB	33h,11h,22h,11h,22h,22h,33h,33h
_dat_palette_game	DB	0,1,2,3,4,0,6,7		; PALETTE
	DB	8,9,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh
	DB	0
PALETTE_PAD_16BF	DB	0
_shd_pan_disk	DB	2,0
_dat_str_animation_pan	DB	61h,6Eh,69h,6Dh,61h,74h,69h,6Fh
	DB	6Eh,2Eh,70h,61h,6Eh,0
_dat_str_env_sve_2	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_ad_pic	DB	61h,64h,2Eh,70h,69h,63h,0
asm_block_16df	DB	0
_shd_str_newline_wrap	DB	0Ah,0
_shd_str_ellipsis_2	DB	20h,2Eh,2Eh,2Eh,20h,0
_shd_str_hideout	DB	20h,68h,69h,64h,65h,6Fh,75h,74h
	DB	0
_shd_str_agent	DB	20h,61h,67h,65h,6Eh,74h,0
_shd_str_safehouse	DB	20h,73h,61h,66h,65h,68h,6Fh,75h
	DB	73h,65h,0
_shd_str_active_cel	DB	20h,61h,63h,74h,69h,76h,65h,20h
	DB	63h,65h,6Ch,0
_shd_str_office	DB	20h,6Fh,66h,66h,69h,63h,65h,0
_dat_str_agent_2	DB	41h,67h,65h,6Eh,74h,20h,41h,0
dat_str_georgina	DB	47h,65h,6Fh,72h,67h,69h,6Eh,61h
	DB	0
dat_str_arkada	DB	41h,72h,6Bh,61h,64h,61h,0
dat_str_yuria	DB	59h,75h,72h,69h,61h,0
dat_str_anatola	DB	41h,6Eh,61h,74h,6Fh,6Ch,61h,0
dat_str_andra	DB	41h,6Eh,64h,72h,61h,0
dat_str_nikola	DB	4Eh,69h,6Bh,6Fh,6Ch,61h,0
dat_str_viktora	DB	56h,69h,6Bh,74h,6Fh,72h,61h,0
dat_str_ivana	DB	49h,76h,61h,6Eh,61h,0
dat_str_natasha	DB	4Eh,61h,74h,61h,73h,68h,61h,0
dat_str_svetlana	DB	53h,76h,65h,74h,6Ch,61h,6Eh,61h
	DB	0
dat_str_anna	DB	41h,6Eh,6Eh,61h,0
dat_str_ludmilla	DB	4Ch,75h,64h,6Dh,69h,6Ch,6Ch,61h
	DB	0
dat_str_lexandra	DB	4Ch,65h,78h,61h,6Eh,64h,72h,61h
	DB	0
dat_str_katerina	DB	4Bh,61h,74h,65h,72h,69h,6Eh,61h
	DB	0
dat_str_olga	DB	4Fh,6Ch,67h,61h,0
dat_str_nadia	DB	4Eh,61h,64h,69h,61h,0
dat_str_leona	DB	4Ch,65h,6Fh,6Eh,61h,0
dat_str_pat	DB	50h,61h,74h,0
dat_str_carla	DB	43h,61h,72h,6Ch,61h,0
dat_str_bobbie	DB	42h,6Fh,62h,62h,69h,65h,0
dat_str_jenny	DB	4Ah,65h,6Eh,6Eh,79h,0
dat_str_frieda	DB	46h,72h,69h,65h,64h,61h,0
dat_str_alice	DB	41h,6Ch,69h,63h,65h,0
dat_str_rose	DB	52h,6Fh,73h,65h,0
dat_str_deirdre	DB	44h,65h,69h,72h,64h,72h,65h,0
dat_str_martha	DB	4Dh,61h,72h,74h,68h,61h,0
dat_str_lisa	DB	4Ch,69h,73h,61h,0
dat_str_erica	DB	45h,72h,69h,63h,61h,0
dat_str_liz	DB	4Ch,69h,7Ah,0
dat_str_emma	DB	45h,6Dh,6Dh,61h,0
dat_str_isadora	DB	49h,73h,61h,64h,6Fh,72h,61h,0
dat_str_jane	DB	4Ah,61h,6Eh,65h,0
dat_str_omara	DB	4Fh,6Dh,61h,72h,61h,0
dat_str_alicia	DB	41h,6Ch,69h,63h,69h,61h,0
dat_str_hasana	DB	48h,61h,73h,61h,6Eh,61h,0
dat_str_leila	DB	4Ch,65h,69h,6Ch,61h,0
dat_str_yasria	DB	59h,61h,73h,72h,69h,61h,0
dat_str_ailha	DB	41h,69h,6Ch,68h,61h,0
dat_str_yousfa	DB	59h,6Fh,75h,73h,66h,61h,0
dat_str_aziza	DB	41h,7Ah,69h,7Ah,61h,0
dat_str_fatima	DB	46h,61h,74h,69h,6Dh,61h,0
dat_str_benazir	DB	42h,65h,6Eh,61h,7Ah,69h,72h,0
dat_str_ouida	DB	4Fh,75h,69h,64h,61h,0
dat_str_selima	DB	53h,65h,6Ch,69h,6Dh,61h,0
dat_str_ismaila	DB	49h,73h,6Dh,61h,69h,6Ch,61h,0
dat_str_persis	DB	50h,65h,72h,73h,69h,73h,0
dat_str_haurouna	DB	48h,61h,75h,72h,6Fh,75h,6Eh,61h
	DB	0
dat_str_zara	DB	5Ah,61h,72h,61h,0
dat_str_carlotta	DB	43h,61h,72h,6Ch,6Fh,74h,74h,61h
	DB	0
dat_str_josita	DB	4Ah,6Fh,73h,69h,74h,61h,0
dat_str_miguela	DB	4Dh,69h,67h,75h,65h,6Ch,61h,0
dat_str_ramona	DB	52h,61h,6Dh,6Fh,6Eh,61h,0
dat_str_luisa	DB	4Ch,75h,69h,73h,61h,0
dat_str_julia	DB	4Ah,75h,6Ch,69h,61h,0
dat_str_juanita	DB	4Ah,75h,61h,6Eh,69h,74h,61h,0
dat_str_raquel	DB	52h,61h,71h,75h,65h,6Ch,0
dat_str_isabel	DB	49h,73h,61h,62h,65h,6Ch,0
dat_str_maria	DB	4Dh,61h,72h,69h,61h,0
dat_str_elena	DB	45h,6Ch,65h,6Eh,61h,0
dat_str_linda	DB	4Ch,69h,6Eh,64h,61h,0
dat_str_carmen	DB	43h,61h,72h,6Dh,65h,6Eh,0
dat_str_agnes	DB	41h,67h,6Eh,65h,73h,0
dat_str_celeste	DB	43h,65h,6Ch,65h,73h,74h,65h,0
dat_str_phyllis	DB	50h,68h,79h,6Ch,6Ch,69h,73h,0
dat_str_georgi	DB	47h,65h,6Fh,72h,67h,69h,0
dat_str_arkady	DB	41h,72h,6Bh,61h,64h,79h,0
dat_str_yuri	DB	59h,75h,72h,69h,0
dat_str_anatol	DB	41h,6Eh,61h,74h,6Fh,6Ch,0
dat_str_andrei	DB	41h,6Eh,64h,72h,65h,69h,0
dat_str_nikita	DB	4Eh,69h,6Bh,69h,74h,61h,0
dat_str_viktor	DB	56h,69h,6Bh,74h,6Fh,72h,0
dat_str_ivan	DB	49h,76h,61h,6Eh,0
dat_str_boris	DB	42h,6Fh,72h,69h,73h,0
dat_str_nikolai	DB	4Eh,69h,6Bh,6Fh,6Ch,61h,69h,0
dat_str_grigori	DB	47h,72h,69h,67h,6Fh,72h,69h,0
dat_str_pavel	DB	50h,61h,76h,65h,6Ch,0
dat_str_mischa	DB	4Dh,69h,73h,63h,68h,61h,0
dat_str_petrov	DB	50h,65h,74h,72h,6Fh,76h,0
dat_str_vladimir	DB	56h,6Ch,61h,64h,69h,6Dh,69h,72h
	DB	0
dat_str_mikhail	DB	4Dh,69h,6Bh,68h,61h,69h,6Ch,0
dat_str_leon	DB	4Ch,65h,6Fh,6Eh,0
dat_str_ian	DB	49h,61h,6Eh,0
dat_str_carl	DB	43h,61h,72h,6Ch,0
dat_str_bob	DB	42h,6Fh,62h,0
dat_str_jim	DB	4Ah,69h,6Dh,0
dat_str_fred	DB	46h,72h,65h,64h,0
dat_str_alan	DB	41h,6Ch,61h,6Eh,0
dat_str_ralph	DB	52h,61h,6Ch,70h,68h,0
dat_str_antoine	DB	41h,6Eh,74h,6Fh,69h,6Eh,65h,0
dat_str_heinrich	DB	48h,65h,69h,6Eh,72h,69h,63h,68h
	DB	0
dat_str_eric	DB	45h,72h,69h,63h,0
dat_str_gordon	DB	47h,6Fh,72h,64h,6Fh,6Eh,0
dat_str_david	DB	44h,61h,76h,69h,64h,0
dat_str_pierre	DB	50h,69h,65h,72h,72h,65h,0
dat_str_claude	DB	43h,6Ch,61h,75h,64h,65h,0
dat_str_gerard	DB	47h,65h,72h,61h,72h,64h,0
dat_str_omar	DB	4Fh,6Dh,61h,72h,0
dat_str_ali	DB	41h,6Ch,69h,0
dat_str_hasan	DB	48h,61h,73h,61h,6Eh,0
dat_str_abdul	DB	41h,62h,64h,75h,6Ch,0
dat_str_yasr	DB	59h,61h,73h,72h,0
dat_str_abu	DB	41h,62h,75h,0
dat_str_yousf	DB	59h,6Fh,75h,73h,66h,0
dat_str_saadi	DB	53h,61h,61h,64h,69h,0
dat_str_achmet	DB	41h,63h,68h,6Dh,65h,74h,0
dat_str_ibrahim	DB	49h,62h,72h,61h,68h,69h,6Dh,0
dat_str_selim	DB	53h,65h,6Ch,69h,6Dh,0
dat_str_ismail	DB	49h,73h,6Dh,61h,69h,6Ch,0
dat_str_mahmoud	DB	4Dh,61h,68h,6Dh,6Fh,75h,64h,0
dat_str_haround	DB	48h,61h,72h,6Fh,75h,6Eh,64h,0
dat_str_suleiman	DB	53h,75h,6Ch,65h,69h,6Dh,61h,6Eh
	DB	0
dat_str_yezid	DB	59h,65h,7Ah,69h,64h,0
dat_str_carlos	DB	43h,61h,72h,6Ch,6Fh,73h,0
dat_str_jose	DB	4Ah,6Fh,73h,65h,0
dat_str_miguel	DB	4Dh,69h,67h,75h,65h,6Ch,0
dat_str_ramon	DB	52h,61h,6Dh,6Fh,6Eh,0
dat_str_luis	DB	4Ch,75h,69h,73h,0
dat_str_julio	DB	4Ah,75h,6Ch,69h,6Fh,0
dat_str_juan	DB	4Ah,75h,61h,6Eh,0
dat_str_pedro	DB	50h,65h,64h,72h,6Fh,0
dat_str_enrique	DB	45h,6Eh,72h,69h,71h,75h,65h,0
dat_str_eduardo	DB	45h,64h,75h,61h,72h,64h,6Fh,0
dat_str_arturo	DB	41h,72h,74h,75h,72h,6Fh,0
dat_str_jorge	DB	4Ah,6Fh,72h,67h,65h,0
dat_str_manuel	DB	4Dh,61h,6Eh,75h,65h,6Ch,0
dat_str_hector	DB	48h,65h,63h,74h,6Fh,72h,0
dat_str_franco	DB	46h,72h,61h,6Eh,63h,6Fh,0
dat_str_jaime	DB	4Ah,61h,69h,6Dh,65h,0
dat_str_katkov	DB	4Bh,61h,74h,6Bh,6Fh,76h,0
dat_str_gorny	DB	47h,6Fh,72h,6Eh,79h,0
dat_str_gromyko	DB	47h,72h,6Fh,6Dh,79h,6Bh,6Fh,0
dat_str_kormarov	DB	4Bh,6Fh,72h,6Dh,61h,72h,6Fh,76h
	DB	0
dat_str_molotov	DB	4Dh,6Fh,6Ch,6Fh,74h,6Fh,76h,0
dat_str_charyk	DB	43h,68h,61h,72h,79h,6Bh,0
dat_str_markov	DB	4Dh,61h,72h,6Bh,6Fh,76h,0
dat_str_filatov	DB	46h,69h,6Ch,61h,74h,6Fh,76h,0
dat_str_badenov	DB	42h,61h,64h,65h,6Eh,6Fh,76h,0
dat_str_chekhov	DB	43h,68h,65h,6Bh,68h,6Fh,76h,0
dat_str_gogol	DB	47h,6Fh,67h,6Fh,6Ch,0
dat_str_zhukov	DB	5Ah,68h,75h,6Bh,6Fh,76h,0
dat_str_nevsky	DB	4Eh,65h,76h,73h,6Bh,79h,0
dat_str_kemidov	DB	4Bh,65h,6Dh,69h,64h,6Fh,76h,0
dat_str_dubrovnik	DB	44h,75h,62h,72h,6Fh,76h,6Eh,69h
	DB	6Bh,0
dat_str_kerensky	DB	4Bh,65h,72h,65h,6Eh,73h,6Bh,79h
	DB	0
dat_str_lorenz	DB	4Ch,6Fh,72h,65h,6Eh,7Ah,0
dat_str_koch	DB	4Bh,6Fh,63h,68h,0
dat_str_baader	DB	42h,61h,61h,64h,65h,72h,0
dat_str_brown	DB	42h,72h,6Fh,77h,6Eh,0
dat_str_jones	DB	4Ah,6Fh,6Eh,65h,73h,0
dat_str_bloom	DB	42h,6Ch,6Fh,6Fh,6Dh,0
dat_str_cahill	DB	43h,61h,68h,69h,6Ch,6Ch,0
dat_str_grivas	DB	47h,72h,69h,76h,61h,73h,0
dat_str_cook	DB	43h,6Fh,6Fh,6Bh,0
dat_str_muller	DB	4Dh,75h,6Ch,6Ch,65h,72h,0
dat_str_hansen	DB	48h,61h,6Eh,73h,65h,6Eh,0
dat_str_olsen	DB	4Fh,6Ch,73h,65h,6Eh,0
dat_str_merrick	DB	4Dh,65h,72h,72h,69h,63h,6Bh,0
dat_str_ballard	DB	42h,61h,6Ch,6Ch,61h,72h,64h,0
dat_str_verne	DB	56h,65h,72h,6Eh,65h,0
dat_str_konrad	DB	4Bh,6Fh,6Eh,72h,61h,64h,0
dat_str_abbas	DB	41h,62h,62h,61h,73h,0
dat_str_said	DB	53h,61h,69h,64h,0
dat_str_daoud	DB	44h,61h,6Fh,75h,64h,0
dat_str_moussa	DB	4Dh,6Fh,75h,73h,73h,61h,0
dat_str_nidal	DB	4Eh,69h,64h,61h,6Ch,0
dat_str_khaled	DB	4Bh,68h,61h,6Ch,65h,64h,0
dat_str_hammid	DB	48h,61h,6Dh,6Dh,69h,64h,0
dat_str_afafat	DB	41h,66h,61h,66h,61h,74h,0
dat_str_agha	DB	41h,67h,68h,61h,0
dat_str_murad	DB	4Dh,75h,72h,61h,64h,0
dat_str_akbar	DB	41h,6Bh,62h,61h,72h,0
dat_str_hosayn	DB	48h,6Fh,73h,61h,79h,6Eh,0
dat_str_raisuli	DB	52h,61h,69h,73h,75h,6Ch,69h,0
dat_str_musafir	DB	4Dh,75h,73h,61h,66h,69h,72h,0
dat_str_nasr	DB	4Eh,61h,73h,72h,0
dat_str_rashid	DB	52h,61h,73h,68h,69h,64h,0
dat_str_munoz	DB	4Dh,75h,6Eh,6Fh,7Ah,0
dat_str_diaz	DB	44h,69h,61h,7Ah,0
dat_str_munoz_2	DB	4Dh,75h,6Eh,6Fh,7Ah,0
dat_str_perez	DB	50h,65h,72h,65h,7Ah,0
dat_str_ramirez	DB	52h,61h,6Dh,69h,72h,65h,7Ah,0
dat_str_alvarez	DB	41h,6Ch,76h,61h,72h,65h,7Ah,0
dat_str_garcia	DB	47h,61h,72h,63h,69h,61h,0
dat_str_lopez	DB	4Ch,6Fh,70h,65h,7Ah,0
dat_str_santos	DB	53h,61h,6Eh,74h,6Fh,73h,0
dat_str_diego	DB	44h,69h,65h,67h,6Fh,0
dat_str_cordoba	DB	43h,6Fh,72h,64h,6Fh,62h,61h,0
dat_str_valdez	DB	56h,61h,6Ch,64h,65h,7Ah,0
dat_str_santiago	DB	53h,61h,6Eh,74h,69h,61h,67h,6Fh
	DB	0
dat_str_enriquez	DB	45h,6Eh,72h,69h,71h,75h,65h,7Ah
	DB	0
dat_str_sanchez	DB	53h,61h,6Eh,63h,68h,65h,7Ah,0
dat_str_delarosa	DB	44h,65h,6Ch,61h,72h,6Fh,73h,61h
	DB	0
_dat_str_space_14	DB	20h,0,0
_dat_first_names	DW	OFFSET DGROUP:dat_str_georgina
	DW	OFFSET DGROUP:dat_str_arkada
	DW	OFFSET DGROUP:dat_str_yuria
	DW	OFFSET DGROUP:dat_str_anatola
	DW	OFFSET DGROUP:dat_str_andra
	DW	OFFSET DGROUP:dat_str_nikola
	DW	OFFSET DGROUP:dat_str_viktora
	DW	OFFSET DGROUP:dat_str_ivana
	DW	OFFSET DGROUP:dat_str_natasha
	DW	OFFSET DGROUP:dat_str_svetlana
	DW	OFFSET DGROUP:dat_str_anna
	DW	OFFSET DGROUP:dat_str_ludmilla
	DW	OFFSET DGROUP:dat_str_lexandra
	DW	OFFSET DGROUP:dat_str_katerina
	DW	OFFSET DGROUP:dat_str_olga
	DW	OFFSET DGROUP:dat_str_nadia
	DW	OFFSET DGROUP:dat_str_leona
	DW	OFFSET DGROUP:dat_str_pat
	DW	OFFSET DGROUP:dat_str_carla
	DW	OFFSET DGROUP:dat_str_bobbie
	DW	OFFSET DGROUP:dat_str_jenny
	DW	OFFSET DGROUP:dat_str_frieda
	DW	OFFSET DGROUP:dat_str_alice
	DW	OFFSET DGROUP:dat_str_rose
	DW	OFFSET DGROUP:dat_str_deirdre
	DW	OFFSET DGROUP:dat_str_martha
	DW	OFFSET DGROUP:dat_str_lisa
	DW	OFFSET DGROUP:dat_str_erica
	DW	OFFSET DGROUP:dat_str_liz
	DW	OFFSET DGROUP:dat_str_emma
	DW	OFFSET DGROUP:dat_str_isadora
	DW	OFFSET DGROUP:dat_str_jane
	DW	OFFSET DGROUP:dat_str_omara
	DW	OFFSET DGROUP:dat_str_alicia
	DW	OFFSET DGROUP:dat_str_hasana
	DW	OFFSET DGROUP:dat_str_leila
	DW	OFFSET DGROUP:dat_str_yasria
	DW	OFFSET DGROUP:dat_str_ailha
	DW	OFFSET DGROUP:dat_str_yousfa
	DW	OFFSET DGROUP:dat_str_aziza
	DW	OFFSET DGROUP:dat_str_fatima
	DW	OFFSET DGROUP:dat_str_benazir
	DW	OFFSET DGROUP:dat_str_ouida
	DW	OFFSET DGROUP:dat_str_selima
	DW	OFFSET DGROUP:dat_str_ismaila
	DW	OFFSET DGROUP:dat_str_persis
	DW	OFFSET DGROUP:dat_str_haurouna
	DW	OFFSET DGROUP:dat_str_zara
	DW	OFFSET DGROUP:dat_str_carlotta
	DW	OFFSET DGROUP:dat_str_josita
	DW	OFFSET DGROUP:dat_str_miguela
	DW	OFFSET DGROUP:dat_str_ramona
	DW	OFFSET DGROUP:dat_str_luisa
	DW	OFFSET DGROUP:dat_str_julia
	DW	OFFSET DGROUP:dat_str_juanita
	DW	OFFSET DGROUP:dat_str_raquel
	DW	OFFSET DGROUP:dat_str_isabel
	DW	OFFSET DGROUP:dat_str_maria
	DW	OFFSET DGROUP:dat_str_elena
	DW	OFFSET DGROUP:dat_str_linda
	DW	OFFSET DGROUP:dat_str_carmen
	DW	OFFSET DGROUP:dat_str_agnes
	DW	OFFSET DGROUP:dat_str_celeste
	DW	OFFSET DGROUP:dat_str_phyllis
	DW	OFFSET DGROUP:dat_str_georgi
	DW	OFFSET DGROUP:dat_str_arkady
	DW	OFFSET DGROUP:dat_str_yuri
	DW	OFFSET DGROUP:dat_str_anatol
	DW	OFFSET DGROUP:dat_str_andrei
	DW	OFFSET DGROUP:dat_str_nikita
	DW	OFFSET DGROUP:dat_str_viktor
	DW	OFFSET DGROUP:dat_str_ivan
	DW	OFFSET DGROUP:dat_str_boris
	DW	OFFSET DGROUP:dat_str_nikolai
	DW	OFFSET DGROUP:dat_str_grigori
	DW	OFFSET DGROUP:dat_str_pavel
	DW	OFFSET DGROUP:dat_str_mischa
	DW	OFFSET DGROUP:dat_str_petrov
	DW	OFFSET DGROUP:dat_str_vladimir
	DW	OFFSET DGROUP:dat_str_mikhail
	DW	OFFSET DGROUP:dat_str_leon
	DW	OFFSET DGROUP:dat_str_ian
	DW	OFFSET DGROUP:dat_str_carl
	DW	OFFSET DGROUP:dat_str_bob
	DW	OFFSET DGROUP:dat_str_jim
	DW	OFFSET DGROUP:dat_str_fred
	DW	OFFSET DGROUP:dat_str_alan
	DW	OFFSET DGROUP:dat_str_ralph
	DW	OFFSET DGROUP:dat_str_antoine
	DW	OFFSET DGROUP:dat_str_heinrich
	DW	OFFSET DGROUP:dat_str_eric
	DW	OFFSET DGROUP:dat_str_gordon
	DW	OFFSET DGROUP:dat_str_david
	DW	OFFSET DGROUP:dat_str_pierre
	DW	OFFSET DGROUP:dat_str_claude
	DW	OFFSET DGROUP:dat_str_gerard
	DW	OFFSET DGROUP:dat_str_omar
	DW	OFFSET DGROUP:dat_str_ali
	DW	OFFSET DGROUP:dat_str_hasan
	DW	OFFSET DGROUP:dat_str_abdul
	DW	OFFSET DGROUP:dat_str_yasr
	DW	OFFSET DGROUP:dat_str_abu
	DW	OFFSET DGROUP:dat_str_yousf
	DW	OFFSET DGROUP:dat_str_saadi
	DW	OFFSET DGROUP:dat_str_achmet
	DW	OFFSET DGROUP:dat_str_ibrahim
	DW	OFFSET DGROUP:dat_str_selim
	DW	OFFSET DGROUP:dat_str_ismail
	DW	OFFSET DGROUP:dat_str_mahmoud
	DW	OFFSET DGROUP:dat_str_haround
	DW	OFFSET DGROUP:dat_str_suleiman
	DW	OFFSET DGROUP:dat_str_yezid
	DW	OFFSET DGROUP:dat_str_carlos
	DW	OFFSET DGROUP:dat_str_jose
	DW	OFFSET DGROUP:dat_str_miguel
	DW	OFFSET DGROUP:dat_str_ramon
	DW	OFFSET DGROUP:dat_str_luis
	DW	OFFSET DGROUP:dat_str_julio
	DW	OFFSET DGROUP:dat_str_juan
	DW	OFFSET DGROUP:dat_str_pedro
	DW	OFFSET DGROUP:dat_str_enrique
	DW	OFFSET DGROUP:dat_str_eduardo
	DW	OFFSET DGROUP:dat_str_arturo
	DW	OFFSET DGROUP:dat_str_jorge
	DW	OFFSET DGROUP:dat_str_manuel
	DW	OFFSET DGROUP:dat_str_hector
	DW	OFFSET DGROUP:dat_str_franco
	DW	OFFSET DGROUP:dat_str_jaime
_dat_last_names	DW	OFFSET DGROUP:dat_str_katkov
	DW	OFFSET DGROUP:dat_str_gorny
	DW	OFFSET DGROUP:dat_str_gromyko
	DW	OFFSET DGROUP:dat_str_kormarov
	DW	OFFSET DGROUP:dat_str_molotov
	DW	OFFSET DGROUP:dat_str_charyk
	DW	OFFSET DGROUP:dat_str_markov
	DW	OFFSET DGROUP:dat_str_filatov
	DW	OFFSET DGROUP:dat_str_badenov
	DW	OFFSET DGROUP:dat_str_chekhov
	DW	OFFSET DGROUP:dat_str_gogol
	DW	OFFSET DGROUP:dat_str_zhukov
	DW	OFFSET DGROUP:dat_str_nevsky
	DW	OFFSET DGROUP:dat_str_kemidov
	DW	OFFSET DGROUP:dat_str_dubrovnik
	DW	OFFSET DGROUP:dat_str_kerensky
	DW	OFFSET DGROUP:dat_str_lorenz
	DW	OFFSET DGROUP:dat_str_koch
	DW	OFFSET DGROUP:dat_str_baader
	DW	OFFSET DGROUP:dat_str_brown
	DW	OFFSET DGROUP:dat_str_jones
	DW	OFFSET DGROUP:dat_str_bloom
	DW	OFFSET DGROUP:dat_str_cahill
	DW	OFFSET DGROUP:dat_str_grivas
	DW	OFFSET DGROUP:dat_str_cook
	DW	OFFSET DGROUP:dat_str_muller
	DW	OFFSET DGROUP:dat_str_hansen
	DW	OFFSET DGROUP:dat_str_olsen
	DW	OFFSET DGROUP:dat_str_merrick
	DW	OFFSET DGROUP:dat_str_ballard
	DW	OFFSET DGROUP:dat_str_verne
	DW	OFFSET DGROUP:dat_str_konrad
	DW	OFFSET DGROUP:dat_str_abbas
	DW	OFFSET DGROUP:dat_str_said
	DW	OFFSET DGROUP:dat_str_daoud
	DW	OFFSET DGROUP:dat_str_moussa
	DW	OFFSET DGROUP:dat_str_nidal
	DW	OFFSET DGROUP:dat_str_khaled
	DW	OFFSET DGROUP:dat_str_hammid
	DW	OFFSET DGROUP:dat_str_afafat
	DW	OFFSET DGROUP:dat_str_agha
	DW	OFFSET DGROUP:dat_str_murad
	DW	OFFSET DGROUP:dat_str_akbar
	DW	OFFSET DGROUP:dat_str_hosayn
	DW	OFFSET DGROUP:dat_str_raisuli
	DW	OFFSET DGROUP:dat_str_musafir
	DW	OFFSET DGROUP:dat_str_nasr
	DW	OFFSET DGROUP:dat_str_rashid
	DW	OFFSET DGROUP:dat_str_munoz
	DW	OFFSET DGROUP:dat_str_diaz
	DW	OFFSET DGROUP:dat_str_munoz_2
	DW	OFFSET DGROUP:dat_str_perez
	DW	OFFSET DGROUP:dat_str_ramirez
	DW	OFFSET DGROUP:dat_str_alvarez
	DW	OFFSET DGROUP:dat_str_garcia
	DW	OFFSET DGROUP:dat_str_lopez
	DW	OFFSET DGROUP:dat_str_santos
	DW	OFFSET DGROUP:dat_str_diego
	DW	OFFSET DGROUP:dat_str_cordoba
	DW	OFFSET DGROUP:dat_str_valdez
	DW	OFFSET DGROUP:dat_str_santiago
	DW	OFFSET DGROUP:dat_str_enriquez
	DW	OFFSET DGROUP:dat_str_sanchez
	DW	OFFSET DGROUP:dat_str_delarosa
_dat_str_master_plan	DB	4Dh,61h,73h,74h,65h,72h,20h,50h
	DB	6Ch,61h,6Eh,0
_dat_str_secret	DB	2Dh,2Dh,53h,45h,43h,52h,45h,54h
	DB	2Dh,2Dh,0
_dat_str_arrested	DB	41h,52h,52h,45h,53h,54h,45h,44h
	DB	0
_dat_str_hiding	DB	49h,4Eh,20h,48h,49h,44h,49h,4Eh
	DB	47h,0
_dat_str_turned	DB	20h,54h,55h,52h,4Eh,45h,44h,0
_dat_str_personnel_file	DB	50h,65h,72h,73h,6Fh,6Eh,6Eh,65h
	DB	6Ch,20h,46h,69h,6Ch,65h,0
_dat_str_action_team	DB	20h,41h,63h,74h,69h,6Fh,6Eh,20h
	DB	54h,65h,61h,6Dh,0
_dat_str_comma_4	DB	2Ch,20h,0
_dat_str_no_activity	DB	28h,4Eh,6Fh,20h,61h,63h,74h,69h
	DB	76h,69h,74h,79h,29h,0
asm_block_1e09	DB	0
_shd_clock_text	DB	30h,30h,3Ah,30h,30h,3Ah,30h,30h
	DB	0
asm_block_1e13	DB	0
_shd_str_incoming_msg	DB	49h,6Eh,63h,6Fh,6Dh,69h,6Eh,67h
	DB	20h,4Dh,73h,67h,0
asm_block_1e21	DB	0
_shd_list_printout	DB	1,0,0,0,36h,0,3Fh,1
	DB	37h,0,8,0,1,0,0,0
	DB	38h,0,3Fh,1,0C7h,0,7,0
	DB	0,0,0,0,0A9h,0,3Fh,1
	DB	0A9h,0,8,0,0,0,0,0
	DB	38h,0,0,0,38h,0,7,0
	DB	0,0,0,0,39h,0,0,0
	DB	0A7h,0,0Fh,0,0,0,0,0
	DB	0A8h,0,0,0,0A8h,0,7,0
	DB	0,0,1,0,38h,0,1,0
	DB	0A8h,0,8,0,0,0,1,0
	DB	0A9h,0,1,0,0A9h,0,5,0
	DB	2,0,8,0,0,0,28h,0
	DB	5,0,0,0,1,0,1Fh,0
	DB	62h,0,22h,1,0A5h,0,7,0
	DB	0,0,1Fh,0,61h,0,22h,1
	DB	61h,0,5,0,1,0,1Eh,0
	DB	0A6h,0,23h,1,0A8h,0,5,0
	DB	0,0,1Fh,0,71h,0,1Fh,0
	DB	0A6h,0,8,0,0,0,23h,1
	DB	61h,0,23h,1,0A7h,0,8,0
	DB	0,0,22h,1,71h,0,22h,1
	DB	0A6h,0,8,0,0,0,1Eh,0
	DB	61h,0,1Eh,0,0A7h,0,8,0
	DB	1,0,21h,0,0A0h,0,20h,1
	DB	0A5h,0,8,0,1,0,32h,0
	DB	0A3h,0,0Dh,1,0A6h,0,7,0
	DB	0,0,0Eh,1,0A6h,0,0Eh,1
	DB	0A6h,0,8,0,0,0,32h,0
	DB	0A7h,0,0Eh,1,0A7h,0,8,0
	DB	0,0,0Eh,1,0A6h,0,0Eh,1
	DB	0A6h,0,8,0,0,0,32h,0
	DB	0A7h,0,0Eh,1,0A7h,0,8,0
	DB	0,0,1Eh,0,0A9h,0,23h,1
	DB	0A9h,0,7,0,0,0,0,0
	DB	0B1h,0,3Fh,1,0B1h,0,0Fh,0
	DB	1,0,4,0,0B8h,0,7Ch,0
	DB	0C3h,0,5,0,1,0,7Bh,0
	DB	0B9h,0,7Ch,0,0C2h,0,8,0
	DB	1,0,6,0,0B9h,0,7Ah,0
	DB	0C2h,0,2,0,0,0,4,0
	DB	0C4h,0,7Ch,0,0C4h,0,0Fh,0
	DB	1,0,92h,0,0B7h,0,0B2h,0
	DB	0C4h,0,5,0,1,0,94h,0
	DB	0B8h,0,0B0h,0,0C2h,0,7,0
	DB	0,0,93h,0,0B8h,0,93h,0
	DB	0C2h,0,0Fh,0,0,0,94h,0
	DB	0B9h,0,94h,0,0C1h,0,0Fh,0
	DB	0,0,95h,0,0B9h,0,0AEh,0
	DB	0B9h,0,0Fh,0,0,0,0B0h,0
	DB	0B9h,0,0B0h,0,0C1h,0,8,0
	DB	0,0,0B1h,0,0B8h,0,0B1h,0
	DB	0C2h,0,8,0,2,0,29h,0
	DB	0,0,3,0,7,0,0,0
	DB	0,0,0Eh,1,0B8h,0,3Fh,1
	DB	0B8h,0,5,0,1,0,0Eh,1
	DB	0B9h,0,3Fh,1,0C7h,0,8,0
	DB	1,0,10h,1,0C5h,0,3Fh,1
	DB	0C7h,0,7,0,1,0,12h,1
	DB	0BDh,0,27h,1,0C1h,0,5,0
	DB	1,0,12h,1,0BCh,0,26h,1
	DB	0C0h,0,3,0,0,0,11h,1
	DB	0BCh,0,11h,1,0C0h,0,0Bh,0
	DB	0,0,12h,1,0BCh,0,25h,1
	DB	0BCh,0,0Bh,0,1,0,2Fh,1
	DB	0BDh,0,33h,1,0C1h,0,5,0
	DB	1,0,2Fh,1,0BCh,0,32h,1
	DB	0C0h,0,4,0,0,0,2Eh,1
	DB	0BCh,0,2Eh,1,0C0h,0,0Ch,0
	DB	0,0,2Fh,1,0BCh,0,31h,1
	DB	0BCh,0,0Ch,0,2,0,9,0
	DB	0,0,2,0,4,0,0,0
	DB	0FFh,0FFh,0,0,0,0,0,0
	DB	0,0,0,0
_dat_str_warning_pan	DB	77h,61h,72h,6Eh,69h,6Eh,67h,2Eh
	DB	70h,61h,6Eh,0
_dat_str_jailbreak	DB	4Ah,61h,69h,6Ch,42h,72h,65h,61h
	DB	6Bh,20h,69h,6Eh,20h,0
_dat_str_bang_nl	DB	21h,0Ah,0
_dat_str_agents_trying_free	DB	20h,61h,67h,65h,6Eh,74h,73h,0Ah
	DB	61h,72h,65h,20h,74h,72h,79h,69h
	DB	6Eh,67h,20h,74h,6Fh,0Ah,66h,72h
	DB	65h,65h,20h,0
_dat_str_bang_nl_2	DB	21h,0Ah,0
_dat_str_bustout_pan	DB	62h,75h,73h,74h,6Fh,75h,74h,2Eh
	DB	70h,61h,6Eh,0
_dat_str_escapes	DB	20h,65h,73h,63h,61h,70h,65h,73h
	DB	21h,0Ah,0
_dat_str_escape_attempt_foiled	DB	45h,73h,63h,61h,70h,65h,20h,61h
	DB	74h,74h,65h,6Dh,70h,74h,20h,66h
	DB	6Fh,69h,6Ch,65h,64h,21h,0Ah,0
_dat_str_car_tracer_leads_new	DB	59h,6Fh,75h,72h,20h,63h,61h,72h
	DB	20h,74h,72h,61h,63h,65h,72h,20h
	DB	6Ch,65h,61h,64h,73h,0Ah,79h,6Fh
	DB	75h,20h,74h,6Fh,20h,61h,20h,6Eh
	DB	65h,77h,20h,62h,75h,69h,6Ch,64h
	DB	69h,6Eh,67h,2Eh,0Ah,0
_dat_str_carcap	DB	2Ah,63h,61h,72h,63h,61h,70h,0
_dat_str_wounded_pan	DB	77h,6Fh,75h,6Eh,64h,65h,64h,2Eh
	DB	70h,61h,6Eh,0
_dat_str_take_time_recover_from	DB	59h,6Fh,75h,20h,74h,61h,6Bh,65h
	DB	20h,74h,69h,6Dh,65h,0Ah,74h,6Fh
	DB	20h,72h,65h,63h,6Fh,76h,65h,72h
	DB	20h,66h,72h,6Fh,6Dh,0Ah,79h,6Fh
	DB	75h,72h,20h,77h,6Fh,75h,6Eh,64h
	DB	73h,0Ah,0
_dat_str_surprisel	DB	2Ah,73h,75h,72h,70h,72h,69h,73h
	DB	65h,4Ch,0
_dat_str_surprisew	DB	2Ah,73h,75h,72h,70h,72h,69h,73h
	DB	65h,57h,0
_dat_str_you_are_in	DB	59h,6Fh,75h,20h,61h,72h,65h,20h
	DB	69h,6Eh,20h,0
_dat_str_do_go	DB	0Ah,44h,6Fh,20h,79h,6Fh,75h,20h
	DB	67h,6Fh,20h,74h,6Fh,20h,2Eh,2Eh
	DB	2Eh,0Ah,0
_dat_str_airport	DB	20h,54h,68h,65h,20h,41h,69h,72h
	DB	70h,6Fh,72h,74h,2Eh,0Ah,0
_dat_str_hotel	DB	20h,59h,6Fh,75h,72h,20h,48h,6Fh
	DB	74h,65h,6Ch,2Eh,0Ah,20h,0
_dat_str_unknown_building	DB	75h,6Eh,6Bh,6Eh,6Fh,77h,6Eh,20h
	DB	62h,75h,69h,6Ch,64h,69h,6Eh,67h
	DB	0
_dat_str_nl_space	DB	0Ah,20h,0
_dat_str_nl_space_2	DB	0Ah,20h,0
_dat_str_check_data	DB	43h,68h,65h,63h,6Bh,20h,44h,61h
	DB	74h,61h,0Ah,0
_dat_str_surprise	DB	2Ah,73h,75h,72h,70h,72h,69h,73h
	DB	65h,0
_dat_str_at	DB	59h,6Fh,75h,20h,61h,72h,65h,20h
	DB	61h,74h,20h,74h,68h,65h,0Ah,0
_dat_str_unknown_building_2	DB	75h,6Eh,6Bh,6Eh,6Fh,77h,6Eh,20h
	DB	62h,75h,69h,6Ch,64h,69h,6Eh,67h
	DB	0
_dat_str_few_guards_peering	DB	0Ah,41h,20h,66h,65h,77h,20h,67h
	DB	75h,61h,72h,64h,73h,20h,61h,72h
	DB	65h,0Ah,70h,65h,65h,72h,69h,6Eh
	DB	67h,20h,74h,68h,72h,6Fh,75h,67h
	DB	68h,20h,74h,68h,65h,0Ah,77h,69h
	DB	6Eh,64h,6Fh,77h,73h,2Eh,0
_dat_str_appears_extra_guards	DB	0Ah,49h,74h,20h,61h,70h,70h,65h
	DB	61h,72h,73h,20h,65h,78h,74h,72h
	DB	61h,0Ah,67h,75h,61h,72h,64h,73h
	DB	20h,68h,61h,76h,65h,20h,62h,65h
	DB	65h,6Eh,0Ah,70h,6Fh,73h,74h,65h
	DB	64h,2Eh,0
_dat_str_building_swarming	DB	0Ah,54h,68h,65h,20h,62h,75h,69h
	DB	6Ch,64h,69h,6Eh,67h,20h,69h,73h
	DB	0Ah,73h,77h,61h,72h,6Dh,69h,6Eh
	DB	67h,20h,77h,69h,74h,68h,20h,67h
	DB	75h,61h,72h,64h,73h,2Eh,0
_dat_str_do_place_wiretap	DB	0Ah,44h,6Fh,20h,79h,6Fh,75h,20h
	DB	2Eh,2Eh,2Eh,0Ah,20h,50h,6Ch,61h
	DB	63h,65h,20h,77h,69h,72h,65h,74h
	DB	61h,70h,0Ah,0
_dat_str_break_into_building	DB	20h,42h,72h,65h,61h,6Bh,20h,69h
	DB	6Eh,74h,6Fh,20h,62h,75h,69h,6Ch
	DB	64h,69h,6Eh,67h,0Ah,0
_dat_str_watch_building_check	DB	20h,57h,61h,74h,63h,68h,20h,74h
	DB	68h,65h,20h,62h,75h,69h,6Ch,64h
	DB	69h,6Eh,67h,0Ah,20h,43h,68h,65h
	DB	63h,6Bh,20h,44h,61h,74h,61h,0Ah
	DB	20h,4Ch,65h,61h,76h,65h,0Ah,0
_dat_str_blding01_pan	DB	62h,6Ch,64h,69h,6Eh,67h,30h,31h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_sneakin_pic	DB	73h,6Eh,65h,61h,6Bh,69h,6Eh,2Eh
	DB	70h,69h,63h,0
_dat_str_wiretap_pic	DB	77h,69h,72h,65h,74h,61h,70h,2Eh
	DB	70h,69h,63h,0
_dat_str_guards	DB	54h,68h,65h,20h,67h,75h,61h,72h
	DB	64h,73h,20h,61h,72h,65h,20h,0
_dat_str_will_have	DB	2Eh,0Ah,59h,6Fh,75h,20h,77h,69h
	DB	6Ch,6Ch,20h,68h,61h,76h,65h,20h
	DB	0
_dat_str_minutes	DB	20h,6Dh,69h,6Eh,75h,74h,65h,73h
	DB	2Eh,0Ah,0
_dat_str_followed_pan	DB	66h,6Fh,6Ch,6Ch,6Fh,77h,65h,64h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_followed	DB	2Ah,66h,6Fh,6Ch,6Ch,6Fh,77h,65h
	DB	64h,0
_dat_str_hq_pan	DB	68h,71h,2Eh,70h,61h,6Eh,0
_dat_str_arrive_at_cia_building	DB	59h,6Fh,75h,20h,61h,72h,72h,69h
	DB	76h,65h,20h,61h,74h,0Ah,74h,68h
	DB	65h,20h,43h,49h,41h,20h,62h,75h
	DB	69h,6Ch,64h,69h,6Eh,67h,0Ah,61h
	DB	6Eh,64h,20h,63h,68h,65h,63h,6Bh
	DB	20h,77h,69h,74h,68h,0Ah,79h,6Fh
	DB	75h,72h,20h,63h,6Fh,6Eh,74h,61h
	DB	63h,74h,2Eh,0Ah,0
_dat_str_binos3_pan	DB	62h,69h,6Eh,6Fh,73h,33h,2Eh,70h
	DB	61h,6Eh,0
_dat_str_notice_someone	DB	59h,6Fh,75h,20h,6Eh,6Fh,74h,69h
	DB	63h,65h,20h,73h,6Fh,6Dh,65h,6Fh
	DB	6Eh,65h,0
_dat_str_leaving_building	DB	0Ah,6Ch,65h,61h,76h,69h,6Eh,67h
	DB	20h,74h,68h,65h,20h,62h,75h,69h
	DB	6Ch,64h,69h,6Eh,67h,2Eh,0Ah,0
_dat_str_do_wait_follow_car	DB	44h,6Fh,20h,79h,6Fh,75h,20h,2Eh
	DB	2Eh,2Eh,0Ah,20h,57h,61h,69h,74h
	DB	0Ah,20h,46h,6Fh,6Ch,6Ch,6Fh,77h
	DB	20h,63h,61h,72h,2Eh,0Ah,20h,54h
	DB	72h,61h,63h,65h,20h,63h,61h,72h
	DB	2Eh,0Ah,20h,43h,68h,65h,63h,6Bh
	DB	20h,44h,61h,74h,61h,0Ah,0
_dat_str_he_looks	DB	48h,65h,20h,6Ch,6Fh,6Fh,6Bh,73h
	DB	20h,0
_dat_str_she_looks	DB	53h,68h,65h,20h,6Ch,6Fh,6Fh,6Bh
	DB	73h,20h,0
_dat_str_nl_dot	DB	0Ah,2Eh,0
_dat_str_bugcar_pan	DB	62h,75h,67h,63h,61h,72h,2Eh,70h
	DB	61h,6Eh,0
_dat_str_briefing_pan	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_good_job_max_found	DB	47h,6Fh,6Fh,64h,20h,6Ah,6Fh,62h
	DB	20h,4Dh,61h,78h,2Ch,20h,59h,6Fh
	DB	75h,20h,66h,6Fh,75h,6Eh,64h,20h
	DB	74h,68h,65h,0Ah,0
_dat_str_should_really_slow_down	DB	21h,2Eh,20h,54h,68h,61h,74h,20h
	DB	73h,68h,6Fh,75h,6Ch,64h,20h,72h
	DB	65h,61h,6Ch,6Ch,79h,0Ah,73h,6Ch
	DB	6Fh,77h,20h,64h,6Fh,77h,6Eh,20h
	DB	74h,68h,65h,69h,72h,20h,6Fh,70h
	DB	65h,72h,61h,74h,69h,6Fh,6Eh,2Eh
	DB	0Ah,0
_dat_str_intrgate_pan	DB	69h,6Eh,74h,72h,67h,61h,74h,65h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_accuse	DB	59h,6Fh,75h,20h,61h,63h,63h,75h
	DB	73h,65h,20h,0
_dat_str_taking_part_plot_we	DB	0Ah,6Fh,66h,20h,74h,61h,6Bh,69h
	DB	6Eh,67h,20h,70h,61h,72h,74h,20h
	DB	69h,6Eh,0Ah,74h,68h,65h,20h,70h
	DB	6Ch,6Fh,74h,2Ch,20h,27h,57h,65h
	DB	20h,6Bh,6Eh,6Fh,77h,0Ah,74h,68h
	DB	61h,74h,20h,79h,6Fh,75h,72h,20h
	DB	72h,6Fh,6Ch,65h,20h,77h,61h,73h
	DB	3Ah,0Ah,0
_dat_str_dot_quote_nl	DB	2Eh,27h,0Ah,0
_dat_str_have_no_evidence	DB	59h,6Fh,75h,20h,68h,61h,76h,65h
	DB	20h,6Eh,6Fh,20h,65h,76h,69h,64h
	DB	65h,6Eh,63h,65h,0Ah,61h,67h,61h
	DB	69h,6Eh,73h,74h,20h,0
_dat_str_dot_nl_he	DB	2Eh,0Ah,48h,65h,0
_dat_str_dot_nl_she	DB	2Eh,0Ah,53h,68h,65h,0
_dat_str_will_have_released	DB	20h,77h,69h,6Ch,6Ch,20h,68h,61h
	DB	76h,65h,20h,74h,6Fh,0Ah,62h,65h
	DB	20h,72h,65h,6Ch,65h,61h,73h,65h
	DB	64h,2Eh,0Ah,0
_dat_str_inter1	DB	2Ah,69h,6Eh,74h,65h,72h,31h,0
_dat_str_doublea	DB	2Ah,64h,6Fh,75h,62h,6Ch,65h,61h
	DB	0
_dat_str_inter2	DB	2Ah,69h,6Eh,74h,65h,72h,32h,0
_dat_str_ask	DB	2Ch,22h,20h,79h,6Fh,75h,20h,61h
	DB	73h,6Bh,2Eh,20h,0
_dat_str_oh_yeah_i_guess	DB	22h,4Fh,68h,20h,79h,65h,61h,68h
	DB	2Ch,20h,49h,20h,67h,75h,65h,73h
	DB	73h,20h,49h,20h,64h,69h,64h,2Ch
	DB	22h,20h,74h,68h,65h,20h,70h,72h
	DB	69h,73h,6Fh,6Eh,65h,72h,20h,72h
	DB	65h,73h,70h,6Fh,6Eh,64h,73h,2Eh
	DB	0Ah,0
_dat_str_hmmm_i_don_t	DB	22h,48h,6Dh,6Dh,6Dh,2Eh,2Eh,2Eh
	DB	2Ch,20h,49h,20h,64h,6Fh,6Eh,27h
	DB	74h,20h,73h,65h,65h,6Dh,20h,74h
	DB	6Fh,20h,72h,65h,6Dh,65h,6Dh,62h
	DB	65h,72h,2Eh,22h,2Ch,20h,74h,68h
	DB	65h,20h,73h,75h,73h,70h,65h,63h
	DB	74h,20h,72h,65h,73h,70h,6Fh,6Eh
	DB	64h,73h,2Eh,0Ah,0
_dat_str_mastermind_breaks_down	DB	54h,68h,65h,20h,4Dh,61h,73h,74h
	DB	65h,72h,4Dh,69h,6Eh,64h,20h,62h
	DB	72h,65h,61h,6Bh,73h,20h,64h,6Fh
	DB	77h,6Eh,20h,61h,6Eh,64h,20h,6Ch
	DB	69h,73h,74h,73h,20h,74h,68h,65h
	DB	20h,70h,61h,72h,74h,69h,63h,69h
	DB	70h,61h,6Eh,74h,73h,20h,69h,6Eh
	DB	20h,74h,68h,65h,20h,70h,6Ch,6Fh
	DB	74h,2Eh,0
_dat_str_injail_pan	DB	69h,6Eh,6Ah,61h,69h,6Ch,2Eh,70h
	DB	61h,6Eh,0
_dat_str_taken_local_jail	DB	0Ah,69h,73h,20h,74h,61h,6Bh,65h
	DB	6Eh,20h,74h,6Fh,0Ah,74h,68h,65h
	DB	20h,6Ch,6Fh,63h,61h,6Ch,20h,6Ah
	DB	61h,69h,6Ch,2Eh,0Ah,0
_dat_str_briefing_pan_2	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_nice0	DB	2Ah,6Eh,69h,63h,65h,30h,0
_dat_str_prose_dta	DB	70h,72h,6Fh,73h,65h,2Eh,64h,74h
	DB	61h,0
_dat_msg_rplc	DB	24h,52h,50h,4Ch,43h,0
_dat_str_max_remington	DB	4Dh,61h,78h,20h,52h,65h,6Dh,69h
	DB	6Eh,67h,74h,6Fh,6Eh,0
_dat_msg_name	DB	24h,4Eh,41h,4Dh,45h,0
_dat_msg_city	DB	24h,43h,49h,54h,59h,0
_dat_msg_org	DB	24h,4Fh,52h,47h,0
_dat_key_us	DB	24h,55h,53h,0
_dat_str_surndr01_pan	DB	73h,75h,72h,6Eh,64h,72h,30h,31h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_grilled	DB	2Ah,67h,72h,69h,6Ch,6Ch,65h,64h
	DB	0
_dat_str_warning_pan_2	DB	77h,61h,72h,6Eh,69h,6Eh,67h,2Eh
	DB	70h,61h,6Eh,0
_dat_str_jailbreak_2	DB	4Ah,61h,69h,6Ch,42h,72h,65h,61h
	DB	6Bh,20h,69h,6Eh,20h,0
_dat_str_bang_nl_3	DB	21h,0Ah,0
_dat_str_agents_free	DB	20h,61h,67h,65h,6Eh,74h,73h,0Ah
	DB	66h,72h,65h,65h,20h,0
_dat_str_bang_nl_4	DB	21h,0Ah,0
_dat_str_escape_pan	DB	65h,73h,63h,61h,70h,65h,2Eh,70h
	DB	61h,6Eh,0
_dat_str_escape	DB	2Ah,65h,73h,63h,61h,70h,65h,0
_dat_str_no_thanks_squinty_agree	DB	20h,4Eh,6Fh,20h,74h,68h,61h,6Eh
	DB	6Bh,73h,2Ch,20h,53h,71h,75h,69h
	DB	6Eh,74h,79h,2Eh,0Ah,20h,41h,67h
	DB	72h,65h,65h,20h,74h,6Fh,20h,65h
	DB	78h,63h,68h,61h,6Eh,67h,65h,2Eh
	DB	0Ah,0
_dat_str_exchanged	DB	59h,6Fh,75h,20h,61h,72h,65h,20h
	DB	65h,78h,63h,68h,61h,6Eh,67h,65h
	DB	64h,0Ah,66h,6Fh,72h,20h,0
_dat_str_dot_nl	DB	2Eh,0Ah,0
_dat_str_two_double_agents	DB	74h,77h,6Fh,20h,64h,6Fh,75h,62h
	DB	6Ch,65h,20h,61h,67h,65h,6Eh,74h
	DB	73h,2Eh,0Ah,0
_dat_str_europe_pic	DB	65h,75h,72h,6Fh,70h,65h,2Eh,70h
	DB	69h,63h,0
_dat_str_africa_pic	DB	61h,66h,72h,69h,63h,61h,2Eh,70h
	DB	69h,63h,0
_dat_str_central_pic	DB	63h,65h,6Eh,74h,72h,61h,6Ch,2Eh
	DB	70h,69h,63h,0
_dat_str_re	DB	59h,6Fh,75h,27h,72h,65h,20h,69h
	DB	6Eh,20h,0
_dat_str_do_travel	DB	0Ah,44h,6Fh,20h,79h,6Fh,75h,20h
	DB	74h,72h,61h,76h,65h,6Ch,20h,74h
	DB	6Fh,20h,2Eh,2Eh,2Eh,0Ah,0
_dat_str_stay_here	DB	20h,53h,74h,61h,79h,20h,68h,65h
	DB	72h,65h,0Ah,0
_dat_str_space	DB	20h,0
_dat_str_nl	DB	0Ah,0
_dat_str_check_data_2	DB	20h,43h,68h,65h,63h,6Bh,20h,44h
	DB	61h,74h,61h,0Ah,0,0
_asm_leg_x	DB	0,1,1,1,0,0FFh,0FFh,0FFh
_asm_leg_y	DB	0FFh,0FFh,0,1,1,1,0,0FFh
_asm_leg_next	DB	7,6,5,0,0,4,1,2
	DB	3
_dat_str_quiet	DB	71h,75h,69h,65h,74h,0
_dat_str_unsuspecting	DB	75h,6Eh,73h,75h,73h,70h,65h,63h
	DB	74h,69h,6Eh,67h,0
_dat_str_cautious	DB	63h,61h,75h,74h,69h,6Fh,75h,73h
	DB	0
_dat_str_suspicious	DB	73h,75h,73h,70h,69h,63h,69h,6Fh
	DB	75h,73h,0
_dat_str_nervous	DB	6Eh,65h,72h,76h,6Fh,75h,73h,0
_dat_str_very_nervous	DB	76h,65h,72h,79h,20h,6Eh,65h,72h
	DB	76h,6Fh,75h,73h,0
asm_block_27a5	DB	0
_dat_str_briefing_pan_3	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_rest_up	DB	54h,68h,65h,20h,72h,65h,73h,74h
	DB	20h,69h,73h,20h,75h,70h,20h,74h
	DB	6Fh,20h,79h,6Fh,75h,2Eh,20h,0
_dat_str_i_ve_assigned_one	DB	49h,27h,76h,65h,20h,61h,73h,73h
	DB	69h,67h,6Eh,65h,64h,20h,6Fh,6Eh
	DB	65h,20h,6Fh,66h,20h,6Dh,79h,20h
	DB	62h,65h,73h,74h,20h,72h,65h,73h
	DB	65h,61h,72h,63h,68h,20h,61h,73h
	DB	73h,69h,73h,74h,61h,6Eh,74h,73h
	DB	20h,74h,6Fh,20h,77h,6Fh,72h,6Bh
	DB	20h,77h,69h,74h,68h,20h,79h,6Fh
	DB	75h,20h,6Fh,6Eh,20h,74h,68h,69h
	DB	73h,20h,63h,61h,73h,65h,2Eh,20h
	DB	0
_dat_str_president_s_counting	DB	54h,68h,65h,20h,50h,72h,65h,73h
	DB	69h,64h,65h,6Eh,74h,27h,73h,20h
	DB	63h,6Fh,75h,6Eh,74h,69h,6Eh,67h
	DB	20h,6Fh,6Eh,20h,79h,6Fh,75h,20h
	DB	4Dh,61h,78h,2Ch,20h,64h,6Fh,6Eh
	DB	27h,74h,20h,6Ch,65h,74h,20h,75h
	DB	73h,20h,64h,6Fh,77h,6Eh,2Eh,0
_dat_str_pic	DB	2Eh,70h,69h,63h,0
_dat_str_comma_space	DB	2Ch,20h,0
_dat_str_cities_cat	DB	63h,69h,74h,69h,65h,73h,2Eh,63h
	DB	61h,74h,0,0
dat_str_tied	DB	20h,74h,69h,65h,64h,20h,74h,6Fh
	DB	20h,0
dat_str_registered	DB	20h,72h,65h,67h,69h,73h,74h,65h
	DB	72h,65h,64h,20h,74h,6Fh,20h,0
dat_str_acquired_by	DB	20h,61h,63h,71h,75h,69h,72h,65h
	DB	64h,20h,62h,79h,20h,0
dat_str_delivered	DB	20h,64h,65h,6Ch,69h,76h,65h,72h
	DB	65h,64h,20h,74h,6Fh,20h,0
dat_str_requested	DB	20h,72h,65h,71h,75h,65h,73h,74h
	DB	65h,64h,20h,66h,6Fh,72h,20h,0
dat_str_tied_2	DB	20h,74h,69h,65h,64h,20h,74h,6Fh
	DB	20h,0
dat_str_registered_2	DB	20h,72h,65h,67h,69h,73h,74h,65h
	DB	72h,65h,64h,20h,74h,6Fh,20h,0
dat_str_traced	DB	20h,74h,72h,61h,63h,65h,64h,20h
	DB	74h,6Fh,20h,0
dat_str_smuggled_into	DB	20h,73h,6Dh,75h,67h,67h,6Ch,65h
	DB	64h,20h,69h,6Eh,74h,6Fh,20h,0
dat_str_requested_2	DB	20h,72h,65h,71h,75h,65h,73h,74h
	DB	65h,64h,20h,66h,6Fh,72h,20h,0
dat_str_tied_3	DB	20h,74h,69h,65h,64h,20h,74h,6Fh
	DB	20h,0
dat_str_rented_by	DB	20h,72h,65h,6Eh,74h,65h,64h,20h
	DB	62h,79h,20h,0
dat_str_frequented_by	DB	20h,66h,72h,65h,71h,75h,65h,6Eh
	DB	74h,65h,64h,20h,62h,79h,20h,0
dat_str_is_in	DB	20h,69h,73h,20h,69h,6Eh,20h,0
dat_str_linked	DB	20h,6Ch,69h,6Eh,6Bh,65h,64h,20h
	DB	74h,6Fh,20h,0
dat_str_purchased_by	DB	20h,70h,75h,72h,63h,68h,61h,73h
	DB	65h,64h,20h,62h,79h,20h,0
dat_str_purchased_by_2	DB	20h,70h,75h,72h,63h,68h,61h,73h
	DB	65h,64h,20h,62h,79h,20h,0
dat_str_traced_2	DB	20h,74h,72h,61h,63h,65h,64h,20h
	DB	74h,6Fh,20h,0
dat_str_purchased	DB	20h,70h,75h,72h,63h,68h,61h,73h
	DB	65h,64h,20h,69h,6Eh,20h,0
dat_str_linked_2	DB	20h,6Ch,69h,6Eh,6Bh,65h,64h,20h
	DB	74h,6Fh,20h,0
dat_str_received_by	DB	20h,72h,65h,63h,65h,69h,76h,65h
	DB	64h,20h,62h,79h,20h,0
dat_str_signed_by	DB	20h,73h,69h,67h,6Eh,65h,64h,20h
	DB	66h,6Fh,72h,20h,62h,79h,20h,0
dat_str_traced_3	DB	20h,74h,72h,61h,63h,65h,64h,20h
	DB	74h,6Fh,20h,0
dat_str_sent	DB	20h,73h,65h,6Eh,74h,20h,74h,6Fh
	DB	20h,0
dat_str_refers	DB	20h,72h,65h,66h,65h,72h,73h,20h
	DB	74h,6Fh,20h,0
dat_str_withdrawn_by	DB	20h,77h,69h,74h,68h,64h,72h,61h
	DB	77h,6Eh,20h,62h,79h,20h,0
dat_str_withdrawn_by_2	DB	20h,77h,69h,74h,68h,64h,72h,61h
	DB	77h,6Eh,20h,62h,79h,20h,0
dat_str_paid_by	DB	20h,70h,61h,69h,64h,20h,62h,79h
	DB	20h,0
dat_str_transaction	DB	20h,74h,72h,61h,6Eh,73h,61h,63h
	DB	74h,69h,6Fh,6Eh,20h,69h,6Eh,20h
	DB	0
dat_str_requested_3	DB	20h,72h,65h,71h,75h,65h,73h,74h
	DB	65h,64h,20h,66h,6Fh,72h,20h,0
dat_str_withdrawn_by_3	DB	20h,77h,69h,74h,68h,64h,72h,61h
	DB	77h,6Eh,20h,62h,79h,20h,0
dat_str_withdrawn_by_4	DB	20h,77h,69h,74h,68h,64h,72h,61h
	DB	77h,6Eh,20h,62h,79h,20h,0
dat_str_paid_by_2	DB	20h,70h,61h,69h,64h,20h,62h,79h
	DB	20h,0
dat_str_transaction_2	DB	20h,74h,72h,61h,6Eh,73h,61h,63h
	DB	74h,69h,6Fh,6Eh,20h,69h,6Eh,20h
	DB	0
dat_str_requested_4	DB	20h,72h,65h,71h,75h,65h,73h,74h
	DB	65h,64h,20h,66h,6Fh,72h,20h,0
dat_str_assigned	DB	20h,61h,73h,73h,69h,67h,6Eh,65h
	DB	64h,20h,74h,6Fh,20h,0
dat_str_assigned_2	DB	20h,61h,73h,73h,69h,67h,6Eh,65h
	DB	64h,20h,74h,6Fh,20h,0
dat_str_assigned_3	DB	20h,61h,73h,73h,69h,67h,6Eh,65h
	DB	64h,20h,74h,6Fh,20h,0
dat_str_used	DB	20h,75h,73h,65h,64h,20h,69h,6Eh
	DB	20h,0
dat_str_assigned_4	DB	20h,61h,73h,73h,69h,67h,6Eh,65h
	DB	64h,20h,74h,6Fh,20h,0
dat_str_jan	DB	4Ah,61h,6Eh,0
dat_str_feb	DB	46h,65h,62h,0
dat_str_mar	DB	4Dh,61h,72h,0
dat_str_apr	DB	41h,70h,72h,0
dat_str_may	DB	4Dh,61h,79h,0
dat_str_jun	DB	4Ah,75h,6Eh,0
dat_str_jul	DB	4Ah,75h,6Ch,0
dat_str_aug	DB	41h,75h,67h,0
dat_str_sep	DB	53h,65h,70h,0
dat_str_oct	DB	4Fh,63h,74h,0
dat_str_nov	DB	4Eh,6Fh,76h,0
dat_str_dec	DB	44h,65h,63h,0
_dat_str_coded_message	DB	20h,20h,20h,20h,20h,20h,20h,43h
	DB	4Fh,44h,45h,44h,20h,4Dh,45h,53h
	DB	53h,41h,47h,45h,3Ah,0Ah,0
_dat_str_meeting_notes	DB	20h,20h,20h,20h,20h,20h,20h,4Dh
	DB	45h,45h,54h,49h,4Eh,47h,20h,4Eh
	DB	4Fh,54h,45h,53h,3Ah,0Ah,0
_dat_str_new_information	DB	20h,20h,20h,20h,20h,20h,20h,4Eh
	DB	45h,57h,20h,49h,4Eh,46h,4Fh,52h
	DB	4Dh,41h,54h,49h,4Fh,4Eh,0Ah,0
_dat_str_additional_information	DB	20h,20h,20h,20h,41h,44h,44h,49h
	DB	54h,49h,4Fh,4Eh,41h,4Ch,20h,49h
	DB	4Eh,46h,4Fh,52h,4Dh,41h,54h,49h
	DB	4Fh,4Eh,0Ah,0
_dat_str_space_2	DB	20h,0
_dat_str_dots	DB	0Ah,2Eh,2Eh,2Eh,20h,0
_dat_str_on	DB	6Fh,6Eh,20h,0
_dat_str_space_2_2	DB	20h,0
_dat_str_of_the	DB	6Fh,66h,20h,74h,68h,65h,20h,0
_dat_str_in	DB	69h,6Eh,20h,0
_dat_str_newline	DB	0Ah,0
_dat_str_empty_4	DB	0
_dat_str_space_3	DB	20h,0
_dat_str_in_2	DB	20h,69h,6Eh,20h,0
_shd_clue_phrases	DW	OFFSET DGROUP:dat_str_tied
	DW	OFFSET DGROUP:dat_str_registered
	DW	OFFSET DGROUP:dat_str_acquired_by
	DW	OFFSET DGROUP:dat_str_delivered
	DW	OFFSET DGROUP:dat_str_requested
	DW	OFFSET DGROUP:dat_str_tied_2
	DW	OFFSET DGROUP:dat_str_registered_2
	DW	OFFSET DGROUP:dat_str_traced
	DW	OFFSET DGROUP:dat_str_smuggled_into
	DW	OFFSET DGROUP:dat_str_requested_2
	DW	OFFSET DGROUP:dat_str_tied_3
	DW	OFFSET DGROUP:dat_str_rented_by
	DW	OFFSET DGROUP:dat_str_frequented_by
	DW	OFFSET DGROUP:dat_str_is_in
	DW	OFFSET DGROUP:dat_str_linked
	DW	OFFSET DGROUP:dat_str_purchased_by
	DW	OFFSET DGROUP:dat_str_purchased_by_2
	DW	OFFSET DGROUP:dat_str_traced_2
	DW	OFFSET DGROUP:dat_str_purchased
	DW	OFFSET DGROUP:dat_str_linked_2
	DW	OFFSET DGROUP:dat_str_received_by
	DW	OFFSET DGROUP:dat_str_signed_by
	DW	OFFSET DGROUP:dat_str_traced_3
	DW	OFFSET DGROUP:dat_str_sent
	DW	OFFSET DGROUP:dat_str_refers
	DW	OFFSET DGROUP:dat_str_withdrawn_by
	DW	OFFSET DGROUP:dat_str_withdrawn_by_2
	DW	OFFSET DGROUP:dat_str_paid_by
	DW	OFFSET DGROUP:dat_str_transaction
	DW	OFFSET DGROUP:dat_str_requested_3
	DW	OFFSET DGROUP:dat_str_withdrawn_by_3
	DW	OFFSET DGROUP:dat_str_withdrawn_by_4
	DW	OFFSET DGROUP:dat_str_paid_by_2
	DW	OFFSET DGROUP:dat_str_transaction_2
	DW	OFFSET DGROUP:dat_str_requested_4
	DW	OFFSET DGROUP:dat_str_assigned
	DW	OFFSET DGROUP:dat_str_assigned_2
	DW	OFFSET DGROUP:dat_str_assigned_3
	DW	OFFSET DGROUP:dat_str_used
	DW	OFFSET DGROUP:dat_str_assigned_4
asm_block_2b8e	DB	2,2,1,4,1,8,1,8
	DB	1,4,1,4,1,2,1,8
_shd_scan_counts	DB	0,1,1,2,1,2,2,3
	DB	1,2,2,3,2,3,3,4
	DB	1,2,2,3,2,3,3,4
	DB	2,3,3,4,3,4,4,5
_shd_month_names	DW	OFFSET DGROUP:dat_str_jan
	DW	OFFSET DGROUP:dat_str_feb
	DW	OFFSET DGROUP:dat_str_mar
	DW	OFFSET DGROUP:dat_str_apr
	DW	OFFSET DGROUP:dat_str_may
	DW	OFFSET DGROUP:dat_str_jun
	DW	OFFSET DGROUP:dat_str_jul
	DW	OFFSET DGROUP:dat_str_aug
	DW	OFFSET DGROUP:dat_str_sep
	DW	OFFSET DGROUP:dat_str_oct
	DW	OFFSET DGROUP:dat_str_nov
	DW	OFFSET DGROUP:dat_str_dec
asm_block_2bd6	DB	0,0
_dat_str_empty_5	DB	0
_dat_str_has_been_identified_as	DB	20h,68h,61h,73h,20h,62h,65h,65h
	DB	6Eh,0Ah,69h,64h,65h,6Eh,74h,69h
	DB	66h,69h,65h,64h,20h,61h,73h,20h
	DB	61h,20h,70h,61h,72h,74h,69h,63h
	DB	69h,70h,61h,6Eh,74h,0Ah,69h,6Eh
	DB	20h,74h,68h,65h,20h,70h,6Ch,6Fh
	DB	74h,2Eh,0Ah,0
_dat_str_empty_6	DB	0
_dat_str_has_been_positively	DB	20h,68h,61h,73h,20h,62h,65h,65h
	DB	6Eh,20h,70h,6Fh,73h,69h,74h,69h
	DB	76h,65h,6Ch,79h,0Ah,69h,64h,65h
	DB	6Eh,74h,69h,66h,69h,65h,64h,20h
	DB	61h,73h,20h,0
_dat_str_newline_2	DB	0Ah,0
_dat_str_we_have_acquired	DB	57h,65h,20h,68h,61h,76h,65h,20h
	DB	61h,63h,71h,75h,69h,72h,65h,64h
	DB	20h,61h,0Ah,70h,68h,6Fh,74h,6Fh
	DB	67h,72h,61h,70h,68h,20h,6Fh,66h
	DB	20h,0
_dat_str_stop	DB	2Eh,0Ah,0
_dat_str_empty_7	DB	0
_dat_str_has_been_spotted	DB	20h,68h,61h,73h,20h,62h,65h,65h
	DB	6Eh,0Ah,73h,70h,6Fh,74h,74h,65h
	DB	64h,20h,69h,6Eh,20h,0
_dat_str_newline_3	DB	0Ah,0
_dat_str_empty_8	DB	0
_dat_str_has_been_identified_as_2	DB	20h,68h,61h,73h,20h,62h,65h,65h
	DB	6Eh,0Ah,69h,64h,65h,6Eh,74h,69h
	DB	66h,69h,65h,64h,20h,61h,73h,20h
	DB	61h,20h,6Dh,65h,6Dh,62h,65h,72h
	DB	0Ah,6Fh,66h,20h,74h,68h,65h,20h
	DB	0
_dat_str_newline_4	DB	0Ah,0
_dat_str_we_have_obtained	DB	57h,65h,20h,68h,61h,76h,65h,20h
	DB	6Fh,62h,74h,61h,69h,6Eh,65h,64h
	DB	0Ah,61h,64h,64h,69h,74h,69h,6Fh
	DB	6Eh,61h,6Ch,20h,69h,6Eh,66h,6Fh
	DB	72h,6Dh,61h,74h,69h,6Fh,6Eh,0Ah
	DB	63h,6Fh,6Eh,63h,65h,72h,6Eh,69h
	DB	6Eh,67h,20h,0
_dat_str_newline_5	DB	0Ah,0
_dat_str_we_have_determined_rank	DB	57h,65h,20h,68h,61h,76h,65h,20h
	DB	64h,65h,74h,65h,72h,6Dh,69h,6Eh
	DB	65h,64h,0Ah,74h,68h,65h,20h,72h
	DB	61h,6Eh,6Bh,20h,6Fh,66h,0Ah,0
_dat_str_newline_6	DB	0Ah,0
_dat_str_we_found_recruiting	DB	57h,65h,20h,66h,6Fh,75h,6Eh,64h
	DB	20h,72h,65h,63h,72h,75h,69h,74h
	DB	69h,6Eh,67h,0Ah,69h,6Eh,66h,6Fh
	DB	72h,6Dh,61h,74h,69h,6Fh,6Eh,20h
	DB	61h,62h,6Fh,75h,74h,0Ah,0
_dat_str_newline_7	DB	0Ah,0
_dat_str_we_found_recruiting_2	DB	57h,65h,20h,66h,6Fh,75h,6Eh,64h
	DB	20h,72h,65h,63h,72h,75h,69h,74h
	DB	69h,6Eh,67h,0Ah,69h,6Eh,66h,6Fh
	DB	72h,6Dh,61h,74h,69h,6Fh,6Eh,20h
	DB	61h,62h,6Fh,75h,74h,0Ah,0
_dat_str_newline_8	DB	0Ah,0
dat_str_recruit	DB	52h,65h,63h,72h,75h,69h,74h,0
dat_str_operative	DB	4Fh,70h,65h,72h,61h,74h,69h,76h
	DB	65h,0
dat_str_technician	DB	54h,65h,63h,68h,6Eh,69h,63h,69h
	DB	61h,6Eh,0
dat_str_agent_3	DB	41h,67h,65h,6Eh,74h,0
dat_str_organizer	DB	4Fh,72h,67h,61h,6Eh,69h,7Ah,65h
	DB	72h,0
dat_str_special_agent	DB	53h,70h,65h,63h,69h,61h,6Ch,20h
	DB	41h,67h,65h,6Eh,74h,0
dat_str_group_leader	DB	47h,72h,6Fh,75h,70h,20h,4Ch,65h
	DB	61h,64h,65h,72h,0
dat_str_mastermind	DB	4Dh,61h,73h,74h,65h,72h,4Dh,69h
	DB	6Eh,64h,0
dat_str_car	DB	43h,41h,52h,0
dat_str_wpn	DB	57h,50h,4Eh,0
dat_str_adr	DB	41h,44h,52h,0
dat_str_tkt	DB	54h,4Bh,54h,0
dat_str_msg	DB	4Dh,53h,47h,0
dat_str_dollar_1	DB	24h,0
dat_str_dollar_2	DB	24h,0
dat_str_fce	DB	46h,43h,45h,0
dat_str_ford_escort	DB	46h,6Fh,72h,64h,20h,45h,73h,63h
	DB	6Fh,72h,74h,20h,23h,0
dat_str_chevy_nova	DB	43h,68h,65h,76h,79h,20h,4Eh,6Fh
	DB	76h,61h,20h,23h,0
dat_str_toyota_tercel	DB	54h,6Fh,79h,6Fh,74h,61h,20h,54h
	DB	65h,72h,63h,65h,6Ch,20h,23h,0
dat_str_vw_golf	DB	56h,57h,20h,47h,6Fh,6Ch,66h,20h
	DB	23h,0
dat_str_mazda_rx7	DB	4Dh,61h,7Ah,64h,61h,20h,52h,58h
	DB	37h,20h,23h,0
dat_str_honda_civic	DB	48h,6Fh,6Eh,64h,61h,20h,43h,69h
	DB	76h,69h,63h,20h,23h,0
dat_str_peugot	DB	50h,65h,75h,67h,6Fh,74h,20h,23h
	DB	0
dat_str_chrysler	DB	43h,68h,72h,79h,73h,6Ch,65h,72h
	DB	20h,23h,0
dat_str_walther_ppk	DB	57h,61h,6Ch,74h,68h,65h,72h,20h
	DB	50h,50h,4Bh,20h,23h,0
dat_str_smith_wesson_9mm	DB	53h,6Dh,69h,74h,68h,26h,57h,65h
	DB	73h,73h,6Fh,6Eh,20h,39h,6Dh,6Dh
	DB	20h,23h,0
dat_str_berreta_m92s	DB	42h,65h,72h,72h,65h,74h,61h,20h
	DB	4Dh,39h,32h,53h,20h,23h,0
dat_str_browning_9mm	DB	42h,72h,6Fh,77h,6Eh,69h,6Eh,67h
	DB	20h,39h,6Dh,6Dh,20h,23h,0
dat_str_hechler_koch_vp	DB	48h,65h,63h,68h,6Ch,65h,72h,26h
	DB	4Bh,6Fh,63h,68h,20h,56h,50h,20h
	DB	23h,0
dat_str_luger_9mm	DB	4Ch,75h,67h,65h,72h,20h,39h,6Dh
	DB	6Dh,20h,23h,0
dat_str_colt_45	DB	43h,6Fh,6Ch,74h,20h,34h,35h,20h
	DB	23h,0
dat_str_357_magnum	DB	33h,35h,37h,20h,4Dh,61h,67h,6Eh
	DB	75h,6Dh,20h,23h,0
dat_str_rue_laverne	DB	52h,75h,65h,20h,4Ch,61h,76h,65h
	DB	72h,6Eh,65h,20h,0
dat_str_hochstrasse	DB	48h,6Fh,63h,68h,53h,74h,72h,61h
	DB	73h,73h,65h,20h,0
dat_str_main_st	DB	4Dh,61h,69h,6Eh,20h,53h,74h,2Eh
	DB	20h,0
dat_str_webley_ct	DB	57h,65h,62h,6Ch,65h,79h,20h,43h
	DB	74h,2Eh,20h,0
dat_str_holmley_park	DB	48h,6Fh,6Ch,6Dh,6Ch,65h,79h,20h
	DB	50h,61h,72h,6Bh,20h,0
dat_str_obensgrabbe	DB	4Fh,62h,65h,6Eh,73h,47h,72h,61h
	DB	62h,62h,65h,20h,0
dat_str_la_paz_blvd	DB	4Ch,61h,20h,50h,61h,7Ah,20h,42h
	DB	6Ch,76h,64h,2Eh,20h,0
dat_str_north_ave	DB	4Eh,6Fh,72h,74h,68h,20h,41h,76h
	DB	65h,2Eh,20h,0
dat_str_panam	DB	50h,61h,6Eh,41h,6Dh,20h,23h,0
dat_str_united	DB	55h,6Eh,69h,74h,65h,64h,20h,23h
	DB	0
dat_str_sabena	DB	53h,61h,62h,65h,6Eh,61h,20h,23h
	DB	0
dat_str_lufthansa	DB	4Ch,75h,66h,74h,68h,61h,6Eh,73h
	DB	61h,20h,23h,0
dat_str_el_al	DB	45h,6Ch,20h,41h,6Ch,20h,23h,0
dat_str_klm	DB	4Bh,4Ch,4Dh,20h,23h,0
dat_str_swissair	DB	53h,77h,69h,73h,73h,41h,69h,72h
	DB	20h,23h,0
dat_str_boac	DB	42h,4Fh,41h,43h,20h,23h,0
dat_str_w_union	DB	57h,2Eh,55h,6Eh,69h,6Fh,6Eh,20h
	DB	23h,0
dat_str_rca	DB	52h,43h,41h,20h,23h,0
dat_str_telex	DB	54h,65h,6Ch,65h,78h,20h,23h,0
dat_str_amtel	DB	41h,6Dh,54h,65h,6Ch,20h,23h,0
dat_str_intertel	DB	49h,6Eh,74h,65h,72h,54h,65h,6Ch
	DB	20h,23h,0
dat_str_satcomm	DB	53h,61h,74h,43h,6Fh,6Dh,6Dh,20h
	DB	23h,0
dat_str_teltron	DB	54h,65h,6Ch,54h,72h,6Fh,6Eh,20h
	DB	23h,0
dat_str_comlink	DB	43h,6Fh,6Dh,4Ch,69h,6Eh,6Bh,20h
	DB	23h,0
dat_str_dollar_3	DB	24h,0
dat_str_dollar_4	DB	24h,0
dat_str_dollar_5	DB	24h,0
dat_str_dollar_6	DB	24h,0
dat_str_dollar_7	DB	24h,0
dat_str_dollar_8	DB	24h,0
dat_str_dollar_9	DB	24h,0
dat_str_dollar_10	DB	24h,0
dat_str_dollar_11	DB	24h,0
dat_str_dollar_12	DB	24h,0
dat_str_dollar_13	DB	24h,0
dat_str_dollar_14	DB	24h,0
dat_str_dollar_15	DB	24h,0
dat_str_dollar_16	DB	24h,0
dat_str_dollar_17	DB	24h,0
dat_str_dollar_18	DB	24h,0
dat_str_swiss_passport	DB	53h,77h,69h,73h,73h,20h,50h,61h
	DB	73h,73h,70h,6Fh,72h,74h,20h,23h
	DB	0
dat_str_interpol_id	DB	49h,6Eh,74h,65h,72h,50h,6Fh,6Ch
	DB	20h,49h,44h,23h,0
dat_str_bahamian_passport	DB	42h,61h,68h,61h,6Dh,69h,61h,6Eh
	DB	20h,50h,61h,73h,73h,70h,6Fh,72h
	DB	74h,20h,23h,0
dat_str_gold_card	DB	47h,6Fh,6Ch,64h,20h,43h,61h,72h
	DB	64h,20h,23h,0
dat_str_swedish_passport	DB	53h,77h,65h,64h,69h,73h,68h,20h
	DB	50h,61h,73h,73h,70h,6Fh,72h,74h
	DB	20h,23h,0
dat_str_green_card	DB	47h,72h,65h,65h,6Eh,20h,43h,61h
	DB	72h,64h,20h,23h,0
dat_str_vista_card	DB	56h,49h,53h,54h,41h,20h,43h,61h
	DB	72h,64h,20h,23h,0
dat_str_liberian_passport	DB	4Ch,69h,62h,65h,72h,69h,61h,6Eh
	DB	20h,50h,61h,73h,73h,70h,6Fh,72h
	DB	74h,20h,23h,0
asm_block_3021	DB	0
_shd_clue_kinds	DW	OFFSET DGROUP:dat_str_recruit
	DW	OFFSET DGROUP:dat_str_operative
	DW	OFFSET DGROUP:dat_str_technician
	DW	OFFSET DGROUP:dat_str_agent_3
	DW	OFFSET DGROUP:dat_str_organizer
	DW	OFFSET DGROUP:dat_str_special_agent
	DW	OFFSET DGROUP:dat_str_group_leader
	DW	OFFSET DGROUP:dat_str_mastermind
	DW	OFFSET DGROUP:dat_str_car
	DW	OFFSET DGROUP:dat_str_wpn
	DW	OFFSET DGROUP:dat_str_adr
	DW	OFFSET DGROUP:dat_str_tkt
	DW	OFFSET DGROUP:dat_str_msg
	DW	OFFSET DGROUP:dat_str_dollar_1
	DW	OFFSET DGROUP:dat_str_dollar_2
	DW	OFFSET DGROUP:dat_str_fce
	DW	OFFSET DGROUP:dat_str_ford_escort
	DW	OFFSET DGROUP:dat_str_chevy_nova
	DW	OFFSET DGROUP:dat_str_toyota_tercel
	DW	OFFSET DGROUP:dat_str_vw_golf
	DW	OFFSET DGROUP:dat_str_mazda_rx7
	DW	OFFSET DGROUP:dat_str_honda_civic
	DW	OFFSET DGROUP:dat_str_peugot
	DW	OFFSET DGROUP:dat_str_chrysler
	DW	OFFSET DGROUP:dat_str_walther_ppk
	DW	OFFSET DGROUP:dat_str_smith_wesson_9mm
	DW	OFFSET DGROUP:dat_str_berreta_m92s
	DW	OFFSET DGROUP:dat_str_browning_9mm
	DW	OFFSET DGROUP:dat_str_hechler_koch_vp
	DW	OFFSET DGROUP:dat_str_luger_9mm
	DW	OFFSET DGROUP:dat_str_colt_45
	DW	OFFSET DGROUP:dat_str_357_magnum
	DW	OFFSET DGROUP:dat_str_rue_laverne
	DW	OFFSET DGROUP:dat_str_hochstrasse
	DW	OFFSET DGROUP:dat_str_main_st
	DW	OFFSET DGROUP:dat_str_webley_ct
	DW	OFFSET DGROUP:dat_str_holmley_park
	DW	OFFSET DGROUP:dat_str_obensgrabbe
	DW	OFFSET DGROUP:dat_str_la_paz_blvd
	DW	OFFSET DGROUP:dat_str_north_ave
	DW	OFFSET DGROUP:dat_str_panam
	DW	OFFSET DGROUP:dat_str_united
	DW	OFFSET DGROUP:dat_str_sabena
	DW	OFFSET DGROUP:dat_str_lufthansa
	DW	OFFSET DGROUP:dat_str_el_al
	DW	OFFSET DGROUP:dat_str_klm
	DW	OFFSET DGROUP:dat_str_swissair
	DW	OFFSET DGROUP:dat_str_boac
	DW	OFFSET DGROUP:dat_str_w_union
	DW	OFFSET DGROUP:dat_str_rca
	DW	OFFSET DGROUP:dat_str_telex
	DW	OFFSET DGROUP:dat_str_amtel
	DW	OFFSET DGROUP:dat_str_intertel
	DW	OFFSET DGROUP:dat_str_satcomm
	DW	OFFSET DGROUP:dat_str_teltron
	DW	OFFSET DGROUP:dat_str_comlink
	DW	OFFSET DGROUP:dat_str_dollar_3
	DW	OFFSET DGROUP:dat_str_dollar_4
	DW	OFFSET DGROUP:dat_str_dollar_5
	DW	OFFSET DGROUP:dat_str_dollar_6
	DW	OFFSET DGROUP:dat_str_dollar_7
	DW	OFFSET DGROUP:dat_str_dollar_8
	DW	OFFSET DGROUP:dat_str_dollar_9
	DW	OFFSET DGROUP:dat_str_dollar_10
	DW	OFFSET DGROUP:dat_str_dollar_11
	DW	OFFSET DGROUP:dat_str_dollar_12
	DW	OFFSET DGROUP:dat_str_dollar_13
	DW	OFFSET DGROUP:dat_str_dollar_14
	DW	OFFSET DGROUP:dat_str_dollar_15
	DW	OFFSET DGROUP:dat_str_dollar_16
	DW	OFFSET DGROUP:dat_str_dollar_17
	DW	OFFSET DGROUP:dat_str_dollar_18
	DW	OFFSET DGROUP:dat_str_swiss_passport
	DW	OFFSET DGROUP:dat_str_interpol_id
	DW	OFFSET DGROUP:dat_str_bahamian_passport
	DW	OFFSET DGROUP:dat_str_gold_card
	DW	OFFSET DGROUP:dat_str_swedish_passport
	DW	OFFSET DGROUP:dat_str_green_card
	DW	OFFSET DGROUP:dat_str_vista_card
	DW	OFFSET DGROUP:dat_str_liberian_passport
dat_str_clandestine_photo	DB	43h,6Ch,61h,6Eh,64h,65h,73h,74h
	DB	69h,6Eh,65h,20h,50h,68h,6Fh,74h
	DB	6Fh,0
dat_str_electronic_wiretap	DB	45h,6Ch,65h,63h,74h,72h,6Fh,6Eh
	DB	69h,63h,20h,57h,69h,72h,65h,54h
	DB	61h,70h,0
dat_str_covert_surveillance	DB	43h,6Fh,76h,65h,72h,74h,20h,53h
	DB	75h,72h,76h,65h,69h,6Ch,6Ch,61h
	DB	6Eh,63h,65h,0
dat_str_file_record_search	DB	46h,69h,6Ch,65h,20h,52h,65h,63h
	DB	6Fh,72h,64h,20h,53h,65h,61h,72h
	DB	63h,68h,0
dat_str_local_informant	DB	4Ch,6Fh,63h,61h,6Ch,20h,49h,6Eh
	DB	66h,6Fh,72h,6Dh,61h,6Eh,74h,0
dat_str_interpol_data_base	DB	49h,4Eh,54h,45h,52h,50h,4Fh,4Ch
	DB	20h,44h,61h,74h,61h,20h,42h,61h
	DB	73h,65h,0
dat_str_local_authorities	DB	4Ch,6Fh,63h,61h,6Ch,20h,41h,75h
	DB	74h,68h,6Fh,72h,69h,74h,69h,65h
	DB	73h,0
_dat_str_clue	DB	43h,6Ch,75h,65h,0
_dat_str_source_2_2	DB	87h,53h,6Fh,75h,72h,63h,65h,3Ah
	DB	20h,0
_dat_str_slash	DB	2Fh,0
_dat_str_newline_9	DB	0Ah,0
_dat_str_method_stop	DB	0Ah,87h,4Dh,65h,74h,68h,6Fh,64h
	DB	3Ah,20h,0
_dat_str_related_2	DB	8Ch,52h,65h,6Ch,61h,74h,65h,64h
	DB	20h,43h,6Ch,75h,65h,73h,3Ah,0
_dat_str_newline_10	DB	0Ah,0
_dat_str_none	DB	2Eh,2Eh,2Eh,6Eh,6Fh,6Eh,65h,0
asm_block_317b	DB	0
_dat_clue_source	DW	OFFSET DGROUP:dat_str_clandestine_photo
	DW	OFFSET DGROUP:dat_str_electronic_wiretap
	DW	OFFSET DGROUP:dat_str_covert_surveillance
	DW	OFFSET DGROUP:dat_str_file_record_search
	DW	OFFSET DGROUP:dat_str_local_informant
	DW	OFFSET DGROUP:dat_str_interpol_data_base
	DW	OFFSET DGROUP:dat_str_local_authorities
dat_msg_key	DB	24h,4Bh,45h,59h,0
dat_msg_name_2	DB	24h,4Eh,41h,4Dh,45h,0
dat_msg_org_2	DB	24h,4Fh,52h,47h,0
dat_msg_city_2	DB	24h,43h,49h,54h,59h,0
dat_msg_role	DB	24h,52h,4Fh,4Ch,45h,0
_dat_key_clue	DB	2Ah,43h,30h,30h,30h,30h,0
_dat_str_clues_txt	DB	63h,6Ch,75h,65h,73h,2Eh,74h,78h
	DB	74h,0,0
_shd_clue_keys	DW	OFFSET DGROUP:dat_msg_key
	DW	OFFSET DGROUP:dat_msg_name_2
	DW	OFFSET DGROUP:dat_msg_org_2
	DW	OFFSET DGROUP:dat_msg_city_2
	DW	OFFSET DGROUP:dat_msg_role
_shd_str_period	DB	2Eh,0
_dat_str_face	DB	74h,68h,69h,73h,20h,66h,61h,63h
	DB	65h,2Eh,0
_dat_str_valkerie	DB	56h,61h,6Ch,6Bh,65h,72h,69h,65h
	DB	0
_dat_str_thunderbolt	DB	54h,68h,75h,6Eh,64h,65h,72h,62h
	DB	6Fh,6Ch,74h,0
_shd_str_00	DB	30h,30h,0
_shd_str_000	DB	30h,30h,30h,0
_shd_key_clue_2	DB	2Ah,43h,30h,30h,0
_shd_key_clue_3	DB	2Ah,43h,30h,30h,30h,30h,0
_shd_key_clue_4	DB	2Ah,43h,30h,30h,30h,30h,0
_shd_str_clues_txt_2	DB	63h,6Ch,75h,65h,73h,2Eh,74h,78h
	DB	74h,0
_shd_str_empty_dossier	DB	0
_shd_str_name	DB	4Eh,61h,6Dh,65h,3Ah,80h,0
_shd_str_rank	DB	52h,61h,6Eh,6Bh,3Ah,80h,0
_shd_str_org	DB	4Fh,72h,67h,3Ah,20h,80h,0
_shd_str_city	DB	43h,69h,74h,79h,3Ah,20h,80h,0
_shd_str_recruited	DB	52h,65h,63h,72h,75h,69h,74h,65h
	DB	64h,0
_shd_str_by	DB	20h,62h,79h,20h,0
_shd_str_in_3	DB	20h,69h,6Eh,20h,0
_shd_str_period_2	DB	2Eh,0
_shd_str_role	DB	52h,6Fh,6Ch,65h,3Ah,20h,80h,0
_shd_str_role_2	DB	52h,6Fh,6Ch,65h,3Ah,20h,80h,4Eh
	DB	4Fh,54h,20h,49h,4Eh,56h,4Fh,4Ch
	DB	56h,45h,44h,0
_shd_str_role_3	DB	52h,6Fh,6Ch,65h,3Ah,20h,80h,75h
	DB	6Eh,6Bh,6Eh,6Fh,77h,6Eh,0
_shd_str_under_arrest	DB	28h,55h,6Eh,64h,65h,72h,20h,41h
	DB	72h,72h,65h,73h,74h,29h,0
_shd_str_hiding	DB	28h,49h,6Eh,20h,48h,69h,64h,69h
	DB	6Eh,67h,29h,0
_shd_str_turned	DB	28h,54h,75h,72h,6Eh,65h,64h,29h
	DB	0
_shd_str_empty_dossier_line	DB	0
_shd_str_quote	DB	27h,0
_shd_str_quote_2	DB	27h,0
_shd_str_message_not_decoded	DB	28h,6Dh,65h,73h,73h,61h,67h,65h
	DB	20h,6Eh,6Fh,74h,20h,64h,65h,63h
	DB	6Fh,64h,65h,64h,29h,0
_shd_str_more	DB	2Eh,2Eh,2Eh,6Dh,6Fh,72h,65h,0
_shd_str_empty_dossier_page	DB	0
_shd_str_rcvd_msg_fm	DB	52h,63h,76h,64h,20h,6Dh,73h,67h
	DB	20h,66h,6Dh,0
_shd_str_sent_msg	DB	53h,65h,6Eh,74h,20h,6Dh,73h,67h
	DB	20h,74h,6Fh,0
_shd_str_space_9	DB	20h,0
_shd_str_someone	DB	20h,73h,6Fh,6Dh,65h,6Fh,6Eh,65h
	DB	0
_shd_str_of_the_2	DB	20h,6Fh,66h,20h,74h,68h,65h,20h
	DB	0
_shd_str_in_4	DB	20h,69h,6Eh,20h,0
_shd_str_on_2	DB	20h,6Fh,6Eh,20h,0
_shd_str_space_10	DB	20h,0
_shd_str_period_3	DB	2Eh,0
BLOCK_32E9	DB	0
_dat_note_01	DB	68h,6Fh,74h,65h,6Ch,2Eh,70h,69h
	DB	63h,0
_dat_note_02	DB	59h,6Fh,75h,20h,61h,72h,65h,20h
	DB	61h,74h,20h,79h,6Fh,75h,72h,0Ah
	DB	68h,6Fh,74h,65h,6Ch,2Eh,20h,44h
	DB	6Fh,20h,79h,6Fh,75h,2Eh,2Eh,2Eh
	DB	0Ah,20h,4Ch,65h,61h,76h,65h,20h
	DB	48h,6Fh,74h,65h,6Ch,0Ah,20h,56h
	DB	69h,73h,69h,74h,20h,74h,68h,65h
	DB	20h,6Ch,6Fh,75h,6Eh,67h,65h,0Ah
	DB	20h,53h,6Ch,65h,65h,70h,20h,74h
	DB	68h,72h,6Fh,75h,67h,68h,20h,63h
	DB	61h,73h,65h,0Ah,20h,53h,61h,76h
	DB	65h,20h,47h,61h,6Dh,65h,0Ah,20h
	DB	4Ch,6Fh,61h,64h,20h,47h,61h,6Dh
	DB	65h,0Ah,20h,0Ah,20h,51h,75h,69h
	DB	74h,0Ah,0
_dat_note_03	DB	2Ah,6Ch,6Fh,75h,6Eh,67h,65h,0
_dat_note_04	DB	44h,61h,74h,61h,20h,46h,69h,6Ch
	DB	65h,73h,2Eh,2Eh,2Eh,0Ah,20h,43h
	DB	6Ch,75h,65h,73h,0Ah,20h,53h,75h
	DB	73h,70h,65h,63h,74h,73h,0Ah,20h
	DB	49h,6Eh,73h,69h,64h,65h,20h,49h
	DB	6Eh,66h,6Fh,72h,6Dh,61h,74h,69h
	DB	6Fh,6Eh,0Ah,20h,4Eh,65h,77h,73h
	DB	20h,42h,75h,6Ch,6Ch,65h,74h,69h
	DB	6Eh,73h,0Ah,0
_dat_note_05	DB	20h,4Fh,72h,67h,61h,6Eh,69h,7Ah
	DB	61h,74h,69h,6Fh,6Eh,20h,53h,75h
	DB	6Dh,6Dh,61h,72h,69h,65h,73h,0Ah
	DB	20h,43h,69h,74h,79h,20h,53h,75h
	DB	6Dh,6Dh,61h,72h,69h,65h,73h,0Ah
	DB	20h,41h,63h,74h,69h,76h,69h,74h
	DB	79h,20h,52h,65h,70h,6Fh,72h,74h
	DB	73h,0Ah,0
_dat_note_06	DB	59h,6Fh,75h,20h,61h,72h,65h,20h
	DB	69h,6Eh,20h,74h,68h,65h,20h,43h
	DB	49h,41h,20h,62h,75h,69h,6Ch,64h
	DB	69h,6Eh,67h,2Eh,0Ah,57h,68h,69h
	DB	63h,68h,20h,66h,6Ch,6Fh,6Fh,72h
	DB	20h,3Fh,0Ah,20h,31h,2Eh,20h,44h
	DB	61h,74h,61h,20h,53h,65h,63h,74h
	DB	69h,6Fh,6Eh,0Ah,20h,32h,2Eh,20h
	DB	49h,6Eh,74h,65h,6Ch,6Ch,69h,67h
	DB	65h,6Eh,63h,65h,20h,53h,65h,63h
	DB	74h,69h,6Fh,6Eh,0Ah,20h,33h,2Eh
	DB	20h,43h,72h,79h,70h,74h,6Fh,20h
	DB	42h,72h,61h,6Eh,63h,68h,0Ah,20h
	DB	4Ch,65h,61h,76h,65h,20h,62h,75h
	DB	69h,6Ch,64h,69h,6Eh,67h,0Ah,0
_dat_note_07	DB	63h,6Fh,6Dh,6Dh,2Eh,70h,61h,6Eh
	DB	0
_dat_note_08	DB	49h,6Eh,74h,65h,6Ch,6Ch,69h,67h
	DB	65h,6Eh,63h,65h,20h,53h,65h,63h
	DB	74h,69h,6Fh,6Eh,2Eh,2Eh,2Eh,0Ah
	DB	20h,4Ch,6Fh,63h,61h,6Ch,20h,53h
	DB	63h,61h,6Eh,0Ah,20h,49h,6Eh,74h
	DB	65h,72h,6Eh,61h,74h,69h,6Fh,6Eh
	DB	61h,6Ch,20h,53h,63h,61h,6Eh,0Ah
	DB	20h,41h,63h,74h,69h,76h,65h,20h
	DB	57h,69h,72h,65h,20h,54h,61h,70h
	DB	73h,0Ah,20h,41h,63h,63h,75h,73h
	DB	65h,20h,44h,6Fh,75h,62h,6Ch,65h
	DB	20h,41h,67h,65h,6Eh,74h,0Ah,20h
	DB	43h,68h,65h,63h,6Bh,20h,77h,69h
	DB	74h,68h,20h,53h,61h,6Dh,0Ah,0
_dat_note_09	DB	4Eh,6Fh,20h,6Eh,65h,77h,20h,69h
	DB	6Eh,66h,6Fh,72h,6Dh,61h,74h,69h
	DB	6Fh,6Eh,0Ah,0
_dat_note_10	DB	4Eh,6Fh,20h,6Eh,65h,77h,20h,69h
	DB	6Eh,66h,6Fh,72h,6Dh,61h,74h,69h
	DB	6Fh,6Eh,0Ah,0
_dat_note_11	DB	54h,68h,65h,20h,6Ch,6Fh,63h,61h
	DB	6Ch,20h,61h,67h,65h,6Eh,74h,20h
	DB	63h,6Fh,6Eh,66h,65h,73h,73h,65h
	DB	73h,0Ah,61h,6Eh,64h,20h,69h,73h
	DB	20h,72h,65h,70h,6Ch,61h,63h,65h
	DB	64h,2Eh,0Ah,0
_dat_note_12	DB	59h,6Fh,75h,20h,73h,65h,61h,72h
	DB	63h,68h,20h,68h,69h,73h,20h,66h
	DB	69h,6Ch,65h,73h,0Ah,66h,6Fh,72h
	DB	20h,61h,64h,64h,69h,74h,69h,6Fh
	DB	6Eh,61h,6Ch,20h,69h,6Eh,66h,6Fh
	DB	72h,6Dh,61h,74h,69h,6Fh,6Eh,2Eh
	DB	2Eh,2Eh,0Ah,0
_dat_note_13	DB	54h,68h,65h,20h,6Ch,6Fh,63h,61h
	DB	6Ch,20h,61h,67h,65h,6Eh,74h,20h
	DB	69h,73h,20h,63h,68h,65h,63h,6Bh
	DB	65h,64h,0Ah,61h,6Eh,64h,20h,70h
	DB	72h,6Fh,76h,65h,64h,20h,69h,6Eh
	DB	6Eh,6Fh,63h,65h,6Eh,74h,2Eh,0Ah
	DB	59h,6Fh,75h,20h,61h,72h,65h,20h
	DB	62h,61h,72h,72h,65h,64h,20h,66h
	DB	72h,6Fh,6Dh,0Ah,75h,73h,69h,6Eh
	DB	67h,20h,74h,68h,65h,20h,6Ch,6Fh
	DB	63h,61h,6Ch,20h,6Fh,66h,66h,69h
	DB	63h,65h,2Eh,0Ah,0
_dat_note_14	DB	72h,65h,73h,65h,61h,72h,63h,68h
	DB	2Eh,70h,61h,6Eh,0
_dat_note_15	DB	44h,61h,74h,61h,20h,53h,65h,63h
	DB	74h,69h,6Fh,6Eh,2Eh,2Eh,2Eh,0Ah
	DB	20h,52h,65h,76h,69h,65h,77h,20h
	DB	43h,6Ch,75h,65h,73h,0Ah,20h,52h
	DB	65h,76h,69h,65h,77h,20h,53h,75h
	DB	73h,70h,65h,63h,74h,73h,0Ah,20h
	DB	49h,6Eh,73h,69h,64h,65h,20h,49h
	DB	6Eh,66h,6Fh,72h,6Dh,61h,74h,69h
	DB	6Fh,6Eh,0Ah,20h,4Eh,65h,77h,73h
	DB	20h,42h,75h,6Ch,6Ch,65h,74h,69h
	DB	6Eh,73h,0Ah,0
_dat_note_16	DB	20h,4Fh,72h,67h,61h,6Eh,69h,7Ah
	DB	61h,74h,69h,6Fh,6Eh,20h,53h,75h
	DB	6Dh,6Dh,61h,72h,79h,0Ah,20h,43h
	DB	69h,74h,79h,20h,53h,75h,6Dh,6Dh
	DB	61h,72h,79h,0Ah,20h,41h,63h,74h
	DB	69h,76h,69h,74h,79h,20h,52h,65h
	DB	70h,6Fh,72h,74h,73h,0Ah,0
_dat_note_17	DB	63h,72h,79h,70h,74h,6Fh,2Eh,70h
	DB	61h,6Eh,0
_dat_note_18	DB	43h,72h,79h,70h,74h,6Fh,20h,42h
	DB	72h,61h,6Eh,63h,68h,2Eh,2Eh,2Eh
	DB	0Ah,20h,43h,6Fh,64h,65h,64h,20h
	DB	4Dh,65h,73h,73h,61h,67h,65h,73h
	DB	0Ah,20h,43h,72h,69h,6Dh,65h,20h
	DB	43h,68h,72h,6Fh,6Eh,6Fh,6Ch,6Fh
	DB	67h,79h,0Ah,0
_dat_note_19	DB	41h,63h,74h,69h,76h,69h,74h,79h
	DB	20h,52h,65h,70h,6Fh,72h,74h,20h
	DB	53h,75h,6Dh,6Dh,61h,72h,79h,0
_dat_note_20	DB	57h,69h,72h,65h,54h,61h,70h,73h
	DB	0
_dat_str_empty_9	DB	0
_dat_str_slash_2	DB	2Fh,0
_dat_str_dots_2	DB	20h,2Eh,2Eh,2Eh,20h,0
_dat_str_percent	DB	25h,0Ah,0
_dat_str_none_2	DB	6Eh,6Fh,6Eh,65h,20h,0Ah,0
_dat_str_which_organization	DB	57h,68h,69h,63h,68h,20h,6Fh,72h
	DB	67h,61h,6Eh,69h,7Ah,61h,74h,69h
	DB	6Fh,6Eh,20h,2Eh,2Eh,2Eh,0Ah,0
_dat_str_allies	DB	41h,6Ch,6Ch,69h,65h,73h,3Ah,20h
	DB	0Ah,20h,0
_dat_str_nl_space_3	DB	0Ah,20h,0
_dat_str_none_3	DB	6Eh,6Fh,6Eh,65h,0
_dat_str_known_locations	DB	4Bh,6Eh,6Fh,77h,6Eh,20h,4Ch,6Fh
	DB	63h,61h,74h,69h,6Fh,6Eh,73h,3Ah
	DB	0Ah,2Dh,0
_dat_str_in_5	DB	20h,69h,6Eh,20h,0
_dat_str_nl_dash	DB	0Ah,2Dh,0
_dat_str_associates	DB	41h,73h,73h,6Fh,63h,69h,61h,74h
	DB	65h,73h,3Ah,20h,0Ah,20h,0
_dat_str_nl_space_4	DB	0Ah,20h,0
_dat_str_none_4	DB	6Eh,6Fh,6Eh,65h,0
_dat_str_space_4	DB	20h,0
_dat_str_newline_11	DB	0Ah,0
_dat_str_which_city	DB	57h,68h,69h,63h,68h,20h,63h,69h
	DB	74h,79h,20h,2Eh,2Eh,2Eh,0Ah,0
_dat_str_known_locations_2	DB	4Bh,6Eh,6Fh,77h,6Eh,20h,4Ch,6Fh
	DB	63h,61h,74h,69h,6Fh,6Eh,73h,3Ah
	DB	0Ah,2Dh,0
_dat_str_unknown_building_3	DB	55h,6Eh,6Bh,6Eh,6Fh,77h,6Eh,20h
	DB	62h,75h,69h,6Ch,64h,69h,6Eh,67h
	DB	2Eh,0
_dat_str_nl_dash_2	DB	0Ah,2Dh,0
_dat_str_none_5	DB	6Eh,6Fh,6Eh,65h,0Ah,0
_dat_str_suspects	DB	53h,75h,73h,70h,65h,63h,74h,73h
	DB	3Ah,0Ah,2Dh,0
_dat_str_slash_3	DB	2Fh,0
_dat_str_ellipsis	DB	0Ah,2Eh,2Eh,2Eh,20h,8Ch,0
_dat_str_nl_dash_space	DB	0Ah,2Dh,20h,0
_dat_str_none_6	DB	6Eh,6Fh,6Eh,65h,0Ah,0
_dat_str_clues	DB	43h,6Ch,75h,65h,73h,3Ah,0Ah,0
_dat_str_dash	DB	2Dh,0
_dat_str_newline_12	DB	0Ah,0
_dat_str_none_7	DB	6Eh,6Fh,6Eh,65h,0Ah,0
_dat_str_space_5	DB	20h,0
_dat_str_newline_13	DB	0Ah,0
_dat_str_documents	DB	44h,6Fh,63h,75h,6Dh,65h,6Eh,74h
	DB	73h,0
_dat_str_select_document	DB	53h,65h,6Ch,65h,63h,74h,20h,44h
	DB	6Fh,63h,75h,6Dh,65h,6Eh,74h,3Ah
	DB	0Ah,20h,0
_dat_str_master_plan_2	DB	4Dh,61h,73h,74h,65h,72h,20h,50h
	DB	6Ch,61h,6Eh,0Ah,20h,0
_dat_str_personel_file	DB	20h,50h,65h,72h,73h,6Fh,6Eh,65h
	DB	6Ch,20h,46h,69h,6Ch,65h,0Ah,20h
	DB	0
_dat_str_none_8	DB	6Eh,6Fh,6Eh,65h,20h,0Ah,0
_dat_str_suspect_files	DB	53h,75h,73h,70h,65h,63h,74h,20h
	DB	46h,69h,6Ch,65h,73h,0
_dat_str_space_6	DB	20h,0
_dat_str_of_the_3	DB	20h,6Fh,66h,20h,74h,68h,65h,20h
	DB	0
_dat_str_in_6	DB	20h,69h,6Eh,20h,0
_dat_str_dot_nl_2	DB	2Eh,0Ah,20h,0
_dat_str_bullet	DB	8Ch,20h,0
_dat_str_space_7	DB	20h,0
_dat_str_arrested_2	DB	28h,41h,72h,72h,65h,73h,74h,65h
	DB	64h,29h,0
_dat_str_hiding_3	DB	28h,48h,69h,64h,69h,6Eh,67h,29h
	DB	0
_dat_str_turned_3	DB	28h,54h,75h,72h,6Eh,65h,64h,29h
	DB	0
_dat_str_custody	DB	28h,49h,6Eh,20h,43h,75h,73h,74h
	DB	6Fh,64h,79h,29h,0
_dat_str_nl_2	DB	0Ah,20h,0
_dat_str_none_9	DB	6Eh,6Fh,6Eh,65h,20h,0Ah,0
_dat_str_coded_messages	DB	43h,6Fh,64h,65h,64h,20h,4Dh,65h
	DB	73h,73h,61h,67h,65h,73h,0
_dat_str_space_8	DB	20h,0
_dat_str_space_11	DB	20h,0
_dat_str_nl_3	DB	0Ah,20h,2Eh,2Eh,2Eh,0
_dat_str_nl_4	DB	0Ah,20h,0
_dat_str_none_10	DB	20h,6Eh,6Fh,6Eh,65h,0Ah,0
_dat_str_message_decode	DB	4Dh,65h,73h,73h,61h,67h,65h,20h
	DB	44h,65h,63h,6Fh,64h,65h,0
_dat_str_from	DB	46h,52h,4Fh,4Dh,3Ah,0
_dat_str_to_heading	DB	54h,4Fh,3Ah,0
_dat_str_message	DB	4Dh,45h,53h,53h,41h,47h,45h,3Ah
	DB	0
_shd_str_nsyn_overflow	DB	4Eh,53h,59h,4Eh,20h,4Fh,76h,65h
	DB	72h,66h,6Ch,6Fh,77h,0Ah,0
_shd_str_chronology	DB	43h,68h,72h,6Fh,6Eh,6Fh,6Ch,6Fh
	DB	67h,79h,0
_shd_str_news	DB	4Eh,65h,77h,73h,0
_shd_str_sent_msg_2	DB	20h,73h,65h,6Eh,74h,20h,6Dh,73h
	DB	67h,20h,74h,6Fh,20h,0
_shd_str_met	DB	20h,6Dh,65h,74h,20h,77h,69h,74h
	DB	68h,20h,0
_shd_str_quote_3	DB	27h,0
_shd_str_quote_4	DB	27h,0
_shd_str_meeting_noted	DB	4Dh,65h,65h,74h,69h,6Eh,67h,20h
	DB	4Eh,6Fh,74h,65h,64h,0
_shd_str_more_2	DB	2Eh,2Eh,2Eh,6Dh,6Fh,72h,65h,0
_shd_str_chronology_2	DB	43h,68h,72h,6Fh,6Eh,6Fh,6Ch,6Fh
	DB	67h,79h,0
_shd_str_news_2	DB	4Eh,65h,77h,73h,0
_shd_str_none_log	DB	6Eh,6Fh,6Eh,65h,0
asm_block_38ed	DB	0
dat_str_victim	DB	24h,56h,49h,43h,54h,49h,4Dh,0
dat_msg_sndorg	DB	24h,53h,4Eh,44h,4Fh,52h,47h,0
dat_msg_rcvorg	DB	24h,52h,43h,56h,4Fh,52h,47h,0
dat_msg_sndloc	DB	24h,53h,4Eh,44h,4Ch,4Fh,43h,0
dat_msg_rcvloc	DB	24h,52h,43h,56h,4Ch,4Fh,43h,0
dat_msg_hlporg	DB	24h,48h,4Ch,50h,4Fh,52h,47h,0
dat_str_object	DB	24h,4Fh,42h,4Ah,45h,43h,54h,0
asm_subst_buffer_0	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h
asm_subst_buffer_1	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,0
asm_subst_buffer_2	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,0
asm_subst_buffer_3	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,0
asm_subst_buffer_4	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,0
asm_subst_buffer_5	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,0
asm_subst_buffer_6	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,0
asm_subst_buffer_7	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h
asm_subst_buffer_8	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,0
_shd_subst_keys	DW	OFFSET DGROUP:dat_str_victim
	DW	OFFSET DGROUP:dat_msg_sndorg
	DW	OFFSET DGROUP:dat_msg_rcvorg
	DW	OFFSET DGROUP:dat_msg_sndloc
	DW	OFFSET DGROUP:dat_msg_rcvloc
	DW	OFFSET DGROUP:dat_msg_hlporg
	DW	OFFSET DGROUP:dat_str_object
_shd_subst_values	DW	OFFSET DGROUP:asm_subst_buffer_0
	DW	OFFSET DGROUP:asm_subst_buffer_2
	DW	OFFSET DGROUP:asm_subst_buffer_3
	DW	OFFSET DGROUP:asm_subst_buffer_4
	DW	OFFSET DGROUP:asm_subst_buffer_5
	DW	OFFSET DGROUP:asm_subst_buffer_6
	DW	OFFSET DGROUP:asm_subst_buffer_7
_shd_str_mode_read_text	DB	72h,74h,0
_shd_fmt_line	DB	25h,5Bh,5Eh,0Ah,5Dh,0Ah,0
_shd_fmt_line_2	DB	25h,5Bh,5Eh,0Ah,5Dh,0Ah,0
_shd_str_space_12	DB	20h,0
_shd_fmt_line_3	DB	25h,5Bh,5Eh,0Ah,5Dh,0Ah,0
_shd_str_information_requires	DB	54h,68h,69h,73h,20h,69h,6Eh,66h
	DB	6Fh,72h,6Dh,61h,74h,69h,6Fh,6Eh
	DB	20h,72h,65h,71h,75h,69h,72h,65h
	DB	73h,20h,73h,65h,63h,75h,72h,69h
	DB	74h,79h,20h,63h,6Ch,65h,61h,72h
	DB	61h,6Eh,63h,65h,3Ah,20h,0
_dat_str_empty_9_2	DB	0
_dat_str_sloc00	DB	2Ah,53h,4Ch,4Fh,43h,30h,30h,0
_dat_str_text_dta	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_str_rloc00	DB	2Ah,52h,4Ch,4Fh,43h,30h,30h,0
_dat_str_text_dta_2	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_str_sorg00	DB	2Ah,53h,4Fh,52h,47h,30h,30h,0
_dat_str_text_dta_3	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_str_rorg00	DB	2Ah,52h,4Fh,52h,47h,30h,30h,0
_dat_str_text_dta_4	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_str_mark_80	DB	80h,0
_dat_str_text_dta_5	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_str_mark_8f	DB	8Fh,0
_dat_str_fluf00	DB	2Ah,46h,4Ch,55h,46h,30h,30h,0
_dat_str_text_dta_6	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_str_alrt00	DB	2Ah,41h,4Ch,52h,54h,30h,30h,0
_dat_str_text_dta_7	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_str_aidd00	DB	2Ah,41h,49h,44h,44h,30h,30h,0
_dat_str_text_dta_8	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_str_text_dta_9	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_msg0000	DB	2Ah,4Dh,53h,47h,30h,30h,30h,30h
	DB	0
_shd_str_facesf_pic	DB	66h,61h,63h,65h,73h,66h,2Eh,70h
	DB	69h,63h,0
_shd_str_faces_pic	DB	66h,61h,63h,65h,73h,2Eh,70h,69h
	DB	63h,0
asm_block_3b21	DB	0
_dat_str_bulletin	DB	42h,75h,6Ch,6Ch,65h,74h,69h,6Eh
	DB	3Ah,20h,0
_dat_str_has_gone_into_hiding	DB	20h,68h,61h,73h,20h,67h,6Fh,6Eh
	DB	65h,20h,69h,6Eh,74h,6Fh,20h,68h
	DB	69h,64h,69h,6Eh,67h,2Eh,0Ah,0
_dat_str_surveillance_team	DB	53h,75h,72h,76h,65h,69h,6Ch,6Ch
	DB	61h,6Eh,63h,65h,20h,54h,65h,61h
	DB	6Dh,0
_dat_str_env_sve_3	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_interpol_bulletin	DB	49h,4Eh,54h,45h,52h,50h,4Fh,4Ch
	DB	20h,42h,75h,6Ch,6Ch,65h,74h,69h
	DB	6Eh,3Ah,0Ah,0
_dat_str_spotted	DB	20h,73h,70h,6Fh,74h,74h,65h,64h
	DB	20h,69h,6Eh,20h,0
_dat_str_bang_nl_5	DB	21h,0Ah,0
_dat_str_interpol	DB	49h,4Eh,54h,45h,52h,50h,4Fh,4Ch
	DB	0
_dat_str_empty_10	DB	0
_dat_str_message_traffic	DB	4Dh,65h,73h,73h,61h,67h,65h,20h
	DB	74h,72h,61h,66h,66h,69h,63h,20h
	DB	64h,65h,74h,65h,63h,74h,65h,64h
	DB	2Eh,0Ah,2Eh,2Eh,2Eh,20h,0
_dat_str_from_2	DB	46h,52h,4Fh,4Dh,3Ah,20h,0
_dat_str_to	DB	54h,4Fh,3Ah,20h,0
_dat_str_dots_3	DB	20h,2Eh,2Eh,2Eh,0Ah,0
_dat_str_satellite_intercept	DB	53h,61h,74h,65h,6Ch,6Ch,69h,74h
	DB	65h,20h,49h,6Eh,74h,65h,72h,63h
	DB	65h,70h,74h,0
_dat_str_double_agent	DB	44h,6Fh,75h,62h,6Ch,65h,20h,41h
	DB	67h,65h,6Eh,74h,3Ah,20h,0
_dat_str_wiretap_at	DB	57h,69h,72h,65h,74h,61h,70h,20h
	DB	61h,74h,20h,0
_dat_str_slash_4	DB	2Fh,0
_dat_str_reveals	DB	20h,72h,65h,76h,65h,61h,6Ch,73h
	DB	20h,0
_dat_str_he	DB	68h,65h,20h,0
_dat_str_she_2	DB	73h,68h,65h,20h,0
_dat_str_space_13	DB	20h,0
_dat_str_nl_5	DB	0Ah,0
_dat_str_empty_12	DB	0
_dat_str_from_3	DB	46h,72h,6Fh,6Dh,3Ah,20h,0
_dat_str_slash_5	DB	2Fh,0
_dat_str_nl_6	DB	0Ah,0
_dat_str_has_just_returned_from	DB	20h,68h,61h,73h,20h,6Ah,75h,73h
	DB	74h,20h,72h,65h,74h,75h,72h,6Eh
	DB	65h,64h,20h,66h,72h,6Fh,6Dh,20h
	DB	61h,20h,74h,72h,69h,70h,20h,74h
	DB	6Fh,20h,0
_dat_str_dot_nl_3	DB	2Eh,0Ah,0
_dat_str_airport_surveillance	DB	41h,69h,72h,70h,6Fh,72h,74h,20h
	DB	53h,75h,72h,76h,65h,69h,6Ch,6Ch
	DB	61h,6Eh,63h,65h,0
_dat_str_empty_13	DB	0
_dat_str_seems_have_departed	DB	20h,73h,65h,65h,6Dh,73h,20h,74h
	DB	6Fh,20h,68h,61h,76h,65h,20h,64h
	DB	65h,70h,61h,72h,74h,65h,64h,20h
	DB	66h,72h,6Fh,6Dh,20h,0
_dat_str_dot_nl_4	DB	2Eh,0Ah,0
_dat_str_airport_surveillance_2	DB	41h,69h,72h,70h,6Fh,72h,74h,20h
	DB	53h,75h,72h,76h,65h,69h,6Ch,6Ch
	DB	61h,6Eh,63h,65h,0
asm_block_3c84	DB	0,0
_dat_str_bulletin_2	DB	42h,75h,6Ch,6Ch,65h,74h,69h,6Eh
	DB	3Ah,0Ah,0
_dat_str_has_come_out_hiding	DB	20h,68h,61h,73h,20h,63h,6Fh,6Dh
	DB	65h,20h,6Fh,75h,74h,20h,6Fh,66h
	DB	20h,68h,69h,64h,69h,6Eh,67h,21h
	DB	0Ah,0
_dat_str_surveillance_team_2	DB	53h,75h,72h,76h,65h,69h,6Ch,6Ch
	DB	61h,6Eh,63h,65h,20h,54h,65h,61h
	DB	6Dh,0
_dat_str_bulletin_3	DB	42h,75h,6Ch,6Ch,65h,74h,69h,6Eh
	DB	3Ah,0Ah,0
_dat_str_has_come_out_hiding_2	DB	20h,68h,61h,73h,20h,63h,6Fh,6Dh
	DB	65h,20h,6Fh,75h,74h,20h,6Fh,66h
	DB	20h,68h,69h,64h,69h,6Eh,67h,21h
	DB	0Ah,0
_dat_str_surveillance_team_3	DB	53h,75h,72h,76h,65h,69h,6Ch,6Ch
	DB	61h,6Eh,63h,65h,20h,54h,65h,61h
	DB	6Dh,0
_dat_str_day_slot	DB	20h,31h,30h,0
_asm_TIMESTAMP	DB	30h,30h,3Ah,30h,30h,20h,41h,4Dh
	DB	20h,4Ah,75h,6Eh,20h,30h,30h,0
_dat_str_comma_space_2	DB	2Ch,20h,0,0
_asm_status_bar_y	DB	0AEh,0
_dat_str_arrested_3	DB	41h,52h,52h,45h,53h,54h,45h,44h
	DB	0
_dat_str_turned_4	DB	54h,55h,52h,4Eh,45h,44h,0
_dat_str_clues_2	DB	43h,6Ch,75h,65h,73h,0
_dat_clue_colours	DB	0Eh,0,0Ah,0,0Eh,0,0Ah,0
_asm_clue_selected	DB	0,0
_dat_str_clue_2	DB	43h,6Ch,75h,65h,0
_dat_str_source_3	DB	87h,53h,6Fh,75h,72h,63h,65h,3Ah
	DB	20h,0
_dat_str_slash_6	DB	2Fh,0
_dat_str_nl_7	DB	0Ah,0
_dat_str_nl_8	DB	0Ah,0
_dat_str_arrested_4	DB	41h,52h,52h,45h,53h,54h,45h,44h
	DB	0
_dat_str_hiding_4	DB	49h,4Eh,20h,48h,49h,44h,49h,4Eh
	DB	47h,0
_dat_str_turned_5	DB	20h,54h,55h,52h,4Eh,45h,44h,0
_dat_str_officem_pan	DB	6Fh,66h,66h,69h,63h,65h,6Dh,2Eh
	DB	70h,61h,6Eh,0
_dat_str_officef_pan	DB	6Fh,66h,66h,69h,63h,65h,66h,2Eh
	DB	70h,61h,6Eh,0
_dat_str_max_i_ve_been	DB	4Dh,61h,78h,2Ch,20h,49h,27h,76h
	DB	65h,20h,62h,65h,65h,6Eh,0Ah,67h
	DB	6Fh,69h,6Eh,67h,20h,6Fh,76h,65h
	DB	72h,20h,74h,68h,65h,0Ah,69h,6Eh
	DB	66h,6Fh,20h,77h,65h,27h,76h,65h
	DB	20h,67h,6Fh,74h,0Ah,73h,6Fh,20h
	DB	66h,61h,72h,20h,2Eh,2Eh,2Eh,0Ah
	DB	0
_dat_str_i_d_look_into	DB	49h,27h,64h,20h,6Ch,6Fh,6Fh,6Bh
	DB	20h,69h,6Eh,74h,6Fh,0Ah,74h,68h
	DB	65h,73h,65h,20h,6Fh,72h,67h,61h
	DB	6Eh,69h,7Ah,61h,74h,69h,6Fh,6Eh
	DB	73h,3Ah,0Ah,0
_dat_str_space_15	DB	20h,0
_dat_str_newline_17	DB	0Ah,0
_dat_str_mark_8f_2	DB	8Fh,54h,68h,65h,73h,65h,20h,63h
	DB	69h,74h,69h,65h,73h,20h,68h,61h
	DB	76h,65h,20h,62h,65h,65h,6Eh,0Ah
	DB	8Fh,70h,72h,65h,74h,74h,79h,20h
	DB	61h,63h,74h,69h,76h,65h,20h,6Ch
	DB	61h,74h,65h,6Ch,79h,3Ah,0Ah,20h
	DB	0
_dat_str_newline_space	DB	0Ah,20h,0
_dat_str_there_s_not_much	DB	54h,68h,65h,72h,65h,27h,73h,20h
	DB	6Eh,6Fh,74h,0Ah,6Dh,75h,63h,68h
	DB	20h,74h,6Fh,20h,67h,6Fh,0Ah,61h
	DB	74h,20h,74h,68h,69h,73h,20h,70h
	DB	6Fh,69h,6Eh,74h,2Eh,0Ah,0
_dat_str_the	DB	54h,68h,65h,20h,0
_dat_str_has	DB	20h,68h,61h,73h,20h,61h,0
_dat_str_right_here	DB	20h,72h,69h,67h,68h,74h,20h,68h
	DB	65h,72h,65h,20h,69h,6Eh,20h,0
_dat_str_i_d_suggest_go	DB	21h,20h,49h,27h,64h,20h,73h,75h
	DB	67h,67h,65h,73h,74h,20h,79h,6Fh
	DB	75h,20h,67h,6Fh,20h,74h,68h,65h
	DB	72h,65h,20h,61h,6Eh,64h,20h,70h
	DB	6Ch,61h,63h,65h,20h,61h,20h,77h
	DB	69h,72h,65h,74h,61h,70h,20h,6Fh
	DB	72h,20h,62h,72h,65h,61h,6Bh,20h
	DB	69h,6Eh,2Eh,0
_dat_str_message_should_give_us	DB	54h,68h,69h,73h,20h,6Dh,65h,73h
	DB	73h,61h,67h,65h,20h,73h,68h,6Fh
	DB	75h,6Ch,64h,20h,67h,69h,76h,65h
	DB	20h,75h,73h,20h,73h,6Fh,6Dh,65h
	DB	20h,76h,69h,74h,61h,6Ch,20h,69h
	DB	6Eh,66h,6Fh,3Ah,20h,0
_dat_str_space_16	DB	20h,0
_dat_str_check_crypto_branch	DB	2Eh,20h,43h,68h,65h,63h,6Bh,20h
	DB	77h,69h,74h,68h,20h,74h,68h,65h
	DB	20h,43h,72h,79h,70h,74h,6Fh,20h
	DB	62h,72h,61h,6Eh,63h,68h,2Eh,0
_dat_str_max_we_ve_got	DB	4Dh,61h,78h,2Ch,20h,77h,65h,27h
	DB	76h,65h,20h,67h,6Fh,74h,20h,65h
	DB	6Eh,6Fh,75h,67h,68h,20h,65h,76h
	DB	69h,64h,65h,6Eh,63h,65h,20h,74h
	DB	6Fh,20h,61h,72h,72h,65h,73h,74h
	DB	20h,74h,68h,69h,73h,20h,61h,67h
	DB	65h,6Eh,74h,2Eh,20h,0
_dat_str_max_i_suggest_check	DB	4Dh,61h,78h,2Ch,20h,49h,20h,73h
	DB	75h,67h,67h,65h,73h,74h,20h,79h
	DB	6Fh,75h,20h,63h,68h,65h,63h,6Bh
	DB	20h,6Fh,75h,74h,20h,74h,68h,69h
	DB	73h,20h,70h,65h,72h,73h,6Fh,6Eh
	DB	2Eh,20h,0
_dat_str_he_2	DB	48h,65h,0
_dat_str_she_3	DB	53h,68h,65h,0
_dat_str_s_right_here	DB	27h,73h,20h,72h,69h,67h,68h,74h
	DB	20h,68h,65h,72h,65h,20h,69h,6Eh
	DB	20h,0
_dat_str_stop_space	DB	2Eh,20h,0
_dat_str_advicea	DB	2Ah,61h,64h,76h,69h,63h,65h,61h
	DB	0
_dat_str_advice1	DB	2Ah,61h,64h,76h,69h,63h,65h,31h
	DB	0
_dat_str_advice2	DB	2Ah,61h,64h,76h,69h,63h,65h,32h
	DB	0
_dat_str_advice3	DB	2Ah,61h,64h,76h,69h,63h,65h,33h
	DB	0
_dat_str_advice4	DB	2Ah,61h,64h,76h,69h,63h,65h,34h
	DB	0
_dat_str_advice5	DB	2Ah,61h,64h,76h,69h,63h,65h,35h
	DB	0
asm_block_3f8d	DB	0
_shd_str_select_load_file	DB	53h,65h,6Ch,65h,63h,74h,20h,4Ch
	DB	6Fh,61h,64h,20h,46h,69h,6Ch,65h
	DB	2Eh,2Eh,2Eh,0Ah,0,0
_shd_save_name	DB	61h,3Ah,63h,76h,30h,2Eh,73h,76h
	DB	65h,0
_shd_str_sve	DB	73h,76h,65h,0
_shd_str_max	DB	20h,4Dh,61h,78h,20h,27h,0
_shd_str_remington_00	DB	27h,20h,52h,65h,6Dh,69h,6Eh,67h
	DB	74h,6Fh,6Eh,3Ah,20h,30h,30h,0
_shd_str_rank_2	DB	20h,72h,61h,6Eh,6Bh,0Ah,20h,2Eh
	DB	2Eh,2Eh,20h,0
_shd_str_colon	DB	3Ah,20h,0
_shd_str_space_slot	DB	20h,0
_shd_str_comma_2	DB	2Ch,20h,0
_shd_str_local	DB	20h,28h,4Ch,6Fh,63h,61h,6Ch,29h
	DB	0
_shd_str_national	DB	20h,28h,4Eh,61h,74h,69h,6Fh,6Eh
	DB	61h,6Ch,29h,0
_shd_str_regional	DB	20h,28h,52h,65h,67h,69h,6Fh,6Eh
	DB	61h,6Ch,29h,0
_shd_str_global	DB	20h,28h,47h,6Ch,6Fh,62h,61h,6Ch
	DB	29h,0
_shd_str_stop_blank	DB	2Eh,0Ah,20h,0Ah,0
_shd_str_empty_slot	DB	20h,28h,45h,4Dh,50h,54h,59h,29h
	DB	0Ah,20h,0Ah,20h,0Ah,0
_shd_str_select_save_file	DB	53h,65h,6Ch,65h,63h,74h,20h,53h
	DB	61h,76h,65h,20h,46h,69h,6Ch,65h
	DB	2Eh,2Eh,2Eh,0Ah,0
_shd_str_game_has_been_saved	DB	47h,61h,6Dh,65h,20h,68h,61h,73h
	DB	20h,62h,65h,65h,6Eh,20h,73h,61h
	DB	76h,65h,64h,2Eh,0Ah,0
_shd_str_game_not_saved	DB	47h,61h,6Dh,65h,20h,4Eh,4Fh,54h
	DB	20h,73h,61h,76h,65h,64h,2Eh,0Ah
	DB	0
_shd_str_write_access_denied	DB	57h,72h,69h,74h,65h,20h,61h,63h
	DB	63h,65h,73h,73h,20h,64h,65h,6Eh
	DB	69h,65h,64h,2Eh,0Ah,0
_shd_str_disk_full	DB	44h,69h,73h,6Bh,20h,46h,75h,6Ch
	DB	6Ch,2Eh,0Ah,0
_shd_str_press_key_continue	DB	50h,72h,65h,73h,73h,20h,6Bh,65h
	DB	79h,20h,74h,6Fh,20h,63h,6Fh,6Eh
	DB	74h,69h,6Eh,75h,65h,2Eh,0Ah,0
_shd_str_sve_2	DB	73h,76h,65h,0
_shd_str_file_error_write	DB	46h,69h,6Ch,65h,20h,45h,72h,72h
	DB	6Fh,72h,3Ah,20h,0
_shd_str_newline_save	DB	0Ah,0
_shd_str_save_progress	DB	0Ah,20h,2Eh,2Eh,2Eh,20h,73h,61h
	DB	76h,65h,20h,69h,6Eh,20h,70h,72h
	DB	6Fh,67h,72h,65h,73h,73h,2Eh,0Ah
	DB	0
_shd_str_which_drive_contains	DB	57h,68h,69h,63h,68h,20h,64h,72h
	DB	69h,76h,65h,20h,63h,6Fh,6Eh,74h
	DB	61h,69h,6Eh,73h,20h,79h,6Fh,75h
	DB	72h,0Ah,73h,61h,76h,65h,64h,20h
	DB	67h,61h,6Dh,65h,20h,66h,69h,6Ch
	DB	65h,73h,3Fh,0Ah,0Ah,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	8Fh,20h,0
_shd_str_which_drive_contains_2	DB	57h,68h,69h,63h,68h,20h,64h,72h
	DB	69h,76h,65h,20h,63h,6Fh,6Eh,74h
	DB	61h,69h,6Eh,73h,20h,79h,6Fh,75h
	DB	72h,0Ah,53h,61h,76h,65h,20h,47h
	DB	61h,6Dh,65h,20h,64h,69h,73h,6Bh
	DB	3Fh,0Ah,0Ah,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,8Fh,20h
	DB	0
_shd_str_press_drive_letter	DB	3Ah,0Ah,0Ah,20h,20h,20h,20h,50h
	DB	72h,65h,73h,73h,20h,64h,72h,69h
	DB	76h,65h,20h,6Ch,65h,74h,74h,65h
	DB	72h,20h,61h,6Eh,64h,0Ah,52h,65h
	DB	74h,75h,72h,6Eh,20h,77h,68h,65h
	DB	6Eh,20h,64h,69h,73h,6Bh,20h,69h
	DB	73h,20h,69h,6Eh,73h,65h,72h,74h
	DB	65h,64h,2Eh,0Ah,0
_shd_str_press_escape_cancel	DB	20h,20h,20h,20h,50h,72h,65h,73h
	DB	73h,20h,45h,73h,63h,61h,70h,65h
	DB	20h,74h,6Fh,20h,63h,61h,6Eh,63h
	DB	65h,6Ch,2Eh,0Ah,0
_shd_str_no_disk_drive	DB	4Eh,6Fh,20h,44h,69h,73h,6Bh,20h
	DB	69h,6Eh,20h,44h,72h,69h,76h,65h
	DB	20h,41h,2Eh,0Ah,0
_shd_str_env_sve_put	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_shd_str_env_sve	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_shd_str_file_error	DB	46h,69h,6Ch,65h,20h,45h,72h,72h
	DB	6Fh,72h,3Ah,20h,0
_shd_str_newline_12	DB	0Ah,0,0
dat_str_final_exe	DB	66h,69h,6Eh,61h,6Ch,2Eh,65h,78h
	DB	65h,0
dat_str_game_exe	DB	67h,61h,6Dh,65h,2Eh,65h,78h,65h
	DB	0
dat_str_tac_exe	DB	74h,61h,63h,2Eh,65h,78h,65h,0
dat_str_hq_pan_2	DB	68h,71h,2Eh,70h,61h,6Eh,0
_shd_str_please_insert_disk	DB	50h,6Ch,65h,61h,73h,65h,20h,69h
	DB	6Eh,73h,65h,72h,74h,20h,44h,69h
	DB	73h,6Bh,20h,0
_shd_str_if_3_5_insert	DB	0Ah,28h,69h,66h,20h,33h,2Eh,35h
	DB	22h,20h,69h,6Eh,73h,65h,72h,74h
	DB	20h,44h,69h,73h,6Bh,20h,0
_shd_str_close_paren	DB	29h,0
_shd_str_press_return_continue	DB	2Eh,0Ah,20h,0Ah,20h,20h,20h,20h
	DB	20h,50h,72h,65h,73h,73h,20h,52h
	DB	65h,74h,75h,72h,6Eh,0Ah,20h,20h
	DB	20h,20h,20h,74h,6Fh,20h,63h,6Fh
	DB	6Eh,74h,69h,6Eh,75h,65h,2Eh,0Ah
	DB	0
_shd_disk_names	DW	OFFSET DGROUP:dat_str_final_exe
	DW	OFFSET DGROUP:dat_str_game_exe
	DW	OFFSET DGROUP:dat_str_tac_exe
	DW	OFFSET DGROUP:dat_str_hq_pan_2
_shd_disk_letter	DB	41h,0
dat_str_pani	DB	50h,41h,4Eh,49h,0
asm_block_4247	DB	0
dat_anim_page_port	DB	0,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_dat_anim_page_2_port	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_shd_anim_page	DW	OFFSET DGROUP:dat_anim_page_port
_shd_anim_page_2	DW	OFFSET DGROUP:_dat_anim_page_2_port
dat_rastport_hidden	DB	0,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
dat_rastport_shown	DB	1,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
dat_rastport_anim	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_drv_page_hidden	DW	OFFSET DGROUP:dat_rastport_hidden
_drv_page_shown	DW	OFFSET DGROUP:dat_rastport_shown
_drv_page_anim	DW	OFFSET DGROUP:dat_rastport_anim
_shm_seq_picture	DB	0,0
_shm_frame_toggle	DB	1,0
_shd_str_pani	DB	50h,41h,4Eh,49h,0
asm_block_42b5	DB	0
_shd_str_one_moment_please	DB	4Fh,6Eh,65h,20h,6Dh,6Fh,6Dh,65h
	DB	6Eh,74h,20h,70h,6Ch,65h,61h,73h
	DB	65h,2Eh,2Eh,2Eh,0
_shd_str_sure_want_quit_no_2	DB	41h,72h,65h,20h,79h,6Fh,75h,20h
	DB	73h,75h,72h,65h,0Ah,79h,6Fh,75h
	DB	20h,77h,61h,6Eh,74h,20h,74h,6Fh
	DB	20h,51h,75h,69h,74h,3Fh,0Ah,20h
	DB	4Eh,6Fh,0Ah,20h,59h,65h,73h,0Ah
	DB	0
dat_str_pani_3	DB	50h,41h,4Eh,49h,0
asm_block_42f9	DB	0
_shd_city_on_screen	DB	0FFh,0FFh
_shd_drive	DB	0FFh,0FFh
_shm_pan_width	DB	40h,1
asm_block_4300	DB	1,0
_shd_palette_menu	DB	0,1,2,3,4,0,6,7		; PALETTE
	DB	8,9,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh
	DB	0
PALETTE_PAD	DB	0
_shd_palette_face	DB	0,1,2,3,4,0,6,7		; PALETTE
	DB	8,9,0Ah,0Bh,6,0Dh,0Eh,0Fh
	DB	0
_shd_str_ok	DB	4Fh,4Bh,0
_shd_str_briefing_pan	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_shd_str_bld	DB	62h,6Ch,64h,0
asm_block_4339	DB	0
_shm_pan_building	DB	0,0
_shd_str_animation_pan	DB	61h,6Eh,69h,6Dh,61h,74h,69h,6Fh
	DB	6Eh,2Eh,70h,61h,6Eh,0
_shd_joystick_dirs	DB	8,0,7,0,6,0,1,0
	DB	0FFh,0FFh,5,0,2,0,3,0
	DB	4,0
_dat_screen_port	DB	0,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,1,0,0Fh,0,4,0
	DB	0,0
_shd_screen	DW	OFFSET DGROUP:_dat_screen_port
_asm_DAT_2206_4370	DB	0
_asm_DAT_2206_4371	DB	0
_asm_DAT_2206_4372	DB	0,0
_asm_DAT_2206_4374	DB	0,0
_asm_DAT_2206_4376	DB	0,0
_asm_DAT_2206_4378	DB	0,0
_asm_DAT_2206_437a	DB	0,0
_asm_DAT_2206_437c	DB	0,0
_asm_DAT_2206_437e	DB	0,0
asm_block_4380	DB	0,0
dat_message_pool	DB	41h,6Ch,6Ch,6Fh,63h,61h,74h,65h
	DB	64h,20h,31h,4Dh,62h,20h,6Fh,66h
	DB	20h,73h,70h,61h,63h,65h,3Fh,3Fh
	DB	3Fh,3Fh,24h
dat_str_ms_dos_lied_us	DB	4Dh,53h,2Dh,44h,4Fh,53h,20h,6Ch
	DB	69h,65h,64h,20h,74h,6Fh,20h,75h
	DB	73h,20h,61h,62h,6Fh,75h,74h,20h
	DB	68h,6Fh,77h,20h,6Dh,75h,63h,68h
	DB	20h,6Dh,65h,6Dh,6Fh,72h,79h,20h
	DB	77h,61h,73h,20h,61h,76h,61h,69h
	DB	6Ch,61h,62h,6Ch,65h,24h
dat_str_filename_not_found	DB	46h,69h,6Ch,65h,6Eh,61h,6Dh,65h
	DB	20h,6Eh,6Fh,74h,20h,66h,6Fh,75h
	DB	6Eh,64h,24h
dat_str_not_enough_memory_load	DB	4Eh,6Fh,74h,20h,65h,6Eh,6Fh,75h
	DB	67h,68h,20h,6Dh,65h,6Dh,6Fh,72h
	DB	79h,20h,74h,6Fh,20h,6Ch,6Fh,61h
	DB	64h,20h,66h,69h,6Ch,65h,24h
dat_str_overlay_load_failed	DB	4Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	6Ch,6Fh,61h,64h,20h,66h,61h,69h
	DB	6Ch,65h,64h,20h,66h,6Fh,72h,20h
	DB	73h,6Fh,6Dh,65h,20h,72h,65h,61h
	DB	73h,6Fh,6Eh,24h
dat_str_overlay_has_overrun	DB	4Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	68h,61h,73h,20h,6Fh,76h,65h,72h
	DB	72h,75h,6Eh,20h,61h,6Ch,6Ch,6Fh
	DB	63h,61h,74h,65h,64h,20h,6Dh,65h
	DB	6Dh,6Fh,72h,79h,24h
dat_str_unable_shrink_overlay	DB	55h,6Eh,61h,62h,6Ch,65h,20h,74h
	DB	6Fh,20h,73h,68h,72h,69h,6Eh,6Bh
	DB	20h,6Fh,76h,65h,72h,6Ch,61h,79h
	DB	20h,6Dh,65h,6Dh,6Fh,72h,79h,20h
	DB	61h,6Ch,6Ch,6Fh,63h,61h,74h,69h
	DB	6Fh,6Eh,24h
dat_str_error_releasing_overlay	DB	45h,72h,72h,6Fh,72h,20h,72h,65h
	DB	6Ch,65h,61h,73h,69h,6Eh,67h,20h
	DB	6Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	6Dh,65h,6Dh,6Fh,72h,79h,24h
_shd_archive_buffer_end	DW	OFFSET DGROUP:_shm_menu_face_x
_shd_archive_fd	DB	0FFh,0FFh
asm_block_449c	DB	0
_asm_DAT_2206_449d	DB	0,0
_asm_DAT_2206_449f	DB	0,0
_asm_DAT_2206_44a1	DB	0,0
_asm_DAT_2206_44a3	DB	0,0
_asm_DAT_2206_44a5	DB	0FFh,0FFh
asm_block_44a7	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
_asm_DAT_2206_4815	DB	0,0
_asm_DAT_2206_4817	DB	0,0
_asm_DAT_2206_4819	DB	0FFh,0FFh
_asm_DAT_2206_481b	DB	0,0
_asm_DAT_2206_481d	DB	0,0
_asm_DAT_2206_481f	DB	0,0
asm_block_4821	DB	0
_asm_DAT_2206_4822	DB	0
_asm_DAT_2206_4823	DB	0,0
_asm_DAT_2206_4825	DB	0,0
_asm_DAT_2206_4827	DB	0,0
_asm_DAT_2206_4829	DB	0,0
_asm_DAT_2206_482b	DB	3Fh,1
_asm_DAT_2206_482d	DB	6Fh,0
asm_block_482f	DB	0
_asm_DAT_2206_4830	DB	0FFh,0FFh
_asm_DAT_2206_4832	DB	0FFh,0FFh
_asm_DAT_2206_4834	DB	0,0
_asm_DAT_2206_4836	DB	0,0
_addr_page_row_tables	DW	OFFSET DGROUP:asm_page_row_left_0
	DW	OFFSET DGROUP:asm_page_row_left_1
	DW	OFFSET DGROUP:asm_page_row_right_0
	DW	OFFSET DGROUP:asm_page_row_right_1
asm_page_row_left_0	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
asm_page_row_right_0	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
asm_page_row_left_1	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
asm_page_row_right_1	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_DAT_2206_4e80	DB	0,0
_asm_DAT_2206_4e82	DB	0,0
DAT_2206_4e84	DB	0,0
DAT_2206_4e86	DB	0,0
DAT_2206_4e88	DB	0,0
DAT_2206_4e8a	DB	0,0
DAT_2206_4e8c	DB	0,0
DAT_2206_4e8e	DB	0,0
DAT_2206_4e90	DB	0,0
DAT_2206_4e92	DB	0,0
DAT_2206_4e94	DB	0,0
DAT_2206_4e96	DB	0,0

_DATA	ENDS

CONST0	SEGMENT	WORD PUBLIC 'CONST'
asm_seg_const0	DB	3,0

CONST0	ENDS

CONST	SEGMENT	WORD PUBLIC 'CONST'
; The two bytes are the C object's: the far buffer's segment.
CONST	ENDS

CONST2	SEGMENT	WORD PUBLIC 'CONST'
_shm_anim_magic	DB	3,0
asm_block_53d0	DB	3,0

CONST2	ENDS

_BSS	SEGMENT	WORD PUBLIC 'BSS'
asm_block_54ac	DB	0
asm_block_54ad	DB	0
asm_block_54ae	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
_asm_building_pan	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_watched	DB	0,0
_asm_watch_odds	DB	0,0
asm_block_54f0	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_picture_width	DB	0,0
_asm_picture_height	DB	0,0
_shm_clue_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_tap_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
asm_block_5534	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_message_key	DB	0,0,0,0,0,0,0,0
	DB	0
asm_block_555d	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0
_asm_jailbreak_target_suspect	DB	0,0
_asm_jailbreak_source_suspect	DB	0,0
asm_block_5582	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
_shm_slot_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_save_loading	DB	0,0
_shm_save_errno	DB	0,0
_shm_slot_fd	DB	0,0
_shm_slot_word	DB	0,0
_shm_save_block	DB	0,0,0,0
asm_block_55b2	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_save_offset	DB	0,0
_shm_save_fd	DB	0,0
asm_block_55c6	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_seq_frames_left	DB	0,0
_shm_frames_owed	DB	0,0
_shm_seq_wait	DB	0,0
_shm_seq_block	DW	0h		; the library's
_shm_seq_pc	DB	0,0,0,0
_shm_seq_depth	DB	0,0
_shm_seq_frames_done	DB	0,0
_shm_seq_sound_queue_count	DB	0,0
_shm_fullscreen_pan	DW	0h		; the library's
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
_shm_frame_deadline	DB	0,0,0,0
_shm_seq_op	DB	0,0
_shm_seq_operand	DB	0,0
_shm_anim_fd	DB	0,0
_shm_anim_magic_read	DB	0,0
_shm_anim_packed	DB	0,0
_shm_anim_signature	DB	0,0,0,0,0
asm_block_5609	DB	0
_shm_anim_row	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_active_pan	DW	0h		; the library's
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
asm_block_5758	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_menu_line_start	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_menu_colour_plain	DB	0,0
_shm_menu_colour_item	DB	0,0
_shm_menu_lines	DB	0,0
_shm_menu_colour_pick	DB	0,0
_shm_source_fd	DB	0,0
_shm_source_dst	DB	0,0
_shm_source_src	DB	0,0
DAT_2206_57b6	DB	0,0
DAT_2206_57b8	DB	0
DAT_2206_57b9	DB	0,0
DAT_2206_57bb	DB	0
asm_block_57bc	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
_shm_sprite_width	DB	0,0
_shm_sprite_height	DB	0,0
_shm_palette_count	DB	0,0
DAT_2206_6fbc	DB	0,0
DAT_2206_6fbe	DB	0,0
DAT_2206_6fc0	DB	0
DAT_2206_6fc1	DB	0
DAT_2206_6fc2	DB	0
DAT_2206_6fc3	DB	0
DAT_2206_6fc4	DB	0,0
DAT_2206_6fc6	DB	0,0
DAT_2206_6fc8	DB	0,0
DAT_2206_6fca	DB	0
DAT_2206_6fcb	DB	0
DAT_2206_6fcc	DB	0,0
DAT_2206_6fce	DB	0
asm_block_6fcf	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0

_BSS	ENDS

;==============================================================================
c_common	SEGMENT	PARA PUBLIC 'BSS'
;==============================================================================
_shm_joystick	DB	2 DUP(?)
_shm_scratch	DB	200h DUP(?)
	PUBLIC	__bufout
__bufout	LABEL	BYTE
D29462	DB	202h DUP(?)
_shm_difficulty	DB	2 DUP(?)
_asm_day	DB	2 DUP(?)
_shm_clock_minutes	DB	2 DUP(?)
_shm_campaign	DB	28Eh DUP(?)
_shm_seed	DB	2 DUP(?)
_shm_options	DB	2 DUP(?)
_shm_cga	DB	2 DUP(?)
asm_block_789e	DB	200h DUP(?)
_shm_cities	DB	220h DUP(?)
_shm_menu_tick	DB	2 DUP(?)
_shm_suspect_count	DB	2 DUP(?)
_shm_log	DB	700h DUP(?)
_shm_menu_face	DB	2 DUP(?)
_shm_wire_clue_source	DB	2 DUP(?)
_shm_crime_events	DB	0B00h DUP(?)
_shm_log_count	DB	2 DUP(?)
_shm_menu_first_line	DB	2 DUP(?)
asm_block_8eca	DB	4 DUP(?)
_shm_building_count	DB	2 DUP(?)
_shm_case_tick	DB	2 DUP(?)
_shm_frame_ticks	DB	2 DUP(?)
asm_block_8ed4	DB	2 DUP(?)
_asm_loaded_width	DB	2 DUP(?)
_shm_source_at	DB	2 DUP(?)
_asm_loaded_height	DB	2 DUP(?)
_shm_case_city_1	DB	2 DUP(?)
_shm_case_city_2	DB	2 DUP(?)
_shm_anim_more	DB	2 DUP(?)
	PUBLIC	__bufin
__bufin	LABEL	BYTE
asm_block_8ee2	DB	200h DUP(?)
_shm_pan_playing	DB	2 DUP(?)
_shm_anim_palette	DB	306h DUP(?)
_asm_stamp_minute	DB	2 DUP(?)
_shm_menu_no_pick	DB	2 DUP(?)
_asm_last_screen	DB	2 DUP(?)
_shm_probed_campaign	DB	28Eh DUP(?)
_shm_menu_items	DB	2 DUP(?)
_shm_anim_segment	DB	2 DUP(?)
_asm_hour	DB	2 DUP(?)
_shm_seq_ticks	DB	2 DUP(?)
_asm_contact_met	DB	2 DUP(?)
_shm_crime_event_count	DB	2 DUP(?)
_shm_case_seed	DB	2 DUP(?)
_shm_clue_method	DB	2 DUP(?)
_shm_menu_relayout	DB	2 DUP(?)
_shm_mission	DB	2 DUP(?)
_shm_menu_colour_bar	DB	2 DUP(?)
_shm_case_org_1	DB	2 DUP(?)
_shm_menu_text_width	DB	2 DUP(?)
_shm_case_org_2	DB	2 DUP(?)
_asm_menu_choice_count	DB	2 DUP(?)
_shm_faces_sprites	DB	0E8h DUP(?)
asm_block_9784	DB	8 DUP(?)
_shm_global_alert_level	DB	2 DUP(?)
_shm_slots_filled	DB	2 DUP(?)
_shm_regs	DB	0Eh DUP(?)
_shm_anim_error	DB	2 DUP(?)
_shm_double_agent_cities	DB	2 DUP(?)
_shm_crime_role_count	DB	2 DUP(?)
_shm_menu_marked	DB	2 DUP(?)
_shm_crime_roles	DB	600h DUP(?)
_shm_seq_done	DB	2 DUP(?)
_shm_refill	DB	2 DUP(?)
_asm_DAT_2206_9daa	DB	2 DUP(?)
_shm_archive_buffer	DB	200h DUP(?)
_shm_menu_face_x	DB	2 DUP(?)
_shm_menu_draw_only	DB	2 DUP(?)
_shm_skills	DB	2 DUP(?)
_shm_menu_face_y	DB	2 DUP(?)
_shm_orgs	DB	240h DUP(?)
_shm_anim_sprites	DB	1F4h DUP(?)
_asm_case_ready	DB	2 DUP(?)
_shm_anim_name	DB	2 DUP(?)
asm_block_a3ec	DB	2 DUP(?)
_shm_finished	DB	2 DUP(?)
_shm_menu_shortcut	DB	20h DUP(?)
_shm_menu_pick	DB	2 DUP(?)
asm_block_a412	DB	2 DUP(?)
_shm_crime_block	DB	48h DUP(?)
_shm_menu_right	DB	2 DUP(?)
_shm_substitute_tail	DB	100h DUP(?)
_shm_role_scan_states	DB	0C0h DUP(?)
_shm_graphics_letter	DB	1 DUP(?)
asm_block_a61f	DB	1 DUP(?)
_shm_menu_bottom	DB	2 DUP(?)
_shm_seq_stop_asked	DB	2 DUP(?)
_asm_campaign_state	DB	2 DUP(?)
_shm_case_city	DB	2 DUP(?)
_shm_activity	DB	40h DUP(?)
_shm_orgs_known	DB	2 DUP(?)
_asm_auto_waiting	DB	2 DUP(?)
	PUBLIC	__buferr
__buferr	LABEL	BYTE
asm_block_a66c	DB	200h DUP(?)
_shm_slot_pick	DB	2 DUP(?)
_shm_case_spare_2	DB	2 DUP(?)
_shm_anim_row_2	DB	140h DUP(?)
_asm_menu_choices	DB	40h DUP(?)
_shm_anim_block_kind	DB	2 DUP(?)
_shm_seq_vars	DB	66h DUP(?)
_shm_case_org	DB	2 DUP(?)
asm_block_aa5a	DB	6 DUP(?)

c_common	ENDS

	END
