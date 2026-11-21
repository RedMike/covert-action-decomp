/* LEAVE.C -- saying how the break-in ended.
 */
#include "TAC.H"
#include "CITY.H"
#include "PROMPT.H"
#include "REVEAL.H"

/* Say how the break-in ended and hold the message on screen: which line it is
 * depends on whether the player walked out or was carried out. */
INT c_end_break_in(void)
{
    /* Still inside the building: the player was caught, which the end line
     * says with -1. */
    if (asm_room_last != 0) {
        asm_end_line = -1;
        /* Gassed past waking. */
        if (asm_people[0].stun > 256)
            strcpy(shm_scratch,
                       dat_str_overcome_by_gas_pass);
        /* Wounded past what the player can take, more with the Kevlar Vest. */
        else if (((asm_kit & 0x40) != 0 ? 3 : 1)
                 < asm_wounds)
            strcpy(shm_scratch,
                       dat_str_slump_ground_overcome);
        /* Neither: the prisoner got away. */
        else
            strcpy(shm_scratch,
                       dat_str_prisoner_released_while);
    } else {
        /* Out of the building: the end line carries what the bugs planted
         * scored. */
        asm_end_line = asm_bug_score;
        /* An ambush or a jailbreak, past its first moments, with no guard
         * left on his feet this round, was won by fighting. */
        if (asm_frame_tick > 64
            && (asm_mission_kind == 3 || asm_mission_kind == 2)
            && shm_activity.city[0] == 0)
            strcpy(shm_scratch,
                       dat_str_have_eliminated_all);
        else
            strcpy(shm_scratch, dat_str_quickly_slip_out);
    }
    /* Show the line without waiting on a choice, and hold it a while. */
    shm_menu_draw_only = 1;
    c_ask_menu((rt_addr) shm_scratch, 32, 100);
    c_wait_retraces(120);
}
