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