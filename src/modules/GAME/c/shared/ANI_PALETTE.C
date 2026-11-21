/* ANI_PALETTE.C -- reading a palette out of a picture file.
 */
#include "GAME.H"
#include "OPENFILE.H"
#include "CREATE.H"
#include "HOOK.H"

/* shared_include_start: ../../../../shared/c/PALETTE-DECODE.C -- generated */
/* PALETTE-DECODE.C -- c_decode_palette, reading a palette from a file.
 */

/* Open `name` as the decoder's source, read its palette into `a`, `b` and
 * answer the entry count.
 */
INT c_decode_palette(UNSIGNED_INT a, UNSIGNED_INT b, rt_addr name)
{
    INT handle;

    handle = c_open(name, 0);
    c_decode_from_file(handle);
    drv_real_palette_read();
    drv_real_palette_put(a, b, shm_palette_count);
    c_close(handle);
    return shm_palette_count;
}
/* shared_include_end: ../../../../shared/c/PALETTE-DECODE.C */
