	PAGE	60,132
	TITLE	COVERT
;
; COVERT.ASM -- the assembly side of COVERT.EXE.
;
; A SPLIT marker stands where a routine is in C; the build cuts the
; assembly there.
;

	EXTRN	_c_main:PROC
	PUBLIC	_dat_MODULE_TABLE
	PUBLIC	_dat_GRAPHIC_NAME
	PUBLIC	_dat_SOUND_NAME
	PUBLIC	_asm_DRIVER_HANDLE
	PUBLIC	_asm_COMM_BLOCK
	PUBLIC	_drv_jump_gfx_page_seg
	PUBLIC	_drv_jump_gfx_set_page_seg
	PUBLIC	_drv_jump_gfx_open
	PUBLIC	_drv_jump_snd_open
	PUBLIC	_drv_jump_snd_close
	PUBLIC	_drv_real_load
	PUBLIC	_drv_real_link_slots
	PUBLIC	_dat_exe_intro
	PUBLIC	_dat_str_empty_arg
	PUBLIC	_dat_file_fonts
	PUBLIC	_dat_exe_misc
	PUBLIC	_dat_exe_mcv
	PUBLIC	_dat_ext_cv
	PUBLIC	_dat_arg_slash_2
	PUBLIC	_dat_module_spawn_arg
	PUBLIC	_asm_regs

; Every segment declared once, empty, so LINK sees them in this order.
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
_TEXT	ENDS
CODE_1	SEGMENT	WORD PUBLIC 'CODE'
CODE_1	ENDS
_DATA	SEGMENT	WORD PUBLIC 'DATA'
_DATA	ENDS
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

DGROUP	GROUP	_DATA,c_common

;==============================================================================
_TEXT	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:_TEXT, ds:DGROUP, ss:DGROUP

;;SPLIT main

_TEXT	ENDS

;==============================================================================
CODE_1	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:CODE_1, ds:DGROUP, ss:DGROUP

;------------------------------------------------------------------------------
; Jump into a driver through the slot whose address the caller pushed. With
; the cursor showing it far-calls instead, so the cursor can be redrawn after.
;------------------------------------------------------------------------------
drv_real_dispatch	PROC	NEAR
	cmp	byte ptr ds:[drv_DAT_117e_0123],0
	jnz	L111b5
	pop	word ptr cs:[L111b0+3]
	jmp	short L111b0
L111b0:
	; The target is patched in by the POP above.
	jmp	dword ptr cs:[0]
L111b5:
	mov	byte ptr ds:[drv_DAT_117e_0122],1
	pop	word ptr cs:[L111c9+3]
	pop	word ptr ds:[drv_DAT_117e_0124]
	pop	word ptr ds:[drv_DAT_117e_0124+2]
	jmp	short L111c9
L111c9:
	; The target is patched in by the POP above.
	call	dword ptr cs:[0]
	dec	byte ptr ds:[drv_DAT_117e_0122]
	jz	L111de
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_117e_0122],0
L111de:
	jmp	dword ptr ds:[drv_DAT_117e_0124]
drv_real_dispatch	ENDP
D111e2	DB	0,0

_drv_jump_gfx_page_seg	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_page_seg	ENDP
D111e9	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0

drv_jump_gfx_sprite_put_clipped	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_sprite_put_clipped	ENDP
D1121a	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0

drv_jump_gfx_overlay_remove	PROC	NEAR
	call	drv_real_dispatch
L11247:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_overlay_remove	ENDP
D11252	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0

drv_jump_FUN_111a_00d5	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_FUN_111a_00d5	ENDP
D11283	DB	0,0,0EAh,0,0,0,0,0
	DB	0

_drv_jump_gfx_set_page_seg	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_set_page_seg	ENDP
D11291	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0

drv_jump_gfx_overlay_put	PROC	NEAR
	call	drv_real_dispatch
L112b0:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_overlay_put	ENDP
D112c9	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

