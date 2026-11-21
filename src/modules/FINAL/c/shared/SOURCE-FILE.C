/* SOURCE-FILE.C -- pointing the decoder at an open file. */
#include "FINAL.H"
#include "ARCHIVE.H"
#include "SRCFILE.H"

/* shared_include_start: ../../../../shared/c/DECODE-FROM-FILE.C -- generated */
/* DECODE-FROM-FILE.C -- c_decode_from_file, pointing the decoder at a file.
 */

/* Make `handle` the file the decoder reads: the buffer is marked empty and the
 * refill pointed at c_refill_from_file.
 */
INT c_decode_from_file(INT handle)
{
    shm_source_fd = handle;
    shm_source_at = shd_archive_buffer_end;
    *(INT (FAR **) ()) &shm_refill = c_refill_from_file;
}
/* shared_include_end: ../../../../shared/c/DECODE-FROM-FILE.C */
