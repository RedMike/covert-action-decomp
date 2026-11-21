	PAGE	60,132
	TITLE	INTRO
;
; INTRO.ASM -- the assembly side of INTRO.EXE.
;
; A SPLIT marker stands where a routine is in C; the build cuts the
; assembly there.
;

	EXTRN	_c_main:PROC
	EXTRN	_c_cursor_at:PROC
	PUBLIC	_asm_strcat
	PUBLIC	_asm_int86
	PUBLIC	_asm_itoa
	PUBLIC	_asm_write_at
	PUBLIC	_asm_dos_print
	PUBLIC	_drv_jump_dos_key
	PUBLIC	_drv_real_load
	PUBLIC	_drv_real_link_slots
	PUBLIC	_dat_blank_line
	PUBLIC	_dat_banner_blank
	PUBLIC	_dat_graphics_options
	PUBLIC	_dat_sound_options
	PUBLIC	_dat_sound_letters
	PUBLIC	_dat_graphics_letters
	PUBLIC	_asm_sound_choices
	PUBLIC	_asm_extra_sound_letters
	PUBLIC	_asm_graphics_choices
	PUBLIC	_asm_regs
	PUBLIC	_dat_exe_misc
	PUBLIC	_dat_title_head
	PUBLIC	_dat_box_top
	PUBLIC	_dat_title_version
	PUBLIC	_dat_title_mpslabs
	PUBLIC	_dat_title_copyright
	PUBLIC	_dat_title_rights
	PUBLIC	_dat_box_bottom
	PUBLIC	_dat_title_tail
	PUBLIC	_asm_prompt_pad_1
	PUBLIC	_dat_menu_joystick
	PUBLIC	_dat_menu_keyboard
	PUBLIC	_asm_prompt_pad_2
	PUBLIC	_dat_msg_one_moment

; Every segment declared once, empty, so LINK sees them in this order.
_TEXT	SEGMENT	PARA PUBLIC 'CODE'
_TEXT	ENDS
CODE_1	SEGMENT	WORD PUBLIC 'CODE'
CODE_1	ENDS
_DATA	SEGMENT	WORD PUBLIC 'DATA'
_DATA	ENDS
_BSS	SEGMENT	BYTE PUBLIC 'BSS'
_BSS	ENDS
XOB	SEGMENT	WORD PUBLIC 'BSS'
XOB	ENDS
XO	SEGMENT	WORD PUBLIC 'BSS'
XO	ENDS
XOE	SEGMENT	WORD PUBLIC 'BSS'
XOE	ENDS
c_common	SEGMENT	PARA PUBLIC 'BSS'
c_common	ENDS

DGROUP	GROUP	_DATA,_BSS,c_common

;==============================================================================
_TEXT	SEGMENT	PARA PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:_TEXT, ds:DGROUP, ss:DGROUP

;;SPLIT main

;;SPLIT FUN_1000_044a

asm_FUN_1000_0474	PROC	NEAR
	push	bp
	mov	bp,sp
	mov	dx,word ptr [bp+4]
	sub	ax,ax
	mov	al,byte ptr [bp+6]
	out	dx,al
	pop	bp
	ret
asm_FUN_1000_0474	ENDP

asm_FUN_1000_0482	PROC	NEAR
	push	bp
	mov	bp,sp
	push	ds
	pop	es
	mov	si,word ptr [bp+4]
L1048a:
	cmp	byte ptr [si],0
	jz	L104a0
	mov	al,byte ptr [si]
	cmp	al,61h
	jl	L1049d
	cmp	al,7Ah
	jg	L1049d
	sub	al,20h
	mov	byte ptr [si],al
L1049d:
	inc	si
	jmp	L1048a
L104a0:
	pop	bp
	ret
asm_FUN_1000_0482	ENDP

asm_FUN_1000_04a2	PROC	NEAR
	push	bp
	mov	bp,sp
	push	ds
	pop	es
	mov	si,word ptr [bp+4]
	mov	di,word ptr [bp+6]
L104ad:
	cmp	byte ptr [si],0
	jnz	L104ba
	cmp	byte ptr [di],0
	jz	L104c7
	jmp	L104cd
L104ba:
	cmp	byte ptr [di],0
	jz	L104cd
	lodsb
	cmp	al,byte ptr [di]
	jnz	L104cd
	inc	di
	jmp	L104ad
L104c7:
	mov	ax,1
	jmp	L104d0
L104cd:
	mov	ax,0
L104d0:
	pop	bp
	ret
asm_FUN_1000_04a2	ENDP

asm_FUN_1000_04d2	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
L104d6:
	mov	bx,word ptr [bp+4]
	inc	word ptr [bp+4]
	mov	si,word ptr [bp+6]
	inc	word ptr [bp+6]
	mov	al,byte ptr [si]
	mov	byte ptr [bx],al
	or	al,al
	jnz	L104d6
	pop	si
	pop	bp
	ret
asm_FUN_1000_04d2	ENDP

