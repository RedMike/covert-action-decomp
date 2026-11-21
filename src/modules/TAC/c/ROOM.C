/* ROOM.C -- drawing the room the player is in.
 */
#include "TAC.H"
#include "CITY.H"
#include "MENU.H"
#include "MAPDRAW.H"
#include "ROOM.H"
#include "WALLCELL.H"

/* Lay out one room at sixteen pixels to the cell: the striped ground, the
 * floor under it, whatever stands on each cell, and the frame round the lot. */
INT c_draw_room(INT room)
{
    INT v0j;    /* the cell being drawn, across */
    INT v1l;    /* and down */
    INT v2n;    /* what to take from the sheet, down */
    INT v3;     /* what stands on the cell */
    INT v4b;    /* how deep the room is, in pixels */

    /* Wipe the view's half of the screen to the striped ground. */
    c_fill_box(0, 0, 172, 200, 1);
    for (v1l = 0; v1l < 200; v1l += 2)
        c_draw_line(0, v1l, 172, v1l, 5);
    /* The divider between the view and the panels. */
    c_draw_line(171, 0, 171, 199, 15);
    c_draw_line(172, 0, 172, 199, 5);
    /* Centre the room in the view rather than follow the player. */
    asm_view_left = 88
        - ((char) asm_rooms[room].width << 4) / 2;
    v4b = (char) asm_rooms[room].height << 4;
    asm_view_top = 108 - v4b / 2;
    /* Its edges on screen; both are overwritten below with its edges on the map. */
    asm_room_right = (INT) asm_view_left
        + ((char) asm_rooms[room].width << 4) - 1;
    asm_room_bottom = v4b + asm_view_top - 1;
    /* Bare floor over every cell first. */
    for (v0j = 0;
         (char) asm_rooms[room].width > v0j; v0j++)
        for (v1l = 0;
             (char) asm_rooms[room].height > v1l;
             v1l++)
            drv_jump_gfx_copy_rect(asm_status_page, 0, 112, 16, 16, shd_screen, (v0j << 4) + asm_view_left, (v1l << 4) + asm_view_top);
    FOBJ_FLOOR_TINT(room, asm_view_left, asm_view_top,
                    (char) asm_rooms[room].width << 4,
                    (char) asm_rooms[room].height << 4);
    /* The room's edges in map pixels, which keep the player inside it. */
    asm_room_left =
        (char) asm_rooms[room].left << 4;
    asm_room_top =
        (char) asm_rooms[room].top << 4;
    asm_room_right =
        ((char) asm_rooms[room].width << 4)
        + asm_room_left - 1;
    asm_room_bottom =
        ((char) asm_rooms[room].height << 4)
        + asm_room_top - 1;
    /* Then whatever stands on each cell, skipping empty ones. */
    for (v1l = 0;
         (char) asm_rooms[room].height > v1l; v1l++)
        for (v0j = 0;
             (char) asm_rooms[room].width > v0j;
             v0j++) {
            v3 = (char) asm_floor_map[v1l + ((((char) asm_rooms[room].left
                + v0j) << 5) + (char) asm_rooms[room].top)];
            if (v3 == -1)
                continue;
            /* An open thing's picture sits one row further down the sheet. */
            v2n = dat_floor_objects[FOBJ_SPRITE(v3 & 0x3f)].sprite_y;
            if ((v3 & 0x80) != 0)
                v2n += 16;
            v3 &= 0x3f;
            drv_jump_gfx_copy_rect(asm_status_page, dat_floor_objects[FOBJ_SPRITE(v3)].sprite_x, v2n, 16, 16, shd_screen, (v0j << 4) + asm_view_left, (v1l << 4) + asm_view_top);
            FOBJ_TINT(v3, room, (v0j << 4) + asm_view_left, (v1l << 4) + asm_view_top, 16);
        }
    /* Frame the room, and keep the finished view on the map page to redraw from. */
    c_outline_box(asm_view_left - 1, asm_view_top - 1,
                    ((char) asm_rooms[room].width
                     << 4) + 1,
                    ((char) asm_rooms[room].height
                     << 4) + 1, 11);
    drv_jump_gfx_copy_rect(shd_screen, 0, 0, 172, 200, shd_map_page, 0, 0);
    /* Name the room in the strip along the top: the street, in an ambush. */
    c_outline_box(26, 0, 143, 18, 7);
    drv_real_fill_rect(shd_screen, 27, 1, 141, 16, 1);
    c_write_text_trimmed(asm_mission_kind == 3 ? (drv_addr) dat_str_street
                    : (drv_addr) dat_room_kinds[asm_rooms[asm_room_last].kind].name,
                    32, 2, 15);
    /* And the equipment panel beside it, fresh. */
    c_draw_kit_panel();
}
