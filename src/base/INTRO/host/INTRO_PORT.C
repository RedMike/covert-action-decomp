#ifdef PORT_MODERN
#include "INTRO_PORT.H"

unsigned char dat_mode_vga[18] = ") VGA (256 color)";
unsigned char dat_mode_mcga[19] = ") MCGA (256 color)";
unsigned char dat_mode_ega[17] = ") EGA (16 color)";
unsigned char dat_mode_tandy[24] = ") Tandy 1000 (16 color)";
unsigned char dat_mode_cga[16] = ") CGA (4 color)";
unsigned char dat_mode_no_sound[25] = ") Shhh! No sounds please";
unsigned char dat_mode_ibm_sound[13] = ") IBM sounds";
unsigned char dat_mode_tandy_sound[15] = ") Tandy sounds";
unsigned char dat_mode_adlib[20] = ") AdLib sound board";
unsigned char dat_mode_roland[26] = ") Roland MT-32 MIDI board";
unsigned char dat_mode_custom_sound[22] = ") Custom sound driver";
unsigned char dat_blank_line_text[83] =
    "                                                                         "
    "      \r\n$";
unsigned char dat_banner_blank_text[81] =
    " \272                                                                    "
    "        \272 ";
unsigned char dat_exe_misc[9] = "misc.exe";
unsigned char dat_title_head[3] = "\377O";
unsigned char dat_box_top[81] = {
    0x20, 0xc9, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xbb, 0x20, 0x00,
};
unsigned char dat_title_version[81] =
    " \272                    Covert Action (TM) - Version 447.01             "
    "        \272 ";
unsigned char dat_title_mpslabs[81] =
    " \272                    From those sneaky guys at MPS Labs.             "
    "        \272 ";
unsigned char dat_title_copyright[81] =
    " \272    Program & Audio-visual Copyright (C) 1990 by MicroProse Software"
    ",Inc.,  \272 ";
unsigned char dat_title_rights[81] =
    " \272                            All Rights Reserved.                    "
    "        \272 ";
unsigned char dat_box_bottom[81] = {
    0x20, 0xc8, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xbc, 0x20, 0x00,
};
unsigned char dat_title_tail[2] = {
    0xff, 0x0e,
};
unsigned char asm_prompt_pad_1[2] = {
    0xff, 0x0e,
};
unsigned char dat_menu_joystick[25] = "1. Joystick and Keyboard";
unsigned char dat_menu_keyboard[17] = "2. Keyboard only";
unsigned char asm_prompt_pad_2[3] = {
    0xff, 0x0e, 0x00,
};
unsigned char dat_msg_one_moment[21] = "One Moment Please...";
unsigned char *dat_graphics_options[5] = {
    (unsigned char *) dat_mode_vga, (unsigned char *) dat_mode_mcga,
    (unsigned char *) dat_mode_ega, (unsigned char *) dat_mode_tandy,
    (unsigned char *) dat_mode_cga,
};
unsigned char *dat_sound_options[6] = {
    (unsigned char *) dat_mode_no_sound, (unsigned char *) dat_mode_ibm_sound,
    (unsigned char *) dat_mode_tandy_sound, (unsigned char *) dat_mode_adlib,
    (unsigned char *) dat_mode_roland, (unsigned char *) dat_mode_custom_sound,
};
unsigned char dat_sound_letters[6] = "NITARX";
unsigned char dat_graphics_letters[5] = "EMETC";
unsigned char *dat_blank_line = (unsigned char *) dat_blank_line_text;
unsigned char *dat_banner_blank = (unsigned char *) dat_banner_blank_text;
union REGS asm_regs;
unsigned char asm_sound_choices[6];
unsigned char asm_extra_sound_letters[6];
unsigned char asm_graphics_choices[5];
#endif
