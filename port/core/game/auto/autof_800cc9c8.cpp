#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_800cc9c8.c"
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

#define NULL ((void *)0)

M2C_UNK fn_800CCAF8(Ptr32<void>);                           /* extern */
M2C_UNK fn_800CCBF4(s32);                           /* extern */
s32 fn_80126034(Ptr32<u16>);                             /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */
s32 fn_8015FB34(Ptr32<void>, Ptr32<u16>);                        /* extern */

extern M2C_UNK lbl_80387DB4[];
extern M2C_UNK lbl_80387DC4[];
extern M2C_UNK lbl_804AE84C;
extern M2C_UNK lbl_804AE854;
extern Ptr32<void> lbl_804B1788;

s32 w3d_auto_800cc9c8(s32 arg0, Ptr32<u16> arg1) {
    u16 temp_r30;
    Ptr32<Ptr32<void>> temp_r31;
    Ptr32<Ptr32<void>> temp_r31_2;
    Ptr32<void> temp_r30_2;
    Ptr32<void> temp_r30_3;

    temp_r30 = *arg1;
    if ((s32) temp_r30 == 0x40) {
        goto block_3;
    }
    if ((s32) temp_r30 == 0x42) {
        goto block_6;
    }
    goto block_7;
block_3:
    if (fn_8015FB34(w3d::G(arg0), arg1) < 0) {
        goto block_5;
    }
    fn_800CCAF8(w3d::G(arg0));
    return 0;
block_5:
    return 0x80004005;
block_6:
    fn_800CCBF4(arg0);
    goto block_13;
block_7:
    if (fn_8015F65C(temp_r30, &lbl_804AE84C) == 0) {
        goto block_10;
    }
    temp_r31 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x6C);
    if (temp_r31 == NULL) {
        goto block_13;
    }
    temp_r30_2 = *temp_r31;
    M2C_FIELD(temp_r30_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, Ptr32<M2C_UNK>, s32)> *, 0x60)(temp_r31, &(*lbl_80387DB4), fn_80126034(arg1));
    goto block_13;
block_10:
    if (fn_8015F65C(temp_r30, &lbl_804AE854) == 0) {
        goto block_13;
    }
    temp_r31_2 = M2C_FIELD(lbl_804B1788, Ptr32<Ptr32<void>> *, 0x6C);
    if (temp_r31_2 == NULL) {
        goto block_13;
    }
    temp_r30_3 = *temp_r31_2;
    M2C_FIELD(temp_r30_3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, Ptr32<M2C_UNK>, s32)> *, 0x60)(temp_r31_2, &(*lbl_80387DC4), fn_80126034(arg1));
block_13:
    return fn_8015FB34(w3d::G(arg0), arg1);
}

}
