/* HQ.C -- arriving at an organisation's building, the CIA's above all.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "ADVICE.H"
#include "DECODE.H"
#include "DIALOG.H"
#include "ORGPLAN.H"
#include "STAKEOUT.H"
#include "CAMPSTAT.H"

/* Arrive at an organisation's building and mark it visited in this city; at
 * the CIA show the headquarters, on the easiest level the greeting and the
 * chief's briefing, then run the building. */
INT c_arrive(INT arg1, INT arg2)
{
    INT v0j;
    INT v1l;
    INT v2n;
    INT v3;
    INT v4b;

    /* A fresh arrival, not a return from a minigame. */
    if (asm_campaign_state == NONE_NOTHING_PENDING) {
        /* Walking in raises the alert around this organisation and city a little. */
        c_raise_alert(arg1, arg2, 20);
        /* Mark the organisation visited in this city, a mark nothing reads. */
        if ((shm_cities[shm_case_city].visited_cia
             & 1 << shm_case_org) == 0)
            shm_cities[shm_case_city].visited_cia
                |= 1 << shm_case_org;
        /* At the CIA, the headquarters animation. */
        if (shm_case_org == 1) {
            c_clear_for_menu();
            drv_jump_gfx_set_colour_map(&dat_colours_hq, &dat_colours_hq);
            /* Refused, animations are switched off in the options. */
            if (c_pan_arm(dat_str_hq_pan, 168, 0) == 0)
                shm_options &= ~OPT_ANIMATION;
            /* On the easiest level, the greeting and the chief's briefing. */
            if (shm_difficulty == 0) {
                strcpy(shm_scratch, dat_str_arrive_at_cia_building);
                c_ask_menu(shm_scratch, 16, 17);
                c_chief_briefing();
            }
        }
    }
    /* Inside the CIA building, fresh or returning. */
    if (shm_case_org == 1)
        c_cia_building();
    /* Whatever was pending has been dealt with. */
    asm_campaign_state = NONE_NOTHING_PENDING;
}
