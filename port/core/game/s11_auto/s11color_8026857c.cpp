#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11color_8026857c.c"
/* Range-isolated m2c recovery by worker s11. Types and names are provisional. */
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

M2C_UNK fn_80173DF0(Ptr32<void>, Ptr32<s8>);                          /* extern */
M2C_UNK fn_8026710C(Ptr32<void>);                        /* extern */
M2C_UNK fn_8034357C(s32);                              /* extern */

void w3d_auto_8026857c(Ptr32<void> arg0) {
    s8 sp8[4];
    u8 var_r9;

    var_r9 = 0xFF;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x8C) != 0) {
        goto block_2;
    }
    var_r9 = 0xB4;
block_2:
    sp8[0] = var_r9;
    M2C_FIELD(&sp8, s8 *, 1) = var_r9;
    M2C_FIELD(&sp8, s8 *, 2) = var_r9;
    M2C_FIELD(&sp8, s8 *, 3) = -1;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1C4) == 0) {
        goto block_4;
    }
    fn_80173DF0(w3d::G(fn_8034357C(M2C_FIELD(arg0, s32 *, 0x1C4))), &sp8);
block_4:
    fn_8026710C(arg0);
    return;
}

}
