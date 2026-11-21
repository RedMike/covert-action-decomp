/* WALLCELL.H -- walls, and choosing, scrapping and furnishing the rooms.
 */
#ifndef WALLCELL_H
#define WALLCELL_H

INT c_furnish_room(INT room);
INT c_pick_rooms(void);
INT c_scrap_room(INT room);
INT c_set_wall(INT col, INT row, INT side);

/* The floor object whose picture a cell's object is drawn with, and the
 * recolouring after it; the shipped drawing without the defines. */
#ifdef TAC_UNIMPLEMENTED_ROOMS
INT c_fobj_sprite(INT obj);
#define FOBJ_SPRITE(obj) c_fobj_sprite(obj)
#else
#define FOBJ_SPRITE(obj) (obj)
#endif

#if defined(TAC_UNIMPLEMENTED_ROOMS) || defined(TAC_ROOM_RECOLOUR)
void c_fobj_tint(INT obj, INT room, INT x, INT y, INT size);
#define FOBJ_TINT(obj, room, x, y, size) c_fobj_tint(obj, room, x, y, size)
#else
#define FOBJ_TINT(obj, room, x, y, size)
#endif

#ifdef TAC_ROOM_RECOLOUR
void c_fobj_floor_tint(INT room, INT x, INT y, INT w, INT h);
#define FOBJ_FLOOR_TINT(room, x, y, w, h) c_fobj_floor_tint(room, x, y, w, h)
#else
#define FOBJ_FLOOR_TINT(room, x, y, w, h)
#endif

#endif
