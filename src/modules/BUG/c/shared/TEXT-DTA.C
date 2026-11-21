/* TEXT-DTA.C -- reading a tagged block out of text.dta, $-keys substituted.
 */
#include "BUG.H"
#include "TEXTDTA.H"

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
