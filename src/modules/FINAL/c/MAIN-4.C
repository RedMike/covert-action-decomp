/* MAIN-4.C -- more of the module's own routines in MAIN.C's unit, after shared/MAIN-2.C. */
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

#ifdef FLEXIBLE_ORIENTATION
/* The orientation menu, styled and padded to match the agent's-sex menu, and
 * what it covers put back from the map page, which holds gender.pic. Escape is
 * Straight, and so is the option being off, which asks nothing. */
void c_orientation_menu(void)
{
    INT choice;

    /* Ask where the sex menu stood, then wipe the menu off with gender.pic behind it. */
    if (MOD_ON(flexible_orientation)) {
        strcpy(shm_scratch,
               (str_addr) "Orientation...       \n Straight\n Gay\n Bisexual\n");
        choice = c_ask_menu((rt_addr) shm_scratch, 96, 81);
        drv_jump_gfx_copy_rect(shd_map_page, 96, 81,
                               shm_menu_right - 96 + 2,
                               shm_menu_bottom - 81 + 2, shd_screen,
                               96, 81);
    } else
        choice = ORIENTATION_STRAIGHT;
    if (choice < 0)
        choice = ORIENTATION_STRAIGHT;
    /* Into the shared block for every module and save, no mission pairing rolled yet. */
    COMM()->spare_66[COMM_ORIENTATION] = (unsigned char) choice;
    COMM()->spare_66[COMM_MISSION_ORIENTATION] = 0;
    c_orientation_load();
}

/* One partner's sex, as mission_orientation spells it: the agent's own for
 * Straight, the other for Gay, and a fresh roll for Bisexual. With the option
 * off a campaign begun with it on plays Straight. */
INT c_orientation_partner(void)
{
    INT sex;

    c_orientation_load();
    sex = (shm_options & OPT_FEMALE) != 0;
    /* The option switched off since: play Straight whatever the campaign chose. */
    if (!MOD_ON(flexible_orientation)) {
        orientation = ORIENTATION_STRAIGHT;
        return sex;
    }
    /* Bisexual tosses a coin each time; Gay is the other sex. */
    if (orientation == ORIENTATION_BISEXUAL)
        return c_random_below(2);
    return sex ^ (orientation == ORIENTATION_GAY);
}

/* The babe who stands where dude `n` does in ending scene `kind` (lau, off,
 * bch, cas), for a bisexual agent's mix: the two numberings put the figures
 * in different spots. */
static char orientation_babe_for_dude[4][4] = {
    { 2, 1, 0, 0 },
    { 4, 3, 1, 2 },
    { 2, 3, 4, 1 },
    { 1, 3, 2, 4 },
};

INT c_orientation_babe(INT kind, INT n)
{
    /* Dudes are numbered from 1. */
    return orientation_babe_for_dude[kind][n - 1];
}

/* Settling a mission's pairing, at its start, by one partner's roll. */
void c_orientation_roll(void)
{
    /* Kept plus one in the shared block, so GAME and the ending scenes read the one pairing. */
    mission_orientation = c_orientation_partner();
    COMM()->spare_66[COMM_MISSION_ORIENTATION] =
        (unsigned char) (mission_orientation + 1);
}
#endif

#ifdef DIAGNOSTICS
#include "SCREEN.H"
#include "CLAMP.H"

/* The faces page's three views, which are its menu's first three items. */
#define DIAG_VIEW_FACES 0
#define DIAG_VIEW_PHOTOS 1
#define DIAG_VIEW_MASTERMINDS 2

/* Row 0 of the organisation table as it ships, while the page rolls its own
 * into it. */
static UNSIGNED_INT diag_saved_row[8];

/* A suspect's face, rolled the way a new suspect's is: bit 15 is never set. */
static INT c_diag_roll_suspect(void)
{
    INT face;

    /* Any non-zero face, with bit 0, its bank, forced on a further third of the time. */
    face = c_random_below(32766) + 1;
    if (c_random_below(3) == 0)
        face |= 1;
    return face;
}

