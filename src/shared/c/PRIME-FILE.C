/* PRIME-FILE.C -- c_prime_file, filling the decoder's buffer from a file.
 */

/* Make `handle` the decoder's source and read its first 200h bytes at once. */
INT c_prime_file(INT handle)
{
    shm_source_fd = handle;
    return c_refill_from_file();
}