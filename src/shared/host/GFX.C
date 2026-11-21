/* GFX.C -- the graphics driver, as EGRAPHIC's interface, in host memory.
 *
 * Pages of one byte per pixel, a sprite pool of blocks, sixteen palette
 * registers in front of a DAC, and the fonts from fonts.cv.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HOST.H"
#include "DRIVERS.H"
#include "DRVREAL.H"

#define PAGES 8
#define PAGE_BYTES (HOST_WIDTH * HOST_HEIGHT)
#define PRESENT_MS 16

static UNSIGNED_INT page_segment[PAGES];
static int shown;
static int dirty;
static int opened;
static unsigned int last_present;
static unsigned char palette[16];
static unsigned char dac[256][3];
static int colours_ready;

/* Text mode while a module runs: the window stays, shown blank. */
static int text_mode;
static unsigned char blank_page[PAGE_BYTES];

/* The CGA's sixteen colours, which are what the EGA's DAC holds in a
 * 200-line mode: entry n is colour (n & 7) with bit 4 as intensity. */
static const unsigned char CGA[16][3] = {
    {0x00, 0x00, 0x00}, {0x00, 0x00, 0xaa}, {0x00, 0xaa, 0x00},
    {0x00, 0xaa, 0xaa}, {0xaa, 0x00, 0x00}, {0xaa, 0x00, 0xaa},
    {0xaa, 0x55, 0x00}, {0xaa, 0xaa, 0xaa}, {0x55, 0x55, 0x55},
    {0x55, 0x55, 0xff}, {0x55, 0xff, 0x55}, {0x55, 0xff, 0xff},
    {0xff, 0x55, 0x55}, {0xff, 0x55, 0xff}, {0xff, 0xff, 0x55},
    {0xff, 0xff, 0xff}
};

static void colours_init(void)
{
    int i;
    if (colours_ready)
        return;
    colours_ready = 1;
    for (i = 0; i < 256; i++) {
        int c = (i & 7) | ((i >> 1) & 8);
        dac[i][0] = CGA[c][0] >> 2;
        dac[i][1] = CGA[c][1] >> 2;
        dac[i][2] = CGA[c][2] >> 2;
    }
    for (i = 0; i < 16; i++)
        palette[i] = (unsigned char) (((i & 0xf) + 8) & 0x17);
}

/* ---- pages ---------------------------------------------------------- */

unsigned char *host_gfx_page(int page)
{
    page &= PAGES - 1;
    if (!page_segment[page])
        page_segment[page] = host_block_new(PAGE_BYTES);
    return host_block_base(page_segment[page]);
}

void host_gfx_touch(int page)
{
    if ((page & (PAGES - 1)) == shown)
        dirty = 1;
}

static void dump_frame(const unsigned char *pixels,
                       const unsigned char (*rgb)[3])
{
    static unsigned int last_dump, frames;
    static const char *where;
    static int asked;
    char name[512];
    FILE *out;
    int i;
    if (!asked) {
        asked = 1;
        where = host_option("COVERT_FRAMES");
    }
    if (!where || (frames && host_ticks_ms() - last_dump < 200))
        return;
    last_dump = host_ticks_ms();
    /* Named by the module running, so a run reads by module. */
    sprintf(name, "%s/%s_%05u.ppm", where, host_module_name(), frames++);
    out = fopen(name, "wb");
    if (!out)
        return;
    fprintf(out, "P6\n%d %d\n255\n", HOST_WIDTH, HOST_HEIGHT);
    for (i = 0; i < PAGE_BYTES; i++)
        fwrite(rgb[pixels[i]], 1, 3, out);
    fclose(out);
}

static void present(void)
{
    unsigned char rgb[256][3];
    const unsigned char *pixels;
    int i;
    colours_init();
    for (i = 0; i < 256; i++) {
        const unsigned char *c = dac[i < 16 ? palette[i] : i];
        rgb[i][0] = (unsigned char) (c[0] * 255 / 63);
        rgb[i][1] = (unsigned char) (c[1] * 255 / 63);
        rgb[i][2] = (unsigned char) (c[2] * 255 / 63);
    }
    pixels = text_mode ? blank_page : host_gfx_page(shown);
    if (opened)
        host_screen_present(pixels, rgb);
    dump_frame(pixels, rgb);
    dirty = 0;
    last_present = host_ticks_ms();
}

