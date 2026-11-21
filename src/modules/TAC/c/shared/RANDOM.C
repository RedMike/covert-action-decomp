/* RANDOM.C -- seeding the random numbers, and drawing one below a bound.
 */
#include "TAC.H"
#include "RANDOM.H"

/* shared_include_start: ../../../../shared/c/SEED-RANDOM.C -- generated */
/* SEED-RANDOM.C -- c_seed_random, seeding the random numbers from the clock.
 */

void c_seed_random(void)
{
    shm_seed = (UNSIGNED_INT) time(0) & 0x7fff;
    srand(shm_seed);
}
/* shared_include_end: ../../../../shared/c/SEED-RANDOM.C */

/* shared_include_start: ../../../../shared/c/RANDOM-BELOW.C -- generated */
/* RANDOM-BELOW.C -- c_random_below, a random number from 0 to `n` - 1.
 */

INT c_random_below(INT n)
{
    return ((LONG) n * (INT) rand()) >> 15;
}
/* shared_include_end: ../../../../shared/c/RANDOM-BELOW.C */
