/* Decompiled automatically by m2c with mechanical corrections (tools/m2c_fixups.py:
 * far globals as unknown-size arrays, dropped leading parameters, forwarded
 * arguments); verified identical to the original after linking. Types and
 * names are m2c placeholders pending review. */
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

M2C_UNK fn_8015F518(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_801628B0();                              /* extern */
s32 fn_802EE7DC();                                  /* extern */
M2C_UNK fn_800FC1B0(M2C_UNK **, s32);               /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(void *, s16 *, void *);               /* extern */
M2C_UNK fn_800DC634();                              /* extern */
M2C_UNK fn_800E67D0(void *, M2C_UNK);               /* extern */
M2C_UNK fn_80035714(void *, M2C_UNK *, f32);           /* extern */
s32 fn_8015F65C(u16, M2C_UNK *);                    /* extern */
void *fn_801613F0(void *, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(void *);                        /* extern */
s32 fn_80178D1C(void *);                               /* extern */
M2C_UNK fn_8003F240(u16);                           /* extern */
M2C_UNK fn_800EB910(void *, u32);                   /* extern */
M2C_UNK fn_80126334(void *);                           /* extern */
s32 fn_801264FC(s32);                               void fn_80126524(void *);                           /* extern */
void *fn_801797B4();                                /* extern */
M2C_UNK fn_80341584(s32);                           /* extern */

extern M2C_UNK lbl_8038A1BC[];
extern M2C_UNK lbl_804AED7C;

void w3d_auto_800e4f38(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AED7C, &(*lbl_8038A1BC));
block_3:
    return;
}

extern M2C_UNK lbl_804100B8[];
extern void *lbl_804AAECC;

void *w3d_auto_800e50cc(void *arg0) {
    fn_801628B0();
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_804100B8);
    M2C_FIELD(arg0, s32 *, 0x50) = fn_802EE7DC();
    lbl_804AAECC = arg0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0xFFFF;
    return arg0;
}

extern M2C_UNK lbl_8038A5CC[];
extern M2C_UNK lbl_8038A5DC[];
extern M2C_UNK lbl_8038A5F4[];
extern M2C_UNK lbl_8038A604[];
extern M2C_UNK lbl_8038A614[];
extern M2C_UNK lbl_8038A620[];
extern M2C_UNK lbl_804AEDB4;
extern M2C_UNK lbl_804AEDBC;
extern M2C_UNK lbl_804AEDC4;
extern M2C_UNK lbl_804AEDDC;
extern M2C_UNK lbl_804AEDE4;

void w3d_auto_800e6390(s32 arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    M2C_UNK *sp14;
    M2C_UNK *sp18;
    M2C_UNK *sp1C;
    M2C_UNK *sp20;
    M2C_UNK *sp24;
    M2C_UNK *sp28;

    sp8 = fn_8015F5A0(&lbl_804AEDC4, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x24);
    spA = fn_8015F5A0(&lbl_804AEDB4, 1);
    fn_80162024(arg0, &spA, arg0 + 0x28);
    spC = fn_8015F5A0(&lbl_804AEDBC, 1);
    fn_80162024(arg0, &spC, arg0 + 0x2C);
    spE = fn_8015F5A0(&lbl_804AEDDC, 1);
    fn_80162024(arg0, &spE, arg0 + 0x30);
    sp10 = fn_8015F5A0(&lbl_804AEDE4, 1);
    fn_80162024(arg0, &sp10, arg0 + 0x34);
    sp14 = &(*lbl_8038A5CC);
    fn_800FC1B0(&sp14, arg0 + 0x38);
    sp18 = &(*lbl_8038A5DC);
    fn_800FC1B0(&sp18, arg0 + 0x3C);
    sp1C = &(*lbl_8038A5F4);
    fn_800FC1B0(&sp1C, arg0 + 0x40);
    sp20 = &(*lbl_8038A604);
    fn_800FC1B0(&sp20, arg0 + 0x44);
    sp24 = &(*lbl_8038A614);
    fn_800FC1B0(&sp24, arg0 + 0x48);
    sp28 = &(*lbl_8038A620);
    fn_800FC1B0(&sp28, arg0 + 0x4C);
    return;
}