void host_pump(void)
{
    host_screen_pump();
    host_keys_tick();
    if (dirty && host_ticks_ms() - last_present >= PRESENT_MS)
        present();
}

void host_wait_ms(unsigned int ms)
{
    host_pump();
    host_sleep_ms(ms);
}

static void ensure_open(void)
{
    colours_init();
    if (!opened) {
        opened = 1;
        host_screen_open();
        dirty = 1;
    }
}

/* A text mode from a module leaves the window open and blank; from the
 * launcher it closes the window. A graphics mode clears every page and resets
 * the colours, as the BIOS's mode set does. */
void host_gfx_mode(int mode)
{
    int i;
    if (mode == 3 || mode == 7) {
        if (dirty)
            present();
        if (host_module_running()) {
            text_mode = 1;
            dirty = 1;
            present();
            return;
        }
        host_screen_close();
        opened = 0;
        return;
    }
    text_mode = 0;
    for (i = 0; i < PAGES; i++)
        if (page_segment[i] && host_block_base(page_segment[i]))
            memset(host_block_base(page_segment[i]), 0, PAGE_BYTES);
    colours_ready = 0;
    shown = 0;
    dirty = 1;
    ensure_open();
}

void host_gfx_show(int page)
{
    ensure_open();
    shown = page & (PAGES - 1);
    dirty = 1;
    present();
}

void host_gfx_dac(int index, int red, int green, int blue)
{
    colours_init();
    dac[index & 255][0] = (unsigned char) (red & 63);
    dac[index & 255][1] = (unsigned char) (green & 63);
    dac[index & 255][2] = (unsigned char) (blue & 63);
    dirty = 1;
}

/* ---- drawing primitives -------------------------------------------- */

static void plot(int page, int x, int y, int colour, int op)
{
    unsigned char *at;
    if (x < 0 || x >= HOST_WIDTH || y < 0 || y >= HOST_HEIGHT)
        return;
    at = host_gfx_page(page) + y * HOST_WIDTH + x;
    switch (op & 3) {
    case 1: *at &= (unsigned char) colour; break;
    case 2: *at |= (unsigned char) colour; break;
    case 3: *at ^= (unsigned char) colour; break;
    default: *at = (unsigned char) (colour & 0xf); break;
    }
}

/* A rectangle cut to the page: returns 0 when nothing is left. */
static int clip_box(int *x, int *y, int *w, int *h)
{
    if (*x < 0) {
        *w += *x;
        *x = 0;
    }
    if (*y < 0) {
        *h += *y;
        *y = 0;
    }
    if (*x + *w > HOST_WIDTH)
        *w = HOST_WIDTH - *x;
    if (*y + *h > HOST_HEIGHT)
        *h = HOST_HEIGHT - *y;
    return *w > 0 && *h > 0;
}

static void solid_rect(int page, int x, int y, int w, int h, int colour)
{
    unsigned char *pixels;
    int row;
    if (!clip_box(&x, &y, &w, &h))
        return;
    pixels = host_gfx_page(page);
    for (row = 0; row < h; row++)
        memset(pixels + (y + row) * HOST_WIDTH + x, colour & 0xf, (size_t) w);
    host_gfx_touch(page);
}

/* ---- sprites -------------------------------------------------------- */

/* A sprite is a block: its width and height in the first two words and
 * one byte per pixel after them, colour 0 being transparent. */
static UNSIGNED_INT sprite_new(int w, int h)
{
    UNSIGNED_INT seg;
    unsigned char *base;
    if (w < 0)
        w = 0;
    if (h < 0)
        h = 0;
    seg = host_block_new(4 + (size_t) w * (size_t) h);
    base = host_block_base(seg);
    base[0] = (unsigned char) w;
    base[1] = (unsigned char) (w >> 8);
    base[2] = (unsigned char) h;
    base[3] = (unsigned char) (h >> 8);
    return seg;
}

