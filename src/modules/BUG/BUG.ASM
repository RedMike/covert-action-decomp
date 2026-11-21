	PAGE	60,132
	TITLE	BUG
;
; BUG.ASM -- the assembly side of BUG.EXE.
;
; A SPLIT marker stands where a routine is in C; the build cuts the
; assembly there.
;

	EXTRN	_c_main:PROC
	EXTRN	_c_hook_hand_back:PROC
	EXTRN	_c_sound_command:PROC
	EXTRN	_c_set_display_page:PROC
	EXTRN	_c_set_dac:PROC
	EXTRN	_c_nothing:PROC
	EXTRN	_c_show_menu:PROC
	EXTRN	_c_hook_repaint:PROC
	EXTRN	_c_draw_sprite:PROC
	EXTRN	_c_draw_bug_sprite:PROC
	EXTRN	_c_load_sprites:PROC
	EXTRN	_c_deal_board:PROC
	EXTRN	_c_board_step:PROC
	EXTRN	_c_trace_wire:PROC
	EXTRN	_c_draw_wires:PROC
	EXTRN	_c_tick:PROC
	EXTRN	_c_read_keys:PROC
	EXTRN	_c_draw_chip_box:PROC
	EXTRN	_c_clock_draw:PROC
	EXTRN	_c_ask_menu:PROC
	EXTRN	_c_hook_message:PROC
	EXTRN	_c_scan_for_tap:PROC
	EXTRN	_c_set_palette_record:PROC
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
	EXTRN	_c_draw_paper:PROC
	EXTRN	_c_print_message:PROC
	EXTRN	_c_draw_display_list:PROC
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
	EXTRN	_c_want_disk:PROC
	EXTRN	_c_seq_start:PROC
	EXTRN	_c_seq_step:PROC
	EXTRN	_c_seq_stop:PROC
	EXTRN	_c_seek:PROC
	PUBLIC	_shm_anim_row_2
	PUBLIC	_drv_jump_gfx_grab
	PUBLIC	_drv_real_FUN_1000_00ca
	PUBLIC	_drv_jump_gfx_fill
	PUBLIC	_drv_jump_gfx_char_width
	PUBLIC	_drv_jump_gfx_pool_release
	PUBLIC	_drv_jump_gfx_get_pixel
	PUBLIC	_drv_jump_gfx_pool_alloc
	PUBLIC	_drv_jump_gfx_copy_rect
	PUBLIC	_drv_jump_gfx_set_colour_map
	PUBLIC	_drv_jump_gfx_sprite_put
	PUBLIC	_drv_jump_snd_command
	PUBLIC	_drv_jump_keyboard_empty
	PUBLIC	_drv_real_link_slots
	PUBLIC	_drv_real_fill_rect
	PUBLIC	_shd_map_page
	PUBLIC	_shd_picture_page
	PUBLIC	_dat_chip_page
	PUBLIC	_dat_clock_text
	PUBLIC	_shm_difficulty
	PUBLIC	_shd_screen
	PUBLIC	_asm_title_x
	PUBLIC	_asm_title_y
	PUBLIC	_asm_max_goals_reached
	PUBLIC	_asm_cursor_col
	PUBLIC	_shm_options
	PUBLIC	_asm_agent_sprite
	PUBLIC	_asm_wire_sprite
	PUBLIC	_shm_cga
	PUBLIC	_asm_cursor_row
	PUBLIC	_asm_held_chip
	PUBLIC	_asm_board_stage
	PUBLIC	_asm_score
	PUBLIC	_asm_frame_count
	PUBLIC	_shm_wire_clue_source
	PUBLIC	_shm_menu_face
	PUBLIC	_asm_alarms
	PUBLIC	_shm_regs
	PUBLIC	_asm_DAT_1a63_7636
	PUBLIC	_asm_seconds_left
	PUBLIC	_shm_building_count
	PUBLIC	_shm_clue_method
	PUBLIC	_shm_mission
	PUBLIC	_shm_graphics_letter
	PUBLIC	_shm_orgs_known
	PUBLIC	_shm_menu_draw_only
	PUBLIC	_shm_finished
	PUBLIC	_asm_DAT_1a63_8274
	PUBLIC	_asm_wires_live
	PUBLIC	_shm_case_city
	PUBLIC	_asm_case_difficulty
	PUBLIC	_shm_case_org
	PUBLIC	_shm_scratch
	PUBLIC	_shm_buildings
	PUBLIC	_shm_suspects
	PUBLIC	_shm_clues_shown
	PUBLIC	_shd_clue_phrases
	PUBLIC	_shd_clue_kinds
	PUBLIC	_shd_clue_source
	PUBLIC	_shd_clock_text
	PUBLIC	_shm_pan_width
	PUBLIC	_shm_clock_minutes
	PUBLIC	_shd_subst_values
	PUBLIC	_shm_cities
	PUBLIC	_shm_suspect_count
	PUBLIC	_shm_crime_events
	PUBLIC	_shm_log_count
	PUBLIC	_shm_case_tick
	PUBLIC	_shm_crime_role_count
	PUBLIC	_shm_crime_roles
	PUBLIC	_shm_role_scan_states
	PUBLIC	_shd_first_names
	PUBLIC	_shd_last_names
	PUBLIC	_shd_scan_counts
	PUBLIC	_shd_month_names
	PUBLIC	_shm_activity
	PUBLIC	_dat_chip_outputs
	PUBLIC	_dat_neighbour_col
	PUBLIC	_dat_neighbour_row
	PUBLIC	_asm_deal_chip
	PUBLIC	_asm_deal_pins
	PUBLIC	_asm_deal_lines
	PUBLIC	_asm_column_done
	PUBLIC	_shm_faces_sprites
	PUBLIC	_asm_bugs_sprites
	PUBLIC	_asm_wire_grid
	PUBLIC	_drv_jump_gfx_set_palette
	PUBLIC	_drv_jump_gfx_show_page
	PUBLIC	_drv_jump_joy_calibrate
	PUBLIC	_shd_pan_disk
	PUBLIC	_shd_city_on_screen
	PUBLIC	_shd_drive
	PUBLIC	_shm_active_pan
	PUBLIC	_shm_menu_tick
	PUBLIC	_shm_menu_first_line
	PUBLIC	_shm_pan_playing
	PUBLIC	_shm_menu_no_pick
	PUBLIC	_shm_menu_items
	PUBLIC	_shm_menu_relayout
	PUBLIC	_shm_menu_colour_bar
	PUBLIC	_shm_menu_text_width
	PUBLIC	_shm_menu_marked
	PUBLIC	_shm_menu_face_x
	PUBLIC	_shm_menu_face_y
	PUBLIC	_shm_menu_pick
	PUBLIC	_shm_menu_line_start
	PUBLIC	_shm_menu_colour_plain
	PUBLIC	_shm_menu_colour_item
	PUBLIC	_shm_menu_lines
	PUBLIC	_shm_menu_colour_pick
	PUBLIC	_shm_menu_shortcut
	PUBLIC	_shm_menu_right
	PUBLIC	_shm_menu_bottom
	PUBLIC	_drv_jump_read_key
	PUBLIC	_drv_jump_joy_read
	PUBLIC	_shm_pan_building
	PUBLIC	_shd_joystick_dirs
	PUBLIC	_shm_joystick
	PUBLIC	_shm_jailbreak_suspect
	PUBLIC	_shm_save_block
	PUBLIC	_shm_save_offset
	PUBLIC	_shm_save_fd
	PUBLIC	_shm_campaign
	PUBLIC	_shm_case_city_1
	PUBLIC	_shm_case_city_2
	PUBLIC	_shm_crime_event_count
	PUBLIC	_shm_case_seed
	PUBLIC	_shm_case_org_1
	PUBLIC	_shm_case_org_2
	PUBLIC	_shm_global_alert_level
	PUBLIC	_shm_double_agent_cities
	PUBLIC	_shm_skills
	PUBLIC	_shm_case_spare_2
	PUBLIC	_drv_jump_gfx_text
	PUBLIC	_drv_real_draw_line
	PUBLIC	_shd_archive_fd
	PUBLIC	_shm_seed
	PUBLIC	_drv_jump_gfx_row_put
	PUBLIC	_drv_jump_gfx_sprite_end
	PUBLIC	_drv_jump_gfx_sprite_row
	PUBLIC	_drv_jump_gfx_sprite_begin
	PUBLIC	_drv_real_unpack_start
	PUBLIC	_drv_real_palette_read
	PUBLIC	_drv_real_palette_put
	PUBLIC	_drv_real_unpack_row
	PUBLIC	_shd_archive_buffer_end
	PUBLIC	_shm_source_fd
	PUBLIC	_shm_source_dst
	PUBLIC	_shm_source_src
	PUBLIC	_shm_sprite_width
	PUBLIC	_shm_sprite_height
	PUBLIC	_shm_palette_count
	PUBLIC	_shm_source_at
	PUBLIC	_shm_refill
	PUBLIC	_asm_DAT_1a63_7db8
	PUBLIC	_shm_archive_buffer
	PUBLIC	_drv_real_FUN_1000_0002
	PUBLIC	_shd_disk_letter
	PUBLIC	_shd_disk_names
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
	PUBLIC	_shm_orgs
	PUBLIC	_shd_str_in_4
	PUBLIC	_shd_str_on_2
	PUBLIC	_shd_str_space_10
	PUBLIC	_shd_str_period_3
	PUBLIC	_asm_block_21eb
	PUBLIC	_shd_subst_keys
	PUBLIC	_shd_str_sloc00
	PUBLIC	_shd_str_rloc00
	PUBLIC	_shd_str_sorg00
	PUBLIC	_shd_str_rorg00
	PUBLIC	_shd_str_fluf00
	PUBLIC	_shd_str_aidd00
	PUBLIC	_shd_list_printout
	PUBLIC	_shm_log
	PUBLIC	_shm_crime_block
	PUBLIC	_dat_str_car_tracer
	PUBLIC	_dat_str_complete
	PUBLIC	_dat_str_alarm
	PUBLIC	_dat_str_phone_taps_completed
	PUBLIC	_dat_str_car_tracer_installed
	PUBLIC	_dat_str_time_expired
	PUBLIC	_dat_str_phones_tapped
	PUBLIC	_dat_str_alarms
	PUBLIC	_shd_str_coded_message
	PUBLIC	_shd_str_meeting_notes
	PUBLIC	_shd_str_new_information
	PUBLIC	_shd_str_additional_information
	PUBLIC	_shd_str_of_the
	PUBLIC	_shd_str_clues_txt_2
	PUBLIC	_shd_str_clues_txt
	PUBLIC	_shd_str_clue
	PUBLIC	_shd_str_none
	PUBLIC	_shd_str_please_insert_disk
	PUBLIC	_shd_str_if_3_5_insert
	PUBLIC	_shd_str_press_return_continue
	PUBLIC	_shd_str_message_not_decoded
	PUBLIC	_shd_str_more
	PUBLIC	_shd_str_facesf_pic
	PUBLIC	_shd_str_faces_pic
	PUBLIC	_dat_str_sure_want_quit_no
	PUBLIC	_dat_str_paused
	PUBLIC	_dat_str_env_sve
	PUBLIC	_dat_str_camera_pic
	PUBLIC	_dat_str_board_pic
	PUBLIC	_dat_str_env_sve_2
	PUBLIC	_shd_str_briefing_pan
	PUBLIC	_shd_str_animation_pan
	PUBLIC	_shd_str_bld
	PUBLIC	_shd_str_one_moment_please
	PUBLIC	_shd_str_sure_want_quit_no_2
	PUBLIC	_shd_str_incoming_msg
	PUBLIC	_shd_str_has_been_identified_as
	PUBLIC	_shd_str_has_been_positively
	PUBLIC	_shd_str_we_have_acquired
	PUBLIC	_shd_str_has_been_spotted
	PUBLIC	_shd_str_has_been_identified_as_org
	PUBLIC	_shd_str_we_have_obtained
	PUBLIC	_shd_str_we_have_determined_rank
	PUBLIC	_shd_str_we_found_recruiting
	PUBLIC	_shd_str_we_found_recruiting_2
	PUBLIC	_shd_str_file_error
	PUBLIC	_dat_str_bugs_pic
	PUBLIC	_shd_str_information_requires
	PUBLIC	_shd_str_hideout
	PUBLIC	_shd_str_agent
	PUBLIC	_shd_str_safehouse
	PUBLIC	_shd_str_active_cel
	PUBLIC	_shd_str_office
	PUBLIC	_shd_str_agent_3
	PUBLIC	_shd_str_master_plan
	PUBLIC	_shd_str_secret
	PUBLIC	_shd_str_arrested_upper
	PUBLIC	_shd_str_hiding_upper
	PUBLIC	_shd_str_turned_upper
	PUBLIC	_shd_str_personnel_file
	PUBLIC	_shd_str_action_team
	PUBLIC	_shd_str_no_activity
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
	PUBLIC	_asm_number_digits
	PUBLIC	_dat_str_no
	PUBLIC	_shd_str_space_after_name
	PUBLIC	_shd_str_dots
	PUBLIC	_shd_str_on
	PUBLIC	_shd_str_space_after_month
	PUBLIC	_shm_clue_digits
	PUBLIC	_shd_str_in
	PUBLIC	_shd_str_newline
	PUBLIC	_shd_str_empty_watch
	PUBLIC	_shd_str_space_face
	PUBLIC	_shd_str_in_2
	PUBLIC	_shd_clue_keys
	PUBLIC	_shd_str_source_2
	PUBLIC	_shd_str_slash_source
	PUBLIC	_shd_str_newline_9
	PUBLIC	_shd_str_method_stop
	PUBLIC	_shd_str_related_2
	PUBLIC	_shd_str_newline_10
	PUBLIC	_shd_str_close_paren
	PUBLIC	_shd_colours_face
	PUBLIC	_shd_colours_screen
	PUBLIC	_shd_colours_screen_2
	PUBLIC	_dat_colours_plain
	PUBLIC	_shd_palette_menu
	PUBLIC	_shd_palette_face
	PUBLIC	_shd_str_ok
	PUBLIC	_shd_colours_paper
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
	PUBLIC	_shd_str_env_sve_put
	PUBLIC	_shd_str_env_sve
	PUBLIC	_shd_str_newline_12
	PUBLIC	_shd_palette_records
	PUBLIC	_shd_str_mode_read_text
	PUBLIC	_shd_fmt_line
	PUBLIC	_shd_fmt_line_2
	PUBLIC	_shd_str_space_12
	PUBLIC	_shd_fmt_line_3
	PUBLIC	_shm_substitute_tail
	PUBLIC	_shd_str_newline_wrap
	PUBLIC	_shd_str_ellipsis_2
	PUBLIC	_shd_str_space_13
	PUBLIC	_shd_str_comma_3
	PUBLIC	_shd_str_empty_message
	PUBLIC	_shd_str_mark_80
	PUBLIC	_shm_message_key
	PUBLIC	_shd_str_mark_8f

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
	mov	word ptr ds:[drv_DAT_1a63_0042],es
	mov	word ptr ds:[drv_DAT_1a63_0044],bx
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
	mov	ds,word ptr ds:[drv_DAT_1a63_0042]
	mov	dx,word ptr ds:[drv_DAT_1a63_0044]
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
	cmp	byte ptr ds:[drv_DAT_1a63_2f0b],0
	jnz	L10169
	pop	word ptr cs:[L10164+3]
	jmp	short L10164
