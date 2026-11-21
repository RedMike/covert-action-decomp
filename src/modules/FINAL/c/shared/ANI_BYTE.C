/* ANI_BYTE.C -- reading bytes out of the decoder, one at a time.
 */
#include "FINAL.H"
#include "ARCHIVE.H"
#include "ANIMREAD.H"

/* shared_include_start: ../../../../shared/c/ANIM-READ.C -- generated */
/* ANIM-READ.C -- c_anim_read, reading bytes from an animation file.
 */

/* Read `size` * `count` bytes into `dest`, a byte at a time. */
INT c_anim_read(char *dest, INT size, INT count)
{
    size = count * size;
    while (size-- != 0)
        *dest++ = (char) c_anim_byte();
}
/* shared_include_end: ../../../../shared/c/ANIM-READ.C */


/* shared_include_start: ../../../../shared/c/ANIM-BYTE.C -- generated */
/* ANIM-BYTE.C -- c_anim_byte, the next byte of an animation file.
 */

/* The animation's next byte, sign-extended, refilling the buffer when it runs
 * out.
 */
INT c_anim_byte(void)
{
    if (shm_source_at >= shd_archive_buffer_end)
        c_prime_file(shm_anim_fd);
    return *(char *) shm_source_at++;
}
/* shared_include_end: ../../../../shared/c/ANIM-BYTE.C */
