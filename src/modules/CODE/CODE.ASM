	PAGE	60,132
	TITLE	CODE
;
; CODE.ASM -- the assembly side of CODE.EXE.
;
; A SPLIT marker stands where a routine is in C; the build cuts the
; assembly there.
;

	EXTRN	_c_want_disk:PROC
	EXTRN	_c_menu_key:PROC
	EXTRN	_c_pan_blank:PROC
	EXTRN	_c_main:PROC
	EXTRN	_c_hook_hand_back:PROC
	EXTRN	_c_sound_command:PROC
	EXTRN	_c_set_display_page:PROC
	EXTRN	_c_nothing:PROC
	EXTRN	_c_hook_repaint:PROC
	EXTRN	_c_draw_face:PROC
	EXTRN	_c_puzzle_set:PROC
	EXTRN	_c_puzzle_draw:PROC
	EXTRN	_c_give_letter:PROC
	EXTRN	_c_fill_guess_row:PROC
	EXTRN	_c_hint_animate:PROC
	EXTRN	_c_flash_letter:PROC
	EXTRN	_c_play_turn:PROC
	EXTRN	_c_draw_guesses:PROC
	EXTRN	_c_is_solved:PROC
	EXTRN	_c_clock_draw:PROC
	EXTRN	_c_menu_box:PROC
	EXTRN	_c_outline_box:PROC
	EXTRN	_c_pan_arm:PROC
	EXTRN	_c_pan_restore:PROC
	EXTRN	_c_wait_for_release:PROC
	EXTRN	_c_joystick_key:PROC
	EXTRN	_c_joystick_read:PROC
	EXTRN	_c_joystick_button:PROC
	EXTRN	_c_menu_run:PROC
	EXTRN	_c_menu_draw:PROC
	EXTRN	_c_seq_start:PROC
	EXTRN	_c_seq_step:PROC
	EXTRN	_c_mouse_move:PROC
	EXTRN	_c_mouse_presses:PROC
	EXTRN	_c_mouse_releases:PROC
	EXTRN	_c_mouse_fence:PROC
	EXTRN	_c_draw_line:PROC
	EXTRN	_c_write_text:PROC
	EXTRN	_c_write_text_trimmed:PROC
	EXTRN	_c_seed_random:PROC
	EXTRN	_c_random_below:PROC
	EXTRN	_c_clamp:PROC
	EXTRN	_c_seq_stop:PROC
	EXTRN	_c_mouse_reset:PROC
	EXTRN	_c_mouse_show:PROC
	EXTRN	_c_mouse_hide:PROC
	EXTRN	_c_mouse_where:PROC
	EXTRN	_c_wait_retraces:PROC
	EXTRN	_c_screen_save:PROC
	EXTRN	_c_screen_restore:PROC
	EXTRN	_c_fill_box:PROC
	EXTRN	_c_set_graphics_mode:PROC
	EXTRN	_c_set_text_mode:PROC
	PUBLIC	_drv_jump_gfx_set_colour_map
	PUBLIC	_drv_jump_gfx_open
	PUBLIC	_drv_jump_snd_command
	PUBLIC	_drv_jump_gfx_fill
	PUBLIC	_drv_jump_gfx_char_width
	PUBLIC	_drv_jump_gfx_text
	PUBLIC	_drv_real_draw_line
	PUBLIC	_drv_jump_gfx_set_palette
	PUBLIC	_drv_jump_gfx_show_page
	PUBLIC	_drv_jump_keyboard_empty
	PUBLIC	_drv_jump_joy_read
	PUBLIC	_drv_jump_joy_calibrate
	PUBLIC	_drv_real_fill_rect
	PUBLIC	_drv_real_link_slots
	PUBLIC	_drv_jump_gfx_copy_rect
	PUBLIC	_drv_real_FUN_1000_0002
	PUBLIC	_shd_disk_names
	PUBLIC	_shd_disk_letter
	PUBLIC	_drv_jump_read_key
	PUBLIC	_shd_clock_text
	PUBLIC	_shd_pan_disk
	PUBLIC	_shd_map_page
	PUBLIC	_shd_city_on_screen
	PUBLIC	_shd_drive
	PUBLIC	_shm_pan_width
	PUBLIC	_shd_joystick_dirs
	PUBLIC	_shm_pan_building
	PUBLIC	_shm_active_pan
	PUBLIC	_shm_menu_line_start
	PUBLIC	_shm_menu_colour_plain
	PUBLIC	_shm_menu_colour_item
	PUBLIC	_shm_menu_lines
	PUBLIC	_shm_menu_colour_pick
	PUBLIC	_shm_joystick
	PUBLIC	_shm_menu_tick
	PUBLIC	_shm_menu_face
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
	PUBLIC	_shm_seed
	PUBLIC	_shm_mouse_regs
	PUBLIC	_shm_mouse_buttons
	PUBLIC	_shm_mouse_x
	PUBLIC	_shm_mouse_y
	PUBLIC	_shm_mouse_count
	PUBLIC	_shm_menu_shortcut
	PUBLIC	_shm_menu_pick
	PUBLIC	_shm_menu_right
	PUBLIC	_shm_menu_bottom
	PUBLIC	_dat_cipher
	PUBLIC	_dat_plain
	PUBLIC	_dat_guess
	PUBLIC	_dat_one_char
	PUBLIC	_asm_clock_seconds
	PUBLIC	_asm_letter_known
	PUBLIC	_asm_letter_count
	PUBLIC	_shm_menu_draw_only
	PUBLIC	_asm_alphabet_size
	PUBLIC	_shm_scratch
	PUBLIC	_shm_regs
	PUBLIC	_shd_screen
	PUBLIC	_asm_difficulty
	PUBLIC	_shm_options
	PUBLIC	_shm_graphics_letter
	PUBLIC	_asm_solved
	PUBLIC	_shm_clock_minutes
	PUBLIC	_shm_finished
	PUBLIC	_shd_str_please_insert_disk
	PUBLIC	_shd_str_if_3_5_insert
	PUBLIC	_shd_str_close_paren
	PUBLIC	_shd_str_press_return_continue
	PUBLIC	_shd_str_briefing_pan
	PUBLIC	_shd_str_animation_pan
	PUBLIC	_shd_str_bld
	PUBLIC	_shd_str_ok
	PUBLIC	_shd_str_one_moment_please
	PUBLIC	_shd_str_sure_want_quit_no_2
	PUBLIC	_dat_str_sure_want_quit_no
	PUBLIC	_dat_str_paused
	PUBLIC	_dat_str_message_decoded
	PUBLIC	_dat_str_crypto_workstation_msg
	PUBLIC	_shd_palette_menu
	PUBLIC	_shd_palette_face
	PUBLIC	_shd_colours_screen
	PUBLIC	_shd_colours_screen_2
	PUBLIC	_shd_colours_paper
	PUBLIC	_dat_str_zero
	PUBLIC	_dat_str_blank
	PUBLIC	_dat_str_dash
	PUBLIC	_asm_count_digits
	PUBLIC	_dat_str_empty

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
	mov	word ptr ds:[drv_DAT_136d_0042],es
	mov	word ptr ds:[drv_DAT_136d_0044],bx
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
	mov	ds,word ptr ds:[drv_DAT_136d_0042]
	mov	dx,word ptr ds:[drv_DAT_136d_0044]
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
	cmp	byte ptr ds:[drv_DAT_136d_1265],0
	jnz	L100dd
	pop	word ptr cs:[L100d8+3]
	jmp	short L100d8
L100d8:
	; The target is patched in by the POP above.
	jmp	dword ptr cs:[0]
L100dd:
	mov	byte ptr ds:[drv_DAT_136d_1264],1
	pop	word ptr cs:[L100f1+3]
	pop	word ptr ds:[drv_DAT_136d_1266]
	pop	word ptr ds:[drv_DAT_136d_1268]
	jmp	short L100f1
L100f1:
	; The target is patched in by the POP above.
	call	dword ptr cs:[0]
	dec	byte ptr ds:[drv_DAT_136d_1264]
	jz	L10106
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_136d_1264],0
L10106:
	jmp	dword ptr ds:[drv_DAT_136d_1266]
drv_real_dispatch	ENDP
D1010a	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

_drv_jump_gfx_fill	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_fill	ENDP
D10126	DB	0,0

_drv_jump_gfx_char_width	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_char_width	ENDP
D1012d	DB	0,0,0EAh,0,0,0,0

drv_jump_gfx_sprite_put_clipped	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_sprite_put_clipped	ENDP
D10142	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0

drv_jump_gfx_overlay_remove	PROC	NEAR
	call	drv_real_dispatch
L1016f:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_overlay_remove	ENDP
D1017a	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

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
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_show_page	ENDP
D101f1	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

_drv_jump_gfx_open	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_open	ENDP
D1020d	DB	0,0

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

drv_real_load	PROC	FAR
	mov	bx,sp
	mov	dx,word ptr [bx+4]
	mov	bx,word ptr [bx+6]
	push	si
	push	di
	push	ds
	push	es
	mov	word ptr ds:[asm_block_126a],dx
	mov	word ptr ds:[asm_block_126a+2],bx
	mov	ah,48h
	mov	bx,0FFFFh
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jc	L10437
	mov	dx,OFFSET DGROUP:dat_msg_allocated_1mb_space
	jmp	drv_real_FUN_1000_04d0
L10437:
	mov	ah,48h
	sub	bx,100h
	mov	word ptr ds:[asm_block_126a+6],bx
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jnc	L1044b
	mov	dx,OFFSET DGROUP:dat_msg_ms_dos_lied_us
	jmp	drv_real_FUN_1000_04d0
L1044b:
	mov	bx,OFFSET DGROUP:asm_block_126a+8
	mov	word ptr [bx],ax
	mov	word ptr [bx+2],ax
	mov	ax,4B03h
	mov	dx,word ptr ds:[asm_block_126a]
	push	ds
	pop	es
	mov	word ptr ds:[asm_block_126a+4],sp
	int	21h		; DOS AH=4Bh AL=03h: load overlay
	mov	dx,DGROUP
	mov	ds,dx
	mov	es,dx
	mov	ss,dx
	mov	sp,word ptr ds:[asm_block_126a+4]
	jnc	L1048d
	cmp	ax,2
	jnz	L1047c
	mov	dx,OFFSET DGROUP:dat_msg_filename_not_found
	jmp	drv_real_FUN_1000_04d0
L1047c:
	cmp	ax,8
	jnz	L10487
	mov	dx,OFFSET DGROUP:dat_msg_not_enough_memory_load
	jmp	drv_real_FUN_1000_04d0