/* A MasterMind-like face: row 0 of the organisation table rolled over each
 * field's whole range, the body in word 7 included, and packed by c_pack_org
 * as a MasterMind's is. The row stays rolled until the page puts it back. */
static INT c_diag_roll_mastermind(void)
{
    INT j;

    /* Each word over the range the shipped rows use: 0-1, 0-1, four of 1-8, 0-3, 0-3. */
    dat_org_table[0][0] = c_random_below(2);
    dat_org_table[0][1] = c_random_below(2);
    for (j = 2; j < 6; j++)
        dat_org_table[0][j] = c_random_below(8) + 1;
    dat_org_table[0][6] = c_random_below(4);
    dat_org_table[0][7] = c_random_below(4);
    return c_pack_org(0);
}

/* Writing what a photo was drawn from under it, as `WORDoObB`: the packed face
 * in hex, its overlay (bits 2 and 3) and the body drawn. */
static void c_diag_label(UNSIGNED_INT word, INT body, INT x, INT y)
{
    char text[12];
    INT i;

    /* The word as four hex digits, top nibble first. */
    for (i = 0; i < 4; i++)
        text[i] = "0123456789ABCDEF"[word >> (12 - i * 4) & 0xf];
    /* Then `o` and the overlay, `b` and the body. */
    text[4] = 'o';
    text[5] = (char) ('0' + (word >> 2 & 3));
    text[6] = 'b';
    text[7] = (char) ('0' + body);
    text[8] = 0;
    /* In the screen's colours rather than the faces'. */
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
    c_write_text_trimmed((drv_addr) text, x, y, 15);
}

/* Faces: twenty suspect faces in two rows of ten above the menu and twenty
 * MasterMind-like ones below it, each by c_draw_face in a 20h-by-23h cell. */
static void c_diag_draw_faces(void)
{
    INT i;

    /* A clear screen in the faces' colours. */
    drv_jump_gfx_set_colour_map(&shd_colours_face, &shd_colours_face);
    drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 1);
    /* Suspects in the top two rows, from the screen's top. */
    for (i = 0; i < 20; i++)
        c_draw_face(c_diag_roll_suspect(), i % 10 * 32, i / 10 * 36 + 2);
    /* MasterMind-like faces in the bottom two, clear of the menu. */
    for (i = 0; i < 20; i++)
        c_draw_face(c_diag_roll_mastermind(), i % 10 * 32,
                    i / 10 * 36 + 124);
}

/* Photos: five suspects by c_draw_face_panel above the menu and five
 * MasterMind-like ones by c_draw_mastermind_face_panel below it, each
 * labelled with what it was drawn from. */
static void c_diag_draw_photos(void)
{
    INT i;
    INT face;

    /* A clear screen in the faces' colours. */
    drv_jump_gfx_set_colour_map(&shd_colours_face, &shd_colours_face);
    drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 1);
    /* Suspects along the top, each labelled with its face word and the body its low bits pick. */
    for (i = 0; i < 5; i++) {
        face = c_diag_roll_suspect();
        c_draw_face_panel(face, i * 64 + 7, 8);
        c_diag_label(face, face & 3, i * 64 + 5, 8 + 56);
    }
    /* MasterMind-like ones along the bottom, from the rolled row 0, with word 7 as the body. */
    for (i = 0; i < 5; i++) {
        face = c_diag_roll_mastermind();
        c_draw_mastermind_face_panel(0, i * 64 + 7, 126, 0, 0);
        c_diag_label(face, dat_org_table[0][7], i * 64 + 5, 126 + 56);
    }
}

/* Each MasterMind's organisation's short name, by the MasterMind's number, as
 * the three WORLDn.DTA give it; and the cities and organisations they are
 * read over, put back after. */
static char diag_short[26][6];
static struct CITY diag_cities[16];
static struct ORG_STATE diag_orgs[16];