asm_FUN_1000_04ed	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	push	es
	les	di,[bp+4]
	mov	si,word ptr [bp+8]
L104f9:
	lodsb
	stosb
	or	al,al
	jnz	L104f9
	pop	es
	pop	di
	pop	si
	pop	bp
	ret
asm_FUN_1000_04ed	ENDP

asm_FUN_1000_0504	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	push	es
	push	ds
	push	ds
	pop	es
	lds	si,[bp+6]
	mov	di,word ptr [bp+4]
L10513:
	lodsb
	stosb
	or	al,al
	jnz	L10513
	pop	ds
	pop	es
	pop	di
	pop	si
	pop	bp
	ret
asm_FUN_1000_0504	ENDP

asm_FUN_1000_051f	PROC	NEAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+4]
L10525:
	mov	bx,word ptr [bp+4]
	inc	word ptr [bp+4]
	cmp	byte ptr [bx],0
	jnz	L10525
	mov	bx,word ptr [bp+4]
	sub	ax,bx
	not	ax
	mov	sp,bp
	pop	bp
	ret
asm_FUN_1000_051f	ENDP

asm_FUN_1000_053b	PROC	NEAR
	push	bp
	mov	bp,sp
	push	ds
	lds	si,[bp+4]
	sub	bx,bx
L10544:
	lodsb
	cmp	al,0
	jz	L1054c
	inc	bx
	jmp	L10544
L1054c:
	mov	ax,bx
	pop	ds
	pop	bp
	ret
asm_FUN_1000_053b	ENDP

;------------------------------------------------------------------------------
; Append the string at the second argument to the one at the first.
;------------------------------------------------------------------------------
_asm_strcat	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
L10555:
	mov	bx,word ptr [bp+4]
	cmp	byte ptr [bx],0
	jz	L10568
	inc	word ptr [bp+4]
	jmp	L10555
L10562:
	inc	word ptr [bp+4]
	mov	bx,word ptr [bp+4]
L10568:
	mov	si,word ptr [bp+6]
	inc	word ptr [bp+6]
	mov	al,byte ptr [si]
	mov	byte ptr [bx],al
	or	al,al
	jnz	L10562
	pop	si
	pop	bp
	ret
_asm_strcat	ENDP

asm_FUN_1000_0579	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	mov	ax,word ptr [bp+6]
L10580:
	mov	bx,word ptr [bp+4]
	cmp	byte ptr [bx],0
	jz	L10591
	cmp	byte ptr [bx],al
	jz	L10597
	inc	word ptr [bp+4]
	jmp	L10580
L10591:
	mov	ax,0
	jmp	L10599
L10597:
	mov	ax,bx
L10599:
	pop	si
	pop	bp
	ret
asm_FUN_1000_0579	ENDP

asm_FUN_1000_059c	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	push	ds
	pop	es
	mov	al,byte ptr [bp+6]
	mov	di,word ptr [bp+4]
	mov	cx,word ptr [bp+8]
	rep stosb
	pop	si
	mov	sp,bp
	pop	bp
	ret
asm_FUN_1000_059c	ENDP

asm_FUN_1000_05b2	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	push	es
	mov	al,byte ptr [bp+8]
	les	di,[bp+4]
	mov	cx,word ptr [bp+0Ah]
	rep stosb
	pop	es
	pop	si
	mov	sp,bp
	pop	bp
	ret
asm_FUN_1000_05b2	ENDP

asm_FUN_1000_05c8	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	mov	cx,word ptr [bp+8]
L105cf:
	mov	si,word ptr [bp+4]
	inc	word ptr [bp+4]
	mov	bx,word ptr [bp+6]
	inc	word ptr [bp+6]
	mov	dl,byte ptr [bx]
	mov	byte ptr [si],dl
	loop	L105cf
	pop	si
	mov	sp,bp
	pop	bp
	ret
asm_FUN_1000_05c8	ENDP

asm_FUN_1000_05e6	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	push	es
	push	ds
	push	ds
	pop	es
	mov	cx,word ptr [bp+0Ah]
	mov	di,word ptr [bp+4]
	lds	si,[bp+6]
	rep movsb
	pop	ds
	pop	es
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret
asm_FUN_1000_05e6	ENDP

asm_FUN_1000_0602	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	mov	cx,word ptr [bp+8]
L10609:
	mov	si,word ptr [bp+4]
	inc	word ptr [bp+4]
	mov	ax,word ptr [si]
	mov	bx,word ptr [bp+6]
	inc	word ptr [bp+6]
	cmp	ax,word ptr [bx]
	loopz	L10609
	or	cx,cx
	jz	L10625
	mov	ax,0
	jmp	L10628
L10625:
	mov	ax,1
L10628:
	pop	si
	mov	sp,bp
	pop	bp
	ret
asm_FUN_1000_0602	ENDP

