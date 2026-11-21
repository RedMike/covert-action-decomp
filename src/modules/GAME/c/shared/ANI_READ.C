/* ANI_READ.C -- reading an animation file, and the BIOS video calls beside it.
 */
#include "GAME.H"
#include "ANI_READ.H"
#include "OPENFILE.H"
#include "CREATE.H"
#include "HOOK.H"
#include "REFILL.H"

/* An animation page's record: nine words, copied whole to the second page. */
struct ANIM_HEADER {
    INT format;
    INT rest[8];
};

/* shared_include_start: ../../../../shared/c/DAC-BLOCK.C -- generated */
/* DAC-BLOCK.C -- c_set_dac_block, loading all 256 DAC colour registers.
 */

/* Load the 100h DAC colour registers from `table`, three bytes each: INT 10h
 * function 1012h.
 */
INT c_set_dac_block(char *table)
{
    INT regs[7];
    INT sregs[4];
    rt_far_addr addr[1];

    *(char FAR **) addr = (char FAR *) table;
    *((char *) regs + 1) = 0x10;
    *(char *) regs = 0x12;
    regs[1] = 0;
    regs[2] = 0x100;
    regs[3] = (UNSIGNED_INT) table;
    sregs[0] = ((UNSIGNED_INT *) addr)[1];
    int86x(0x10, (rt_addr) regs, (rt_addr) regs, (rt_addr) sregs);
}
/* shared_include_end: ../../../../shared/c/DAC-BLOCK.C */

/* shared_include_start: ../../../../shared/c/BORDER-COLOUR.C -- generated */
/* BORDER-COLOUR.C -- c_set_border_colour, which sets the border colour.
 */

/* Set the border (overscan) colour: INT 10h function 10h, subfunction 1. */
INT c_set_border_colour(INT colour)
{
    union REGS regs;

    regs.h.ah = 0x10;
    regs.h.al = 1;
    regs.h.bh = (char) colour;
    INTERRUPT(0x10, &regs, &regs);
}
/* shared_include_end: ../../../../shared/c/BORDER-COLOUR.C */

/* shared_include_start: ../../../../shared/c/VIDEO-MODE.C -- generated */
/* VIDEO-MODE.C -- c_set_video_mode, setting a BIOS video mode.
 */

/* INT 10h function 0 -- set video mode `mode`. */
INT c_set_video_mode(INT mode)
{
    INT regs[7];

    *((char *) regs + 1) = 0;
    *(char *) regs = (char) mode;
    INTERRUPT(0x10, regs, regs);
}
/* shared_include_end: ../../../../shared/c/VIDEO-MODE.C */

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

/* shared_include_start: ../../../../shared/c/ANIM-BLOCKS.C -- generated */
/* ANIM-BLOCKS.C -- c_anim_extra_blocks, reading an animation's palette block.
 */

/* Read the palette the header's flag bytes announce: 11h bytes for kind 0,
 * 306h for kind 2, else none.
 */
INT c_anim_extra_blocks(void)
{
    c_anim_read((char *) &shm_anim_more, 1, 1);
    if (shm_anim_more == 0)
        return;
    c_anim_read((char *) &shm_anim_block_kind, 1, 1);
    switch (shm_anim_block_kind) {
    case 0:
        c_anim_read((char *) shm_anim_palette, 0x11, 1);
        break;
    case 1:
        break;
    case 2:
        c_anim_read((char *) shm_anim_palette, 0x306, 1);
        break;
    }
}
/* shared_include_end: ../../../../shared/c/ANIM-BLOCKS.C */

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

/* shared_include_start: ../../../../shared/c/ANIM-SPRITES.C -- generated */
/* ANIM-SPRITES.C -- c_anim_sprites, reading every sprite of an animation.
 */

INT c_anim_sprites(void)
{
    INT ok;
    INT spare;
    INT n;

    ok = 1;
    c_anim_read((char *) shm_anim_sprites, 2, 0xfa);
    if (drv_jump_gfx_pool_alloc() == 0)
        return 0;
    for (n = 0; n < 0xfa; n++)
        if (shm_anim_sprites[n] != 0) {
            shm_anim_sprites[n] = c_anim_frame();
            if (shm_anim_sprites[n] == 0) {
                shm_anim_error = 0;
                ok = 0;
                break;
            }
        }
    drv_jump_gfx_pool_release();
    return ok;
}
/* shared_include_end: ../../../../shared/c/ANIM-SPRITES.C */