/* Reading every world for the short names. An organisation's `known` is its
 * MasterMind's number as the file gives it, -1 for none, and two worlds that
 * share a number agree on the name. */
static void c_diag_short_names(void)
{
    INT w;
    INT i;
    INT j;
    INT n;

    /* Keep the case's cities and organisations, which reading a world overwrites. */
    for (i = 0; i < 16; i++) {
        diag_cities[i] = shm_cities[i];
        diag_orgs[i] = shm_orgs[i];
    }
    /* A MasterMind no world names has no short name. */
    for (n = 0; n < 26; n++)
        diag_short[n][0] = 0;
    /* Each world's organisations with a MasterMind give that MasterMind's short name. */
    for (w = 0; w < 3; w++) {
        c_read_world(w);
        for (i = 0; i < 16; i++) {
            if (shm_orgs[i].known == -1)
                continue;
            n = shm_orgs[i].known & 0xff;
            if (n >= 26)
                continue;
            for (j = 0; j < 5; j++)
                diag_short[n][j] = shm_orgs[i].short_name[j];
            diag_short[n][5] = 0;
        }
    }
    /* Put the case's own back. */
    for (i = 0; i < 16; i++) {
        shm_cities[i] = diag_cities[i];
        shm_orgs[i] = diag_orgs[i];
    }
}

/* MasterMinds a page of Masterminds holds: two rows of five panels, where
 * Photos has them, the menu between. */
#define DIAG_MM_PAGE 10
#define DIAG_MM_PAGES ((0x1a + DIAG_MM_PAGE - 1) / DIAG_MM_PAGE)

/* Masterminds: page `page` of the 26 rows of the organisation table as it
 * ships, each by c_draw_mastermind_face_panel with its organisation's short
 * name centred under it. */
static void c_diag_draw_masterminds(INT page)
{
    INT k;
    INT n;
    INT x;
    INT y;
    INT wide;

    /* A clear screen in the faces' colours. */
    drv_jump_gfx_set_colour_map(&shd_colours_face, &shd_colours_face);
    drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 1);
    /* The page's MasterMinds, the last page stopping at the twenty-sixth. */
    for (k = 0; k < DIAG_MM_PAGE; k++) {
        n = page * DIAG_MM_PAGE + k;
        if (n >= 26)
            break;
        /* Five along the top, five along the bottom, where Photos puts its panels. */
        x = k % 5 * 64 + 7;
        y = k < 5 ? 8 : 126;
        c_draw_mastermind_face_panel(n, x, y, 0, 0);
        /* The short name centred under the panel, in the screen's colours. */
        drv_jump_gfx_set_colour_map(&shd_colours_screen,
                                    &shd_colours_screen_2);
        wide = c_text_width((rt_addr) diag_short[n]);
        c_write_text_trimmed((drv_addr) diag_short[n], x + 25 - wide / 2,
                             y + 55, 15);
    }
}

/* The faces page's menu into shm_scratch: Masterminds carries a slider, `+`
 * on a track of `=`, the knob at `page`, its bar between the track's two. */
static void c_diag_menu_text(INT page)
{
    char *at;
    INT i;

    /* No title line: the three views, the slider a stop per page of Masterminds, Back.. last. */
    strcpy(shm_scratch, (str_addr) " Faces\n Photos\n Masterminds [");
    at = (char *) shm_scratch + strlen(shm_scratch);
    for (i = 0; i < DIAG_MM_PAGES; i++)
        *at++ = (char) (i == page ? '+' : '=');
    *at = 0;
    strcat((str_addr) shm_scratch, (str_addr) "]\n Back..\n");
}

/* The faces page: a view and the menu centred over it, Faces first. Picking
 * Faces or Photos rolls that view again; Masterminds shows the slider's page,
 * and picking it again moves it right, wrapping. Back.. or Escape leaves.
 *
 * With EXTRA_MENU_OPTIONS, Left and Right move the slider without the wrap. */
