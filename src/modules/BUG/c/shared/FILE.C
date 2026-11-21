/* FILE.C -- reading a whole file and writing a whole file.
 */
#include "BUG.H"
#include "ARCFILE.H"
#include "ARCHIVE.H"

/* shared_include_start: ../../../../shared/c/READ-ALL.C -- generated */
/* READ-ALL.C -- c_read_all, reading a whole file into a near buffer.
 */

/* Read all of `name` into `buf` and answer the byte count; a failed read is
 * fatal.
 */
INT c_read_all(rt_addr name, char *buf)
{
    INT got;
    INT handle;

    handle = c_open(name, 0);
    if (_dos_read(handle, (rt_far_addr) buf, 0xffff,
                          (rt_addr) &got) != 0)
        c_fatal(0);
    c_close(handle);
    return got;
}
/* shared_include_end: ../../../../shared/c/READ-ALL.C */

/* shared_include_start: ../../../../shared/c/READ-FAR.C -- generated */
/* READ-FAR.C -- c_read_all_far, reading a whole file into a far buffer.
 */

/* Read all of `name` into the far buffer `buf` and answer the byte count; a
 * failed read is fatal.
 */
INT c_read_all_far(rt_addr name, rt_far_addr buf)
{
    INT got;
    INT handle;

    handle = c_open(name, 0);
    if (_dos_read(handle, buf, 0xffff, (rt_addr) &got) != 0)
        c_fatal(0);
    c_close(handle);
    return got;
}
/* shared_include_end: ../../../../shared/c/READ-FAR.C */

/* shared_include_start: ../../../../shared/c/WRITE-FILE.C -- generated */
/* WRITE-FILE.C -- c_write_file, writing a buffer to a new file.
 */

/* Create `name`, write `len` bytes of `buf` to it and answer the count
 * written; a failed write is fatal.
 */
INT c_write_file(rt_addr name, char *buf, UNSIGNED_INT len,
                    UNSIGNED_INT wrote)
{
    INT handle;

    handle = c_create(name);
    if (_dos_write(handle, buf, len, wrote, &wrote) != 0)
        c_fatal(0);
    c_close(handle);
    return wrote;
}
/* shared_include_end: ../../../../shared/c/WRITE-FILE.C */
