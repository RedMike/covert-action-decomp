/* CODE.H -- what the C side can reach on the assembly side. */
#ifndef CODE_H
#define CODE_H

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

/* data defined in assembly, exported to C */
#ifdef PORT_MODERN
/* The data group, datum by datum, which the portable build alone reads. */
#include "CODE_PORT.H"
#else
extern struct COLOUR_MAP shd_colours_screen;
extern struct COLOUR_MAP shd_colours_screen_2;
extern struct COLOUR_MAP shd_colours_paper;
/* The disk the menu's animation is on, asked for when it is not in
the drive rather than refused. */
extern UNSIGNED_INT shd_pan_disk;
/* The off-screen page descriptor: what the screen is copied to before a menu
or a pop-up covers it, and copied back from after. */
extern struct RASTPORT *shd_map_page;
extern unsigned char dat_str_empty[2];
/* The cipher alphabet: the letter each plain letter is enciphered as, shuffled
at the start of every puzzle. */
extern unsigned char dat_cipher[30];
/* The plain alphabet, A to Z, which dat_cipher is the permutation of. */
extern unsigned char dat_plain[29];
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
extern unsigned char shd_str_one_moment_please[21];
extern unsigned char shd_str_sure_want_quit_no_2[41];
/* Which city's picture is on screen, so an unchanged one is not reloaded; cleared to -1 when a sequence starts. */
extern UNSIGNED_INT shd_city_on_screen;
/* The current drive, cached from _dos_getdrive the first time the menu needs
it; 2 or less means a floppy, which is what the wait message is for. */
extern INT shd_drive;
/* How wide the animation area is, in pixels, for every blank and restore of
 * it. */
extern UNSIGNED_INT shm_pan_width;
extern struct PALETTE shd_palette_menu;
/* The palette set in place of shd_palette_menu when the face drawn beside
the menu is of the fourth kind. It differs in one register. */
extern struct PALETTE shd_palette_face;
extern unsigned char shd_str_ok[3];
extern unsigned char shd_str_briefing_pan[13];
extern unsigned char shd_str_bld[4];
/* Set when the animation's name begins with "bld", so that the restore
repaints the building's smaller corner as well. */
extern UNSIGNED_INT shm_pan_building;
extern unsigned char shd_str_animation_pan[14];
/* Nine directions indexed by the stick's two steps, each clamped to -1, 0 or 1
and combined as x * 3 + y + 4. */
extern UNSIGNED_INT shd_joystick_dirs[9];
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
/* The screen's page descriptor, the first argument of every drawing call.
It also carries the drawing colour and the font. */
extern struct RASTPORT *shd_screen;
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
extern struct JOYSTICK shm_joystick;
/* The puzzle's text, the 200h bytes of the shared block's message folded to
 * upper case, and the scratch buffer the disk prompt is built in. */
extern unsigned char shm_scratch[512];
/* How hard this puzzle is, -3 to 5, from the case's difficulty less two bits
of the skill word. Below 1 the board is opened up before play starts. */
extern INT asm_difficulty;
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
#endif

#endif /* CODE_H */
