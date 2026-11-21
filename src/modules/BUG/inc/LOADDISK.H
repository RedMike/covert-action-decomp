/* LOADDISK.H -- asking for the right floppy to be put in the drive.
 *
 * Sites push `ready` as a long or as a word, so the prototype ends in an
 * ellipsis; UNCHECKED_PARAMS holds the parameter for the portable build.
 */
#ifndef LOADDISK_H
#define LOADDISK_H

INT c_want_disk(INT disk, UNCHECKED_PARAMS(LONG ready));

#endif
