/* MAIN.C -- the module's entry point: set the puzzle up, run it, hand back.
 */
#include "CODE.H"
#include "SETUP.H"
#include "RANDOM.H"
#include "PUZZLE.H"
#include "PLAY.H"
#include "LOADDISK.H"
#include "RESULT.H"

/* Set the board up from the shared block, run the puzzle, and hand back.
 *
 * The case's difficulty less the agent's skill sets how hard it is; bit 5 of
 * the options, a real case rather than practice, picks what runs next.
 */
void c_main(void)
{
    /* Until the puzzle is over, nothing runs next. */
    COMM()->next_module = NONE_EXIT;
    /* Reach the drivers COVERT loaded, and open the screen in paper colours. */
    drv_real_link_slots(COMM()->driver_segment[0]);
    drv_real_link_slots(COMM()->driver_segment[1]);
    drv_real_link_slots(COMM()->driver_segment[2]);
    drv_jump_gfx_open(0);
    drv_jump_gfx_set_colour_map(&shd_colours_paper, &shd_colours_paper);
    /* A better cryptographer gets an easier puzzle. */
    asm_difficulty = c_clamp(
        COMM()->difficulty - (((INT) COMM()->skills >> 4) & 3) + 1, -3, 5);
    shm_options = COMM()->options;
    shm_graphics_letter = COMM()->graphics_letter;
    shd_screen->font = 1;
    shd_screen->bg_pen = 15;
    /* Make up the puzzle and put it on screen. */
    c_seed_random();
    c_puzzle_set();
    c_puzzle_draw();
    /* Play until the puzzle is solved or abandoned. */
    do {
        c_play_turn();
    } while (shm_finished == 0);
    /* Report whether it was solved, how long it took, and what runs next. */
    COMM()->result[RES_CODE_SOLVED] = asm_solved;
    COMM()->result[RES_MINUTES] = shm_clock_minutes;
    COMM()->next_module = (shm_options & OPT_PRACTICE) ? FINAL_PRACTICE_OVER : GAME_CAMPAIGN;
    /* Hand back, and ask for the disk the next module is on. */
    c_hook_hand_back(LONG_LIT(0));
    shd_screen->font = 1;
    c_want_disk((shm_options & OPT_PRACTICE) ? 1 : 2, LONG_LIT(1));
}
