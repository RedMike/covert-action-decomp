/* PUZZLE.H -- the board the PUZZLE.C target sets up, draws and gives away.
 */
#ifndef PUZZLE_H
#define PUZZLE_H

void c_puzzle_set(void);
void c_puzzle_draw(void);
void c_give_letter(void);
void c_fill_guess_row(void);
void c_hint_animate(void);
void c_flash_letter(INT letter);

#endif
