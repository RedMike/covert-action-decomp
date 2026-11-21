/* PANEL.C -- text pages and panels: messages, names, presence, distances.
 */
#include "TAC.H"
#include "SPRITES.H"
#include "PANEL.H"
#include "CITY.H"
#include "CASE.H"
#include "TILES.H"
#include "FACES.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* shared_include_start: ../../../../shared/c/WRAP-MESSAGE.C -- generated */
/* WRAP-MESSAGE.C -- c_wrap_message, wrapping text into lines.
 */

/* Wrap shm_scratch at the first space past `width` characters on each line. A
 * '^' forces a break.
 */
void c_wrap_message(INT width)
{
    INT run;
    INT i;

    run = 0;
    for (i = 0; (INT) strlen(shm_scratch) > i; i++) {
        if ((shm_scratch)[i] == '^') {
            (shm_scratch)[i] = ' ';
            (shm_scratch)[i + 1] = '\n';
            run = -1;
        }
        if ((shm_scratch)[i] == '\n')
            run = -1;
        run++;
        if (run > width && (shm_scratch)[i] == ' '
            && (shm_scratch)[i + 1] != ' ') {
            (shm_scratch)[i] = '\n';
            run = 0;
        }
    }
    if (run > 0)
        strcat(shm_scratch, shd_str_newline_wrap);
}
/* shared_include_end: ../../../../shared/c/WRAP-MESSAGE.C */

/* shared_include_start: ../../../../shared/c/DRAW-MESSAGE.C -- generated */
/* DRAW-MESSAGE.C -- c_draw_message, drawing shm_scratch word-wrapped.
 */

/* Draw shm_scratch from (x, y), wrapped into lines of at most `width` * 8
 * pixels; answer the y the next line would start at. Text past y = 0c0h is
 * left out.
 */
INT c_draw_message(INT width, UNSIGNED_INT x, INT y, UNSIGNED_INT colour)
{
    INT saved;
    INT wide;
    INT space;
    INT start;
    INT n;

    for (n = wide = start = space = 0; (INT) strlen(shm_scratch) > n;
         n++) {
        wide += drv_jump_gfx_char_width(shd_screen->font,
                                  ((char *) shm_scratch)[n]);
        if ((shm_scratch)[n] == ' ' || (shm_scratch)[n] == '\n')
            space = n;
        if ((shm_scratch)[n] == '\n' || width * 8 < wide) {
            saved = ((char *) shm_scratch)[space];
            (shm_scratch)[space] = 0;
            c_write_text_trimmed((rt_addr) shm_scratch + start, x, y,
                               colour);
            (shm_scratch)[space] = saved;
            y += 8;
            wide = 0;
            start = space + 1;
            n = space;
            if (y >= 0xc0)
                break;
        }
    }
    if (wide > 0 && y < 0xc0) {
        c_write_text_trimmed((rt_addr) shm_scratch + start, x, y,
                           colour);
        y += 8;
    }
    return y;
}
/* shared_include_end: ../../../../shared/c/DRAW-MESSAGE.C */

/* shared_include_start: ../../../../shared/c/FILTER-MESSAGE.C -- generated */
/* FILTER-MESSAGE.C -- c_filter_message, keeping only some words of a message.
 */

/* Keep only the words of shm_scratch whose bit in `mask`, counted modulo
 * `mod`, is set, with an ellipsis where words were dropped.
 */
void c_filter_message(INT mask, INT mod)
{
    INT from;
    char kept[512];
    INT keep;
    INT at;
    INT word;

    from = word = keep = 0;
    kept[0] = 0;
    for (at = 0; (INT) strlen(shm_scratch) > at; at++) {
        if ((shm_scratch)[at] == ' '
            || (shm_scratch)[at] == '\n') {
            if (mask & 1 << word % mod) {
                if (keep == 0)
                    from = at + 1;
                keep = 1;
            } else {
                if (keep != 0) {
                    (shm_scratch)[at] = 0;
                    strcat(kept,
                               shm_scratch + from);
                    (shm_scratch)[at] = ' ';
                    strcat(kept, shd_str_ellipsis_2);
                }
                keep = 0;
            }
            word++;
        }
    }
    if (keep != 0)
        strcat(kept, shm_scratch + from);
    strcpy(shm_scratch, kept);
}
/* shared_include_end: ../../../../shared/c/FILTER-MESSAGE.C */

