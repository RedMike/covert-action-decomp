/* INTRO_PORT.H -- the data group, as the portable build reads it.
 *
 * INTRO.H includes it under PORT_MODERN; the DOS build never stages it.
 */
#ifndef INTRO_PORT_H
#define INTRO_PORT_H

#include "PORTING.H"
#include "COMM.H"
#include "STRUCTS.H"

#ifndef PORT_MODERN
extern unsigned char run_banner_pad[8];
/* LINK's own 64 bytes, whose year dates the compiler: MSC 5.1 writes 1988,
5.0 writes 1987. */
extern unsigned char run_banner[56];
extern unsigned char run_banner_tail[2];
#endif
extern unsigned char dat_mode_vga[18];
extern unsigned char dat_mode_mcga[19];
extern unsigned char dat_mode_ega[17];
extern unsigned char dat_mode_tandy[24];
extern unsigned char dat_mode_cga[16];
extern unsigned char dat_mode_no_sound[25];
extern unsigned char dat_mode_ibm_sound[13];
extern unsigned char dat_mode_tandy_sound[15];
extern unsigned char dat_mode_adlib[20];
extern unsigned char dat_mode_roland[26];
extern unsigned char dat_mode_custom_sound[22];
#ifndef PORT_MODERN
extern unsigned char dat_drv_egraphic_1[13];
extern unsigned char dat_drv_mgraphic[13];
extern unsigned char dat_drv_egraphic_2[13];
extern unsigned char dat_drv_tgraphic[13];
extern unsigned char dat_drv_cgraphic[13];
#endif
extern unsigned char dat_blank_line_text[83];
extern unsigned char dat_banner_blank_text[81];
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
#ifndef PORT_MODERN
extern unsigned char dat_prompt_graphics[79];
#endif
extern unsigned char asm_prompt_pad_1[2];
#ifndef PORT_MODERN
extern unsigned char dat_prompt_sound[79];
#endif
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
#ifndef PORT_MODERN
extern unsigned char asm_sound_letter_pad[6];
#endif
/* EMETC: the letter each graphics option is recorded as, in menu order. The
first and third are both E, which is what makes the VGA option load EGRAPHIC. */
extern unsigned char dat_graphics_letters[5];
#ifndef PORT_MODERN
extern unsigned char asm_graphic_letter_tail;
extern unsigned char *dat_driver_names[5];
#endif
/* Offset of 79 spaces, CR, LF and the terminating $: one blank line through
asm_dos_print. */
extern unsigned char *dat_blank_line;
/* Offset of a blank row of the banner box -- spaces between two vertical rules. */
extern unsigned char *dat_banner_blank;
#ifndef PORT_MODERN
/* The dispatch segment's cursor state: a byte set while a slot call runs, a
byte set while the cursor shows, and the caller's far return address. */
extern unsigned char asm_block_112c_050a[6];
extern UNSIGNED_INT drv_DAT_112c_0510;
extern UNSIGNED_INT drv_DAT_112c_0512;
extern UNSIGNED_INT drv_DAT_112c_0514;
extern UNSIGNED_INT drv_DAT_112c_0516;
extern UNSIGNED_INT drv_DAT_112c_0518;
extern UNSIGNED_INT drv_DAT_112c_051a;
extern unsigned char dat_msg_allocated[27];
extern unsigned char dat_msg_memory_available[54];
extern unsigned char dat_msg_file_not_found[19];
extern unsigned char dat_msg_load_no_memory[31];
extern unsigned char dat_msg_load_failed[36];
extern unsigned char dat_msg_overlay_overrun[37];
extern unsigned char dat_msg_shrink_failed[43];
extern unsigned char dat_msg_release_failed[31];
extern unsigned char asm_message_pool_pad[2];
extern unsigned char run_crt0dat_0634[22];
extern unsigned char run_abrktb_tail[80];
extern unsigned char run_crt0dat_06b0;
extern UNSIGNED_INT run_crt0dat_06b1;
extern unsigned char run_crt0dat_06b3[14];
extern unsigned char run_crt0dat_06c5[5];
extern unsigned char run_crt0dat_06cb;
extern unsigned char run_crt0dat_06cc;
extern unsigned char run_crt0dat_06cd;
extern unsigned char run_crt0dat_06ce;
extern unsigned char run_crt0dat_06cf;
extern unsigned char run_crt0dat_06d0;
extern unsigned char run_crt0dat_06d1[13];
extern unsigned char run_crt0dat_06e8;
extern unsigned char run_crt0dat_06e9;
extern unsigned char run_crt0dat_06ea[8];
extern UNSIGNED_INT run_stdargv_06f4;
extern unsigned char run_stdargv_06f6[2];
extern UNSIGNED_INT run_crt0dat_06fa;
extern UNSIGNED_LONG run_crt0dat_06fc;
extern UNSIGNED_LONG run_crt0dat_0700;
extern unsigned char run_nmsg_marker[8];
extern UNSIGNED_INT run_crt0msg_070c;
extern unsigned char run_msg_r6000[26];
extern unsigned char run_crt0msg_0728[2];
extern unsigned char run_msg_r6003[31];
extern unsigned char run_crt0msg_0749[2];
extern unsigned char run_msg_r6009[44];
extern unsigned char run_crt0msg_0777[7];
extern unsigned char run_msg_runtime_error[16];
extern unsigned char run_crt0msg_078e[2];
extern unsigned char run_msg_r6002[37];
extern unsigned char run_crt0msg_07b5[2];
extern unsigned char run_msg_r6001[35];
extern unsigned char run_crt0msg_07da[2];
extern unsigned char run_crt0msg_07dc;
extern unsigned char asm_bss_07dd;
#endif
/* The register block asm_int86 reads and writes: AX, BX, CX and DX, from the
bottom up. */
extern union REGS asm_regs;
#ifndef PORT_MODERN
extern unsigned char asm_bss_07ec[11];
#endif
/* The letter each numbered line of the sound menu stands for, one byte per
 * line. */
extern unsigned char asm_sound_choices[6];
#ifndef PORT_MODERN
extern unsigned char asm_bss_07fd[30];
#endif
/* Six letters for sound options past the six built in. Unused. */
extern unsigned char asm_extra_sound_letters[6];
#ifndef PORT_MODERN
extern unsigned char asm_bss_0821[4];
#endif
/* The letter each numbered line of the graphics menu stands for, one byte per
 * line. */
extern unsigned char asm_graphics_choices[5];
#ifndef PORT_MODERN
extern unsigned char asm_bss_082a[2083];
#endif

#endif /* INTRO_PORT_H */
