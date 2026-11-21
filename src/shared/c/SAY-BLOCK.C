/* SAY-BLOCK.C -- c_say_block, appending a text block with the usual keys.
 */

/* Append the block tagged `key` in the file `name` to shm_scratch, with the
 * seven $-keys substituted from their value buffers.
 */
INT c_say_block(rt_addr name, rt_addr key)
{
    return c_say_block_with(name, key, shd_subst_keys,
                           shd_subst_values, 7);
}