_drv_jump_gfx_open	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_gfx_open	ENDP
D112e5	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0,0,0,0EAh,0,0,0
	DB	0,0,0,0EAh,0,0,0,0
	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0,0,0,0EAh,0,0,0
	DB	0,0,0,0EAh,0,0,0,0
	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0

_drv_jump_snd_open	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_snd_open	ENDP
D114a5	DB	0,0,0EAh,0,0,0,0,0
	DB	0

_drv_jump_snd_close	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_snd_close	ENDP
D114b3	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0,0,0,0EAh,0,0,0
	DB	0,0,0,0EAh,0,0,0,0
	DB	0

;------------------------------------------------------------------------------
; Load a driver: allocate all of memory, EXEC it as an overlay, shrink the
; block to what it needs, and return its segment. A second name loads a data
; file.
;------------------------------------------------------------------------------
_drv_real_load	PROC	FAR
	mov	bx,sp
	mov	dx,word ptr [bx+4]
	mov	bx,word ptr [bx+6]
	push	si
	push	di
	push	ds
	push	es
	mov	word ptr ds:[drv_DAT_117e_0124+4],dx
	mov	word ptr ds:[drv_DAT_117e_0124+6],bx
	mov	ah,48h
	mov	bx,0FFFFh
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jc	L1150f
	mov	dx,OFFSET DGROUP:dat_msg_allocated
	jmp	drv_real_fail
L1150f:
	mov	ah,48h
	sub	bx,100h
	mov	word ptr ds:[drv_DAT_117e_0124+10],bx
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jnc	L11523
	mov	dx,OFFSET DGROUP:dat_msg_dos_lied
	jmp	drv_real_fail
L11523:
	mov	bx,OFFSET DGROUP:drv_DAT_117e_0124+12
	mov	word ptr [bx],ax
	mov	word ptr [bx+2],ax
	mov	ax,4B03h
	mov	dx,word ptr ds:[drv_DAT_117e_0124+4]
	push	ds
	pop	es
	mov	word ptr ds:[drv_DAT_117e_0124+8],sp
	int	21h		; DOS AH=4Bh AL=03h: load overlay
	mov	dx,DGROUP
	mov	ds,dx
	mov	es,dx
	mov	ss,dx
	mov	sp,word ptr ds:[drv_DAT_117e_0124+8]
	jnc	L11565
	cmp	ax,2
	jnz	L11554
	mov	dx,OFFSET DGROUP:dat_msg_file_not_found
	jmp	drv_real_fail
L11554:
	cmp	ax,8
	jnz	L1155f
	mov	dx,OFFSET DGROUP:dat_msg_load_no_memory
	jmp	drv_real_fail
L1155f:
	mov	dx,OFFSET DGROUP:dat_msg_load_failed
	jmp	drv_real_fail
L11565:
	mov	es,word ptr ds:[drv_DAT_117e_0124+12]
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
	cmp	bx,word ptr ds:[drv_DAT_117e_0124+10]
	jbe	L11595
	mov	dx,OFFSET DGROUP:dat_msg_overlay_overrun
	jmp	drv_real_fail
L11595:
	mov	ah,4Ah
	int	21h		; DOS AH=4Ah: resize memory block (ES = segment, BX = paragraphs)
	jnc	L115a1
	mov	dx,OFFSET DGROUP:dat_msg_shrink_failed
	jmp	drv_real_fail
L115a1:
	mov	ax,es
	pop	es
	pop	ds
	pop	di
	pop	si
	retf
_drv_real_load	ENDP

;------------------------------------------------------------------------------
; Print the $-terminated message in DX and exit to DOS. Never returns.
;------------------------------------------------------------------------------
drv_real_fail	PROC	NEAR
	mov	ah,9
	int	21h		; DOS AH=09h: write $-terminated string to stdout
	mov	ax,4C00h
	int	21h		; DOS AH=4Ch: terminate (AL = code)
drv_real_fail	ENDP

