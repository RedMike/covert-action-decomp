/* MAIN-3.C -- more of the module's own routines in MAIN.C's unit, after shared/MAIN.C. */
#include "FINAL.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "LOADDISK.H"
#include "CSTART.H"
#include "CMISEND.H"
#include "CMISSTRT.H"
#include "CASERUN.H"
#include "SAVELOAD.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "MAIN.H"
#include "ORIENT.H"
#include "MODOPTS.H"
#include "SETUPTXT.H"
#include "RESULT.H"
#include "ALERTLVL.H"

#ifdef COVERT_MENU_OPTIONS
/* What each option is called on the menu, in the struct's order. */
static char *mod_option_labels[] = {
    " Faster Break-in Movement: ",
    " Additional Guidance Text: ",
    " Flexible Character Orientation: ",
    " Unimplemented Rooms: ",
    " Player Disguise On Map: ",
    " Photos without camera: ",
};

/* The one counted option, a slider of these stops rather than On and Off. */
#define MOD_SLIDER 5
#define MOD_STOPS 3
static unsigned char mod_slider_stops[MOD_STOPS] = { 0, 2, 5 };

/* The stop the slider's count sits at, the highest not above it. */
static INT c_mod_slider_stop(void)
{
    INT stop;

    /* Down from the top stop to the first the count reaches; below every stop is the first. */
    for (stop = MOD_STOPS - 1; stop > 0; stop--)
        if (mod_slider_stops[stop] <= MOD_OPTION_BYTES[MOD_SLIDER])
            break;
    return stop;
}

/* Writing mods.txt, a line an option, for the other modules to read back and
 * for the next run. */
static void c_mod_options_save(void)
{
    char digits[4];
    INT fd;
    INT i;

    /* The file is written afresh; where it cannot be, the choices last this session only. */
    fd = open((str_addr) "mods.txt", 0x8302, 0x80);
    if (fd == -1)
        return;
    /* One `name = n` line an option, its byte as a decimal number, 0 for Off. */
    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        strcpy(shm_scratch, (str_addr) mod_option_names[i]);
        strcat((str_addr) shm_scratch, (str_addr) " = ");
        strcat((str_addr) shm_scratch,
               (str_addr) itoa(MOD_OPTION_BYTES[i], (str_addr) digits, 10));
        strcat((str_addr) shm_scratch, (str_addr) "\r\n");
        write(fd, (str_addr) shm_scratch, strlen(shm_scratch));
    }
    close(fd);
}

/* The Mod Options menu's text into shm_scratch, every option Off and the
 * slider at its first stop when `all_off`, which is the widest the menu can
 * be. The slider is `+` on a track of `=`, then its count. */
static void c_mod_options_text(INT all_off)
{
    char *at;
    INT stop;
    INT i;
    INT j;

    /* The title line, then a line an option: its label and its setting. */
    strcpy(shm_scratch, (str_addr) "Mod Options\n");
    for (i = 0; i < MOD_OPTION_COUNT; i++) {
        strcat((str_addr) shm_scratch, (str_addr) mod_option_labels[i]);
        /* The slider: the knob at its stop on the track, then the count that stop gives. */
        if (i == MOD_SLIDER) {
            stop = all_off ? 0 : c_mod_slider_stop();
            at = (char *) shm_scratch + strlen(shm_scratch);
            *at++ = '[';
            for (j = 0; j < MOD_STOPS; j++)
                *at++ = (char) (j == stop ? '+' : '=');
            *at++ = ']';
            *at++ = ' ';
            *at++ = (char) ('0' + mod_slider_stops[stop]);
            *at++ = '\n';
            *at = 0;
            continue;
        }
        /* Any other option is On or Off. */
        strcat((str_addr) shm_scratch,
               (str_addr) (MOD_OPTION_BYTES[i] != 0 && !all_off
                           ? "On\n" : "Off\n"));
    }
    /* The way out, the item after the options. */
    strcat((str_addr) shm_scratch, (str_addr) " Back..\n");
}

/* The widest line in pixels of the menu text in shm_scratch, and how many
 * lines it has into `lines`. */
