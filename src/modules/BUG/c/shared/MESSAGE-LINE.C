/* MESSAGE-LINE.C -- one intercepted message written as a sentence.
 */
#include "BUG.H"
#include "TEXTLAY.H"
#include "REPORT.H"
#include "CRIMEVNT.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/INTERCEPT-LINE.C -- generated */
/* INTERCEPT-LINE.C -- c_intercept_line, one case-log record as a sentence.
 */

/* Append log record `nth` to shm_scratch as a sentence: what happened, then as
 * far as is known who with, their organisation, the city and the date.
 */
void c_intercept_line(INT nth)
{
    INT party;
    INT last;
    INT origin;
    INT peer;

    /* What happened: the event's own description, or for a bare message which way it went. */
    origin = shm_log[nth].slot;
    if (origin >= 0)
        strcat(shm_scratch, shm_crime_events[origin].description);
    else if (origin & 1)
        strcat(shm_scratch, shd_str_rcvd_msg_fm);
    else
        strcat(shm_scratch, shd_str_sent_msg);
    /* An event with anyone at the far end goes on to name them, as far as the player knows. */
    if (shm_crime_events[origin].flags & CRIME_IN_USE || origin < 0) {
        /* The exchange's other half is the record logged the same minute, on either side. */
        peer = shm_log[nth].from;
        party = shm_log[nth].to;
        last = -1;
        if (shm_log[nth + 1].minute
            == shm_log[nth].minute)
            last = nth + 1;
        if (shm_log[nth - 1].minute
            == shm_log[nth].minute)
            last = nth - 1;
        /* Who it was with, or "someone". */
        if (shm_log[nth].known & 2) {
            strcat(shm_scratch, shd_str_space_9);
            c_person_name(party);
        } else
            strcat(shm_scratch, shd_str_someone);
        /* Their organisation. */
        if (shm_log[nth].known & 4) {
            strcat(shm_scratch, shd_str_of_the_2);
            strcat(shm_scratch, shm_orgs[shm_suspects[party].org].short_name);
        }
        /* The city at their end. */
        if (shm_log[nth].known & 8) {
            strcat(shm_scratch, shd_str_in_4);
            strcat(shm_scratch, shm_cities[shm_log[nth].to_city].name);
        }
        /* Once the far end is placed, share what is known of them between both halves and their file. */
        if ((shm_log[nth].known & 2
             && shm_suspects[party].flags & SUSPECT_NAME)
            || (shm_log[nth].known & 4
                && shm_log[nth].known & 8
                && shm_suspects[party].flags & SUSPECT_ORG
                && shm_suspects[party].flags & SUSPECT_CITY)) {
            shm_log[nth].known |=
                shm_suspects[party].flags & (SUSPECT_NAME | SUSPECT_ORG);
            shm_log[last].known |=
                shm_suspects[peer].flags & (SUSPECT_NAME | SUSPECT_ORG);
            shm_suspects[party].flags |=
                shm_log[nth].known & 6;
            if (shm_log[nth].to_city
                == shm_suspects[party].city) {
                shm_log[nth].known |=
                    shm_suspects[party].flags & SUSPECT_CITY;
                shm_suspects[party].flags |=
                    shm_log[nth].known & 8;
            }
        }
        /* The same from the other half, for the suspect at this end. */
        if ((shm_log[last].known & 2
             && shm_suspects[peer].flags & SUSPECT_NAME)
            || (shm_log[last].known & 4
                && shm_log[last].known & 8
                && shm_suspects[peer].flags & SUSPECT_ORG
                && shm_suspects[peer].flags & SUSPECT_CITY)) {
            shm_log[last].known |=
                shm_suspects[peer].flags & (SUSPECT_NAME | SUSPECT_ORG);
            shm_log[nth].known |=
                shm_suspects[party].flags & (SUSPECT_NAME | SUSPECT_ORG);
            shm_suspects[peer].flags |=
                shm_log[last].known & 6;
            if (shm_log[last].to_city
                == shm_suspects[peer].city) {
                shm_log[last].known |=
                    shm_suspects[peer].flags & SUSPECT_CITY;
                shm_suspects[peer].flags |=
                    shm_log[last].known & 8;
            }
        }
    }
    /* The date, if known: the case's month and the campaign day it happened on. */
    if (shm_log[nth].known & 1) {
        strcat(shm_scratch, shd_str_on_2);
        strcat(shm_scratch,
                   (char *) shd_month_names
                   [shm_campaign.cases % 12]);
        strcat(shm_scratch, shd_str_space_10);
        strcat(shm_scratch,
                   (char *) itoa(shm_log[nth].minute / 1440 + 1,
                                     shm_clue_digits, 10));
    }
    /* Close the sentence. */
    strcat(shm_scratch, shd_str_period_3);
}
/* shared_include_end: ../../../../shared/c/INTERCEPT-LINE.C */
