/* ARCHIVE-FIND.C -- finding a file in the archive's directory.
 */
#include "TAC.H"
#include "FATAL.H"
#include "SEEK.H"
#include "ARCHFILE.H"

/* shared_include_start: ../../../../shared/c/ARCHIVE-FIND.C -- generated */
/* ARCHIVE-FIND.C -- c_archive_find, finding a file in the archive's directory.
 */

/* Find `name` in the archive's directory, compared without case, and copy its
 * 24-byte entry to `out`; answer 1 if it is there. A failed seek or read is
 * fatal.
 */
INT c_archive_find(rt_addr name, char *out)
{
    INT got;
    INT left;

    if (shd_archive_fd == -1)
        return 0;
    if (c_seek(shd_archive_fd, 0, 0) != 0)
        c_fatal(0);
    if (_dos_read(shd_archive_fd,
                          (rt_far_addr) &left, 2,
                          (rt_addr) &got) != 0)
        c_fatal(0);
    while (left-- != 0) {
        if (_dos_read(shd_archive_fd,
                              (rt_far_addr) out, 0x18,
                              (rt_addr) &got) != 0)
            c_fatal(0);
        if (strnicmp(out, name, 0xc) == 0)
            return 1;
    }
    return 0;
}
/* shared_include_end: ../../../../shared/c/ARCHIVE-FIND.C */

