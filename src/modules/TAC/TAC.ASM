	PAGE	60,132
	TITLE	TAC
;
; TAC.ASM -- the assembly side of TAC.EXE.
;
; A SPLIT marker stands where a routine is in C; the build cuts the
; assembly there.
;

	EXTRN	_c_hook_hand_back:PROC
	EXTRN	_c_sound_command:PROC
	EXTRN	_c_set_display_page:PROC
	EXTRN	_c_set_palette_entry:PROC
	EXTRN	_c_sign:PROC
	EXTRN	_c_set_palette_record:PROC
	EXTRN	_c_hook_repaint:PROC
	EXTRN	_c_place_player:PROC
	EXTRN	_c_tick:PROC
	EXTRN	_c_player_move:PROC
	EXTRN	_c_draw_cast:PROC
	EXTRN	_c_resolve_shot:PROC
	EXTRN	_c_add_grenade:PROC
	EXTRN	_c_step_effects:PROC
	EXTRN	_c_board_dot:PROC
	EXTRN	_c_guard_knocked_down:PROC
	EXTRN	_c_primary_interact:PROC
	EXTRN	_c_aim_cursor:PROC
	EXTRN	_c_take_photo:PROC
	EXTRN	_c_plant_bug:PROC
	EXTRN	_c_secondary_interact:PROC
	EXTRN	_c_draw_status:PROC
	EXTRN	_c_write_centred:PROC
	EXTRN	_c_ask_menu:PROC
	EXTRN	_c_end_break_in:PROC
	EXTRN	_c_give_tip:PROC
	EXTRN	_c_pick_password:PROC
	EXTRN	_c_reveal_letter:PROC
	EXTRN	_c_ask_password:PROC
	EXTRN	_c_question_panel:PROC
	EXTRN	_c_search_names:PROC
	EXTRN	_c_type_message:PROC
	EXTRN	_c_text_field_draw:PROC
	EXTRN	_c_hook_message:PROC
	EXTRN	_c_view_save:PROC
	EXTRN	_c_view_restore:PROC
	EXTRN	_c_lay_out_building:PROC
	EXTRN	_c_clear_floor:PROC
	EXTRN	_c_run_walls:PROC
	EXTRN	_c_number_rooms:PROC
	EXTRN	_c_cut_doorways:PROC
	EXTRN	_c_pick_rooms:PROC
	EXTRN	_c_scrap_room:PROC
	EXTRN	_c_furnish_room:PROC
	EXTRN	_c_set_wall:PROC
	EXTRN	_c_draw_plan:PROC
	EXTRN	_c_draw_room:PROC
	EXTRN	_c_draw_cell:PROC
	EXTRN	_c_cheap_distance:PROC
	EXTRN	_c_draw_sprite:PROC
	EXTRN	_c_draw_tile_2:PROC
	EXTRN	_c_load_tiles:PROC
	EXTRN	_c_guard_turn:PROC
	EXTRN	_c_next_room:PROC
	EXTRN	_c_room_cost:PROC
	EXTRN	_c_room_distances:PROC
	EXTRN	_c_doorway_cell:PROC
	EXTRN	_c_flood_path:PROC
	EXTRN	_c_place_person:PROC
	EXTRN	_c_guard_sees:PROC
	EXTRN	_c_guard_sees_player:PROC
	EXTRN	_c_line_of_sight:PROC
	EXTRN	_c_guard_alertness:PROC
	EXTRN	_c_octant:PROC
	EXTRN	_c_facing8:PROC
	EXTRN	_c_kit_screen:PROC
	EXTRN	_c_clock_draw:PROC
	EXTRN	_c_refresh_kit:PROC
	EXTRN	_c_draw_kit_panel:PROC
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
	EXTRN	_c_save_put:PROC
	EXTRN	_c_put_section:PROC
	EXTRN	_c_get_section:PROC
	EXTRN	_c_save_get:PROC
	EXTRN	_c_want_disk:PROC
	EXTRN	_c_seq_start:PROC
	EXTRN	_c_seq_step:PROC
	EXTRN	_c_seq_stop:PROC
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
	PUBLIC	_dat_room_kinds
	PUBLIC	_dat_floor_objects
	PUBLIC	_dat_move_dx
	PUBLIC	_dat_move_dy
	PUBLIC	_dat_step_dx
	PUBLIC	_dat_step_dy
	PUBLIC	_dat_side_dx
	PUBLIC	_dat_side_dy
	PUBLIC	_asm_status_page
	PUBLIC	_dat_cast_frames
	PUBLIC	_asm_saved_page
	PUBLIC	_shm_suspects
	PUBLIC	_shm_buildings
	PUBLIC	_shm_clues_shown
	PUBLIC	_shm_jailbreak_suspect
	PUBLIC	_shd_map_page
	PUBLIC	_asm_game_speed
	PUBLIC	_dat_room_mask
	PUBLIC	_shd_pan_disk
	PUBLIC	_asm_page_3
	PUBLIC	_asm_facing
	PUBLIC	_asm_facing_goal
	PUBLIC	_dat_joystick_keys
	PUBLIC	_asm_shot_fired
	PUBLIC	_dat_meter_colours
	PUBLIC	_dat_tip_items
	PUBLIC	_dat_wall_tiles
	PUBLIC	_dat_step_facing
	PUBLIC	_dat_no_room
	PUBLIC	_addr_kit_names
	PUBLIC	_dat_kit_boxes
	PUBLIC	_dat_kit_points
	PUBLIC	_dat_kit_sprite_rects
	PUBLIC	_dat_kit_slot_rects
	PUBLIC	_shd_clue_phrases
	PUBLIC	_shd_scan_counts
	PUBLIC	_shd_month_names
	PUBLIC	_shd_clue_kinds
	PUBLIC	_shd_clue_source
	PUBLIC	_shd_subst_values
	PUBLIC	_shd_first_names
	PUBLIC	_shd_last_names
	PUBLIC	_shd_clock_text
	PUBLIC	_shd_city_on_screen
	PUBLIC	_shd_drive
	PUBLIC	_shm_pan_width
	PUBLIC	_shm_pan_building
	PUBLIC	_shd_joystick_dirs
	PUBLIC	_shd_disk_names
	PUBLIC	_shd_disk_letter
	PUBLIC	_shd_screen
	PUBLIC	_shd_archive_buffer_end
	PUBLIC	_shd_archive_fd
	PUBLIC	_asm_regs
	PUBLIC	_asm_blip_x
	PUBLIC	_asm_blip_y
	PUBLIC	_asm_cast_x
	PUBLIC	_asm_cast_y
	PUBLIC	_asm_signs_here
	PUBLIC	_asm_disguise_label_shown
	PUBLIC	_asm_gas_label_shown
	PUBLIC	_asm_move_cost
	PUBLIC	_asm_direction_keycode
	PUBLIC	_asm_shooter
	PUBLIC	_asm_flash_x
	PUBLIC	_asm_flash_y
	PUBLIC	_shm_field_cursor
	PUBLIC	_shm_field_char_width
	PUBLIC	_shm_field_cursor_x
	PUBLIC	_asm_room_doorways
	PUBLIC	_asm_step_map
	PUBLIC	_asm_last_grenade_tick
	PUBLIC	_asm_path_queue_col
	PUBLIC	_asm_path_queue_row
	PUBLIC	_shm_active_pan
	PUBLIC	_shm_menu_line_start
	PUBLIC	_shm_menu_colour_plain
	PUBLIC	_shm_menu_colour_item
	PUBLIC	_shm_menu_lines
	PUBLIC	_shm_menu_colour_pick
	PUBLIC	_shm_save_block
	PUBLIC	_shm_save_offset
	PUBLIC	_shm_save_fd
	PUBLIC	_shm_source_fd
	PUBLIC	_shm_source_dst
	PUBLIC	_shm_source_src
	PUBLIC	_shm_sprite_width
	PUBLIC	_shm_sprite_height
	PUBLIC	_shm_palette_count
	PUBLIC	_asm_org_alert_level
	PUBLIC	_asm_photo_score
	PUBLIC	_shm_joystick
	PUBLIC	_asm_clips_left
	PUBLIC	_asm_palette_flash
	PUBLIC	_shm_scratch
	PUBLIC	_asm_guard_seen
	PUBLIC	_asm_disguised
	PUBLIC	_asm_night
	PUBLIC	_shm_difficulty
	PUBLIC	_asm_panel_x
	PUBLIC	_asm_panel_y
	PUBLIC	_shm_clock_minutes
	PUBLIC	_asm_guard_alert
	PUBLIC	_asm_jump_ticks
	PUBLIC	_asm_floor_map
	PUBLIC	_asm_guard_room
	PUBLIC	_asm_guards_at_target
	PUBLIC	_asm_crouch_walk_ticks
	PUBLIC	_asm_shot_timer
	PUBLIC	_asm_rounds_left
	PUBLIC	_asm_doorways
	PUBLIC	_shm_campaign
	PUBLIC	_shm_seed
	PUBLIC	_shm_options
	PUBLIC	_asm_room_right
	PUBLIC	_shm_cga
	PUBLIC	_asm_radar_sprite
	PUBLIC	_asm_readout_sprite
	PUBLIC	_asm_kit
	PUBLIC	_asm_room_bottom
	PUBLIC	_asm_effect
	PUBLIC	_asm_grenades
	PUBLIC	_shm_cities
	PUBLIC	_asm_photos_taken
	PUBLIC	_asm_player_cell
	PUBLIC	_asm_kit_sprites
	PUBLIC	_asm_player_cell_row
	PUBLIC	_asm_rooms
	PUBLIC	_asm_room_seen_tick
	PUBLIC	_asm_room_seen
	PUBLIC	_shm_menu_tick
	PUBLIC	_shm_suspect_count
	PUBLIC	_asm_mission_kind
	PUBLIC	_shm_log
	PUBLIC	_shm_menu_face
	PUBLIC	_asm_throw_frames
	PUBLIC	_asm_bugs_planted
	PUBLIC	_asm_frame_tick
	PUBLIC	_shm_wire_clue_source
	PUBLIC	_shm_crime_events
	PUBLIC	_shm_log_count
	PUBLIC	_shm_menu_first_line
	PUBLIC	_asm_seen_longest
	PUBLIC	_asm_guard_sees
	PUBLIC	_asm_room_count
	PUBLIC	_asm_player_col
	PUBLIC	_shm_building_count
	PUBLIC	_asm_guard_in_room
	PUBLIC	_shm_case_tick
	PUBLIC	_asm_cursor_col
	PUBLIC	_asm_player_row
	PUBLIC	_asm_room_map
	PUBLIC	_asm_cursor_row
	PUBLIC	_asm_last_move_type
	PUBLIC	_asm_room_left
	PUBLIC	_asm_payload_room
	PUBLIC	_shm_source_at
	PUBLIC	_asm_room_top
	PUBLIC	_shm_case_city_1
	PUBLIC	_asm_guard_distances
	PUBLIC	_shm_case_city_2
	PUBLIC	_asm_ammunition
	PUBLIC	_shm_pan_playing
	PUBLIC	_asm_walked
	PUBLIC	_asm_bug_score
	PUBLIC	_shm_menu_no_pick
	PUBLIC	_shm_menu_items
	PUBLIC	_asm_crouched
	PUBLIC	_asm_hour
	PUBLIC	_asm_walk_frame
	PUBLIC	_asm_film_left
	PUBLIC	_shm_crime_event_count
	PUBLIC	_asm_high_security
	PUBLIC	_asm_alarm_sounded
	PUBLIC	_asm_bugs_left
	PUBLIC	_asm_guard_tick
	PUBLIC	_asm_player_x
	PUBLIC	_shm_case_seed
	PUBLIC	_shm_clue_method
	PUBLIC	_shm_menu_relayout
	PUBLIC	_asm_outcome
	PUBLIC	_asm_player_y
	PUBLIC	_shm_mission
	PUBLIC	_shm_menu_colour_bar
	PUBLIC	_asm_guard_turn_at
	PUBLIC	_shm_case_org_1
	PUBLIC	_shm_menu_text_width
	PUBLIC	_shm_case_org_2
	PUBLIC	_shm_faces_sprites
	PUBLIC	_asm_tile_sprites
	PUBLIC	_asm_suspect_here
	PUBLIC	_asm_room_last
	PUBLIC	_shm_global_alert_level
	PUBLIC	_shm_regs
	PUBLIC	_shm_double_agent_cities
	PUBLIC	_shm_crime_role_count
	PUBLIC	_shm_menu_marked
	PUBLIC	_shm_crime_roles
	PUBLIC	_shm_refill
	PUBLIC	_asm_DAT_20e3_c3f8
	PUBLIC	_shm_archive_buffer
	PUBLIC	_asm_view_left
	PUBLIC	_shm_menu_face_x
	PUBLIC	_shm_menu_draw_only
	PUBLIC	_shm_skills
	PUBLIC	_asm_view_top
	PUBLIC	_shm_menu_face_y
	PUBLIC	_shm_finished
	PUBLIC	_asm_target_room
	PUBLIC	_asm_people
	PUBLIC	_shm_menu_shortcut
	PUBLIC	_asm_belt_text
	PUBLIC	_shm_menu_pick
	PUBLIC	_asm_end_line
	PUBLIC	_shm_menu_right
	PUBLIC	_shm_role_scan_states
	PUBLIC	_asm_guards_awake
	PUBLIC	_asm_wounds
	PUBLIC	_shm_graphics_letter
	PUBLIC	_shm_menu_bottom
	PUBLIC	_asm_sound_arg_1
	PUBLIC	_asm_sound_arg_2
	PUBLIC	_asm_seen_count
	PUBLIC	_shm_case_city
	PUBLIC	_shm_activity
	PUBLIC	_shm_orgs_known
	PUBLIC	_shm_case_spare_2
	PUBLIC	_asm_difficulty_was
	PUBLIC	_asm_conspicuous
	PUBLIC	_asm_doorway_count
	PUBLIC	_asm_guards_to_come
	PUBLIC	_asm_wall_map
	PUBLIC	_shm_case_org
	PUBLIC	_drv_real_FUN_1000_0002
	PUBLIC	_drv_real_FUN_1000_00ca
	PUBLIC	_drv_jump_gfx_page_seg
	PUBLIC	_drv_jump_gfx_grab
	PUBLIC	_drv_jump_gfx_fill
	PUBLIC	_drv_jump_gfx_char_width
	PUBLIC	_drv_jump_gfx_pool_release
	PUBLIC	_drv_jump_gfx_free_page
	PUBLIC	_drv_jump_gfx_pool_alloc
	PUBLIC	_drv_jump_gfx_row_put
	PUBLIC	_drv_jump_gfx_copy_rect
	PUBLIC	_drv_jump_gfx_text
	PUBLIC	_drv_jump_gfx_set_page_seg
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
	PUBLIC	_shd_str_master_plan
	PUBLIC	_shd_str_personnel_file
	PUBLIC	_shm_orgs
	PUBLIC	_asm_password_hint
	PUBLIC	_shm_crime_block
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
	PUBLIC	_dat_str_bugged
	PUBLIC	_dat_str_room_already_bugged
	PUBLIC	_dat_str_nothing_bug
	PUBLIC	_shd_str_coded_message
	PUBLIC	_shd_str_meeting_notes
	PUBLIC	_shd_str_new_information
	PUBLIC	_shd_str_additional_information
	PUBLIC	_shd_str_of_the
	PUBLIC	_shd_str_has_been_identified_as
	PUBLIC	_shd_str_has_been_positively
	PUBLIC	_shd_str_we_have_acquired
	PUBLIC	_shd_str_has_been_spotted
	PUBLIC	_shd_str_has_been_identified_as_org
	PUBLIC	_shd_str_we_have_obtained
	PUBLIC	_shd_str_we_have_determined_rank
	PUBLIC	_shd_str_we_found_recruiting
	PUBLIC	_shd_str_we_found_recruiting_2
	PUBLIC	_shd_str_clue
	PUBLIC	_shd_str_none
	PUBLIC	_shd_str_clues_txt
	PUBLIC	_shd_str_clues_txt_2
	PUBLIC	_shd_str_message_not_decoded
	PUBLIC	_shd_str_more
	PUBLIC	_shd_str_facesf_pic
	PUBLIC	_shd_str_faces_pic
	PUBLIC	_dat_str_which_door
	PUBLIC	_dat_str_door_5
	PUBLIC	_dat_str_paused
	PUBLIC	_dat_str_sure_want_quit_no
	PUBLIC	_dat_str_overcome_by_gas_pass
	PUBLIC	_dat_str_slump_ground_overcome
	PUBLIC	_dat_str_prisoner_released_while
	PUBLIC	_dat_str_have_eliminated_all
	PUBLIC	_dat_str_quickly_slip_out
	PUBLIC	_shd_str_one_moment_please
	PUBLIC	_shd_str_sure_want_quit_no_2
	PUBLIC	_shd_str_briefing_pan
	PUBLIC	_shd_str_animation_pan
	PUBLIC	_shd_str_bld
	PUBLIC	_shd_str_env_sve_put
	PUBLIC	_shd_str_env_sve
	PUBLIC	_shd_str_file_error
	PUBLIC	_shd_str_hideout
	PUBLIC	_shd_str_agent
	PUBLIC	_shd_str_safehouse
	PUBLIC	_shd_str_active_cel
	PUBLIC	_shd_str_office
	PUBLIC	_shd_str_agent_3
	PUBLIC	_shd_str_secret
	PUBLIC	_shd_str_arrested_upper
	PUBLIC	_shd_str_hiding_upper
	PUBLIC	_shd_str_turned_upper
	PUBLIC	_shd_str_action_team
	PUBLIC	_shd_str_no_activity
	PUBLIC	_dat_str_text_dta
	PUBLIC	_dat_password_hint_initial
	PUBLIC	_dat_str_enter_password
	PUBLIC	_dat_str_access_confirmed
	PUBLIC	_dat_str_access_denied
	PUBLIC	_dat_str_nothing_photograph
	PUBLIC	_dat_str_already_photographed
	PUBLIC	_dat_str_photographed
	PUBLIC	_dat_str_open
	PUBLIC	_dat_str_first
	PUBLIC	_dat_str_out_film
	PUBLIC	_shd_str_please_insert_disk
	PUBLIC	_shd_str_if_3_5_insert
	PUBLIC	_shd_str_press_return_continue
	PUBLIC	_dat_str_search
	PUBLIC	_dat_str_has
	PUBLIC	_dat_str_no_operatives
	PUBLIC	_dat_str_has_no_operatives
	PUBLIC	_dat_str_now_2
	PUBLIC	_dat_str_no_data
	PUBLIC	_dat_str_gas
	PUBLIC	_dat_str_disguise
	PUBLIC	_dat_str_cia_agent
	PUBLIC	_dat_str_double_agent
	PUBLIC	_dat_str_now
	PUBLIC	_dat_str_find
	PUBLIC	_dat_str_has_been_identified_as
	PUBLIC	_dat_str_find_incriminating
	PUBLIC	_dat_str_into_double_agent
	PUBLIC	_dat_str_set_trap_cancel_remote
	PUBLIC	_dat_str_do_want_arrest
	PUBLIC	_dat_str_bug
	PUBLIC	_dat_str_photo
	PUBLIC	_dat_str_closed
	PUBLIC	_shd_str_mode_read_text
	PUBLIC	_shd_fmt_line
	PUBLIC	_shd_fmt_line_2
	PUBLIC	_shd_str_space_12
	PUBLIC	_shd_fmt_line_3
	PUBLIC	_shm_substitute_tail
	PUBLIC	_shd_str_empty_message
	PUBLIC	_shd_str_mark_80
	PUBLIC	_shm_message_key
	PUBLIC	_asm_number_digits
	PUBLIC	_shm_clue_digits
	PUBLIC	_shd_str_mark_8f
	PUBLIC	_dat_str_empty_17
	PUBLIC	_shd_str_space_after_name
	PUBLIC	_shd_str_dots
	PUBLIC	_shd_str_on
	PUBLIC	_shd_str_space_after_month
	PUBLIC	_shd_str_in
	PUBLIC	_shd_str_newline
	PUBLIC	_shd_str_empty_watch
	PUBLIC	_shd_str_space_face
	PUBLIC	_shd_str_in_2
	PUBLIC	_shd_str_empty_identified
	PUBLIC	_shd_str_empty_positively
	PUBLIC	_shd_str_newline_2
	PUBLIC	_shd_str_stop
	PUBLIC	_shd_str_empty_spotted
	PUBLIC	_shd_str_newline_3
	PUBLIC	_shd_str_empty_org
	PUBLIC	_shd_str_newline_4
	PUBLIC	_shd_str_newline_5
	PUBLIC	_shd_str_newline_6
	PUBLIC	_shd_str_newline_7
	PUBLIC	_shd_str_newline_8
	PUBLIC	_shd_str_source_2
	PUBLIC	_shd_str_slash_source
	PUBLIC	_shd_str_newline_9
	PUBLIC	_shd_str_method_stop
	PUBLIC	_shd_str_related_2
	PUBLIC	_shd_str_newline_10
	PUBLIC	_shd_clue_keys
	PUBLIC	_shd_colours_face
	PUBLIC	_shd_colours_screen
	PUBLIC	_shd_colours_screen_2
	PUBLIC	_dat_colours_badge
	PUBLIC	_dat_colours_tactical
	PUBLIC	_dat_str_empty_15
	PUBLIC	_asm_number_digits_3
	PUBLIC	_dat_str_newline_13
	PUBLIC	_asm_password_text
	PUBLIC	_shm_anim_row_2
	PUBLIC	_shd_palette_menu
	PUBLIC	_shd_palette_face
	PUBLIC	_shd_str_ok
	PUBLIC	_shd_str_newline_12
	PUBLIC	_shd_str_newline_wrap
	PUBLIC	_shd_str_ellipsis_2
	PUBLIC	_shd_str_space_13
	PUBLIC	_shd_str_comma_3
	PUBLIC	_dat_str_mode_read_text_2
	PUBLIC	_dat_fmt_word
	PUBLIC	_dat_fmt_word_2
	PUBLIC	_dat_str_empty_19
	PUBLIC	_shd_str_close_paren
	PUBLIC	_dat_str_a
	PUBLIC	_dat_str_newline_in
	PUBLIC	_dat_str_newline_14
	PUBLIC	_dat_str_newline_in_2
	PUBLIC	_dat_str_newline_15
	PUBLIC	_dat_str_bang
	PUBLIC	_dat_str_empty_20
	PUBLIC	_shd_palette_records
	PUBLIC	_dat_str_bang_2
	PUBLIC	_dat_str_bang_3
	PUBLIC	_dat_str_empty_18
	PUBLIC	_dat_str_empty_16
	PUBLIC	_dat_str_question
	PUBLIC	_dat_str_equip2_pic
	PUBLIC	_dat_str_camera_pic
	PUBLIC	_dat_str_guys3_pic
	PUBLIC	_dat_str_guys2_pic
	PUBLIC	_dat_str_equip1_pic
	PUBLIC	_dat_str_equip1m_pic
	PUBLIC	_dat_str_env_sve_2
	PUBLIC	_dat_str_env_sve
	PUBLIC	_dat_str_street
	PUBLIC	_dat_str_spritesf_pic
	PUBLIC	_dat_str_sprites_pic

