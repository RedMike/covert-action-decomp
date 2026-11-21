/* CLUELIST.C -- the page of every clue about one crime role.
 */
#include "GAME.H"
#include "SPRITES.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "FRAME.H"
#include "CASE.H"
#include "LINES.H"
#include "PANEL.H"
#include "FACES.H"
#include "ALERTLVL.H"

/* Show every clue about crime role `nth`: first each one with its source as
 * text, then the ones that show a face, with a picture and a verdict. */
INT c_clue_list(INT nth)
{
    INT v0j;    /* the suspect a clue names */
    INT v1l;    /* where the clue's line is drawn */
    INT v2n;    /* the row the next one goes on */
    INT v3;     /* the clue being shown */

    /* A page titled "Clue". */
    c_page_frame(dat_str_clue_2, 14);
    v2n = 16;
    /* Each clue about the role, in the order turned up. */
    for (v3 = 0; v3 < 80; v3++)
        if (shm_clues_shown[v3].role == nth) {
            /* Every clue after the first on a sheet of its own, laid over at a random indent. */
            v1l = c_random_below(12) + 4;
            if (v2n != 16)
                c_text_panel(v1l, v2n - 2);
            /* "Source: <organisation>/<city>", then the clue in its own words. */
            shd_screen->bg_pen = 15;
            strcpy(shm_scratch, &dat_str_source_3);
            strcat(shm_scratch,
                       shm_orgs[shm_clues_shown[v3].org].long_name);
            strcat(shm_scratch, dat_str_slash_6);
            strcat(shm_scratch,
                       shm_cities[shm_clues_shown[v3].city].name);
            strcat(shm_scratch, dat_str_nl_7);
            c_clue_line_full(v3);
            strcat(shm_scratch, dat_str_nl_8);
            v2n = c_draw_message(32, v1l + 8, v2n, 5);
            v2n += 4;
        }
    v2n = 16;
    /* Then each clue about the role that shows a face, three at most. */
    for (v3 = 0; v3 < 80; v3++)
        if (shm_clues_shown[v3].role == nth
            && shm_clues_shown[v3].subject >> 8 == 1) {
        /* Phrasing the clue sets the face it shows; the text itself is not drawn. */
        shm_scratch[0] = 0;
        c_clue_line(v3);
        /* The portrait clipped to the page, always at the same spot. */
        c_draw_face_panel(shm_menu_face, 264, 16);
        c_draw_sprite(SPRITE_PAPERCLIP, 299, 40);
        /* Stamped with what has become of the role's suspect. */
        v0j = shm_crime_roles[shm_clues_shown[v3].role].suspect;
        if (shm_suspects[v0j].alert_level == ALERT_ARRESTED)
            c_write_text_trimmed(dat_str_arrested_4, 258, 52, 12);
        if (shm_suspects[v0j].alert_level == ALERT_HIDING)
            c_write_text_trimmed(dat_str_hiding_4, 258, 52, 12);
        if (shm_suspects[v0j].alert_level == ALERT_TURNED)
            c_write_text_trimmed(dat_str_turned_5, 258, 52, 12);
        /* The row only counts the portraits: it never moves them. */
        v2n += 64;
        if (v2n > 144)
            break;
        }
    c_wait_key();
}
