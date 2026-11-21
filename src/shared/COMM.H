/* COMM.H -- the block of state COVERT shares with every module it runs.
 *
 * COVERT stays resident and publishes a far pointer to the block at a fixed
 * low-memory word, which every module reads back before each access.
 */
#ifndef COMM_H
#define COMM_H

#include "PORTING.H"

/* struct COMM_BLOCK; a field of unknown purpose is named for its offset. */
#include "STRUCTS.H"

/* The names for next_module. */
#include "NEXTMOD.H"

/* The bits of options. */
#include "CMP_OPTS.H"

/* Asking for the block with COMM(), and publishing it with COMM_PUBLISH:
 * through the low-memory pointer on DOS, and supplied by the host otherwise.
 */
#ifdef PORT_MODERN
/* Supplied by the host. */
struct COMM_BLOCK FAR *port_comm(void);
void port_comm_publish(struct COMM_BLOCK FAR *block);
#define COMM() port_comm()
#define COMM_PUBLISH(block) port_comm_publish(block)
#else
#define COMM() (*(struct COMM_BLOCK FAR * FAR *) 0x000004f0L)
#define COMM_PUBLISH(block) (COMM() = (block))
#endif


/* The block as bytes, for copying a save section out of it at a computed
 * offset.
 */
#define COMM_BYTES ((unsigned char FAR *) COMM())
/* The low byte of `graphics_letter`, read as a byte as the shipped code does.
 */
#define COMM_LETTER_BYTE (((unsigned char FAR *) COMM())[0x44])

#endif /* COMM_H */
