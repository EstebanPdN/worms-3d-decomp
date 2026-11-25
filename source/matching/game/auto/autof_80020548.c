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

M2C_UNK fn_801628B0();                              /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
void *fn_801613F0(s32, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(void *);                        /* extern */
M2C_UNK fn_8015F518(M2C_UNK *, M2C_UNK *);          /* extern */
M2C_UNK fn_80022704(s32, s32, s32, s32, s32, s32, u32);                           /* extern */

extern M2C_UNK lbl_8040DB08[];
extern s32 lbl_804AA7A4;
extern s32 lbl_804AA7A8;
extern void *lbl_804B1760;

void *w3d_auto_80020548(void *arg0) {
    fn_801628B0();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8040DB08);
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    lbl_804B1760 = arg0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    lbl_804AA7A8 = 0;
    lbl_804AA7A4 = 0;
    return arg0;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AC9DC;
extern s32 lbl_804B1754;

void w3d_auto_800216f8(void *arg0, u32 arg1) {
    void *temp_r30;

    if ((u32) M2C_FIELD(arg0, u32 *, 0x14) >= arg1) {
        goto block_2;
    }
    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AC9DC, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    M2C_FIELD(arg0, s32 *, 4) = 1;
block_2:
    return;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACA04;
extern s32 lbl_804B1754;

s32 w3d_auto_80021f2c(void *arg0) {
    void *temp_r30;

    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACA04, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    M2C_FIELD(arg0, s32 *, 4) = 1;
    return 0;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804AC9D4;
extern M2C_UNK lbl_804AC9DC;
extern s32 lbl_804B1754;

s32 w3d_auto_80021f94(void *arg0) {
    void *temp_r30;
    void *temp_r30_2;

    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804AC9D4, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    temp_r30_2 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804AC9DC, 1);
    M2C_FIELD(temp_r30_2, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
    M2C_FIELD(arg0, s32 *, 4) = 1;
    return 0;
}

extern M2C_UNK lbl_8036C228[];
extern M2C_UNK lbl_8036C23C[];
extern M2C_UNK lbl_8036C250[];
extern M2C_UNK lbl_8036C264[];
extern M2C_UNK lbl_8036C278[];
extern M2C_UNK lbl_8036C28C[];
extern M2C_UNK lbl_8036C2A4[];
extern M2C_UNK lbl_8036C2BC[];
extern M2C_UNK lbl_8036C2CC[];
extern M2C_UNK lbl_8036C2E4[];
extern M2C_UNK lbl_8036C300[];
extern M2C_UNK lbl_804AC9CC;
extern M2C_UNK lbl_804AC9D4;
extern M2C_UNK lbl_804AC9DC;
extern M2C_UNK lbl_804AC9E4;
extern M2C_UNK lbl_804AC9EC;
extern M2C_UNK lbl_804AC9F4;
extern M2C_UNK lbl_804AC9FC;
extern M2C_UNK lbl_804ACA04;
extern M2C_UNK lbl_804ACA0C;
extern M2C_UNK lbl_804ACA14;
extern M2C_UNK lbl_804ACA1C;

void w3d_auto_80022028(s32 arg0, s32 arg1) {
    if (arg1 != 0xFFFF) {
        goto block_3;
    }
    if (arg0 == 0) {
        goto block_3;
    }
    fn_8015F518(&lbl_804AC9CC, &(*lbl_8036C228));
    fn_8015F518(&lbl_804AC9D4, &(*lbl_8036C23C));
    fn_8015F518(&lbl_804AC9DC, &(*lbl_8036C250));
    fn_8015F518(&lbl_804AC9E4, &(*lbl_8036C264));
    fn_8015F518(&lbl_804AC9EC, &(*lbl_8036C278));
    fn_8015F518(&lbl_804AC9F4, &(*lbl_8036C28C));
    fn_8015F518(&lbl_804AC9FC, &(*lbl_8036C2A4));
    fn_8015F518(&lbl_804ACA04, &(*lbl_8036C2BC));
    fn_8015F518(&lbl_804ACA0C, &(*lbl_8036C2CC));
    fn_8015F518(&lbl_804ACA14, &(*lbl_8036C2E4));
    fn_8015F518(&lbl_804ACA1C, &(*lbl_8036C300));
block_3:
    return;
}

void w3d_auto_800226d0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u32 temp_r9;

    temp_r9 = (u32) (M2C_FIELD(arg0, s32 *, 0x20) - M2C_FIELD(arg0, s32 *, 0x1C)) >> 2U;
    if (temp_r9 == 0) {
        goto block_2;
    }
    fn_80022704(arg0, arg1, arg2, arg3, arg4, arg5, temp_r9);
block_2:
    return;
}

extern M2C_UNK lbl_8040DDF8[];
extern M2C_UNK **lbl_804AA7D4;

M2C_UNK **w3d_auto_80022c2c(M2C_UNK **arg0) {
    fn_801628B0();
    *arg0 = &(*lbl_8040DDF8);
    lbl_804AA7D4 = arg0;
    return arg0;
}

s32 w3d_auto_8002324c(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 0;
    return 0x80004005;
}

extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACB0C;
extern s32 lbl_804B1754;

void w3d_auto_800267a4(void) {
    void *temp_r30;

    temp_r30 = fn_801613F0(lbl_804B1754, 8);
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACB0C, 1);
    M2C_FIELD(temp_r30, M2C_UNK **, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30);
    return;
}
