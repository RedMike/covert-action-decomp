/* ARCFILE.H -- the file open, create and close the ARCFILE.C target defines.
 *
 * The open finds a file either in the game's archive or on the disk.
 */
#ifndef ARCFILE_H
#define ARCFILE_H

INT c_open(rt_addr name, INT mode);
INT c_create(rt_addr name);
INT c_close(INT handle);

#endif
