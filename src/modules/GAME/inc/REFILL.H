/* REFILL.H -- refilling the decoder's buffer from memory or a file.
 *
 * Each block reader is far: it is called with PUSH CS ahead of a near CALL.
 */

#include "PORTING.H"
#ifndef REFILL_H
#define REFILL_H

INT FAR c_refill_from_memory(void);
INT FAR c_refill_from_file(void);
INT c_prime_file(INT handle);

#endif
