/* HALL-OF-FAME.C -- the roll of finished careers, its file and its screen.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "MENUS.H"
#include "LOADDISK.H"
#include "SCREEN.H"
#include "MAIN.H"
#include "CMISEND.H"
#include "CASERUN.H"

/* Empty the table by putting -1 in each record's score, which marks a vacant
 * place. The second local is unused.
 */
void c_fame_clear(void)
{
    INT entry;
    INT spare;

    /* All six places on the roll start vacant. */
    for (entry = 0; entry < 6; entry++)
        asm_fame[entry].score = -1;
}

/* Load fame.dta over the table, or leave it empty if there is no such file. */
void c_fame_load(void)
{
    INT fd;

    /* An empty roll unless a saved one is found. */
    c_fame_clear();
    /* With a readable fame.dta, take all six entries from it. */
    if ((INT) access(dat_str_fame_dta, 4) != -1) {
        fd = open(dat_str_fame_dta_2, 0x8102, 0x80);
        read(fd, (rt_addr) asm_fame, 264);
        close(fd);
    }
}

/* Write the table back, only over an existing writable fame.dta: there is no
 * create path, and the file does not ship, so a stock install never keeps a
 * roll.
 */
void c_fame_save(void)
{
    INT fd;

    /* Only where a writable fame.dta already exists, save all six entries over it. */
    if ((INT) access(dat_str_fame_dta_3, 2) != -1) {
        fd = open(dat_str_fame_dta_4, 0x8302, 0x80);
        write(fd, (rt_addr) asm_fame, 264);
        close(fd);
    }
}

/* Show the roll with entry `fresh` framed, or -1 when opened from the menu.
 * From the menu, '1' to '5' plays that career's interlude; with an entry
 * framed, C returns 1 to ask for a clear. Five rows are drawn: a sixth entry
 * just earned replaces the fifth.
 */
