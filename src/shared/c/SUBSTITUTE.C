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
