/* ANIM-PARAGRAPHS.C -- c_anim_paragraphs, loading an animation's script block.
 */

INT c_anim_paragraphs(void)
{
    char FAR *p;
    UNSIGNED_INT total;
    UNSIGNED_INT paras;
    UNSIGNED_INT i;
    UNSIGNED_INT avail;

    c_anim_read((char *) &paras, 2, 1);
    avail = drv_jump_mem_avail();
    if (avail < paras) {
        shm_anim_error = 0;
        return 0;
    }
    _dos_allocmem(paras, (rt_addr) &shm_anim_segment);
    SET_POINTER_START(p, shm_anim_segment);
    total = paras << 4;
    for (i = 0; i < total; i++)
        *p++ = c_anim_byte();
    /* The byte count, which is nonzero for success. */
    return (total);
}
