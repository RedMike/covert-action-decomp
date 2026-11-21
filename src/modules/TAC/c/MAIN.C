/* MAIN.C -- the entry point: setting up, running and ending a break-in.
 */
#include "TAC.H"
#include "BLIP.H"
#include "KEYSHIFT.H"
#include "LOADDISK.H"
#include "RANDOM.H"
#include "PAGESHOW.H"
#include "CITY.H"
#include "MENU.H"
#include "CASE.H"
#include "NOTHING.H"
#include "TILES.H"
#include "ANI_LD2.H"
#include "PLANT.H"
#include "REVEAL.H"
#include "TURN.H"
#include "MODOPTS.H"
#include "RESULT.H"
#include "ALERTLVL.H"

/* Set the break-in up, run it, and write the result back to the shared block.
 * The block's first byte says which of the four kinds of mission this is,
 * which decides how many guards there are and which pictures are loaded.
 *
 * The rooms the player has explored are read in and written back out, so
 * what was learnt here survives into the campaign.
 */
INT c_main(void)
{
    INT i;
    INT room;

#ifdef COVERT_MENU_OPTIONS
    /* Read the mod options FINAL saved. */
    c_mod_options_load();
#endif
    /* Which mission this is, from the module the game asked for: escaping
     * capture, a jailbreak, an ambush, or else a break-in, as practice is. */
    if (COMM()->next_module == TAC_CAPTURE_ESCAPE)
        asm_mission_kind = 1;
    if (COMM()->next_module == TAC_JAILBREAK)
        asm_mission_kind = 2;
    if (COMM()->next_module == TAC_FIGHT_AMBUSHED)
        asm_mission_kind = 3;
    if ((shm_options & OPT_PRACTICE) != 0)
        asm_mission_kind = 0;
    /* The request is used up. */
    COMM()->next_module = NONE_EXIT;
    c_save_get(dat_str_env_sve);
    /* The speed the player last chose. */
    asm_game_speed = (shm_skills >> 8) & 3;
    /* This mission's difficulty: the game's, less the low two bits of the
     * skill word, plus one; the game's own is kept to work from. */
    shm_difficulty = (asm_difficulty_was = shm_difficulty)
                        - (shm_skills & 3) + 1;
    /* A jailbreak is one harder. */
    if (asm_mission_kind == 2)
        shm_difficulty++;
    /* A break-in faces the organisation's alert. */
    if (asm_mission_kind == 0)
        asm_org_alert_level = COMM()->org_alert_level;
    /* An alert organisation can add one more, and the easiest game level
     * keeps the easiest mission. */
    if (asm_difficulty_was != 0)
        shm_difficulty += c_clamp(
            asm_org_alert_level * asm_difficulty_was / 50, 0, 1);
    else
        shm_difficulty = 0;
    shm_difficulty = c_clamp(shm_difficulty, 0, 4);
    /* On a break-in, the suspect of the case's organisation in the case's
     * city, or -1 for none. */
    asm_suspect_here = 0xffff;
    if (asm_mission_kind == 0)
        for (i = 0; i < shm_suspect_count; i++)
            if (shm_suspects[i].org
                    == shm_case_org
                && shm_suspects[i].city
                    == shm_case_city)
                asm_suspect_here = i;
    /* One out of play is not here, unless turned double agent. */
    if (shm_suspects[asm_suspect_here].alert_level < 0
        && shm_suspects[asm_suspect_here].alert_level != ALERT_TURNED)
        asm_suspect_here = 0xffff;
    /* A jailbreak is about the prisoner the game names. */
    if (asm_mission_kind == 2)
        asm_suspect_here = (char) COMM()->result[RES_TAC_TARGET];
    /* The hour of the day, and whether it is night, 8 p.m. to 8 a.m. */
    asm_hour = (unsigned) shm_clock_minutes / 60 % 24;
    asm_night = asm_hour < 8 || asm_hour >= 20;
    asm_film_left = 1;
    /* How many guards the mission brings on, by its kind and difficulty. */
    asm_guards_to_come = shm_difficulty * 4 + 8;
    if (asm_mission_kind == 2)
        asm_guards_to_come = asm_difficulty_was * 2 + 4;
    if (asm_mission_kind == 3)
        asm_guards_to_come = asm_difficulty_was * 2 + 2;
    if (asm_mission_kind == 1)
        asm_guards_to_come = 3 * shm_difficulty + 3;
    /* Make the loaded drivers callable. */
    drv_real_link_slots(COMM()->driver_segment[0]);
    drv_real_link_slots(COMM()->driver_segment[1]);
    drv_real_link_slots(COMM()->driver_segment[2]);
    /* Seed from the case's city and organisation, so the same building is
     * laid out the same way on every visit. */
    srand((unsigned) (shm_case_city + 13)
              * (unsigned) (shm_case_org + 7) * 23
              + (shm_case_seed & 0x3fff));
    /* Set up the screen: page 3, the font, the pens and the palette. */
    drv_jump_gfx_set_page_seg(3, asm_page_3 = drv_jump_gfx_page_seg(3));
    shd_screen->font = 1;
    shd_screen->bg_pen = 15;
    c_set_palette_record(0);
    /* Cut the radar and the readout out of camera.pic. */
    drv_jump_gfx_pool_alloc();
    c_load_picture(dat_str_camera_pic, 2);
    asm_radar_sprite = drv_jump_gfx_grab(2, 0, 0, 196, 112);
    asm_readout_sprite = drv_jump_gfx_grab(2, 200, 0, 72, 61);
    drv_jump_gfx_pool_release();
    c_load_tiles();
    /* Load the people's sheet, guys2.pic for an ambush and guys3.pic otherwise,
     * keeping the status strip's 40 rows safe on the map page meanwhile. */
    drv_jump_gfx_copy_rect(asm_status_page, 0, 160, 320, 40, shd_map_page, 0, 160);
    if (asm_mission_kind != 3)
        c_load_picture(dat_str_guys3_pic, 2);
    else
        c_load_picture(dat_str_guys2_pic, 2);
    drv_jump_gfx_copy_rect(shd_map_page, 0, 160, 320, 40, asm_status_page, 0, 160);
    /* Lay out the building, then reseed from the clock for the run itself
     * and pick the password. */
    c_lay_out_building();
    c_seed_random();
    c_pick_password();
    /* Practice, suspect 0, or a double agent in this city's CIA office set
     * asm_high_security. */
    if ((shm_options & OPT_PRACTICE) != 0 || asm_suspect_here == 0
        || (shm_double_agent_cities & (1 << (char) shm_case_city)) != 0)
        asm_high_security = 1;
    /* Suspect 0 makes the mission one harder, up to the hardest. */
    if (asm_suspect_here == 0 && shm_difficulty < 4)
        shm_difficulty++;
    /* With asm_high_security set, two more guards a level. */
    if (asm_high_security != 0)
        asm_guards_to_come += shm_difficulty * 2;
    /* Mark the rooms explored on earlier visits to this building. */
    room = c_building_explore(shm_case_org, shm_case_city, 0);
    if (room != -1)
        for (i = 0; i <= asm_room_count; i++)
            if ((shm_buildings[room].tac_rooms_explored
                 & (UNSIGNED_LONG) 1 << i) != 0)
                asm_rooms[i].flags |= 2;
    /* The kit screen's backdrop for the player's gender, shown at once on a
     * break-in, the one mission whose kit is chosen. */
    if ((shm_options & OPT_FEMALE) != 0)
        c_load_picture(dat_str_equip1_pic, 1);
    else
        c_load_picture(dat_str_equip1m_pic, 1);
    if (asm_mission_kind == 0)
        drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen, 0, 0);
    /* Kit the player out and put him in the building. */
    c_wait_for_release();
    c_place_player();
    drv_jump_gfx_set_colour_map(&dat_colours_tactical, &dat_colours_tactical);
    NUM_LOCK_ON();
    /* The shipped code means INT 16h's key-repeat call but makes it of INT
     * 10h, so repeat is never set; FIX_TAC_MOVE makes it, at 30 a second. */
