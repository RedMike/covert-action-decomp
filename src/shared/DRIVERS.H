/* DRIVERS.H -- the driver entries the game calls, one prototype each. An entry
 * taking its arguments in registers is described but not declared, as C cannot
 * call it.
 */
#ifndef DRIVERS_H
#define DRIVERS_H

/* FAR and NEAR, and the widths the two builds disagree on. */
#include "PORTING.H"

/* RASTPORT, which every drawing entry takes a pointer to. */
#include "STRUCTS.H"

/* A page is a display-sized buffer, page 0 the screen, and a RASTPORT a
 * window into one. A sprite is a block of pixels, width and height first,
 * named by the segment it starts at in the driver's pool.
 */
/* An address kept in a word takes a word type from ADDRESS.H; one held in a
 * pointer is declared as that pointer.
 */

/* The word types. */
#include "ADDRESS.H"

/* graphics: slots 0x00 to 0x32 */

/* 0x00: The segment of a page, allocating it first if the driver keeps pages
 * in memory of its own: 0 if the allocation failed. Page 0 needs no
 * allocating.
 */
UNSIGNED_INT FAR drv_jump_gfx_page_seg(INT page);

/* 0x01: How many paragraphs the largest free DOS block holds. */
UNSIGNED_INT FAR drv_jump_mem_avail(void);

/* 0x02: Copy the w-by-h rectangle at (x, y) of a page into a new sprite and
 * return its handle, the segment the sprite starts at.
 */
drv_sprite FAR drv_jump_gfx_grab(INT page, INT x, INT y, INT w, INT h);

/* 0x03: Fill the w-by-h rectangle at (x, y) of the picture with a two-colour
 * pattern: colour_a and colour_b alternate across each row.
 */
void FAR drv_jump_gfx_fill(struct RASTPORT *pic, INT x, INT y, INT w, INT h,
        INT colour_a, INT colour_b);

/* 0x04: The width in pixels of the character ch in a typeface, 0 for a
 * typeface or a character the driver does not have.
 */
UNSIGNED_INT FAR drv_jump_gfx_char_width(INT typeface, signed char ch);

/* 0x05: Fill a whole page with a fill pattern, by its number in the driver's
 * pattern table.
 */
void FAR drv_jump_gfx_page_fill(INT page, INT fill);

/* 0x06: Draw a sprite at (x, y) of the picture, clipped to the picture's
 * edges, and return a far pointer to the driver's record of what was visible:
 * left, top, right, bottom, then how much was cut on each side.
 */
INT FAR * FAR drv_jump_gfx_sprite_put_clipped(struct RASTPORT *pic, INT x,
        INT y, drv_sprite sprite);

/* 0x07: Give the sprite pool back to DOS and return the segment it had, 0 if
 * there was none.
 */
UNSIGNED_INT FAR drv_jump_gfx_pool_release(void);

/* 0x08: Free the memory a page was allocated in. Page 0 is never freed. */
void FAR drv_jump_gfx_free_page(INT page);

/* 0x09: Bring a page onto the screen as a pixel dissolve: every pixel copied
 * in pseudo-random order. Page 0 is refused.
 */
void FAR drv_jump_gfx_dissolve(INT page);

/* 0x0c: The colour of the pixel at (x, y) of a page. */
UNSIGNED_INT FAR drv_jump_gfx_get_pixel(INT page, INT x, INT y);

/* 0x0e: Take the overlay sprite off page 0, restoring what it covered. */
void FAR drv_jump_gfx_overlay_remove(void);

/* 0x10: A word from the driver's capability table. Word 0 is non-zero where
 * the hardware can flip display pages.
 */
UNSIGNED_INT FAR drv_jump_gfx_capability(INT which);

/* 0x11: Take all the free DOS memory at module start as the driver's pool for
 * pages and sprites, and return its segment; entry 0x07 releases it.
 */
UNSIGNED_INT FAR drv_jump_gfx_pool_alloc(void);

/* 0x12: Write w pixel bytes as one scanline of a page, at (x, y). */
void FAR drv_jump_gfx_row_put(drv_addr pixels, INT page, INT y, INT x, INT w);

/* 0x13: Copy the w-by-h rectangle at (x, y) of one picture to (dx, dy) of
 * another. Nothing is copied when w or h is 0.
 */
void FAR drv_jump_gfx_copy_rect(struct RASTPORT *src, INT x, INT y, INT w,
        INT h, struct RASTPORT *dst, INT dx, INT dy);

/* 0x14: Write a NUL-terminated string at (x, y) of the picture, in the
 * RASTPORT's fg_pen and the typeface at its font, and return the width in
 * pixels of what was written.
 */
UNSIGNED_INT FAR drv_jump_gfx_text(struct RASTPORT *pic, INT x, INT y,
        drv_addr text);

/* 0x18: Make seg the segment of a page, so a block the caller allocated can
 * be drawn on as one.
 */
void FAR drv_jump_gfx_set_page_seg(INT page, UNSIGNED_INT seg);

/* 0x1a: Load the 16 palette registers and the border from a 17-byte table.
 * The CGA driver has no palette to load and does nothing.
 */
