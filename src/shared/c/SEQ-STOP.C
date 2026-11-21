/* SEQ-STOP.C -- c_seq_stop, taking a sequence down.
 */

/* Take the sequence down: copy the shown page over the hidden one where two
 * are in use, then give the memory up. Only the first non-zero sprite handle
 * is freed, as shipped.
 */
INT c_seq_stop(void)
{
    INT i;

    shm_seq_picture = 0;
    if (drv_jump_gfx_capability(0) != 0 && shd_anim_page->page == 0) {
        drv_jump_gfx_copy_rect((struct RASTPORT *) drv_page_shown, 0, 0, 0x140, 0xc8, (struct RASTPORT *) drv_page_hidden, 0, 0);
        drv_jump_gfx_show_page(shd_anim_page->page);
        *(char *) shd_anim_page ^= 1;
    }
    _dos_freemem(shm_anim_segment);
    for (i = 0; i < 0xfa; i++)
        if (shm_anim_sprites[i] != 0) {
            _dos_freemem(shm_anim_sprites[i]);
            break;
        }
}