extern M2C_UNK lbl_804100E8[];

void *w3d_auto_800e6738(void *arg0) {
    fn_800DC634();
    M2C_FIELD(arg0, M2C_UNK **, 0x70) = &(*lbl_804100E8);
    fn_800E67D0(arg0, 0);
    return arg0;
}

extern M2C_UNK lbl_8038B148[];
extern f32 lbl_8038B150[];
extern M2C_UNK lbl_8040DB38[];
extern s32 lbl_804AA8C8;
extern M2C_UNK lbl_804AEE3C;
extern M2C_UNK lbl_804AEE44;
extern s32 lbl_804B1754;

void w3d_auto_800e783c(void *arg0, u16 *arg1) {
    u16 temp_r30;
    void *temp_r30_2;

    temp_r30 = *arg1;
    if (fn_80178D1C(M2C_FIELD(arg0, s32 *, 0x54)) != 0) {
        goto block_3;
    }
    if (fn_8015F65C(temp_r30, &lbl_804AEE44) == 0) {
        goto block_3;
    }
    temp_r30_2 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804AEE3C, 1);
    M2C_FIELD(temp_r30_2, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
    fn_80035714(lbl_804AA8C8, &(*lbl_8038B148), (*lbl_8038B150));
block_3:
    return;
}

extern M2C_UNK lbl_8038B154[];
extern M2C_UNK lbl_8038B168[];
extern M2C_UNK lbl_8038B17C[];
extern M2C_UNK lbl_8038B190[];
extern M2C_UNK lbl_804AEE2C;
extern M2C_UNK lbl_804AEE34;
extern M2C_UNK lbl_804AEE3C;
extern M2C_UNK lbl_804AEE44;

void w3d_auto_800e78d4(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AEE2C, &(*lbl_8038B154));
    fn_8015F518(&lbl_804AEE34, &(*lbl_8038B168));
    fn_8015F518(&lbl_804AEE3C, &(*lbl_8038B17C));
    fn_8015F518(&lbl_804AEE44, &(*lbl_8038B190));
block_3:
    return;
}

extern f32 lbl_8038B3F4[];
extern u16 lbl_804AA95E;
extern void *lbl_804B1788;

s32 w3d_auto_800eabb0(void *arg0, u32 arg1) {
    f32 temp_f13;
    s32 temp_r0;
    void *temp_r3;

    fn_80341584(M2C_FIELD(arg0, s32 *, 0xC0));
    temp_r3 = fn_801797B4();
    temp_f13 = M2C_FIELD(temp_r3, f32 *, 0x184);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        goto block_8;
    }
    if (!(temp_f13 > (*lbl_8038B3F4))) {
        goto block_8;
    }
    if (arg1 <= (u32) (M2C_FIELD(arg0, s32 *, 0x1C) + M2C_FIELD(temp_r3, s32 *, 0x18C))) {
        goto block_8;
    }
    fn_80126334(M2C_FIELD(arg0, s32 *, 0x100));
    if (fn_801264FC(M2C_FIELD(arg0, s32 *, 0x100)) == 0xFFFF) {
        goto block_7;
    }
    fn_8003F240(lbl_804AA95E);
    fn_800EB910(arg0, arg1);
    fn_80126524(M2C_FIELD(arg0, s32 *, 0x100));
    temp_r0 = M2C_FIELD(lbl_804B1788, s32 *, 0xBC);
    if (temp_r0 & 0x8000) {
        goto block_6;
    }
    M2C_FIELD(lbl_804B1788, s32 *, 0xBC) = (s32) (temp_r0 | 0x20000);
block_6:
    return 1;
block_7:
    fn_80126524(M2C_FIELD(arg0, s32 *, 0x100));
block_8:
    return 0;
}