L10487:
	mov	dx,OFFSET DGROUP:dat_msg_overlay_load_failed
	jmp	drv_real_FUN_1000_04d0
L1048d:
	mov	es,word ptr ds:[asm_block_126a+8]
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
	cmp	bx,word ptr ds:[asm_block_126a+6]
	jbe	L104bd
	mov	dx,OFFSET DGROUP:dat_msg_overlay_has_overrun
	jmp	drv_real_FUN_1000_04d0
L104bd:
	mov	ah,4Ah
	int	21h		; DOS AH=4Ah: resize memory block (ES = segment, BX = paragraphs)
	jnc	L104c9
	mov	dx,OFFSET DGROUP:dat_msg_unable_shrink_overlay
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
	mov	dx,word ptr ds:[asm_block_126a+2]
	or	dx,dx
	jz	L1052b
	mov	ax,3D00h
	int	21h		; DOS AH=3Dh: open existing file (AL = access mode)
	jnc	L104ee
	mov	dx,OFFSET DGROUP:dat_msg_filename_not_found
	jmp	drv_real_FUN_1000_04d0
L104ee:
	mov	ds,bx
	mov	bx,ax
	mov	ax,3F00h
	mov	cx,8000h
	xor	dx,dx
	int	21h		; DOS AH=3Fh: read from file or device (BX = handle, CX = count)
	jnc	L10503
	mov	dx,OFFSET DGROUP:dat_msg_filename_not_found
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
	mov	dx,OFFSET DGROUP:dat_msg_filename_not_found
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

drv_real_free	PROC	FAR
	mov	bx,sp
	mov	ax,word ptr [bx+4]
	push	es
	mov	es,ax
	mov	ah,49h
	int	21h		; DOS AH=49h: free memory block (ES = segment)
	jnc	L10574
	mov	dx,OFFSET DGROUP:dat_msg_error_releasing_overlay
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
	mov	word ptr ds:[drv_DAT_136d_1709],si
	mov	cx,word ptr [bp+0Eh]
	shl	si,1
	lea	di,[drv_DAT_136d_1395]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	mov	dx,cx
	rep stosw
	mov	cx,dx
	lea	di,[drv_DAT_136d_154d]
	add	di,si
	mov	ax,word ptr [bp+8]
	add	ax,word ptr [bx+2]
	add	ax,word ptr [bp+0Ch]
	dec	ax
	rep stosw
	mov	ax,word ptr [bp+10h]
	call	far ptr drv_jump_gfx_set_colour
	mov	ax,ds:[drv_DAT_136d_1709]
	mov	cx,ax
	add	cx,word ptr [bp+0Eh]
	dec	cx
	mov	word ptr ds:[drv_DAT_136d_170b],cx
	mov	bx,OFFSET DGROUP:drv_DAT_136d_1395
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
	mov	ax,ds:[drv_DAT_136d_1709]
	mov	cx,word ptr ds:[drv_DAT_136d_170b]
	mov	bx,OFFSET DGROUP:drv_DAT_136d_1395
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
	mov	di,word ptr ds:[drv_DAT_136d_1709]
	or	di,di
	js	L10633
	mov	cx,word ptr ds:[drv_DAT_136d_170b]
	inc	cx
	sub	cx,di
	shl	di,1
	mov	bx,cx
	mov	dx,di
	add	di,OFFSET DGROUP:drv_DAT_136d_1395
	mov	ax,0FFFFh
	rep stosw
	mov	ds:[drv_DAT_136d_1709],ax
	mov	cx,bx
	mov	di,dx
	add	di,OFFSET DGROUP:drv_DAT_136d_154d
	sub	ax,ax
	rep stosw
	mov	ds:[drv_DAT_136d_170b],ax
L10633:
	ret
drv_real_FUN_1000_05fe	ENDP

drv_real_FUN_1000_0634	PROC	NEAR
	mov	ax,DGROUP
	mov	es,ax
	mov	cx,di
	or	si,si
	lea	di,[drv_DAT_136d_1395]
	jz	L1064d
	cmp	si,word ptr ds:[drv_DAT_136d_171b]
	jnz	L1068e
	lea	di,[drv_DAT_136d_154d]
L1064d:
	cmp	cx,dx
	jge	L10653
	xchg	cx,dx
L10653:
	or	dx,dx
	jns	L10659
	sub	dx,dx
L10659:
	cmp	cx,word ptr ds:[drv_DAT_136d_171d]
	jle	L10663
	mov	cx,word ptr ds:[drv_DAT_136d_171d]
L10663:
	add	si,word ptr ds:[asm_block_170d]
	add	cx,word ptr ds:[asm_block_170d+2]
	add	dx,word ptr ds:[asm_block_170d+2]
	cmp	cx,word ptr ds:[drv_DAT_136d_170b]
	jbe	L10679
	mov	word ptr ds:[drv_DAT_136d_170b],cx
L10679:
	cmp	dx,word ptr ds:[drv_DAT_136d_1709]
	jnc	L10683
	mov	word ptr ds:[drv_DAT_136d_1709],dx
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
	mov	si,word ptr ds:[drv_DAT_136d_171b]
	cmp	bx,si
	jg	drv_real_FUN_1000_0634
	ret
drv_real_FUN_1000_068f	ENDP

drv_real_FUN_1000_069e	PROC	NEAR
	mov	ax,ds:[asm_block_170d]
	add	word ptr ds:[drv_DAT_136d_138d],ax
	add	word ptr ds:[drv_DAT_136d_138f],ax
	mov	ax,ds:[asm_block_170d+2]
	add	word ptr ds:[drv_DAT_136d_1391],ax
	add	word ptr ds:[drv_DAT_136d_1393],ax
	mov	ax,ds:[drv_DAT_136d_138f]
	cmp	ax,word ptr ds:[drv_DAT_136d_138d]
	jnc	L106d6
	mov	bx,word ptr ds:[drv_DAT_136d_138d]
	mov	word ptr ds:[drv_DAT_136d_138f],bx
	mov	ds:[drv_DAT_136d_138d],ax
	mov	ax,ds:[drv_DAT_136d_1393]
	mov	bx,word ptr ds:[drv_DAT_136d_1391]
	mov	word ptr ds:[drv_DAT_136d_1393],bx
	mov	ds:[drv_DAT_136d_1391],ax
L106d6:
	mov	bx,word ptr ds:[drv_DAT_136d_138f]
	sub	bx,word ptr ds:[drv_DAT_136d_138d]
	mov	word ptr ds:[asm_block_154f+438],bx
	mov	ax,ds:[drv_DAT_136d_1393]
	mov	dx,ax
	mov	cx,word ptr ds:[drv_DAT_136d_1391]
	sub	ax,cx
	mov	bp,2
	jns	L106f8
	xchg	cx,dx
	neg	bp
	neg	ax
L106f8:
	mov	ds:[asm_block_154f+440],ax
	cmp	dx,word ptr ds:[drv_DAT_136d_170b]
	jbe	L10705
	mov	word ptr ds:[drv_DAT_136d_170b],dx
L10705:
	cmp	cx,word ptr ds:[drv_DAT_136d_1709]
	jnc	L1070f
	mov	word ptr ds:[drv_DAT_136d_1709],cx
L1070f:
	cmp	ax,bx
	jnc	drv_real_FUN_1000_075e
	mov	di,word ptr ds:[drv_DAT_136d_1391]
	shl	di,1
	mov	ax,ds:[drv_DAT_136d_138d]
	mov	dx,word ptr ds:[asm_block_154f+438]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[asm_block_154f+440]
	jmp	L1073f
L10730:
	cmp	ax,word ptr [di+drv_DAT_136d_154d]
	jbe	L1073a
	mov	word ptr [di+drv_DAT_136d_154d],ax
L1073a:
	inc	ax
	sub	bx,dx
	add	di,bp
L1073f:
	cmp	ax,word ptr [di+drv_DAT_136d_1395]
	jnc	L10749
	mov	word ptr [di+drv_DAT_136d_1395],ax
L10749:
	dec	cx
	js	L10753
	add	bx,si
	jns	L10730
	inc	ax
	jmp	L10749
L10753:
	cmp	ax,word ptr [di+drv_DAT_136d_154d]
	jbe	L1075d
	mov	word ptr [di+drv_DAT_136d_154d],ax
L1075d:
	ret
drv_real_FUN_1000_069e	ENDP

drv_real_FUN_1000_075e	PROC	NEAR
	mov	di,word ptr ds:[drv_DAT_136d_1391]
	shl	di,1
	mov	ax,ds:[drv_DAT_136d_138d]
	mov	dx,word ptr ds:[asm_block_154f+440]
	mov	cx,dx
	mov	bx,cx
	inc	bx
	shr	bx,1
	neg	bx
	mov	si,word ptr ds:[asm_block_154f+438]
L10778:
	cmp	ax,word ptr [di+drv_DAT_136d_1395]
	jnc	L10782
	mov	word ptr [di+drv_DAT_136d_1395],ax
L10782:
	cmp	ax,word ptr [di+drv_DAT_136d_154d]
	jbe	L1078c
	mov	word ptr [di+drv_DAT_136d_154d],ax
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
	mov	ax,ds:[drv_DAT_136d_138d]
	mov	bx,word ptr ds:[drv_DAT_136d_1391]
	mov	cx,word ptr ds:[drv_DAT_136d_138f]
	mov	dx,word ptr ds:[drv_DAT_136d_1393]
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
	mov	word ptr ds:[drv_DAT_136d_1713],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_136d_1717],dx
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
	sar	word ptr ds:[drv_DAT_136d_1713],1
	sar	word ptr ds:[drv_DAT_136d_1717],1
	jmp	L1088f
L10832:
	jmp	L107f4
L10834:
	mov	cx,word ptr ds:[drv_DAT_136d_138d]
	mov	dx,word ptr ds:[drv_DAT_136d_1391]
	mov	si,word ptr ds:[drv_DAT_136d_138f]
	mov	di,word ptr ds:[drv_DAT_136d_1393]
	mov	bx,cx
	mov	bp,dx
	call	drv_real_FUN_1000_0938
	mov	ds:[drv_DAT_136d_1712],al
	mov	bx,si
	mov	bp,di
	call	drv_real_FUN_1000_0938
	jnz	L10871
	cmp	byte ptr ds:[drv_DAT_136d_1712],0
	jnz	L10861
	jmp	L107ce
