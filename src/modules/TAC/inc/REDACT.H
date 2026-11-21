/* REDACT.H -- the decoder's two refill routines.
 *
 * Each is far: it is called with PUSH CS ahead of a near CALL.
 */

#include "PORTING.H"
#ifndef REDACT_H
#define REDACT_H

INT FAR c_refill_from_memory(void);
INT FAR c_refill_from_file(void);

#endif