L10164:
	; The target is patched in by the POP above.
	jmp	dword ptr cs:[0]
L10169:
	mov	byte ptr ds:[drv_DAT_1a63_2f0a],1
	pop	word ptr cs:[L1017d+3]
	pop	word ptr ds:[drv_DAT_1a63_2f0c]
	pop	word ptr ds:[drv_DAT_1a63_2f0e]
	jmp	short L1017d
L1017d:
	; The target is patched in by the POP above.
	call	dword ptr cs:[0]
	dec	byte ptr ds:[drv_DAT_1a63_2f0a]
	jz	L10192
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_1a63_2f0a],0
L10192:
	jmp	dword ptr ds:[drv_DAT_1a63_2f0c]
drv_real_dispatch	ENDP
D10196	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0

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
D101ce	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0

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
	mov	word ptr ds:[drv_DAT_1a63_2f10],dx
	mov	word ptr ds:[drv_DAT_1a63_2f12],bx
	mov	ah,48h
	mov	bx,0FFFFh
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jc	L104c3
	mov	dx,OFFSET DGROUP:dat_message_pool
	jmp	drv_real_FUN_1000_055c
L104c3:
	mov	ah,48h
	sub	bx,100h
	mov	word ptr ds:[drv_DAT_1a63_2f16],bx
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jnc	L104d7
	mov	dx,OFFSET DGROUP:dat_str_ms_dos_lied_us
	jmp	drv_real_FUN_1000_055c
