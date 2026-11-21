/* COVERT_PORT.H -- the data group, as the portable build reads it.
 *
 * COVERT.H includes it under PORT_MODERN; the DOS build never stages it.
 */
#ifndef COVERT_PORT_H
#define COVERT_PORT_H

#include "PORTING.H"
#include "COMM.H"
#include "STRUCTS.H"

#ifndef PORT_MODERN
extern unsigned char run_banner_pad[8];
/* LINK's own 64-byte segment, whose year dates the compiler: MSC 5.1 writes
1988, 5.0 writes 1987. */
extern unsigned char run_banner[56];
extern unsigned char run_banner_tail[2];
#endif
extern unsigned char dat_module_0[9];
extern unsigned char dat_module_1[8];
extern unsigned char dat_module_2[9];
extern unsigned char dat_module_3[10];
extern unsigned char dat_module_4[8];
extern unsigned char dat_module_5[10];
extern unsigned char dat_module_6[10];
extern unsigned char dat_module_7[8];
extern unsigned char dat_module_8[8];
extern unsigned char dat_module_9[10];
extern unsigned char dat_module_10[8];
extern unsigned char dat_module_11[10];
extern unsigned char dat_module_12[8];
extern unsigned char dat_module_13[8];
extern unsigned char dat_module_14[10];
extern unsigned char dat_module_15[9];
extern unsigned char dat_module_16[8];
extern unsigned char dat_module_17[10];
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
#ifndef PORT_MODERN
extern unsigned char dat_module_spawn_pad;
extern unsigned char asm_block_117e_00d0[18];
/* Holds the DGROUP offset of asm_block_117e_00d0, the RASTPORT-shaped nine
words in front of it. */
extern unsigned char *addr_page_rastport;
#endif
/* One pointer per module, to the name of the executable spawned for it,
indexed by the shared block's next_module. */
extern unsigned char *dat_MODULE_TABLE[18];
extern unsigned char dat_GRAPHIC_NAME[13];
#ifndef PORT_MODERN
extern unsigned char dat_graphic_name_pad;
#endif
extern unsigned char dat_SOUND_NAME[10];
extern UNSIGNED_INT asm_DRIVER_HANDLE;
#ifndef PORT_MODERN
extern unsigned char drv_DAT_117e_0122;
extern unsigned char drv_DAT_117e_0123;
extern unsigned char drv_DAT_117e_0124[16];
extern unsigned char dat_msg_allocated[27];
extern unsigned char dat_msg_dos_lied[54];
extern unsigned char dat_msg_file_not_found[19];
extern unsigned char dat_msg_load_no_memory[31];
extern unsigned char dat_msg_load_failed[36];
extern unsigned char dat_msg_overlay_overrun[37];
extern unsigned char dat_msg_shrink_failed[43];
extern unsigned char dat_msg_release_failed[31];
extern unsigned char asm_message_pool_pad[2];
extern UNSIGNED_INT drv_DAT_117e_024c;
extern UNSIGNED_INT drv_DAT_117e_024e;
extern UNSIGNED_INT drv_DAT_117e_0250;
extern UNSIGNED_INT drv_DAT_117e_0252;
extern UNSIGNED_INT drv_DAT_117e_0254;
extern UNSIGNED_INT drv_DAT_117e_0256;
extern UNSIGNED_INT drv_DAT_117e_0258;
extern UNSIGNED_INT drv_DAT_117e_025a;
extern UNSIGNED_INT drv_DAT_117e_025c;
extern UNSIGNED_INT drv_DAT_117e_025e;
extern UNSIGNED_INT drv_DAT_117e_0260;
extern UNSIGNED_INT run_crt0_02aa;
extern UNSIGNED_INT run_crt0_02ac;
extern UNSIGNED_INT run_crt0_02ae;
extern unsigned char run_abrktb_tail[72];
extern unsigned char run_crt0dat_0308;
extern UNSIGNED_INT run_crt0dat_0309;
extern unsigned char run_crt0dat_030b[8];
extern unsigned char run_crt0dat_0315[4];
extern unsigned char run_crt0dat_031d;
extern unsigned char run_crt0dat_0323;
extern unsigned char run_crt0dat_0324;
extern unsigned char run_crt0dat_0325;
extern unsigned char run_crt0dat_0326;
extern unsigned char run_crt0dat_0327;
extern unsigned char run_crt0dat_0328;
extern unsigned char run_crt0dat_0329[11];
extern unsigned char run_crt0dat_0334;
extern unsigned char run_crt0dat_0335;
extern unsigned char run_crt0dat_0340;
extern unsigned char run_crt0dat_0341;
extern unsigned char run_crt0dat_0344[6];
extern UNSIGNED_INT STKHQQ;
extern UNSIGNED_INT run_stdargv_034e;
extern unsigned char run_stdargv_0350[20];
extern UNSIGNED_INT run_nmalloc_0366;
extern unsigned char run_nmalloc_0368[2];
extern UNSIGNED_INT run_nmalloc_036a;
extern unsigned char run_nmalloc_036c[8];
extern unsigned char run_nmalloc_0376[4];
extern unsigned char run_acfinfo_spawn[14];
extern UNSIGNED_INT run_dospawn_0388;
extern UNSIGNED_INT run_dospawn_038a;
extern UNSIGNED_INT run_dospawn_038c;
extern unsigned char run_spawnvp_ptrs[8];
extern unsigned char run_spawnvp_bufs[32];
extern unsigned char run_ext_com[5];
extern unsigned char run_ext_exe[5];
extern unsigned char run_env_path[5];
extern unsigned char run_path_sep[2];
extern unsigned char run_spawnvp_tail;
extern unsigned char run_crt0dat_03c8[2];
extern UNSIGNED_INT run_crt0dat_03cc;
extern UNSIGNED_LONG run_crt0dat_03ce;
extern UNSIGNED_LONG run_crt0dat_03d2;
extern UNSIGNED_INT run_execload_03d6;
extern unsigned char run_nmsg_marker[8];
extern UNSIGNED_INT run_crt0msg_03e0;
extern unsigned char run_msg_r6000[26];
extern unsigned char run_crt0msg_03fc[2];
extern unsigned char run_msg_r6003[31];
extern unsigned char run_crt0msg_041d[2];
extern unsigned char run_msg_r6009[44];
extern unsigned char run_crt0msg_044b[7];
extern unsigned char run_msg_runtime_error[16];
extern unsigned char run_crt0msg_0462[2];
extern unsigned char run_msg_r6002[37];
extern unsigned char run_crt0msg_0489[2];
extern unsigned char run_msg_r6001[35];
extern unsigned char run_crt0msg_04ae[3];
extern unsigned char asm_bss_0471[3];
extern unsigned char asm_bss_0474[12];
#endif
extern struct COMM_BLOCK asm_COMM_BLOCK;
/* The register block for the INT 10h call that sets text mode at the end. */
extern union REGS asm_regs;
#ifndef PORT_MODERN
extern unsigned char asm_bss_336e[50];
/* The rest of the stack segment, after the emitted BSS. */
extern unsigned char asm_stack[1999];
#endif

#endif /* COVERT_PORT_H */
