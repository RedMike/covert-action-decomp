/* WRITE-CHECKED.C -- c_write_checked, a write that keeps its error.
 */

/* Write `many` bytes from `at` to `fd`, keeping errno in shm_save_errno if the
 * write fails.
 */
void c_write_checked(INT fd, char *at, INT many)
{
    if ((INT) write(fd, at, many) == -1)
        shm_save_errno = errno;
}
