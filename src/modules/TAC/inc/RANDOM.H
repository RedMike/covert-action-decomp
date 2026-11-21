/* RANDOM.H -- seeding the random numbers, one below a bound, and clamping.
 */
#ifndef RANDOM_H
#define RANDOM_H

void c_seed_random(void);
INT c_random_below(INT n);
INT c_clamp(INT v, INT low, INT high);

#endif
