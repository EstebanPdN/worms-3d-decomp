#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autof_800a7ab8.c"
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

M2C_UNK fn_800F8A48(s16, s32);                      /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C();                              /* extern */
Ptr32<void> fn_80165254();                                /* extern */
M2C_UNK fn_80035714(Ptr32<void>, Ptr32<M2C_UNK>, f32);           /* extern */
s32 fn_8015F65C(u16, Ptr32<M2C_UNK>);                    /* extern */

extern M2C_UNK lbl_8040DB38[];
extern s32 lbl_804B1754;

void w3d_auto_800a7ab8(Ptr32<void> arg0, s16 arg1) {
    Ptr32<void> temp_r3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0xB4) == 0) {
        goto block_2;
    }
    temp_r3 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r3, s16 *, 0) = arg1;
    M2C_FIELD(temp_r3, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C();
    return;
block_2:
    fn_800F8A48(arg1, M2C_FIELD(fn_80165254(), s32 *, 0x34) + 0xA);
    return;
}

extern M2C_UNK lbl_80381990[];
extern f32 lbl_80381998[];
extern s32 lbl_804AA8C8;
extern M2C_UNK lbl_804AE31C;

void w3d_auto_800a9b18(s32 arg0, Ptr32<u16> arg1) {
    if (fn_8015F65C(*arg1, &lbl_804AE31C) == 0) {
        goto block_2;
    }
    fn_80035714(w3d::G(lbl_804AA8C8), &(*lbl_80381990), (*lbl_80381998));
block_2:
    return;
}

}