static INT c_menu_widest(INT *lines)
{
    INT wide;
    INT widest;
    char *at;

    wide = widest = *lines = 0;
    /* Each line ends at a newline: keep it if it is the widest yet, and count it. */
    for (at = (char *) shm_scratch; *at != 0; at++)
        if (*at == '\n') {
            if (wide > widest)
                widest = wide;
            wide = 0;
            (*lines)++;
        } else
            /* Within a line, add up the characters' widths in the screen's font. */
            wide += drv_jump_gfx_char_width(shd_screen->font, *at);
    return widest;
}

/* The Mod Options menu, centred at its widest: Return toggles an option or
 * moves the slider a stop right, wrapping; Back.. or Escape leaves; with
 * EXTRA_MENU_OPTIONS Left and Right move the slider. The box sits on an even
 * row, an odd one being the box-less style. */
static void c_mod_options_menu(void)
{
    INT choice;
    INT stop;
    INT widest;
    INT lines;
    INT x;
    INT y;

    /* Start from what mods.txt says now. */
    c_mod_options_load();
    /* Centre the menu at its widest, on an even row, and keep the screen it covers. */
    c_mod_options_text(1);
    widest = c_menu_widest(&lines);
    x = (320 - widest - 8) / 2;
    y = ((200 - (lines << 3) - 6) / 2) & ~1;
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
    choice = 0;
    do {
        /* Ask with the options as they stand, the bar on the item last picked. */
        c_mod_options_text(0);
        shm_menu_pick = choice;
#ifdef EXTRA_MENU_OPTIONS
        menu_sideways = MOD_SLIDER + 1;
#endif
        choice = c_ask_menu((rt_addr) shm_scratch, x, y);
        drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen,
                               0, 0);
        /* Move the slider or flip the option picked; the slider's count follows its stop. */
        stop = c_mod_slider_stop();
#ifdef EXTRA_MENU_OPTIONS
        if (menu_sideways == KEY_LEFT) {
            if (stop > 0)
                stop--;
        } else if (menu_sideways == KEY_RIGHT) {
            if (stop < MOD_STOPS - 1)
                stop++;
        } else
#endif
        if (choice == MOD_SLIDER)
            stop = (stop + 1) % MOD_STOPS;
        else if (choice >= 0 && choice < MOD_OPTION_COUNT)
            MOD_OPTION_BYTES[choice] ^= 1;
#ifdef EXTRA_MENU_OPTIONS
        menu_sideways = 0;
#endif
        MOD_OPTION_BYTES[MOD_SLIDER] = mod_slider_stops[stop];
    } while (choice >= 0 && choice < MOD_OPTION_COUNT);
    /* Back.. or Escape: keep the choices for the other modules and the next run. */
    c_mod_options_save();
}

#ifdef SETUP_OPTIONS
/* The Options menu's settings, in its order: each one's label, its key in
 * setup.txt, the letters COVERT takes for it and what each is called. */
#define SETUP_COUNT 3
#define SETUP_MOST 5
static char *setup_labels[SETUP_COUNT] = {
    " Graphics: ", " Sound: ", " Joystick: ",
};
static char *setup_keys[SETUP_COUNT] = { "graphics", "sound", "joystick" };
static char *setup_letters[SETUP_COUNT] = { "EMTC", "NITAR", "NY" };
static char *setup_names[SETUP_COUNT][SETUP_MOST] = {
    { "VGA/EGA", "MCGA", "Tandy", "CGA" },
    { "None", "IBM", "Tandy", "AdLib", "Roland" },
    { "Off", "On" },
};
static INT setup_picks[SETUP_COUNT];

/* How many values setting `i` has. */
static INT c_setup_stops(INT i)
{
    INT n;

    /* A value a letter. */
    for (n = 0; setup_letters[i][n] != 0; n++)
        ;
    return n;
}

/* Where `letter` is among setting `i`'s, the first where it is none. */
static INT c_setup_find(INT i, INT letter)
{
    INT n;

    /* A letter the setting does not know shows as its first value. */
    for (n = 0; setup_letters[i][n] != 0; n++)
        if (setup_letters[i][n] == letter)
            return n;
    return 0;
}

