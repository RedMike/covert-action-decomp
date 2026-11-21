/* CMISEND.H -- the end of a case and the screens and scenes it plays.
 *
 * c_interlude's `on` is a long, as its sites push it; only its low word is
 * read.
 */
#ifndef CMISEND_H
#define CMISEND_H

void c_case_end(void);
void c_chronology(void);
void c_grid_cell(INT cell);
void c_grid_caption(INT x, INT y, INT cell);
void c_grid_highlight_org(INT org);
void c_grid_highlight_cell(INT cell);
void c_grid_restack(INT org);
void c_grid_bar_cell(INT org);
void c_grid_connections(INT org);
void c_grid_redraw_org(INT org);
void c_draw_sprite(INT sprite, INT x, INT y);
INT c_ask_menu(rt_addr text, INT x, INT y);
rt_addr c_timestamp(INT minutes);
void c_reveal_case(void);
INT c_efficiency_report(void);
void c_career_screen(void);
void c_trim_to_width(INT width);
void c_portrait_screen(void);
void c_interlude(INT scene, LONG on);

#endif
