/* PASSWORD.C -- asking for the password, and the panel it is asked in.
 */
#include "TAC.H"
#include "PASSWORD.H"
#include "RANDOM.H"
#include "CITY.H"
#include "PANEL.H"
#include "MAPDRAW.H"
#include "RANGE.H"
#include "RESTORE.H"
#include "RADAR.H"
#include "REVEAL.H"
#include "SEARCH.H"
#include "TYPE.H"

/* Ask for the password and act on the answer: the right one opens the files to
 * a search and may raise the alarm anyway, the wrong one always raises it. */
INT c_ask_password(void)
{
    /* Keep the room's view to put back once the panel is done with. */
    c_view_save();
    /* Ask, and let the player type an answer from blank. */
    c_question_panel(dat_str_enter_password);
    shm_scratch[0] = 0;
    /* Escape walks away from the terminal with nothing tried. */
    if ((INT) c_type_message(116, 100, 12) != -1) {
        /* Clear the panel for the verdict. */
        c_question_panel(dat_str_empty_19);
        /* The password, upper or lower case, lets the player search the files;
         * the harder the game, the likelier the alarm goes off here anyway. */
        if (strcmpi(shm_scratch, asm_password_text) == 0) {
            c_draw_centred(dat_str_access_confirmed, 160, 103, 10);
            c_search_names();
            if (c_random_below(3) < asm_difficulty_was)
                c_room_distances(asm_room_last, 240);
        } else {
            /* A wrong one sets the alarm off here, and the refusal stays up a moment. */
            c_draw_centred(dat_str_access_denied, 160, 103, 12);
            c_room_distances(asm_room_last, 240);
            c_wait_retraces(90);
        }
        /* Every try changes the password, so the hint so far is lost. */
        c_pick_password();
    }
    /* Back to the room's colours, view and kit panel. */
    shd_screen->bg_pen = 1;
    drv_jump_gfx_set_colour_map(&dat_colours_tactical, &dat_colours_tactical);
    c_view_restore();
    c_draw_kit_panel();
}

/* The panel the question is asked in: a shaded box, its highlights, and the
 * line of text across the middle. */
INT c_question_panel(rt_addr text)
{
    /* The panel is drawn in its own colours. */
    drv_jump_gfx_set_colour_map(&dat_colours_badge, &dat_colours_badge);
    /* The box, with a frame of the other shade just inside its edge. */
    c_fill_box(99, 85, 221, 114, 8);
    c_fill_box(100, 87, 220, 113, 5);
    c_fill_box(101, 88, 219, 112, 8);
    /* The well the answer is typed into and the verdict shown in. */
    c_fill_box(105, 101, 215, 110, 5);
    /* Lines picking out the frame's top, the well's top and sides, and the bottom. */
    c_draw_line(101, 86, 219, 86, 7);
    c_draw_line(103, 99, 217, 99, 5);
    c_draw_line(102, 112, 218, 112, 5);
    c_draw_line(104, 101, 104, 110, 7);
    c_draw_line(216, 101, 216, 110, 7);
    /* The line of text, above the well. */
    c_draw_centred((str_addr) text, 161, 90, 2);
}
