/* MAIN.C -- the car chase's entry point.
 *
 * The C defines no data: every datum lives in the assembly. MSC 5.1 places a
 * local by its name, so the locals' names stay.
 */
#include "CHASE.H"
#include "SETUP.H"
#include "SETUP1.H"
#include "RANDOM.H"
#include "FILEIO.H"
#include "MENU1.H"
#include "CARPICK.H"
#include "MAZE.H"
#include "CHASESTA.H"
#include "SIGHT.H"
#include "RETRACE.H"
#include "LOADDISK.H"
#include "RESULT.H"

/* Set the chase up from the shared block, run it a frame at a time until
 * shm_finished is set, then show the closing message and hand back. The
 * block's first byte says which situation this is on the way in, and which
 * module runs next on the way out.
 */
void c_main(void)
{
    INT gender;
    INT i;
    INT hour;

    /* Take the chase's settings and the case over from the game. */
    c_setup(108);
    /* Tailing a suspect and practice are one chase; an ambush turns it round. */
    switch ((char) COMM()->next_module) {
    case CHASE_SUSPECT:
    case CHASE_PRACTICE:
        asm_chase_kind = 0;
        break;
    case CHASE_UNUSED:
        asm_chase_kind = 1;
        break;
    case CHASE_AMBUSHED:
        asm_chase_kind = 2;
        break;
    }
    /* The suspect's sex, which the closing message calls them by. */
    gender = (char) COMM()->result[RES_CHASE_SEX];
    /* Until the chase decides, nothing runs next and the suspect's role stays hidden. */
    COMM()->next_module = NONE_EXIT;
    COMM()->result[RES_ROLE_HIDDEN] = 1;
    /* The speed the player last chose, kept above the four skill levels. */
    asm_game_speed = ((INT) shm_skills >> 10) & 3;
    /* A better driver faces an easier chase. */
    shm_difficulty = c_clamp(
        shm_difficulty - (((INT) shm_skills >> 2) & 3) + 1, 0, 3);
    /* An alert organisation's suspect is quicker to notice a tail. */
    asm_org_alert_level = COMM()->org_alert_level;
    /* Between eight in the evening and eight in the morning the chase is at night. */
    hour = shm_clock_minutes / 60 % 24;
    asm_night = (hour < 8 || hour >= 20) ? 1 : 0;
    /* CGA gets colours of its own. */
    shm_graphics_letter = COMM_LETTER_BYTE;
    shm_cga = shm_graphics_letter == 'C';
    /* Reach the drivers COVERT loaded. */
    drv_real_link_slots(COMM()->driver_segment[0]);
    drv_real_link_slots(COMM()->driver_segment[1]);
    drv_real_link_slots(COMM()->driver_segment[2]);
    /* Borrow the spare page to unpack the car pictures into. */
    asm_page_3 = drv_jump_gfx_page_seg(3);
    drv_jump_gfx_set_page_seg(3, asm_page_3);
    shd_screen->font = 1;
    shd_screen->bg_pen = 15;
    drv_jump_gfx_pool_alloc();
    c_decode_picture(3, dat_str_chase_pic);

    /* Cut out the suspect's car, seen from behind, at the sixteen distances the windscreen shows. */
    i = 0;
    do {
        asm_windscreen_car_sprites[i] = drv_jump_gfx_grab(
            3, dat_windscreen_car_rects[i][0], dat_windscreen_car_rects[i][1],
            dat_windscreen_car_rects[i][2] - dat_windscreen_car_rects[i][0] + 1,
            dat_windscreen_car_rects[i][3] - dat_windscreen_car_rects[i][1] + 1);
        i++;
    } while (i < 16);

    /* The street tiles the board and the dashboard are drawn from. */
    drv_jump_gfx_pool_release();
    c_decode_picture(2, dat_str_street_pic);
    /* A chase in a city is laid out on that city's own streets. */
    asm_fresh_board = 1;
    c_seed_random();
    drv_jump_gfx_set_palette(&dat_palette_chase);
    /* Tailing, the player picks the cars; ambushed, there is no time to. */
    if (asm_chase_kind != 2)
        c_pick_cars();
    /* Lay the city out and put the cars on it. */
    shd_screen->font = 2;
    c_hook_main();
    c_make_maze();
    c_chase_start();

    /* Run the chase a frame at a time, at the chosen speed, until it is over. */
    do {
        c_chase_step();
        asm_frame_tick++;
        c_wait_retraces(asm_game_speed == 1 ? 4
                           : asm_game_speed != 0 ? 0 : 8);
    } while (shm_finished == 0);
    /* Silence the engine. */
    c_sound_command(0);

    /* The suspect got away: lost in traffic, or they spotted the tail and fled. */
    if (asm_outcome == 0) {
        if (asm_chase_kind == 0) {
            if (shm_finished != 2) {
                strcpy(shm_scratch, dat_str_we_ve_totally_lost);
            } else {
                strcpy(shm_scratch, (gender & 1) ? dat_str_he : dat_str_she);
                strcat(shm_scratch, dat_str_turns_corner_dashes);
                strcat(shm_scratch, dat_str_we_ll_have_less);
            }
        }
        /* Ambushed, the player reached the safety of a building. */
        if (asm_chase_kind == 2)
            strcpy(shm_scratch, dat_str_dash_into_building);
    }
    /* The suspect was followed home, or the pursuers were run off the road. */
    if (asm_outcome == 1) {
        if (asm_chase_kind == 0) {
            strcpy(shm_scratch, (gender & 1) ? dat_str_he_2 : dat_str_she_2);
            strcat(shm_scratch, dat_str_pulls_over_walks_into);
        }
        if (asm_chase_kind == 2)
            strcpy(shm_scratch, dat_str_pursuers_run_off_road);
    }
    /* The suspect was run off the road and caught. */
    if (asm_outcome == 2) {
        strcpy(shm_scratch, dat_str_run);
        strcat(shm_scratch, (gender & 1) ? dat_str_his : dat_str_her);
        strcat(shm_scratch, dat_str_car_off_road_make);
    }

    /* Tell the player how it went. */
    drv_jump_gfx_set_palette(&dat_palette_default);
    shd_screen->font = 1;
    c_menu_run(shm_scratch, 100, 80);
    /* Report back: how it ended, how wary the suspect now is, and what runs next. */
    COMM()->result[RES_CHASE_OUTCOME] = asm_outcome;
    COMM()->result[RES_CHASE_ALERT] =
        c_clamp(25 * (INT) asm_suspect_alert, 0, 100);
    COMM()->next_module = (shm_options & OPT_PRACTICE) ? FINAL_PRACTICE_OVER : GAME_CAMPAIGN;
    COMM()->result[RES_ROLE_HIDDEN] = 1;
    /* How long the chase took, in minutes. */
    COMM()->result[RES_MINUTES] = asm_frame_tick / 60;
    /* Keep the chosen speed for next time. */
    shm_skills = (shm_skills & 0xf7ff) | (asm_game_speed << 10);
    COMM()->skills = shm_skills;
    /* Give back what the chase took, and ask for the disk the next module is on. */
    _dos_freemem(asm_windscreen_car_sprites[0]);
    c_hook_hand_back(LONG_LIT(0));
    drv_jump_gfx_free_page(3);
    c_want_disk((shm_options & OPT_PRACTICE) ? 1 : 2, LONG_LIT(1));
}
