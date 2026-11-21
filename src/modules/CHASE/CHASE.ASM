	PAGE	60,132
	TITLE	CHASE
;
; CHASE.ASM -- the assembly side of CHASE.EXE.
;
; A SPLIT marker stands where a routine is in C; the build cuts the
; assembly there.
;

	EXTRN	_c_hook_hand_back:PROC
	EXTRN	_c_sound_command:PROC
	EXTRN	_c_set_display_page:PROC
	EXTRN	_c_nothing:PROC
	EXTRN	_c_hook_repaint:PROC
	EXTRN	_c_draw_face:PROC
	EXTRN	_c_setup:PROC
	EXTRN	_c_get_section:PROC
	EXTRN	_c_chase_start:PROC
	EXTRN	_c_pick_cars:PROC
	EXTRN	_c_chase_step:PROC
	EXTRN	_c_sight:PROC
	EXTRN	_c_is_open:PROC
	EXTRN	_c_board_mark:PROC
	EXTRN	_c_board_dot:PROC
	EXTRN	_c_board_draw:PROC
	EXTRN	_c_board_car:PROC
	EXTRN	_c_hook_step:PROC
	EXTRN	_c_dashboard:PROC
	EXTRN	_c_turning_animation:PROC
	EXTRN	_c_sign:PROC
	EXTRN	_c_clock_text:PROC
	EXTRN	_c_hook_main:PROC
	EXTRN	_c_make_maze:PROC
	EXTRN	_c_near_destination:PROC
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
	EXTRN	_c_want_disk:PROC
	EXTRN	_c_seq_start:PROC
	EXTRN	_c_seq_step:PROC
	EXTRN	_c_seq_stop:PROC
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
	PUBLIC	_shm_anim_row_2
	PUBLIC	_shm_archive_buffer
	PUBLIC	_shd_map_page
	PUBLIC	_asm_chase_kind
	PUBLIC	_asm_game_speed
	PUBLIC	_shd_pan_disk
	PUBLIC	_dat_windscreen_car_rects
	PUBLIC	_asm_page_3
	PUBLIC	_dat_side_dx
	PUBLIC	_dat_side_dy
	PUBLIC	_dat_gear_steps
	PUBLIC	_dat_street_x
	PUBLIC	_dat_street_y
	PUBLIC	_asm_active_car
	PUBLIC	_dat_tile_page
	PUBLIC	_dat_dash_page
	PUBLIC	_dat_windscreen
	PUBLIC	_asm_car_stats
	PUBLIC	_dat_car_offset
	PUBLIC	_dat_windscreen_shown
	PUBLIC	_dat_windscreen_car_shown
	PUBLIC	_dat_clock_text
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
	PUBLIC	_shm_save_block
	PUBLIC	_shm_save_offset
	PUBLIC	_asm_arena
	PUBLIC	_asm_view_set
	PUBLIC	_asm_view_at
	PUBLIC	_asm_view_col
	PUBLIC	_asm_view_row
	PUBLIC	_asm_windscreen_near
	PUBLIC	_asm_windscreen_range
	PUBLIC	_asm_windscreen_car_x
	PUBLIC	_asm_windscreen_car_y
	PUBLIC	_asm_compass_dx
	PUBLIC	_asm_compass_dy
	PUBLIC	_asm_dash_scratch
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
	PUBLIC	_asm_org_alert_level
	PUBLIC	_shm_joystick
	PUBLIC	_asm_sight_dir
	PUBLIC	_shm_scratch
	PUBLIC	_asm_night
	PUBLIC	_shm_difficulty
	PUBLIC	_asm_goal_spot
	PUBLIC	_shm_clock_minutes
	PUBLIC	_asm_cars
	PUBLIC	_asm_tick
	PUBLIC	_shm_seed
	PUBLIC	_shm_options
	PUBLIC	_shm_cga
	PUBLIC	_shm_cities
	PUBLIC	_shm_menu_tick
	PUBLIC	_asm_stuck_count
	PUBLIC	_shm_suspect_count
	PUBLIC	_asm_cell_map
	PUBLIC	_asm_windscreen_frame
	PUBLIC	_shm_menu_face
	PUBLIC	_asm_head_on
	PUBLIC	_shm_mouse_regs
	PUBLIC	_asm_outcome
	PUBLIC	_asm_frame_tick
	PUBLIC	_shm_log_count
	PUBLIC	_shm_menu_first_line
	PUBLIC	_shm_case_seed
	PUBLIC	_shm_building_count
	PUBLIC	_shm_case_tick
	PUBLIC	_asm_graphics_word
	PUBLIC	_shm_source_at
	PUBLIC	_shm_case_city_1
	PUBLIC	_shm_case_city_2
	PUBLIC	_shm_pan_playing
	PUBLIC	_shm_menu_no_pick
	PUBLIC	_shm_menu_items
	PUBLIC	_asm_engine_note
	PUBLIC	_asm_fresh_board
	PUBLIC	_shm_crime_event_count
	PUBLIC	_asm_DAT_1663_5c00
	PUBLIC	_asm_start_spot
	PUBLIC	_shm_menu_relayout
	PUBLIC	_shm_mission
	PUBLIC	_shm_menu_colour_bar
	PUBLIC	_shm_case_org_1
	PUBLIC	_shm_menu_text_width
	PUBLIC	_shm_case_org_2
	PUBLIC	_asm_windscreen_car_sprites
	PUBLIC	_shm_regs
	PUBLIC	_asm_countdown
	PUBLIC	_shm_double_agent_cities
	PUBLIC	_shm_crime_role_count
	PUBLIC	_shm_menu_marked
	PUBLIC	_asm_DAT_1663_626a
	PUBLIC	_shm_refill
	PUBLIC	_shm_menu_face_x
	PUBLIC	_shm_menu_draw_only
	PUBLIC	_shm_skills
	PUBLIC	_shm_mouse_buttons
	PUBLIC	_shm_mouse_x
	PUBLIC	_shm_mouse_y
	PUBLIC	_shm_mouse_count
	PUBLIC	_shm_menu_face_y
	PUBLIC	_shm_finished
	PUBLIC	_shm_menu_shortcut
	PUBLIC	_shm_menu_pick
	PUBLIC	_shm_menu_right
	PUBLIC	_shm_graphics_letter
	PUBLIC	_shm_menu_bottom
	PUBLIC	_asm_spot_x
	PUBLIC	_asm_spot_y
	PUBLIC	_asm_suspect_alert
	PUBLIC	_shm_case_city
	PUBLIC	_asm_suspicion_scale
	PUBLIC	_shm_orgs_known
	PUBLIC	_shm_jailbreak_suspect
	PUBLIC	_shm_case_spare_2
	PUBLIC	_asm_goal_x
	PUBLIC	_asm_goal_y
	PUBLIC	_shm_case_org
	PUBLIC	_drv_real_FUN_1000_0002
	PUBLIC	_drv_jump_gfx_page_seg
	PUBLIC	_drv_jump_gfx_grab
	PUBLIC	_drv_jump_gfx_fill
	PUBLIC	_drv_jump_gfx_char_width
	PUBLIC	_drv_jump_gfx_sprite_put_clipped
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
	PUBLIC	_dat_str_cars_pic
	PUBLIC	_dat_str_tracking
	PUBLIC	_dat_str_mph
	PUBLIC	_dat_str_excellent
	PUBLIC	_dat_str_fair
	PUBLIC	_dat_str_low
	PUBLIC	_dat_str_moderate
	PUBLIC	_dat_str_high
	PUBLIC	_dat_str_extreme
	PUBLIC	_shd_str_please_insert_disk
	PUBLIC	_shd_str_if_3_5_insert
	PUBLIC	_shd_str_press_return_continue
	PUBLIC	_shd_str_briefing_pan
	PUBLIC	_shd_str_animation_pan
	PUBLIC	_shd_str_bld
	PUBLIC	_dat_str_we_ve_totally_lost
	PUBLIC	_dat_str_she
	PUBLIC	_dat_str_turns_corner_dashes
	PUBLIC	_dat_str_we_ll_have_less
	PUBLIC	_dat_str_dash_into_building
	PUBLIC	_dat_str_she_2
	PUBLIC	_dat_str_pulls_over_walks_into
	PUBLIC	_dat_str_pursuers_run_off_road
	PUBLIC	_dat_str_run
	PUBLIC	_dat_str_his
	PUBLIC	_dat_str_her
	PUBLIC	_dat_str_car_off_road_make
	PUBLIC	_dat_str_loc
	PUBLIC	_shd_str_one_moment_please
	PUBLIC	_shd_str_sure_want_quit_no_2
	PUBLIC	_dat_str_sure_want_quit_no
	PUBLIC	_dat_str_empty
	PUBLIC	_asm_number_digits
	PUBLIC	_dat_colours_car_pick
	PUBLIC	_shd_colours_screen
	PUBLIC	_shd_colours_screen_2
	PUBLIC	_dat_str_empty_2
	PUBLIC	_shd_str_close_paren
	PUBLIC	_dat_palette_default
	PUBLIC	_dat_palette_chase
	PUBLIC	_dat_str_he
	PUBLIC	_dat_str_he_2
	PUBLIC	_asm_number_digits_2
	PUBLIC	_shm_orgs
	PUBLIC	_shd_str_ok
	PUBLIC	_shd_palette_menu
	PUBLIC	_shd_palette_face
	PUBLIC	_shm_campaign
	PUBLIC	_shm_crime_roles
	PUBLIC	_shm_role_scan_states
	PUBLIC	_shm_crime_events
	PUBLIC	_dat_str_chase_pic
	PUBLIC	_dat_str_street_pic

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
	mov	word ptr ds:[drv_DAT_1663_0042],es
	mov	word ptr ds:[drv_DAT_1663_0044],bx
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
	mov	ds,word ptr ds:[drv_DAT_1663_0042]
	mov	dx,word ptr ds:[drv_DAT_1663_0044]
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

