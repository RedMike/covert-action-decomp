/* TEXT-LAYOUT.C -- laying text out and drawing it, and the phrases in it.
 */
#include "BUG.H"
#include "PRIMS.H"
#include "SCREEN.H"
#include "FACES.H"
#include "REPORT.H"
#include "TEXTLAY.H"
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