L10861:
	xchg	cx,si
	xchg	dx,di
	xchg	byte ptr ds:[drv_DAT_136d_1712],al
	mov	word ptr ds:[drv_DAT_136d_138d],cx
	mov	word ptr ds:[drv_DAT_136d_1391],dx
L10871:
	test	byte ptr ds:[drv_DAT_136d_1712],al
	jnz	L10832
	mov	bp,dx
	mov	dx,si
	sub	dx,cx
	jo	L10806
	mov	word ptr ds:[drv_DAT_136d_1713],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_136d_1717],dx
	mov	dx,di
	sub	dx,bp
	jo	L10824
L1088f:
	mov	word ptr ds:[drv_DAT_136d_1715],dx
	sar	dx,1
	mov	word ptr ds:[drv_DAT_136d_1719],dx
L10899:
	test	al,9
	jz	L108d5
	sub	bx,bx
	or	si,si
	js	L108a7
	mov	bx,word ptr ds:[drv_DAT_136d_171b]
L108a7:
	mov	ax,bx
	sub	ax,cx
	imul	word ptr ds:[drv_DAT_136d_1715]
	push	bx
	mov	bx,dx
	idiv	word ptr ds:[drv_DAT_136d_1713]
	mov	bl,bh
	xor	bl,byte ptr ds:[drv_DAT_136d_1713+1]
	jns	L108c1
	neg	dx
	dec	ax
L108c1:
	sub	dx,word ptr ds:[drv_DAT_136d_1717]
	xor	dh,bh
	js	L108ca
	inc	ax
L108ca:
	pop	bx
	add	ax,bp
	js	L108dd
	cmp	ax,word ptr ds:[drv_DAT_136d_171d]
	jle	L1090e
L108d5:
	mov	bx,word ptr ds:[drv_DAT_136d_171d]
	cmp	di,bx
	jg	L108df
L108dd:
	sub	bx,bx
L108df:
	mov	ax,bx
	sub	ax,bp
	imul	word ptr ds:[drv_DAT_136d_1713]
	push	bx
	mov	bx,dx
L108ea:
	idiv	word ptr ds:[drv_DAT_136d_1715]
	mov	bl,bh
	xor	bl,byte ptr ds:[drv_DAT_136d_1715+1]
	jns	L108f9
	neg	dx
	dec	ax
L108f9:
	sub	dx,word ptr ds:[drv_DAT_136d_1719]
	xor	dh,bh
	js	L10902
	inc	ax
L10902:
	pop	bx
	add	ax,cx
	js	L1091f
	cmp	ax,word ptr ds:[drv_DAT_136d_171b]
	jg	L1091f
	xchg	bx,ax
L1090e:
	cmp	byte ptr ds:[drv_DAT_136d_1712],0
	jnz	L10922
	mov	ds:[drv_DAT_136d_1393],ax
	mov	word ptr ds:[drv_DAT_136d_138f],bx
	jmp	L107ce
L1091f:
	jmp	L107f4
L10922:
	mov	ds:[drv_DAT_136d_1391],ax
	mov	word ptr ds:[drv_DAT_136d_138d],bx
	xchg	cx,si
	xchg	bp,di
	mov	al,ds:[drv_DAT_136d_1712]
	mov	byte ptr ds:[drv_DAT_136d_1712],0
	jmp	L10899
drv_real_FUN_1000_07ac	ENDP

drv_real_FUN_1000_0938	PROC	NEAR
	mov	al,0Fh
	or	bx,bx
	js	L10940
	and	al,0F7h
L10940:
	cmp	bx,word ptr ds:[drv_DAT_136d_171b]
	jg	L10948
	and	al,0FEh
L10948:
	or	bp,bp
	js	L1094e
	and	al,0FBh
L1094e:
	cmp	bp,word ptr ds:[drv_DAT_136d_171d]
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
	mov	ax,ds:[drv_DAT_136d_1715]
	jz	L10969
	mov	ax,ds:[drv_DAT_136d_1713]
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
	mov	ds:[drv_DAT_136d_171b],ax
	mov	ax,word ptr [bx+8]
	mov	ds:[drv_DAT_136d_171d],ax
	call	far ptr drv_jump_gfx_select_pic
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_136d_138d],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_136d_1391],ax
	mov	ax,word ptr [bp+0Ch]
	mov	ds:[drv_DAT_136d_138f],ax
	mov	ax,word ptr [bp+0Eh]
	mov	ds:[drv_DAT_136d_1393],ax
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

drv_real_mouse_open	PROC	FAR
	xor	ax,ax
	mov	es,ax
	mov	bx,0CCh
	mov	ax,word ptr es:[bx]
	or	ax,word ptr es:[bx+2]
	jz	L10a4c
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
	or	ax,ax
	jz	L10a4c
	mov	ax,0Ch
	mov	cx,1Fh
	mov	dx,cs
	mov	es,dx
	lea	dx,[drv_real_mouse_event]
	int	33h		; mouse AX=000Ch: set user-defined event handler
	mov	ax,3
	int	33h		; mouse AX=0003h: get position and button status
	mov	word ptr ds:[asm_block_172e],0
	cmp	cx,0C8h
	jc	L10a40
	shr	cx,1
	mov	word ptr ds:[asm_block_172e],1
L10a40:
	mov	word ptr ds:[asm_block_1724],bx
	mov	word ptr ds:[drv_DAT_136d_1720],cx
	mov	word ptr ds:[drv_DAT_136d_1722],dx
L10a4c:
	retf
drv_real_mouse_open	ENDP

drv_real_mouse_close	PROC	FAR
	xor	ax,ax
	mov	es,ax
	mov	bx,0CCh
	mov	ax,word ptr es:[bx]
	or	ax,word ptr es:[bx+2]
	jz	L10a67
	call	far ptr drv_real_FUN_1000_0a86
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
L10a67:
	retf
drv_real_mouse_close	ENDP

drv_real_FUN_1000_0a68	PROC	FAR
	xor	ax,ax
	xchg	word ptr ds:[asm_block_1724+2],ax
	retf
drv_real_FUN_1000_0a68	ENDP

drv_real_mouse_set_cursor	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	ds:[drv_DAT_136d_172a],ax
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_136d_172c],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_136d_1728],ax
	pop	bp
	retf
drv_real_mouse_set_cursor	ENDP

drv_real_FUN_1000_0a86	PROC	FAR
	mov	byte ptr ds:[drv_DAT_136d_1265],0
	call	far ptr drv_jump_gfx_overlay_remove
	retf
drv_real_FUN_1000_0a86	ENDP

drv_real_cursor_show	PROC	FAR
	push	word ptr ds:[drv_DAT_136d_1728]
	mov	ax,ds:[drv_DAT_136d_1722]
	sub	ax,word ptr ds:[drv_DAT_136d_172c]
	push	ax
	mov	ax,ds:[drv_DAT_136d_1720]
	sub	ax,word ptr ds:[drv_DAT_136d_172a]
	push	ax
	call	far ptr drv_jump_gfx_overlay_put
	add	sp,6
	mov	byte ptr ds:[drv_DAT_136d_1265],1
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
	mov	ds:[asm_block_172e+2],ax
	mov	word ptr ds:[asm_block_172e+4],bx
	mov	word ptr ds:[asm_block_172e+6],cx
	mov	word ptr ds:[asm_block_172e+8],dx
	lea	ax,[asm_block_172e+2]
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
	push	word ptr ds:[drv_DAT_136d_1728]
	mov	ax,ds:[drv_DAT_136d_1722]
	sub	ax,word ptr ds:[drv_DAT_136d_172c]
	push	ax
	mov	ax,ds:[drv_DAT_136d_1720]
	sub	ax,word ptr ds:[drv_DAT_136d_172a]
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

drv_real_mouse_event	PROC	FAR
	mov	di,DGROUP
	mov	ds,di
	cmp	word ptr ds:[asm_block_172e],0
	jz	L10b19
	shr	cx,1
L10b19:
	or	word ptr ds:[asm_block_1724+2],bx
	mov	word ptr ds:[asm_block_1724],bx
	mov	word ptr ds:[drv_DAT_136d_1720],cx
	mov	word ptr ds:[drv_DAT_136d_1722],dx
	test	ax,1
	jz	L10b49
	cmp	byte ptr ds:[drv_DAT_136d_1265],0
	jz	L10b49
	mov	al,2
	xchg	byte ptr ds:[drv_DAT_136d_1264],al
	or	al,al
	jnz	L10b49
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_136d_1264],0
L10b49:
	retf
drv_real_mouse_event	ENDP

CODE_0	ENDS

;==============================================================================
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:_TEXT, ds:DGROUP, ss:DGROUP

;;SPLIT main

;;SPLIT FUN_10b4_0164

;;SPLIT FUN_10b4_017d

;;SPLIT FUN_10b4_0194

;;SPLIT FUN_10b4_01b3

;;SPLIT FUN_10b4_01b4

;;SPLIT FUN_10b4_01b5

;;SPLIT FUN_10b4_01b6

;;SPLIT FUN_10b4_02ed

;;SPLIT FUN_10b4_07ed

;;SPLIT FUN_10b4_0863

;;SPLIT FUN_10b4_08c9

;;SPLIT FUN_10b4_0997

;;SPLIT FUN_10b4_0a1a

;;SPLIT FUN_10b4_0c1b

;;SPLIT FUN_10b4_0d64

;;SPLIT FUN_10b4_0dee

;;SPLIT FUN_10b4_0e8e

;;SPLIT FUN_10b4_135d

;;SPLIT FUN_10b4_170e

;;SPLIT FUN_10b4_1766

;;SPLIT FUN_10b4_17bf

;;SPLIT FUN_10b4_1880

;;SPLIT FUN_10b4_18d2

;;SPLIT FUN_10b4_1a03

;;SPLIT FUN_10b4_1a2c

;;SPLIT FUN_10b4_1a5f

;;SPLIT FUN_10b4_1adc

;;SPLIT FUN_10b4_1b58

;;SPLIT FUN_10b4_1b7a

;;SPLIT FUN_10b4_1cac

;;SPLIT FUN_10b4_1cad

;;SPLIT FUN_10b4_1cae

;;SPLIT FUN_10b4_1cb0

;;SPLIT FUN_10b4_1cc6

;;SPLIT FUN_10b4_1cdc

;;SPLIT FUN_10b4_1cf2

;;SPLIT FUN_10b4_1d1a

;;SPLIT FUN_10b4_1d40

;;SPLIT FUN_10b4_1d78

;;SPLIT FUN_10b4_1db0

;;SPLIT FUN_10b4_1df8

