/* GET-SECTION.C -- c_get_section, reading one section of a saved game.
 */

/* Read `many` bytes of a saved game into `at`: from the shared block when
 * shm_save_offset is set, else from `fd`.
 */
void c_get_section(INT fd, char *at, INT many)
{
    char FAR *far_at;

    if (shm_save_offset != 0) {
        far_at = at;
        shm_save_block = COMM_BYTES + shm_save_offset;
        COPY_FAR(shm_save_block, far_at, many);
        shm_save_offset += many;
    } else {
        read(fd, at, many);
    }
}