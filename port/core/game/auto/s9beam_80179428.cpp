#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9beam_80179428.c"
/* Recovery worker s9: combinations of mechanically corrected m2c forms. */
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

M2C_UNK fn_8017892C();                              /* extern */
Ptr32<Ptr32<void>> fn_8020B680(Ptr32<M2C_UNK>);                      /* extern */
extern M2C_UNK lbl_804124A0[];
extern M2C_UNK lbl_80413068[];
extern M2C_UNK lbl_80413BE8[];
extern s32 lbl_804AB5CC;
extern Ptr32<Ptr32<void>> lbl_804B0158;

Ptr32<void> s9_beam_80179428(Ptr32<void> arg0) {
    s32 temp_r9;
    Ptr32<Ptr32<void>> temp_r3;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<Ptr32<void>> temp_r3_3;

    fn_8017892C();
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_804124A0);
    temp_r3 = fn_8020B680(&(*lbl_80413068));
    if (temp_r3 == NULL) {
        goto block_2;
    }
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0xC)(temp_r3);
block_2:
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 4);
    if (temp_r3_2 == NULL) {
        goto block_4;
    }
    M2C_FIELD(*temp_r3_2, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3_2);
block_4:
    {
        __typeof__(lbl_804AB5CC + 1) h0 = lbl_804AB5CC + 1;
        M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 4) = temp_r3;
        temp_r9 = h0;
        lbl_804AB5CC = temp_r9;
    }
    if (temp_r9 != 1) {
        goto block_10;
    }
    temp_r3_3 = fn_8020B680(&(*lbl_80413BE8));
    if (temp_r3_3 == NULL) {
        goto block_7;
    }
    M2C_FIELD(*temp_r3_3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>)> *, 0xC)(temp_r3_3);
block_7:
    if ((Ptr32<Ptr32<void>>) lbl_804B0158 == NULL) {
        goto block_9;
    }
    M2C_FIELD(*lbl_804B0158, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(lbl_804B0158);
block_9:
    lbl_804B0158 = temp_r3_3;
    M2C_FIELD(*temp_r3_3, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, M2C_UNK)> *, 0x34)(temp_r3_3, 1);
block_10:
    return arg0;
}

}