;;SPLIT FUN_10b4_1e18

;;SPLIT FUN_10b4_1e39

;;SPLIT FUN_10b4_1e62

;;SPLIT FUN_10b4_1e9a

;;SPLIT FUN_10b4_1eb8

;;SPLIT FUN_10b4_1ed4

;;SPLIT FUN_10b4_1efe

;;SPLIT FUN_10b4_1f18

;;SPLIT FUN_10b4_1f32

;;SPLIT FUN_10b4_1f49

;;SPLIT FUN_10b4_1f62

_TEXT	ENDS

;==============================================================================
_DATA	SEGMENT	WORD PUBLIC 'DATA'
;==============================================================================
drv_DAT_136d_0042	DB	0,0
drv_DAT_136d_0044	DB	0,0
asm_block_0046	DB	0,0,3Fh,3Fh,3Fh,3Fh,3Fh,3Fh
	DB	3Fh,3Fh,3Fh,3Fh,3Fh,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0
dat_note_01	DB	54h,68h,65h,20h,4Dh,69h,63h,72h
	DB	6Fh,50h,72h,6Fh,73h,65h,20h,47h
	DB	72h,61h,70h,68h,69h,63h,73h,20h
	DB	4Ch,69h,62h,72h,61h,72h,79h,20h
	DB	69h,73h,20h,69h,6Eh,74h,65h,6Eh
	DB	64h,65h,64h,20h,74h,6Fh,20h,62h
	DB	65h,20h,61h,20h,63h,6Fh,6Ch,6Ch
	DB	65h,63h,74h,69h,6Fh,6Eh,20h,6Fh
	DB	66h,20h,68h,69h,67h,68h,20h,71h
	DB	75h,61h,6Ch,69h,74h,79h,20h,72h
	DB	6Fh,75h,74h,69h,6Eh,65h,73h,0
dat_note_02	DB	54h,6Fh,20h,70h,65h,72h,66h,6Fh
	DB	72h,6Dh,20h,74h,68h,65h,20h,70h
	DB	72h,69h,6Dh,69h,74h,69h,76h,65h
	DB	20h,67h,72h,61h,70h,68h,69h,63h
	DB	20h,66h,75h,6Eh,63h,74h,69h,6Fh
	DB	6Eh,73h,20h,6Eh,6Fh,72h,6Dh,61h
	DB	6Ch,6Ch,79h,20h,72h,65h,71h,75h
	DB	69h,72h,65h,64h,20h,69h,6Eh,20h
	DB	6Fh,75h,72h,20h,67h,61h,6Dh,65h
	DB	73h,2Eh,0
dat_note_03	DB	54h,68h,65h,20h,72h,6Fh,75h,74h
	DB	69h,6Eh,65h,73h,20h,61h,72h,65h
	DB	20h,63h,6Fh,6Dh,62h,69h,6Eh,65h
	DB	64h,20h,74h,6Fh,67h,65h,74h,68h
	DB	65h,72h,20h,74h,6Fh,20h,66h,6Fh
	DB	72h,6Dh,20h,61h,20h,63h,6Fh,6Eh
	DB	73h,69h,73h,74h,65h,6Eh,74h,20h
	DB	69h,6Eh,74h,65h,72h,66h,61h,63h
	DB	65h,20h,62h,65h,74h,77h,65h,65h
	DB	6Eh,20h,74h,68h,65h,20h,61h,70h
	DB	70h,6Ch,69h,63h,61h,74h,69h,6Fh
	DB	6Eh,73h,2Eh,0
dat_note_04	DB	41h,73h,20h,6Dh,75h,63h,68h,20h
	DB	61h,73h,20h,70h,6Fh,73h,73h,69h
	DB	62h,6Ch,65h,2Ch,20h,67h,72h,61h
	DB	70h,68h,69h,63h,73h,20h,61h,64h
	DB	61h,70h,74h,65h,72h,20h,73h,70h
	DB	65h,63h,69h,66h,69h,63h,20h,6Ch
	DB	6Fh,67h,69h,63h,20h,68h,61h,73h
	DB	20h,62h,65h,65h,6Eh,20h,68h,69h
	DB	64h,64h,65h,6Eh,2Eh,54h,6Fh,20h
	DB	6Dh,61h,6Bh,65h,20h,74h,68h,65h
	DB	20h,75h,6Eh,64h,65h,72h,6Ch,79h
	DB	69h,6Eh,67h,20h,68h,61h,72h,64h
	DB	77h,61h,72h,65h,20h,74h,72h,61h
	DB	6Eh,73h,70h,61h,72h,65h,6Eh,74h
	DB	20h,74h,6Fh,20h,74h,68h,65h,20h
	DB	75h,73h,65h,72h,2Eh,0
dat_note_05	DB	45h,61h,63h,68h,20h,67h,61h,6Dh
	DB	65h,20h,77h,69h,6Ch,6Ch,20h,6Fh
	DB	66h,20h,6Eh,65h,63h,65h,73h,73h
	DB	69h,74h,79h,20h,65h,6Dh,62h,65h
	DB	6Ch,6Ch,69h,73h,68h,20h,74h,68h
	DB	65h,20h,6Ch,69h,62h,72h,61h,72h
	DB	79h,20h,77h,69h,74h,68h,20h,63h
	DB	75h,73h,74h,6Fh,6Dh,20h,66h,65h
	DB	61h,74h,75h,72h,65h,73h,2Eh,0
dat_note_06	DB	48h,6Fh,70h,65h,66h,75h,6Ch,6Ch
	DB	79h,20h,74h,68h,65h,20h,6Ch,69h
	DB	62h,72h,61h,72h,79h,20h,77h,69h
	DB	6Ch,6Ch,20h,61h,74h,20h,6Ch,65h
	DB	61h,73h,74h,20h,70h,72h,6Fh,76h
	DB	69h,64h,65h,20h,74h,68h,65h,20h
	DB	72h,65h,71h,75h,69h,72h,65h,64h
	DB	20h,70h,72h,69h,6Dh,69h,74h,69h
	DB	76h,65h,73h,2Eh,0
dat_note_07	DB	4Dh,61h,6Eh,79h,20h,6Fh,66h,20h
	DB	74h,68h,65h,20h,43h,2Dh,63h,61h
	DB	6Ch,6Ch,61h,62h,6Ch,65h,20h,67h
	DB	72h,61h,70h,68h,69h,63h,73h,20h
	DB	72h,6Fh,75h,74h,69h,6Eh,65h,73h
	DB	20h,67h,65h,74h,20h,74h,68h,65h
	DB	69h,72h,20h,70h,61h,72h,61h,6Dh
	DB	65h,74h,65h,72h,73h,20h,66h,72h
	DB	6Fh,6Dh,20h,61h,20h,52h,61h,73h
	DB	74h,50h,6Fh,72h,74h,2Eh,0
dat_note_08	DB	41h,20h,52h,61h,73h,74h,50h,6Fh
	DB	72h,74h,20h,69h,73h,20h,61h,20h
	DB	64h,65h,66h,69h,6Eh,69h,74h,69h
	DB	6Fh,6Eh,20h,6Fh,66h,20h,61h,20h
	DB	77h,69h,6Eh,64h,6Fh,77h,20h,69h
	DB	6Eh,74h,6Fh,20h,61h,20h,73h,63h
	DB	72h,65h,65h,6Eh,2Eh,0
dat_note_09	DB	49h,74h,20h,64h,65h,66h,69h,6Eh
	DB	65h,73h,20h,74h,68h,65h,20h,62h
	DB	6Fh,75h,6Eh,64h,61h,72h,69h,65h
	DB	73h,20h,6Fh,66h,20h,74h,68h,61h
	DB	74h,20h,77h,69h,6Eh,64h,6Fh,77h
	DB	20h,66h,6Fh,72h,20h,63h,6Ch,69h
	DB	70h,70h,69h,6Eh,67h,20h,61h,6Eh
	DB	64h,20h,72h,65h,6Ch,61h,74h,69h
	DB	76h,65h,20h,61h,64h,64h,72h,65h
	DB	73h,73h,69h,6Eh,67h,2Eh,0
dat_note_10	DB	41h,73h,20h,77h,65h,6Ch,6Ch,20h
	DB	61h,73h,20h,6Dh,61h,69h,6Eh,74h
	DB	61h,69h,6Eh,69h,6Eh,67h,20h,63h
	DB	75h,72h,72h,65h,6Eh,74h,20h,70h
	DB	65h,6Eh,20h,63h,6Fh,6Ch,6Fh,72h
	DB	73h,20h,61h,6Eh,64h,20h,66h,6Fh
	DB	6Eh,74h,20h,69h,6Eh,66h,6Fh,20h
	DB	66h,6Fh,72h,20h,74h,65h,78h,74h
	DB	20h,64h,72h,61h,77h,69h,6Eh,67h
	DB	2Eh,0
dat_note_11	DB	54h,68h,65h,20h,66h,69h,6Ch,65h
	DB	20h,52h,61h,73h,74h,50h,6Fh,72h
	DB	74h,20h,63h,6Fh,6Eh,74h,61h,69h
	DB	6Eh,73h,20h,61h,20h,64h,65h,66h
	DB	69h,6Eh,69h,74h,69h,6Fh,6Eh,20h
	DB	6Fh,66h,20h,74h,68h,65h,20h,73h
	DB	74h,72h,75h,63h,74h,75h,72h,65h
	DB	2Eh,0
dat_note_12	DB	4Dh,61h,70h,20h,61h,20h,67h,72h
	DB	61h,70h,68h,69h,63h,20h,70h,61h
	DB	67h,65h,20h,74h,6Fh,20h,61h,20h
	DB	6Dh,65h,6Dh,6Fh,72h,79h,20h,73h
	DB	65h,67h,6Dh,65h,6Eh,74h,2Eh,0
dat_note_13	DB	52h,65h,74h,75h,72h,6Eh,73h,20h
	DB	6Ch,69h,62h,72h,61h,72h,79h,20h
	DB	73h,70h,65h,63h,69h,66h,69h,63h
	DB	20h,64h,61h,74h,61h,20h,70h,61h
	DB	72h,61h,6Dh,65h,74h,65h,72h,73h
	DB	20h,6Fh,6Eh,65h,20h,61h,74h,20h
	DB	61h,20h,74h,69h,6Dh,65h,2Eh,0
