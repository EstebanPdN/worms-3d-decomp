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

M2C_UNK fn_80022634(void *);                           /* extern */
extern s32 lbl_804AA7A8;
M2C_UNK fn_800271EC(void *, M2C_UNK);               /* extern */
f32 fn_8002726C(void *);                            /* extern */
void *fn_80165254();                                /* extern */
M2C_UNK fn_8015FEF0();                              /* extern */
extern M2C_UNK lbl_8040E6D8[];
M2C_UNK fn_803426B8(void *);                        /* extern */
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(void *, s16 *, void *);         /* extern */
M2C_UNK fn_8020BD38(void *, M2C_UNK *);             /* extern */
s32 fn_802E0210();                                  /* extern */
extern M2C_UNK lbl_80387410[];
extern void *lbl_804AAE0C;
extern M2C_UNK lbl_804AE794;
extern M2C_UNK lbl_804AE79C;
extern M2C_UNK lbl_804AE7A4;
extern M2C_UNK lbl_804AE7AC;
extern M2C_UNK lbl_804AE7B4;
extern M2C_UNK lbl_804AE7CC;
extern M2C_UNK lbl_804AE7EC;
extern M2C_UNK lbl_8040FE00[];
M2C_UNK fn_801FFECC();                              /* extern */
extern M2C_UNK lbl_80418D88[];
M2C_UNK fn_801628B0();                              /* extern */
extern M2C_UNK lbl_80419CB0[];

void w3d_auto_80020880(void *arg0) {
    fn_80022634(M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg0, s32 *, 0x24) = 0;
    lbl_804AA7A8 = 0;
    return;
}

s32 w3d_auto_800231ec(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
}

void w3d_auto_8002709c(void *arg0) {
    f32 temp_f1;

    M2C_FIELD(arg0, s32 *, 0x50) = M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
    M2C_FIELD(arg0, f32 *, 0x54) = fn_8002726C(arg0);
    temp_f1 = fn_8002726C(arg0);
    if (temp_f1 > M2C_FIELD(arg0, f32 *, 0x58)) {
        goto block_2;
    }
    if (!(temp_f1 < M2C_FIELD(arg0, f32 *, 0x5C))) {
        goto block_3;
    }
block_2:
    fn_800271EC(arg0, 0);
block_3:
    return;
}

void *w3d_auto_8003a490(void *arg0) {
    fn_8015FEF0();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8040E6D8);
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = M2C_FIELD(arg0, s32 *, 0x24) = -1;
    return arg0;
}

void *w3d_auto_800b912c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = M2C_FIELD(arg0, s32 *, 4) = 0;
    fn_803426B8(arg0 + 0x10);
    return arg0;
}

void w3d_auto_800c6a20(void *arg0) {
    s16 sp8;
    s16 spA;
    s16 spC;
    s16 spE;
    s16 sp10;
    s16 sp12;
    s16 sp14;

    lbl_804AAE0C = arg0;
    M2C_FIELD(arg0, s32 *, 0x44) = M2C_FIELD(arg0, s32 *, 0x40) = 0;
    fn_8020BD38(arg0 + 0x3C, &(*lbl_80387410));
    sp8 = fn_8015F5A0(&lbl_804AE794, 1);
    fn_80162024(arg0, &sp8, arg0 + 0x1C);
    spA = fn_8015F5A0(&lbl_804AE79C, 1);
    fn_80162024(arg0, &spA, arg0 + 0x20);
    spC = fn_8015F5A0(&lbl_804AE7A4, 1);
    fn_80162024(arg0, &spC, arg0 + 0x24);
    spE = fn_8015F5A0(&lbl_804AE7AC, 1);
    fn_80162024(arg0, &spE, arg0 + 0x28);
    sp10 = fn_8015F5A0(&lbl_804AE7CC, 1);
    fn_80162024(arg0, &sp10, arg0 + 0x2C);
    sp12 = fn_8015F5A0(&lbl_804AE7EC, 1);
    fn_80162024(arg0, &sp12, arg0 + 0x30);
    sp14 = fn_8015F5A0(&lbl_804AE7B4, 1);
    fn_80162024(arg0, &sp14, arg0 + 0x34);
    M2C_FIELD(arg0, s32 *, 0x40) = fn_802E0210();
    return;
}

void *w3d_auto_800da250(void *arg0) {
    fn_8015FEF0();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_8040FE00);
    M2C_FIELD(arg0, s32 *, 0x1C) = -1;
    M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s32 *, 0x20) = 0;
    return arg0;
}

s32 w3d_auto_801626ec(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + 1);
}

s32 w3d_auto_80178870(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + 1);
}

s32 w3d_auto_801797ec(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + 1);
}

s32 w3d_auto_801d5f60(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x30) = M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    return 0;
}

void *w3d_auto_80200340(void *arg0, s32 arg1) {
    fn_801FFECC();
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80418D88);
    M2C_FIELD(arg0, s32 *, 0x14) = M2C_FIELD(arg0, s32 *, 0x10) = 0;
    return arg0;
}

void *w3d_auto_8021cbc8(void *arg0) {
    fn_801628B0();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &(*lbl_80419CB0);
    M2C_FIELD(arg0, s32 *, 0x20) = 1;
    M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    return arg0;
}

void w3d_auto_8034f190(void *arg0) {
    M2C_FIELD(arg0, s16 *, 4) = M2C_FIELD(arg0, s32 *, 0) = 0;
    return;
}

s32 w3d_auto_8035a230(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 1);
}
