/* MENUS.H -- the menu and its boxes, the joystick read and the pan animation.
 */
#ifndef MENUS_H
#define MENUS_H

INT c_joystick_key(void);
INT c_joystick_read(INT *px, INT *py);
INT c_menu_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour);
INT c_menu_draw(char *title, INT x, INT y, INT sel);
INT c_menu_key(void);
INT c_menu_run(rt_addr title, INT x, INT y);
INT c_outline_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour);
INT c_pan_arm(char *name, INT y, INT z);
INT c_pan_restore(INT x, INT y);
void c_wait_for_release(void);

#endif
