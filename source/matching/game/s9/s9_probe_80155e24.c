typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
/* m2c helper macros (MIT license, see tools/m2c/LICENSE) */
/*
 * This header contains macros emitted by m2c in "valid syntax" mode,
 * which can be enabled by passing `--valid-syntax` on the command line.
 *
 * In this mode, unhandled types and expressions are emitted as macros so
 * that the output is compilable without human intervention.
 */


/* Unknown types */
typedef s32 M2C_UNK;
typedef s8  M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;

/* Unknown field access, like `*(type_ptr) &expr->unk_offset` */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((type)(expr))

/* Unaligned reads */
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)

/* Unhandled instructions */
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK() (0)
#define M2C_SYNC() (0)

#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define DMULT_HI(a, b) (0)
#define DMULTU_HI(a, b) (0)
#define CLZ(x) (0)
#define REVERSE_BITS(x) (0)
#define ROTATE_RIGHT(x, shift) (0)
#define ARM_RRX(x, carry) (0)
#define BSWAP32(x) (0)
#define BSWAP16(x) (0)
#define BSWAP16X2(x) (0)

/* Carry/overflow bits from partially-implemented instructions */
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)

/* Memcpy patterns */
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy

#define NULL ((void *)0)
M2C_UNK fn_800FC1F0(M2C_UNK **, s32 *);             /* extern */
M2C_UNK fn_800FC3B0(M2C_UNK **, s32);               /* extern */
void *fn_800FC6DC(s32);                                /* extern */
M2C_UNK fn_801555F8(void *);                        /* extern */
M2C_UNK fn_80155688(void *);                              /* extern */
s32 fn_80155784(void *, s32);                       /* extern */
s32 fn_801558DC(void *, s32);                       /* extern */
M2C_UNK fn_80155C9C(void *, s32);                   /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
void *fn_801613F0(s32, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(void *);                        /* extern */
M2C_UNK fn_80178C54(M2C_UNK,s32 *);                         /* extern */
M2C_UNK fn_8021C32C(s32);                              /* extern */
M2C_UNK fn_803426B4(s32);                           /* extern */
extern M2C_UNK lbl_803A27AC[];
extern M2C_UNK lbl_803A27F0[];
extern M2C_UNK lbl_803A2A7C[];
extern M2C_UNK lbl_803A2A90[];
extern M2C_UNK lbl_8040DB38[];
extern s32 lbl_804ABAC0;
extern M2C_UNK lbl_804AFE50;
extern M2C_UNK lbl_804AFEB8;
extern s32 lbl_804B1754;

void s9_probe_80155e24(void *arg0) {
    M2C_UNK *sp8;
    s32 spC;
    M2C_UNK *sp10;
    M2C_UNK *sp14;
    M2C_UNK *sp18;
    s32 sp1C;
    M2C_UNK *sp20;
    s32 sp24;
    s32 temp_r3;
    s32 var_r30;
    void *temp_r30;
    void *temp_r30_2;

    var_r30 = -1;
    fn_80155688(arg0);
    fn_801555F8(arg0);
    sp8 = &(*lbl_803A27AC);
    fn_800FC1F0(&sp8, &spC);
    sp10 = &(*lbl_803A2A7C);
    fn_800FC3B0(&sp10, spC);
    if (spC == -1) {
        goto block_2;
    }
    var_r30 = M2C_FIELD(fn_800FC6DC(spC), u8 *, 0xD5);
    sp14 = &(*lbl_803A2A90);
    fn_800FC3B0(&sp14, (s32) var_r30);
block_2:
    sp1C = -1;
    sp18 = &(*lbl_803A27F0);
    fn_800FC1F0(&sp18, &sp1C);
    sp20 = &(*lbl_803A2A90);
    fn_800FC3B0(&sp20, sp1C);
    sp24 = -1;
    sp24 = fn_80155784(arg0, sp1C);
    fn_80155C9C(arg0, sp1C);
    if ((s32) var_r30 <= sp24) {
        goto block_4;
    }
    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AFEB8, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
block_4:
    if (sp24 == -1) {
        goto block_6;
    }
    fn_80178C54(fn_803426B4(M2C_FIELD(arg0, s32 *, 0x130)),&sp24);
block_6:
    temp_r3 = fn_801558DC(arg0, sp24);
    spC = temp_r3;
    if (temp_r3 == -1) {
        goto block_8;
    }
    fn_80178C54(fn_803426B4(M2C_FIELD(arg0, s32 *, 0x128)),&spC);
block_8:
    temp_r30_2 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804AFE50, 1);
    M2C_FIELD(temp_r30_2, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
    if ((s32) lbl_804ABAC0 == 0) {
        goto block_11;
    }
    if (spC == -1) {
        goto block_11;
    }
    fn_8021C32C(lbl_804ABAC0);
block_11:
    M2C_FIELD(arg0, s32 *, 0x19C) = 0;
    return;
}