/* shared_include_start: ../../../../shared/c/WORTH-THE-TRIP.C -- generated */
/* WORTH-THE-TRIP.C -- c_worth_the_trip, whether a lead is worth the distance.
 */

/* Whether `other`'s presence in `city` beats the cost of getting there from
 * `org`.
 */
INT c_worth_the_trip(INT org, INT other, INT city)
{
    INT sum;

    sum = c_packed_distance(
              shm_orgs[org].where,
              shm_cities[city].where)
        + c_packed_distance(
              shm_orgs[org].where,
              shm_orgs[other].where) * 3 / 2;
    return c_presence(city, other) * 4 + 0x10 > sum;
}
/* shared_include_end: ../../../../shared/c/WORTH-THE-TRIP.C */

/* shared_include_start: ../../../../shared/c/PACKED-DISTANCE.C -- generated */
/* PACKED-DISTANCE.C -- c_packed_distance, the distance between two positions.
 */

/* The distance between two packed coordinates, a pair of nibbles each: the
 * larger difference doubled plus the smaller.
 */
INT c_packed_distance(INT a, INT b)
{
    INT dx;
    INT dy;

    dx = abs((a & 0xf) - (b & 0xf));
    dy = abs(((unsigned char) a & 0xf0) / 16
                 - ((unsigned char) b & 0xf0) / 16);
    if (dx > dy)
        return dx * 2 + dy;
    return dy * 2 + dx;
}
/* shared_include_end: ../../../../shared/c/PACKED-DISTANCE.C */

/* shared_include_start: ../../../../shared/c/CITY-DISTANCE.C -- generated */
/* CITY-DISTANCE.C -- c_city_distance, how far apart two cities are on the map.
 */

/* Answer how far apart cities `a` and `b` are on the map: twice the larger of
 * the two axis distances plus the smaller.
 */
INT c_city_distance(INT a, INT b)
{
    INT dx;
    INT dy;

    dx = abs(shm_cities[a].map_x
                 - shm_cities[b].map_x);
    dy = abs(shm_cities[a].map_y
                 - shm_cities[b].map_y);
    if (dx > dy)
        return dx * 2 + dy;
    return dy * 2 + dx;
}
/* shared_include_end: ../../../../shared/c/CITY-DISTANCE.C */

/* shared_include_start: ../../../../shared/c/SAY-PRESENCE.C -- generated */
/* SAY-PRESENCE.C -- c_say_presence, naming an organisation's presence.
 */

/* Append the word for `org`'s presence in `city` to shm_scratch and answer the
 * number behind it, 0 to 5. "active cel" is spelt that way in the data.
 */
INT c_say_presence(INT city, INT org)
{
    INT rank;

    rank = c_presence(city, org);
    if (rank == 1)
        strcat(shm_scratch, shd_str_hideout);
    if (rank == 2)
        strcat(shm_scratch, shd_str_agent);
    if (rank == 3)
        strcat(shm_scratch, shd_str_safehouse);
    if (rank == 4)
        strcat(shm_scratch, shd_str_active_cel);
    if (rank == 5)
        strcat(shm_scratch, shd_str_office);
    return rank;
}
/* shared_include_end: ../../../../shared/c/SAY-PRESENCE.C */

/* shared_include_start: ../../../../shared/c/PRESENCE.C -- generated */
/* PRESENCE.C -- c_presence, how strongly an organisation is present in a city.
 */

/* How big `org`'s presence in `city` is, 0 to 5, from the city's rank, the
 * organisation's strength and scale, and their distance. The mastermind's city
 * and org answer 1.
 */
