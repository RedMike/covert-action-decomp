/* KEYS.C -- the keyboard as INT 16h hands it out.
 *
 * A queue of words, the scan code in the high byte and the character in the
 * low, filled from the host's keyboard and, for an unattended run, from a
 * scripted list.
 */

#include <stdlib.h>
#include <string.h>

#include "HOST.H"
#include "DRIVERS.H"

#define QUEUE 64
/* What the BIOS's own buffer holds: a held key repeats no deeper. */
#define BIOS_QUEUE 15

static unsigned int queue[QUEUE];
static int head, count;
static int num_lock;

/* The scripted keys: COVERT_KEYS names them, comma-separated, COVERT_KEY_MS is
 * how often one is pressed, and COVERT_LIMIT is how many seconds the run
 * gets. */
static const char *script;
static unsigned int script_every = 300;
static unsigned int script_next;
static unsigned int limit_at;
static int script_read;

/* The typematic INT 16h AH=3 sets. Until a module sets one, a held key repeats
 * as the host's keyboard does; after, the held word is queued at the delay and
 * rate asked for. */
static unsigned int repeat_delay, repeat_every;
static unsigned int held_word, held_next;
static int held_scan = -1;

void host_typematic(unsigned int delay_ms, unsigned int every_ms)
{
    repeat_delay = delay_ms;
    repeat_every = every_ms;
    held_scan = -1;
}

int host_typematic_on(void)
{
    return repeat_every != 0;
}

/* What port 60h reads: the keyboard's last byte, a scan code going down and
 * the same with bit 7 set coming up. */
static int last_byte = 0x80;

void host_key_released(int scan)
{
    if (scan == held_scan)
        held_scan = -1;
    last_byte = (scan & 0x7f) | 0x80;
}

int host_key_port(void)
{
    return last_byte;
}

void host_key_push(unsigned int code)
{
    if (count == QUEUE)
        return;
    queue[(head + count) % QUEUE] = code & 0xffffu;
    count++;
}

int host_key_waiting(void)
{
    host_pump();
    return count > 0;
}

unsigned int host_key_take(void)
{
    unsigned int code;
    while (!host_key_waiting())
        host_wait_ms(2);
    code = queue[head];
    head = (head + 1) % QUEUE;
    count--;
    return code;
}

int host_num_lock(void)
{
    return num_lock;
}

void host_set_num_lock(int on)
{
    num_lock = on;
}

/* The keypad's digits, by scan code, which the BIOS hands out only with
 * Num Lock on: without it the same keys are the arrows. */
static int keypad_digit(int scan)
{
    switch (scan) {
    case 0x47: return '7';
    case 0x48: return '8';
    case 0x49: return '9';
    case 0x4b: return '4';
    case 0x4c: return '5';
    case 0x4d: return '6';
    case 0x4f: return '1';
    case 0x50: return '2';
    case 0x51: return '3';
    case 0x52: return '0';
    case 0x53: return '.';
    }
    return 0;
}

void host_key_from_scancode(int scan, int ascii)
{
    if (ascii < 0 && num_lock)
        ascii = keypad_digit(scan);
    if (ascii < 0)
        ascii = 0;
    host_key_push(((unsigned int) scan << 8) | ((unsigned int) ascii & 0xff));
    last_byte = scan & 0x7f;
    if (repeat_every) {
        held_scan = scan;
        held_word = ((unsigned int) scan << 8) | ((unsigned int) ascii & 0xff);
        held_next = host_ticks_ms() + repeat_delay;
    }
}

static const struct { const char *name; int scan; int ascii; } NAMED[] = {
    {"esc", 0x01, 0x1b}, {"enter", 0x1c, 0x0d}, {"space", 0x39, ' '},
    {"tab", 0x0f, 0x09}, {"backspace", 0x0e, 0x08},
    {"up", 0x48, 0}, {"down", 0x50, 0}, {"left", 0x4b, 0}, {"right", 0x4d, 0},
    {"home", 0x47, 0}, {"end", 0x4f, 0}, {"pgup", 0x49, 0}, {"pgdn", 0x51, 0},
    {"f1", 0x3b, 0}, {"f2", 0x3c, 0}, {"f3", 0x3d, 0}, {"f4", 0x3e, 0},
    {"f5", 0x3f, 0}, {"f6", 0x40, 0}, {"f7", 0x41, 0}, {"f8", 0x42, 0},
    {"f9", 0x43, 0}, {"f10", 0x44, 0},
    {"kp7", 0x47, -1}, {"kp8", 0x48, -1}, {"kp9", 0x49, -1},
    {"kp4", 0x4b, -1}, {"kp5", 0x4c, -1}, {"kp6", 0x4d, -1},
    {"kp1", 0x4f, -1}, {"kp2", 0x50, -1}, {"kp3", 0x51, -1},
    {"kp0", 0x52, -1},
    {0, 0, 0}
};

