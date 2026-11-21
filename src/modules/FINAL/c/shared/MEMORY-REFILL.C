/* MEMORY-REFILL.C -- the decoder's refill when it is reading out of memory.
 *
 * Compiled with `/Ot`.
 */
#include "FINAL.H"
#include "ARCHIVE.H"

/* shared_include_start: ../../../../shared/c/MEMORY-REFILL.C -- generated */
/* MEMORY-REFILL.C -- c_refill_from_memory, feeding the decoder from memory.
 */

/* Copy the next 200h bytes of the in-memory source into the decoder's buffer
 * and answer the count. `far` because the decoder calls it through a pointer.
 */
INT FAR c_refill_from_memory(void)
{
    char FAR *p;

    p = (char FAR *) shm_archive_buffer;
    COPY_FROM_SEGMENT(shm_source_src, shm_source_dst, p, 0x200);
    shm_source_at = (rt_addr) shm_archive_buffer;
    ((char *) &shm_source_dst)[1] += 2;
    return 0x200;
}
/* shared_include_end: ../../../../shared/c/MEMORY-REFILL.C */