;------------------------------------------------------------------------------
; Run one interrupt with AX, BX, CX and DX from the block at the second
; argument, written back to the block at the third. Only 10h, 21h, 16h and 1ah
; are dispatched; any other returns -1.
;------------------------------------------------------------------------------
_asm_int86	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	push	di
	push	ax
	push	bx
	push	cx
	push	dx
	mov	di,word ptr [bp+6]
	mov	ax,word ptr [di]
	mov	bx,word ptr [di+2]
	mov	cx,word ptr [di+4]
	mov	dx,word ptr [di+6]
	cmp	word ptr [bp+4],10h
	jz	L1065f
	cmp	word ptr [bp+4],21h
	jz	L10664
	cmp	word ptr [bp+4],16h
	jz	L10669
	cmp	word ptr [bp+4],1Ah
	jz	L1066e
	jmp	L10673
L1065f:
	int	10h
	jmp	L1067a
L10664:
	int	21h
	jmp	L1067a
L10669:
	int	16h
	jmp	L1067a
L1066e:
	int	1Ah
	jmp	L1067a
L10673:
	sub	ax,ax
	not	ax
	jmp	L10688
L1067a:
	mov	di,word ptr [bp+8]
	mov	word ptr [di],ax
	mov	word ptr [di+2],bx
	mov	word ptr [di+4],cx
	mov	word ptr [di+6],dx
L10688:
	pop	dx
	pop	cx
	pop	bx
	pop	ax
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret
_asm_int86	ENDP

;------------------------------------------------------------------------------
; Format the first argument into the buffer at the second in base 10, 16 or 2,
; the third, and return the buffer; any other base empties it.
;------------------------------------------------------------------------------
_asm_itoa	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bp+8]
	cmp	ax,0Ah
	jz	L106ae
	cmp	ax,2
	jz	L106ba
	cmp	ax,10h
	jz	L106b4
	jmp	L106c0
L106ae:
	call	asm_FUN_1000_06d2
	jmp	L106ca
L106b4:
	call	asm_FUN_1000_06fd
	jmp	L106ca
L106ba:
	call	asm_FUN_1000_0745
	jmp	L106ca
L106c0:
	mov	bx,word ptr [bp+6]
	mov	word ptr [bx],0
	mov	ax,0
L106ca:
	mov	ax,word ptr [bp+6]
	pop	si
	mov	sp,bp
	pop	bp
	ret
_asm_itoa	ENDP

asm_FUN_1000_06d2	PROC	NEAR
	sub	cx,cx
	mov	ax,word ptr [bp+4]
	mov	si,0Ah
	or	ax,ax
	jns	L106e4
	mov	byte ptr [bx],2Dh
	inc	bx
	neg	ax
L106e4:
	sub	dx,dx
	div	si
	add	dx,30h
	push	dx
	inc	cx
	or	ax,ax
	jnz	L106e4
	mov	ax,cx
L106f3:
	pop	dx
	mov	byte ptr [bx],dl
	inc	bx
	loop	L106f3
	mov	byte ptr [bx],0
	ret
asm_FUN_1000_06d2	ENDP

asm_FUN_1000_06fd	PROC	NEAR
	mov	cx,4
	mov	ax,word ptr [bp+4]
	and	ah,0F0h
	mov	al,ah
	sub	ah,ah
	shr	ax,cl
	add	ax,30h
	mov	byte ptr [bx],al
	inc	bx
	mov	ax,word ptr [bp+4]
	and	ah,0Fh
	mov	al,ah
	sub	ah,ah
	add	ax,30h
	mov	byte ptr [bx],al
	inc	bx
	mov	ax,word ptr [bp+4]
	and	al,0F0h
	sub	ah,ah
	shr	ax,cl
	add	ax,30h
	mov	byte ptr [bx],al
	inc	bx
	mov	ax,word ptr [bp+4]
	and	al,0Fh
	sub	ah,ah
	add	ax,30h
	mov	byte ptr [bx],al
	inc	bx
	mov	byte ptr [bx],0
	mov	ax,4
	ret
asm_FUN_1000_06fd	ENDP

asm_FUN_1000_0745	PROC	NEAR
	mov	dx,word ptr [bp+4]
	sub	ax,ax
	mov	ah,80h
L1074c:
	test	dx,ax
	jnz	L10757
	mov	byte ptr [bx],30h
	inc	bx
	jmp	L1075b
L10757:
	mov	byte ptr [bx],31h
	inc	bx
L1075b:
	shr	ax,1
	jnc	L1074c
	mov	byte ptr [bx],0
	mov	ax,10h
	ret
asm_FUN_1000_0745	ENDP
dat_TEXT_ATTRIBUTE	DB	0Fh

;------------------------------------------------------------------------------
; Write a string at (row, col) through the BIOS in the attribute
; dat_TEXT_ATTRIBUTE holds. A column of -1 leaves the cursor where it is; an
; 0FFh makes the next byte the attribute.
;------------------------------------------------------------------------------
_asm_write_at	PROC	NEAR
	push	bp
	mov	bp,sp
	push	si
	mov	ah,2
	xor	bh,bh
	mov	dh,byte ptr [bp+4]
	mov	dl,byte ptr [bp+6]
	cmp	dx,-1
	jz	L1077c
	int	10h		; BIOS video AH=02h: set cursor position (BH = page, DH/DL = row/col)
