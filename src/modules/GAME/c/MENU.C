/* MENU.C -- running a menu on a cleared screen.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "ADVICE.H"
#include "DIALOG.H"

/* Run a menu, clearing the screen first if the last thing on it was not a
 * menu. */
INT c_ask_menu(rt_addr title, INT x, INT y)
{
    /* After anything but a menu, start on a clean screen with the status bar redrawn. */
    if (asm_last_screen != -1) {
        c_clear_for_menu();
        c_campaign_tick(0);
        asm_last_screen = -1;
    }
    /* Then let the player pick, and answer the pick. */
    return c_menu_run(title, x, y);
}

/* Clear the whole screen to colour 5. */
INT c_clear_for_menu(void)
{
    INT v0j;
    INT v1a;

    /* The menus' background colour, over the whole 320 by 200 screen. */
    shd_screen->bg_pen = 5;
    drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 5);
}
