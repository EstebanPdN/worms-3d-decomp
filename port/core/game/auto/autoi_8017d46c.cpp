#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "autoi_8017d46c.c"
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

extern M2C_UNK lbl_804A8FD8[];
extern M2C_UNK lbl_804A8DD8[];
extern M2C_UNK lbl_80456F14[];
extern M2C_UNK lbl_804A9CF8[];
extern s32 lbl_804ABCE4;

s32 w3d_auto_8017d46c(s32 arg0, Ptr32<u8> arg1, s32 arg2) {
    *(&(*lbl_804A8FD8) + (*arg1)) = arg2;
    return 0;
}

s32 w3d_auto_8017d530(s32 arg0, Ptr32<u8> arg1, Ptr32<s32> arg2) {
    *arg2 = *(&(*lbl_804A8DD8) + (*arg1));
    return 0;
}

s32 w3d_auto_8017dca8(s32 arg0, Ptr32<u8> arg1) {
    return *(&(*lbl_80456F14) + (*arg1));
}

void w3d_auto_802cd2e0(u32 arg0, s32 arg1) {
    if ((s32) lbl_804ABCE4 == 0) {
        goto block_4;
    }
    if (arg0 > 0xFU) {
        goto block_4;
    }
    *(&(*lbl_804A9CF8) + (arg0)) = arg1;
    return;
block_4:
    return;
}

}