;------------------------------------------------------------------------------
; Jump into a driver through the slot whose address the caller pushed. With
; the cursor showing it far-calls instead, so the cursor can be redrawn after.
;------------------------------------------------------------------------------
drv_real_dispatch	PROC	NEAR
	cmp	byte ptr ds:[drv_DAT_1663_1a0b],0
	jnz	L100dd
	pop	word ptr cs:[L100d8+3]
	jmp	short L100d8
L100d8:
	; The target is patched in by the POP above.
	jmp	dword ptr cs:[0]
L100dd:
	mov	byte ptr ds:[drv_DAT_1663_1a0a],1
	pop	word ptr cs:[L100f1+3]
	pop	word ptr ds:[drv_DAT_1663_1a0c]
	pop	word ptr ds:[drv_DAT_1663_1a0e]
	jmp	short L100f1
L100f1:
	; The target is patched in by the POP above.
	call	dword ptr cs:[0]
	dec	byte ptr ds:[drv_DAT_1663_1a0a]
	jz	L10106
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_1663_1a0a],0
L10106:
	jmp	dword ptr ds:[drv_DAT_1663_1a0c]
drv_real_dispatch	ENDP
D1010a	DB	0,0

_drv_jump_gfx_page_seg	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_page_seg	ENDP
D10111	DB	0,0,0EAh,0,0,0,0,0
	DB	0

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
D1012d	DB	0,0,0EAh,0,0,0,0

_drv_jump_gfx_sprite_put_clipped	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
_drv_jump_gfx_sprite_put_clipped	ENDP

_drv_jump_gfx_pool_release	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_pool_release	ENDP
D10142	DB	0,0

_drv_jump_gfx_free_page	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_free_page	ENDP
D10149	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0

drv_jump_gfx_overlay_remove	PROC	NEAR
	call	drv_real_dispatch
L1016f:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_overlay_remove	ENDP
D1017a	DB	0,0,0EAh,0,0,0,0,0
	DB	0

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
	DB	0

_drv_jump_gfx_set_page_seg	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_set_page_seg	ENDP
D101b9	DB	0,0,0EAh,0,0,0,0,0
	DB	0

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
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
_drv_jump_gfx_show_page	ENDP

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
D10261	DB	0,0,0EAh,0,0,0,0,0
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
	mov	word ptr ds:[drv_DAT_1663_1a10],dx
	mov	word ptr ds:[drv_DAT_1663_1a12],bx
	mov	ah,48h
	mov	bx,0FFFFh
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jc	L10437
	mov	dx,OFFSET DGROUP:dat_message_pool
	jmp	drv_real_FUN_1000_04d0
L10437:
	mov	ah,48h
	sub	bx,100h
	mov	word ptr ds:[drv_DAT_1663_1a16],bx
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jnc	L1044b
	mov	dx,OFFSET DGROUP:dat_str_ms_dos_lied_us
	jmp	drv_real_FUN_1000_04d0
L1044b:
	mov	bx,OFFSET DGROUP:drv_DAT_1663_1a18
	mov	word ptr [bx],ax
	mov	word ptr [bx+2],ax
	mov	ax,4B03h
	mov	dx,word ptr ds:[drv_DAT_1663_1a10]
	push	ds
	pop	es
	mov	word ptr ds:[drv_DAT_1663_1a14],sp
	int	21h		; DOS AH=4Bh AL=03h: load overlay
	mov	dx,DGROUP
	mov	ds,dx
	mov	es,dx
	mov	ss,dx
	mov	sp,word ptr ds:[drv_DAT_1663_1a14]
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
	mov	es,word ptr ds:[drv_DAT_1663_1a18]
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
	cmp	bx,word ptr ds:[drv_DAT_1663_1a16]
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

;------------------------------------------------------------------------------
; Read the data file a driver load names into memory after the driver, in 32K
; goes, and return the segment past it.
;------------------------------------------------------------------------------
drv_real_load_data	PROC	NEAR
	push	ds
	mov	dx,word ptr ds:[drv_DAT_1663_1a12]
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
	mov	word ptr ds:[drv_DAT_1663_1eb3],si
	mov	cx,word ptr [bp+0Eh]
	shl	si,1
	lea	di,[drv_DAT_1663_1b3f]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	mov	dx,cx
	rep stosw
	mov	cx,dx
	lea	di,[drv_DAT_1663_1cf7]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	add	ax,word ptr [bp+0Ch]
	dec	ax
	rep stosw
	mov	ax,word ptr [bp+10h]
	call	far ptr drv_jump_gfx_set_colour
	mov	ax,ds:[drv_DAT_1663_1eb3]
	mov	cx,ax
	add	cx,word ptr [bp+0Eh]
	dec	cx
	mov	word ptr ds:[drv_DAT_1663_1eb5],cx
	mov	bx,OFFSET DGROUP:drv_DAT_1663_1b3f
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
	mov	ax,ds:[drv_DAT_1663_1eb3]
	mov	cx,word ptr ds:[drv_DAT_1663_1eb5]
	mov	bx,OFFSET DGROUP:drv_DAT_1663_1b3f
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
	mov	di,word ptr ds:[drv_DAT_1663_1eb3]
	or	di,di
	js	L10633
	mov	cx,word ptr ds:[drv_DAT_1663_1eb5]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,OFFSET DGROUP:drv_DAT_1663_1b3f
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[drv_DAT_1663_1eb3],ax
	mov	cx,bx
	mov	di,dx
	add	di,OFFSET DGROUP:drv_DAT_1663_1cf7
	sub	ax,ax
	rep stosw
	mov	ds:[drv_DAT_1663_1eb5],ax
L10633:
	ret
drv_real_FUN_1000_05fe	ENDP