;------------------------------------------------------------------------------
; Read the data file a driver load names into memory after the driver, in 32K
; goes, and return the segment past it.
;------------------------------------------------------------------------------
drv_real_load_data	PROC	NEAR
	push	ds
	mov	dx,word ptr ds:[drv_DAT_117e_0124+6]
	or	dx,dx
	jz	L11603
	mov	ax,3D00h
	int	21h		; DOS AH=3Dh: open existing file (AL = access mode)
	jnc	L115c6
	mov	dx,OFFSET DGROUP:dat_msg_file_not_found
	jmp	drv_real_fail
L115c6:
	mov	ds,bx
	mov	bx,ax
	mov	ax,3F00h
	mov	cx,8000h
	xor	dx,dx
	int	21h		; DOS AH=3Fh: read from file or device (BX = handle, CX = count)
	jnc	L115db
	mov	dx,OFFSET DGROUP:dat_msg_file_not_found
	jmp	drv_real_fail
L115db:
	cmp	ax,cx
	jc	L115e6
	mov	ax,ds
	add	ax,800h
	mov	ds,ax
L115e6:
	add	ax,0Fh
	shr	ax,1
	shr	ax,1
	shr	ax,1
	shr	ax,1
	mov	dx,ds
	add	dx,ax
	mov	ax,3E00h
	int	21h		; DOS AH=3Eh: close file (BX = handle)
	jnc	L11601
	mov	dx,OFFSET DGROUP:dat_msg_file_not_found
	jmp	drv_real_fail
L11601:
	mov	bx,dx
L11603:
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
	lea	di,[D111e2]
	add	di,ax
	mov	ax,CODE_1
	mov	es,ax
	mov	cx,word ptr ds:[30h]
	mov	ax,ds:[28h]
L1162c:
	add	di,3
	movsw
	stosw
	loop	L1162c
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
	jnc	L1164c
	mov	dx,OFFSET DGROUP:dat_msg_release_failed
	jmp	drv_real_fail
L1164c:
	pop	es
	retf
drv_real_free	ENDP

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
	jz	L1169c
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
	or	ax,ax
	jz	L1169c
	mov	ax,0Ch
	mov	cx,1Fh
	mov	dx,cs
	mov	es,dx
	lea	dx,[drv_real_mouse_event]
	int	33h		; mouse AX=000Ch: set user-defined event handler
	mov	ax,3
	int	33h		; mouse AX=0003h: get position and button status
	mov	word ptr ds:[drv_DAT_117e_0258],0
	cmp	cx,0C8h
	jc	L11690
	shr	cx,1
	mov	word ptr ds:[drv_DAT_117e_0258],1
L11690:
	mov	word ptr ds:[drv_DAT_117e_024e],bx
	mov	word ptr ds:[asm_message_pool_pad],cx
	mov	word ptr ds:[drv_DAT_117e_024c],dx
L1169c:
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
	jz	L116b7
	call	far ptr drv_real_cursor_hide
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
L116b7:
	retf
drv_real_mouse_close	ENDP

;------------------------------------------------------------------------------
; Return the buttons pressed since the last call, and forget them.
;------------------------------------------------------------------------------
drv_real_mouse_take_buttons	PROC	FAR
	xor	ax,ax
	xchg	word ptr ds:[drv_DAT_117e_0250],ax
	retf
drv_real_mouse_take_buttons	ENDP

;------------------------------------------------------------------------------
; Set the cursor's hot spot and which shape to draw.
;------------------------------------------------------------------------------
drv_real_mouse_set_cursor	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	ds:[drv_DAT_117e_0254],ax
	mov	ax,word ptr [bp+8]
	mov	ds:[drv_DAT_117e_0256],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[drv_DAT_117e_0252],ax
	pop	bp
	retf
drv_real_mouse_set_cursor	ENDP

