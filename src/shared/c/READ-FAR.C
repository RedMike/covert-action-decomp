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
