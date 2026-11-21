/* CARSPEC.H -- the bits of CAR.spec: the car the player picked, as the pick
 * screen shows it. The bits above CAR_VISIBILITY are always clear.
 */
#ifndef CARSPEC_H
#define CARSPEC_H

#define CAR_SPEED 0x3           /* 40, 60 or 80 mph; the top gear is this + 2 */
#define CAR_TRACKING 0x4        /* arrows to car 0, and homing on it unsteered */
#define CAR_HANDLING 0x8        /* excellent rather than fair: a U-turn on the spot */
#define CAR_VISIBILITY 0x30     /* conspicuousity in-game, Low to Extreme */
#define CAR_VISIBILITY_SHIFT 4  /* where CAR_VISIBILITY starts */

#endif /* CARSPEC_H */
