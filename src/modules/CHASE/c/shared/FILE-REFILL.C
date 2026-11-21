/* FILE-REFILL.C -- the decoder's refill when it is reading out of a file.
 */
#include "CHASE.H"
#include "ARCHIVE.H"

/* shared_include_start: ../../../../shared/c/FILE-REFILL.C -- generated */
/* FILE-REFILL.C -- c_refill_from_file, refilling the decoder from a file.
 */

/* Read the next 200h bytes of the decoder's file into its buffer and answer
 * how many came back. `far` because the decoder calls it through a pointer.
 */
INT FAR c_refill_from_file(void)
{
    INT got;

    _dos_read(shm_source_fd,
                      (rt_far_addr) shm_archive_buffer,
                      0x200, (rt_addr) &got);
    shm_source_at = (rt_addr) shm_archive_buffer;
    return got;
}
/* shared_include_end: ../../../../shared/c/FILE-REFILL.C */
