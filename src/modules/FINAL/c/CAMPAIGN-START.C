/* CAMPAIGN-START.C -- creating a character, picking a mission and briefing it.
 */
#include "FINAL.H"
#include "SPRITES.H"
#include "KEYCODES.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "SCREEN.H"
#include "CMISEND.H"
#include "CMISSTRT.H"
#include "SAVELOAD.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "CSTART.H"
#include "ORIENT.H"

/* Open a new campaign: clear the score, the cases, the career record and the
 * sets played, set the best rank to 99, then ask the player's gender, code
 * name and difficulty and run the training screen.
 */
void c_campaign_start(void)
{
    /* A new career: no score, no cases, an empty record, no MasterMind caught, the worst rank. */
    shm_campaign.score = 0;
    shm_campaign.cases = 0;
    shm_campaign.record[0] = 0xff;
    shm_campaign.masterminds_arrested = 0;
    shm_campaign.best_rank = 99;
    /* Put up the gender picture and ask whether the agent is Maximillian or Maxine. */
    c_load_picture(dat_str_gender_pic, 1);
    drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen,
                           0, 0);
    strcpy(shm_scratch, dat_str_select_one_maximillian);
    if (c_ask_menu((rt_addr) shm_scratch, 96, 33) == 1)
        shm_options |= OPT_FEMALE;
#ifdef FLEXIBLE_ORIENTATION
    /* The optional build also asks the agent's orientation. */
    c_orientation_menu();
#endif
    /* Then the code name, the difficulty, kept to the four levels, and the training. */
    c_code_name_screen();
    strcpy(shm_scratch, dat_str_which_difficulty_level);
    shm_difficulty = c_clamp(
        c_ask_menu((rt_addr) shm_scratch, 96, 129),
        0, 3);
    c_training_screen(LONG_LIT(0));
}

/* Start a mission set: set 0 for a first case at the lowest difficulty, else
 * any but the last one; then a mastermind organisation still at large that
 * suits the set, and the set's opening briefing read out of plot.txt. The
 * casts keep the code as shipped.
 */
void c_set_start(void)
{
    INT last;
    INT i;
    INT n;

    /* A blank screen, the menu cursor home, and sixteen draws to stir the random numbers. */
    drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 5);
    shm_menu_pick = 0;
    for (i = 0; i < 16; i++)
        c_random_below(4095);
    /* Any set but 0 and the last one played; only a first case at the lowest difficulty gets 0. */
    if (shm_difficulty != 0 || shm_campaign.cases != 0) {
        last = shm_campaign.mission_set;
        do {
            shm_campaign.mission_set = c_random_below(15) + 1;
        } while (last == shm_campaign.mission_set);
    } else {
        shm_campaign.mission_set = 0;
    }

    /* Draw a world and a MasterMind until one fits the set. */
    for (;;) {
        n = 0;
        do {
            /* Every eighth draw tries another of the three worlds. */
            if ((n & 7) == 0) {
                shm_campaign.world = c_random_below(3);
                c_read_world(shm_campaign.world);
            }
            /* A fresh set: no missions done, and the MasterMind's organisation and city. */
            shm_campaign.mastermind_flags = shm_campaign.missions_done = 0;
            shm_campaign.mastermind_org = c_random_below(12) + 4;
            shm_campaign.mastermind_city = c_random_below(16);
            shm_campaign.mission_step = -1;
            n++;
            /* Redraw one whose MasterMind is caught, for 999 draws, or one known as -1, always. */
        } while ((n < 999
                  && ((LONG_LIT(1) << *(unsigned char *) &shm_orgs[shm_campaign.mastermind_org].known)
                      & (LONG) shm_campaign.masterminds_arrested) != 0)
                 || shm_orgs[shm_campaign.mastermind_org].known == -1);
        /* The MasterMind's looks and its number among the 26, out of the organisation's record. */
        shm_campaign.mastermind_visuals = c_pack_org(
            *(unsigned char *) &shm_orgs[shm_campaign.mastermind_org].known);
        shm_campaign.mastermind_org_known = *(UNSIGNED_INT *) &shm_orgs[shm_campaign.mastermind_org].known & 0xff;
        /* Keep it only if its known word shares a bit with the set's field_18 mask. */
        if (*(UNSIGNED_INT *) &shm_orgs[shm_campaign.mastermind_org].known
            & dat_mission_sets[shm_campaign.mission_set].field_18)
            break;
    }

    /* The set's opening briefing is plot.txt's *PL<set>9<n>, paragraphs n from 0. */
    strcpy(asm_plot_key, dat_key_plot_start);
    asm_plot_key[3] = shm_campaign.mission_set / 10 + '0';
    asm_plot_key[4] = shm_campaign.mission_set % 10 + '0';
    /* Over the briefing animation, show it in the message panel a paragraph at a time. */
    c_seq_set_var(0, 4);
    drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
    c_pan_arm(dat_str_briefing_pan, 0, 0);
    do {
        shm_scratch[0] = 0;
        n = c_say_block(dat_str_plot_txt, asm_plot_key);
        if (n) {
            c_wrap_message(40);
            c_ask_menu((rt_addr) shm_scratch, 8, 149);
            c_clear_message_panel();
        }
        asm_plot_key[6]++;
    } while (n);
    /* The set has been briefed, so this run's mission pick skips its own briefing. */
    asm_set_first = 1;
}