;------------------------------------------------------------------------------
; Take the cursor off the screen and record that it is off.
;------------------------------------------------------------------------------
drv_real_cursor_hide	PROC	FAR
	mov	byte ptr ds:[drv_DAT_117e_0123],0
	call	far ptr drv_jump_gfx_overlay_remove
	retf
drv_real_cursor_hide	ENDP

;------------------------------------------------------------------------------
; Draw the cursor at the position the last event left, and record that it is
; on.
;------------------------------------------------------------------------------
drv_real_cursor_show	PROC	FAR
	push	word ptr ds:[drv_DAT_117e_0252]
	mov	ax,ds:[drv_DAT_117e_024c]
	sub	ax,word ptr ds:[drv_DAT_117e_0256]
	push	ax
	mov	ax,ds:[asm_message_pool_pad]
	sub	ax,word ptr ds:[drv_DAT_117e_0254]
	push	ax
	call	far ptr drv_jump_gfx_overlay_put
	add	sp,6
	mov	byte ptr ds:[drv_DAT_117e_0123],1
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
	mov	ds:[drv_DAT_117e_025a],ax
	mov	word ptr ds:[drv_DAT_117e_025c],bx
	mov	word ptr ds:[drv_DAT_117e_025e],cx
	mov	word ptr ds:[drv_DAT_117e_0260],dx
	lea	ax,[drv_DAT_117e_025a]
	pop	bp
	retf
drv_real_mouse_int	ENDP

;------------------------------------------------------------------------------
; Put back what the cursor covered and draw it again where it now is.
;------------------------------------------------------------------------------
drv_real_cursor_redraw	PROC	FAR
	push	ax
	push	dx
	push	es
	mov	ax,CODE_1
	mov	es,ax
	call	dword ptr es:[L11247]
	push	word ptr ds:[drv_DAT_117e_0252]
	mov	ax,ds:[drv_DAT_117e_024c]
	sub	ax,word ptr ds:[drv_DAT_117e_0256]
	push	ax
	mov	ax,ds:[asm_message_pool_pad]
	sub	ax,word ptr ds:[drv_DAT_117e_0254]
	push	ax
	mov	ax,CODE_1
	mov	es,ax
	call	dword ptr es:[L112b0]
	add	sp,6
	pop	es
	pop	dx
	pop	ax
	retf
drv_real_cursor_redraw	ENDP

;------------------------------------------------------------------------------
; The mouse driver's own callback, on its stack: record the position and the
; buttons, and redraw the cursor if it is showing.
;------------------------------------------------------------------------------
drv_real_mouse_event	PROC	FAR
	mov	di,DGROUP
	mov	ds,di
	cmp	word ptr ds:[drv_DAT_117e_0258],0
	jz	L11769
	shr	cx,1
L11769:
	or	word ptr ds:[drv_DAT_117e_0250],bx
	mov	word ptr ds:[drv_DAT_117e_024e],bx
	mov	word ptr ds:[asm_message_pool_pad],cx
	mov	word ptr ds:[drv_DAT_117e_024c],dx
	test	ax,1
	jz	L11799
	cmp	byte ptr ds:[drv_DAT_117e_0123],0
	jz	L11799
	mov	al,2
	xchg	byte ptr ds:[drv_DAT_117e_0122],al
	or	al,al
	jnz	L11799
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[drv_DAT_117e_0122],0
L11799:
	retf
drv_real_mouse_event	ENDP
D1179a	DB	0,0,0,0,0,0

CODE_1	ENDS

;==============================================================================
_DATA	SEGMENT	WORD PUBLIC 'DATA'
;==============================================================================
dat_module_0	DB	67h,61h,6Dh,65h,2Eh,65h,78h,65h
	DB	0
dat_module_1	DB	74h,61h,63h,2Eh,65h,78h,65h,0
dat_module_2	DB	63h,6Fh,64h,65h,2Eh,65h,78h,65h
	DB	0
dat_module_3	DB	63h,68h,61h,73h,65h,2Eh,65h,78h
	DB	65h,0
