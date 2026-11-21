	PAGE	60,132
	TITLE	MISCOVR - Covert Action miscellaneous driver overlay
;
; MISC.ASM -- MISC.EXE (internal name MISCOVR.EXE, 02-20-89), the keyboard and
; joystick overlay.
;
; Loaded with INT 21h AX=4B03h and entered through the caller's patched
; far-jump table, so the MZ entry point is never used. The header at offset
; 28h is what the caller reads: the two segments, the data length, this
; driver's first global slot index, and from 32h the eight entry offsets.
;
; Two encodings are MASM's and have to stay: the indexed data references take
; a disp16, their label being a forward reference, and each forward JMP is a
; short jump padded with a NOP.
;

; Every segment declared once, empty, so LINK sees them in this order.
CODE	SEGMENT	PARA PUBLIC 'CODE'
CODE	ENDS
DATA	SEGMENT	PARA PUBLIC 'DATA'
DATA	ENDS
STACK	SEGMENT	PARA STACK 'STACK'
STACK	ENDS

DGROUP	GROUP	DATA

;==============================================================================
CODE	SEGMENT	PARA PUBLIC 'CODE'
;==============================================================================
	ASSUME	cs:CODE, ds:DGROUP, ss:DGROUP
asm_header_pad	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
dat_banner:
	DB	4Dh,49h,53h,43h,4Fh,56h,52h,2Eh
	DB	45h,58h,45h,20h,30h,32h,2Dh,32h
	DB	30h,2Dh,38h,39h
asm_banner_pad	DB	0,0,0,0
addr_overlay_code_segment	DW	CODE
addr_overlay_data_segment	DW	DGROUP
dat_overlay_data_size	DB	90h,0
dat_overlay_base_slot	DB	5Ah,0
dat_overlay_entry_count	DB	8,0
addr_overlay_entries	DW	OFFSET asm_keyboard_empty
	DW	OFFSET asm_read_key
	DW	OFFSET asm_dos_key
	DW	OFFSET asm_clear_shift
	DW	OFFSET asm_clear_shift
	DW	OFFSET asm_joy_button
	DW	OFFSET asm_joy_calibrate
	DW	OFFSET asm_joy_read

;------------------------------------------------------------------------------
; DOS keyboard input with echo.
;------------------------------------------------------------------------------
asm_dos_key	PROC	FAR
	mov	ah,1
	int	21h		; DOS AH=01h: read character from stdin, with echo
	retf
asm_dos_key	ENDP

;------------------------------------------------------------------------------
; BIOS blocking key read.
;------------------------------------------------------------------------------
asm_read_key	PROC	FAR
	sub	ah,ah
	int	16h		; BIOS keyboard AH=00h: read keystroke, blocking (AH = scan code, AL = ASCII)
	retf
asm_read_key	ENDP

;------------------------------------------------------------------------------
; Non-blocking keyboard poll: 0FFFFh when the keyboard is empty and 0 when a
; key waits, the opposite sense to kbhit().
;------------------------------------------------------------------------------
asm_keyboard_empty	PROC	FAR
	mov	ah,1
	int	16h		; BIOS keyboard AH=01h: check keystroke status, non-blocking (ZF set if none waiting)
	jz	L10055
	sub	ax,ax
	retf
L10055:
	sub	ax,ax
	not	ax
	retf
asm_keyboard_empty	ENDP

;------------------------------------------------------------------------------
; Clear the four modifier bits in the BIOS keyboard flag at 0040:0017, leaving
; the lock bits.
;------------------------------------------------------------------------------
asm_clear_shift	PROC	FAR
	push	es
	sub	ax,ax
	mov	es,ax
	; ES is zero: 0000:0417 is the BIOS shift-state byte.
	mov	al,es:[417h]
	and	al,0F0h
	mov	es:[417h],al
	pop	es
	retf
asm_clear_shift	ENDP
asm_shift_pad	DB	0

;------------------------------------------------------------------------------
; Read a joystick button, its index on the stack and read through DS.
;------------------------------------------------------------------------------
asm_joy_button	PROC	FAR
	mov	bx,sp
	mov	dx,201h
	in	al,dx
	not	al
	mov	cx,word ptr [bx+4]
	add	cx,4
	shr	al,cl
	and	ax,1
	retf
asm_joy_button	ENDP

;------------------------------------------------------------------------------
; Sample both axes and seed the running extremes from them.
;------------------------------------------------------------------------------
asm_joy_calibrate	PROC	FAR
	push	ds
	mov	ax,DGROUP
	mov	ds,ax
	call	asm_joy_sample
	mov	bx,0
	call	asm_seed_axis
	mov	bx,1
	call	asm_seed_axis
	pop	ds
	retf