L104d7:
	mov	bx,OFFSET DGROUP:drv_DAT_1a63_2f18
	mov	word ptr [bx],ax
	mov	word ptr [bx+2],ax
	mov	ax,4B03h
	mov	dx,word ptr ds:[drv_DAT_1a63_2f10]
	push	ds
	pop	es
	mov	word ptr ds:[drv_DAT_1a63_2f14],sp
	int	21h		; DOS AH=4Bh AL=03h: load overlay
	mov	dx,DGROUP
	mov	ds,dx
	mov	es,dx
	mov	ss,dx
	mov	sp,word ptr ds:[drv_DAT_1a63_2f14]
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
	mov	es,word ptr ds:[drv_DAT_1a63_2f18]
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
	cmp	bx,word ptr ds:[drv_DAT_1a63_2f16]
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
	mov	dx,word ptr ds:[drv_DAT_1a63_2f12]
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
	mov	word ptr ds:[drv_DAT_1a63_33b3],si
	mov	cx,word ptr [bp+0Eh]
	shl	si,1
	lea	di,[drv_DAT_1a63_303f]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	mov	dx,cx
	rep stosw
	mov	cx,dx
	lea	di,[drv_DAT_1a63_31f7]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	add	ax,word ptr [bp+0Ch]
	dec	ax
	rep stosw
	mov	ax,word ptr [bp+10h]
	call	far ptr drv_jump_gfx_set_colour
	mov	ax,ds:[drv_DAT_1a63_33b3]
	mov	cx,ax
	add	cx,word ptr [bp+0Eh]
	dec	cx
	mov	word ptr ds:[drv_DAT_1a63_33b5],cx
	mov	bx,OFFSET DGROUP:drv_DAT_1a63_303f
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
	mov	ax,ds:[drv_DAT_1a63_33b3]
	mov	cx,word ptr ds:[drv_DAT_1a63_33b5]
	mov	bx,OFFSET DGROUP:drv_DAT_1a63_303f
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
	mov	di,word ptr ds:[drv_DAT_1a63_33b3]
	or	di,di
	js	L106bf
	mov	cx,word ptr ds:[drv_DAT_1a63_33b5]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,OFFSET DGROUP:drv_DAT_1a63_303f
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[drv_DAT_1a63_33b3],ax
	mov	cx,bx
	mov	di,dx
	add	di,OFFSET DGROUP:drv_DAT_1a63_31f7
	sub	ax,ax
	rep stosw
	mov	ds:[drv_DAT_1a63_33b5],ax
L106bf:
	ret
drv_real_FUN_1000_068a	ENDP

drv_real_FUN_1000_06c0	PROC	NEAR
	mov	ax,DGROUP
	mov	es,ax
	mov	cx,di
	or	si,si
	lea	di,[drv_DAT_1a63_303f]
	jz	L106d9
	cmp	si,word ptr ds:[drv_DAT_1a63_33c5]
	jnz	L1071a
	lea	di,[drv_DAT_1a63_31f7]
L106d9:
	cmp	cx,dx
	jge	L106df
	xchg	cx,dx
L106df:
	or	dx,dx
	jns	L106e5
	sub	dx,dx
L106e5:
	cmp	cx,word ptr ds:[drv_DAT_1a63_33c7]
	jle	L106ef
	mov	cx,word ptr ds:[drv_DAT_1a63_33c7]
L106ef:
	add	si,word ptr ds:[drv_DAT_1a63_33b7]
	add	cx,word ptr ds:[drv_DAT_1a63_33b9]
	add	dx,word ptr ds:[drv_DAT_1a63_33b9]
	cmp	cx,word ptr ds:[drv_DAT_1a63_33b5]
	jbe	L10705
	mov	word ptr ds:[drv_DAT_1a63_33b5],cx
L10705:
	cmp	dx,word ptr ds:[drv_DAT_1a63_33b3]
	jnc	L1070f
	mov	word ptr ds:[drv_DAT_1a63_33b3],dx
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
	mov	si,word ptr ds:[drv_DAT_1a63_33c5]
	cmp	bx,si
	jg	drv_real_FUN_1000_06c0
	ret
drv_real_FUN_1000_071b	ENDP

drv_real_FUN_1000_072a	PROC	NEAR
	mov	ax,ds:[drv_DAT_1a63_33b7]
	add	word ptr ds:[drv_DAT_1a63_3037],ax
	add	word ptr ds:[drv_DAT_1a63_3039],ax
	mov	ax,ds:[drv_DAT_1a63_33b9]
	add	word ptr ds:[drv_DAT_1a63_303b],ax
	add	word ptr ds:[drv_DAT_1a63_303d],ax
	mov	ax,ds:[drv_DAT_1a63_3039]
	cmp	ax,word ptr ds:[drv_DAT_1a63_3037]
	jnc	L10762
	mov	bx,word ptr ds:[drv_DAT_1a63_3037]
	mov	word ptr ds:[drv_DAT_1a63_3039],bx
	mov	ds:[drv_DAT_1a63_3037],ax
	mov	ax,ds:[drv_DAT_1a63_303d]
	mov	bx,word ptr ds:[drv_DAT_1a63_303b]
	mov	word ptr ds:[drv_DAT_1a63_303d],bx
	mov	ds:[drv_DAT_1a63_303b],ax
L10762:
	mov	bx,word ptr ds:[drv_DAT_1a63_3039]
	sub	bx,word ptr ds:[drv_DAT_1a63_3037]
	mov	word ptr ds:[drv_DAT_1a63_33af],bx
	mov	ax,ds:[drv_DAT_1a63_303d]
	mov	dx,ax
	mov	cx,word ptr ds:[drv_DAT_1a63_303b]
	sub	ax,cx
	mov	bp,2
	jns	L10784
	xchg	cx,dx
	neg	bp
	neg	ax
L10784:
	mov	ds:[drv_DAT_1a63_33b1],ax
	cmp	dx,word ptr ds:[drv_DAT_1a63_33b5]
	jbe	L10791
	mov	word ptr ds:[drv_DAT_1a63_33b5],dx
L10791:
	cmp	cx,word ptr ds:[drv_DAT_1a63_33b3]
	jnc	L1079b
	mov	word ptr ds:[drv_DAT_1a63_33b3],cx
L1079b:
	cmp	ax,bx
	jnc	drv_real_FUN_1000_07ea
	mov	di,word ptr ds:[drv_DAT_1a63_303b]
	shl	di,1
	mov	ax,ds:[drv_DAT_1a63_3037]
	mov	dx,word ptr ds:[drv_DAT_1a63_33af]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[drv_DAT_1a63_33b1]
	jmp	L107cb
L107bc:
	cmp	ax,word ptr [di+drv_DAT_1a63_31f7]
	jbe	L107c6
	mov	word ptr [di+drv_DAT_1a63_31f7],ax
L107c6:
	inc	ax
	sub	bx,dx
	add	di,bp
L107cb:
	cmp	ax,word ptr [di+drv_DAT_1a63_303f]
	jnc	L107d5
	mov	word ptr [di+drv_DAT_1a63_303f],ax
L107d5:
	dec	cx
	js	L107df
	add	bx,si
	jns	L107bc
	inc	ax
	jmp	L107d5
L107df:
	cmp	ax,word ptr [di+drv_DAT_1a63_31f7]
	jbe	L107e9
	mov	word ptr [di+drv_DAT_1a63_31f7],ax
L107e9:
	ret
drv_real_FUN_1000_072a	ENDP

