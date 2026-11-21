/* CASE-EVIDENCE-NEWS.C -- announcing new evidence on a suspect.
 *
 * The news is the difference from the mask the record held before, reported a
 * field at a time and each set as it is told, so the name says more each pass;
 * then the wait for a key.
 */
#include "FINAL.H"
#include "MENUS.H"
#include "SCREEN.H"
#include "CMISEND.H"
#include "SAVELOAD.H"
#include "CASERUN.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/REPORT-FIELDS.C -- generated */
/* REPORT-FIELDS.C -- c_report_new_fields, announcing new evidence.
 */

/* Announce the evidence just added on suspect `who`: one message per newly set
 * bit. `flags` is the word before the evidence.
 */
UNSIGNED_INT c_report_new_fields(INT who, UNSIGNED_INT flags)
{
    INT picked;   /* the bits still to be reported */
    INT gained;   /* every bit the suspect ends up with */

    gained = shm_suspects[who].flags;
    shm_suspects[who].flags = flags;
    if (gained == flags)
        return flags;
    do {
        c_dossier(who, 0, 0);
        shm_menu_draw_only = 0;
        gained |= shm_suspects[who].flags;
        picked = gained
                 ^ shm_suspects[who].flags;
        if (picked & SUSPECT_PARTICIPANT) {
            shm_suspects[who].flags |= SUSPECT_PARTICIPANT;
            strcpy(shm_scratch, shd_str_empty_identified);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_identified_as);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_NAME) {
            strcpy(shm_scratch, (char *) &shd_str_empty_positively);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_positively);
            shm_suspects[who].flags |= SUSPECT_NAME;
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_2);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_PHOTO) {
            shm_suspects[who].flags |= SUSPECT_PHOTO;
            strcpy(shm_scratch, shd_str_we_have_acquired);
            c_person_name(who);
            strcat(shm_scratch, shd_str_stop);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_CITY) {
            shm_suspects[who].flags |= SUSPECT_CITY;
            strcpy(shm_scratch, shd_str_empty_spotted);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_spotted);
            strcat(shm_scratch,
                       shm_cities[shm_suspects[who].city].name);
            strcat(shm_scratch, shd_str_newline_3);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
            shm_activity.city[shm_suspects[who].city]++;
        } else if (picked & SUSPECT_ORG) {
            shm_suspects[who].flags |= SUSPECT_ORG;
            strcpy(shm_scratch, shd_str_empty_org);
            c_person_name(who);
            strcat(shm_scratch, shd_str_has_been_identified_as_org);
            strcat(shm_scratch,
                       shm_orgs[shm_suspects[who].org].long_name);
            strcat(shm_scratch, shd_str_newline_4);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
            shm_orgs[shm_suspects[who].org].known |= 1;
            shm_activity.org[shm_suspects[who].org]++;
        } else if (picked & SUSPECT_MORE_INFO) {
            shm_suspects[who].flags |= SUSPECT_MORE_INFO;
            strcpy(shm_scratch, shd_str_we_have_obtained);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_5);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RANK) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RANK >> 8;
            strcpy(shm_scratch, shd_str_we_have_determined_rank);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_6);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RECRUITED_IN) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RECRUITED_IN >> 8;
            strcpy(shm_scratch, shd_str_we_found_recruiting);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_7);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        } else if (picked & SUSPECT_RECRUITED_BY) {
            *((char *) &shm_suspects[who].flags + 1) |= SUSPECT_RECRUITED_BY >> 8;
            strcpy(shm_scratch, shd_str_we_found_recruiting_2);
            c_person_name(who);
            strcat(shm_scratch, shd_str_newline_8);
            c_ask_menu(shm_scratch, 0x14, 0x3c);
        continue;
    }
    } while (shm_suspects[who].flags != gained);
    c_dossier(who, 0, 0);
    return c_wait_key();
}
/* shared_include_end: ../../../../shared/c/REPORT-FIELDS.C */
/* shared_include_start: ../../../../shared/c/WAIT-KEY.C -- generated */
/* WAIT-KEY.C -- c_wait_key, waiting for a key or a joystick button.
 */

/* Wait for a key, or either joystick button when the stick is on, then for
 * everything to be let go; answer the key's menu code, or 1 for a button.
 */
INT c_wait_key(void)
{
    INT input;   /* the key, or 1 for a button, and -1 until one arrives */

    input = -1;
    while (drv_jump_keyboard_empty() != 0 && input == -1) {
        if (shm_options & OPT_JOYSTICK) {
            if (c_joystick_button(0) != 0 || c_joystick_button(1) != 0)
                input = 1;
        }
    }
    if (input == -1)
        input = c_menu_key();
    c_wait_for_release();
    return input;
}
/* shared_include_end: ../../../../shared/c/WAIT-KEY.C */
