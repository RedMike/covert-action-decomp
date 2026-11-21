/* LOAD-PICTURE.C -- c_load_picture, loading a picture file onto a surface.
 */

/* Load picture file `name` onto surface `a`, through c_decode_picture with
 * the arguments the other way round.
 */
INT c_load_picture(rt_addr name, UNSIGNED_INT a)
{
    return c_decode_picture(a, name);
}