dat_module_4	DB	62h,75h,67h,2Eh,65h,78h,65h,0
dat_module_5	DB	63h,68h,61h,73h,65h,2Eh,65h,78h
	DB	65h,0
dat_module_6	DB	63h,68h,61h,73h,65h,2Eh,65h,78h
	DB	65h,0
dat_module_7	DB	74h,61h,63h,2Eh,65h,78h,65h,0
dat_module_8	DB	74h,61h,63h,2Eh,65h,78h,65h,0
dat_module_9	DB	66h,69h,6Eh,61h,6Ch,2Eh,65h,78h
	DB	65h,0
dat_module_10	DB	74h,61h,63h,2Eh,65h,78h,65h,0
dat_module_11	DB	66h,69h,6Eh,61h,6Ch,2Eh,65h,78h
	DB	65h,0
dat_module_12	DB	62h,75h,67h,2Eh,65h,78h,65h,0
dat_module_13	DB	74h,61h,63h,2Eh,65h,78h,65h,0
dat_module_14	DB	63h,68h,61h,73h,65h,2Eh,65h,78h
	DB	65h,0
dat_module_15	DB	63h,6Fh,64h,65h,2Eh,65h,78h,65h
	DB	0
dat_module_16	DB	62h,75h,67h,2Eh,65h,78h,65h,0
dat_module_17	DB	66h,69h,6Eh,61h,6Ch,2Eh,65h,78h
	DB	65h,0
_dat_str_empty_arg	DB	0
_dat_exe_intro	DB	69h,6Eh,74h,72h,6Fh,2Eh,65h,78h
	DB	65h,0
_dat_file_fonts	DB	66h,6Fh,6Eh,74h,73h,2Eh,63h,76h
	DB	0
_dat_exe_misc	DB	6Dh,69h,73h,63h,2Eh,65h,78h,65h
	DB	0
_dat_arg_slash_2	DB	2Fh,32h,0
_dat_ext_cv	DB	63h,76h,0
_dat_exe_mcv	DB	6Dh,63h,76h,2Eh,65h,78h,65h,0
_dat_module_spawn_arg	DB	0
dat_module_spawn_pad	DB	0
asm_block_117e_00d0	DB	0,0,0,0,0,0,3Fh,1
	DB	0C7h,0,0,0,0Fh,0,4,0
	DB	0,0
addr_page_rastport	DW	OFFSET DGROUP:asm_block_117e_00d0
_dat_MODULE_TABLE	DW	OFFSET DGROUP:dat_module_0
	DW	OFFSET DGROUP:dat_module_1
	DW	OFFSET DGROUP:dat_module_2
	DW	OFFSET DGROUP:dat_module_3
	DW	OFFSET DGROUP:dat_module_4
	DW	OFFSET DGROUP:dat_module_5
	DW	OFFSET DGROUP:dat_module_6
	DW	OFFSET DGROUP:dat_module_7
	DW	OFFSET DGROUP:dat_module_8
	DW	OFFSET DGROUP:dat_module_9
	DW	OFFSET DGROUP:dat_module_10
	DW	OFFSET DGROUP:dat_module_11
	DW	OFFSET DGROUP:dat_module_12
	DW	OFFSET DGROUP:dat_module_13
	DW	OFFSET DGROUP:dat_module_14
	DW	OFFSET DGROUP:dat_module_15
	DW	OFFSET DGROUP:dat_module_16
	DW	OFFSET DGROUP:dat_module_17
_dat_GRAPHIC_NAME	DB	3Fh,67h,72h,61h,70h,68h,69h,63h
	DB	2Eh,65h,78h,65h,0
dat_graphic_name_pad	DB	0
_dat_SOUND_NAME	DB	3Fh,73h,6Fh,75h,6Eh,64h,2Eh,63h
	DB	61h,0
