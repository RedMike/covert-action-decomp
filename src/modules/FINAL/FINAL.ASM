	PAGE	60,132
	TITLE	FINAL
;
; FINAL.ASM -- the assembly side of FINAL.EXE.
;
; A SPLIT marker stands where a routine is in C; the build cuts the
; assembly there.
;

	EXTRN	_c_main:PROC
	EXTRN	_c_sound_command:PROC
	EXTRN	_c_play_animation:PROC
	EXTRN	_c_practice_setup:PROC
	EXTRN	_c_set_display_page:PROC
	EXTRN	_c_hook_hand_back:PROC
	EXTRN	_c_hook_repaint:PROC
	EXTRN	_c_opening_blurb:PROC
	EXTRN	_c_hook_message:PROC
	EXTRN	_c_campaign_start:PROC
	EXTRN	_c_set_start:PROC
	EXTRN	_c_mission_pick:PROC
	EXTRN	_c_code_name_screen:PROC
	EXTRN	_c_difficulty_menu:PROC
	EXTRN	_c_training_screen:PROC
	EXTRN	_c_skill_rows:PROC
	EXTRN	_c_text_field:PROC
	EXTRN	_c_text_field_draw:PROC
	EXTRN	_c_pack_org:PROC
	EXTRN	_c_draw_mastermind_face_panel:PROC
	EXTRN	_c_show_all_orgs:PROC
	EXTRN	_c_copy_protection:PROC
	EXTRN	_c_clear_message_panel:PROC
	EXTRN	_c_case_end:PROC
	EXTRN	_c_chronology:PROC
	EXTRN	_c_grid_cell:PROC
	EXTRN	_c_grid_caption:PROC
	EXTRN	_c_grid_highlight_org:PROC
	EXTRN	_c_grid_highlight_cell:PROC
	EXTRN	_c_grid_restack:PROC
	EXTRN	_c_grid_bar_cell:PROC
	EXTRN	_c_grid_connections:PROC
	EXTRN	_c_grid_redraw_org:PROC
	EXTRN	_c_draw_sprite:PROC
	EXTRN	_c_ask_menu:PROC
	EXTRN	_c_timestamp:PROC
	EXTRN	_c_reveal_case:PROC
	EXTRN	_c_efficiency_report:PROC
	EXTRN	_c_career_screen:PROC
	EXTRN	_c_trim_to_width:PROC
	EXTRN	_c_portrait_screen:PROC
	EXTRN	_c_interlude:PROC
	EXTRN	_c_case_generate:PROC
	EXTRN	_c_clear_happen_ticks:PROC
	EXTRN	_c_place_participant:PROC
	EXTRN	_c_briefing:PROC
	EXTRN	_c_read_crime:PROC
	EXTRN	_c_read_world:PROC
	EXTRN	_c_fame_clear:PROC
	EXTRN	_c_fame_load:PROC
	EXTRN	_c_fame_save:PROC
	EXTRN	_c_fame_screen:PROC
	EXTRN	_c_fame_add:PROC
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
	EXTRN	_c_log_add:PROC
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
	EXTRN	_c_seq_reset:PROC
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
	EXTRN	_c_mouse_reset:PROC
	EXTRN	_c_mouse_show:PROC
	EXTRN	_c_mouse_hide:PROC
	EXTRN	_c_mouse_where:PROC
	EXTRN	_c_mouse_move:PROC
	EXTRN	_c_mouse_presses:PROC
	EXTRN	_c_mouse_releases:PROC
	EXTRN	_c_mouse_fence:PROC
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
	EXTRN	_c_decode_palette:PROC
	EXTRN	_c_load_picture:PROC
	EXTRN	_c_decode_from_file:PROC
	EXTRN	_c_decode_picture:PROC
	EXTRN	_c_decode_scan:PROC
	EXTRN	_c_load_anim:PROC
	EXTRN	_c_animation_from_memory:PROC
	EXTRN	_c_refill_from_memory:PROC
	EXTRN	_c_prime_file:PROC
	EXTRN	_c_refill_from_file:PROC
	EXTRN	_c_fatal:PROC
	EXTRN	_c_set_mode_keeping_errno:PROC
	EXTRN	_c_archive_open:PROC
	EXTRN	_c_archive_close:PROC
	EXTRN	_c_archive_find:PROC
	EXTRN	_c_seek:PROC
	EXTRN	_c_log_draw:PROC
	EXTRN	_c_menu_run:PROC
	EXTRN	_c_menu_draw:PROC
	PUBLIC	_shm_anim_row_2
	PUBLIC	_dat_CRIME_DTA_NAME
	PUBLIC	_shm_suspects
	PUBLIC	_asm_DAT_20d8_828e
	PUBLIC	_shm_crime_events
	PUBLIC	_shm_case_city_1
	PUBLIC	_shm_case_city_2
	PUBLIC	_shm_mission
	PUBLIC	_shm_case_org_1
	PUBLIC	_shm_global_alert_level
	PUBLIC	_shm_crime_roles
	PUBLIC	_asm_case_mastermind
	PUBLIC	_shm_role_scan_states
	PUBLIC	_shm_activity
	PUBLIC	_shm_case_spare_2
	PUBLIC	_drv_jump_gfx_copy_rect
	PUBLIC	_drv_jump_gfx_set_colour_map
	PUBLIC	_drv_real_fill_rect
	PUBLIC	_drv_jump_gfx_fill
	PUBLIC	_drv_jump_keyboard_empty
	PUBLIC	_drv_jump_gfx_char_width
	PUBLIC	_drv_jump_gfx_set_palette
	PUBLIC	_drv_jump_gfx_show_page
	PUBLIC	_drv_jump_gfx_open
	PUBLIC	_drv_jump_joy_calibrate
	PUBLIC	_drv_jump_snd_command
	PUBLIC	_drv_real_link_slots
	PUBLIC	_dat_skill_names
	PUBLIC	_shd_map_page
	PUBLIC	_shd_screen
	PUBLIC	_shm_field_cursor
	PUBLIC	_shm_field_char_width
	PUBLIC	_shm_field_cursor_x
	PUBLIC	_shm_menu_draw_only
	PUBLIC	_shm_scratch
	PUBLIC	_shm_difficulty
	PUBLIC	_shm_skills
	PUBLIC	_shm_menu_pick
	PUBLIC	_shm_cga
	PUBLIC	_shm_graphics_letter
	PUBLIC	_dat_skill_colours
	PUBLIC	_dat_org_table
	PUBLIC	_dat_org_names
	PUBLIC	_shm_clock_minutes
	PUBLIC	_shm_campaign
	PUBLIC	_shm_options
	PUBLIC	_shm_log_count
	PUBLIC	_shm_building_count
	PUBLIC	_shm_case_tick
	PUBLIC	_asm_shown_count
	PUBLIC	_asm_set_first
	PUBLIC	_shm_orgs_known
	PUBLIC	_asm_dossier_seen
	PUBLIC	_dat_mission_sets
	PUBLIC	_asm_DAT_20d8_9bee
	PUBLIC	_asm_DAT_20d8_9e86
	PUBLIC	_shm_case_seed
	PUBLIC	_shm_regs
	PUBLIC	_shm_case_city
	PUBLIC	_asm_fresh_start
	PUBLIC	_shm_seq_vars
	PUBLIC	_shm_case_org
	PUBLIC	_drv_jump_gfx_grab
	PUBLIC	_drv_jump_gfx_pool_release
	PUBLIC	_drv_jump_gfx_dissolve
	PUBLIC	_drv_jump_gfx_pool_alloc
	PUBLIC	_asm_screen_sprite_a
	PUBLIC	_asm_scene_sprites
	PUBLIC	_asm_screen_sprite_c
	PUBLIC	_dat_ending_names
	PUBLIC	_dat_interlude_table
	PUBLIC	_asm_report_slots
	PUBLIC	_asm_career_cursor
	PUBLIC	_asm_report_topics
	PUBLIC	_shm_suspect_count
	PUBLIC	_shm_pan_playing
	PUBLIC	_asm_report_total
	PUBLIC	_shm_crime_role_count
	PUBLIC	_asm_case_flags
	PUBLIC	_asm_masterminds_arrested
	PUBLIC	_asm_case_points
	PUBLIC	_asm_grid_in_play
	PUBLIC	_shm_wire_clue_source
	PUBLIC	_asm_case_city_3
	PUBLIC	_shm_crime_event_count
	PUBLIC	_drv_jump_gfx_get_pixel
	PUBLIC	_asm_replay_page
	PUBLIC	_drv_jump_gfx_sprite_put
	PUBLIC	_shm_case_org_2
	PUBLIC	_shd_month_names
	PUBLIC	_shm_double_agent_cities
	PUBLIC	_shd_clue_kinds
	PUBLIC	_addr_crime_names
	PUBLIC	_asm_case_minute
	PUBLIC	_asm_case_hour
	PUBLIC	_asm_case_day
	PUBLIC	_asm_fame
	PUBLIC	_shd_subst_values
	PUBLIC	_shm_clue_method
	PUBLIC	_shm_seed
	PUBLIC	_shd_scan_counts
	PUBLIC	_shm_log
	PUBLIC	_shm_menu_face
	PUBLIC	_shm_buildings
	PUBLIC	_shm_clues_shown
	PUBLIC	_shd_clue_phrases
	PUBLIC	_shd_clue_source
	PUBLIC	_shm_hook_critical_error
	PUBLIC	_shm_unhook_critical_error
	PUBLIC	_shm_jailbreak_suspect
	PUBLIC	_shd_pan_disk
	PUBLIC	_shd_save_name
	PUBLIC	_shm_save_loading
	PUBLIC	_shm_save_errno
	PUBLIC	_shm_slot_fd
	PUBLIC	_shm_slot_word
	PUBLIC	_shm_save_block
	PUBLIC	_shm_save_offset
	PUBLIC	_shm_save_fd
	PUBLIC	_shm_slots_filled
	PUBLIC	_shm_slot_pick
	PUBLIC	_shm_faces_sprites
	PUBLIC	_shd_clock_text
	PUBLIC	_shm_pan_width
	PUBLIC	_shd_first_names
	PUBLIC	_shd_last_names
	PUBLIC	_drv_real_FUN_1000_0002
	PUBLIC	_shd_disk_names
	PUBLIC	_shd_disk_letter
	PUBLIC	_shm_menu_no_pick
	PUBLIC	_drv_jump_read_key
	PUBLIC	_drv_jump_joy_read
	PUBLIC	_shm_pan_building
	PUBLIC	_shd_joystick_dirs
	PUBLIC	_shm_active_pan
	PUBLIC	_shm_joystick
	PUBLIC	_drv_jump_gfx_capability
	PUBLIC	_drv_real_anim_reset
	PUBLIC	_shd_anim_page
	PUBLIC	_shd_anim_page_2
	PUBLIC	_drv_page_hidden
	PUBLIC	_drv_page_shown
	PUBLIC	_shm_seq_picture
	PUBLIC	_shm_seq_frames_left
	PUBLIC	_shm_frames_owed
	PUBLIC	_shm_seq_wait
	PUBLIC	_shm_seq_block
	PUBLIC	_shm_seq_frames_done
	PUBLIC	_shm_fullscreen_pan
	PUBLIC	_shm_frame_ticks
	PUBLIC	_shm_anim_segment
	PUBLIC	_shm_seq_ticks
	PUBLIC	_shm_seq_done
	PUBLIC	_shm_seq_stop_asked
	PUBLIC	_shm_anim_sprites
	PUBLIC	_drv_page_anim
	PUBLIC	_shm_frame_toggle
	PUBLIC	_shm_frame_deadline
	PUBLIC	_drv_real_FUN_1000_00ca
	PUBLIC	_drv_real_page_copy
	PUBLIC	_drv_jump_mem_avail
	PUBLIC	_drv_jump_gfx_page_fill
	PUBLIC	_drv_jump_gfx_sprite_put_clipped
	PUBLIC	_drv_real_sprite_put
	PUBLIC	_drv_real_sprite_put_2
	PUBLIC	_drv_real_draw_line
	PUBLIC	_drv_jump_gfx_text
	PUBLIC	_shd_archive_fd
	PUBLIC	_drv_real_palette_read
	PUBLIC	_drv_real_palette_put
	PUBLIC	_shd_archive_buffer_end
	PUBLIC	_shm_source_fd
	PUBLIC	_shm_palette_count
	PUBLIC	_shm_source_at
	PUBLIC	_shm_refill
	PUBLIC	_asm_DAT_20d8_a5ac
	PUBLIC	_drv_jump_gfx_row_put
	PUBLIC	_drv_jump_gfx_sprite_end
	PUBLIC	_drv_jump_gfx_sprite_row
	PUBLIC	_drv_jump_gfx_sprite_begin
	PUBLIC	_drv_real_unpack_start
	PUBLIC	_drv_real_unpack_row
	PUBLIC	_shm_source_dst
	PUBLIC	_shm_source_src
	PUBLIC	_shm_sprite_width
	PUBLIC	_shm_sprite_height
	PUBLIC	_shm_archive_buffer
	PUBLIC	_shm_anim_more
	PUBLIC	_shm_anim_palette
	PUBLIC	_shm_anim_block_kind
	PUBLIC	_asm_FARBUF
	PUBLIC	_shm_seq_data
	PUBLIC	_shm_menu_line_start
	PUBLIC	_shm_menu_colour_plain
	PUBLIC	_shm_menu_colour_item
	PUBLIC	_shm_menu_lines
	PUBLIC	_shm_menu_colour_pick
	PUBLIC	_shm_menu_tick
	PUBLIC	_shm_menu_first_line
	PUBLIC	_shm_menu_items
	PUBLIC	_shm_menu_relayout
	PUBLIC	_shm_menu_colour_bar
	PUBLIC	_shm_menu_text_width
	PUBLIC	_shm_menu_marked
	PUBLIC	_shm_menu_right
	PUBLIC	_shm_menu_bottom
	PUBLIC	_shm_seq_op
	PUBLIC	_shm_seq_operand
	PUBLIC	_shm_mouse_regs
	PUBLIC	_shm_mouse_buttons
	PUBLIC	_shm_mouse_x
	PUBLIC	_shm_mouse_y
	PUBLIC	_shm_mouse_count
	PUBLIC	_shm_anim_magic
	PUBLIC	_shm_seq_pc
	PUBLIC	_shm_seq_depth
	PUBLIC	_shm_seq_sound_queue_count
	PUBLIC	_shm_anim_fd
	PUBLIC	_shm_anim_magic_read
	PUBLIC	_shm_anim_packed
	PUBLIC	_shm_anim_signature
	PUBLIC	_shm_anim_error
	PUBLIC	_shm_anim_name
	PUBLIC	_shd_city_on_screen
	PUBLIC	_shd_drive
	PUBLIC	_shm_menu_face_x
	PUBLIC	_shm_menu_face_y
	PUBLIC	_shm_finished
	PUBLIC	_shm_menu_shortcut
	PUBLIC	_dat_str_briefing_pan
	PUBLIC	_dat_str_briefing_pan_2
	PUBLIC	_dat_str_briefing_pan_3
	PUBLIC	_dat_str_looks_like_about_wraps
	PUBLIC	_dat_str_we_ve_been_able
	PUBLIC	_dat_note_01
	PUBLIC	_dat_note_03
	PUBLIC	_dat_note_04
	PUBLIC	_dat_note_05
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
	PUBLIC	_dat_str_empty_2
	PUBLIC	_dat_str_paren_open
	PUBLIC	_dat_str_paren_close
	PUBLIC	_dat_str_space
	PUBLIC	_dat_str_slash
	PUBLIC	_dat_str_sent_message
	PUBLIC	_dat_str_caret
	PUBLIC	_dat_str_caret_2
	PUBLIC	_dat_str_empty_3
	PUBLIC	_dat_str_sent_message_2
	PUBLIC	_dat_str_sent_package
	PUBLIC	_dat_str_empty_4
	PUBLIC	_dat_str_paren_open_2
	PUBLIC	_dat_str_paren_close_2
	PUBLIC	_dat_str_slash_2
	PUBLIC	_dat_str_caret_3
	PUBLIC	_dat_str_caret_4
	PUBLIC	_dat_str_paren_open_3
	PUBLIC	_dat_str_paren_close_3
	PUBLIC	_dat_str_now_has
	PUBLIC	_dat_str_empty_5
	PUBLIC	_dat_str_left
	PUBLIC	_dat_str_traveled
	PUBLIC	_dat_str_broke
	PUBLIC	_dat_str_slash_3
	PUBLIC	_dat_str_arrested
	PUBLIC	_dat_str_confiscated
	PUBLIC	_dat_str_went_into_hiding
	PUBLIC	_dat_str_mission_completed
	PUBLIC	_dat_str_unable
	PUBLIC	_dat_str_complete_mission
	PUBLIC	_dat_str_came_out_hiding
	PUBLIC	_dat_str_escaped_from_jail
	PUBLIC	_dat_str_released_by_exchange
	PUBLIC	_dat_str_turned
	PUBLIC	_dat_str_space_2
	PUBLIC	_dat_str_day_number
	PUBLIC	_dat_date_template
	PUBLIC	_dat_str_org_sep
	PUBLIC	_dat_str_org_slash
	PUBLIC	_dat_str_at_large
	PUBLIC	_dat_str_arrested_2
	PUBLIC	_dat_str_turned_2
	PUBLIC	_dat_str_ep_0
	PUBLIC	_dat_str_ep_of
	PUBLIC	_dat_str_ep_50
	PUBLIC	_dat_str_ep_50_2
	PUBLIC	_dat_str_of_50
	PUBLIC	_dat_str_of_org
	PUBLIC	_dat_str_ep_blank
	PUBLIC	_dat_str_empty_agents
	PUBLIC	_dat_str_double_agent_s
	PUBLIC	_dat_str_remained_undetected
	PUBLIC	_dat_str_within_cia
	PUBLIC	_dat_str_ep_slash
	PUBLIC	_dat_str_dashes
	PUBLIC	_dat_str_dashes_end
	PUBLIC	_dat_str_ep_total
	PUBLIC	_dat_str_ep_total_of
	PUBLIC	_dat_str_max
	PUBLIC	_dat_str_remington
	PUBLIC	_dat_str_case
	PUBLIC	_dat_str_comma
	PUBLIC	_dat_str_space_3
	PUBLIC	_dat_str_arrests
	PUBLIC	_dat_str_ep_colon
	PUBLIC	_dat_str_slash_4
	PUBLIC	_dat_str_arrested_3
	PUBLIC	_dat_str_mastermind
	PUBLIC	_dat_str_arrested_masterminds
	PUBLIC	_dat_str_agents
	PUBLIC	_dat_str_after_difficult_few
	PUBLIC	_dat_str_word_latest_case_seems
	PUBLIC	_dat_str_after_successful_case
	PUBLIC	_dat_str_re_feeling_invincible
	PUBLIC	_dat_str_back_pic
	PUBLIC	_dat_str_hand
	PUBLIC	_dat_str_pic
	PUBLIC	_dat_str_red_herring
	PUBLIC	_dat_str_we_have_indications
	PUBLIC	_dat_str_operation_preparation
	PUBLIC	_dat_str_europe
	PUBLIC	_dat_str_africa_middle_east
	PUBLIC	_dat_str_central_america
	PUBLIC	_dat_str_the
	PUBLIC	_dat_str_known_involved
	PUBLIC	_dat_str_mission_prevent
	PUBLIC	_dat_str_capture_as_many
	PUBLIC	_dat_str_caution_one_more_double
	PUBLIC	_dat_str_i_m_afraid_re
	PUBLIC	_dat_str_perhaps_should_practice
	PUBLIC	_dat_str_ok_re_cleared
	PUBLIC	_dat_str_here_some_info_we
	PUBLIC	_dat_str_we_think_s_linked
	PUBLIC	_dat_str_briefing_pan_4
	PUBLIC	_dat_str_10_dta
	PUBLIC	_dat_str_fame_dta
	PUBLIC	_dat_str_fame_dta_2
	PUBLIC	_dat_str_fame_dta_3
	PUBLIC	_dat_str_fame_dta_4
	PUBLIC	_dat_str_dashes_2
	PUBLIC	_dat_str_stop
	PUBLIC	_dat_str_max_3
	PUBLIC	_dat_str_remington_case
	PUBLIC	_dat_str_space_4
	PUBLIC	_dat_str_space_5
	PUBLIC	_dat_str_slash_5
	PUBLIC	_dat_str_ep_colon_2
	PUBLIC	_dat_str_dashes_3
	PUBLIC	_shd_str_coded_message
	PUBLIC	_shd_str_meeting_notes
	PUBLIC	_shd_str_space_after_name
	PUBLIC	_shd_str_dots
	PUBLIC	_shd_str_on
	PUBLIC	_shd_str_space_after_month
	PUBLIC	_shd_str_of_the
	PUBLIC	_shd_str_in
	PUBLIC	_shd_str_newline
	PUBLIC	_shd_str_empty_watch
	PUBLIC	_shd_str_space_face
	PUBLIC	_shd_str_in_2
	PUBLIC	_shd_str_empty_identified
	PUBLIC	_shd_str_has_been_identified_as
	PUBLIC	_shd_str_empty_positively
	PUBLIC	_shd_str_has_been_positively
	PUBLIC	_shd_str_newline_2
	PUBLIC	_shd_str_we_have_acquired
	PUBLIC	_shd_str_stop
	PUBLIC	_shd_str_empty_spotted
	PUBLIC	_shd_str_has_been_spotted
	PUBLIC	_shd_str_newline_3
	PUBLIC	_shd_str_empty_org
	PUBLIC	_shd_str_has_been_identified_as_org
	PUBLIC	_shd_str_newline_4
	PUBLIC	_shd_str_we_have_obtained
	PUBLIC	_shd_str_newline_5
	PUBLIC	_shd_str_we_have_determined_rank
	PUBLIC	_shd_str_newline_6
	PUBLIC	_shd_str_we_found_recruiting
	PUBLIC	_shd_str_newline_7
	PUBLIC	_shd_str_we_found_recruiting_2
	PUBLIC	_shd_str_newline_8
	PUBLIC	_shd_str_source_2
	PUBLIC	_shd_str_slash_source
	PUBLIC	_shd_str_newline_9
	PUBLIC	_shd_str_newline_10
	PUBLIC	_shd_key_clue
	PUBLIC	_shd_str_period
	PUBLIC	_shd_str_face
	PUBLIC	_shd_str_valkerie
	PUBLIC	_shd_str_thunderbolt
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
	PUBLIC	_shd_str_sloc00
	PUBLIC	_shd_str_rloc00
	PUBLIC	_shd_str_sorg00
	PUBLIC	_shd_str_rorg00
	PUBLIC	_shd_str_fluf00
	PUBLIC	_shd_str_aidd00
	PUBLIC	_shm_anim_row
	PUBLIC	_shm_cities
	PUBLIC	_shm_orgs
	PUBLIC	_shm_crime_block
	PUBLIC	_dat_str_score_stop
	PUBLIC	_shd_str_method_stop
	PUBLIC	_shd_str_pani
	PUBLIC	_dat_str_icons_pic
	PUBLIC	_dat_note_02
	PUBLIC	_dat_str_efficiency_report
	PUBLIC	_dat_str_confiscated_2
	PUBLIC	_dat_str_not_found
	PUBLIC	_dat_str_prevented_crime
	PUBLIC	_dat_str_efficiency_rating
	PUBLIC	_dat_str_career
	PUBLIC	_dat_str_career_2
	PUBLIC	_dat_str_couldn_t_stop
	PUBLIC	_dat_str_prevented
	PUBLIC	_dat_str_career_3
	PUBLIC	_dat_str_career_4
	PUBLIC	_dat_str_masterminds_arrested
	PUBLIC	_dat_str_gender_pic_2
	PUBLIC	_dat_str_max_2
	PUBLIC	_dat_str_remington_2
	PUBLIC	_dat_str_arrested_4
	PUBLIC	_dat_str_arrested_5
	PUBLIC	_dat_str_final4_cat
	PUBLIC	_dat_str_final3_cat
	PUBLIC	_dat_str_f_pic
	PUBLIC	_dat_str_m_pic
	PUBLIC	_dat_str_laudude1_pic
	PUBLIC	_dat_str_dude
	PUBLIC	_dat_str_babe
	PUBLIC	_dat_str_world
	PUBLIC	_dat_str_which_difficulty_level_2
	PUBLIC	_dat_str_gender_pic
	PUBLIC	_dat_str_select_one_maximillian
	PUBLIC	_dat_str_which_difficulty_level
	PUBLIC	_dat_str_plot_txt
	PUBLIC	_dat_str_max_remington_s
	PUBLIC	_dat_str_mattress_full_cash
	PUBLIC	_dat_str_pl000a
	PUBLIC	_dat_str_pl000a_2
	PUBLIC	_dat_str_plot_txt_2
	PUBLIC	_dat_str_max_s_code_name
	PUBLIC	_dat_str_training_pic
	PUBLIC	_dat_str_practice
	PUBLIC	_dat_str_training
	PUBLIC	_dat_str_good
	PUBLIC	_dat_str_excellent
	PUBLIC	_dat_str_awesome
	PUBLIC	_dat_str_max_i_m_sure
	PUBLIC	_dat_str_among_these_faces
	PUBLIC	_shd_str_clue
	PUBLIC	_shd_str_none
	PUBLIC	_shd_str_clues_txt
	PUBLIC	_shd_clue_keys
	PUBLIC	_shd_str_clues_txt_2
	PUBLIC	_shd_str_new_information
	PUBLIC	_shd_str_additional_information
	PUBLIC	_shd_str_message_not_decoded
	PUBLIC	_shd_str_more
	PUBLIC	_shd_str_chronology
	PUBLIC	_shd_str_news
	PUBLIC	_shd_str_more_2
	PUBLIC	_shd_str_sent_msg_2
	PUBLIC	_shd_str_met
	PUBLIC	_shd_str_meeting_noted
	PUBLIC	_shd_str_chronology_2
	PUBLIC	_shd_str_news_2
	PUBLIC	_shd_str_none_log
	PUBLIC	_shd_str_nsyn_overflow
	PUBLIC	_shd_str_hideout
	PUBLIC	_shd_str_agent
	PUBLIC	_shd_str_safehouse
	PUBLIC	_shd_str_active_cel
	PUBLIC	_shd_str_office
	PUBLIC	_shd_str_please_insert_disk
	PUBLIC	_shd_str_if_3_5_insert
	PUBLIC	_shd_str_press_return_continue
	PUBLIC	_shd_str_facesf_pic
	PUBLIC	_shd_str_faces_pic
	PUBLIC	_dat_str_hall_fame
	PUBLIC	_dat_str_covert_action
	PUBLIC	_dat_str_hall_fame_2
	PUBLIC	_dat_str_env_sve
	PUBLIC	_dat_str_move_joystick_upper
	PUBLIC	_dat_str_move_joystick_lower
	PUBLIC	_dat_str_labs_pic
	PUBLIC	_dat_str_env_sve_2
	PUBLIC	_dat_str_title2_pan
	PUBLIC	_dat_str_credits_pan
	PUBLIC	_dat_str_do_want_create_new
	PUBLIC	_dat_str_env_sve_3
	PUBLIC	_dat_str_env_sve_4
	PUBLIC	_dat_str_animation_pan
	PUBLIC	_dat_str_env_sve_5
	PUBLIC	_dat_str_text_dta
	PUBLIC	_dat_str_sloc00
	PUBLIC	_dat_str_text_dta_2
	PUBLIC	_dat_str_rloc00
	PUBLIC	_dat_str_text_dta_3
	PUBLIC	_dat_str_sorg00
	PUBLIC	_dat_str_text_dta_4
	PUBLIC	_dat_str_rorg00
	PUBLIC	_dat_str_text_dta_5
	PUBLIC	_dat_str_fluf00
	PUBLIC	_shd_str_one_moment_please
	PUBLIC	_shd_str_sure_want_quit_no_2
	PUBLIC	_shd_str_briefing_pan
	PUBLIC	_shd_str_animation_pan
	PUBLIC	_shd_str_bld
	PUBLIC	_shd_str_agent_3
	PUBLIC	_shd_str_master_plan
	PUBLIC	_shd_str_secret
	PUBLIC	_shd_str_arrested_upper
	PUBLIC	_shd_str_hiding_upper
	PUBLIC	_shd_str_turned_upper
	PUBLIC	_shd_str_personnel_file
	PUBLIC	_shd_str_action_team
	PUBLIC	_shd_str_no_activity
	PUBLIC	_shd_str_which_drive_contains
	PUBLIC	_shd_str_which_drive_contains_2
	PUBLIC	_shd_str_press_drive_letter
	PUBLIC	_shd_str_press_escape_cancel
	PUBLIC	_shd_str_no_disk_drive
	PUBLIC	_shd_str_env_sve_put
	PUBLIC	_shd_str_env_sve
	PUBLIC	_shd_str_file_error
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
	PUBLIC	_shd_str_information_requires
	PUBLIC	_shd_str_text_dta_sloc
	PUBLIC	_shd_str_text_dta_rloc
	PUBLIC	_shd_str_text_dta_sorg
	PUBLIC	_shd_str_text_dta_rorg
	PUBLIC	_shd_str_text_dta_msg
	PUBLIC	_shd_str_text_dta_fluf
	PUBLIC	_shd_str_alrt00
	PUBLIC	_shd_str_text_dta_help
	PUBLIC	_shd_str_text_dta_aidd
	PUBLIC	_shd_str_text_dta_event
	PUBLIC	_shd_str_msg0000
	PUBLIC	_dat_key_plot_zero
	PUBLIC	_dat_colours_report
	PUBLIC	_dat_colours_title
	PUBLIC	_dat_colours_title_2
	PUBLIC	_shd_colours_screen
	PUBLIC	_shd_colours_screen_2
	PUBLIC	_dat_colours_main
	PUBLIC	_shd_colours_face
	PUBLIC	_dat_colours_badge
	PUBLIC	_dat_colours_grid
	PUBLIC	_dat_palette_title
	PUBLIC	_asm_plot_key
	PUBLIC	_asm_number_digits
	PUBLIC	_asm_number_digits_2
	PUBLIC	_asm_number_digits_3
	PUBLIC	_asm_number_digits_4
	PUBLIC	_asm_number_digits_5
	PUBLIC	_shm_clue_digits
	PUBLIC	_shm_message_key
	PUBLIC	_dat_str_ep_100
	PUBLIC	_dat_key_plot_start
	PUBLIC	_dat_str_blank
	PUBLIC	_dat_str_average
	PUBLIC	_dat_palette_badge
	PUBLIC	_shd_str_related_2
	PUBLIC	_shd_str_quote_3
	PUBLIC	_shd_str_quote_4
	PUBLIC	_shd_str_close_paren
	PUBLIC	_dat_str_clear
	PUBLIC	_dat_str_empty_15
	PUBLIC	_shd_str_ok
	PUBLIC	_shd_palette_menu
	PUBLIC	_shd_palette_face
	PUBLIC	_shd_str_space_13
	PUBLIC	_shd_str_comma_3
	PUBLIC	_shd_str_newline_12
	PUBLIC	_shm_probed_campaign
	PUBLIC	_shm_slot_digits
	PUBLIC	_shd_str_colon
	PUBLIC	_shd_str_space_slot
	PUBLIC	_shd_str_comma_2
	PUBLIC	_shd_str_stop_blank
	PUBLIC	_shd_str_newline_save
	PUBLIC	_shd_str_mode_read_text
	PUBLIC	_shd_fmt_line
	PUBLIC	_shd_fmt_line_2
	PUBLIC	_shd_str_space_12
	PUBLIC	_shd_fmt_line_3
	PUBLIC	_shm_substitute_tail
	PUBLIC	_shd_str_newline_wrap
	PUBLIC	_shd_str_ellipsis_2
	PUBLIC	_shd_str_empty_message
	PUBLIC	_shd_str_mark_80
	PUBLIC	_shd_str_mark_8f

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