drv_real_FUN_1000_0634	PROC	NEAR
	mov	ax,DGROUP
	mov	es,ax
	mov	cx,di
	or	si,si
	lea	di,[drv_DAT_1663_1b3f]
	jz	L1064d
	cmp	si,word ptr ds:[drv_DAT_1663_1ec5]
	jnz	L1068e
	lea	di,[drv_DAT_1663_1cf7]
L1064d:
	cmp	cx,dx
	jge	L10653
	xchg	cx,dx
L10653:
	or	dx,dx
	jns	L10659
	sub	dx,dx
L10659:
	cmp	cx,word ptr ds:[drv_DAT_1663_1ec7]
	jle	L10663
	mov	cx,word ptr ds:[drv_DAT_1663_1ec7]
L10663:
	add	si,word ptr ds:[drv_DAT_1663_1eb7]
	add	cx,word ptr ds:[drv_DAT_1663_1eb9]
	add	dx,word ptr ds:[drv_DAT_1663_1eb9]
	cmp	cx,word ptr ds:[drv_DAT_1663_1eb5]
	jbe	L10679
	mov	word ptr ds:[drv_DAT_1663_1eb5],cx
L10679:
	cmp	dx,word ptr ds:[drv_DAT_1663_1eb3]
	jnc	L10683
	mov	word ptr ds:[drv_DAT_1663_1eb3],dx
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

drv_real_FUN_1000_068f	PROC	NEAR
	sub	si,si
	or	bx,bx
	js	drv_real_FUN_1000_0634
	mov	si,word ptr ds:[drv_DAT_1663_1ec5]
	cmp	bx,si
	jg	drv_real_FUN_1000_0634
	ret
drv_real_FUN_1000_068f	ENDP

drv_real_FUN_1000_069e	PROC	NEAR
	mov	ax,ds:[drv_DAT_1663_1eb7]
	add	word ptr ds:[drv_DAT_1663_1b37],ax
	add	word ptr ds:[drv_DAT_1663_1b39],ax
	mov	ax,ds:[drv_DAT_1663_1eb9]
	add	word ptr ds:[drv_DAT_1663_1b3b],ax
	add	word ptr ds:[drv_DAT_1663_1b3d],ax
	mov	ax,ds:[drv_DAT_1663_1b39]
	cmp	ax,word ptr ds:[drv_DAT_1663_1b37]
	jnc	L106d6
	mov	bx,word ptr ds:[drv_DAT_1663_1b37]
	mov	word ptr ds:[drv_DAT_1663_1b39],bx
	mov	ds:[drv_DAT_1663_1b37],ax
	mov	ax,ds:[drv_DAT_1663_1b3d]
	mov	bx,word ptr ds:[drv_DAT_1663_1b3b]
	mov	word ptr ds:[drv_DAT_1663_1b3d],bx
	mov	ds:[drv_DAT_1663_1b3b],ax
L106d6:
	mov	bx,word ptr ds:[drv_DAT_1663_1b39]
	sub	bx,word ptr ds:[drv_DAT_1663_1b37]
	mov	word ptr ds:[drv_DAT_1663_1eaf],bx
	mov	ax,ds:[drv_DAT_1663_1b3d]
	mov	dx,ax
	mov	cx,word ptr ds:[drv_DAT_1663_1b3b]
	sub	ax,cx
	mov	bp,2
	jns	L106f8
	xchg	cx,dx
	neg	bp
	neg	ax
L106f8:
	mov	ds:[drv_DAT_1663_1eb1],ax
	cmp	dx,word ptr ds:[drv_DAT_1663_1eb5]
	jbe	L10705
	mov	word ptr ds:[drv_DAT_1663_1eb5],dx
L10705:
	cmp	cx,word ptr ds:[drv_DAT_1663_1eb3]
	jnc	L1070f
	mov	word ptr ds:[drv_DAT_1663_1eb3],cx
L1070f:
	cmp	ax,bx
	jnc	drv_real_FUN_1000_075e
	mov	di,word ptr ds:[drv_DAT_1663_1b3b]
	shl	di,1
	mov	ax,ds:[drv_DAT_1663_1b37]
	mov	dx,word ptr ds:[drv_DAT_1663_1eaf]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[drv_DAT_1663_1eb1]
	jmp	L1073f
L10730:
	cmp	ax,word ptr [di+drv_DAT_1663_1cf7]
	jbe	L1073a
	mov	word ptr [di+drv_DAT_1663_1cf7],ax
L1073a:
	inc	ax
	sub	bx,dx
	add	di,bp
L1073f:
	cmp	ax,word ptr [di+drv_DAT_1663_1b3f]
	jnc	L10749
	mov	word ptr [di+drv_DAT_1663_1b3f],ax
L10749:
	dec	cx
	js	L10753
	add	bx,si
	jns	L10730
	inc	ax
	jmp	L10749
L10753:
	cmp	ax,word ptr [di+drv_DAT_1663_1cf7]
	jbe	L1075d
	mov	word ptr [di+drv_DAT_1663_1cf7],ax
L1075d:
	ret
drv_real_FUN_1000_069e	ENDP

drv_real_FUN_1000_075e	PROC	NEAR
	mov	di,word ptr ds:[drv_DAT_1663_1b3b]
	shl	di,1
	mov	ax,ds:[drv_DAT_1663_1b37]
	mov	dx,word ptr ds:[drv_DAT_1663_1eb1]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[drv_DAT_1663_1eaf]
L10778:
	cmp	ax,word ptr [di+drv_DAT_1663_1b3f]
	jnc	L10782
	mov	word ptr [di+drv_DAT_1663_1b3f],ax
L10782:
	cmp	ax,word ptr [di+drv_DAT_1663_1cf7]
	jbe	L1078c
	mov	word ptr [di+drv_DAT_1663_1cf7],ax
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
	mov	ax,ds:[drv_DAT_1663_1b37]
	mov	bx,word ptr ds:[drv_DAT_1663_1b3b]
	mov	cx,word ptr ds:[drv_DAT_1663_1b39]
	mov	dx,word ptr ds:[drv_DAT_1663_1b3d]
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
	mov	word ptr ds:[drv_DAT_1663_1ebd],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_1663_1ec1],dx
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
	sar	word ptr ds:[drv_DAT_1663_1ebd],1
	sar	word ptr ds:[drv_DAT_1663_1ec1],1
	jmp	L1088f
L10832:
	jmp	L107f4
L10834:
	mov	cx,word ptr ds:[drv_DAT_1663_1b37]
	mov	dx,word ptr ds:[drv_DAT_1663_1b3b]
	mov	si,word ptr ds:[drv_DAT_1663_1b39]
	mov	di,word ptr ds:[drv_DAT_1663_1b3d]
	mov	bx,cx
	mov	bp,dx
	call	drv_real_FUN_1000_0938
	mov	ds:[drv_DAT_1663_1ebc],al
	mov	bx,si
	mov	bp,di
	call	drv_real_FUN_1000_0938
	jnz	L10871
	cmp	byte ptr ds:[drv_DAT_1663_1ebc],0
	jnz	L10861
	jmp	L107ce
L10861:
	xchg	cx,si
	xchg	dx,di
	xchg	byte ptr ds:[drv_DAT_1663_1ebc],al
	mov	word ptr ds:[drv_DAT_1663_1b37],cx
	mov	word ptr ds:[drv_DAT_1663_1b3b],dx
L10871:
	test	byte ptr ds:[drv_DAT_1663_1ebc],al
	jnz	L10832
	mov	bp,dx
	mov	dx,si
	sub	dx,cx
	jo	L10806
	mov	word ptr ds:[drv_DAT_1663_1ebd],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_1663_1ec1],dx
	mov	dx,di
	sub	dx,bp
	jo	L10824
L1088f:
	mov	word ptr ds:[drv_DAT_1663_1ebf],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_1663_1ec3],dx
L10899:
	test	al,9
	jz	L108d5
	sub	bx,bx
	or	si,si
	js	L108a7
	mov	bx,word ptr ds:[drv_DAT_1663_1ec5]
