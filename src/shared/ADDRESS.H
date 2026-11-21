/* ADDRESS.H -- the types an address the game holds in a word is written in. */
#ifndef ADDRESS_H
#define ADDRESS_H

/* An address the game holds in a word: a buffer, a string, a stream. `unsigned
 * int` on DOS and a byte pointer on a portable build.
 */
#ifdef PORT_MODERN
typedef unsigned char * rt_addr;
#else
typedef unsigned int rt_addr;
#endif

/* A stream from fopen: a word on DOS and the host's FILE * on a portable
 * build.
 */
#ifdef PORT_MODERN
#include <stdio.h>
typedef FILE * rt_stream;
#else
typedef unsigned int rt_stream;
#endif

/* A far address: the buffer a DOS read fills. A real pointer on both builds.
 */
#ifdef PORT_MODERN
typedef unsigned char * rt_far_addr;
#else
typedef char FAR * rt_far_addr;
#endif

/* The text a library function reads or writes: a real pointer on both builds.
 */
typedef unsigned char * str_addr;

/* The near address of bytes in the caller's data segment: an `int` on DOS and
 * a byte pointer on a portable build.
 */
#ifdef PORT_MODERN
typedef unsigned char * drv_addr;
#else
typedef int drv_addr;
#endif

/* A sprite handle: the segment the sprite starts at, a word on both builds. */
#ifdef PORT_MODERN
typedef unsigned short drv_sprite;
#else
typedef unsigned int drv_sprite;
#endif

#endif /* ADDRESS_H */
