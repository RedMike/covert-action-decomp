/* ARCH-OPEN.C -- c_archive_open, opening the game's archive file.
 */

/* Open `name` read-only as the archive; answer 1 if it opened. Without it,
 * files are read loose from the disk.
 */
INT c_archive_open(rt_addr name)
{
    INT handle;

    if (_dos_open(name, 0x8000, (rt_addr) &handle) != 0)
        return 0;
    shd_archive_fd = handle;
    return 1;
}