; Every segment declared once, empty, so LINK sees them in this order.
CODE_0	SEGMENT	PARA PUBLIC 'CODE'
CODE_0	ENDS
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT	WORD PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT	WORD PUBLIC 'CONST'
CONST	ENDS
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

DGROUP	GROUP	_DATA,CONST,_BSS,c_common

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
	mov	word ptr ds:[DAT_20e3_0042],es
	mov	word ptr ds:[DAT_20e3_0044],bx
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
	mov	ds,word ptr ds:[DAT_20e3_0042]
	mov	dx,word ptr ds:[DAT_20e3_0044]
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
	cmp	byte ptr ds:[DAT_20e3_37b3],0
	jnz	L10169
	pop	word ptr cs:[L10164+3]
	jmp	short L10164
L10164:
	; The target is patched in by the POP above.
	jmp	dword ptr cs:[0]
L10169:
	mov	byte ptr ds:[DAT_20e3_37b2],1
	pop	word ptr cs:[L1017d+3]
	pop	word ptr ds:[DAT_20e3_37b4]
	pop	word ptr ds:[DAT_20e3_37b6]
	jmp	short L1017d
L1017d:
	; The target is patched in by the POP above.
	call	dword ptr cs:[0]
	dec	byte ptr ds:[DAT_20e3_37b2]
	jz	L10192
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[DAT_20e3_37b2],0
L10192:
	jmp	dword ptr ds:[DAT_20e3_37b4]
drv_real_dispatch	ENDP
D10196	DB	0,0

_drv_jump_gfx_page_seg	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_page_seg	ENDP
D1019d	DB	0,0,0EAh,0,0,0,0,0
	DB	0

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
D101b9	DB	0,0,0EAh,0,0,0,0

drv_jump_gfx_sprite_put_clipped	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
drv_jump_gfx_sprite_put_clipped	ENDP

_drv_jump_gfx_pool_release	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_pool_release	ENDP
D101ce	DB	0,0

_drv_jump_gfx_free_page	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_free_page	ENDP
D101d5	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0

drv_jump_gfx_overlay_remove	PROC	NEAR
	call	drv_real_dispatch
L101fb:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_overlay_remove	ENDP
D10206	DB	0,0,0EAh,0,0,0,0,0
	DB	0

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
	DB	0

_drv_jump_gfx_set_page_seg	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_set_page_seg	ENDP
D10245	DB	0,0,0EAh,0,0,0,0,0
	DB	0

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
	DB	0,0EAh,0,0,0,0,0,0

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
D102ed	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
	mov	word ptr ds:[DAT_20e3_37b8],dx
	mov	word ptr ds:[DAT_20e3_37ba],bx
	mov	ah,48h
	mov	bx,0FFFFh
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jc	L104c3
	mov	dx,OFFSET DGROUP:dat_message_pool
	jmp	drv_real_FUN_1000_055c
L104c3:
	mov	ah,48h
	sub	bx,100h
	mov	word ptr ds:[DAT_20e3_37be],bx
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jnc	L104d7
	mov	dx,OFFSET DGROUP:dat_str_ms_dos_lied_us
	jmp	drv_real_FUN_1000_055c
