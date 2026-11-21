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
