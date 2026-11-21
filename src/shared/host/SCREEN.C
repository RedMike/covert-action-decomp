/* SCREEN.C -- the window the pages are shown in, the controller, the clock.
 *
 * SDL2 under PORT_SDL, a window scaled up from 320 by 200 whose key events
 * become the BIOS's words; otherwise none. COVERT_HEADLESS runs the SDL build
 * with no window too.
 */

/* Ask for the POSIX calls below before any header: -std=c89 hides them. */
#if !defined(_WIN32) && !defined(_DEFAULT_SOURCE)
#define _DEFAULT_SOURCE 1
#define _POSIX_C_SOURCE 200809L
#endif

#include <stdlib.h>
#include <string.h>

/* The headless clock's windows.h, ahead of the LONG that PORTING.H defines. */
#if defined(_WIN32) && !defined(PORT_SDL)
#include <windows.h>
#endif

#include "HOST.H"

#ifdef PORT_SDL

#define SDL_MAIN_HANDLED
#include <SDL.h>

#define SCALE 3

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture;
static int pending_scan = -1;
static int headless = -1;

/* Whether COVERT_HEADLESS asks for no window: a scripted run's choice. */
static int is_headless(void)
{
    if (headless < 0) {
        const char *value = host_option("COVERT_HEADLESS");
        headless = value && *value && *value != '0';
    }
    return headless;
}

unsigned int host_ticks_ms(void)
{
    if (!SDL_WasInit(SDL_INIT_TIMER))
        SDL_InitSubSystem(SDL_INIT_TIMER);
    return (unsigned int) SDL_GetTicks();
}

void host_sleep_ms(unsigned int ms)
{
    SDL_Delay(ms);
}

int host_screen_open(void)
{
    if (window || is_headless())
        return 1;
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        host_fatal(SDL_GetError());
        return 0;
    }
    window = SDL_CreateWindow("Covert Action", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, HOST_WIDTH * SCALE,
                              HOST_HEIGHT * SCALE, SDL_WINDOW_RESIZABLE);
    if (!window) {
        host_fatal(SDL_GetError());
        return 0;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
        renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetLogicalSize(renderer, HOST_WIDTH, HOST_HEIGHT);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24,
                                SDL_TEXTUREACCESS_STREAMING, HOST_WIDTH,
                                HOST_HEIGHT);
    SDL_StartTextInput();
    /* The BIOS flag starts as the keyboard's own Num Lock; the game's later
     * writes do not reach the keyboard's light. */
    host_set_num_lock((SDL_GetModState() & KMOD_NUM) != 0);
    return 1;
}

void host_screen_close(void)
{
    if (!window)
        return;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    texture = 0;
    renderer = 0;
    window = 0;
}

void host_screen_present(const unsigned char *pixels,
                         const unsigned char (*rgb)[3])
{
    unsigned char *out;
    int pitch, x, y;
    if (is_headless() || (!window && !host_screen_open()))
        return;
    if (SDL_LockTexture(texture, 0, (void **) &out, &pitch) != 0)
        return;
    for (y = 0; y < HOST_HEIGHT; y++) {
        unsigned char *row = out + y * pitch;
        const unsigned char *in = pixels + y * HOST_WIDTH;
        for (x = 0; x < HOST_WIDTH; x++) {
            const unsigned char *c = rgb[in[x]];
            row[x * 3] = c[0];
            row[x * 3 + 1] = c[1];
            row[x * 3 + 2] = c[2];
        }
    }
    SDL_UnlockTexture(texture);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, 0, 0);
    SDL_RenderPresent(renderer);
}