L104d7:
	mov	bx,OFFSET DGROUP:DAT_20e3_37c0
	mov	word ptr [bx],ax
	mov	word ptr [bx+2],ax
	mov	ax,4B03h
	mov	dx,word ptr ds:[DAT_20e3_37b8]
	push	ds
	pop	es
	mov	word ptr ds:[DAT_20e3_37bc],sp
	int	21h		; DOS AH=4Bh AL=03h: load overlay
	mov	dx,DGROUP
	mov	ds,dx
	mov	es,dx
	mov	ss,dx
	mov	sp,word ptr ds:[DAT_20e3_37bc]
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
	mov	es,word ptr ds:[DAT_20e3_37c0]
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
	cmp	bx,word ptr ds:[DAT_20e3_37be]
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
	mov	dx,word ptr ds:[DAT_20e3_37ba]
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
	mov	word ptr ds:[DAT_20e3_3c5b],si
	mov	cx,word ptr [bp+0Eh]
	shl	si,1
	lea	di,[DAT_20e3_38e7]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	mov	dx,cx
	rep stosw
	mov	cx,dx
	lea	di,[asm_block_38e9+438]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	add	ax,word ptr [bp+0Ch]
	dec	ax
	rep stosw
	mov	ax,word ptr [bp+10h]
	call	far ptr drv_jump_gfx_set_colour
	mov	ax,ds:[DAT_20e3_3c5b]
	mov	cx,ax
	add	cx,word ptr [bp+0Eh]
	dec	cx
	mov	word ptr ds:[DAT_20e3_3c5d],cx
	mov	bx,OFFSET DGROUP:DAT_20e3_38e7
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
	mov	ax,ds:[DAT_20e3_3c5b]
	mov	cx,word ptr ds:[DAT_20e3_3c5d]
	mov	bx,OFFSET DGROUP:DAT_20e3_38e7
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
	mov	di,word ptr ds:[DAT_20e3_3c5b]
	or	di,di
	js	L106bf
	mov	cx,word ptr ds:[DAT_20e3_3c5d]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,OFFSET DGROUP:DAT_20e3_38e7
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[DAT_20e3_3c5b],ax
	mov	cx,bx
	mov	di,dx
	add	di,OFFSET DGROUP:asm_block_38e9+438
	sub	ax,ax
	rep stosw
	mov	ds:[DAT_20e3_3c5d],ax
L106bf:
	ret
drv_real_FUN_1000_068a	ENDP

drv_real_FUN_1000_06c0	PROC	NEAR
	mov	ax,DGROUP
	mov	es,ax
	mov	cx,di
	or	si,si
	lea	di,[DAT_20e3_38e7]
	jz	L106d9
	cmp	si,word ptr ds:[DAT_20e3_3c6d]
	jnz	L1071a
	lea	di,[asm_block_38e9+438]
L106d9:
	cmp	cx,dx
	jge	L106df
	xchg	cx,dx
L106df:
	or	dx,dx
	jns	L106e5
	sub	dx,dx
L106e5:
	cmp	cx,word ptr ds:[DAT_20e3_3c6f]
	jle	L106ef
	mov	cx,word ptr ds:[DAT_20e3_3c6f]
L106ef:
	add	si,word ptr ds:[DAT_20e3_3c5f]
	add	cx,word ptr ds:[DAT_20e3_3c61]
	add	dx,word ptr ds:[DAT_20e3_3c61]
	cmp	cx,word ptr ds:[DAT_20e3_3c5d]
	jbe	L10705
	mov	word ptr ds:[DAT_20e3_3c5d],cx
L10705:
	cmp	dx,word ptr ds:[DAT_20e3_3c5b]
	jnc	L1070f
	mov	word ptr ds:[DAT_20e3_3c5b],dx
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

drv_real_FUN_1000_071b	PROC	NEAR
	sub	si,si
	or	bx,bx
	js	drv_real_FUN_1000_06c0
	mov	si,word ptr ds:[DAT_20e3_3c6d]
	cmp	bx,si
	jg	drv_real_FUN_1000_06c0
	ret
drv_real_FUN_1000_071b	ENDP

drv_real_FUN_1000_072a	PROC	NEAR
	mov	ax,ds:[DAT_20e3_3c5f]
	add	word ptr ds:[DAT_20e3_38df],ax
	add	word ptr ds:[DAT_20e3_38e1],ax
	mov	ax,ds:[DAT_20e3_3c61]
	add	word ptr ds:[DAT_20e3_38e3],ax
	add	word ptr ds:[DAT_20e3_38e5],ax
	mov	ax,ds:[DAT_20e3_38e1]
	cmp	ax,word ptr ds:[DAT_20e3_38df]
	jnc	L10762
	mov	bx,word ptr ds:[DAT_20e3_38df]
	mov	word ptr ds:[DAT_20e3_38e1],bx
	mov	ds:[DAT_20e3_38df],ax
	mov	ax,ds:[DAT_20e3_38e5]
	mov	bx,word ptr ds:[DAT_20e3_38e3]
	mov	word ptr ds:[DAT_20e3_38e5],bx
	mov	ds:[DAT_20e3_38e3],ax
L10762:
	mov	bx,word ptr ds:[DAT_20e3_38e1]
	sub	bx,word ptr ds:[DAT_20e3_38df]
	mov	word ptr ds:[asm_block_38e9+878],bx
	mov	ax,ds:[DAT_20e3_38e5]
	mov	dx,ax
	mov	cx,word ptr ds:[DAT_20e3_38e3]
	sub	ax,cx
	mov	bp,2
	jns	L10784
	xchg	cx,dx
	neg	bp
	neg	ax
L10784:
	mov	ds:[asm_block_38e9+880],ax
	cmp	dx,word ptr ds:[DAT_20e3_3c5d]
	jbe	L10791
	mov	word ptr ds:[DAT_20e3_3c5d],dx
L10791:
	cmp	cx,word ptr ds:[DAT_20e3_3c5b]
	jnc	L1079b
	mov	word ptr ds:[DAT_20e3_3c5b],cx
L1079b:
	cmp	ax,bx
	jnc	drv_real_FUN_1000_07ea
	mov	di,word ptr ds:[DAT_20e3_38e3]
	shl	di,1
	mov	ax,ds:[DAT_20e3_38df]
	mov	dx,word ptr ds:[asm_block_38e9+878]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[asm_block_38e9+880]
	jmp	L107cb
L107bc:
	cmp	ax,word ptr [di+asm_block_38e9+438]
	jbe	L107c6
	mov	word ptr [di+asm_block_38e9+438],ax
L107c6:
	inc	ax
	sub	bx,dx
	add	di,bp
L107cb:
	cmp	ax,word ptr [di+DAT_20e3_38e7]
	jnc	L107d5
	mov	word ptr [di+DAT_20e3_38e7],ax
L107d5:
	dec	cx
	js	L107df
	add	bx,si
	jns	L107bc
	inc	ax
	jmp	L107d5
L107df:
	cmp	ax,word ptr [di+asm_block_38e9+438]
	jbe	L107e9
	mov	word ptr [di+asm_block_38e9+438],ax
L107e9:
	ret
drv_real_FUN_1000_072a	ENDP

drv_real_FUN_1000_07ea	PROC	NEAR
	mov	di,word ptr ds:[DAT_20e3_38e3]
	shl	di,1
	mov	ax,ds:[DAT_20e3_38df]
	mov	dx,word ptr ds:[asm_block_38e9+880]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[asm_block_38e9+878]
L10804:
	cmp	ax,word ptr [di+DAT_20e3_38e7]
	jnc	L1080e
	mov	word ptr [di+DAT_20e3_38e7],ax
L1080e:
	cmp	ax,word ptr [di+asm_block_38e9+438]
	jbe	L10818
	mov	word ptr [di+asm_block_38e9+438],ax
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
	mov	ax,ds:[DAT_20e3_38df]
	mov	bx,word ptr ds:[DAT_20e3_38e3]
	mov	cx,word ptr ds:[DAT_20e3_38e1]
	mov	dx,word ptr ds:[DAT_20e3_38e5]
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
	mov	word ptr ds:[DAT_20e3_3c65],dx
	sar	dx,1
	mov	word ptr ds:[DAT_20e3_3c69],dx
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
	sar	word ptr ds:[DAT_20e3_3c65],1
	sar	word ptr ds:[DAT_20e3_3c69],1
	jmp	L1091b
L108be:
	jmp	L10880
L108c0:
	mov	cx,word ptr ds:[DAT_20e3_38df]
	mov	dx,word ptr ds:[DAT_20e3_38e3]
	mov	si,word ptr ds:[DAT_20e3_38e1]
	mov	di,word ptr ds:[DAT_20e3_38e5]
	mov	bx,cx
	mov	bp,dx
	call	drv_real_FUN_1000_09c4
	mov	ds:[DAT_20e3_3c64],al
	mov	bx,si
	mov	bp,di
	call	drv_real_FUN_1000_09c4
	jnz	L108fd
	cmp	byte ptr ds:[DAT_20e3_3c64],0
	jnz	L108ed
	jmp	L1085a
L108ed:
	xchg	cx,si
	xchg	dx,di
	xchg	byte ptr ds:[DAT_20e3_3c64],al
	mov	word ptr ds:[DAT_20e3_38df],cx
	mov	word ptr ds:[DAT_20e3_38e3],dx
L108fd:
	test	byte ptr ds:[DAT_20e3_3c64],al
	jnz	L108be
	mov	bp,dx
	mov	dx,si
	sub	dx,cx
	jo	L10892
	mov	word ptr ds:[DAT_20e3_3c65],dx
	sar	dx,1
	mov	word ptr ds:[DAT_20e3_3c69],dx
	mov	dx,di
	sub	dx,bp
	jo	L108b0
L1091b:
	mov	word ptr ds:[DAT_20e3_3c67],dx
	sar	dx,1
	mov	word ptr ds:[DAT_20e3_3c6b],dx
L10925:
	test	al,9
	jz	L10961
	sub	bx,bx
	or	si,si
	js	L10933
	mov	bx,word ptr ds:[DAT_20e3_3c6d]
L10933:
	mov	ax,bx
	sub	ax,cx
	imul	word ptr ds:[DAT_20e3_3c67]
	push	bx
	mov	bx,dx
	idiv	word ptr ds:[DAT_20e3_3c65]
	mov	bl,bh
	xor	bl,byte ptr ds:[DAT_20e3_3c65+1]
	jns	L1094d
	neg	dx
	dec	ax
L1094d:
	sub	dx,word ptr ds:[DAT_20e3_3c69]
	xor	dh,bh
	js	L10956
	inc	ax
L10956:
	pop	bx
	add	ax,bp
	js	L10969
	cmp	ax,word ptr ds:[DAT_20e3_3c6f]
	jle	L1099a
L10961:
	mov	bx,word ptr ds:[DAT_20e3_3c6f]
	cmp	di,bx
	jg	L1096b
L10969:
	sub	bx,bx
L1096b:
	mov	ax,bx
	sub	ax,bp
	imul	word ptr ds:[DAT_20e3_3c65]
	push	bx
	mov	bx,dx
L10976:
	idiv	word ptr ds:[DAT_20e3_3c67]
	mov	bl,bh
	xor	bl,byte ptr ds:[DAT_20e3_3c67+1]
	jns	L10985
	neg	dx
	dec	ax
L10985:
	sub	dx,word ptr ds:[DAT_20e3_3c6b]
	xor	dh,bh
	js	L1098e
	inc	ax
L1098e:
	pop	bx
	add	ax,cx
	js	L109ab
	cmp	ax,word ptr ds:[DAT_20e3_3c6d]
	jg	L109ab
	xchg	bx,ax
L1099a:
	cmp	byte ptr ds:[DAT_20e3_3c64],0
	jnz	L109ae
	mov	ds:[DAT_20e3_38e5],ax
	mov	word ptr ds:[DAT_20e3_38e1],bx
	jmp	L1085a
L109ab:
	jmp	L10880
L109ae:
	mov	ds:[DAT_20e3_38e3],ax
	mov	word ptr ds:[DAT_20e3_38df],bx
	xchg	cx,si
	xchg	bp,di
	mov	al,ds:[DAT_20e3_3c64]
	mov	byte ptr ds:[DAT_20e3_3c64],0
	jmp	L10925
drv_real_FUN_1000_0838	ENDP

drv_real_FUN_1000_09c4	PROC	NEAR
	mov	al,0Fh
	or	bx,bx
	js	L109cc
	and	al,0F7h
L109cc:
	cmp	bx,word ptr ds:[DAT_20e3_3c6d]
	jg	L109d4
	and	al,0FEh
L109d4:
	or	bp,bp
	js	L109da
	and	al,0FBh
L109da:
	cmp	bp,word ptr ds:[DAT_20e3_3c6f]
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
	mov	ax,ds:[DAT_20e3_3c67]
	jz	L109f5
	mov	ax,ds:[DAT_20e3_3c65]
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
	mov	ds:[DAT_20e3_3c6d],ax
	mov	ax,word ptr [bx+8]
	mov	ds:[DAT_20e3_3c6f],ax
	call	far ptr drv_jump_gfx_select_pic
	mov	ax,word ptr [bp+8]
	mov	ds:[DAT_20e3_38df],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[DAT_20e3_38e3],ax
	mov	ax,word ptr [bp+0Ch]
	mov	ds:[DAT_20e3_38e1],ax
	mov	ax,word ptr [bp+0Eh]
	mov	ds:[DAT_20e3_38e5],ax
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
	mov	ds:[DAT_20e3_8ba7],al
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
	mov	ds:[DAT_20e3_8ba7],al
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
	mov	byte ptr ds:[DAT_20e3_8b9c],0
	mov	byte ptr ds:[DAT_20e3_8b9d],0
	mov	ax,OFFSET DGROUP:asm_block_8bab+512
	mov	ds:[DAT_20e3_8b98],ax
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
	mov	ds:[DAT_20e3_8b9f],al
	mov	ds:[DAT_20e3_8ba4],ax
	mov	byte ptr ds:[DAT_20e3_8ba6],8
drv_real_FUN_1000_0b9b	ENDP

drv_real_FUN_1000_0bd9	PROC	NEAR
	mov	byte ptr ds:[DAT_20e3_8b9e],9
	mov	word ptr ds:[DAT_20e3_8ba0],1FFh
	mov	dx,100h
	mov	word ptr ds:[DAT_20e3_8ba2],dx
	mov	ax,0FFFFh
	xor	bx,bx
	mov	cx,800h
