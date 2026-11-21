/* ARCHIVE.H -- the archive, the decoder refills, seeking and the fatal error.
 */

#include "PORTING.H"
#ifndef ARCHIVE_H
#define ARCHIVE_H

INT c_archive_close(void);
INT c_archive_find(rt_addr name, char *out);
INT c_archive_open(rt_addr name);
INT c_fatal(rt_addr what);
INT c_prime_file(INT handle);
INT FAR c_refill_from_file(void);
INT FAR c_refill_from_memory(void);
INT c_seek(INT handle, UNSIGNED_INT lo, UNSIGNED_INT hi);
INT c_set_mode_keeping_errno(INT mode);

#endif
