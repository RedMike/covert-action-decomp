/* CLUE.C -- the clue screen one tapped fact produces.
 */
#include "BUG.H"
#include "SPRITES.H"
#include "PRIMS.H"
#include "SCREEN.H"
#include "TEXTLAY.H"
#include "FACES.H"
#include "BOARD.H"
#include "REPORT.H"

/* shared_include_start: ../../../../shared/c/CLUE-RECORD.C -- generated */
/* CLUE-RECORD.C -- c_clue_record, filing a new clue and showing it.
 */

/* File fact `bit` about crime role `cell`, from organisation `org` in `city`,
 * in the first free clue record unless already given, then show it with the
 * records sharing its text.
 */
UNSIGNED_INT c_clue_record(INT org, INT city, INT cell, INT bit)
{
    INT phase;
    INT inert;
    INT stray;
    INT pad;
    INT spot;
    INT pad2;
    INT line;
    INT scrap;
    INT into;
    INT match;
    INT shown;

    if ((shm_crime_roles[cell].clues_known & bit) == 0) {
        for (into = 0; into < 0x50; into++)
            if (shm_clues_shown[into].role == -1) {
            shm_clues_shown[into].org = org;
            shm_clues_shown[into].city = city;
            shm_clues_shown[into].role = cell;
            if (bit > 0x1f)
                bit >>= 5;
            shm_clues_shown[into].subject =
                c_clue_about(into, bit);
            shm_clues_shown[into].text =
                c_clue_text(cell, 0);
            shm_crime_roles[cell].clues_known |= bit;
            c_page_frame(shd_str_clue, 9);
            shd_screen->bg_pen = 0xf;
            strcpy(shm_scratch, &shd_str_source_2);
            strcat(shm_scratch, shm_orgs[shm_clues_shown[into].org].long_name);
            strcat(shm_scratch, shd_str_slash_source);
            strcat(shm_scratch, shm_cities[shm_clues_shown[into].city].name);
            strcat(shm_scratch, shd_str_newline_9);
            c_clue_line_full(into);
            if (shm_clues_shown[into].org > 1)
                shm_clue_method = shm_wire_clue_source == 1 ? 1 : 0;
            strcat(shm_scratch, shd_str_method_stop);
            strcat(shm_scratch, (char *) shd_clue_source[shm_clue_method]);
            c_draw_message(0x1f, 0x10, 0x11, 5);
            if (bit == 1) {
                c_draw_face_panel(shm_menu_face, 0x108, 0x12);
                c_draw_sprite(SPRITE_PAPERCLIP, 0x12b, 0x2e);
            } else
                c_draw_sprite(shm_clue_method + SPRITE_CLUE_SOURCE, 0x110,
                              0x10);
            c_write_text_trimmed(&shd_str_related_2, 0x10, 0x42, 5);
            line = 0x4c;
            shown = 0;
            spot = 0x49;
            for (phase = 0; phase < 2; phase++)
                for (match = 0; match < 0x50; match++) {
                    if (shm_clues_shown[match].role
                        == -1)
                        continue;
                    if (into == match)
                        continue;
                    if (line > 0xb4)
                        break;
                    if (!((phase != 0
                           && shm_clues_shown[into].subject
                              == shm_clues_shown[match].subject)
                          || (phase == 0
                              && shm_clues_shown[into].text
                                 == shm_clues_shown[match].text)))
                        continue;
                    shm_scratch[0] = 0;
                    pad = c_random_below(0xc) + 4;
                    c_text_panel(pad, line - 2);
                    if (shm_clues_shown[match].subject
                        >> 8 == 0x10)
                        c_clue_line_full(match);
                    else
                        c_clue_line(match);
                    strcat(shm_scratch, shd_str_newline_10);
                    shown = 1;
                    line = c_draw_message(0x20, pad + 8, line, 0);
                    line += 4;
                    if (shm_clues_shown[match].subject
                        >> 8 == 1) {
                        c_draw_face_panel(
                            shm_suspects[shm_crime_roles[shm_clues_shown[match].role].suspect].visuals,
                            0x108, c_clamp(spot, 0, 0x96));
                        c_draw_sprite(SPRITE_PAPERCLIP, 0x12b,
                                        c_clamp(spot + 0x18, 0,
                                                           0xb0));
                        spot += 0x28;
                    }
                }
            if (shown == 0)
                c_write_text_trimmed(shd_str_none, 0x10, 0x48, 5);
            c_wait_key();
            shm_menu_face = -1;
            into = 999;
        }
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-RECORD.C */