L10bf3:
	mov	word ptr [bx+DAT_20e3_7392],ax
	add	bx,3
	loop	L10bf3
	mov	al,0
	xor	bx,bx
	mov	cx,100h
L10c03:
	mov	byte ptr [bx+DAT_20e3_7394],al
	inc	al
	add	bx,3
	loop	L10c03
	ret
drv_real_FUN_1000_0bd9	ENDP

drv_real_FUN_1000_0c0f	PROC	NEAR
	cmp	byte ptr ds:[DAT_20e3_8ba7],0
	jz	L10c19
	inc	cx
	shr	cx,1
L10c19:
	mov	word ptr ds:[DAT_20e3_8b9a],cx
	mov	ax,ds:[DAT_20e3_8b98]
	mov	word ptr ds:[DAT_20e3_8b98],sp
	mov	sp,ax
	mov	dx,word ptr ds:[DAT_20e3_8ba2]
L10c2a:
	cmp	byte ptr ds:[DAT_20e3_8b9c],0
	jnz	L10c52
	call	drv_real_FUN_1000_0c8b
	cmp	al,90h
	jz	L10c3e
	mov	ds:[DAT_20e3_8b9d],al
	jmp	L10c59
L10c3e:
	call	drv_real_FUN_1000_0c8b
	or	al,al
	jnz	L10c4d
	mov	al,90h
	mov	ds:[DAT_20e3_8b9d],al
	jmp	L10c59
L10c4d:
	dec	al
	mov	ds:[DAT_20e3_8b9c],al
L10c52:
	mov	al,ds:[DAT_20e3_8b9d]
	dec	byte ptr ds:[DAT_20e3_8b9c]
L10c59:
	cmp	byte ptr ds:[DAT_20e3_8ba7],0
	jz	L10c76
	mov	ah,al
	and	al,0Fh
	shr	ah,1
	shr	ah,1
	shr	ah,1
	shr	ah,1
	stosw
	dec	word ptr ds:[DAT_20e3_8b9a]
	jnz	L10c2a
	jmp	L10c7d
L10c76:
	stosb
	dec	word ptr ds:[DAT_20e3_8b9a]
	jnz	L10c2a
L10c7d:
	mov	word ptr ds:[DAT_20e3_8ba2],dx
	mov	ax,ds:[DAT_20e3_8b98]
	mov	word ptr ds:[DAT_20e3_8b98],sp
	mov	sp,ax
	ret
drv_real_FUN_1000_0c0f	ENDP

drv_real_FUN_1000_0c8b	PROC	NEAR
	pop	bp
	cmp	sp,OFFSET DGROUP:asm_block_8bab+512
	jz	L10c95
L10c92:
	pop	ax
	jmp	bp
L10c95:
	mov	bx,word ptr ds:[DAT_20e3_8ba4]
	mov	cl,10h
	mov	ch,byte ptr ds:[DAT_20e3_8ba6]
	sub	cl,ch
	shr	bx,cl
	mov	cl,ch
L10ca5:
	cmp	cl,byte ptr ds:[DAT_20e3_8b9e]
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
	mov	ds:[DAT_20e3_8ba4],ax
	shl	ax,cl
	or	bx,ax
	add	cl,10h
	jmp	L10ca5
L10ccc:
	sub	cl,byte ptr ds:[DAT_20e3_8b9e]
	mov	byte ptr ds:[DAT_20e3_8ba6],cl
	mov	ax,bx
	and	ax,word ptr ds:[DAT_20e3_8ba0]
	mov	cx,ax
	cmp	ax,dx
	jl	L10cea
	mov	cx,dx
	mov	ax,ds:[DAT_20e3_8ba8]
	mov	bl,byte ptr ds:[DAT_20e3_8baa]
	push	bx
L10cea:
	mov	bx,ax
	add	bx,ax
	add	bx,ax
	mov	ax,word ptr [bx+DAT_20e3_7392]
	inc	ax
	jz	L10cff
	dec	ax
	mov	bl,byte ptr [bx+DAT_20e3_7394]
	push	bx
	jmp	L10cea
L10cff:
	mov	al,byte ptr [bx+DAT_20e3_7394]
	mov	ds:[DAT_20e3_8baa],al
	push	ax
	mov	bx,dx
	add	bx,dx
	add	bx,dx
	mov	byte ptr [bx+DAT_20e3_7394],al
	mov	ax,ds:[DAT_20e3_8ba8]
	mov	word ptr [bx+DAT_20e3_7392],ax
	inc	dx
	cmp	dx,word ptr ds:[DAT_20e3_8ba0]
	jle	L10d28
	inc	byte ptr ds:[DAT_20e3_8b9e]
	stc
	rcl	word ptr ds:[DAT_20e3_8ba0],1
L10d28:
	mov	al,ds:[DAT_20e3_8b9e]
	cmp	al,byte ptr ds:[DAT_20e3_8b9f]
	jle	L10d34
	call	drv_real_FUN_1000_0bd9
L10d34:
	mov	word ptr ds:[DAT_20e3_8ba8],cx
	jmp	L10c92
drv_real_FUN_1000_0c8b	ENDP
D10d3b	DB	0

drv_real_mouse_open	PROC	FAR
	xor	ax,ax
	mov	es,ax
	mov	bx,0CCh
	mov	ax,word ptr es:[bx]
	or	ax,word ptr es:[bx+2]
	jz	L10d8a
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
	or	ax,ax
	jz	L10d8a
	mov	ax,0Ch
	mov	cx,1Fh
	mov	dx,cs
	mov	es,dx
	lea	dx,[drv_real_mouse_event]
	int	33h		; mouse AX=000Ch: set user-defined event handler
	mov	ax,3
	int	33h		; mouse AX=0003h: get position and button status
	mov	word ptr ds:[DAT_20e3_3c80],0
	cmp	cx,0C8h
	jc	L10d7e
	shr	cx,1
	mov	word ptr ds:[DAT_20e3_3c80],1
L10d7e:
	mov	word ptr ds:[DAT_20e3_3c76],bx
	mov	word ptr ds:[DAT_20e3_3c72],cx
	mov	word ptr ds:[DAT_20e3_3c74],dx
L10d8a:
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
	jz	L10da5
	call	far ptr drv_real_FUN_1000_0dc4
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
L10da5:
	retf
drv_real_mouse_close	ENDP

drv_real_FUN_1000_0da6	PROC	FAR
	xor	ax,ax
	xchg	word ptr ds:[DAT_20e3_3c78],ax
	retf
drv_real_FUN_1000_0da6	ENDP

;------------------------------------------------------------------------------
; Set the cursor's hot spot and which shape to draw.
;------------------------------------------------------------------------------
drv_real_mouse_set_cursor	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	ds:[DAT_20e3_3c7c],ax
	mov	ax,word ptr [bp+8]
	mov	ds:[DAT_20e3_3c7e],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[DAT_20e3_3c7a],ax
	pop	bp
	retf
drv_real_mouse_set_cursor	ENDP

drv_real_FUN_1000_0dc4	PROC	FAR
	mov	byte ptr ds:[DAT_20e3_37b3],0
	call	far ptr drv_jump_gfx_overlay_remove
	retf
drv_real_FUN_1000_0dc4	ENDP

drv_real_cursor_show	PROC	FAR
	push	word ptr ds:[DAT_20e3_3c7a]
	mov	ax,ds:[DAT_20e3_3c74]
	sub	ax,word ptr ds:[DAT_20e3_3c7e]
	push	ax
	mov	ax,ds:[DAT_20e3_3c72]
	sub	ax,word ptr ds:[DAT_20e3_3c7c]
	push	ax
	call	far ptr drv_jump_gfx_overlay_put
	add	sp,6
	mov	byte ptr ds:[DAT_20e3_37b3],1
	retf
drv_real_cursor_show	ENDP

drv_real_mouse_int	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	bx,word ptr [bp+8]
	mov	cx,word ptr [bp+0Ah]
	mov	dx,word ptr [bp+0Ch]
	int	33h
	mov	ds:[DAT_20e3_3c82],ax
	mov	word ptr ds:[DAT_20e3_3c84],bx
	mov	word ptr ds:[DAT_20e3_3c86],cx
	mov	word ptr ds:[DAT_20e3_3c88],dx
	lea	ax,[DAT_20e3_3c82]
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
	push	word ptr ds:[DAT_20e3_3c7a]
	mov	ax,ds:[DAT_20e3_3c74]
	sub	ax,word ptr ds:[DAT_20e3_3c7e]
	push	ax
	mov	ax,ds:[DAT_20e3_3c72]
	sub	ax,word ptr ds:[DAT_20e3_3c7c]
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
	cmp	word ptr ds:[DAT_20e3_3c80],0
	jz	L10e57
	shr	cx,1
L10e57:
	or	word ptr ds:[DAT_20e3_3c78],bx
	mov	word ptr ds:[DAT_20e3_3c76],bx
	mov	word ptr ds:[DAT_20e3_3c72],cx
	mov	word ptr ds:[DAT_20e3_3c74],dx
	test	ax,1
	jz	L10e87
	cmp	byte ptr ds:[DAT_20e3_37b3],0
	jz	L10e87
	mov	al,2
	xchg	byte ptr ds:[DAT_20e3_37b2],al
	or	al,al
	jnz	L10e87
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[DAT_20e3_37b2],0
L10e87:
	retf
drv_real_mouse_event	ENDP

CODE_0	ENDS

;==============================================================================
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:_TEXT, ds:DGROUP, ss:DGROUP

;;SPLIT main

;;SPLIT FUN_10e8_063d

;;SPLIT FUN_10e8_0662

;;SPLIT FUN_10e8_0681

;;SPLIT FUN_10e8_06a0

;;SPLIT FUN_10e8_06d9

;;SPLIT FUN_10e8_06f6

;;SPLIT FUN_10e8_070d

;;SPLIT FUN_10e8_070e

;;SPLIT FUN_10e8_0bcb

;;SPLIT FUN_10e8_0f4c

;;SPLIT FUN_10e8_1b32

;;SPLIT FUN_10e8_225d

;;SPLIT FUN_10e8_2553

;;SPLIT FUN_10e8_26b0

;;SPLIT FUN_10e8_2c73

;;SPLIT FUN_10e8_2c8d

;;SPLIT FUN_10e8_2d10

;;SPLIT FUN_10e8_2fc9

;;SPLIT FUN_10e8_3081

;;SPLIT FUN_10e8_32e6

;;SPLIT FUN_10e8_33ca

;;SPLIT FUN_10e8_3407

;;SPLIT FUN_10e8_347c

;;SPLIT FUN_10e8_34c0

;;SPLIT FUN_10e8_34e2

;;SPLIT FUN_10e8_3573

;;SPLIT FUN_10e8_38bb

;;SPLIT FUN_10e8_39a1

;;SPLIT FUN_10e8_3a3e

;;SPLIT FUN_10e8_3b0b

;;SPLIT FUN_10e8_3c1c

;;SPLIT FUN_10e8_4078

;;SPLIT FUN_10e8_42d6

;;SPLIT FUN_10e8_4392

;;SPLIT FUN_10e8_44a1

;;SPLIT FUN_10e8_44c2

;;SPLIT FUN_10e8_44e4

;;SPLIT FUN_10e8_45da

;;SPLIT FUN_10e8_46cb

;;SPLIT FUN_10e8_4838

;;SPLIT FUN_10e8_4931

;;SPLIT FUN_10e8_4d3a

;;SPLIT FUN_10e8_4ead

;;SPLIT FUN_10e8_4f8d

;;SPLIT FUN_10e8_534f

;;SPLIT FUN_10e8_540c

;;SPLIT FUN_10e8_5674

;;SPLIT FUN_10e8_5962

;;SPLIT FUN_10e8_5ab6

;;SPLIT FUN_10e8_5aed

;;SPLIT FUN_10e8_5b0d

;;SPLIT FUN_10e8_5b2d

;;SPLIT FUN_10e8_5ca6

;;SPLIT FUN_10e8_6b78

;;SPLIT FUN_10e8_6c44

;;SPLIT FUN_10e8_6cb1

;;SPLIT FUN_10e8_6e34

;;SPLIT FUN_10e8_6ec9

;;SPLIT FUN_10e8_7155

;;SPLIT FUN_10e8_74ee

;;SPLIT FUN_10e8_757f

;;SPLIT FUN_10e8_7615

;;SPLIT FUN_10e8_7821

;;SPLIT FUN_10e8_78b2

;;SPLIT FUN_10e8_792e

;;SPLIT FUN_10e8_79ea

;;SPLIT FUN_10e8_7e0c

;;SPLIT FUN_10e8_7e6e

;;SPLIT FUN_10e8_7e72

;;SPLIT FUN_10e8_8106

;;SPLIT FUN_10e8_89f9

;;SPLIT FUN_10e8_8b31

;;SPLIT FUN_10e8_8b64

;;SPLIT FUN_10e8_8e52

;;SPLIT FUN_10e8_8eab

;;SPLIT FUN_10e8_8faf

;;SPLIT FUN_10e8_9050

;;SPLIT FUN_10e8_90b2

;;SPLIT FUN_10e8_9149

;;SPLIT FUN_10e8_9195

;;SPLIT FUN_10e8_94f3

;;SPLIT FUN_10e8_95a6

;;SPLIT FUN_10e8_9673

;;SPLIT FUN_10e8_96dc

;;SPLIT FUN_10e8_9713

;;SPLIT FUN_10e8_97c8

;;SPLIT FUN_10e8_984d

;;SPLIT FUN_10e8_986d

;;SPLIT FUN_10e8_9a3c

;;SPLIT FUN_10e8_a081

;;SPLIT FUN_10e8_a3aa

