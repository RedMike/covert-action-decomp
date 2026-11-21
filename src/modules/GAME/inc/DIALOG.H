/* DIALOG.H -- the menu, the boxes it is drawn from, and the panning arm.
 */
#ifndef DIALOG_H
#define DIALOG_H

INT c_menu_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour);
INT c_menu_draw(char *title, INT x, INT y, INT sel);
INT c_menu_run(rt_addr title, INT x, INT y);
INT c_outline_box(INT x, INT y, INT w, INT h, UNSIGNED_INT colour);
INT c_pan_arm(char *name, INT y, INT z);

#endif