L1077c:
	mov	bl,byte ptr cs:[dat_TEXT_ATTRIBUTE]
	xor	bh,bh
	mov	cx,1
	mov	si,word ptr [bp+8]
L10789:
	lodsb
	or	al,al
	jz	L107af
	cmp	al,0FFh
	jz	L107a2
	mov	dl,al
	mov	ah,9
	mov	al,20h
	int	10h		; BIOS video AH=09h: write character and attribute at cursor
	mov	ah,0Eh
	mov	al,dl
	int	10h		; BIOS video AH=0Eh: teletype output (AL = character)
	jmp	L10789
L107a2:
	lodsb
	or	al,al
	jz	L107af
	mov	cs:[dat_TEXT_ATTRIBUTE],al
	mov	bl,al
	jmp	L10789
L107af:
	pop	si
	pop	bp
	ret
_asm_write_at	ENDP

;------------------------------------------------------------------------------
; Print the $-terminated string at the argument through INT 21h AH=9.
;------------------------------------------------------------------------------
_asm_dos_print	PROC	NEAR
	push	bp
	mov	bp,sp
	mov	ah,9
	mov	dx,word ptr [bp+4]
	int	21h		; DOS AH=09h: write $-terminated string to stdout
	pop	bp
	ret
_asm_dos_print	ENDP

_TEXT	ENDS

;==============================================================================
CODE_1	SEGMENT	WORD PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:CODE_1, ds:DGROUP, ss:DGROUP

drv_real_dispatch	PROC	NEAR
	cmp	byte ptr ds:[asm_block_112c_050a+1],0
	jnz	L10ccd
	pop	word ptr cs:[L10cc8+3]
	jmp	short L10cc8
L10cc8:
	; The target is patched in by the POP above.
	jmp	dword ptr cs:[0]
L10ccd:
	mov	byte ptr ds:[asm_block_112c_050a],1
	pop	word ptr cs:[L10ce1+3]
	pop	word ptr ds:[asm_block_112c_050a+2]
	pop	word ptr ds:[asm_block_112c_050a+4]
	jmp	short L10ce1
L10ce1:
	; The target is patched in by the POP above.
	call	dword ptr cs:[0]
	dec	byte ptr ds:[asm_block_112c_050a]
	jz	L10cf6
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[asm_block_112c_050a],0
L10cf6:
	jmp	dword ptr ds:[asm_block_112c_050a+2]
drv_real_dispatch	ENDP
D10cfa	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0

drv_jump_gfx_sprite_put_clipped	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_sprite_put_clipped	ENDP
D10d32	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0

drv_jump_gfx_overlay_remove	PROC	NEAR
	call	drv_real_dispatch
L10d5f:
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_gfx_overlay_remove	ENDP
D10d6a	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0

drv_jump_FUN_10cb_00dd	PROC	NEAR
	call	drv_real_dispatch
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	add	byte ptr [bx+si],al
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
drv_jump_FUN_10cb_00dd	ENDP
D10d9b	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0

drv_jump_gfx_overlay_put	PROC	NEAR
	call	drv_real_dispatch
L10dc8:
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
D10de1	DB	0,0,0EAh,0,0,0,0,0
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
	DB	0,0,0,0,0EAh,0,0,0
	DB	0,0,0,0EAh,0,0,0,0
	DB	0,0,0EAh,0,0,0,0,0
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
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0

_drv_jump_dos_key	PROC	NEAR
	DB	0EAh,0,0,0,0		; JMPF 0:0, patched when a driver loads
_drv_jump_dos_key	ENDP
D10f85	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0EAh,0,0,0,0
	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0,0
	DB	0EAh,0,0,0,0,0,0,0EAh
	DB	0,0,0,0,0,0,0EAh,0
	DB	0,0,0,0,0,0EAh,0,0
	DB	0,0,0,0,0EAh,0,0,0
	DB	0,0,0,0EAh,0,0,0,0
	DB	0,0,0EAh,0,0,0,0,0
	DB	0,0EAh,0,0,0,0,0

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
	mov	word ptr ds:[drv_DAT_112c_0510],dx
	mov	word ptr ds:[drv_DAT_112c_0512],bx
	mov	ah,48h
	mov	bx,0FFFFh
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jc	L11027
	mov	dx,OFFSET DGROUP:dat_msg_allocated
	jmp	drv_real_FUN_10cb_0410
L11027:
	mov	ah,48h
	sub	bx,100h
	mov	word ptr ds:[drv_DAT_112c_0516],bx
	int	21h		; DOS AH=48h: allocate memory (BX = paragraphs)
	jnc	L1103b
	mov	dx,OFFSET DGROUP:dat_msg_memory_available
	jmp	drv_real_FUN_10cb_0410
