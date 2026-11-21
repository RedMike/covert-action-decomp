/* TRIM.C -- trimming the message buffer to fit a width in pixels. */
#include "GAME.H"
#include "FRAME.H"

/* shared_include_start: ../../../../shared/c/TRIM-TO-WIDTH.C -- generated */
/* TRIM-TO-WIDTH.C -- c_trim_to_width, cutting text down to a width.
 */

/* Drop characters from the end of the scratch string until it fits `width`
 * pixels, measuring again after each.
 */
void c_trim_to_width(INT width)
{
    while ((INT) c_text_width((rt_addr) shm_scratch) > width)
        *((unsigned char *) shm_scratch
          + strlen(shm_scratch) - 1) = 0;
}
/* shared_include_end: ../../../../shared/c/TRIM-TO-WIDTH.C */
