/* HOOK-MESSAGE.C -- the agent picture a piece of news is shown on.
 */
#include "BUG.H"
#include "PRIMS.H"
#include "MENU.H"
#include "TEXTLAY.H"
#include "FACES.H"
#include "BOARD.H"

/* Draw the agent picture inside the title box, with the face or the wire
 * picture and the message in shm_scratch on it, then a random chain of wire
 * for a wiretap or a plain frame for a photo.
 */
void c_hook_message(void)
{
    INT v0j;
    INT v1k;
    INT v2l;
    INT v3m;   /* how far along the wire the chain has been drawn */
    INT v4n;   /* x of the picture */
    INT v5o;   /* y of it */
    INT v6;    /* the length of the segment being drawn */

    v4n = c_clamp(0x1f, asm_title_x - 0x92,
                             asm_title_x);
    v5o = c_clamp(0x31, asm_title_y - 0x66,
                             asm_title_y);
    drv_jump_gfx_sprite_put(shd_screen, v4n, v5o, asm_agent_sprite);
    if (shm_menu_face > -1)
        c_draw_face_panel(shm_menu_face, v4n + 0x3a, v5o + 0x18);
    if (shm_menu_face == -2)
        drv_jump_gfx_sprite_put(shd_screen, v4n + 0x3e, v5o + 0xa,
                          asm_wire_sprite);
    shd_screen->bg_pen = 0xb;
    c_draw_message(0xe, v4n + 0x14, v5o + 0x43, 3);
    c_draw_message(0xe, v4n + 0x13, v5o + 0x43, 5);
    if (shm_wire_clue_source != 1) {
        c_outline_box(v4n + 0xd, v5o + 0xa, 0x78, 0x4e, 0xf);
    } else {
        v3m = 0x10;
        do {
            v6 = c_random_below(0x10) + 2;
            c_draw_line(v4n + v3m, v5o + 0x40, v4n + v3m + v6,
                               v5o + 0x40, 0xf);
            v3m += v6;
            c_draw_line(v4n + v3m, v5o + 0x40, v4n + v3m,
                               v5o + 0x30, 0xf);
            c_draw_line(v4n + v3m, v5o + 0x30, v4n + v3m + 4,
                               v5o + 0x30, 0xf);
            v3m += 4;
            c_draw_line(v4n + v3m, v5o + 0x40, v4n + v3m,
                               v5o + 0x30, 0xf);
        } while (v3m < 0x72);
        c_draw_line(v4n + v3m, v5o + 0x40, v4n + 0x82, v5o + 0x40, 0xf);
    }
}
