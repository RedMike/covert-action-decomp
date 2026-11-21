/* DRVREAL.H -- the dispatch segment's own routines, one declaration each: they
 * sit beside the slots DRIVERS.H declares, in a segment that is one library
 * linked into every module.
 */
#ifndef DRVREAL_H
#define DRVREAL_H

/* FAR and NEAR, and the widths the two builds disagree on. */
#include "PORTING.H"

/* RASTPORT, which every drawing entry takes a pointer to. */
#include "STRUCTS.H"

/* The word types, and the slots some of these pass their frame to. */
#include "DRIVERS.H"

/* Each parameter list is what the sites pass; a routine that keeps no frame of
 * its own says how it takes them.
 */

/* Looks for the file `name` by FCB search, on the current drive, then on
 * `drive`, then on the other floppy if there are two, with INT 24h hooked so
 * an empty drive fails rather than prompts: 0 when found, -1 when not.
 */
INT FAR drv_real_FUN_1000_0002(drv_addr name, INT drive);

/* Chooses a palette by the graphics adapter's letter and tail-jumps into the
 * set-palette slot with its own frame, so its one argument is that slot's.
 */
void FAR drv_real_FUN_1000_00ca(struct PALETTE *colours);

/* Resets the animation for a sequence that restarts, once its counters and
 * actors are cleared.
 */
void FAR drv_real_anim_reset(void);

/* A line between two points in the caller's picture. */
INT FAR drv_real_draw_line(struct RASTPORT *pic, INT x1, INT y1, INT x2, INT y2, INT colour);

/* A filled rectangle in the caller's picture, given by a corner and a size
 * rather than two corners.
 */
INT FAR drv_real_fill_rect(struct RASTPORT *pic, INT x, INT y, INT w, INT h, INT colour);

/* Walk the loaded driver's entry table and write each entry into the far-jump
 * slot that stands for it, which is what makes a driver callable.
 */
void FAR drv_real_link_slots(UNSIGNED_INT driver);

/* Load a driver: allocate all of memory, EXEC it as an overlay, shrink the
 * block to what it needs, and return its segment. A second name loads a data
 * file.
 */
UNSIGNED_INT FAR drv_real_load(drv_addr name, drv_addr second);

/* Keeps no BP frame: it reads its two word arguments off the stack through BX
 * and uses BP as a scratch register.
 */
void FAR drv_real_page_copy(INT a, INT b);

/* Reads its first two words together as one far pointer, offset then segment,
 * and the third as a count; declared as the three words the sites push.
 */
void FAR drv_real_palette_put(INT at_offset, INT at_segment, INT count);

/* Reads the palette out of the picture just decoded, for drv_real_palette_put
 * to hand on.
 */
void FAR drv_real_palette_read(void);

/* Sets its own return address aside and calls the clipped sprite entry with
 * the caller's four arguments still in place, so its parameters are that
 * entry's.
 */
void FAR drv_real_sprite_put(struct RASTPORT *pic, INT x, INT y, drv_sprite sprite);

/* Sets its own return address aside and calls the clipped sprite entry with
 * the caller's four arguments still in place, so its parameters are that
 * entry's.
 */
void FAR drv_real_sprite_put_2(struct RASTPORT *pic, INT x, INT y, drv_sprite sprite);

/* Unpacks the next row of the picture into the block it is handed. */
void FAR drv_real_unpack_row(drv_addr block);

/* Starts unpacking the picture the source has been pointed at, once the
 * reader is set and before the first row.
 */
void FAR drv_real_unpack_start(void);

#endif /* DRVREAL_H */