L1103b:
	mov	bx,OFFSET DGROUP:drv_DAT_112c_0518
	mov	word ptr [bx],ax
	mov	word ptr [bx+2],ax
	mov	ax,4B03h
	mov	dx,word ptr ds:[drv_DAT_112c_0510]
	push	ds
	pop	es
	mov	word ptr ds:[drv_DAT_112c_0514],sp
	int	21h		; DOS AH=4Bh AL=03h: load overlay
	mov	dx,DGROUP
	mov	ds,dx
	mov	es,dx
	mov	ss,dx
	mov	sp,word ptr ds:[drv_DAT_112c_0514]
	jnc	L1107d
	cmp	ax,2
	jnz	L1106c
	mov	dx,OFFSET DGROUP:dat_msg_file_not_found
	jmp	drv_real_FUN_10cb_0410
L1106c:
	cmp	ax,8
	jnz	L11077
	mov	dx,OFFSET DGROUP:dat_msg_load_no_memory
	jmp	drv_real_FUN_10cb_0410
L11077:
	mov	dx,OFFSET DGROUP:dat_msg_load_failed
	jmp	drv_real_FUN_10cb_0410
L1107d:
	mov	es,word ptr ds:[drv_DAT_112c_0518]
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
	cmp	bx,word ptr ds:[drv_DAT_112c_0516]
	jbe	L110ad
	mov	dx,OFFSET DGROUP:dat_msg_overlay_overrun
	jmp	drv_real_FUN_10cb_0410
L110ad:
	mov	ah,4Ah
	int	21h		; DOS AH=4Ah: resize memory block (ES = segment, BX = paragraphs)
	jnc	L110b9
	mov	dx,OFFSET DGROUP:dat_msg_shrink_failed
	jmp	drv_real_FUN_10cb_0410
L110b9:
	mov	ax,es
	pop	es
	pop	ds
	pop	di
	pop	si
	retf
_drv_real_load	ENDP

drv_real_FUN_10cb_0410	PROC	NEAR
	mov	ah,9
	int	21h		; DOS AH=09h: write $-terminated string to stdout
	mov	ax,4C00h
	int	21h		; DOS AH=4Ch: terminate (AL = code)
drv_real_FUN_10cb_0410	ENDP

;------------------------------------------------------------------------------
; Read the data file a driver load names into memory after the driver, in 32K
; goes, and return the segment past it.
;------------------------------------------------------------------------------
drv_real_load_data	PROC	NEAR
	push	ds
	mov	dx,word ptr ds:[drv_DAT_112c_0512]
	or	dx,dx
	jz	L1111b
	mov	ax,3D00h
	int	21h		; DOS AH=3Dh: open existing file (AL = access mode)
	jnc	L110de
	mov	dx,OFFSET DGROUP:dat_msg_file_not_found
	jmp	drv_real_FUN_10cb_0410
L110de:
	mov	ds,bx
	mov	bx,ax
	mov	ax,3F00h
	mov	cx,8000h
	xor	dx,dx
	int	21h		; DOS AH=3Fh: read from file or device (BX = handle, CX = count)
	jnc	L110f3
	mov	dx,OFFSET DGROUP:dat_msg_file_not_found
	jmp	drv_real_FUN_10cb_0410
L110f3:
	cmp	ax,cx
	jc	L110fe
	mov	ax,ds
	add	ax,800h
	mov	ds,ax
L110fe:
	add	ax,0Fh
	shr	ax,1
	shr	ax,1
	shr	ax,1
	shr	ax,1
	mov	dx,ds
	add	dx,ax
	mov	ax,3E00h
	int	21h		; DOS AH=3Eh: close file (BX = handle)
	jnc	L11119
	mov	dx,OFFSET DGROUP:dat_msg_file_not_found
	jmp	drv_real_FUN_10cb_0410
L11119:
	mov	bx,dx
L1111b:
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
	lea	di,[D10cfa]
	add	di,ax
	mov	ax,CODE_1
	mov	es,ax
	mov	cx,word ptr ds:[30h]
	mov	ax,ds:[28h]
L11144:
	add	di,3
	movsw
	stosw
	loop	L11144
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
	jnc	L11164
	mov	dx,OFFSET DGROUP:dat_msg_release_failed
	jmp	drv_real_FUN_10cb_0410
L11164:
	pop	es
	retf
drv_real_free	ENDP

drv_real_mouse_open	PROC	FAR
	xor	ax,ax
	mov	es,ax
	mov	bx,0CCh
	mov	ax,word ptr es:[bx]
	or	ax,word ptr es:[bx+2]
	jz	L111b4
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
	or	ax,ax
	jz	L111b4
	mov	ax,0Ch
	mov	cx,1Fh
	mov	dx,cs
	mov	es,dx
	lea	dx,[drv_real_mouse_event]
	int	33h		; mouse AX=000Ch: set user-defined event handler
	mov	ax,3
	int	33h		; mouse AX=0003h: get position and button status
	mov	word ptr ds:[run_crt0dat_0634+12],0
	cmp	cx,0C8h
	jc	L111a8
	shr	cx,1
	mov	word ptr ds:[run_crt0dat_0634+12],1
