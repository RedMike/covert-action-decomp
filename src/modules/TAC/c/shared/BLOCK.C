/* BLOCK.C -- what messages and clues say, read from tagged blocks of text.
 */
#include "TAC.H"
#include "BLOCK.H"
#include "RANDOM.H"
#include "CRIMEVNT.H"
#include "SUSPFLAG.H"

/* shared_include_start: ../../../../shared/c/SAY-BLOCK.C -- generated */
/* SAY-BLOCK.C -- c_say_block, appending a text block with the usual keys.
 */

/* Append the block tagged `key` in the file `name` to shm_scratch, with the
 * seven $-keys substituted from their value buffers.
 */
INT c_say_block(rt_addr name, rt_addr key)
{
    return c_say_block_with(name, key, shd_subst_keys,
                           shd_subst_values, 7);
}
/* shared_include_end: ../../../../shared/c/SAY-BLOCK.C */

/* shared_include_start: ../../../../shared/c/SAY-WITH.C -- generated */
/* SAY-WITH.C -- c_say_block_with, appending a text block with substitutions.
 */

/* Append the block tagged `key` in the file `name` to shm_scratch with `count`
 * keys substituted; answer whether it was found, appending a notice if not.
 */
INT c_say_block_with(rt_addr name, rt_addr key, rt_addr *keys,
                    rt_addr *values, INT count)
{
    char line[256];
    rt_stream stream;
    INT scanned;
    INT found;

    stream = fopen(name, shd_str_mode_read_text);
    do {
        scanned = fscanf(stream, shd_fmt_line, line);
#ifdef PORT_MODERN
        /* Skip a blank first line, as prose.dta has, which a modern library's
         * %[ would not match. */
        if (scanned == 0)
            scanned = fscanf(stream, (str_addr) " %[^\n]\n", line);
#endif
        ASSERT_SCAN_PROGRESS(scanned, name, key);
    } while (strcmp(line, key) != 0 && scanned != -1);
    if (scanned != -1) {
        do {
            fscanf(stream, shd_fmt_line_2, line);
        } while (line[0] == '*');
        do {
            c_substitute(line, keys, values, count);
            strcat(shm_scratch, line);
            strcat(shm_scratch, shd_str_space_12);
            fscanf(stream, shd_fmt_line_3, line);
        } while (line[0] != '*');
        found = 1;
    } else {
        strcat(shm_scratch, shd_str_information_requires);
        strcat(shm_scratch, key);
        found = 0;
    }
    fclose(stream);
    return found;
}
/* shared_include_end: ../../../../shared/c/SAY-WITH.C */

/* shared_include_start: ../../../../shared/c/SUBSTITUTE.C -- generated */
/* SUBSTITUTE.C -- c_substitute, replacing $-keys in a line of text.
 */

/* Replace, in place, the first occurrence in `line` of each of the `count`
 * keys with its value.
 */
INT c_substitute(char *line, rt_addr *keys, rt_addr *values,
                    INT count)
{
    str_addr hit;
    INT i;

    for (i = 0; i < count; i++) {
        hit = strstr(line, keys[i]);
        if (hit != 0) {
            strcpy(shm_substitute_tail, hit);
            *hit = 0;
            strcat(line, values[i]);
            strcat(line, strlen(keys[i]) + shm_substitute_tail);
        }
    }
}
/* shared_include_end: ../../../../shared/c/SUBSTITUTE.C */

/* shared_include_start: ../../../../shared/c/SAY-MESSAGE.C -- generated */
/* SAY-MESSAGE.C -- c_say_message, what an informant says about a message.
 */

/* Append what an informant says about intercepted message `nth`: its two ends
 * fill the substitutions, then seven topics follow in random order.
 */
