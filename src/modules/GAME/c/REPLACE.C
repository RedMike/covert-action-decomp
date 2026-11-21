/* REPLACE.C -- replacing every occurrence of a key in the message buffer.
 */
#include "GAME.H"
#include "PRISONER.H"

/* Replace every occurrence of `find` in the message buffer with `repl`. */
INT c_replace(char *find, char *repl)
{
    char *v0j;      /* where the next occurrence starts */
    char v1a[256];  /* what followed it, while the buffer is cut short */

    /* Replace every occurrence; a `repl` that contains `find` never ends. */
    do {
        v0j = (char *) strstr(shm_scratch, find);
        if (v0j != 0) {
            strcpy(v1a, v0j);
            *v0j = 0;
            strcat(shm_scratch, repl);
            strcat(shm_scratch, v1a + strlen(find));
        }
    } while (v0j != 0);
}
