/* SQUEEZE.C -- taking the spaces out of a string.
 */
#include "GAME.H"
#include "CMP_STRT.H"

/* Take the spaces out of `s`, in place. */
INT c_squeeze(char *s)
{
    INT v0j;    /* how far along it has looked */

    /* Close each space up, looking again where the next character slid in, so a city name becomes a file name. */
    for (v0j = 0; (INT) strlen(s) > v0j; v0j++)
        while (s[v0j] == ' ')
            strcpy(s + v0j, s + v0j + 1);
}
