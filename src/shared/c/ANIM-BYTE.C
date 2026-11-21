/* ANIM-BYTE.C -- c_anim_byte, the next byte of an animation file.
 */

/* The animation's next byte, sign-extended, refilling the buffer when it runs
 * out.
 */
INT c_anim_byte(void)
{
    if (shm_source_at >= shd_archive_buffer_end)
        c_prime_file(shm_anim_fd);
    return *(char *) shm_source_at++;
}
