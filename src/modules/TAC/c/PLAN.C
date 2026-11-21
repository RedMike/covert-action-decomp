/* PLAN.C -- drawing the floor plan.
 */
#include "TAC.H"
#include "CITY.H"
#include "MENU.H"
#include "WALLCELL.H"
#include "PLAN.H"

/* Draw the floor plan at three pixels to the cell: the walls, whatever stands
 * on each cell, and a cross on every marker that is still live. */
INT c_draw_plan(INT left, INT top, INT scale)
{
    INT v0j;
    INT v1j;    /* where this cell is across */
    INT v2k;    /* and down */
    INT v3l;    /* the column being drawn */
    INT v4m;    /* the marker being crossed */
    INT v5m;    /* the row being drawn */
    INT v6n;    /* what to take from the sheet, across */
    INT v7o;    /* and down */
    INT v8;     /* what stands on the cell */

    /* Draw on page 1, the map page, starting from a bare background. */
    shd_screen->page = 1;
    c_fill_box(left, top, left + 119, top + 95, 3);
    /* The ambush has no plan to draw, only the trap crosses. */
    if (asm_mission_kind != 3) {
        c_outline_box(left - 1, top - 1, 121, 97, 7);
        for (v3l = 0; v3l < 40; v3l++)
            for (v5m = 0; v5m < 32; v5m++) {
                /* Only rooms the player has been in, unless the floor plan is carried. */
                if ((asm_rooms[(char) asm_room_map[(v3l << 5)
                    + v5m]].flags & 2) == 0
                    && (asm_kit & 0x8000) == 0)
                    continue;
                v1j = v3l * 3 + left;
                v2k = v5m * 3 + top;
                v8 = (char) asm_floor_map[(v3l << 5) + v5m];
                /* A thing on the cell shows as its miniature from the sheet. */
                if (v8 != -1) {
                    v8 &= 0x3f;
                    v6n = dat_floor_objects[FOBJ_SPRITE(v8)].sprite_x / 16 * 3;
                    v7o = dat_floor_objects[FOBJ_SPRITE(v8)].sprite_y / 16 * 3 + 128;
                    drv_jump_gfx_copy_rect(asm_status_page, v6n, v7o, 3, 3, shd_screen, v1j, v2k);
                    FOBJ_TINT(v8, -1, v1j, v2k, 3);
                } else {
                    /* Bare floor shows the floor colour, the street black, and a gassed room 12. */
                    c_fill_box(v1j, v2k, v1j + 2, v2k + 2,
                                    (unsigned char) asm_room_map[(v3l << 5)
                                        + v5m]
                                    != 0 ? 3 : 0);
                    if ((asm_rooms[asm_room_map[(v3l << 5) + v5m]].flags
                         & 0x10) != 0)
                        c_fill_box(v1j, v2k, v1j + 2, v2k + 2, 12);
                }
            }
    }
    /* A cross on every trap that is set and waiting. */
    for (v4m = 0; v4m < 16; v4m++) {
        if ((asm_grenades[v4m].flags != -1
             && asm_grenades[v4m].timer
                == -9998)
            || asm_grenades[v4m].timer
               == -9999) {
            v6n = asm_grenades[v4m].x * 3
                  / 16 + left;
            v7o = asm_grenades[v4m].y * 3
                  / 16 + top;
            c_draw_line(v6n - 1, v7o - 1, v6n + 1, v7o + 1, 15);
            c_draw_line(v6n + 1, v7o - 1, v6n - 1, v7o + 1, 15);
        }
    }
    /* Copy the finished plan to the screen. */
    shd_screen->page = 0;
    drv_jump_gfx_copy_rect(shd_map_page, left - 1, top - 1, 122, 98, shd_screen, left - 1, top - 1);
}