dat_note_14	DB	50h,72h,6Fh,67h,72h,61h,6Dh,73h
	DB	20h,77h,6Fh,75h,6Ch,64h,20h,68h
	DB	61h,76h,65h,20h,61h,6Eh,20h,69h
	DB	6Eh,63h,6Ch,75h,64h,65h,20h,66h
	DB	69h,6Ch,65h,20h,77h,69h,74h,68h
	DB	20h,64h,65h,66h,69h,6Eh,65h,73h
	DB	20h,66h,6Fh,72h,20h,74h,68h,65h
	DB	20h,69h,6Eh,64h,65h,78h,65h,73h
	DB	2Eh,43h,6Fh,6Eh,63h,65h,70h,74h
	DB	75h,61h,6Ch,6Ch,79h,2Ch,20h,74h
	DB	68h,69h,73h,20h,66h,61h,63h,69h
	DB	6Ch,69h,74h,79h,20h,73h,68h,6Fh
	DB	75h,6Ch,64h,20h,62h,65h,20h,66h
	DB	6Fh,72h,20h,73h,74h,61h,74h,69h
	DB	63h,20h,64h,61h,74h,61h,20h,6Fh
	DB	6Eh,6Ch,79h,2Eh,0
dat_note_15	DB	4Ch,6Fh,61h,64h,20h,69h,6Eh,20h
	DB	74h,68h,65h,20h,73h,65h,6Ch,65h
	DB	63h,74h,65h,64h,20h,6Fh,76h,65h
	DB	72h,6Ch,61h,79h,20h,61h,6Eh,64h
	DB	20h,73h,65h,74h,75h,70h,20h,76h
	DB	65h,63h,74h,6Fh,72h,20h,74h,61h
	DB	62h,6Ch,65h,2Eh,0
dat_note_16	DB	54h,68h,69h,73h,20h,69h,73h,20h
	DB	61h,20h,73h,6Fh,66h,74h,77h,61h
	DB	72h,65h,20h,6Fh,6Eh,6Ch,79h,20h
	DB	66h,75h,6Eh,63h,74h,69h,6Fh,6Eh
	DB	2Eh,0
dat_note_17	DB	54h,6Fh,20h,6Ch,6Fh,61h,64h,20h
	DB	74h,68h,65h,20h,6Eh,65h,77h,20h
	DB	70h,61h,6Ch,65h,74h,74h,65h,20h
	DB	69h,6Eh,74h,6Fh,20h,74h,68h,65h
	DB	20h,68h,61h,72h,64h,77h,61h,72h
	DB	65h,20h,72h,65h,67h,69h,73h,74h
	DB	65h,72h,73h,2Ch,20h,61h,20h,53h
	DB	65h,74h,50h,61h,6Ch,65h,74h,74h
	DB	65h,9,69h,73h,20h,72h,65h,71h
	DB	75h,69h,72h,65h,64h,2Eh,0
dat_note_18	DB	53h,65h,74h,20h,76h,69h,64h,65h
	DB	6Fh,20h,6Dh,6Fh,64h,65h,20h,66h
	DB	6Fh,72h,20h,74h,68h,69h,73h,20h
	DB	6Ch,69h,62h,72h,61h,72h,79h,20h
	DB	70h,6Ch,75h,73h,20h,61h,6Eh,79h
	DB	20h,6Fh,74h,68h,65h,72h,20h,6Ch
	DB	69h,62h,72h,61h,72h,79h,20h,73h
	DB	70h,65h,63h,69h,66h,69h,63h,20h
	DB	69h,6Eh,69h,74h,69h,61h,6Ch,69h
	DB	7Ah,61h,74h,69h,6Fh,6Eh,0
dat_note_19	DB	54h,68h,65h,20h,6Dh,6Fh,64h,65h
	DB	20h,61h,72h,67h,75h,6Dh,65h,6Eh
	DB	74h,20h,69h,73h,20h,74h,68h,65h
	DB	20h,73h,61h,6Dh,65h,20h,76h,61h
	DB	6Ch,75h,65h,20h,75h,73h,65h,64h
	DB	20h,66h,6Fh,72h,20h,4Ch,69h,62h
	DB	43h,61h,6Eh,44h,6Fh,2Eh,0
dat_note_20	DB	41h,6Eh,64h,20h,69h,73h,20h,75h
	DB	6Eh,75h,73h,65h,64h,20h,69h,6Eh
	DB	20h,6Ch,69h,62h,72h,61h,72h,69h
	DB	65h,73h,20h,73h,75h,70h,70h,6Fh
	DB	72h,74h,69h,6Eh,67h,9,61h,20h
	DB	73h,69h,6Eh,67h,6Ch,65h,20h,76h
	DB	69h,64h,65h,6Fh,20h,6Dh,6Fh,64h
	DB	65h,2Eh,0
dat_note_21	DB	44h,65h,74h,65h,72h,6Dh,69h,6Eh
	DB	65h,20h,77h,68h,61h,74h,20h,67h
	DB	72h,61h,70h,68h,69h,63h,73h,20h
	DB	6Dh,6Fh,64h,65h,73h,20h,61h,72h
	DB	65h,20h,73h,75h,70h,70h,6Fh,72h
	DB	74h,65h,64h,20h,69h,6Eh,20h,74h
	DB	68h,65h,20h,68h,61h,72h,64h,77h
	DB	61h,72h,65h,2Eh,0
dat_note_22	DB	52h,65h,74h,75h,72h,6Eh,73h,20h
	DB	61h,20h,63h,6Fh,64h,65h,20h,66h
	DB	6Fh,72h,20h,74h,68h,65h,20h,68h
	DB	69h,67h,68h,65h,73h,74h,20h,70h
	DB	65h,72h,66h,6Fh,72h,6Dh,61h,6Eh
	DB	63h,65h,20h,76h,69h,64h,65h,6Fh
	DB	20h,73h,79h,73h,74h,65h,6Dh,20h
	DB	66h,6Fh,75h,6Eh,64h,2Eh,0
dat_note_23	DB	49h,74h,20h,77h,6Fh,75h,6Ch,64h
	DB	20h,62h,65h,20h,6Eh,69h,63h,65h
	DB	20h,69h,66h,20h,74h,68h,69h,73h
	DB	20h,63h,6Fh,64h,65h,20h,77h,61h
	DB	73h,20h,75h,73h,65h,64h,20h,73h
	DB	79h,73h,74h,65h,6Dh,2Dh,77h,69h
	DB	64h,65h,2Eh,0
dat_note_24	DB	54h,68h,69h,73h,20h,67h,72h,6Fh
	DB	75h,70h,20h,6Fh,66h,20h,66h,75h
	DB	6Eh,63h,74h,69h,6Fh,6Eh,73h,20h
	DB	6Fh,70h,65h,72h,61h,74h,65h,20h
	DB	6Fh,6Eh,20h,65h,6Eh,74h,69h,72h
	DB	65h,20h,67h,72h,61h,70h,68h,69h
	DB	63h,20h,70h,61h,67h,65h,73h,2Eh
	DB	0
dat_note_25	DB	44h,69h,73h,70h,6Ch,61h,79h,20h
	DB	74h,68h,65h,20h,73h,65h,6Ch,65h
	DB	63h,74h,65h,64h,20h,67h,72h,61h
	DB	70h,68h,69h,63h,73h,20h,70h,61h
	DB	67h,65h,20h,6Fh,6Eh,20h,74h,68h
	DB	65h,20h,43h,52h,54h,2Eh,0
dat_note_26	DB	4Fh,74h,68h,65h,72h,77h,69h,73h
	DB	65h,20h,61h,20h,62h,6Ch,61h,73h
	DB	74h,20h,69h,73h,20h,70h,65h,72h
	DB	66h,6Fh,72h,6Dh,65h,64h,2Ch,20h
	DB	6Fh,76h,65h,72h,77h,72h,69h,74h
	DB	69h,6Eh,67h,20h,74h,68h,65h,20h
	DB	64h,61h,74h,61h,20h,70h,72h,65h
	DB	76h,69h,6Fh,75h,73h,6Ch,79h,20h
	DB	69h,6Eh,20h,76h,69h,64h,65h,6Fh
	DB	20h,6Dh,65h,6Dh,6Fh,72h,79h,2Eh
	DB	0
dat_note_27	DB	44h,69h,73h,70h,6Ch,61h,79h,20h
	DB	74h,68h,65h,20h,73h,65h,6Ch,65h
	DB	63h,74h,65h,64h,20h,67h,72h,61h
	DB	70h,68h,69h,63h,73h,20h,70h,61h
	DB	67h,65h,20h,6Fh,6Eh,20h,74h,68h
	DB	65h,20h,43h,52h,54h,2Eh,0
dat_note_28	DB	4Fh,74h,68h,65h,72h,77h,69h,73h
	DB	65h,20h,61h,20h,6Eh,6Fh,6Eh,2Dh
	DB	64h,65h,73h,74h,72h,75h,63h,74h
	DB	69h,76h,65h,20h,53h,68h,6Fh,77h
	DB	50h,61h,67h,65h,20h,69h,73h,20h
	DB	70h,65h,72h,66h,6Fh,72h,6Dh,65h
	DB	64h,2Ch,20h,73h,77h,61h,70h,70h
	DB	69h,6Eh,67h,20h,74h,68h,65h,20h
	DB	64h,61h,74h,61h,20h,77h,69h,74h
	DB	68h,20h,74h,68h,65h,20h,76h,69h
	DB	64h,65h,6Fh,20h,62h,75h,66h,66h
	DB	65h,72h,2Eh,0
dat_note_29	DB	41h,20h,72h,61h,6Eh,64h,6Fh,6Dh
	DB	20h,64h,69h,73h,73h,6Fh,6Ch,76h
	DB	65h,20h,69h,73h,20h,70h,65h,72h
	DB	66h,6Fh,72h,6Dh,65h,64h,20h,66h
	DB	72h,6Fh,6Dh,9,70h,61h,67h,65h
	DB	20h,74h,6Fh,20h,74h,68h,65h,20h
	DB	63h,75h,72h,72h,65h,6Eh,74h,20h
	DB	76h,69h,64h,65h,6Fh,20h,70h,61h
	DB	67h,65h,2Eh,0
dat_note_30	DB	54h,68h,69h,73h,20h,69h,73h,20h
	DB	61h,20h,64h,65h,73h,74h,72h,75h
	DB	63h,74h,69h,76h,65h,20h,63h,6Fh
	DB	70h,79h,20h,69h,6Eh,20h,61h,6Ch
	DB	6Ch,20h,76h,69h,64h,65h,6Fh,20h
	DB	6Dh,6Fh,64h,65h,73h,2Eh,0
