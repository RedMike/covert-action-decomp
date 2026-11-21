/* RAID.C -- settling a break-in once the player is back out of the building.
 */
#include "GAME.H"
#include "CASE.H"
#include "CMP_STRT.H"
#include "DIALOG.H"
#include "BLOCK.H"
#include "ANI_PLAY.H"
#include "ORGPLAN.H"
#include "PRISONER.H"
#include "PROSE.H"
#include "RAID.H"
#include "LOGKINDS.H"
#include "CAMPSTAT.H"
#include "RESULT.H"

/* Settle a break-in at organisation `org` in city `where`: log it and, unless
 * the player was caught, report each crime object found on the local suspect,
 * add the taps planted and make any arrest. */
INT c_raid(INT org, INT where)
{
    INT v0j;    /* the taps planted, or -1 when the player was caught */
    INT v1k;
    INT v2l;
    INT v3m;    /* the crime object being checked */
    INT v4n;    /* the suspect of that organisation and city */
    INT v5o;    /* the building record */
    INT v6;
    INT v7a;

    /* The break-in goes in the log, and the building and its organisation are now known. */
    c_log_add(LOG_BREAK_IN, org * 0x100 + where);
    v5o = c_building_explore(org, where, 0xc);
    shm_orgs[org].known |= 1;
    /* Coming back from TAC: how it ended, and how alarmed the organisation is now. */
    if (asm_campaign_state != NONE_NOTHING_PENDING) {
        v0j = (char) COMM()->result[RES_TAC_END_LINE];
        c_raise_alert(org, where, (char) COMM()->result[RES_TAC_ALERT]);
    }
    /* The organisation's suspect in this city, if on file. */
    v4n = c_evidence_unlock(org, where, 0, LONG_LIT(0));
    /* Caught inside: the organisation is fully alarmed and the player is a prisoner. */
    if (v0j == -1) {
        c_raise_alert(org, where, 100);
        c_player_captured_menu();
        return;
    }
    /* With the crime object found, each one the local suspect held is reported and taken out of play. */
    if ((COMM()->result[RES_TAC_OUTCOME] & 1) != 0 && v4n != -1) {
        v3m = 0;
        do {
            if ((char) shm_crime_block[v3m].u2
                == v4n) {
                drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
                c_pan_arm(dat_str_briefing_pan, 0, 0);
                c_seq_set_var(0, 2);
                strcpy(shm_scratch, dat_str_good_job_max_found);
                strcat(shm_scratch,
                           (char *) shm_crime_block[v3m].name);
                strcat(shm_scratch, dat_str_should_really_slow_down);
                c_ask_menu(shm_scratch, 16, 149);
                c_remove_crime_object(v3m);
            }
            v3m++;
        } while (v3m < 4);
    }
    /* The bugs planted strengthen the building's tap. */
    shm_buildings[v5o].wiretap_level += v0j;
    /* An arrest made inside means an interrogation. */
    if ((COMM()->result[RES_TAC_OUTCOME] & 2) != 0)
        c_arrest(v4n);
}