#ifdef FIX_TAC_MOVE
    if (MOD_ON(fast_tac_move)) {
        /* Set typematic: a quarter-second delay, then 30 a second. */
        asm_regs.x.ax = 0x0305;
        asm_regs.x.bx = 0;
        INTERRUPT(0x16, &asm_regs, &asm_regs);
    } else
#endif
    {
        /* Meant as a quarter-second delay and 15 a second. */
        asm_regs.h.ah = 3;
        asm_regs.h.al = 5;
        asm_regs.h.bh = 0;
        asm_regs.h.bl = 8;
        INTERRUPT(0x10, &asm_regs, &asm_regs);
    }
    /* Play until the run ends: a turn, then the effects, each followed by a
     * wait of 6, 4 or 2 retraces by the speed chosen. */
    do {
        c_tick();
        c_wait_retraces(asm_game_speed != 0
                           ? (asm_game_speed == 1 ? 4 : 2) : 6);
        c_step_effects(LONG_LIT(0));
        c_wait_retraces(asm_game_speed != 0
                           ? (asm_game_speed == 1 ? 4 : 2) : 6);
    } while (shm_finished == 0);
    NUM_LOCK_OFF();
    c_end_break_in();
    /* Back to FINAL after practice, to the campaign otherwise. */
    COMM()->next_module = (shm_options & OPT_PRACTICE) != 0
        ? FINAL_PRACTICE_OVER : GAME_CAMPAIGN;
    /* Hand back how it ended, the organisation's alert, what was achieved,
     * the wounds, whether an arrest may reveal the role, and the time taken. */
    COMM()->result[RES_TAC_END_LINE] = asm_end_line;
    COMM()->result[RES_TAC_ALERT] = asm_seen_count != 0
              ? c_clamp(10 * asm_seen_count + 20, 0,
                                   10 * asm_guards_to_come)
              : 0;
    COMM()->result[RES_TAC_OUTCOME] = asm_outcome;
    COMM()->result[RES_TAC_WOUNDS] = asm_wounds;
    COMM()->result[RES_ROLE_HIDDEN] = (asm_outcome & 4) == 0;
    COMM()->result[RES_MINUTES] = asm_frame_tick / 60;
    /* Keep the speed for next time. */
    shm_skills = (shm_skills & 0xfcff)
                        | (asm_game_speed << 8);
    /* Remember the rooms explored this time. */
    room = c_building_explore(shm_case_org, shm_case_city, 0);
    if (room != -1)
        for (i = 0; i <= asm_room_count; i++)
            if ((asm_rooms[i].flags & 2) != 0)
                shm_buildings[room].tac_rooms_explored
                    |= (UNSIGNED_LONG) 1 << i;
    /* Save, quieten the sound, give the keyboard back and free the page. */
    c_save_put(dat_str_env_sve_2);
    c_sound_command(0);
    c_hook_hand_back(LONG_LIT(0));
    drv_jump_gfx_free_page(3);
    /* Ask for the disk the next module is on. */
    return c_want_disk((shm_options & OPT_PRACTICE) != 0 ? 1 : 2,
                              (LONG) 1);
}