INT c_fame_screen(INT fresh)
{
    INT type;
    INT x;
    INT y;
    INT nth;
    INT choice;
    UNSIGNED_INT score;
    INT solved;
    INT shown[6];

    for (;;) {
        /* The page and its heading: COVERT ACTION over HALL OF FAME, ruled off. */
        c_page_frame(dat_str_hall_fame, 1);
        shd_screen->bg_pen = 15;
        c_draw_centred(dat_str_covert_action, 160, 16, 0);
        c_draw_centred(dat_str_hall_fame_2, 160, 24, 0);
        c_draw_line(80, 32, 240, 32, 14);
        y = 40;
        for (nth = 0; nth < 6; nth++) {
            /* Five rows: the sixth entry shows only when it is the one just earned, */
            if (nth != fresh && nth == 5)
                break;
            /* and then in place of the fifth. */
            if (fresh == 5 && nth == 4)
                continue;
            /* Each entry on its own panel, set in by a random few pixels. */
            x = c_random_below(8) + 12;
            c_text_panel(x - 8, y - 4);
            /* Keep the score, with the agent's sex in its top bit, for picking the entry by key. */
            shown[nth] = asm_fame[nth].score;
            if (asm_fame[nth].difficulty & 0x80)
                *((unsigned char *) &shown[nth] + 1) |= 0x80;
            /* A vacant place is a row of dashes. */
            if (asm_fame[nth].score == -1) {
                strcpy(shm_scratch, dat_str_dashes_2);
                c_write_text((rt_addr) shm_scratch, x, y, 0);
                y += 26;
                continue;
            }
            /* First line: the place, the agent's name, and the case number with its month and year. */
            shm_scratch[0] = 0;
            strcat(shm_scratch,
                       (char *) itoa(nth + 1, asm_number_digits_5, 10));
            strcat(shm_scratch, dat_str_stop);
            strcat(shm_scratch, dat_str_max_3);
            strcat(shm_scratch, asm_fame[nth].name);
            strcat(shm_scratch, dat_str_remington_case);
            solved = asm_fame[nth].cases;
            strcat(shm_scratch,
                       (char *) itoa(solved + 1, asm_number_digits_5, 10));
            strcat(shm_scratch, dat_str_space_4);
            strcat(shm_scratch,
                       (char *) shd_month_names[solved % 12]);
            strcat(shm_scratch, dat_str_space_5);
            strcat(shm_scratch,
                       (char *) itoa(solved / 12 + 1990,
                                         asm_number_digits_5, 10));
            c_write_text((rt_addr) shm_scratch, x, y, 0);
            y += 8;
            /* Second line: the mission the career ended on, its type and its place. */
            type = dat_mission_sets[asm_fame[nth].mission_set]
                       .mission[asm_fame[nth].mission_step];
            strcpy(shm_scratch,
                       (char *) addr_crime_names[type]);
            strcat(shm_scratch, dat_str_slash_5);
            strcat(shm_scratch,
                       (char *) dat_mission_sets[asm_fame[nth].mission_set]
                           .text[asm_fame[nth].mission_step][0]);
            c_write_text((rt_addr) shm_scratch, x, y, 9);
            y += 8;
            /* Third line: the last case's efficiency points and the career's score. */
            strcpy(shm_scratch, dat_str_ep_colon_2);
            strcat(shm_scratch,
                       (char *) itoa(asm_fame[nth].points,
                                     asm_number_digits_5, 10));
            strcat(shm_scratch, dat_str_score_stop);
            strcat(shm_scratch,
                       (char *) itoa(asm_fame[nth].score,
                                     asm_number_digits_5, 10));
            strcat(shm_scratch, dat_str_dashes_3);
            c_write_text((rt_addr) shm_scratch, x, y, 7);
            y += 14;
            /* Lay a two-colour pattern over the career just added, to pick it out. */
            if (nth == fresh)
                drv_jump_gfx_fill(shd_screen, x - 4, y - 32,
                                  296, 26, 15, 14);
        }
        /* With a new career on the roll, offer the boxed Clear option. */
        if (fresh != -1) {
            c_write_text(dat_str_clear, 252, 189, 0);
            c_outline_box(236, 187, 60, 10, 11);
        }
        choice = c_wait_key();
        /* C asks the caller to clear the roll. */
        if (fresh != -1 && (choice == 'c' || choice == 'C'))
            return 1;
        /* From the menu, a row's number replays interlude score / 150, at most 20, as Max or Maxine. */
        if (fresh == -1 && choice >= '1' && choice <= '5') {
            score = shown[choice - '1'];
            shm_options &= ~OPT_FEMALE;
            if (score & 0x8000)
                shm_options |= OPT_FEMALE;
            c_interlude(c_clamp((score & 0x7fff) / 150, 0, 20),
                            LONG_LIT(0));
            /* After a key, sound command 1 and disk 1 back in the drive, then the roll again. */
            c_wait_key();
            c_sound_command(1);
            c_want_disk(1, LONG_LIT(1));
        } else
            break;
    }
    return 0;
}

/* Put a finished career on the roll and show it there, answering the slot it
 * took. The score is `ep`, the case's efficiency points, times one more than
 * the difficulty; a career that beats nothing still takes the sixth slot. The
 * first local is never read.
 */
INT c_fame_add(INT ep)
{
    INT zero;
    INT slot;
    INT score;
    INT step;

    zero = 0;
    /* Harder difficulties multiply the points into a bigger score. */
    score = ep * (shm_difficulty + 1);
restart:
    /* Find the first place the score beats, or the sixth whatever it is. */
    for (slot = 0; slot < 6; slot++) {
        if (asm_fame[slot].score < score || slot == 5) {
            /* Push the careers below it down a place, the last falling off. */
            for (step = 5; step > slot; step--)
                memcpy((char *) &asm_fame[step],
                           (char *) &asm_fame[step - 1], 44);
            /* Record the career: score, name, difficulty and sex, last mission, points and cases. */
            asm_fame[slot].score = score;
            strcpy(asm_fame[slot].name, shm_campaign.player_name);
            asm_fame[slot].difficulty = shm_difficulty;
            if (shm_options & OPT_FEMALE)
                asm_fame[slot].difficulty |= 0x80;
            asm_fame[slot].mission_set = shm_campaign.mission_set;
            asm_fame[slot].mission_step = shm_campaign.mission_step;
            asm_fame[slot].points = ep;
            asm_fame[slot].cases = shm_campaign.cases;
            /* Show it on the roll; a clear empties the roll and the career is entered again. */
            if (c_fame_screen(slot)) {
                c_fame_clear();
                goto restart;
            }
            return slot;
        }
    }
    return -1;
}
