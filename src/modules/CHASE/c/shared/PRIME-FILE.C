/* PRIME-FILE.C -- setting the file handle and filling the buffer at once.
 */
#include "CHASE.H"
#include "ARCHIVE.H"

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
