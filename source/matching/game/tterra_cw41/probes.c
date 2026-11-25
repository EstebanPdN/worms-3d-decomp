typedef unsigned int u32;
typedef unsigned char u8;
/* Reference-only frames. Types describe observed PPC registers, not original declarations. */
extern u32 fn_803345bc(u32, const u8 *);
extern u32 fn_803345f0(u32, const u8 *);
extern void fn_8033dcf0(u32, u32, u32);
extern void fn_8033de40(u32);
u32 tterra_cw41_add_80322ce0(u32 index, const u8 *data) { volatile char pad[8]; return fn_803345bc(index, data); }
u32 tterra_cw41_remove_80322d00(u32 index, const u8 *data) { volatile char pad[8]; return fn_803345f0(index, data); }
void tterra_cw41_init_8033457c(u32 index, u32 value, u32 word) { volatile char pad[8]; fn_8033dcf0(index, value, word); }
void tterra_cw41_disable_8033459c(u32 index) { volatile char pad[8]; fn_8033de40(index); }