L108a7:
	mov	ax,bx
	sub	ax,cx
	imul	word ptr ds:[drv_DAT_1663_1ebf]
	push	bx
	mov	bx,dx
	idiv	word ptr ds:[drv_DAT_1663_1ebd]
	mov	bl,bh
	xor	bl,byte ptr ds:[drv_DAT_1663_1ebd+1]
	jns	L108c1
	neg	dx
	dec	ax
L108c1:
	sub	dx,word ptr ds:[drv_DAT_1663_1ec1]
	xor	dh,bh
	js	L108ca
	inc	ax
L108ca:
	pop	bx
	add	ax,bp
	js	L108dd
	cmp	ax,word ptr ds:[drv_DAT_1663_1ec7]
	jle	L1090e
L108d5:
	mov	bx,word ptr ds:[drv_DAT_1663_1ec7]
	cmp	di,bx
	jg	L108df
L108dd:
	sub	bx,bx
L108df:
	mov	ax,bx
	sub	ax,bp
	imul	word ptr ds:[drv_DAT_1663_1ebd]
	push	bx
	mov	bx,dx
L108ea:
	idiv	word ptr ds:[drv_DAT_1663_1ebf]
	mov	bl,bh
	xor	bl,byte ptr ds:[drv_DAT_1663_1ebf+1]
	jns	L108f9
	neg	dx
	dec	ax
L108f9:
	sub	dx,word ptr ds:[drv_DAT_1663_1ec3]
	xor	dh,bh
	js	L10902
	inc	ax
L10902:
	pop	bx
	add	ax,cx
	js	L1091f
	cmp	ax,word ptr ds:[drv_DAT_1663_1ec5]
	jg	L1091f
	xchg	bx,ax
L1090e:
	cmp	byte ptr ds:[drv_DAT_1663_1ebc],0
	jnz	L10922
	mov	ds:[drv_DAT_1663_1b3d],ax
	mov	word ptr ds:[drv_DAT_1663_1b39],bx
	jmp	L107ce
L1091f:
	jmp	L107f4
L10922:
	mov	ds:[drv_DAT_1663_1b3b],ax
	mov	word ptr ds:[drv_DAT_1663_1b37],bx
	xchg	cx,si
	xchg	bp,di
	mov	al,ds:[drv_DAT_1663_1ebc]
	mov	byte ptr ds:[drv_DAT_1663_1ebc],0
	jmp	L10899
drv_real_FUN_1000_07ac	ENDP

drv_real_FUN_1000_0938	PROC	NEAR
	mov	al,0Fh
	or	bx,bx
	js	L10940
	and	al,0F7h
L10940:
	cmp	bx,word ptr ds:[drv_DAT_1663_1ec5]
	jg	L10948
	and	al,0FEh
L10948:
	or	bp,bp
	js	L1094e
	and	al,0FBh
L1094e:
	cmp	bp,word ptr ds:[drv_DAT_1663_1ec7]
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
	mov	ax,ds:[drv_DAT_1663_1ebf]
	jz	L10969
	mov	ax,ds:[drv_DAT_1663_1ebd]
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
	mov	ds:[drv_DAT_1663_1ec5],ax
	mov	ax,word ptr [bx+8]
	mov	ds:[drv_DAT_1663_1ec7],ax
	call	far ptr drv_jump_gfx_select_pic
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_1663_1b37],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_1663_1b3b],ax
	mov	ax,word ptr [bp+0Ch]
	mov	ds:[drv_DAT_1663_1b39],ax
	mov	ax,word ptr [bp+0Eh]
	mov	ds:[drv_DAT_1663_1b3d],ax
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
	mov	ds:[drv_DAT_1663_3c71],al
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
	mov	ds:[drv_DAT_1663_3c71],al
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
	mov	byte ptr ds:[drv_DAT_1663_3c66],0
	mov	byte ptr ds:[drv_DAT_1663_3c67],0
	mov	ax,OFFSET DGROUP:asm_block_3c75+512
	mov	ds:[drv_DAT_1663_3c62],ax
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
	mov	ds:[drv_DAT_1663_3c69],al
	mov	ds:[drv_DAT_1663_3c6e],ax
	mov	byte ptr ds:[drv_DAT_1663_3c70],8
drv_real_FUN_1000_0b0f	ENDP

drv_real_FUN_1000_0b4d	PROC	NEAR
	mov	byte ptr ds:[drv_DAT_1663_3c68],9
	mov	word ptr ds:[drv_DAT_1663_3c6a],1FFh
	mov	dx,100h
	mov	word ptr ds:[drv_DAT_1663_3c6c],dx
	mov	ax,0FFFFh
	xor	bx,bx
	mov	cx,800h
L10b67:
	mov	word ptr [bx+drv_DAT_1663_245c],ax
	add	bx,3
	loop	L10b67
	mov	al,0
	xor	bx,bx
	mov	cx,100h
L10b77:
	mov	byte ptr [bx+drv_DAT_1663_245e],al
	inc	al
	add	bx,3
	loop	L10b77
	ret
drv_real_FUN_1000_0b4d	ENDP

drv_real_FUN_1000_0b83	PROC	NEAR
	cmp	byte ptr ds:[drv_DAT_1663_3c71],0
	jz	L10b8d
	inc	cx
	shr	cx,1
L10b8d:
	mov	word ptr ds:[drv_DAT_1663_3c64],cx
	mov	ax,ds:[drv_DAT_1663_3c62]
	mov	word ptr ds:[drv_DAT_1663_3c62],sp
	mov	sp,ax
	mov	dx,word ptr ds:[drv_DAT_1663_3c6c]
L10b9e:
	cmp	byte ptr ds:[drv_DAT_1663_3c66],0
	jnz	L10bc6
	call	drv_real_FUN_1000_0bff
	cmp	al,90h
	jz	L10bb2
	mov	ds:[drv_DAT_1663_3c67],al
	jmp	L10bcd
L10bb2:
	call	drv_real_FUN_1000_0bff
	or	al,al
	jnz	L10bc1
	mov	al,90h
	mov	ds:[drv_DAT_1663_3c67],al
	jmp	L10bcd
L10bc1:
	dec	al
	mov	ds:[drv_DAT_1663_3c66],al
L10bc6:
	mov	al,ds:[drv_DAT_1663_3c67]
	dec	byte ptr ds:[drv_DAT_1663_3c66]
L10bcd:
	cmp	byte ptr ds:[drv_DAT_1663_3c71],0
	jz	L10bea
	mov	ah,al
	and	al,0Fh
	shr	ah,1
	shr	ah,1
	shr	ah,1
	shr	ah,1
	stosw
	dec	word ptr ds:[drv_DAT_1663_3c64]
	jnz	L10b9e
	jmp	L10bf1
L10bea:
	stosb
	dec	word ptr ds:[drv_DAT_1663_3c64]
	jnz	L10b9e
L10bf1:
	mov	word ptr ds:[drv_DAT_1663_3c6c],dx
	mov	ax,ds:[drv_DAT_1663_3c62]
	mov	word ptr ds:[drv_DAT_1663_3c62],sp
	mov	sp,ax
	ret
drv_real_FUN_1000_0b83	ENDP

drv_real_FUN_1000_0bff	PROC	NEAR
	pop	bp
	cmp	sp,OFFSET DGROUP:asm_block_3c75+512
	jz	L10c09
L10c06:
	pop	ax
	jmp	bp
L10c09:
	mov	bx,word ptr ds:[drv_DAT_1663_3c6e]
	mov	cl,10h
	mov	ch,byte ptr ds:[drv_DAT_1663_3c70]
	sub	cl,ch
	shr	bx,cl
	mov	cl,ch
L10c19:
	cmp	cl,byte ptr ds:[drv_DAT_1663_3c68]
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
	mov	ds:[drv_DAT_1663_3c6e],ax
	shl	ax,cl
	or	bx,ax
	add	cl,10h
	jmp	L10c19