L111a8:
	mov	word ptr ds:[run_crt0dat_0634+2],bx
	mov	word ptr ds:[asm_message_pool_pad],cx
	mov	word ptr ds:[run_crt0dat_0634],dx
L111b4:
	retf
drv_real_mouse_open	ENDP

drv_real_mouse_close	PROC	FAR
	xor	ax,ax
	mov	es,ax
	mov	bx,0CCh
	mov	ax,word ptr es:[bx]
	or	ax,word ptr es:[bx+2]
	jz	L111cf
	call	far ptr drv_real_FUN_10cb_053e
	mov	ax,0
	int	33h		; mouse AX=0000h: reset driver and read status
L111cf:
	retf
drv_real_mouse_close	ENDP

drv_real_FUN_10cb_0520	PROC	FAR
	xor	ax,ax
	xchg	word ptr ds:[run_crt0dat_0634+4],ax
	retf
drv_real_FUN_10cb_0520	ENDP

drv_real_mouse_set_cursor	PROC	FAR
	push	bp
	mov	bp,sp
	mov	ax,word ptr [bp+6]
	mov	ds:[run_crt0dat_0634+8],ax
	mov	ax,word ptr [bp+8]
	mov	ds:[run_crt0dat_0634+10],ax
	mov	ax,word ptr [bp+0Ah]
	mov	ds:[run_crt0dat_0634+6],ax
	pop	bp
	retf
drv_real_mouse_set_cursor	ENDP

drv_real_FUN_10cb_053e	PROC	FAR
	mov	byte ptr ds:[asm_block_112c_050a+1],0
	call	far ptr drv_jump_gfx_overlay_remove
	retf
drv_real_FUN_10cb_053e	ENDP

drv_real_cursor_show	PROC	FAR
	push	word ptr ds:[run_crt0dat_0634+6]
	mov	ax,ds:[run_crt0dat_0634]
	sub	ax,word ptr ds:[run_crt0dat_0634+10]
	push	ax
	mov	ax,ds:[asm_message_pool_pad]
	sub	ax,word ptr ds:[run_crt0dat_0634+8]
	push	ax
	call	far ptr drv_jump_gfx_overlay_put
	add	sp,6
	mov	byte ptr ds:[asm_block_112c_050a+1],1
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
	mov	ds:[run_crt0dat_0634+14],ax
	mov	word ptr ds:[run_crt0dat_0634+16],bx
	mov	word ptr ds:[run_crt0dat_0634+18],cx
	mov	word ptr ds:[run_crt0dat_0634+20],dx
	lea	ax,[run_crt0dat_0634+14]
	pop	bp
	retf
drv_real_mouse_int	ENDP

drv_real_cursor_redraw	PROC	FAR
	push	ax
	push	dx
	push	es
	mov	ax,CODE_1
	mov	es,ax
	call	dword ptr es:[L10d5f]
	push	word ptr ds:[run_crt0dat_0634+6]
	mov	ax,ds:[run_crt0dat_0634]
	sub	ax,word ptr ds:[run_crt0dat_0634+10]
	push	ax
	mov	ax,ds:[asm_message_pool_pad]
	sub	ax,word ptr ds:[run_crt0dat_0634+8]
	push	ax
	mov	ax,CODE_1
	mov	es,ax
	call	dword ptr es:[L10dc8]
	add	sp,6
	pop	es
	pop	dx
	pop	ax
	retf
drv_real_cursor_redraw	ENDP

drv_real_mouse_event	PROC	FAR
	mov	di,DGROUP
	mov	ds,di
	cmp	word ptr ds:[run_crt0dat_0634+12],0
	jz	L11281
	shr	cx,1
L11281:
	or	word ptr ds:[run_crt0dat_0634+4],bx
	mov	word ptr ds:[run_crt0dat_0634+2],bx
	mov	word ptr ds:[asm_message_pool_pad],cx
	mov	word ptr ds:[run_crt0dat_0634],dx
	test	ax,1
	jz	L112b1
	cmp	byte ptr ds:[asm_block_112c_050a+1],0
	jz	L112b1
	mov	al,2
	xchg	byte ptr ds:[asm_block_112c_050a],al
	or	al,al
	jnz	L112b1
	call	far ptr drv_real_cursor_redraw
	mov	byte ptr ds:[asm_block_112c_050a],0
L112b1:
	retf
drv_real_mouse_event	ENDP
D112b2	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0

CODE_1	ENDS

;==============================================================================
_DATA	SEGMENT	WORD PUBLIC 'DATA'
;==============================================================================
dat_mode_vga	DB	29h,20h,56h,47h,41h,20h,28h,32h
	DB	35h,36h,20h,63h,6Fh,6Ch,6Fh,72h
	DB	29h,0
dat_mode_mcga	DB	29h,20h,4Dh,43h,47h,41h,20h,28h
	DB	32h,35h,36h,20h,63h,6Fh,6Ch,6Fh
	DB	72h,29h,0
