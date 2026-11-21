/* LOADDISK.H -- the disk prompt the LOADDISK.C target defines.
 *
 * The ellipsis lets each site push `ready` as the long or the word it shipped
 * with; UNCHECKED_PARAMS names the parameter for the portable build to read.
 */
#ifndef LOADDISK_H
#define LOADDISK_H

INT c_want_disk(INT disk, UNCHECKED_PARAMS(LONG ready));

#endif