L10c40:
	sub	cl,byte ptr ds:[drv_DAT_1663_3c68]
	mov	byte ptr ds:[drv_DAT_1663_3c70],cl
	mov	ax,bx
	and	ax,word ptr ds:[drv_DAT_1663_3c6a]
	mov	cx,ax
	cmp	ax,dx
	jl	L10c5e
	mov	cx,dx
	mov	ax,ds:[drv_DAT_1663_3c72]
	mov	bl,byte ptr ds:[drv_DAT_1663_3c74]
	push	bx
L10c5e:
	mov	bx,ax
	add	bx,ax
	add	bx,ax
	mov	ax,word ptr [bx+drv_DAT_1663_245c]
	inc	ax
	jz	L10c73
	dec	ax
	mov	bl,byte ptr [bx+drv_DAT_1663_245e]
	push	bx
	jmp	L10c5e
L10c73:
	mov	al,byte ptr [bx+drv_DAT_1663_245e]
	mov	ds:[drv_DAT_1663_3c74],al
	push	ax
	mov	bx,dx
	add	bx,dx
	add	bx,dx
	mov	byte ptr [bx+drv_DAT_1663_245e],al
	mov	ax,ds:[drv_DAT_1663_3c72]
	mov	word ptr [bx+drv_DAT_1663_245c],ax
	inc	dx
	cmp	dx,word ptr ds:[drv_DAT_1663_3c6a]
	jle	L10c9c
	inc	byte ptr ds:[drv_DAT_1663_3c68]
	stc
	rcl	word ptr ds:[drv_DAT_1663_3c6a],1
L10c9c:
	mov	al,ds:[drv_DAT_1663_3c68]
	cmp	al,byte ptr ds:[drv_DAT_1663_3c69]
	jle	L10ca8
	call	drv_real_FUN_1000_0b4d
L10ca8:
	mov	word ptr ds:[drv_DAT_1663_3c72],cx
	jmp	L10c06
drv_real_FUN_1000_0bff	ENDP
D10caf	DB	0

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
	jz	L10cfe
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
	or	ax,ax
	jz	L10cfe
	mov	ax,0Ch
	mov	cx,1Fh
	mov	dx,cs
	mov	es,dx
	lea	dx,[drv_real_mouse_event]
	int	33h		; mouse AX=000Ch: set user-defined event handler
	mov	ax,3
	int	33h		; mouse AX=0003h: get position and button status
	mov	word ptr ds:[drv_DAT_1663_1ed8],0
	cmp	cx,0C8h
	jc	L10cf2
	shr	cx,1
	mov	word ptr ds:[drv_DAT_1663_1ed8],1
L10cf2:
	mov	word ptr ds:[drv_DAT_1663_1ece],bx
	mov	word ptr ds:[drv_DAT_1663_1eca],cx
	mov	word ptr ds:[drv_DAT_1663_1ecc],dx
L10cfe:
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
	jz	L10d19
	call	far ptr drv_real_FUN_1000_0d38
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
L10d19:
	retf
drv_real_mouse_close	ENDP

drv_real_FUN_1000_0d1a	PROC	FAR
	xor	ax,ax
	xchg	word ptr ds:[drv_DAT_1663_1ed0],ax
	retf
drv_real_FUN_1000_0d1a	ENDP

;------------------------------------------------------------------------------
; Set the cursor's hot spot and which shape to draw.
;------------------------------------------------------------------------------
drv_real_mouse_set_cursor	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	ds:[drv_DAT_1663_1ed4],ax
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_1663_1ed6],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_1663_1ed2],ax
	pop	bp
	retf
drv_real_mouse_set_cursor	ENDP

drv_real_FUN_1000_0d38	PROC	FAR
	mov	byte ptr ds:[drv_DAT_1663_1a0b],0
	call	far ptr drv_jump_gfx_overlay_remove
	retf
drv_real_FUN_1000_0d38	ENDP

;------------------------------------------------------------------------------
; Draw the cursor at the position the last event left, and record that it is
; on.
;------------------------------------------------------------------------------
drv_real_cursor_show	PROC	FAR
	push	word ptr ds:[drv_DAT_1663_1ed2]
	mov	ax,ds:[drv_DAT_1663_1ecc]
	sub	ax,word ptr ds:[drv_DAT_1663_1ed6]
	push	ax
	mov	ax,ds:[drv_DAT_1663_1eca]
	sub	ax,word ptr ds:[drv_DAT_1663_1ed4]
	push	ax
	call	far ptr drv_jump_gfx_overlay_put
	add	sp,6
	mov	byte ptr ds:[drv_DAT_1663_1a0b],1
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
	mov	ds:[drv_DAT_1663_1eda],ax
	mov	word ptr ds:[drv_DAT_1663_1edc],bx
	mov	word ptr ds:[drv_DAT_1663_1ede],cx
	mov	word ptr ds:[drv_DAT_1663_1ee0],dx
	lea	ax,[drv_DAT_1663_1eda]
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
	push	word ptr ds:[drv_DAT_1663_1ed2]
	mov	ax,ds:[drv_DAT_1663_1ecc]
	sub	ax,word ptr ds:[drv_DAT_1663_1ed6]
	push	ax
	mov	ax,ds:[drv_DAT_1663_1eca]
	sub	ax,word ptr ds:[drv_DAT_1663_1ed4]
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
	cmp	word ptr ds:[drv_DAT_1663_1ed8],0
	jz	L10dcb
	shr	cx,1
L10dcb:
	or	word ptr ds:[drv_DAT_1663_1ed0],bx
	mov	word ptr ds:[drv_DAT_1663_1ece],bx
	mov	word ptr ds:[drv_DAT_1663_1eca],cx
	mov	word ptr ds:[drv_DAT_1663_1ecc],dx
	test	ax,1
	jz	L10dfb
	cmp	byte ptr ds:[drv_DAT_1663_1a0b],0
	jz	L10dfb
	mov	al,2
	xchg	byte ptr ds:[drv_DAT_1663_1a0a],al
	or	al,al
	jnz	L10dfb
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_1663_1a0a],0
L10dfb:
	retf
drv_real_mouse_event	ENDP

CODE_0	ENDS

;==============================================================================
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:_TEXT, ds:DGROUP, ss:DGROUP

;;SPLIT main

;;SPLIT FUN_10df_044e

;;SPLIT FUN_10df_0467

;;SPLIT FUN_10df_0482

;;SPLIT FUN_10df_04a1

;;SPLIT FUN_10df_04a2

;;SPLIT FUN_10df_04a3

;;SPLIT FUN_10df_04a4

;;SPLIT FUN_10df_06ae

;;SPLIT FUN_10df_0708

;;SPLIT FUN_10df_0842

;;SPLIT FUN_10df_0dc6

;;SPLIT FUN_10df_1ceb

;;SPLIT FUN_10df_1ede

;;SPLIT FUN_10df_1f80

;;SPLIT FUN_10df_1ff8

;;SPLIT FUN_10df_2012

;;SPLIT FUN_10df_2400

;;SPLIT FUN_10df_248c

;;SPLIT FUN_10df_2496

;;SPLIT FUN_10df_29d8

;;SPLIT FUN_10df_2bb3

;;SPLIT FUN_10df_2bd0

;;SPLIT FUN_10df_2c50

;;SPLIT FUN_10df_2c51

;;SPLIT FUN_10df_3190

;;SPLIT FUN_10df_321c

;;SPLIT FUN_10df_36eb

;;SPLIT FUN_10df_3a9c

;;SPLIT FUN_10df_3af4

;;SPLIT FUN_10df_3b4d

;;SPLIT FUN_10df_3c0e

;;SPLIT FUN_10df_3c60

;;SPLIT FUN_10df_3d91

;;SPLIT FUN_10df_3dba

;;SPLIT FUN_10df_3ded

;;SPLIT FUN_10df_3e6a

;;SPLIT FUN_10df_3ee6

