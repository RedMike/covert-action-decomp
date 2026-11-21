/* CITY-DISTANCE.C -- c_city_distance, how far apart two cities are on the map.
 */

/* Answer how far apart cities `a` and `b` are on the map: twice the larger of
 * the two axis distances plus the smaller.
 */
INT c_city_distance(INT a, INT b)
{
    INT dx;
    INT dy;

    dx = abs(shm_cities[a].map_x
                 - shm_cities[b].map_x);
    dy = abs(shm_cities[a].map_y
                 - shm_cities[b].map_y);
    if (dx > dy)
        return dx * 2 + dy;
    return dy * 2 + dx;
}