void c_say_message(INT nth)
{
    INT reversed;
    INT slot;
    INT told;
    INT from;
    INT target;
    INT pick;
    INT hold;
    INT org;

    slot = shm_log[nth].slot;
    strcpy(shm_scratch, (char *) &shd_str_empty_message);
    from = shm_log[nth].from;
    target = shm_log[nth].to;
    if (slot >= 0) {
        reversed = 0;
        if ((shm_crime_events[slot].flags & CRIME_KIND) == (CRIME_MESSAGE | CRIME_RECEIVED)) {
            hold = from;
            from = target;
            target = hold;
            reversed = 1;
        }
    }
    strcpy(shd_subst_values[0], shm_campaign.text[0]);
    strcpy(shd_subst_values[6], shm_campaign.text[1]);
    strcpy(shd_subst_values[1],
               shm_orgs[shm_suspects[from].org].long_name);
    strcpy(shd_subst_values[2],
               shm_orgs[shm_suspects[target].org].long_name);
    if (reversed == 0) {
        strcpy(shd_subst_values[3],
                   shm_cities[shm_log[nth].from_city].name);
        strcpy(shd_subst_values[4],
                   shm_cities[shm_log[nth].to_city].name);
    } else {
        strcpy(shd_subst_values[4],
                   shm_cities[shm_log[nth].from_city].name);
        strcpy(shd_subst_values[3],
                   shm_cities[shm_log[nth].to_city].name);
    }
    told = 0;
    do {
        pick = c_random_below(7);
        if ((told & 1 << pick) == 0) {
            told |= 1 << pick;
            switch (pick) {
            case 0:
                if (shm_suspects[from].flags & SUSPECT_CITY)
                    c_say_one_of(shd_str_text_dta_sloc, (char *) shd_str_sloc00, 8);
                break;
            case 1:
                if (shm_suspects[target].flags & SUSPECT_CITY)
                    c_say_one_of(shd_str_text_dta_rloc, (char *) shd_str_rloc00, 8);
                break;
            case 2:
                if (shm_suspects[from].flags & SUSPECT_ORG)
                    c_say_one_of(shd_str_text_dta_sorg, (char *) shd_str_sorg00, 8);
                break;
            case 3:
                if (shm_suspects[target].flags & SUSPECT_ORG)
                    c_say_one_of(shd_str_text_dta_rorg, (char *) shd_str_rorg00, 8);
                break;
            case 4:
                c_message_tag(shm_mission,
                                   slot >= 0
                                   ? shm_crime_events[slot].message_id : slot);
                strcat(shm_scratch, shd_str_mark_80);
                c_say_block(shd_str_text_dta_msg, shm_message_key);
                strcat(shm_scratch, shd_str_mark_8f);
                break;
            case 5:
                c_say_one_of(shd_str_text_dta_fluf, (char *) shd_str_fluf00, 0xc);
                break;
            case 6:
                strcpy(shm_message_key, shd_str_alrt00);
                shm_message_key[6] += c_clamp(
                    shm_log[nth].status / 20,
                    0, 4);
                if (shm_log[nth].status > 15) {
                    c_say_block(shd_str_text_dta_help, shm_message_key);
                } else {
                    org = shm_suspects[shm_crime_roles[(INT) c_random_below(shm_crime_role_count - shm_difficulty * 4)].suspect].org;
                    if (shm_suspects[from].org
                            != org
                        && shm_suspects[target].org != org) {
                        strcpy(shd_subst_values[5], shm_orgs[org].long_name);
                        c_say_one_of(shd_str_text_dta_aidd, (char *) shd_str_aidd00, 2);
                    }
                }
                break;
            }
        }
    } while (told != 0x7f);
}
/* shared_include_end: ../../../../shared/c/SAY-MESSAGE.C */

/* shared_include_start: ../../../../shared/c/SAY-ONE-OF.C -- generated */
/* SAY-ONE-OF.C -- c_say_one_of, appending one of several phrasings.
 */

/* Append one of `n` phrasings of the tag `key` from the file `name`: a random
 * number below `n` replaces the tag's last two digits.
 */
INT c_say_one_of(rt_addr name, char *key, INT n)
{
    n = c_random_below(n);
    key[6] = n % 10 + '0';
    key[5] = n / 10 + '0';
    return c_say_block(name, (rt_addr) key);
}
/* shared_include_end: ../../../../shared/c/SAY-ONE-OF.C */

/* shared_include_start: ../../../../shared/c/SAY-EVENT-TEXT.C -- generated */
/* SAY-EVENT-TEXT.C -- c_say_event_text, the text of a crime event's message.
 */

/* Append what the case says about crime event `nth`: the block its "*MSGaabb"
 * tag names, with the victim, object and sender filled in.
 */
INT c_say_event_text(INT nth)
{
    strcpy(shd_subst_values[0], shm_campaign.text[0]);
    strcpy(shd_subst_values[6], shm_campaign.text[1]);
    strcpy(shd_subst_values[1],
               shm_orgs[shm_suspects[shm_crime_roles[shm_crime_events[nth].main_participant].suspect].org].long_name);
    strcpy(shd_subst_values[3],
               shm_cities[shm_suspects[shm_crime_roles[shm_crime_events[nth].main_participant].suspect].city].name);
    c_message_tag(shm_mission,
                    nth >= 0
                    ? shm_crime_events[nth].message_id : nth);
    return c_say_block(shd_str_text_dta_event, shm_message_key);
}
/* shared_include_end: ../../../../shared/c/SAY-EVENT-TEXT.C */

/* shared_include_start: ../../../../shared/c/MESSAGE-TAG.C -- generated */
/* MESSAGE-TAG.C -- c_message_tag, building a message's text tag.
 */

/* Build the tag "*MSGaabb" in shm_message_key from `a` and `b`; a negative `b`
 * makes `a` 99 and `b` half its magnitude.
 */
INT c_message_tag(INT a, INT b)
{
    strcpy(shm_message_key, shd_str_msg0000);
    if (b < 0) {
        a = 99;
        b = -b / 2;
    }
    shm_message_key[4] += a / 10;
    shm_message_key[5] += a % 10;
    shm_message_key[6] += b / 10;
    shm_message_key[7] += b % 10;
}
/* shared_include_end: ../../../../shared/c/MESSAGE-TAG.C */
