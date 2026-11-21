/* CODE_PORT.H -- the data group, as the portable build reads it.
 *
 * CODE.H includes it under PORT_MODERN; the DOS build never stages it.
 */
#ifndef CODE_PORT_H
#define CODE_PORT_H

#include "PORTING.H"
#include "COMM.H"
#include "STRUCTS.H"

#ifndef PORT_MODERN
extern unsigned char run_banner_pad[8];
extern unsigned char run_banner[58];
extern UNSIGNED_INT drv_DAT_136d_0042;
extern UNSIGNED_INT drv_DAT_136d_0044;
extern unsigned char asm_block_0046[38];
extern unsigned char dat_note_01[88];
extern unsigned char dat_note_02[75];
extern unsigned char dat_note_03[92];
extern unsigned char dat_note_04[126];
extern unsigned char dat_note_05[72];
extern unsigned char dat_note_06[69];
extern unsigned char dat_note_07[79];
extern unsigned char dat_note_08[54];
extern unsigned char dat_note_09[79];
extern unsigned char dat_note_10[74];
extern unsigned char dat_note_11[58];
extern unsigned char dat_note_12[40];
extern unsigned char dat_note_13[56];
extern unsigned char dat_note_14[125];
extern unsigned char dat_note_15[53];
extern unsigned char dat_note_16[34];
extern unsigned char dat_note_17[79];
extern unsigned char dat_note_18[79];
extern unsigned char dat_note_19[55];
extern unsigned char dat_note_20[59];
extern unsigned char dat_note_21[61];
extern unsigned char dat_note_22[63];
extern unsigned char dat_note_23[52];
extern unsigned char dat_note_24[57];
extern unsigned char dat_note_25[47];
extern unsigned char dat_note_26[81];
extern unsigned char dat_note_27[47];
extern unsigned char dat_note_28[92];
extern unsigned char dat_note_29[68];
extern unsigned char dat_note_30[47];
extern unsigned char dat_note_31[61];
extern unsigned char dat_note_32[49];
extern unsigned char dat_note_33[42];
extern unsigned char dat_note_34[69];
extern unsigned char dat_note_35[60];
extern unsigned char dat_note_36[91];
extern unsigned char dat_note_37[69];
extern unsigned char dat_note_38[68];
extern unsigned char dat_note_39[35];
extern unsigned char dat_note_40[50];
extern unsigned char dat_note_41[51];
extern unsigned char dat_note_42[96];
extern unsigned char dat_note_43[85];
extern unsigned char dat_note_44[53];
extern unsigned char dat_note_45[74];
extern unsigned char dat_note_46[76];
extern unsigned char dat_note_47[57];
extern unsigned char dat_note_48[63];
extern unsigned char dat_note_49[33];
extern unsigned char dat_note_50[40];
extern unsigned char dat_note_51[84];
extern unsigned char dat_note_52[48];
extern unsigned char dat_note_53[97];
extern unsigned char dat_note_54[62];
extern unsigned char dat_note_55[61];
extern unsigned char dat_note_56[85];
extern unsigned char asm_block_0ef4[30];
#endif
extern struct COLOUR_MAP shd_colours_screen;
extern struct COLOUR_MAP shd_colours_screen_2;
extern struct COLOUR_MAP shd_colours_paper;
#ifndef PORT_MODERN
/* The 56 note-text pointers, dat_note_01 to dat_note_56 in order, up to the
off-screen page's RASTPORT; the four 16-byte blocks in front of it have the
shape of colour maps. */
extern unsigned char *addr_note_table[56];
#endif
/* The disk the menu's animation is on, asked for when it is not in
the drive rather than refused. */
extern UNSIGNED_INT shd_pan_disk;
extern struct RASTPORT dat_map_page_port;
/* The off-screen page descriptor: what the screen is copied to before a menu
or a pop-up covers it, and copied back from after. */
extern struct RASTPORT *shd_map_page;
extern unsigned char dat_str_empty[2];
/* The cipher alphabet: the letter each plain letter is enciphered as, shuffled
at the start of every puzzle. */
extern unsigned char dat_cipher[30];
/* The plain alphabet, A to Z, which dat_cipher is the permutation of. */
extern unsigned char dat_plain[29];
#ifndef PORT_MODERN
extern unsigned char asm_block_1095;
#endif
/* The player's guess for each letter, a space where nothing is guessed. */
extern unsigned char dat_guess[32];
extern unsigned char dat_str_crypto_workstation_msg[30];
extern unsigned char dat_str_zero[2];
extern unsigned char dat_str_blank[1];
extern unsigned char dat_str_dash[2];
/* A one-character string, filled with a letter and handed to c_write_text. */
extern unsigned char dat_one_char[2];
extern unsigned char dat_str_sure_want_quit_no[41];
extern unsigned char dat_str_paused[8];
extern unsigned char dat_str_message_decoded[17];
/* The clock string the panel shows, '00:00:00', its digits written in
 * place. */
