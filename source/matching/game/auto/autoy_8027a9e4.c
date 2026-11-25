/* Decompiled automatically by m2c; statement order or callee return width
 * adjusted by tools/m2c_reorder.py and verified identical to the original
 * after linking. Types and names are m2c placeholders pending review. */
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

M2C_UNK fn_8010A8E0(void *, u16, s32);                 /* extern */
s32 fn_8015F5A0(M2C_UNK *, M2C_UNK);                /* extern */
s32 fn_801613F0(void *, M2C_UNK);                      /* extern */
M2C_UNK fn_8016239C();                              /* extern */
extern M2C_UNK lbl_804B0B34;
extern s32 lbl_804B1754;
M2C_UNK fn_802BD354(void *);                        /* extern */
M2C_UNK fn_802BD8CC(void *);                        /* extern */
M2C_UNK fn_802BDD24(void *);                        /* extern */

void w3d_auto_8027a9e4(s32 arg0, s32 arg1) {
    s32 temp_r30;

    temp_r30 = fn_801613F0(lbl_804B1754, 0xC);
    fn_8010A8E0(temp_r30, fn_8015F5A0(&lbl_804B0B34, 1), arg1);
    fn_8016239C();
    return;
}

void w3d_auto_802b8418(void *arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0xB0);
    if (temp_r0 != 0) {
        goto block_3;
    }
    M2C_FIELD(arg0, s32 *, 0x104) = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x108) = temp_r0;
    return;
block_3:
    return;
}

void w3d_auto_802bd3cc(void *arg0, f32 farg0) {
    s32 var_r0;

    var_r0 = 0;
    if (M2C_FIELD(arg0, f32 *, 0x34) == farg0) {
        goto block_2;
    }
    M2C_FIELD(arg0, f32 *, 0x34) = farg0;
    var_r0 = 1;
    M2C_FIELD(arg0, f32 *, 0x38) = farg0;
block_2:
    if (var_r0 != 1) {
        goto block_4;
    }
    fn_802BD8CC(arg0);
    fn_802BDD24(arg0);
block_4:
    fn_802BD354(arg0);
    return;
}

void w3d_auto_802c4a70(void *arg0, f32 farg0, f32 farg1) {
    M2C_FIELD(arg0, f32 *, 0x170) = farg0;
    M2C_FIELD(arg0, f32 *, 0x174) = farg1;
    return;
}

void w3d_auto_802e0f64(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x48) = arg1;
    M2C_FIELD(arg0, s32 *, 0x4C) = arg2;
    return;
}

s32 w3d_auto_8035a1dc(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    return 0;
}
