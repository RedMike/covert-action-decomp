/* SAVELOAD.H -- the save and load menus and files, and the joystick button.
 */
#ifndef SAVELOAD_H
#define SAVELOAD_H

INT c_ask_drive(void);
INT c_drive_ready(INT drive);
void c_get_section(INT fd, char *at, INT many);
INT c_joystick_button(INT button);
INT c_load_menu(void);
void c_put_section(INT fd, char *at, INT many);
INT c_save_get(char *name);
void c_save_menu(void);
void c_save_put(char *name);
INT c_save_slot(char *name, LONG probe);
INT c_save_write(char *name);

#endif
