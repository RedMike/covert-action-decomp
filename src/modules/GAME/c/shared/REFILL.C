/* REFILL.C -- refilling the decoder's buffer, from memory or from a file.
 */
#include "GAME.H"
#include "REFILL.H"

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

/* shared_include_start: ../../../../shared/c/PRIME-FILE.C -- generated */
/* PRIME-FILE.C -- c_prime_file, filling the decoder's buffer from a file.
 */

/* Make `handle` the decoder's source and read its first 200h bytes at once. */
INT c_prime_file(INT handle)
{
    shm_source_fd = handle;
    return c_refill_from_file();
}
/* shared_include_end: ../../../../shared/c/PRIME-FILE.C */

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
