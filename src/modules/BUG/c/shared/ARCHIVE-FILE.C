/* ARCHIVE-FILE.C -- opening a file that may be inside the archive.
 */
#include "BUG.H"
#include "ARCHIVE.H"
#include "ARCFILE.H"

/* shared_include_start: ../../../../shared/c/OPEN-FILE.C -- generated */
/* OPEN-FILE.C -- c_open, opening a file from the archive or the disk.
 */

/* Open `name` and answer a handle; a failure is fatal. For an archive member
 * the archive's own handle is seeked to it; any other name is opened from the
 * disk in `mode`.
 */
INT c_open(rt_addr name, INT mode)
{
    INT opened;
    INT record[12];

    if (c_archive_find(name, (char *) record) != 0) {
        if (c_seek(shd_archive_fd, record[10], record[11]) != 0)
            c_fatal(name);
        return shd_archive_fd;
    }
    if (_dos_open(name, mode, (rt_addr) &opened) != 0)
        c_fatal(name);
    return opened;
}
/* shared_include_end: ../../../../shared/c/OPEN-FILE.C */