INT c_presence(INT city, INT org)
{
    INT span;
    INT gap;
    INT rank;

    gap = c_packed_distance(
              shm_cities[city].where,
              shm_orgs[org].where);
    rank = (shm_cities[city].rank + 4)
           * shm_orgs[org].strength / (gap + 1);
    if (rank > 0) {
        span = rank * 0x3c
               / shm_orgs[org].scale + 10;
        rank = rank * 6
               / shm_orgs[org].scale + 1;
        if (rank > 5)
            rank = 5;
    }
    if (city == shm_campaign.mastermind_city && org == shm_campaign.mastermind_org)
        rank = 1;
    if (rank <= 0 && shm_difficulty == 0 && city == 1
        && shm_suspects[shm_crime_roles[0].suspect].org
           == org)
        rank = 1;
    return rank;
}
/* shared_include_end: ../../../../shared/c/PRESENCE.C */

/* shared_include_start: ../../../../shared/c/PERSON-NAME.C -- generated */
/* PERSON-NAME.C -- c_person_name, the name a suspect goes by.
 */

/* Append suspect `nth`'s name to the scratch buffer: the real name once
 * revealed, otherwise a codename lettered from `nth`.
 */
void c_person_name(INT nth)
{
    if (shm_suspects[nth].flags & SUSPECT_NAME) {
        c_person_real_name(nth);
    } else {
        strcat(shm_scratch, shd_str_agent_3);
        ((char *) shm_scratch)[strlen(shm_scratch) - 1] =
            nth % 26 + 'A';
    }
}
/* shared_include_end: ../../../../shared/c/PERSON-NAME.C */

/* shared_include_start: ../../../../shared/c/PERSON-REAL-NAME.C -- generated */
/* PERSON-REAL-NAME.C -- c_person_real_name, a suspect's real name.
 */

/* Append suspect `nth`'s real name to the scratch buffer: the organisation's
 * nationality picks a run of names and the suspect's visuals pick from it.
 * `spare` is unused.
 */
void c_person_real_name(INT nth)
{
    INT spare;

    strcat(shm_scratch,
               shd_first_names
                   [shm_suspects[nth].visuals & 1]
                   [shm_orgs[shm_suspects[nth].org].nationality * 2
                    + (shm_suspects[nth].visuals >> 1
                       & 0xf)]);
    strcat(shm_scratch, shd_str_space_13);
    strcat(shm_scratch,
               shd_last_names
                   [shm_orgs[shm_suspects[nth].org].nationality * 2
                    + (shm_suspects[nth].visuals >> 5
                       & 0xf)]);
}
/* shared_include_end: ../../../../shared/c/PERSON-REAL-NAME.C */

/* shared_include_start: ../../../../shared/c/PERSONNEL-FILE.C -- generated */
/* PERSONNEL-FILE.C -- c_personnel_file, the Master Plan and Personnel Files.
 */

/* Draw the Master Plan (`org` 0) or `org`'s Personnel File and wait for a key.
 * `reveal` first turns on each listed suspect's record.
 */