;;SPLIT FUN_10e8_a3c7

;;SPLIT FUN_10e8_a4b3

;;SPLIT FUN_10e8_a522

;;SPLIT FUN_10e8_a817

;;SPLIT FUN_10e8_a84c

;;SPLIT FUN_10e8_a8f1

;;SPLIT FUN_10e8_a948

;;SPLIT FUN_10e8_a9b8

;;SPLIT FUN_10e8_ab21

;;SPLIT FUN_10e8_ad31

;;SPLIT FUN_10e8_af1a

;;SPLIT FUN_10e8_af9e

;;SPLIT FUN_10e8_b089

;;SPLIT FUN_10e8_b16d

;;SPLIT FUN_10e8_b1e1

;;SPLIT FUN_10e8_b23d

;;SPLIT FUN_10e8_b2a2

;;SPLIT FUN_10e8_b321

;;SPLIT FUN_10e8_b3d4

;;SPLIT FUN_10e8_b41c

;;SPLIT FUN_10e8_b4a6

;;SPLIT FUN_10e8_b766

;;SPLIT FUN_10e8_b8ad

;;SPLIT FUN_10e8_b969

;;SPLIT FUN_10e8_b9f5

;;SPLIT FUN_10e8_ba3a

;;SPLIT FUN_10e8_baab

;;SPLIT FUN_10e8_bae6

;;SPLIT FUN_10e8_bfb5

;;SPLIT FUN_10e8_c366

;;SPLIT FUN_10e8_c3be

;;SPLIT FUN_10e8_c417

;;SPLIT FUN_10e8_c4d8

;;SPLIT FUN_10e8_c52a

;;SPLIT FUN_10e8_c65b

;;SPLIT FUN_10e8_c684

;;SPLIT FUN_10e8_c6b7

;;SPLIT FUN_10e8_c734

;;SPLIT FUN_10e8_c7b0

;;SPLIT FUN_10e8_c7d2

;;SPLIT FUN_10e8_cb07

;;SPLIT FUN_10e8_cb60

;;SPLIT FUN_10e8_cbb9

;;SPLIT FUN_10e8_cf7c

;;SPLIT FUN_10e8_d0ae

;;SPLIT FUN_10e8_d0af

;;SPLIT FUN_10e8_d0b0

;;SPLIT FUN_10e8_d0b2

;;SPLIT FUN_10e8_d0d2

;;SPLIT FUN_10e8_d0f3

;;SPLIT FUN_10e8_d11c

;;SPLIT FUN_10e8_d154

;;SPLIT FUN_10e8_d172

;;SPLIT FUN_10e8_d18e

;;SPLIT FUN_10e8_d1b8

;;SPLIT FUN_10e8_d1d2

;;SPLIT FUN_10e8_d1ec

;;SPLIT FUN_10e8_d203

;;SPLIT FUN_10e8_d21c

;;SPLIT FUN_10e8_d23a

;;SPLIT FUN_10e8_d29a

;;SPLIT FUN_10e8_d2c4

;;SPLIT FUN_10e8_d2e8

;;SPLIT FUN_10e8_d32c

;;SPLIT FUN_10e8_d372

;;SPLIT FUN_10e8_d3b4

;;SPLIT FUN_10e8_d418

;;SPLIT FUN_10e8_d458

;;SPLIT FUN_10e8_d4c4

;;SPLIT FUN_10e8_d4d6

;;SPLIT FUN_10e8_d532

;;SPLIT FUN_10e8_d596

;;SPLIT FUN_10e8_d5b4

;;SPLIT FUN_10e8_d5e8

;;SPLIT FUN_10e8_d5f8

;;SPLIT FUN_10e8_d620

;;SPLIT FUN_10e8_d642

;;SPLIT FUN_10e8_d672

;;SPLIT FUN_10e8_d6a2

;;SPLIT FUN_10e8_d6c8

;;SPLIT FUN_10e8_d788

_TEXT	ENDS

;==============================================================================
_DATA	SEGMENT	WORD PUBLIC 'DATA'
;==============================================================================
DAT_20e3_0042	DB	0,0
DAT_20e3_0044	DB	0,0
asm_block_0046	DB	0,0,3Fh,3Fh,3Fh,3Fh,3Fh,3Fh
	DB	3Fh,3Fh,3Fh,3Fh,3Fh,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
_dat_str_env_sve	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_camera_pic	DB	63h,61h,6Dh,65h,72h,61h,2Eh,70h
	DB	69h,63h,0
_dat_str_guys3_pic	DB	67h,75h,79h,73h,33h,2Eh,70h,69h
	DB	63h,0
_dat_str_guys2_pic	DB	67h,75h,79h,73h,32h,2Eh,70h,69h
	DB	63h,0
_dat_str_equip1_pic	DB	65h,71h,75h,69h,70h,31h,2Eh,70h
	DB	69h,63h,0
_dat_str_equip1m_pic	DB	65h,71h,75h,69h,70h,31h,6Dh,2Eh
	DB	70h,69h,63h,0
_dat_str_env_sve_2	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_room_kinds	DB	4Fh,66h,66h,69h,63h,65h,0,0		; ROOM_KIND[10]
	DB	0,0,0,0,0,0,0,0
	DB	4,0,2,0,7,0,46h,69h
	DB	6Ch,65h,20h,52h,6Fh,6Fh,6Dh,0
	DB	0,0,0,0,0,0,6,0
	DB	1,0,7,0,43h,6Fh,6Dh,70h
	DB	75h,74h,65h,72h,20h,52h,6Fh,6Fh
	DB	6Dh,0,0,0,8,0,4,0
	DB	7,0,43h,61h,66h,65h,74h,65h
	DB	72h,69h,61h,0,0,0,0,0
	DB	0,0,2,0,4,0,7,0
	DB	4Ch,6Fh,75h,6Eh,67h,65h,0,0
	DB	0,0,0,0,0,0,0,0
	DB	2,0,2,0,7,0,43h,69h
	DB	70h,68h,65h,72h,20h,52h,6Fh,6Fh
	DB	6Dh,0,0,0,0,0,0Ch,0
	DB	1,0,7,0,42h,65h,64h,20h
	DB	52h,6Fh,6Fh,6Dh,0,0,0,0
	DB	0,0,0,0,6,0,2,0
	DB	0,0,42h,61h,74h,68h,72h,6Fh
	DB	6Fh,6Dh,0,0,0,0,0,0
	DB	0,0,0Ch,0,1,0,7,0
	DB	4Bh,69h,74h,63h,68h,65h,6Eh,0
	DB	0,0,0,0,0,0,0,0
	DB	4,0,2,0,0,0,53h,74h
	DB	6Fh,72h,61h,67h,65h,20h,52h,6Fh
	DB	6Fh,6Dh,0,0,0,0,4,0
	DB	4,0,7,0
_dat_floor_objects	DB	57h,61h,6Ch,6Ch,0,0,0,0		; FLOOR_OBJECT[62]
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,57h,61h,6Ch,6Ch
	DB	0,0,0,0,0,0,0,0
	DB	10h,0,0,0,0,0,0,0
	DB	57h,61h,6Ch,6Ch,0,0,0,0
	DB	0,0,0,0,20h,0,0,0
	DB	0,0,0,0,57h,61h,6Ch,6Ch
	DB	0,0,0,0,0,0,0,0
	DB	30h,0,0,0,0,0,0,0
	DB	57h,61h,6Ch,6Ch,0,0,0,0
	DB	0,0,0,0,40h,0,0,0
	DB	0,0,0,0,57h,61h,6Ch,6Ch
	DB	0,0,0,0,0,0,0,0
	DB	50h,0,0,0,0,0,0,0
	DB	57h,61h,6Ch,6Ch,0,0,0,0
	DB	0,0,0,0,60h,0,0,0
	DB	0,0,0,0,57h,61h,6Ch,6Ch
	DB	0,0,0,0,0,0,0,0
	DB	70h,0,0,0,0,0,0,0
	DB	44h,6Fh,6Fh,72h,0,0,0,0
	DB	0,0,0,0,40h,0,10h,0
	DB	12h,0,0,0,44h,6Fh,6Fh,72h
	DB	0,0,0,0,0,0,0,0
	DB	50h,0,10h,0,12h,0,0,0
	DB	44h,6Fh,6Fh,72h,0,0,0,0
	DB	0,0,0,0,60h,0,10h,0
	DB	12h,0,0,0,44h,6Fh,6Fh,72h
	DB	0,0,0,0,0,0,0,0
	DB	70h,0,10h,0,12h,0,0,0
	DB	43h,68h,61h,69h,72h,0,0,0
	DB	0,0,0,0,80h,0,0,0
	DB	1,0,19h,2,43h,68h,61h,69h
	DB	72h,0,0,0,0,0,0,0
	DB	90h,0,0,0,1,0,18h,2
	DB	43h,68h,61h,69h,72h,0,0,0
	DB	0,0,0,0,0A0h,0,0,0
	DB	1,0,19h,2,43h,68h,61h,69h
	DB	72h,0,0,0,0,0,0,0
	DB	0B0h,0,0,0,1,0,18h,2
	DB	54h,65h,72h,6Dh,69h,6Eh,61h,6Ch
	DB	0,0,0,0,0C0h,0,0,0
	DB	1,2,25h,0,54h,79h,70h,65h
	DB	77h,72h,69h,74h,65h,72h,0,0
	DB	0D0h,0,0,0,5,0,3,0
	DB	54h,65h,72h,6Dh,69h,6Eh,61h,6Ch
	DB	0,0,0,0,0E0h,0,0,0
	DB	1,2,21h,0,54h,79h,70h,65h
	DB	77h,72h,69h,74h,65h,72h,0,0
	DB	0F0h,0,0,0,5,0,3,0
	DB	43h,68h,61h,69h,72h,0,0,0
	DB	0,0,0,0,0,1,0,0
	DB	1,0,45h,4,50h,6Ch,61h,6Eh
	DB	74h,0,0,0,0,0,0,0
	DB	10h,1,0,0,5,0,51h,4
	DB	43h,68h,61h,69h,72h,0,0,0
	DB	0,0,0,0,20h,1,0,0
	DB	1,0,45h,4,50h,6Ch,61h,6Eh
	DB	74h,0,0,0,0,0,0,0
	DB	30h,1,0,0,5,0,51h,4
	DB	46h,69h,6Ch,65h,73h,0,0,0
	DB	0,0,0,0,80h,0,10h,0
	DB	2Bh,1,7,2,46h,69h,6Ch,65h
	DB	73h,0,0,0,0,0,0,0
	DB	90h,0,10h,0,2Bh,1,27h,2
	DB	46h,69h,6Ch,65h,73h,0,0,0
	DB	0,0,0,0,0A0h,0,10h,0
	DB	2Bh,1,7,2,46h,69h,6Ch,65h
	DB	73h,0,0,0,0,0,0,0
	DB	0B0h,0,10h,0,2Bh,1,27h,2
	DB	46h,6Ch,6Fh,6Fh,72h,20h,53h,61h
	DB	66h,65h,0,0,0C0h,0,10h,0
	DB	2Bh,1,66h,0,57h,61h,6Ch,6Ch
	DB	20h,53h,61h,66h,65h,0,0,0
	DB	0D0h,0,10h,0,0Ah,1,23h,0
	DB	50h,69h,63h,74h,75h,72h,65h,0
	DB	0,0,0,0,0E0h,0,10h,0
	DB	6,1,59h,4,57h,61h,6Ch,6Ch
	DB	20h,53h,61h,66h,65h,0,0,0
	DB	0F0h,0,10h,0,0Ah,1,63h,4
	DB	54h,61h,62h,6Ch,65h,0,0,0
	DB	0,0,0,0,40h,0,30h,0
	DB	81h,0,18h,3,54h,61h,62h,6Ch
	DB	65h,0,0,0,0,0,0,0
	DB	50h,0,30h,0,81h,0,18h,3
	DB	44h,65h,73h,6Bh,0,0,0,0
	DB	0,0,0,0,20h,0,10h,0
	DB	4Bh,0,1,0,44h,65h,73h,6Bh
	DB	0,0,0,0,0,0,0,0
	DB	30h,0,10h,0,4Bh,0,1,0
	DB	44h,65h,73h,6Bh,0,0,0,0
	DB	0,0,0,0,0,0,10h,0
	DB	4Bh,0,1,0,44h,65h,73h,6Bh
	DB	0,0,0,0,0,0,0,0
	DB	10h,0,10h,0,4Bh,0,1,0
	DB	43h,6Fh,75h,63h,68h,0,0,0
	DB	0,0,0,0,60h,0,30h,0
	DB	45h,0,11h,6,43h,6Fh,75h,63h
	DB	68h,0,0,0,0,0,0,0
	DB	70h,0,30h,0,45h,0,11h,6
	DB	54h,6Fh,69h,6Ch,65h,74h,0,0
	DB	0,0,0,0,0,0,40h,0
	DB	0Bh,1,80h,0,54h,6Fh,69h,6Ch
	DB	65h,74h,0,0,0,0,0,0
	DB	10h,0,40h,0,0Bh,1,80h,0
	DB	53h,69h,6Eh,6Bh,0,0,0,0
	DB	0,0,0,0,60h,0,40h,0
	DB	0Bh,1,80h,0,53h,69h,6Eh,6Bh
	DB	0,0,0,0,0,0,0,0
	DB	70h,0,40h,0,0Bh,1,80h,0
	DB	42h,61h,74h,68h,74h,75h,62h,0
	DB	0,0,0,0,80h,0,40h,0
	DB	41h,0,80h,0,42h,61h,74h,68h
	DB	74h,75h,62h,0,0,0,0,0
	DB	90h,0,40h,0,41h,0,80h,0
	DB	42h,65h,64h,0,0,0,0,0
	DB	0,0,0,0,0C0h,0,30h,0
	DB	41h,0,40h,0,42h,65h,64h,0
	DB	0,0,0,0,0,0,0,0
	DB	0D0h,0,30h,0,41h,0,40h,0
	DB	52h,61h,6Eh,67h,65h,0,0,0
	DB	0,0,0,0,0A0h,0,40h,0
	DB	1,1,0,1,52h,61h,6Eh,67h
	DB	65h,0,0,0,0,0,0,0
	DB	0B0h,0,40h,0,1,1,0,1
	DB	52h,65h,66h,72h,69h,67h,65h,72h
	DB	61h,74h,6Fh,72h,0C0h,0,50h,0
	DB	21h,1,0,1,52h,65h,66h,72h
	DB	69h,67h,65h,72h,61h,74h,6Fh,72h
	DB	0D0h,0,50h,0,21h,1,0,1
	DB	53h,74h,65h,72h,65h,6Fh,0,0
	DB	0,0,0,0,0E0h,0,30h,0
	DB	1,1,50h,6,54h,65h,6Ch,65h
	DB	76h,69h,73h,69h,6Fh,6Eh,0,0
	DB	0F0h,0,30h,0,1,1,40h,4
	DB	4Ch,61h,6Dh,70h,0,0,0,0
	DB	0,0,0,0,0,1,30h,0
	DB	1,1,8,6,54h,65h,6Ch,65h
	DB	76h,69h,73h,69h,6Fh,6Eh,0,0
	DB	10h,1,30h,0,1,1,0,4
	DB	43h,6Fh,6Dh,70h,75h,74h,65h,72h
	DB	0,0,0,0,0,0,30h,0
	DB	25h,1,24h,0,44h,72h,61h,77h
	DB	65h,72h,73h,0,0,0,0,0
	DB	10h,0,60h,0,0Bh,1,40h,4
	DB	43h,6Fh,6Dh,70h,75h,74h,65h,72h
	DB	0,0,0,0,20h,0,30h,0
	DB	25h,1,24h,0,44h,72h,61h,77h
	DB	65h,72h,73h,0,0,0,0,0
	DB	30h,0,60h,0,0Bh,1,40h,4
	DB	4Dh,61h,63h,47h,75h,66h,66h,69h
	DB	6Eh,20h,20h,0,0,0,60h,0
	DB	3,0,0,0,4Ch,6Fh,63h,61h
	DB	6Ch,20h,41h,67h,65h,6Eh,74h,0
	DB	0,1,10h,0,3,0,0,0
