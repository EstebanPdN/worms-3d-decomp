#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoy_8026cb70.c"
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

M2C_UNK fn_8026CC60(Ptr32<void>);                        /* extern */
s16 fn_8015F5A0(Ptr32<M2C_UNK>, M2C_UNK);                /* extern */
M2C_UNK fn_80162024(Ptr32<void>, Ptr32<s16>, Ptr32<void>);         /* extern */
extern M2C_UNK lbl_804B0B20;
M2C_UNK fn_80275F18();                              /* extern */
M2C_UNK fn_802761B8(Ptr32<void>, Ptr32<void>, M2C_UNK);          /* extern */
s32 fn_802EF198(Ptr32<void>, s32);                          /* extern */
extern s32 lbl_804ABB9C;
extern s32 lbl_804ABBA0;

void w3d_auto_8026cb70(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    M2C_FIELD(arg0, s32 *, 0x50) = arg1;
    fn_8026CC60(arg0);
    return;
}

void w3d_auto_8026cb9c(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x54) = arg1;
    fn_8026CC60(arg0);
    return;
}

void w3d_auto_8026cbc8(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    fn_8026CC60(arg0);
    return;
}

void w3d_auto_8026cbf4(Ptr32<void> arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
    M2C_FIELD(arg0, s32 *, 0x38) = arg1;
    fn_8026CC60(arg0);
    return;
}

void w3d_auto_8026f9d0(Ptr32<void> arg0) {
    s16 sp8;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0xB0);
    if (temp_r0 != 0) {
        goto block_2;
    }
    M2C_FIELD(arg0, s32 *, 0x100) = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x104) = temp_r0;
block_2:
    sp8 = fn_8015F5A0(&lbl_804B0B20, 1);
    fn_80162024(arg0, &sp8, arg0 + 0xF8);
    return;
}

void w3d_auto_802734bc(Ptr32<void> arg0, s32 arg1) {
    s32 temp_r0;
    s32 var_r31;
    s32 var_r3;

    if (arg1 != 0x1B) {
        goto block_2;
    }
    fn_80275F18();
    return;
block_2:
    var_r3 = fn_802EF198(w3d::G(lbl_804ABB9C), arg1);
    var_r31 = lbl_804ABB9C;
    if (var_r3 != 0) {
        goto block_4;
    }
    var_r31 = lbl_804ABBA0;
    var_r3 = fn_802EF198(w3d::G(var_r31), arg1);
    if (var_r3 == 0) {
        goto block_9;
    }
block_4:
    temp_r0 = var_r3 - var_r31;
    if (temp_r0 == 0) {
        goto block_7;
    }
    if (temp_r0 == 1) {
        goto block_8;
    }
    return;
block_7:
    fn_802761B8(arg0, w3d::G(M2C_FIELD(arg0, s32 *, 0x5C)), 0x14);
    return;
block_8:
    fn_802761B8(arg0, w3d::G(M2C_FIELD(arg0, s32 *, 0x5C)), 0x15);
block_9:
    return;
}

void w3d_auto_802785d8(Ptr32<void> arg0, s32 arg1) {
    s32 var_r31;
    s32 var_r3;

    if (arg1 != 0x1B) {
        goto block_2;
    }
    fn_80275F18();
    return;
block_2:
    var_r3 = fn_802EF198(w3d::G(lbl_804ABB9C), arg1);
    var_r31 = lbl_804ABB9C;
    if (var_r3 != 0) {
        goto block_4;
    }
    var_r31 = lbl_804ABBA0;
    var_r3 = fn_802EF198(w3d::G(var_r31), arg1);
    if (var_r3 == 0) {
        goto block_6;
    }
block_4:
    if (var_r3 != var_r31) {
        goto block_6;
    }
    fn_802761B8(arg0, w3d::G(M2C_FIELD(arg0, s32 *, 0x5C)), 0x14);
block_6:
    return;
}

}
