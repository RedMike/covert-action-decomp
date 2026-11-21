/* MENU.H -- the menu and its box, the input under it, and the save file.
 */
#ifndef MENU_H
#define MENU_H

INT c_menu_run(rt_addr title, INT x, INT y);
INT c_menu_draw(char *title, INT x, INT y, INT sel);
INT c_menu_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour);
INT c_outline_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour);
INT c_pan_restore(INT x, INT y);
INT c_menu_key(void);
void c_wait_for_release(void);
INT c_joystick_key(void);
INT c_joystick_read(INT *px, INT *py);
INT c_joystick_button(INT button);
void c_save_put(char *name);
void c_put_section(INT fd, char *at, INT many);
void c_get_section(INT fd, char *at, INT many);
INT c_save_get(char *name);

#endif
