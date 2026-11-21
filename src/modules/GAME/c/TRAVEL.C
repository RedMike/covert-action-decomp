/* TRAVEL.C -- flying the plane across the map from one city to another.
 */
#include "GAME.H"
#include "SPRITES.H"
#include "CMP_STRT.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "NOTICE.H"
#include "ORGPLAN.H"
#include "TRAVEL.H"

/* Walk the plane from city `from` to city `to`, a step at a time, and answer
 * how many steps it took. */
INT c_fly_distance(INT from, INT to)
{
    INT v0j;    /* how high the plane is */
    INT v1j;    /* how far it still has to turn */
    INT v2j;    /* the height it is climbing to, or -1 */
    INT v3k;    /* where the plane is now */
    INT v4k;
    INT v5k;    /* where the sprite is drawn */
    INT v6l;    /* where it is going */
    INT v7l;    /* how far that is, across */
    INT v8l;
    INT v9m;    /* and down */
    INT v10f;   /* how many steps have been taken */
    INT v11f;   /* which way it is facing */

    /* A debug build logs where the flight is from and to. */
    LOG_MESSAGE4("Flying from %d (%s) to %d (%s)", from, shm_cities[from].name, to, shm_cities[to].name);

    /* Keep a clean copy of the map to redraw from under the plane. */
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 192, 200, shd_map_page, 0, 0);
    /* From one city's place on the map to the other's. */
    v3k = shm_cities[from].map_x;
    v4k = shm_cities[from].map_y;
    v6l = shm_cities[to].map_x;
    v8l = shm_cities[to].map_y;

    LOG_MESSAGE4("Flying pos from (%d,%d) to (%d,%d)", v3k, v4k, v6l, v8l);

    /* Set off on the ground facing the destination; the random heading drawn first is overwritten. */
    v1j = v11f = c_random_below(8);
    v0j = v10f = 0;
    v7l = v6l - v3k;
    v9m = v8l - v4k;
    v11f = ((char *) asm_leg_next)[c_sign(v7l) * 3 + c_sign(v9m) + 4];

    TRACE_MESSAGE3("Distance (%d,%d) means offset %d", v7l, v9m, v11f);
    /* Start the flight's sound, and watch the height for the start of the descent. */
    c_sound_command(35);
    v2j = 0;
    do {
        /* Turn an eighth at a time towards the destination, the shorter way round. */
        v1j = ((char *) asm_leg_next)[c_sign(v7l) * 3 + c_sign(v9m) + 4]
              - v11f;
        if (v1j != 0) {
            if ((v1j & 7) < 4)
                v11f++;
            else
                v11f--;
            v11f &= 7;
        }
        /* Climb a step every other move, up to 8 and never above half the distance left, so it comes down to land. */
        v0j = c_clamp((v10f++ & 1) + v0j, 0,
                              ((INT) abs(v7l) + (INT) abs(v9m)) / 2);
        if (v0j > 8)
            v0j = 8;
        /* The first time it drops, the sound changes, once. */
        if (v0j < v2j) {
            c_sound_command(36);
            v2j = -1;
        }
        if (v2j != -1)
            v2j = v0j;

        TRACE_MESSAGE3("Distance (%d,%d) means offset %d", v7l, v9m, v11f);
        TRACE_MESSAGE3("Offset %d means movement (%d,%d)", v11f, ((char *) asm_leg_x)[v11f], ((char *) asm_leg_y)[v11f]);
        /* Move one leg, put back the map behind the plane, and draw its shadow and then the plane above it. */
        v3k += ((char *) asm_leg_x)[v11f];
        v4k += ((char *) asm_leg_y)[v11f];
        v5k = c_clamp(v3k - 5, 0, 999);
        drv_jump_gfx_copy_rect(shd_map_page, v5k, v4k - v0j - 6, 10, v0j + 12, shd_screen, v5k, v4k - v0j - 6);
        c_draw_sprite(v11f + SPRITE_PLANE_SHADOW, v5k + 1, v4k - 4);
        c_draw_sprite(v11f + SPRITE_PLANE, v5k + 1, v4k - v0j - 4);
        /* Pace the flight, and see how far is left to go. */
        c_wait_retraces(10);
        v7l = v6l - v3k;
        v9m = v8l - v4k;
        TRACE_MESSAGE2("Distance now (%d,%d)", v7l, v9m);
    } while (v7l != 0 || v9m != 0);
    /* How many legs it took, from which the caller reckons the flight's time. */
    return v10f;
}
