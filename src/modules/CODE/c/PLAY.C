/* PLAY.C -- one turn of the puzzle: waiting for a key and acting on it.
 */
#include "CODE.H"
#include "KEYCODES.H"
#include "CLOCK.H"
#include "SOLVED.H"
#include "SETUP.H"
#include "PUZZLE.H"
#include "PLAY.H"
#include "MENU.H"
#include "KEYREAD.H"
#include "RETRACE.H"

/* One turn: idle until a key comes, then act on it. Escape gives up, Alt-Q
 * quits, Alt-P pauses, Alt-S toggles sound, F1 gives a letter away, F10 clears
 * the guesses back to the given letters, and a letter key sets its guess.
 *
 * The solved check sits in the F1 case and is written `!= 0` around the fill,
 * as shipped.
 */
void c_play_turn(void)
{
    INT letter;
    INT from;
    INT index;
    INT read;

    for (;;) {
        /* The clock runs while the player thinks. */
        c_wait_retraces(10);
        asm_clock_seconds++;
        c_clock_draw(asm_clock_seconds);
        if (kbhit() == 0)
            continue;
        read = c_menu_key();
        letter = read - 'a';
        switch (read) {
        /* Give up. */
        case KEY_ESC:
            shm_finished = 1;
            return;
        /* Buy a letter for an hour on the clock. */
        case KEY_F1:
            c_hint_animate();
            c_give_letter();
            c_draw_guesses();
            asm_clock_seconds += 3600;
            break;
        /* Wipe the player's own guesses, keeping the letters given. */
        case KEY_F10:
            c_fill_guess_row();
            c_draw_guesses();
            return;
        /* Quit the game once the player says they are sure, keeping the screen underneath. */
        case KEY_ALT_Q:
            drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
            if (c_menu_run(dat_str_sure_want_quit_no, 80, 80) == 1) {
                c_hook_hand_back(LONG_LIT(1));
                exit(UNSET_ARGS(0));
            }
            drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen, 0, 0);
            break;
        /* Sound on or off. */
        case KEY_ALT_S:
            shm_options ^= OPT_SOUND;
            break;
        /* Pause, with the puzzle hidden so it cannot be worked on meanwhile. */
        case KEY_ALT_P:
            drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
            drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 0);
            shm_menu_draw_only = 1;
            c_menu_run(dat_str_paused, 128, 81);
            c_menu_key();
            drv_jump_gfx_copy_rect(shd_map_page, 0, 0, 320, 200, shd_screen, 0, 0);
            break;
        /* A letter picks a cipher letter, and the next key is the guess for it. */
        default:
            if (letter < 0 || letter >= asm_alphabet_size)
                continue;
            c_flash_letter(letter);
            /* Anything but a letter clears the guess. */
            index = c_menu_key();
            index -= 'a';
            if (index < 0 || index >= asm_alphabet_size)
                dat_guess[letter] = ' ';
            else
                dat_guess[letter] = index + 'A';
            c_sound_command(45);
            c_draw_guesses();
            break;
        }
        /* Once enough is right, fill in the rest and say the message is decoded. */
        if (c_is_solved() != 0) {
            shm_finished = 1;
            asm_solved = 1;
            for (from = 0; from < asm_alphabet_size; from++) {
                read = (char) dat_cipher[from] - 'A';
                dat_guess[read] = dat_plain[from];
            }
            c_sound_command(46);
            c_draw_guesses();
            c_menu_run(dat_str_message_decoded, 100, 2);
        }
        return;
    }
}
