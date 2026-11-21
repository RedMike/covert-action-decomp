/* BOARD-EXIT.C -- drawing a car on the map.
 */
#include "CHASE.H"
#include "BOARDEXI.H"

/* Draw board sprite `which` for car `car` centred on (x, y): car 0 in one
 * colour, every other car in the other, swapped in an ambush. The low bit of
 * `which` says whether the sprite lies across or down.
 */
void c_board_car(INT x, INT y, INT car, INT which)
{
    if (asm_chase_kind == 2)
        car = !car;
    if (which & 1)
        drv_jump_gfx_copy_rect(dat_tile_page, (which << 3) + 1, car ? 10 : 2, 6, 4, shd_map_page, x - 3, y - 2);
    else
        drv_jump_gfx_copy_rect(dat_tile_page, (which << 3) + 2, car ? 9 : 1, 4, 6, shd_map_page, x - 2, y - 3);
}
