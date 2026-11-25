#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10reorder_801f2798.c"
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

M2C_UNK fn_801FE240(Ptr32<void>);                        /* extern */

void w3d_auto_801f2798(Ptr32<void> arg0) {
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<void> temp_r9;
    Ptr32<void> var_r30;

    temp_r9 = M2C_FIELD(arg0, Ptr32<void> *, 8);
    if (temp_r9 == NULL) {
        goto block_6;
    }
    var_r30 = temp_r9 + (M2C_FIELD(temp_r9, s32 *, -8) * 4);
    if (temp_r9 == var_r30) {
        goto block_5;
    }
loop_2:
    temp_r3 = M2C_FIELD(var_r30, Ptr32<Ptr32<void>> *, -4);
    var_r30 -= 4;
    if (temp_r3 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3);
block_4:
    if ((void *) M2C_FIELD(arg0, Ptr32<void> *, 8) != var_r30) {
        goto loop_2;
    }
block_5:
    fn_801FE240(M2C_FIELD(arg0, Ptr32<void> *, 8) - 8);
block_6:
    M2C_FIELD(arg0, s16 *, 6) = 4;
    M2C_FIELD(arg0, Ptr32<void> *, 8) = NULL;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    return;
}

}