; CL's own DW SEG _asm_FARBUF in CONST: a far address, not a variable.
dat_FARBUF_SEG	EQU	5BB8h

;==============================================================================
CODE_0	SEGMENT	PARA PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:CODE_0, ds:DGROUP, ss:DGROUP
drv_DAT_1000_0000	DB	0,0

_drv_real_FUN_1000_0002	PROC	FAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	push	es
	mov	ah,35h
	mov	al,24h
	int	21h		; DOS AH=35h: get interrupt vector (AL = vector)
	mov	word ptr ds:[drv_DAT_20d8_0042],es
	mov	word ptr ds:[drv_DAT_20d8_0044],bx
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
	mov	word ptr cs:[drv_DAT_1000_0000],0
	mov	ah,11h
	mov	dx,47h
	int	21h		; DOS AH=11h: find first file, by FCB
	or	al,al
	jz	L10098
	mov	ah,0Eh
	mov	dx,word ptr [bp+8]
	int	21h		; DOS AH=0Eh: select default drive
	mov	word ptr cs:[drv_DAT_1000_0000],0
	mov	ah,11h
	mov	dx,47h
	int	21h		; DOS AH=11h: find first file, by FCB
	or	al,al
	jnz	L10066
	cmp	word ptr cs:[drv_DAT_1000_0000],0
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
	mov	word ptr cs:[drv_DAT_1000_0000],0
	mov	ah,19h
	int	21h		; DOS AH=19h: get current default drive
	xor	al,1
	mov	dl,al
	mov	ah,0Eh
	int	21h		; DOS AH=0Eh: select default drive
	mov	ah,11h
	mov	dx,47h
	int	21h		; DOS AH=11h: find first file, by FCB
	cmp	word ptr cs:[drv_DAT_1000_0000],0
	jnz	L10070
L10098:
	cbw
	push	ax
	mov	ah,25h
	mov	al,24h
	push	ds
	mov	ds,word ptr ds:[drv_DAT_20d8_0042]
	mov	dx,word ptr ds:[drv_DAT_20d8_0044]
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
	mov	word ptr cs:[drv_DAT_1000_0000],1
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

_drv_real_FUN_1000_00ca	PROC	FAR
	mov	al,ds:[_shm_graphics_letter]
	cmp	al,4Dh
	jz	L100de
	cmp	al,43h
	jz	L100de
	cmp	al,45h
	jz	L100e3
	cmp	al,54h
	jz	L1011d
	retf
L100de:
	jmp	far ptr _drv_jump_gfx_set_palette
L100e3:
	push	si
	mov	si,sp
	mov	si,word ptr [si+6]
	mov	cl,0
	mov	dx,3DAh
L100ee:
	in	al,dx
	test	al,8
	jz	L100ee
L100f3:
	mov	dl,0DAh
	in	al,dx
	test	al,1
	jz	L100ee
	cli
	mov	dl,0C0h
	mov	al,cl
	out	dx,al
	jmp	short L10102
L10102:
	lodsb
	and	al,0Fh
	add	al,8
	and	al,17h
	out	dx,al
	jmp	short L1010c
L1010c:
	mov	ax,20h
	out	dx,al
	sti
	inc	cl
	aaa
	add	cl,ah
	cmp	cl,11h
	jbe	L100f3
	pop	si
	retf
L1011d:
	push	si
	mov	si,sp
	mov	si,word ptr [si+6]
	mov	cl,10h
	mov	dx,3DAh
L10128:
	in	al,dx
	test	al,8
	jz	L10128
L1012d:
	in	al,dx
	test	al,1
	jz	L10128
	cli
	mov	al,cl
	out	dx,al
	jmp	short L10138
L10138:
	mov	dl,0DEh
	lodsb
	out	dx,al
	jmp	short L1013e
L1013e:
	mov	dl,0DAh
	mov	al,0
	out	dx,al
	sti
	cmp	cl,2
	jz	L10154
	inc	cl
	cmp	cl,20h
	jc	L1012d
	mov	cl,2
	jmp	L1012d
L10154:
	pop	si
	retf
_drv_real_FUN_1000_00ca	ENDP

;------------------------------------------------------------------------------
; Jump into a driver through the slot whose address the caller pushed. With
; the cursor showing it far-calls instead, so the cursor can be redrawn after.
;------------------------------------------------------------------------------
drv_real_dispatch	PROC	NEAR
	cmp	byte ptr ds:[drv_DAT_20d8_4b5b],0
	jnz	L10169
	pop	word ptr cs:[L10164+3]
	jmp	short L10164
L10164:
	; The target is patched in by the POP above.
	jmp	dword ptr cs:[0]
L10169:
	mov	byte ptr ds:[drv_DAT_20d8_4b5a],1
	pop	word ptr cs:[L1017d+3]
	pop	word ptr ds:[drv_DAT_20d8_4b5c]
	pop	word ptr ds:[drv_DAT_20d8_4b5e]
	jmp	short L1017d
L1017d:
	; The target is patched in by the POP above.
	call	dword ptr cs:[0]
	dec	byte ptr ds:[drv_DAT_20d8_4b5a]
	jz	L10192
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_20d8_4b5a],0
L10192:
	jmp	dword ptr ds:[drv_DAT_20d8_4b5c]
drv_real_dispatch	ENDP
D10196	DB	0,0,0EAh,0,0,0,0,0
	DB	0

_drv_jump_mem_avail	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_mem_avail	ENDP
D101a4	DB	0,0

_drv_jump_gfx_grab	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_grab	ENDP
D101ab	DB	0,0

_drv_jump_gfx_fill	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_fill	ENDP
D101b2	DB	0,0

_drv_jump_gfx_char_width	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_char_width	ENDP
D101b9	DB	0,0

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
D101ce	DB	0,0,0EAh,0,0,0,0,0
	DB	0

_drv_jump_gfx_dissolve	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_dissolve	ENDP
D101dc	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0

_drv_jump_gfx_get_pixel	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_get_pixel	ENDP
D101f1	DB	0,0,0EAh,0,0,0,0

drv_jump_gfx_overlay_remove	PROC	NEAR
	call	drv_real_dispatch
L101fb:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_overlay_remove	ENDP
D10206	DB	0,0

_drv_jump_gfx_capability	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_capability	ENDP
D1020d	DB	0,0

_drv_jump_gfx_pool_alloc	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_pool_alloc	ENDP
D10214	DB	0,0

_drv_jump_gfx_row_put	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_row_put	ENDP
D1021b	DB	0,0

_drv_jump_gfx_copy_rect	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_copy_rect	ENDP
D10222	DB	0,0

_drv_jump_gfx_text	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_text	ENDP

drv_jump_FUN_1000_0229	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_FUN_1000_0229	ENDP
D10237	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

_drv_jump_gfx_set_palette	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_set_palette	ENDP
D10253	DB	0,0

_drv_jump_gfx_set_colour_map	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_set_colour_map	ENDP
D1025a	DB	0,0,0EAh,0,0,0,0

drv_jump_gfx_overlay_put	PROC	NEAR
	call	drv_real_dispatch
L10264:
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
D1027d	DB	0,0

_drv_jump_gfx_sprite_row	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_sprite_row	ENDP
D10284	DB	0,0

_drv_jump_gfx_sprite_begin	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_sprite_begin	ENDP
D1028b	DB	0,0,0EAh,0,0,0,0,0
	DB	0

_drv_jump_gfx_open	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_open	ENDP
D10299	DB	0,0

drv_jump_gfx_plot	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_plot	ENDP
D102a0	DB	0,0

drv_jump_gfx_edge_fill	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_edge_fill	ENDP
D102a7	DB	0,0

drv_jump_gfx_write_reset	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_write_reset	ENDP
D102ae	DB	0,0

drv_jump_gfx_set_colour	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_set_colour	ENDP
D102b5	DB	0,0

drv_jump_gfx_line	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_line	ENDP
D102bc	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0

drv_jump_gfx_select_page	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_select_page	ENDP
D102e6	DB	0,0

drv_jump_gfx_select_pic	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_select_pic	ENDP
D102ed	DB	0,0

drv_jump_gfx_edge_copy	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_edge_copy	ENDP
D102f4	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
D10413	DB	0,0

_drv_jump_read_key	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_read_key	ENDP
D1041a	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0

_drv_jump_joy_calibrate	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_joy_calibrate	ENDP
D1043d	DB	0,0

_drv_jump_joy_read	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_joy_read	ENDP
D10444	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

_drv_jump_snd_command	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_snd_command	ENDP
D10460	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0,0,0,0EAh,0,0,0
	DB	0,0,0,0EAh,0,0,0,0
	DB	0,0,0EAh,0,0,0,0,0

;------------------------------------------------------------------------------
; Load a driver: allocate all of memory, EXEC it as an overlay, shrink the
; block to what it needs, and return its segment. A second name loads a data
; file.
;------------------------------------------------------------------------------
drv_real_load	PROC	FAR
	mov	bx,sp
	mov	dx,word ptr [bx+4]
	mov	bx,word ptr [bx+6]
	push	si
	push	di
	push	ds
	push	es
	mov	word ptr ds:[drv_DAT_20d8_4b60],dx
	mov	word ptr ds:[drv_DAT_20d8_4b62],bx
	mov	ah,48h
	mov	bx,0FFFFh
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jc	L104c3
	mov	dx,OFFSET DGROUP:dat_message_pool
	jmp	drv_real_FUN_1000_055c
L104c3:
	mov	ah,48h
	sub	bx,100h
	mov	word ptr ds:[drv_DAT_20d8_4b66],bx
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jnc	L104d7
	mov	dx,OFFSET DGROUP:dat_str_ms_dos_lied_us
	jmp	drv_real_FUN_1000_055c
L104d7:
	mov	bx,OFFSET DGROUP:drv_DAT_20d8_4b68
	mov	word ptr [bx],ax
	mov	word ptr [bx+2],ax
	mov	ax,4B03h
	mov	dx,word ptr ds:[drv_DAT_20d8_4b60]
	push	ds
	pop	es
	mov	word ptr ds:[drv_DAT_20d8_4b64],sp
	int	21h		; DOS AH=4Bh AL=03h: load overlay
	mov	dx,DGROUP
	mov	ds,dx
	mov	es,dx
	mov	ss,dx
	mov	sp,word ptr ds:[drv_DAT_20d8_4b64]
	jnc	L10519
	cmp	ax,2
	jnz	L10508
	mov	dx,OFFSET DGROUP:dat_str_filename_not_found
	jmp	drv_real_FUN_1000_055c
L10508:
	cmp	ax,8
	jnz	L10513
	mov	dx,OFFSET DGROUP:dat_str_not_enough_memory_load
	jmp	drv_real_FUN_1000_055c
L10513:
	mov	dx,OFFSET DGROUP:dat_str_overlay_load_failed
	jmp	drv_real_FUN_1000_055c
L10519:
	mov	es,word ptr ds:[drv_DAT_20d8_4b68]
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
	cmp	bx,word ptr ds:[drv_DAT_20d8_4b66]
	jbe	L10549
	mov	dx,OFFSET DGROUP:dat_str_overlay_has_overrun
	jmp	drv_real_FUN_1000_055c
L10549:
	mov	ah,4Ah
	int	21h		; DOS AH=4Ah: resize memory block (ES = segment, BX = paragraphs)
	jnc	L10555
	mov	dx,OFFSET DGROUP:dat_str_unable_shrink_overlay
	jmp	drv_real_FUN_1000_055c
L10555:
	mov	ax,es
	pop	es
	pop	ds
	pop	di
	pop	si
	retf
drv_real_load	ENDP

drv_real_FUN_1000_055c	PROC	NEAR
	mov	ah,9
	int	21h		; DOS AH=09h: write $-terminated string to stdout
	mov	ax,4C00h
	int	21h		; DOS AH=4Ch: terminate (AL = code)
drv_real_FUN_1000_055c	ENDP

;------------------------------------------------------------------------------
; Read the data file a driver load names into memory after the driver, in 32K
; goes, and return the segment past it.
;------------------------------------------------------------------------------
drv_real_load_data	PROC	NEAR
	push	ds
	mov	dx,word ptr ds:[drv_DAT_20d8_4b62]
	or	dx,dx
	jz	L105b7
	mov	ax,3D00h
	int	21h		; DOS AH=3Dh: open existing file (AL = access mode)
	jnc	L1057a
	mov	dx,OFFSET DGROUP:dat_str_filename_not_found
	jmp	drv_real_FUN_1000_055c
L1057a:
	mov	ds,bx
	mov	bx,ax
	mov	ax,3F00h
	mov	cx,8000h
	xor	dx,dx
	int	21h		; DOS AH=3Fh: read from file or device (BX = handle, CX = count)
	jnc	L1058f
	mov	dx,OFFSET DGROUP:dat_str_filename_not_found
	jmp	drv_real_FUN_1000_055c
L1058f:
	cmp	ax,cx
	jc	L1059a
	mov	ax,ds
	add	ax,800h
	mov	ds,ax
L1059a:
	add	ax,0Fh
	shr	ax,1
	shr	ax,1
	shr	ax,1
	shr	ax,1
	mov	dx,ds
	add	dx,ax
	mov	ax,3E00h
	int	21h		; DOS AH=3Eh: close file (BX = handle)
	jnc	L105b5
	mov	dx,OFFSET DGROUP:dat_str_filename_not_found
	jmp	drv_real_FUN_1000_055c
L105b5:
	mov	bx,dx
L105b7:
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
	lea	di,[D10196]
	add	di,ax
	mov	ax,CODE_0
	mov	es,ax
	mov	cx,word ptr ds:[30h]
	mov	ax,ds:[28h]
L105e0:
	add	di,3
	movsw
	stosw
	loop	L105e0
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
	jnc	L10600
	mov	dx,OFFSET DGROUP:dat_str_error_releasing_overlay
	jmp	drv_real_FUN_1000_055c
L10600:
	pop	es
	retf
drv_real_free	ENDP

_drv_real_fill_rect	PROC	FAR
	push	bp
	mov	bp,sp
	push	di
	push	si
	call	drv_real_FUN_1000_068a
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	call	far ptr drv_jump_gfx_select_page
	mov	si,word ptr [bp+0Ah]
	add	si,word ptr [bx+4]
	mov	word ptr ds:[drv_DAT_20d8_5003],si
	mov	cx,word ptr [bp+0Eh]
	shl	si,1
	lea	di,[drv_DAT_20d8_4c8f]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	mov	dx,cx
	rep stosw
	mov	cx,dx
	lea	di,[drv_DAT_20d8_4e47]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	add	ax,word ptr [bp+0Ch]
	dec	ax
	rep stosw
	mov	ax,word ptr [bp+10h]
	call	far ptr drv_jump_gfx_set_colour
	mov	ax,ds:[drv_DAT_20d8_5003]
	mov	cx,ax
	add	cx,word ptr [bp+0Eh]
	dec	cx
	mov	word ptr ds:[drv_DAT_20d8_5005],cx
	mov	bx,OFFSET DGROUP:drv_DAT_20d8_4c8f
	call	far ptr drv_jump_gfx_edge_fill
	call	far ptr drv_jump_gfx_write_reset
	pop	si
	pop	di
	pop	bp
	retf
_drv_real_fill_rect	ENDP
D1066d	DB	0

drv_real_FUN_1000_066e	PROC	FAR
	push	di
	push	si
	push	bp
	mov	ax,ds:[drv_DAT_20d8_5003]
	mov	cx,word ptr ds:[drv_DAT_20d8_5005]
	mov	bx,OFFSET DGROUP:drv_DAT_20d8_4c8f
	call	far ptr drv_jump_gfx_edge_fill
	pop	bp
	pop	si
	pop	di
	retf
drv_real_FUN_1000_066e	ENDP

drv_real_FUN_1000_0684	PROC	FAR
	push	di
	call	drv_real_FUN_1000_068a
	pop	di
	retf
drv_real_FUN_1000_0684	ENDP

drv_real_FUN_1000_068a	PROC	NEAR
	mov	ax,DGROUP
	mov	es,ax
	mov	di,word ptr ds:[drv_DAT_20d8_5003]
	or	di,di
	js	L106bf
	mov	cx,word ptr ds:[drv_DAT_20d8_5005]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,OFFSET DGROUP:drv_DAT_20d8_4c8f
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[drv_DAT_20d8_5003],ax
	mov	cx,bx
	mov	di,dx
	add	di,OFFSET DGROUP:drv_DAT_20d8_4e47
	sub	ax,ax
	rep stosw
	mov	ds:[drv_DAT_20d8_5005],ax
L106bf:
	ret
drv_real_FUN_1000_068a	ENDP

drv_real_FUN_1000_06c0	PROC	NEAR
	mov	ax,DGROUP
	mov	es,ax
	mov	cx,di
	or	si,si
	lea	di,[drv_DAT_20d8_4c8f]
	jz	L106d9
	cmp	si,word ptr ds:[drv_DAT_20d8_5015]
	jnz	L1071a
	lea	di,[drv_DAT_20d8_4e47]
L106d9:
	cmp	cx,dx
	jge	L106df
	xchg	cx,dx
L106df:
	or	dx,dx
	jns	L106e5
	sub	dx,dx
L106e5:
	cmp	cx,word ptr ds:[drv_DAT_20d8_5017]
	jle	L106ef
	mov	cx,word ptr ds:[drv_DAT_20d8_5017]
L106ef:
	add	si,word ptr ds:[drv_DAT_20d8_5007]
	add	cx,word ptr ds:[drv_DAT_20d8_5009]
	add	dx,word ptr ds:[drv_DAT_20d8_5009]
	cmp	cx,word ptr ds:[drv_DAT_20d8_5005]
	jbe	L10705
	mov	word ptr ds:[drv_DAT_20d8_5005],cx
L10705:
	cmp	dx,word ptr ds:[drv_DAT_20d8_5003]
	jnc	L1070f
	mov	word ptr ds:[drv_DAT_20d8_5003],dx
L1070f:
	add	di,dx
	add	di,dx
	sub	cx,dx
	inc	cx
	mov	ax,si
	rep stosw
L1071a:
	ret
drv_real_FUN_1000_06c0	ENDP
	sub	si,si
	or	bx,bx
	js	drv_real_FUN_1000_06c0
	mov	si,word ptr ds:[drv_DAT_20d8_5015]
	cmp	bx,si
	jg	drv_real_FUN_1000_06c0
	ret

drv_real_FUN_1000_072a	PROC	NEAR
	mov	ax,ds:[drv_DAT_20d8_5007]
	add	word ptr ds:[drv_DAT_20d8_4c87],ax
	add	word ptr ds:[drv_DAT_20d8_4c89],ax
	mov	ax,ds:[drv_DAT_20d8_5009]
	add	word ptr ds:[drv_DAT_20d8_4c8b],ax
	add	word ptr ds:[drv_DAT_20d8_4c8d],ax
	mov	ax,ds:[drv_DAT_20d8_4c89]
	cmp	ax,word ptr ds:[drv_DAT_20d8_4c87]
	jnc	L10762
	mov	bx,word ptr ds:[drv_DAT_20d8_4c87]
	mov	word ptr ds:[drv_DAT_20d8_4c89],bx
	mov	ds:[drv_DAT_20d8_4c87],ax
	mov	ax,ds:[drv_DAT_20d8_4c8d]
	mov	bx,word ptr ds:[drv_DAT_20d8_4c8b]
	mov	word ptr ds:[drv_DAT_20d8_4c8d],bx
	mov	ds:[drv_DAT_20d8_4c8b],ax
L10762:
	mov	bx,word ptr ds:[drv_DAT_20d8_4c89]
	sub	bx,word ptr ds:[drv_DAT_20d8_4c87]
	mov	word ptr ds:[drv_DAT_20d8_4fff],bx
	mov	ax,ds:[drv_DAT_20d8_4c8d]
	mov	dx,ax
	mov	cx,word ptr ds:[drv_DAT_20d8_4c8b]
	sub	ax,cx
	mov	bp,2
	jns	L10784
	xchg	cx,dx
	neg	bp
	neg	ax
L10784:
	mov	ds:[drv_DAT_20d8_5001],ax
	cmp	dx,word ptr ds:[drv_DAT_20d8_5005]
	jbe	L10791
	mov	word ptr ds:[drv_DAT_20d8_5005],dx
L10791:
	cmp	cx,word ptr ds:[drv_DAT_20d8_5003]
	jnc	L1079b
	mov	word ptr ds:[drv_DAT_20d8_5003],cx
L1079b:
	cmp	ax,bx
	jnc	drv_real_FUN_1000_07ea
	mov	di,word ptr ds:[drv_DAT_20d8_4c8b]
	shl	di,1
	mov	ax,ds:[drv_DAT_20d8_4c87]
	mov	dx,word ptr ds:[drv_DAT_20d8_4fff]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[drv_DAT_20d8_5001]
	jmp	L107cb
L107bc:
	cmp	ax,word ptr [di+drv_DAT_20d8_4e47]
	jbe	L107c6
	mov	word ptr [di+drv_DAT_20d8_4e47],ax
L107c6:
	inc	ax
	sub	bx,dx
	add	di,bp
L107cb:
	cmp	ax,word ptr [di+drv_DAT_20d8_4c8f]
	jnc	L107d5
	mov	word ptr [di+drv_DAT_20d8_4c8f],ax
L107d5:
	dec	cx
	js	L107df
	add	bx,si
	jns	L107bc
	inc	ax
	jmp	L107d5
L107df:
	cmp	ax,word ptr [di+drv_DAT_20d8_4e47]
	jbe	L107e9
	mov	word ptr [di+drv_DAT_20d8_4e47],ax
L107e9:
	ret
drv_real_FUN_1000_072a	ENDP

drv_real_FUN_1000_07ea	PROC	NEAR
	mov	di,word ptr ds:[drv_DAT_20d8_4c8b]
	shl	di,1
	mov	ax,ds:[drv_DAT_20d8_4c87]
	mov	dx,word ptr ds:[drv_DAT_20d8_5001]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[drv_DAT_20d8_4fff]
L10804:
	cmp	ax,word ptr [di+drv_DAT_20d8_4c8f]
	jnc	L1080e
	mov	word ptr [di+drv_DAT_20d8_4c8f],ax
L1080e:
	cmp	ax,word ptr [di+drv_DAT_20d8_4e47]
	jbe	L10818
	mov	word ptr [di+drv_DAT_20d8_4e47],ax
L10818:
	dec	cx
	js	L10826
	add	di,bp
	add	bx,si
	js	L10804
	sub	bx,dx
	inc	ax
	jmp	L10804
L10826:
	ret
drv_real_FUN_1000_07ea	ENDP
D10827	DB	0

drv_real_FUN_1000_0828	PROC	FAR
	call	drv_real_FUN_1000_0838
	retf