;;SPLIT FUN_10df_3f08

;;SPLIT FUN_10df_403a

;;SPLIT FUN_10df_403b

;;SPLIT FUN_10df_403c

;;SPLIT FUN_10df_403e

;;SPLIT FUN_10df_4054

;;SPLIT FUN_10df_406a

;;SPLIT FUN_10df_4080

;;SPLIT FUN_10df_40a8

;;SPLIT FUN_10df_40ce

;;SPLIT FUN_10df_4106

;;SPLIT FUN_10df_413e

;;SPLIT FUN_10df_4186

;;SPLIT FUN_10df_41a6

;;SPLIT FUN_10df_41c7

;;SPLIT FUN_10df_41f0

;;SPLIT FUN_10df_4228

;;SPLIT FUN_10df_4246

;;SPLIT FUN_10df_4262

;;SPLIT FUN_10df_428c

;;SPLIT FUN_10df_42a6

;;SPLIT FUN_10df_42c0

;;SPLIT FUN_10df_42d7

;;SPLIT FUN_10df_42f0

;;SPLIT FUN_10df_430e

;;SPLIT FUN_10df_436e

;;SPLIT FUN_10df_4398

;;SPLIT FUN_10df_43bc

;;SPLIT FUN_10df_4400

;;SPLIT FUN_10df_4446

;;SPLIT FUN_10df_4488

;;SPLIT FUN_10df_44ec

;;SPLIT FUN_10df_452c

;;SPLIT FUN_10df_4598

;;SPLIT FUN_10df_45aa

;;SPLIT FUN_10df_4606

;;SPLIT FUN_10df_466a

;;SPLIT FUN_10df_4688

;;SPLIT FUN_10df_46bc

;;SPLIT FUN_10df_46cc

;;SPLIT FUN_10df_46f4

;;SPLIT FUN_10df_4716

;;SPLIT FUN_10df_4746

;;SPLIT FUN_10df_4776

;;SPLIT FUN_10df_479c

;;SPLIT FUN_10df_485c

_TEXT	ENDS

;==============================================================================
_DATA	SEGMENT	WORD PUBLIC 'DATA'
;==============================================================================
drv_DAT_1663_0042	DB	0,0
drv_DAT_1663_0044	DB	0,0
asm_block_0046	DB	0,0,3Fh,3Fh,3Fh,3Fh,3Fh,3Fh
	DB	3Fh,3Fh,3Fh,3Fh,3Fh,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
dat_str_env_sve	DB	65h,6Eh,76h,2Eh,73h,76h,65h,0
_dat_str_chase_pic	DB	63h,68h,61h,73h,65h,2Eh,70h,69h
	DB	63h,0
_dat_str_street_pic	DB	73h,74h,72h,65h,65h,74h,2Eh,70h
	DB	69h,63h,0
_dat_str_we_ve_totally_lost	DB	27h,57h,65h,27h,76h,65h,20h,74h
	DB	6Fh,74h,61h,6Ch,6Ch,79h,20h,6Ch
	DB	6Fh,73h,74h,0Ah,74h,72h,61h,63h
	DB	6Bh,20h,6Fh,66h,20h,74h,68h,69h
	DB	73h,20h,67h,75h,79h,2Eh,0Ah,4Ch
	DB	65h,74h,27h,73h,20h,67h,6Fh,20h
	DB	62h,61h,63h,6Bh,20h,74h,6Fh,0Ah
	DB	77h,68h,65h,72h,65h,20h,77h,65h
	DB	20h,73h,74h,61h,72h,74h,65h,64h
	DB	2Eh,27h,0Ah,0
_dat_str_he	DB	48h,65h,0
_dat_str_she	DB	53h,68h,65h,0
_dat_str_turns_corner_dashes	DB	20h,74h,75h,72h,6Eh,73h,20h,74h
	DB	68h,65h,20h,63h,6Fh,72h,6Eh,65h
	DB	72h,0Ah,61h,6Eh,64h,20h,64h,61h
	DB	73h,68h,65h,73h,20h,69h,6Eh,74h
	DB	6Fh,20h,61h,0Ah,63h,72h,6Fh,77h
	DB	64h,65h,64h,20h,72h,65h,73h,74h
	DB	61h,75h,72h,61h,6Eh,74h,2Eh,0Ah
	DB	0
_dat_str_we_ll_have_less	DB	27h,57h,65h,27h,6Ch,6Ch,20h,68h
	DB	61h,76h,65h,20h,74h,6Fh,0Ah,62h
	DB	65h,20h,6Ch,65h,73h,73h,20h,6Fh
	DB	62h,76h,69h,6Fh,75h,73h,0Ah,6Eh
	DB	65h,78h,74h,20h,74h,69h,6Dh,65h
	DB	2Ch,20h,4Dh,61h,78h,2Eh,27h,0Ah
	DB	0
_dat_str_dash_into_building	DB	59h,6Fh,75h,20h,64h,61h,73h,68h
	DB	20h,69h,6Eh,74h,6Fh,20h,74h,68h
	DB	65h,0Ah,62h,75h,69h,6Ch,64h,69h
	DB	6Eh,67h,20h,73h,65h,63h,6Fh,6Eh
	DB	64h,73h,20h,61h,68h,65h,61h,64h
	DB	0Ah,6Fh,66h,20h,79h,6Fh,75h,72h
	DB	20h,70h,75h,72h,73h,75h,65h,72h
	DB	73h,21h,0Ah,0
_dat_str_he_2	DB	48h,65h,0
_dat_str_she_2	DB	53h,68h,65h,0
_dat_str_pulls_over_walks_into	DB	20h,70h,75h,6Ch,6Ch,73h,20h,6Fh
	DB	76h,65h,72h,0Ah,61h,6Eh,64h,20h
	DB	77h,61h,6Ch,6Bh,73h,20h,69h,6Eh
	DB	74h,6Fh,0Ah,61h,20h,62h,75h,69h
	DB	6Ch,64h,69h,6Eh,67h,20h,61h,73h
	DB	20h,79h,6Fh,75h,0Ah,71h,75h,69h
	DB	65h,74h,6Ch,79h,20h,70h,61h,72h
	DB	6Bh,20h,6Eh,65h,61h,72h,62h,79h
	DB	2Eh,0Ah,0
_dat_str_pursuers_run_off_road	DB	59h,6Fh,75h,72h,20h,70h,75h,72h
	DB	73h,75h,65h,72h,73h,20h,72h,75h
	DB	6Eh,0Ah,79h,6Fh,75h,20h,6Fh,66h
	DB	66h,20h,74h,68h,65h,20h,72h,6Fh
	DB	61h,64h,21h,0Ah,0
_dat_str_run	DB	59h,6Fh,75h,20h,72h,75h,6Eh,20h
	DB	0
_dat_str_his	DB	68h,69h,73h,0
_dat_str_her	DB	68h,65h,72h,0
_dat_str_car_off_road_make	DB	20h,63h,61h,72h,0Ah,6Fh,66h,66h
	DB	20h,74h,68h,65h,20h,72h,6Fh,61h
	DB	64h,20h,61h,6Eh,64h,0Ah,6Dh,61h
	DB	6Bh,65h,20h,74h,68h,65h,20h,61h
	DB	72h,72h,65h,73h,74h,21h,0Ah,0
	DB	0,0
BLOCK_022C	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0FFh,0FFh
RASTPORT_15EC	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
RASTPORT_PTR_15FE	DW	OFFSET DGROUP:RASTPORT_15EC
dat_map_page_port	DB	1,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_shd_map_page	DW	OFFSET DGROUP:dat_map_page_port
asm_block_1614	DB	0,0,1,0,2,0,0,2
	DB	0,1,3,1,2,1,0,3
	DB	0,1,11h,11h,2,0,2,3
	DB	30h,11h,13h,31h,22h,23h,33h,33h
