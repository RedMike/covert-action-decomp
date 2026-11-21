/* RADAR.C -- more of the module's own routines in RADAR.C's unit, after HOOK-MESSAGE.C. */
#include "TAC.H"
#include "MENU.H"
#include "PANEL.H"
#include "RADAR.H"
#include "FACES.H"
#include "RANDOM.H"

/* Save the whole working screen to the saved page. */
INT c_view_save(void)
{
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 320, 200, asm_saved_page, 0, 0);
}
