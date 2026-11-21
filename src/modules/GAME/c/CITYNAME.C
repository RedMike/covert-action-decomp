/* CITYNAME.C -- a city's marker and name on the travel map.
 */
#include "GAME.H"
#include "MISC1.H"
#include "FRAME.H"
#include "TRAVEL.H"

/* Put city `city`'s name on the map in colour `colour` beside its marker dot,
 * on the dot's left where it would run off the right edge. */
INT c_city_name(INT city, INT colour)
{
    INT v0j;    /* how wide the name is */

    /* The city's dot, three pixels square, drawn once in colour 3 and then over in colour 11. */
    drv_real_fill_rect(shd_screen,
                      shm_cities[city].map_x - 1,
                      shm_cities[city].map_y - 1, 3, 3, 3);
    v0j = c_text_width(shm_cities[city].name);
    drv_real_fill_rect(shd_screen,
                      shm_cities[city].map_x - 1,
                      shm_cities[city].map_y - 1, 3, 3, 11);
    /* The name goes right of the dot if it ends short of x = 192, where the city list starts, and left otherwise. */
    if ((unsigned) (189 - v0j) > (unsigned) shm_cities[city].map_x)
        c_write_text_trimmed(shm_cities[city].name,
                        shm_cities[city].map_x + 3,
                        shm_cities[city].map_y - 3, colour);
    else
        c_write_text_trimmed(shm_cities[city].name,
                        shm_cities[city].map_x - v0j - 3,
                        shm_cities[city].map_y - 3, colour);
}
