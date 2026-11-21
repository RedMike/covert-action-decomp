/* CASE-3.C -- more of the module's own routines in CASE.C's unit, after shared/CASE-2.C. */
#include "GAME.H"
#include "SPRITES.H"
#include "CASE.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "DIALOG.H"
#include "FRAME.H"
#include "BLOCK.H"
#include "LINES.H"
#include "PLAUSIBL.H"
#include "SUSPECT.H"
#include "SUSPECTS.H"
#include "PANEL.H"
#include "FACES.H"
#include "HANDOVER.H"
#include "TAG.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "CLUEFACT.H"

/* Recording the clue organisation `org` in `city` has just turned up about
 * crime role `cell`, and showing it with every known clue it connects to. */
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

    /* Only a fact the role has not given yet makes a new clue. */
    if ((shm_crime_roles[cell].clues_known & bit) == 0) {
        /* It goes in the first free clue record, with where it came from. */
        for (into = 0; into < 80; into++)
            if (shm_clues_shown[into].role == -1) {
            shm_clues_shown[into].org = org;
            shm_clues_shown[into].city = city;
            shm_clues_shown[into].role = cell;
            /* A bit above the five fact bits is shifted down onto them. */
            if (bit > 0x1f)
                bit >>= 5;
            /* What it tells and how it reads, and the role has now given it. */
            shm_clues_shown[into].subject =
                c_clue_about(into, bit);
            shm_clues_shown[into].text =
                c_clue_text(cell, 0);
            shm_crime_roles[cell].clues_known |= bit;
            /* The clue page, opening with the Source: line. */
            c_page_frame(dat_str_clue, 9);
            shd_screen->bg_pen = 15;
            strcpy(shm_scratch, &dat_str_source_2_2);
            strcat(shm_scratch, shm_orgs[shm_clues_shown[into].org].long_name);
            strcat(shm_scratch, dat_str_slash);
            strcat(shm_scratch, shm_cities[shm_clues_shown[into].city].name);
            strcat(shm_scratch, dat_str_newline_9);
            /* Then the clue itself in full. */
            c_clue_line_full(into);
            /* Out of an enemy organisation, the method is the watch's: wiretap or clandestine photo. */
            if (shm_clues_shown[into].org > 1)
                shm_clue_method = shm_wire_clue_source == 1 ? 1 : 0;
            strcat(shm_scratch, dat_str_method_stop);
            strcat(shm_scratch, (char *) dat_clue_source[shm_clue_method]);
            c_draw_message(31, 16, 17, 5);
            /* A face clue pins the face to the page; any other shows the method's picture. */
            if (bit == 1) {
                c_draw_face_panel(shm_menu_face, 264, 18);
                c_draw_sprite(SPRITE_PAPERCLIP, 299, 46);
            } else
                c_draw_sprite(shm_clue_method + SPRITE_CLUE_SOURCE, 272, 16);
            /* Below, the clues it connects to, with any faces stacked down the right. */
            c_write_text_trimmed(&dat_str_related_2, 16, 66, 5);
            line = 76;
            shown = 0;
            spot = 73;
            /* First those that read the same, then those that tell about the same thing. */
            for (phase = 0; phase < 2; phase++)
                for (match = 0; match < 80; match++) {
                    if (shm_clues_shown[match].role
                        == -1)
                        continue;
                    if (into == match)
                        continue;
                    /* No more once the page is full. */
                    if (line > 180)
                        break;
                    if (!((phase != 0
                           && shm_clues_shown[into].subject
                              == shm_clues_shown[match].subject)
                          || (phase == 0
                              && shm_clues_shown[into].text
                                 == shm_clues_shown[match].text)))
                        continue;
                    /* Each on its own white panel, at a random indent. */
                    shm_scratch[0] = 0;
                    pad = c_random_below(12) + 4;
                    c_text_panel(pad, line - 2);
                    /* A role clue is told in full, any other as a phrase. */
                    if (shm_clues_shown[match].subject
                        >> 8 == 0x10)
                        c_clue_line_full(match);
                    else
                        c_clue_line(match);
                    strcat(shm_scratch, dat_str_newline_10);
                    shown = 1;
                    line = c_draw_message(32, pad + 8, line, 0);
                    line += 4;
                    /* A face clue pins its suspect's face down the right, kept on the screen. */
                    if (shm_clues_shown[match].subject
                        >> 8 == 1) {
                        c_draw_face_panel(
                            shm_suspects[shm_crime_roles[shm_clues_shown[match].role].suspect].visuals,
                            264, c_clamp(spot, 0, 150));
                        c_draw_sprite(SPRITE_PAPERCLIP, 299,
                                        c_clamp(spot + 24, 0,
                                                           176));
                        spot += 40;
                    }
                }
            /* Say so when nothing connects. */
            if (shown == 0)
                c_write_text_trimmed(dat_str_none, 16, 72, 5);
            /* Hold the page until a key, then end the search: one record is enough. */
            c_wait_key();
            shm_menu_face = -1;
            into = 999;
        }
    }
}

