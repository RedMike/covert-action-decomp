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