dat_note_31	DB	54h,68h,69h,73h,20h,67h,72h,6Fh
	DB	75h,70h,20h,6Fh,66h,20h,66h,75h
	DB	6Eh,63h,74h,69h,6Fh,6Eh,73h,20h
	DB	6Fh,70h,65h,72h,61h,74h,65h,20h
	DB	6Fh,6Eh,20h,77h,69h,6Eh,64h,6Fh
	DB	77h,73h,20h,6Fh,66h,20h,67h,72h
	DB	61h,70h,68h,69h,63h,20h,70h,61h
	DB	67h,65h,73h,2Eh,0
dat_note_32	DB	43h,6Fh,70h,79h,20h,61h,20h,77h
	DB	69h,6Eh,64h,6Fh,77h,20h,66h,72h
	DB	6Fh,6Dh,20h,6Fh,6Eh,65h,20h,67h
	DB	72h,61h,70h,68h,69h,63h,73h,20h
	DB	70h,61h,67h,65h,20h,74h,6Fh,20h
	DB	61h,6Eh,6Fh,74h,68h,65h,72h,2Eh
	DB	0
dat_note_33	DB	46h,69h,6Ch,6Ch,20h,61h,20h,77h
	DB	69h,6Eh,64h,6Fh,77h,20h,69h,6Eh
	DB	20h,61h,20h,52h,61h,73h,74h,50h
	DB	6Fh,72h,74h,20h,77h,69h,74h,68h
	DB	20h,61h,20h,63h,6Fh,6Ch,6Fh,72h
	DB	2Eh,0
dat_note_34	DB	54h,68h,65h,73h,65h,20h,72h,6Fh
	DB	75h,74h,69h,6Eh,65h,73h,20h,72h
	DB	65h,61h,64h,20h,61h,20h,70h,69h
	DB	63h,74h,75h,72h,65h,20h,66h,72h
	DB	6Fh,6Dh,20h,61h,20h,64h,69h,73h
	DB	6Bh,20h,66h,69h,6Ch,65h,20h,69h
	DB	6Eh,74h,6Fh,20h,61h,20h,67h,72h
	DB	61h,70h,68h,69h,63h,73h,20h,70h
	DB	61h,67h,65h,2Eh,0
dat_note_35	DB	41h,6Eh,79h,20h,63h,6Fh,6Eh,76h
	DB	65h,72h,73h,69h,6Fh,6Eh,20h,6Fh
	DB	72h,20h,64h,65h,63h,6Fh,6Dh,70h
	DB	72h,65h,73h,73h,69h,6Fh,6Eh,20h
	DB	69h,73h,20h,70h,65h,72h,66h,6Fh
	DB	72h,6Dh,65h,64h,20h,61h,75h,74h
	DB	6Fh,6Dh,61h,74h,69h,63h,61h,6Ch
	DB	6Ch,79h,2Eh,0
dat_note_36	DB	43h,75h,72h,72h,65h,6Eh,74h,6Ch
	DB	79h,20h,74h,77h,6Fh,20h,66h,69h
	DB	6Ch,65h,20h,66h,6Fh,72h,6Dh,61h
	DB	74h,73h,20h,61h,72h,65h,20h,73h
	DB	75h,70h,70h,6Fh,72h,74h,65h,64h
	DB	3Ah,20h,49h,46h,46h,20h,66h,6Fh
	DB	72h,20h,64h,65h,76h,65h,6Ch,6Fh
	DB	70h,6Dh,65h,6Eh,74h,20h,61h,6Eh
	DB	64h,20h,43h,52h,55h,4Eh,43h,48h
	DB	45h,44h,20h,66h,6Fh,72h,20h,70h
	DB	72h,6Fh,64h,75h,63h,74h,69h,6Fh
	DB	6Eh,2Eh,0
dat_note_37	DB	54h,68h,65h,20h,70h,69h,63h,74h
	DB	75h,72h,65h,20h,66h,69h,6Ch,65h
	DB	20h,63h,6Fh,6Eh,74h,61h,69h,6Eh
	DB	73h,20h,63h,6Fh,6Ch,6Fh,72h,20h
	DB	70h,61h,6Ch,65h,74h,74h,65h,20h
	DB	64h,61h,74h,61h,20h,74h,68h,61h
	DB	74h,20h,69h,73h,20h,6Ch,6Fh,61h
	DB	64h,65h,64h,20h,61h,73h,20h,77h
	DB	65h,6Ch,6Ch,2Eh,0
dat_note_38	DB	46h,6Fh,72h,20h,63h,6Fh,6Ch,6Fh
	DB	72h,20h,70h,69h,63h,74h,75h,72h
	DB	65h,73h,2Ch,20h,74h,68h,65h,20h
	DB	70h,61h,6Ch,65h,74h,74h,65h,20h
	DB	69h,73h,20h,31h,36h,20h,63h,6Fh
	DB	6Ch,6Fh,72h,20h,76h,61h,6Ch,75h
	DB	65h,73h,20h,73h,74h,6Fh,72h,65h
	DB	64h,20h,69h,6Eh,20h,62h,79h,74h
	DB	65h,73h,2Eh,0
dat_note_39	DB	57h,69h,74h,68h,20h,74h,68h,65h
	DB	20h,75h,70h,70h,65h,72h,20h,6Eh
	DB	69h,62h,62h,6Ch,65h,20h,62h,65h
	DB	69h,6Eh,67h,20h,62h,6Ch,61h,6Eh
	DB	6Bh,2Eh,0
dat_note_40	DB	54h,68h,65h,20h,66h,6Fh,6Ch,6Ch
	DB	6Fh,77h,69h,6Eh,67h,20h,61h,72h
	DB	65h,20h,75h,73h,65h,64h,20h,69h
	DB	6Eh,74h,65h,72h,6Eh,61h,6Ch,6Ch
	DB	79h,20h,62h,79h,20h,4Ch,6Fh,61h
	DB	64h,50h,69h,63h,74h,75h,72h,65h
	DB	2Eh,0
dat_note_41	DB	54h,68h,65h,20h,66h,6Fh,6Ch,6Ch
	DB	6Fh,77h,69h,6Eh,67h,20h,63h,6Fh
	DB	64h,65h,20h,69h,6Ch,6Ch,75h,73h
	DB	74h,72h,61h,74h,65h,73h,20h,74h
	DB	68h,65h,20h,69h,6Eh,74h,65h,6Eh
	DB	64h,65h,64h,20h,75h,73h,61h,67h
	DB	65h,2Eh,0
dat_note_42	DB	53h,70h,72h,69h,74h,65h,73h,20h
	DB	61h,72h,65h,20h,64h,65h,66h,69h
	DB	6Eh,65h,64h,20h,62h,79h,20h,61h
	DB	20h,73h,74h,72h,75h,63h,74h,75h
	DB	72h,65h,20h,61h,6Eh,64h,20h,61h
	DB	72h,65h,20h,70h,61h,73h,73h,65h
	DB	64h,20h,61h,73h,20h,61h,72h,67h
	DB	75h,6Dh,65h,6Eh,74h,73h,20h,77h
	DB	69h,74h,68h,20h,70h,6Fh,69h,6Eh
	DB	74h,65h,72h,73h,20h,74h,6Fh,20h
	DB	74h,68h,61h,74h,20h,73h,74h,72h
	DB	75h,63h,74h,75h,72h,65h,2Eh,0
dat_note_43	DB	54h,68h,65h,20h,68h,65h,61h,64h
	DB	65h,72h,20h,6Fh,66h,20h,74h,68h
	DB	65h,20h,73h,74h,72h,75h,63h,74h
	DB	75h,72h,65h,20h,64h,65h,66h,69h
	DB	6Eh,65h,73h,20h,74h,68h,65h,20h
	DB	73h,69h,7Ah,65h,20h,6Fh,66h,20h
	DB	74h,68h,65h,20h,73h,70h,72h,69h
	DB	74h,65h,20h,61h,6Eh,64h,20h,6Fh
	DB	74h,68h,65h,72h,20h,70h,61h,72h
	DB	61h,6Dh,65h,74h,65h,72h,20h,64h
	DB	61h,74h,61h,2Eh,0
dat_note_44	DB	46h,6Fh,6Ch,6Ch,6Fh,77h,69h,6Eh
	DB	67h,20h,74h,68h,65h,20h,68h,65h
	DB	61h,64h,65h,72h,20h,69h,73h,20h
	DB	74h,68h,65h,20h,63h,6Fh,6Dh,70h
	DB	72h,65h,73h,73h,65h,64h,20h,70h
	DB	69h,63h,74h,75h,72h,65h,20h,64h
	DB	61h,74h,61h,2Eh,0
dat_note_45	DB	45h,61h,63h,68h,20h,73h,63h,61h
	DB	6Eh,20h,6Ch,69h,6Eh,65h,20h,69h
	DB	73h,20h,64h,65h,66h,69h,6Eh,65h
	DB	64h,20h,62h,79h,20h,74h,77h,6Fh
	DB	20h,73h,69h,7Ah,65h,20h,62h,79h
	DB	74h,65h,73h,20h,61h,6Eh,64h,20h
	DB	74h,68h,65h,20h,76h,61h,72h,69h
	DB	61h,62h,6Ch,65h,20h,6Ch,65h,6Eh
	DB	67h,74h,68h,20h,64h,61h,74h,61h
	DB	2Eh,0
dat_note_46	DB	54h,68h,65h,20h,66h,69h,72h,73h
	DB	74h,20h,73h,69h,7Ah,65h,20h,62h
	DB	79h,74h,65h,20h,67h,69h,76h,65h
	DB	73h,20h,74h,68h,65h,20h,72h,65h
	DB	6Ch,61h,74h,69h,76h,65h,20h,6Fh
	DB	66h,66h,73h,65h,74h,20h,74h,6Fh
	DB	20h,74h,68h,65h,20h,66h,69h,72h
	DB	73h,74h,20h,6Eh,6Fh,6Eh,2Dh,62h
	DB	6Ch,61h,6Eh,6Bh,20h,70h,69h,78h
	DB	65h,6Ch,2Eh,0
dat_note_47	DB	54h,68h,65h,20h,73h,65h,63h,6Fh
	DB	6Eh,64h,20h,73h,69h,7Ah,65h,20h
	DB	62h,79h,74h,65h,20h,67h,69h,76h
	DB	65h,73h,20h,74h,68h,65h,20h,6Ch
	DB	65h,6Eh,67h,74h,68h,20h,6Fh,66h
	DB	20h,64h,61h,74h,61h,20h,66h,6Fh
	DB	6Ch,6Ch,6Fh,77h,69h,6Eh,67h,2Eh
	DB	0