/* The PC's scan code for a USB key, on a US layout. */
static int scan_of(SDL_Scancode code)
{
    static const int LETTERS[26] = {
        0x1e, 0x30, 0x2e, 0x20, 0x12, 0x21, 0x22, 0x23, 0x17, 0x24, 0x25,
        0x26, 0x32, 0x31, 0x18, 0x19, 0x10, 0x13, 0x1f, 0x14, 0x16, 0x2f,
        0x11, 0x2d, 0x15, 0x2c
    };
    if (code >= SDL_SCANCODE_A && code <= SDL_SCANCODE_Z)
        return LETTERS[code - SDL_SCANCODE_A];
    if (code >= SDL_SCANCODE_1 && code <= SDL_SCANCODE_0)
        return 0x02 + (code - SDL_SCANCODE_1);
    if (code >= SDL_SCANCODE_F1 && code <= SDL_SCANCODE_F10)
        return 0x3b + (code - SDL_SCANCODE_F1);
    switch (code) {
    case SDL_SCANCODE_RETURN: case SDL_SCANCODE_KP_ENTER: return 0x1c;
    case SDL_SCANCODE_ESCAPE: return 0x01;
    case SDL_SCANCODE_BACKSPACE: return 0x0e;
    case SDL_SCANCODE_TAB: return 0x0f;
    case SDL_SCANCODE_SPACE: return 0x39;
    case SDL_SCANCODE_MINUS: return 0x0c;
    case SDL_SCANCODE_EQUALS: return 0x0d;
    case SDL_SCANCODE_LEFTBRACKET: return 0x1a;
    case SDL_SCANCODE_RIGHTBRACKET: return 0x1b;
    case SDL_SCANCODE_BACKSLASH: return 0x2b;
    case SDL_SCANCODE_SEMICOLON: return 0x27;
    case SDL_SCANCODE_APOSTROPHE: return 0x28;
    case SDL_SCANCODE_GRAVE: return 0x29;
    case SDL_SCANCODE_COMMA: return 0x33;
    case SDL_SCANCODE_PERIOD: return 0x34;
    case SDL_SCANCODE_SLASH: case SDL_SCANCODE_KP_DIVIDE: return 0x35;
    case SDL_SCANCODE_KP_MULTIPLY: return 0x37;
    case SDL_SCANCODE_KP_MINUS: return 0x4a;
    case SDL_SCANCODE_KP_PLUS: return 0x4e;
    case SDL_SCANCODE_HOME: case SDL_SCANCODE_KP_7: return 0x47;
    case SDL_SCANCODE_UP: case SDL_SCANCODE_KP_8: return 0x48;
    case SDL_SCANCODE_PAGEUP: case SDL_SCANCODE_KP_9: return 0x49;
    case SDL_SCANCODE_LEFT: case SDL_SCANCODE_KP_4: return 0x4b;
    case SDL_SCANCODE_KP_5: return 0x4c;
    case SDL_SCANCODE_RIGHT: case SDL_SCANCODE_KP_6: return 0x4d;
    case SDL_SCANCODE_END: case SDL_SCANCODE_KP_1: return 0x4f;
    case SDL_SCANCODE_DOWN: case SDL_SCANCODE_KP_2: return 0x50;
    case SDL_SCANCODE_PAGEDOWN: case SDL_SCANCODE_KP_3: return 0x51;
    case SDL_SCANCODE_INSERT: case SDL_SCANCODE_KP_0: return 0x52;
    case SDL_SCANCODE_DELETE: case SDL_SCANCODE_KP_PERIOD: return 0x53;
    case SDL_SCANCODE_F11: return 0x57;
    case SDL_SCANCODE_F12: return 0x58;
    default: return 0;
    }
}

static int is_keypad(SDL_Scancode code)
{
    return (code >= SDL_SCANCODE_KP_1 && code <= SDL_SCANCODE_KP_0)
        || code == SDL_SCANCODE_KP_PERIOD;
}

/* A key that will bring a text event is held until it does, so the word
 * carries the character the layout gives it. With Alt held the word is the
 * scan code. */
static void key_down(const SDL_KeyboardEvent *key)
{
    SDL_Scancode code = key->keysym.scancode;
    int scan = scan_of(code);
    int mods = key->keysym.mod;
    int sym = key->keysym.sym;
    int ascii = -1;
    pending_scan = -1;
    if (code == SDL_SCANCODE_NUMLOCKCLEAR) {
        host_set_num_lock(!host_num_lock());
        return;
    }
    if (scan == 0 && !(sym >= 0x20 && sym < 0x7f))
        return;
    if (mods & KMOD_ALT) {
        if (scan)
            host_key_from_scancode(scan, 0);
        return;
    }
    if (mods & KMOD_CTRL) {
        if (sym >= 'a' && sym <= 'z')
            ascii = sym - 'a' + 1;
        else
            ascii = 0;
        host_key_from_scancode(scan, ascii);
        return;
    }
    switch (code) {
    case SDL_SCANCODE_RETURN: case SDL_SCANCODE_KP_ENTER: ascii = 0x0d; break;
    case SDL_SCANCODE_ESCAPE: ascii = 0x1b; break;
    case SDL_SCANCODE_BACKSPACE: ascii = 0x08; break;
    case SDL_SCANCODE_TAB: ascii = 0x09; break;
    default: break;
    }
    if (ascii >= 0) {
        host_key_from_scancode(scan, ascii);
        return;
    }
    if (is_keypad(code)) {
        host_key_from_scancode(scan, -1);
        return;
    }
    if (sym >= 0x20 && sym < 0x7f) {
        pending_scan = scan;
        return;
    }
    host_key_from_scancode(scan, 0);
}

