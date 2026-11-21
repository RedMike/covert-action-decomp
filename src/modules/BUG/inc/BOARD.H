/* BOARD.H -- the board and its sprites, wires, clock, pictures and sounds.
 *
 * c_board_step's flag is a long, as its sites push it.
 */
#ifndef BOARD_H
#define BOARD_H

/* Indices into asm_bugs_sprites, the handles cut out of bugs.pic, which
 * c_draw_bug_sprite puts. A wire piece is + the direction, 0 to 7; 8 to 0fh
 * are cut and never drawn.
 */
#define BUG_SPRITE_WIRE     0x00    /* a wire, by direction */
#define BUG_SPRITE_WIRE_IN  0x10    /* the same where the signal comes in */
#define BUG_SPRITE_WIRE_OUT 0x18    /* and where it leaves */
#define BUG_SPRITE_CHIPS    0x20    /* + the chip, 0 to 0bh */

/* The chips: the highest of the twelve kinds, and the size of asm_deal_chip,
 * seven columns of five chips. asm_deal_lines is twice both.
 */
#define CHIP_MAX            11
#define CHIP_COLS           7
#define CHIP_ROWS           5
#define LINE_COLS           (CHIP_COLS * 2)
#define LINE_ROWS           (CHIP_ROWS * 2)

/* An asm_deal_chip entry: the kind in the low bits, and whether the slot is
 * locked, so the player cannot swap it, and whether its chip is face up.
 */
#define CHIP_KIND           0x3f
#define CHIP_LOCKED         0x40
#define CHIP_SHOWN          0x80

/* The size of asm_wire_grid, column first, one cell for every 8 pixels. */
#define WIRE_GRID_COLS      40
#define WIRE_GRID_ROWS      25

/* The eight ways out of a wire grid cell, clockwise from up on screen, as
 * dat_neighbour_col and dat_neighbour_row number them.
 */
#define WAY_N               0
#define WAY_NE              1
#define WAY_E               2
#define WAY_SE              3
#define WAY_S               4
#define WAY_SW              5
#define WAY_W               6
#define WAY_NW              7

/* A wire grid cell's bits: 1 << the way for each neighbour a wire runs to, and
 * above them whether the cell carries the signal.
 */
#define WIRE_N              0x01
#define WIRE_NE             0x02
#define WIRE_E              0x04
#define WIRE_SE             0x08
#define WIRE_S              0x10
#define WIRE_SW             0x20
#define WIRE_W              0x40
#define WIRE_NW             0x80
#define WIRE_LIVE           0x100

/* What asm_board_stage says the board is for. */
#define BOARD_STAGE_PHONES  0       /* tapping phones */
#define BOARD_STAGE_TRACER  1       /* installing a car tracer */

void c_draw_sprite(INT sprite, INT x, INT y);
void c_load_sprites(void);
void c_deal_board(void);
void c_draw_bug_sprite(INT sprite, UNSIGNED_INT x, UNSIGNED_INT y);
void c_board_step(LONG redraw);
void c_trace_wire(INT col, INT row, INT from, INT mark);
void c_draw_wires(INT col, INT row, INT from);
void c_tick(INT ticks);
void c_read_keys(void);
void c_draw_chip_box(INT chip, INT x, INT y, LONG flag);
void c_clock_draw(void);
INT c_ask_menu(rt_addr text, INT x, INT y);
void c_hook_message(void);
void c_scan_for_tap(UNSIGNED_INT what);
void c_set_palette_record(INT sound);

#endif
