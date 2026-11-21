/* FILE-CREATE.C -- making a file, and closing one.
 */
#include "FINAL.H"
#include "ARCHIVE.H"
#include "ARCFILE.H"

/* shared_include_start: ../../../../shared/c/FILE-CREATE.C -- generated */
/* FILE-CREATE.C -- c_create, creating a file to write.
 */

/* Create `name` as an ordinary file, truncating it if it is there, and answer
 * the handle. A failure is fatal.
 */
INT c_create(rt_addr name)
{
    INT handle;

    if (_dos_creat(name, 0, (rt_addr) &handle) != 0)
        c_fatal(name);
    return handle;
}
/* shared_include_end: ../../../../shared/c/FILE-CREATE.C */

/* shared_include_start: ../../../../shared/c/FILE-CLOSE.C -- generated */
/* FILE-CLOSE.C -- c_close, closing a file unless it is the archive.
 */

/* Close `handle` unless it is the archive's, which stays open. A failed close
 * is fatal.
 */
INT c_close(INT handle)
{
    if (handle != shd_archive_fd && _dos_close(handle) != 0)
        c_fatal(0);
}
/* shared_include_end: ../../../../shared/c/FILE-CLOSE.C */
