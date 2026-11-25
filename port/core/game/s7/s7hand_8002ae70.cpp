#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7hand_8002ae70.c"
/* Recovered from original instructions; inferred types and names. */
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
s32 fn_800C53A0(Ptr32<void>, s32);                       /* extern */
s32 fn_800FCEA0();                                  /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
Ptr32<void> fn_801613F0(Ptr32<void>, M2C_UNK);                    /* extern */
M2C_UNK fn_8016239C(Ptr32<void>);                        /* extern */
Ptr32<void> fn_80165254();                                /* extern */
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACC34;
extern M2C_UNK lbl_804ACC44;
extern M2C_UNK lbl_804ACC5C;
extern s32 lbl_804B1754;

void w3d_auto_8002ae70(Ptr32<void> arg0) {
    s32 temp_r29;
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r30_2;
    Ptr32<void> temp_r30_3;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        goto block_6;
    }
    temp_r29 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_r29 == 0) {
        goto block_3;
    }
    { s32 allocator = lbl_804B1754;
    M2C_FIELD(arg0, s32 *, 0x3C) = 3;
    temp_r30 = fn_801613F0(w3d::G(allocator), 8); }
    M2C_FIELD(temp_r30, s16 *, 0) = fn_8015F5A0(&lbl_804ACC5C, 1);
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    M2C_FIELD(arg0, s32 *, 0x34) = fn_800C53A0(temp_r30, M2C_FIELD(fn_80165254(), s32 *, 0x34) + M2C_FIELD(arg0, s32 *, 0x38));
    return;
block_3:
    M2C_FIELD(arg0, s32 *, 0x3C) = temp_r29;
    temp_r30_2 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30_2, s16 *, 0) = fn_8015F5A0(&lbl_804ACC44, 1);
    M2C_FIELD(temp_r30_2, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_2);
    if (fn_800FCEA0() != 0) {
        goto block_5;
    }
    temp_r30_3 = fn_801613F0(w3d::G(lbl_804B1754), 8);
    M2C_FIELD(temp_r30_3, s16 *, 0) = fn_8015F5A0(&lbl_804ACC34, 1);
    M2C_FIELD(temp_r30_3, Ptr32<M2C_UNK> *, 4) = &(*lbl_8040DB38);
    fn_8016239C(temp_r30_3);
block_5:
    M2C_FIELD(arg0, s32 *, 0x30) = temp_r29;
block_6:
    return;
}

}
