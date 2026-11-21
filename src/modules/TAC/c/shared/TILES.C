/* shared/TILES.C -- the shared routines in TILES.C's unit, after TILES.C. */
#include "TAC.H"
#include "FACES.H"
#include "ANI_LD2.H"
#include "TILES.H"
#include "MODOPTS.H"

/* shared_include_start: ../../../../shared/c/DRAW-SPRITE.C -- generated */
/* DRAW-SPRITE.C -- c_draw_sprite, drawing one of the face system's sprites.
 */

/* Draw sprite `sprite` of shm_faces_sprites at (x, y). */
void c_draw_sprite(INT sprite, INT x, INT y)
{
    drv_jump_gfx_sprite_put(shd_screen, x, y, shm_faces_sprites[sprite]);
}
/* shared_include_end: ../../../../shared/c/DRAW-SPRITE.C */