void c_personnel_file(INT org, INT reveal)
{
    INT x;
    INT row;
    INT blank;
    INT i;
    INT y;
    INT spare;

    switch (org) {
    case 0:
        shm_orgs_known |= 1;
        c_page_frame(shd_str_master_plan, 9);
        y = 0x20;
        (shm_scratch)[0] = 0;
        for (i = 0; i < 5; i++)
            strcat(shm_scratch, shd_str_secret);
        c_write_text_trimmed((rt_addr) shm_scratch, 0xc, 0x10, 0xe);
        c_write_text_trimmed((rt_addr) shm_scratch, 0xc, 0xbc, 0xe);
        for (i = 0; shm_crime_role_count - shm_difficulty * 4 > i;
             i++) {
            if ((*(INT *) &shm_crime_roles[i].flags & ROLE_MASTERMIND)
                == 0) {
                x = (i & 3) * 0x48 + 0x1c;
                if (i == 4)
                    y += 0x50;
                row = shm_crime_roles[i].suspect;
                if ((shm_suspects[row].flags & (SUSPECT_PHOTO | SUSPECT_PHOTO_LOST))
                    != SUSPECT_PHOTO_LOST)
                    c_draw_face_panel(shm_suspects[row].visuals, x, y);
                (shm_scratch)[0] = 0;
                if (shm_suspects[row].alert_level == ALERT_ARRESTED)
                    strcpy(shm_scratch, shd_str_arrested_upper);
                if (shm_suspects[row].alert_level == ALERT_HIDING)
                    strcpy(shm_scratch, shd_str_hiding_upper);
                if (shm_suspects[row].alert_level == ALERT_TURNED)
                    strcpy(shm_scratch, shd_str_turned_upper);
                c_write_text_trimmed((rt_addr) shm_scratch, x - 1,
                                   y + 0x10, 5);
                c_write_text_trimmed((rt_addr) shm_scratch, x - 2,
                                   y + 0x10, 0xc);
                strcpy(shm_scratch, shm_crime_roles[i].name);
                c_draw_centred(shm_scratch, x + 0x19,
                                   y + 0x38, 0xc);
                y ^= 8;
            }
        }
        break;
    default:
        shm_orgs_known |= 1 << org;
        c_page_frame(shd_str_personnel_file, 9);
        strcpy(shm_scratch, shm_orgs[org].long_name);
        strcat(shm_scratch, shd_str_action_team);
        c_write_text_trimmed((rt_addr) shm_scratch, 0x50, 0x10, 5);
        y = 0x20;
        blank = 1;
        for (i = 1; i < shm_suspect_count; i++) {
            if (shm_suspects[i].org == org
                && (shm_suspects[i].role & 0x7fff)
                   != 0) {
                if (reveal != 0)
                    shm_suspects[i].flags |= SUSPECT_NAME | SUSPECT_ORG | SUSPECT_CITY;
                (shm_scratch)[0] = 0;
                c_person_name(i);
                if (shm_suspects[i].flags & SUSPECT_CITY) {
                    strcat(shm_scratch, shd_str_comma_3);
                    strcat(shm_scratch,
                               shm_cities[shm_suspects[i].city].name);
                }
                c_write_text_trimmed((rt_addr) shm_scratch, 0x50, y,
                                   0xc);
                y += 8;
                blank = 0;
            }
        }
        if (blank != 0)
            c_write_text_trimmed(shd_str_no_activity, 0x50, y, 0xc);
    }
    c_wait_key();
}
/* shared_include_end: ../../../../shared/c/PERSONNEL-FILE.C */

/* shared_include_start: ../../../../shared/c/PAGE-FRAME.C -- generated */
/* PAGE-FRAME.C -- c_page_frame, a full-screen page with a title.
 */

/* Frame the whole screen: a background in `colour` (always 2 on CGA), a
 * border, a white page, and `text` as a centred title.
 */
void c_page_frame(rt_addr text, INT colour)
{
    INT wide;

    shm_pan_width = 0x140;
    if (shm_cga != 0)
        colour = 2;
    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 0xa, 6);
    drv_real_fill_rect(shd_screen, 0, 0xa, 0x140, 0xbe, colour);
    shd_screen->bg_pen = colour;
    c_folder_header(0xa0, 2, colour);
    c_draw_line(0, 0, 0, 0xc7, 6);
    c_draw_line(0x13f, 0, 0x13f, 0xc7, 6);
    drv_real_fill_rect(shd_screen, 8, 0xe, 0x130, 0xba, 0xf);
    c_draw_line(0xa, 0xd, 0x138, 0xd, 7);
    c_draw_line(0x138, 0xd, 0x138, 0xc7, 8);
    wide = c_text_width(text);
    drv_real_fill_rect(shd_screen, 0xef - wide / 2, 3, wide + 2, 9, 7);
    c_write_text_trimmed(text, 0xf0 - wide / 2, 4, 0);
    shd_screen->bg_pen = 0xf;
}
/* shared_include_end: ../../../../shared/c/PAGE-FRAME.C */

/* shared_include_start: ../../../../shared/c/FOLDER-HEADER.C -- generated */
/* FOLDER-HEADER.C -- c_folder_header, drawing a folder tab and its rules.
 */

/* Draw the folder tab at (x, y) in `colour`, with a rule from its foot to each
 * screen edge.
 */