drv_real_FUN_1000_07ea	PROC	NEAR
	mov	di,word ptr ds:[drv_DAT_1a63_303b]
	shl	di,1
	mov	ax,ds:[drv_DAT_1a63_3037]
	mov	dx,word ptr ds:[drv_DAT_1a63_33b1]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[drv_DAT_1a63_33af]
L10804:
	cmp	ax,word ptr [di+drv_DAT_1a63_303f]
	jnc	L1080e
	mov	word ptr [di+drv_DAT_1a63_303f],ax
L1080e:
	cmp	ax,word ptr [di+drv_DAT_1a63_31f7]
	jbe	L10818
	mov	word ptr [di+drv_DAT_1a63_31f7],ax
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
	mov	ax,ds:[drv_DAT_1a63_3037]
	mov	bx,word ptr ds:[drv_DAT_1a63_303b]
	mov	cx,word ptr ds:[drv_DAT_1a63_3039]
	mov	dx,word ptr ds:[drv_DAT_1a63_303d]
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
	mov	word ptr ds:[drv_DAT_1a63_33bd],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_1a63_33c1],dx
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
	sar	word ptr ds:[drv_DAT_1a63_33bd],1
	sar	word ptr ds:[drv_DAT_1a63_33c1],1
	jmp	L1091b
L108be:
	jmp	L10880
L108c0:
	mov	cx,word ptr ds:[drv_DAT_1a63_3037]
	mov	dx,word ptr ds:[drv_DAT_1a63_303b]
	mov	si,word ptr ds:[drv_DAT_1a63_3039]
	mov	di,word ptr ds:[drv_DAT_1a63_303d]
	mov	bx,cx
	mov	bp,dx
	call	drv_real_FUN_1000_09c4
	mov	ds:[drv_DAT_1a63_33bc],al
	mov	bx,si
	mov	bp,di
	call	drv_real_FUN_1000_09c4
	jnz	L108fd
	cmp	byte ptr ds:[drv_DAT_1a63_33bc],0
	jnz	L108ed
	jmp	L1085a
L108ed:
	xchg	cx,si
	xchg	dx,di
	xchg	byte ptr ds:[drv_DAT_1a63_33bc],al
	mov	word ptr ds:[drv_DAT_1a63_3037],cx
	mov	word ptr ds:[drv_DAT_1a63_303b],dx
L108fd:
	test	byte ptr ds:[drv_DAT_1a63_33bc],al
	jnz	L108be
	mov	bp,dx
	mov	dx,si
	sub	dx,cx
	jo	L10892
	mov	word ptr ds:[drv_DAT_1a63_33bd],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_1a63_33c1],dx
	mov	dx,di
	sub	dx,bp
	jo	L108b0
L1091b:
	mov	word ptr ds:[drv_DAT_1a63_33bf],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_1a63_33c3],dx
L10925:
	test	al,9
	jz	L10961
	sub	bx,bx
	or	si,si
	js	L10933
	mov	bx,word ptr ds:[drv_DAT_1a63_33c5]
L10933:
	mov	ax,bx
	sub	ax,cx
	imul	word ptr ds:[drv_DAT_1a63_33bf]
	push	bx
	mov	bx,dx
	idiv	word ptr ds:[drv_DAT_1a63_33bd]
	mov	bl,bh
	xor	bl,byte ptr ds:[drv_DAT_1a63_33bd+1]
	jns	L1094d
	neg	dx
	dec	ax
L1094d:
	sub	dx,word ptr ds:[drv_DAT_1a63_33c1]
	xor	dh,bh
	js	L10956
	inc	ax
L10956:
	pop	bx
	add	ax,bp
	js	L10969
	cmp	ax,word ptr ds:[drv_DAT_1a63_33c7]
	jle	L1099a
L10961:
	mov	bx,word ptr ds:[drv_DAT_1a63_33c7]
	cmp	di,bx
	jg	L1096b
L10969:
	sub	bx,bx
L1096b:
	mov	ax,bx
	sub	ax,bp
	imul	word ptr ds:[drv_DAT_1a63_33bd]
	push	bx
	mov	bx,dx
L10976:
	idiv	word ptr ds:[drv_DAT_1a63_33bf]
	mov	bl,bh
	xor	bl,byte ptr ds:[drv_DAT_1a63_33bf+1]
	jns	L10985
	neg	dx
	dec	ax
L10985:
	sub	dx,word ptr ds:[drv_DAT_1a63_33c3]
	xor	dh,bh
	js	L1098e
	inc	ax
L1098e:
	pop	bx
	add	ax,cx
	js	L109ab
	cmp	ax,word ptr ds:[drv_DAT_1a63_33c5]
	jg	L109ab
	xchg	bx,ax
L1099a:
	cmp	byte ptr ds:[drv_DAT_1a63_33bc],0
	jnz	L109ae
	mov	ds:[drv_DAT_1a63_303d],ax
	mov	word ptr ds:[drv_DAT_1a63_3039],bx
	jmp	L1085a
L109ab:
	jmp	L10880
L109ae:
	mov	ds:[drv_DAT_1a63_303b],ax
	mov	word ptr ds:[drv_DAT_1a63_3037],bx
	xchg	cx,si
	xchg	bp,di
	mov	al,ds:[drv_DAT_1a63_33bc]
	mov	byte ptr ds:[drv_DAT_1a63_33bc],0
	jmp	L10925
drv_real_FUN_1000_0838	ENDP

drv_real_FUN_1000_09c4	PROC	NEAR
	mov	al,0Fh
	or	bx,bx
	js	L109cc
	and	al,0F7h
L109cc:
	cmp	bx,word ptr ds:[drv_DAT_1a63_33c5]
	jg	L109d4
	and	al,0FEh
L109d4:
	or	bp,bp
	js	L109da
	and	al,0FBh
L109da:
	cmp	bp,word ptr ds:[drv_DAT_1a63_33c7]
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
	mov	ax,ds:[drv_DAT_1a63_33bf]
	jz	L109f5
	mov	ax,ds:[drv_DAT_1a63_33bd]
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
	mov	ds:[drv_DAT_1a63_33c5],ax
	mov	ax,word ptr [bx+8]
	mov	ds:[drv_DAT_1a63_33c7],ax
	call	far ptr drv_jump_gfx_select_pic
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_1a63_3037],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_1a63_303b],ax
	mov	ax,word ptr [bp+0Ch]
	mov	ds:[drv_DAT_1a63_3039],ax
	mov	ax,word ptr [bp+0Eh]
	mov	ds:[drv_DAT_1a63_303d],ax
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
	mov	ds:[drv_DAT_1a63_5311],al
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
	mov	ds:[drv_DAT_1a63_5311],al
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
	mov	byte ptr ds:[drv_DAT_1a63_5306],0
	mov	byte ptr ds:[drv_DAT_1a63_5307],0
	mov	ax,OFFSET DGROUP:asm_block_5315+512
	mov	ds:[drv_DAT_1a63_5302],ax
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
	mov	ds:[drv_DAT_1a63_5309],al
	mov	ds:[drv_DAT_1a63_530e],ax
	mov	byte ptr ds:[drv_DAT_1a63_5310],8
drv_real_FUN_1000_0b9b	ENDP

drv_real_FUN_1000_0bd9	PROC	NEAR
	mov	byte ptr ds:[drv_DAT_1a63_5308],9
	mov	word ptr ds:[drv_DAT_1a63_530a],1FFh
	mov	dx,100h
	mov	word ptr ds:[drv_DAT_1a63_530c],dx
	mov	ax,0FFFFh
	xor	bx,bx
	mov	cx,800h
L10bf3:
	mov	word ptr [bx+drv_DAT_1a63_3afc],ax
	add	bx,3
	loop	L10bf3
	mov	al,0
	xor	bx,bx
	mov	cx,100h
L10c03:
	mov	byte ptr [bx+drv_DAT_1a63_3afe],al
	inc	al
	add	bx,3
	loop	L10c03
	ret
drv_real_FUN_1000_0bd9	ENDP

drv_real_FUN_1000_0c0f	PROC	NEAR
	cmp	byte ptr ds:[drv_DAT_1a63_5311],0
	jz	L10c19
	inc	cx
	shr	cx,1
