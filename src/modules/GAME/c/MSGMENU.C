/* MSGMENU.C -- the menu of coded messages still to be cracked.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "DECODE.H"
#include "FRAME.H"
#include "BLOCK.H"
#include "CASE.H"
#include "SUSPECT.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"
#include "CAMPSTAT.H"
#include "RESULT.H"

/* List every coded message that has been intercepted and not yet cracked,
 * and hand the one picked to the decoder through the shared block. */
INT c_message_menu(void)
{
    char v0j[64];   /* the message text, trimmed to fit the width */
    INT v1j;        /* the crime event the message is */
    INT v2k;        /* never used */
    INT v3k;        /* set to 2 and never read */
    INT v4l;        /* the byte being copied to the shared block */
    INT v5m;        /* set to 2 and never read */
    INT v6m;        /* the message being listed */
    INT v7n;        /* how much was in the buffer before the text */
    INT v8n;        /* never used */
    INT v9o;        /* never used */

    /* A page of its own; the menu's answer is looked up one along, so slot 0 is what Escape gives. */
    c_page_frame(dat_str_coded_messages, 7);
    asm_menu_choice_count = 1;
    asm_menu_choices[0] = -1;
    v3k = 2;
    v5m = 2;
    strcpy(shm_scratch, dat_str_space_8);
    /* Every logged message the player knows of, sent or received or with no crime event, not yet cracked. */
    for (v6m = 0; v6m < shm_log_count; v6m++) {
        v1j = shm_log[v6m].slot;
        if (shm_log[v6m].kind == LOG_MESSAGE
            && shm_log[v6m].known != 0
            && ((shm_crime_events[v1j].flags & CRIME_KIND) == CRIME_MESSAGE
                || (shm_crime_events[v1j].flags & CRIME_KIND)
                   == (CRIME_MESSAGE | CRIME_RECEIVED)
                || v1j < 0)
            && (shm_log[v6m].known & 0x8000) == 0) {
            /* Its sender and the first eleven characters of the intercept's description, the rest on a line below. */
            c_person_name(shm_log[v6m].from);
            strcat(shm_scratch, dat_str_space_11);
            v7n = strlen(shm_scratch);
            c_intercept_line(v6m);
            strcpy(v0j, &shm_scratch[v7n + 11]);
            /* Shortened a character at a time until it fits the page's 292 pixels. */
            while ((INT) c_text_width(v0j) > 292)
                v0j[strlen(v0j) - 1] = 0;
            shm_scratch[v7n + 11] = 0;
            strcat(shm_scratch, dat_str_nl_3);
            strcat(shm_scratch, v0j);
            strcat(shm_scratch, dat_str_nl_4);
            /* The entry takes two lines, and either picks the message. */
            asm_menu_choices[asm_menu_choice_count++] = v6m;
            asm_menu_choices[asm_menu_choice_count++] = v6m;
        }
    }
    /* Coming back from another module, the list is only drawn, not asked. */
    if (asm_campaign_state != NONE_NOTHING_PENDING)
        return;
    /* Nothing to crack: a None line that picks nothing. */
    if (asm_menu_choice_count == 1) {
        strcat(shm_scratch, dat_str_none_10);
        asm_menu_choices[asm_menu_choice_count] = -1;
    }
    v6m = asm_menu_choices[c_ask_menu(shm_scratch, 10, 15) + 1];
    if (v6m == -1)
        return;
    /* Hand CODE the message's log entry and its full text, 512 bytes through the shared block. */
    COMM()->result[RES_CODE_MESSAGE] = v6m;
    c_say_message(v6m);
    for (v4l = 0; v4l < 512; v4l++)
        COMM()->message[v4l] = shm_scratch[v4l];
}
