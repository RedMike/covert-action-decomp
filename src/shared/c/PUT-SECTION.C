/* PUT-SECTION.C -- c_put_section, writing one section of a save.
 */

/* Write `many` bytes from `at` to `fd` or, when shm_save_offset is set, into
 * the shared block at that offset.
 */
void c_put_section(INT fd, char *at, INT many)
{
    char FAR *far_at;

    if (shm_save_offset != 0) {
        far_at = at;
        shm_save_block = COMM_BYTES + shm_save_offset;
        COPY_FAR(far_at, shm_save_block, many);
        shm_save_offset += many;
    } else {
        write(fd, at, many);
    }
}