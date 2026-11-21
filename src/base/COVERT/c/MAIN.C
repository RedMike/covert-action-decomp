/* MAIN.C -- the launcher's entry point: load the drivers, run the modules.
 */
#include "COVERT.H"
#include "SETUPTXT.H"

#if defined(COVERT_SKIP_INTRO) && !defined(PORT_MODERN)
/* `value` where it is one of `allowed`, and `keep` where it is not. */
static char c_setup_letter(char value, char *allowed, char keep)
{
    while (*allowed != 0)
        if (*allowed++ == value)
            return value;
    return keep;
}

/* INTRO's three answers without INTRO: VGA, AdLib and keyboard only, then
 * whatever setup.txt beside the game says in `name = value` lines, of which
 * only first letters count. */
static void c_setup_answers(void)
{
    char text[512];
    char *at;
    char key;
    char value;
    INT fd;
    INT got;

    COMM()->spare_05[COMM_SETUP_RESTART] = 0;
    COMM()->graphics_driver = 'E';
    COMM()->sound_driver = 'A';
    COMM()->joystick_enabled = 0;
    fd = open((str_addr) "setup.txt", 0x8000);
    if (fd == -1)
        return;
    got = read(fd, (str_addr) text, sizeof text - 1);
    close(fd);
    if (got <= 0)
        return;
    text[got] = 0;
    at = text;
    while (*at != 0) {
        while (*at == ' ')
            at++;
        key = *at | 0x20;
        while (*at != 0 && *at != '\n' && *at != '=')
            at++;
        if (*at == '=') {
            do
                at++;
            while (*at == ' ');
            value = *at & 0xdf;
            if (value == 'V')
                value = 'E';
            if (key == 'g')
                COMM()->graphics_driver =
                    c_setup_letter(value, "EMTC", COMM()->graphics_driver);
            else if (key == 's')
                COMM()->sound_driver =
                    c_setup_letter(value, "NITAR", COMM()->sound_driver);
            else if (key == 'j')
                COMM()->joystick_enabled = value == 'Y' || *at == '1';
        }
        while (*at != 0 && *at++ != '\n')
            ;
    }
}
#endif

/* Load the drivers, then spawn game modules until one asks to stop. The shared
 * block names the drivers and the module to run next; 0ffh ends the game.
 * `spare` is never read.
 */
INT c_main(void)
{
    INT many;
    INT i;
    CHAR_INDEX code;
    INT spare;

    COMM_PUBLISH((struct COMM_BLOCK FAR *) &asm_COMM_BLOCK);
#if defined(COVERT_SKIP_INTRO) && !defined(PORT_MODERN)
    c_setup_answers();
#else
    SETUP_QUESTIONS(0, dat_exe_intro, dat_str_empty_arg);
#endif
    dat_GRAPHIC_NAME[0] = COMM()->graphics_driver;
    dat_SOUND_NAME[0] = COMM()->sound_driver;
    COMM()->driver_segment[0] = drv_real_load((drv_addr)dat_GRAPHIC_NAME, (drv_addr)dat_file_fonts);
    COMM()->driver_segment[1] = drv_real_load((drv_addr)dat_exe_misc, 0);
    COMM()->driver_segment[2] = drv_real_load((drv_addr)dat_SOUND_NAME, 0);
    drv_real_link_slots(COMM()->driver_segment[0]);
    drv_real_link_slots(COMM()->driver_segment[1]);
    drv_real_link_slots(COMM()->driver_segment[2]);
    drv_jump_gfx_open(0);
    many = 3;
    for (i = 0; i < many; i++) {
        asm_DRIVER_HANDLE = drv_jump_gfx_page_seg(i);
        drv_jump_gfx_set_page_seg(i, asm_DRIVER_HANDLE);
    }
    drv_jump_snd_open();
    COMM()->next_module = FINAL_TITLE;
    COMM()->mission_started = 0;
    do {
        NUM_LOCK_OFF();
        code = COMM()->next_module;
        if (code == CODEVIEW_DEBUG)
            SPAWN_PROCESS_ON_PATH(0, dat_exe_mcv, dat_ext_cv, dat_arg_slash_2,
                        dat_MODULE_TABLE[code]);
        else
            SPAWN_PROCESS(0, dat_MODULE_TABLE[(CHAR_INDEX) COMM()->next_module],
                      dat_module_spawn_arg);
    } while (COMM()->next_module != NONE_EXIT);
    drv_jump_snd_close();
    asm_regs.h.ah = 0;
    asm_regs.h.al = 3;
#if defined(COVERT_SKIP_INTRO) && !defined(PORT_MODERN)
    /* Where the session ended to change setup.txt, say so in text mode. */
    many = INTERRUPT(0x10, &asm_regs, &asm_regs);
    if (COMM()->spare_05[COMM_SETUP_RESTART] != 0)
        write(1, (str_addr) SETUP_RESTART_NOTE,
              sizeof SETUP_RESTART_NOTE - 1);
    return many;
#else
    return INTERRUPT(0x10, &asm_regs, &asm_regs);
#endif
}