dat_note_48	DB	54h,68h,65h,72h,65h,20h,77h,61h
	DB	73h,20h,61h,20h,63h,6Fh,6Eh,63h
	DB	65h,70h,74h,75h,61h,6Ch,20h,70h
	DB	72h,6Fh,62h,6Ch,65h,6Dh,20h,77h
	DB	69h,74h,68h,20h,62h,75h,69h,6Ch
	DB	64h,69h,6Eh,67h,20h,73h,70h,72h
	DB	69h,74h,65h,73h,20h,6Fh,66h,66h
	DB	2Dh,6Ch,69h,6Eh,65h,2Eh,0
dat_note_49	DB	42h,75h,74h,20h,49h,20h,63h,61h
	DB	6Eh,27h,74h,20h,72h,65h,6Dh,65h
	DB	6Dh,62h,65h,72h,20h,77h,68h,61h
	DB	74h,20h,69h,74h,20h,69h,73h,2Eh
	DB	0
dat_note_50	DB	53h,70h,72h,69h,74h,65h,73h,20h
	DB	63h,61h,6Eh,20h,62h,65h,20h,62h
	DB	75h,69h,6Ch,74h,20h,6Fh,6Eh,6Ch
	DB	69h,6Eh,65h,20h,6Fh,72h,20h,6Fh
	DB	66h,66h,6Ch,69h,6Eh,65h,2Eh,0
dat_note_51	DB	41h,6Eh,20h,6Fh,66h,66h,2Dh,6Ch
	DB	69h,6Eh,65h,20h,73h,70h,72h,69h
	DB	74h,65h,20h,63h,6Fh,6Dh,70h,69h
	DB	6Ch,65h,72h,20h,77h,69h,6Ch,6Ch
	DB	20h,61h,6Ch,6Ch,6Fh,77h,20h,73h
	DB	70h,72h,69h,74h,65h,73h,20h,74h
	DB	6Fh,20h,62h,65h,20h,65h,78h,74h
	DB	72h,61h,63h,74h,65h,64h,20h,66h
	DB	72h,6Fh,6Dh,20h,67h,72h,61h,70h
	DB	68h,69h,63h,20h,69h,6Dh,61h,67h
	DB	65h,73h,2Eh,0
dat_note_52	DB	46h,6Fh,72h,6Dh,65h,64h,20h,69h
	DB	6Eh,74h,6Fh,20h,73h,74h,72h,75h
	DB	63h,74h,75h,72h,65h,73h,20h,61h
	DB	6Eh,64h,20h,73h,61h,76h,65h,64h
	DB	20h,69h,6Eh,20h,64h,69h,73h,6Bh
	DB	20h,66h,69h,6Ch,65h,73h,2Eh,0
dat_note_53	DB	41h,6Eh,20h,6Fh,6Eh,2Dh,6Ch,69h
	DB	6Eh,65h,20h,66h,61h,63h,69h,6Ch
	DB	69h,74h,79h,20h,77h,69h,6Ch,6Ch
	DB	20h,65h,78h,69h,73h,74h,20h,74h
	DB	6Fh,20h,70h,65h,72h,66h,6Fh,72h
	DB	6Dh,20h,74h,68h,65h,20h,73h,61h
	DB	6Dh,65h,20h,66h,75h,6Eh,63h,74h
	DB	69h,6Fh,6Eh,20h,61h,74h,20h,74h
	DB	68h,65h,20h,65h,78h,70h,65h,6Eh
	DB	73h,65h,20h,6Fh,66h,20h,6Ch,6Fh
	DB	6Eh,67h,65h,72h,20h,6Ch,6Fh,61h
	DB	64h,20h,74h,69h,6Dh,65h,73h,2Eh
	DB	0
dat_note_54	DB	53h,70h,72h,69h,74h,65h,73h,20h
	DB	63h,6Fh,6Eh,74h,61h,69h,6Eh,20h
	DB	74h,68h,65h,20h,64h,65h,73h,74h
	DB	69h,6Eh,61h,74h,69h,6Fh,6Eh,20h
	DB	70h,61h,67h,65h,20h,66h,6Fh,72h
	DB	20h,77h,72h,69h,74h,69h,6Eh,67h
	DB	20h,61h,6Eh,64h,20h,64h,69h,73h
	DB	70h,6Ch,61h,79h,2Eh,0
dat_note_55	DB	53h,70h,72h,69h,74h,65h,73h,20h
	DB	41h,4Ch,57h,41h,59h,53h,20h,65h
	DB	78h,69h,73h,74h,20h,69h,6Eh,20h
	DB	72h,65h,61h,6Ch,20h,6Dh,65h,6Dh
	DB	6Fh,72h,79h,20h,61h,6Eh,64h,20h
	DB	61h,72h,65h,20h,69h,6Eh,20h,70h
	DB	69h,78h,65h,6Ch,20h,66h,6Fh,72h
	DB	6Dh,61h,74h,2Eh,0
dat_note_56	DB	49h,74h,20h,69h,73h,20h,73h,74h
	DB	69h,6Ch,6Ch,20h,61h,6Eh,20h,6Fh
	DB	70h,65h,6Eh,20h,69h,73h,73h,75h
	DB	65h,20h,61h,73h,20h,74h,6Fh,20h
	DB	77h,68h,65h,74h,68h,65h,72h,20h
	DB	6Fh,72h,20h,6Eh,6Fh,74h,20h,61h
	DB	20h,73h,65h,70h,61h,72h,61h,74h
	DB	65h,20h,6Dh,61h,73h,6Bh,20h,70h
	DB	6Ch,61h,6Eh,65h,20h,69h,73h,20h
	DB	72h,65h,71h,75h,69h,72h,65h,64h
	DB	2Eh,0,0,0,0
asm_block_0ef4	DB	1,0,2,0,0,2,0,1
	DB	3,1,2,1,0,3,0,1
	DB	11h,11h,2,0,2,3,30h,11h
	DB	13h,31h,22h,23h,33h,33h
_shd_colours_screen	DB	0,0,1,0,2,0,0,2		; COLOUR_MAP
	DB	0,1,2,3,2,1,1,3
_shd_colours_screen_2	DB	0,0,11h,11h,22h,0,0,22h		; COLOUR_MAP
	DB	0,22h,33h,33h,22h,11h,22h,33h
BLOCK_0F32	DB	0,0,11h,11h,22h,22h,22h,22h
	DB	0,22h,33h,33h,0,0,11h,33h
	DB	0,22h,0,0,0,0,0,0
	DB	0,22h,22h,0,0,0,11h,33h
	DB	0,12h,11h,10h,11h,0,12h,33h
	DB	22h,13h,33h,11h,33h,22h,33h,33h
	DB	0,12h,0,0,22h,0,0,13h
	DB	2,11h,0,0,0,0,33h,33h
	DB	0,11h,11h,11h,22h,0,22h,12h
	DB	0,11h,11h,33h,33h,22h,33h,33h
_shd_colours_paper	DB	0,11h,11h,11h,22h,0,22h,12h		; COLOUR_MAP
	DB	0,11h,11h,33h,33h,22h,33h,33h
BLOCK_0F92	DB	0,11h,11h,1,22h,0,22h,22h
	DB	0,11h,11h,33h,33h,33h,33h,33h
BLOCK_0FA2	DB	0,0,11h,11h,22h,0,0,11h
	DB	22h,22h,33h,33h,22h,11h,22h,33h
BLOCK_0FB2	DB	0,0,11h,11h,22h,0,0,22h
	DB	0,22h,33h,33h,22h,11h,22h,33h
BLOCK_0FC2	DB	0,0,11h,11h,22h,0,0,33h
	DB	22h,22h,11h,33h,22h,33h,22h,33h
addr_note_table	DW	OFFSET DGROUP:dat_note_01
	DW	OFFSET DGROUP:dat_note_02
	DW	OFFSET DGROUP:dat_note_03
	DW	OFFSET DGROUP:dat_note_04
	DW	OFFSET DGROUP:dat_note_05
	DW	OFFSET DGROUP:dat_note_06
	DW	OFFSET DGROUP:dat_note_07
	DW	OFFSET DGROUP:dat_note_08
	DW	OFFSET DGROUP:dat_note_09
	DW	OFFSET DGROUP:dat_note_10
	DW	OFFSET DGROUP:dat_note_11
	DW	OFFSET DGROUP:dat_note_12
	DW	OFFSET DGROUP:dat_note_13
	DW	OFFSET DGROUP:dat_note_14
	DW	OFFSET DGROUP:dat_note_15
	DW	OFFSET DGROUP:dat_note_16
	DW	OFFSET DGROUP:dat_note_17
	DW	OFFSET DGROUP:dat_note_18
	DW	OFFSET DGROUP:dat_note_19
	DW	OFFSET DGROUP:dat_note_20
	DW	OFFSET DGROUP:dat_note_21
	DW	OFFSET DGROUP:dat_note_22
	DW	OFFSET DGROUP:dat_note_23
	DW	OFFSET DGROUP:dat_note_24
	DW	OFFSET DGROUP:dat_note_25
	DW	OFFSET DGROUP:dat_note_26
	DW	OFFSET DGROUP:dat_note_27
	DW	OFFSET DGROUP:dat_note_28
	DW	OFFSET DGROUP:dat_note_29
	DW	OFFSET DGROUP:dat_note_30
	DW	OFFSET DGROUP:dat_note_31
	DW	OFFSET DGROUP:dat_note_32
	DW	OFFSET DGROUP:dat_note_33
	DW	OFFSET DGROUP:dat_note_34
	DW	OFFSET DGROUP:dat_note_35
	DW	OFFSET DGROUP:dat_note_36
	DW	OFFSET DGROUP:dat_note_37
	DW	OFFSET DGROUP:dat_note_38
	DW	OFFSET DGROUP:dat_note_39
	DW	OFFSET DGROUP:dat_note_40
	DW	OFFSET DGROUP:dat_note_41
	DW	OFFSET DGROUP:dat_note_42
	DW	OFFSET DGROUP:dat_note_43
	DW	OFFSET DGROUP:dat_note_44
	DW	OFFSET DGROUP:dat_note_45
	DW	OFFSET DGROUP:dat_note_46
	DW	OFFSET DGROUP:dat_note_47
	DW	OFFSET DGROUP:dat_note_48
	DW	OFFSET DGROUP:dat_note_49
	DW	OFFSET DGROUP:dat_note_50
	DW	OFFSET DGROUP:dat_note_51
	DW	OFFSET DGROUP:dat_note_52
	DW	OFFSET DGROUP:dat_note_53
	DW	OFFSET DGROUP:dat_note_54
	DW	OFFSET DGROUP:dat_note_55
	DW	OFFSET DGROUP:dat_note_56
