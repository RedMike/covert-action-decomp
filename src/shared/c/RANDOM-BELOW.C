/* RANDOM-BELOW.C -- c_random_below, a random number from 0 to `n` - 1.
 */

INT c_random_below(INT n)
{
    return ((LONG) n * (INT) rand()) >> 15;
}