/* TRAP.C -- adding a grenade, thrown or set.
 */
#include "TAC.H"
#include "PAGESHOW.H"
#include "MAPDRAW.H"
#include "PROMPT.H"
#include "PLAN.H"
#include "RESTORE.H"
#include "RADAR.H"
#include "TRAP.H"

/* The trap menu's entries, in the order dat_str_set_trap_cancel_remote lists them. */
enum trap_menu_entry {
    TRAP_MENU_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    TRAP_MENU_CANCEL = 0,
    TRAP_MENU_REMOTE_CONTROL = 1,
    TRAP_MENU_BOOBY_TRAP = 2
};

/* Put a grenade in the first free slot: ask which kind when there is no
 * animation to run, and when there is, start a player's throw a walking step
 * back to his right, a step being two or three pixels. */
INT c_add_grenade(INT x, INT y, INT dir, INT anim, INT flags)
{
    INT v0j;    /* the slot being tried */
    INT v1l;    /* the direction the step comes from */
    INT v2n;    /* which kind the prompt answered */

    /* Take the first of the sixteen slots that is free. */
    for (v0j = 0; v0j < 16; v0j++)
        if (asm_grenades[v0j].flags == -1) {
        /* A grenade the player throws starts a step behind him to his right; a guard's starts where he stands. */
        if ((flags & 0x80) == 0 && anim != -1) {
            v1l = ((dir + 2) & 7) + 1;
            x += dat_move_dx[v1l];
            y += dat_move_dy[v1l];
        }
        /* Where it starts, which way it goes, and what kind it is. */
        asm_grenades[v0j].x = x;
        asm_grenades[v0j].y = y;
        asm_grenades[v0j].dir = dir;
        asm_grenades[v0j].flags = flags;
        /* A throw flies longer the further it is thrown, and the throw is heard. */
        if (anim != -1) {
            asm_grenades[v0j].timer = anim * 10;
            c_sound_command(12);
        } else {
            /* Otherwise it is set as a trap: ask how, the keypad working as arrows in the menu. */
            c_view_save();
            NUM_LOCK_OFF();
            strcpy(shm_scratch, dat_str_set_trap_cancel_remote);
            v2n = c_ask_menu(shm_scratch, 30, 50);
            NUM_LOCK_ON();
            /* A trap actually set uses up a grenade of its kind. */
            if (v2n > 0) {
                c_sound_command(11);
                asm_ammunition[flags]--;
        }
        /* Cancelling frees the slot; a remote waits for the detonate key, a booby trap for a guard. */
        switch (v2n) {
        case TRAP_MENU_CANCEL:
            asm_grenades[v0j].flags = -1;
            break;
        case TRAP_MENU_REMOTE_CONTROL:
            asm_grenades[v0j].timer = 0xd8f1;
            break;
        case TRAP_MENU_BOOBY_TRAP:
            asm_grenades[v0j].timer = 0xd8f2;
            break;
        }
        /* Put the view back, and show the new trap on the floor plan. */
        c_view_restore();
        if (v2n == TRAP_MENU_REMOTE_CONTROL || v2n == TRAP_MENU_BOOBY_TRAP)
            c_draw_plan(180, 100, 3);
        }
        break;
    }
    /* The player's grenade counts have changed, so redraw his panel. */
    if ((flags & 0x80) == 0)
        c_draw_kit_panel();
}
