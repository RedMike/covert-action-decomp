/* RESTORE.C -- putting the saved screen back.
 */
#include "TAC.H"
#include "RESTORE.H"

/* Put the saved screen back, whole. */
INT c_view_restore(void)
{
    /* Undo whatever was drawn over the screen since c_view_save took it. */
    drv_jump_gfx_copy_rect(asm_saved_page, 0, 0, 320, 200, shd_screen, 0, 0);
}
