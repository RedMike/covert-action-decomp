/* HOOK-MESSAGE.C -- the pop-up panel by the cursor.
 */
#include "TAC.H"
#include "MENU.H"
#include "PANEL.H"
#include "RADAR.H"
#include "FACES.H"
#include "RANDOM.H"

/* Draw the pop-up panel by the cursor: its frame, the face or the readout
 * the message is about, and the message itself. */
INT c_hook_message(void)
{
    INT v0j;
    INT v1k;
    INT v2l;
    INT v3m;
    INT v4o;    /* where the panel sits across */
    INT v5;     /* and down */
    INT v6a;

    /* Hang the panel up and to the left of its anchor, kept clear of the top left. */
    v4o = c_clamp(31,
                          (INT) asm_panel_x - 146,
                          (INT) asm_panel_x);
    v5 = c_clamp(49,
                         (INT) asm_panel_y - 102,
                         (INT) asm_panel_y);
    /* The panel's frame, with the face the message is about or the readout in it. */
    drv_jump_gfx_sprite_put(shd_screen, v4o, v5, asm_radar_sprite);
    if (shm_menu_face > -1)
        c_draw_face_panel(shm_menu_face, v4o + 66, v5 + 24);
    if (shm_menu_face == -2)
        drv_jump_gfx_sprite_put(shd_screen, v4o + 55, v5 + 7,
                          asm_readout_sprite);
    /* The message, drawn twice a pixel apart for a shadow. */
    shd_screen->bg_pen = 11;
    c_draw_message(14, v4o + 20, v5 + 67, 3);
    c_draw_message(14, v4o + 19, v5 + 67, 5);
    /* Rule two outlines on the panel, a small one inside a large one. */
    c_outline_box(v4o + 13, v5 + 10, 119, 78, 15);
    c_outline_box(v4o + 57, v5 + 41, 31, 16, 15);
}
