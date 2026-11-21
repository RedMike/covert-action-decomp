/* CHUNK-READ.C -- c_anim_chunk, reading an animation's background page.
 */

void c_anim_chunk(void)
{
    INT code;
    INT word;

    code = c_anim_byte();
    switch (code) {
    case 0:
        break;
    case 1:
        c_anim_frame_rows(shd_anim_page_2->page);
        break;
    case 2:
        c_anim_read((char *) &word, 2, 1);
        drv_jump_gfx_page_fill(shd_anim_page_2->page, word);
        break;
    }
}