static void c_diag_faces_page(void)
{
    INT view;
    INT page;
    INT choice;
    INT x;
    INT j;

    /* Keep row 0 as it ships, which the MasterMind-like rolls overwrite. */
    for (j = 0; j < 8; j++)
        diag_saved_row[j] = dat_org_table[0][j];
    /* The short names, and the palette the faces are drawn in. */
    c_diag_short_names();
    drv_jump_gfx_set_palette(&dat_palette_badge);
    /* Centre the menu on its widest line, which is the slider's. */
    strcpy(shm_scratch, (str_addr) " Masterminds [+==]");
    x = (320 - c_text_width((rt_addr) shm_scratch) - 8) / 2;
    /* Open on Faces, the slider at the first page. */
    page = 0;
    view = DIAG_VIEW_FACES;
    c_diag_draw_faces();
    do {
        /* Ask, the bar on the view showing. */
        c_diag_menu_text(page);
        shm_menu_pick = view;
#ifdef EXTRA_MENU_OPTIONS
        menu_sideways = DIAG_VIEW_MASTERMINDS + 1;
#endif
        choice = c_ask_menu((rt_addr) shm_scratch, x, 80);
        /* Move the slider: sideways, or by picking Masterminds while it shows. */
#ifdef EXTRA_MENU_OPTIONS
        if (menu_sideways == KEY_LEFT) {
            if (page > 0)
                page--;
        } else if (menu_sideways == KEY_RIGHT) {
            if (page < DIAG_MM_PAGES - 1)
                page++;
        } else
#endif
        if (choice == DIAG_VIEW_MASTERMINDS && view == DIAG_VIEW_MASTERMINDS)
            page = (page + 1) % DIAG_MM_PAGES;
#ifdef EXTRA_MENU_OPTIONS
        menu_sideways = 0;
#endif
        /* Redraw the view picked; Masterminds wants the shipped row 0 back first. */
        if (choice == DIAG_VIEW_FACES) {
            view = choice;
            c_diag_draw_faces();
        } else if (choice == DIAG_VIEW_PHOTOS) {
            view = choice;
            c_diag_draw_photos();
        } else if (choice == DIAG_VIEW_MASTERMINDS) {
            view = choice;
            for (j = 0; j < 8; j++)
                dat_org_table[0][j] = diag_saved_row[j];
            c_diag_draw_masterminds(page);
        }
    } while (choice >= 0 && choice <= DIAG_VIEW_MASTERMINDS);
    /* Leaving: the shipped row 0, the screen's colours and the title palette back. */
    for (j = 0; j < 8; j++)
        dat_org_table[0][j] = diag_saved_row[j];
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
    drv_jump_gfx_set_palette(&dat_palette_title);
}

/* The Diagnostics menu: a test an item and Back.. under them, the screen kept
 * on the map page and put back after. A test's own Back.. leaves for the main
 * menu, not for this one. */
static void c_diagnostics_menu(void)
{
    INT choice;

    /* Keep the main menu's screen, which the tests draw over. */
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
    /* Ask below the main menu, the bar on the first test. */
    strcpy(shm_scratch, (str_addr) "Diagnostics\n Faces Test\n Back..\n");
    shm_menu_pick = 0;
    choice = c_ask_menu((rt_addr) shm_scratch, 80, SUBMENU_Y);
    if (choice == 0)
        c_diag_faces_page();
    /* Put the main menu's screen back. */
    drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen, 0, 0);
}
#endif

/* The main menu's shipped entries, in the order dat_str_do_want_create_new lists them. */
enum main_menu_entry {
    MAIN_MENU_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    MAIN_MENU_CREATE_A_NEW_CHARACTER = 0,
    MAIN_MENU_LOAD_A_SAVED_GAME = 1,
    MAIN_MENU_PRACTICE_A_SKILL = 2,
    MAIN_MENU_REVIEW_HALL_OF_FAME = 3
};

