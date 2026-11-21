/* PORTING.C -- the operations PORTING.H and COMM.H leave to the host.
 *
 * Num Lock, far pointers, the software interrupt, the spawn pair, the shared
 * block and setup answers. A module is a library here, loaded, run and
 * unloaded, so its data starts fresh each time.
 */

/* Ask for the POSIX calls below before any header: -std=c89 hides them. */
#if !defined(_WIN32) && !defined(_DEFAULT_SOURCE)
#define _DEFAULT_SOURCE 1
#define _POSIX_C_SOURCE 200809L
#endif

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#include <unistd.h>
#endif

#include "HOST.H"
#include "PORTING.H"
#include "COMM.H"

/* The setup answers INTRO would ask for, fixed to the host's drivers: 'E'
 * for EGRAPHIC, which VGA and EGA both load, and 'N' for no sound. */
#define HOST_GRAPHICS_DRIVER 'E'
#define HOST_SOUND_DRIVER 'N'

/* The shared block until COVERT publishes its own. `message` runs to the
 * end of what COVERT keeps, so the case a module saves there fits. */
static struct COMM_BLOCK host_store;
static struct COMM_BLOCK FAR *published;

const char *host_option(const char *name)
{
    return getenv(name);
}

void host_fatal(const char *what)
{
    fprintf(stderr, "covert: %s\n", what ? what : "failed");
    exit(0x63);
}

/* ---- the shared block ------------------------------------------------ */

/* The block COVERT published, or a zeroed one of the host's until it has. */
struct COMM_BLOCK FAR *port_comm(void)
{
    return published ? published : &host_store;
}

void port_comm_publish(struct COMM_BLOCK FAR *block)
{
    published = block;
    host_block_adopt(block, sizeof (struct COMM_BLOCK));
}

void port_setup(void)
{
    COMM()->graphics_driver = HOST_GRAPHICS_DRIVER;
    COMM()->sound_driver = HOST_SOUND_DRIVER;
    /* The joystick answer is whether the host has a controller plugged in. */
    COMM()->joystick_enabled = (unsigned char) host_joystick_open();
}

/* ---- the keyboard's lights ------------------------------------------- */

void port_num_lock(INT on)
{
    host_set_num_lock(on != 0);
}

/* ---- far pointers ---------------------------------------------------- */

void *port_set_pointer(UNSIGNED_INT segment, UNSIGNED_INT offset)
{
    unsigned char *base = host_block_base(segment);
    return base ? base + offset : 0;
}

void *port_set_pointer_within(void *fp, UNSIGNED_INT offset)
{
    size_t within;
    UNSIGNED_INT segment = host_block_of(fp, &within);
    unsigned char *base = host_block_base(segment);
    return base ? base + offset : 0;
}

UNSIGNED_INT port_get_pointer_start(void *fp)
{
    size_t within;
    return host_block_of(fp, &within);
}

UNSIGNED_INT port_get_pointer_within(void *fp)
{
    size_t within;
    host_block_of(fp, &within);
    return (UNSIGNED_INT) within;
}

/* ---- the software interrupt ------------------------------------------ */

/* INT 10h's mode set, display page and DAC entry; INT 16h AH=3 AL=5, the
 * typematic delay and rate; and INT 33h, which answers that there is no mouse.
 * Anything else does nothing. */
INT port_int86(INT number, rt_addr in, rt_addr out)
{
    union REGS *r = (union REGS *) in;
    union REGS *back = (union REGS *) out;
    union REGS result = *r;
    if (number == 0x16) {
        if (r->h.ah == 0x03 && r->h.al == 0x05)
            host_typematic(((r->h.bh & 3) + 1) * 250u,
                           (((8u + (r->h.bl & 7)) << ((r->h.bl >> 3) & 3))
                            * 417u + 50u) / 100u);
    } else if (number == 0x10) {
        switch (r->h.ah) {
        case 0x00:
            host_gfx_mode(r->h.al);
            break;
        case 0x05:
            host_gfx_show(r->h.al);
            break;
        case 0x10:
            if (r->h.al == 0x10)
                host_gfx_dac(r->x.bx, r->h.dh, r->h.ch, r->h.cl);
            break;
        default:
            break;
        }
    } else if (number == 0x33) {
        result.x.ax = 0;
    }
    result.x.cflag = 0;
    *back = result;
    return (INT) result.x.ax;
}

/* ---- the next module ------------------------------------------------- */

