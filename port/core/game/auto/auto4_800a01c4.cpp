#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "auto4_800a01c4.c"
/* Decompiled automatically by m2c (ppc-gcc-c) via tools/m2c_batch.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending review. */
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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)(w3d::bytes(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((w3d::slot_t<type>)(expr))

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


M2C_UNK fn_800A064C(Ptr32<void>);                        void fn_800A08AC(Ptr32<void>);                        /* extern */
M2C_UNK fn_800A12C0(Ptr32<void>);                        /* extern */
M2C_UNK fn_800A1608(Ptr32<void>);                        /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */
s32 fn_8015FB34(Ptr32<void>, Ptr32<u16>);                     /* extern */
Ptr32<void> fn_80165254();                                /* extern */

extern M2C_UNK lbl_804AE12C;
extern M2C_UNK lbl_804AE134;
extern M2C_UNK lbl_804AE13C;
extern M2C_UNK lbl_804AE144;
extern M2C_UNK lbl_804AE14C;
extern M2C_UNK lbl_804AE154;
extern M2C_UNK lbl_804AE15C;
extern M2C_UNK lbl_804AE164;
extern M2C_UNK lbl_804AE16C;

s32 w3d_auto_800a01c4(Ptr32<void> arg0, Ptr32<u16> arg1) {
    u16 temp_r31;

    temp_r31 = *arg1;
    if ((s32) temp_r31 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r31 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8015FB34(arg0, arg1) < 0) {
        goto block_5;
    }
    fn_800A064C(arg0);
    goto block_21;
block_5:
    return 0x80004005;
block_6:
    fn_800A08AC(arg0);
    goto block_19;
block_7:
    if (fn_8015F65C(temp_r31, &lbl_804AE164) == 0) {
        goto block_9;
    }
    M2C_FIELD(arg0, s32 *, 0x58) = 1;
    fn_800A12C0(arg0);
block_9:
    if (fn_8015F65C(temp_r31, &lbl_804AE16C) == 0) {
        goto block_11;
    }
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(fn_80165254(), s32 *, 0x34);
block_11:
    if (fn_8015F65C(temp_r31, &lbl_804AE12C) != 0) {
        goto block_17;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE134) != 0) {
        goto block_17;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE13C) != 0) {
        goto block_17;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE144) != 0) {
        goto block_17;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE14C) != 0) {
        goto block_17;
    }
    if (fn_8015F65C(temp_r31, &lbl_804AE154) == 0) {
        goto block_18;
    }
block_17:
    fn_800A12C0(arg0);
    goto block_21;
block_18:
    if (fn_8015F65C(temp_r31, &lbl_804AE15C) != 0) {
        goto block_20;
    }
block_19:
    return fn_8015FB34(arg0, arg1);
block_20:
    fn_800A1608(arg0);
block_21:
    return 0;
}

}
