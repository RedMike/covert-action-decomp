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