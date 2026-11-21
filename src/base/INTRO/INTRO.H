/* INTRO.H -- what the C side can reach on the assembly side. */
#ifndef INTRO_H
#define INTRO_H

/* The driver entries this module calls, declared once for every module. */
#include "DRIVERS.H"

/* The dispatch segment's own routines, declared once for every module. */
#include "DRVREAL.H"

/* The MSC 5.1 run-time this module calls, declared once for the tree. */
#include "RUNTIME.H"

/* A type this module reaches, declared once for the modules sharing it. */
#include "COMM.H"

/* The structures this module reaches, defined once for the whole tree. */
#include "STRUCTS.H"

/* routines in assembly, exported to C */
/* Append the string at the second argument to the one at the first. */
str_addr asm_strcat(str_addr dest, str_addr source);
/* Run one interrupt with AX, BX, CX and DX from the block at the second
 * argument, written back to the block at the third. Only 10h, 21h, 16h and 1ah
 * are dispatched; any other returns -1. */
INT asm_int86(INT number, union REGS *in, union REGS *out);
/* Format the first argument into the buffer at the second in base 10, 16 or 2,
 * the third, and return the buffer; any other base empties it. */
str_addr asm_itoa(INT value, str_addr text, INT radix);
/* Write a string at (row, col) through the BIOS in the attribute
 * dat_TEXT_ATTRIBUTE holds. A column of -1 leaves the cursor where it is; an
 * 0FFh makes the next byte the attribute. */
UNSIGNED_INT asm_write_at(INT row, INT col, str_addr text);
/* Print the $-terminated string at the argument through INT 21h AH=9. */
UNSIGNED_INT asm_dos_print(str_addr text);

/* data defined in assembly, exported to C */
#ifdef PORT_MODERN
/* The data group, datum by datum, which the portable build alone reads. */
#include "INTRO_PORT.H"
#else
extern unsigned char dat_exe_misc[9];
/* 0FFh, then 004fh -- 79, the width of the six lines that follow. */
extern unsigned char dat_title_head[3];
extern unsigned char dat_box_top[81];
extern unsigned char dat_title_version[81];
extern unsigned char dat_title_mpslabs[81];
extern unsigned char dat_title_copyright[81];
extern unsigned char dat_title_rights[81];
extern unsigned char dat_box_bottom[81];
extern unsigned char dat_title_tail[2];
extern unsigned char asm_prompt_pad_1[2];
extern unsigned char dat_menu_joystick[25];
extern unsigned char dat_menu_keyboard[17];
extern unsigned char asm_prompt_pad_2[3];
extern unsigned char dat_msg_one_moment[21];
/* The five graphics option texts, in menu order. */
extern unsigned char *dat_graphics_options[5];
/* The six sound option texts, in menu order. */
extern unsigned char *dat_sound_options[6];
/* NITARX: the letter each sound option is recorded as, in menu order. */
extern unsigned char dat_sound_letters[6];
/* EMETC: the letter each graphics option is recorded as, in menu order. The
first and third are both E, which is what makes the VGA option load EGRAPHIC. */
extern unsigned char dat_graphics_letters[5];
/* Offset of 79 spaces, CR, LF and the terminating $: one blank line through
asm_dos_print. */
extern unsigned char *dat_blank_line;
/* Offset of a blank row of the banner box -- spaces between two vertical rules. */
extern unsigned char *dat_banner_blank;
/* The register block asm_int86 reads and writes: AX, BX, CX and DX, from the
bottom up. */
extern union REGS asm_regs;
/* The letter each numbered line of the sound menu stands for, one byte per
 * line. */
extern unsigned char asm_sound_choices[6];
/* Six letters for sound options past the six built in. Unused. */
extern unsigned char asm_extra_sound_letters[6];
/* The letter each numbered line of the graphics menu stands for, one byte per
 * line. */
extern unsigned char asm_graphics_choices[5];
#endif

#endif /* INTRO_H */
