/* PACKED-DISTANCE.C -- c_packed_distance, the distance between two positions.
 */

/* The distance between two packed coordinates, a pair of nibbles each: the
 * larger difference doubled plus the smaller.
 */
INT c_packed_distance(INT a, INT b)
{
    INT dx;
    INT dy;

    dx = abs((a & 0xf) - (b & 0xf));
    dy = abs(((unsigned char) a & 0xf0) / 16
                 - ((unsigned char) b & 0xf0) / 16);
    if (dx > dy)
        return dx * 2 + dy;
    return dy * 2 + dx;
}