extern unsigned char shd_clock_text[9];
#ifndef PORT_MODERN
extern unsigned char asm_block_1127;
#endif
extern unsigned char shd_str_one_moment_please[21];
extern unsigned char shd_str_sure_want_quit_no_2[41];
#ifndef PORT_MODERN
extern unsigned char dat_str_pani[5];
extern unsigned char asm_block_116b;
#endif
/* Which city's picture is on screen, so an unchanged one is not reloaded; cleared to -1 when a sequence starts. */
extern UNSIGNED_INT shd_city_on_screen;
/* The current drive, cached from _dos_getdrive the first time the menu needs
it; 2 or less means a floppy, which is what the wait message is for. */
extern INT shd_drive;
/* How wide the animation area is, in pixels, for every blank and restore of
 * it. */
extern UNSIGNED_INT shm_pan_width;
#ifndef PORT_MODERN
extern unsigned char asm_block_1172[2];
#endif
extern struct PALETTE shd_palette_menu;
/* The palette set in place of shd_palette_menu when the face drawn beside
the menu is of the fourth kind. It differs in one register. */
extern struct PALETTE shd_palette_face;
extern unsigned char shd_str_ok[3];
extern unsigned char shd_str_briefing_pan[13];
extern unsigned char shd_str_bld[4];
#ifndef PORT_MODERN
extern unsigned char asm_block_11ab;
#endif
/* Set when the animation's name begins with "bld", so that the restore
repaints the building's smaller corner as well. */
extern UNSIGNED_INT shm_pan_building;
extern unsigned char shd_str_animation_pan[14];
/* Nine directions indexed by the stick's two steps, each clamped to -1, 0 or 1
and combined as x * 3 + y + 4. */
extern UNSIGNED_INT shd_joystick_dirs[9];
extern unsigned char dat_str_final_exe[10];
extern unsigned char dat_str_game_exe[9];
extern unsigned char dat_str_tac_exe[8];
extern unsigned char dat_str_hq_pan[7];
extern unsigned char shd_str_please_insert_disk[20];
extern unsigned char shd_str_if_3_5_insert[23];
extern unsigned char shd_str_close_paren[2];
extern unsigned char shd_str_press_return_continue[41];
/* The name to look for on each of the four disks, one word per disk, indexed
by the disk number less one. */
extern drv_addr shd_disk_names[4];
/* The drive letter the disk prompt names, built as the disk number plus '@'
and appended to the message as a one-character string. */
extern unsigned char shd_disk_letter[2];
extern struct RASTPORT dat_screen_port;
/* The screen's page descriptor, the first argument of every drawing call.
It also carries the drawing colour and the font. */
extern struct RASTPORT *shd_screen;
#ifndef PORT_MODERN
extern unsigned char drv_DAT_136d_1264;
extern unsigned char drv_DAT_136d_1265;
extern UNSIGNED_INT drv_DAT_136d_1266;
extern UNSIGNED_INT drv_DAT_136d_1268;
extern unsigned char asm_block_126a[12];
extern unsigned char dat_msg_allocated_1mb_space[27];
extern unsigned char dat_msg_ms_dos_lied_us[54];
extern unsigned char dat_msg_filename_not_found[19];
extern unsigned char dat_msg_not_enough_memory_load[31];
extern unsigned char dat_msg_overlay_load_failed[36];
extern unsigned char dat_msg_overlay_has_overrun[37];
extern unsigned char dat_msg_unable_shrink_overlay[43];
extern unsigned char dat_msg_error_releasing_overlay[31];
extern unsigned char asm_message_pool_pad;
extern UNSIGNED_INT drv_DAT_136d_138d;
extern UNSIGNED_INT drv_DAT_136d_138f;
extern UNSIGNED_INT drv_DAT_136d_1391;
extern UNSIGNED_INT drv_DAT_136d_1393;
extern UNSIGNED_INT drv_DAT_136d_1395;
extern unsigned char asm_block_1397[436];
extern UNSIGNED_INT drv_DAT_136d_154b;
extern UNSIGNED_INT drv_DAT_136d_154d;
extern unsigned char asm_block_154f[442];
extern UNSIGNED_INT drv_DAT_136d_1709;
extern UNSIGNED_INT drv_DAT_136d_170b;
extern unsigned char asm_block_170d[5];
extern unsigned char drv_DAT_136d_1712;
extern UNSIGNED_INT drv_DAT_136d_1713;
extern UNSIGNED_INT drv_DAT_136d_1715;
extern UNSIGNED_INT drv_DAT_136d_1717;
extern UNSIGNED_INT drv_DAT_136d_1719;
extern UNSIGNED_INT drv_DAT_136d_171b;
extern UNSIGNED_INT drv_DAT_136d_171d;
extern unsigned char asm_block_171f;
extern UNSIGNED_INT drv_DAT_136d_1720;
extern UNSIGNED_INT drv_DAT_136d_1722;
extern unsigned char asm_block_1724[4];
extern UNSIGNED_INT drv_DAT_136d_1728;
extern UNSIGNED_INT drv_DAT_136d_172a;
extern UNSIGNED_INT drv_DAT_136d_172c;
extern unsigned char asm_block_172e[10];
extern unsigned char asm_block_1740[80];
extern unsigned char asm_block_17a1[8];
extern unsigned char asm_block_17ab[4];
extern unsigned char asm_block_17b3;
extern unsigned char asm_block_17b5[3];
extern unsigned char run_crt0dat_17b9;
extern unsigned char asm_block_17ba;
extern unsigned char run_crt0dat_17bb;
extern unsigned char run_crt0dat_17bc;
extern unsigned char run_crt0dat_17bd;
extern unsigned char run_crt0dat_17be;
extern unsigned char asm_block_17bf[13];
extern unsigned char run_crt0dat_17d6;
extern unsigned char run_crt0dat_17d7;
extern unsigned char asm_block_17d8[8];
extern UNSIGNED_INT run_stdargv_17e2;
extern unsigned char asm_block_17e4[278];
extern UNSIGNED_INT run_tz_days_leap[13];
extern UNSIGNED_INT run_tz_days_common[13];
extern unsigned char run_tz_name[4];
extern unsigned char run_tz_standard[4];
extern unsigned char run_timeset_1938;
extern unsigned char asm_block_1939[3];
extern UNSIGNED_INT run_timeset_193e;
extern UNSIGNED_INT run_timeset_1944;
extern unsigned char run_day_names[22];
extern unsigned char run_month_names[37];
extern unsigned char asm_block_1981;
extern UNSIGNED_INT run_rand_1982;
extern UNSIGNED_INT run_rand_1984;
extern unsigned char asm_block_1986[2];
extern UNSIGNED_INT run_crt0dat_198a;
extern UNSIGNED_LONG run_crt0dat_198c;
extern UNSIGNED_LONG run_crt0dat_1990;
extern unsigned char asm_block_1994[2];
extern unsigned char run_nmsg_marker[8];
extern UNSIGNED_INT run_crt0msg_199e;
extern unsigned char run_crt0msg_19a0[26];
extern unsigned char asm_block_19ba[2];
extern unsigned char run_msg_r6003[31];
extern unsigned char asm_block_19db[2];
extern unsigned char run_msg_r6009[44];
extern unsigned char asm_block_1a09[7];
extern unsigned char run_msg_runtime_error[16];
extern unsigned char asm_block_1a20[2];
extern unsigned char run_msg_r6002[37];
extern unsigned char asm_block_1a47[2];
extern unsigned char run_msg_r6001[35];
extern unsigned char asm_block_1a6c[4];
extern unsigned char asm_block_1a70;
extern unsigned char asm_block_1a71;
extern unsigned char asm_block_1a72[8];
#endif
/* Seconds on the puzzle's clock, stepped every ten retraces while it waits and
carried into shm_clock_minutes at sixty; asking for a letter adds an hour. */
extern INT asm_clock_seconds;
/* One flag per letter of the alphabet: non-zero once the player has been given
that letter, so rebuilding the guess row puts it back. */
extern UNSIGNED_INT asm_letter_known[28];
/* itoa's digit buffer, ten bytes, which each letter's count is written
into. */
extern unsigned char asm_count_digits[10];
/* How many letters the puzzle uses, 1ah, which bounds every loop over the
 * alphabet. */
