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
