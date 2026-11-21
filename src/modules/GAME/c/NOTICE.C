/* NOTICE.C -- playing a full-screen animation, and sending sound commands.
 */
#include "GAME.H"
#include "LOADDISK.H"
#include "ANI_PLAY.H"
#include "NOTICE.H"

/* Play the animation file `text` names, from `edge` to `last`.
 *
 * With animations off in shm_options or disk 4 not in the drive, the screen
 * right of `edge` is only blanked. Otherwise the screen is saved first, and
 * the palette, colour map and page are put back after it.
 */
void c_notice(char *text, INT edge, INT last)
{
    INT saved;

    /* No animation to be had: blank the screen right of `edge` and make sure the usual disk is back. */
    if ((shm_options & OPT_ANIMATION) == 0 || c_want_disk(4, (LONG) 0) == 0) {
        drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
        drv_real_fill_rect(shd_screen, edge, 0, 320 - edge, 200, 5);
        c_want_disk(shd_pan_disk, (LONG) 1);
        return;
    }
    /* Keep a copy of the screen as it was. */
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, shd_map_page, 0, 0);
    /* Play the named animation, keeping the screen's background pen across it. */
    strcpy(dat_str_animation_pan, text);
    saved = shd_screen->bg_pen;
    c_seq_play(dat_str_animation_pan, 0xffff, edge, last);
    shd_screen->bg_pen = saved;
    /* Afterwards the city picture must be reloaded, and the disk, palette, colours and page put back. */
    shd_city_on_screen = 0xffff;
    c_want_disk(shd_pan_disk, (LONG) 1);
    drv_jump_gfx_set_palette(&dat_palette_game);
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
    drv_jump_gfx_show_page(0);
}