/* The character for the key held back; a text event with no key waiting is
 * dropped. */
static void text_input(const SDL_TextInputEvent *text)
{
    unsigned char ch = (unsigned char) text->text[0];
    if (pending_scan < 0 || ch < 0x20 || ch >= 0x7f)
        return;
    host_key_from_scancode(pending_scan, ch);
    pending_scan = -1;
}

void host_screen_pump(void)
{
    SDL_Event event;
    if (!window)
        return;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
        case SDL_KEYDOWN:
            /* Drop the host's repeats once a module sets its own rate. */
            if (event.key.repeat && host_typematic_on())
                break;
            key_down(&event.key);
            break;
        case SDL_KEYUP:
            if (scan_of(event.key.keysym.scancode))
                host_key_released(scan_of(event.key.keysym.scancode));
            break;
        case SDL_TEXTINPUT:
            text_input(&event.text);
            break;
        default:
            break;
        }
    }
}

/* ---- a game controller, as the PC joystick -------------------------- */

static SDL_GameController *pad;
static int pad_asked;

/* Open the first game controller the host has, once, and answer whether
 * there is one. */
int host_joystick_open(void)
{
    int i;
    if (pad_asked)
        return pad != 0;
    pad_asked = 1;
    if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) != 0)
        return 0;
    for (i = 0; i < SDL_NumJoysticks(); i++)
        if (SDL_IsGameController(i)) {
            pad = SDL_GameControllerOpen(i);
            if (pad)
                break;
        }
    return pad != 0;
}

int host_joystick_present(void)
{
    return pad != 0;
}

/* The left stick as two signed bytes centred at zero: SDL's -32768..32767
 * becomes -128..127, left and up negative. */
void host_joystick_axes(int *x, int *y)
{
    if (!pad) {
        *x = 0;
        *y = 0;
        return;
    }
    SDL_GameControllerUpdate();
    *x = SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTX) >> 8;
    *y = SDL_GameControllerGetAxis(pad, SDL_CONTROLLER_AXIS_LEFTY) >> 8;
}

/* The two buttons the game reads, active high in bits 0 and 1: A is fire and B
 * is cancel. */
unsigned int host_joystick_buttons(void)
{
    unsigned int mask = 0;
    if (!pad)
        return 0;
    SDL_GameControllerUpdate();
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_A))
        mask |= 1;
    if (SDL_GameControllerGetButton(pad, SDL_CONTROLLER_BUTTON_B))
        mask |= 2;
    return mask;
}

#else /* no window at all */

#ifndef _WIN32
#include <time.h>
#endif

unsigned int host_ticks_ms(void)
{
#ifdef _WIN32
    return (unsigned int) GetTickCount();
#else
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return (unsigned int) (now.tv_sec * 1000u + now.tv_nsec / 1000000u);
#endif
}

void host_sleep_ms(unsigned int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    struct timespec span;
    span.tv_sec = ms / 1000;
    span.tv_nsec = (long) (ms % 1000) * 1000000L;
    nanosleep(&span, 0);
#endif
}

int host_screen_open(void)
{
    return 1;
}

void host_screen_close(void)
{
}

void host_screen_present(const unsigned char *pixels,
                         const unsigned char (*rgb)[3])
{
}

void host_screen_pump(void)
{
}

/* No window means no controller, as though no joystick were chosen. */
int host_joystick_open(void)
{
    return 0;
}

int host_joystick_present(void)
{
    return 0;
}

void host_joystick_axes(int *x, int *y)
{
    *x = 0;
    *y = 0;
}

unsigned int host_joystick_buttons(void)
{
    return 0;
}

#endif
