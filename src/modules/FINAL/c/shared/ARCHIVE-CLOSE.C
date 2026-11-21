/* ARCHIVE-CLOSE.C -- closing the archive, once.
 */
#include "FINAL.H"
#include "ARCHIVE.H"

/* shared_include_start: ../../../../shared/c/ARCH-CLOSE.C -- generated */
/* ARCH-CLOSE.C -- c_archive_close, closing the game's archive file.
 */

/* Close the archive if it is open and mark it closed, -1. A failed close is
 * fatal.
 */
INT c_archive_close(void)
{
    if (shd_archive_fd != -1) {
        if (_dos_close(shd_archive_fd) != 0)
            c_fatal(0);
        shd_archive_fd = -1;
    }
}
/* shared_include_end: ../../../../shared/c/ARCH-CLOSE.C */