L10c19:
	mov	word ptr ds:[drv_DAT_1a63_5304],cx
	mov	ax,ds:[drv_DAT_1a63_5302]
	mov	word ptr ds:[drv_DAT_1a63_5302],sp
	mov	sp,ax
	mov	dx,word ptr ds:[drv_DAT_1a63_530c]
L10c2a:
	cmp	byte ptr ds:[drv_DAT_1a63_5306],0
	jnz	L10c52
	call	drv_real_FUN_1000_0c8b
	cmp	al,90h
	jz	L10c3e
	mov	ds:[drv_DAT_1a63_5307],al
	jmp	L10c59
L10c3e:
	call	drv_real_FUN_1000_0c8b
	or	al,al
	jnz	L10c4d
	mov	al,90h
	mov	ds:[drv_DAT_1a63_5307],al
	jmp	L10c59
L10c4d:
	dec	al
	mov	ds:[drv_DAT_1a63_5306],al
L10c52:
	mov	al,ds:[drv_DAT_1a63_5307]
	dec	byte ptr ds:[drv_DAT_1a63_5306]
L10c59:
	cmp	byte ptr ds:[drv_DAT_1a63_5311],0
	jz	L10c76
	mov	ah,al
	and	al,0Fh
	shr	ah,1
	shr	ah,1
	shr	ah,1
	shr	ah,1
	stosw
	dec	word ptr ds:[drv_DAT_1a63_5304]
	jnz	L10c2a
	jmp	L10c7d
L10c76:
	stosb
	dec	word ptr ds:[drv_DAT_1a63_5304]
	jnz	L10c2a
L10c7d:
	mov	word ptr ds:[drv_DAT_1a63_530c],dx
	mov	ax,ds:[drv_DAT_1a63_5302]
	mov	word ptr ds:[drv_DAT_1a63_5302],sp
	mov	sp,ax
	ret
drv_real_FUN_1000_0c0f	ENDP

drv_real_FUN_1000_0c8b	PROC	NEAR
	pop	bp
	cmp	sp,OFFSET DGROUP:asm_block_5315+512
	jz	L10c95
L10c92:
	pop	ax
	jmp	bp
L10c95:
	mov	bx,word ptr ds:[drv_DAT_1a63_530e]
	mov	cl,10h
	mov	ch,byte ptr ds:[drv_DAT_1a63_5310]
	sub	cl,ch
	shr	bx,cl
	mov	cl,ch
L10ca5:
	cmp	cl,byte ptr ds:[drv_DAT_1a63_5308]
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
	mov	ds:[drv_DAT_1a63_530e],ax
	shl	ax,cl
	or	bx,ax
	add	cl,10h
	jmp	L10ca5
L10ccc:
	sub	cl,byte ptr ds:[drv_DAT_1a63_5308]
	mov	byte ptr ds:[drv_DAT_1a63_5310],cl
	mov	ax,bx
	and	ax,word ptr ds:[drv_DAT_1a63_530a]
	mov	cx,ax
	cmp	ax,dx
	jl	L10cea
	mov	cx,dx
	mov	ax,ds:[drv_DAT_1a63_5312]
	mov	bl,byte ptr ds:[drv_DAT_1a63_5314]
	push	bx
L10cea:
	mov	bx,ax
	add	bx,ax
	add	bx,ax
	mov	ax,word ptr [bx+drv_DAT_1a63_3afc]
	inc	ax
	jz	L10cff
	dec	ax
	mov	bl,byte ptr [bx+drv_DAT_1a63_3afe]
	push	bx
	jmp	L10cea
L10cff:
	mov	al,byte ptr [bx+drv_DAT_1a63_3afe]
	mov	ds:[drv_DAT_1a63_5314],al
	push	ax
	mov	bx,dx
	add	bx,dx
	add	bx,dx
	mov	byte ptr [bx+drv_DAT_1a63_3afe],al
	mov	ax,ds:[drv_DAT_1a63_5312]
	mov	word ptr [bx+drv_DAT_1a63_3afc],ax
	inc	dx
	cmp	dx,word ptr ds:[drv_DAT_1a63_530a]
	jle	L10d28
	inc	byte ptr ds:[drv_DAT_1a63_5308]
	stc
	rcl	word ptr ds:[drv_DAT_1a63_530a],1
L10d28:
	mov	al,ds:[drv_DAT_1a63_5308]
	cmp	al,byte ptr ds:[drv_DAT_1a63_5309]
	jle	L10d34
	call	drv_real_FUN_1000_0bd9
L10d34:
	mov	word ptr ds:[drv_DAT_1a63_5312],cx
	jmp	L10c92
drv_real_FUN_1000_0c8b	ENDP
D10d3b	DB	0

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
	mov	word ptr ds:[drv_DAT_1a63_33d8],0
	cmp	cx,0C8h
	jc	L10d7e
	shr	cx,1
	mov	word ptr ds:[drv_DAT_1a63_33d8],1
L10d7e:
	mov	word ptr ds:[drv_DAT_1a63_33ce],bx
	mov	word ptr ds:[drv_DAT_1a63_33ca],cx
	mov	word ptr ds:[drv_DAT_1a63_33cc],dx
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
	xchg	word ptr ds:[drv_DAT_1a63_33d0],ax
	retf
drv_real_FUN_1000_0da6	ENDP

;------------------------------------------------------------------------------
; Set the cursor's hot spot and which shape to draw.
;------------------------------------------------------------------------------
drv_real_mouse_set_cursor	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	ds:[drv_DAT_1a63_33d4],ax
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_1a63_33d6],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_1a63_33d2],ax
	pop	bp
	retf
drv_real_mouse_set_cursor	ENDP

drv_real_FUN_1000_0dc4	PROC	FAR
	mov	byte ptr ds:[drv_DAT_1a63_2f0b],0
	call	far ptr drv_jump_gfx_overlay_remove
	retf
drv_real_FUN_1000_0dc4	ENDP

;------------------------------------------------------------------------------
; Draw the cursor at the position the last event left, and record that it is
; on.
;------------------------------------------------------------------------------
drv_real_cursor_show	PROC	FAR
	push	word ptr ds:[drv_DAT_1a63_33d2]
	mov	ax,ds:[drv_DAT_1a63_33cc]
	sub	ax,word ptr ds:[drv_DAT_1a63_33d6]
	push	ax
	mov	ax,ds:[drv_DAT_1a63_33ca]
	sub	ax,word ptr ds:[drv_DAT_1a63_33d4]
	push	ax
	call	far ptr drv_jump_gfx_overlay_put
	add	sp,6
	mov	byte ptr ds:[drv_DAT_1a63_2f0b],1
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
	mov	ds:[drv_DAT_1a63_33da],ax
	mov	word ptr ds:[drv_DAT_1a63_33dc],bx
	mov	word ptr ds:[drv_DAT_1a63_33de],cx
	mov	word ptr ds:[drv_DAT_1a63_33e0],dx
	lea	ax,[drv_DAT_1a63_33da]
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
	push	word ptr ds:[drv_DAT_1a63_33d2]
	mov	ax,ds:[drv_DAT_1a63_33cc]
	sub	ax,word ptr ds:[drv_DAT_1a63_33d6]
	push	ax
	mov	ax,ds:[drv_DAT_1a63_33ca]
	sub	ax,word ptr ds:[drv_DAT_1a63_33d4]
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
	cmp	word ptr ds:[drv_DAT_1a63_33d8],0
	jz	L10e57
	shr	cx,1
L10e57:
	or	word ptr ds:[drv_DAT_1a63_33d0],bx
	mov	word ptr ds:[drv_DAT_1a63_33ce],bx
	mov	word ptr ds:[drv_DAT_1a63_33ca],cx
	mov	word ptr ds:[drv_DAT_1a63_33cc],dx
	test	ax,1
	jz	L10e87
	cmp	byte ptr ds:[drv_DAT_1a63_2f0b],0
	jz	L10e87
	mov	al,2
	xchg	byte ptr ds:[drv_DAT_1a63_2f0a],al
	or	al,al
	jnz	L10e87
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_1a63_2f0a],0
L10e87:
	retf
drv_real_mouse_event	ENDP

CODE_0	ENDS

