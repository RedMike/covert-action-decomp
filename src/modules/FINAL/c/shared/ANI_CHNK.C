/* ANI_CHNK.C -- an animation file's window, and the chunks after it.
 *
 * The file gives the page-1 window's origin and clip and the frame time, and
 * the window is copied whole onto page 2. A chunk's first byte is 1 for a
 * frame to draw, 2 for a fill pattern to cover the page with, 0 for nothing.
 */
#include "FINAL.H"
#include "ANIMREAD.H"
#include "ANIMFRM.H"
#include "ANIMPLAY.H"
#include "ANI_CHNK.H"

/* A page's window as nine words, so it copies whole. */
struct ANIM_HEADER {
    INT format;
    INT rest[8];
};

/* shared_include_start: ../../../../shared/c/ANIM-CHUNKS-START.C -- generated */
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
/* shared_include_end: ../../../../shared/c/ANIM-CHUNKS-START.C */

/* shared_include_start: ../../../../shared/c/CHUNK-READ.C -- generated */
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
/* shared_include_end: ../../../../shared/c/CHUNK-READ.C */