drv_real_FUN_1000_0828	ENDP

drv_real_FUN_1000_082c	PROC	FAR
	push	bp
	push	si
	push	di
	push	es
	call	drv_real_FUN_1000_0838
	pop	es
	pop	di
	pop	si
	pop	bp
	retf
drv_real_FUN_1000_082c	ENDP

drv_real_FUN_1000_0838	PROC	NEAR
	sub	ax,ax
	mov	es,ax
	; The INT 0 vector, in segment zero.
	push	word ptr es:[0]
	push	word ptr es:[2]
	lea	ax,[drv_real_FUN_1000_09e5]
	mov	es:[0],ax
	mov	word ptr es:[2],CODE_0
	push	ds
	pop	es
	jmp	L108c0
L1085a:
	sub	ax,ax
	mov	es,ax
	pop	word ptr es:[2]
	pop	word ptr es:[0]
	push	ds
	pop	es
	mov	ax,ds:[drv_DAT_20d8_4c87]
	mov	bx,word ptr ds:[drv_DAT_20d8_4c8b]
	mov	cx,word ptr ds:[drv_DAT_20d8_4c89]
	mov	dx,word ptr ds:[drv_DAT_20d8_4c8d]
	call	far ptr drv_jump_gfx_line
	clc
	ret
L10880:
	sub	ax,ax
	mov	es,ax
	pop	word ptr es:[2]
	pop	word ptr es:[0]
	push	ds
	pop	es
	stc
	ret
L10892:
	cmc
	rcr	dx,1
	mov	word ptr ds:[drv_DAT_20d8_500d],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_20d8_5011],dx
	mov	dx,di
	sub	dx,bp
	jno	L108ab
	cmc
	rcr	dx,1
	jmp	L1091b
L108ab:
	sar	dx,1
	jmp	L1091b
L108b0:
	cmc
	rcr	dx,1
	sar	word ptr ds:[drv_DAT_20d8_500d],1
	sar	word ptr ds:[drv_DAT_20d8_5011],1
	jmp	L1091b
L108be:
	jmp	L10880
L108c0:
	mov	cx,word ptr ds:[drv_DAT_20d8_4c87]
	mov	dx,word ptr ds:[drv_DAT_20d8_4c8b]
	mov	si,word ptr ds:[drv_DAT_20d8_4c89]
	mov	di,word ptr ds:[drv_DAT_20d8_4c8d]
	mov	bx,cx
	mov	bp,dx
	call	drv_real_FUN_1000_09c4
	mov	ds:[drv_DAT_20d8_500c],al
	mov	bx,si
	mov	bp,di
	call	drv_real_FUN_1000_09c4
	jnz	L108fd
	cmp	byte ptr ds:[drv_DAT_20d8_500c],0
	jnz	L108ed
	jmp	L1085a
L108ed:
	xchg	cx,si
	xchg	dx,di
	xchg	byte ptr ds:[drv_DAT_20d8_500c],al
	mov	word ptr ds:[drv_DAT_20d8_4c87],cx
	mov	word ptr ds:[drv_DAT_20d8_4c8b],dx
L108fd:
	test	byte ptr ds:[drv_DAT_20d8_500c],al
	jnz	L108be
	mov	bp,dx
	mov	dx,si
	sub	dx,cx
	jo	L10892
	mov	word ptr ds:[drv_DAT_20d8_500d],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_20d8_5011],dx
	mov	dx,di
	sub	dx,bp
	jo	L108b0
L1091b:
	mov	word ptr ds:[drv_DAT_20d8_500f],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_20d8_5013],dx
L10925:
	test	al,9
	jz	L10961
	sub	bx,bx
	or	si,si
	js	L10933
	mov	bx,word ptr ds:[drv_DAT_20d8_5015]
L10933:
	mov	ax,bx
	sub	ax,cx
	imul	word ptr ds:[drv_DAT_20d8_500f]
	push	bx
	mov	bx,dx
	idiv	word ptr ds:[drv_DAT_20d8_500d]
	mov	bl,bh
	xor	bl,byte ptr ds:[drv_DAT_20d8_500d+1]
	jns	L1094d
	neg	dx
	dec	ax
L1094d:
	sub	dx,word ptr ds:[drv_DAT_20d8_5011]
	xor	dh,bh
	js	L10956
	inc	ax
L10956:
	pop	bx
	add	ax,bp
	js	L10969
	cmp	ax,word ptr ds:[drv_DAT_20d8_5017]
	jle	L1099a
L10961:
	mov	bx,word ptr ds:[drv_DAT_20d8_5017]
	cmp	di,bx
	jg	L1096b
L10969:
	sub	bx,bx
L1096b:
	mov	ax,bx
	sub	ax,bp
	imul	word ptr ds:[drv_DAT_20d8_500d]
	push	bx
	mov	bx,dx
L10976:
	idiv	word ptr ds:[drv_DAT_20d8_500f]
	mov	bl,bh
	xor	bl,byte ptr ds:[drv_DAT_20d8_500f+1]
	jns	L10985
	neg	dx
	dec	ax
L10985:
	sub	dx,word ptr ds:[drv_DAT_20d8_5013]
	xor	dh,bh
	js	L1098e
	inc	ax
L1098e:
	pop	bx
	add	ax,cx
	js	L109ab
	cmp	ax,word ptr ds:[drv_DAT_20d8_5015]
	jg	L109ab
	xchg	bx,ax
L1099a:
	cmp	byte ptr ds:[drv_DAT_20d8_500c],0
	jnz	L109ae
	mov	ds:[drv_DAT_20d8_4c8d],ax
	mov	word ptr ds:[drv_DAT_20d8_4c89],bx
	jmp	L1085a
L109ab:
	jmp	L10880
L109ae:
	mov	ds:[drv_DAT_20d8_4c8b],ax
	mov	word ptr ds:[drv_DAT_20d8_4c87],bx
	xchg	cx,si
	xchg	bp,di
	mov	al,ds:[drv_DAT_20d8_500c]
	mov	byte ptr ds:[drv_DAT_20d8_500c],0
	jmp	L10925
drv_real_FUN_1000_0838	ENDP

drv_real_FUN_1000_09c4	PROC	NEAR
	mov	al,0Fh
	or	bx,bx
	js	L109cc
	and	al,0F7h
L109cc:
	cmp	bx,word ptr ds:[drv_DAT_20d8_5015]
	jg	L109d4
	and	al,0FEh
L109d4:
	or	bp,bp
	js	L109da
	and	al,0FBh
L109da:
	cmp	bp,word ptr ds:[drv_DAT_20d8_5017]
	jg	L109e2
	and	al,0FDh
L109e2:
	or	al,al
	ret
drv_real_FUN_1000_09c4	ENDP

drv_real_FUN_1000_09e5	PROC	FAR
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+2],OFFSET L10976
	mov	ax,ds:[drv_DAT_20d8_500f]
	jz	L109f5
	mov	ax,ds:[drv_DAT_20d8_500d]
L109f5:
	xor	dx,ax
	mov	ax,7F00h
	jns	L109fe
	neg	ax
L109fe:
	add	word ptr [bp+2],4
	sub	dx,dx
	pop	bp
	iret
drv_real_FUN_1000_09e5	ENDP

_drv_real_draw_line	PROC	FAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx+6]
	mov	ds:[drv_DAT_20d8_5015],ax
	mov	ax,word ptr [bx+8]
	mov	ds:[drv_DAT_20d8_5017],ax
	call	far ptr drv_jump_gfx_select_pic
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_20d8_4c87],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_20d8_4c8b],ax
	mov	ax,word ptr [bp+0Ch]
	mov	ds:[drv_DAT_20d8_4c89],ax
	mov	ax,word ptr [bp+0Eh]
	mov	ds:[drv_DAT_20d8_4c8d],ax
	mov	ax,word ptr [bp+10h]
	call	far ptr drv_jump_gfx_set_colour
	call	drv_real_FUN_1000_0838
	call	far ptr drv_jump_gfx_write_reset
	pop	di
	pop	si
	pop	bp
	retf
_drv_real_draw_line	ENDP

drv_real_FUN_1000_0a4b	PROC	FAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	mov	bx,word ptr [bp+6]
	mov	cx,word ptr [bp+8]
	or	cx,cx
	js	L10a86
	cmp	cx,word ptr [bx+6]
	jg	L10a86
	mov	dx,word ptr [bp+0Ah]
	or	dx,dx
	js	L10a86
	cmp	dx,word ptr [bx+8]
	jg	L10a86
	call	far ptr drv_jump_gfx_select_pic
	mov	ax,word ptr [bp+0Ch]
	call	far ptr drv_jump_gfx_set_colour
	mov	ax,cx
	mov	bx,dx
	call	far ptr drv_jump_gfx_plot
	call	far ptr drv_jump_gfx_write_reset
L10a86:
	pop	di
	pop	si
	pop	bp
	retf
drv_real_FUN_1000_0a4b	ENDP

_drv_real_unpack_start	PROC	FAR
	push	si
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10aa3
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10aa3:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	mov	dx,ax
	and	al,1
	mov	ds:[drv_DAT_20d8_77af],al
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10ac7
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10ac7:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	mov	ds:[_shm_sprite_width],ax
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10ae7
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10ae7:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	mov	ds:[_shm_sprite_height],ax
	test	dx,8
	jz	L10afd
	add	word ptr ds:[_shm_source_at],10h
	jmp	L10b09
L10afd:
	test	dx,10h
	jz	L10b15
	add	word ptr ds:[_shm_source_at],80h
L10b09:
	xor	ax,ax
	push	si
	push	ax
	call	far ptr _drv_jump_gfx_set_colour_map
	add	sp,4
L10b15:
	call	drv_real_FUN_1000_0b9b
	pop	si
	retf
_drv_real_unpack_start	ENDP

_drv_real_palette_read	PROC	FAR
	push	si
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10b33
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10b33:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	and	al,1
	mov	ds:[drv_DAT_20d8_77af],al
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10b55
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10b55:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	mov	ds:[_shm_palette_count],ax
	call	drv_real_FUN_1000_0b9b
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
	call	drv_real_FUN_1000_0c0f
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
	call	drv_real_FUN_1000_0c0f
	mov	word ptr ds:[_shm_source_at],si
	pop	di
	pop	si
	pop	bp
	retf
_drv_real_unpack_row	ENDP

drv_real_FUN_1000_0b9b	PROC	NEAR
	mov	byte ptr ds:[drv_DAT_20d8_77a4],0
	mov	byte ptr ds:[drv_DAT_20d8_77a5],0
	mov	ax,OFFSET DGROUP:asm_block_77b3+512
	mov	ds:[drv_DAT_20d8_77a0],ax
	mov	si,word ptr ds:[_shm_source_at]
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10bc3
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10bc3:
	lodsw
	mov	word ptr ds:[_shm_source_at],si
	cmp	al,0Bh
	jbe	L10bce
	mov	al,0Bh
L10bce:
	mov	ds:[drv_DAT_20d8_77a7],al
	mov	ds:[drv_DAT_20d8_77ac],ax
	mov	byte ptr ds:[drv_DAT_20d8_77ae],8
drv_real_FUN_1000_0b9b	ENDP

drv_real_FUN_1000_0bd9	PROC	NEAR
	mov	byte ptr ds:[drv_DAT_20d8_77a6],9
	mov	word ptr ds:[drv_DAT_20d8_77a8],1FFh
	mov	dx,100h
	mov	word ptr ds:[drv_DAT_20d8_77aa],dx
	mov	ax,0FFFFh
	xor	bx,bx
	mov	cx,800h
L10bf3:
	mov	word ptr [bx+drv_DAT_20d8_5f9a],ax
	add	bx,3
	loop	L10bf3
	mov	al,0
	xor	bx,bx
	mov	cx,100h
L10c03:
	mov	byte ptr [bx+drv_DAT_20d8_5f9c],al
	inc	al
	add	bx,3
	loop	L10c03
	ret
drv_real_FUN_1000_0bd9	ENDP

drv_real_FUN_1000_0c0f	PROC	NEAR
	cmp	byte ptr ds:[drv_DAT_20d8_77af],0
	jz	L10c19
	inc	cx
	shr	cx,1
L10c19:
	mov	word ptr ds:[drv_DAT_20d8_77a2],cx
	mov	ax,ds:[drv_DAT_20d8_77a0]
	mov	word ptr ds:[drv_DAT_20d8_77a0],sp
	mov	sp,ax
	mov	dx,word ptr ds:[drv_DAT_20d8_77aa]
L10c2a:
	cmp	byte ptr ds:[drv_DAT_20d8_77a4],0
	jnz	L10c52
	call	drv_real_FUN_1000_0c8b
	cmp	al,90h
	jz	L10c3e
	mov	ds:[drv_DAT_20d8_77a5],al
	jmp	L10c59
L10c3e:
	call	drv_real_FUN_1000_0c8b
	or	al,al
	jnz	L10c4d
	mov	al,90h
	mov	ds:[drv_DAT_20d8_77a5],al
	jmp	L10c59
L10c4d:
	dec	al
	mov	ds:[drv_DAT_20d8_77a4],al
L10c52:
	mov	al,ds:[drv_DAT_20d8_77a5]
	dec	byte ptr ds:[drv_DAT_20d8_77a4]
L10c59:
	cmp	byte ptr ds:[drv_DAT_20d8_77af],0
	jz	L10c76
	mov	ah,al
	and	al,0Fh
	shr	ah,1
	shr	ah,1
	shr	ah,1
	shr	ah,1
	stosw
	dec	word ptr ds:[drv_DAT_20d8_77a2]
	jnz	L10c2a
	jmp	L10c7d
L10c76:
	stosb
	dec	word ptr ds:[drv_DAT_20d8_77a2]
	jnz	L10c2a
L10c7d:
	mov	word ptr ds:[drv_DAT_20d8_77aa],dx
	mov	ax,ds:[drv_DAT_20d8_77a0]
	mov	word ptr ds:[drv_DAT_20d8_77a0],sp
	mov	sp,ax
	ret
drv_real_FUN_1000_0c0f	ENDP

drv_real_FUN_1000_0c8b	PROC	NEAR
	pop	bp
	cmp	sp,OFFSET DGROUP:asm_block_77b3+512
	jz	L10c95
L10c92:
	pop	ax
	jmp	bp
L10c95:
	mov	bx,word ptr ds:[drv_DAT_20d8_77ac]
	mov	cl,10h
	mov	ch,byte ptr ds:[drv_DAT_20d8_77ae]
	sub	cl,ch
	shr	bx,cl
	mov	cl,ch
L10ca5:
	cmp	cl,byte ptr ds:[drv_DAT_20d8_77a6]
	jge	L10ccc
	cmp	si,word ptr ds:[_shd_archive_buffer_end]
	jc	L10cbf
	push	bx
	push	cx
	push	dx
	call	dword ptr ds:[_shm_refill]
	pop	dx
	pop	cx
	pop	bx
	mov	si,word ptr ds:[_shm_source_at]
L10cbf:
	lodsw
	mov	ds:[drv_DAT_20d8_77ac],ax
	shl	ax,cl
	or	bx,ax
	add	cl,10h
	jmp	L10ca5
L10ccc:
	sub	cl,byte ptr ds:[drv_DAT_20d8_77a6]
	mov	byte ptr ds:[drv_DAT_20d8_77ae],cl
	mov	ax,bx
	and	ax,word ptr ds:[drv_DAT_20d8_77a8]
	mov	cx,ax
	cmp	ax,dx
	jl	L10cea
	mov	cx,dx
	mov	ax,ds:[drv_DAT_20d8_77b0]
	mov	bl,byte ptr ds:[drv_DAT_20d8_77b2]
	push	bx
L10cea:
	mov	bx,ax
	add	bx,ax
	add	bx,ax
	mov	ax,word ptr [bx+drv_DAT_20d8_5f9a]
	inc	ax
	jz	L10cff
	dec	ax
	mov	bl,byte ptr [bx+drv_DAT_20d8_5f9c]
	push	bx
	jmp	L10cea
L10cff:
	mov	al,byte ptr [bx+drv_DAT_20d8_5f9c]
	mov	ds:[drv_DAT_20d8_77b2],al
	push	ax
	mov	bx,dx
	add	bx,dx
	add	bx,dx
	mov	byte ptr [bx+drv_DAT_20d8_5f9c],al
	mov	ax,ds:[drv_DAT_20d8_77b0]
	mov	word ptr [bx+drv_DAT_20d8_5f9a],ax
	inc	dx
	cmp	dx,word ptr ds:[drv_DAT_20d8_77a8]
	jle	L10d28
	inc	byte ptr ds:[drv_DAT_20d8_77a6]
	stc
	rcl	word ptr ds:[drv_DAT_20d8_77a8],1
L10d28:
	mov	al,ds:[drv_DAT_20d8_77a6]
	cmp	al,byte ptr ds:[drv_DAT_20d8_77a7]
	jle	L10d34
	call	drv_real_FUN_1000_0bd9
L10d34:
	mov	word ptr ds:[drv_DAT_20d8_77b0],cx
	jmp	L10c92
drv_real_FUN_1000_0c8b	ENDP
D10d3b	DB	0
drv_DAT_1000_0d3c	DB	0,0
drv_DAT_1000_0d3e	DB	0,0

_drv_real_sprite_put	PROC	NEAR
	pop	word ptr cs:[drv_DAT_1000_0d3c]
	pop	word ptr cs:[drv_DAT_1000_0d3e]
	call	far ptr _drv_jump_gfx_sprite_put_clipped
	push	bp
	mov	bp,sp
	mov	bp,word ptr [bp+2]
	call	drv_real_FUN_1000_0d8b
	pop	bp
	jmp	dword ptr cs:[drv_DAT_1000_0d3c]
_drv_real_sprite_put	ENDP

_drv_real_sprite_put_2	PROC	NEAR
	pop	word ptr cs:[drv_DAT_1000_0d3c]
	pop	word ptr cs:[drv_DAT_1000_0d3e]
	call	far ptr _drv_jump_gfx_sprite_put_clipped
	push	bp
	mov	bp,sp
	mov	bp,word ptr [bp+2]
	push	ax
	push	dx
	call	drv_real_FUN_1000_0d8b
	pop	dx
	pop	ax
	xor	byte ptr [bp+0],1
	call	drv_real_FUN_1000_0d8b
	xor	byte ptr [bp+0],1
	pop	bp
	jmp	dword ptr cs:[drv_DAT_1000_0d3c]
_drv_real_sprite_put_2	ENDP

drv_real_FUN_1000_0d8b	PROC	NEAR
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
	js	L10dee
	mov	di,word ptr es:[bx+2]
	add	di,word ptr [bp+4]
	cmp	di,word ptr [si+drv_DAT_20d8_501a]
	jnc	L10db2
	mov	word ptr [si+drv_DAT_20d8_501a],di
L10db2:
	mov	cx,word ptr es:[bx+6]
	add	cx,di
	dec	cx
	cmp	cx,word ptr [si+drv_DAT_20d8_501e]
	jbe	L10dc3
	mov	word ptr [si+drv_DAT_20d8_501e],cx
L10dc3:
	shl	di,1
	shl	cx,1
	mov	ax,word ptr [si+addr_page_row_tables]
	add	di,ax
	add	cx,ax
	mov	ax,word ptr es:[bx]
	add	ax,word ptr [bp+2]
	add	dx,ax
L10dd7:
	cmp	ax,word ptr [di]
	jnc	L10ddd
	mov	word ptr [di],ax
L10ddd:
	cmp	dx,word ptr [di+190h]
	jbe	L10de7
	mov	word ptr [di+190h],dx
L10de7:
	add	di,2
	cmp	di,cx
	jbe	L10dd7
L10dee:
	pop	si
	pop	di
	pop	es
	ret
drv_real_FUN_1000_0d8b	ENDP

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
	mov	ax,word ptr [bp+drv_DAT_20d8_501a]
	mov	cx,word ptr [bp+drv_DAT_20d8_501e]
	mov	bx,word ptr [bp+addr_page_row_tables]
	push	bp
	call	far ptr drv_jump_gfx_edge_copy
	pop	bp
	mov	ax,ds
	mov	es,ax
	mov	di,word ptr [bp+drv_DAT_20d8_501a]
	or	di,di
	js	L10e4d
	mov	cx,word ptr [bp+drv_DAT_20d8_501e]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,word ptr [bp+addr_page_row_tables]
	mov	ax,0FFFFh
	rep stosw
	mov	word ptr [bp+drv_DAT_20d8_501a],ax
	mov	cx,bx
	mov	di,dx
	add	di,word ptr [bp+addr_page_row_tables+4]
	sub	ax,ax
	rep stosw
	mov	word ptr [bp+drv_DAT_20d8_501e],ax
L10e4d:
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
	mov	di,word ptr ds:[drv_DAT_20d8_501a]
	or	di,di
	js	L10e87
	mov	cx,word ptr ds:[drv_DAT_20d8_501e]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,word ptr ds:[addr_page_row_tables]
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[drv_DAT_20d8_501a],ax
	mov	cx,bx
	mov	di,dx
	add	di,word ptr ds:[addr_page_row_tables+4]
	sub	ax,ax
	rep stosw
	mov	ds:[drv_DAT_20d8_501e],ax
L10e87:
	mov	di,word ptr ds:[drv_DAT_20d8_501c]
	or	di,di
	js	L10eb7
	mov	cx,word ptr ds:[drv_DAT_20d8_5020]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,word ptr ds:[addr_page_row_tables+2]
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[drv_DAT_20d8_501c],ax
	mov	cx,bx
	mov	di,dx
	add	di,word ptr ds:[addr_page_row_tables+6]
	sub	ax,ax
	rep stosw
	mov	ds:[drv_DAT_20d8_5020],ax
L10eb7:
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
	jz	L10f08
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
	or	ax,ax
	jz	L10f08
	mov	ax,0Ch
	mov	cx,1Fh
	mov	dx,cs
	mov	es,dx
	lea	dx,[drv_real_mouse_event]
	int	33h		; mouse AX=000Ch: set user-defined event handler
	mov	ax,3
	int	33h		; mouse AX=0003h: get position and button status
	mov	word ptr ds:[drv_DAT_20d8_5678],0
	cmp	cx,0C8h
	jc	L10efc
	shr	cx,1
	mov	word ptr ds:[drv_DAT_20d8_5678],1
L10efc:
	mov	word ptr ds:[drv_DAT_20d8_566e],bx
	mov	word ptr ds:[drv_DAT_20d8_566a],cx
	mov	word ptr ds:[drv_DAT_20d8_566c],dx
L10f08:
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
	jz	L10f23
	call	far ptr drv_real_FUN_1000_0f42
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
L10f23:
	retf
drv_real_mouse_close	ENDP

drv_real_FUN_1000_0f24	PROC	FAR
	xor	ax,ax
	xchg	word ptr ds:[drv_DAT_20d8_5670],ax
	retf
drv_real_FUN_1000_0f24	ENDP

;------------------------------------------------------------------------------
; Set the cursor's hot spot and which shape to draw.
;------------------------------------------------------------------------------
drv_real_mouse_set_cursor	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	ds:[drv_DAT_20d8_5674],ax
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_20d8_5676],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_20d8_5672],ax
	pop	bp
	retf
drv_real_mouse_set_cursor	ENDP

drv_real_FUN_1000_0f42	PROC	FAR
	mov	byte ptr ds:[drv_DAT_20d8_4b5b],0
	call	far ptr drv_jump_gfx_overlay_remove
	retf
drv_real_FUN_1000_0f42	ENDP

;------------------------------------------------------------------------------
; Draw the cursor at the position the last event left, and record that it is
; on.
;------------------------------------------------------------------------------
drv_real_cursor_show	PROC	FAR
	push	word ptr ds:[drv_DAT_20d8_5672]
	mov	ax,ds:[drv_DAT_20d8_566c]
	sub	ax,word ptr ds:[drv_DAT_20d8_5676]
	push	ax
	mov	ax,ds:[drv_DAT_20d8_566a]
	sub	ax,word ptr ds:[drv_DAT_20d8_5674]
	push	ax
	call	far ptr drv_jump_gfx_overlay_put
	add	sp,6
	mov	byte ptr ds:[drv_DAT_20d8_4b5b],1
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
	mov	ds:[drv_DAT_20d8_567a],ax
	mov	word ptr ds:[drv_DAT_20d8_567c],bx
	mov	word ptr ds:[drv_DAT_20d8_567e],cx
	mov	word ptr ds:[drv_DAT_20d8_5680],dx
	lea	ax,[drv_DAT_20d8_567a]
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
	call	dword ptr es:[L101fb]
	push	word ptr ds:[drv_DAT_20d8_5672]
	mov	ax,ds:[drv_DAT_20d8_566c]
	sub	ax,word ptr ds:[drv_DAT_20d8_5676]
	push	ax
	mov	ax,ds:[drv_DAT_20d8_566a]
	sub	ax,word ptr ds:[drv_DAT_20d8_5674]
	push	ax
	mov	ax,CODE_0
	mov	es,ax
	call	dword ptr es:[L10264]
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
	cmp	word ptr ds:[drv_DAT_20d8_5678],0
	jz	L10fd5
	shr	cx,1
L10fd5:
	or	word ptr ds:[drv_DAT_20d8_5670],bx
	mov	word ptr ds:[drv_DAT_20d8_566e],bx
	mov	word ptr ds:[drv_DAT_20d8_566a],cx
	mov	word ptr ds:[drv_DAT_20d8_566c],dx
	test	ax,1
	jz	L11005
	cmp	byte ptr ds:[drv_DAT_20d8_4b5b],0
	jz	L11005
	mov	al,2
	xchg	byte ptr ds:[drv_DAT_20d8_4b5a],al
	or	al,al
	jnz	L11005
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_20d8_4b5a],0
L11005:
	retf
drv_real_mouse_event	ENDP

CODE_0	ENDS

;==============================================================================
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:_TEXT, ds:DGROUP, ss:DGROUP

asm_FUN_1100_0016	PROC	FAR
	mov	al,0
	iret
asm_FUN_1100_0016	ENDP

;------------------------------------------------------------------------------
; Install the module's INT 24h handler, saving the old vector, so a critical
; error comes back as a failed call.
;------------------------------------------------------------------------------
_shm_hook_critical_error	PROC	NEAR
	mov	al,1
	xchg	byte ptr ds:[asm_DAT_20d8_006c],al
	or	al,al
	jnz	L1103d
	mov	ah,35h
	mov	al,24h
	int	21h		; DOS AH=35h: get interrupt vector (AL = vector)
	mov	word ptr ds:[asm_DAT_20d8_006d],bx
	mov	word ptr ds:[asm_DAT_20d8_006d+2],es
	push	ds
	mov	ah,25h
	mov	al,24h
	lds	dx,ds:[asm_DAT_20d8_0071]
	int	21h		; DOS AH=25h: set interrupt vector (AL = vector, DS:DX = handler)
	pop	ds
L1103d:
	ret
_shm_hook_critical_error	ENDP

;------------------------------------------------------------------------------
; Put the INT 24h handler back, if this is the call that took it.
;------------------------------------------------------------------------------
_shm_unhook_critical_error	PROC	NEAR
	mov	al,0
	xchg	byte ptr ds:[asm_DAT_20d8_006c],al
	or	al,al
	jz	L11054
	push	ds
	mov	ah,25h
	mov	al,24h
	lds	dx,ds:[asm_DAT_20d8_006d]
	int	21h		; DOS AH=25h: set interrupt vector (AL = vector, DS:DX = handler)
	pop	ds