/* Pick the next mission of the current set and brief the player on it. A slot
 * is taken if undone, filled, not the last one picked (for 99 draws) and, for
 * the set's last mission, every slot below is done; 999 failures start a set.
 * `step == 7` is dead, the draw being 0..5.
 */
void c_mission_pick(void)
{
    INT counter;
    INT mset;
    INT step;
    INT avail;
    INT prereq;

#ifdef FLEXIBLE_ORIENTATION
    /* The optional build settles this mission's pairing for the agent's orientation. */
    c_orientation_roll();
#endif
    mset = shm_campaign.mission_set;
    for (;;) {
        counter = 0;
        do {
            /* Draw a slot; it will do if not yet played and the set fills it. */
            step = c_random_below(6);
            avail = ((shm_campaign.missions_done & 1 << step) != 0
                     || dat_mission_sets[mset].mission[step] == -1)
                    ? 0 : 1;
            /* The set's last mission waits until every one before it is done. */
            if (dat_mission_sets[mset].mission[step + 1] == -1) {
                prereq = 0xff >> (8 - step);
                if ((prereq & shm_campaign.missions_done) != prereq)
                    avail = 0;
            }
            /* Avoid repeating the last mission while there are draws to spare. */
            if (step == shm_campaign.mission_step && ++counter < 99)
                avail = 0;
        } while (!avail && ++counter < 999);
        if (counter < 999) {
            /* Take the slot: its mission type and the two nouns the briefing is written around. */
            shm_campaign.mission_step = step;
            shm_campaign.mission = dat_mission_sets[mset].mission[step];
            if (step < 7) {
                strcpy(shm_campaign.text[0], dat_mission_sets[mset].text[step][0]);
                strcpy(shm_campaign.text[1], dat_mission_sets[mset].text[step][1]);
            } else {
                /* Dead, the draw never reaching slot 7. */
                strcpy(shm_campaign.text[0], dat_str_max_remington_s);
                strcpy(shm_campaign.text[1], dat_str_mattress_full_cash);
            }
            /* Briefing *PL<set><slot>A on once slots 0 and 1 are done or in play, else a on. */
            strcpy(asm_plot_key, (((1 << step) & 3) | shm_campaign.missions_done) == 3
                                ? dat_str_pl000a : dat_str_pl000a_2);
            asm_plot_key[3] = shm_campaign.mission_set / 10 + '0';
            asm_plot_key[4] = shm_campaign.mission_set % 10 + '0';
            asm_plot_key[5] = step + '0';
            /* Brief it a paragraph at a time, unless the set's own briefing just played. */
            if (asm_set_first == 0 || step == 7) {
                c_seq_set_var(0, 4);
                drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
                c_pan_arm(dat_str_briefing_pan_2, 0, 0);
                do {
                    shm_scratch[0] = 0;
                    avail = c_say_block(dat_str_plot_txt_2, asm_plot_key);
                    if (avail) {
                        c_wrap_message(40);
                        c_ask_menu((rt_addr) shm_scratch,
                                           8, 149);
                        c_clear_message_panel();
                    }
                    asm_plot_key[6]++;
                } while (avail);
            }
            break;
        }
        /* No slot would do in 999 draws: start a new set and pick again. */
        c_set_start();
    }
    /* The case starts with an empty log, clocks at zero, no buildings, no organisation known. */
    shm_log_count = shm_clock_minutes = shm_case_tick
        = shm_building_count = asm_dossier_seen = asm_shown_count
        = shm_orgs_known = 0;
}

/* The code-name screen: a bevelled panel with the prompt and a text field,
 * whose typed name becomes the player's code name. &dat_colours_badge goes in
 * as both colour-map arguments.
 */
