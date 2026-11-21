/* LOADDISK.H -- the disk prompt the LOADDISK.C target defines.
 *
 * Sites push `ready` as a long or as a word, so UNCHECKED_PARAMS spells an
 * ellipsis and names the parameter for the portable build.
 */
#ifndef LOADDISK_H
#define LOADDISK_H

INT c_want_disk(INT disk, UNCHECKED_PARAMS(LONG ready));

#endif