static unsigned char *sprite_open(drv_sprite sprite, int *w, int *h)
{
    unsigned char *base = host_block_base(sprite);
    if (!base || host_block_size(sprite) < 4)
        return 0;
    *w = base[0] | (base[1] << 8);
    *h = base[2] | (base[3] << 8);
    if (*w <= 0 || *h <= 0
            || host_block_size(sprite) < 4 + (size_t) *w * (size_t) *h)
        return 0;
    return base + 4;
}

/* The visible part of a sprite drawn at (x, y) of a picture, as the
 * clipped put reports it: x, y, width, height, then the four cuts. */
static INT visible[8];

static INT FAR *put_sprite(struct RASTPORT *pic, int x, int y,
                           drv_sprite sprite, int clipped)
{
    int w, h, cut_l = 0, cut_t = 0, cut_r = 0, cut_b = 0;
    int row, col, page;
    unsigned char *pixels = sprite_open(sprite, &w, &h);
    unsigned char *target;
    memset(visible, 0, sizeof visible);
    if (!pixels || !pic)
        return visible;
    if (clipped) {
        if (pic->clip_x < 0 || pic->clip_y < 0)
            return visible;
        if (y < 0) {
            if (-y >= h)
                return visible;
            cut_t = -y;
        }
        if (y > pic->clip_y)
            return visible;
        if (y + h - 1 > pic->clip_y)
            cut_b = y + h - 1 - pic->clip_y;
        if (x < 0) {
            if (-x >= w)
                return visible;
            cut_l = -x;
        }
        if (x > pic->clip_x)
            return visible;
        if (x + w - 1 > pic->clip_x)
            cut_r = x + w - 1 - pic->clip_x;
    }
    visible[0] = (INT) (x + cut_l);
    visible[1] = (INT) (y + cut_t);
    visible[2] = (INT) (w - cut_l - cut_r);
    visible[3] = (INT) (h - cut_t - cut_b);
    visible[4] = (INT) cut_l;
    visible[5] = (INT) cut_t;
    visible[6] = (INT) cut_r;
    visible[7] = (INT) cut_b;
    if (visible[2] <= 0 || visible[3] <= 0) {
        visible[2] = 0;
        visible[3] = 0;
        return visible;
    }
    page = pic->page;
    target = host_gfx_page(page);
    for (row = cut_t; row < h - cut_b; row++) {
        int py = pic->origin_y + y + row;
        if (py < 0 || py >= HOST_HEIGHT)
            continue;
        for (col = cut_l; col < w - cut_r; col++) {
            int px = pic->origin_x + x + col;
            unsigned char c = pixels[row * w + col];
            if (c && px >= 0 && px < HOST_WIDTH)
                target[py * HOST_WIDTH + px] = c;
        }
    }
    host_gfx_touch(page);
    return visible;
}

static UNSIGNED_INT build_seg;
static int build_w, build_h, build_row;

/* A page or a sprite under construction that was the module's memory
 * went with it; the next module gets a fresh page where it asks. */
void host_gfx_module_end(void)
{
    int i;
    for (i = 0; i < PAGES; i++)
        if (page_segment[i] && !host_block_base(page_segment[i]))
            page_segment[i] = 0;
    if (build_seg && !host_block_base(build_seg))
        build_seg = 0;
    text_mode = 0;
}

/* ---- fonts ---------------------------------------------------------- */

/* fonts.cv: a count, an offset per face, and at each offset a descriptor read
 * backwards, then the character widths, last first, with the glyph rows after.
 * The descriptor: first and last character, row width as a power of two, fixed
 * width or 0, height, spacing, rows below the baseline. */
static unsigned char *fonts;
static size_t fonts_size;
static int fonts_tried;

struct FACE {
    int first, last, shift, fixed, height, spacing, extra, stride;
    const unsigned char *widths;
    const unsigned char *rows;
};

static void fonts_load(void)
{
    char path[512];
    FILE *in;
    long size;
    if (fonts_tried)
        return;
    fonts_tried = 1;
    in = fopen(host_path("fonts.cv", path, sizeof path), "rb");
    if (!in)
        return;
    fseek(in, 0, SEEK_END);
    size = ftell(in);
    fseek(in, 0, SEEK_SET);
    if (size > 0) {
        fonts = (unsigned char *) malloc((size_t) size);
        if (fonts && fread(fonts, 1, (size_t) size, in) == (size_t) size)
            fonts_size = (size_t) size;
    }
    fclose(in);
}

