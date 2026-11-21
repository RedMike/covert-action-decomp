/* CASE-CLUE-SHOW.C -- the screen showing one clue, and the text it is made of.
 *
 * A record holds two words rather than two strings, what the clue is *about*
 * and what it *reads* like, each a kind in the high byte and the thing in the
 * low, so two clues are related exactly when their words are equal.
 */
#include "FINAL.H"
#include "SPRITES.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "SCREEN.H"
#include "CMISEND.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "CASERUN.H"
#include "CLUEFACT.H"

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

/* shared_include_start: ../../../../shared/c/CLUE-ABOUT.C -- generated */
/* CLUE-ABOUT.C -- c_clue_about, packing what a clue says into one word.
 */

/* Pack fact `what` of clue record `slot` into a word: the fact in the high
 * byte and what it names in the low one. Naming an organisation or city counts
 * it in shm_activity.
 */
INT c_clue_about(INT slot, INT what)
{
    INT suspect;   /* the suspect filling the clue's role */

    suspect = shm_crime_roles[shm_clues_shown[slot].role].suspect;
    switch (what) {
    case CLUE_CITY:
        shm_activity.city[shm_suspects[suspect].city]++;
        return what * 0x100
               + shm_suspects[suspect].city;

    case CLUE_ORG:
        shm_activity.org[shm_suspects[suspect].org]++;
        shm_orgs[shm_suspects[suspect].org].known |= 1;
        strcat(shm_scratch,
                   shm_orgs[shm_suspects[suspect].org].long_name);
        return what * 0x100
               + shm_suspects[suspect].org;

    case CLUE_FACE:
        return what * 0x100 + suspect;

    case CLUE_NAME:
        return what * 0x100 + suspect;

    case CLUE_ROLE:
        return what * 0x100
               + shm_clues_shown[slot].role;

    }
}
/* shared_include_end: ../../../../shared/c/CLUE-ABOUT.C */

/* shared_include_start: ../../../../shared/c/CLUE-TEXT.C -- generated */
/* CLUE-TEXT.C -- c_clue_text, the word saying what a role's clue reads as.
 */

/* The word a clue about crime role `cell` reads as: a clue type in the high
 * byte and the role's clue_id in the low one, halved unless `full`.
 */
INT c_clue_text(INT cell, INT full)
{
    INT num;
    INT shade;
    char key[8];

    shade = *(unsigned char *) &shm_crime_roles[cell].clue_id;
    if (full != 0)
        shade &= 0x7f;
    else
        shade >>= 1;
    if (shm_crime_role_count - shm_difficulty * 4 > cell)
        return shm_crime_roles[cell].clue_type * 256
               + shade;
    num = shm_suspects[shm_crime_roles[cell].suspect].visuals;
    strcpy(key, shd_key_clue);
    key[5] += num % 6;
    key[3] += (num >> 3) % 4;
    num = strlen(shm_scratch);
    c_say_block_with(shd_str_clues_txt, key, shd_clue_keys,
                       shd_subst_values, 5);
    (shm_scratch)[num] = 0;
    return (*((char *) &shm_scratch[1] + num) & 0xf) * 256 + shade;
}
/* shared_include_end: ../../../../shared/c/CLUE-TEXT.C */

/* shared_include_start: ../../../../shared/c/CLUE-LINE.C -- generated */
/* CLUE-LINE.C -- c_clue_line, a clue record as an assembled phrase.
 */

/* Append clue record `nth` to shm_scratch as a phrase: the clue's thing, the
 * joining words and the subject, a half left out where its word is -1.
 */
