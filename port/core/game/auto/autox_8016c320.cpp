#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autox_8016c320.c"
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

s32 fn_80216E7C();                                  /* extern */
s32 fn_8021ED0C();                                  /* extern */
M2C_UNK fn_80240994();                              /* extern */
s32 fn_8025D588(Ptr32<void>);                               /* extern */

s32 w3d_auto_8016c320(s32 arg0, Ptr32<void> arg1) {
    return ((s32) M2C_FIELD(arg1, s32 *, 0x30) != 0) ? (1) : (0);
}

s32 w3d_auto_802171a8(Ptr32<void> arg0) {
    return (fn_80216E7C() != 0) ? (-1) : (M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0x30), s32 *, 8));
}

s32 w3d_auto_802198a0(Ptr32<void> arg0) {
    return ((s32) M2C_FIELD(arg0, s32 *, 0x2C) == 0) ? (0) : (0x80004001);
}

s32 w3d_auto_8021eab8(Ptr32<void> arg0) {
    fn_80240994();
    return (fn_8021ED0C() != 0) ? (fn_8025D588(w3d::G(M2C_FIELD(arg0, s32 *, 0x38)))) : (M2C_FIELD(arg0, s32 *, 0x34));
}

s32 w3d_auto_8026ce2c(s32 arg0, s32 arg1) {
    return (arg1 != 0) ? (arg1) : (1);
}

s32 w3d_auto_8026ce3c(s32 arg0, s32 arg1) {
    return (arg1 != 0) ? (arg1) : (1);
}

s16 w3d_auto_802c8158(Ptr32<void> arg0) {
    return ((s32) M2C_FIELD(arg0, s32 *, 0x24) == 0) ? (0) : (M2C_FIELD(arg0, s16 *, 0x60));
}

s32 w3d_auto_802e0c54(Ptr32<void> arg0) {
    Ptr32<void> temp_r9;

    temp_r9 = M2C_FIELD(arg0, Ptr32<void> *, 4);
    return ((s32) M2C_FIELD(temp_r9, s32 *, 0xA0) == 0) ? (-1) : (M2C_FIELD(temp_r9, s32 *, 0x98));
}

s32 w3d_auto_8035a208(Ptr32<void> arg0) {
    return ((s32) M2C_FIELD(arg0, s32 *, 8) != -1) ? (1) : (0);
}

}
