/* ARCHIVE.H -- what the ARCHIVE.C target defines for the rest of the module.
 *
 * The two decoder refills, the fatal error and the mode switch it makes first,
 * and the archive's directory lookup and seek.
 */

#include "PORTING.H"
#ifndef ARCHIVE_H
#define ARCHIVE_H

INT FAR c_refill_from_memory(void);
INT FAR c_refill_from_file(void);
INT c_fatal(rt_addr what);
INT c_set_mode_keeping_errno(INT mode);
INT c_archive_find(rt_addr name, char *out);
INT c_seek(INT handle, UNSIGNED_INT lo, UNSIGNED_INT hi);

#endif
