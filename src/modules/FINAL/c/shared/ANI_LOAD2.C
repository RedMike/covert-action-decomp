/* ANI_LOAD2.C -- loading a picture, taking the name before the surface.
 */
#include "FINAL.H"
#include "FILEIO.H"
#include "ANI_LD2.H"

/* shared_include_start: ../../../../shared/c/LOAD-PICTURE.C -- generated */
/* LOAD-PICTURE.C -- c_load_picture, loading a picture file onto a surface.
 */

/* Load picture file `name` onto surface `a`, through c_decode_picture with
 * the arguments the other way round.
 */
INT c_load_picture(rt_addr name, UNSIGNED_INT a)
{
    return c_decode_picture(a, name);
}
/* shared_include_end: ../../../../shared/c/LOAD-PICTURE.C */