extern INT asm_alphabet_size;
/* How many times each cipher letter appears in the text, counted as the text
is drawn and shown in the column beside it. */
extern INT asm_letter_count[28];
/* The screen's background animation, a struct SEQ_BLOCK: armed when a screen
 * is entered, started each time a menu opens and stepped while it waits. */
extern struct SEQ_BLOCK shm_active_pan;
#ifndef PORT_MODERN
extern unsigned char asm_block_1b06[16];
#endif
/* Where each line of the menu text starts, one word per line, filled as the
text is split on newlines; line n ends one byte before entry n + 1. */
extern INT shm_menu_line_start[32];
/* The colour a menu line that is not a choosable item is written in. */
extern UNSIGNED_INT shm_menu_colour_plain;
/* The colour an unselected menu item is written in. */
extern UNSIGNED_INT shm_menu_colour_item;
/* How many lines the menu text has, after clamping to what fits below the
box's top edge. */
extern INT shm_menu_lines;
/* The colour the selected menu item is written in. */
extern UNSIGNED_INT shm_menu_colour_pick;
#ifndef PORT_MODERN
extern unsigned char asm_block_1b5e[16];
extern UNSIGNED_INT run_tzset_1b6e;
#endif
extern struct JOYSTICK shm_joystick;
/* The puzzle's text, the 200h bytes of the shared block's message folded to
 * upper case, and the scratch buffer the disk prompt is built in. */
