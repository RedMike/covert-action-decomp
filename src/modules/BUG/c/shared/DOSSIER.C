/* DOSSIER.C -- the dossier one suspect is shown on.
 */
#include "BUG.H"
#include "SPRITES.H"
#include "PRIMS.H"
#include "SCREEN.H"
#include "TEXTLAY.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "BOARD.H"
#include "REPORT.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/DOSSIER.C -- generated */
/* DOSSIER.C -- c_dossier, drawing a suspect's dossier and intercepts.
 */

/* Draw suspect `nth`'s dossier at (`x`, `y`), then their intercepted messages.
 * A `y` of zero is a whole screen; any other is a panel, without the
 * recruitment line, face and messages.
 */
void c_dossier(INT nth, INT x, INT y)
{
    INT filled;
    INT disused;
    INT slot;
    INT low;
    INT unwanted;
    INT row;
    INT scrap;
    INT tick;
    INT rank;
    INT dead;

    /* Remember where the dossier starts: 0 means it has the screen to itself. */
    row = y;
    unwanted = nth;
    /* A panel is indented; a page of its own is framed with the suspect's name as its title. */
    if (y != 0)
        x += 4;
    else {
        strcpy(shm_scratch, shd_str_empty_dossier);
        c_person_name(nth);
        c_page_frame((rt_addr) shm_scratch, 3);
        y = 18;
        x += 10;
    }
    /* The name they go by, real or a codename. */
    y += 2;
    strcpy(shm_scratch, shd_str_name);
    c_person_name(nth);
    c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    /* The rank, once learnt: that of a role the suspect fills, or else one read off their face. */
    if (shm_suspects[nth].flags & SUSPECT_RANK) {
        rank = (shm_suspects[nth].visuals >> 2) & 7;
        for (tick = 0; tick < shm_crime_role_count; tick++)
            if (shm_crime_roles[tick].suspect == nth)
                rank = shm_crime_roles[tick].rank;
        strcpy(shm_scratch, shd_str_rank);
        strcat(shm_scratch, (char *) shd_clue_kinds[rank]);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* The organisation, once learnt, which also marks the organisation as heard of. */
    if (shm_suspects[nth].flags & SUSPECT_ORG) {
        shm_orgs[shm_suspects[nth].org].known |= 1;
        strcpy(shm_scratch, shd_str_org);
        strcat(shm_scratch, shm_orgs[shm_suspects[nth].org].long_name);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* The city they work from, once learnt. */
    if (shm_suspects[nth].flags & SUSPECT_CITY) {
        strcpy(shm_scratch, shd_str_city);
        strcat(shm_scratch, shm_cities[shm_suspects[nth].city].name);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* Recruited by whoever fills the first role in the same organisation, unless that is the suspect. */
    strcpy(shm_scratch, shd_str_recruited);
    if (shm_suspects[nth].flags & SUSPECT_RECRUITED_BY)
        for (tick = 0; tick < shm_crime_role_count; tick++)
            if (shm_suspects[nth].org
                == shm_suspects[shm_crime_roles[tick].suspect].org) {
                if (nth != shm_crime_roles[tick].suspect) {
                    strcat(shm_scratch, shd_str_by);
                    c_person_real_name(shm_crime_roles[tick].suspect);
                }
                break;
            }
    /* ...and in the city nearest the one they work from. */
    if (shm_suspects[nth].flags & SUSPECT_RECRUITED_IN) {
        rank = -1;
        low = 999;
        for (tick = 0; tick < 16; tick++)
            if (tick != shm_suspects[nth].city
                && (INT) c_city_distance(tick,
                                            shm_suspects[nth].city) < low) {
                rank = tick;
                low = c_city_distance(rank,
                                         shm_suspects[nth].city);
            }
        if (rank != -1) {
            strcat(shm_scratch, shd_str_in_3);
            strcat(shm_scratch, shm_cities[rank].name);
        }
    }
    /* Only a page of its own shows the Recruited line, and only once something follows the word. */
    if ((INT) strlen(shm_scratch) > 12 && row == 0) {
        strcat(shm_scratch, shd_str_period_2);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* A page of its own shows the photograph, once taken, clipped to the top right. */
    if (shm_suspects[nth].flags & SUSPECT_PHOTO && row == 0) {
        c_draw_face_panel(shm_suspects[nth].visuals, 264, 8);
        c_draw_sprite(SPRITE_PAPERCLIP, 299, 40);
    }
    /* Below a rule, a Role: line for each role the suspect is known to fill. */
    filled = 0;
    y += 10;
    c_draw_line(x, y - 2, x + 128, y - 2, 12);
    for (tick = 0; tick < shm_crime_role_count; tick++)
        if (shm_suspects[nth].role_known
            & 1 << tick) {
            strcpy(shm_scratch, shd_str_role);
            strcat(shm_scratch, shm_crime_roles[tick].name);
            c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
            filled = 1;
        }
    /* No role known: NOT INVOLVED if fully identified and flagged yet holding no real role, else unknown. */
    if (filled == 0) {
        if ((shm_suspects[nth].flags & (SUSPECT_IDENTITY | SUSPECT_PARTICIPANT))
                == (SUSPECT_IDENTITY | SUSPECT_PARTICIPANT)
            && (shm_suspects[nth].role & 0x7fff)
               == 0)
            strcpy(shm_scratch, shd_str_role_2);
        else
            strcpy(shm_scratch, shd_str_role_3);
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 7);
    }
    /* What has become of the suspect: arrested, in hiding or turned. */
    if (shm_suspects[nth].alert_level == ALERT_ARRESTED) {
        strcpy(shm_scratch, shd_str_under_arrest);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 5);
    }
    if (shm_suspects[nth].alert_level == ALERT_HIDING) {
        strcpy(shm_scratch, shd_str_hiding);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 5);
    }
    if (shm_suspects[nth].alert_level == ALERT_TURNED) {
        strcpy(shm_scratch, shd_str_turned);
        y += 8;
        c_write_text_trimmed((rt_addr) shm_scratch, x, y, 5);
    }
    /* Close the card with a rule, and start the messages clear of the photograph if there is one. */
    c_draw_line(x, y + 8, x + 128, y + 8, 12);
    y += 2;
    y = c_clamp(y + 8,
                           shm_suspects[nth].flags & SUSPECT_PHOTO ? row + 54 : 0, 99);
    /* On a page of its own, every logged message from the suspect that the player knows of. */
    for (tick = 0; tick < shm_log_count; tick++)
        if (shm_log[tick].from == nth
            && shm_log[tick].known != 0
            && row == 0) {
            for (;;) {
                /* Its headline: what it was, with whom, where and when. */
                strcpy(shm_scratch, shd_str_empty_dossier_line);
                c_intercept_line(tick);
                y = c_draw_message(37, x, y, 5);
                if (row == 0) {
                    slot = shm_log[tick].slot;
                    /* A decoded message is quoted in full. */
                    if (shm_log[tick].known & 0x8000) {
                        strcpy(shm_scratch, shd_str_quote);
                        c_say_event_text(slot);
                        strcat(shm_scratch, shd_str_quote_2);
                        y = c_draw_message(36, x + 4, y, 12);
                    } else {
                        /* A coded message not yet decoded says so. */
                        if ((shm_crime_events[slot].flags & CRIME_KIND) == CRIME_MESSAGE
                            || (shm_crime_events[slot].flags & CRIME_KIND)
                               == (CRIME_MESSAGE | CRIME_RECEIVED)) {
                            c_write_text(shd_str_message_not_decoded, x + 4, y, 4);
                            y += 8;
                        }
                        /* Meeting notes show only the words the record's known bits let through. */
                        if ((shm_crime_events[slot].flags & CRIME_KIND) == CRIME_MEETING
                            || (shm_crime_events[slot].flags & CRIME_KIND)
                               == (CRIME_MEETING | CRIME_RECEIVED)) {
                            shm_scratch[0] = 0;
                            c_say_event_text(slot);
                            c_filter_message(shm_log[tick].known, 5);
                            y = c_draw_message(36, x + 4, y, 12);
                        }
                    }
                }
                /* At the foot of the page, wait for a key and redraw this message atop a fresh page. */
                if (y >= 192) {
                    c_write_text(shd_str_more, 256, 192, 12);
                    c_wait_key();
                    strcpy(shm_scratch, shd_str_empty_dossier_page);
                    c_person_name(nth);
                    c_page_frame((rt_addr) shm_scratch, 3);
                    y = 16;
                } else
                    break;
            }
        }
}
/* shared_include_end: ../../../../shared/c/DOSSIER.C */
