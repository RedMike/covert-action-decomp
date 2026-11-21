/* MAIN-5.C -- more of the module's own routines in MAIN.C's unit, after shared/MAIN-3.C. */
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

/* Playing one of the animations over the whole screen, the screen kept on the
 * map page first, and putting the title palette back afterwards. The name is
 * copied into the one buffer every play reads, and the background pen kept.
 */
void c_play_animation(rt_addr name, UNSIGNED_INT x, UNSIGNED_INT y)
{
    INT saved;

    /* Keep a copy of the whole screen on the map page before the animation draws. */
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page,
                           0, 0);
    /* Play it to its end, the screen's background pen kept across the play. */
    strcpy(dat_str_animation_pan, name);
    saved = shd_screen->bg_pen;
    c_seq_play(dat_str_animation_pan, -1, x, y);
    shd_screen->bg_pen = saved;
    /* Back to the title palette, with page 0 on show. */
    drv_jump_gfx_set_palette(&dat_palette_title);
    drv_jump_gfx_show_page(0);
}

/* Setting up practice at skill `mode` for the module that runs it: bit 5 of
 * the option word, the packed skills at 555h, a random organisation, city and
 * world, the opening blurb for mode 2, all of it saved to the shared block.
 */
void c_practice_setup(INT mode)
{
    /* The practice module for the skill: combat, driving, cryptography or electronics. */
    COMM()->next_module = mode + TAC_PRACTICE;
    COMM()->mission_started = 1;
    /* Flag practice rather than campaign, with every skill field at level 1, Good. */
    shm_options |= OPT_PRACTICE;
    shm_skills = 0x555;
    /* A random setting: organisation 4 to 15, any of the sixteen cities, any world. */
    shm_case_org = c_random_below(12) + 4;
    shm_case_city = c_random_below(16);
    c_read_world(c_random_below(3));
    /* Cryptography practice needs a message to decipher: the opening blurb. */
    if (mode == 2)
        c_opening_blurb();
    /* Hand it all over through the shared block's env.sve. */
    c_save_put(dat_str_env_sve_5);
}