_dat_move_dx	DB	0,0,0,0,2,0,3,0
	DB	2,0,0,0,0FEh,0FFh,0FDh,0FFh
	DB	0FEh,0FFh
_dat_move_dy	DB	0,0,0FDh,0FFh,0FEh,0FFh,0,0
	DB	2,0,3,0,2,0,0,0
	DB	0FEh,0FFh
_dat_step_dx	DB	0,0,0,0,1,0,1,0
	DB	1,0,0,0,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh
_dat_step_dy	DB	0,0,0FFh,0FFh,0FFh,0FFh,0,0
	DB	1,0,1,0,1,0,0,0
	DB	0FFh,0FFh
_dat_side_dx	DB	0,0,1,0,0,0,0FFh,0FFh
	DB	0,0
_dat_side_dy	DB	0FFh,0FFh,0,0,1,0,0,0
	DB	0FFh,0FFh
dat_status_page_port	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_asm_status_page	DW	OFFSET DGROUP:dat_status_page_port
dat_cast_frames_port	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_dat_cast_frames	DW	OFFSET DGROUP:dat_cast_frames_port
dat_saved_page_port	DB	3,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_asm_saved_page	DW	OFFSET DGROUP:dat_saved_page_port
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
asm_block_1ac0	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
RASTPORT_PTR_1AD2	DW	OFFSET DGROUP:asm_block_1ac0
dat_map_page_port	DB	1,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_shd_map_page	DW	OFFSET DGROUP:dat_map_page_port
asm_block_1ae8	DB	0,0,1,0,2,0,0,2
	DB	0,1,3,1,2,1,0,3
	DB	0,1,11h,11h,2,0,2,3
	DB	30h,11h,13h,31h,22h,23h,33h,33h
_shd_colours_screen	DB	0,0,1,0,2,0,0,2		; COLOUR_MAP
	DB	0,1,2,3,2,1,1,3
_shd_colours_screen_2	DB	0,0,11h,11h,22h,0,0,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,22h,11h,22h,33h
D22958	DB	0,0,11h,11h,22h,22h,22h,22h
	DB	0,22h,33h,33h,0,0,11h,33h
	DB	0,22h,0,0,0,0,0,0
	DB	0,22h,22h,0,0,0,11h,33h
	DB	0,12h,11h,10h,11h,0,12h,33h
	DB	22h,13h,33h,11h,33h,22h,33h,33h
	DB	0,12h,0,0,22h,0,0,13h
	DB	2,11h,0,0,0,0,33h,33h
	DB	0,11h,11h,11h,22h,0,22h,12h
	DB	0,11h,11h,33h,33h,22h,33h,33h
	DB	0,11h,11h,11h,22h,0,22h,12h
	DB	0,11h,11h,33h,33h,22h,33h,33h
_shd_colours_face	DB	0,11h,11h,1,22h,0,22h,22h		; COLOUR_MAP
	DB	0,11h,11h,33h,33h,33h,33h,33h
_dat_colours_badge	DB	0,0,11h,11h,22h,0,0,11h		; COLOUR_MAP
	DB	22h,22h,33h,33h,22h,11h,22h,33h
_dat_colours_tactical	DB	0,0,11h,11h,22h,0,0,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,22h,11h,22h,33h
D229e8	DB	0,0,11h,11h,22h,0,0,33h
	DB	22h,22h,11h,33h,22h,33h,22h,33h
_asm_game_speed	DB	1,0
_dat_room_mask	DB	1,0
_shd_pan_disk	DB	3,0
_shd_palette_records	DB	0,1,2,3,4,0,6,7		; PALETTE[5]
	DB	8,9,0Ah,0Bh,0Ch,0,0Eh,0Fh
	DB	0,0,1,2,0Fh,4,0,6
	DB	7,8,9,0Ah,0Bh,0Ch,0,0Eh
	DB	0Fh,0,0,1,2,3,4,0
	DB	6,0Ch,8,9,0Ah,0Bh,0Ch,0
	DB	0Eh,0Fh,0,0,1,2,0Eh,4
	DB	0,6,7,8,9,0Ah,0Bh,0Ch
	DB	0,0Eh,0Fh,0,0,1,2,0
	DB	4,0,6,7,8,9,0Ah,0Bh
	DB	0Ch,0,0Eh,0Fh,0
PALETTE_TABLE_PAD	DB	0
_asm_page_3	DB	0,0
_dat_str_empty_15	DB	0
_dat_str_which_door	DB	57h,68h,69h,63h,68h,20h,64h,6Fh
	DB	6Fh,72h,3Fh,20h,20h,0Ah,20h,0
_dat_str_door_5	DB	44h,6Fh,6Fh,72h,20h,23h,0
_dat_str_newline_13	DB	0Ah,20h,0,0
_asm_facing	DB	4,0
_asm_facing_goal	DB	4,0
_dat_str_paused	DB	50h,41h,55h,53h,45h,44h,0Ah,0
_dat_str_sure_want_quit_no	DB	41h,72h,65h,20h,79h,6Fh,75h,20h
	DB	73h,75h,72h,65h,0Ah,79h,6Fh,75h
	DB	20h,77h,61h,6Eh,74h,20h,74h,6Fh
	DB	20h,51h,75h,69h,74h,3Fh,0Ah,20h
	DB	4Eh,6Fh,0Ah,20h,59h,65h,73h,0Ah
	DB	0,0
_dat_joystick_keys	DB	0,0,48h,0,49h,0,4Dh,0
	DB	51h,0,50h,0,4Fh,0,4Bh,0
	DB	47h,0
_asm_shot_fired	DB	0,0
_dat_meter_colours	DB	0,8,3,7,0Fh
_dat_str_set_trap_cancel_remote	DB	53h,65h,74h,20h,74h,72h,61h,70h
	DB	0Ah,20h,43h,61h,6Eh,63h,65h,6Ch
	DB	0Ah,20h,52h,65h,6Dh,6Fh,74h,65h
	DB	20h,43h,6Fh,6Eh,74h,72h,6Fh,6Ch
	DB	0Ah,20h,42h,6Fh,6Fh,62h,79h,20h
	DB	54h,72h,61h,70h,0Ah,0,0
_dat_str_empty_16	DB	0
_dat_str_do_want_arrest	DB	44h,6Fh,20h,79h,6Fh,75h,20h,77h
	DB	61h,6Eh,74h,20h,74h,6Fh,0Ah,61h
	DB	72h,72h,65h,73h,74h,20h,0
_dat_str_question	DB	3Fh,0Ah,20h,59h,65h,73h,0Ah,20h
	DB	4Eh,6Fh,0Ah,0
_dat_str_bug	DB	20h,2Eh,2Eh,2Eh,20h,62h,75h,67h
	DB	0
_dat_str_photo	DB	20h,2Eh,2Eh,2Eh,20h,70h,68h,6Fh
	DB	74h,6Fh,0
_dat_str_closed	DB	20h,63h,6Ch,6Fh,73h,65h,64h,2Eh
	DB	0
_dat_str_nothing_photograph	DB	4Eh,6Fh,74h,68h,69h,6Eh,67h,20h
	DB	74h,6Fh,20h,70h,68h,6Fh,74h,6Fh
	DB	67h,72h,61h,70h,68h,2Eh,0
_dat_str_already_photographed	DB	41h,6Ch,72h,65h,61h,64h,79h,20h
	DB	70h,68h,6Fh,74h,6Fh,67h,72h,61h
	DB	70h,68h,65h,64h,2Eh,0
_dat_str_photographed	DB	20h,70h,68h,6Fh,74h,6Fh,67h,72h
	DB	61h,70h,68h,65h,64h,2Eh,0
_dat_str_open	DB	4Fh,70h,65h,6Eh,20h,0
_dat_str_first	DB	20h,66h,69h,72h,73h,74h,2Eh,0
_dat_str_out_film	DB	4Fh,75h,74h,20h,6Fh,66h,20h,66h
	DB	69h,6Ch,6Dh,2Eh,0
_dat_str_empty_17	DB	0
_dat_str_bugged	DB	20h,62h,75h,67h,67h,65h,64h,2Eh
	DB	0
_dat_str_room_already_bugged	DB	52h,6Fh,6Fh,6Dh,20h,61h,6Ch,72h
	DB	65h,61h,64h,79h,20h,62h,75h,67h
	DB	67h,65h,64h,2Eh,0
_dat_str_nothing_bug	DB	4Eh,6Fh,74h,68h,69h,6Eh,67h,20h
	DB	74h,6Fh,20h,62h,75h,67h,2Eh,0
_dat_str_gas	DB	47h,41h,53h,0
_dat_str_disguise	DB	44h,69h,73h,67h,75h,69h,73h,65h
	DB	0
_dat_str_overcome_by_gas_pass	DB	59h,6Fh,75h,20h,61h,72h,65h,20h
	DB	6Fh,76h,65h,72h,63h,6Fh,6Dh,65h
	DB	0Ah,62h,79h,20h,67h,61h,73h,20h
	DB	61h,6Eh,64h,20h,70h,61h,73h,73h
	DB	20h,6Fh,75h,74h,2Eh,0Ah,0
_dat_str_slump_ground_overcome	DB	59h,6Fh,75h,20h,73h,6Ch,75h,6Dh
	DB	70h,20h,74h,6Fh,0Ah,74h,68h,65h
	DB	20h,67h,72h,6Fh,75h,6Eh,64h,2Ch
	DB	20h,6Fh,76h,65h,72h,63h,6Fh,6Dh
	DB	65h,0Ah,62h,79h,20h,79h,6Fh,75h
	DB	72h,20h,77h,6Fh,75h,6Eh,64h,73h
	DB	2Eh,0Ah,0
_dat_str_prisoner_released_while	DB	54h,68h,65h,20h,70h,72h,69h,73h
	DB	6Fh,6Eh,65h,72h,20h,69h,73h,0Ah
	DB	72h,65h,6Ch,65h,61h,73h,65h,64h
	DB	20h,77h,68h,69h,6Ch,65h,20h,79h
	DB	6Fh,75h,0Ah,61h,72h,65h,20h,6Fh
	DB	75h,74h,20h,6Fh,66h,20h,74h,68h
	DB	65h,20h,72h,6Fh,6Fh,6Dh,2Eh,0Ah
	DB	0
_dat_str_have_eliminated_all	DB	59h,6Fh,75h,20h,68h,61h,76h,65h
	DB	20h,65h,6Ch,69h,6Dh,69h,6Eh,61h
	DB	74h,65h,64h,0Ah,61h,6Ch,6Ch,20h
	DB	6Fh,66h,20h,79h,6Fh,75h,72h,20h
	DB	65h,6Eh,65h,6Dh,69h,65h,73h,2Eh
	DB	0Ah,0
_dat_str_quickly_slip_out	DB	59h,6Fh,75h,20h,71h,75h,69h,63h
	DB	6Bh,6Ch,79h,20h,73h,6Ch,69h,70h
	DB	0Ah,6Fh,75h,74h,20h,6Fh,66h,20h
	DB	74h,68h,65h,20h,62h,75h,69h,6Ch
	DB	64h,69h,6Eh,67h,2Eh,0Ah,0