/* The scan code of a printable character on a US keyboard. */
static int scan_of(int ch)
{
    static const char ROW1[] = "1234567890-=";
    static const char ROW2[] = "qwertyuiop[]";
    static const char ROW3[] = "asdfghjkl;'`";
    static const char ROW4[] = "\\zxcvbnm,./";
    const char *at;
    int lower = ch;
    if (ch >= 'A' && ch <= 'Z')
        lower = ch - 'A' + 'a';
    if ((at = strchr(ROW1, lower)) != 0 && lower)
        return 0x02 + (int) (at - ROW1);
    if ((at = strchr(ROW2, lower)) != 0 && lower)
        return 0x10 + (int) (at - ROW2);
    if ((at = strchr(ROW3, lower)) != 0 && lower)
        return 0x1e + (int) (at - ROW3);
    if ((at = strchr(ROW4, lower)) != 0 && lower)
        return 0x2b + (int) (at - ROW4);
    if (ch == ' ')
        return 0x39;
    return 0;
}

static void press_token(const char *token, size_t length)
{
    int n;
    if (length == 0)
        return;
    if (length > 5 && memcmp(token, "wait:", 5) == 0) {
        script_next += (unsigned int) atoi(token + 5) * 1000u;
        return;
    }
    /* Alt and a letter: the scan code alone, as the BIOS hands out Alt-Q. */
    if (length == 5 && memcmp(token, "alt:", 4) == 0) {
        host_key_from_scancode(scan_of((unsigned char) token[4]), 0);
        return;
    }
    for (n = 0; NAMED[n].name; n++)
        if (strlen(NAMED[n].name) == length
                && memcmp(NAMED[n].name, token, length) == 0) {
            host_key_from_scancode(NAMED[n].scan, NAMED[n].ascii);
            return;
        }
    if (length == 1)
        host_key_from_scancode(scan_of((unsigned char) token[0]),
                               (unsigned char) token[0]);
}

static void script_init(void)
{
    const char *value;
    script_read = 1;
    script = host_option("COVERT_KEYS");
    value = host_option("COVERT_KEY_MS");
    if (value && atoi(value) > 0)
        script_every = (unsigned int) atoi(value);
    value = host_option("COVERT_LIMIT");
    if (value && atoi(value) > 0)
        limit_at = host_ticks_ms() + (unsigned int) atoi(value) * 1000u;
    script_next = host_ticks_ms() + script_every;
}

/* ---- the keyboard and joystick slots -------------------------------- */

UNSIGNED_INT FAR drv_jump_keyboard_empty(void)
{
    if (host_key_waiting())
        return 0;
    host_wait_ms(1);
    return 0xffff;
}

UNSIGNED_INT FAR drv_jump_read_key(void)
{
    return (UNSIGNED_INT) host_key_take();
}

UNSIGNED_INT FAR drv_jump_dos_key(void)
{
    return (UNSIGNED_INT) (host_key_take() & 0xff);
}

/* A host controller's stick is centred already, so there is nothing to
 * calibrate. */
void FAR drv_jump_joy_calibrate(void)
{
}

/* Both axes in one word, the low byte X and the high byte Y, each a signed
 * byte; centred with no controller. */
UNSIGNED_INT FAR drv_jump_joy_read(void)
{
    int x, y;
    if (!host_joystick_present())
        return 0x8080;
    host_joystick_axes(&x, &y);
    return (UNSIGNED_INT) (((y & 0xff) << 8) | (x & 0xff));
}

/* Press the next scripted key when its time has come, end the run when
 * its time has, and repeat a held key at the typematic rate. */
void host_keys_tick(void)
{
    unsigned int now;
    if (!script_read)
        script_init();
    now = host_ticks_ms();
    if (limit_at && (int) (now - limit_at) >= 0)
        exit(0);
    if (script && *script && (int) (now - script_next) >= 0) {
        const char *end = strchr(script, ',');
        size_t length = end ? (size_t) (end - script) : strlen(script);
        press_token(script, length);
        /* A scripted key is a tap: nothing else ever releases it. */
        held_scan = -1;
        last_byte |= 0x80;
        script = end ? end + 1 : script + length;
        script_next += script_every;
    }
    while (held_scan >= 0 && (int) (now - held_next) >= 0) {
        if (count < BIOS_QUEUE)
            host_key_push(held_word);
        held_next += repeat_every;
    }
}
