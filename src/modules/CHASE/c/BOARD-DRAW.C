/* BOARD-DRAW.C -- scrolling and drawing the map window.
 */
#include "CHASE.H"
#include "RANDOM.H"
#include "LINE.H"
#include "BOARDDRA.H"
#include "BOARDEXI.H"

/* Scroll the map window towards car `car` and draw it: the five-by-five block
 * of tiles under the window, the streets closed off in each, the three cars in
 * range, and the frame.
 *
 * The locals' names fix their frame slots.
 */
INT c_board_draw(INT car, INT atx, INT aty)
{
    INT v0j;                            /* where the window is scrolling to, y */
    INT v1j;                            /* the car's x, then the tile column */
    INT v2j;                            /* the car's y, then the tile row */
    INT v3k;                            /* the street bit, then the car */
    INT v4k;                            /* the tile's x in the sheet, then the car's */
    INT v5l;                            /* the window's tile column */
    INT v6l;                            /* the tile's y in the sheet, then the car's */
    INT v7m;                            /* the window's tile row */
    INT v8m;                            /* whether it is drawn at its mark */
    INT v9n;                            /* the sprite to draw for it */
    INT v10g;                           /* where the window is scrolling to, x */

    v1j = asm_cars[car].x;
    v2j = asm_cars[car].y;
    v10g = c_clamp(v1j - 0x3c, 0, 0x288);
    v0j = c_clamp(v2j - 0x32, 0, 0x29c);
    if (asm_view_set == 0) {
        asm_view_set = v10g;
        asm_view_at = v0j;
    }
    do {
        asm_view_set += c_clamp(v10g - (INT) asm_view_set, -4, 4);
        asm_view_at += c_clamp(v0j - (INT) asm_view_at, -4, 4);
        v5l = (INT) asm_view_set / 32;
        v7m = (INT) asm_view_at / 32;
        if (v5l != asm_view_col || v7m != asm_view_row) {
            for (v1j = 0; v1j < 5; v1j++)
                for (v2j = 0; v2j < 5; v2j++) {
                    v4k = (asm_cell_map[(v5l + v1j) * 24 + v7m + v2j] >> 4) << 5;
                    v6l = 0x11;
                    while (v4k >= 0x140) {
                        v4k -= 0x140;
                        v6l += 0x20;
                    }
                    drv_jump_gfx_copy_rect(dat_tile_page, v4k, v6l, 0x20, 0x20, shd_map_page, v1j << 5, v2j << 5);
                    for (v3k = 0; v3k < 4; v3k++)
                        if ((1 << v3k
                             & asm_cell_map[(v5l + v1j) * 24 + v7m + v2j]) == 0)
                            drv_real_fill_rect(shd_map_page,
                                (v1j << 5) + dat_car_offset[v3k * 2],
                                (v2j << 5) + dat_car_offset[v3k * 2 + 8],
                                dat_car_offset[v3k * 2 + 1],
                                dat_car_offset[v3k * 2 + 9], 7);
                }
            asm_view_col = v5l;
            asm_view_row = v7m;
        }
        drv_jump_gfx_copy_rect(shd_map_page, asm_view_set - (v5l << 5), asm_view_at - (v7m << 5), 0x78, 0x64, shd_map_page, atx, aty);
        for (v3k = 0; v3k < 3; v3k++) {
            if (v3k != 0
                && asm_cars[v3k].suspicion
                   > 2 * asm_suspicion_scale
                && asm_frame_tick & 2)
                continue;
            if ((v8m = asm_chase_kind == 2 ? (v8m = v3k > 0) : v3k == 0) == 0) {
                v4k = asm_cars[v3k].x
                      - asm_view_set;
                v6l = asm_cars[v3k].y
                      - asm_view_at;
                v9n = (asm_cars[v3k].suspicion
                       > asm_suspicion_scale ? 0
                       : v3k == asm_active_car
                         && (asm_frame_tick & 7) == 0 ? 8 : 4)
                      + asm_cars[v3k].facing;
                if (asm_frame_tick & 4
                    && asm_cars[v3k].goal != -1) {
                    if (((asm_cars[v3k].facing
                          + 1) & 3)
                        == asm_cars[v3k].goal)
                        v9n += 0xc;
                    if (((asm_cars[v3k].facing
                          - 1) & 3)
                        == asm_cars[v3k].goal)
                        v9n += 0x18;
                }
            } else {
                v4k = asm_cars[v3k].from_x
                      - asm_view_set;
                v6l = asm_cars[v3k].from_y
                      - asm_view_at;
                v9n = (asm_cars[v3k].locked_on != 0 ? 0 : 4)
                      + asm_cars[v3k].goal;
            }
            if (v4k > 4 && v4k < 0x74 && v6l > 4 && v6l < 0x60)
                c_board_car(v4k + atx, v6l + aty, v3k, v9n);
        }
        shd_screen->page = 1;
        c_draw_line(atx, aty, atx + 0x77, aty, 0xf);
        c_draw_line(atx + 0x77, aty + 0x63, atx + 0x77, aty, 0xf);
        c_draw_line(atx + 0x77, aty + 0x63, atx, aty + 0x63, 0xf);
        c_draw_line(atx, aty, atx, aty + 0x63, 0xf);
        shd_screen->page = 0;
        drv_jump_gfx_copy_rect(shd_map_page, atx, aty, 0x78, 0x64, shd_screen, atx, aty);
    } while (v10g != asm_view_set || v0j != asm_view_at);
}