L11054:
	ret
_shm_unhook_critical_error	ENDP
D11055	DB	0

;;SPLIT main

;;SPLIT FUN_1100_041d

;;SPLIT FUN_1100_0434

;;SPLIT FUN_1100_04a7

;;SPLIT FUN_1100_0519

;;SPLIT FUN_1100_0538

;;SPLIT FUN_1100_0539

;;SPLIT FUN_1100_053a

;;SPLIT FUN_1100_067c

;;SPLIT FUN_1100_067e

;;SPLIT FUN_1100_0734

;;SPLIT FUN_1100_0906

;;SPLIT FUN_1100_0af4

;;SPLIT FUN_1100_0c40

;;SPLIT FUN_1100_0c70

;;SPLIT FUN_1100_0e1a

;;SPLIT FUN_1100_0ed2

;;SPLIT FUN_1100_10fb

;;SPLIT FUN_1100_11b7

;;SPLIT FUN_1100_1214

;;SPLIT FUN_1100_1322

;;SPLIT FUN_1100_1394

;;SPLIT FUN_1100_173c

;;SPLIT FUN_1100_175e

;;SPLIT FUN_1100_1da2

;;SPLIT FUN_1100_2703

;;SPLIT FUN_1100_27cc

;;SPLIT FUN_1100_28a8

;;SPLIT FUN_1100_28de

;;SPLIT FUN_1100_2941

;;SPLIT FUN_1100_2a30

;;SPLIT FUN_1100_2b92

;;SPLIT FUN_1100_2c2a

;;SPLIT FUN_1100_2c60

;;SPLIT FUN_1100_2c80

;;SPLIT FUN_1100_2c94

;;SPLIT FUN_1100_2d63

;;SPLIT FUN_1100_2e06

;;SPLIT FUN_1100_35d6

;;SPLIT FUN_1100_3a22

;;SPLIT FUN_1100_3a49

;;SPLIT FUN_1100_3bcc

;;SPLIT FUN_1100_3f4c

;;SPLIT FUN_1100_46b5

;;SPLIT FUN_1100_46df

;;SPLIT FUN_1100_499e

;;SPLIT FUN_1100_4b82

;;SPLIT FUN_1100_4c2c

;;SPLIT FUN_1100_4caa

;;SPLIT FUN_1100_4cd0

;;SPLIT FUN_1100_4d1d

;;SPLIT FUN_1100_4d67

;;SPLIT FUN_1100_5164

;;SPLIT FUN_1100_524c

;;SPLIT FUN_1100_5b3f

;;SPLIT FUN_1100_5c77

;;SPLIT FUN_1100_5caa

;;SPLIT FUN_1100_5f98

;;SPLIT FUN_1100_5ff1

;;SPLIT FUN_1100_60f5

;;SPLIT FUN_1100_6196

;;SPLIT FUN_1100_61f8

;;SPLIT FUN_1100_628f

;;SPLIT FUN_1100_62db

;;SPLIT FUN_1100_6639

;;SPLIT FUN_1100_66ec

;;SPLIT FUN_1100_67b9

;;SPLIT FUN_1100_6822

;;SPLIT FUN_1100_6859

;;SPLIT FUN_1100_690e

;;SPLIT FUN_1100_6993

;;SPLIT FUN_1100_69b3

;;SPLIT FUN_1100_6b82

;;SPLIT FUN_1100_71c7

;;SPLIT FUN_1100_74f0

;;SPLIT FUN_1100_750d

;;SPLIT FUN_1100_75f9

;;SPLIT FUN_1100_7668

;;SPLIT FUN_1100_795d

;;SPLIT FUN_1100_7992

;;SPLIT FUN_1100_7a37

;;SPLIT FUN_1100_7a8e

;;SPLIT FUN_1100_7afe

;;SPLIT FUN_1100_7c67

;;SPLIT FUN_1100_7e77

;;SPLIT FUN_1100_8060

;;SPLIT FUN_1100_80e4

;;SPLIT FUN_1100_81cf

;;SPLIT FUN_1100_82b3

;;SPLIT FUN_1100_8327

;;SPLIT FUN_1100_8383

;;SPLIT FUN_1100_83e8

;;SPLIT FUN_1100_8467

;;SPLIT FUN_1100_851a

;;SPLIT FUN_1100_8562

;;SPLIT FUN_1100_85ec

;;SPLIT FUN_1100_88ac

;;SPLIT FUN_1100_89f3

;;SPLIT FUN_1100_8aaf

;;SPLIT FUN_1100_8b3b

;;SPLIT FUN_1100_8b80

;;SPLIT FUN_1100_8bf1

;;SPLIT FUN_1100_8c2c

;;SPLIT FUN_1100_8d04

;;SPLIT FUN_1100_8f74

;;SPLIT FUN_1100_9443

;;SPLIT FUN_1100_97f4

;;SPLIT FUN_1100_984c

;;SPLIT FUN_1100_98a5

;;SPLIT FUN_1100_9966

;;SPLIT FUN_1100_99b8

;;SPLIT FUN_1100_9ae9

;;SPLIT FUN_1100_9b12

;;SPLIT FUN_1100_9b45

;;SPLIT FUN_1100_9bc2

;;SPLIT FUN_1100_9c3e

;;SPLIT FUN_1100_9c60

;;SPLIT FUN_1100_9d3b

;;SPLIT FUN_1100_9f20

;;SPLIT FUN_1100_a055

;;SPLIT FUN_1100_a111

;;SPLIT FUN_1100_a12e

;;SPLIT FUN_1100_a295

;;SPLIT FUN_1100_a2f6

;;SPLIT FUN_1100_a62b

;;SPLIT FUN_1100_a684

;;SPLIT FUN_1100_a6dd

;;SPLIT FUN_1100_aaa0

;;SPLIT FUN_1100_abd2

;;SPLIT FUN_1100_ac01

;;SPLIT FUN_1100_ac12

;;SPLIT FUN_1100_ac20

;;SPLIT FUN_1100_ac6c

;;SPLIT FUN_1100_ac84

;;SPLIT FUN_1100_ad37

;;SPLIT FUN_1100_ad42

;;SPLIT FUN_1100_add0

;;SPLIT FUN_1100_ae0b

;;SPLIT FUN_1100_ae33

;;SPLIT FUN_1100_ae96

;;SPLIT FUN_1100_aeeb

;;SPLIT FUN_1100_af04

;;SPLIT FUN_1100_af05

;;SPLIT FUN_1100_afd2

;;SPLIT FUN_1100_affc

;;SPLIT FUN_1100_b01a

;;SPLIT FUN_1100_b488

;;SPLIT FUN_1100_b4bf

;;SPLIT FUN_1100_b4ea

;;SPLIT FUN_1100_b596

;;SPLIT FUN_1100_b5b7

;;SPLIT FUN_1100_b62a

;;SPLIT FUN_1100_b65f

;;SPLIT FUN_1100_b6e4

;;SPLIT FUN_1100_b723

;;SPLIT FUN_1100_b7c6

;;SPLIT FUN_1100_b9af

;;SPLIT FUN_1100_b9ec

;;SPLIT FUN_1100_ba2c

;;SPLIT FUN_1100_ba53

;;SPLIT FUN_1100_ba76

;;SPLIT FUN_1100_bad6

;;SPLIT FUN_1100_bb3a

;;SPLIT FUN_1100_bb90

;;SPLIT FUN_1100_bc17

;;SPLIT FUN_1100_bc68

;;SPLIT FUN_1100_bcd3

;;SPLIT FUN_1100_bd49

;;SPLIT FUN_1100_bdc4

;;SPLIT FUN_1100_be4f

;;SPLIT FUN_1100_be8c

;;SPLIT FUN_1100_beb1

;;SPLIT FUN_1100_bed0

;;SPLIT FUN_1100_bee6

;;SPLIT FUN_1100_befc

;;SPLIT FUN_1100_bf12

;;SPLIT FUN_1100_bf3a

;;SPLIT FUN_1100_bf60

;;SPLIT FUN_1100_bf98

;;SPLIT FUN_1100_bfd0

;;SPLIT FUN_1100_c018

;;SPLIT FUN_1100_c038

;;SPLIT FUN_1100_c059

;;SPLIT FUN_1100_c082

;;SPLIT FUN_1100_c0ba

;;SPLIT FUN_1100_c0d8

;;SPLIT FUN_1100_c0f4

;;SPLIT FUN_1100_c11e

;;SPLIT FUN_1100_c138

;;SPLIT FUN_1100_c152

;;SPLIT FUN_1100_c169

;;SPLIT FUN_1100_c182

;;SPLIT FUN_1100_c1a0

;;SPLIT FUN_1100_c200

;;SPLIT FUN_1100_c22a

;;SPLIT FUN_1100_c24e

;;SPLIT FUN_1100_c292

;;SPLIT FUN_1100_c2d8

;;SPLIT FUN_1100_c31a

;;SPLIT FUN_1100_c37e

;;SPLIT FUN_1100_c3be

;;SPLIT FUN_1100_c42a

;;SPLIT FUN_1100_c43c

;;SPLIT FUN_1100_c498

;;SPLIT FUN_1100_c4fc

;;SPLIT FUN_1100_c51a

;;SPLIT FUN_1100_c54e

;;SPLIT FUN_1100_c55e

;;SPLIT FUN_1100_c586

;;SPLIT FUN_1100_c5a8

;;SPLIT FUN_1100_c5d8

;;SPLIT FUN_1100_c608

;;SPLIT FUN_1100_c62e

;;SPLIT FUN_1100_c6ee

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
asm_DAT_1fb4_080c	DB	0,0
asm_block_080e	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
asm_DAT_1fb4_0840	DB	0,0
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
drv_DAT_20d8_0042	DB	0,0
drv_DAT_20d8_0044	DB	0,0
asm_block_0046	DB	0,0,3Fh,3Fh,3Fh,3Fh,3Fh,3Fh
	DB	3Fh,3Fh,3Fh,3Fh,3Fh,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
asm_DAT_20d8_006c	DB	0
asm_DAT_20d8_006d	DB	0,0,0,0
asm_DAT_20d8_0071	DB	16h,0
	DW	_TEXT
asm_block_0075	DB	0
_dat_str_env_sve	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_move_joystick_upper	DB	4Dh,6Fh,76h,65h,20h,4Ah,4Fh,59h
	DB	53h,54h,49h,43h,4Bh,20h,74h,6Fh
	DB	0Ah,75h,70h,70h,65h,72h,2Dh,6Ch
	DB	65h,66h,74h,20h,63h,6Fh,72h,6Eh
	DB	65h,72h,0Ah,61h,6Eh,64h,20h,70h
	DB	72h,65h,73h,73h,20h,62h,75h,74h
	DB	74h,6Fh,6Eh,2Eh,0Ah,0
_dat_str_move_joystick_lower	DB	4Dh,6Fh,76h,65h,20h,4Ah,4Fh,59h
	DB	53h,54h,49h,43h,4Bh,20h,74h,6Fh
	DB	0Ah,6Ch,6Fh,77h,65h,72h,2Dh,72h
	DB	69h,67h,68h,74h,20h,63h,6Fh,72h
	DB	6Eh,65h,72h,0Ah,61h,6Eh,64h,20h
	DB	70h,72h,65h,73h,73h,20h,62h,75h
	DB	74h,74h,6Fh,6Eh,2Eh,0Ah,0
_dat_str_labs_pic	DB	6Ch,61h,62h,73h,2Eh,70h,69h,63h
	DB	0
_dat_str_env_sve_2	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_title2_pan	DB	74h,69h,74h,6Ch,65h,32h,2Eh,70h
	DB	61h,6Eh,0
_dat_str_credits_pan	DB	63h,72h,65h,64h,69h,74h,73h,2Eh
	DB	70h,61h,6Eh,0
_dat_str_do_want_create_new	DB	44h,6Fh,20h,79h,6Fh,75h,20h,77h
	DB	61h,6Eh,74h,20h,74h,6Fh,2Eh,2Eh
	DB	2Eh,0Ah,20h,43h,72h,65h,61h,74h
	DB	65h,20h,61h,20h,4Eh,65h,77h,20h
	DB	43h,68h,61h,72h,61h,63h,74h,65h
	DB	72h,0Ah,20h,4Ch,6Fh,61h,64h,20h
	DB	61h,20h,53h,61h,76h,65h,64h,20h
	DB	47h,61h,6Dh,65h,0Ah,20h,50h,72h
	DB	61h,63h,74h,69h,63h,65h,20h,61h
	DB	20h,73h,6Bh,69h,6Ch,6Ch,0Ah,20h
	DB	52h,65h,76h,69h,65h,77h,20h,48h
	DB	61h,6Ch,6Ch,20h,6Fh,66h,20h,46h
	DB	61h,6Dh,65h,0Ah,0
_dat_str_env_sve_3	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_env_sve_4	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
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
asm_block_154a	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
RASTPORT_PTR_155C	DW	OFFSET DGROUP:asm_block_154a
dat_map_page_port	DB	1,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_shd_map_page	DW	OFFSET DGROUP:dat_map_page_port
_dat_colours_title	DB	0,0,1,0,2,0,0,2		; COLOUR_MAP
	DB	0,1,3,1,2,1,0,3
_dat_colours_title_2	DB	0,1,11h,11h,2,0,2,3		; COLOUR_MAP
	DB	30h,11h,13h,31h,22h,23h,33h,33h
_shd_colours_screen	DB	0,0,1,0,2,0,0,2		; COLOUR_MAP
	DB	0,1,2,3,2,1,1,3
_shd_colours_screen_2	DB	0,0,11h,11h,22h,0,0,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,22h,11h,22h,33h
D22332	DB	0,0,11h,11h,22h,22h,22h,22h
	DB	0,22h,33h,33h,0,0,11h,33h
	DB	0,22h,0,0,0,0,0,0
	DB	0,22h,22h,0,0,0,11h,33h
_dat_colours_report	DB	0,12h,11h,10h,11h,0,12h,33h		; COLOUR_MAP
	DB	22h,13h,33h,11h,33h,22h,33h,33h
_dat_colours_main	DB	0,12h,0,0,22h,0,0,13h		; COLOUR_MAP
	DB	2,11h,0,0,0,0,33h,33h
D22372	DB	0,11h,11h,11h,22h,0,22h,12h
	DB	0,11h,11h,33h,33h,22h,33h,33h
	DB	0,11h,11h,11h,22h,0,22h,12h
	DB	0,11h,11h,33h,33h,22h,33h,33h
_shd_colours_face	DB	0,11h,11h,1,22h,0,22h,22h		; COLOUR_MAP
	DB	0,11h,11h,33h,33h,33h,33h,33h
_dat_colours_badge	DB	0,0,11h,11h,22h,0,0,11h		; COLOUR_MAP
	DB	22h,22h,33h,33h,22h,11h,22h,33h
_dat_colours_grid	DB	0,0,11h,11h,22h,0,0,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,22h,11h,22h,33h
D223c2	DB	0,0,11h,11h,22h,0,0,33h
	DB	22h,22h,11h,33h,22h,33h,22h,33h
_dat_palette_title	DB	0,1,2,3,4,0,6,7		; PALETTE
	DB	8,9,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh
	DB	0
PALETTE_PAD_1663	DB	0
_shd_pan_disk	DB	1,0
_dat_str_animation_pan	DB	61h,6Eh,69h,6Dh,61h,74h,69h,6Fh
	DB	6Eh,2Eh,70h,61h,6Eh,0
_dat_str_env_sve_5	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_empty_15	DB	0
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
_dat_str_fluf00	DB	2Ah,46h,4Ch,55h,46h,30h,30h,0
_dat_str_text_dta_5	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
dat_str_set00_mission0_where	DB	74h,68h,65h,20h,55h,53h,20h,45h
	DB	6Dh,62h,61h,73h,73h,79h,0
dat_str_set00_mission0_what	DB	61h,20h,74h,6Fh,70h,20h,73h,65h
	DB	63h,72h,65h,74h,20h,63h,6Fh,64h
	DB	65h,20h,62h,6Fh,6Fh,6Bh,0
dat_str_set00_mission1_where	DB	0
dat_str_set00_mission1_what	DB	0
dat_str_set00_mission2_where	DB	0
dat_str_set00_mission2_what	DB	0
dat_str_set00_mission3_where	DB	0
dat_str_set00_mission3_what	DB	0
dat_str_set00_mission4_where	DB	0
dat_str_set00_mission4_what	DB	0
dat_str_set00_mission5_where	DB	0
dat_str_set00_mission5_what	DB	0
dat_str_set00_mission6_where	DB	0
dat_str_set00_mission6_what	DB	0
dat_str_set00_mission7_where	DB	0
dat_str_set00_mission7_what	DB	0
dat_str_set01_mission0_where	DB	73h,61h,74h,74h,65h,6Ch,69h,74h
	DB	65h,20h,65h,78h,70h,65h,72h,74h
	DB	20h,58h,61h,76h,69h,65h,72h,20h
	DB	52h,61h,79h,62h,61h,6Eh,0
dat_str_set01_mission0_what	DB	0
dat_str_set01_mission1_where	DB	74h,68h,65h,20h,75h,70h,6Ch,69h
	DB	6Eh,6Bh,20h,67h,72h,6Fh,75h,6Eh
	DB	64h,20h,73h,74h,61h,74h,69h,6Fh
	DB	6Eh,0
dat_str_set01_mission1_what	DB	0
dat_str_set01_mission2_where	DB	43h,49h,41h,20h,73h,74h,6Fh,72h
	DB	61h,67h,65h,0
dat_str_set01_mission2_what	DB	58h,2Dh,42h,61h,6Eh,64h,20h,72h
	DB	61h,64h,69h,6Fh,20h,74h,72h,61h
	DB	6Eh,73h,6Dh,69h,74h,74h,65h,72h
	DB	0
dat_str_set01_mission3_where	DB	0
dat_str_set01_mission3_what	DB	0
dat_str_set01_mission4_where	DB	0
dat_str_set01_mission4_what	DB	0
dat_str_set01_mission5_where	DB	0
dat_str_set01_mission5_what	DB	0
dat_str_set01_mission6_where	DB	0
dat_str_set01_mission6_what	DB	0
dat_str_set01_mission7_where	DB	0
dat_str_set01_mission7_what	DB	0
dat_str_set02_mission0_where	DB	74h,68h,65h,20h,46h,72h,65h,65h
	DB	64h,6Fh,6Dh,20h,47h,61h,6Dh,65h
	DB	73h,20h,73h,65h,63h,75h,72h,69h
	DB	74h,79h,20h,70h,6Ch,61h,6Eh,0
dat_str_set02_mission0_what	DB	0
dat_str_set02_mission1_where	DB	61h,6Eh,20h,49h,73h,72h,61h,65h
	DB	6Ch,69h,20h,73h,65h,63h,75h,72h
	DB	69h,74h,79h,20h,65h,78h,70h,65h
	DB	72h,74h,0
dat_str_set02_mission1_what	DB	0
dat_str_set02_mission2_where	DB	74h,68h,65h,20h,49h,73h,72h,61h
	DB	65h,6Ch,69h,20h,61h,74h,68h,6Ch
	DB	65h,74h,69h,63h,20h,64h,6Fh,72h
	DB	6Dh,69h,74h,6Fh,72h,79h,0
dat_str_set02_mission2_what	DB	0
dat_str_set02_mission3_where	DB	0
dat_str_set02_mission3_what	DB	0
dat_str_set02_mission4_where	DB	0
dat_str_set02_mission4_what	DB	0
dat_str_set02_mission5_where	DB	0
dat_str_set02_mission5_what	DB	0
dat_str_set02_mission6_where	DB	0
dat_str_set02_mission6_what	DB	0
dat_str_set02_mission7_where	DB	0
dat_str_set02_mission7_what	DB	0
dat_str_set03_mission0_where	DB	74h,68h,65h,20h,6Eh,6Fh,74h,65h
	DB	64h,20h,63h,68h,65h,6Dh,69h,73h
	DB	74h,20h,44h,72h,20h,50h,61h,73h
	DB	74h,75h,72h,65h,0
dat_str_set03_mission0_what	DB	0
dat_str_set03_mission1_where	DB	61h,20h,6Ch,61h,72h,67h,65h,20h
	DB	69h,6Eh,64h,75h,73h,74h,72h,69h
	DB	61h,6Ch,20h,77h,61h,72h,65h,68h
	DB	6Fh,75h,73h,65h,0
dat_str_set03_mission1_what	DB	63h,68h,65h,6Dh,69h,63h,61h,6Ch
	DB	73h,0
dat_str_set03_mission2_where	DB	6Eh,65h,77h,20h,73h,75h,70h,65h
	DB	72h,20h,64h,72h,75h,67h,0
dat_str_set03_mission2_what	DB	0
dat_str_set03_mission3_where	DB	0
dat_str_set03_mission3_what	DB	0
dat_str_set03_mission4_where	DB	0
dat_str_set03_mission4_what	DB	0
dat_str_set03_mission5_where	DB	0
dat_str_set03_mission5_what	DB	0
dat_str_set03_mission6_where	DB	0
dat_str_set03_mission6_what	DB	0
dat_str_set03_mission7_where	DB	0
dat_str_set03_mission7_what	DB	0
dat_str_set04_mission0_where	DB	47h,65h,72h,61h,6Ch,64h,6Fh,20h
	DB	43h,6Fh,72h,61h,7Ah,6Fh,6Eh,0
dat_str_set04_mission0_what	DB	0
dat_str_set04_mission1_where	DB	74h,68h,65h,20h,45h,6Ch,65h,63h
	DB	74h,69h,6Fh,6Eh,20h,43h,6Fh,6Dh
	DB	6Dh,69h,73h,73h,69h,6Fh,6Eh,20h
	DB	48h,51h,0
dat_str_set04_mission1_what	DB	0
dat_str_set04_mission2_where	DB	74h,68h,65h,20h,53h,6Fh,63h,69h
	DB	61h,6Ch,20h,44h,65h,6Dh,6Fh,63h
	DB	72h,61h,74h,20h,63h,61h,6Dh,70h
	DB	61h,69h,67h,6Eh,20h,72h,61h,6Ch
	DB	6Ch,79h,0
dat_str_set04_mission2_what	DB	0
dat_str_set04_mission3_where	DB	0
dat_str_set04_mission3_what	DB	0
dat_str_set04_mission4_where	DB	0
dat_str_set04_mission4_what	DB	0
dat_str_set04_mission5_where	DB	0
dat_str_set04_mission5_what	DB	0
dat_str_set04_mission6_where	DB	0
dat_str_set04_mission6_what	DB	0
dat_str_set04_mission7_where	DB	0
dat_str_set04_mission7_what	DB	0
dat_str_set05_mission0_where	DB	43h,61h,72h,6Ch,6Fh,73h,20h,74h
	DB	68h,65h,20h,48h,79h,65h,6Eh,61h
	DB	0
dat_str_set05_mission0_what	DB	0
dat_str_set05_mission1_where	DB	73h,75h,6Dh,6Dh,69h,74h,20h,49h
	DB	44h,20h,44h,6Fh,63h,75h,6Dh,65h
	DB	6Eh,74h,73h,0
dat_str_set05_mission1_what	DB	0
dat_str_set05_mission2_where	DB	61h,20h,6Ch,65h,61h,64h,69h,6Eh
	DB	67h,20h,48h,65h,61h,64h,20h,6Fh
	DB	66h,20h,53h,74h,61h,74h,65h,0
dat_str_set05_mission2_what	DB	0
dat_str_set05_mission3_where	DB	0
dat_str_set05_mission3_what	DB	0
dat_str_set05_mission4_where	DB	0
dat_str_set05_mission4_what	DB	0
dat_str_set05_mission5_where	DB	0
dat_str_set05_mission5_what	DB	0
dat_str_set05_mission6_where	DB	0
dat_str_set05_mission6_what	DB	0
dat_str_set05_mission7_where	DB	0
dat_str_set05_mission7_what	DB	0
dat_str_set06_mission0_where	DB	57h,69h,6Ch,6Ch,69h,65h,20h,74h
	DB	68h,65h,20h,50h,65h,6Eh,0
dat_str_set06_mission0_what	DB	0
dat_str_set06_mission1_where	DB	74h,68h,65h,20h,54h,72h,65h,61h
	DB	73h,75h,72h,79h,20h,42h,75h,69h
	DB	6Ch,64h,69h,6Eh,67h,0
dat_str_set06_mission1_what	DB	43h,75h,72h,72h,65h,6Eh,63h,79h
	DB	20h,50h,6Ch,61h,74h,65h,73h,0
dat_str_set06_mission2_where	DB	6Dh,65h,64h,69h,75h,6Dh,20h,64h
	DB	65h,6Eh,6Fh,6Dh,69h,6Eh,61h,74h
	DB	69h,6Fh,6Eh,20h,63h,75h,72h,72h
	DB	65h,6Eh,63h,79h,0
dat_str_set06_mission2_what	DB	63h,75h,72h,72h,65h,6Eh,63h,79h
	DB	20h,70h,61h,70h,65h,72h,0
dat_str_set06_mission3_where	DB	0
dat_str_set06_mission3_what	DB	0
dat_str_set06_mission4_where	DB	0
dat_str_set06_mission4_what	DB	0
dat_str_set06_mission5_where	DB	0
dat_str_set06_mission5_what	DB	0
dat_str_set06_mission6_where	DB	0
dat_str_set06_mission6_what	DB	0
dat_str_set06_mission7_where	DB	0
dat_str_set06_mission7_what	DB	0
dat_str_set07_mission0_where	DB	41h,69h,72h,42h,61h,73h,65h,20h
	DB	50h,61h,73h,73h,77h,6Fh,72h,64h
	DB	73h,0
dat_str_set07_mission0_what	DB	0
dat_str_set07_mission1_where	DB	41h,69h,72h,42h,61h,73h,65h,20h
	DB	49h,44h,20h,43h,61h,72h,64h,73h
	DB	0
dat_str_set07_mission1_what	DB	0
dat_str_set07_mission2_where	DB	61h,6Eh,20h,41h,69h,72h,42h,61h
	DB	73h,65h,0
dat_str_set07_mission2_what	DB	61h,20h,4Eh,75h,63h,6Ch,65h,61h
	DB	72h,20h,42h,6Fh,6Dh,62h,0
dat_str_set07_mission3_where	DB	0
dat_str_set07_mission3_what	DB	0
dat_str_set07_mission4_where	DB	0
dat_str_set07_mission4_what	DB	0
dat_str_set07_mission5_where	DB	0
dat_str_set07_mission5_what	DB	0
dat_str_set07_mission6_where	DB	0
dat_str_set07_mission6_what	DB	0
dat_str_set07_mission7_where	DB	0
dat_str_set07_mission7_what	DB	0
dat_str_set08_mission0_where	DB	61h,20h,63h,68h,65h,6Dh,69h,63h
	DB	61h,6Ch,20h,70h,6Ch,61h,6Eh,74h
	DB	0
dat_str_set08_mission0_what	DB	65h,78h,70h,6Ch,6Fh,73h,69h,76h
	DB	65h,20h,70h,72h,6Fh,70h,65h,6Ch
	DB	6Ch,61h,6Eh,74h,73h,0
