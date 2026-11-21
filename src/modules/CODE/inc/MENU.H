/* MENU.H -- the menu the MENU.C target puts up and the box it draws in.
 */
#ifndef MENU_H
#define MENU_H

INT c_menu_run(rt_addr text, INT across, INT down);
INT c_menu_draw(char *title, INT x, INT y, INT sel);

#endif
