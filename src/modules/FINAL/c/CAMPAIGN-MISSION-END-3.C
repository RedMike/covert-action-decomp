/* CAMPAIGN-MISSION-END-3.C -- more of the module's own routines in CAMPAIGN-MISSION-END.C's unit, after shared/CAMPAIGN-MISSION-END-2.C. */
#include "FINAL.H"
#include "SPRITES.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "ARCHIVE.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "MENUS.H"
#include "SEQUENCE.H"
#include "LOADDISK.H"
#include "SCREEN.H"
#include "MAIN.H"
#include "CSTART.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "ORIENT.H"
#include "SAVELOAD.H"
#include "CASERUN.H"
#include "CMISEND.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* The portrait screen: the agent's picture and name, then every arrested
 * MasterMind's face stamped with a shadowed "arrested". Bit 1 of shm_options,
 * the agent's sex, picks the picture's half and the side the rest goes on.
 */
void c_portrait_screen(void)
{
    INT side;
    INT org;
    INT row;
    INT x;

    /* A sound cue, and the agents' picture with all but this agent's part painted over. */
    c_sound_command(2);
    side = shm_options & OPT_FEMALE ? 0 : 97;
    c_load_picture(dat_str_gender_pic_2, 1);
    drv_real_fill_rect(shd_map_page, side, 0, 223, 200, 5);
    drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen, 0, 0);
    /* The agent's full name, centred on their own part. */
    x = shm_options & OPT_FEMALE ? 260 : 56;
    c_draw_centred(dat_str_max_2, x, 86, 14);
    c_draw_centred(shm_campaign.player_name, x, 94, 14);
    c_draw_centred(dat_str_remington_2, x, 102, 14);
    /* Each arrested MasterMind's face dropped somewhere on the painted part, one by one. */
    for (org = 0; org < 26; org++) {
        if ((LONG_LIT(1) << org) & (LONG) shm_campaign.masterminds_arrested) {
            x = c_random_below(164) + 4;
            row = c_random_below(140) + 4;
            c_draw_mastermind_face_panel(org, x + side, row, 0, 0);
            /* "Arrested" across it, over a shadow one pixel off. */
            c_write_text_trimmed(dat_str_arrested_4, x + side + 1, row + 24, 0);
            c_write_text_trimmed(dat_str_arrested_5, x + side, row + 23, 12);
            c_wait_retraces(30);
        }
    }
    /* A pause, then the caller's career-end message, put on the painted part. */
    c_wait_retraces(120);
    c_ask_menu((rt_addr) shm_scratch, side + 24, 64);
    c_sound_command(1);
}

/* The interlude between cases: a paragraph of downtime when `on`, then row
 * `scene` of dat_interlude_table, built up a picture at a time from files
 * named by the place's prefix. `on` is a long, as its sites push it; `unused`
 * is never read.
 */