dat_mode_ega	DB	29h,20h,45h,47h,41h,20h,28h,31h
	DB	36h,20h,63h,6Fh,6Ch,6Fh,72h,29h
	DB	0
dat_mode_tandy	DB	29h,20h,54h,61h,6Eh,64h,79h,20h
	DB	31h,30h,30h,30h,20h,28h,31h,36h
	DB	20h,63h,6Fh,6Ch,6Fh,72h,29h,0
dat_mode_cga	DB	29h,20h,43h,47h,41h,20h,28h,34h
	DB	20h,63h,6Fh,6Ch,6Fh,72h,29h,0
dat_mode_no_sound	DB	29h,20h,53h,68h,68h,68h,21h,20h
	DB	4Eh,6Fh,20h,73h,6Fh,75h,6Eh,64h
	DB	73h,20h,70h,6Ch,65h,61h,73h,65h
	DB	0
dat_mode_ibm_sound	DB	29h,20h,49h,42h,4Dh,20h,73h,6Fh
	DB	75h,6Eh,64h,73h,0
dat_mode_tandy_sound	DB	29h,20h,54h,61h,6Eh,64h,79h,20h
	DB	73h,6Fh,75h,6Eh,64h,73h,0
dat_mode_adlib	DB	29h,20h,41h,64h,4Ch,69h,62h,20h
	DB	73h,6Fh,75h,6Eh,64h,20h,62h,6Fh
	DB	61h,72h,64h,0
dat_mode_roland	DB	29h,20h,52h,6Fh,6Ch,61h,6Eh,64h
	DB	20h,4Dh,54h,2Dh,33h,32h,20h,4Dh
	DB	49h,44h,49h,20h,62h,6Fh,61h,72h
	DB	64h,0
dat_mode_custom_sound	DB	29h,20h,43h,75h,73h,74h,6Fh,6Dh
	DB	20h,73h,6Fh,75h,6Eh,64h,20h,64h
	DB	72h,69h,76h,65h,72h,0
dat_drv_egraphic_1	DB	45h,67h,72h,61h,70h,68h,69h,63h
	DB	2Eh,65h,78h,65h,0
dat_drv_mgraphic	DB	4Dh,67h,72h,61h,70h,68h,69h,63h
	DB	2Eh,65h,78h,65h,0
dat_drv_egraphic_2	DB	45h,67h,72h,61h,70h,68h,69h,63h
	DB	2Eh,65h,78h,65h,0
dat_drv_tgraphic	DB	54h,67h,72h,61h,70h,68h,69h,63h
	DB	2Eh,65h,78h,65h,0
dat_drv_cgraphic	DB	43h,67h,72h,61h,70h,68h,69h,63h
	DB	2Eh,65h,78h,65h,0
dat_blank_line_text	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,0Dh
	DB	0Ah,24h,0
dat_banner_blank_text	DB	20h,0BAh,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,0BAh,20h
	DB	0
_dat_exe_misc	DB	6Dh,69h,73h,63h,2Eh,65h,78h,65h
	DB	0
_dat_title_head	DB	0FFh,4Fh,0
_dat_box_top	DB	20h,0C9h,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0BBh,20h
	DB	0
_dat_title_version	DB	20h,0BAh,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,43h,6Fh
	DB	76h,65h,72h,74h,20h,41h,63h,74h
	DB	69h,6Fh,6Eh,20h,28h,54h,4Dh,29h
	DB	20h,2Dh,20h,56h,65h,72h,73h,69h
	DB	6Fh,6Eh,20h,34h,34h,37h,2Eh,30h
	DB	31h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,0BAh,20h
	DB	0
_dat_title_mpslabs	DB	20h,0BAh,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,46h,72h
	DB	6Fh,6Dh,20h,74h,68h,6Fh,73h,65h
	DB	20h,73h,6Eh,65h,61h,6Bh,79h,20h
	DB	67h,75h,79h,73h,20h,61h,74h,20h
	DB	4Dh,50h,53h,20h,4Ch,61h,62h,73h
	DB	2Eh,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,0BAh,20h
	DB	0
_dat_title_copyright	DB	20h,0BAh,20h,20h,20h,20h,50h,72h
	DB	6Fh,67h,72h,61h,6Dh,20h,26h,20h
	DB	41h,75h,64h,69h,6Fh,2Dh,76h,69h
	DB	73h,75h,61h,6Ch,20h,43h,6Fh,70h
	DB	79h,72h,69h,67h,68h,74h,20h,28h
	DB	43h,29h,20h,31h,39h,39h,30h,20h
	DB	62h,79h,20h,4Dh,69h,63h,72h,6Fh
	DB	50h,72h,6Fh,73h,65h,20h,53h,6Fh
	DB	66h,74h,77h,61h,72h,65h,2Ch,49h
	DB	6Eh,63h,2Eh,2Ch,20h,20h,0BAh,20h
	DB	0
