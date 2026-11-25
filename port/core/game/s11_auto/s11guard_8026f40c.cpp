#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11guard_8026f40c.c"
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

M2C_UNK fn_8026ED00(Ptr32<void>);                        /* extern */
M2C_UNK fn_8026F9D0(Ptr32<void>);                        /* extern */
M2C_UNK fn_8026FC98(Ptr32<void>, M2C_UNK);               /* extern */
M2C_UNK fn_80296518(Ptr32<void>, s32);                           /* extern */
M2C_UNK fn_802B0990(Ptr32<void>, s32);                   /* extern */
M2C_UNK fn_802BC8B4(Ptr32<void>, s32);                           /* extern */

void w3d_auto_8026f40c(Ptr32<void> arg0, s32 arg1) {
    s32 var_r30;
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r3;

    var_r30 = 1;
    if (arg1 != (s32) M2C_FIELD(arg0, s32 *, 0xB0)) {
        goto block_2;
    }
    var_r30 = 0;
block_2:
    fn_802B0990((arg0 + 0x1C), arg1);
    if (var_r30 == 0) {
        goto block_16;
    }
    temp_r30 = M2C_FIELD(arg0, Ptr32<void> *, 0x28);
    if (arg1 != 0) {
        goto block_5;
    }
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0xD0), Ptr32<M2C_UNK (Ptr32<void>, M2C_UNK)> *, 0x34)((arg0 + 0x1C), 0);
    goto block_11;
block_5:
    if ((s32) M2C_FIELD(M2C_FIELD(temp_r30, Ptr32<void> *, 0x88), u16 *, -4) == 0) {
        goto block_9;
    }
    if (!((M2C_FIELD(temp_r30, u8 *, 0x8) ^ 4) & 4)) {
        goto block_9;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x8C) == 0) {
        goto block_9;
    }
    fn_8026FC98(arg0, 0);
block_9:
    if ((s32) M2C_FIELD(temp_r30, s32 *, 0x98) == 0) {
        goto block_11;
    }
    M2C_FIELD(M2C_FIELD(arg0, Ptr32<void> *, 0xD0), Ptr32<M2C_UNK (Ptr32<void>, M2C_UNK)> *, 0x34)((arg0 + 0x1C), 1);
block_11:
    fn_8026ED00(arg0);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        goto block_14;
    }
    if (arg1 != 1) {
        goto block_14;
    }
    fn_802BC8B4(w3d::G(M2C_FIELD(arg0, s32 *, 0x120)), M2C_FIELD(arg0, s32 *, 0x12C));
block_14:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x124) == 0) {
        goto block_16;
    }
    fn_80296518(w3d::G(M2C_FIELD(arg0, s32 *, 0x124)), arg1);
block_16:
    fn_8026F9D0(arg0);
    return;
}

}
