/* ARCFILE.H -- opening a file from the archive or the disk, creating, closing.
 */
#ifndef ARCFILE_H
#define ARCFILE_H

INT c_open(rt_addr name, INT mode);
INT c_create(rt_addr name);
INT c_close(INT handle);

#endif