dat_str_set08_mission1_where	DB	61h,20h,6Dh,65h,74h,61h,6Ch,20h
	DB	66h,6Fh,75h,6Eh,64h,72h,79h,0
dat_str_set08_mission1_what	DB	68h,69h,67h,68h,2Dh,73h,74h,72h
	DB	65h,6Eh,67h,74h,68h,20h,74h,75h
	DB	62h,65h,73h,0
dat_str_set08_mission2_where	DB	74h,68h,65h,20h,73h,75h,70h,65h
	DB	72h,20h,63h,61h,6Eh,6Eh,6Fh,6Eh
	DB	0
dat_str_set08_mission2_what	DB	70h,72h,65h,63h,69h,73h,69h,6Fh
	DB	6Eh,20h,6Ch,61h,74h,68h,65h,0
dat_str_set08_mission3_where	DB	0
dat_str_set08_mission3_what	DB	0
dat_str_set08_mission4_where	DB	0
dat_str_set08_mission4_what	DB	0
dat_str_set08_mission5_where	DB	0
dat_str_set08_mission5_what	DB	0
dat_str_set08_mission6_where	DB	0
dat_str_set08_mission6_what	DB	0
dat_str_set08_mission7_where	DB	0
dat_str_set08_mission7_what	DB	0
dat_str_set09_mission0_where	DB	61h,20h,62h,72h,65h,65h,64h,65h
	DB	72h,20h,72h,65h,61h,63h,74h,6Fh
	DB	72h,0
dat_str_set09_mission0_what	DB	70h,6Ch,75h,74h,6Fh,6Eh,69h,75h
	DB	6Dh,20h,32h,33h,35h,0
dat_str_set09_mission1_where	DB	70h,68h,79h,73h,69h,63h,69h,73h
	DB	74h,20h,44h,72h,20h,41h,2Eh,20h
	DB	45h,69h,6Eh,73h,74h,6Fh,6Eh,65h
	DB	0
dat_str_set09_mission1_what	DB	0
dat_str_set09_mission2_where	DB	61h,20h,6Eh,75h,63h,6Ch,65h,61h
	DB	72h,20h,62h,6Fh,6Dh,62h,0
dat_str_set09_mission2_what	DB	69h,6Dh,70h,6Ch,6Fh,64h,69h,6Eh
	DB	67h,20h,64h,65h,74h,6Fh,6Eh,61h
	DB	74h,6Fh,72h,0
dat_str_set09_mission3_where	DB	0
dat_str_set09_mission3_what	DB	0
dat_str_set09_mission4_where	DB	0
dat_str_set09_mission4_what	DB	0
dat_str_set09_mission5_where	DB	0
dat_str_set09_mission5_what	DB	0
dat_str_set09_mission6_where	DB	0
dat_str_set09_mission6_what	DB	0
dat_str_set09_mission7_where	DB	0
dat_str_set09_mission7_what	DB	0
dat_str_set10_mission0_where	DB	74h,72h,61h,69h,6Eh,20h,73h,74h
	DB	61h,74h,69h,6Fh,6Eh,0
dat_str_set10_mission0_what	DB	0
dat_str_set10_mission1_where	DB	74h,68h,65h,20h,56h,65h,74h,65h
	DB	72h,61h,6Eh,27h,73h,20h,44h,61h
	DB	79h,20h,70h,61h,72h,61h,64h,65h
	DB	0
dat_str_set10_mission1_what	DB	0
dat_str_set10_mission2_where	DB	61h,20h,53h,75h,70h,72h,65h,6Dh
	DB	65h,20h,43h,6Fh,75h,72h,74h,20h
	DB	4Ah,75h,73h,74h,69h,63h,65h,0
dat_str_set10_mission2_what	DB	0
dat_str_set10_mission3_where	DB	0
dat_str_set10_mission3_what	DB	0
dat_str_set10_mission4_where	DB	0
dat_str_set10_mission4_what	DB	0
dat_str_set10_mission5_where	DB	0
dat_str_set10_mission5_what	DB	0
dat_str_set10_mission6_where	DB	0
dat_str_set10_mission6_what	DB	0
dat_str_set10_mission7_where	DB	0
dat_str_set10_mission7_what	DB	0
dat_str_set11_mission0_where	DB	62h,61h,63h,74h,65h,72h,69h,6Fh
	DB	6Ch,6Fh,67h,69h,73h,74h,20h,45h
	DB	64h,67h,61h,72h,20h,43h,6Fh,6Ch
	DB	69h,0
dat_str_set11_mission0_what	DB	0
dat_str_set11_mission1_where	DB	74h,68h,65h,20h,6Dh,65h,64h,69h
	DB	63h,61h,6Ch,20h,63h,6Fh,6Ch,6Ch
	DB	65h,67h,65h,0
dat_str_set11_mission1_what	DB	76h,69h,72h,75h,6Ch,65h,6Eh,74h
	DB	20h,76h,69h,72h,75h,73h,20h,73h
	DB	61h,6Dh,70h,6Ch,65h,73h,0
dat_str_set11_mission2_where	DB	64h,65h,61h,64h,6Ch,79h,20h,76h
	DB	69h,72h,75h,73h,20h,58h,0
dat_str_set11_mission2_what	DB	6Fh,6Eh,65h,20h,6Dh,69h,6Ch,6Ch
	DB	69h,6Fh,6Eh,20h,50h,65h,74h,72h
	DB	69h,20h,64h,69h,73h,68h,65h,73h
	DB	0
dat_str_set11_mission3_where	DB	0
dat_str_set11_mission3_what	DB	0
dat_str_set11_mission4_where	DB	0
dat_str_set11_mission4_what	DB	0
dat_str_set11_mission5_where	DB	0
dat_str_set11_mission5_what	DB	0
dat_str_set11_mission6_where	DB	0
dat_str_set11_mission6_what	DB	0
dat_str_set11_mission7_where	DB	0
dat_str_set11_mission7_what	DB	0
dat_str_set12_mission0_where	DB	49h,6Eh,74h,65h,72h,50h,6Fh,6Ch
	DB	20h,48h,65h,61h,64h,71h,75h,61h
	DB	72h,74h,65h,72h,73h,0
dat_str_set12_mission0_what	DB	0
dat_str_set12_mission1_where	DB	63h,68h,69h,65h,66h,20h,64h,72h
	DB	75h,67h,20h,69h,6Eh,76h,65h,73h
	DB	74h,69h,67h,61h,74h,6Fh,72h,0
dat_str_set12_mission1_what	DB	0
dat_str_set12_mission2_where	DB	0
dat_str_set12_mission2_what	DB	0
dat_str_set12_mission3_where	DB	0
dat_str_set12_mission3_what	DB	0
dat_str_set12_mission4_where	DB	0
dat_str_set12_mission4_what	DB	0
dat_str_set12_mission5_where	DB	0
dat_str_set12_mission5_what	DB	0
dat_str_set12_mission6_where	DB	0
dat_str_set12_mission6_what	DB	0
dat_str_set12_mission7_where	DB	0
dat_str_set12_mission7_what	DB	0
dat_str_set13_mission0_where	DB	56h,49h,50h,20h,74h,72h,61h,76h
	DB	65h,6Ch,20h,69h,74h,69h,6Eh,65h
	DB	72h,61h,72h,79h,0
dat_str_set13_mission0_what	DB	0
dat_str_set13_mission1_where	DB	74h,68h,65h,20h,6Ch,6Fh,63h,6Fh
	DB	6Dh,6Fh,74h,69h,76h,65h,20h,70h
	DB	6Ch,61h,6Eh,74h,0
dat_str_set13_mission1_what	DB	74h,72h,61h,69h,6Eh,20h,73h,63h
	DB	68h,65h,6Dh,61h,74h,69h,63h,73h
	DB	0
dat_str_set13_mission2_where	DB	74h,68h,65h,20h,74h,72h,61h,69h
	DB	6Eh,20h,73h,74h,61h,74h,69h,6Fh
	DB	6Eh,0
dat_str_set13_mission2_what	DB	0
dat_str_set13_mission3_where	DB	0
dat_str_set13_mission3_what	DB	0
dat_str_set13_mission4_where	DB	0
dat_str_set13_mission4_what	DB	0
dat_str_set13_mission5_where	DB	0
dat_str_set13_mission5_what	DB	0
dat_str_set13_mission6_where	DB	0
dat_str_set13_mission6_what	DB	0
dat_str_set13_mission7_where	DB	0
dat_str_set13_mission7_what	DB	0
dat_str_set14_mission0_where	DB	70h,72h,69h,73h,6Fh,6Eh,20h,76h
	DB	69h,73h,69h,74h,6Fh,72h,20h,70h
	DB	61h,73h,73h,0
dat_str_set14_mission0_what	DB	0
dat_str_set14_mission1_where	DB	74h,68h,65h,20h,70h,72h,69h,73h
	DB	6Fh,6Eh,20h,77h,61h,72h,64h,65h
	DB	6Eh,0
dat_str_set14_mission1_what	DB	0
dat_str_set14_mission2_where	DB	4Dh,61h,6Eh,6Eh,79h,20h,4Eh,6Fh
	DB	72h,69h,65h,67h,61h,0
dat_str_set14_mission2_what	DB	0
dat_str_set14_mission3_where	DB	0
dat_str_set14_mission3_what	DB	0
dat_str_set14_mission4_where	DB	0
dat_str_set14_mission4_what	DB	0
dat_str_set14_mission5_where	DB	0
dat_str_set14_mission5_what	DB	0
dat_str_set14_mission6_where	DB	0
dat_str_set14_mission6_what	DB	0
dat_str_set14_mission7_where	DB	0
dat_str_set14_mission7_what	DB	0
dat_str_set15_mission0_where	DB	66h,69h,67h,68h,74h,65h,72h,20h
	DB	70h,69h,6Ch,6Fh,74h,0
dat_str_set15_mission0_what	DB	0
dat_str_set15_mission1_where	DB	61h,69h,72h,62h,61h,73h,65h,20h
	DB	6Fh,70h,65h,72h,61h,74h,69h,6Fh
	DB	6Eh,20h,70h,6Ch,61h,6Eh,73h,0
dat_str_set15_mission1_what	DB	0
dat_str_set15_mission2_where	DB	74h,68h,65h,20h,73h,65h,63h,72h
	DB	65h,74h,20h,68h,61h,6Eh,67h,61h
	DB	72h,0
dat_str_set15_mission2_what	DB	73h,74h,65h,61h,6Ch,74h,68h,20h
	DB	66h,69h,67h,68h,74h,65h,72h,0
dat_str_set15_mission3_where	DB	0
dat_str_set15_mission3_what	DB	0
dat_str_set15_mission4_where	DB	0
dat_str_set15_mission4_what	DB	0
dat_str_set15_mission5_where	DB	0
dat_str_set15_mission5_what	DB	0
dat_str_set15_mission6_where	DB	0
dat_str_set15_mission6_what	DB	0
dat_str_set15_mission7_where	DB	0
dat_str_set15_mission7_what	DB	0
_dat_str_gender_pic	DB	67h,65h,6Eh,64h,65h,72h,2Eh,70h
	DB	69h,63h,0
_dat_str_select_one_maximillian	DB	53h,65h,6Ch,65h,63h,74h,20h,6Fh
	DB	6Eh,65h,2Eh,2Eh,2Eh,0Ah,20h,4Dh
	DB	61h,78h,69h,6Dh,69h,6Ch,6Ch,69h
	DB	61h,6Eh,20h,52h,65h,6Dh,69h,6Eh
	DB	67h,74h,6Fh,6Eh,0Ah,20h,4Dh,61h
	DB	78h,69h,6Eh,65h,20h,52h,65h,6Dh
	DB	69h,6Eh,67h,74h,6Fh,6Eh,0Ah,0
_dat_str_which_difficulty_level	DB	57h,68h,69h,63h,68h,20h,64h,69h
	DB	66h,66h,69h,63h,75h,6Ch,74h,79h
	DB	20h,6Ch,65h,76h,65h,6Ch,3Fh,0Ah
	DB	20h,4Ch,6Fh,63h,61h,6Ch,20h,44h
	DB	69h,73h,74h,75h,72h,62h,61h,6Eh
	DB	63h,65h,0Ah,20h,4Eh,61h,74h,69h
	DB	6Fh,6Eh,61h,6Ch,20h,54h,68h,72h
	DB	65h,61h,74h,0Ah,20h,52h,65h,67h
	DB	69h,6Fh,6Eh,61h,6Ch,20h,43h,6Fh
	DB	6Eh,66h,6Ch,69h,63h,74h,0Ah,20h
	DB	47h,6Ch,6Fh,62h,61h,6Ch,20h,43h
	DB	72h,69h,73h,69h,73h,0Ah,0
asm_block_1cfd	DB	0
_dat_org_table	DB	0,0,1,0,2,0,2,0
	DB	2,0,2,0,3,0,1,0
	DB	0,0,0,0,3,0,3,0
	DB	3,0,3,0,1,0,2,0
	DB	0,0,1,0,5,0,3,0
	DB	4,0,6,0,0,0,3,0
	DB	0,0,0,0,8,0,4,0
	DB	6,0,1,0,3,0,1,0
	DB	0,0,1,0,5,0,5,0
	DB	5,0,5,0,0,0,0,0
	DB	0,0,1,0,6,0,6,0
	DB	6,0,6,0,3,0,2,0
	DB	0,0,1,0,4,0,8,0
	DB	5,0,2,0,3,0,1,0
	DB	0,0,1,0,7,0,7,0
	DB	8,0,7,0,1,0,3,0
	DB	0,0,1,0,1,0,2,0
	DB	3,0,7,0,2,0,1,0
	DB	0,0,1,0,3,0,1,0
	DB	8,0,5,0,3,0,3,0
	DB	0,0,1,0,2,0,2,0
	DB	2,0,3,0,3,0,0,0
	DB	0,0,0,0,3,0,3,0
	DB	3,0,1,0,2,0,1,0
	DB	0,0,1,0,4,0,8,0
	DB	5,0,3,0,3,0,2,0
	DB	0,0,0,0,8,0,4,0
	DB	6,0,5,0,3,0,3,0
	DB	0,0,1,0,7,0,7,0
	DB	8,0,8,0,0,0,0,0
	DB	0,0,1,0,6,0,6,0
	DB	6,0,8,0,3,0,3,0
	DB	1,0,0,0,2,0,2,0
	DB	2,0,2,0,3,0,2,0
	DB	1,0,0,0,4,0,4,0
	DB	4,0,4,0,1,0,3,0
	DB	1,0,0,0,7,0,1,0
	DB	8,0,5,0,0,0,3,0
	DB	1,0,0,0,8,0,5,0
	DB	3,0,7,0,3,0,3,0
	DB	1,0,1,0,1,0,8,0
	DB	4,0,2,0,1,0,2,0
	DB	1,0,1,0,4,0,7,0
	DB	2,0,1,0,0,0,2,0
	DB	1,0,1,0,5,0,2,0
	DB	6,0,3,0,0,0,0,0
	DB	1,0,1,0,5,0,5,0
	DB	5,0,5,0,3,0,0,0
	DB	1,0,0,0,5,0,3,0
	DB	1,0,6,0,3,0,1,0
	DB	1,0,0,0,2,0,6,0
	DB	7,0,8,0,0,0,0,0
_dat_mission_sets	DB	57h,65h,6Ch,63h,6Fh,6Dh,65h,20h		; MISSION_SET[16]
	DB	4Dh,61h,78h,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0Fh,1,0,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh
	DW	OFFSET DGROUP:dat_str_set00_mission0_where
	DW	OFFSET DGROUP:dat_str_set00_mission0_what
	DW	OFFSET DGROUP:dat_str_set00_mission1_where
	DW	OFFSET DGROUP:dat_str_set00_mission1_what
	DW	OFFSET DGROUP:dat_str_set00_mission2_where
	DW	OFFSET DGROUP:dat_str_set00_mission2_what
	DW	OFFSET DGROUP:dat_str_set00_mission3_where
	DW	OFFSET DGROUP:dat_str_set00_mission3_what
	DW	OFFSET DGROUP:dat_str_set00_mission4_where
	DW	OFFSET DGROUP:dat_str_set00_mission4_what
	DW	OFFSET DGROUP:dat_str_set00_mission5_where
	DW	OFFSET DGROUP:dat_str_set00_mission5_what
	DW	OFFSET DGROUP:dat_str_set00_mission6_where
	DW	OFFSET DGROUP:dat_str_set00_mission6_what
	DW	OFFSET DGROUP:dat_str_set00_mission7_where
	DW	OFFSET DGROUP:dat_str_set00_mission7_what
	DB	27h,4Bh,65h,79h,48h,6Fh,6Ch,65h
	DB	27h,20h,53h,61h,74h,74h,65h,6Ch
	DB	69h,74h,65h,0,0,0,0,0
	DB	0,9,0,0,6,0,4,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set01_mission0_where
	DW	OFFSET DGROUP:dat_str_set01_mission0_what
	DW	OFFSET DGROUP:dat_str_set01_mission1_where
	DW	OFFSET DGROUP:dat_str_set01_mission1_what
	DW	OFFSET DGROUP:dat_str_set01_mission2_where
	DW	OFFSET DGROUP:dat_str_set01_mission2_what
	DW	OFFSET DGROUP:dat_str_set01_mission3_where
	DW	OFFSET DGROUP:dat_str_set01_mission3_what
	DW	OFFSET DGROUP:dat_str_set01_mission4_where
	DW	OFFSET DGROUP:dat_str_set01_mission4_what
	DW	OFFSET DGROUP:dat_str_set01_mission5_where
	DW	OFFSET DGROUP:dat_str_set01_mission5_what
	DW	OFFSET DGROUP:dat_str_set01_mission6_where
	DW	OFFSET DGROUP:dat_str_set01_mission6_what
	DW	OFFSET DGROUP:dat_str_set01_mission7_where
	DW	OFFSET DGROUP:dat_str_set01_mission7_what
	DB	46h,72h,65h,65h,64h,6Fh,6Dh,20h
	DB	47h,61h,6Dh,65h,73h,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0Ch,7,0,2,0,6,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set02_mission0_where
	DW	OFFSET DGROUP:dat_str_set02_mission0_what
	DW	OFFSET DGROUP:dat_str_set02_mission1_where
	DW	OFFSET DGROUP:dat_str_set02_mission1_what
	DW	OFFSET DGROUP:dat_str_set02_mission2_where
	DW	OFFSET DGROUP:dat_str_set02_mission2_what
	DW	OFFSET DGROUP:dat_str_set02_mission3_where
	DW	OFFSET DGROUP:dat_str_set02_mission3_what
	DW	OFFSET DGROUP:dat_str_set02_mission4_where
	DW	OFFSET DGROUP:dat_str_set02_mission4_what
	DW	OFFSET DGROUP:dat_str_set02_mission5_where
	DW	OFFSET DGROUP:dat_str_set02_mission5_what
	DW	OFFSET DGROUP:dat_str_set02_mission6_where
	DW	OFFSET DGROUP:dat_str_set02_mission6_what
	DW	OFFSET DGROUP:dat_str_set02_mission7_where
	DW	OFFSET DGROUP:dat_str_set02_mission7_what
	DB	53h,75h,70h,65h,72h,44h,72h,75h
	DB	67h,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,6,0,0,4,0,3,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set03_mission0_where
	DW	OFFSET DGROUP:dat_str_set03_mission0_what
	DW	OFFSET DGROUP:dat_str_set03_mission1_where
	DW	OFFSET DGROUP:dat_str_set03_mission1_what
	DW	OFFSET DGROUP:dat_str_set03_mission2_where
	DW	OFFSET DGROUP:dat_str_set03_mission2_what
	DW	OFFSET DGROUP:dat_str_set03_mission3_where
	DW	OFFSET DGROUP:dat_str_set03_mission3_what
	DW	OFFSET DGROUP:dat_str_set03_mission4_where
	DW	OFFSET DGROUP:dat_str_set03_mission4_what
	DW	OFFSET DGROUP:dat_str_set03_mission5_where
	DW	OFFSET DGROUP:dat_str_set03_mission5_what
	DW	OFFSET DGROUP:dat_str_set03_mission6_where
	DW	OFFSET DGROUP:dat_str_set03_mission6_what
	DW	OFFSET DGROUP:dat_str_set03_mission7_where
	DW	OFFSET DGROUP:dat_str_set03_mission7_what
	DB	4Ch,69h,62h,65h,72h,69h,61h,6Eh
	DB	20h,45h,6Ch,65h,63h,74h,69h,6Fh
	DB	6Eh,0,0,0,0,0,0,0
	DB	0,9,0Bh,0,6,0,8,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set04_mission0_where
	DW	OFFSET DGROUP:dat_str_set04_mission0_what
	DW	OFFSET DGROUP:dat_str_set04_mission1_where
	DW	OFFSET DGROUP:dat_str_set04_mission1_what
	DW	OFFSET DGROUP:dat_str_set04_mission2_where
	DW	OFFSET DGROUP:dat_str_set04_mission2_what
	DW	OFFSET DGROUP:dat_str_set04_mission3_where
	DW	OFFSET DGROUP:dat_str_set04_mission3_what
	DW	OFFSET DGROUP:dat_str_set04_mission4_where
	DW	OFFSET DGROUP:dat_str_set04_mission4_what
	DW	OFFSET DGROUP:dat_str_set04_mission5_where
	DW	OFFSET DGROUP:dat_str_set04_mission5_what
	DW	OFFSET DGROUP:dat_str_set04_mission6_where
	DW	OFFSET DGROUP:dat_str_set04_mission6_what
	DW	OFFSET DGROUP:dat_str_set04_mission7_where
	DW	OFFSET DGROUP:dat_str_set04_mission7_what
	DB	53h,75h,6Dh,6Dh,69h,74h,20h,43h
	DB	6Fh,6Eh,66h,65h,72h,65h,6Eh,63h
	DB	65h,0,0,0,0,0,0,0
	DB	0,0Ch,0Ah,0,9,0,2,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set05_mission0_where
	DW	OFFSET DGROUP:dat_str_set05_mission0_what
	DW	OFFSET DGROUP:dat_str_set05_mission1_where
	DW	OFFSET DGROUP:dat_str_set05_mission1_what
	DW	OFFSET DGROUP:dat_str_set05_mission2_where
	DW	OFFSET DGROUP:dat_str_set05_mission2_what
	DW	OFFSET DGROUP:dat_str_set05_mission3_where
	DW	OFFSET DGROUP:dat_str_set05_mission3_what
	DW	OFFSET DGROUP:dat_str_set05_mission4_where
	DW	OFFSET DGROUP:dat_str_set05_mission4_what
	DW	OFFSET DGROUP:dat_str_set05_mission5_where
	DW	OFFSET DGROUP:dat_str_set05_mission5_what
	DW	OFFSET DGROUP:dat_str_set05_mission6_where
	DW	OFFSET DGROUP:dat_str_set05_mission6_what
	DW	OFFSET DGROUP:dat_str_set05_mission7_where
	DW	OFFSET DGROUP:dat_str_set05_mission7_what
	DB	52h,61h,6Dh,70h,61h,6Eh,74h,20h
	DB	49h,6Eh,66h,6Ch,61h,74h,69h,6Fh
	DB	6Eh,0,0,0,0,0,0,0
	DB	0,0Ah,0Ah,0,4,0,0Ch,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set06_mission0_where
	DW	OFFSET DGROUP:dat_str_set06_mission0_what
	DW	OFFSET DGROUP:dat_str_set06_mission1_where
	DW	OFFSET DGROUP:dat_str_set06_mission1_what
	DW	OFFSET DGROUP:dat_str_set06_mission2_where
	DW	OFFSET DGROUP:dat_str_set06_mission2_what
	DW	OFFSET DGROUP:dat_str_set06_mission3_where
	DW	OFFSET DGROUP:dat_str_set06_mission3_what
	DW	OFFSET DGROUP:dat_str_set06_mission4_where
	DW	OFFSET DGROUP:dat_str_set06_mission4_what
	DW	OFFSET DGROUP:dat_str_set06_mission5_where
	DW	OFFSET DGROUP:dat_str_set06_mission5_what
	DW	OFFSET DGROUP:dat_str_set06_mission6_where
	DW	OFFSET DGROUP:dat_str_set06_mission6_what
	DW	OFFSET DGROUP:dat_str_set06_mission7_where
	DW	OFFSET DGROUP:dat_str_set06_mission7_what
	DB	53h,74h,6Fh,6Ch,65h,6Eh,20h,4Eh
	DB	75h,6Bh,65h,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0Ch,7,0,9,0,4,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set07_mission0_where
	DW	OFFSET DGROUP:dat_str_set07_mission0_what
	DW	OFFSET DGROUP:dat_str_set07_mission1_where
	DW	OFFSET DGROUP:dat_str_set07_mission1_what
	DW	OFFSET DGROUP:dat_str_set07_mission2_where
	DW	OFFSET DGROUP:dat_str_set07_mission2_what
	DW	OFFSET DGROUP:dat_str_set07_mission3_where
	DW	OFFSET DGROUP:dat_str_set07_mission3_what
	DW	OFFSET DGROUP:dat_str_set07_mission4_where
	DW	OFFSET DGROUP:dat_str_set07_mission4_what
	DW	OFFSET DGROUP:dat_str_set07_mission5_where
	DW	OFFSET DGROUP:dat_str_set07_mission5_what
	DW	OFFSET DGROUP:dat_str_set07_mission6_where
	DW	OFFSET DGROUP:dat_str_set07_mission6_what
	DW	OFFSET DGROUP:dat_str_set07_mission7_where
	DW	OFFSET DGROUP:dat_str_set07_mission7_what
	DB	53h,75h,70h,65h,72h,20h,43h,61h
	DB	6Eh,6Eh,6Fh,6Eh,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0Bh,4,0,4,0,0Ch,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set08_mission0_where
	DW	OFFSET DGROUP:dat_str_set08_mission0_what
	DW	OFFSET DGROUP:dat_str_set08_mission1_where
	DW	OFFSET DGROUP:dat_str_set08_mission1_what
	DW	OFFSET DGROUP:dat_str_set08_mission2_where
	DW	OFFSET DGROUP:dat_str_set08_mission2_what
	DW	OFFSET DGROUP:dat_str_set08_mission3_where
	DW	OFFSET DGROUP:dat_str_set08_mission3_what
	DW	OFFSET DGROUP:dat_str_set08_mission4_where
	DW	OFFSET DGROUP:dat_str_set08_mission4_what
	DW	OFFSET DGROUP:dat_str_set08_mission5_where
	DW	OFFSET DGROUP:dat_str_set08_mission5_what
	DW	OFFSET DGROUP:dat_str_set08_mission6_where
	DW	OFFSET DGROUP:dat_str_set08_mission6_what
	DW	OFFSET DGROUP:dat_str_set08_mission7_where
	DW	OFFSET DGROUP:dat_str_set08_mission7_what
	DB	42h,75h,69h,6Ch,64h,20h,4Eh,75h
	DB	63h,6Ch,65h,61h,72h,20h,57h,65h
	DB	61h,70h,6Fh,6Eh,0,0,0,0
	DB	0,0Dh,4,0,0,0,0Ch,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0
	DW	OFFSET DGROUP:dat_str_set09_mission0_where
	DW	OFFSET DGROUP:dat_str_set09_mission0_what
	DW	OFFSET DGROUP:dat_str_set09_mission1_where
	DW	OFFSET DGROUP:dat_str_set09_mission1_what
	DW	OFFSET DGROUP:dat_str_set09_mission2_where
	DW	OFFSET DGROUP:dat_str_set09_mission2_what
	DW	OFFSET DGROUP:dat_str_set09_mission3_where
	DW	OFFSET DGROUP:dat_str_set09_mission3_what
	DW	OFFSET DGROUP:dat_str_set09_mission4_where
	DW	OFFSET DGROUP:dat_str_set09_mission4_what
	DW	OFFSET DGROUP:dat_str_set09_mission5_where
	DW	OFFSET DGROUP:dat_str_set09_mission5_what
	DW	OFFSET DGROUP:dat_str_set09_mission6_where
	DW	OFFSET DGROUP:dat_str_set09_mission6_what
	DW	OFFSET DGROUP:dat_str_set09_mission7_where
	DW	OFFSET DGROUP:dat_str_set09_mission7_what
	DB	54h,65h,72h,72h,6Fh,72h,20h,43h
	DB	61h,6Dh,70h,61h,69h,67h,6Eh,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0Ch,6,0,8,0,2,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh
	DW	OFFSET DGROUP:dat_str_set10_mission0_where
	DW	OFFSET DGROUP:dat_str_set10_mission0_what
	DW	OFFSET DGROUP:dat_str_set10_mission1_where
	DW	OFFSET DGROUP:dat_str_set10_mission1_what
	DW	OFFSET DGROUP:dat_str_set10_mission2_where
	DW	OFFSET DGROUP:dat_str_set10_mission2_what
	DW	OFFSET DGROUP:dat_str_set10_mission3_where
	DW	OFFSET DGROUP:dat_str_set10_mission3_what
	DW	OFFSET DGROUP:dat_str_set10_mission4_where
	DW	OFFSET DGROUP:dat_str_set10_mission4_what
	DW	OFFSET DGROUP:dat_str_set10_mission5_where
	DW	OFFSET DGROUP:dat_str_set10_mission5_what
	DW	OFFSET DGROUP:dat_str_set10_mission6_where
	DW	OFFSET DGROUP:dat_str_set10_mission6_what
	DW	OFFSET DGROUP:dat_str_set10_mission7_where
	DW	OFFSET DGROUP:dat_str_set10_mission7_what
	DB	56h,69h,72h,75h,73h,20h,58h,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0Ch,0,0,4,0,0Ch,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh
	DW	OFFSET DGROUP:dat_str_set11_mission0_where
	DW	OFFSET DGROUP:dat_str_set11_mission0_what
	DW	OFFSET DGROUP:dat_str_set11_mission1_where
	DW	OFFSET DGROUP:dat_str_set11_mission1_what
	DW	OFFSET DGROUP:dat_str_set11_mission2_where
	DW	OFFSET DGROUP:dat_str_set11_mission2_what
	DW	OFFSET DGROUP:dat_str_set11_mission3_where
	DW	OFFSET DGROUP:dat_str_set11_mission3_what
	DW	OFFSET DGROUP:dat_str_set11_mission4_where
	DW	OFFSET DGROUP:dat_str_set11_mission4_what
	DW	OFFSET DGROUP:dat_str_set11_mission5_where
	DW	OFFSET DGROUP:dat_str_set11_mission5_what
	DW	OFFSET DGROUP:dat_str_set11_mission6_where
	DW	OFFSET DGROUP:dat_str_set11_mission6_what
	DW	OFFSET DGROUP:dat_str_set11_mission7_where
	DW	OFFSET DGROUP:dat_str_set11_mission7_what
	DB	44h,72h,75h,67h,20h,53h,68h,6Fh
	DB	72h,74h,61h,67h,65h,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0Ah,6,0,2,0,3,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh
	DW	OFFSET DGROUP:dat_str_set12_mission0_where
	DW	OFFSET DGROUP:dat_str_set12_mission0_what
	DW	OFFSET DGROUP:dat_str_set12_mission1_where
	DW	OFFSET DGROUP:dat_str_set12_mission1_what
	DW	OFFSET DGROUP:dat_str_set12_mission2_where
	DW	OFFSET DGROUP:dat_str_set12_mission2_what
	DW	OFFSET DGROUP:dat_str_set12_mission3_where
	DW	OFFSET DGROUP:dat_str_set12_mission3_what
	DW	OFFSET DGROUP:dat_str_set12_mission4_where
	DW	OFFSET DGROUP:dat_str_set12_mission4_what
	DW	OFFSET DGROUP:dat_str_set12_mission5_where
	DW	OFFSET DGROUP:dat_str_set12_mission5_what
	DW	OFFSET DGROUP:dat_str_set12_mission6_where
	DW	OFFSET DGROUP:dat_str_set12_mission6_what
	DW	OFFSET DGROUP:dat_str_set12_mission7_where
	DW	OFFSET DGROUP:dat_str_set12_mission7_what
	DB	54h,72h,61h,69h,6Eh,20h,57h,72h
	DB	65h,63h,6Bh,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0Ch,7,0,5,0,6,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh
	DW	OFFSET DGROUP:dat_str_set13_mission0_where
	DW	OFFSET DGROUP:dat_str_set13_mission0_what
	DW	OFFSET DGROUP:dat_str_set13_mission1_where
	DW	OFFSET DGROUP:dat_str_set13_mission1_what
	DW	OFFSET DGROUP:dat_str_set13_mission2_where
	DW	OFFSET DGROUP:dat_str_set13_mission2_what
	DW	OFFSET DGROUP:dat_str_set13_mission3_where
	DW	OFFSET DGROUP:dat_str_set13_mission3_what
	DW	OFFSET DGROUP:dat_str_set13_mission4_where
	DW	OFFSET DGROUP:dat_str_set13_mission4_what
	DW	OFFSET DGROUP:dat_str_set13_mission5_where
	DW	OFFSET DGROUP:dat_str_set13_mission5_what
	DW	OFFSET DGROUP:dat_str_set13_mission6_where
	DW	OFFSET DGROUP:dat_str_set13_mission6_what
	DW	OFFSET DGROUP:dat_str_set13_mission7_where
	DW	OFFSET DGROUP:dat_str_set13_mission7_what
	DB	50h,72h,69h,73h,6Fh,6Eh,20h,42h
	DB	72h,65h,61h,6Bh,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,7,9,0,0Bh,0,0Ah,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh
	DW	OFFSET DGROUP:dat_str_set14_mission0_where
	DW	OFFSET DGROUP:dat_str_set14_mission0_what
	DW	OFFSET DGROUP:dat_str_set14_mission1_where
	DW	OFFSET DGROUP:dat_str_set14_mission1_what
	DW	OFFSET DGROUP:dat_str_set14_mission2_where
	DW	OFFSET DGROUP:dat_str_set14_mission2_what
	DW	OFFSET DGROUP:dat_str_set14_mission3_where
	DW	OFFSET DGROUP:dat_str_set14_mission3_what
	DW	OFFSET DGROUP:dat_str_set14_mission4_where
	DW	OFFSET DGROUP:dat_str_set14_mission4_what
	DW	OFFSET DGROUP:dat_str_set14_mission5_where
	DW	OFFSET DGROUP:dat_str_set14_mission5_what
	DW	OFFSET DGROUP:dat_str_set14_mission6_where
	DW	OFFSET DGROUP:dat_str_set14_mission6_what
	DW	OFFSET DGROUP:dat_str_set14_mission7_where
	DW	OFFSET DGROUP:dat_str_set14_mission7_what
	DB	53h,74h,65h,61h,6Ch,74h,68h,20h
	DB	46h,69h,67h,68h,74h,65h,72h,0
	DB	0,0,0,0,0,0,0,0
	DB	0,3,0Bh,0,7,0,4,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh
	DW	OFFSET DGROUP:dat_str_set15_mission0_where
	DW	OFFSET DGROUP:dat_str_set15_mission0_what
	DW	OFFSET DGROUP:dat_str_set15_mission1_where
	DW	OFFSET DGROUP:dat_str_set15_mission1_what
	DW	OFFSET DGROUP:dat_str_set15_mission2_where
	DW	OFFSET DGROUP:dat_str_set15_mission2_what
	DW	OFFSET DGROUP:dat_str_set15_mission3_where
	DW	OFFSET DGROUP:dat_str_set15_mission3_what
	DW	OFFSET DGROUP:dat_str_set15_mission4_where
	DW	OFFSET DGROUP:dat_str_set15_mission4_what
	DW	OFFSET DGROUP:dat_str_set15_mission5_where
	DW	OFFSET DGROUP:dat_str_set15_mission5_what
	DW	OFFSET DGROUP:dat_str_set15_mission6_where
	DW	OFFSET DGROUP:dat_str_set15_mission6_what
	DW	OFFSET DGROUP:dat_str_set15_mission7_where
	DW	OFFSET DGROUP:dat_str_set15_mission7_what
