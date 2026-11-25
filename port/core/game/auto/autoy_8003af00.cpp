#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoy_8003af00.c"
/* Decompiled automatically by m2c; statement order or callee return width
 * adjusted by tools/m2c_reorder.py and verified identical to the original
 * after linking. Types and names are m2c placeholders pending review. */
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

M2C_UNK fn_8010A8E0(Ptr32<void>, u16, s32);                 /* extern */
s32 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
s32 fn_801613F0(Ptr32<void>, M2C_UNK);                      /* extern */
M2C_UNK fn_8016239C();                              /* extern */
extern M2C_UNK lbl_804AD12C;
extern s32 lbl_804B1754;
s32 fn_800672A8(s32);                               /* extern */
Ptr32<f32> fn_800672B0(s32);                              /* extern */
s32 fn_800672B8(s32);                               /* extern */
s32 fn_80164FC8(s32);                               /* extern */

void w3d_auto_8003af00(s32 arg0, s32 arg1) {
    s32 temp_r30;

    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30), fn_8015F5A0(&lbl_804AD12C, 1), arg1);
    fn_8016239C();
    return;
}

s32 w3d_auto_80066bc4(Ptr32<void> arg0) {
    s32 temp_r3;
    Ptr32<Ptr32<void>> temp_r29;
    Ptr32<Ptr32<void>> temp_r29_2;
    Ptr32<Ptr32<void>> temp_r3_2;
    Ptr32<void> temp_r30;
    Ptr32<void> temp_r30_2;

    temp_r3 = fn_80164FC8(M2C_FIELD(arg0, s32 *, 0x1C));
    if (temp_r3 == 0) {
        goto block_2;
    }
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (M2C_FIELD(arg0, f32 *, 0x24) + *fn_800672B0(temp_r3));
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + M2C_FIELD(fn_800672B0(temp_r3), f32 *, 8));
    temp_r29 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    temp_r30 = *temp_r29;
    M2C_FIELD(temp_r30, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, M2C_UNK)> *, 0x4C)(temp_r29, fn_800672A8(temp_r3), 0);
    temp_r29_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    temp_r30_2 = *temp_r29_2;
    M2C_FIELD(temp_r30_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, s32, M2C_UNK)> *, 0x54)(temp_r29_2, fn_800672B8(temp_r3), 0);
    temp_r3_2 = M2C_FIELD(arg0, Ptr32<Ptr32<void>> *, 0x20);
    M2C_FIELD(*temp_r3_2, Ptr32<M2C_UNK (Ptr32<Ptr32<void>>, Ptr32<void>, M2C_UNK)> *, 0x50)(temp_r3_2, arg0 + 0x24, 0);
block_2:
    return 0;
}

}
