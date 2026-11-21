/* ANIM-SIGNATURE.C -- c_anim_signature, checking an animation file's header.
 */

/* Check the header: "PANI", a version byte and a format byte. A wrong
 * signature sets shm_anim_error to 1 and a wrong version to 2.
 */
INT c_anim_signature(rt_addr name)
{
    shm_anim_name = name;
    shm_anim_signature[0] = (char) c_anim_byte();
    shm_anim_signature[1] = (char) c_anim_byte();
    shm_anim_signature[2] = (char) c_anim_byte();
    shm_anim_signature[3] = (char) c_anim_byte();
    shm_anim_signature[4] = 0;
    shm_anim_magic_read = c_anim_byte();
    shm_anim_packed = c_anim_byte();
    if (strcmp(shd_str_pani, shm_anim_signature) != 0) {
        shm_anim_error = 1;
        return 0;
    }
    if (shm_anim_magic_read != shm_anim_magic) {
        shm_anim_error = 2;
        return 0;
    }
    return 1;
}