_dat_key_plot_start	DB	2Ah,50h,4Ch,30h,30h,39h,30h,0
_dat_str_briefing_pan	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_plot_txt	DB	70h,6Ch,6Fh,74h,2Eh,74h,78h,74h
	DB	0
_dat_str_max_remington_s	DB	4Dh,61h,78h,20h,52h,65h,6Dh,69h
	DB	6Eh,67h,74h,6Fh,6Eh,27h,73h,20h
	DB	61h,70h,61h,72h,74h,6Dh,65h,6Eh
	DB	74h,0
_dat_str_mattress_full_cash	DB	61h,20h,6Dh,61h,74h,74h,72h,65h
	DB	73h,73h,20h,66h,75h,6Ch,6Ch,20h
	DB	6Fh,66h,20h,63h,61h,73h,68h,0
_dat_str_pl000a	DB	2Ah,50h,4Ch,30h,30h,30h,41h,0
_dat_str_pl000a_2	DB	2Ah,50h,4Ch,30h,30h,30h,61h,0
_dat_str_briefing_pan_2	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_plot_txt_2	DB	70h,6Ch,6Fh,74h,2Eh,74h,78h,74h
	DB	0
_dat_str_max_s_code_name	DB	4Dh,61h,78h,27h,73h,20h,63h,6Fh
	DB	64h,65h,20h,6Eh,61h,6Dh,65h,20h
	DB	69h,73h,3Ah,0
_dat_str_which_difficulty_level_2	DB	57h,68h,69h,63h,68h,20h,64h,69h
	DB	66h,66h,69h,63h,75h,6Ch,74h,79h
	DB	20h,6Ch,65h,76h,65h,6Ch,3Fh,0Ah
	DB	20h,4Ch,6Fh,63h,61h,6Ch,20h,44h
	DB	69h,73h,74h,75h,72h,62h,61h,6Eh
	DB	63h,65h,0Ah,20h,4Eh,61h,74h,69h
	DB	6Fh,6Eh,61h,6Ch,20h,54h,68h,72h
	DB	65h,61h,74h,0Ah,20h,52h,65h,67h
	DB	69h,6Fh,6Eh,61h,6Ch,20h,43h,6Fh
	DB	6Eh,66h,6Ch,69h,63h,74h,0Ah,20h
	DB	47h,6Ch,6Fh,62h,61h,6Ch,20h,43h
	DB	72h,69h,73h,69h,73h,0Ah,0
dat_str_combat	DB	43h,6Fh,6Dh,62h,61h,74h,0
dat_str_driving	DB	44h,72h,69h,76h,69h,6Eh,67h,0
dat_str_cryptography	DB	43h,72h,79h,70h,74h,6Fh,67h,72h
	DB	61h,70h,68h,79h,0
dat_str_electronics	DB	45h,6Ch,65h,63h,74h,72h,6Fh,6Eh
	DB	69h,63h,73h,0
dat_str_stamina	DB	53h,74h,61h,6Dh,69h,6Eh,61h,0
_dat_str_training_pic	DB	74h,72h,61h,69h,6Eh,69h,6Eh,67h
	DB	2Eh,70h,69h,63h,0
_dat_str_blank	DB	20h,0
_dat_str_practice	DB	20h,70h,72h,61h,63h,74h,69h,63h
	DB	65h,0Ah,20h,0
_dat_str_training	DB	20h,74h,72h,61h,69h,6Eh,69h,6Eh
	DB	67h,0Ah,20h,0
_dat_skill_names	DW	OFFSET DGROUP:dat_str_combat
	DW	OFFSET DGROUP:dat_str_driving
	DW	OFFSET DGROUP:dat_str_cryptography
	DW	OFFSET DGROUP:dat_str_electronics
	DW	OFFSET DGROUP:dat_str_stamina
_dat_str_average	DB	41h,76h,65h,72h,61h,67h,65h,0
_dat_str_good	DB	47h,6Fh,6Fh,64h,0
_dat_str_excellent	DB	45h,78h,63h,65h,6Ch,6Ch,65h,6Eh
	DB	74h,0
_dat_str_awesome	DB	41h,77h,65h,73h,6Fh,6Dh,65h,0
	DB	0
_dat_skill_colours	DB	4,0,9,0,8,0,2,0
_dat_palette_badge	DB	0,1,2,3,4,0,6,7		; PALETTE
	DB	8,9,0Ah,0Bh,0Ch,0Fh,0Eh,0Fh
	DB	0
_dat_str_max_i_m_sure	DB	4Dh,61h,78h,2Ch,20h,49h,27h,6Dh
	DB	20h,73h,75h,72h,65h,20h,79h,6Fh
	DB	75h,20h,72h,65h,63h,6Fh,67h,6Eh
	DB	69h,7Ah,65h,20h,74h,68h,65h,20h
	DB	68h,65h,61h,64h,20h,6Fh,66h,0Ah
	DB	74h,68h,65h,20h,0
_dat_str_among_these_faces	DB	20h,61h,6Dh,6Fh,6Eh,67h,20h,74h
	DB	68h,65h,73h,65h,20h,66h,61h,63h
	DB	65h,73h,2Eh,0Ah,0,0
_dat_str_briefing_pan_3	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_looks_like_about_wraps	DB	49h,74h,20h,6Ch,6Fh,6Fh,6Bh,73h
	DB	20h,6Ch,69h,6Bh,65h,20h,74h,68h
	DB	61h,74h,20h,61h,62h,6Fh,75h,74h
	DB	20h,77h,72h,61h,70h,73h,20h,69h
	DB	74h,20h,75h,70h,2Ch,20h,4Dh,61h
	DB	78h,2Eh,20h,0
_dat_str_we_ve_been_able	DB	57h,65h,27h,76h,65h,20h,62h,65h
	DB	65h,6Eh,20h,61h,62h,6Ch,65h,20h
	DB	74h,6Fh,20h,70h,75h,74h,20h,74h
	DB	6Fh,67h,65h,74h,68h,65h,72h,20h
	DB	61h,20h,70h,72h,65h,74h,74h,79h
	DB	20h,67h,6Fh,6Fh,64h,20h,63h,68h
	DB	72h,6Fh,6Eh,6Fh,6Ch,6Fh,67h,79h
	DB	20h,6Fh,66h,20h,74h,68h,69h,73h
	DB	20h,63h,61h,73h,65h,2Ch,20h,74h
	DB	61h,6Bh,65h,20h,61h,20h,6Ch,6Fh
	DB	6Fh,6Bh,2Eh,0
_dat_str_icons_pic	DB	69h,63h,6Fh,6Eh,73h,2Eh,70h,69h
	DB	63h,0
_dat_key_plot_zero	DB	2Ah,50h,4Ch,30h,30h,30h,30h,0
_dat_note_01	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_note_02	DB	70h,6Ch,6Fh,74h,2Eh,74h,78h,74h
	DB	0
_dat_note_03	DB	49h,6Eh,74h,65h,72h,72h,6Fh,67h
	DB	61h,74h,69h,6Fh,6Eh,20h,6Fh,66h
	DB	20h,74h,68h,65h,20h,73h,75h,73h
	DB	70h,65h,63h,74h,73h,20h,68h,61h
	DB	73h,20h,72h,65h,76h,65h,61h,6Ch
	DB	65h,64h,20h,73h,6Fh,6Dh,65h,20h
	DB	61h,64h,64h,69h,74h,69h,6Fh,6Eh
	DB	61h,6Ch,20h,69h,6Eh,66h,6Fh,72h
	DB	6Dh,61h,74h,69h,6Fh,6Eh,20h,61h
	DB	62h,6Fh,75h,74h,20h,4Dh,72h,2Eh
	DB	42h,69h,67h,2Eh,0
_dat_note_04	DB	59h,6Fh,75h,20h,68h,61h,76h,65h
	DB	20h,63h,61h,70h,74h,75h,72h,65h
	DB	64h,20h,74h,68h,65h,20h,4Dh,61h
	DB	73h,74h,65h,72h,4Dh,69h,6Eh,64h
	DB	20h,63h,6Fh,6Eh,74h,72h,6Fh,6Ch
	DB	6Ch,69h,6Eh,67h,20h,74h,68h,65h
	DB	20h,0
_dat_note_05	DB	21h,20h,54h,68h,65h,20h,63h,6Fh
	DB	75h,6Eh,74h,72h,79h,20h,68h,61h
	DB	73h,20h,62h,65h,65h,6Eh,20h,73h
	DB	61h,76h,65h,64h,20h,66h,72h,6Fh
	DB	6Dh,20h,61h,20h,64h,61h,6Eh,67h
	DB	65h,72h,6Fh,75h,73h,20h,70h,6Ch
	DB	6Fh,74h,2Eh,20h,0
_dat_note_06	DB	43h,6Fh,6Eh,67h,72h,61h,74h,75h
	DB	6Ch,61h,74h,69h,6Fh,6Eh,73h,2Ch
	DB	20h,74h,68h,65h,20h,50h,72h,65h
	DB	73h,69h,64h,65h,6Eh,74h,20h,63h
	DB	6Fh,6Dh,6Dh,65h,6Eh,64h,73h,20h
	DB	79h,6Fh,75h,2Eh,0Ah,0
_dat_note_07	DB	43h,6Fh,6Eh,67h,72h,61h,74h,75h
	DB	6Ch,61h,74h,69h,6Fh,6Eh,73h,20h
	DB	4Dh,61h,78h,2Ch,20h,77h,65h,27h
	DB	76h,65h,20h,64h,65h,63h,69h,64h
	DB	65h,64h,20h,74h,6Fh,20h,70h,72h
	DB	6Fh,6Dh,6Fh,74h,65h,20h,79h,6Fh
	DB	75h,20h,66h,72h,6Fh,6Dh,20h,30h
	DB	30h,0
_dat_note_08	DB	20h,72h,61h,6Eh,6Bh,20h,74h,6Fh
	DB	20h,30h,30h,0
_dat_note_09	DB	20h,72h,61h,6Eh,6Bh,2Eh,20h,48h
	DB	65h,72h,65h,27h,73h,20h,61h,20h
	DB	63h,6Fh,6Dh,6Dh,65h,6Eh,64h,61h
	DB	74h,69h,6Fh,6Eh,20h,66h,72h,6Fh
	DB	6Dh,20h,74h,68h,65h,20h,50h,72h
	DB	65h,73h,69h,64h,65h,6Eh,74h,2Eh
	DB	0
_dat_note_10	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_note_11	DB	49h,4Eh,43h,52h,45h,44h,49h,42h
	DB	4Ch,45h,3Ah,20h,59h,6Fh,75h,20h
	DB	68h,61h,76h,65h,0Ah,61h,72h,72h
	DB	65h,73h,74h,65h,64h,20h,61h,6Ch
	DB	6Ch,20h,32h,36h,20h,4Dh,61h,73h
	DB	74h,65h,72h,6Dh,69h,6Eh,64h,73h
	DB	21h,0Ah,0
_dat_note_12	DB	59h,6Fh,75h,20h,68h,61h,76h,65h
	DB	20h,63h,6Fh,6Dh,70h,6Ch,65h,74h
	DB	65h,64h,20h,61h,0Ah,74h,65h,6Eh
	DB	20h,79h,65h,61h,72h,20h,63h,61h
	DB	72h,65h,65h,72h,20h,77h,69h,74h
	DB	68h,20h,74h,68h,65h,20h,43h,49h
	DB	41h,2Eh,0Ah,0
_dat_note_13	DB	59h,6Fh,75h,20h,72h,65h,74h,69h
	DB	72h,65h,20h,74h,6Fh,20h,61h,20h
	DB	77h,65h,6Ch,6Ch,2Dh,0Ah,64h,65h
	DB	73h,65h,72h,76h,65h,64h,20h,6Ch
	DB	69h,66h,65h,20h,6Fh,66h,20h,72h
	DB	65h,6Ch,61h,78h,61h,74h,69h,6Fh
	DB	6Eh,2Eh,0Ah,0
_dat_note_14	DB	44h,6Fh,20h,79h,6Fh,75h,20h,77h
	DB	61h,6Eh,74h,20h,74h,6Fh,2Eh,2Eh
	DB	2Eh,0Ah,20h,43h,6Fh,6Eh,74h,69h
	DB	6Eh,75h,65h,20h,47h,61h,6Dh,65h
	DB	0Ah,20h,53h,61h,76h,65h,20h,47h
	DB	61h,6Dh,65h,0Ah,20h,45h,6Eh,64h
	DB	20h,47h,61h,6Dh,65h,0Ah,0
_dat_note_15	DB	20h,43h,68h,61h,6Eh,67h,65h,20h
	DB	44h,69h,66h,66h,69h,63h,75h,6Ch
	DB	74h,79h,20h,4Ch,65h,76h,65h,6Ch
	DB	0Ah,0
_dat_note_16	DB	57h,68h,69h,63h,68h,20h,64h,69h
	DB	66h,66h,69h,63h,75h,6Ch,74h,79h
	DB	20h,6Ch,65h,76h,65h,6Ch,3Fh,0Ah
	DB	20h,4Ch,6Fh,63h,61h,6Ch,20h,44h
	DB	69h,73h,74h,75h,72h,62h,61h,6Eh
	DB	63h,65h,0Ah,20h,4Eh,61h,74h,69h
	DB	6Fh,6Eh,61h,6Ch,20h,54h,68h,72h
	DB	65h,61h,74h,0Ah,20h,52h,65h,67h
	DB	69h,6Fh,6Eh,61h,6Ch,20h,43h,6Fh
	DB	6Eh,66h,6Ch,69h,63h,74h,0Ah,20h
	DB	47h,6Ch,6Fh,62h,61h,6Ch,20h,43h
	DB	72h,69h,73h,69h,73h,0Ah,0
_dat_note_17	DB	44h,6Fh,20h,79h,6Fh,75h,20h,77h
	DB	61h,6Eh,74h,20h,74h,6Fh,2Eh,2Eh
	DB	2Eh,0Ah,20h,43h,6Fh,6Eh,74h,69h
	DB	6Eh,75h,65h,20h,47h,61h,6Dh,65h
	DB	0Ah,20h,45h,6Eh,64h,20h,47h,61h
	DB	6Dh,65h,0Ah,0
_dat_note_18	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0,0
dat_replay_page_port	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_asm_replay_page	DW	OFFSET DGROUP:dat_replay_page_port
_asm_plot_key	DB	2Ah,50h,4Ch,30h,30h,30h,30h,0
_dat_str_empty_2	DB	0
_dat_str_paren_open	DB	20h,28h,0
_dat_str_paren_close	DB	29h,20h,0
_dat_str_space	DB	20h,0
_dat_str_slash	DB	2Fh,0
_dat_str_sent_message	DB	20h,73h,65h,6Eh,74h,20h,6Dh,65h
	DB	73h,73h,61h,67h,65h,20h,74h,6Fh
	DB	20h,0
_dat_str_caret	DB	5Eh,0
_dat_str_caret_2	DB	5Eh,0
_dat_str_empty_3	DB	0
_dat_str_sent_message_2	DB	73h,65h,6Eh,74h,20h,6Dh,65h,73h
	DB	73h,61h,67h,65h,20h,74h,6Fh,0
_dat_str_sent_package	DB	73h,65h,6Eh,74h,20h,70h,61h,63h
	DB	6Bh,61h,67h,65h,20h,74h,6Fh,0
_dat_str_empty_4	DB	0
_dat_str_paren_open_2	DB	20h,28h,0
_dat_str_paren_close_2	DB	29h,20h,0
_dat_str_slash_2	DB	2Fh,0
_dat_str_caret_3	DB	5Eh,0
_dat_str_caret_4	DB	5Eh,0
_dat_str_paren_open_3	DB	20h,28h,0
_dat_str_paren_close_3	DB	29h,20h,0
_dat_str_now_has	DB	6Eh,6Fh,77h,20h,68h,61h,73h,20h
	DB	74h,68h,65h,20h,0
_dat_str_empty_5	DB	0
_dat_str_left	DB	20h,6Ch,65h,66h,74h,20h,0
_dat_str_traveled	DB	59h,6Fh,75h,20h,74h,72h,61h,76h
	DB	65h,6Ch,65h,64h,20h,74h,6Fh,20h
	DB	0
_dat_str_broke	DB	59h,6Fh,75h,20h,62h,72h,6Fh,6Bh
	DB	65h,20h,69h,6Eh,20h,74h,6Fh,20h
	DB	0
_dat_str_slash_3	DB	2Fh,0
_dat_str_arrested	DB	59h,6Fh,75h,20h,61h,72h,72h,65h
	DB	73h,74h,65h,64h,20h,0
_dat_str_confiscated	DB	59h,6Fh,75h,20h,63h,6Fh,6Eh,66h
	DB	69h,73h,63h,61h,74h,65h,64h,20h
	DB	0
_dat_str_went_into_hiding	DB	20h,77h,65h,6Eh,74h,20h,69h,6Eh
	DB	74h,6Fh,20h,68h,69h,64h,69h,6Eh
	DB	67h,2Eh,0
_dat_str_mission_completed	DB	4Dh,69h,73h,73h,69h,6Fh,6Eh,20h
	DB	63h,6Fh,6Dh,70h,6Ch,65h,74h,65h
	DB	64h,2Eh,0
_dat_str_unable	DB	55h,6Eh,61h,62h,6Ch,65h,20h,74h
	DB	6Fh,0
_dat_str_complete_mission	DB	63h,6Fh,6Dh,70h,6Ch,65h,74h,65h
	DB	20h,6Dh,69h,73h,73h,69h,6Fh,6Eh
	DB	2Eh,0
_dat_str_came_out_hiding	DB	20h,63h,61h,6Dh,65h,20h,6Fh,75h
	DB	74h,20h,6Fh,66h,20h,68h,69h,64h
	DB	69h,6Eh,67h,2Eh,0
_dat_str_escaped_from_jail	DB	20h,65h,73h,63h,61h,70h,65h,64h
	DB	20h,66h,72h,6Fh,6Dh,20h,6Ah,61h
	DB	69h,6Ch,2Eh,0
_dat_str_released_by_exchange	DB	20h,72h,65h,6Ch,65h,61h,73h,65h
	DB	64h,20h,62h,79h,20h,65h,78h,63h
	DB	68h,61h,6Eh,67h,65h,2Eh,0
_dat_str_turned	DB	59h,6Fh,75h,20h,74h,75h,72h,6Eh
	DB	65h,64h,20h,0
_dat_str_space_2	DB	20h,0
_dat_str_day_number	DB	20h,31h,30h,0
BLOCK_2A09	DB	0
_dat_date_template	DB	30h,30h,3Ah,30h,30h,20h,41h,4Dh
	DB	20h,4Ah,75h,6Eh,20h,30h,30h,0
