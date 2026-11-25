#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoy_80024d08.c"
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

M2C_UNK fn_80161014();                              /* extern */
extern M2C_UNK lbl_8040DEC8[];
extern M2C_UNK lbl_8040DF48[];
M2C_UNK fn_8010A8E0(Ptr32<void>, u16, Ptr32<M2C_UNK>);           /* extern */
s32 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
s32 fn_801613F0(Ptr32<void>, M2C_UNK);                      /* extern */
M2C_UNK fn_8016239C();                              /* extern */
extern M2C_UNK lbl_8037310C[];
extern M2C_UNK lbl_804ACD54;
extern s32 lbl_804B1754;

Ptr32<void> w3d_auto_80024d08(Ptr32<void> arg0) {
    fn_80161014();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040DEC8);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    return arg0;
}

Ptr32<void> w3d_auto_80025830(Ptr32<void> arg0) {
    fn_80161014();
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, Ptr32<M2C_UNK> *, 0) = &(*lbl_8040DF48);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    return arg0;
}

void w3d_auto_800306a4(Ptr32<void> arg0) {
    s32 temp_r30;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        goto block_2;
    }
    temp_r30 = fn_801613F0(w3d::G(lbl_804B1754), 0xC);
    fn_8010A8E0(w3d::G(temp_r30), fn_8015F5A0(&lbl_804ACD54, 1), &(*lbl_8037310C));
    fn_8016239C();
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
block_2:
    return;
}

}
