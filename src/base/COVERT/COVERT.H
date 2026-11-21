/* COVERT.H -- what the C side can reach on the assembly side. */
#ifndef COVERT_H
#define COVERT_H

/* The driver entries this module calls, declared once for every module. */
#include "DRIVERS.H"

/* The dispatch segment's own routines, declared once for every module. */
#include "DRVREAL.H"

/* The MSC 5.1 run-time this module calls, declared once for the tree. */
#include "RUNTIME.H"

/* A type this module reaches, declared once for the modules sharing it. */
#include "COMM.H"

/* The structures this module reaches, defined once for the whole tree. */
#include "STRUCTS.H"

/* data defined in assembly, exported to C */
#ifdef PORT_MODERN
/* The data group, datum by datum, which the portable build alone reads. */
#include "COVERT_PORT.H"
#else
extern unsigned char dat_str_empty_arg[1];
extern unsigned char dat_exe_intro[10];
extern unsigned char dat_file_fonts[9];
extern unsigned char dat_exe_misc[9];
extern unsigned char dat_arg_slash_2[3];
extern unsigned char dat_ext_cv[3];
/* The executable run from PATH when the next module is 'c'; likely a debug
tool that was never distributed. */
extern unsigned char dat_exe_mcv[8];
/* The empty string handed to spawnl as a spawned module's argv[0]. */
extern unsigned char dat_module_spawn_arg[1];
/* One pointer per module, to the name of the executable spawned for it,
indexed by the shared block's next_module. */
extern unsigned char *dat_MODULE_TABLE[18];
extern unsigned char dat_GRAPHIC_NAME[13];
extern unsigned char dat_SOUND_NAME[10];
extern UNSIGNED_INT asm_DRIVER_HANDLE;
extern struct COMM_BLOCK asm_COMM_BLOCK;
/* The register block for the INT 10h call that sets text mode at the end. */
extern union REGS asm_regs;
#endif

#endif /* COVERT_H */