void c_code_name_screen(void)
{
    /* The bevelled panel and the sunken box the name is typed into. */
    drv_jump_gfx_set_colour_map(&dat_colours_badge, &dat_colours_badge);
    c_fill_box(99, 85, 221, 114, 8);
    c_fill_box(100, 87, 220, 113, 5);
    c_fill_box(101, 88, 219, 112, 8);
    c_fill_box(105, 101, 215, 110, 5);
    c_draw_line(101, 86, 219, 86, 7);
    c_draw_line(103, 99, 217, 99, 5);
    c_draw_line(102, 112, 218, 112, 5);
    c_draw_line(104, 101, 104, 110, 7);
    c_draw_line(216, 101, 216, 110, 7);
    /* Ask for the code name, starting from an empty field of fifteen characters. */
    c_draw_centred(dat_str_max_s_code_name, 161, 90, 2);
    shm_scratch[0] = 0;
    c_text_field(106, 100, 15);
    strcpy(shm_campaign.player_name, shm_scratch);
    /* Back to the screen's own background and colours. */
    shd_screen->bg_pen = 5;
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
}

/* Ask the difficulty into shm_difficulty, then which skill to practise; answer
 * that skill, or -1.
 */
INT c_difficulty_menu(void)
{
    /* Practice is at a chosen difficulty, taken unclamped. */
    strcpy(shm_scratch, dat_str_which_difficulty_level_2);
    shm_difficulty = c_ask_menu((rt_addr) shm_scratch,
                                           80, 128);
    /* Then the training screen only asks which skill. */
    return (c_training_screen(LONG_LIT(1)));
}

/* The training screen: spend four grades across the four skills until they run
 * out or the player leaves, then pack them into shm_skills. With `practice`
 * set it only asks which skill to practise and answers it, or -1. `practice`
 * is a long, as its sites push it.
 */
INT c_training_screen(LONG practice)
{
    INT used;
    INT x;
    INT i;
    INT j;
    INT choice;
    INT skill[4];

    /* `x` and `j` are set and never read. */
    x = 40;
    j = 100;
    used = 0;
    /* Put up the training picture. */
    c_load_picture(dat_str_training_pic, 1);
    drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen,
                           0, 0);
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);

    /* Every skill starts at Average. */
    i = 0;
    do {
        skill[i] = 0;
        i++;
    } while (i < 4);

    shm_menu_pick = 0;
    do {
        /* Training shows the grades so far; practice has none to show. */
        shd_screen->bg_pen = 5;
        if ((INT) practice == 0)
            c_skill_rows(skill);
        /* A menu of the four skills, each worded for training or for practice. */
        strcpy(shm_scratch, dat_str_blank);
        for (i = 0; i < 4; i++) {
            strcat(shm_scratch,
                       dat_skill_names[i]);
            strcat(shm_scratch,
                       (INT) practice ? dat_str_practice : dat_str_training);
        }
        choice = c_ask_menu((rt_addr) shm_scratch,
                                    92, 25);
        shm_menu_pick = choice;
        /* Practice wants only the skill picked. */
        if ((INT) practice) {
            shm_menu_pick = 0;
            return (choice);
        }
        /* A grade spent raises that skill, up to Awesome. */
        if (choice != -1 && skill[choice] != 3) {
            used++;
            skill[choice]++;
        }
    } while (choice != -1 && used != 4);

    /* Grades left unspent raise the first skills one each, lost on any already Awesome. */
        /* `i` stays one past the last skill raised. */
    for (i = 0; i < 4 - used; i++)
        if (skill[i] < 3)
            skill[i]++;
    c_skill_rows(skill);
    /* After the rows are shown, the skill at `i` drops from Excellent to Good. */
    if (skill[i] == 2)
        skill[i] = 1;

    /* Pack the four grades, two bits each, into the skills word. */
    i = 0;
    do {
        shm_skills += skill[i] << (i * 2);
        i++;
    } while (i < 4);
    c_wait_retraces(60);
    /* The lowest difficulty overrides the training: every skill Good. */
    if (shm_difficulty == 0)
        shm_skills = 0x55;
    /* The two fields above the trained four get bit 0 set, level 1 as the 0x555 reset has. */
    *((unsigned char *) &shm_skills + 1) |= 5;
    return;
}

/* The training screen's four skill rows: a coloured bar with the grade's name
 * on it, from `skill`, four levels 0 to 3. Any other level draws the bar under
 * whatever text the buffer held.
 */