/* shared_include_start: ../../../../shared/c/ANIM-PARAGRAPHS.C -- generated */
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
/* shared_include_end: ../../../../shared/c/ANIM-PARAGRAPHS.C */

/* shared_include_start: ../../../../shared/c/ANIM-ROWS.C -- generated */
/* ANIM-ROWS.C -- c_anim_frame_rows, reading one frame straight onto a page.
 */

void c_anim_frame_rows(INT arg)
{
    INT i;

    if ((shd_archive_buffer_end - shm_source_at) % 2 != 0)
        c_anim_byte();
    if (shm_anim_packed != 0)
        drv_real_unpack_start();
    else
        c_anim_frame_header();
    for (i = 0; i < shm_sprite_height; i++) {
        if (shm_anim_packed != 0)
            drv_real_unpack_row((rt_addr) shm_anim_row);
        else
            c_anim_read(shm_anim_row, 1, shm_sprite_width);
        drv_jump_gfx_row_put((rt_addr) shm_anim_row, arg, i, 0, shm_sprite_width);
    }
}
/* shared_include_end: ../../../../shared/c/ANIM-ROWS.C */

/* shared_include_start: ../../../../shared/c/ANIM-FRAME.C -- generated */
/* ANIM-FRAME.C -- c_anim_frame, reading one animation frame into a sprite.
 */

/* Read one frame into a sprite through the driver; answer the sprite, or 0 if
 * a row was refused. shm_anim_packed picks packed rows or plain ones.
 */
INT c_anim_frame(void)
{
    INT row;

    if ((shd_archive_buffer_end - shm_source_at) % 2 != 0)
        c_anim_byte();
    if (shm_anim_packed != 0)
        drv_real_unpack_start();
    else
        c_anim_frame_header();
    drv_jump_gfx_sprite_begin(shm_sprite_width, shm_sprite_height);
    for (row = 0; row < shm_sprite_height; row++) {
        if (shm_anim_packed != 0)
            drv_real_unpack_row((rt_addr) shm_anim_row);
        else
            c_anim_read(shm_anim_row, 1, shm_sprite_width);
        if (drv_jump_gfx_sprite_row((rt_addr) shm_anim_row) == 0)
            return 0;
    }
    return drv_jump_gfx_sprite_end();
}
/* shared_include_end: ../../../../shared/c/ANIM-FRAME.C */

/* shared_include_start: ../../../../shared/c/ANIM-HEADER.C -- generated */
/* ANIM-HEADER.C -- c_anim_frame_header, reading a plain frame's size.
 */

/* Read a plain frame's header, three words: one skipped, then the width and
 * the row count.
 */
INT c_anim_frame_header(void)
{
    INT ignored;

    c_anim_read((char *) &ignored, 1, 2);
    c_anim_read((char *) &shm_sprite_width, 1, 2);
    c_anim_read((char *) &shm_sprite_height, 1, 2);
}
/* shared_include_end: ../../../../shared/c/ANIM-HEADER.C */

/* shared_include_start: ../../../../shared/c/ANIM-READ.C -- generated */
/* ANIM-READ.C -- c_anim_read, reading bytes from an animation file.
 */

/* Read `size` * `count` bytes into `dest`, a byte at a time. */
INT c_anim_read(char *dest, INT size, INT count)
{
    size = count * size;
    while (size-- != 0)
        *dest++ = (char) c_anim_byte();
}
/* shared_include_end: ../../../../shared/c/ANIM-READ.C */

/* shared_include_start: ../../../../shared/c/ANIM-BYTE.C -- generated */
/* ANIM-BYTE.C -- c_anim_byte, the next byte of an animation file.
 */

/* The animation's next byte, sign-extended, refilling the buffer when it runs
 * out.
 */
INT c_anim_byte(void)
{
    if (shm_source_at >= shd_archive_buffer_end)
        c_prime_file(shm_anim_fd);
    return *(char *) shm_source_at++;
}
/* shared_include_end: ../../../../shared/c/ANIM-BYTE.C */
