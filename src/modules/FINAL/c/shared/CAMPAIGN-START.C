/* shared/CAMPAIGN-START.C -- the shared routines in CAMPAIGN-START.C's unit, after CAMPAIGN-START.C. */
#include "FINAL.H"
#include "SPRITES.H"
#include "KEYCODES.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "SCREEN.H"
#include "CMISEND.H"
#include "CMISSTRT.H"
#include "SAVELOAD.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "CSTART.H"
#include "ORIENT.H"

/* shared_include_start: ../../../../shared/c/FIELD-DRAW.C -- generated */
/* FIELD-DRAW.C -- c_text_field_draw, redrawing a text entry field.
 */

/* Redraw the `n`-cell text field at (x, y) from shm_scratch, keeping the x and
 * width of the character at the cursor.
 */
void c_text_field_draw(INT x, UNSIGNED_INT y, INT n)
{
    INT i;
    INT ch;

    x += 2;
    y += 2;
    for (i = 0; i < n; i++) {
        drv_real_fill_rect(shd_screen, x, y, 8, 8, 5);
        if ((INT) strlen(shm_scratch) > i) {
            ch = ((char *) shm_scratch)[i + 1];
            ((char *) shm_scratch)[i + 1] = 0;
            c_write_text((drv_addr) (shm_scratch + i),
                               x, y, 0xa);
            ((char *) shm_scratch)[i + 1] = ch;
            if (i == shm_field_cursor) {
                shm_field_cursor_x = x;
                shm_field_char_width = drv_jump_gfx_char_width(
                    1, ((char *) shm_scratch)[i]);
            }
            x += drv_jump_gfx_char_width(1, ((char *) shm_scratch)[i]);
        }
    }
}
/* shared_include_end: ../../../../shared/c/FIELD-DRAW.C */