_shd_colours_screen	DB	0,0,1,0,2,0,0,2		; COLOUR_MAP
	DB	0,1,2,3,2,1,1,3
_shd_colours_screen_2	DB	0,0,11h,11h,22h,0,0,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,22h,11h,22h,33h
BLOCK_1654	DB	0,0,11h,11h,22h,22h,22h,22h
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
	DB	0,11h,11h,1,22h,0,22h,22h
	DB	0,11h,11h,33h,33h,33h,33h,33h
	DB	0,0,11h,11h,22h,0,0,11h
	DB	22h,22h,33h,33h,22h,11h,22h,33h
	DB	0,0,11h,11h,22h,0,0,22h
	DB	0,22h,33h,33h,22h,11h,22h,33h
_dat_colours_car_pick	DB	0,0,11h,11h,22h,0,0,33h		; COLOUR_MAP
	DB	22h,22h,11h,33h,22h,33h,22h,33h
_asm_chase_kind	DB	0,0
_asm_game_speed	DB	1,0
_shd_pan_disk	DB	2,0
_dat_palette_chase	DB	0Eh,1,2,3,4,0,6,7		; PALETTE
	DB	8,9,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh
	DB	0
PALETTE_PAD_170B	DB	0
_dat_windscreen_car_rects	DB	5,0,54h,0,35h,0,74h,0
	DB	8,0,75h,0,32h,0,91h,0
	DB	0Ah,0,92h,0,30h,0,0ABh,0
	DB	0Ch,0,0ACh,0,2Eh,0,0C2h,0
	DB	47h,0,54h,0,66h,0,68h,0
	DB	4Ah,0,6Ah,0,64h,0,7Bh,0
	DB	4Bh,0,7Eh,0,63h,0,8Eh,0
	DB	4Dh,0,8Fh,0,61h,0,9Ch,0
	DB	4Eh,0,9Dh,0,60h,0,0A8h,0
	DB	50h,0,0A9h,0,5Eh,0,0B2h,0
	DB	51h,0,0B3h,0,5Eh,0,0BBh,0
	DB	51h,0,0BCh,0,5Ch,0,0C3h,0
	DB	3Ch,0,0A9h,0,44h,0,0AFh,0
	DB	3Dh,0,0B0h,0,44h,0,0B4h,0
	DB	3Eh,0,0B5h,0,43h,0,0B8h,0
	DB	3Fh,0,0B9h,0,42h,0,0BBh,0
_asm_page_3	DB	0,0
_dat_palette_default	DB	0,1,2,3,4,0,6,7		; PALETTE
	DB	8,9,0Ah,0Bh,0Ch,0Dh,0Eh,0Fh
	DB	0
PALETTE_PAD_179F	DB	0
_dat_side_dx	DB	0,0,1,0,0,0,0FFh,0FFh
_dat_side_dy	DB	0FFh,0FFh,0,0,1,0,0,0
_dat_gear_steps	DB	0,0,1,0,9,0,15h,0
	DB	1Bh,0
_dat_street_x	DB	2,0,7,0,8,0,8,0		; STREET_SPAN[4]
	DB	2,0,7,0,0,0,0,0
_dat_street_y	DB	0,0,0,0,2,0,7,0		; STREET_SPAN[4]
	DB	8,0,8,0,2,0,7,0
_asm_active_car	DB	1,0
dat_tile_page_port	DB	3,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_dat_tile_page	DW	OFFSET DGROUP:dat_tile_page_port
dat_dash_page_port	DB	2,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_dat_dash_page	DW	OFFSET DGROUP:dat_dash_page_port
dat_windscreen_port	DB	0,0,0C9h,0,1,0,3Eh,1		; RASTPORT
	DB	4Bh,0,0,0,0Fh,0,4,0
	DB	0,0
_dat_windscreen	DW	OFFSET DGROUP:dat_windscreen_port
_dat_str_cars_pic	DB	63h,61h,72h,73h,2Eh,70h,69h,63h
	DB	0
_dat_str_tracking	DB	28h,54h,72h,61h,63h,6Bh,69h,6Eh
	DB	67h,29h,0
_dat_str_empty	DB	0
_dat_str_mph	DB	20h,6Dh,70h,68h,0
_dat_str_excellent	DB	45h,78h,63h,65h,6Ch,6Ch,65h,6Eh
	DB	74h,0
_dat_str_fair	DB	46h,61h,69h,72h,0
_dat_str_low	DB	4Ch,6Fh,77h,0
_dat_str_moderate	DB	4Dh,6Fh,64h,65h,72h,61h,74h,65h
	DB	0
_dat_str_high	DB	48h,69h,67h,68h,0
_dat_str_extreme	DB	45h,78h,74h,72h,65h,6Dh,65h,0
_asm_car_stats	DB	43h,61h,72h,20h,23h,0,0,7
	DB	0,8,0,0Ah,0,2,0,0Fh
	DB	0,7,0,0Ch,0,4,0
_dat_str_sure_want_quit_no	DB	41h,72h,65h,20h,79h,6Fh,75h,20h
	DB	73h,75h,72h,65h,0Ah,79h,6Fh,75h
	DB	20h,77h,61h,6Eh,74h,20h,74h,6Fh
	DB	20h,51h,75h,69h,74h,3Fh,0Ah,20h
	DB	4Eh,6Fh,0Ah,20h,59h,65h,73h,0Ah
	DB	0,0
_dat_car_offset	DB	2,0,1Ch,0,1Eh,0,2,0
	DB	2,0,1Ch,0,0,0,2,0
	DB	0,0,2,0,2,0,1Ch,0
	DB	1Eh,0,2,0,2,0,1Ch,0
_dat_str_empty_2	DB	0,0
_dat_windscreen_shown	DB	0FFh,0FFh
_dat_windscreen_car_shown	DB	0FFh,0FFh
_dat_clock_text	DB	30h,3Ah,30h,30h,3Ah,30h,30h,0
_dat_str_loc	DB	4Ch,6Fh,63h,0
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
asm_block_1911	DB	0
_shd_city_on_screen	DB	0FFh,0FFh
_shd_drive	DB	0FFh,0FFh
_shm_pan_width	DB	40h,1
asm_block_1918	DB	1,0
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
asm_block_1951	DB	0
_shm_pan_building	DB	0,0
_shd_str_animation_pan	DB	61h,6Eh,69h,6Dh,61h,74h,69h,6Fh
	DB	6Eh,2Eh,70h,61h,6Eh,0
_shd_joystick_dirs	DB	8,0,7,0,6,0,1,0
	DB	0FFh,0FFh,5,0,2,0,3,0
	DB	4,0
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
drv_DAT_1663_1a0a	DB	0
drv_DAT_1663_1a0b	DB	0
drv_DAT_1663_1a0c	DB	0,0
drv_DAT_1663_1a0e	DB	0,0
drv_DAT_1663_1a10	DB	0,0
drv_DAT_1663_1a12	DB	0,0
drv_DAT_1663_1a14	DB	0,0
drv_DAT_1663_1a16	DB	0,0
drv_DAT_1663_1a18	DB	0,0
drv_DAT_1663_1a1a	DB	0,0
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
asm_block_1b36	DB	0
drv_DAT_1663_1b37	DB	0,0
drv_DAT_1663_1b39	DB	0,0
drv_DAT_1663_1b3b	DB	0,0
drv_DAT_1663_1b3d	DB	0,0
drv_DAT_1663_1b3f	DB	0FFh,0FFh
asm_block_1b41	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
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
drv_DAT_1663_1cf5	DB	0FFh,0FFh
drv_DAT_1663_1cf7	DB	0,0
asm_block_1cf9	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
drv_DAT_1663_1eaf	DB	0,0
drv_DAT_1663_1eb1	DB	0,0
drv_DAT_1663_1eb3	DB	0FFh,0FFh
drv_DAT_1663_1eb5	DB	0,0
drv_DAT_1663_1eb7	DB	0,0
drv_DAT_1663_1eb9	DB	0,0
asm_block_1ebb	DB	0
drv_DAT_1663_1ebc	DB	0
drv_DAT_1663_1ebd	DB	0,0
drv_DAT_1663_1ebf	DB	0,0
drv_DAT_1663_1ec1	DB	0,0
drv_DAT_1663_1ec3	DB	0,0
drv_DAT_1663_1ec5	DB	3Fh,1
drv_DAT_1663_1ec7	DB	6Fh,0
asm_block_1ec9	DB	0
drv_DAT_1663_1eca	DB	0,0
drv_DAT_1663_1ecc	DB	0,0
drv_DAT_1663_1ece	DB	0,0
drv_DAT_1663_1ed0	DB	0,0
drv_DAT_1663_1ed2	DB	0,0
drv_DAT_1663_1ed4	DB	0,0
drv_DAT_1663_1ed6	DB	0,0
drv_DAT_1663_1ed8	DB	0,0
drv_DAT_1663_1eda	DB	0,0
drv_DAT_1663_1edc	DB	0,0
drv_DAT_1663_1ede	DB	0,0
drv_DAT_1663_1ee0	DB	0,0

