/* SAVELOAD.H -- the save and load menus, their slots, and the sections.
 */
#ifndef SAVELOAD_H
#define SAVELOAD_H

INT c_ask_drive(void);
INT c_drive_ready(INT drive);
INT c_load_menu(void);
void c_save_menu(void);
INT c_save_get(char *name);
INT c_save_slot(char *name, LONG probe);
INT c_save_write(char *name);
void c_write_checked(INT fd, char *at, INT many);
void c_save_put(char *name);
void c_put_section(INT fd, char *at, INT many);
void c_get_section(INT fd, char *at, INT many);

#endif