_dat_str_efficiency_report	DB	45h,66h,66h,69h,63h,69h,65h,6Eh
	DB	63h,79h,20h,52h,65h,70h,6Fh,72h
	DB	74h,0
_dat_str_org_sep	DB	2Ch,20h,0
_dat_str_org_slash	DB	2Fh,0
_dat_str_at_large	DB	41h,74h,20h,4Ch,61h,72h,67h,65h
	DB	0
_dat_str_arrested_2	DB	41h,52h,52h,45h,53h,54h,45h,44h
	DB	0
_dat_str_turned_2	DB	54h,55h,52h,4Eh,45h,44h,0
_dat_str_ep_0	DB	45h,50h,3Ah,0
_dat_str_ep_of	DB	89h,2Fh,0
_dat_str_ep_50	DB	45h,50h,3Ah,30h,0
_dat_str_confiscated_2	DB	43h,4Fh,4Eh,46h,49h,53h,43h,41h
	DB	54h,45h,44h,0
_dat_str_ep_50_2	DB	45h,50h,3Ah,35h,30h,0
_dat_str_not_found	DB	4Eh,6Fh,74h,20h,66h,6Fh,75h,6Eh
	DB	64h,0
_dat_str_of_50	DB	89h,2Fh,35h,30h,0
_dat_str_of_org	DB	20h,0
_dat_str_ep_blank	DB	45h,50h,3Ah,20h,30h,2Fh,0
_dat_str_prevented_crime	DB	50h,72h,65h,76h,65h,6Eh,74h,65h
	DB	64h,20h,63h,72h,69h,6Dh,65h,0
_dat_str_ep_100	DB	45h,50h,3Ah,31h,30h,30h,89h,2Fh
	DB	31h,30h,30h,0
_dat_str_empty_agents	DB	0
_dat_str_double_agent_s	DB	20h,44h,6Fh,75h,62h,6Ch,65h,20h
	DB	41h,67h,65h,6Eh,74h,28h,73h,29h
	DB	0
_dat_str_remained_undetected	DB	72h,65h,6Dh,61h,69h,6Eh,65h,64h
	DB	20h,75h,6Eh,64h,65h,74h,65h,63h
	DB	74h,65h,64h,0
_dat_str_within_cia	DB	77h,69h,74h,68h,69h,6Eh,20h,74h
	DB	68h,65h,20h,43h,49h,41h,2Eh,0
_dat_str_ep_slash	DB	45h,50h,3Ah,30h,2Fh,0
_dat_str_efficiency_rating	DB	45h,66h,66h,69h,63h,69h,65h,6Eh
	DB	63h,79h,20h,52h,61h,74h,69h,6Eh
	DB	67h,0
_dat_str_dashes	DB	2Dh,2Dh,2Dh,20h,0
_dat_str_dashes_end	DB	20h,2Dh,2Dh,2Dh,0
_dat_str_ep_total	DB	45h,50h,3Ah,0
_dat_str_ep_total_of	DB	89h,2Fh,0
BLOCK_2AFB	DB	0
dat_str_kidnapping	DB	4Bh,69h,64h,6Eh,61h,70h,70h,69h
	DB	6Eh,67h,0
dat_str_theft	DB	54h,68h,65h,66h,74h,0
dat_str_assassination	DB	41h,73h,73h,61h,73h,73h,69h,6Eh
	DB	61h,74h,69h,6Fh,6Eh,0
dat_str_drug_smuggle	DB	44h,72h,75h,67h,20h,53h,6Dh,75h
	DB	67h,67h,6Ch,65h,0
dat_str_theft_2	DB	54h,68h,65h,66h,74h,0
dat_str_photo	DB	50h,68h,6Fh,74h,6Fh,0
dat_str_bombing	DB	42h,6Fh,6Dh,62h,69h,6Eh,67h,0
dat_str_datacrime	DB	44h,61h,74h,61h,43h,72h,69h,6Dh
	DB	65h,0
dat_str_terrorist_attack	DB	54h,65h,72h,72h,6Fh,72h,69h,73h
	DB	74h,20h,41h,74h,74h,61h,63h,6Bh
	DB	0
dat_str_forgery	DB	46h,6Fh,72h,67h,65h,72h,79h,0
dat_str_jail_break	DB	4Ah,61h,69h,6Ch,20h,42h,72h,65h
	DB	61h,6Bh,0
dat_str_blackmail	DB	42h,6Ch,61h,63h,6Bh,6Dh,61h,69h
	DB	6Ch,0
dat_str_manufacture	DB	4Dh,61h,6Eh,75h,66h,61h,63h,74h
	DB	75h,72h,65h,0
dat_str_pfo	DB	50h,46h,4Fh,0
dat_str_m18	DB	4Dh,31h,38h,0
dat_str_jamaican_gang	DB	4Ah,61h,6Dh,61h,69h,63h,61h,6Eh
	DB	20h,47h,61h,6Eh,67h,0
dat_str_haitian_junta	DB	48h,61h,69h,74h,69h,61h,6Eh,20h
	DB	4Ah,75h,6Eh,74h,61h,0
dat_str_red_september	DB	52h,65h,64h,20h,53h,65h,70h,74h
	DB	65h,6Dh,62h,65h,72h,0
dat_str_iraqi_sp	DB	49h,72h,61h,71h,69h,20h,53h,50h
	DB	0
dat_str_muslim_jihad	DB	4Dh,75h,73h,6Ch,69h,6Dh,20h,4Ah
	DB	69h,68h,61h,64h,0
dat_str_shining_way	DB	53h,68h,69h,6Eh,69h,6Eh,67h,20h
	DB	57h,61h,79h,0
dat_str_tupamaros	DB	54h,75h,70h,61h,6Dh,61h,72h,6Fh
	DB	73h,0
dat_str_colombian_cartel	DB	43h,6Fh,6Ch,6Fh,6Dh,62h,69h,61h
	DB	6Eh,20h,43h,61h,72h,74h,65h,6Ch
	DB	0
dat_str_mafia	DB	4Dh,61h,66h,69h,61h,0
dat_str_libyan_emb	DB	4Ch,69h,62h,79h,61h,6Eh,20h,45h
	DB	6Dh,62h,2Eh,0
dat_str_fln	DB	46h,4Ch,4Eh,0
dat_str_amazon_cartel	DB	41h,6Dh,61h,7Ah,6Fh,6Eh,20h,43h
	DB	61h,72h,74h,65h,6Ch,0
dat_str_mercenaries	DB	4Dh,65h,72h,63h,65h,6Eh,61h,72h
	DB	69h,65h,73h,0
dat_str_death_squads	DB	44h,65h,61h,74h,68h,20h,53h,71h
	DB	75h,61h,64h,73h,0
dat_str_rev_guards	DB	52h,65h,76h,2Eh,20h,47h,75h,61h
	DB	72h,64h,73h,0
dat_str_unioncorsique	DB	55h,6Eh,69h,6Fh,6Eh,43h,6Fh,72h
	DB	73h,69h,71h,75h,65h,0
dat_str_pifa	DB	50h,49h,46h,41h,0
dat_str_red_army	DB	52h,65h,64h,20h,41h,72h,6Dh,79h
	DB	0
dat_str_red_battalion	DB	52h,65h,64h,20h,42h,61h,74h,74h
	DB	61h,6Ch,69h,6Fh,6Eh,0
dat_str_direct_action	DB	44h,69h,72h,65h,63h,74h,20h,41h
	DB	63h,74h,69h,6Fh,6Eh,0
dat_str_stassi	DB	53h,74h,61h,73h,73h,69h,0
dat_str_prc	DB	50h,52h,43h,0
dat_str_marxists	DB	4Dh,61h,72h,78h,69h,73h,74h,73h
	DB	0
dat_str_dignity_bttn	DB	44h,69h,67h,6Eh,69h,74h,79h,20h
	DB	42h,74h,74h,6Eh,0
_dat_str_career	DB	43h,61h,72h,65h,65h,72h,0
_dat_str_career_2	DB	54h,68h,65h,20h,43h,61h,72h,65h
	DB	65h,72h,20h,6Fh,66h,0
_dat_str_max	DB	4Dh,61h,78h,20h,27h,0
_dat_str_remington	DB	27h,20h,52h,65h,6Dh,69h,6Eh,67h
	DB	74h,6Fh,6Eh,0
_dat_str_case	DB	43h,61h,73h,65h,20h,23h,0
_dat_str_comma	DB	2Ch,20h,0
_dat_str_space_3	DB	20h,0
_dat_str_arrests	DB	2Eh,20h,20h,41h,72h,72h,65h,73h
	DB	74h,73h,3Ah,20h,0
_dat_str_ep_colon	DB	20h,45h,50h,3Ah,20h,0
_dat_str_couldn_t_stop	DB	2Eh,2Eh,2Eh,20h,63h,6Fh,75h,6Ch
	DB	64h,6Eh,27h,74h,20h,73h,74h,6Fh
	DB	70h,20h,0
_dat_str_prevented	DB	2Eh,2Eh,2Eh,20h,70h,72h,65h,76h
	DB	65h,6Eh,74h,65h,64h,20h,0
_dat_str_slash_4	DB	2Fh,0
_dat_str_arrested_3	DB	2Eh,2Eh,2Eh,20h,61h,72h,72h,65h
	DB	73h,74h,65h,64h,20h,0
_dat_str_mastermind	DB	20h,4Dh,61h,73h,74h,65h,72h,4Dh
	DB	69h,6Eh,64h,21h,0
_dat_str_career_3	DB	43h,61h,72h,65h,65h,72h,0
_dat_str_arrested_masterminds	DB	41h,72h,72h,65h,73h,74h,65h,64h
	DB	2Ch,20h,4Dh,61h,73h,74h,65h,72h
	DB	4Dh,69h,6Eh,64h,73h,3Ah,20h,0
_dat_str_agents	DB	20h,20h,41h,67h,65h,6Eh,74h,73h
	DB	3Ah,20h,0
_dat_str_career_4	DB	43h,61h,72h,65h,65h,72h,0
_dat_str_masterminds_arrested	DB	4Dh,61h,73h,74h,65h,72h,4Dh,69h
	DB	6Eh,64h,73h,20h,41h,72h,72h,65h
	DB	73h,74h,65h,64h,0
_addr_crime_names	DW	OFFSET DGROUP:dat_str_kidnapping
	DW	OFFSET DGROUP:dat_str_theft
	DW	OFFSET DGROUP:dat_str_assassination
	DW	OFFSET DGROUP:dat_str_drug_smuggle
	DW	OFFSET DGROUP:dat_str_theft_2
	DW	OFFSET DGROUP:dat_str_photo
	DW	OFFSET DGROUP:dat_str_bombing
	DW	OFFSET DGROUP:dat_str_datacrime
	DW	OFFSET DGROUP:dat_str_terrorist_attack
	DW	OFFSET DGROUP:dat_str_forgery
	DW	OFFSET DGROUP:dat_str_jail_break
	DW	OFFSET DGROUP:dat_str_blackmail
	DW	OFFSET DGROUP:dat_str_manufacture
_dat_org_names	DW	OFFSET DGROUP:dat_str_pfo
	DW	OFFSET DGROUP:dat_str_m18
	DW	OFFSET DGROUP:dat_str_jamaican_gang
	DW	OFFSET DGROUP:dat_str_haitian_junta
	DW	OFFSET DGROUP:dat_str_red_september
	DW	OFFSET DGROUP:dat_str_iraqi_sp
	DW	OFFSET DGROUP:dat_str_muslim_jihad
	DW	OFFSET DGROUP:dat_str_shining_way
	DW	OFFSET DGROUP:dat_str_tupamaros
	DW	OFFSET DGROUP:dat_str_colombian_cartel
	DW	OFFSET DGROUP:dat_str_mafia
	DW	OFFSET DGROUP:dat_str_libyan_emb
	DW	OFFSET DGROUP:dat_str_fln
	DW	OFFSET DGROUP:dat_str_amazon_cartel
	DW	OFFSET DGROUP:dat_str_mercenaries
	DW	OFFSET DGROUP:dat_str_death_squads
	DW	OFFSET DGROUP:dat_str_rev_guards
	DW	OFFSET DGROUP:dat_str_unioncorsique
	DW	OFFSET DGROUP:dat_str_pifa
	DW	OFFSET DGROUP:dat_str_red_army
	DW	OFFSET DGROUP:dat_str_red_battalion
	DW	OFFSET DGROUP:dat_str_direct_action
	DW	OFFSET DGROUP:dat_str_stassi
	DW	OFFSET DGROUP:dat_str_prc
	DW	OFFSET DGROUP:dat_str_marxists
	DW	OFFSET DGROUP:dat_str_dignity_bttn
_dat_str_gender_pic_2	DB	67h,65h,6Eh,64h,65h,72h,2Eh,70h
	DB	69h,63h,0
_dat_str_max_2	DB	4Dh,61h,78h,0
_dat_str_remington_2	DB	52h,65h,6Dh,69h,6Eh,67h,74h,6Fh
	DB	6Eh,0
_dat_str_arrested_4	DB	41h,52h,52h,45h,53h,54h,45h,44h
	DB	0
_dat_str_arrested_5	DB	41h,52h,52h,45h,53h,54h,45h,44h
	DB	0
asm_block_2dd5	DB	0
dat_str_lau	DB	6Ch,61h,75h,0
dat_str_off	DB	6Fh,66h,66h,0
dat_str_bch	DB	62h,63h,68h,0
dat_str_cas	DB	63h,61h,73h,0
_dat_str_after_difficult_few	DB	41h,66h,74h,65h,72h,20h,61h,20h
	DB	64h,69h,66h,66h,69h,63h,75h,6Ch
	DB	74h,20h,66h,65h,77h,20h,64h,61h
	DB	79h,73h,20h,69h,74h,27h,73h,20h
	DB	74h,69h,6Dh,65h,20h,74h,6Fh,20h
	DB	68h,65h,61h,64h,20h,66h,6Fh,72h
	DB	20h,74h,68h,65h,20h,4Ch,61h,75h
	DB	6Eh,64h,72h,6Fh,4Dh,61h,74h,2Eh
	DB	0
_dat_str_word_latest_case_seems	DB	57h,6Fh,72h,64h,20h,6Fh,66h,20h
	DB	79h,6Fh,75h,72h,20h,6Ch,61h,74h
	DB	65h,73h,74h,20h,63h,61h,73h,65h
	DB	20h,73h,65h,65h,6Dh,73h,20h,74h
	DB	6Fh,20h,68h,61h,76h,65h,20h,72h
	DB	65h,61h,63h,68h,65h,64h,20h,74h
	DB	68h,65h,20h,73h,65h,63h,72h,65h
	DB	74h,61h,72h,69h,61h,6Ch,20h,70h
	DB	6Fh,6Fh,6Ch,2Eh,0
_dat_str_after_successful_case	DB	41h,66h,74h,65h,72h,20h,61h,20h
	DB	73h,75h,63h,63h,65h,73h,73h,66h
	DB	75h,6Ch,20h,63h,61h,73h,65h,2Ch
	DB	20h,79h,6Fh,75h,20h,64h,65h,73h
	DB	65h,72h,76h,65h,20h,73h,6Fh,6Dh
	DB	65h,20h,74h,69h,6Dh,65h,20h,61h
	DB	74h,20h,74h,68h,65h,20h,62h,65h
	DB	61h,63h,68h,21h,0
_dat_str_re_feeling_invincible	DB	59h,6Fh,75h,27h,72h,65h,20h,66h
	DB	65h,65h,6Ch,69h,6Eh,67h,20h,69h
	DB	6Eh,76h,69h,6Eh,63h,69h,62h,6Ch
	DB	65h,2Ch,20h,74h,69h,6Dh,65h,20h
	DB	74h,6Fh,20h,74h,72h,79h,20h,79h
	DB	6Fh,75h,72h,20h,6Ch,75h,63h,6Bh
	DB	20h,61h,74h,20h,74h,68h,65h,20h
	DB	43h,61h,73h,69h,6Eh,6Fh,21h,0
_dat_str_final4_cat	DB	66h,69h,6Eh,61h,6Ch,34h,2Eh,63h
	DB	61h,74h,0
_dat_str_final3_cat	DB	66h,69h,6Eh,61h,6Ch,33h,2Eh,63h
	DB	61h,74h,0
_dat_str_back_pic	DB	62h,61h,63h,6Bh,2Eh,70h,69h,63h
	DB	0
_dat_str_hand	DB	68h,61h,6Eh,64h,0
_dat_str_f_pic	DB	66h,2Eh,70h,69h,63h,0
_dat_str_m_pic	DB	6Dh,2Eh,70h,69h,63h,0
_dat_str_laudude1_pic	DB	6Ch,61h,75h,64h,75h,64h,65h,31h
	DB	2Eh,70h,69h,63h,0
_dat_str_dude	DB	64h,75h,64h,65h,0
_dat_str_babe	DB	62h,61h,62h,65h,0
_dat_str_pic	DB	2Eh,70h,69h,63h,0
asm_block_2f35	DB	0
_dat_ending_names	DW	OFFSET DGROUP:dat_str_lau
	DW	OFFSET DGROUP:dat_str_off
	DW	OFFSET DGROUP:dat_str_bch
	DW	OFFSET DGROUP:dat_str_cas
_dat_interlude_table	DB	0,0,1,0,0FFh,0FFh,0FFh,0FFh		; INTERLUDE[21]
	DB	0FFh,0FFh,0,0,2,0,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,1,0,4,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,1,0
	DB	3,0,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	1,0,2,0,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,1,0,1,0,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,1,0,2,0
	DB	1,0,0FFh,0FFh,0FFh,0FFh,2,0
	DB	4,0,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	2,0,1,0,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,2,0,3,0,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,2,0,4,0
	DB	1,0,0FFh,0FFh,0FFh,0FFh,2,0
	DB	2,0,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	2,0,1,0,2,0,0FFh,0FFh
	DB	0FFh,0FFh,2,0,4,0,3,0
	DB	2,0,0FFh,0FFh,3,0,4,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,3,0
	DB	2,0,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	3,0,3,0,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,3,0,2,0,4,0
	DB	0FFh,0FFh,0FFh,0FFh,3,0,1,0
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,3,0
	DB	2,0,3,0,4,0,0FFh,0FFh
	DB	3,0,4,0,2,0,1,0
	DB	3,0
_dat_str_red_herring	DB	52h,65h,64h,20h,48h,65h,72h,72h
	DB	69h,6Eh,67h,0
_dat_str_we_have_indications	DB	57h,65h,20h,68h,61h,76h,65h,20h
	DB	69h,6Eh,64h,69h,63h,61h,74h,69h
	DB	6Fh,6Eh,73h,20h,74h,68h,61h,74h
	DB	20h,0
_dat_str_operation_preparation	DB	61h,6Eh,20h,6Fh,70h,65h,72h,61h
	DB	74h,69h,6Fh,6Eh,20h,69h,73h,20h
	DB	69h,6Eh,20h,70h,72h,65h,70h,61h
	DB	72h,61h,74h,69h,6Fh,6Eh,20h,73h
	DB	6Fh,6Dh,65h,77h,68h,65h,72h,65h
	DB	20h,69h,6Eh,20h,0
_dat_str_europe	DB	45h,75h,72h,6Fh,70h,65h,2Eh,0
_dat_str_africa_middle_east	DB	41h,66h,72h,69h,63h,61h,2Fh,4Dh
	DB	69h,64h,64h,6Ch,65h,20h,45h,61h
	DB	73h,74h,2Eh,0
_dat_str_central_america	DB	43h,65h,6Eh,74h,72h,61h,6Ch,20h
	DB	41h,6Dh,65h,72h,69h,63h,61h,2Eh
	DB	0
_dat_str_the	DB	20h,54h,68h,65h,20h,0
_dat_str_known_involved	DB	20h,69h,73h,20h,6Bh,6Eh,6Fh,77h
	DB	6Eh,20h,74h,6Fh,20h,62h,65h,20h
	DB	69h,6Eh,76h,6Fh,6Ch,76h,65h,64h
	DB	2Eh,0
_dat_str_mission_prevent	DB	59h,6Fh,75h,72h,20h,6Dh,69h,73h
	DB	73h,69h,6Fh,6Eh,20h,69h,73h,20h
	DB	74h,6Fh,20h,70h,72h,65h,76h,65h
	DB	6Eh,74h,20h,74h,68h,69h,73h,20h
	DB	6Fh,70h,65h,72h,61h,74h,69h,6Fh
	DB	6Eh,20h,66h,72h,6Fh,6Dh,20h,73h
	DB	75h,63h,63h,65h,65h,64h,69h,6Eh
	DB	67h,20h,0
_dat_str_capture_as_many	DB	61h,6Eh,64h,20h,74h,6Fh,20h,63h
	DB	61h,70h,74h,75h,72h,65h,20h,61h
	DB	73h,20h,6Dh,61h,6Eh,79h,20h,6Fh
	DB	66h,20h,74h,68h,65h,20h,70h,61h
	DB	72h,74h,69h,63h,69h,70h,61h,6Eh
	DB	74h,73h,20h,61h,73h,20h,70h,6Fh
	DB	73h,73h,69h,62h,6Ch,65h,2Eh,0
_dat_str_caution_one_more_double	DB	20h,43h,61h,75h,74h,69h,6Fh,6Eh
	DB	2Ch,20h,6Fh,6Eh,65h,20h,6Fh,72h
	DB	20h,6Dh,6Fh,72h,65h,20h,44h,6Fh
	DB	75h,62h,6Ch,65h,20h,41h,67h,65h
	DB	6Eh,74h,73h,20h,61h,72h,65h,20h
	DB	62h,65h,6Ch,69h,65h,76h,65h,64h
	DB	20h,74h,6Fh,20h,62h,65h,20h,61h
	DB	63h,74h,69h,76h,65h,20h,77h,69h
	DB	74h,68h,69h,6Eh,20h,74h,68h,65h
	DB	20h,43h,49h,41h,2Eh,0
_dat_str_i_m_afraid_re	DB	49h,27h,6Dh,20h,61h,66h,72h,61h
	DB	69h,64h,20h,79h,6Fh,75h,27h,72h
	DB	65h,20h,6Eh,6Fh,74h,20h,71h,75h
	DB	69h,74h,65h,20h,75h,70h,20h,74h
	DB	6Fh,20h,73h,70h,65h,65h,64h,20h
	DB	79h,65h,74h,20h,4Dh,61h,78h,2Eh
	DB	20h,0
_dat_str_perhaps_should_practice	DB	50h,65h,72h,68h,61h,70h,73h,20h
	DB	79h,6Fh,75h,20h,73h,68h,6Fh,75h
	DB	6Ch,64h,20h,70h,72h,61h,63h,74h
	DB	69h,63h,65h,20h,79h,6Fh,75h,72h
	DB	20h,73h,6Bh,69h,6Ch,6Ch,73h,20h
	DB	62h,65h,66h,6Fh,72h,65h,20h,79h
	DB	6Fh,75h,20h,74h,61h,6Bh,65h,20h
	DB	74h,68h,69h,73h,20h,63h,61h,73h
	DB	65h,2Eh,0
_dat_str_ok_re_cleared	DB	4Fh,4Bh,2Ch,20h,79h,6Fh,75h,27h
	DB	72h,65h,20h,63h,6Ch,65h,61h,72h
	DB	65h,64h,2Eh,20h,0
_dat_str_here_some_info_we	DB	48h,65h,72h,65h,20h,69h,73h,20h
	DB	73h,6Fh,6Dh,65h,20h,69h,6Eh,66h
	DB	6Fh,20h,77h,65h,27h,76h,65h,20h
	DB	70h,69h,63h,6Bh,65h,64h,20h,75h
	DB	70h,20h,6Fh,76h,65h,72h,20h,74h
	DB	68h,65h,20h,6Ch,61h,73h,74h,20h
	DB	66h,65h,77h,20h,64h,61h,79h,73h
	DB	2Eh,20h,0
_dat_str_we_think_s_linked	DB	57h,65h,20h,74h,68h,69h,6Eh,6Bh
	DB	20h,69h,74h,27h,73h,20h,6Ch,69h
	DB	6Eh,6Bh,65h,64h,20h,74h,6Fh,20h
	DB	74h,68h,69h,73h,20h,6Fh,70h,65h
	DB	72h,61h,74h,69h,6Fh,6Eh,2Eh,2Eh
	DB	2Eh,0Ah,0
_dat_str_briefing_pan_4	DB	62h,72h,69h,65h,66h,69h,6Eh,67h
	DB	2Eh,70h,61h,6Eh,0
_dat_str_10_dta	DB	31h,30h,2Eh,64h,74h,61h,0
asm_block_3275	DB	0
_dat_CRIME_DTA_NAME	DB	63h,72h,69h,6Dh,65h,30h,2Eh,64h
	DB	74h,61h,20h,0
_dat_str_world	DB	77h,6Fh,72h,6Ch,64h,30h,2Eh,64h
	DB	74h,61h,0
asm_block_328d	DB	0
_dat_str_fame_dta	DB	66h,61h,6Dh,65h,2Eh,64h,74h,61h
	DB	0
_dat_str_fame_dta_2	DB	66h,61h,6Dh,65h,2Eh,64h,74h,61h
	DB	0
_dat_str_fame_dta_3	DB	66h,61h,6Dh,65h,2Eh,64h,74h,61h
	DB	0
_dat_str_fame_dta_4	DB	66h,61h,6Dh,65h,2Eh,64h,74h,61h
	DB	0
_dat_str_hall_fame	DB	48h,61h,6Ch,6Ch,20h,6Fh,66h,20h
	DB	46h,61h,6Dh,65h,0
_dat_str_covert_action	DB	43h,4Fh,56h,45h,52h,54h,20h,41h
	DB	43h,54h,49h,4Fh,4Eh,0
_dat_str_hall_fame_2	DB	48h,41h,4Ch,4Ch,20h,4Fh,46h,20h
	DB	46h,41h,4Dh,45h,0
_dat_str_dashes_2	DB	20h,2Dh,2Dh,2Dh,0
_dat_str_stop	DB	2Eh,20h,0
_dat_str_max_3	DB	4Dh,61h,78h,20h,27h,0
_dat_str_remington_case	DB	27h,20h,52h,65h,6Dh,69h,6Eh,67h
	DB	74h,6Fh,6Eh,2Ch,20h,20h,43h,61h
	DB	73h,65h,20h,23h,0
_dat_str_space_4	DB	20h,0
_dat_str_space_5	DB	20h,0
_dat_str_slash_5	DB	2Fh,0
_dat_str_ep_colon_2	DB	45h,50h,3Ah,20h,0
_dat_str_score_stop	DB	20h,20h,20h,20h,80h,2Dh,2Dh,2Dh
	DB	20h,53h,43h,4Fh,52h,45h,3Ah,20h
	DB	0
_dat_str_dashes_3	DB	20h,2Dh,2Dh,2Dh,0
_dat_str_clear	DB	43h,83h,6Ch,65h,61h,72h,0
asm_block_3325	DB	0
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
_shd_str_coded_message	DB	20h,20h,20h,20h,20h,20h,20h,43h
	DB	4Fh,44h,45h,44h,20h,4Dh,45h,53h
	DB	53h,41h,47h,45h,3Ah,0Ah,0