/* The Options menu's text into shm_scratch: every setting at its pick, or at
 * value `all` round its own count when that is not -1, for measuring. */
static void c_setup_text(INT all)
{
    INT i;
    INT n;

    /* The title line, then a line a setting: its label and its value's name. */
    strcpy(shm_scratch, (str_addr) "Options\n");
    for (i = 0; i < SETUP_COUNT; i++) {
        n = all < 0 ? setup_picks[i] : all % c_setup_stops(i);
        strcat((str_addr) shm_scratch, (str_addr) setup_labels[i]);
        strcat((str_addr) shm_scratch, (str_addr) setup_names[i][n]);
        strcat((str_addr) shm_scratch, (str_addr) "\n");
    }
    /* The way out, the item after the settings. */
    strcat((str_addr) shm_scratch, (str_addr) " Back..\n");
}

/* Writing setup.txt, a `key = letter` line a setting, for COVERT to read at
 * the next start. */
static void c_setup_save(void)
{
    char *at;
    INT fd;
    INT i;

    /* The file is written afresh; where it cannot be, nothing is kept. */
    fd = open((str_addr) "setup.txt", 0x8302, 0x80);
    if (fd == -1)
        return;
    /* One `key = letter` line a setting, the letter COVERT takes for its value. */
    for (i = 0; i < SETUP_COUNT; i++) {
        strcpy(shm_scratch, (str_addr) setup_keys[i]);
        strcat((str_addr) shm_scratch, (str_addr) " = ");
        at = (char *) shm_scratch + strlen(shm_scratch);
        *at++ = setup_letters[i][setup_picks[i]];
        *at++ = '\r';
        *at++ = '\n';
        *at = 0;
        write(fd, (str_addr) shm_scratch, strlen(shm_scratch));
    }
    close(fd);
}

/* The Options menu, centred at its widest: Return moves a setting on a value,
 * wrapping, and Back.. or Escape leaves. The drivers are loaded before FINAL
 * runs, so a change is written to setup.txt and ends the session. */
static void c_setup_menu(void)
{
    INT was[SETUP_COUNT];
    INT choice;
    INT widest;
    INT wide;
    INT lines;
    INT x;
    INT y;
    INT i;

    /* Each setting starts at what this session is running with, kept to spot a change. */
    setup_picks[0] = c_setup_find(0, COMM()->graphics_driver);
    setup_picks[1] = c_setup_find(1, COMM()->sound_driver);
    setup_picks[2] = COMM()->joystick_enabled != 0;
    for (i = 0; i < SETUP_COUNT; i++)
        was[i] = setup_picks[i];
    /* Measure every value of every setting, so the menu need not move as they change. */
    widest = 0;
    for (i = 0; i < SETUP_MOST; i++) {
        c_setup_text(i);
        wide = c_menu_widest(&lines);
        if (wide > widest)
            widest = wide;
    }
    /* Centre it there, on an even row, and keep the screen it covers. */
    x = (320 - widest - 8) / 2;
    y = ((200 - (lines << 3) - 6) / 2) & ~1;
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
    choice = 0;
    do {
        /* Ask, the bar on the item last picked, and move that setting on a value. */
        c_setup_text(-1);
        shm_menu_pick = choice;
        choice = c_ask_menu((rt_addr) shm_scratch, x, y);
        drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen,
                               0, 0);
        if (choice >= 0 && choice < SETUP_COUNT)
            setup_picks[choice] =
                (setup_picks[choice] + 1) % c_setup_stops(choice);
    } while (choice >= 0 && choice < SETUP_COUNT);
    /* Nothing changed: back to the main menu as if never asked. */
    for (i = 0; i < SETUP_COUNT; i++)
        if (setup_picks[i] != was[i])
            break;
    if (i == SETUP_COUNT)
        return;
    /* A change: write setup.txt, ask COVERT for the note to restart, and end the session. */
    c_setup_save();
    COMM()->spare_05[COMM_SETUP_RESTART] = 1;
    c_hook_hand_back(UNSET_ARGS(0));
    COMM()->next_module = NONE_EXIT;
    exit(UNSET_ARGS(0));
}
#endif
#endif