_dat_title_rights	DB	20h,0BAh,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,41h,6Ch
	DB	6Ch,20h,52h,69h,67h,68h,74h,73h
	DB	20h,52h,65h,73h,65h,72h,76h,65h
	DB	64h,2Eh,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,0BAh,20h
	DB	0
_dat_box_bottom	DB	20h,0C8h,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0CDh
	DB	0CDh,0CDh,0CDh,0CDh,0CDh,0CDh,0BCh,20h
	DB	0
_dat_title_tail	DB	0FFh,0Eh
dat_prompt_graphics	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,53h,65h,6Ch,65h,63h
	DB	74h,20h,67h,72h,61h,70h,68h,69h
	DB	63h,73h,20h,6Dh,6Fh,64h,65h,3Ah
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,0
_asm_prompt_pad_1	DB	0FFh,0Eh
dat_prompt_sound	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,53h,65h
	DB	6Ch,65h,63h,74h,20h,73h,6Fh,75h
	DB	6Eh,64h,20h,6Dh,6Fh,64h,65h,3Ah
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,20h,20h
	DB	20h,20h,20h,20h,20h,20h,0
_dat_menu_joystick	DB	31h,2Eh,20h,4Ah,6Fh,79h,73h,74h
	DB	69h,63h,6Bh,20h,61h,6Eh,64h,20h
	DB	4Bh,65h,79h,62h,6Fh,61h,72h,64h
	DB	0
_dat_menu_keyboard	DB	32h,2Eh,20h,4Bh,65h,79h,62h,6Fh
	DB	61h,72h,64h,20h,6Fh,6Eh,6Ch,79h
	DB	0
_asm_prompt_pad_2	DB	0FFh,0Eh,0
_dat_msg_one_moment	DB	4Fh,6Eh,65h,20h,4Dh,6Fh,6Dh,65h
	DB	6Eh,74h,20h,50h,6Ch,65h,61h,73h
	DB	65h,2Eh,2Eh,2Eh,0
_dat_graphics_options	DW	OFFSET DGROUP:dat_mode_vga
	DW	OFFSET DGROUP:dat_mode_mcga
	DW	OFFSET DGROUP:dat_mode_ega
	DW	OFFSET DGROUP:dat_mode_tandy
	DW	OFFSET DGROUP:dat_mode_cga
_dat_sound_options	DW	OFFSET DGROUP:dat_mode_no_sound
	DW	OFFSET DGROUP:dat_mode_ibm_sound
	DW	OFFSET DGROUP:dat_mode_tandy_sound
	DW	OFFSET DGROUP:dat_mode_adlib
	DW	OFFSET DGROUP:dat_mode_roland
	DW	OFFSET DGROUP:dat_mode_custom_sound
_dat_sound_letters	DB	4Eh,49h,54h,41h,52h,58h
asm_sound_letter_pad	DB	0,0,0,0,0,0
_dat_graphics_letters	DB	45h,4Dh,45h,54h,43h
asm_graphic_letter_tail	DB	0
dat_driver_names	DW	OFFSET DGROUP:dat_drv_egraphic_1
	DW	OFFSET DGROUP:dat_drv_mgraphic
	DW	OFFSET DGROUP:dat_drv_egraphic_2
	DW	OFFSET DGROUP:dat_drv_tgraphic
	DW	OFFSET DGROUP:dat_drv_cgraphic
_dat_blank_line	DW	OFFSET DGROUP:dat_blank_line_text
_dat_banner_blank	DW	OFFSET DGROUP:dat_banner_blank_text
asm_block_112c_050a	DB	0,0,0,0,0,0
drv_DAT_112c_0510	DB	0,0
drv_DAT_112c_0512	DB	0,0
drv_DAT_112c_0514	DB	0,0
drv_DAT_112c_0516	DB	0,0
drv_DAT_112c_0518	DB	0,0
drv_DAT_112c_051a	DB	0,0
dat_msg_allocated	DB	41h,6Ch,6Ch,6Fh,63h,61h,74h,65h
	DB	64h,20h,31h,4Dh,62h,20h,6Fh,66h
	DB	20h,73h,70h,61h,63h,65h,3Fh,3Fh
	DB	3Fh,3Fh,24h
dat_msg_memory_available	DB	4Dh,53h,2Dh,44h,4Fh,53h,20h,6Ch
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
run_crt0dat_0634	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0

_DATA	ENDS

;==============================================================================
_BSS	SEGMENT	BYTE PUBLIC 'BSS'
;==============================================================================
_asm_regs	DB	0Eh DUP(?)
asm_bss_07ec	DB	0Bh DUP(?)
_asm_sound_choices	DB	6 DUP(?)
asm_bss_07fd	DB	1Eh DUP(?)
_asm_extra_sound_letters	DB	6 DUP(?)
asm_bss_0821	DB	4 DUP(?)
_asm_graphics_choices	DB	5 DUP(?)
asm_bss_082a	DB	2 DUP(?)

_BSS	ENDS

c_common	SEGMENT	PARA PUBLIC 'BSS'
	DB	10h DUP(?)

c_common	ENDS

	END