void FAR drv_jump_gfx_set_palette(struct PALETTE *colours);

/* 0x1b: Load the two tables the CGA driver maps colours through -- 16 entries
 * each, 128 in mode 7 -- which is how a 16-colour palette is drawn in four.
 * The EGA driver does nothing.
 */
void FAR drv_jump_gfx_set_colour_map(struct COLOUR_MAP *map_a,
        struct COLOUR_MAP *map_b);

/* 0x1d: Draw a sprite on page 0 at (x, y) as the overlay, saving what it
 * covers so entry 0x0e can take it off again.
 */
void FAR drv_jump_gfx_overlay_put(INT x, INT y, drv_sprite sprite);

/* 0x1e: Put a page on screen, copied or flipped to as the hardware allows,
 * moving the overlay onto it first. Page 0 is a no-op.
 */
void FAR drv_jump_gfx_show_page(INT page);

/* 0x1f: Draw a sprite at (x, y) of the picture, unclipped: the sprite has to
 * lie inside it. Entry 0x06 is the clipping form.
 */
void FAR drv_jump_gfx_sprite_put(struct RASTPORT *pic, INT x, INT y,
        drv_sprite sprite);

/* 0x20: Finish the sprite under construction and return its handle: 0x22
 * begins it and 0x21 adds each row.
 */
drv_sprite FAR drv_jump_gfx_sprite_end(void);

/* 0x21: Append one row of pixels to the sprite under construction. Returns 0
 * when the pool is full, in which case the sprite's height is cut short.
 */
UNSIGNED_INT FAR drv_jump_gfx_sprite_row(drv_addr pixels);

/* 0x22: Start building a w-by-h sprite at the pool's free end. Entry 0x21
 * adds the rows and 0x20 finishes it.
 */
void FAR drv_jump_gfx_sprite_begin(INT w, INT h);

/* 0x24: Put the display into the driver's graphics mode at start-up; the
 * flags pick a variant of it. A card that will not take the mode gets a
 * message and the program exits.
 */
void FAR drv_jump_gfx_open(INT mode_flags);

/* 0x25: drv_jump_gfx_plot. Plot one pixel of the current picture in the
 * current colour. Registers: AX = x, BX = y.
 */

/* 0x26: drv_jump_gfx_edge_fill. Fill rows AX to CX of the current picture
 * between a left and a right edge per row, in the current colour. The table
 * holds 220 left edges then 220 right edges. Registers: AX = first row, CX =
 * last row, BX = edge table.
 */

/* 0x27: Put the card's write state back to plain writes after the register-
 * called primitives. Nothing to do on CGA.
 */
void FAR drv_jump_gfx_write_reset(void);

/* 0x28: drv_jump_gfx_set_colour. Set the colour and the write operation the
 * register-called primitives draw with. Registers: AL = colour, AH = write
 * operation (0 replace, 1 AND, 2 OR, 3 XOR).
 */

/* 0x29: drv_jump_gfx_line. Draw a line between two points of the current
 * picture in the current colour. Registers: AX, BX = x1, y1; CX, DX = x2, y2.
 */

/* 0x2f: drv_jump_gfx_select_page. Make a page the one the register-called
 * primitives draw on. Registers: AX = page.
 */

/* 0x30: drv_jump_gfx_select_pic. Make a RASTPORT the one the register-called
 * primitives draw on. Registers: BX = a RASTPORT in the caller's DGROUP.
 */

/* 0x31: drv_jump_gfx_edge_copy. Copy rows AX to CX from one page to another
 * between a left and a right edge per row, the table holding 200 left edges
 * then 200 right edges. Registers: AX = first row, CX = last row, BX = edge
 * table, SI = source page, DI = destination page.
 */

/* misc: slots 0x5a to 0x61 */

/* 0x5a: Non-zero when no key is waiting, 0 when one is: the opposite sense to
 * kbhit().
 */
UNSIGNED_INT FAR drv_jump_keyboard_empty(void);

/* 0x5b: Wait for a key and return it: the scan code in the high byte, the
 * character in the low.
 */
UNSIGNED_INT FAR drv_jump_read_key(void);

/* 0x5c: Read one character through DOS, echoed to the screen. */
UNSIGNED_INT FAR drv_jump_dos_key(void);

/* 0x60: Sample both joystick axes and take the readings as the centre the
 * running extremes grow from.
 */
void FAR drv_jump_joy_calibrate(void);

/* 0x61: Sample both joystick axes and return them scaled, one byte each, in
 * one word.
 */
UNSIGNED_INT FAR drv_jump_joy_read(void);

/* sound: slots 0x64 to 0x6e */

/* 0x64: Initialise the sound device, once the graphics drivers are linked. */
void FAR drv_jump_snd_open(void);

/* 0x65: Send the sound driver a command, 0 to 46, with whatever the command
 * takes after it: ISOUND's 26 and 27 take one word.
 */
void FAR drv_jump_snd_command(INT command, ...);

/* 0x66: Shut the sound device down at exit. */
UNSIGNED_INT FAR drv_jump_snd_close(void);

#endif /* DRIVERS_H */