/* Packing what a clue says into one word: the kind of fact in the high byte
 * and which city, organisation, suspect or role in the low one. */
INT c_clue_about(INT slot, INT what)
{
    INT suspect;   /* the suspect filling the clue's role */

    suspect = shm_crime_roles[shm_clues_shown[slot].role].suspect;
    switch (what) {
    /* The suspect's city, which now counts in the activity report. */
    case CLUE_CITY:
        shm_activity.city[shm_suspects[suspect].city]++;
        return what * 0x100
               + shm_suspects[suspect].city;

    /* The suspect's organisation: counted, now heard of, and named in the text. */
    case CLUE_ORG:
        shm_activity.org[shm_suspects[suspect].org]++;
        shm_orgs[shm_suspects[suspect].org].known |= 1;
        strcat(shm_scratch,
                   shm_orgs[shm_suspects[suspect].org].long_name);
        return what * 0x100
               + shm_suspects[suspect].org;

    /* A fact about the suspect themself, 1 being the one shown with the face. */
    case CLUE_FACE:
        return what * 0x100 + suspect;

    case CLUE_NAME:
        return what * 0x100 + suspect;

    /* The role in the plot itself. */
    case CLUE_ROLE:
        return what * 0x100
               + shm_clues_shown[slot].role;

    }
}

/* Build the word that says what the clue about crime role `cell` *reads*
 * like. A red herring's kind is read from its clues.txt block, appended to
 * shm_scratch and cut off again. */
INT c_clue_text(INT cell, INT full)
{
    INT num;
    INT shade;
    char key[8];

    /* The low byte is the role's clue id: its low seven bits, or halved. */
    shade = *(unsigned char *) &shm_crime_roles[cell].clue_id;
    if (full != 0)
        shade &= 0x7f;
    else
        shade >>= 1;
    /* A real role's clue reads as its own clue type. */
    if (shm_crime_role_count - shm_difficulty * 4 > cell)
        return shm_crime_roles[cell].clue_type * 256
               + shade;
    /* A red herring's block, "*C0000" with two digits stepped, is picked by its suspect's random visuals word. */
    num = shm_suspects[shm_crime_roles[cell].suspect].visuals;
    strcpy(key, dat_key_clue);
    key[5] += num % 6;
    key[3] += (num >> 3) % 4;
    /* Read it onto the end of the text only to see its kind, then cut it off again. */
    num = strlen(shm_scratch);
    c_say_block_with(dat_str_clues_txt, key, shd_clue_keys,
                       shd_subst_values, 5);
    (shm_scratch)[num] = 0;
    /* The kind is the low nibble of the block's second character. */
    return (*((char *) &shm_scratch[1] + num) & 0xf) * 256 + shade;
}