_asm_DRIVER_HANDLE	DB	0,0
drv_DAT_117e_0122	DB	0
drv_DAT_117e_0123	DB	0
drv_DAT_117e_0124	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
dat_msg_allocated	DB	41h,6Ch,6Ch,6Fh,63h,61h,74h,65h
	DB	64h,20h,31h,4Dh,62h,20h,6Fh,66h
	DB	20h,73h,70h,61h,63h,65h,3Fh,3Fh
	DB	3Fh,3Fh,24h
dat_msg_dos_lied	DB	4Dh,53h,2Dh,44h,4Fh,53h,20h,6Ch
	DB	69h,65h,64h,20h,74h,6Fh,20h,75h
	DB	73h,20h,61h,62h,6Fh,75h,74h,20h
	DB	68h,6Fh,77h,20h,6Dh,75h,63h,68h
	DB	20h,6Dh,65h,6Dh,6Fh,72h,79h,20h
	DB	77h,61h,73h,20h,61h,76h,61h,69h
	DB	6Ch,61h,62h,6Ch,65h,24h
dat_msg_file_not_found	DB	46h,69h,6Ch,65h,6Eh,61h,6Dh,65h
	DB	20h,6Eh,6Fh,74h,20h,66h,6Fh,75h
	DB	6Eh,64h,24h
dat_msg_load_no_memory	DB	4Eh,6Fh,74h,20h,65h,6Eh,6Fh,75h
	DB	67h,68h,20h,6Dh,65h,6Dh,6Fh,72h
	DB	79h,20h,74h,6Fh,20h,6Ch,6Fh,61h
	DB	64h,20h,66h,69h,6Ch,65h,24h
dat_msg_load_failed	DB	4Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	6Ch,6Fh,61h,64h,20h,66h,61h,69h
	DB	6Ch,65h,64h,20h,66h,6Fh,72h,20h
	DB	73h,6Fh,6Dh,65h,20h,72h,65h,61h
	DB	73h,6Fh,6Eh,24h
dat_msg_overlay_overrun	DB	4Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	68h,61h,73h,20h,6Fh,76h,65h,72h
	DB	72h,75h,6Eh,20h,61h,6Ch,6Ch,6Fh
	DB	63h,61h,74h,65h,64h,20h,6Dh,65h
	DB	6Dh,6Fh,72h,79h,24h
dat_msg_shrink_failed	DB	55h,6Eh,61h,62h,6Ch,65h,20h,74h
	DB	6Fh,20h,73h,68h,72h,69h,6Eh,6Bh
	DB	20h,6Fh,76h,65h,72h,6Ch,61h,79h
	DB	20h,6Dh,65h,6Dh,6Fh,72h,79h,20h
	DB	61h,6Ch,6Ch,6Fh,63h,61h,74h,69h
	DB	6Fh,6Eh,24h
dat_msg_release_failed	DB	45h,72h,72h,6Fh,72h,20h,72h,65h
	DB	6Ch,65h,61h,73h,69h,6Eh,67h,20h
	DB	6Fh,76h,65h,72h,6Ch,61h,79h,20h
	DB	6Dh,65h,6Dh,6Fh,72h,79h,24h
asm_message_pool_pad	DB	0,0
drv_DAT_117e_024c	DB	0,0
drv_DAT_117e_024e	DB	0,0
drv_DAT_117e_0250	DB	0,0
drv_DAT_117e_0252	DB	0,0
drv_DAT_117e_0254	DB	0,0
drv_DAT_117e_0256	DB	0,0
drv_DAT_117e_0258	DB	0,0
drv_DAT_117e_025a	DB	0,0
drv_DAT_117e_025c	DB	0,0
drv_DAT_117e_025e	DB	0,0
drv_DAT_117e_0260	DB	0,0

_DATA	ENDS

;==============================================================================
c_common	SEGMENT	PARA PUBLIC 'BSS'
;==============================================================================
_asm_COMM_BLOCK	DB	2EE0h DUP(?)
_asm_regs	DB	0Eh DUP(?)
asm_bss_336e	DB	2 DUP(?)

c_common	ENDS

	END