static int face_of(int index, struct FACE *face)
{
    size_t offset;
    const unsigned char *e;
    fonts_load();
    if (!fonts || fonts_size < 2 || index <= 0
            || index > (fonts[0] | (fonts[1] << 8)))
        return 0;
    if ((size_t) index * 2 + 1 >= fonts_size)
        return 0;
    offset = (size_t) (fonts[index * 2] | (fonts[index * 2 + 1] << 8));
    if (offset < 9 || offset >= fonts_size)
        return 0;
    e = fonts + offset;
    face->first = e[-8];
    face->last = e[-7];
    face->shift = e[-6] - 1;
    face->fixed = e[-5];
    face->height = e[-4];
    face->spacing = e[-3];
    face->extra = e[-2];
    if (face->last < face->first || face->shift < 0 || face->shift > 3)
        return 0;
    face->widths = e - 9 - (face->last - face->first);
    face->rows = e;
    face->stride = (face->last - face->first + 1) << face->shift;
    return face->widths >= fonts;
}

static int glyph_row_bits(const struct FACE *face, const unsigned char *row,
                          int index)
{
    const unsigned char *at = row + (index << face->shift);
    if (at + 1 >= fonts + fonts_size)
        return 0;
    return (at[0] << 8) | at[1];
}

/* Draw text: cut a fixed-width line and the rows to the clip, skip what lies
 * left of 0, then draw. A byte with bit 7 set is a new colour. Returns the
 * pen's x; *wrap_at is the byte the cut zeroed. */
static int draw_stages(struct RASTPORT *pic, const struct FACE *face,
                       int pen_x, int pen_y, unsigned char *p,
                       unsigned char **wrap_at, unsigned char *wrap_saved)
{
    int advance, height, skip = 0, trim = 0, fg, op, bg, opaque, page;
    const unsigned char *rows = face->rows;
    height = face->height + ((pic->draw_mode & 1) ? face->extra : 0);
    advance = face->fixed ? face->fixed + face->spacing : 0;
    if (advance) {
        int dx, cx = pic->clip_x;
        unsigned char *s = p;
        if (cx < 0 || pen_x > cx)
            return pen_x;
        dx = pen_x - 1;
        for (;;) {
            if (*s & 0x80) {
                s++;
                continue;
            }
            if (*s == 0)
                break;
            dx += advance;
            if (dx < cx) {
                s++;
                continue;
            }
            trim = dx - cx;
            s++;
            *wrap_at = s;
            *wrap_saved = *s;
            *s = 0;
            break;
        }
        if (pen_x < 0) {
            int chars = -pen_x / advance;
            skip = -pen_x % advance;
            pen_x = 0;
            while (chars-- > 0) {
                while (*p & 0x80)
                    p++;
                if (*p == 0)
                    return pen_x;
                p++;
            }
        }
    }
    if (pic->clip_y < 0)
        return pen_x;
    if (pen_y < 0) {
        height += pen_y;
        if (height <= 0)
            return pen_x;
        rows += (size_t) (-pen_y) * (size_t) face->stride;
        pen_y = 0;
    }
    if (pen_y > pic->clip_y)
        return pen_x;
    if (pen_y + height - 1 > pic->clip_y)
        height -= pen_y + height - 1 - pic->clip_y;
    pen_x += pic->origin_x;
    pen_y += pic->origin_y;
    fg = pic->fg_pen & 0xff;
    op = (pic->fg_pen >> 8) & 0xff;
    bg = pic->bg_pen & 0xff;
    opaque = (pic->draw_mode & 0xff) != 0;
    page = pic->page;
    for (;;) {
        int ch = *p, next = p[1], index, w, r, j;
        p++;
        if (ch == 0)
            break;
        if (ch & 0x80) {
            fg = ch & 0x7f;
            continue;
        }
        index = ch - face->first;
        if (index < 0 || ch > face->last) {
            skip = 0;
            continue;
        }
        w = advance ? advance : face->widths[index] + face->spacing;
        if (next == 0)
            w -= trim;
        w -= skip;
        if (w > 0) {
            if (opaque)
                solid_rect(page, pen_x, pen_y, w, height, bg);
            for (r = 0; r < height; r++) {
                int bits = glyph_row_bits(face, rows + r * face->stride, index);
                for (j = skip; j < skip + w && j < 16; j++)
                    if (bits & (0x8000 >> j))
                        plot(page, pen_x + j - skip, pen_y + r, fg, op);
            }
            host_gfx_touch(page);
            pen_x += w;
        }
        skip = 0;
    }
    return pen_x;
}

