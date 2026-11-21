/* ANI_OPEN.C -- opening an animation file and reading its header.
 */
#include "FINAL.H"
#include "ANIMHDR.H"
#include "ANIMREAD.H"
#include "ANI_CHNK.H"
#include "ARCFILE.H"
#include "SRCFILE.H"
#include "ANIMLOAD.H"

/* shared_include_start: ../../../../shared/c/ANIM-OPEN.C -- generated */
/* ANIM-OPEN.C -- c_anim_open, loading an animation file.
 */

/* Load the animation file `name`; answer 1, or 0 if the signature is wrong or
 * the sprites or the memory fail.
 */
INT c_anim_open(rt_addr name)
{
    INT unused;
    INT spare;

    shm_anim_fd = c_open(name, 0x8000);
    c_decode_from_file(shm_anim_fd);
    if (c_anim_signature(name) == 0) {
        c_close(shm_anim_fd);
        return 0;
    }
    c_anim_extra_blocks();
    c_anim_start_chunks();
    c_anim_chunk();
    if (c_anim_sprites() == 0 || c_anim_paragraphs() == 0) {
        c_close(shm_anim_fd);
        return 0;
    }
    c_close(shm_anim_fd);
    return 1;
}
/* shared_include_end: ../../../../shared/c/ANIM-OPEN.C */


/* shared_include_start: ../../../../shared/c/ANIM-SIGNATURE.C -- generated */
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
/* shared_include_end: ../../../../shared/c/ANIM-SIGNATURE.C */
