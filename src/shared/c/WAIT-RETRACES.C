/* WAIT-RETRACES.C -- c_wait_retraces, waiting for vertical retraces.
 */

/* Wait `n` vertical retraces, by bit 3 of status port 3dah. `unused` is not
 * read.
 */
INT c_wait_retraces(INT n)
{
    INT unused;

    if (n != 0)
        while (n-- != 0) {
            while ((inp(0x3da) & 8) == 0)
                ;
            while ((inp(0x3da) & 8) != 0)
                ;
        }
}