;==============================================================================
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:_TEXT, ds:DGROUP, ss:DGROUP

;;SPLIT main

;;SPLIT FUN_10e8_020d

;;SPLIT FUN_10e8_020e

;;SPLIT FUN_10e8_0225

;;SPLIT FUN_10e8_0244

;;SPLIT FUN_10e8_0287

;;SPLIT FUN_10e8_0288

;;SPLIT FUN_10e8_029a

;;SPLIT FUN_10e8_029c

;;SPLIT FUN_10e8_02bc

;;SPLIT FUN_10e8_02dc

;;SPLIT FUN_10e8_0395

;;SPLIT FUN_10e8_09cc

;;SPLIT FUN_10e8_0efd

;;SPLIT FUN_10e8_0ff1

;;SPLIT FUN_10e8_1077

;;SPLIT FUN_10e8_10bc

;;SPLIT FUN_10e8_14e8

;;SPLIT FUN_10e8_153e

;;SPLIT FUN_10e8_15ff

;;SPLIT FUN_10e8_1613

;;SPLIT FUN_10e8_17bb

;;SPLIT FUN_10e8_186b

;;SPLIT FUN_10e8_1882

;;SPLIT FUN_10e8_2175

;;SPLIT FUN_10e8_22ad

;;SPLIT FUN_10e8_22e0

;;SPLIT FUN_10e8_25ce

;;SPLIT FUN_10e8_2627

;;SPLIT FUN_10e8_272b

;;SPLIT FUN_10e8_27cc

;;SPLIT FUN_10e8_282e

;;SPLIT FUN_10e8_28c5

;;SPLIT FUN_10e8_2911

;;SPLIT FUN_10e8_2c6f

;;SPLIT FUN_10e8_2d22

;;SPLIT FUN_10e8_2def

;;SPLIT FUN_10e8_2e58

;;SPLIT FUN_10e8_2e8f

;;SPLIT FUN_10e8_2f44

;;SPLIT FUN_10e8_2fc9

;;SPLIT FUN_10e8_2fe9

;;SPLIT FUN_10e8_31b8

;;SPLIT FUN_10e8_37fd

;;SPLIT FUN_10e8_3b26

;;SPLIT FUN_10e8_3b43

;;SPLIT FUN_10e8_3c2f

;;SPLIT FUN_10e8_3c9e

;;SPLIT FUN_10e8_3f93

;;SPLIT FUN_10e8_3fc8

;;SPLIT FUN_10e8_406d

;;SPLIT FUN_10e8_40c4

;;SPLIT FUN_10e8_4134

;;SPLIT FUN_10e8_429d

;;SPLIT FUN_10e8_44ad

;;SPLIT FUN_10e8_4696

;;SPLIT FUN_10e8_471a

;;SPLIT FUN_10e8_4805

;;SPLIT FUN_10e8_48e9

;;SPLIT FUN_10e8_495d

;;SPLIT FUN_10e8_49b9

;;SPLIT FUN_10e8_4a1e

;;SPLIT FUN_10e8_4a9d

;;SPLIT FUN_10e8_4b50

;;SPLIT FUN_10e8_4b98

;;SPLIT FUN_10e8_4c22

;;SPLIT FUN_10e8_4ee2

;;SPLIT FUN_10e8_5029

;;SPLIT FUN_10e8_50e5

;;SPLIT FUN_10e8_5171

;;SPLIT FUN_10e8_51b6

;;SPLIT FUN_10e8_5227

;;SPLIT FUN_10e8_5262

;;SPLIT FUN_10e8_5371

;;SPLIT FUN_10e8_5727

;;SPLIT FUN_10e8_58b2

;;SPLIT FUN_10e8_5d81

;;SPLIT FUN_10e8_6132

;;SPLIT FUN_10e8_618a

;;SPLIT FUN_10e8_61e3

;;SPLIT FUN_10e8_62a4

;;SPLIT FUN_10e8_62f6

;;SPLIT FUN_10e8_6427

;;SPLIT FUN_10e8_6450

;;SPLIT FUN_10e8_6483

;;SPLIT FUN_10e8_6500

;;SPLIT FUN_10e8_657c

;;SPLIT FUN_10e8_659e

;;SPLIT FUN_10e8_68d3

;;SPLIT FUN_10e8_692c

;;SPLIT FUN_10e8_6985

;;SPLIT FUN_10e8_6d48

;;SPLIT FUN_10e8_6e7a

;;SPLIT FUN_10e8_6e7b

;;SPLIT FUN_10e8_6e7c

;;SPLIT FUN_10e8_6e7e

;;SPLIT FUN_10e8_6e9e

;;SPLIT FUN_10e8_6ebf

;;SPLIT FUN_10e8_6ee8

;;SPLIT FUN_10e8_6f20

;;SPLIT FUN_10e8_6f3e

;;SPLIT FUN_10e8_6f5a

;;SPLIT FUN_10e8_6f84

;;SPLIT FUN_10e8_6f9e

;;SPLIT FUN_10e8_6fb8

;;SPLIT FUN_10e8_6fcf

;;SPLIT FUN_10e8_6fe8

;;SPLIT FUN_10e8_7006

;;SPLIT FUN_10e8_7066

;;SPLIT FUN_10e8_7090

;;SPLIT FUN_10e8_70b4

;;SPLIT FUN_10e8_70f8

;;SPLIT FUN_10e8_713e

;;SPLIT FUN_10e8_7180

;;SPLIT FUN_10e8_71e4

;;SPLIT FUN_10e8_7224

;;SPLIT FUN_10e8_7290

;;SPLIT FUN_10e8_72a2

;;SPLIT FUN_10e8_72fe

;;SPLIT FUN_10e8_7362

;;SPLIT FUN_10e8_7380

;;SPLIT FUN_10e8_73b4

;;SPLIT FUN_10e8_73c4

;;SPLIT FUN_10e8_73ec

;;SPLIT FUN_10e8_740e

;;SPLIT FUN_10e8_743e

;;SPLIT FUN_10e8_746e

;;SPLIT FUN_10e8_7494

;;SPLIT FUN_10e8_7554

_TEXT	ENDS

;==============================================================================
_DATA	SEGMENT	WORD PUBLIC 'DATA'
;==============================================================================
drv_DAT_1a63_0042	DB	0,0
drv_DAT_1a63_0044	DB	0,0
asm_block_0046	DB	0,0,3Fh,3Fh,3Fh,3Fh,3Fh,3Fh
	DB	3Fh,3Fh,3Fh,3Fh,3Fh,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
_dat_str_env_sve	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_camera_pic	DB	63h,61h,6Dh,65h,72h,61h,2Eh,70h
	DB	69h,63h,0
_dat_str_board_pic	DB	62h,6Fh,61h,72h,64h,2Eh,70h,69h
	DB	63h,0
_dat_str_env_sve_2	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
asm_block_0091	DB	0
_dat_neighbour_col	DB	0,0,1,0,1,0,1,0
	DB	0,0,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
_dat_neighbour_row	DB	0FFh,0FFh,0FFh,0FFh,0,0,1,0
	DB	1,0,1,0,0,0,0FFh,0FFh
_dat_chip_outputs	DB	0,0,0,0,1,0,0,0
	DB	1,0,0,0,1,0,0,0
	DB	0,0,0,0,0,0,1,0
	DB	0,0,1,0,0,0,1,0
	DB	0,0,0,0,1,0,1,0
	DB	0,0,0,0,1,0,1,0
	DB	0,0,0,0,0,0,0,0
	DB	1,0,1,0,1,0,1,0
	DB	0,0,0,0,1,0,0,0
	DB	0,0,1,0,1,0,1,0
	DB	0,0,0,0,0,0,1,0
	DB	1,0,0,0,1,0,1,0
	DB	1,0,0,0,0,0,0,0
	DB	1,0,1,0,0,0,1,0
	DB	0,0,1,0,1,0,1,0
	DB	0,0,0,0,1,0,0,0
	DB	1,0,1,0,0,0,1,0
	DB	1,0,0,0,0,0,0,0
	DB	0,0,1,0,0,0,0,0
	DB	1,0,1,0,1,0,0,0
	DB	1,0,0,0,1,0,1,0
	DB	0,0,0,0,0,0,1,0
	DB	1,0,1,0,1,0,0,0
	DB	0,0,1,0,0,0,0,0
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
asm_block_155c	DB	0,0,1,0,2,0,0,2
	DB	0,1,3,1,2,1,0,3
	DB	0,1,11h,11h,2,0,2,3
	DB	30h,11h,13h,31h,22h,23h,33h,33h