asm_joy_calibrate	ENDP

asm_seed_axis	PROC	NEAR
	shl	bx,1
	mov	ax,word ptr [bx+asm_raw]
	mov	word ptr [bx+asm_centre],ax
	mov	word ptr [bx+asm_lo_bound],ax
	mov	word ptr [bx+asm_hi_bound],ax
	ret
asm_seed_axis	ENDP

;------------------------------------------------------------------------------
; Sample both axes and scale them into the two result bytes.
;------------------------------------------------------------------------------
asm_joy_read	PROC	FAR
	push	ds
	mov	ax,DGROUP
	mov	ds,ax
	call	asm_joy_sample
	mov	bx,0
	call	asm_scale_axis
	mov	bx,1
	call	asm_scale_axis
	mov	ax,ds:[asm_result]
	pop	ds
	retf
asm_joy_read	ENDP

;------------------------------------------------------------------------------
; Time both joystick axes by counting the one-shot decay on port 201h.
;------------------------------------------------------------------------------
asm_joy_sample	PROC	NEAR
	push	bp
	xor	bx,bx
	xor	bp,bp
	mov	cx,0FFFFh
	mov	dx,201h
	cli
	out	dx,al
	jmp	short L100d3
L100d3:
	jmp	short L100d5
L100d5:
	in	al,dx
	and	al,3
	jz	L100e6
	shr	al,1
	adc	bx,0
	shr	al,1
	adc	bp,0
	loop	L100d5
L100e6:
	sti
	mov	word ptr ds:[asm_raw],bx
	mov	word ptr ds:[asm_raw+2],bp
	pop	bp
	ret
asm_joy_sample	ENDP

;------------------------------------------------------------------------------
; Scale one axis against its recorded extremes into a signed byte.
;------------------------------------------------------------------------------
asm_scale_axis	PROC	NEAR
	shl	bx,1
	mov	ax,word ptr [bx+asm_raw]
	mov	dx,ax
	sub	dx,word ptr [bx+asm_centre]
	jc	L10106
	ja	L10128
	mov	ah,0
	jmp	L10143
L10106:
	neg	dx
	cmp	ax,word ptr [bx+asm_lo_bound]
	ja	L1011b
	mov	word ptr [bx+asm_lo_bound],ax
	mov	word ptr [bx+asm_lo_span],dx
	mov	ah,81h
	jmp	L10143
L1011b:
	xor	ax,ax
	div	word ptr [bx+asm_lo_span]
	shr	ax,1
	neg	ax
	jmp	L10143
L10128:
	cmp	ax,word ptr [bx+asm_hi_bound]
	jc	L1013b
	mov	word ptr [bx+asm_hi_bound],ax
	mov	word ptr [bx+asm_hi_span],dx
	mov	ah,7Fh
	jmp	L10143
L1013b:
	xor	ax,ax
	div	word ptr [bx+asm_hi_span]
	shr	ax,1
L10143:
	shr	bx,1
	mov	byte ptr [bx+asm_result],ah
	ret
asm_scale_axis	ENDP
asm_code_pad	DB	0,0,0,0,0,0

CODE	ENDS

;==============================================================================
DATA	SEGMENT	PARA PUBLIC 'DATA'
;==============================================================================
asm_data_head	DB	0,0,0,0,0,0,0,0
	DB	0,0,0,0,0,0,0,0
dat_copyright	DB	43h,6Fh,70h,79h,72h,69h,67h,68h
	DB	74h,20h,28h,43h,29h,20h,31h,39h
	DB	38h,39h,20h,62h,79h,20h,4Dh,69h
	DB	63h,72h,6Fh,50h,72h,6Fh,73h,65h
	DB	20h,53h,6Fh,66h,74h,77h,61h,72h
	DB	65h,2Ch,20h,41h,6Ch,6Ch,20h,52h
	DB	69h,67h,68h,74h,73h,20h,52h,65h
	DB	73h,65h,72h,76h,65h,64h,2Eh,0
asm_lo_span	DB	0,0,0,0,0,0,0,0
asm_hi_span	DB	0,0,0,0,0,0,0,0
asm_lo_bound	DB	0,0,0,0,0,0,0,0
asm_hi_bound	DB	0,0,0,0,0,0,0,0
asm_centre	DB	0,0,0,0,0,0,0,0
asm_raw	DB	0,0,0,0,0,0,0,0
asm_result	DB	0,0,0,0

DATA	ENDS

;==============================================================================
STACK	SEGMENT	PARA STACK 'STACK'
;==============================================================================
	DB	10h DUP(?)

STACK	ENDS

	END	dat_banner