_dat_str_cia_agent	DB	54h,68h,65h,20h,43h,49h,41h,20h
	DB	61h,67h,65h,6Eh,74h,20h,69h,6Eh
	DB	0Ah,0
_dat_str_double_agent	DB	20h,69h,73h,0Ah,61h,20h,64h,6Fh
	DB	75h,62h,6Ch,65h,20h,61h,67h,65h
	DB	6Eh,74h,21h,21h,0Ah,0
_dat_str_now	DB	20h,6Eh,6Fh,77h,0Ah,69h,6Eh,20h
	DB	0
_dat_str_bang_2	DB	21h,0Ah,0
_dat_str_find	DB	59h,6Fh,75h,20h,66h,69h,6Eh,64h
	DB	0Ah,0
_dat_str_bang_3	DB	21h,0Ah,0
_dat_str_empty_18	DB	0
_dat_str_has_been_identified_as	DB	20h,68h,61h,73h,0Ah,62h,65h,65h
	DB	6Eh,20h,69h,64h,65h,6Eh,74h,69h
	DB	66h,69h,65h,64h,20h,61h,73h,0Ah
	DB	61h,20h,70h,61h,72h,74h,69h,63h
	DB	69h,70h,61h,6Eh,74h,0Ah,69h,6Eh
	DB	20h,74h,68h,65h,20h,70h,6Ch,6Fh
	DB	74h,2Eh,0Ah,0
_dat_str_find_incriminating	DB	59h,6Fh,75h,20h,66h,69h,6Eh,64h
	DB	20h,69h,6Eh,63h,72h,69h,6Dh,69h
	DB	6Eh,61h,74h,69h,6Eh,67h,0Ah,65h
	DB	76h,69h,64h,65h,6Eh,63h,65h,20h
	DB	77h,68h,69h,63h,68h,20h,77h,69h
	DB	6Ch,6Ch,0Ah,74h,75h,72h,6Eh,20h
	DB	0
_dat_str_into_double_agent	DB	0Ah,69h,6Eh,74h,6Fh,20h,61h,20h
	DB	64h,6Fh,75h,62h,6Ch,65h,20h,61h
	DB	67h,65h,6Eh,74h,21h,0Ah,0
_dat_tip_items	DB	2,0,5,0,6,0,7,0
	DB	8,0,9,0,0Ah,0,0Fh,0
_dat_str_mode_read_text_2	DB	72h,74h,0
_dat_str_text_dta	DB	74h,65h,78h,74h,2Eh,64h,74h,61h
	DB	0
_dat_fmt_word	DB	25h,33h,32h,73h,0
_dat_fmt_word_2	DB	25h,33h,32h,73h,0
_dat_password_hint_initial	DB	2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	DB	2Eh,2Eh,0
_dat_str_enter_password	DB	45h,6Eh,74h,65h,72h,20h,50h,61h
	DB	73h,73h,57h,6Fh,72h,64h,3Ah,0
_dat_str_empty_19	DB	0
_dat_str_access_confirmed	DB	41h,63h,63h,65h,73h,73h,20h,43h
	DB	4Fh,4Eh,46h,49h,52h,4Dh,45h,44h
	DB	0
_dat_str_access_denied	DB	41h,63h,63h,65h,73h,73h,20h,44h
	DB	45h,4Eh,49h,45h,44h,0
_dat_str_search	DB	53h,65h,61h,72h,63h,68h,20h,66h
	DB	6Fh,72h,3Ah,0
_dat_str_has	DB	20h,68h,61h,73h,0Ah,0
_dat_str_a	DB	61h,0
_dat_str_no_operatives	DB	6Eh,6Fh,20h,6Fh,70h,65h,72h,61h
	DB	74h,69h,76h,65h,73h,0
_dat_str_newline_in	DB	0Ah,69h,6Eh,20h,0
_dat_str_newline_14	DB	0Ah,0
_dat_str_has_no_operatives	DB	20h,68h,61h,73h,0Ah,6Eh,6Fh,20h
	DB	6Fh,70h,65h,72h,61h,74h,69h,76h
	DB	65h,73h,0
_dat_str_newline_in_2	DB	0Ah,69h,6Eh,20h,0
_dat_str_newline_15	DB	0Ah,0
_dat_str_now_2	DB	20h,6Eh,6Fh,77h,0Ah,69h,6Eh,20h
	DB	0
_dat_str_bang	DB	21h,0Ah,0
_dat_str_empty_20	DB	0
_dat_str_no_data	DB	4Eh,6Fh,20h,44h,61h,74h,61h,0
	DB	0
_dat_wall_tiles	DB	0,0,1,4,2,0,5,0
	DB	3,7,0,0,6,0,0,0
_dat_str_street	DB	53h,74h,72h,65h,65h,74h,0
_dat_str_spritesf_pic	DB	73h,70h,72h,69h,74h,65h,73h,66h
	DB	2Eh,70h,69h,63h,0
_dat_str_sprites_pic	DB	73h,70h,72h,69h,74h,65h,73h,2Eh
	DB	70h,69h,63h,0
_dat_step_facing	DB	8,0,7,0,6,0,1,0
	DB	0,0,5,0,2,0,3,0
	DB	4,0
_dat_no_room	DB	0FFh,0FFh
dat_str_pistol	DB	50h,69h,73h,74h,6Fh,6Ch,0
dat_str_uzi	DB	55h,7Ah,69h,0
dat_str_camera	DB	43h,61h,6Dh,65h,72h,61h,0
dat_str_bugs	DB	42h,75h,67h,73h,0
dat_str_safecracking_tools	DB	53h,61h,66h,65h,63h,72h,61h,63h
	DB	6Bh,69h,6Eh,67h,20h,54h,6Fh,6Fh
	DB	6Ch,73h,0
dat_str_gas_mask	DB	47h,61h,73h,20h,4Dh,61h,73h,6Bh
	DB	0
dat_str_kevlar_vest	DB	4Bh,65h,76h,6Ch,61h,72h,20h,56h
	DB	65h,73h,74h,0
dat_str_motion_detector	DB	4Dh,6Fh,74h,69h,6Fh,6Eh,20h,44h
	DB	65h,74h,65h,63h,74h,6Fh,72h,0
dat_str_fragmentation_grenades	DB	46h,72h,61h,67h,6Dh,65h,6Eh,74h
	DB	61h,74h,69h,6Fh,6Eh,20h,47h,72h
	DB	65h,6Eh,61h,64h,65h,73h,0
dat_str_gas_grenades	DB	47h,61h,73h,20h,47h,72h,65h,6Eh
	DB	61h,64h,65h,73h,0
dat_str_stun_grenades	DB	53h,74h,75h,6Eh,20h,47h,72h,65h
	DB	6Eh,61h,64h,65h,73h,0
dat_str_assorted_grenades	DB	41h,73h,73h,6Fh,72h,74h,65h,64h
	DB	20h,47h,72h,65h,6Eh,61h,64h,65h
	DB	73h,0
dat_str_empty_kit_1	DB	0
dat_str_empty_kit_2	DB	0
dat_str_empty_kit_3	DB	0
dat_str_floor_plan	DB	46h,6Ch,6Fh,6Fh,72h,20h,50h,6Ch
	DB	61h,6Eh,0
_dat_str_equip2_pic	DB	65h,71h,75h,69h,70h,32h,2Eh,70h
	DB	69h,63h,0
_addr_kit_names	DW	OFFSET DGROUP:dat_str_pistol
	DW	OFFSET DGROUP:dat_str_uzi
	DW	OFFSET DGROUP:dat_str_camera
	DW	OFFSET DGROUP:dat_str_bugs
	DW	OFFSET DGROUP:dat_str_safecracking_tools
	DW	OFFSET DGROUP:dat_str_gas_mask
	DW	OFFSET DGROUP:dat_str_kevlar_vest
	DW	OFFSET DGROUP:dat_str_motion_detector
	DW	OFFSET DGROUP:dat_str_fragmentation_grenades
	DW	OFFSET DGROUP:dat_str_gas_grenades
	DW	OFFSET DGROUP:dat_str_stun_grenades
	DW	OFFSET DGROUP:dat_str_assorted_grenades
	DW	OFFSET DGROUP:dat_str_empty_kit_1
	DW	OFFSET DGROUP:dat_str_empty_kit_2
	DW	OFFSET DGROUP:dat_str_empty_kit_3
	DW	OFFSET DGROUP:dat_str_floor_plan
_dat_kit_boxes	DB	0,0,0,0,0,0,0,0		; KIT_BOX[12]
	DB	1,0,2,0,1,0,5,0
	DB	1,0,3,0,2,0,6,0
	DB	2,0,8,0,3,0,6,0
	DB	6,0,4,0,8,0,4,0
	DB	5,0,6,0,1,0,7,0
	DB	7,0,4,0,2,0,6,0
	DB	7,0,6,0,5,0,7,0
	DB	3,0,9,0,8,0,4,0
	DB	8,0,0Ah,0,9,0,4,0
	DB	9,0,0Bh,0,0Ah,0,4,0
	DB	0Ah,0,0Bh,0,0Bh,0,4,0
_dat_kit_points	DB	0AAh,0,30h,0,0A6h,0,2Eh,0		; POINT[13]
	DB	0D8h,0,49h,0,0E5h,0,7,0
	DB	0FCh,0,46h,0,0F7h,0,0,0
	DB	0F7h,0,1Fh,0,0Ah,1,0,0
	DB	0ACh,0,3,0,0ACh,0,11h,0
	DB	0ACh,0,1Fh,0,0ACh,0,47h,0
	DB	0ACh,0,50h,0
_dat_kit_sprite_rects	DB	0A2h,0,19h,0,0BDh,0,26h,0		; RECT[15]
	DB	0A2h,0,47h,0,0DCh,0,5Dh,0
	DB	10h,1,65h,0,28h,1,7Ah,0
	DB	2,1,29h,0,8,1,2Dh,0
	DB	0DCh,0,0ACh,0,11h,1,0C6h,0
	DB	0FEh,0,1,0,23h,1,1Fh,0
	DB	0DFh,0,47h,0,0Eh,1,84h,0
	DB	0F6h,0,29h,0,0FFh,0,3Ah,0
	DB	1Dh,1,89h,0,25h,1,95h,0
	DB	1Dh,1,98h,0,25h,1,0A4h,0
	DB	1Dh,1,0A7h,0,25h,1,0B3h,0
	DB	0C9h,0,29h,0,0CBh,0,2Fh,0
	DB	0BCh,0,29h,0,0C6h,0,37h,0
	DB	0A2h,0,5Fh,0,0AAh,0,65h,0
	DB	2Ah,1,65h,0,38h,1,71h,0
_dat_kit_slot_rects	DB	0,0,0,0,0,0,0,0		; RECT[12]
	DB	2,0,0Fh,0,3Eh,0,27h,0
	DB	2,0,36h,0,3Eh,0,48h,0
	DB	2,0,58h,0,3Eh,0,69h,0
	DB	45h,0,88h,0,9Dh,0,0B8h,0
	DB	45h,0,0Fh,0,71h,0,32h,0
	DB	45h,0,3Ch,0,9Dh,0,7Eh,0
	DB	74h,0,0Fh,0,9Dh,0,32h,0
	DB	2,0,7Ah,0,3Eh,0,8Ah,0
	DB	2,0,8Ch,0,3Eh,0,9Ah,0
	DB	2,0,9Ch,0,3Eh,0,0AAh,0
	DB	2,0,0ACh,0,3Eh,0,0BAh,0
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
asm_block_2592	DB	2,2,1,4,1,8,1,8
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
asm_block_25da	DB	0,0
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
asm_block_2a25	DB	0
_shd_clue_kinds	DW	OFFSET DGROUP:dat_str_recruit
	DW	OFFSET DGROUP:dat_str_operative
	DW	OFFSET DGROUP:dat_str_technician
	DW	OFFSET DGROUP:dat_str_agent
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
asm_block_2b7f	DB	0
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
	DB	74h,0,0
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
BLOCK_2CED	DB	0
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
	DB	63h,0
asm_block_2f21	DB	0
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
	DB	76h,69h,74h,79h,29h,0,0
_shd_clock_text	DB	30h,30h,3Ah,30h,30h,3Ah,30h,30h
	DB	0
asm_block_3655	DB	0
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
asm_block_3699	DB	0
_shd_city_on_screen	DB	0FFh,0FFh
_shd_drive	DB	0FFh,0FFh
_shm_pan_width	DB	40h,1
asm_block_36a0	DB	1,0
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
asm_block_36d9	DB	0
_shm_pan_building	DB	0,0
_shd_str_animation_pan	DB	61h,6Eh,69h,6Dh,61h,74h,69h,6Fh
	DB	6Eh,2Eh,70h,61h,6Eh,0
_shd_joystick_dirs	DB	8,0,7,0,6,0,1,0
	DB	0FFh,0FFh,5,0,2,0,3,0
	DB	4,0
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
dat_screen_port	DB	0,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,1,0,0Fh,0,4,0
	DB	0,0
_shd_screen	DW	OFFSET DGROUP:dat_screen_port
DAT_20e3_37b2	DB	0
DAT_20e3_37b3	DB	0
DAT_20e3_37b4	DB	0,0
DAT_20e3_37b6	DB	0,0
DAT_20e3_37b8	DB	0,0
DAT_20e3_37ba	DB	0,0
DAT_20e3_37bc	DB	0,0
DAT_20e3_37be	DB	0,0
DAT_20e3_37c0	DB	0,0
DAT_20e3_37c2	DB	0,0
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
_shd_archive_buffer_end	DW	OFFSET DGROUP:_asm_view_left
_shd_archive_fd	DB	0FFh,0FFh
asm_block_38de	DB	0
DAT_20e3_38df	DB	0,0
DAT_20e3_38e1	DB	0,0
DAT_20e3_38e3	DB	0,0
DAT_20e3_38e5	DB	0,0
DAT_20e3_38e7	DB	0FFh,0FFh
asm_block_38e9	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
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
	DB	0,0,0,0,0,0,0,0
	DB	0,0
