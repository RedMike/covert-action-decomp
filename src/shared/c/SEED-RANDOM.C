/* SEED-RANDOM.C -- c_seed_random, seeding the random numbers from the clock.
 */

void c_seed_random(void)
{
    shm_seed = (UNSIGNED_INT) time(0) & 0x7fff;
    srand(shm_seed);
}