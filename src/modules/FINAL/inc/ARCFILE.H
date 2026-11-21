/* ARCFILE.H -- opening and closing files, archived or loose, and creating one.
 */
#ifndef ARCFILE_H
#define ARCFILE_H

INT c_close(INT handle);
INT c_create(rt_addr name);
INT c_open(rt_addr name, INT mode);

#endif