void c_skill_rows(INT *skill)
{
    INT i;

    /* On CGA the last skill's bar takes colour 0 instead. */
    if (shm_cga != 0)
        dat_skill_colours[3] = 0;
    for (i = 0; i < 4; i++) {
        /* The grade's name. */
        switch (skill[i]) {
        case 0:
            strcpy(shm_scratch, dat_str_average);
            break;
        case 1:
            strcpy(shm_scratch, dat_str_good);
            break;
        case 2:
            strcpy(shm_scratch, dat_str_excellent);
            break;
        case 3:
            strcpy(shm_scratch, dat_str_awesome);
            break;
        }
        /* The skill's bar along the bottom of the screen, with the name centred on it. */
        drv_real_fill_rect(shd_screen, i * 80 + 8, 188, 64, 8,
                          dat_skill_colours[i]);
        c_draw_centred(shm_scratch, i * 80 + 40,
                           188, shm_cga ? 15 : 14);
    }
}

/* Read a line into shm_scratch in a field `n` characters wide at (x, y), until
 * Enter. The opening text is blanked only when the first key is printable, and
 * Delete also blanks the character it pulls under the cursor.
 */
void c_text_field(INT x, UNSIGNED_INT y, INT n)
{
    char tmp[64];
    INT first;
    INT i;
    INT ch;

    /* Clear the field and pad the opening text with spaces to its full width. */
    drv_real_fill_rect(shd_screen, x, y + 1, n * 7, 9, 5);
    shd_screen->bg_pen = 5;
    shm_field_cursor = 0;
    first = 1;
    for (i = strlen(shm_scratch); i < n; i++)
        (shm_scratch)[i] = ' ';
    (shm_scratch)[n] = 0;

    c_text_field_draw(x, y, n);
    for (;;) {
        /* Blink the cursor until a key comes. */
        while (drv_jump_keyboard_empty()) {
            drv_jump_gfx_fill(shd_screen, shm_field_cursor_x, (INT) y + 1,
                              shm_field_char_width, 10, 5, 2);
            c_wait_retraces(10);
            drv_jump_gfx_fill(shd_screen, shm_field_cursor_x, (INT) y + 1,
                              shm_field_char_width, 10, 2, 5);
            if (drv_jump_keyboard_empty())
                c_wait_retraces(10);
        }
        /* Enter finishes the line. */
        ch = c_menu_key();
        if (ch == KEY_ENTER) {
            i = n - 1;
            break;
        }
        /* The arrows move the cursor within the field. */
        if (ch == KEY_LEFT && shm_field_cursor != 0)
            shm_field_cursor--;
        if (ch == KEY_RIGHT && n - 1 > shm_field_cursor)
            shm_field_cursor++;
        /* Insert opens a space at the cursor, losing the last character. */
        if (ch == KEY_INS) {
            strcpy(tmp,
                       (shm_scratch + shm_field_cursor));
            strcpy((shm_scratch + shm_field_cursor + 1),
                       tmp);
            (shm_scratch)[shm_field_cursor] = ' ';
            (shm_scratch)[n] = 0;
        }
        /* Delete closes up over the cursor, blanking what slides under it
         * too. */
        if (ch == KEY_DEL) {
            strcpy((shm_scratch + shm_field_cursor),
                       (shm_scratch + shm_field_cursor + 1));
            (shm_scratch)[shm_field_cursor] = ' ';
            (shm_scratch)[n - 1] = ' ';
            (shm_scratch)[n] = 0;
        }
        /* Backspace removes the character before the cursor. */
        if (ch == KEY_BACKSPACE && shm_field_cursor != 0) {
            strcpy((shm_scratch + shm_field_cursor - 1),
                       (shm_scratch + shm_field_cursor));
            (shm_scratch)[n - 1] = ' ';
            (shm_scratch)[n] = 0;
            shm_field_cursor--;
        }
        /* A printable key overwrites at the cursor; typed first, it replaces the opening text. */
        if (ch < 0x80 && ch >= ' ') {
            if (first)
                for (i = 0; i < n; i++)
                    (shm_scratch)[i] = ' ';
            (shm_scratch)[shm_field_cursor] = ch;
            if (n - 1 > shm_field_cursor)
                shm_field_cursor++;
        }
        first = 0;
        c_text_field_draw(x, y, n);
    }
    /* Trim the trailing spaces, though never the first character. */
    for (; i > 0 && (shm_scratch)[i] == ' '; i--)
        (shm_scratch)[i] = 0;
}
