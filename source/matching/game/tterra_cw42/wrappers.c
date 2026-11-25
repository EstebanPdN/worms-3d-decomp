typedef unsigned char u8; typedef unsigned int u32;
typedef struct { u8 bytes[188]; } Record;
extern Record tterra_cw42_table_804a7df8[];
extern u32 tterra_cw42_callee_803408ec(Record *, const u8 *);
extern u32 tterra_cw42_callee_80340994(Record *, const u8 *);
u32 tterra_cw42_add_803345bc(u32 i, const u8 *p) { volatile u8 pad[8]; return tterra_cw42_callee_803408ec(&tterra_cw42_table_804a7df8[i & 255],p); }
u32 tterra_cw42_remove_803345f0(u32 i, const u8 *p) { volatile u8 pad[8]; return tterra_cw42_callee_80340994(&tterra_cw42_table_804a7df8[i & 255],p); }
