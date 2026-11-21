/* STAKEOUT.C -- watching a building for someone to come out of it.
 */
#include "GAME.H"
#include "SPRITES.H"
#include "CASE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DECODE.H"
#include "DIALOG.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "ANI_PLAY.H"
#include "NOTICE.H"
#include "ORGPLAN.H"
#include "FACES.H"
#include "STAKEOUT.H"
#include "CAMPSTAT.H"
#include "RESULT.H"
#include "SUSPFLAG.H"

/* The stakeout menu's entries, in the order dat_str_do_wait_follow_car lists them. */
enum stakeout_menu_entry {
    STAKEOUT_MENU_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    STAKEOUT_MENU_WAIT = 0,
    STAKEOUT_MENU_FOLLOW_CAR = 1,
    STAKEOUT_MENU_TRACE_CAR = 2,
    STAKEOUT_MENU_CHECK_DATA = 3
};

/* Watch a building: pick the organisation whose man is likeliest to show, wait
 * for him, and offer to sit tight, follow the car or bug it. */
INT c_stakeout(INT org, INT city)
{
    INT v0j;    /* the man who comes out */
    INT v1k;    /* how likely this organisation is */
    INT v2m;    /* the likeliest so far */
    INT v3o;    /* the organisation being weighed */
    INT v4;     /* what the player chose */
    INT v5b;    /* the organisation being watched for */

    for (;;) {
        /* An hour or two of watching passes. */
        drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 5);
        c_campaign_tick(c_random_below(2) * 60 + 60);
        do {
            /* Which other organisation present in the city is likeliest to be visiting: lowest score wins. */
            v2m = 999;
            v5b = org;
            v3o = 1;
            do {
                if (c_presence(city, v3o) != 0) {
                    /* The nearer it is to the watched organisation the likelier, with chance; at org 0 chance alone. */
                    v1k = c_packed_distance(
                              shm_orgs[org].where,
                              shm_orgs[v3o].where)
                          + c_random_below(16);
                    if (org == 0)
                        v1k = c_random_below(16);
                    /* Less likely with no suspect of its own on file here who holds a role. */
                    v0j = c_evidence_unlock(v3o, city, 0, LONG_LIT(0));
                    if (v0j == -1
                        || shm_suspects[v0j].role == 0)
                        v1k += c_random_below(24);
                    /* Less likely where its building here is already known. */
                    if ((shm_cities[city].known_orgs
                         & 1 << v3o) != 0)
                        v1k += c_random_below(16);
                    if (v1k < v2m && v3o != org) {
                        v2m = v1k;
                        v5b = v3o;
                    }
                }
                v3o++;
            } while (v3o < 16);
            /* Two times in three the visitor comes out, else one of the building's own: face and city go on file. */
            if (c_random_below(3) != 0 || org == 0)
                v0j = c_evidence_unlock(v5b, city, SUSPECT_PHOTO | SUSPECT_CITY,
                                        LONG_LIT(0));
            else
                v0j = c_evidence_unlock(org, city, SUSPECT_PHOTO | SUSPECT_CITY,
                                        LONG_LIT(0));
        /* Never someone out of play, nor the mastermind. */
        } while (shm_suspects[v0j].alert_level < 0
                 || v0j == 0);
        /* The person through the binoculars, or a still of them without animation. */
        shm_menu_face_x = 26;
        shm_menu_face_y = 45;
        shm_menu_face = shm_suspects[v0j].visuals;
        drv_jump_gfx_set_colour_map(&dat_colours_stakeout, &dat_colours_stakeout);
        if (c_pan_arm(dat_str_binos3_pan, 150, 2) != 0)
            c_seq_set_var(0, (shm_suspects[v0j].visuals & 1) != 0 ? -1 : 1);
        else {
            drv_real_fill_rect(shd_screen, 168, 8, 144, 96, 1);
            c_draw_face(shm_menu_face, 224, 32);
            c_draw_sprite((shm_menu_face & 3) + SPRITE_BODIES_1, 214, 57);
        }
        /* "You notice someone leaving the building. Do you ..." */
        strcpy(shm_scratch, dat_str_notice_someone);
        strcat(shm_scratch, dat_str_leaving_building);
        strcat(shm_scratch, dat_str_do_wait_follow_car);
        v4 = c_ask_menu(shm_scratch, 2, 20);
        /* Escape ends the stakeout. */
        if (v4 == STAKEOUT_MENU_NO_CHOICE)
            return;
        switch (v4) {
        /* Let them go and keep watching; someone seen and nothing more is forgotten again. */
        case STAKEOUT_MENU_WAIT:
        case STAKEOUT_MENU_CHECK_DATA:
            if (shm_suspects[v0j].flags == (SUSPECT_PHOTO | SUSPECT_CITY))
                c_suspect_release(v0j);
            if (v4 == STAKEOUT_MENU_CHECK_DATA)
                c_data_menu();
            break;

        /* "He looks <mood>.", then hand the tail to CHASE. */
        case STAKEOUT_MENU_FOLLOW_CAR:
            if ((shm_suspects[v0j].visuals & 1) != 0)
                strcpy(shm_scratch, dat_str_he_looks);
            else
                strcpy(shm_scratch, dat_str_she_looks);
            c_org_mood(shm_suspects[v0j].org,
                            shm_suspects[v0j].city);
            strcat(shm_scratch, dat_str_nl_dot);
            shm_menu_draw_only = 1;
            c_ask_menu(shm_scratch, 20, 100);
            COMM()->result[RES_CHASE_SUSPECT] = v0j;
            COMM()->result[RES_CHASE_ORG] = shm_case_org;
            COMM()->result[RES_CHASE_SEX] =
                shm_suspects[v0j].visuals & 1;
            shm_finished = CHASE_SUSPECT;
            /* The visiting organisation is dealt with from here, even when one of the building's own came out. */
            shm_case_org = v5b;
            return;

        /* Plant a tracer on the car: its animation, then the car tracer. */
        case STAKEOUT_MENU_TRACE_CAR:
            drv_jump_gfx_set_colour_map(&dat_colours_stakeout_2, &dat_colours_stakeout_2);
            c_notice(dat_str_bugcar_pan, 0, 0);
            shm_finished = BUG_CAR_TRACER;
            shm_case_org = v5b;
            return;

        default:
            return;
        }
    }
}