void c_clue_line(INT nth)
{
    if (shm_clues_shown[nth].text != -1) {
        c_clue_thing(shm_clues_shown[nth].text);
        strcat(shm_scratch,
                   (char *) shd_clue_phrases[
                       c_clue_phrase(
                           shm_clues_shown[nth].subject,
                           shm_clues_shown[nth].text)]);
    }
    if (shm_clues_shown[nth].subject != -1) {
        c_clue_subject(nth,
                        shm_clues_shown[nth].subject);
        strcat(shm_scratch, shd_str_period);
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-LINE.C */

/* shared_include_start: ../../../../shared/c/CLUE-PHRASE.C -- generated */
/* CLUE-PHRASE.C -- c_clue_phrase, choosing the words that join up a clue.
 */

/* Which of the forty phrases in shd_clue_phrases joins a clue to its subject:
 * the run of five by the clue type in `kind`, the place in it by the fact bit
 * in `about`.
 */
INT c_clue_phrase(INT about, INT kind)
{
    INT pick;
    INT step;

    pick = ((kind >> 8) & 7) * 5;
    for (step = about >> 8; step > 1; step >>= 1)
        pick++;
    return pick;
}
/* shared_include_end: ../../../../shared/c/CLUE-PHRASE.C */

/* shared_include_start: ../../../../shared/c/CLUE-SUBJECT.C -- generated */
/* CLUE-SUBJECT.C -- c_clue_subject, naming what a clue is about.
 */

/* Append what clue record `nth` is about, from `about`: the fact in the high
 * byte and what it names in the low one.
 */
void c_clue_subject(INT nth, INT about)
{
    INT who;

    who = (unsigned char) about;
    switch (about >> 8) {
    case CLUE_CITY:
        strcat(shm_scratch, shm_cities[who].name);
        break;
    case CLUE_ORG:
        strcat(shm_scratch, shm_orgs[who].long_name);
        shm_orgs[who].known |= 1;
        break;
    case CLUE_NAME:
        c_person_real_name(who);
        break;
    case CLUE_FACE:
        strcat(shm_scratch, shd_str_face);
        shm_menu_face = shm_suspects[who].visuals;
        break;
    case CLUE_ROLE:
        if (shm_clues_shown[nth].role
            < shm_crime_role_count - shm_difficulty * 4)
            strcat(shm_scratch, shd_str_valkerie);
        else
            strcat(shm_scratch, shd_str_thunderbolt);
        break;
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-SUBJECT.C */

/* shared_include_start: ../../../../shared/c/CLUE-THING.C -- generated */
/* CLUE-THING.C -- c_clue_thing, naming the object a clue is about.
 */

/* Append the thing the clue word `about` names, unless it is -1: its name from
 * shd_clue_kinds and its number. Types 5 and 6 are money, in hundreds and
 * thousands.
 */
void c_clue_thing(INT about)
{
    if (about != -1) {
        strcat(shm_scratch,
                   (char *) ((rt_addr (*)[8]) &shd_clue_kinds[16])
                   [(about >> 8) & 0xf][(about >> 4) & 7]);
        strcat(shm_scratch,
                   (char *) itoa((about & 0x3f) + 1, shm_clue_digits, 10));
        if (((about >> 8) & 0xf) == 5)
            strcat(shm_scratch, shd_str_00);
        if (((about >> 8) & 0xf) == 6)
            strcat(shm_scratch, shd_str_000);
    }
}
/* shared_include_end: ../../../../shared/c/CLUE-THING.C */

/* shared_include_start: ../../../../shared/c/CLUE-FULL.C -- generated */
/* CLUE-FULL.C -- c_clue_line_full, a clue record as its own line.
 */

/* Append clue record `nth` as its own line from clues.txt rather than as an
 * assembled phrase.
 */
void c_clue_line_full(INT nth)
{
    c_clue_from_file(shm_clues_shown[nth].subject,
                    shm_clues_shown[nth].text, nth);
}
/* shared_include_end: ../../../../shared/c/CLUE-FULL.C */

/* shared_include_start: ../../../../shared/c/CLUE-FROM-FILE.C -- generated */
/* CLUE-FROM-FILE.C -- c_clue_from_file, a clue's own line from clues.txt.
 */

/* Append clue record `nth`'s line from clues.txt, keyed by the clue type in
 * `kind` and the fact in `about`, with its fields filled in; a face only sets
 * shm_menu_face.
 */
void c_clue_from_file(INT about, INT kind, INT nth)
{
    INT num;
    INT here;
    char seek[8];
    INT cut;

    /* The clue's line in clues.txt is keyed by the clue's type and by which fact it tells. */
    num = (unsigned char) about;
    strcpy(seek, shd_key_clue_2);
    seek[2] += (kind >> 8) & 0xf;
    for (here = about >> 8; here > 1; here >>= 1)
        seek[3]++;
    /* The object the clue turns on becomes $KEY, built at the buffer's end and cut off again. */
    here = strlen(shm_scratch);
    c_clue_thing(kind);
    strcpy((char *) shd_subst_values[0],
               (char *) shm_scratch + here);
    (shm_scratch)[here] = 0;
    /* Most lines are led by one character, the method, which is cut off the text. */
    cut = 1;
    switch (about >> 8) {
    /* A face is shown beside the text rather than written into it. */
    case 1:
        shm_menu_face = shm_suspects[num].visuals;
        break;
    /* The suspect's real name becomes $NAME. */
    case 2:
        c_person_real_name(num);
        strcpy((char *) shd_subst_values[1],
                   (char *) shm_scratch + here);
        (shm_scratch)[here] = 0;
        break;
    /* The organisation becomes $ORG. */
    case 4:
        strcpy((char *) shd_subst_values[2],
                   shm_orgs[num].long_name);
        break;
    /* The city becomes $CITY. */
    case 8:
        strcpy((char *) shd_subst_values[3],
                   shm_cities[num].name);
        break;
    /* The role itself has a line of its own, led by two characters to cut. */
    case 0x10:
        cut = 2;
        /* A real role's line is keyed by the case's mission and the role. */
        if (shm_clues_shown[nth].role
            < shm_crime_role_count - shm_difficulty * 4) {
            strcpy(seek, shd_key_clue_3);
            seek[5] += num;
            seek[3] += shm_mission % 10;
            seek[2] += shm_mission / 10;
        /* A red herring's line is picked by bits of its suspect's face instead. */
        } else {
            here = shm_suspects[shm_crime_roles[shm_clues_shown[nth].role].suspect].visuals;
            strcpy(seek, shd_key_clue_4);
            seek[5] += here % 6;
            seek[3] += (here >> 3) % 4;
        }
        break;
    }
    /* Append the line with the fields filled in. */
    here = strlen(shm_scratch);
    c_say_block_with(shd_str_clues_txt_2, seek, shd_clue_keys,
                       shd_subst_values, 5);
    /* Keep the lead character as the clue's method, and cut the lead off the text. */
    shm_clue_method = *((char *) shm_scratch + here) & 0xf;
    OVERLAPPING_STRCPY((char *) shm_scratch + here,
               (char *) shm_scratch + here + cut);
}
/* shared_include_end: ../../../../shared/c/CLUE-FROM-FILE.C */
