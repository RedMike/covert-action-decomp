/* CMP_STRT.H -- the campaign's start, its menus, the badge and city picture.
 */
#ifndef CMP_STRT_H
#define CMP_STRT_H

void c_clear_happen_ticks(void);
INT c_ask_menu(rt_addr title, INT x, INT y);
INT c_campaign_start(void);
INT c_city_picture(INT city, INT x, INT y);
INT c_clear_for_menu(void);
void c_draw_sprite(INT sprite, INT x, INT y);
INT c_load_city_picture(rt_addr name);
INT c_squeeze(char *s);

#endif