void c_folder_header(INT x, INT y, UNSIGNED_INT colour)
{
    drv_real_fill_rect(shd_screen, x + 0xa, y, 0x8c, 8, colour);
    if (y != 0)
        c_draw_line(x + 0xa, y - 1, x + 0x93, y - 1, 5);
    c_draw_line(0, y + 8, x, y + 8, 8);
    c_draw_line(x + 0x9e, y + 8, 0x13f, y + 8, 8);
    c_draw_sprite(SPRITE_FOLDER_START, x, y);
    c_draw_sprite(SPRITE_FOLDER_END, x + 0x93, y);
    drv_jump_gfx_fill(shd_screen, x, y, 0xa0, 8, 0xd, colour);
}
/* shared_include_end: ../../../../shared/c/FOLDER-HEADER.C */

/* shared_include_start: ../../../../shared/c/CLOCK-TEXT.C -- generated */
/* CLOCK-TEXT.C -- c_clock_text, a time of day as "hh:mm:ss".
 */

/* Write the time `seconds` after shm_clock_minutes, wrapped to a day, into the
 * template shd_clock_text and answer it.
 */
rt_addr c_clock_text(INT seconds)
{
    INT mins;
    INT rest;
    INT hour;
    INT secs;

    rest = (UNSIGNED_INT) (seconds / 60 + shm_clock_minutes) % 1440;
    hour = rest / 60;
    mins = rest % 60;
    secs = seconds % 60;
    shd_clock_text[0] = hour / 10 + '0';
    shd_clock_text[1] = hour % 10 + '0';
    shd_clock_text[3] = mins / 10 + '0';
    shd_clock_text[4] = mins % 10 + '0';
    shd_clock_text[6] = secs / 10 + '0';
    shd_clock_text[7] = secs % 10 + '0';
    return (rt_addr) shd_clock_text;
}
/* shared_include_end: ../../../../shared/c/CLOCK-TEXT.C */

/* shared_include_start: ../../../../shared/c/TEXT-WIDTH.C -- generated */
/* TEXT-WIDTH.C -- c_text_width, how wide a string is in pixels.
 */

/* How many pixels `text` takes in the screen's font. */
INT c_text_width(rt_addr text)
{
    INT typeface;
    unsigned char *at;
    INT wide;

    at = (unsigned char *) text;
    typeface = shd_screen->font;
    wide = 0;
    while (*at != 0)
        wide += drv_jump_gfx_char_width(typeface, *at++);
    return wide;
}
/* shared_include_end: ../../../../shared/c/TEXT-WIDTH.C */

/* shared_include_start: ../../../../shared/c/TEXT-PANEL.C -- generated */
/* TEXT-PANEL.C -- c_text_panel, the panel a page of text goes on.
 */

/* Draw the white panel a page of text goes on, 130h wide from (`x`, `y`) to
 * the bottom of the screen, with a bevel.
 */
void c_text_panel(INT x, INT y)
{
    drv_real_fill_rect(shd_screen, x, y, 0x130, 0xc8 - y, 0xf);
    c_draw_line(x + 1, y, x + 0x130, y, 7);
    c_draw_line(x + 0x130, y, x + 0x130, 0xc7, 8);
    c_draw_line(x, y + 1, x, 0xc7, 7);
}
/* shared_include_end: ../../../../shared/c/TEXT-PANEL.C */

/* shared_include_start: ../../../../shared/c/DRAW-CENTRED.C -- generated */
/* DRAW-CENTRED.C -- c_draw_centred, drawing text centred on a point.
 */

/* Draw `text` centred on `x`, with draw_mode cleared for the call so no
 * background is painted.
 */
void c_draw_centred(str_addr text, INT x, INT y, UNSIGNED_INT colour)
{
    x -= c_text_width((rt_addr) text) / 2;
    shd_screen->draw_mode = 0;
    c_write_text((drv_addr) text, x, y, colour);
    shd_screen->draw_mode = 1;
}
/* shared_include_end: ../../../../shared/c/DRAW-CENTRED.C */