_shd_colours_screen	DB	0,0,1,0,2,0,0,2		; COLOUR_MAP
	DB	0,1,2,3,2,1,1,3
_shd_colours_screen_2	DB	0,0,11h,11h,22h,0,0,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,22h,11h,22h,33h
_dat_colours_plain	DB	0,0,11h,11h,22h,22h,22h,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,0,0,11h,33h
D1bbdc	DB	0,22h,0,0,0,0,0,0
	DB	0,22h,22h,0,0,0,11h,33h
	DB	0,12h,11h,10h,11h,0,12h,33h
	DB	22h,13h,33h,11h,33h,22h,33h,33h
	DB	0,12h,0,0,22h,0,0,13h
	DB	2,11h,0,0,0,0,33h,33h
_shd_colours_paper	DB	0,11h,11h,11h,22h,0,22h,12h		; COLOUR_MAP
	DB	0,11h,11h,33h,33h,22h,33h,33h
D1bc1c	DB	0,11h,11h,11h,22h,0,22h,12h
	DB	0,11h,11h,33h,33h,22h,33h,33h
_shd_colours_face	DB	0,11h,11h,1,22h,0,22h,22h		; COLOUR_MAP
	DB	0,11h,11h,33h,33h,33h,33h,33h
D1bc3c	DB	0,0,11h,11h,22h,0,0,11h
	DB	22h,22h,33h,33h,22h,11h,22h,33h
	DB	0,0,11h,11h,22h,0,0,22h
	DB	0,22h,33h,33h,22h,11h,22h,33h
	DB	0,0,11h,11h,22h,0,0,33h
	DB	22h,22h,11h,33h,22h,33h,22h,33h
_shd_pan_disk	DB	2,0
dat_chip_page_port	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_dat_chip_page	DW	OFFSET DGROUP:dat_chip_page_port
	PUBLIC	_shm_difficulty_word
_shm_difficulty_word	LABEL	BYTE
_shm_difficulty	DB	1,0
_shd_palette_records	DB	0,1,2,3,0Fh,0Ch,6,7		; PALETTE[5]
	DB	8,9,0Ah,0Bh,0Ch,0Fh,0Eh,0Fh
	DB	0,0,1,2,3,0Fh,0Ch,6
	DB	7,8,9,0Ah,0Bh,0Fh,0Ch,0Eh
	DB	0Fh,0,0,1,2,3,0Ch,0Fh
	DB	6,7,8,9,0Ah,0Bh,0Fh,0Ch
	DB	0Eh,0Fh,0,0,1,2,3,0Ch
	DB	0Fh,6,7,8,9,0Ah,0Bh,0Ch
	DB	0Fh,0Eh,0Fh,0,0,1,2,3
	DB	4,0,6,7,8,9,0Ah,0Bh
	DB	0Ch,0Dh,0Eh,0Fh,0
_dat_str_bugs_pic	DB	62h,75h,67h,73h,2Eh,70h,69h,63h
	DB	0
_dat_str_car_tracer	DB	43h,61h,72h,20h,74h,72h,61h,63h
	DB	65h,72h,20h,0
_dat_str_complete	DB	25h,20h,63h,6Fh,6Dh,70h,6Ch,65h
	DB	74h,65h,0Ah,0
_dat_str_alarm	DB	41h,6Ch,61h,72h,6Dh,21h,21h,21h
	DB	0Ah,0
_dat_str_phone_taps_completed	DB	50h,68h,6Fh,6Eh,65h,20h,74h,61h
	DB	70h,73h,20h,63h,6Fh,6Dh,70h,6Ch
	DB	65h,74h,65h,64h,2Eh,0Ah,0
_dat_str_car_tracer_installed	DB	43h,61h,72h,20h,74h,72h,61h,63h
	DB	65h,72h,20h,69h,6Eh,73h,74h,61h
	DB	6Ch,6Ch,65h,64h,2Eh,0Ah,0
_dat_str_time_expired	DB	54h,69h,6Dh,65h,20h,65h,78h,70h
	DB	69h,72h,65h,64h,2Eh,0Ah,0
_dat_str_phones_tapped	DB	20h,70h,68h,6Fh,6Eh,65h,73h,20h
	DB	74h,61h,70h,70h,65h,64h,2Eh,0Ah
	DB	0
_dat_str_no	DB	4Eh,6Fh,0
_dat_str_alarms	DB	20h,41h,6Ch,61h,72h,6Dh,73h,0Ah
	DB	0
_dat_str_sure_want_quit_no	DB	41h,72h,65h,20h,79h,6Fh,75h,20h
	DB	73h,75h,72h,65h,0Ah,79h,6Fh,75h
	DB	20h,77h,61h,6Eh,74h,20h,74h,6Fh
	DB	20h,51h,75h,69h,74h,3Fh,0Ah,20h
	DB	4Eh,6Fh,0Ah,20h,59h,65h,73h,0Ah
	DB	0
_dat_str_paused	DB	50h,41h,55h,53h,45h,44h,0Ah,0
	DB	0
_dat_clock_text	DB	30h,30h,3Ah,30h,30h,3Ah,30h,30h
	DB	0
asm_block_1769	DB	0
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
asm_block_1a90	DB	2,2,1,4,1,8,1,8
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
asm_block_1ad8	DB	0,0
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
	DB	74h,20h,23h,0,0
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
asm_block_207d	DB	0
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
asm_block_20b9	DB	0
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
_asm_block_21eb	DB	0
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
asm_block_2b49	DB	0
_shd_clock_text	DB	30h,30h,3Ah,30h,30h,3Ah,30h,30h
	DB	0
asm_block_2b53	DB	0
_shd_str_incoming_msg	DB	49h,6Eh,63h,6Fh,6Dh,69h,6Eh,67h
	DB	20h,4Dh,73h,67h,0
asm_block_2b61	DB	0
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
asm_block_2df1	DB	0
_shd_city_on_screen	DB	0FFh,0FFh
_shd_drive	DB	0FFh,0FFh
_shm_pan_width	DB	40h,1
asm_block_2df8	DB	1,0
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
asm_block_2e31	DB	0
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
drv_DAT_1a63_2f0a	DB	0
drv_DAT_1a63_2f0b	DB	0
drv_DAT_1a63_2f0c	DB	0,0
drv_DAT_1a63_2f0e	DB	0,0
drv_DAT_1a63_2f10	DB	0,0
drv_DAT_1a63_2f12	DB	0,0
drv_DAT_1a63_2f14	DB	0,0
drv_DAT_1a63_2f16	DB	0,0
drv_DAT_1a63_2f18	DB	0,0
drv_DAT_1a63_2f1a	DB	0,0
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
asm_block_3036	DB	0
drv_DAT_1a63_3037	DB	0,0
drv_DAT_1a63_3039	DB	0,0
drv_DAT_1a63_303b	DB	0,0
drv_DAT_1a63_303d	DB	0,0
drv_DAT_1a63_303f	DB	0FFh,0FFh
asm_block_3041	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
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
drv_DAT_1a63_31f5	DB	0FFh,0FFh
drv_DAT_1a63_31f7	DB	0,0
asm_block_31f9	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
drv_DAT_1a63_33af	DB	0,0
drv_DAT_1a63_33b1	DB	0,0
drv_DAT_1a63_33b3	DB	0FFh,0FFh
drv_DAT_1a63_33b5	DB	0,0
drv_DAT_1a63_33b7	DB	0,0
drv_DAT_1a63_33b9	DB	0,0
asm_block_33bb	DB	0
drv_DAT_1a63_33bc	DB	0
drv_DAT_1a63_33bd	DB	0,0
drv_DAT_1a63_33bf	DB	0,0
drv_DAT_1a63_33c1	DB	0,0
drv_DAT_1a63_33c3	DB	0,0
drv_DAT_1a63_33c5	DB	3Fh,1
drv_DAT_1a63_33c7	DB	6Fh,0
asm_block_33c9	DB	0
drv_DAT_1a63_33ca	DB	0,0
drv_DAT_1a63_33cc	DB	0,0
drv_DAT_1a63_33ce	DB	0,0
drv_DAT_1a63_33d0	DB	0,0
drv_DAT_1a63_33d2	DB	0,0
drv_DAT_1a63_33d4	DB	0,0
drv_DAT_1a63_33d6	DB	0,0
drv_DAT_1a63_33d8	DB	0,0
drv_DAT_1a63_33da	DB	0,0
drv_DAT_1a63_33dc	DB	0,0
drv_DAT_1a63_33de	DB	0,0
drv_DAT_1a63_33e0	DB	0,0

