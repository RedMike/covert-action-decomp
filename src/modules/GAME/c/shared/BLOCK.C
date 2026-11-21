/* shared/BLOCK.C -- the shared routines in BLOCK.C's unit, before BLOCK.C. */

#include "GAME.H"
#include "BLOCK.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "FRAME.H"
#include "CASE.H"
#include "LINES.H"
#include "TAG.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/LOG-ADD.C -- generated */
/* LOG-ADD.C -- c_log_add, adding a record to the case log.
 */

/* Add a record of `kind` about `slot` to the case log at the current minute; a
 * message also records its sender and recipient. Records past the 128th still
 * write past the end.
 */
INT c_log_add(INT kind, INT slot)
{
    INT sender;
    INT to;
    INT row;

    shm_log[shm_log_count].minute = shm_clock_minutes;
    shm_log[shm_log_count].kind = kind;
    shm_log[shm_log_count].slot = slot;
    shm_log[shm_log_count].known = 0;
    shm_log[shm_log_count].from = 0xff;
    shm_log[shm_log_count].status = 0;
    DEBUG_MESSAGE4("c_log_add: [%d] kind=%d (%s) minute=%d",
                   shm_log_count,
                   shm_log[shm_log_count].kind,
                   LOG_KIND_NAME(shm_log[shm_log_count].kind),
                   shm_log[shm_log_count].minute);
    DEBUG_MESSAGE3("  slot=%d known=%x status=%d",
                   shm_log[shm_log_count].slot,
                   shm_log[shm_log_count].known,
                   shm_log[shm_log_count].status);
    if (kind == LOG_MESSAGE) {
        sender = shm_crime_roles[shm_crime_events[slot].main_participant].suspect;
        shm_log[shm_log_count].from = sender;
        row = sender * 16;
        shm_log[shm_log_count].from_city = shm_suspects[sender].city;
        shm_log[shm_log_count].status = shm_suspects[sender].alert_level;
        if (shm_crime_events[slot].flags & CRIME_IN_USE) {
            to = shm_crime_roles[CRIME_FAR_CELL(shm_crime_events[slot])].suspect;
            shm_log[shm_log_count].to = to;
            shm_log[shm_log_count].to_city = shm_suspects[to].city;
        }
        DEBUG_MESSAGE3("  from=%d from_city=%d (%s)",
                       shm_log[shm_log_count].from,
                       shm_log[shm_log_count].from_city,
                       shm_cities[shm_log[shm_log_count].from_city].name);
        DEBUG_MESSAGE3("  to=%d to_city=%d (%s)",
                       shm_log[shm_log_count].to,
                       shm_log[shm_log_count].to_city,
                       shm_cities[shm_log[shm_log_count].to_city].name);
    }
    shm_log_count++;
    if (shm_log_count >= 128) {
        strcpy(shm_scratch, shd_str_nsyn_overflow);
        c_ask_menu((rt_addr) shm_scratch, 0x32, 0x32);
    }
}
/* shared_include_end: ../../../../shared/c/LOG-ADD.C */

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

/* shared_include_start: ../../../../shared/c/SAY-BLOCK.C -- generated */
/* SAY-BLOCK.C -- c_say_block, appending a text block with the usual keys.
 */

/* Append the block tagged `key` in the file `name` to shm_scratch, with the
 * seven $-keys substituted from their value buffers.
 */
INT c_say_block(rt_addr name, rt_addr key)
{
    return c_say_block_with(name, key, shd_subst_keys,
                           shd_subst_values, 7);
}
/* shared_include_end: ../../../../shared/c/SAY-BLOCK.C */

/* shared_include_start: ../../../../shared/c/SAY-WITH.C -- generated */
/* SAY-WITH.C -- c_say_block_with, appending a text block with substitutions.
 */

/* Append the block tagged `key` in the file `name` to shm_scratch with `count`
 * keys substituted; answer whether it was found, appending a notice if not.
 */
INT c_say_block_with(rt_addr name, rt_addr key, rt_addr *keys,
                    rt_addr *values, INT count)
{
    char line[256];
    rt_stream stream;
    INT scanned;
    INT found;

    stream = fopen(name, shd_str_mode_read_text);
    do {
        scanned = fscanf(stream, shd_fmt_line, line);
#ifdef PORT_MODERN
        /* Skip a blank first line, as prose.dta has, which a modern library's
         * %[ would not match. */
        if (scanned == 0)
            scanned = fscanf(stream, (str_addr) " %[^\n]\n", line);
#endif
        ASSERT_SCAN_PROGRESS(scanned, name, key);
    } while (strcmp(line, key) != 0 && scanned != -1);
    if (scanned != -1) {
        do {
            fscanf(stream, shd_fmt_line_2, line);
        } while (line[0] == '*');
        do {
            c_substitute(line, keys, values, count);
            strcat(shm_scratch, line);
            strcat(shm_scratch, shd_str_space_12);
            fscanf(stream, shd_fmt_line_3, line);
        } while (line[0] != '*');
        found = 1;
    } else {
        strcat(shm_scratch, shd_str_information_requires);
        strcat(shm_scratch, key);
        found = 0;
    }
    fclose(stream);
    return found;
}
/* shared_include_end: ../../../../shared/c/SAY-WITH.C */

/* shared_include_start: ../../../../shared/c/SUBSTITUTE.C -- generated */
/* SUBSTITUTE.C -- c_substitute, replacing $-keys in a line of text.
 */

/* Replace, in place, the first occurrence in `line` of each of the `count`
 * keys with its value.
 */
INT c_substitute(char *line, rt_addr *keys, rt_addr *values,
                    INT count)
{
    str_addr hit;
    INT i;

    for (i = 0; i < count; i++) {
        hit = strstr(line, keys[i]);
        if (hit != 0) {
            strcpy(shm_substitute_tail, hit);
            *hit = 0;
            strcat(line, values[i]);
            strcat(line, strlen(keys[i]) + shm_substitute_tail);
        }
    }
}
/* shared_include_end: ../../../../shared/c/SUBSTITUTE.C */

