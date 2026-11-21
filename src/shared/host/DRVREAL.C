/* DRVREAL.C -- the dispatch segment's own routines, on the host.
 *
 * The dirty rows the animation keeps per page, the driver loader and slot
 * patcher, which do nothing here, and the disk check.
 */

#include <stdlib.h>
#include <string.h>

#include "HOST.H"
#include "DRIVERS.H"
#include "DRVREAL.H"

/* ---- the dirty rows the animation keeps ----------------------------- */

/* Per page parity: the rows an actor was drawn on since the last copy,
 * and the leftmost and rightmost column touched on each. */
static struct {
    int min_row, max_row;
    int left[HOST_HEIGHT];
    int right[HOST_HEIGHT];
} edges[2] = {
    {-1, 0, {0}, {0}}, {-1, 0, {0}, {0}}
};
static int edges_ready;

static void edges_clear(int parity)
{
    int row;
    for (row = 0; row < HOST_HEIGHT; row++) {
        edges[parity].left[row] = 0xffff;
        edges[parity].right[row] = 0;
    }
    edges[parity].min_row = -1;
    edges[parity].max_row = 0;
}

static void edges_init(void)
{
    if (edges_ready)
        return;
    edges_ready = 1;
    edges_clear(0);
    edges_clear(1);
}

static void record(int parity, const struct RASTPORT *pic, const INT *seen)
{
    int x0, x1, y0, y1, row;
    edges_init();
    if (seen[3] <= 0)
        return;
    y0 = seen[1] + pic->origin_y;
    y1 = y0 + seen[3] - 1;
    x0 = seen[0] + pic->origin_x;
    x1 = x0 + seen[2] - 1;
    if (edges[parity].min_row < 0 || y0 < edges[parity].min_row)
        edges[parity].min_row = y0;
    if (y1 > edges[parity].max_row)
        edges[parity].max_row = y1;
    for (row = y0; row <= y1; row++) {
        if (row < 0 || row >= HOST_HEIGHT)
            continue;
        if (x0 < edges[parity].left[row])
            edges[parity].left[row] = x0;
        if (x1 > edges[parity].right[row])
            edges[parity].right[row] = x1;
    }
}

void FAR drv_real_sprite_put(struct RASTPORT *pic, INT x, INT y,
                             drv_sprite sprite)
{
    INT FAR *seen = drv_jump_gfx_sprite_put_clipped(pic, x, y, sprite);
    record(pic->page & 1, pic, seen);
}

void FAR drv_real_sprite_put_2(struct RASTPORT *pic, INT x, INT y,
                               drv_sprite sprite)
{
    INT FAR *seen = drv_jump_gfx_sprite_put_clipped(pic, x, y, sprite);
    record(pic->page & 1, pic, seen);
    record((pic->page & 1) ^ 1, pic, seen);
}

void FAR drv_real_anim_reset(void)
{
    edges_init();
    edges_clear(0);
    edges_clear(1);
}

/* Copy the rows recorded for page b's parity from page a to page b and clear
 * the record. Each row's span is widened to whole eight-pixel bytes, as on the
 * EGA. */
void FAR drv_real_page_copy(INT a, INT b)
{
    int parity = b & 1, row;
    const unsigned char *from;
    unsigned char *to;
    edges_init();
    if (edges[parity].min_row < 0)
        return;
    from = host_gfx_page(a);
    to = host_gfx_page(b);
    for (row = edges[parity].min_row; row <= edges[parity].max_row; row++) {
        int left = edges[parity].left[row], right = edges[parity].right[row];
        if (row < 0 || row >= HOST_HEIGHT || left > right)
            continue;
        left &= ~7;
        right |= 7;
        if (left < 0)
            left = 0;
        if (right >= HOST_WIDTH)
            right = HOST_WIDTH - 1;
        memcpy(to + row * HOST_WIDTH + left, from + row * HOST_WIDTH + left,
               (size_t) (right - left + 1));
    }
    host_gfx_touch(b);
    edges_clear(parity);
}

/* ---- the loader, and what it loaded --------------------------------- */

/* The drivers are linked in, so there is nothing to load and nothing to
 * patch. */
void FAR drv_real_link_slots(UNSIGNED_INT driver)
{
}

UNSIGNED_INT FAR drv_real_load(drv_addr name, drv_addr second)
{
    return 0;
}

/* Whether the wanted disk is in, 0 or -1. The game's files are one directory
 * on the host, so it always is. */
INT FAR drv_real_FUN_1000_0002(drv_addr name, INT drive)
{
    return 0;
}
