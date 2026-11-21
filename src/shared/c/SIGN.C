/* SIGN.C -- c_sign, the sign of a number.
 */

/* Which way `n` points: 1, -1, or 0 for neither. */
INT c_sign(INT n)
{
    if (n > 0)
        return 1;
    if (n < 0)
        return -1;
    return 0;
}
