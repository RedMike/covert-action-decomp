/* ANIM-CHUNKS-START.C -- c_anim_start_chunks, setting up both animation pages.
 */

void c_anim_start_chunks(void)
{
    shd_anim_page->page = 1;
    c_anim_read((char *) &shd_anim_page->origin_x, 2, 1);
    c_anim_read((char *) &shd_anim_page->origin_y, 2, 1);
    c_anim_read((char *) &shd_anim_page->clip_x, 2, 1);
    c_anim_read((char *) &shd_anim_page->clip_y, 2, 1);
    c_anim_read((char *) &shm_frame_ticks, 2, 1);
    *(struct ANIM_HEADER *) shd_anim_page_2 =
        *(struct ANIM_HEADER *) shd_anim_page;
    shd_anim_page_2->page = 2;
}
