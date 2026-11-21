/* PICTURE-UNPACK.C -- the picture and palette unpacker of a portable build.
 *
 * LZW codes of 9 to 11 bits read low bit first, a 90h escape for runs, and a
 * packed mode of two pixels a byte.
 */
#define CODES 0x800

static struct {
    int packed;            /* two pixels a byte, low nibble first */
    int rle_count;         /* repeats of rle_byte still owed */
    int rle_byte;
    int code_width, max_width, code_mask, next_code;
    unsigned int bits_word, bits_left;
    int prev_code, first_byte;
    unsigned short prefix[CODES];
    unsigned char suffix[CODES];
    unsigned char stack[CODES + 16];
    int depth;
} lz;

static void refill(void)
{
    INT (*call)(void) = (INT (*)(void)) (void *) shm_refill;
    if (call)
        call();
}

static unsigned int read_word(void)
{
    unsigned int w;
    if (shm_source_at >= shd_archive_buffer_end)
        refill();
    w = shm_source_at[0] | ((unsigned int) shm_source_at[1] << 8);
    shm_source_at += 2;
    return w;
}

static void reset_codes(void)
{
    int i;
    lz.code_width = 9;
    lz.code_mask = 0x1ff;
    lz.next_code = 0x100;
    for (i = 0; i < CODES; i++)
        lz.prefix[i] = 0xffff;
    for (i = 0; i < 256; i++)
        lz.suffix[i] = (unsigned char) i;
}

/* Read the code-width word and start afresh: the low byte is the widest code
 * and the high byte the stream's first eight bits. */
static void begin_codes(void)
{
    unsigned int w;
    lz.rle_count = 0;
    lz.rle_byte = 0;
    w = read_word();
    lz.max_width = (w & 0xff) > 11 ? 11 : (int) (w & 0xff);
    lz.bits_word = w;
    lz.bits_left = 8;
    lz.depth = 0;
    reset_codes();
}

static void push(int byte)
{
    if (lz.depth < (int) sizeof lz.stack)
        lz.stack[lz.depth++] = (unsigned char) byte;
}

/* The next byte unpacked; a code is read and its string stacked when the stack
 * is empty. */
static int next_byte(void)
{
    unsigned int bits, n, code;
    int added, walk, first = 0;
    if (lz.depth)
        return lz.stack[--lz.depth];
    bits = lz.bits_word >> (16 - lz.bits_left);
    n = lz.bits_left;
    while (n < (unsigned int) lz.code_width) {
        unsigned int w = read_word();
        lz.bits_word = w;
        bits |= w << n;
        n += 16;
    }
    lz.bits_left = n - (unsigned int) lz.code_width;
    code = bits & 0xffff & (unsigned int) lz.code_mask;
    if ((int) code >= lz.next_code) {
        added = lz.next_code;
        walk = lz.prev_code;
        push(lz.first_byte);
    } else {
        added = (int) code;
        walk = (int) code;
    }
    for (;;) {
        if (lz.prefix[walk & (CODES - 1)] == 0xffff) {
            first = lz.suffix[walk & (CODES - 1)];
            push(first);
            break;
        }
        push(lz.suffix[walk & (CODES - 1)]);
        walk = lz.prefix[walk & (CODES - 1)];
    }
    lz.first_byte = first;
    lz.suffix[lz.next_code & (CODES - 1)] = (unsigned char) first;
    lz.prefix[lz.next_code & (CODES - 1)] = (unsigned short) lz.prev_code;
    lz.next_code++;
    if (lz.next_code > lz.code_mask) {
        lz.code_width++;
        lz.code_mask = (lz.code_mask << 1) | 1;
    }
    if (lz.code_width > lz.max_width)
        reset_codes();
    lz.prev_code = added;
    return lz.stack[--lz.depth];
}

/* Unpack `count` pixels into `out`: the codes give bytes, 90h is the
 * run-length escape, and a packed picture's byte is two pixels. */
static void unpack(unsigned char *out, int count)
{
    int left = lz.packed ? (count + 1) / 2 : count;
    while (left-- > 0) {
        int b;
        if (lz.rle_count == 0) {
            b = next_byte();
            if (b == 0x90) {
                int n = next_byte();
                if (n == 0) {
                    b = 0x90;
                    lz.rle_byte = b;
                } else {
                    lz.rle_count = n - 1;
                    b = lz.rle_byte;
                    lz.rle_count--;
                }
            } else {
                lz.rle_byte = b;
            }
        } else {
            b = lz.rle_byte;
            lz.rle_count--;
        }
        if (lz.packed) {
            *out++ = (unsigned char) (b & 0x0f);
            *out++ = (unsigned char) ((b >> 4) & 0x0f);
        } else {
            *out++ = (unsigned char) b;
        }
    }
}

void FAR drv_real_unpack_start(void)
{
    unsigned int flags = read_word();
    lz.packed = flags & 1;
    shm_sprite_width = (INT) read_word();
    shm_sprite_height = (INT) read_word();
    if (flags & 8)
        shm_source_at += 0x10;
    else if (flags & 0x10)
        shm_source_at += 0x80;
    begin_codes();
}

void FAR drv_real_palette_read(void)
{
    unsigned int flags = read_word();
    lz.packed = flags & 1;
    shm_palette_count = (INT) read_word();
    begin_codes();
}

void FAR drv_real_palette_put(INT at_offset, INT at_segment, INT count)
{
    unsigned char *out = (unsigned char *) port_set_pointer(
        (UNSIGNED_INT) at_segment, (UNSIGNED_INT) at_offset);
    if (out && count > 0)
        unpack(out, count);
}

void FAR drv_real_unpack_row(drv_addr block)
{
    if (block)
        unpack((unsigned char *) block, shm_sprite_width);
}
