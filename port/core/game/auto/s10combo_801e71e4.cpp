#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10combo_801e71e4.c"
/* Missing virtual-object arguments, guarded pointer arguments and byte offsets restored; exact matches only. */
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

M2C_UNK fn_8020FC60(Ptr32<void>, s32);                   /* extern */
M2C_UNK fn_802134FC(Ptr32<void>);                              /* extern */
extern M2C_UNK lbl_80417048[];
extern M2C_UNK lbl_80417070[];
M2C_UNK fn_801E8CCC(Ptr32<void>);                        /* extern */
extern M2C_UNK lbl_80417190[];
extern M2C_UNK lbl_804171B8[];
extern Ptr32<void> lbl_804B18E0;
M2C_UNK fn_801FE1F8(Ptr32<void>);                        /* extern */
M2C_UNK fn_8020C5C4(s32);                           /* extern */
M2C_UNK fn_80210990(Ptr32<void>, M2C_UNK);               /* extern */
M2C_UNK fn_80210ABC(Ptr32<void>, M2C_UNK);               /* extern */
M2C_UNK fn_80341588(s32);                           /* extern */
extern M2C_UNK lbl_804190F0[];
extern M2C_UNK lbl_80419138[];

void w3d_auto_801e71e4(Ptr32<void> arg0, s32 arg1) {
    Ptr32<Ptr32<void>> temp_r3;

    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0xC) = &(*lbl_80417048);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_80417070);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        goto block_2;
    }
    fn_802134FC(w3d::G(M2C_FIELD(arg0, s32 *, 0x40)));
block_2:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x34) == 0) {
        goto block_4;
    }
    fn_802134FC(w3d::G(M2C_FIELD(arg0, s32 *, 0x34)));
block_4:
    temp_r3 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x30);
    if (temp_r3 == NULL) {
        goto block_6;
    }
    M2C_FIELD(*temp_r3, Ptr32<M2C_UNK (Ptr32<void>)> *, 0x10)(temp_r3);
block_6:
    fn_8020FC60(arg0, arg1);
    return;
}

void w3d_auto_801e8b04(Ptr32<void> arg0, s32 arg1) {
    Ptr32<void> var_r10;
    Ptr32<void> var_r9;

    var_r10 = lbl_804B18E0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0xC) = &(*lbl_80417190);
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_804171B8);
    var_r9 = NULL;
    if (var_r10 == NULL) {
        goto block_7;
    }
loop_1:
    if (var_r10 != arg0) {
        goto block_6;
    }
    if (var_r9 == NULL) {
        goto block_4;
    }
    M2C_FIELD(var_r9, Ptr32<void> *, 0x4C) = (void *) M2C_FIELD(arg0, Ptr32<void> *, 0x4C);
    goto block_5;
block_4:
    lbl_804B18E0 = M2C_FIELD(arg0, Ptr32<void> *, 0x4C);
block_5:
    fn_801E8CCC(arg0);
    goto block_7;
block_6:
    var_r9 = var_r10;
    var_r10 = M2C_FIELD(var_r10, Ptr32<void> *, 0x4C);
    if (var_r10 != NULL) {
        goto loop_1;
    }
block_7:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x3C) == 0) {
        goto block_9;
    }
    fn_802134FC(w3d::G(M2C_FIELD(arg0, s32 *, 0x3C)));
block_9:
    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        goto block_11;
    }
    fn_802134FC(w3d::G(M2C_FIELD(arg0, s32 *, 0x30)));
block_11:
    fn_8020FC60(arg0, arg1);
    return;
}


}