void host_executable_directory(char *buffer, size_t size)
{
    char *slash;
    buffer[0] = 0;
#ifdef _WIN32
    GetModuleFileNameA(0, buffer, (DWORD) size);
    slash = strrchr(buffer, '\\');
#else
    {
        long got = readlink("/proc/self/exe", buffer, size - 1);
        buffer[got > 0 ? got : 0] = 0;
    }
    slash = strrchr(buffer, '/');
#endif
    if (slash)
        slash[1] = 0;
    else
        buffer[0] = 0;
}

/* A module is a library beside this executable, named by its DOS name's stem
 * in lower case with the platform's suffix; its entry is the module's `main`,
 * renamed to ENTRY_NAME. */
#ifdef _WIN32
#define LIBRARY_SUFFIX ".dll"
#else
#define LIBRARY_SUFFIX ".so"
#endif
#define ENTRY_NAME "port_main"

static jmp_buf module_return;
static int module_running;
static char module_name[16] = "covert";

const char *host_module_name(void)
{
    return module_name;
}

int host_module_running(void)
{
    return module_running;
}

/* The stem of a DOS name, lower-cased: "TAC.EXE" is "tac". */
static void stem_of(const char *name, char *stem, size_t size)
{
    const char *base = name;
    const char *at;
    size_t n = 0;
    for (at = name; *at; at++)
        if (*at == '\\' || *at == '/')
            base = at + 1;
    for (at = base; *at && *at != '.' && n + 1 < size; at++)
        stem[n++] = (char) ((*at >= 'A' && *at <= 'Z') ? *at + 32 : *at);
    stem[n] = 0;
}

static void library_path(const char *stem, char *buffer, size_t size)
{
    host_executable_directory(buffer, size);
    if (strlen(buffer) + strlen(stem) + strlen(LIBRARY_SUFFIX) >= size)
        buffer[0] = 0;
    strcat(buffer, stem);
    strcat(buffer, LIBRARY_SUFFIX);
}

#ifdef _WIN32
typedef HMODULE library;

static library library_load(const char *path)
{
    return LoadLibraryA(path);
}

static void (*library_entry(library lib))(void)
{
    return (void (*)(void)) GetProcAddress(lib, ENTRY_NAME);
}

static void library_unload(library lib)
{
    FreeLibrary(lib);
}

static const char *library_error(void)
{
    static char text[32];
    sprintf(text, "error %lu", (unsigned long) GetLastError());
    return text;
}
#else
typedef void *library;

static library library_load(const char *path)
{
    return dlopen(path, RTLD_NOW | RTLD_LOCAL);
}

static void (*library_entry(library lib))(void)
{
    void (*entry)(void) = 0;
    void *found = dlsym(lib, ENTRY_NAME);
    if (found)
        memcpy(&entry, &found, sizeof entry);
    return entry;
}

static void library_unload(library lib)
{
    dlclose(lib);
}

static const char *library_error(void)
{
    const char *text = dlerror();
    return text ? text : "cannot be loaded";
}
#endif

/* What DOS gave a child and took back when it ended: the module's memory, its
 * open files, its own run-time. */
static void module_begin(const char *stem)
{
    strncpy(module_name, stem, sizeof module_name - 1);
    host_blocks_module_begin();
    host_runtime_module_begin();
}

static void module_end(void)
{
    host_runtime_module_end();
    host_blocks_module_end();
    host_gfx_module_end();
    strcpy(module_name, "covert");
}

/* Load the module, run it to its exit, unload it. A library that is missing or
 * has no entry ends the program. */
static int run_module(const char *name)
{
    char stem[16];
    char path[512];
    char text[600];
    library lib;
    void (*entry)(void);
    stem_of(name, stem, sizeof stem);
    library_path(stem, path, sizeof path);
    lib = library_load(path);
    if (!lib) {
        sprintf(text, "%s: %s", path, library_error());
        host_fatal(text);
    }
    entry = library_entry(lib);
    if (!entry) {
        sprintf(text, "%s: no %s", path, ENTRY_NAME);
        host_fatal(text);
    }
    module_begin(stem);
    if (setjmp(module_return) == 0) {
        module_running = 1;
        entry();
    }
    module_running = 0;
    module_end();
    library_unload(lib);
    return 0;
}

/* `exit` for the modules: a status of 0 ends the module and the launcher goes
 * on; any other ends the program. */
void port_exit(int status)
{
    if (module_running && status == 0)
        longjmp(module_return, 1);
    exit(status);
}

INT port_spawnl(INT mode, str_addr path, str_addr arg0)
{
    return (INT) run_module((const char *) path);
}

/* A spawn by PATH is of mcv.exe, which is not part of this build. */
INT port_spawnlp(INT mode, str_addr file, str_addr arg0,
                 str_addr arg1, str_addr arg2)
{
    char text[600];
    sprintf(text, "%s is not part of this build", (const char *) file);
    host_fatal(text);
    return -1;
}