_DATA	ENDS

CONST	SEGMENT	WORD PUBLIC 'CONST'
asm_const_pair	DB	3,0

CONST	ENDS

_BSS	SEGMENT	WORD PUBLIC 'BSS'
asm_block_39ee	DB	0
asm_block_39ef	DB	0
asm_block_39f0	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
_asm_number_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_clue_digits	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_message_key	DB	0,0,0,0,0,0,0,0
	DB	0
asm_block_3a37	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0
_shm_active_pan	DW	0h		; the library's
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
asm_block_3a76	DB	0,0,0,0,0,0,0,0
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
asm_block_3ad2	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_save_offset	DB	0,0
_shm_save_fd	DB	0,0
asm_block_3ae6	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_source_fd	DB	0,0
_shm_source_dst	DB	0,0
_shm_source_src	DB	0,0
drv_DAT_1a63_3afc	DB	0,0
drv_DAT_1a63_3afe	DB	0
drv_DAT_1a63_3aff	DB	0,0
drv_DAT_1a63_3b01	DB	0
asm_block_3b02	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
drv_DAT_1a63_5302	DB	0,0
drv_DAT_1a63_5304	DB	0,0
drv_DAT_1a63_5306	DB	0
drv_DAT_1a63_5307	DB	0
drv_DAT_1a63_5308	DB	0
drv_DAT_1a63_5309	DB	0
drv_DAT_1a63_530a	DB	0,0
drv_DAT_1a63_530c	DB	0,0
drv_DAT_1a63_530e	DB	0,0
drv_DAT_1a63_5310	DB	0
drv_DAT_1a63_5311	DB	0
drv_DAT_1a63_5312	DB	0,0
drv_DAT_1a63_5314	DB	0
asm_block_5315	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
D1fd72	DB	202h DUP(?)
_asm_title_x	DB	2 DUP(?)
asm_block_5946	DB	2 DUP(?)
_asm_title_y	DB	2 DUP(?)
_shm_clock_minutes	DB	2 DUP(?)
_asm_deal_chip	DB	46h DUP(?)
_shm_campaign	DB	28Eh DUP(?)
_shm_seed	DB	2 DUP(?)
_asm_max_goals_reached	DB	2 DUP(?)
_asm_cursor_col	DB	2 DUP(?)
_shm_options	DB	2 DUP(?)
_asm_agent_sprite	DB	2 DUP(?)
_asm_wire_sprite	DB	2 DUP(?)
_shm_cga	DB	2 DUP(?)
_asm_cursor_row	DB	2 DUP(?)
_asm_held_chip	DB	2 DUP(?)
asm_block_5c32	DB	200h DUP(?)
_shm_cities	DB	220h DUP(?)
_shm_menu_tick	DB	2 DUP(?)
_shm_suspect_count	DB	2 DUP(?)
_asm_board_stage	DB	2 DUP(?)
_shm_log	DB	700h DUP(?)
_shm_menu_face	DB	2 DUP(?)
_asm_score	DB	2 DUP(?)
_asm_frame_count	DB	2 DUP(?)
_shm_wire_clue_source	DB	2 DUP(?)
_shm_crime_events	DB	0B00h DUP(?)
_shm_log_count	DB	2 DUP(?)
_shm_menu_first_line	DB	2 DUP(?)
asm_block_7264	DB	4 DUP(?)
_shm_building_count	DB	2 DUP(?)
_shm_case_tick	DB	2 DUP(?)
asm_block_726c	DB	2 DUP(?)
_shm_source_at	DB	2 DUP(?)
_shm_case_city_1	DB	2 DUP(?)
_shm_case_city_2	DB	2 DUP(?)
	PUBLIC	__bufin
__bufin	LABEL	BYTE
asm_block_7274	DB	200h DUP(?)
_shm_pan_playing	DB	2 DUP(?)
_shm_menu_no_pick	DB	2 DUP(?)
asm_block_7478	DB	2 DUP(?)
_asm_alarms	DB	2 DUP(?)
_shm_menu_items	DB	2 DUP(?)
_asm_deal_pins	DB	78h DUP(?)
asm_block_74f6	DB	14h DUP(?)
_asm_deal_lines	DB	118h DUP(?)
_asm_column_done	DB	14h DUP(?)
_asm_DAT_1a63_7636	DB	2 DUP(?)
_shm_crime_event_count	DB	2 DUP(?)
_shm_case_seed	DB	2 DUP(?)
_shm_clue_method	DB	2 DUP(?)
_shm_menu_relayout	DB	2 DUP(?)
_shm_mission	DB	2 DUP(?)
_shm_menu_colour_bar	DB	2 DUP(?)
_shm_case_org_1	DB	2 DUP(?)
_shm_menu_text_width	DB	2 DUP(?)
asm_block_7648	DB	2 DUP(?)
_shm_case_org_2	DB	2 DUP(?)
_shm_faces_sprites	DB	0E8h DUP(?)
asm_block_7734	DB	8 DUP(?)
_asm_bugs_sprites	DB	58h DUP(?)
asm_block_7794	DB	8 DUP(?)
_shm_global_alert_level	DB	2 DUP(?)
_shm_regs	DB	0Eh DUP(?)
_shm_double_agent_cities	DB	2 DUP(?)
asm_block_77ae	DB	2 DUP(?)
_shm_crime_role_count	DB	2 DUP(?)
_shm_menu_marked	DB	2 DUP(?)
_shm_crime_roles	DB	600h DUP(?)
_asm_seconds_left	DB	2 DUP(?)
_shm_refill	DB	2 DUP(?)
_asm_DAT_1a63_7db8	DB	2 DUP(?)
_shm_archive_buffer	DB	200h DUP(?)
_shm_menu_face_x	DB	2 DUP(?)
_shm_menu_draw_only	DB	2 DUP(?)
_shm_skills	DB	2 DUP(?)
_shm_orgs	DB	240h DUP(?)
_shm_menu_face_y	DB	2 DUP(?)
asm_block_8202	DB	4 DUP(?)
_shm_finished	DB	2 DUP(?)
_shm_menu_shortcut	DB	20h DUP(?)
_shm_menu_pick	DB	2 DUP(?)
asm_block_822a	DB	2 DUP(?)
_shm_crime_block	DB	48h DUP(?)
_asm_DAT_1a63_8274	DB	2 DUP(?)
_shm_menu_right	DB	2 DUP(?)
_shm_substitute_tail	DB	100h DUP(?)
_shm_role_scan_states	DB	0C0h DUP(?)
_shm_graphics_letter	DB	1 DUP(?)
asm_block_8439	DB	1 DUP(?)
_shm_menu_bottom	DB	2 DUP(?)
_asm_wire_grid	DB	7D0h DUP(?)
_asm_wires_live	DB	2 DUP(?)
_shm_case_city	DB	2 DUP(?)
_shm_activity	DB	40h DUP(?)
_shm_orgs_known	DB	2 DUP(?)
	PUBLIC	__buferr
__buferr	LABEL	BYTE
asm_block_8c52	DB	202h DUP(?)
_shm_case_spare_2	DB	2 DUP(?)
_shm_anim_row_2	DB	140h DUP(?)
_asm_case_difficulty	DB	2 DUP(?)
asm_block_8f98	DB	40h DUP(?)
_shm_case_org	DB	2 DUP(?)
asm_block_8fda	DB	6 DUP(?)

c_common	ENDS

	END