extern unsigned char shm_scratch[512];
/* How hard this puzzle is, -3 to 5, from the case's difficulty less two bits
of the skill word. Below 1 the board is opened up before play starts. */
extern INT asm_difficulty;
#ifndef PORT_MODERN
extern unsigned char asm_block_1d74[2];
#endif
/* The random seed, taken from the clock and handed to srand. */
extern UNSIGNED_INT shm_seed;
/* The option mask out of the shared block: bit 2 sound, bit 3 the
animation, bit 4 the joystick. The menu toggles all three. */
extern INT shm_options;
/* The graphics driver's letter, out of the shared block. */
extern UNSIGNED_INT shm_graphics_letter;
/* Set to have the menu box draw the tick marker in its corner. */
extern UNSIGNED_INT shm_menu_tick;
/* A face packed into a word, drawn beside the menu when it is not -1. */
extern INT shm_menu_face;
/* AX of the four-word register block the INT 33h calls read and write: AX, BX,
CX, DX from here up. */
extern union REGS shm_mouse_regs;
/* Set to 1 once the puzzle is solved, handed back in the shared block. */
extern UNSIGNED_INT asm_solved;
/* Minutes on the puzzle's clock, handed back in the shared block. */
extern UNSIGNED_INT shm_clock_minutes;
/* Which line of the menu text the first choosable item is on, so an item's
number can be turned into a row. */
extern INT shm_menu_first_line;
/* Non-zero while an animation is armed behind the menu. */
extern UNSIGNED_INT shm_pan_playing;
/* Set to run the menu with nothing selectable: the highlight is left off and
the answer is -1. */
extern UNSIGNED_INT shm_menu_no_pick;
/* How many choosable items the menu text has. */
extern INT shm_menu_items;
/* Set while the box has to be measured and drawn whole; clear, the draw
touches only the selected line and those either side of it. */
extern UNSIGNED_INT shm_menu_relayout;
/* The colour the highlight bar behind the selected item is filled in. */
extern UNSIGNED_INT shm_menu_colour_bar;
/* The widest menu line, in pixels, which is what sizes the box. */
extern INT shm_menu_text_width;
/* AL of the four-word register block the INT 10h calls read and write. */
extern union REGS shm_regs;
/* One bit per menu item: a marked item is drawn with a caret over the space
in front of it. */
extern UNSIGNED_INT shm_menu_marked;
/* Where the face beside the menu is drawn, across. */
extern UNSIGNED_INT shm_menu_face_x;
/* Set to have the menu drawn and left, answering -1 without reading a key. */
extern UNSIGNED_INT shm_menu_draw_only;
/* The button word the last INT 33h call returned. */
extern UNSIGNED_INT shm_mouse_buttons;
/* The x the last INT 33h call returned. */
extern UNSIGNED_INT shm_mouse_x;
/* The y the last INT 33h call returned. */
extern UNSIGNED_INT shm_mouse_y;
/* The press or release count the last INT 33h call returned. */
extern UNSIGNED_INT shm_mouse_count;
/* Where the face beside the menu is drawn, down. */
extern UNSIGNED_INT shm_menu_face_y;
/* Non-zero once the puzzle is over: 1 finished, -1 quit out of. */
extern INT shm_finished;
/* The letter that picks each menu item, taken from the character after the
space that marks the item. 32 of them. */
extern unsigned char shm_menu_shortcut[32];
/* Which item the menu starts on, and cleared to 0 as it leaves. */
extern UNSIGNED_INT shm_menu_pick;
/* The menu box's right edge. */
extern UNSIGNED_INT shm_menu_right;
/* The menu box's bottom edge. */
extern UNSIGNED_INT shm_menu_bottom;
#ifndef PORT_MODERN
extern unsigned char asm_block_1de6[2074];
#endif

#endif /* CODE_PORT_H */
