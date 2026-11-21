/* SEQ-PREPARE-PAGES.C -- c_seq_prepare_pages, preparing the animation page for a frame.
 */

void c_seq_prepare_pages(void)
{
    switch (shm_frames_owed) {
    case 2:
        shm_frames_owed--;
        drv_jump_gfx_copy_rect((struct RASTPORT *) drv_page_anim, 0, 0, shd_anim_page->clip_x + 1, shd_anim_page->clip_y + 1, shd_anim_page, 0, 0);
        drv_jump_gfx_copy_rect(shd_anim_page, 0, 0, shd_anim_page->clip_x + 1, shd_anim_page->clip_y + 1, shd_anim_page_2, 0, 0);
        break;
    case 1:
        shm_frames_owed--;
        if (drv_jump_gfx_capability(0) == 0)
            drv_real_page_copy(shd_anim_page_2->page, shd_anim_page->page);
        else {
            drv_jump_gfx_copy_rect((struct RASTPORT *) drv_page_shown, 0, 0, 0x140, 0xc8, (struct RASTPORT *) drv_page_hidden, 0, 0);
            drv_jump_gfx_copy_rect(shd_anim_page_2, 0, 0, shd_anim_page->clip_x + 1, shd_anim_page->clip_y + 1, shd_anim_page, 0, 0);
        }
        break;
    case 0:
        drv_real_page_copy(shd_anim_page_2->page, shd_anim_page->page);
        break;
    }
}
