/* HOST.H -- the interface the portable host's own files share.
 *
 * The block table, the screen, the key queue, the graphics pages and palette,
 * host file names, and the begin and end of a module's run.
 */
#ifndef HOST_H
#define HOST_H

#include <stddef.h>

#include "PORTING.H"
#include "STRUCTS.H"

/* Blocks the game holds by a 16-bit handle. */
UNSIGNED_INT host_block_new(size_t size);
void host_block_free(UNSIGNED_INT segment);
unsigned char *host_block_base(UNSIGNED_INT segment);
size_t host_block_size(UNSIGNED_INT segment);
void host_block_grow(UNSIGNED_INT segment, size_t size);
UNSIGNED_INT host_block_adopt(void *base, size_t size);
UNSIGNED_INT host_block_of(const void *at, size_t *offset);
void host_blocks_module_begin(void);
void host_blocks_module_end(void);

/* The window, or none; the clock. */
#define HOST_WIDTH 320
#define HOST_HEIGHT 200
int host_screen_open(void);
void host_screen_close(void);
void host_screen_present(const unsigned char *pixels,
                         const unsigned char (*rgb)[3]);
void host_screen_pump(void);
unsigned int host_ticks_ms(void);
void host_sleep_ms(unsigned int ms);

/* A host game controller, where one is plugged in, as the PC joystick. */
int host_joystick_open(void);
int host_joystick_present(void);
void host_joystick_axes(int *x, int *y);
unsigned int host_joystick_buttons(void);

/* The keyboard, as INT 16h hands it out. */
void host_key_push(unsigned int code);
int host_key_waiting(void);
unsigned int host_key_take(void);
void host_key_from_scancode(int scan, int ascii);
void host_key_released(int scan);
int host_key_port(void);
void host_typematic(unsigned int delay_ms, unsigned int every_ms);
int host_typematic_on(void);
void host_keys_tick(void);
int host_num_lock(void);
void host_set_num_lock(int on);

/* Graphics pages, palette, sprites and fonts. */
unsigned char *host_gfx_page(int page);
void host_gfx_touch(int page);
void host_gfx_mode(int mode);
void host_gfx_show(int page);
void host_gfx_dac(int index, int red, int green, int blue);
void host_pump(void);
void host_wait_ms(unsigned int ms);
void host_gfx_module_end(void);

/* File names on the host's disk, and what a module has open. */
void host_settle_directory(void);
const char *host_path(const char *name, char *buffer, size_t size);
int host_file_exists(const char *name);
void host_runtime_module_begin(void);
void host_runtime_module_end(void);

/* The way out, host options, and the module being run. */
void host_fatal(const char *what);
const char *host_option(const char *name);
void host_executable_directory(char *buffer, size_t size);
const char *host_module_name(void);
int host_module_running(void);

#endif /* HOST_H */
