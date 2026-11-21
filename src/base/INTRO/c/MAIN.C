/* MAIN.C -- the setup questions: graphics, sound and joystick.
 *
 * Under MSC 5.1 a local's name decides its frame offset, so the names stay.
 */
#include "INTRO.H"
#include "CURSOR.H"

/* Ask the three setup questions over the title banner and write the answers
 * into the shared block: a letter of "EMETC" for graphics and of "NITARX" for
 * sound. The `idx >= 7` arm is dead; `padk` through `padi` are unread.
 */
void c_main(void)
{
    INT padk[24];
    char used;
    unsigned char prompt[58];
    char more;
    INT pado[2];
    unsigned char idx;
    unsigned char typed;
    INT padb[7];
    char asked;
    INT padd[2];
    UNSIGNED_INT row2;
    INT rows;
    INT padg[10];
    UNSIGNED_INT nitem;
    INT padi;

    drv_real_link_slots(drv_real_load((drv_addr) dat_exe_misc, 0));
    asm_regs.x.ax = 3;
    asm_int86(0x10, &asm_regs, &asm_regs);
    asm_write_at(0, 0, dat_title_head);
    asm_write_at(1, 0, dat_box_top);
    asm_write_at(2, 0, dat_banner_blank);
    asm_write_at(3, 0, dat_title_version);
    asm_write_at(4, 0, dat_banner_blank);
    asm_write_at(5, 0, dat_title_mpslabs);
    asm_write_at(6, 0, dat_banner_blank);
    asm_write_at(7, 0, dat_title_copyright);
    asm_write_at(8, 0, dat_title_rights);
    asm_write_at(9, 0, dat_banner_blank);
    asm_write_at(10, 0, dat_box_bottom);
    used = 1;
    asked = 1;
    c_cursor_at(13, 0);
    idx = 1;
    do {
        asm_dos_print(dat_blank_line);
        idx++;
    } while (idx <= 10);
    c_cursor_at(11, 0);
    asm_dos_print(dat_blank_line);
    asm_dos_print(dat_blank_line);
    asm_write_at(13, 0, dat_title_tail);
    asm_dos_print(dat_blank_line);
    nitem = 1;
    idx = 0;
    do {
        asm_itoa(nitem, prompt, 10);
        asm_graphics_choices[nitem - 1] = dat_graphics_letters[idx];
        asm_strcat(prompt, dat_graphics_options[idx]);
        asm_write_at(nitem++ + 14, 0x1b, prompt);
        idx++;
    } while (idx < 5);
    more = 1;
    do {
        c_cursor_at(13, '1');
        typed = drv_jump_dos_key();
        if (typed >= '1' && nitem + 0x30 > typed) {
            COMM()->graphics_driver = asm_graphics_choices[typed - '1'];
            if (COMM()->graphics_driver == 'H')
                COMM()->graphics_driver = 'C';
            if (COMM()->graphics_driver == 'V')
                COMM()->graphics_driver = 'M';
            more = 0;
        }
    } while (more);
    if (asked == 1) {
        c_cursor_at(12, 0);
        idx = 1;
        do {
            asm_dos_print(dat_blank_line);
            idx++;
        } while (idx <= 12);
        asm_write_at(12, 0, asm_prompt_pad_1);
        nitem = 1;
        row2 = 1;
        rows = 7;
        idx = 0;
        do {
            asm_itoa(nitem, prompt, 10);
            asm_sound_choices[nitem - 1] = dat_sound_letters[idx];
            if (idx >= 7) {
                dat_sound_options[idx][15] = asm_extra_sound_letters[idx];
                asm_sound_choices[nitem - 1] = asm_extra_sound_letters[idx];
            }
            asm_strcat(prompt, dat_sound_options[idx]);
            asm_write_at(row2++ + 13, 0x1b, prompt);
            nitem++;
            idx++;
        } while (idx < 6);
        more = 1;
        do {
            c_cursor_at(13, '2');
            typed = drv_jump_dos_key();
            if (typed >= '1' && nitem + 0x30 > typed) {
                COMM()->sound_driver = asm_sound_choices[typed - '1'];
                more = 0;
            }
        } while (more);
    }
    c_cursor_at(12, 0);
    idx = 1;
    do {
        asm_dos_print(dat_blank_line);
        idx++;
    } while (idx <= 12);
    asm_write_at(13, 0x1b, dat_menu_joystick);
    asm_write_at(14, 0x1b, dat_menu_keyboard);
    more = 1;
    do {
        c_cursor_at(13, '2');
        typed = drv_jump_dos_key();
        if (typed >= '1' && typed <= '2') {
            COMM()->joystick_enabled = typed == '1';
            more = 0;
        }
    } while (more);
    c_cursor_at(12, 0);
    idx = 1;
    do {
        asm_dos_print(dat_blank_line);
        idx++;
    } while (idx <= 12);
    asm_write_at(13, 0, asm_prompt_pad_2);
    asm_write_at(16, 0x1d, dat_msg_one_moment);
}
