/* TILES.H -- board tiles and sprites, and the cheap distance.
 */
#ifndef TILES_H
#define TILES_H

INT c_cheap_distance(INT dx, INT dy);
void c_draw_sprite(INT sprite, INT x, INT y);
void c_draw_tile_2(INT tile, INT x, INT y);
void c_load_tiles(void);

#endif
