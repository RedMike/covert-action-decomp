/* SIGHT.C -- the line of sight from a car to car 0.
 */
#include "CHASE.H"
#include "SIGHT.H"
#include "STREET.H"
#include "DOOR1.H"

/* How far car `car` is from car 0 along a straight line in one lane, or 0 if a
 * closed cell lies between. asm_sight_dir is left set unless the two share a
 * spot.
 *
 * The locals' declaration order fixes their frame slots.
 */
INT c_sight(INT car)
{
    INT clear;
    INT i;
    INT cx;
    INT dx;
    INT cy;
    INT dy;
    INT adx;
    INT ady;
    INT dir;

    dx = asm_cars[0].x - asm_cars[car].x;
    dy = asm_cars[0].y - asm_cars[car].y;
    adx = abs(dx);
    ady = abs(dy);
    /* At night nothing further than two blocks away can be seen. */
    if (asm_night != 0 && (adx > 64 || ady > 64))
        return 0;
    clear = 1;
    /* The junction the car last passed. */
    cx = ((asm_cars[car].facing == 3 ? 31 : 0)
          + asm_cars[car].x) / 32;
    cy = ((asm_cars[car].facing == 0 ? 31 : 0)
          + asm_cars[car].y) / 32;
    /* Car 0 up or down the same street within six blocks, and no closed street between. */
    if (adx == 0 && ady < 192
        && asm_cars[car].x % 32 == 0) {
        dir = dy > 0 ? 2 : 0;
        for (i = 0; ady / 32 >= i; cy += c_sign(dy), i++)
            if (c_is_open(cx, cy, dir) == 0) {
                clear = 0;
                break;
            }
        asm_sight_dir = dir == 0 ? dy < 0 : dy > 0;
        if (clear == 0)
            return 0;
        return ady;
    }
    /* Otherwise only along the same street across, within six blocks, the same way. */
    if (ady != 0)
        return 0;
    if (adx >= 192)
        return 0;
    if (asm_cars[car].y % 32 != 0)
        return 0;
    dir = dx > 0 ? 1 : 3;
    for (i = 0; adx / 32 >= i; cx += c_sign(dx), i++)
        if (c_is_open(cx, cy, dir) == 0) {
            clear = 0;
            break;
        }
    asm_sight_dir = dir == 3 ? dx < 0 : dx > 0;
    if (clear == 0)
        return 0;
    return adx;
}