/* Draw text and put back the byte the cut zeroed. Returns the pen's x,
 * from the origin. */
static UNSIGNED_INT draw_text(struct RASTPORT *pic, int x, int y,
                              unsigned char *text)
{
    struct FACE face;
    unsigned char *wrap_at = 0, wrap_saved = 0;
    int pen_x;
    if (!pic || !text || *text == 0 || !face_of(pic->font, &face))
        return (UNSIGNED_INT) (x - (pic ? pic->origin_x : 0));
    pen_x = draw_stages(pic, &face, x, y, text, &wrap_at, &wrap_saved);
    if (wrap_at)
        *wrap_at = wrap_saved;
    return (UNSIGNED_INT) (pen_x - pic->origin_x);
}

/* ---- the slots ------------------------------------------------------ */

UNSIGNED_INT FAR drv_jump_gfx_page_seg(INT page)
{
    ensure_open();
    host_gfx_page(page);
    return page_segment[page & (PAGES - 1)];
}

UNSIGNED_INT FAR drv_jump_mem_avail(void)
{
    return 0xfff0;
}

drv_sprite FAR drv_jump_gfx_grab(INT page, INT x, INT y, INT w, INT h)
{
    UNSIGNED_INT seg = sprite_new(w, h);
    unsigned char *out = host_block_base(seg) + 4;
    const unsigned char *in = host_gfx_page(page);
    int row, col;
    for (row = 0; row < h; row++)
        for (col = 0; col < w; col++) {
            int px = x + col, py = y + row;
            out[row * w + col] =
                (px >= 0 && px < HOST_WIDTH && py >= 0 && py < HOST_HEIGHT)
                ? in[py * HOST_WIDTH + px] : 0;
        }
    return (drv_sprite) seg;
}

/* A recolouring, not a pattern: every pixel of colour_a inside the rectangle
 * becomes colour_b. */
void FAR drv_jump_gfx_fill(struct RASTPORT *pic, INT x, INT y, INT w, INT h,
        INT colour_a, INT colour_b)
{
    unsigned char *pixels;
    int row, col, px = x + pic->origin_x, py = y + pic->origin_y;
    int ww = w, hh = h;
    if (!clip_box(&px, &py, &ww, &hh))
        return;
    pixels = host_gfx_page(pic->page);
    for (row = 0; row < hh; row++)
        for (col = 0; col < ww; col++) {
            unsigned char *at = pixels + (py + row) * HOST_WIDTH + px + col;
            if (*at == (unsigned char) (colour_a & 0xf))
                *at = (unsigned char) (colour_b & 0xf);
        }
    host_gfx_touch(pic->page);
}

UNSIGNED_INT FAR drv_jump_gfx_char_width(INT typeface, signed char ch)
{
    struct FACE face;
    if (ch < 0 || !face_of(typeface, &face))
        return 0;
    if (ch < face.first || ch > face.last)
        return 0;
    if (face.fixed)
        return (UNSIGNED_INT) (face.fixed + face.spacing);
    return (UNSIGNED_INT) (face.widths[ch - face.first] + face.spacing);
}

void FAR drv_jump_gfx_page_fill(INT page, INT fill)
{
    memset(host_gfx_page(page), fill & 0xf, PAGE_BYTES);
    host_gfx_touch(page);
}

INT FAR * FAR drv_jump_gfx_sprite_put_clipped(struct RASTPORT *pic, INT x,
        INT y, drv_sprite sprite)
{
    return put_sprite(pic, x, y, sprite, 1);
}

