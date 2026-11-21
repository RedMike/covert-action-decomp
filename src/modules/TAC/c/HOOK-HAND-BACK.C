/* HOOK-HAND-BACK.C -- the hook c_hook_hand_back in MAIN.C's unit, after MAIN.C. */
#include "TAC.H"
#include "BLIP.H"
#include "KEYSHIFT.H"
#include "LOADDISK.H"
#include "RANDOM.H"
#include "PAGESHOW.H"
#include "CITY.H"
#include "MENU.H"
#include "CASE.H"
#include "NOTHING.H"
#include "TILES.H"
#include "ANI_LD2.H"
#include "PLANT.H"
#include "REVEAL.H"
#include "TURN.H"
#include "MODOPTS.H"
#include "RESULT.H"
#include "ALERTLVL.H"

/* Give the keyboard's shift state back, and stop the game if asked to; only
 * the argument's low word is read. Under FIX_TAC_MOVE the key repeat also
 * goes back to DOSBox's own half second and 30 a second: what it was before
 * cannot be read. */
void c_hook_hand_back(LONG stop)
{
#ifdef FIX_TAC_MOVE
    if (MOD_ON(fast_tac_move)) {
        /* Undo the fix's faster key repeat, so the rest of the game types as usual. */
        asm_regs.x.ax = 0x0305;
        asm_regs.x.bx = 0x0100;
        INTERRUPT(0x16, &asm_regs, &asm_regs);
    }
#endif
    /* Num Lock goes back off for whatever runs next. */
    NUM_LOCK_OFF();
    /* Quitting ends the session: no module runs after this one. */
    if ((INT) stop != 0)
        COMM()->next_module = NONE_EXIT;
}