_shd_pan_disk	DB	2,0
dat_map_page_port	DB	1,0,0,0,0,0,3Fh,1		; RASTPORT
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
_shd_map_page	DW	OFFSET DGROUP:dat_map_page_port
_dat_str_empty	DB	0,0
_dat_cipher	DB	41h,42h,43h,44h,45h,46h,47h,48h
	DB	49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh,50h
	DB	51h,52h,53h,54h,55h,56h,57h,58h
	DB	59h,5Ah,5Bh,5Ch,0,0
_dat_plain	DB	41h,42h,43h,44h,45h,46h,47h,48h
	DB	49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh,50h
	DB	51h,52h,53h,54h,55h,56h,57h,58h
	DB	59h,5Ah,5Bh,5Ch,0
asm_block_1095	DB	0
_dat_guess	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,0,0,0
_dat_str_crypto_workstation_msg	DB	43h,52h,59h,50h,54h,4Fh,20h,57h
	DB	4Fh,52h,4Bh,53h,54h,41h,54h,49h
	DB	4Fh,4Eh,2Ch,20h,4Dh,73h,67h,3Ah
	DB	23h,4Dh,31h,37h,33h,0
_dat_str_zero	DB	30h,0
_dat_str_blank	DB	0
_dat_str_dash	DB	2Dh,0
BLOCK_10D9	DB	0
_dat_one_char	DB	78h,0
_dat_str_sure_want_quit_no	DB	41h,72h,65h,20h,79h,6Fh,75h,20h
	DB	73h,75h,72h,65h,0Ah,79h,6Fh,75h
	DB	20h,77h,61h,6Eh,74h,20h,74h,6Fh
	DB	20h,51h,75h,69h,74h,3Fh,0Ah,20h
	DB	4Eh,6Fh,0Ah,20h,59h,65h,73h,0Ah
	DB	0
_dat_str_paused	DB	50h,41h,55h,53h,45h,44h,0Ah,0
_dat_str_message_decoded	DB	4Dh,45h,53h,53h,41h,47h,45h,20h
	DB	44h,45h,43h,4Fh,44h,45h,44h,0Ah
	DB	0
_shd_clock_text	DB	30h,30h,3Ah,30h,30h,3Ah,30h,30h
	DB	0
asm_block_1127	DB	0
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
asm_block_116b	DB	0
_shd_city_on_screen	DB	0FFh,0FFh
_shd_drive	DB	0FFh,0FFh
_shm_pan_width	DB	40h,1
asm_block_1172	DB	1,0
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
asm_block_11ab	DB	0
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
drv_DAT_136d_1264	DB	0
drv_DAT_136d_1265	DB	0
drv_DAT_136d_1266	DB	0,0
drv_DAT_136d_1268	DB	0,0
asm_block_126a	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0
dat_msg_allocated_1mb_space	DB	41h,6Ch,6Ch,6Fh,63h,61h,74h,65h
	DB	64h,20h,31h,4Dh,62h,20h,6Fh,66h
	DB	20h,73h,70h,61h,63h,65h,3Fh,3Fh
	DB	3Fh,3Fh,24h
dat_msg_ms_dos_lied_us	DB	4Dh,53h,2Dh,44h,4Fh,53h,20h,6Ch
	DB	69h,65h,64h,20h,74h,6Fh,20h,75h
	DB	73h,20h,61h,62h,6Fh,75h,74h,20h
	DB	68h,6Fh,77h,20h,6Dh,75h,63h,68h
	DB	20h,6Dh,65h,6Dh,6Fh,72h,79h,20h
	DB	77h,61h,73h,20h,61h,76h,61h,69h
	DB	6Ch,61h,62h,6Ch,65h,24h
dat_msg_filename_not_found	DB	46h,69h,6Ch,65h,6Eh,61h,6Dh,65h
	DB	20h,6Eh,6Fh,74h,20h,66h,6Fh,75h
	DB	6Eh,64h,24h
dat_msg_not_enough_memory_load	DB	4Eh,6Fh,74h,20h,65h,6Eh,6Fh,75h
	DB	67h,68h,20h,6Dh,65h,6Dh,6Fh,72h
	DB	79h,20h,74h,6Fh,20h,6Ch,6Fh,61h
	DB	64h,20h,66h,69h,6Ch,65h,24h
dat_msg_overlay_load_failed	DB	4Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	6Ch,6Fh,61h,64h,20h,66h,61h,69h
	DB	6Ch,65h,64h,20h,66h,6Fh,72h,20h
	DB	73h,6Fh,6Dh,65h,20h,72h,65h,61h
	DB	73h,6Fh,6Eh,24h
dat_msg_overlay_has_overrun	DB	4Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	68h,61h,73h,20h,6Fh,76h,65h,72h
	DB	72h,75h,6Eh,20h,61h,6Ch,6Ch,6Fh
	DB	63h,61h,74h,65h,64h,20h,6Dh,65h
	DB	6Dh,6Fh,72h,79h,24h
dat_msg_unable_shrink_overlay	DB	55h,6Eh,61h,62h,6Ch,65h,20h,74h
	DB	6Fh,20h,73h,68h,72h,69h,6Eh,6Bh
	DB	20h,6Fh,76h,65h,72h,6Ch,61h,79h
	DB	20h,6Dh,65h,6Dh,6Fh,72h,79h,20h
	DB	61h,6Ch,6Ch,6Fh,63h,61h,74h,69h
	DB	6Fh,6Eh,24h
dat_msg_error_releasing_overlay	DB	45h,72h,72h,6Fh,72h,20h,72h,65h
	DB	6Ch,65h,61h,73h,69h,6Eh,67h,20h
	DB	6Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	6Dh,65h,6Dh,6Fh,72h,79h,24h
asm_message_pool_pad	DB	0
drv_DAT_136d_138d	DB	0,0
drv_DAT_136d_138f	DB	0,0
drv_DAT_136d_1391	DB	0,0
drv_DAT_136d_1393	DB	0,0
drv_DAT_136d_1395	DB	0FFh,0FFh
asm_block_1397	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
	DB	0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh,0FFh
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
drv_DAT_136d_154b	DB	0FFh,0FFh
drv_DAT_136d_154d	DB	0,0
asm_block_154f	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
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
drv_DAT_136d_1709	DB	0FFh,0FFh
drv_DAT_136d_170b	DB	0,0
asm_block_170d	DB	0,0,0,0,0
drv_DAT_136d_1712	DB	0
drv_DAT_136d_1713	DB	0,0
drv_DAT_136d_1715	DB	0,0
drv_DAT_136d_1717	DB	0,0
drv_DAT_136d_1719	DB	0,0
drv_DAT_136d_171b	DB	3Fh,1
drv_DAT_136d_171d	DB	6Fh,0
asm_block_171f	DB	0
drv_DAT_136d_1720	DB	0,0
drv_DAT_136d_1722	DB	0,0
asm_block_1724	DB	0,0,0,0
drv_DAT_136d_1728	DB	0,0
drv_DAT_136d_172a	DB	0,0
drv_DAT_136d_172c	DB	0,0
asm_block_172e	DB	0,0,0,0,0,0,0,0
	DB	0,0

_DATA	ENDS

CONST	SEGMENT	WORD PUBLIC 'CONST'
asm_block_1994	DB	3,0

CONST	ENDS

;==============================================================================
_BSS	SEGMENT	WORD PUBLIC 'BSS'
;==============================================================================
asm_block_1a70	DB	1 DUP(?)
asm_block_1a71	DB	1 DUP(?)
asm_block_1a72	DB	8 DUP(?)
_asm_clock_seconds	DB	2 DUP(?)
_asm_letter_known	DB	38h DUP(?)
_asm_count_digits	DB	0Ah DUP(?)
_asm_alphabet_size	DB	2 DUP(?)
_asm_letter_count	DB	38h DUP(?)
_shm_active_pan	DB	0Eh DUP(?)
asm_block_1b06	DB	10h DUP(?)
_shm_menu_line_start	DB	40h DUP(?)
_shm_menu_colour_plain	DB	2 DUP(?)
_shm_menu_colour_item	DB	2 DUP(?)
_shm_menu_lines	DB	2 DUP(?)
_shm_menu_colour_pick	DB	2 DUP(?)
asm_block_1b5e	DB	10h DUP(?)

_BSS	ENDS

c_common	SEGMENT	PARA PUBLIC 'BSS'
_shm_joystick	DB	2 DUP(?)
_shm_scratch	DB	200h DUP(?)
_asm_difficulty	DB	2 DUP(?)
asm_block_1d74	DB	2 DUP(?)
_shm_seed	DB	2 DUP(?)
_shm_options	DB	2 DUP(?)
_shm_graphics_letter	DB	2 DUP(?)
_shm_menu_tick	DB	2 DUP(?)
_shm_menu_face	DB	2 DUP(?)
_shm_mouse_regs	DB	0Eh DUP(?)
_asm_solved	DB	2 DUP(?)
_shm_clock_minutes	DB	2 DUP(?)
_shm_menu_first_line	DB	2 DUP(?)
_shm_pan_playing	DB	2 DUP(?)
_shm_menu_no_pick	DB	2 DUP(?)
_shm_menu_items	DB	2 DUP(?)
_shm_menu_relayout	DB	2 DUP(?)
_shm_menu_colour_bar	DB	2 DUP(?)
_shm_menu_text_width	DB	2 DUP(?)
_shm_regs	DB	0Eh DUP(?)
_shm_menu_marked	DB	2 DUP(?)
_shm_menu_face_x	DB	2 DUP(?)
_shm_menu_draw_only	DB	2 DUP(?)
_shm_mouse_buttons	DB	2 DUP(?)
_shm_mouse_x	DB	2 DUP(?)
_shm_mouse_y	DB	2 DUP(?)
_shm_mouse_count	DB	2 DUP(?)
_shm_menu_face_y	DB	2 DUP(?)
_shm_finished	DB	2 DUP(?)
_shm_menu_shortcut	DB	20h DUP(?)
_shm_menu_pick	DB	2 DUP(?)
_shm_menu_right	DB	2 DUP(?)
_shm_menu_bottom	DB	2 DUP(?)
asm_block_1de6	DB	0Ah DUP(?)

c_common	ENDS

	END
