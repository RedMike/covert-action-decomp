/* DOOR.C -- drawing a cell, and both halves of a door.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "PAGESHOW.H"
#include "DOOR.H"
#include "WALLCELL.H"

/* Draw one cell of the room the player is in, and where the cell is a door,
 * open its other half and draw that too. */
INT c_draw_cell(INT col, INT row)
{
    INT v0j;    /* the other half's column */
    INT v1k;    /* and row */
    INT v2l;    /* where this cell lands across */
    INT v3m;    /* and down */
    INT v4o;    /* which row of the sheet to take */
    INT v5;     /* which way the door faces */
    INT v6a;    /* what is on the cell */

    /* Only a cell holding something, in the room on screen, is drawn. */
    v6a = (char) asm_floor_map[(col << 5) + row];
    if (v6a != -1
        && (char) asm_room_map[(col << 5) + row]
           == asm_room_last) {
        /* An open thing's picture sits one row further down the sheet. */
        v4o = dat_floor_objects[FOBJ_SPRITE(v6a & 0x3f)].sprite_y;
        if ((v6a & 0x80) != 0)
            v4o += 16;
        v6a &= 0x3f;
        /* Where the cell sits in the centred view of the room. */
        v2l = ((col - (char) asm_rooms[asm_room_last].left) << 4)
              + asm_view_left;
        v3m = ((row - (char) asm_rooms[asm_room_last].top) << 4)
              + asm_view_top;
        /* Draw it, tinted, and keep a copy on the map page for later redraws. */
        drv_jump_gfx_copy_rect(asm_status_page, dat_floor_objects[FOBJ_SPRITE(v6a)].sprite_x, v4o, 16, 16, shd_screen, v2l, v3m);
        FOBJ_TINT(v6a, asm_room_last, v2l, v3m, 16);
        drv_jump_gfx_copy_rect(shd_screen, v2l, v3m, 16, 16, shd_map_page, v2l, v3m);
    }
    /* A door has a twin on the far side of the wall that opens and shuts with it. */
    if ((dat_floor_objects[(v6a & 0x3f)].flags & FOBJ_DOOR)
        != 0) {
        /* The low two bits of a door say which side its twin is on. */
        v5 = v6a & 3;
        v0j = dat_side_dx[v5] + col;
        v1k = dat_side_dy[v5] + row;
        /* The twin takes this half's open bit. */
        asm_floor_map[(v0j << 5) + v1k] &= 0x7f;
        asm_floor_map[(v0j << 5) + v1k] +=
            asm_floor_map[(col << 5) + row] & 0x80;
        /* Where the twin shows in this room too, it is heard and drawn. */
        if ((char) asm_room_map[(v0j << 5) + v1k]
            == asm_room_last) {
            c_sound_command(
                (asm_floor_map[(v0j << 5) + v1k] & 0x80)
                != 0 ? 13 : 14);
            c_draw_cell(v0j, v1k);
        }
    }
}
