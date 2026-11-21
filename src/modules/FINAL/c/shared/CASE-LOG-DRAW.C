/* CASE-LOG-DRAW.C -- drawing the case log, a page at a time.
 *
 * As the Chronology, with each message's text, or the News.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "SCREEN.H"
#include "TEXTDTA.H"
#include "CMISEND.H"
#include "CASERUN.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"

/* shared_include_start: ../../../../shared/c/LOG-DRAW.C -- generated */
/* LOG-DRAW.C -- c_log_draw, showing the case log a page at a time.
 */

/* Draw the case log page by page, as the chronology with `full`, else news.
 * The gotos keep the code in the shipped order.
 */
void c_log_draw(LONG full)
{
    INT subj;
    INT unused;
    INT pad2;
    INT msg;
    INT i;
    INT y;

    c_page_frame((INT) full != 0 ? shd_str_chronology : shd_str_news, 0xe);
    y = 0x10;
    for (i = 0; i < shm_log_count; i++) {
        if (shm_log[i].kind == -1)
            continue;
        for (;;) {
            subj = shm_log[i].slot;
            pad2 = 0;
            switch (shm_log[i].kind) {
            case LOG_MESSAGE:
                if (shm_crime_events[subj].flags & CRIME_BULLETIN) {
                    c_write_text_trimmed(
                        c_timestamp(shm_log[i].minute) + 9, 8, y, 7);
                    y += 8;
                    (shm_scratch)[0] = 0;
                    c_say_event_text(subj);
                    y = c_draw_message(0x24, 0xc, y, 0);
                } else
                    goto message;
            }
page:
            if (y >= 0xc0) {
                c_write_text(shd_str_more_2, 0x100, 0xc0, 0xc);
                c_wait_key();
                goto banner;
message:
                if (shm_log[i].known != 0
                    && (INT) full != 0) {
                    msg = shm_log[i].slot;
                    if ((shm_log[i].known & 0x8000)
                        && ((shm_crime_events[msg].flags & CRIME_KIND) == CRIME_MESSAGE
                            || (shm_crime_events[msg].flags & CRIME_KIND)
                               == CRIME_MEETING)) {
                        strcpy(shm_scratch,
                                   shm_crime_roles[shm_crime_events[msg].main_participant].name);
                        if (shm_crime_events[msg].flags & CRIME_MESSAGE)
                            strcat(shm_scratch, shd_str_sent_msg_2);
                        else
                            strcat(shm_scratch, shd_str_met);
                        strcat(shm_scratch,
                                   shm_crime_roles[shm_crime_events[msg].flags & CRIME_FAR_NIBBLE].name);
                        c_write_text_trimmed((rt_addr) shm_scratch,
                                        8, y, 7);
                        y += 8;
                        strcpy(shm_scratch, shd_str_quote_3);
                        c_say_event_text(msg);
                        strcat(shm_scratch, shd_str_quote_4);
                        y = c_draw_message(0x24, 0xc, y, 0xc);
                    } else if ((shm_crime_events[msg].flags & CRIME_KIND)
                               == CRIME_MEETING) {
                        c_write_text_trimmed(shd_str_meeting_noted, 8, y, 7);
                        y += 8;
                        (shm_scratch)[0] = 0;
                        c_say_event_text(msg);
                        c_filter_message(shm_log[i].known, 5);
                        y = c_draw_message(0x24, 0xc, y, 0xc);
                    }
                }
                goto page;
banner:
                c_page_frame((INT) full != 0 ? shd_str_chronology_2 : shd_str_news_2,
                                0xe);
                y = 0x10;
                continue;
            }
            break;
        }
    }
    if (y == 0x10)
        c_write_text(shd_str_none_log, 0xc, y, 7);
    c_wait_key();
}
/* shared_include_end: ../../../../shared/c/LOG-DRAW.C */
