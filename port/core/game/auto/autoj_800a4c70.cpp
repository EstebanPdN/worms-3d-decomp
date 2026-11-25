#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoj_800a4c70.c"
/* Decompiled automatically by m2c; statement order, callee return width or a
 * guarded call argument adjusted by tools/m2c_reorder.py and verified identical
 * to the original after linking. Types and names are m2c placeholders pending
 * review. */
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

M2C_UNK fn_800A4DE4(Ptr32<void>);                        /* extern */
M2C_UNK fn_80181640(M2C_UNK, Ptr32<M2C_UNK>, Ptr32<void>, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK fn_80343584(s32);                           /* extern */
extern M2C_UNK lbl_80380FA4[];
extern f32 lbl_80380FAC[];
extern f32 lbl_80380FB0[];
extern M2C_UNK lbl_80380FB4[];
extern f32 lbl_80380FBC[];
extern f32 lbl_80380FC0[];
extern f32 lbl_80380FC4[];
M2C_UNK fn_800A82F0(Ptr32<void>, s32, s32);                      /* extern */
M2C_UNK fn_800F90E8(s32, s32, s32);                 /* extern */
M2C_UNK fn_801613F0(Ptr32<void>, M2C_UNK);                  /* extern */
M2C_UNK fn_8016239C();                              /* extern */
Ptr32<void> fn_80165254();                                /* extern */
extern s32 lbl_804B1754;
M2C_UNK fn_800A8314(Ptr32<void>, s32, s32, s32);                 /* extern */
M2C_UNK fn_800FA21C(s32, s32, s32, s32);            /* extern */
M2C_UNK fn_800ED070(Ptr32<void>, Ptr32<void>);                           /* extern */
M2C_UNK fn_80164FC8(s32);                           /* extern */

void w3d_auto_800a4c70(Ptr32<void> arg0) {
    fn_80181640(fn_80343584(M2C_FIELD(arg0, s32 *, 0x20)), &(*lbl_80380FA4), arg0 + 0x24, 0, (*lbl_80380FAC), (*lbl_80380FB0), (*lbl_80380FB0));
    fn_800A4DE4(arg0);
    return;
}

void w3d_auto_800a4cd0(Ptr32<void> arg0) {
    fn_80181640(fn_80343584(M2C_FIELD(arg0, s32 *, 0x20)), &(*lbl_80380FB4), arg0 + 0x24, 0, (*lbl_80380FBC), (*lbl_80380FC0), (*lbl_80380FC4));
    fn_800A4DE4(arg0);
    M2C_FIELD(arg0, s32 *, 0x2C) = 1;
    return;
}

void w3d_auto_800a7bb4(Ptr32<void> arg0, s32 arg1, s32 arg2) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xB4) == 0) {
        goto block_2;
    }
    fn_800A82F0(w3d::G(fn_801613F0(w3d::G(lbl_804B1754), 0xC)), arg1, arg2);
    fn_8016239C();
    return;
block_2:
    fn_800F90E8(arg1, arg2, M2C_FIELD(fn_80165254(), s32 *, 0x34) + 0xA);
    return;
}

void w3d_auto_800a7c24(Ptr32<void> arg0, s32 arg1, s32 arg2, s32 arg3) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xB4) == 0) {
        goto block_2;
    }
    fn_800A8314(w3d::G(fn_801613F0(w3d::G(lbl_804B1754), 0x10)), arg1, arg2, arg3);
    fn_8016239C();
    return;
block_2:
    fn_800FA21C(arg1, arg2, arg3, M2C_FIELD(fn_80165254(), s32 *, 0x34) + 0xA);
    return;
}

void w3d_auto_800e96a0(Ptr32<void> arg0, s32 arg1) {
    fn_800ED070(w3d::G(fn_80164FC8(M2C_FIELD(arg0, s32 *, 0xC0))), w3d::G(arg1));
    return;
}

}