_DATA	ENDS

CONST	SEGMENT	WORD PUBLIC 'CONST'
asm_block_22c6	DB	3,0

CONST	ENDS

_BSS	SEGMENT	WORD PUBLIC 'BSS'
asm_block_23a2	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_save_block	DB	0,0,0,0
_shm_save_offset	DB	0,0
_asm_arena	DB	0,0
_asm_view_set	DB	0,0
_asm_view_at	DB	0,0
_asm_view_col	DB	0,0
_asm_view_row	DB	0,0
_asm_windscreen_near	DB	0,0
_asm_windscreen_range	DB	0,0
_asm_windscreen_car_x	DB	0,0
_asm_windscreen_car_y	DB	0,0
_asm_compass_dx	DB	0,0
_asm_compass_dy	DB	0,0
_asm_dash_scratch	DB	0,0
_asm_number_digits_2	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_active_pan	DW	0h		; the library's
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
asm_block_23ee	DB	0,0,0,0,0,0,0,0
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
asm_block_2446	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
_shm_source_fd	DB	0,0
_shm_source_dst	DB	0,0
_shm_source_src	DB	0,0
drv_DAT_1663_245c	DB	0,0
drv_DAT_1663_245e	DB	0
drv_DAT_1663_245f	DB	0,0
drv_DAT_1663_2461	DB	0
asm_block_2462	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
drv_DAT_1663_3c62	DB	0,0
drv_DAT_1663_3c64	DB	0,0
drv_DAT_1663_3c66	DB	0
drv_DAT_1663_3c67	DB	0
drv_DAT_1663_3c68	DB	0
drv_DAT_1663_3c69	DB	0
drv_DAT_1663_3c6a	DB	0,0
drv_DAT_1663_3c6c	DB	0,0
drv_DAT_1663_3c6e	DB	0,0
drv_DAT_1663_3c70	DB	0
drv_DAT_1663_3c71	DB	0
drv_DAT_1663_3c72	DB	0,0
drv_DAT_1663_3c74	DB	0
asm_block_3c75	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
_shm_joystick	DB	2 DUP(?)
_asm_sight_dir	DB	2 DUP(?)
_shm_scratch	DB	200h DUP(?)
D1a6b6	DB	200h DUP(?)
_asm_night	DB	2 DUP(?)
_shm_difficulty	DB	2 DUP(?)
asm_block_428a	DB	2 DUP(?)
_asm_goal_spot	DB	2 DUP(?)
_shm_clock_minutes	DB	2 DUP(?)
_asm_cars	DB	3Ch DUP(?)
_asm_tick	DB	2 DUP(?)
_shm_campaign	DB	28Eh DUP(?)
_shm_seed	DB	2 DUP(?)
_shm_options	DB	2 DUP(?)
_shm_cga	DB	2 DUP(?)
_shm_cities	DB	220h DUP(?)
_shm_menu_tick	DB	2 DUP(?)
_asm_stuck_count	DB	2 DUP(?)
_shm_suspect_count	DB	2 DUP(?)
_asm_cell_map	DB	940h DUP(?)
_asm_windscreen_frame	DB	2 DUP(?)
_shm_menu_face	DB	2 DUP(?)
_asm_head_on	DB	2 DUP(?)
_shm_mouse_regs	DB	0Eh DUP(?)
_asm_outcome	DB	2 DUP(?)
_asm_frame_tick	DB	2 DUP(?)
_shm_crime_events	DB	0B00h DUP(?)
_shm_log_count	DB	2 DUP(?)
_shm_menu_first_line	DB	2 DUP(?)
_shm_case_seed	DB	2 DUP(?)
_shm_building_count	DB	2 DUP(?)
_shm_case_tick	DB	2 DUP(?)
_asm_graphics_word	DB	2 DUP(?)
_shm_source_at	DB	2 DUP(?)
_shm_case_city_1	DB	2 DUP(?)
_shm_case_city_2	DB	2 DUP(?)
_shm_pan_playing	DB	2 DUP(?)
_shm_menu_no_pick	DB	2 DUP(?)
asm_block_5bf6	DB	2 DUP(?)
_shm_menu_items	DB	2 DUP(?)
_asm_engine_note	DB	2 DUP(?)
_asm_fresh_board	DB	2 DUP(?)
_shm_crime_event_count	DB	2 DUP(?)
_asm_DAT_1663_5c00	DB	2 DUP(?)
_asm_start_spot	DB	2 DUP(?)
_shm_menu_relayout	DB	2 DUP(?)
_shm_mission	DB	2 DUP(?)
_shm_menu_colour_bar	DB	2 DUP(?)
_shm_case_org_1	DB	2 DUP(?)
_shm_menu_text_width	DB	2 DUP(?)
_shm_case_org_2	DB	2 DUP(?)
asm_block_5c10	DB	2 DUP(?)
_asm_windscreen_car_sprites	DB	20h DUP(?)
asm_block_5c32	DB	22h DUP(?)
_shm_regs	DB	0Eh DUP(?)
_asm_countdown	DB	2 DUP(?)
_shm_double_agent_cities	DB	2 DUP(?)
_shm_crime_role_count	DB	2 DUP(?)
_shm_menu_marked	DB	2 DUP(?)
_shm_crime_roles	DB	600h DUP(?)
_asm_DAT_1663_626a	DB	2 DUP(?)
_asm_number_digits	DB	0Ah DUP(?)
_shm_refill	DB	2 DUP(?)
DAT_1663_6278	DB	2 DUP(?)
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
asm_block_66ca	DB	4 DUP(?)
_shm_finished	DB	2 DUP(?)
_shm_menu_shortcut	DB	20h DUP(?)
_shm_menu_pick	DB	2 DUP(?)
asm_block_66f2	DB	4Ah DUP(?)
_shm_menu_right	DB	2 DUP(?)
_shm_role_scan_states	DB	0C0h DUP(?)
_shm_graphics_letter	DB	1 DUP(?)
asm_block_67ff	DB	1 DUP(?)
_shm_menu_bottom	DB	2 DUP(?)
_asm_spot_x	DB	20h DUP(?)
_asm_spot_y	DB	20h DUP(?)
_asm_suspect_alert	DB	2 DUP(?)
_shm_case_city	DB	2 DUP(?)
_asm_suspicion_scale	DB	2 DUP(?)
_shm_orgs_known	DB	2 DUP(?)
_shm_jailbreak_suspect	DB	2 DUP(?)
_shm_case_spare_2	DB	2 DUP(?)
_shm_anim_row_2	DB	180h DUP(?)
_asm_goal_x	DB	2 DUP(?)
_asm_goal_y	DB	2 DUP(?)
_shm_case_org	DB	2 DUP(?)
asm_block_69d4	DB	0Ch DUP(?)

c_common	ENDS

	END
