#ifdef PORT_MODERN
#include "CODE_PORT.H"

struct COLOUR_MAP shd_colours_screen = {
    0x00,
    0x00,
    0x01,
    0x00,
    0x02,
    0x00,
    0x00,
    0x02,
    0x00,
    0x01,
    0x02,
    0x03,
    0x02,
    0x01,
    0x01,
    0x03,
};
struct COLOUR_MAP shd_colours_screen_2 = {
    0x00,
    0x00,
    0x11,
    0x11,
    0x22,
    0x00,
    0x00,
    0x22,
    0x00,
    0x22,
    0x33,
    0x33,
    0x22,
    0x11,
    0x22,
    0x33,
};
struct COLOUR_MAP shd_colours_paper = {
    0x00,
    0x11,
    0x11,
    0x11,
    0x22,
    0x00,
    0x22,
    0x12,
    0x00,
    0x11,
    0x11,
    0x33,
    0x33,
    0x22,
    0x33,
    0x33,
};
UNSIGNED_INT shd_pan_disk = 0x0002;
struct RASTPORT dat_map_page_port = { 1, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *shd_map_page = (struct RASTPORT *) &dat_map_page_port;
unsigned char dat_str_empty[2];
unsigned char dat_cipher[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\";
unsigned char dat_plain[29] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\";
unsigned char dat_guess[32] = "                             ";
unsigned char dat_str_crypto_workstation_msg[30] =
    "CRYPTO WORKSTATION, Msg:#M173";
unsigned char dat_str_zero[2] = "0";
unsigned char dat_str_blank[1];
unsigned char dat_str_dash[2] = "-";
unsigned char dat_one_char[2] = "x";
unsigned char dat_str_sure_want_quit_no[41] =
    "Are you sure\nyou want to Quit?\n No\n Yes\n";
unsigned char dat_str_paused[8] = "PAUSED\n";
unsigned char dat_str_message_decoded[17] = "MESSAGE DECODED\n";
unsigned char shd_clock_text[9] = "00:00:00";
unsigned char shd_str_one_moment_please[21] = "One moment please...";
unsigned char shd_str_sure_want_quit_no_2[41] =
    "Are you sure\nyou want to Quit?\n No\n Yes\n";
UNSIGNED_INT shd_city_on_screen = 0xffff;
INT shd_drive = -1;
UNSIGNED_INT shm_pan_width = 0x0140;
struct PALETTE shd_palette_menu = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
struct PALETTE shd_palette_face = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x06,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
unsigned char shd_str_ok[3] = "OK";
unsigned char shd_str_briefing_pan[13] = "briefing.pan";
unsigned char shd_str_bld[4] = "bld";
UNSIGNED_INT shm_pan_building;
unsigned char shd_str_animation_pan[14] = "animation.pan";
UNSIGNED_INT shd_joystick_dirs[9] = {
    0x0008, 0x0007, 0x0006, 0x0001, 0xffff, 0x0005,
    0x0002, 0x0003, 0x0004,
};
unsigned char dat_str_final_exe[10] = "final.exe";
unsigned char dat_str_game_exe[9] = "game.exe";
unsigned char dat_str_tac_exe[8] = "tac.exe";
unsigned char dat_str_hq_pan[7] = "hq.pan";
unsigned char shd_str_please_insert_disk[20] = "Please insert Disk ";
unsigned char shd_str_if_3_5_insert[23] = "\n(if 3.5\" insert Disk ";
unsigned char shd_str_close_paren[2] = ")";
unsigned char shd_str_press_return_continue[41] =
    ".\n \n     Press Return\n     to continue.\n";
drv_addr shd_disk_names[4] = {
    (drv_addr) dat_str_final_exe, (drv_addr) dat_str_game_exe,
    (drv_addr) dat_str_tac_exe, (drv_addr) dat_str_hq_pan,
};
unsigned char shd_disk_letter[2] = "A";
struct RASTPORT dat_screen_port = { 0, 0, 0, 319, 199, 1, 15, 4, 0 };
struct RASTPORT *shd_screen = (struct RASTPORT *) &dat_screen_port;
INT asm_clock_seconds;
UNSIGNED_INT asm_letter_known[28];
unsigned char asm_count_digits[10];
INT asm_alphabet_size;
INT asm_letter_count[28];
struct SEQ_BLOCK shm_active_pan;
INT shm_menu_line_start[32];
UNSIGNED_INT shm_menu_colour_plain;
UNSIGNED_INT shm_menu_colour_item;
INT shm_menu_lines;
UNSIGNED_INT shm_menu_colour_pick;
struct JOYSTICK shm_joystick;
unsigned char shm_scratch[512];
INT asm_difficulty;
UNSIGNED_INT shm_seed;
INT shm_options;
UNSIGNED_INT shm_graphics_letter;
UNSIGNED_INT shm_menu_tick;
INT shm_menu_face;
union REGS shm_mouse_regs;
UNSIGNED_INT asm_solved;
UNSIGNED_INT shm_clock_minutes;
INT shm_menu_first_line;
UNSIGNED_INT shm_pan_playing;
UNSIGNED_INT shm_menu_no_pick;
INT shm_menu_items;
UNSIGNED_INT shm_menu_relayout;
UNSIGNED_INT shm_menu_colour_bar;
INT shm_menu_text_width;
union REGS shm_regs;
UNSIGNED_INT shm_menu_marked;
UNSIGNED_INT shm_menu_face_x;
UNSIGNED_INT shm_menu_draw_only;
UNSIGNED_INT shm_mouse_buttons;
UNSIGNED_INT shm_mouse_x;
UNSIGNED_INT shm_mouse_y;
UNSIGNED_INT shm_mouse_count;
UNSIGNED_INT shm_menu_face_y;
INT shm_finished;
unsigned char shm_menu_shortcut[32];
UNSIGNED_INT shm_menu_pick;
UNSIGNED_INT shm_menu_right;
UNSIGNED_INT shm_menu_bottom;
#endif