void c_interlude(INT scene, LONG on)
{
    INT unused;
    INT kind;
    INT i;
    INT j;

    /* The scene's place: the LaundroMat, the secretarial pool, the beach or the Casino. */
    kind = dat_interlude_table[scene].place;
    /* Asked for, a blank screen and the place's own paragraph leading into the scene. */
    if ((INT) on) {
        drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 0);
        switch (kind) {
        case 0:
            strcpy(shm_scratch, dat_str_after_difficult_few);
            break;
        case 1:
            strcpy(shm_scratch, dat_str_word_latest_case_seems);
            break;
        case 2:
            strcpy(shm_scratch, dat_str_after_successful_case);
            break;
        case 3:
            strcpy(shm_scratch, dat_str_re_feeling_invincible);
            break;
        }
        /* Shown without waiting for a choice, then held a moment. */
        c_wrap_message(24);
        shm_menu_draw_only = 1;
        c_menu_run((rt_addr) shm_scratch, 64, 80);
        c_wait_retraces(120);
    }
    /* The first two places' pictures are in final4.cat on disk 4, the rest in final3.cat on 3. */
    c_want_disk(kind <= 1 ? 4 : 3, LONG_LIT(1));
    c_archive_open(kind <= 1 ? dat_str_final4_cat : dat_str_final3_cat);
    /* The scene is composed on page 2 before it is shown. */
    asm_replay_page->page = 2;
    drv_jump_gfx_pool_alloc();
    /* The place's background... */
    strcpy(shm_scratch, (char *) dat_ending_names[kind]);
    strcat(shm_scratch, dat_str_back_pic);
    c_load_picture((rt_addr) shm_scratch, 2);
    asm_screen_sprite_a = drv_jump_gfx_grab(2, 0, 0, 320, 200);
    /* ...and the agent's hand in the foreground, a woman's or a man's. */
    strcpy(shm_scratch, (char *) dat_ending_names[kind]);
    strcat(shm_scratch, dat_str_hand);
    strcat(shm_scratch,
               (char *) (shm_options & OPT_FEMALE
                         ? dat_str_f_pic : dat_str_m_pic));
    c_load_picture((rt_addr) shm_scratch, 2);
    asm_scene_sprites[0] = drv_jump_gfx_grab(2, 0, 0, 320, 200);
    /* The place's own sound cue. */
    c_sound_command(kind + 40);
    /* In the first two places, two times in three, laudude1.pic as well. */
    asm_screen_sprite_c = 0;
    if (kind <= 1 && c_random_below(3)) {
        c_load_picture(dat_str_laudude1_pic, 2);
        asm_screen_sprite_c = drv_jump_gfx_grab(2, 0, 0, 320, 200);
    }
    /* Stack them back to front and show the empty scene. */
    drv_jump_gfx_sprite_put(asm_replay_page, 0, 0, asm_screen_sprite_a);
    if (asm_screen_sprite_c)
        drv_jump_gfx_sprite_put(asm_replay_page, 0, 0, asm_screen_sprite_c);
    drv_jump_gfx_sprite_put(asm_replay_page, 0, 0, asm_scene_sprites[0]);
    drv_jump_gfx_copy_rect(asm_replay_page, 0, 0, 320, 200, shd_screen, 0, 0);
    /* Then the company arrives one at a time: each of the row's four words not -1 is one more. */
    for (i = 1; i <= 4; i++) {
        if (dat_interlude_table[scene].company[i - 1] != -1) {
            /* The picture's name: the place, a dude or a babe, and the row's number for it. */
            strcpy(shm_scratch, (char *) dat_ending_names[kind]);
#ifdef FLEXIBLE_ORIENTATION
            /* Each partner follows the agent's orientation, rolled per partner
             * for Bisexual, a babe then taking the spot of the dude named. */
            {
                INT n;
                INT dude;

                n = dat_interlude_table[scene].company[i - 1];
                dude = c_orientation_partner();
                if (!dude && orientation == ORIENTATION_BISEXUAL)
                    n = c_orientation_babe(kind, n);
                strcat(shm_scratch,
                           (char *) (dude ? dat_str_dude : dat_str_babe));
                strcat(shm_scratch,
                           (char *) itoa(n, asm_number_digits_4, 10));
            }
#else
            /* A woman agent's company is a dude, a man's a babe. */
            strcat(shm_scratch,
                       (char *) (shm_options & OPT_FEMALE
                                 ? dat_str_dude : dat_str_babe));
            strcat(shm_scratch,
                       (char *) itoa(dat_interlude_table[scene].company[i - 1],
                                     asm_number_digits_4, 10));
#endif
            strcat(shm_scratch, dat_str_pic);
            c_load_picture((rt_addr) shm_scratch, 2);
            asm_scene_sprites[i]
                = drv_jump_gfx_grab(2, 0, 0, 320, 200);
            /* Recompose: background, everyone so far, the hand on top; then dissolve it in. */
            drv_jump_gfx_sprite_put(asm_replay_page, 0, 0, asm_screen_sprite_a);
            for (j = 1; j <= i; j++)
                drv_jump_gfx_sprite_put(asm_replay_page, 0, 0,
                                  asm_scene_sprites[j]);
            drv_jump_gfx_sprite_put(asm_replay_page, 0, 0, asm_scene_sprites[0]);
            drv_jump_gfx_dissolve(2);
            drv_jump_gfx_copy_rect(asm_replay_page, 0, 0, 320, 200, shd_screen, 0, 0);
            drv_jump_gfx_show_page(0);
        }
    }
    /* Done: give back the picture memory and the archive. */
    drv_jump_gfx_pool_release();
    c_archive_close();
    _dos_freemem(asm_screen_sprite_a);
}