UNSIGNED_INT FAR drv_jump_gfx_pool_release(void)
{
    return 0x0800;
}

void FAR drv_jump_gfx_free_page(INT page)
{
}

/* Copy the page onto the shown one in the order a 16-bit shift register with
 * taps b400h walks its pixels, 177 to 355 a frame, so three to six seconds for
 * the page. */
#define DISSOLVE_PIXELS_PER_MS 18

void FAR drv_jump_gfx_dissolve(INT page)
{
    unsigned char *from, *to;
    unsigned int lfsr = 1, n = 0, started;
    ensure_open();
    if ((page & (PAGES - 1)) == shown)
        return;
    from = host_gfx_page(page);
    to = host_gfx_page(shown);
    started = host_ticks_ms();
    do {
        unsigned int at = lfsr - 1;
        if (at < PAGE_BYTES)
            to[at] = from[at];
        if (lfsr & 1)
            lfsr = (lfsr >> 1) ^ 0xb400u;
        else
            lfsr >>= 1;
        if (++n % 1024 == 0) {
            unsigned int due = started + n / DISSOLVE_PIXELS_PER_MS;
            dirty = 1;
            present();
            while ((int) (host_ticks_ms() - due) < 0)
                host_wait_ms(1);
        }
    } while (lfsr != 1);
    dirty = 1;
    present();
}

UNSIGNED_INT FAR drv_jump_gfx_get_pixel(INT page, INT x, INT y)
{
    if (x < 0 || x >= HOST_WIDTH || y < 0 || y >= HOST_HEIGHT)
        return 0;
    return host_gfx_page(page)[y * HOST_WIDTH + x];
}

void FAR drv_jump_gfx_overlay_remove(void)
{
}

UNSIGNED_INT FAR drv_jump_gfx_capability(INT which)
{
    return which == 0 ? 1 : 0;
}

UNSIGNED_INT FAR drv_jump_gfx_pool_alloc(void)
{
    return 0x0800;
}

void FAR drv_jump_gfx_row_put(drv_addr pixels, INT page, INT y, INT x, INT w)
{
    unsigned char *target;
    int col;
    if (y < 0 || y >= HOST_HEIGHT || !pixels)
        return;
    target = host_gfx_page(page) + y * HOST_WIDTH;
    for (col = 0; col < w; col++) {
        int px = x + col;
        if (px >= 0 && px < HOST_WIDTH)
            target[px] = (unsigned char) (pixels[col] & 0xf);
    }
    host_gfx_touch(page);
}

void FAR drv_jump_gfx_copy_rect(struct RASTPORT *src, INT x, INT y, INT w,
        INT h, struct RASTPORT *dst, INT dx, INT dy)
{
    static unsigned char held[PAGE_BYTES];
    int row, sx, sy, tx, ty, ww, hh;
    const unsigned char *from;
    unsigned char *to;
    if (w <= 0 || h <= 0)
        return;
    sx = x + src->origin_x;
    sy = y + src->origin_y;
    tx = dx + dst->origin_x;
    ty = dy + dst->origin_y;
    ww = w;
    hh = h;
    if (sx < 0) {
        ww += sx;
        tx -= sx;
        sx = 0;
    }
    if (sy < 0) {
        hh += sy;
        ty -= sy;
        sy = 0;
    }
    if (tx < 0) {
        ww += tx;
        sx -= tx;
        tx = 0;
    }
    if (ty < 0) {
        hh += ty;
        sy -= ty;
        ty = 0;
    }
    if (sx + ww > HOST_WIDTH)
        ww = HOST_WIDTH - sx;
    if (tx + ww > HOST_WIDTH)
        ww = HOST_WIDTH - tx;
    if (sy + hh > HOST_HEIGHT)
        hh = HOST_HEIGHT - sy;
    if (ty + hh > HOST_HEIGHT)
        hh = HOST_HEIGHT - ty;
    if (ww <= 0 || hh <= 0)
        return;
    from = host_gfx_page(src->page);
    to = host_gfx_page(dst->page);
    for (row = 0; row < hh; row++)
        memcpy(held + row * ww, from + (sy + row) * HOST_WIDTH + sx, (size_t) ww);
    for (row = 0; row < hh; row++)
        memcpy(to + (ty + row) * HOST_WIDTH + tx, held + row * ww, (size_t) ww);
    host_gfx_touch(dst->page);
}

