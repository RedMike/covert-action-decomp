/* CASEDUE.C -- whether a crime event is due, and which event answers it.
 */
#include "GAME.H"
#include "ADVICE.H"
#include "BLOCK.H"
#include "SUSPECT.H"
#include "MESSAGE.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"

/* Say whether crime event `nth` is ready to break, and which event answers it:
 * -1 when it is not, 1 when it has no far party, else the matching event. */
INT c_case_due(INT nth)
{
    INT v0j;    /* declared and never used */
    INT v1j;    /* the suspect in the event's main role */
    INT v2j;    /* the suspect at the event's far end */
    INT v3k;    /* declared and never used */
    INT v4k;    /* set when that second suspect, held or hiding, need not catch up first */
    INT v5l;    /* the event being scanned */
    INT v6l;    /* what the first suspect is doing */
    INT v7m;    /* the event that answers, or -1 */
    INT v8m;    /* declared and never used */
    INT v9n;    /* the crime role at the event's far end */
    INT v10g;   /* declared and never used */

    /* Only an event still waiting to happen can come due. */
    if (shm_crime_events[nth].happen_tick != 999)
        return -1;
    /* A turned agent no longer carries out the plot's steps that score. */
    v1j = shm_crime_roles[shm_crime_events[nth].main_participant].suspect;
    v6l = shm_suspects[v1j].alert_level;
    if (v6l == ALERT_TURNED
        && shm_crime_events[nth].score != 0)
        return -1;
    /* A participant's steps happen in order: an earlier one still waiting goes first. */
    for (v5l = 0; v5l < nth; v5l++)
        if (shm_crime_events[v5l].happen_tick == 999
            && shm_crime_events[nth].main_participant
               == shm_crime_events[v5l].main_participant)
            return -1;
    /* A dead store: the scan below sets it afresh. */
    v5l = (char) shm_crime_events[nth].main_participant;
    /* One person acting alone: due once the log has more than five entries, unless out of play. */
    if ((shm_crime_events[nth].flags & CRIME_IN_USE) == 0) {
        if (shm_log_count <= 5)
            return -1;
        v6l = shm_suspects[v1j].alert_level;
        if (v6l < 0 && v6l != ALERT_TURNED) {
            c_test_for_jailbreak(v1j, nth);
            return -1;
        }
        return 1;
    }
    /* Two parties: the one at the far end of the event. */
    v9n = CRIME_FAR_CELL(shm_crime_events[nth]);
    v2j = shm_crime_roles[v9n].suspect;
    v4k = shm_suspects[v2j].alert_level < 0
          && shm_suspects[v2j].alert_level != ALERT_TURNED
          && (shm_crime_events[nth].flags & CRIME_UNKNOWN_10) != 0;
    /* Find the far party's half of the exchange; a step of theirs still waiting before it holds this back. */
    v7m = -1;
    for (v5l = 0; v5l < shm_crime_event_count; v5l++) {
        if ((char) shm_crime_events[v5l].main_participant == v9n) {
            if (shm_crime_events[nth].message_id
                == shm_crime_events[v5l].message_id) {
                v7m = v5l;
                break;
            }
            if (shm_crime_events[v5l].happen_tick == 999 && v4k == 0)
                return -1;
        }
    }
    /* Either party under arrest stops it, and may bring on a jailbreak. */
    if (shm_suspects[v1j].alert_level == ALERT_ARRESTED) {
        c_test_for_jailbreak(v1j, nth);
        return -1;
    }
    if (shm_suspects[v2j].alert_level == ALERT_ARRESTED) {
        c_test_for_jailbreak(v2j, nth);
        return -1;
    }
    /* A party in hiding comes out for it, and the surveillance team reports the sighting. */
    if (shm_suspects[v1j].alert_level == ALERT_HIDING
        && shm_suspects[v2j].alert_level != ALERT_ARRESTED) {
        shm_suspects[v1j].alert_level = 0;
        strcpy(shm_scratch, dat_str_bulletin_2);
        c_person_name(v1j);
        strcat(shm_scratch, dat_str_has_come_out_hiding);
        c_print_message(dat_str_surveillance_team_2);
        c_log_add(LOG_AT_LARGE, v1j);
    }
    /* Likewise the far party. */
    if (shm_suspects[v2j].alert_level == ALERT_HIDING
        && shm_suspects[v1j].alert_level != ALERT_ARRESTED) {
        shm_suspects[v2j].alert_level = 0;
        strcpy(shm_scratch, dat_str_bulletin_3);
        c_person_name(v2j);
        strcat(shm_scratch, dat_str_has_come_out_hiding_2);
        c_print_message(dat_str_surveillance_team_3);
        c_log_add(LOG_AT_LARGE, v2j);
    }
    /* The far party's matching event, or -1 if they have none. */
    return v7m;
}
