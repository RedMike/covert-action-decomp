/* shared/CAMPAIGN-MISSION-END.C -- the shared routines in CAMPAIGN-MISSION-END.C's unit, after CAMPAIGN-MISSION-END.C. */
#include "FINAL.H"
#include "SPRITES.H"
#include "PORTING.H"
#include "KEYCODES.H"
#include "ARCHIVE.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "MENUS.H"
#include "SEQUENCE.H"
#include "LOADDISK.H"
#include "SCREEN.H"
#include "MAIN.H"
#include "CSTART.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "ORIENT.H"
#include "SAVELOAD.H"
#include "CASERUN.H"
#include "CMISEND.H"
#include "CRIMEVNT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* shared_include_start: ../../../../shared/c/DRAW-SPRITE.C -- generated */
/* DRAW-SPRITE.C -- c_draw_sprite, drawing one of the face system's sprites.
 */

/* Draw sprite `sprite` of shm_faces_sprites at (x, y). */
void c_draw_sprite(INT sprite, INT x, INT y)
{
    drv_jump_gfx_sprite_put(shd_screen, x, y, shm_faces_sprites[sprite]);
}
/* shared_include_end: ../../../../shared/c/DRAW-SPRITE.C */

/* shared_include_start: ../../../../shared/c/ASK-MENU.C -- generated */
/* ASK-MENU.C -- c_ask_menu, putting up a menu and answering the choice.
 */

/* Run the menu `text` at (x, y) and answer the choice, straight through to
 * c_menu_run.
 */
INT c_ask_menu(rt_addr text, INT x, INT y)
{
    return c_menu_run(text, x, y);
}
/* shared_include_end: ../../../../shared/c/ASK-MENU.C */