_shd_str_meeting_notes	DB	20h,20h,20h,20h,20h,20h,20h,4Dh
	DB	45h,45h,54h,49h,4Eh,47h,20h,4Eh
	DB	4Fh,54h,45h,53h,3Ah,0Ah,0
_shd_str_new_information	DB	20h,20h,20h,20h,20h,20h,20h,4Eh
	DB	45h,57h,20h,49h,4Eh,46h,4Fh,52h
	DB	4Dh,41h,54h,49h,4Fh,4Eh,0Ah,0
_shd_str_additional_information	DB	20h,20h,20h,20h,41h,44h,44h,49h
	DB	54h,49h,4Fh,4Eh,41h,4Ch,20h,49h
	DB	4Eh,46h,4Fh,52h,4Dh,41h,54h,49h
	DB	4Fh,4Eh,0Ah,0
_shd_str_space_after_name	DB	20h,0
_shd_str_dots	DB	0Ah,2Eh,2Eh,2Eh,20h,0
_shd_str_on	DB	6Fh,6Eh,20h,0
_shd_str_space_after_month	DB	20h,0
_shd_str_of_the	DB	6Fh,66h,20h,74h,68h,65h,20h,0
_shd_str_in	DB	69h,6Eh,20h,0
_shd_str_newline	DB	0Ah,0
_shd_str_empty_watch	DB	0
_shd_str_space_face	DB	20h,0
_shd_str_in_2	DB	20h,69h,6Eh,20h,0
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
asm_block_364c	DB	2,2,1,4,1,8,1,8
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
MONTH_NAMES_PAD	DB	0
asm_block_3695	DB	0
_shd_str_empty_identified	DB	0
_shd_str_has_been_identified_as	DB	20h,68h,61h,73h,20h,62h,65h,65h
	DB	6Eh,0Ah,69h,64h,65h,6Eh,74h,69h
	DB	66h,69h,65h,64h,20h,61h,73h,20h
	DB	61h,20h,70h,61h,72h,74h,69h,63h
	DB	69h,70h,61h,6Eh,74h,0Ah,69h,6Eh
	DB	20h,74h,68h,65h,20h,70h,6Ch,6Fh
	DB	74h,2Eh,0Ah,0
_shd_str_empty_positively	DB	0
_shd_str_has_been_positively	DB	20h,68h,61h,73h,20h,62h,65h,65h
	DB	6Eh,20h,70h,6Fh,73h,69h,74h,69h
	DB	76h,65h,6Ch,79h,0Ah,69h,64h,65h
	DB	6Eh,74h,69h,66h,69h,65h,64h,20h
	DB	61h,73h,20h,0
_shd_str_newline_2	DB	0Ah,0
_shd_str_we_have_acquired	DB	57h,65h,20h,68h,61h,76h,65h,20h
	DB	61h,63h,71h,75h,69h,72h,65h,64h
	DB	20h,61h,0Ah,70h,68h,6Fh,74h,6Fh
	DB	67h,72h,61h,70h,68h,20h,6Fh,66h
	DB	20h,0
_shd_str_stop	DB	2Eh,0Ah,0
_shd_str_empty_spotted	DB	0
_shd_str_has_been_spotted	DB	20h,68h,61h,73h,20h,62h,65h,65h
	DB	6Eh,0Ah,73h,70h,6Fh,74h,74h,65h
	DB	64h,20h,69h,6Eh,20h,0
_shd_str_newline_3	DB	0Ah,0
_shd_str_empty_org	DB	0
_shd_str_has_been_identified_as_org	DB	20h,68h,61h,73h,20h,62h,65h,65h
	DB	6Eh,0Ah,69h,64h,65h,6Eh,74h,69h
	DB	66h,69h,65h,64h,20h,61h,73h,20h
	DB	61h,20h,6Dh,65h,6Dh,62h,65h,72h
	DB	0Ah,6Fh,66h,20h,74h,68h,65h,20h
	DB	0
_shd_str_newline_4	DB	0Ah,0
_shd_str_we_have_obtained	DB	57h,65h,20h,68h,61h,76h,65h,20h
	DB	6Fh,62h,74h,61h,69h,6Eh,65h,64h
	DB	0Ah,61h,64h,64h,69h,74h,69h,6Fh
	DB	6Eh,61h,6Ch,20h,69h,6Eh,66h,6Fh
	DB	72h,6Dh,61h,74h,69h,6Fh,6Eh,0Ah
	DB	63h,6Fh,6Eh,63h,65h,72h,6Eh,69h
	DB	6Eh,67h,20h,0
_shd_str_newline_5	DB	0Ah,0
_shd_str_we_have_determined_rank	DB	57h,65h,20h,68h,61h,76h,65h,20h
	DB	64h,65h,74h,65h,72h,6Dh,69h,6Eh
	DB	65h,64h,0Ah,74h,68h,65h,20h,72h
	DB	61h,6Eh,6Bh,20h,6Fh,66h,0Ah,0
_shd_str_newline_6	DB	0Ah,0
_shd_str_we_found_recruiting	DB	57h,65h,20h,66h,6Fh,75h,6Eh,64h
	DB	20h,72h,65h,63h,72h,75h,69h,74h
	DB	69h,6Eh,67h,0Ah,69h,6Eh,66h,6Fh
	DB	72h,6Dh,61h,74h,69h,6Fh,6Eh,20h
	DB	61h,62h,6Fh,75h,74h,0Ah,0
_shd_str_newline_7	DB	0Ah,0
_shd_str_we_found_recruiting_2	DB	57h,65h,20h,66h,6Fh,75h,6Eh,64h
	DB	20h,72h,65h,63h,72h,75h,69h,74h
	DB	69h,6Eh,67h,0Ah,69h,6Eh,66h,6Fh
	DB	72h,6Dh,61h,74h,69h,6Fh,6Eh,20h
	DB	61h,62h,6Fh,75h,74h,0Ah,0
_shd_str_newline_8	DB	0Ah,0
dat_str_recruit	DB	52h,65h,63h,72h,75h,69h,74h,0
dat_str_operative	DB	4Fh,70h,65h,72h,61h,74h,69h,76h
	DB	65h,0
dat_str_technician	DB	54h,65h,63h,68h,6Eh,69h,63h,69h
	DB	61h,6Eh,0
dat_str_agent	DB	41h,67h,65h,6Eh,74h,0
dat_str_organizer	DB	4Fh,72h,67h,61h,6Eh,69h,7Ah,65h
	DB	72h,0
dat_str_special_agent	DB	53h,70h,65h,63h,69h,61h,6Ch,20h
	DB	41h,67h,65h,6Eh,74h,0
dat_str_group_leader	DB	47h,72h,6Fh,75h,70h,20h,4Ch,65h
	DB	61h,64h,65h,72h,0
dat_str_mastermind_2	DB	4Dh,61h,73h,74h,65h,72h,4Dh,69h
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
	DB	74h,20h,23h,0,0
_shd_clue_kinds	DW	OFFSET DGROUP:dat_str_recruit
	DW	OFFSET DGROUP:dat_str_operative
	DW	OFFSET DGROUP:dat_str_technician
	DW	OFFSET DGROUP:dat_str_agent
	DW	OFFSET DGROUP:dat_str_organizer
	DW	OFFSET DGROUP:dat_str_special_agent
	DW	OFFSET DGROUP:dat_str_group_leader
	DW	OFFSET DGROUP:dat_str_mastermind_2
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
_shd_str_clue	DB	43h,6Ch,75h,65h,0
_shd_str_source_2	DB	87h,53h,6Fh,75h,72h,63h,65h,3Ah
	DB	20h,0
_shd_str_slash_source	DB	2Fh,0
_shd_str_newline_9	DB	0Ah,0
_shd_str_method_stop	DB	0Ah,87h,4Dh,65h,74h,68h,6Fh,64h
	DB	3Ah,20h,0
_shd_str_related_2	DB	8Ch,52h,65h,6Ch,61h,74h,65h,64h
	DB	20h,43h,6Ch,75h,65h,73h,3Ah,0
_shd_str_newline_10	DB	0Ah,0
_shd_str_none	DB	2Eh,2Eh,2Eh,6Eh,6Fh,6Eh,65h,0
asm_block_3c39	DB	0
_shd_clue_source	DW	OFFSET DGROUP:dat_str_clandestine_photo
	DW	OFFSET DGROUP:dat_str_electronic_wiretap
	DW	OFFSET DGROUP:dat_str_covert_surveillance
	DW	OFFSET DGROUP:dat_str_file_record_search
	DW	OFFSET DGROUP:dat_str_local_informant
	DW	OFFSET DGROUP:dat_str_interpol_data_base
	DW	OFFSET DGROUP:dat_str_local_authorities
dat_msg_key	DB	24h,4Bh,45h,59h,0
dat_msg_name	DB	24h,4Eh,41h,4Dh,45h,0
dat_msg_org	DB	24h,4Fh,52h,47h,0
dat_msg_city	DB	24h,43h,49h,54h,59h,0
dat_msg_role	DB	24h,52h,4Fh,4Ch,45h,0
_shd_key_clue	DB	2Ah,43h,30h,30h,30h,30h,0
_shd_str_clues_txt	DB	63h,6Ch,75h,65h,73h,2Eh,74h,78h
	DB	74h,0
asm_block_3c75	DB	0
_shd_clue_keys	DW	OFFSET DGROUP:dat_msg_key
	DW	OFFSET DGROUP:dat_msg_name
	DW	OFFSET DGROUP:dat_msg_org
	DW	OFFSET DGROUP:dat_msg_city
	DW	OFFSET DGROUP:dat_msg_role
_shd_str_period	DB	2Eh,0
_shd_str_face	DB	74h,68h,69h,73h,20h,66h,61h,63h
	DB	65h,2Eh,0
_shd_str_valkerie	DB	56h,61h,6Ch,6Bh,65h,72h,69h,65h
	DB	0
_shd_str_thunderbolt	DB	54h,68h,75h,6Eh,64h,65h,72h,62h
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
BLOCK_3DA7	DB	0
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
_shd_str_empty_message	DB	0
_shd_str_sloc00	DB	2Ah,53h,4Ch,4Fh,43h,30h,30h,0
_shd_str_text_dta_sloc	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_rloc00	DB	2Ah,52h,4Ch,4Fh,43h,30h,30h,0
_shd_str_text_dta_rloc	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_sorg00	DB	2Ah,53h,4Fh,52h,47h,30h,30h,0
_shd_str_text_dta_sorg	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_rorg00	DB	2Ah,52h,4Fh,52h,47h,30h,30h,0
_shd_str_text_dta_rorg	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_mark_80	DB	80h,0
_shd_str_text_dta_msg	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_mark_8f	DB	8Fh,0
_shd_str_fluf00	DB	2Ah,46h,4Ch,55h,46h,30h,30h,0
_shd_str_text_dta_fluf	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_alrt00	DB	2Ah,41h,4Ch,52h,54h,30h,30h,0
_shd_str_text_dta_help	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_aidd00	DB	2Ah,41h,49h,44h,44h,30h,30h,0
_shd_str_text_dta_aidd	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_text_dta_event	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_shd_str_msg0000	DB	2Ah,4Dh,53h,47h,30h,30h,30h,30h
	DB	0
_shd_str_facesf_pic	DB	66h,61h,63h,65h,73h,66h,2Eh,70h
	DB	69h,63h,0
_shd_str_faces_pic	DB	66h,61h,63h,65h,73h,2Eh,70h,69h
	DB	63h,0,0
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
_shd_str_agent_3	DB	41h,67h,65h,6Eh,74h,20h,41h,0
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
_shd_str_space_13	DB	20h,0,0
_shd_first_names	DW	OFFSET DGROUP:dat_str_georgina
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
_shd_last_names	DW	OFFSET DGROUP:dat_str_katkov
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
_shd_str_master_plan	DB	4Dh,61h,73h,74h,65h,72h,20h,50h
	DB	6Ch,61h,6Eh,0
_shd_str_secret	DB	2Dh,2Dh,53h,45h,43h,52h,45h,54h
	DB	2Dh,2Dh,0
_shd_str_arrested_upper	DB	41h,52h,52h,45h,53h,54h,45h,44h
	DB	0
_shd_str_hiding_upper	DB	49h,4Eh,20h,48h,49h,44h,49h,4Eh
	DB	47h,0
_shd_str_turned_upper	DB	20h,54h,55h,52h,4Eh,45h,44h,0
_shd_str_personnel_file	DB	50h,65h,72h,73h,6Fh,6Eh,6Eh,65h
	DB	6Ch,20h,46h,69h,6Ch,65h,0
_shd_str_action_team	DB	20h,41h,63h,74h,69h,6Fh,6Eh,20h
	DB	54h,65h,61h,6Dh,0
_shd_str_comma_3	DB	2Ch,20h,0
_shd_str_no_activity	DB	28h,4Eh,6Fh,20h,61h,63h,74h,69h
	DB	76h,69h,74h,79h,29h,0
asm_block_4705	DB	0
_shd_clock_text	DB	30h,30h,3Ah,30h,30h,3Ah,30h,30h
	DB	0
asm_block_470f	DB	0
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
asm_block_4777	DB	0
_shd_str_one_moment_please	DB	4Fh,6Eh,65h,20h,6Dh,6Fh,6Dh,65h
	DB	6Eh,74h,20h,70h,6Ch,65h,61h,73h
	DB	65h,2Eh,2Eh,2Eh,0
_shd_str_sure_want_quit_no_2	DB	41h,72h,65h,20h,79h,6Fh,75h,20h
	DB	73h,75h,72h,65h,0Ah,79h,6Fh,75h
	DB	20h,77h,61h,6Eh,74h,20h,74h,6Fh
	DB	20h,51h,75h,69h,74h,3Fh,0Ah,20h
	DB	4Eh,6Fh,0Ah,20h,59h,65h,73h,0Ah
	DB	0
dat_str_pani	DB	50h,41h,4Eh,49h,0
asm_block_47bb	DB	0
_shd_city_on_screen	DB	0FFh,0FFh
_shd_drive	DB	0FFh,0FFh
_shm_pan_width	DB	40h,1
asm_block_47c2	DB	1,0
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
asm_block_47fb	DB	0
_shm_pan_building	DB	0,0
_shd_str_animation_pan	DB	61h,6Eh,69h,6Dh,61h,74h,69h,6Fh
	DB	6Eh,2Eh,70h,61h,6Eh,0
_shd_joystick_dirs	DB	8,0,7,0,6,0,1,0
	DB	0FFh,0FFh,5,0,2,0,3,0
	DB	4,0
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
dat_str_hq_pan	DB	68h,71h,2Eh,70h,61h,6Eh,0
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
	DW	OFFSET DGROUP:dat_str_hq_pan
_shd_disk_letter	DB	41h,0
dat_str_pani_2	DB	50h,41h,4Eh,49h,0
asm_block_4ad7	DB	0
dat_anim_page_port	DB	0,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
dat_anim_page_2_port	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_shd_anim_page	DW	OFFSET DGROUP:dat_anim_page_port
_shd_anim_page_2	DW	OFFSET DGROUP:dat_anim_page_2_port
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
asm_block_4b45	DB	0
dat_screen_port	DB	0,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,1,0,0Fh,0,4,0
	DB	0,0
_shd_screen	DW	OFFSET DGROUP:dat_screen_port
drv_DAT_20d8_4b5a	DB	0
drv_DAT_20d8_4b5b	DB	0
drv_DAT_20d8_4b5c	DB	0,0
drv_DAT_20d8_4b5e	DB	0,0
drv_DAT_20d8_4b60	DB	0,0
drv_DAT_20d8_4b62	DB	0,0
drv_DAT_20d8_4b64	DB	0,0
drv_DAT_20d8_4b66	DB	0,0
drv_DAT_20d8_4b68	DB	0,0
drv_DAT_20d8_4b6a	DB	0,0
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
asm_block_4c86	DB	0
drv_DAT_20d8_4c87	DB	0,0
drv_DAT_20d8_4c89	DB	0,0
drv_DAT_20d8_4c8b	DB	0,0
drv_DAT_20d8_4c8d	DB	0,0
drv_DAT_20d8_4c8f	DB	0FFh,0FFh
asm_block_4c91	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
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
	DB	0FFh,0FFh,0FFh,0FFh
drv_DAT_20d8_4e45	DB	0FFh,0FFh
drv_DAT_20d8_4e47	DB	0,0
asm_block_4e49	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
drv_DAT_20d8_4fff	DB	0,0
drv_DAT_20d8_5001	DB	0,0
drv_DAT_20d8_5003	DB	0FFh,0FFh
drv_DAT_20d8_5005	DB	0,0
drv_DAT_20d8_5007	DB	0,0
drv_DAT_20d8_5009	DB	0,0
asm_block_500b	DB	0
drv_DAT_20d8_500c	DB	0
drv_DAT_20d8_500d	DB	0,0
drv_DAT_20d8_500f	DB	0,0
drv_DAT_20d8_5011	DB	0,0
drv_DAT_20d8_5013	DB	0,0
drv_DAT_20d8_5015	DB	3Fh,1
drv_DAT_20d8_5017	DB	6Fh,0
asm_block_5019	DB	0
drv_DAT_20d8_501a	DB	0FFh,0FFh
drv_DAT_20d8_501c	DB	0FFh,0FFh
drv_DAT_20d8_501e	DB	0,0
drv_DAT_20d8_5020	DB	0,0
addr_page_row_tables	DW	OFFSET DGROUP:asm_page_row_left_0
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
drv_DAT_20d8_566a	DB	0,0
drv_DAT_20d8_566c	DB	0,0
drv_DAT_20d8_566e	DB	0,0
drv_DAT_20d8_5670	DB	0,0
drv_DAT_20d8_5672	DB	0,0
drv_DAT_20d8_5674	DB	0,0
drv_DAT_20d8_5676	DB	0,0
drv_DAT_20d8_5678	DB	0,0
drv_DAT_20d8_567a	DB	0,0
drv_DAT_20d8_567c	DB	0,0
drv_DAT_20d8_567e	DB	0,0
drv_DAT_20d8_5680	DB	0,0

_DATA	ENDS

CONST0	SEGMENT	WORD PUBLIC 'CONST'
asm_seg_const0	DB	3,0,3,0

CONST0	ENDS

CONST	SEGMENT	WORD PUBLIC 'CONST'
; The two bytes are the C object's: the far buffer's segment.
CONST	ENDS

CONST2	SEGMENT	WORD PUBLIC 'CONST'
_shm_anim_magic	DB	3,0

CONST2	ENDS

_BSS	SEGMENT	WORD PUBLIC 'BSS'
asm_block_5c96	DB	0
asm_block_5c97	DB	0
asm_block_5c98	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
_shm_field_cursor	DB	0,0
_shm_field_char_width	DB	0,0
_shm_field_cursor_x	DB	0,0
_asm_number_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_number_digits_2	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_number_digits_3	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_number_digits_4	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_number_digits_5	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_clue_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_message_key	DB	0,0,0,0,0,0,0,0
	DB	0
asm_block_5d45	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0
_shm_active_pan	DW	0h		; the library's
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
asm_block_5d84	DB	0,0,0,0,0,0,0,0
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
asm_block_5ddc	DB	0,0,0,0
_shm_slot_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_save_loading	DB	0,0
_shm_save_errno	DB	0,0
_shm_slot_fd	DB	0,0
_shm_slot_word	DB	0,0
_shm_save_block	DB	0,0,0,0
asm_block_5dfc	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_save_offset	DB	0,0
_shm_save_fd	DB	0,0
asm_block_5e10	DB	0,0,0,0,0,0,0,0
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
asm_block_5e53	DB	0
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
_shm_source_fd	DB	0,0
_shm_source_dst	DB	0,0
_shm_source_src	DB	0,0
drv_DAT_20d8_5f9a	DB	0,0
drv_DAT_20d8_5f9c	DB	0
drv_DAT_20d8_5f9d	DB	0,0
drv_DAT_20d8_5f9f	DB	0
asm_block_5fa0	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
drv_DAT_20d8_77a0	DB	0,0
drv_DAT_20d8_77a2	DB	0,0
drv_DAT_20d8_77a4	DB	0
drv_DAT_20d8_77a5	DB	0
drv_DAT_20d8_77a6	DB	0
drv_DAT_20d8_77a7	DB	0
drv_DAT_20d8_77a8	DB	0,0
drv_DAT_20d8_77aa	DB	0,0
drv_DAT_20d8_77ac	DB	0,0
drv_DAT_20d8_77ae	DB	0
drv_DAT_20d8_77af	DB	0
drv_DAT_20d8_77b0	DB	0,0
drv_DAT_20d8_77b2	DB	0
asm_block_77b3	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
D28962	DB	200h DUP(?)
_asm_report_slots	DB	2 DUP(?)
asm_block_7de4	DB	2 DUP(?)
_shm_difficulty	DB	2 DUP(?)
asm_block_7de8	DB	2 DUP(?)
_asm_case_day	DB	2 DUP(?)
_asm_career_cursor	DB	2 DUP(?)
_asm_report_topics	DB	2 DUP(?)
_shm_clock_minutes	DB	2 DUP(?)
_shm_campaign	DB	28Eh DUP(?)
_shm_seed	DB	2 DUP(?)
_asm_screen_sprite_a	DB	2 DUP(?)
_asm_scene_sprites	DB	0Ah DUP(?)
_asm_screen_sprite_c	DB	2 DUP(?)
_shm_options	DB	2 DUP(?)
_shm_cga	DB	2 DUP(?)
asm_block_8094	DB	1FAh DUP(?)
_asm_DAT_20d8_828e	DB	2 DUP(?)
asm_block_8290	DB	4 DUP(?)
_shm_cities	DB	220h DUP(?)
_shm_menu_tick	DB	2 DUP(?)
_shm_suspect_count	DB	2 DUP(?)
_shm_log	DB	700h DUP(?)
_shm_menu_face	DB	2 DUP(?)
_shm_mouse_regs	DB	0Eh DUP(?)
_shm_wire_clue_source	DB	2 DUP(?)
_shm_crime_events	DB	0B00h DUP(?)
_shm_log_count	DB	2 DUP(?)
_shm_menu_first_line	DB	2 DUP(?)
asm_block_96ce	DB	2 DUP(?)
_shm_building_count	DB	2 DUP(?)
_shm_case_tick	DB	2 DUP(?)
_shm_frame_ticks	DB	2 DUP(?)
_asm_shown_count	DB	2 DUP(?)
_shm_source_at	DB	2 DUP(?)
_shm_case_city_1	DB	2 DUP(?)
_shm_case_city_2	DB	2 DUP(?)
_shm_anim_more	DB	2 DUP(?)
	PUBLIC	__bufin
__bufin	LABEL	BYTE
asm_block_96e0	DB	200h DUP(?)
_shm_pan_playing	DB	2 DUP(?)
_shm_anim_palette	DB	306h DUP(?)
_asm_report_total	DB	2 DUP(?)
_asm_case_minute	DB	2 DUP(?)
_shm_menu_no_pick	DB	2 DUP(?)
_asm_DAT_20d8_9bee	DB	2 DUP(?)
_shm_probed_campaign	DB	28Eh DUP(?)
_shm_menu_items	DB	2 DUP(?)
_shm_anim_segment	DB	2 DUP(?)
_asm_case_hour	DB	2 DUP(?)
_shm_seq_ticks	DB	2 DUP(?)
_asm_DAT_20d8_9e86	DB	2 DUP(?)
_shm_crime_event_count	DB	2 DUP(?)
_shm_case_seed	DB	2 DUP(?)
_shm_clue_method	DB	2 DUP(?)
_shm_menu_relayout	DB	2 DUP(?)
_shm_mission	DB	2 DUP(?)
_shm_menu_colour_bar	DB	2 DUP(?)
_shm_case_org_1	DB	2 DUP(?)
_shm_menu_text_width	DB	2 DUP(?)
_shm_case_org_2	DB	2 DUP(?)
asm_block_9e9a	DB	2 DUP(?)
_shm_faces_sprites	DB	0E8h DUP(?)
asm_block_9f84	DB	8 DUP(?)
_shm_global_alert_level	DB	2 DUP(?)
_shm_slots_filled	DB	2 DUP(?)
_shm_regs	DB	0Eh DUP(?)
_shm_anim_error	DB	2 DUP(?)
_shm_double_agent_cities	DB	2 DUP(?)
_shm_crime_role_count	DB	2 DUP(?)
_shm_menu_marked	DB	2 DUP(?)
_shm_crime_roles	DB	600h DUP(?)
_asm_fresh_start	DB	2 DUP(?)
_shm_seq_done	DB	2 DUP(?)
_shm_refill	DB	2 DUP(?)
_asm_DAT_20d8_a5ac	DB	2 DUP(?)
_shm_archive_buffer	DB	200h DUP(?)
_shm_menu_face_x	DB	2 DUP(?)
_shm_menu_draw_only	DB	2 DUP(?)
_shm_skills	DB	2 DUP(?)
_shm_mouse_buttons	DB	2 DUP(?)
_shm_mouse_x	DB	2 DUP(?)
_shm_mouse_y	DB	2 DUP(?)
_shm_mouse_count	DB	2 DUP(?)
_shm_menu_face_y	DB	2 DUP(?)
_shm_orgs	DB	240h DUP(?)
_shm_anim_sprites	DB	1F4h DUP(?)
asm_block_abf2	DB	2 DUP(?)
_shm_anim_name	DB	2 DUP(?)
_asm_case_mastermind	DB	2 DUP(?)
_shm_finished	DB	2 DUP(?)
_asm_case_flags	DB	2 DUP(?)
_shm_menu_shortcut	DB	20h DUP(?)
_shm_menu_pick	DB	2 DUP(?)
_asm_case_city_3	DB	2 DUP(?)
_shm_crime_block	DB	48h DUP(?)
_asm_masterminds_arrested	DB	2 DUP(?)
_shm_menu_right	DB	2 DUP(?)
_shm_substitute_tail	DB	100h DUP(?)
_shm_role_scan_states	DB	0C0h DUP(?)
_shm_graphics_letter	DB	1 DUP(?)
asm_block_ae2d	DB	1 DUP(?)
_shm_menu_bottom	DB	2 DUP(?)
_shm_seq_stop_asked	DB	2 DUP(?)
_asm_set_first	DB	2 DUP(?)
asm_block_ae34	DB	2 DUP(?)
_shm_case_city	DB	2 DUP(?)
_shm_activity	DB	40h DUP(?)
_shm_orgs_known	DB	2 DUP(?)
_asm_dossier_seen	DB	2 DUP(?)
	PUBLIC	__buferr
__buferr	LABEL	BYTE
asm_block_ae7c	DB	200h DUP(?)
_shm_slot_pick	DB	2 DUP(?)
_shm_case_spare_2	DB	2 DUP(?)
_shm_anim_row_2	DB	140h DUP(?)
_asm_fame	DB	108h DUP(?)
asm_block_b2c8	DB	40h DUP(?)
_asm_case_points	DB	2 DUP(?)
_shm_anim_block_kind	DB	2 DUP(?)
_asm_grid_in_play	DB	2 DUP(?)
_shm_seq_vars	DB	66h DUP(?)
_shm_case_org	DB	2 DUP(?)
asm_block_b376	DB	0Ah DUP(?)

c_common	ENDS

	END
