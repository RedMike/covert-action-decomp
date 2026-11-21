/* SEGMENTS.C -- the blocks the game holds by a 16-bit segment.
 *
 * A block's segment is its entry's number here; a pointer that lies in no
 * block becomes one on the spot. A block made while a module runs goes when it
 * ends.
 */

#include <stdlib.h>
#include <string.h>

#include "HOST.H"

#define FIRST_SEGMENT 0x1000
#define BLOCKS 4096

struct BLOCK {
    unsigned char *base;
    size_t size;
    int owned;   /* malloc'd here, so freed here */
    int used;
    int born;    /* the generation it was made in: 0 is the launcher's */
};

static struct BLOCK blocks[BLOCKS];
static int next_free = 0;
static int generation;

static int slot_of(UNSIGNED_INT segment)
{
    int index = (int) segment - FIRST_SEGMENT;
    if (index < 0 || index >= BLOCKS || !blocks[index].used)
        return -1;
    return index;
}

static int take_slot(void)
{
    int tries;
    for (tries = 0; tries < BLOCKS; tries++) {
        int index = next_free;
        next_free = (next_free + 1) % BLOCKS;
        if (!blocks[index].used)
            return index;
    }
    host_fatal("out of segments");
    return -1;
}

UNSIGNED_INT host_block_new(size_t size)
{
    int index = take_slot();
    blocks[index].base = (unsigned char *) calloc(size ? size : 1, 1);
    if (!blocks[index].base)
        host_fatal("out of memory");
    blocks[index].size = size;
    blocks[index].owned = 1;
    blocks[index].used = 1;
    blocks[index].born = generation;
    return (UNSIGNED_INT) (FIRST_SEGMENT + index);
}

UNSIGNED_INT host_block_adopt(void *base, size_t size)
{
    int index;
    /* The same block adopted twice is one entry. */
    for (index = 0; index < BLOCKS; index++)
        if (blocks[index].used && blocks[index].base == base)
            return (UNSIGNED_INT) (FIRST_SEGMENT + index);
    index = take_slot();
    blocks[index].base = (unsigned char *) base;
    blocks[index].size = size;
    blocks[index].owned = 0;
    blocks[index].used = 1;
    blocks[index].born = generation;
    return (UNSIGNED_INT) (FIRST_SEGMENT + index);
}

/* A module's blocks are the generation its run opens, and all go when it ends:
 * what it allocated is freed, and a pointer adopted as a block is
 * forgotten. */
void host_blocks_module_begin(void)
{
    generation++;
}

void host_blocks_module_end(void)
{
    int index;
    for (index = 0; index < BLOCKS; index++)
        if (blocks[index].used && blocks[index].born == generation)
            host_block_free((UNSIGNED_INT) (FIRST_SEGMENT + index));
}

void host_block_free(UNSIGNED_INT segment)
{
    int index = slot_of(segment);
    if (index < 0)
        return;
    if (blocks[index].owned)
        free(blocks[index].base);
    memset(&blocks[index], 0, sizeof blocks[index]);
}

unsigned char *host_block_base(UNSIGNED_INT segment)
{
    int index = slot_of(segment);
    return index < 0 ? 0 : blocks[index].base;
}

size_t host_block_size(UNSIGNED_INT segment)
{
    int index = slot_of(segment);
    return index < 0 ? 0 : blocks[index].size;
}

/* A block the game allocated smaller than what the host keeps in it: a page is
 * 32000 bytes on the EGA and 64000 here. */
void host_block_grow(UNSIGNED_INT segment, size_t size)
{
    int index = slot_of(segment);
    unsigned char *grown;
    if (index < 0 || blocks[index].size >= size || !blocks[index].owned)
        return;
    grown = (unsigned char *) realloc(blocks[index].base, size);
    if (!grown)
        host_fatal("out of memory");
    memset(grown + blocks[index].size, 0, size - blocks[index].size);
    blocks[index].base = grown;
    blocks[index].size = size;
}

/* The block a pointer lies in and how far into it, adopting the pointer
 * as a block of its own where it lies in none. */
UNSIGNED_INT host_block_of(const void *at, size_t *offset)
{
    const unsigned char *p = (const unsigned char *) at;
    int index;
    for (index = 0; index < BLOCKS; index++) {
        const struct BLOCK *b = &blocks[index];
        if (b->used && b->size && p >= b->base && p < b->base + b->size) {
            *offset = (size_t) (p - b->base);
            return (UNSIGNED_INT) (FIRST_SEGMENT + index);
        }
    }
    *offset = 0;
    return host_block_adopt((void *) at, 0);
}