UNSIGNED_INT FAR drv_jump_gfx_text(struct RASTPORT *pic, INT x, INT y,
        drv_addr text)
{
    return draw_text(pic, x, y, (unsigned char *) text);
}

void FAR drv_jump_gfx_set_page_seg(INT page, UNSIGNED_INT seg)
{
    page &= PAGES - 1;
    if (!host_block_base(seg))
        return;
    host_block_grow(seg, PAGE_BYTES);
    page_segment[page] = seg;
}

void FAR drv_jump_gfx_set_palette(struct PALETTE *colours)
{
    const unsigned char *bytes = (const unsigned char *) colours;
    int i;
    colours_init();
    if (!bytes)
        return;
    for (i = 0; i < 16; i++)
        palette[i] = (unsigned char) (((bytes[i] & 0xf) + 8) & 0x17);
    dirty = 1;
}

void FAR drv_jump_gfx_set_colour_map(struct COLOUR_MAP *map_a,
        struct COLOUR_MAP *map_b)
{
}

void FAR drv_jump_gfx_overlay_put(INT x, INT y, drv_sprite sprite)
{
}

void FAR drv_jump_gfx_show_page(INT page)
{
    host_gfx_show(page);
}

void FAR drv_jump_gfx_sprite_put(struct RASTPORT *pic, INT x, INT y,
        drv_sprite sprite)
{
    put_sprite(pic, x, y, sprite, 0);
}

drv_sprite FAR drv_jump_gfx_sprite_end(void)
{
    drv_sprite done = (drv_sprite) build_seg;
    build_seg = 0;
    return done;
}

UNSIGNED_INT FAR drv_jump_gfx_sprite_row(drv_addr pixels)
{
    unsigned char *base;
    int col;
    if (!build_seg || build_row >= build_h || !pixels)
        return 0;
    base = host_block_base(build_seg) + 4 + build_row * build_w;
    for (col = 0; col < build_w; col++)
        base[col] = (unsigned char) (pixels[col] & 0xf);
    build_row++;
    return 1;
}

void FAR drv_jump_gfx_sprite_begin(INT w, INT h)
{
    build_w = w < 0 ? 0 : w;
    build_h = h < 0 ? 0 : h;
    build_row = 0;
    build_seg = sprite_new(build_w, build_h);
}

void FAR drv_jump_gfx_open(INT mode_flags)
{
    host_gfx_mode(0x0d);
}

void FAR drv_jump_gfx_write_reset(void)
{
}

/* ---- the dispatch segment's own drawing ----------------------------- */

INT FAR drv_real_draw_line(struct RASTPORT *pic, INT x1, INT y1, INT x2,
                           INT y2, INT colour)
{
    int ax = x1 + pic->origin_x, ay = y1 + pic->origin_y;
    int bx = x2 + pic->origin_x, by = y2 + pic->origin_y;
    int dx = bx > ax ? bx - ax : ax - bx, sx = ax < bx ? 1 : -1;
    int dy = by > ay ? ay - by : by - ay, sy = ay < by ? 1 : -1;
    int err = dx + dy;
    for (;;) {
        int twice;
        plot(pic->page, ax, ay, colour, 0);
        if (ax == bx && ay == by)
            break;
        twice = 2 * err;
        if (twice >= dy) {
            err += dy;
            ax += sx;
        }
        if (twice <= dx) {
            err += dx;
            ay += sy;
        }
    }
    host_gfx_touch(pic->page);
    return 0;
}

INT FAR drv_real_fill_rect(struct RASTPORT *pic, INT x, INT y, INT w, INT h,
                           INT colour)
{
    solid_rect(pic->page, x + pic->origin_x, y + pic->origin_y, w, h, colour);
    return 0;
}

/* Chooses between the adapters' ways of loading a palette; here there
 * is one adapter. */
void FAR drv_real_FUN_1000_00ca(struct PALETTE *colours)
{
    drv_jump_gfx_set_palette(colours);
}