DAT_20e3_3c5b	DB	0FFh,0FFh
DAT_20e3_3c5d	DB	0,0
DAT_20e3_3c5f	DB	0,0
DAT_20e3_3c61	DB	0,0
asm_block_3c63	DB	0
DAT_20e3_3c64	DB	0
DAT_20e3_3c65	DB	0,0
DAT_20e3_3c67	DB	0,0
DAT_20e3_3c69	DB	0,0
DAT_20e3_3c6b	DB	0,0
DAT_20e3_3c6d	DB	3Fh,1
DAT_20e3_3c6f	DB	6Fh,0
asm_block_3c71	DB	0
DAT_20e3_3c72	DB	0,0
DAT_20e3_3c74	DB	0,0
DAT_20e3_3c76	DB	0,0
DAT_20e3_3c78	DB	0,0
DAT_20e3_3c7a	DB	0,0
DAT_20e3_3c7c	DB	0,0
DAT_20e3_3c7e	DB	0,0
DAT_20e3_3c80	DB	0,0
DAT_20e3_3c82	DB	0,0
DAT_20e3_3c84	DB	0,0
DAT_20e3_3c86	DB	0,0
DAT_20e3_3c88	DB	0,0

_DATA	ENDS

CONST	SEGMENT	WORD PUBLIC 'CONST'
asm_seg_const	DB	3,0

CONST	ENDS

_BSS	SEGMENT	WORD PUBLIC 'BSS'
asm_block_4298	DB	0
asm_block_4299	DB	0
asm_block_429a	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
_asm_regs	DB	0,0,0,0,0,0,0,0		; REGS
	DB	0,0,0,0,0,0
asm_block_42b6	DB	0,0
_asm_number_digits_3	DB	0,0,0,0,0,0,0,0
	DB	0,0
_asm_blip_x	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
_asm_blip_y	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
_asm_cast_x	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
_asm_cast_y	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
_asm_signs_here	DB	0,0
_asm_disguise_label_shown	DB	0,0
_asm_gas_label_shown	DB	0,0
_asm_move_cost	DB	0,0
_asm_direction_keycode	DB	0,0
_asm_shooter	DB	0,0
_asm_flash_x	DB	0,0
_asm_flash_y	DB	0,0
asm_block_431a	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
_shm_field_cursor	DB	0,0
_shm_field_char_width	DB	0,0
_shm_field_cursor_x	DB	0,0
asm_block_433a	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
_asm_room_doorways	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
asm_block_4384	DB	0,0,0,0,0,0,0,0
	DB	0,0
_asm_step_map	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_last_grenade_tick	DB	0,0
asm_block_7090	DB	0,0,0,0,0,0,0,0
	DB	0,0
_asm_path_queue_col	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_path_queue_row	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_asm_number_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0
_shm_clue_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_message_key	DB	0,0,0,0,0,0,0,0
	DB	0
asm_block_72dd	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0
_shm_active_pan	DW	0h		; the library's
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
asm_block_730c	DB	0,0,0,0,0,0,0,0
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
_shm_save_block	DB	0,0,0,0
asm_block_7368	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_save_offset	DB	0,0
_shm_save_fd	DB	0,0
asm_block_737c	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_source_fd	DB	0,0
_shm_source_dst	DB	0,0
_shm_source_src	DB	0,0
DAT_20e3_7392	DB	0,0
DAT_20e3_7394	DB	0
asm_block_7395	DB	0,0
asm_block_7397	DB	0
asm_block_7398	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
DAT_20e3_8b98	DB	0,0
DAT_20e3_8b9a	DB	0,0
DAT_20e3_8b9c	DB	0
DAT_20e3_8b9d	DB	0
DAT_20e3_8b9e	DB	0
DAT_20e3_8b9f	DB	0
DAT_20e3_8ba0	DB	0,0
DAT_20e3_8ba2	DB	0,0
DAT_20e3_8ba4	DB	0,0
DAT_20e3_8ba6	DB	0
DAT_20e3_8ba7	DB	0
DAT_20e3_8ba8	DB	0,0
DAT_20e3_8baa	DB	0
asm_block_8bab	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
_asm_org_alert_level	DB	2 DUP(?)
_asm_photo_score	DB	2 DUP(?)
_shm_joystick	DB	2 DUP(?)
_asm_clips_left	DB	2 DUP(?)
_asm_palette_flash	DB	2 DUP(?)
_shm_scratch	DB	200h DUP(?)
D29e0a	DB	200h DUP(?)
_asm_guard_seen	DB	2 DUP(?)
_asm_disguised	DB	2 DUP(?)
_asm_night	DB	2 DUP(?)
_shm_difficulty	DB	2 DUP(?)
_asm_panel_x	DB	2 DUP(?)
asm_block_91e4	DB	2 DUP(?)
_asm_panel_y	DB	2 DUP(?)
_shm_clock_minutes	DB	2 DUP(?)
_asm_guard_alert	DB	2 DUP(?)
_asm_jump_ticks	DB	2 DUP(?)
_asm_floor_map	DB	500h DUP(?)
_asm_guard_room	DB	2 DUP(?)
_asm_guards_at_target	DB	2 DUP(?)
_asm_crouch_walk_ticks	DB	2 DUP(?)
_asm_shot_timer	DB	2 DUP(?)
_asm_rounds_left	DB	2 DUP(?)
_asm_doorways	DB	1E0h DUP(?)
_shm_campaign	DB	28Eh DUP(?)
_shm_seed	DB	2 DUP(?)
_shm_options	DB	2 DUP(?)
_asm_room_right	DB	2 DUP(?)
_shm_cga	DB	2 DUP(?)
_asm_radar_sprite	DB	2 DUP(?)
_asm_readout_sprite	DB	2 DUP(?)
_asm_kit	DB	2 DUP(?)
_asm_room_bottom	DB	2 DUP(?)
	PUBLIC	__bufout
__bufout	LABEL	BYTE
asm_block_9b76	DB	200h DUP(?)
_asm_effect	DB	2 DUP(?)
_asm_grenades	DB	0A0h DUP(?)
_shm_cities	DB	220h DUP(?)
_asm_photos_taken	DB	2 DUP(?)
_asm_player_cell	DB	2 DUP(?)
_asm_kit_sprites	DB	1Eh DUP(?)
asm_block_a05a	DB	2 DUP(?)
_asm_player_cell_row	DB	2 DUP(?)
_asm_rooms	DB	150h DUP(?)
_asm_room_seen_tick	DB	30h DUP(?)
_asm_room_seen	DB	2 DUP(?)
_shm_menu_tick	DB	2 DUP(?)
_shm_suspect_count	DB	2 DUP(?)
_asm_mission_kind	DB	2 DUP(?)
_shm_log	DB	700h DUP(?)
_shm_menu_face	DB	2 DUP(?)
_asm_throw_frames	DB	2 DUP(?)
_asm_bugs_planted	DB	2 DUP(?)
_asm_frame_tick	DB	2 DUP(?)
_shm_wire_clue_source	DB	2 DUP(?)
_shm_crime_events	DB	0B00h DUP(?)
_shm_log_count	DB	2 DUP(?)
_shm_menu_first_line	DB	2 DUP(?)
_asm_seen_longest	DB	2 DUP(?)
asm_block_b3f6	DB	2 DUP(?)
_asm_guard_sees	DB	2 DUP(?)
_asm_room_count	DB	2 DUP(?)
_asm_player_col	DB	2 DUP(?)
asm_block_b3fe	DB	2 DUP(?)
_shm_building_count	DB	2 DUP(?)
_asm_guard_in_room	DB	2 DUP(?)
_shm_case_tick	DB	2 DUP(?)
_asm_cursor_col	DB	2 DUP(?)
_asm_player_row	DB	2 DUP(?)
_asm_room_map	DB	500h DUP(?)
asm_block_b90a	DB	2 DUP(?)
_asm_cursor_row	DB	2 DUP(?)
_asm_last_move_type	DB	2 DUP(?)
_asm_room_left	DB	2 DUP(?)
_asm_payload_room	DB	2 DUP(?)
_shm_source_at	DB	2 DUP(?)
_asm_room_top	DB	2 DUP(?)
_shm_case_city_1	DB	2 DUP(?)
_asm_guard_distances	DB	30h DUP(?)
_shm_case_city_2	DB	2 DUP(?)
_asm_ammunition	DB	6 DUP(?)
	PUBLIC	__bufin
__bufin	LABEL	BYTE
asm_block_b952	DB	200h DUP(?)
_shm_pan_playing	DB	2 DUP(?)
asm_block_bb54	DB	2 DUP(?)
_asm_walked	DB	2 DUP(?)
_asm_bug_score	DB	2 DUP(?)
_shm_menu_no_pick	DB	2 DUP(?)
asm_block_bb5c	DB	2 DUP(?)
_shm_menu_items	DB	2 DUP(?)
_asm_crouched	DB	2 DUP(?)
_asm_hour	DB	2 DUP(?)
_asm_walk_frame	DB	2 DUP(?)
_asm_film_left	DB	2 DUP(?)
_shm_crime_event_count	DB	2 DUP(?)
_asm_high_security	DB	2 DUP(?)
_asm_alarm_sounded	DB	2 DUP(?)
_asm_bugs_left	DB	2 DUP(?)
_asm_guard_tick	DB	2 DUP(?)
_asm_player_x	DB	2 DUP(?)
_shm_case_seed	DB	2 DUP(?)
_shm_clue_method	DB	2 DUP(?)
_shm_menu_relayout	DB	2 DUP(?)
_asm_outcome	DB	1 DUP(?)
asm_block_bb7b	DB	1 DUP(?)
_asm_player_y	DB	2 DUP(?)
_shm_mission	DB	2 DUP(?)
_shm_menu_colour_bar	DB	2 DUP(?)
_asm_guard_turn_at	DB	2 DUP(?)
_shm_case_org_1	DB	2 DUP(?)
_shm_menu_text_width	DB	2 DUP(?)
_shm_case_org_2	DB	2 DUP(?)
asm_block_bb8a	DB	2 DUP(?)
_shm_faces_sprites	DB	0E8h DUP(?)
asm_block_bc74	DB	8 DUP(?)
_asm_tile_sprites	DB	160h DUP(?)
_asm_suspect_here	DB	2 DUP(?)
_asm_room_last	DB	2 DUP(?)
_shm_global_alert_level	DB	2 DUP(?)
_shm_regs	DB	0Eh DUP(?)
_shm_double_agent_cities	DB	2 DUP(?)
_shm_crime_role_count	DB	2 DUP(?)
_shm_menu_marked	DB	2 DUP(?)
_shm_crime_roles	DB	600h DUP(?)
_shm_refill	DB	2 DUP(?)
_asm_DAT_20e3_c3f8	DB	2 DUP(?)
_shm_archive_buffer	DB	200h DUP(?)
_asm_view_left	DB	2 DUP(?)
_shm_menu_face_x	DB	2 DUP(?)
_shm_menu_draw_only	DB	2 DUP(?)
_shm_skills	DB	2 DUP(?)
_asm_view_top	DB	2 DUP(?)
_shm_orgs	DB	240h DUP(?)
_shm_menu_face_y	DB	2 DUP(?)
_asm_password_text	DB	21h DUP(?)
asm_block_c867	DB	5 DUP(?)
_shm_finished	DB	2 DUP(?)
_asm_target_room	DB	2 DUP(?)
_asm_people	DB	0FCh DUP(?)
_shm_menu_shortcut	DB	20h DUP(?)
_asm_password_hint	DB	0Bh DUP(?)
asm_block_c997	DB	1 DUP(?)
_asm_belt_text	DB	2 DUP(?)
_shm_menu_pick	DB	2 DUP(?)
asm_block_c99c	DB	2 DUP(?)
_shm_crime_block	DB	48h DUP(?)
_asm_end_line	DB	2 DUP(?)
_shm_menu_right	DB	2 DUP(?)
_shm_substitute_tail	DB	100h DUP(?)
_shm_role_scan_states	DB	0C0h DUP(?)
_asm_guards_awake	DB	2 DUP(?)
_asm_wounds	DB	2 DUP(?)
_shm_graphics_letter	DB	1 DUP(?)
asm_block_cbaf	DB	1 DUP(?)
_shm_menu_bottom	DB	2 DUP(?)
_asm_sound_arg_1	DB	2 DUP(?)
asm_block_cbb4	DB	2 DUP(?)
_asm_sound_arg_2	DB	2 DUP(?)
_asm_seen_count	DB	2 DUP(?)
_shm_case_city	DB	2 DUP(?)
_shm_activity	DB	40h DUP(?)
_shm_orgs_known	DB	2 DUP(?)
	PUBLIC	__buferr
__buferr	LABEL	BYTE
asm_block_cbfe	DB	202h DUP(?)
_shm_case_spare_2	DB	2 DUP(?)
_shm_anim_row_2	DB	140h DUP(?)
_asm_difficulty_was	DB	2 DUP(?)
_asm_conspicuous	DB	2 DUP(?)
_asm_doorway_count	DB	2 DUP(?)
asm_block_cf48	DB	40h DUP(?)
_asm_guards_to_come	DB	2 DUP(?)
_asm_wall_map	DB	500h DUP(?)
_shm_case_org	DB	2 DUP(?)
asm_block_d48c	DB	4 DUP(?)

c_common	ENDS

	END
