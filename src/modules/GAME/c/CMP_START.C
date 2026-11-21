/* CMP_START.C -- starting a campaign, up to the opening briefing.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "ADVICE.H"
#include "DIALOG.H"
#include "CASE.H"
#include "ANI_PLAY.H"
#include "WRAP.H"

/* Open a campaign: run the clock and scan random cities from the CIA until
 * enough clues and evidence have turned up, then show the briefing. */
INT c_campaign_start(void)
{
    INT v0j;
    INT v1j;
    INT v2j;
    INT v3j;
    INT v4j;
    INT v5j;
    INT v6j;
    INT v7k;    /* the city scanned */
    INT v8k;
    INT v9k;
    INT v10d;   /* how much has happened so far */
    INT v11d;
    INT v12d;
    INT v13d;

    /* Nothing found yet, and the case's clock about to be ticked in. */
    v10d = 0;
    shm_case_tick = -1;
    /* Until enough clues and evidence have turned up, more the easier the level: */
    do {
        /* once the log has more than five entries, scan a random city with no double agent at the CIA; */
        if (shm_log_count > 5) {
            do {
                v7k = c_random_below(16);
            } while ((shm_double_agent_cities & 1 << v7k) != 0);
            v10d += c_suspect_scan(1, v7k, 99, LONG_LIT(0));
        /* until then, let three hours pass. */
        } else
            c_campaign_tick(180);
        /* This is no wait of the player's, so the clock is not running on by itself. */
        asm_auto_waiting = 0;
    } while ((4 - shm_difficulty) * 2 > v10d);
    /* The case is ready to break: brief the player over briefing.pan. */
    asm_case_ready = 1;
    c_seq_set_var(0, 1);
    drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
    c_pan_arm(dat_str_briefing_pan_3, 0, 0);
    /* Only the easiest level is given a research assistant. */
    strcpy(shm_scratch, dat_str_rest_up);
    if (shm_difficulty == 0)
        strcat(shm_scratch, dat_str_i_ve_assigned_one);
    strcat(shm_scratch, dat_str_president_s_counting);
    /* Wrap the briefing to 40 columns and show it. */
    c_wrap_message(40);
    return c_ask_menu(shm_scratch, 8, 149);
}
